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

#ifndef TRACK_H_
#define TRACK_H_
#include "model/statistics/statistic.h"
#include <QList>
#include <QPen>
#include "trackpoint.h"
class GpxWriter;
class QGraphicsScene;
class Lap;

class Track: public Statistic
{
	Q_OBJECT
public:
	Track(Lap *lap);
	virtual ~Track();
	void save(GpxWriter *writer);
	void drawMapScene(QGraphicsScene *scene);
	int drawCurveScene(QGraphicsScene *scene, int offset, QPen pen);
	void append(Trackpoint *tp) {trackPoints.append(tp);};
	void processNewHeartData(int HeartRate);
private:
	QList<Trackpoint *> trackPoints;
	Lap *lap;
	/*virtual int getHeartRateMaximum() = 0;
	virtual int getHeartRateMinimum() = 0;
	virtual int getHeartRateAverage() = 0;
*/
/*	virtual qreal getAltitudeMaximum() = 0;
	virtual qreal getAltitudeMinimum() = 0;
	virtual qreal getAltitudeAverage() = 0;
*/

};

#endif /* TRACK_H_ */
