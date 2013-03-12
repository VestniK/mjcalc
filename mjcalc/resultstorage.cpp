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

#include <QtCore/QHash>
#include <QtCore/QByteArray>

#include "resultstorage.h"

ResultStorage::ResultStorage(QObject *parent): QAbstractListModel(parent)
{
    QHash<int, QByteArray> roles;
    roles[totals1] = "totals1";
    roles[totals2] = "totals2";
    roles[totals3] = "totals3";
    roles[totals4] = "totals4";
    setRoleNames(roles);
}

ResultStorage::~ResultStorage()
{
}

QVariant ResultStorage::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= mResults.size() || index.column() != 0)
        return QVariant();
    if (role < totals1 || role > totals4)
        return QVariant();
    int totals[mjcalc::playersCount] = {0, 0, 0, 0};
    for (int i = 0; i <= index.row(); ++i)
        mResults[i].addScores(totals);
    switch (role) {
        case totals1: return QVariant(totals[0]);
        case totals2: return QVariant(totals[1]);
        case totals3: return QVariant(totals[2]);
        case totals4: return QVariant(totals[3]);
    }
    return QVariant();
}

int ResultStorage::rowCount(const QModelIndex& parent) const
{
    return mResults.size();
}

void ResultStorage::clear()
{
    mResults.clear();
}

void ResultStorage::addRoundResults(const mjcalc::Result &score)
{
    mResults.append(score);
}
