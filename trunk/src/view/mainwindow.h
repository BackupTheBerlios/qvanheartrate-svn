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

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_
#include <QMainWindow>
#include "ui_mainwindow.h"

class QMenu;
class QAction;
class ModelController;
class MapWidget;
class MainWindow: public QMainWindow, public Ui_MainWindow
{
	Q_OBJECT
public:
	MainWindow(ModelController *modelControlle) ;
	virtual ~MainWindow();

private:
	void createMenus();
	void createActions();
	QAction *loadAction;
	QAction *saveAction;
	QAction *zoomToFit;
	QAction *exitAction;
	QMenu *fileMenu;
	QMenu *viewMenu;
	ModelController *modelController;

private slots:
	void load();
	void save();

};

#endif /* MAINWINDOW_H_ */
