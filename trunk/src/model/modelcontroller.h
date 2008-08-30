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

#ifndef MODELCONTROLLER_H_
#define MODELCONTROLLER_H_
#include <QObject>
#include <QString>

class Activities;
class QGraphicsScene;

class ModelController : public QObject
{
	Q_OBJECT
public:
	ModelController(QObject *parent=0);
	virtual ~ModelController();
	bool load(QString fileName);
	bool save(QString fileName);
	void drawMapScene();
	void drawCurveScene();
	QGraphicsScene *getMapScene() {return mapScene;};
	QGraphicsScene *getCurveScene() {return curveScene;};
private:
	QObject *parent;
	Activities *activities;
	QGraphicsScene *mapScene;
	QGraphicsScene *curveScene;

};

#endif /* MODELCONTROLLER_H_ */
