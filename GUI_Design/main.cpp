#include <QApplication>
#include <QPushButton>
#include <QProgressBar>

int main(int argc, char **argv){
    /*QApplication app (argc, argv);

    QWidget window;

    QPushButton *button = new QPushButton("Yes", &window);
    button->setGeometry(10,10,80,30);
    button->setStyleSheet("color: blue");

    window.show();

    return app.exec();*/

    QApplication myApp(argc, argv);
    QWidget window;

    QProgressBar* bar = new QProgressBar(&window);
    //bar->setRange(0,1);
    //bar->setValue(1);
    bar->setStyleSheet("::chunk{background-color: "
                      "qlineargradient(x0: 0, x2: 1,"
                      "stop: 0 green, stop: 0.6 green,"
                      "stop: 0.60001 orange, stop: 0.8 orange,"
                      "stop: 0.80001 red; stop: 1 red"
                      ")}");
    window.show();

    return myApp.exec();
}
