#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "util.h"
#include "clu.h"





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //connet to postgre
    QSqlDatabase *db=new QSqlDatabase(QSqlDatabase::addDatabase ("QPSQL"));
    db->setHostName("172.23.5.168") ;
    db->setPort (5432);
    db->setUserName ("postgres") ;
    db->setPassword("126041");
    db-> setDatabaseName ("dachuang") ;

    //test the connection
    qDebug()<<"begin to connect";
    if(db->open())
    qDebug()<<"connect db success" ;
    else
    {
    qDebug()<<"error: connect db ";
    qDebug() .noquote() <<db->lastError() ;
    }


    ui->setupUi(this);
   //析构函数
//       imgDir = "";//add显示读取的目录
//       count = 0;//标签个数
//       if (img.isNull()) {
//               ui->zoom_in_Button->setEnabled(false);
//               ui->zoom_out_Button->setEnabled(false);
//               ui->left_Button->setEnabled(false);
//               ui->right_Button->setEnabled(false);
//               ui->rectangle_Button->setEnabled(false);
//               ui->round_Button->setEnabled(false);
//               ui->viewLabel->setText("打开一个图片(Ctrl+O)");
//               ui->lineEdit->setReadOnly( true );
//           }//设置如果没有图片时这些按钮是无法点击的状态

//       ui->openButton->setShortcut(QKeySequence("Ctrl+O"));//设定打开的快捷键
//       ui->saveButton->setShortcut(QKeySequence("Ctrl+S"));//设定保存的快捷键

//       ui->lineEdit->setPlaceholderText( "键入标签名称" );

       scaleFactor = 1;// 缩放比例
       currentRotate = 0;

       QMap<int, int> desktop = Util::GetScreenResolution();//存储获取的屏幕分辨率
       int desktopWidth = desktop.firstKey();
       int desktopHeight = desktop[desktopWidth];
       int factor = 1;//？
       int w = desktopWidth / factor;
       int h = desktopHeight / factor;
       this->resize(w, h);//设置大小
//       imgVision=new myLable(this);//画布大小
//       imgVision->hide();
//       frame_layout=new QGridLayout(ui->viewLabel);
//       frame_layout->addWidget(imgVision);

       setWindowTitle("code_visualization");//显示标题

//qDebug()<<"aaa";
       QString path = "/home/nss/code20201109/code_visualization/e.png";
       if (path.isEmpty()) {//如果路径为空
                   QMessageBox mesg;//出现弹窗
                   mesg.warning(this,"警告","打开图片失败!");
                   return;
               } else {
                    qDebug()<<"abb";
                   currentImg = Util::getSplitLast(path, "/");//读取路径
                   imgDir = Util::getFileDir(path, "/");//获取图片名称
                   imgList = Util::getDirBelowFiles(imgDir);//获取图像

                   imgIndex = imgList.indexOf(currentImg);

                   QPixmap tmp(path);//读取图片的名称和路径，类QPixmap代表图像

                   img = tmp;

                   int w = img.width();
                   int h = img.height();//图片宽度和长度



                   //imgVision->show();
//                   ui->viewLabel->resize(w, h);
                   ui->viewLabel->setPixmap(img);
        }

       QSqlQuery query;
       query.exec("select * from get_project()");
       while(query.next()){
           project p1;
           QString name=query.value(0).toString();
           p1.name=name;
           p1.id=query.value(1).toInt();
           p1.b1->setText(name);
           list.append(p1);
           qDebug()<<"id: "<<p1.id<<"    name:"<<p1.name<<endl;
       }





//       for(int i=0;i<2;i++){
//           project p1;
//           p1.name="111";
//           list.append(p1);
//           project p2;
//           p2.name="222";
//           list.append(p2);
//       }
//       qDebug()<<list.at(0).name<<endl<<list.at(1).id<<endl;
       QVBoxLayout *layout = new QVBoxLayout;
       qDebug()<<list.capacity()<<endl;
//       QCheckBox q1[10];
       for(int i=0;i<list.size();i++){
//           QString a=QString("%1").arg(i);
           QString tep="select get_function(";
           tep.append(QString("%1").arg(list.at(i).id));
           tep.append(")");
           qDebug()<<tep<<endl;
           query.exec(tep);
           query.next();
           QString tem=query.value(0).toString();
            qDebug()<<tem<<endl;
           list[i].dot=tem;
           qDebug()<<list.at(i).id<<endl<<list.at(i).dot<<endl;
           QString a=list.at(i).name;
           qDebug()<<"1"<<endl;
//           list[i].b1->setText("aaaa");
                      qDebug()<<"2"<<endl;
//           QCheckBox *q1=new QCheckBox(a);
//           q1->setText(a);
//           b_list.append();
          layout->addWidget(list[i].b1);
                     qDebug()<<"3"<<endl;
       }

       ui->widget->setLayout(layout);
        QString temm="select get_function(28);";
       query.exec(temm);
       qDebug()<<"????"<<endl;
       query.next();
       QString usage=query.value(0).toString();
       qDebug()<<usage<<endl;

//       shell::exe("dot -Tpng /home/nss/code20201109/code_visualization/e.dot -o /home/nss/code20201109/code_visualization/e.png");
////       shell::exe("ls");
//           QPixmap tmp(path);
//               img = tmp;
//               ui->viewLabel->setPixmap(img);
//       db->close() ;
//       delete db;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::scaleImage(double factor){
    scaleFactor*=factor;//缩放比例scaleFactor初始值为1
    QSize size = img.size();//原始照片
    QSize scaleSize = scaleFactor * size;//放缩后的图片
    img2 = img.scaled(scaleSize, Qt::KeepAspectRatio);

    ui->viewLabel->setPixmap(img2);
    ui->zoom_in_Button->setEnabled(true);
    ui->zoom_out_Button->setEnabled(true);//放大和缩小按钮正常工作
    if(scaleFactor<=0.25)
        ui->zoom_in_Button->setEnabled(false);//当放缩的倍率小于0.25时，缩小按钮停止工作
    if(scaleFactor>=2.5)
        ui->zoom_out_Button->setEnabled(false);//当放缩的倍率高于2.5时，放大的按钮停止工作

}


void MainWindow::on_zoom_out_Button_clicked()
{
    if (img.isNull()) {
                return;
        }
        double factor = 1.25;//make it large as 1.25
        scaleImage(factor);
}

void MainWindow::on_zoom_in_Button_clicked()
{
    if (img.isNull()) {
                return;
        }
        double factor = 0.8;//每次都缩小0.8倍
        scaleImage(factor);
}

void MainWindow::on_Btn_confirm_clicked()
{
    int num=list.size();
    for(int i=0;i<num;i++){
        int m=list.at(i).b1->checkState();
        qDebug()<<list.at(i).name<<"  "<<m<<endl;
        if(list.at(i).b1->checkState()){
                dot=list.at(i).dot;
                break;
    }
    }
    shell::save(dot);
    shell::exe("dot -Tpng /home/nss/code20201109/code_visualization/e.dot -o /home/nss/code20201109/code_visualization/e.png");
    QPixmap tmp("/home/nss/code20201109/code_visualization/e.png");//读取图片的名称和路径，类QPixmap代表图像
    img = tmp;
    ui->viewLabel->setPixmap(img);


}


