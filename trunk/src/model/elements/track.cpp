//C-  -*- C++ -*-
//C- -------------------------------------------------------------------
//C- qVanHeartRate
//C- Copyright (c) 2008 Marc Feld
//C-
//C- This software is subject to, and may be distributed under, the
//C- GNU General Public License, either version 2 of the license,
//C- or (at your option) any later version. The license should have
//C- accompanied the software or you may obtain a copy of the license
//C- from the Free Software Foundation at http://www.fsf.org .
//C-
//C- This program is distributed in the hope that it will be useful,
//C- but WITHOUT ANY WARRANTY; without even the implied warranty of
//C- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//C- GNU General Public License for more details.
//C-  ------------------------------------------------------------------

#include "track.h"
#include <QPolygonF>
#include <QPen>
#include <QGraphicsScene>
#include <QDebug>
#include "model/elements/position.h"
Track::Track()
{
	// TODO Auto-generated constructor stub

}

Track::~Track()
{
	// TODO Auto-generated destructor stub
}

void Track::save(GpxWriter *writer)
{
	foreach(Trackpoint *trackPoint, *this)
	{
		trackPoint->save(writer);
	}
}


void Track::drawMapScene(QGraphicsScene *scene)
{
  QPainterPath *pa = 0;
  foreach(Trackpoint *trackPoint, *this)
  {
	  Position po = trackPoint->getPosition();
	  if (!po.isNull())
		  if (!pa)
			  pa = new QPainterPath(QPointF(po.x(),-po.y()));
		  else
			  pa->lineTo((QPointF(po.x(),-po.y())));
  }
 // qDebug() << p;
  if (pa)
	  scene->addPath(*pa,QPen(QColor(Qt::black)));
}
