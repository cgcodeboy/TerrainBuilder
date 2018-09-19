#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

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
    void on_select_BT_clicked();

    void on_connect_BT_clicked();

    void on_type1_BT_clicked();

    void on_tpye2_BT_clicked();

    void on_type3_BT_clicked();

    void on_type4_BT_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
