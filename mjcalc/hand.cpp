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

#include "hand.h"

Hand::Hand(mjcalc::Result *res, mjcalc::Wind handWind, QObject *parent): QObject(parent), result(res), wind(handWind)
{
    Q_ASSERT(handWind != mjcalc::Unspecified);
}

Hand::~Hand()
{
}

int Hand::score() const
{
    return (*result)[wind];
}

void Hand::setScore(int val)
{
    (*result)[wind] = val;
    emit scoreChanged(val);
}

bool Hand::dead() const
{
    return result->isDeadHand(wind);
}

void Hand::setDead(bool val)
{
    result->setDeadHand(wind, val);
    qDebug("void Hand::setDeadHand(%s)", val ? "true" : "false");
    emit stateChanged(val);
}
