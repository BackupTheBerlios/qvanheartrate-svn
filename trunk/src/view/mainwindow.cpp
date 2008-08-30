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

#include "mainwindow.h"
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include <QDebug>
#include "model/modelcontroller.h"
#include "view/graphicsview/mapwidget.h"

MainWindow::MainWindow(ModelController *modelController) :
	QMainWindow(), modelController(modelController)
{

	setupUi(this);

	mapWidget->setScene(modelController->getMapScene());
	curveWidget->setScene(modelController->getCurveScene());

	createMenus();
}

MainWindow::~MainWindow()
{
	delete fileMenu;
	delete loadAction;
}

void MainWindow::createActions()
{
	loadAction = new QAction(tr("&Load..."), this);
	loadAction->setShortcut(tr("Ctrl+L"));
	loadAction->setStatusTip(tr("Load an file"));
	connect(loadAction, SIGNAL(triggered()), this, SLOT(load()));

	saveAction = new QAction(tr("&Save..."), this);
	saveAction->setShortcut(tr("Ctrl+S"));
	saveAction->setStatusTip(tr("Save an file"));
	connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

	exitAction = new QAction(tr("&Exit"), this);
	exitAction->setShortcut(tr("Alt+F4"));
	exitAction->setStatusTip(tr("Exits the application"));
	connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

	zoomToFit = new QAction(tr("Zoom to &fit"), this);
	zoomToFit->setShortcut(tr("F8"));
	addAction(zoomToFit);
	connect(zoomToFit, SIGNAL(triggered()), mapWidget, SLOT(zoomToFit()));
	connect(zoomToFit, SIGNAL(triggered()), curveWidget, SLOT(zoomToFit()));

}

void MainWindow::createMenus()
{
	createActions();

	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(loadAction);
	fileMenu->addAction(saveAction);
	fileMenu->addSeparator();
	fileMenu->addAction(exitAction);

	viewMenu = menuBar()->addMenu(tr("&View"));
	viewMenu->addAction(zoomToFit);

	/*fileMenu->addAction(openAct);
	 fileMenu->addAction(saveAct);*/
}

void MainWindow::load()
{
	QFileDialog fileDialog(this);
	fileDialog.setNameFilter(tr("Trainings (*.tcx)"));
	fileDialog.setFileMode(QFileDialog::ExistingFiles);
	QStringList fileNames;
	if (fileDialog.exec())
	{
		fileNames = fileDialog.selectedFiles();
		foreach(QString fileName, fileNames){
		modelController->load(fileName);
		zoomToFit->trigger();
	}
}
//	mapView
//mapView-> fitInView(QRectF(QPointF(48, 8),QPointF(50, 9)));
qDebug() << fileNames;
}

void MainWindow::save()
{
	QFileDialog fileDialog(this);
	fileDialog.setNameFilter(tr("GPX (*.gpx)"));
	fileDialog.setFileMode(QFileDialog::AnyFile);

	QStringList fileNames;
	if (fileDialog.exec())
	{
		fileNames = fileDialog.selectedFiles();

		foreach (QString fileName, fileNames){
		modelController->save(fileName);
	}
}
}
