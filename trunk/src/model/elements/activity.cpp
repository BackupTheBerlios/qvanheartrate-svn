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


#include "activity.h"

#include <QGraphicsScene>
#include "model/elements/lap.h"
#include "model/parser/gpxwriter.h"

Activity::Activity()
{
	// TODO Auto-generated constructor stub

}

Activity::~Activity()
{
	// TODO Auto-generated destructor stub
}


void Activity::save(GpxWriter *writer)
{	//<trk>
	writer->writeStartElement("trk");
	writer->writeStartElement("trkseg");

	foreach(Lap *lap, laps)
	{
		lap->save(writer);
	}
	writer->writeEndElement();
	writer->writeEndElement();

}

void Activity::drawMapScene(QGraphicsScene *scene)
{
	foreach(Lap *lap, laps)
	{
	  lap->drawMapScene(scene);
    }
}

int Activity::drawCurveScene(QGraphicsScene *scene,int offset)
{
	int i=offset;
	foreach(Lap *lap, laps)
	{
	  i = lap->drawCurveScene(scene,i);
    }
	return i;
}
