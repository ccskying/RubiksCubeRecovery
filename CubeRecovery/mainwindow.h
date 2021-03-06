#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox.h>
#include <QTextEdit>
#include "ccubecontrol.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Cube CubeData;
    QTextEdit* pEditOpLog;//operation log

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void WriteOperationLog(QString strOperation);
    QString ColorToQString(CubeColor BlockColor);
    void InitCubeCoordinate(Cube CubeData);

    void on_Bt_ShowCube_clicked();
    void on_Bt_InitCube_clicked();
    //purpose: to initialize a cube use random operations.
    //input: n: use how many operaions to initialize a random cube.
    void InitCube_Random(int n);undifined
    //operations
    void on_Bt_TurnR_clicked();
    void on_Bt_TurnF_clicked();
    void on_Bt_TurnD_clicked();

    void on_Bt_TurnL_clicked();
    void on_Bt_TurnB_clicked();
    void on_Bt_TurnU_clicked();

//////////////////////////////////////

    void on_Bt_TrunFb_clicked();
    void on_Bt_TurnDb_clicked();

    void on_Bt_TurnLb_clicked();
    void on_Bt_TurnUb_clicked();
    void on_Bt_TurnBb_clicked();

    void on_Bt_TurnRb_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
