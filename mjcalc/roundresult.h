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

namespace mjcalc {

static const size_t playersCount = 4;

struct RoundResult
{
    int scores[playersCount];
    int winner;
    size_t eastPlayer;
};

void calcTotals(const RoundResult &results, int totals[playersCount]);
size_t calcNextEast(const RoundResult &results);

}

#endif // MJCALC_ROUNDRESULT_H
