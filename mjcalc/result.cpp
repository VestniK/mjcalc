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

#include<cassert>

#include "result.h"

using namespace mjcalc;

static inline
bool checkBit(quint8 bt, int bitPos)
{
    return (bt & (1 << bitPos)) != 0;
}

Result::Result(): eastPlayer(0), winner(static_cast<quint8>(Unspecified)), deadHands(0)
{
    for (size_t pos = 0; pos < playersCount; ++pos)
        scores[pos] = 0;
}

void Result::addScores(int totals[playersCount]) const
{
    assert(winner < playersCount && winner >= 0);
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

void Result::prepareNextRound()
{
    eastPlayer = winner == eastPlayer ? eastPlayer : (eastPlayer + 1)%playersCount;
    winner = static_cast<qint8>(Unspecified);
    deadHands = 0;
    for (size_t pos = 0; pos < mjcalc::playersCount; ++pos)
        scores[pos] = 0;
}

void Result::setWinner(Wind wind)
{
    if (wind < East || wind > North) {
        winner = static_cast<qint8>(Unspecified);
        return;
    }
    winner = static_cast<qint8>(playerPos(wind));
}

Wind Result::winnerWind() const
{
    if (winner >= playersCount || winner < 0)
        return Unspecified;
    return static_cast<Wind>((playersCount + winner - eastPlayer)%playersCount);
}

qint32 Result::operator[] (Wind player) const
{
    assert(player != Unspecified);
    return scores[playerPos(player)];
}

qint32 &Result::operator[] (Wind player)
{
    assert(player != Unspecified);
    return scores[playerPos(player)];
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
    quint8 mask = 1 << playerPos(player);
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

Result::State Result::state() const
{
    if (winner < 0 || winner >= playersCount)
        return NoWinner;
    for (size_t pos = 0; pos < playersCount; ++pos) {
        if (scores[pos]%2 != 0)
            return OddHand;
    }
    if (checkBit(deadHands, winner))
        return WinnerIsDead;
    if (scores[winner] < minWinnerScore)
        return SmallWinnerHand;
    return Ok;
}
