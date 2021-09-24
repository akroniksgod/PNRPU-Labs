#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graph.h"
#include <string>
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap backgr(":/prefix1/pics/backgr.jpeg");
    backgr = backgr.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, backgr);
    this->setPalette(palette);

    QGraphicsDropShadowEffect *eff = new QGraphicsDropShadowEffect(this);
    eff->setOffset(2, 2);
    eff->setBlurRadius(0.5);
    eff->setColor(Qt::black);
    ui->sign->setGraphicsEffect(eff);
    QGraphicsDropShadowEffect *eff2 = new QGraphicsDropShadowEffect(this);
    eff2->setOffset(1, 1);
    eff2->setBlurRadius(0.5);
    eff2->setColor(Qt::black);
    ui->date_year->setGraphicsEffect(eff2);
    QGraphicsDropShadowEffect *eff3 = new QGraphicsDropShadowEffect(this);
    eff3->setOffset(2, 2);
    eff3->setBlurRadius(1);
    eff3->setColor(Qt::white);
    ui->title->setGraphicsEffect(eff3);
}

vector<vector<int>> mat;

bool MainWindow::ScaningTable()
{
    QString inp1 = ui->sec_fir->text(), inp2 = ui->th_fir->text(), inp3 = ui->four_fir->text(), inp4 = ui->fith_fir->text(), inp5 = ui->six_fir->text(),
        inp6 = ui->fir_sec->text(), inp7 = ui->th_sec->text(), inp8 = ui->four_sec->text(), inp9 = ui->fith_sec->text(), inp10 = ui->six_sec->text(),
        inp11 = ui->fir_th->text(), inp12 = ui->sec_th->text(), inp13 = ui->four_th->text(), inp14 = ui->fith_th->text(), inp15 = ui->six_th->text(),
        inp16 = ui->fir_four->text(), inp17 = ui->sec_four->text(), inp18 = ui->th_four->text(), inp19 = ui->fith_four->text(), inp20 = ui->six_four->text(),
        inp21 = ui->fir_fith->text(), inp22 = ui->sec_fith->text(), inp23 = ui->th_fith->text(), inp24 = ui->four_fith->text(), inp25 = ui->six_fith->text(),
        inp26 = ui->fir_six->text(), inp27 = ui->sec_six->text(), inp28 = ui->th_six->text(), inp29 = ui->four_six->text(), inp30 = ui->fith_six->text();

    if (inp1.isEmpty() || inp2.isEmpty() || inp3.isEmpty() || inp3.isEmpty() || inp4.isEmpty() || inp5.isEmpty() ||
            inp6.isEmpty() || inp7.isEmpty() || inp8.isEmpty() || inp9.isEmpty() || inp10.isEmpty() || inp11.isEmpty() ||
            inp12.isEmpty() || inp13.isEmpty() || inp14.isEmpty() || inp15.isEmpty() || inp16.isEmpty() || inp17.isEmpty() ||
            inp18.isEmpty() || inp19.isEmpty() || inp20.isEmpty() || inp21.isEmpty() || inp22.isEmpty() || inp23.isEmpty() ||
            inp24.isEmpty() || inp25.isEmpty() || inp26.isEmpty() || inp27.isEmpty() || inp28.isEmpty() || inp29.isEmpty() || inp30.isEmpty())
        return 0;

    int in1 = inp1.toInt(), in2 = inp2.toInt(), in3 = inp3.toInt(), in4 = inp4.toInt(), in5 = inp5.toInt(), in6 = inp6.toInt(), in7 = inp7.toInt(),
              in8 = inp8.toInt(), in9 = inp9.toInt(), in10 = inp10.toInt(), in11 = inp11.toInt(), in12 = inp12.toInt(), in13 = inp13.toInt(),
              in14 = inp14.toInt(), in15 = inp15.toInt(), in16 = inp16.toInt(), in17 = inp17.toInt(), in18 = inp18.toInt(), in19 = inp19.toInt(),
              in20 = inp20.toInt(), in21 = inp21.toInt(), in22 = inp22.toInt(), in23 = inp23.toInt(), in24 = inp24.toInt(), in25 = inp25.toInt(),
              in26 = inp26.toInt(), in27 = inp27.toInt(), in28 = inp28.toInt(), in29 = inp29.toInt(), in30 = inp30.toInt();

    mat = {{ INT_MAX, in1, in2, in3, in4, in5 },
           { in6, INT_MAX, in7, in8, in9, in10 },
           { in11, in12, INT_MAX, in13, in14, in15 },
           { in16, in17, in18, INT_MAX, in19, in20 },
           { in21, in22, in23, in24, INT_MAX, in25 },
           { in26, in27, in28, in29, in30, INT_MAX}};
    return 1;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete window; 
}

void MainWindow::on_run_clicked()
{
    if (!ScaningTable())
        return;    
    /*ofstream fout;
    fout.open("forMatrix.txt");
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (mat[i][j] != INT_MAX)
                fout << mat[i][j] << " ";
            else
                fout << 0 << " ";
        }
        fout << endl;
    }
    fout.close();   */

    window = new Graph(this);
    window->setWindowTitle("Kommivoyager");
    window->show();
}
