#ifndef CUBEOPERATIONS_H
#define CUBEOPERATIONS_H

//Purpose: this file defines basic operations of the cube.

#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

#include "cubedata.h"
#include "arrayoperate.h"

/*Attention: a function called xxxTurn() means turn the surface of the cube which is in this color 90° clockwise.
//          Samely as the fuctions called xxxTurnB(), they means to turn it 90° anticlockwise.
//          The clockwise moving is based on the location when the surface is the front surface of the cube.
//
//  all of the functions in this file follows the same input and output data type
//
//  Input: data in the type of "Cube".
//  Output: whether it execute successful or not. Return ture if it success.
//
//操作函数
*/
static bool redTurn(Cube *pCubeData);
static bool greenTrun(Cube *pCubeData);
static bool yellowTurn(Cube *pCubeData);
static bool orangeTurn(Cube *pCubeData);
static bool blueTurn(Cube *pCubeData);
static bool whiteTurn(Cube *pCubeData);
///////////////
static bool redTurnB(Cube *pCubeData);
static bool greenTrunB(Cube *pCubeData);
static bool yellowTurnB(Cube *pCubeData);
static bool orangeTurnB(Cube *pCubeData);
static bool blueTurnB(Cube *pCubeData);
static bool whiteTurnB(Cube *pCubeData);

bool redTurn(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    Block arrTmp[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrTmp[i][j] = pCubeData->arrCube[i][j][2];
        }
    }
    ArrTurnRight(arrTmp);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[i][j][2] = arrTmp[i][j];
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[i][j][2].arrColor[k][1] == yellow)
                    pCubeData->arrCube[i][j][2].arrColor[k][1] = green;
                else if(pCubeData->arrCube[i][j][2].arrColor[k][1] == green)
                    pCubeData->arrCube[i][j][2].arrColor[k][1] = white;
                else if(pCubeData->arrCube[i][j][2].arrColor[k][1] == white)
                    pCubeData->arrCube[i][j][2].arrColor[k][1] = blue;
                else if(pCubeData->arrCube[i][j][2].arrColor[k][1] == blue)
                    pCubeData->arrCube[i][j][2].arrColor[k][1] = yellow;
            }

        }
    }

    return true;
}

bool greenTrun(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    Block arrTmp[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrTmp[i][j] = pCubeData->arrCube[2][i][j];
        }
    }
    ArrTurnRight(arrTmp);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[2][i][j] = arrTmp[i][j];
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[2][i][j].arrColor[k][1] == yellow)
                    pCubeData->arrCube[2][i][j].arrColor[k][1] = orange;
                else if(pCubeData->arrCube[2][i][j].arrColor[k][1] == orange)
                    pCubeData->arrCube[2][i][j].arrColor[k][1] = white;
                else if(pCubeData->arrCube[2][i][j].arrColor[k][1] == white)
                    pCubeData->arrCube[2][i][j].arrColor[k][1] = red;
                else if(pCubeData->arrCube[2][i][j].arrColor[k][1] == red)
                    pCubeData->arrCube[2][i][j].arrColor[k][1] = yellow;
            }

        }
    }
    return true;
}

bool yellowTurn(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    Block arrTmp[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrTmp[i][j] = pCubeData->arrCube[i][2][j];
        }
    }
    ArrTurnRight(arrTmp);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[i][2][j] = arrTmp[i][j];
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[i][2][j].arrColor[k][1] == red)
                    pCubeData->arrCube[i][2][j].arrColor[k][1] = green;
                else if(pCubeData->arrCube[i][2][j].arrColor[k][1] == green)
                    pCubeData->arrCube[i][2][j].arrColor[k][1] = orange;
                else if(pCubeData->arrCube[i][2][j].arrColor[k][1] == orange)
                    pCubeData->arrCube[i][2][j].arrColor[k][1] = blue;
                else if(pCubeData->arrCube[i][2][j].arrColor[k][1] == blue)
                    pCubeData->arrCube[i][2][j].arrColor[k][1] = red;
            }

        }
    }
    return true;
}

