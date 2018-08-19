#ifndef CCUBETABLEWIG_H
#define CCUBETABLEWIG_H

#include <QObject>
#include <QWidget>
#include <QTableWidget>

#include "cubedata.h"

class CCubeTableWig : public QTableWidget
{
    Q_OBJECT
public:
    //背景颜色设成全局变量，这样只要一次初始化，全程可以用
    QBrush bkgRed;
    QBrush bkgOrange;
    QBrush bkgBlue;
    QBrush bkgGreen;
    QBrush bkgYellow;
    QBrush bkgWhite;

    explicit CCubeTableWig(QWidget *parent = 0);
    //初始化，创建需要用到的单元格对象和第一次颜色填充
    void InitShowCube();
    //按照当前三维数组状态，展示到表格背景
    void ShowCube(Cube *pCubeData);
    //需要一个函数将颜色枚举类翻译为QBrush对象
    QBrush ColorToBrush(CubeColor BlockColor);

signals:

public slots:
};

#endif // CCUBETABLEWIG_H
