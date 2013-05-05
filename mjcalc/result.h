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

#ifndef MJCALC_ROUNDRESULT_H
#define MJCALC_ROUNDRESULT_H

#include <QtCore/QtGlobal>

class QDataStream;

namespace mjcalc {

static const size_t playersCount = 4;

enum Wind {
    Unspecified = -1,
    East = 0,
    South,
    West,
    North
};

class Result
{
public:
    Result();

    void addScores(int totals[playersCount]) const;
    void prepareNextRound();
    void setWinner(Wind wind);
    Wind winnerWind() const;

    qint32 operator[] (Wind player) const;
    qint32 &operator[] (Wind player);
    void setDeadHand(Wind player, bool state);
    bool isDeadHand(Wind player) const;

    size_t playerPos(Wind player) const;

private:
    qint32 scores[playersCount];
    qint8 winner;
    quint8 eastPlayer;
    quint8 deadHands;

    friend
    QDataStream &operator<<(QDataStream &, const Result &);
    friend
    QDataStream &operator>>(QDataStream &, Result &);
};

}

#endif // MJCALC_ROUNDRESULT_H
