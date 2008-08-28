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

#include <QApplication>
#include <QTranslator>
#include <QDebug>
#include "view/mainwindow.h"
#include "model/modelcontroller.h"
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QStringList list = app.arguments();

	ModelController model;
	qDebug() << list.count() << list;
	if (list.count() == 3)
	{
		model.load(list.at(1));
		model.save(list.at(2));
		return 0;
	}

	MainWindow mainWindow(&model);
	mainWindow.show();
	QTranslator translator;
	translator.load("src_de", QCoreApplication::applicationDirPath());
	app.installTranslator(&translator);

	return app.exec();
}
