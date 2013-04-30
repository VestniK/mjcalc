#include <QtCore/QDir>
#include <QtCore/QFileInfo>

#include <QtGui/QApplication>

#include <QtDeclarative/QDeclarativeContext>

#include <mjcalc/game.h>
#include <mjcalc/mjcalcview.h>
#include <mjcalc/persistantstore.h>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    mjcalc::PersistantStore store;
    Game game(&store);
    MjCalcView wnd;
    wnd.rootContext()->setContextProperty("game", &game);

    QObject::connect(&game, SIGNAL(showAddScores()), &wnd, SLOT(showAddScores()), Qt::QueuedConnection);
    QObject::connect(&game, SIGNAL(showNewPage()), &wnd, SLOT(showNewPage()), Qt::QueuedConnection);
    QObject::connect(&game, SIGNAL(showMainPage()), &wnd, SLOT(showMainPage()), Qt::QueuedConnection);

    if (game.isEmpty())
        wnd.showNewPage();
    else
        wnd.showMainPage();
    return app.exec();
}
