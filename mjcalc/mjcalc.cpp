#include <QtCore/QDir>
#include <QtCore/QFileInfo>

#include <QtGui/QApplication>

#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeContext>

#include "resultcontroller.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QDir::addSearchPath(
        "qml",
        app.applicationDirPath() + "/../share/mjcalc"
    );
    ResultController resultController;
    QDeclarativeView wnd;
    wnd.rootContext()->setContextProperty("resultController", &resultController);
    wnd.setSource(QUrl::fromLocalFile(QFileInfo("qml:addResults.qml").absoluteFilePath()));
    wnd.setResizeMode(QDeclarativeView::SizeRootObjectToView);
    wnd.show();
    return app.exec();
}
