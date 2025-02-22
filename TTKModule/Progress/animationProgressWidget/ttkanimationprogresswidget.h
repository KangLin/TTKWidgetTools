#ifndef TTKANIMATIONPROGRESSWIDGET_H
#define TTKANIMATIONPROGRESSWIDGET_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2023 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include <QWidget>
#include "ttkglobaldefine.h"

class QPropertyAnimation;

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKAnimationProgressWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKAnimationProgressWidget)
public:
    explicit TTKAnimationProgressWidget(QWidget *parent = nullptr);

    void start();
    void stop();

    virtual QSize sizeHint() const override final;

private Q_SLOTS:
    void valueChanged(const QVariant &value);

private:
    virtual void paintEvent(QPaintEvent *event) override final;

    int m_index;
    int m_value;
    QList<QPixmap> m_ranges;
    QPropertyAnimation *m_animation;

};

#endif // TTKANIMATIONPROGRESSWIDGET_H
