#include <QtCore/QDir>
#include <QtCore/QFileInfo>

#include <QtGui/QApplication>

#include <QtDeclarative/QDeclarativeContext>

#include "game.h"
#include "mjcalcview.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Game game;
    MjCalcView wnd;
    wnd.rootContext()->setContextProperty("game", &game);

    QObject::connect(&game, SIGNAL(showAddScores()), &wnd, SLOT(showAddScores()), Qt::QueuedConnection);
    QObject::connect(&game, SIGNAL(showNewPage()), &wnd, SLOT(showNewPage()), Qt::QueuedConnection);
    QObject::connect(&game, SIGNAL(showMainPage()), &wnd, SLOT(showMainPage()), Qt::QueuedConnection);

    wnd.showNewPage();
    return app.exec();
}
