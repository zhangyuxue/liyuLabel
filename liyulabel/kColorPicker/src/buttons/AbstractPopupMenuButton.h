/*
 * Copyright (C) 2018 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef KCOLORPICKER_ABSTRACTPOPUPMENUBUTTON_H
#define KCOLORPICKER_ABSTRACTPOPUPMENUBUTTON_H

#include <QToolButton>
#include <QPainter>
#include <QPaintEvent>
#include <QStyleOption>

namespace kColorPicker {

class AbstractPopupMenuButton : public QToolButton
{
Q_OBJECT
public:
	explicit AbstractPopupMenuButton(const QIcon &icon);

signals:
	void colorSelected(const QColor &color) const;

protected slots:
	virtual void paintEvent(QPaintEvent *event);
	virtual void buttonClicked() = 0;
};

} // namespace kColorPicker

#endif //KCOLORPICKER_ABSTRACTPOPUPMENUBUTTON_H
