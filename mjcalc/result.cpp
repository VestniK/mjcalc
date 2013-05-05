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

static inline
bool checkBit(uint8_t bt, int bitPos)
{
    return (bt & (1 << bitPos)) != 0;
}

Result::Result(): eastPlayer(0), winner(static_cast<size_t>(Unspecified)), deadHands(0)
{
    for (size_t pos = 0; pos < playersCount; ++pos)
        scores[pos] = 0;
}

Result::Result(int scores[playersCount], size_t winnerPos, size_t eastPos, uint8_t deadHandsMask) : eastPlayer(eastPos), winner(winnerPos), deadHands(deadHandsMask)
{
    for (size_t pos = 0; pos < playersCount; ++pos)
        this->scores[pos] = scores[pos];
}

void Result::addScores(int totals[playersCount]) const
{
    assert(winner < playersCount);
    for (size_t i = 0; i < playersCount; ++i) {
        if (checkBit(deadHands, i))
            continue;
        for (size_t j = 0; j < i; ++j) {
            if (checkBit(deadHands, j))
                continue;
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

size_t Result::prepareNextRound()
{
    eastPlayer = winner == eastPlayer ? eastPlayer : (eastPlayer + 1)%playersCount;
    winner = static_cast<size_t>(Unspecified);
    deadHands = 0;
    for (size_t pos = 0; pos < mjcalc::playersCount; ++pos)
        scores[pos] = 0;
}

void Result::setWinner(Wind wind)
{
    if (wind < East || wind > North) {
        winner = static_cast<size_t>(Unspecified);
        return;
    }
    winner = playerPos(wind);
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
    return scores[playerPos(player)];
}

int &Result::operator[] (Wind player)
{
    assert(player != Unspecified);
    return scores[(eastPlayer + player)%playersCount];
}

size_t Result::playerPos(Wind player) const
{
    if (player == Unspecified)
        return static_cast<size_t>(-1);
    return (eastPlayer + static_cast<size_t>(player))%playersCount;
}

void Result::setDeadHand(Wind player, bool state)
{
    assert(player != Unspecified);
    uint8_t mask = 1 << playerPos(player);
    if (state)
        deadHands |= mask;
    else
        deadHands &= ~mask;
}

bool Result::isDeadHand(Wind player) const
{
    assert(player != Unspecified);
    return checkBit(deadHands, playerPos(player));
}
