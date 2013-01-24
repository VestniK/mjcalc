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


#include "roundresult.h"

using namespace mjcalc;

void calcTotals(const RoundResult &results, int totals[playersCount])
{
    for (size_t i = 0; i < playersCount; ++i) {
        for (size_t j = 0; j < i; ++j) {
            int debt = results.scores[i] - results.scores[j];
            if (i == results.winner)
                debt = results.scores[i];
            else if (j == results.winner)
                debt = -results.scores[j];
            if (i == results.eastPlayer || j == results.eastPlayer)
                debt *= 2;
            totals[i] += debt;
            totals[j] -= debt;
        }
    }
}

size_t calcNextEast(const RoundResult &results)
{
    return results.winner == results.eastPlayer ? results.eastPlayer : (results.eastPlayer + 1)%playersCount;
}
