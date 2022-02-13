#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void digits_numbers();
    void on_pushButton_point_clicked();
    void operations();
    void on_pushButton_equal_clicked();
    void math_operations();
    void function(QString& ,double& );
    void on_pushButton_AC_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
