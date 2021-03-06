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

#include "lap.h"
#include "model/elements/track.h"
#include "model/parser/gpxwriter.h"
#include "model/elements/activity.h"
Lap::Lap(Activity *activity) : activity(activity)
{
	// TODO Auto-generated constructor stub

}

Lap::~Lap()
{
	// TODO Auto-generated destructor stub
}

void Lap::processNewHeartData(int HeartRate)
{
	Statistic::processNewHeartData(HeartRate);
	activity->processNewHeartData(HeartRate);
}

void Lap::save(GpxWriter *writer)
{
	foreach(Track *track, tracks)
	{
		track->save(writer);
	}
}

void Lap::drawMapScene(QGraphicsScene *scene)
{
  foreach(Track *track, tracks)
    {
      track->drawMapScene(scene);
    }
}

int Lap::drawCurveScene(QGraphicsScene *scene, int offset)
{
  int i=offset;
  foreach(Track *track, tracks)
    {
	  i = track->drawCurveScene(scene,i,QPen(QColor(Qt::red)));
    }

  return i;
}
