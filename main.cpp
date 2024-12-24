#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>//程序启动界面动画
#include <QTimer>//设置程序启动界面的时长

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap(":/res/appLauchingPage.png");//创建QPixmap对象，设置启动图片
    QSplashScreen splash(pixmap);//利用QPixmap对象创建一个QSplashScreen对象
    splash.show();//显示启动图像
    a.processEvents();//使得程序在显示启动画面时仍然能相应鼠标等其它事件
    MainWindow w;
    QTimer::singleShot(2000, [&]()
    {
        w.show();
        splash.finish(&w);//在主窗体对象初始化完成后结束启动画面
    });

    return a.exec();
}
