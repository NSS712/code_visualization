#ifndef SHELL_H
#define SHELL_H

#include<QString>
#include<QProcess>
#include<QDebug>
#include<QFile>


class shell
{
public:

    shell();
    static void exe(QString);
    static void save(QString);
//    static QStringList split(QString,QString);
//    static QStringList hold(QStringList,QString);
//    static QString ctags_cmd(QString,int);
//    static QStringList cflow_cmd(QString,QStringList,QString);
//    static QString ls_cmd(QString,QString);
};

#endif // SHELL_H
