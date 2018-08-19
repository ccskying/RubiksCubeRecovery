#include "ccubetablewig.h"

CCubeTableWig::CCubeTableWig(QWidget *parent) : QTableWidget(parent)
{
    bkgRed.setColor(Qt::GlobalColor::red);
    bkgOrange.setColor(QColor(255,165,0));
    bkgBlue.setColor(QColor(0,162,232));
    bkgGreen.setColor(Qt::GlobalColor::green);
    bkgYellow.setColor(Qt::GlobalColor::yellow);
    bkgWhite.setColor(Qt::GlobalColor::white);
    //只设置颜色不能用，与直接使用构造函数创建相比差了一个样式
    bkgRed.setStyle(Qt::SolidPattern);
    bkgOrange.setStyle(Qt::SolidPattern);
    bkgBlue.setStyle(Qt::SolidPattern);
    bkgGreen.setStyle(Qt::SolidPattern);
    bkgYellow.setStyle(Qt::SolidPattern);
    bkgWhite.setStyle(Qt::SolidPattern);
    //初始化表格
    setColumnCount(12);
    setRowCount(9);
    for(int i = 0; i < columnCount(); i++)
    {
        setColumnWidth(i,50);
    }
    for(int i = 0; i < rowCount(); i++)
    {
        setRowHeight(i,50);
    }
    InitShowCube();

}

void CCubeTableWig::InitShowCube()
{

    //橙面
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem;
            pItem->setBackground(bkgOrange);
            QString str;
            str.sprintf("%d,%d,%d",i,j,0);
            pItem->setText(str);
            setItem(6-1-j,3-1-i,pItem);
        }
    }
    //红色
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem;
            pItem->setBackground(bkgRed);
            QString str;
            str.sprintf("%d,%d,%d",i,j,2);
            pItem->setText(str);
            setItem(6-1-j,6+i,pItem);
        }
    }
    //黄面
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem;
            pItem->setBackground(bkgYellow);
            QString str;
            str.sprintf("%d,%d,%d",i,2,j);
            pItem->setText(str);
            setItem(j,6+i,pItem);
        }
    }
    //白色
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem;
            pItem->setBackground(bkgWhite);
            QString str;
            str.sprintf("%d,%d,%d",i,0,j);
            pItem->setText(str);
            setItem(9-1-j,6+i,pItem);
        }
    }
    //绿色
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem;
            pItem->setBackground(bkgGreen);
            QString str;
            str.sprintf("%d,%d,%d",2,i,j);
            pItem->setText(str);
            setItem(6-1-i,12-1-j,pItem);
        }
    }
    //蓝色
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            QTableWidgetItem *pItem = new QTableWidgetItem;
            pItem->setBackground(bkgBlue);
            QString str;
            str.sprintf("%d,%d,%d",0,i,j);
            pItem->setText(str);
            setItem(6-1-i,3+j,pItem);
        }
    }

//    QTableWidgetItem *pItem = new QTableWidgetItem;
//    pItem->setBackground(bkgRed);
//    setItem(0,0,pItem);
//    QTableWidgetItem *pItem2 = new QTableWidgetItem;
//    pItem2->setBackground(bkgRed);
//    setItem(1,7,pItem2);


}

void CCubeTableWig::ShowCube(Cube *pCubeData)
{
    if(pCubeData == NULL) return;
    //橙色
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[i][j][0].arrColor[k][1] == orange)
                    item(6-1-j,3-1-i)->setBackground(ColorToBrush(pCubeData->arrCube[i][j][0].arrColor[k][0]));
            }
        }
    }
    //红色
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[i][j][2].arrColor[k][1] == red)
                    item(6-1-j,6+i)->setBackground(ColorToBrush(pCubeData->arrCube[i][j][2].arrColor[k][0]));
            }
        }
    }
    //黄色
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[i][2][j].arrColor[k][1] == yellow)
                    item(j,6+i)->setBackground(ColorToBrush(pCubeData->arrCube[i][2][j].arrColor[k][0]));
            }
        }
    }
    //白色
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[i][0][j].arrColor[k][1] == white)
                    item(9-1-j,6+i)->setBackground(ColorToBrush(pCubeData->arrCube[i][0][j].arrColor[k][0]));
            }
        }
    }
    //绿色
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[2][i][j].arrColor[k][1] == green)
                    item(6-1-i,12-1-j)->setBackground(ColorToBrush(pCubeData->arrCube[2][i][j].arrColor[k][0]));
            }
        }
    }
    //蓝色
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[0][i][j].arrColor[k][1] == blue)
                    item(6-1-i,3+j)->setBackground(ColorToBrush(pCubeData->arrCube[0][i][j].arrColor[k][0]));
            }
        }
    }
}

QBrush CCubeTableWig::ColorToBrush(CubeColor BlockColor)
{
    switch (BlockColor) {
    case blue:
        return bkgBlue;
        break;
    case white:
        return bkgWhite;
        break;
    case orange:
        return bkgOrange;
        break;
    case red:
        return bkgRed;
        break;
    case yellow:
        return bkgYellow;
        break;
    case green:
        return bkgGreen;
        break;
    default:
        return bkgWhite;
        break;
    }
    //如果啥都不是，返回个白的
    return bkgWhite;
}
