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

#ifndef HAND_H
#define HAND_H

#include <QtCore/QObject>

#include <mjcalc/result.h>

class Hand : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Hand)
    Q_PROPERTY(int score READ score WRITE setScore NOTIFY scoreChanged)
    Q_PROPERTY(bool dead READ dead WRITE setDead NOTIFY stateChanged)
public:
    Hand(mjcalc::Result *res, mjcalc::Wind wind, QObject *parent = 0);
    virtual ~Hand();

    int score() const;
    bool dead() const;
    void setScore(int val);
    void setDead(bool val);

signals:
    void scoreChanged(int val);
    void stateChanged(bool deadHand);

private:
    mjcalc::Result *result;
    mjcalc::Wind wind;
};

#endif // HAND_H
