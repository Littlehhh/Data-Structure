#include "ferrysystem.h"
#include "ui_ferrysystem.h"
#include <stack>
#include <vector>
#include <queue>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <QFileDialog>
#include <QTextCodec>
#include <QFile>
#include <QTextStream>
using namespace std;

FerrySystem::FerrySystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FerrySystem)
{
    ui->setupUi(this);
}

FerrySystem::~FerrySystem()
{
    delete ui;
}
int FerrySystem::getedit()
{
    QString edit;
    edit = ui->lineEdit->text();

    int num = edit.toInt();
    cout << num << endl;
    return num;
}

void FerrySystem::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open Data"),"",tr("Data File(*.txt)"));
    QTextCodec *code = QTextCodec::codecForName("gb18030");
    string sname = code->fromUnicode(filename).data();
    int currentTime = getedit();
    run(sname,0);


}
void FerrySystem::on_pushButton_2_clicked()
{
    QFile file("FinalData.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
              {cout<< "error";return;}

    QTextStream in(&file);
    QString num,name,sex,age,arriveTime,reachTime;

    ui->tableWidget->setRowCount(10000);
    int i = 0;
    while (!in.atEnd())
    {
        in >> num >> name  >> age >> sex >> arriveTime >> reachTime ;
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(num));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(name));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(age));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(sex));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(arriveTime));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(reachTime));
        i++;
    }

    ui->label_2->setNum(i-1);

    ui->tableWidget->show();
}
void printVector(vector<guest>& all)
{
    for(vector<guest>::iterator it = all.begin(); it!=all.end();++it)
        cout << (*it).name << ' ' << (*it).age << ' ' << (*it).ArriveTime << endl;

    cout<<endl;
}
void run(string filename,int currentTime)
{
    vector<guest> ALL;
    boat A(20);
    boat B(40);
    boat C(50);
    queue<boat> port,arriveport;
    queue<guest> final;
    priority_queue<guest> WaitQueue;

    //初始化时间
    //int currentTime = 0;
   // int currentTime = ui->getedit();
    int boatleavingTime = 3600 * 8;
    int BoardingTime = 0;
    int GetOffTime = 3600 * 8 + 600;
    //读入数据
    getGuest(ALL,filename);//"D:/Qt/qtworks/DSAAproject/Ferry_System/data.txt"
    sort(ALL.begin(),ALL.end(),sortTime);
    printVector(ALL);
    //初始化港口
    port.push(A);
    port.push(B);
    port.push(C);

    //系统运行

    while( !ALL.empty() || !WaitQueue.empty() || !port.front().s.empty() )
    {
        //判断港口是否有船
        if( port.front().returnTime <= currentTime )
        {

            //判断是否有人正在登船
            if (port.front().isBoarding == false)
            {
                //判断等候队列是否有人
                if (WaitQueue.empty())
                {	//等候队列为空直接上船
                    //这个时间是否有人到达
                    if (!ALL.empty() && ALL.back().ArriveTime == currentTime)
                    {
                        port.front().s.push(ALL.back());
                        //更改状态：正在有人登船
                        port.front().isBoarding = true;
                        BoardingTime = 20;
                        ALL.pop_back();
                    }
                    //解决如果两个人同时到达
                  //  while (!ALL.empty() && ALL.back().ArriveTime == currentTime)
                 //   {
                 //       WaitQueue.push(ALL.back());
                 //       ALL.pop_back();
                 //   }
                }
                else
                {
                    //这个时间是否有人到达
                    if (!ALL.empty() && ALL.back().ArriveTime == currentTime)
                    {	//等候队列不为空，进入队列
                        WaitQueue.push(ALL.back());
                        ALL.pop_back();
                    }
                    //更改状态：正在有人登船
                    port.front().isBoarding = true;
                    BoardingTime = 20;
                    //队列前一个人上船并从队列弹出
                    port.front().s.push(WaitQueue.top());
                    WaitQueue.pop();
                }
            }
            else
            {
                if (!ALL.empty() && ALL.back().ArriveTime == currentTime)
                {
                    //若有人正在登船则进入等候队列
                    WaitQueue.push(ALL.back());
                    ALL.pop_back();
                }
            }
        }
        else
        {
            if (!ALL.empty() && ALL.back().ArriveTime == currentTime)
            {	//若港口无船则进入等候队列
                WaitQueue.push( ALL.back() );
                ALL.pop_back();
            }
        }
        //判断船是否满员，或者到达正点
        if(currentTime < 3600*8)
        {
            if( port.front().s.size() == port.front().capacity )
            {
                //处理时间
                //port.front().leaveTime = boatleavingTime ;
               // GetOffTime = port.front().leaveTime + 600;//10分钟

                while( !port.front().s.empty() )
                {
                    port.front().s.top().ReachTime = GetOffTime;
                    GetOffTime += 10;

                    final.push(port.front().s.top());
                    port.front().s.pop();
                }
                port.front().returnTime = GetOffTime + 480;//8分钟
                port.front().isBoarding = false;

                port.push( port.front() );
                port.pop();

            }
        }
        else
        {
            if( port.front().s.size() == port.front().capacity || (currentTime+20)%3600 == 0 )
            {

                //处理时间
                port.front().leaveTime = currentTime + 20;
                GetOffTime = port.front().leaveTime + 600;//10分钟

                while( !port.front().s.empty() )
                {
                    port.front().s.top().ReachTime = GetOffTime;
                    GetOffTime += 10;

                    final.push(port.front().s.top());
                    port.front().s.pop();
                }
                port.front().returnTime = GetOffTime + 480;//8分钟
                port.front().isBoarding = false;
                port.push( port.front() );
                port.pop();
            }
        }
        if(!ALL.empty() && ALL.back().ArriveTime == currentTime);
        else
        {
            currentTime++;
            BoardingTime--;
        }
        if( BoardingTime == 0)
            port.front().isBoarding = false;

    }
    printQueue(final);


}
void printQueue(queue<guest>& all)
{
    fstream out("FinalData.txt",ios::out);

    if(!out)
    {
        cout<<"txt read error"<<endl;
        return ;
    }
    while(!all.empty())
    {
       // cout << all.front().name << ' ' << all.front().age << ' ' << all.front().ArriveTime << ' ' << all.front().ReachTime << endl;

       // out << all.front().name << ' ' << all.front().age << ' ' << all.front().ArriveTime << ' ' << all.front().ReachTime << endl;
 out << all.front().num << ' ' <<  all.front().name << ' ' << all.front().sex << ' ' << all.front().age << ' ' << all.front().ArriveTime << ' ' << all.front().ReachTime << endl;
                                                                                                                                    //Int2Time(all.front().ArriveTime)//Int2Time(all.front().ReachTime)
        all.pop();
    }
    out.close();
}
string Int2Time(int time)
{
    string h,m,s,Time;
    int hh,mm,ss;
    ss = time % 60;
    hh = ((time-ss) / 60) / 60;
    mm = ((time-ss) / 60) - 60*hh;

    h = to_string(hh);
    m = to_string(mm);
    s = to_string(ss);
    Time = h+':'+m+':'+s;
    return Time;
}

void getGuest(vector<guest>& all,string filename)
{
    cout << filename << endl;
    ifstream input(filename.c_str());
    if(!input)
    {
        cout<<"txt read error"<<endl;
        return ;
    }
    guest Guest;

    while(!input.eof())
    {
        input >> Guest.num >> Guest.name >> Guest.sex >> Guest.age >> Guest.h >> Guest.m >> Guest.s;
                //Guest.ArriveTime;
        Guest.ArriveTime = Guest.h * 3600 + Guest.m * 60 + Guest.s;
        if( Guest.age <= 10 )
            Guest.Priority = 300000 + 40000 - Guest.ArriveTime;
        else if( Guest.age >= 70 )
            Guest.Priority = 200000 + 40000 - Guest.ArriveTime;
        else
            Guest.Priority = 100000 + 40000 - Guest.ArriveTime;
        all.push_back(Guest);
    }
    input.close();
}
bool sortTime( const guest &x1, const guest &x2 )
{
    return x1.ArriveTime > x2.ArriveTime;//从大到小排序
}



