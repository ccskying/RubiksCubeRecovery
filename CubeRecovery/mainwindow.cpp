#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pEditOpLog = this->findChild<QTextEdit*>("EditOpLog");
    pEditOpLog->insertPlainText("Operations: ");
    //初始化魔方
    bool bInitSuc = false;
    bInitSuc = InitCube(&CubeData);
    if(bInitSuc == false)
    {
        QMessageBox::warning(NULL,"warning","魔方初始化错误.");
    }
    bool (*pFun[18])(Cube*);
    InitFunctionList(pFun);
    InitCubeCoordinate(CubeData);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::WriteOperationLog(QString strOperation)
{
    static int nInit = 0;
    if(strOperation.compare("Initialization") == 0)
    {
        nInit++;
        pEditOpLog->insertPlainText("\n" + strOperation + " "+ QString::number(nInit) + " ======================\n" + "Operations:");
    }else {
        pEditOpLog->insertPlainText(strOperation + " | ");
    }
    pEditOpLog->moveCursor(QTextCursor::End);


}

QString MainWindow::ColorToQString(CubeColor BlockColor)
{
    switch (BlockColor) {
    case blue:
        return "蓝色";
        break;
    case white:
        return "白色";
        break;
    case orange:
        return "橙色";
        break;
    case red:
        return "红色";
        break;
    case yellow:
        return "黄色";
        break;
    case green:
        return "绿色";
        break;
    default:
        return "白色";
        break;
    }
    //如果啥都不是，返回个白的
    return "白色";
}

void MainWindow::InitCubeCoordinate(Cube CubeData)
{
    ui->FromtLabel->setText(ColorToQString(CubeData.FromtColor));
    ui->TopLabel->setText(ColorToQString(CubeData.TopColor));
    ui->RightLabel->setText(ColorToQString(CubeData.RightColor));
}


void MainWindow::on_Bt_ShowCube_clicked()
{
    ui->tableWidget->ShowCube(&CubeData);
}

void MainWindow::on_Bt_InitCube_clicked()
{
    InitCube(&CubeData);
    ui->tableWidget->ShowCube(&CubeData);
    WriteOperationLog("Initialization");
}

//////////////////////////////////////////////////////////

void MainWindow::on_Bt_TurnR_clicked()
{
    R(&CubeData);
    ui->tableWidget->ShowCube(&CubeData);
    WriteOperationLog("R");
}

void MainWindow::on_Bt_TurnF_clicked()
{
    F(&CubeData);
    ui->tableWidget->ShowCube(&CubeData);
}

void MainWindow::on_Bt_TurnD_clicked()
{
    D(&CubeData);
    ui->tableWidget->ShowCube(&CubeData);
}



/////////////////////////////////////

void MainWindow::on_Bt_TurnL_clicked()
{
    Lb(&CubeData);
    ui->tableWidget->ShowCube(&CubeData);
}

void MainWindow::on_Bt_TurnU_clicked()
{
    Ub(&CubeData);
    ui->tableWidget->ShowCube(&CubeData);
}

void MainWindow::on_Bt_TurnB_clicked()
{
    Bb(&CubeData);
    ui->tableWidget->ShowCube(&CubeData);
}

///////////////////////////////////////////////////////////////

void MainWindow::on_Bt_TurnRb_clicked()
{
    Rb(&CubeData);
    ui->tableWidget->ShowCube(&CubeData);
}

void MainWindow::on_Bt_TrunFb_clicked()
{
    Fb(&CubeData);
    ui->tableWidget->ShowCube(&CubeData);
}

void MainWindow::on_Bt_TurnDb_clicked()
{
    Db(&CubeData);
    ui->tableWidget->ShowCube(&CubeData);
}

////////////////////////////////////

void MainWindow::on_Bt_TurnLb_clicked()
{
    L(&CubeData);
    ui->tableWidget->ShowCube(&CubeData);
}

void MainWindow::on_Bt_TurnUb_clicked()
{
    U(&CubeData);
    ui->tableWidget->ShowCube(&CubeData);
}

void MainWindow::on_Bt_TurnBb_clicked()
{
    B(&CubeData);
    ui->tableWidget->ShowCube(&CubeData);
}

