#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>  //用作绘画设备的屏幕外图像表示形式
#include <QStandardPaths>   //提供了用于访问标准路径的方法
#include <QDir> //提供了访问目录结构和它们的内容
#include <QByteArrayList>   //提供字节数组的列表
#include <QImageReader> //提供了一种独立于格式的接口，用于从文件或其他设备读取图像
#include <QImageWriter> //提供了与格式无关的接口，用于将图像写入文件或其他设备
#include <QByteArray>   //提供的字节的阵列
#include <QtWidgets>
#include <QMatrix>  //指定坐标系的2D变换
#include <QSize>    //定义了使用整数点的精度的二维对象的大小
#include <QPixmap>
#include<QVector>
#include<vector>
#include <QLabel>
#include <QImage>
#include <QScrollArea>
//#include <QPrinter>
#include <QApplication>
#include <QtWidgets>
//#include <QPrintDialog>
#include <QtPrintSupport/qtprintsupportglobal.h>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>  //QFileDialog类提供了一个对话框，允许用户选择文件或目录。
#include <QStringList>
//#include <QPrinter>
#include <QRect>
#include <stdio.h>
#include <list>
#include<clu.h>
#include <QCoreApplication>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QSqlError>
#include <QSqlQuery>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_zoom_out_Button_clicked();

    void on_zoom_in_Button_clicked();

private:
    Ui::MainWindow *ui;
        int count;//记录有几个框选框,点击一次rectangle或circle就加1
        QPixmap img;    //图片
        QPixmap img2;
        QString imgDir; //图片目录
        int currentRotate;
        double scaleFactor;       // 缩放比例
        double tmpFactor = 0;

        QStringList imgList;    //图片目录下的图片文件列表
        int imgIndex;   //打开图片的路径
        QString currentImg; //图片名



//        myLable *imgVision; //类似画布
        QGridLayout *frame_layout;  //imgvision依赖的布局管理器



        QVector<QString> lables;//保存键入的标签内容
        void scaleImage(double factor);//缩放图片的公共函数
//        std::vector<draw_point> draws;  //保存所画的框选框

        QVector<project>list;

};

#endif // MAINWINDOW_H
