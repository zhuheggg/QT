#include "mainwindow.h"
#include <QApplication>
#include<cstdio>
#include<climits>
#include<QDebug>
using namespace std;
#define m 0x12345678
#define HHI(xxx)  ((qint8) ((qint32)(xxx)>>24))
#define LHI(xxx)  ((qint8) ((qint32)(xxx)>>16))
#define HLO(xxx)  ((qint8) ((qint32)(xxx)>>8))
#define LLO(xxx)  ((qint8) ((qint32)(xxx)&255))
#define MAX(x,y) (((x)>(y))?(x):(y))
#define MIN(x,y) (((x)<(y))?(x):(y))
int main(int argc, char *argv[])
{
   int n;
   QList<qint8> values;
   values.append(HHI(m));
   values.append(LHI(m));
   values.append(HLO(m));
   values.append(LLO(m));

   qDebug("原始值:0x%x(%d):",m,(m));
   qDebug("最高8位和次高8位最大值：0x%x",MAX(HHI(m),LHI(m)));
   qDebug("次低8位和最低8位最小值：0x%x",MIN(HLO(m),LLO(m)));
   n=(values.at(2)<<24)+(values.at(0)<<16)+(values.at(3)<<8)+(values.at(1));
   qDebug("新32位数为:0x%x(%d)",n,(n));
   std::sort(values.begin(),values.end(),greater<quint8>());
   qDebug("排序前:(%d,%d,%d,%d),排序后:(%d,%d,%d,%d)",values.at(3),values.at(2),values.at(1),values.at(0),values.at(0),values.at(1),values.at(2),values.at(3));
}
