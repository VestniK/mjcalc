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

#ifndef RESULTCONTROLLER_H
#define RESULTCONTROLLER_H

#include <QtCore/QObject>

class ResultController : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ResultController)
    Q_ENUMS(Winner)
    Q_PROPERTY(Winner winner READ winner WRITE setWinner)
    Q_PROPERTY(unsigned eastHandScore READ eastHandScore WRITE setEastHandScore)
    Q_PROPERTY(unsigned southHandScore READ southHandScore WRITE setSouthHandScore)
    Q_PROPERTY(unsigned westHandScore READ westHandScore WRITE setWestHandScore)
    Q_PROPERTY(unsigned northHandScore READ northHandScore WRITE setNorthHandScore)
public:
    virtual ~ResultController();
    ResultController(QObject *parent = 0);

    enum Winner {
        Unspecified,
        East,
        South,
        West,
        North
    };

    Winner winner() const {return mWinner;}
    unsigned eastHandScore() const {return mEastHandScore;}
    unsigned southHandScore() const {return mSouthHandScore;}
    unsigned westHandScore() const {return mWestHandScore;}
    unsigned northHandScore() const {return mNorthHandScore;}

public slots:
    void addScore();

    void setWinner(Winner val) {mWinner = val;}
    void setEastHandScore(unsigned val) {mEastHandScore = val;}
    void setSouthHandScore(unsigned val) {mSouthHandScore = val;}
    void setWestHandScore(unsigned val) {mWestHandScore = val;}
    void setNorthHandScore(unsigned val) {mNorthHandScore = val;}

private:
    Winner mWinner;
    unsigned mEastHandScore;
    unsigned mSouthHandScore;
    unsigned mWestHandScore;
    unsigned mNorthHandScore;
};

#endif // RESULTCONTROLLER_H
