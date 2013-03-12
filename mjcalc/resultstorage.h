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

#ifndef RESULTSTORAGE_H
#define RESULTSTORAGE_H

#include <QtCore/QAbstractListModel>
#include <QtCore/QList>
#include <QtCore/QVariant>

#include "result.h"

class ResultStorage : public QAbstractListModel
{
    Q_OBJECT
    Q_DISABLE_COPY(ResultStorage)

public:
    enum Roles {
        totals1 = Qt::UserRole + 1,
        totals2,
        totals3,
        totals4
    };

    explicit ResultStorage(QObject *parent = 0);
    virtual ~ResultStorage();

    virtual QVariant data(const QModelIndex& index, int role) const;
    virtual int rowCount(const QModelIndex& parent) const;

    void clear();
    void addRoundResults(const mjcalc::Result &score);

private:
    QList<mjcalc::Result> mResults;
};

#endif // RESULTSTORAGE_H
