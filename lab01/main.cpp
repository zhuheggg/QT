#include <iostream>
#include <QCoreApplication>
#include<QList>
#include<QVector>
#include<QDeBug>
#include <algorithm>
using namespace std;
class student
{
    public:
    int num;
    QString name;
    int score1;
    int score2;
};
bool name1(student A,student B)
{
   if(A.name<=B.name)
   {
       return 0;
   }
   else
   {
       return 1;
   }
}
bool score1(student A,student B)
{
    if(A.score1<=B.score1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
bool score2(student A,student B)
{
    if(A.score2<=B.score2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
      class student
       A,B,C,D;
       A.num=1403130209;
       A.name="鲁智深";
       A.score1=80;
       A.score2=72;
       B.num=1403140101;
       B.name="林冲";
       B.score1=82;
       B.score2=76;
       C.num=1403140102;
       C.name="宋江";
       C.score1=76;
       C.score2=85;
       D.num=1403140103;
       D.name="武松";
       D.score1=88;
       D.score2=80;
       QList<student> table;
       table<<A<<B<<C<<D;
       qDebug("原表格为\n");
       for(int i=0;i<4;i++)
           {
               qDebug()<<table.at(i).num<<table.at(i).name<<table.at(i).score1<<table.at(i).score2;
           }
           qDebug("\n");
          std:: sort(table.begin(),table.end(),name1);
          qDebug("按姓名排序\n");
             for(int i=0;i<4;i++)
             {
                 qDebug()<<table.at(i).num<<table.at(i).name<<table.at(i).score1<<table.at(i).score2;
             }
                 qDebug("\n");
            std:: sort(table.begin(),table.end(),score1) ;
           qDebug("按score1排序\n");
                    for(int i=0;i<4;i++)
                    {
                        qDebug()<<table.at(i).num<<table.at(i).name<<table.at(i).score1<<table.at(i).score2;
                    }
                        qDebug("\n");
              std:: sort(table.begin(),table.end(),score2) ;
              qDebug("按score2排序\n");
                       for(int i=0;i<4;i++)
                       {
                           qDebug()<<table.at(i).num<<table.at(i).name<<table.at(i).score1<<table.at(i).score2;
                       }
                           qDebug("\n");

}
