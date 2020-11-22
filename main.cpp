#include "mainwindow.h"

int main(int argc, char *argv[])
{

//    const char *database_info = "hostaddr=172.23.5.168 dbname=dachuang user=postgres password=126041";
//    PGconn *conn =PQconnectdb(database_info);
//    const char* c="INSERT INTO project(projectname,url) VALUES('liu','c/ajshdj');";
//     PGresult *patientResults = PQexec(conn,c);
//       bool b_result=false;
//       QSqlQuery qsQuery=QSqlQuery(db);
//       QString  strSqlText(QString::fromStdDtring(strSql));
//       qDebug()<<strSqlText<<endl;
//       b_result=qsQuery.prepare(strSqlText);
//       if(!b_result){
//           qDebug()<<"prepare fail"<<endl;
//       }
//       b_result=qsQuery.exec();
//       if(!b_result){
//           qDebug()<<"exe fail"<<endl;
//       }
//       QString qe="callee('a','b')";
//       int aa = QSqlDatabase::exec(qe);
//       qDebug()<<aa<<endl;
//       qe="select callee('a','b')";
//       aa = QSqlDatabase::exec(qe);
//QSqlQuery query;
//if(!sq.exec("callee('a','b');"))
//    {
//        qDebug()<< sq.lastError()<<endl;
//    }
//if(!query.exec("select callee('a','b');"))
//    {
//        qDebug()<< query.lastError()<<endl;
//    }
//query.exec("select callee('a'，'b')");
//while(query.next())
//    {
//       qDebug() << query.value(0).toInt()
//                                      << query.value(1).toString();
//    }
//int aa=sq.exec("callee('a','b')");
//       qDebug()<<aa<<endl;
//        aa=db->exec("select callee('a','b')");
//              qDebug()<<aa<<endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
