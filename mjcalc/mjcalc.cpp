#include <QtCore/QDir>
#include <QtCore/QFileInfo>

#include <QtGui/QApplication>

#include <QtDeclarative/QDeclarativeContext>

#include "resultcontroller.h"
#include "game.h"
#include "mjcalcview.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QDir::addSearchPath(
        "qml",
        app.applicationDirPath() + "/../share/mjcalc"
    );
    ResultController resultController;
    Game game;
    MjCalcView wnd;
    wnd.rootContext()->setContextProperty("resultController", &resultController);
    wnd.rootContext()->setContextProperty("game", &game);

    QObject::connect(&game, SIGNAL(showAddScores()), &wnd, SLOT(showAddScores()), Qt::QueuedConnection);
    QObject::connect(&game, SIGNAL(showNewPage()), &wnd, SLOT(showNewPage()), Qt::QueuedConnection);
    QObject::connect(&game, SIGNAL(showMainPage()), &wnd, SLOT(showMainPage()), Qt::QueuedConnection);

    wnd.showNewPage();
    wnd.show();
    return app.exec();
}
