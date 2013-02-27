#include <QtCore/QDir>
#include <QtCore/QFileInfo>

#include <QtGui/QApplication>

#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeContext>

#include "resultcontroller.h"
#include "game.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QDir::addSearchPath(
        "qml",
        app.applicationDirPath() + "/../share/mjcalc"
    );
    ResultController resultController;
    Game game;
    QDeclarativeView wnd;
    wnd.setAttribute(Qt::WA_OpaquePaintEvent);
    wnd.setAttribute(Qt::WA_NoSystemBackground);
    wnd.viewport()->setAttribute(Qt::WA_OpaquePaintEvent);
    wnd.viewport()->setAttribute(Qt::WA_NoSystemBackground);
    wnd.rootContext()->setContextProperty("resultController", &resultController);
    wnd.rootContext()->setContextProperty("game", &game);
    wnd.setSource(QUrl::fromLocalFile(QFileInfo("qml:new.qml").absoluteFilePath()));
    wnd.setResizeMode(QDeclarativeView::SizeRootObjectToView);
    wnd.show();
    return app.exec();
}
