#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QList>
#include <QString>
#include <QStyle>
#include <QPainter>

int TOTAL_GAMES = 0;
int WIN = 0;
int DRAW = 0;
int LOSE = 0;

QPixmap vFlip(const QPixmap &original)
{
    QPixmap flipped(original.size());
    flipped.fill(Qt::transparent);
    QPainter painter(&flipped);
    painter.translate(flipped.width() / 2, flipped.height() / 2);
    painter.rotate(180);
    painter.drawPixmap(-original.rect().center(), original);
    painter.end();

    return flipped;
}

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void handle_result(int p_choice, Ui::MainWindow* ui){
    TOTAL_GAMES++;
    ui->total_games->setText(QString("Games: %1").arg(TOTAL_GAMES));

    int c_choice = rand()%3;
    int diff = p_choice - c_choice;
    ui->cpu_display->setText("");
    QPixmap rock_pixmap(":/assets/rock.png");
    QPixmap paper_pixmap(":/assets/paper.png");
    QPixmap scissors_pixmap(":/assets/scissors.png");
    QPixmap load_pixmap;
    rock_pixmap = rock_pixmap.scaledToHeight(ui->cpu_display->height());
    paper_pixmap = paper_pixmap.scaledToHeight(ui->cpu_display->height());
    scissors_pixmap = scissors_pixmap.scaledToHeight(ui->cpu_display->height());

    switch(c_choice){
    case 0:
        load_pixmap = vFlip(rock_pixmap);
        break;
    case 1:
        load_pixmap = vFlip(paper_pixmap);
        break;
    case 2:
        load_pixmap = vFlip(scissors_pixmap);
        break;
    }
    ui->cpu_display->setPixmap(load_pixmap);

    switch (diff){
    case 0:
        LOSE++;
        ui->display->setText("It's a draw");
        ui->display->setProperty("result", "draw");
        ui->display->style()->unpolish(ui->display);
        ui->display->style()->polish(ui->display);
        break;
    case -1:
    case 2:
        DRAW++;
        ui->display->setText("I win");
        ui->display->setProperty("result", "lose");
        ui->display->style()->unpolish(ui->display);
        ui->display->style()->polish(ui->display);
        break;
    default:
        WIN++;
        ui->display->setText("You win");
        ui->display->setProperty("result", "win");
        ui->display->style()->unpolish(ui->display);
        ui->display->style()->polish(ui->display);
        break;
    }
    ui->score->setText(QString("W: %1% D: %2% L:%3%").arg(WIN*100/TOTAL_GAMES).arg(DRAW*100/TOTAL_GAMES).arg(LOSE*100/TOTAL_GAMES));
}

void MainWindow::on_button_rock_clicked(){
    handle_result(0, ui);
}

void MainWindow::on_button_paper_clicked(){
    handle_result(1, ui);
}


void MainWindow::on_button_scissors_clicked(){
    handle_result(2, ui);
}

void MainWindow::on_cpu_display_customContextMenuRequested(const QPoint &pos)
{

}