bool orangeTurn(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    Block arrTmp[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrTmp[i][j] = pCubeData->arrCube[i][j][0];
        }
    }
    ArrTurnRight(arrTmp);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[i][j][0] = arrTmp[i][j];
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[i][j][0].arrColor[k][1] == yellow)
                    pCubeData->arrCube[i][j][0].arrColor[k][1] = green;
                else if(pCubeData->arrCube[i][j][0].arrColor[k][1] == green)
                    pCubeData->arrCube[i][j][0].arrColor[k][1] = white;
                else if(pCubeData->arrCube[i][j][0].arrColor[k][1] == white)
                    pCubeData->arrCube[i][j][0].arrColor[k][1] = blue;
                else if(pCubeData->arrCube[i][j][0].arrColor[k][1] == blue)
                    pCubeData->arrCube[i][j][0].arrColor[k][1] = yellow;
            }

        }
    }
    return true;
}

bool blueTurn(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    Block arrTmp[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrTmp[i][j] = pCubeData->arrCube[0][i][j];
        }
    }
    ArrTurnRight(arrTmp);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[0][i][j] = arrTmp[i][j];
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[0][i][j].arrColor[k][1] == yellow)
                    pCubeData->arrCube[0][i][j].arrColor[k][1] = orange;
                else if(pCubeData->arrCube[0][i][j].arrColor[k][1] == orange)
                    pCubeData->arrCube[0][i][j].arrColor[k][1] = white;
                else if(pCubeData->arrCube[0][i][j].arrColor[k][1] == white)
                    pCubeData->arrCube[0][i][j].arrColor[k][1] = red;
                else if(pCubeData->arrCube[0][i][j].arrColor[k][1] == red)
                    pCubeData->arrCube[0][i][j].arrColor[k][1] = yellow;
            }

        }
    }
    return true;
}

bool whiteTurn(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    Block arrTmp[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrTmp[i][j] = pCubeData->arrCube[i][0][j];
        }
    }
    ArrTurnRight(arrTmp);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[i][0][j] = arrTmp[i][j];
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[i][0][j].arrColor[k][1] == red)
                    pCubeData->arrCube[i][0][j].arrColor[k][1] = green;
                else if(pCubeData->arrCube[i][0][j].arrColor[k][1] == green)
                    pCubeData->arrCube[i][0][j].arrColor[k][1] = orange;
                else if(pCubeData->arrCube[i][0][j].arrColor[k][1] == orange)
                    pCubeData->arrCube[i][0][j].arrColor[k][1] = blue;
                else if(pCubeData->arrCube[i][0][j].arrColor[k][1] == blue)
                    pCubeData->arrCube[i][0][j].arrColor[k][1] = red;
            }

        }
    }
    return true;
}

//////////////////

bool redTurnB(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    Block arrTmp[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrTmp[i][j] = pCubeData->arrCube[i][j][2];
        }
    }
    ArrTurnLeft(arrTmp);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[i][j][2] = arrTmp[i][j];
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[i][j][2].arrColor[k][1] == yellow)
                    pCubeData->arrCube[i][j][2].arrColor[k][1] = blue;
                else if(pCubeData->arrCube[i][j][2].arrColor[k][1] == blue)
                    pCubeData->arrCube[i][j][2].arrColor[k][1] = white;
                else if(pCubeData->arrCube[i][j][2].arrColor[k][1] == white)
                    pCubeData->arrCube[i][j][2].arrColor[k][1] = green;
                else if(pCubeData->arrCube[i][j][2].arrColor[k][1] == green)
                    pCubeData->arrCube[i][j][2].arrColor[k][1] = yellow;
            }

        }
    }

    return true;
}

bool greenTrunB(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    Block arrTmp[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrTmp[i][j] = pCubeData->arrCube[2][i][j];
        }
    }
    ArrTurnLeft(arrTmp);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[2][i][j] = arrTmp[i][j];
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[2][i][j].arrColor[k][1] == yellow)
                    pCubeData->arrCube[2][i][j].arrColor[k][1] = red;
                else if(pCubeData->arrCube[2][i][j].arrColor[k][1] == red)
                    pCubeData->arrCube[2][i][j].arrColor[k][1] = white;
                else if(pCubeData->arrCube[2][i][j].arrColor[k][1] == white)
                    pCubeData->arrCube[2][i][j].arrColor[k][1] = orange;
                else if(pCubeData->arrCube[2][i][j].arrColor[k][1] == orange)
                    pCubeData->arrCube[2][i][j].arrColor[k][1] = yellow;
            }

        }
    }
    return true;
}

