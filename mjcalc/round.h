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

#ifndef ROUND_H
#define ROUND_H

#include <QtCore/QObject>

#include <mjcalc/result.h>
#include <mjcalc/hand.h>

class Round : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Round)
    Q_PROPERTY(int winner READ winner WRITE setWinner)
    Q_PROPERTY(QObject *eastHand READ eastHand CONSTANT)
    Q_PROPERTY(QObject *southHand READ southHand CONSTANT)
    Q_PROPERTY(QObject *westHand READ westHand CONSTANT)
    Q_PROPERTY(QObject *northHand READ northHand CONSTANT)
public:
    virtual ~Round();
    explicit Round(QObject *parent = 0);

    int winner() const;
    Hand *eastHand();
    Hand *southHand();
    Hand *westHand();
    Hand *northHand();

    void startNext();
    const mjcalc::Result &result() const {return mResult;}
    void setResult(const mjcalc::Result &val) {mResult = val;}

public slots:
    void setWinner(int val);

private:
    mjcalc::Result mResult;
    Hand *hands[mjcalc::playersCount];
};

#endif // RESULTCONTROLLER_H
