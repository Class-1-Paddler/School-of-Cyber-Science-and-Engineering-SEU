/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_12;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView_2;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_13;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1287, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/readFromFile.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon1);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_2->setIcon(icon1);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/write2File.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_3->setIcon(icon2);
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_4->setIcon(icon1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(221, 227, 216, 255), stop:0.55 rgba(180, 207, 213, 255), stop:0.98 rgba(221, 227, 216, 255), stop:1 rgba(180, 207, 213, 0))"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_3 = new QHBoxLayout(page);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(page);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout->addWidget(tableView);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(widget_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(widget_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_12 = new QPushButton(widget_2);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        verticalLayout->addWidget(pushButton_12);


        horizontalLayout->addWidget(widget_2);


        horizontalLayout_3->addWidget(widget);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        horizontalLayout_4 = new QHBoxLayout(page_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(page_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableView_2 = new QTableView(widget_3);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        horizontalLayout_2->addWidget(tableView_2);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_8 = new QPushButton(widget_4);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        verticalLayout_2->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(widget_4);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        verticalLayout_2->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(widget_4);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        verticalLayout_2->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(widget_4);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        verticalLayout_2->addWidget(pushButton_11);

        pushButton_13 = new QPushButton(widget_4);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        verticalLayout_2->addWidget(pushButton_13);

        pushButton_2 = new QPushButton(widget_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);


        horizontalLayout_2->addWidget(widget_4);


        horizontalLayout_4->addWidget(widget_3);

        stackedWidget->addWidget(page_2);

        horizontalLayout_5->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1287, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addSeparator();
        menu->addAction(action_2);
        menu->addAction(action_3);
        menu->addAction(action_4);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\347\220\203\345\221\230\344\277\241\346\201\257\345\255\230\345\202\250\346\226\207\344\273\266", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\345\234\272\346\254\241\344\277\241\346\201\257\345\255\230\345\202\250\346\226\207\344\273\266", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272\346\225\260\346\215\256", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\346\225\260\346\215\256", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\234\272\346\254\241\344\277\241\346\201\257", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\351\200\211\344\270\255\347\220\203\345\221\230\344\277\241\346\201\257", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\347\255\233\351\200\211", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\350\257\246\347\273\206\345\234\272\346\254\241\345\210\227\350\241\250", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\345\275\223\345\211\215\350\241\250\346\240\274\344\270\255\347\232\204\346\225\260\346\215\256\345\210\260\346\226\207\344\273\266", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\234\272\346\254\241\344\277\241\346\201\257", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\351\200\211\344\270\255\345\234\272\346\254\241", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\351\200\211\344\270\255\345\234\272\346\254\241", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\345\234\272\346\254\241\344\277\241\346\201\257", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260\345\234\272\346\254\241\344\277\241\346\201\257", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\347\220\203\345\221\230\344\277\241\346\201\257\350\241\250", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "  \346\226\207\344\273\266(F)  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
