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

#include "round.h"

Round::~Round()
{
}

Round::Round(QObject *parent):
    QObject(parent)
{
}

int Round::eastHandScore() const
{
    return mResult[mjcalc::East];
}

int Round::southHandScore() const
{
    return mResult[mjcalc::South];
}

int Round::westHandScore() const
{
    return mResult[mjcalc::West];
}

int Round::northHandScore() const
{
    return mResult[mjcalc::North];
}

mjcalc::Wind Round::winner() const
{
    return mResult.winnerWind();
}

void Round::setEastHandScore(int val)
{
    mResult[mjcalc::East] = val;
}

void Round::setSouthHandScore(int val)
{
    mResult[mjcalc::South] = val;
}

void Round::setWestHandScore(int val)
{
    mResult[mjcalc::West] = val;
}

void Round::setNorthHandScore(int val)
{
    mResult[mjcalc::North] = val;
}

void Round::setWinner(mjcalc::Wind val)
{
    mResult.setWinner(val);
}