bool yellowTurnB(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    Block arrTmp[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrTmp[i][j] = pCubeData->arrCube[i][2][j];
        }
    }
    ArrTurnLeft(arrTmp);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[i][2][j] = arrTmp[i][j];
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[i][2][j].arrColor[k][1] == red)
                    pCubeData->arrCube[i][2][j].arrColor[k][1] = blue;
                else if(pCubeData->arrCube[i][2][j].arrColor[k][1] == blue)
                    pCubeData->arrCube[i][2][j].arrColor[k][1] = orange;
                else if(pCubeData->arrCube[i][2][j].arrColor[k][1] == orange)
                    pCubeData->arrCube[i][2][j].arrColor[k][1] = green;
                else if(pCubeData->arrCube[i][2][j].arrColor[k][1] == green)
                    pCubeData->arrCube[i][2][j].arrColor[k][1] = red;
            }

        }
    }
    return true;
}

bool orangeTurnB(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    Block arrTmp[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrTmp[i][j] = pCubeData->arrCube[i][j][0];
        }
    }
    ArrTurnLeft(arrTmp);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[i][j][0] = arrTmp[i][j];
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[i][j][0].arrColor[k][1] == yellow)
                    pCubeData->arrCube[i][j][0].arrColor[k][1] = blue;
                else if(pCubeData->arrCube[i][j][0].arrColor[k][1] == blue)
                    pCubeData->arrCube[i][j][0].arrColor[k][1] = white;
                else if(pCubeData->arrCube[i][j][0].arrColor[k][1] == white)
                    pCubeData->arrCube[i][j][0].arrColor[k][1] = green;
                else if(pCubeData->arrCube[i][j][0].arrColor[k][1] == green)
                    pCubeData->arrCube[i][j][0].arrColor[k][1] = yellow;
            }

        }
    }
    return true;
}

bool blueTurnB(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    Block arrTmp[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrTmp[i][j] = pCubeData->arrCube[0][i][j];
        }
    }
    ArrTurnLeft(arrTmp);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[0][i][j] = arrTmp[i][j];
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[0][i][j].arrColor[k][1] == yellow)
                    pCubeData->arrCube[0][i][j].arrColor[k][1] = red;
                else if(pCubeData->arrCube[0][i][j].arrColor[k][1] == red)
                    pCubeData->arrCube[0][i][j].arrColor[k][1] = white;
                else if(pCubeData->arrCube[0][i][j].arrColor[k][1] == white)
                    pCubeData->arrCube[0][i][j].arrColor[k][1] = orange;
                else if(pCubeData->arrCube[0][i][j].arrColor[k][1] == orange)
                    pCubeData->arrCube[0][i][j].arrColor[k][1] = yellow;
            }

        }
    }
    return true;
}

bool whiteTurnB(Cube *pCubeData)
{
    if(pCubeData == NULL) return false;
    Block arrTmp[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrTmp[i][j] = pCubeData->arrCube[i][0][j];
        }
    }
    ArrTurnLeft(arrTmp);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            pCubeData->arrCube[i][0][j] = arrTmp[i][j];
            for(int k = 0; k < 3; k++)
            {
                if(pCubeData->arrCube[i][0][j].arrColor[k][1] == red)
                    pCubeData->arrCube[i][0][j].arrColor[k][1] = blue;
                else if(pCubeData->arrCube[i][0][j].arrColor[k][1] == blue)
                    pCubeData->arrCube[i][0][j].arrColor[k][1] = orange;
                else if(pCubeData->arrCube[i][0][j].arrColor[k][1] == orange)
                    pCubeData->arrCube[i][0][j].arrColor[k][1] = green;
                else if(pCubeData->arrCube[i][0][j].arrColor[k][1] == green)
                    pCubeData->arrCube[i][0][j].arrColor[k][1] = red;
            }

        }
    }
}

#endif // CUBEOPERATIONS_H
