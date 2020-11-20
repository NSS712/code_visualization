#ifndef UTIL_H
#define UTIL_H




#include <QObject>
#include <QWidget>
#include <QMap>
#include <QDir>
#include <QSettings>

class Util : public QObject
{
public:
    Util();
    ~Util();

   static QMap<int, int> GetScreenResolution();//获取可用桌面的分辨率、桌面的大小
   static QString getSplitLast(QString string, QString separator);//对文件的后缀名进行分割
   static QString getFileDir(QString path, QString separator);//获取文件的目录
   static QStringList getDirBelowFiles(const QString path);//确认可以读取的照片格式
   static void removeFile(const QString path);//移动图片
};


#endif // UTIL_H


