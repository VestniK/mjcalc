/*
 * Mahjong calculator is simple tool to calculate totals by hands scores.
 * Copyright (C) 2013  Sergey Vidyuk <sir.vestnik@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "mjcalcview.h"

#include <QtCore/QFileInfo>
#include <QtCore/QUrl>

#include <QtGui/QApplication>

static QUrl getResource(const QString &name)
{
#ifdef BLACKBERRY
    return QUrl::fromLocalFile(QFileInfo("app/native/share/mjcalc/" + name).absoluteFilePath());
#else
    return QUrl::fromLocalFile(QFileInfo(qApp->applicationDirPath() + "/../share/mjcalc/" + name).absoluteFilePath());
#endif
}

MjCalcView::MjCalcView(QWidget* parent): QDeclarativeView(parent)
{
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);
    viewport()->setAttribute(Qt::WA_OpaquePaintEvent);
    viewport()->setAttribute(Qt::WA_NoSystemBackground);
    setResizeMode(QDeclarativeView::SizeRootObjectToView);
}

MjCalcView::~MjCalcView()
{
}

void MjCalcView::showNewPage()
{
    setSource(getResource("new.qml"));
    showFullScreen();
}

void MjCalcView::showAddScores()
{
    setSource(getResource("addResults.qml"));
    showFullScreen();
}

void MjCalcView::showMainPage()
{
    setSource(getResource("main.qml"));
    showFullScreen();
}
