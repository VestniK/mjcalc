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

#include "game.h"
#include "round.h"

Game::~Game()
{
}

Game::Game(QObject *parent): QObject(parent)
{
    mCurrentRound = new Round(this);
}

void Game::start()
{
    mResults.clear();
    emit showMainPage();
}

void Game::addScore()
{
    mResults.append(mCurrentRound->result());
    mCurrentRound->startNext();
    int totals[mjcalc::playersCount] = {0, 0, 0, 0};
    /// @todo show this results to the user
    foreach (const mjcalc::Result & res, mResults) {
        res.addScores(totals);
        qDebug("%d, %d, %d, %d", totals[0], totals[1], totals[2], totals[3]);
    }
    emit showMainPage();
}

const QString& Game::eastPlayer() const
{
     return mPlayers[mCurrentRound->result().playerPos(mjcalc::East)];
}

const QString& Game::southPlayer() const
{
    return mPlayers[mCurrentRound->result().playerPos(mjcalc::South)];
}

const QString& Game::westPlayer() const
{
    return mPlayers[mCurrentRound->result().playerPos(mjcalc::West)];
}

const QString& Game::northPlayer() const
{
    return mPlayers[mCurrentRound->result().playerPos(mjcalc::North)];
}
