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

#include "resultcontroller.h"

ResultController::~ResultController()
{
}

ResultController::ResultController(QObject *parent):
    QObject(parent),
    mEastHandScore(0),
    mSouthHandScore(0),
    mWestHandScore(0),
    mNorthHandScore(0)
{
}

void ResultController::addScore()
{
    qDebug("east = %u", mEastHandScore);
    qDebug("south = %u", mSouthHandScore);
    qDebug("west = %u", mWestHandScore);
    qDebug("north = %u", mNorthHandScore);
}
