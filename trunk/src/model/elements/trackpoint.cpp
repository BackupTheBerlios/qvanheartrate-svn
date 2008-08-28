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

#include "trackpoint.h"
#include <QDebug>
#include "model/parser/gpxwriter.h"
#include "model/elements/position.h"

Trackpoint::Trackpoint()
{
	// TODO Auto-generated constructor stub
	altitudeMeters = 0.0;
	time.setTime_t(0);
}

Trackpoint::~Trackpoint()
{
	// TODO Auto-generated destructor stub
}

void Trackpoint::save(GpxWriter *writer)
{
	if (!position.isNull())
	{
		writer->writeStartElement("trkpt");
		writer->writeAttribute("lat", QString::number(
				position.getLatitudeDegrees()));
		writer->writeAttribute("lon", QString::number(
				position.getLongitudeDegrees()));
		if (altitudeMeters != 0.0)
		{
			writer->writeTextElement("ele", QString::number(altitudeMeters));
		}
		if (!time.isNull())
		{
			writer->writeTextElement("time", time.toString(Qt::ISODate) + "Z");
		}

		writer->writeEndElement();
	}

}

Position Trackpoint::getPosition()
{
	return position;
}
