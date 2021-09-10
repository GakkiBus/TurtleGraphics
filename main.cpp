#include "parser.h"
#include "mainwindow.h"

#include <QtWidgets>

#include <iostream>
#include <fstream>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.show();
    return app.exec();
}
