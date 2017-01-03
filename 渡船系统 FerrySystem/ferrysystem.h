#ifndef FERRYSYSTEM_H
#define FERRYSYSTEM_H

#include <QMainWindow>
#include<stack>
#include<vector>
#include<queue>
#include<string>


using namespace std;
namespace Ui {
class FerrySystem;
}

class FerrySystem : public QMainWindow
{
    Q_OBJECT

public:
    explicit FerrySystem(QWidget *parent = 0);
    ~FerrySystem();

    int getedit();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FerrySystem *ui;
};

typedef struct _guest{
    int num;
    string name;
    string sex;
    int age;
    long int ArriveTime;
    int h;
    int m;
    int s;
    long int ReachTime;
    long int Priority;
    bool operator < (const _guest &x) const
    {
        return Priority<x.Priority;
    }
}guest;
class boat{
    public:
        int capacity;
        stack<guest> s;
        int leaveTime;
        int returnTime;
        bool isBoarding;
        explicit boat(int num)
        :capacity(num),leaveTime(0),returnTime(0),isBoarding(false)	{
        }

};
void printVector(vector<guest>& all);
void getGuest(vector<guest>& all,string filename);
void printQueue(queue<guest>& all);
bool sortTime( const guest &x1, const guest &x2);
void run(string filename,int currentTime);
string Int2Time(int time);
#endif // FERRYSYSTEM_H
