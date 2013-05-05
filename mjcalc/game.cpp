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

#include "game.h"
#include "round.h"

Game::~Game()
{
}

Game::Game(mjcalc::PersistantStore *store, QObject *parent): QObject(parent), mStore(store)
{
    mCurrentRound = new Round(this);
    QList<mjcalc::Result> storedResults;
    if (!mStore->load(mPlayers, storedResults)) {
        for (int i = 0; i < mjcalc::playersCount; ++i)
            mPlayers[i].clear();
        return;
    }
    mResults.setResults(storedResults);
    mjcalc::Result next = storedResults.back();
    next.prepareNextRound();
    mCurrentRound->setResult(next);
}

void Game::start()
{
    mResults.clear();
    mStore->reset(mPlayers);
    emit showMainPage();
}

void Game::addScore()
{
    qDebug(
        "Game::addScore(): e: %d; s:%d; w:%d; n:%d",
        mCurrentRound->result()[mjcalc::East],
        mCurrentRound->result()[mjcalc::South],
        mCurrentRound->result()[mjcalc::West],
        mCurrentRound->result()[mjcalc::North]
    );
    mResults.addRoundResults(mCurrentRound->result());
    mStore->storeResult(mCurrentRound->result());
    mCurrentRound->startNext();
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

bool Game::isEmpty() const
{
    return mResults.rowCount() == 0;
}
