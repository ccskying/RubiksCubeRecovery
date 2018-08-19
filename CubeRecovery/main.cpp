#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    char *pstr = "hello";
    int n = strlen(pstr);
    printf("%d",n);

//    bool (*p)(Cube*);
//    p = R;
    EOF;




    MainWindow w;
    w.show();
    //清理内存
//    if(pCubeData != NULL)
//    {
//        free(pCubeData);
//        pCubeData = NULL;
//    }

    return a.exec();
}
