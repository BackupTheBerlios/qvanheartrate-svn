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
#include "model/elements/lap.h"

Track::Track(Lap *lap) : lap(lap)
{
	// TODO Auto-generated constructor stub

}

Track::~Track()
{
	// TODO Auto-generated destructor stub
}

void Track::processNewHeartData(int HeartRate)
{
	Statistic::processNewHeartData(HeartRate);
	lap->processNewHeartData(HeartRate);
}

void Track::save(GpxWriter *writer)
{
	foreach(Trackpoint *trackPoint, trackPoints)
	{
		trackPoint->save(writer);
	}
}


void Track::drawMapScene(QGraphicsScene *scene)
{
  QPainterPath *pa = 0;
  foreach(Trackpoint *trackPoint, trackPoints)
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

int Track::drawCurveScene(QGraphicsScene *scene, int offset, QPen pen)
{
  QPainterPath *paHeart = 0;
  int i=offset;
  foreach(Trackpoint *trackPoint, trackPoints)
  {
	  int heartRate = trackPoint->getHeartRateBpm();

	  if (heartRate != 0 || heartRate > 200)
	  {
		  if (!paHeart)
			  paHeart = new QPainterPath(QPoint(i,-heartRate));
		  else
			  paHeart->lineTo((QPoint(i,-heartRate)));
		  i++;
	  }

  }
 // qDebug() << p;
  if (paHeart)
	  scene->addPath(*paHeart,pen);

  return i;
}
