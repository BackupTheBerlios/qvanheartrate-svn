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

#include "modelcontroller.h"
#include <QObject>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QList>
#include <QGraphicsScene>
#include "model/parser/tcxreader.h"
#include "model/parser/gpxwriter.h"
#include "model/elements/activities.h"
#include "model/elements/activity.h"

ModelController::ModelController()
{
	activities = new Activities;
	mapScene = new QGraphicsScene(this);
}

ModelController::~ModelController()
{
	// TODO Auto-generated destructor stub
}

bool ModelController::load(QString fileName)
{

	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly))
		return false;
	TcxReader tcxReader;
	if (!tcxReader.read(&file))
	{
		qDebug() << tcxReader.errorString();
		return false;
	}
	else
	{
		foreach(Activity *a, *tcxReader.getActivities())
		{
		   activities->append(a);
	       drawMapScene();
	    }
    }

return true;
}

bool ModelController::save(QString fileName)
{
	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly))
		return false;

	GpxWriter gpxWriter;
	if (!gpxWriter.write(&file, activities))
	{
		//qDebug() << tcxReader.errorString();
		return false;
	}
	return true;
}

void ModelController::drawMapScene()
{
	activities->drawMapScene(mapScene);
}
