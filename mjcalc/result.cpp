/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2011  Sergey Vidyuk <sir.vestnik@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include<cassert>

#include "result.h"

using namespace mjcalc;

Result::Result(): eastPlayer(0), winner(static_cast<size_t>(Unspecified))
{
    for (size_t pos = 0; pos < mjcalc::playersCount; ++pos)
        scores[pos] = 0;
}

void Result::addScores(int totals[playersCount]) const
{
    assert(winner < playersCount);
    for (size_t i = 0; i < playersCount; ++i) {
        for (size_t j = 0; j < i; ++j) {
            int debt = scores[i] - scores[j];
            if (i == winner)
                debt = scores[i];
            else if (j == winner)
                debt = -scores[j];
            if (i == eastPlayer || j == eastPlayer)
                debt *= 2;
            totals[i] += debt;
            totals[j] -= debt;
        }
    }
}

size_t Result::getNextEast() const
{
    return winner == eastPlayer ? eastPlayer : (eastPlayer + 1)%playersCount;
}

void Result::setWinner(Wind wind)
{
    if (wind == Unspecified) {
        winner = static_cast<size_t>(Unspecified);
        return;
    }
    winner = (eastPlayer + static_cast<size_t>(wind))%playersCount;
}

Wind Result::winnerWind() const
{
    if (winner >= playersCount)
        return Unspecified;
    return static_cast<Wind>((playersCount + winner - eastPlayer)%playersCount);
}

int Result::operator[] (Wind player) const
{
    assert(player != Unspecified);
    return scores[(eastPlayer + player)%playersCount];
}

int &Result::operator[] (Wind player)
{
    assert(player != Unspecified);
    return scores[(eastPlayer + player)%playersCount];
}

