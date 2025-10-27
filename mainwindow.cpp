#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Fotoğrafı açmak

void MainWindow::on_actionOpen_triggered(void){
    // cout << "Merhaba!" << endl;
    QString fileName = QFileDialog::getOpenFileName(this,
    tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    cout << "Secilen Dosya: " << fileName.toStdString() << endl;

    qim.load(fileName);
    qpixmap = QPixmap::fromImage(qim);
    qgscene.addPixmap(qpixmap);
    ui->graphicsView->setScene(&qgscene);
}

// Kırmızı Filtresi

void MainWindow::on_action_redFilter_triggered(void){
    cout << "Genislik ve yukseklik: " << qim.width() << " , " << qim.height() << endl;

    QRgb c1 = qim.pixel(392,154);

    int r1,g1,b1;
    r1 = qRed(c1);
    g1 = qGreen(c1);
    b1 = qBlue(c1);

    cout << "R,G,B: " << r1 << " , " << g1 << " , " << b1 << endl;

    QImage islenmisQim = qim;

    for (int w = 0; w < qim.width(); w++) {
        for (int h = 0; h < qim.height(); h++) {

            c1 = qim.pixel(w,h);
            r1 = qRed(c1);
            g1 = qGreen(c1);
            b1 = qBlue(c1);

            // kırmızı
            if(!(r1>100 && b1<100 && g1<100)){
                islenmisQim.setPixelColor(w,h,QColor(0,0,0));
            }

        }

    }

    qgscene.clear();

    qpixmap = QPixmap::fromImage(islenmisQim);
    qgscene.addPixmap(qpixmap);
    ui->graphicsView->setScene(&qgscene);

    // Çıktı: Görüntü sadece kırmızıları gösteriyor, diğer kısımlar siyah.

}

// Yeşil Filtresi

void MainWindow::on_action_greenFilter_triggered(void){
    cout << "Genislik ve yukseklik: " << qim.width() << " , " << qim.height() << endl;

    QRgb c1 = qim.pixel(392,154);

    int r1,g1,b1;
    r1 = qRed(c1);
    g1 = qGreen(c1);
    b1 = qBlue(c1);

    cout << "R,G,B: " << r1 << " , " << g1 << " , " << b1 << endl;

    QImage islenmisQim = qim;

    for (int w = 0; w < qim.width(); w++) {
        for (int h = 0; h < qim.height(); h++) {

            c1 = qim.pixel(w,h);
            r1 = qRed(c1);
            g1 = qGreen(c1);
            b1 = qBlue(c1);

            // yeşil
            if (!(g1 > 100 && r1 < 100 && b1 < 100)) {
                islenmisQim.setPixelColor(w,h,QColor(0,0,0));
            }
        }

    }

    qgscene.clear();

    qpixmap = QPixmap::fromImage(islenmisQim);
    qgscene.addPixmap(qpixmap);
    ui->graphicsView->setScene(&qgscene);

    // Çıktı: Görüntü sadece yeşilleri gösteriyor, diğer kısımlar siyah.

}

// Mavi Filtresi

void MainWindow::on_action_blueFilter_triggered(void){
    cout << "Genislik ve yukseklik: " << qim.width() << " , " << qim.height() << endl;

    QRgb c1 = qim.pixel(392,154);

    int r1,g1,b1;
    r1 = qRed(c1);
    g1 = qGreen(c1);
    b1 = qBlue(c1);

    cout << "R,G,B: " << r1 << " , " << g1 << " , " << b1 << endl;

    QImage islenmisQim = qim;

    for (int w = 0; w < qim.width(); w++) {
        for (int h = 0; h < qim.height(); h++) {

            c1 = qim.pixel(w,h);
            r1 = qRed(c1);
            g1 = qGreen(c1);
            b1 = qBlue(c1);

            // mavi
            if(!(b1 > r1 + 25 && b1 > g1 + 25)){
               islenmisQim.setPixelColor(w,h,QColor(0,0,0));
            }

        }

    }

    qgscene.clear();

    qpixmap = QPixmap::fromImage(islenmisQim);
    qgscene.addPixmap(qpixmap);
    ui->graphicsView->setScene(&qgscene);

    // Çıktı: Görüntü sadece mavileri gösteriyor, diğer kısımlar siyah.

}

// Gray Scale: Fotoğrafı gri yapmak

void MainWindow::on_pushButton_grayScaleImage_clicked()
{
    cout << "Genislik ve yukseklik: " << qim.width() << " , " << qim.height() << endl;

    int r1, g1, b1;
    QRgb c1;

    QImage grayscaleqim = qim;

    for (int w = 0; w < qim.width(); w++) {
        for (int h = 0; h < qim.height(); h++) {

            c1 = qim.pixel(w, h);

            r1 = qRed(c1);
            g1 = qGreen(c1);
            b1 = qBlue(c1);

            int gray = (r1 + g1 + b1) / 3;

            grayscaleqim.setPixelColor(w, h, QColor(gray, gray, gray));
        }
    }

    qgscene.clear();
    qpixmap = QPixmap::fromImage(grayscaleqim);
    qgscene.addPixmap(qpixmap);
    ui->graphicsView->setScene(&qgscene);

    // Çıktı: Tüm pikseller gri tonlara dönüşüyor.

}

// Average Filter : Ortalama filtresi (yumuşatma)

void MainWindow::on_pushButton_averageFilter_clicked()
{
    cout<< "Genislik ve yukseklik: " << qim.width() << " , " << qim.height() << endl;

    QRgb c1 = 	qim.pixel(392, 154);


    int r1,g1,b1;
    r1 = qRed(c1);
    g1 = qGreen(c1);
    b1 = qBlue(c1);

    cout<< "R,G,B :" << r1 <<", "<<g1<<", "<< b1 << endl;

    QColor black("black");


    QImage islenmisQim=qim;

    for( int w=1; w<qim.width()-1; w++ ){
        for( int h=1; h<qim.height()-1; h++){

            int toplam=0;
            for(int m=-1; m<=1; m++ ){
                for(int n=-1; n<=1; n++){
                    c1 = qim.pixel( w+m, h+n );
                    r1 = qRed(c1);
                    g1 = qGreen(c1);
                    b1 = qBlue(c1);

                    int grayScale=(r1+g1+b1)/3;

                    toplam += grayScale;


                }
            }
            int ortalama=toplam/25;

            islenmisQim.setPixelColor( w,h,QColor(ortalama,ortalama,ortalama) );


        }
    }

    qim=islenmisQim;

    qgscene.clear();

    qpixmap = QPixmap::fromImage( islenmisQim );
    qgscene.addPixmap( qpixmap );
    ui->graphicsView->setScene( &qgscene );

    // Çıktı: Görüntü daha yumuşak

}

// Quiz

void MainWindow::on_pushButton_quiz_clicked()
{
    cout<< "Genislik ve yukseklik: " << qim.width() << " , " << qim.height() << endl;

    QRgb c1 = 	qim.pixel(392, 154);


    int r1,g1,b1;
    r1 = qRed(c1);
    g1 = qGreen(c1);
    b1 = qBlue(c1);

    cout<< "R,G,B :" << r1 <<", "<<g1<<", "<< b1 << endl;


    QImage islenmisQim=qim;

    for (int w = 1; w < qim.width() - 1; w++) {
        for (int h = 1; h < qim.height() - 1; h++) {

            double toplam = 0.0;
            for (int m = -1; m <= 1; m++) {
                for (int n = -1; n <= 1; n++) {
                    QRgb c1 = qim.pixel(w + m, h + n);
                    int r1 = qRed(c1);
                    int g1 = qGreen(c1);
                    int b1 = qBlue(c1);
                    int gray = (r1 + g1 + b1) / 3;

                    double quiz_katsayi;
                    if (m == 0 && n == 0)
                        quiz_katsayi = 0.2;
                    else
                        quiz_katsayi = 0.1;

                    toplam += gray * quiz_katsayi;
                }
            }

            int ortalama = toplam;
            islenmisQim.setPixelColor(w, h, QColor(ortalama, ortalama, ortalama));
        }
    }


    qim=islenmisQim;

    qgscene.clear();

    qpixmap = QPixmap::fromImage( islenmisQim );
    qgscene.addPixmap( qpixmap );
    ui->graphicsView->setScene( &qgscene );
}

// Median Filter: Medyan filtresi

void MainWindow::on_pushButton_medianFilter_clicked()
{
    QRgb c1 = 	qim.pixel(392, 154);

    cout<< "Genislik ve yukseklik: " << qim.width() << " , " << qim.height() << endl;

    int r1,g1,b1;
    r1 = qRed(c1);
    g1 = qGreen(c1);
    b1 = qBlue(c1);

    cout<< "R,G,B :" << r1 <<", "<<g1<<", "<< b1 << endl;

    QColor black("black");
    QImage islenmisQim=qim;
    int grayScale;
    std::vector<int> kernelinPenceresindekiRenkler;

    for( int w=1; w<qim.width()-1; w++ ){
        for( int h=1; h<qim.height()-1; h++){
            kernelinPenceresindekiRenkler.clear();
            for(int m=-1; m<=1; m++ ){
                for(int n=-1; n<=1; n++){
                    c1 = qim.pixel( w+m, h+n );
                    r1 = qRed(c1);
                    g1 = qGreen(c1);
                    b1 = qBlue(c1);
                    grayScale=(r1+g1+b1)/3;
                    kernelinPenceresindekiRenkler.push_back(grayScale);
                }
            }

            // cout << "kernelinPenceresindekiRenkler : sort edilmemiş hali:" << endl;
            // for(int i=0; i < kernelinPenceresindekiRenkler.size(); i++)
            //     cout << kernelinPenceresindekiRenkler.at(i) << endl;

            std::sort( kernelinPenceresindekiRenkler.begin(), kernelinPenceresindekiRenkler.end() );

            // cout << "kernelinPenceresindekiRenkler : sort edilmiş hali:" << endl;
            // for(int i=0; i < kernelinPenceresindekiRenkler.size(); i++)
            //     cout << kernelinPenceresindekiRenkler.at(i) << endl;

            int medianValue = kernelinPenceresindekiRenkler.at(4);
            islenmisQim.setPixelColor( w,h,QColor(medianValue,medianValue,medianValue) );
        }
    }

    qim=islenmisQim;

    qgscene.clear();

    qpixmap = QPixmap::fromImage( islenmisQim );
    qgscene.addPixmap( qpixmap );
    ui->graphicsView->setScene( &qgscene );

    // Çıktı: Temiz olmayan bir görüntü temizleniyor.
}

// Laplacion Kernel: Nesnelerin sınırlarını vurgular

void MainWindow::on_pushButton_laplacianKernel_clicked()
{
    QRgb c1 = 	qim.pixel(392, 154);

    cout<< "Genislik ve yukseklik: " << qim.width() << " , " << qim.height() << endl;

    int r1,g1,b1;
    r1 = qRed(c1);
    g1 = qGreen(c1);
    b1 = qBlue(c1);

    cout<< "R,G,B :" << r1 <<", "<<g1<<", "<< b1 << endl;

    QImage islenmisQim=qim;


    for (int w = 1; w < qim.width() - 1; w++) {
        for (int h = 1; h < qim.height() - 1; h++) {

            double toplam = 0.0;
            for (int m = -1; m <= 1; m++) {
                for (int n = -1; n <= 1; n++) {
                    QRgb c1 = qim.pixel(w + m, h + n);
                    int r1 = qRed(c1);
                    int g1 = qGreen(c1);
                    int b1 = qBlue(c1);
                    int gray = (r1 + g1 + b1) / 3;

                    double laplacian_kernel;
                    if (m == 0 && n == 0)
                        laplacian_kernel = 4;
                    else if (m == 0 || n == 0)
                        laplacian_kernel = -1;
                    else
                        laplacian_kernel = 0;

                    toplam += gray * laplacian_kernel;
                }
            }

            int ortalama = toplam;

            if (ortalama < 0){
                ortalama = 0;
            }
            if (ortalama > 255){
                ortalama = 255;
            }

            islenmisQim.setPixelColor(w, h, QColor(ortalama, ortalama, ortalama));
        }
    }


    qim=islenmisQim;

    qgscene.clear();

    qpixmap = QPixmap::fromImage( islenmisQim );
    qgscene.addPixmap( qpixmap );
    ui->graphicsView->setScene( &qgscene );

    // Çıktı: Nesnelerin kenarları belirginleşiyor, düz alanlar koyulaşıyor.

}
