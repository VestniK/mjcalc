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
    /// @todo Drop old scores and start new game score desk
    emit showMainPage();
}

void Game::addScore()
{
    /// @todo add results
    qDebug("east : %d", mCurrentRound->eastHandScore());
    qDebug("south: %d", mCurrentRound->southHandScore());
    qDebug("west : %d", mCurrentRound->westHandScore());
    qDebug("north: %d", mCurrentRound->northHandScore());
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
