#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include<QList>
#include <QTextStream>
#include <QFile>
using namespace std;
namespace SK {
enum SortKind{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}
typedef struct
{
    QStringList student;
} studData;
QDebug operator << (QDebug d, const studData &data)
{
    for(int i=0;i<data.student.size();i++)
    d.noquote().nospace()<<QString(data.student.at(i))<<"\t" ;
    return d;
}
class myCmp
{
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2);
private:
    int currentColumn;
};
bool myCmp::operator()(const studData &d1,const  studData &d2)
{
    bool result = false;
    quint32 sortedColumn = 0x00000001<<currentColumn;
    switch (sortedColumn)
    {
        default:result=d1.student.at(currentColumn+1)>d2.student.at(currentColumn+1);break;//比较过程
    }
    return result;
}
class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);
    void readFile();
    void doSort();
private:
    QString add;
    studData title;
    QList<studData > data;    
    void output(quint8 lie);
};
ScoreSorter::ScoreSorter(QString dataFile)
{
    this->add=dataFile;
}
void ScoreSorter::readFile()
{
    QFile file(this->add);//文件位置为debug
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }
    QString titile(file.readLine());
    this->title.student = titile.split(" ", QString::SkipEmptyParts);
    if((this->title.student).last() == "\n") this->title.student.removeLast();
    studData eachdata;
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);

        eachdata.student = str.split(" ", QString::SkipEmptyParts);
        if((eachdata.student).last() == "\n") eachdata.student.removeLast();
        if(eachdata.student.size()==0) continue;
        this->data.append(eachdata);
    }
    file.close();
}
void ScoreSorter::doSort()
{
    for(int i=1;i<this->title.student.size();i++)
    {
        myCmp cmp(i-1);
        std::sort(this->data.begin() , this->data.end(),cmp);
        qDebug()<<"当前排序第 "<<i+1 <<" 列：";
        qDebug() << '\t'<< (this->title);
        for(int i=0;i<this->data.size();i++)  qDebug() << this->data.at(i);
        qDebug()<<"---------------------------------------------------------------\n";
        this->output(i+1);
    }
}
void ScoreSorter::output(quint8 lie)
{
    QFile file("sorted_"+this->add);

    file.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");//保存格式
    stream<<QString("排序后输出，当前排序第 ")<<lie <<QString(" 列：")<<"\r\n";
    stream<<"\t";
for(int j=0;j<this->title.student.size();j++)
        stream<<this->title.student.at(j)<<"\t";
        stream<<"\r\n";
    for(int i=0;i<this->data.size();i++)
    {
        for(int j=0;j<this->title.student.size();j++)
        stream<<this->data.at(i).student.at(j)<<"\t";
        stream<<"\r\n";
    }


    stream<<"------------------------------------------------------------------"<<"\r\n\r\n";
    file.close();
}
int main ()
{


    //qInstallMessageHandler(myMessageOutput);
    QString datafile = "data.txt";
    QFile f("sorted_"+datafile);
    if (f.exists())
    {
        f.remove();
    }

    ScoreSorter s(datafile);
    s.readFile();
    s.doSort();

    return 0;
}
