#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
//    const char *database_info = "hostaddr=172.23.5.168 dbname=dachuang user=postgres password=126041";
//    PGconn *conn =PQconnectdb(database_info);
//    const char* c="INSERT INTO project(projectname,url) VALUES('liu','c/ajshdj');";
//     PGresult *patientResults = PQexec(conn,c);




    QSqlDatabase *db=new QSqlDatabase(QSqlDatabase::addDatabase ("QPSQL"));
       db->setHostName("172.23.5.168") ;
       db->setPort (5432);
       db->setUserName ("postgres") ;
       db->setPassword("126041");
       db-> setDatabaseName ("dachuang") ;

       qDebug()<<"begin to connect";
       if(db->open())
       qDebug()<<"connect db success" ;
       else
       {
       qDebug()<<"error: connect db ";
       qDebug() .noquote() <<db->lastError() ;
       }



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

QSqlQuery query;
//if(!sq.exec("callee('a','b');"))
//    {
//        qDebug()<< sq.lastError()<<endl;
//    }
if(!query.exec("select callee('a','b');"))
    {
        qDebug()<< query.lastError()<<endl;
    }
//query.exec("select callee('a'，'b')");
while(query.next())
    {
       qDebug() << query.value(0).toInt()
                                      << query.value(1).toString();
    }



//int aa=sq.exec("callee('a','b')");
//       qDebug()<<aa<<endl;

//        aa=db->exec("select callee('a','b')");
//              qDebug()<<aa<<endl;

       db->close() ;
       delete db;



    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
