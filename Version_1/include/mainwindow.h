/*----------------------------------------------------------------------
Copyright [09.28.2018] by [cgcodeboy]
Distributed under the LGPL License(http://www.gnu.org/licenses/lgpl.html)
-----------------------------------------------------------------------*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDir>

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

    void on_layout_Gen_BT_clicked();

    void on_constant_Gen_BT_clicked();

    void on_gradient_Gen_BT_clicked();

    void on_perlin_Gen_BT_clicked();

    void on_radial_Gen_BT_clicked();

    void on_voronoi_Gen_BT_clicked();

    void on_simple_Con_BT_clicked();

    void on_terrace_Filter_BT_clicked();

    void on_complex_Con_BT_clicked();

    void on_blur_Filter_BT_clicked();

    void on_clamp_Filter_BT_clicked();

    void on_noise_Filter_BT_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
