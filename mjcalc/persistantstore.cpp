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

#include "persistantstore.h"

#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QDataStream>
#include <QtCore/QString>

namespace mjcalc {

static const quint32 formatVer = 0;
static const quint32 *namesSig = reinterpret_cast<const quint32 *>("name");
static const quint32 *resultsSig = reinterpret_cast<const quint32 *>("rslt");
static const quint32 *separatorSig = reinterpret_cast<const quint32 *>("endr");

static inline
QString getCacheFile()
{
    return QDir::home().absoluteFilePath(".mjcalc.cache");
}

PersistantStore::PersistantStore()
{
}

PersistantStore::~PersistantStore()
{
}

void PersistantStore::storeResult(const Result &res)
{
    QFile cache(getCacheFile());
    cache.open(QIODevice::Append | QIODevice::WriteOnly);
    QDataStream stm(&cache);
    stm.setVersion(QDataStream::Qt_4_8);
    qDebug("storing res: [%d, %d, %d, %d]; win: %u; east: %u; deads: %u", res.score(0), res.score(1), res.score(2), res.score(3), res.winnerPos(), res.eastPos(), quint32(res.deadHandsMask()));
    stm << quint32(res.winnerPos());
    stm << quint32(res.eastPos());
    for (size_t pos = 0; pos < playersCount; ++pos)
        stm << qint32(res.score(pos));
    stm << quint8(res.deadHandsMask());
    stm << *separatorSig;
}

void PersistantStore::reset(const QString players[playersCount])
{
    QFile cache(getCacheFile());
    cache.open(QIODevice::Truncate | QIODevice::WriteOnly);
    QDataStream stm(&cache);
    stm.setVersion(QDataStream::Qt_4_8);
    stm << formatVer << *namesSig;
    for (int i = 0; i < playersCount; ++i)
        stm << players[i] << *separatorSig;
    stm << *resultsSig;
}

bool PersistantStore::load(QString players[playersCount], QList<Result> &dest) const
{
    QFile cache(getCacheFile());
    if (!cache.exists())
        return false;
    cache.open(QIODevice::ReadOnly);
    QDataStream stm(&cache);
    stm.setVersion(QDataStream::Qt_4_8);
    quint32 meta;
    stm >> meta;
    if (meta != formatVer)
        return false;
    stm >> meta;
    if (meta != *namesSig)
        return false;
    for (int i = 0; i < playersCount; ++i) {
        stm >> players[i] >> meta;
        if (meta != *separatorSig)
            return false;
    }
    stm >> meta;
    if (meta != *resultsSig)
        return false;
    forever {
        quint32 winnerPos, eastPos;
        stm >> winnerPos;
        if (stm.status() == QDataStream::ReadPastEnd)
            break;
        stm >> eastPos;
        qint32 scores[playersCount];
        for (int i = 0; i < playersCount; ++i)
            stm >> scores[i];
        quint8 deadHands = 0;
        stm >> deadHands;
        meta = 0;
        stm >> meta;
        if (meta != *separatorSig)
            return false;
        qDebug("read result: [%d, %d, %d, %d]; win: %u, east: %u, deads: %u", scores[0], scores[1], scores[2], scores[3], winnerPos, eastPos, quint32(deadHands));
        dest.append(Result(scores, winnerPos, eastPos, deadHands));
    }
    return !dest.empty();
}

} // namespace mjcalc
