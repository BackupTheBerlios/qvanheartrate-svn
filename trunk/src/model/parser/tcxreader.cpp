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

#include "tcxreader.h"
#include "model/elements/activity.h"
#include "model/elements/track.h"
#include "model/elements/trackpoint.h"
#include "model/elements/position.h"
#include "model/elements/author.h"

#include <QDebug>

TcxReader::TcxReader()
{
	activities = new QList<Activity *>;

}

TcxReader::~TcxReader()
{
	// TODO Auto-generated destructor stub
}

bool TcxReader::read(QIODevice *device)
{
	setDevice(device);

	while (!atEnd())
	{
		readNext();
		if (isStartElement())
		{

			if (name() == "TrainingCenterDatabase") // && attributes().value("xmlns") == "http://www.garmin.com/xmlschemas/TrainingCenterDatabase/v2")
				readTcx();
			else
				raiseError(
						QObject::tr(
								"The file is not an http://www.garmin.com/xmlschemas/TrainingCenterDatabase/v2 file."));
		}
	}

	return !error();
}

void TcxReader::readUnknownElement()
{
	Q_ASSERT(isStartElement());

	while (!atEnd())
	{
		readNext();

		if (isEndElement())
			break;

		if (isStartElement())
			readUnknownElement();
	}
}

void TcxReader::readTcx()
{
	//Q_ASSERT(isStartElement() && name() == "xbel");

	while (!atEnd())
	{
		readNext();

		if (isEndElement())
			break;

		if (isStartElement())
		{
			if (name() == "Activities")
				readActivities();
			else if (name() == "Author")
				readAuthor(new Author());
			else
				readUnknownElement();
		}
	}
}

void TcxReader::readActivities()
{
//	qDebug() << "activities";
	while (!atEnd())
	{
		readNext();

		if (isEndElement())
			break;

		if (isStartElement())
		{
			if (name() == "Activity")
			{
				Activity *a = new Activity();
				activities->append(a);
				readActivity(a);
			}
			else if (name() == "Autor")
				readAuthor(new Author());
			else
				readUnknownElement();
		}
	}
}

void TcxReader::readActivity(Activity *activity)
{
//	qDebug() << "activity";
	while (!atEnd())
	{
		readNext();

		if (isEndElement())
			break;

		if (isStartElement())
		{
			if (name() == "Id")
			{
				activity->setId(readElementText());
			}
			else if (name() == "Lap")
			{
				Lap *l = new Lap();
				activity->append(l);
				readLap(l);
			}

			else
				readUnknownElement();
		}
	}
}

void TcxReader::readLap(Lap *lap)
{
//	qDebug() << "Lap";
	while (!atEnd())
	{
		readNext();

		if (isEndElement())
			break;

		if (isStartElement())
		{
			if (name() == "Hrearrjr")
				qDebug() << "yy"; //activity->setId(readElementText());
			else if (name() == "Track")
			{
				Track *t = new Track();
				lap->append(t);
				readTrack(t);
			}

			else
				readUnknownElement();
		}
	}

}

void TcxReader::readTrack(Track *track)
{
//	qDebug() << "Track";
	while (!atEnd())
	{
		readNext();

		if (isEndElement())
			break;

		if (isStartElement())
		{
			if (name() == "Hrearrjr")
				qDebug() << "yy"; //activity->setId(readElementText());
			else if (name() == "Trackpoint")
			{
				Trackpoint *tp = new Trackpoint();
				track->append(tp);
				readTrackpoint(tp);
			}

			else
				readUnknownElement();
		}
	}
}

void TcxReader::readTrackpoint(Trackpoint *trackPoint)
{
	//qDebug() << "TrackPoint";
	while (!atEnd())
	{
		readNext();

		if (isEndElement())
			break;

		if (isStartElement())
		{
			if (name() == "Time")
			{
				trackPoint->setDateTime(QDateTime::fromString(
						readElementText(), Qt::ISODate));
			}
			else if (name() == "AltitudeMeters")
			{
				trackPoint->setAltitudeMeters(readElementText().toDouble());
			}
			else if (name() == "DistanceMeters")
			{
				trackPoint->setDistanceMeters(readElementText().toDouble());
			}
			else if (name() == "Position")
			{

				trackPoint->setPosition(readPosition());
			}
			else if (name() == "HeartRateBpm")
			{
				readHeartRateBpm(trackPoint);
			}

			else
				readUnknownElement();
		}
	}
}

void TcxReader::readHeartRateBpm(Trackpoint *trackpoint)
{
//	qDebug() << "HeartRate";
	while (!atEnd())
	{
		readNext();

		if (isEndElement())
			break;

		if (isStartElement())
		{
			if (name() == "Value")
			{
				trackpoint->setHeartRateBpm(readElementText().toInt()); //activity->setId(readElementText());
			}
			else
				readUnknownElement();
		}
	}
}

Position TcxReader::readPosition()
{
//	qDebug() << "TrackPoint";
	Position position;
	while (!atEnd())
	{
		readNext();

		if (isEndElement())
			break;

		if (isStartElement())
		{
			if (name() == "Hrearrjr")
				qDebug() << "yy"; //activity->setId(readElementText());
			else if (name() == "LatitudeDegrees")
				position.setLatitudeDegrees(readElementText().toDouble());
			else if (name() == "LongitudeDegrees")
				position.setLongitudeDegrees(readElementText().toDouble());
			else
				readUnknownElement();
		}
	}
	return position;
}

void TcxReader::readAuthor(Author */*author*/)
{

}
