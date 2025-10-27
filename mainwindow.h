#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qgraphicsscene.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_actionOpen_triggered(void);
    void on_action_redFilter_triggered(void);
    void on_action_greenFilter_triggered(void);
    void on_action_blueFilter_triggered(void);

private slots:
    void on_pushButton_grayScaleImage_clicked();

    void on_pushButton_averageFilter_clicked();

    void on_pushButton_quiz_clicked();

    void on_pushButton_medianFilter_clicked();

    void on_pushButton_laplacianKernel_clicked();

private:
    Ui::MainWindow *ui;

    QImage qim;
    QPixmap qpixmap;
    QGraphicsScene qgscene;
};
#endif // MAINWINDOW_H
