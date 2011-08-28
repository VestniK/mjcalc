#include <QtCore/QDir>
#include <QtCore/QFileInfo>

#include <QtGui/QApplication>

#include <QtDeclarative/QDeclarativeView>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QDir::addSearchPath(
        "qml",
        app.applicationDirPath() + "/../share/mjcalc"
    );
    QDeclarativeView wnd(QUrl::fromLocalFile(QFileInfo("qml:main.qml").absoluteFilePath()));
    wnd.setResizeMode(QDeclarativeView::SizeRootObjectToView);
    wnd.show();
    return app.exec();
}
