/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDosya_A;
    QAction *actionOkuma;
    QAction *actionOpen;
    QAction *action_redFilter;
    QAction *action_greenFilter;
    QAction *action_blueFilter;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_averageFilter;
    QLabel *label;
    QPushButton *pushButton_grayScaleImage;
    QPushButton *pushButton_medianFilter;
    QPushButton *pushButton_quiz;
    QPushButton *pushButton_laplacianKernel;
    QGraphicsView *graphicsView;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuIslem;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(854, 619);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::CameraPhoto));
        MainWindow->setWindowIcon(icon);
        actionDosya_A = new QAction(MainWindow);
        actionDosya_A->setObjectName("actionDosya_A");
        actionOkuma = new QAction(MainWindow);
        actionOkuma->setObjectName("actionOkuma");
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        action_redFilter = new QAction(MainWindow);
        action_redFilter->setObjectName("action_redFilter");
        action_greenFilter = new QAction(MainWindow);
        action_greenFilter->setObjectName("action_greenFilter");
        action_blueFilter = new QAction(MainWindow);
        action_blueFilter->setObjectName("action_blueFilter");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pushButton_averageFilter = new QPushButton(centralwidget);
        pushButton_averageFilter->setObjectName("pushButton_averageFilter");

        gridLayout->addWidget(pushButton_averageFilter, 2, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 9, 0, 1, 1);

        pushButton_grayScaleImage = new QPushButton(centralwidget);
        pushButton_grayScaleImage->setObjectName("pushButton_grayScaleImage");

        gridLayout->addWidget(pushButton_grayScaleImage, 2, 0, 1, 1);

        pushButton_medianFilter = new QPushButton(centralwidget);
        pushButton_medianFilter->setObjectName("pushButton_medianFilter");

        gridLayout->addWidget(pushButton_medianFilter, 6, 0, 1, 1);

        pushButton_quiz = new QPushButton(centralwidget);
        pushButton_quiz->setObjectName("pushButton_quiz");

        gridLayout->addWidget(pushButton_quiz, 2, 2, 1, 1);

        pushButton_laplacianKernel = new QPushButton(centralwidget);
        pushButton_laplacianKernel->setObjectName("pushButton_laplacianKernel");

        gridLayout->addWidget(pushButton_laplacianKernel, 6, 1, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 11, 0, 1, 3);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 854, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuIslem = new QMenu(menubar);
        menuIslem->setObjectName("menuIslem");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuIslem->menuAction());
        menuFile->addAction(actionOpen);
        menuIslem->addAction(action_redFilter);
        menuIslem->addAction(action_greenFilter);
        menuIslem->addAction(action_blueFilter);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Image Lab", nullptr));
        actionDosya_A->setText(QCoreApplication::translate("MainWindow", "Dosya A\303\247", nullptr));
        actionOkuma->setText(QCoreApplication::translate("MainWindow", "Okuma", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        action_redFilter->setText(QCoreApplication::translate("MainWindow", "Red", nullptr));
        action_greenFilter->setText(QCoreApplication::translate("MainWindow", "Green", nullptr));
        action_blueFilter->setText(QCoreApplication::translate("MainWindow", "Blue", nullptr));
        pushButton_averageFilter->setText(QCoreApplication::translate("MainWindow", "Average Filter", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Photo", nullptr));
        pushButton_grayScaleImage->setText(QCoreApplication::translate("MainWindow", "Gray Scale", nullptr));
        pushButton_medianFilter->setText(QCoreApplication::translate("MainWindow", "Median Filter", nullptr));
        pushButton_quiz->setText(QCoreApplication::translate("MainWindow", "Quiz", nullptr));
        pushButton_laplacianKernel->setText(QCoreApplication::translate("MainWindow", "Laplacian Kernel", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuIslem->setTitle(QCoreApplication::translate("MainWindow", "Operation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
