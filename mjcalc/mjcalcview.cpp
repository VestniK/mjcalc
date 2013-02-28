/*
 * <one line to give the program's name and a brief idea of what it does.>
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
    setSource(QUrl::fromLocalFile(QFileInfo("qml:new.qml").absoluteFilePath()));
}

void MjCalcView::showAddScores()
{
    setSource(QUrl::fromLocalFile(QFileInfo("qml:addResults.qml").absoluteFilePath()));
}

void MjCalcView::showMainPage()
{
    setSource(QUrl::fromLocalFile(QFileInfo("qml:main.qml").absoluteFilePath()));
}
