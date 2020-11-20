#include "util.h"

#include <QApplication>
#include <QDesktopWidget>


// 获取桌面的分辨率
QMap<int, int> Util::GetScreenResolution() {
    QMap<int, int> map;

    QDesktopWidget* desktop = QApplication::desktop();
    int width = desktop->width();
    int height = desktop->height();
    map[width] = height;

    return map;
}//获取可用桌面的大小

QString Util::getSplitLast(QString string, QString separator)
{
    return string.split(separator).last();
}//获取文件的后缀名

QString Util::getFileDir(QString path, QString separator) {
    int i = path.lastIndexOf(separator);//分隔符的位置
    int offset = i + 1;
    QString dir = path.mid(0, offset);//输出开始到分隔符之间的字母即名称

    return dir;
}//获取文件的名称

QStringList Util::getDirBelowFiles(const QString path)
{
    QDir dir(path);//QDir类提供了访问系统目录结构及其内容的与平台无关的方式。
    QStringList nameFilters;
    nameFilters << "*.jpg" << "*.png"<< "*.bmp";
    QStringList files = dir.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
    return files;
}//读入jpg、png、bmp格式的照片

void Util::removeFile(const QString path) {
    if (path.isEmpty()) {
        return;
    }
    QFile file(path);//QFile类用来输入和输出图像
    file.remove();
}//读入图片
