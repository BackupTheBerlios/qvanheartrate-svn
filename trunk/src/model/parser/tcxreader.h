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

#ifndef TCXREADER_H_
#define TCXREADER_H_
#include <QXmlStreamReader>

class Activity;
class Lap;
class Track;
class Trackpoint;
class Position;
class Author;


class TcxReader : public QXmlStreamReader
{
public:
	TcxReader();
	virtual ~TcxReader();
	bool read(QIODevice *device);
	QList<Activity *> *getActivities() {return activities;};
private:
	QList<Activity *> *activities;
	void readUnknownElement();
	void readTcx();
	void readActivities();
	void readActivity(Activity *activity);
	void readLap(Lap *lap);
	void readTrack(Track *track);
	void readTrackpoint(Trackpoint *trackPoint);
	void readHeartRateBpm(Trackpoint *trackpoint);
	void readPosition(Position *position);

	void readAuthor(Author *autor);
};

#endif /* TCXREADER_H_ */
