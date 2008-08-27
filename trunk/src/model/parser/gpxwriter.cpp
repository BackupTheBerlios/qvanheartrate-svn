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

#include "gpxwriter.h"
#include "model/elements/activities.h"
#include "model/elements/activity.h"

GpxWriter::GpxWriter()
{
	setAutoFormatting(true);
}

GpxWriter::~GpxWriter()
{
	// TODO Auto-generated destructor stub
}

bool GpxWriter::write(QIODevice *device,Activities *activities)
{
	setDevice(device);
	writeStartDocument("1.0");
	writeStartElement("gpx");
	writeAttribute("xmlns","http://www.topografix.com/GPX/1/1");
	writeAttribute("creator","qVanHeartRate");
	writeAttribute("version","1.1");
	writeAttribute("xmlns:xsi","http://www.W3.org/2001/XMLSchema-instance");
	writeAttribute("xsi:schemaLocation","http://www.topografix.com/GPX/1/1 http://www.topografix.com/GPX/1/1/gpx.xsd");


	activities->save(this);
	writeEndElement();
	writeEndDocument();
	return true;
}

