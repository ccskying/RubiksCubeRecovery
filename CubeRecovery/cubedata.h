/*
文件名：cubedata.h
用途：定义魔方的基础数据结构
 */


#ifndef CCUBEDATA_H
#define CCUBEDATA_H

#include <stdio.h>

typedef enum CubeColor
{
    blue = -3,
    white = -2,
    orange = -1,
    nullcolor = 0,
    red = 1,    
    yellow = 2,
    green = 3,



}CubeColor;
//一个块，包含2-3个面
//只标记有颜色的面，空白面为nullcolor
typedef struct Block
{
    CubeColor arrColor[3][2];
}Block;
////中轴对象，用于维护中块链表
//typedef struct CubeCenter
//{
//    Block *pCenter;

//}CubeCenter;
//魔方对象，包含顶面，前面，右面，中轴标识，以及整个魔方的状态
//标记三个面是为了简化算法，在需要查找面时可以直接取反找到对面
//这三个面用于确定执行公式的坐标
//魔方摆放的坐标始终不变，这样不需要动三维数组的坐标系
typedef struct Cube{
    CubeColor TopColor;
    CubeColor FromtColor;
    CubeColor RightColor;
    Block arrCube[3][3][3];
//    CubeCenter mCenter;
}Cube;





//一个方块的面
//typedef struct BlockSide
//{
//    int Color;//颜色
//    int directSide;//朝向
//}BlockSide;
//中块，包含关键的链表
//typedef struct SideCenter
//{
//    int Color;
//    Block *pBlock;
//}SideCenter;

////轴块
//typedef struct CenterBlock
//{


//    SideCenter* parrBcenters[6];//把6个面的中块放在一个数组里

//    //分别定义6个中块的指针方便调用，本质还是数组中的一个变量
//    SideCenter *pBRed;/* = &arrBcenters[0];*///红面中块
//    SideCenter *pBOrange;/* = &arrBcenters[1];*///橙面中块
//    SideCenter *pBBlue;/* = &arrBcenters[2];*///蓝面中块
//    SideCenter *pBGreen;/* = &arrBcenters[3];*///绿面中块
//    SideCenter *pBYellow;/* = &arrBcenters[4];*///黄面中块
//    SideCenter *pBWhite;/* = &arrBcenters[5];*///白面中块

//    //定义顶面和前面的标记，用于指示几个中块的朝向
//    SideCenter *pBTop/* = pBYellow*/;
//    SideCenter *pBFromt/* = pBRed*/;
//}CenterBlock;

//整个魔方的状态
//class CCubeData
//{
//private:
//    //Block arrCube[3][3][3];
//    //尝试三维循环链表的解决方案
//    CenterBlock BCenter;//轴块


//public:
//    CCubeData();
//};





#endif // CCUBEDATA_H
