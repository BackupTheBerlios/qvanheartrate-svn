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

#include "activities.h"
#include "model/parser/gpxwriter.h"
#include <QGraphicsScene>

Activities::Activities()
{
  // TODO Auto-generated constructor stub

}

Activities::~Activities()
{
  // TODO Auto-generated destructor stub
}

void Activities::save(GpxWriter *writer)
{
  foreach(Activity *activity, *this)
  {
   activity->save(writer);
  }

}

void Activities::drawMapScene(QGraphicsScene *scene)
{
  foreach(Activity *activity, *this)
  {
    activity->drawMapScene(scene);
  }
}

void Activities::drawCurveScene(QGraphicsScene *scene)
{
	int i=0;
  foreach(Activity *activity, *this)
  {
    i=activity->drawCurveScene(scene,i);
  }
}
