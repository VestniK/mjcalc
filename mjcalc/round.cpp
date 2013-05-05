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

#include "round.h"

Round::~Round()
{
}

Round::Round(QObject *parent):
    QObject(parent)
{
    for (int wind = mjcalc::East; wind <= mjcalc::North; ++wind)
        hands[wind] = new Hand(&mResult, static_cast<mjcalc::Wind>(wind), this);
}

Hand* Round::eastHand()
{
    return hands[mjcalc::East];
}

Hand* Round::southHand()
{
    return hands[mjcalc::South];
}

Hand* Round::westHand()
{
    return hands[mjcalc::West];
}

Hand* Round::northHand()
{
    return hands[mjcalc::North];
}

int Round::winner() const
{
    return mResult.winnerWind();
}

void Round::setWinner(int val)
{
    mResult.setWinner(static_cast<mjcalc::Wind>(val));
}

void Round::startNext()
{
    mResult.prepareNextRound();
}
