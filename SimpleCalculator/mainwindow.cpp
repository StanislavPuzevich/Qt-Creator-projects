#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;
double num_def;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this, SLOT(digits_numbers()));   //чтобы не сохдавать на каждую кнопку метод push_button(), нажатия
    connect(ui->pushButton_1,SIGNAL(clicked()),this, SLOT(digits_numbers()));   //лучше обработать через сигналы
    connect(ui->pushButton_2,SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this, SLOT(digits_numbers()));
    connect(ui->pushButton_plusANDminus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->pushButton_division,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->pushButton_division->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()                                               //метод обработки сигнала
{
    QPushButton *button = (QPushButton*)sender();                               //в этой строке ловим сигнал и присваиваем переменной
    QString newlabel;
    double numbers;

    if(ui->Result_window->text().contains(".") && button->text() == "0")
        newlabel = ui->Result_window->text() + button->text();
    else
    {
        numbers = (ui->Result_window->text() + button->text()).toDouble();          //работаем с TextLabel, по нажатию клавиш, меняя значение
        newlabel = QString::number(numbers,'g',10);
    }

    ui->Result_window->setText(newlabel);
}

void MainWindow::on_pushButton_point_clicked()
{
    if(!(ui->Result_window->text().contains(".")))
    ui->Result_window->setText(ui->Result_window->text() + ".");
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton*)sender();
    QString newlabel;
    double numbers = 0;

    if(button->text() == "+/-")
    {
        numbers = ui->Result_window->text().toDouble();
        numbers *= -1;
    }
    else if(button->text() == "%")
    {
        numbers = ui->Result_window->text().toDouble();
        numbers /= 100;
    }

    function(newlabel,numbers);
}

void MainWindow::math_operations()
{
     QPushButton *button = (QPushButton*)sender();

     num_first = ui->Result_window->text().toDouble();

     ui->Result_window->setText("0");

     button->setChecked(true);
}

void MainWindow::on_pushButton_equal_clicked()
{
    QString newlabel;
    double result = 0, num_second;

    num_second= ui->Result_window->text().toDouble();
    if(ui->pushButton_plus->isChecked())
    {
        result = num_first + num_second;
        ui->pushButton_plus->setChecked(false);
    }
    else if (ui->pushButton_minus->isChecked())
    {
        result = num_first - num_second;
        ui->pushButton_minus->setChecked(false);
    }
    else if (ui->pushButton_mult->isChecked())
    {
        result = num_first * num_second;
        ui->pushButton_mult->setChecked(false);
    }
    else if (ui->pushButton_division->isChecked())
    {
        if(num_second == 0)
            ui->Result_window->setText("incorrect expression");
        else
            result = num_first / num_second;

        ui->pushButton_division->setChecked(false);
    }
    num_first = 0;
    function(newlabel,result);
}

void MainWindow::function(QString& newlabel,double& num)
{
    newlabel = QString::number(num,'g',10);
    ui->Result_window->setText(newlabel);
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_division->setChecked(false);

    num_first = 0;
    ui->Result_window->setText("0");
}
