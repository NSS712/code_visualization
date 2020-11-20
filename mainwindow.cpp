#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "util.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
   //析构函数
       imgDir = "";//add显示读取的目录
       count = 0;//标签个数
       if (img.isNull()) {
//               ui->zoom_in_Button->setEnabled(false);
//               ui->zoom_out_Button->setEnabled(false);
//               ui->left_Button->setEnabled(false);
//               ui->right_Button->setEnabled(false);
//               ui->rectangle_Button->setEnabled(false);
//               ui->round_Button->setEnabled(false);
               ui->viewLabel->setText("打开一个图片(Ctrl+O)");
//               ui->lineEdit->setReadOnly( true );
           }//设置如果没有图片时这些按钮是无法点击的状态

//       ui->openButton->setShortcut(QKeySequence("Ctrl+O"));//设定打开的快捷键
//       ui->saveButton->setShortcut(QKeySequence("Ctrl+S"));//设定保存的快捷键

//       ui->lineEdit->setPlaceholderText( "键入标签名称" );

       scaleFactor = 1;// 缩放比例
       currentRotate = 0;

       QMap<int, int> desktop = Util::GetScreenResolution();//存储获取的屏幕分辨率
       int desktopWidth = desktop.firstKey();
       int desktopHeight = desktop[desktopWidth];
       int factor = 2;//？
       int w = desktopWidth / factor;
       int h = desktopHeight / factor;
       this->resize(w, h);//设置大小
//       imgVision=new myLable(this);//画布大小
//       imgVision->hide();
//       frame_layout=new QGridLayout(ui->viewLabel);
//       frame_layout->addWidget(imgVision);


       setWindowTitle("code_visualization");//显示标题

qDebug()<<"aaa";
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
                   ui->viewLabel->resize(w, h);
                   ui->viewLabel->setPixmap(img);



}
}

MainWindow::~MainWindow()
{
    delete ui;
}
