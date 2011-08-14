#include <QtGui/QApplication>
#include <QtGui/QWidget>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget wnd;
    wnd.show();
    return app.exec();
}
