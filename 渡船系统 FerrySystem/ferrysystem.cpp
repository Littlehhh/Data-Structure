#include "ferrysystem.h"
#include "ui_ferrysystem.h"
#include<stack>
#include<vector>
#include<queue>
#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>
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

void FerrySystem::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open Data"),"",tr("Data File(*.txt)"));
    QTextCodec *code = QTextCodec::codecForName("gb18030");
    string sname = code->fromUnicode(filename).data();

    run(sname);


}
void FerrySystem::on_pushButton_2_clicked()
{
    QFile file("FinalData.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
              {cout<< "error";return;}

    QTextStream in(&file);
    QString name,age,arriveTime,reachTime;

    ui->tableWidget->setRowCount(1000);
    int i = 0;
    while (!in.atEnd())
    {
        in >> name  >> age >> arriveTime >> reachTime ;
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(name));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(age));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(arriveTime));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(reachTime));
        i++;
    }

    ui->label_2->setNum(i-1);

    ui->tableWidget->show();
}
void run(string filename)
{
    vector<guest> ALL;
    boat A(20);
    boat B(40);
    boat C(50);
    queue<boat> port;
    queue<guest> final;
    priority_queue<guest> WaitQueue;
    //初始化时间
    int currentTime = 0;
    int BoardingTime = 0;
    int GetOffTime = 0;
    //读入数据
    getGuest(ALL,filename);//"D:/Qt/qtworks/DSAAproject/Ferry_System/data.txt"
    sort(ALL.begin(),ALL.end(),sortTime);
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
                    while (!ALL.empty() && ALL.back().ArriveTime == currentTime)
                    {
                        WaitQueue.push(ALL.back());
                        ALL.pop_back();
                    }
                }
                else
                {
                    //这个时间是否有人到达
                    while (!ALL.empty() && ALL.back().ArriveTime == currentTime)
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
                while (!ALL.empty() && ALL.back().ArriveTime == currentTime)
                {
                    //若有人正在登船则进入等候队列
                    WaitQueue.push(ALL.back());
                    ALL.pop_back();
                }
            }
        }
        else
        {
            while (!ALL.empty() && ALL.back().ArriveTime == currentTime)
            {	//若港口无船则进入等候队列
                WaitQueue.push( ALL.back() );
                ALL.pop_back();
            }
        }
        //判断船是否满员，或者到达正点
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
        BoardingTime--;
        if( BoardingTime == 0)
            port.front().isBoarding = false;
        currentTime++;
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
  out << all.front().name << ' ' << all.front().age << ' ' << Int2Time(all.front().ArriveTime) << ' ' << Int2Time(all.front().ReachTime) << endl;

        all.pop();
    }
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
        input >> Guest.name >> Guest.age >> Guest.ArriveTime;
        if( Guest.age < 10 )
            Guest.Priority = 3;
        else if( Guest.age > 70 )
            Guest.Priority = 2;
        else
            Guest.Priority = 1;
        all.push_back(Guest);
    }
    input.close();
}
bool sortTime( const guest &x1, const guest &x2 )
{
    return x1.ArriveTime>x2.ArriveTime;//从大到小排序
}



