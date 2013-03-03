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

// TODO: Move all index to wind calculation related code into roundresult

Round::~Round()
{
}

Round::Round(QObject *parent):
    QObject(parent)
{
    for (size_t pos = 0; pos < mjcalc::playersCount; ++pos)
        result.scores[pos] = 0;
    result.winner = Unspecified;
    result.eastPlayer = 0;
}

int Round::eastHandScore() const
{
    return result.scores[result.eastPlayer];
}

int Round::southHandScore() const
{
    return result.scores[(result.eastPlayer + South)%mjcalc::playersCount];
}

int Round::westHandScore() const
{
    return result.scores[(result.eastPlayer + West)%mjcalc::playersCount];
}

int Round::northHandScore() const
{
    return result.scores[(result.eastPlayer + North)%mjcalc::playersCount];
}

Round::Winner Round::winner() const
{
    if (result.winner < 0 || result.winner >= mjcalc::playersCount)
        return Unspecified;
    return static_cast<Round::Winner>((mjcalc::playersCount + result.winner - result.eastPlayer)%mjcalc::playersCount);
}

void Round::setEastHandScore(int val)
{
    result.scores[result.eastPlayer] = val;
}

void Round::setSouthHandScore(int val)
{
    result.scores[(result.eastPlayer + South)%mjcalc::playersCount] = val;
}

void Round::setWestHandScore(int val)
{
    result.scores[(result.eastPlayer + West)%mjcalc::playersCount] = val;
}

void Round::setNorthHandScore(int val)
{
    result.scores[(result.eastPlayer + North)%mjcalc::playersCount] = val;
}

void Round::setWinner(Round::Winner val)
{
    if (val == Unspecified) {
        result.winner = Unspecified;
        return;
    }
    result.winner = (result.eastPlayer + val)%mjcalc::playersCount;
}
