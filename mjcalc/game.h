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

#ifndef GAME_H
#define GAME_H

#include <QtCore/QObject>
#include <QtCore/QString>

#include "round.h"
#include "resultstorage.h"

class Game : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Game)
    // Access players by ID
    Q_PROPERTY(QString player1 READ player1 WRITE setPlayer1)
    Q_PROPERTY(QString player2 READ player2 WRITE setPlayer2)
    Q_PROPERTY(QString player3 READ player3 WRITE setPlayer3)
    Q_PROPERTY(QString player4 READ player4 WRITE setPlayer4)
    // Access players by wind
    Q_PROPERTY(QString eastPlayer READ eastPlayer CONSTANT)
    Q_PROPERTY(QString southPlayer READ southPlayer CONSTANT)
    Q_PROPERTY(QString westPlayer READ westPlayer CONSTANT)
    Q_PROPERTY(QString northPlayer READ northPlayer CONSTANT)
    // Current round
    Q_PROPERTY(QObject *currentRound READ currentRound CONSTANT)
    Q_PROPERTY(QObject *results READ results CONSTANT)

public:
    explicit Game(QObject *parent = 0);
    virtual ~Game();

    const QString &player1() const {return mPlayers[0];}
    const QString &player2() const {return mPlayers[1];}
    const QString &player3() const {return mPlayers[2];}
    const QString &player4() const {return mPlayers[3];}

    const QString &eastPlayer() const;
    const QString &southPlayer() const;
    const QString &westPlayer() const;
    const QString &northPlayer() const;

    Round *currentRound() {return mCurrentRound;}
    QAbstractItemModel *results() {return &mResults;}

public slots:
    void setPlayer1(const QString &val) {mPlayers[0] = val;}
    void setPlayer2(const QString &val) {mPlayers[1] = val;}
    void setPlayer3(const QString &val) {mPlayers[2] = val;}
    void setPlayer4(const QString &val) {mPlayers[3] = val;}

    void start();
    void addScore();

signals:
    void showNewPage();
    void showAddScores();
    void showMainPage();

private:
    QString mPlayers[mjcalc::playersCount];
    Round *mCurrentRound;
    ResultStorage mResults;
};

#endif // GAME_H
