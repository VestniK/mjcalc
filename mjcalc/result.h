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


#ifndef MJCALC_ROUNDRESULT_H
#define MJCALC_ROUNDRESULT_H

#include <sys/types.h>
#include <stdint.h>

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
    Result(int scores[playersCount], size_t winnerPos, size_t eastPos, uint8_t deadHandsMask);

    void addScores(int totals[playersCount]) const;
    size_t prepareNextRound();
    void setWinner(Wind wind);
    Wind winnerWind() const;

    int operator[] (Wind player) const;
    int &operator[] (Wind player);
    void setDeadHand(Wind player, bool state);
    bool isDeadHand(Wind player) const;

    size_t playerPos(Wind player) const;
    int score(size_t pos) const {return scores[pos];}
    size_t winnerPos() const {return winner;}
    size_t eastPos() const {return eastPlayer;}
    uint8_t deadHandsMask() const {return deadHands;}

private:
    int scores[playersCount];
    size_t winner;
    size_t eastPlayer;
    uint8_t deadHands;
};

}

#endif // MJCALC_ROUNDRESULT_H
