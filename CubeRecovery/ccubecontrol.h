//魔方控制函数
//旋转面，旋转整个魔方
#ifndef CCUBECONTROL_H
#define CCUBECONTROL_H

#include "cubeoperations.h"

//初始化魔方
static bool InitCube(Cube *pCubeData);
//初始化操作函数列表
static bool InitFunctionList(bool (*pFun[18])(Cube*));

static bool R(Cube *pCubeData);
static bool F(Cube *pCubeData);
static bool U(Cube *pCubeData);
static bool L(Cube *pCubeData);
static bool D(Cube *pCubeData);
static bool B(Cube *pCubeData);
///////////////////////////////////
static bool Rb(Cube *pCubeData);
static bool Fb(Cube *pCubeData);
static bool Ub(Cube *pCubeData);
static bool Lb(Cube *pCubeData);
static bool Db(Cube *pCubeData);
static bool Bb(Cube *pCubeData);

bool R(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    greenTrun(pCubeData);
    return true;
}
bool F(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    redTurn(pCubeData);
    return true;
}
bool U(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    yellowTurn(pCubeData);
    return true;
}
bool L(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    blueTurn(pCubeData);
    return true;
}
bool D(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    whiteTurn(pCubeData);
    return true;
}
bool B(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    orangeTurn(pCubeData);
    return true;
}

//////////////////////


bool Rb(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    greenTrunB(pCubeData);
    return true;
}

bool Fb(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    redTurnB(pCubeData);
    return true;
}

bool Ub(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    yellowTurnB(pCubeData);
    return true;
}

bool Lb(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    blueTurnB(pCubeData);
    return true;
}

bool Bb(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    orangeTurnB(pCubeData);
    return true;
}
bool Db(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    whiteTurnB(pCubeData);
    return true;
}

bool InitCube(Cube *pCubeData)
{
    //if(pCubeData != NULL) return false;
    //分配整个魔方的空间
//    pCubeData = (Cube*)malloc(sizeof(Cube));
    memset(pCubeData,0,sizeof(Cube));
    //初始化顶面和前面标记
    pCubeData->TopColor = yellow;
    pCubeData->FromtColor = red;
    pCubeData->RightColor = green;
    //橙面
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[i][j][0].arrColor[0][0] = orange;
            pCubeData->arrCube[i][j][0].arrColor[0][1] = orange;
        }
    }
    //红面
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[i][j][2].arrColor[0][0] = red;
            pCubeData->arrCube[i][j][2].arrColor[0][1] = red;
        }
    }
    //黄面
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[i][2][j].arrColor[1][0] = yellow;
            pCubeData->arrCube[i][2][j].arrColor[1][1] = yellow;
        }
    }
    //白色
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[i][0][j].arrColor[1][0] = white;
            pCubeData->arrCube[i][0][j].arrColor[1][1] = white;
        }
    }
    //绿面
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[2][i][j].arrColor[2][0] = green;
            pCubeData->arrCube[2][i][j].arrColor[2][1] = green;
        }
    }
    //蓝面
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[0][i][j].arrColor[2][0] = blue;
            pCubeData->arrCube[0][i][j].arrColor[2][1] = blue;
        }
    }

    return true;
}



bool InitFunctionList(bool (*pFun[])(Cube *))
{
    pFun[0] = R;
    pFun[1] = L;
    return false;
}





#endif // CCUBECONTROL_H
