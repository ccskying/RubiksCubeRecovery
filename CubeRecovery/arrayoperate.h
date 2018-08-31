/*
 * Purpose: turn the arrat which saving the data of one surface of the cube 90° clockwise or anticlockwise
 * 这个头文件用于定义单面旋转函数
*/
#ifndef ARRAYOPERATE_H
#define ARRAYOPERATE_H

#include "cubedata.h"

//clockwide
static void ArrTurnCW(Block arrCube[3][3]);
//anticlockwide
static void ArrTurnACW(Block arrCube[3][3]);

void ArrTurnCW(Block arrCube[3][3])
{
    Block arrTmp[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrTmp[2-j][i] = arrCube[i][j];
        }
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrCube[i][j] = arrTmp[i][j];
        }
    }
}
void ArrTurnACW(Block arrCube[3][3])
{
    Block arrTmp[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrTmp[j][2-i] = arrCube[i][j];
        }
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrCube[i][j] = arrTmp[i][j];
        }
    }
}

#endif // ARRAYOPERATE_H
