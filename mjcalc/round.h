/*
 * <one line to give the program's name and a brief idea of what it does.>
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

#include "result.h"

using namespace mjcalc;

class Round : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Round)
    Q_PROPERTY(Wind winner READ winner WRITE setWinner)
    Q_PROPERTY(int eastHandScore READ eastHandScore WRITE setEastHandScore)
    Q_PROPERTY(int southHandScore READ southHandScore WRITE setSouthHandScore)
    Q_PROPERTY(int westHandScore READ westHandScore WRITE setWestHandScore)
    Q_PROPERTY(int northHandScore READ northHandScore WRITE setNorthHandScore)
public:
    virtual ~Round();
    explicit Round(QObject *parent = 0);

    mjcalc::Wind winner() const;
    int eastHandScore() const;
    int southHandScore() const;
    int westHandScore() const;
    int northHandScore() const;

    const mjcalc::Result &result() const {return mResult;}

public slots:
    void setWinner(mjcalc::Wind val);
    void setEastHandScore(int val);
    void setSouthHandScore(int val);
    void setWestHandScore(int val);
    void setNorthHandScore(int val);

private:
    mjcalc::Result mResult;
};

#endif // RESULTCONTROLLER_H
