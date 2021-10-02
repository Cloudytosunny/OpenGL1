#include "helloopengl.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloOpenGL w;
    w.show();

    return a.exec();
}
