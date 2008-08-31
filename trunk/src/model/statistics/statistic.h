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

#ifndef STATISTIC_H_
#define STATISTIC_H_
#include <QObject>

class Statistic : public QObject
{
	Q_OBJECT
public:
	Statistic();
	virtual ~Statistic();

	virtual int getHeartRateMaximum() {return heartRateMaximum;};
	virtual int getHeartRateMinimum() {return heartRateMinimum;};
	virtual int getHeartRateAverage() {return heartRateAverage;};

public slots:
	virtual void processNewHeartData(int HeartRate);

private:
	int heartRateMaximum, heartRateMinimum, heartRateAverage;

/*	virtual qreal getAltitudeMaximum() = 0;
	virtual qreal getAltitudeMinimum() = 0;
	virtual qreal getAltitudeAverage() = 0;
*/
};

#endif /* STATISTIC_H_ */
