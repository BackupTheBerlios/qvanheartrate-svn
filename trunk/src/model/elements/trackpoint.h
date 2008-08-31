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

#ifndef TRACKPOINT_H_
#define TRACKPOINT_H_
#include <QDateTime>

#include "model/elements/position.h"
class GpxWriter;
class Track;
class Trackpoint
{
public:
	Trackpoint(Track *track);
	virtual ~Trackpoint();
	void setPosition(Position p) { position = p;};
	void setDateTime(QDateTime dt) {time = dt;};
	void setAltitudeMeters(qreal altiMeters);
	void setDistanceMeters(qreal distMeters);
	void setHeartRateBpm(int rate);
	void save(GpxWriter *writer);
	Position getPosition();
	int getHeartRateBpm() {return heartRateBpm;};
	qreal getAltitudeMeters() {return altitudeMeters;};
	qreal getDistanceMeters() {return distanceMeters;};
	QDateTime getTime() {return time;};

private:
	QDateTime time;           // <Time>2008-08-21T16:24:05Z</Time>
	Position position;
    qreal altitudeMeters; // <AltitudeMeters>136.140</AltitudeMeters>
    qreal distanceMeters; // <DistanceMeters>160468.516</DistanceMeters>
    int heartRateBpm;     //     <Value>95</Value>
    Track *track;
};

#endif /* TRACKPOINT_H_ */
