#include "shell.h"


shell::shell()
{

}

void shell::exe(QString strCmd){
    QProcess p;
//    QString dot_path="cd /home/nss/code20201109/code_visualization";
//    p.start("bash",QStringList()<<"-c"<<strCmd);
//   p.Append(QStringList()<<"-c"<<strCmd);
    p.start("bash",QStringList()<<"-c"<<strCmd);
    p.waitForFinished(-1);
    QString strResult = p.readAllStandardOutput();
    qDebug()<<strResult<<endl;
//    if(strResult=="")qDebug()<<"error: "<<strCmd<<" exe return null" ;
    //qDebug().noquote()<<strResult;
    //this->split(strResult,"\n");
    p.kill();
//    return strResult;
}

void shell::save(QString e){
//    QFile file("/home/nss/code20201109/code_visualization/e.dot");
//    file.open(QIODevice::WriteOnly | QIODevice::Text);
//    file.write(e.toUtf8());
//    file.close();

        QFile aFile("/home/nss/code20201109/code_visualization/e.dot");
        if (!aFile.open(QIODevice::WriteOnly | QIODevice::Text)){
            qDebug()<<"f"<<endl;
            return ;}
        QTextStream aStream(&aFile); //用文本流读取文件
//        QString str=ui->textEditStream->toPlainText(); //转换为字符串
        aStream<<e; //写入文本流
        aFile.close();//关闭文件
        return;
}
