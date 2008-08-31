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

#include "statistic.h"

Statistic::Statistic()
{
	// TODO Auto-generated constructor stub
	heartRateMaximum = 0;
	heartRateMinimum = 250;
	heartRateAverage = 0;


}

Statistic::~Statistic()
{
	// TODO Auto-generated destructor stub
}

void Statistic::processNewHeartData(int heartRate)
{
	if (heartRate > heartRateMaximum)
		heartRateMaximum = heartRate;

	if (heartRate < heartRateMinimum)
		heartRateMinimum = heartRate;

	if (heartRateAverage != 0)
		heartRateAverage = (heartRateAverage + heartRate) / 2;
	else
		heartRateAverage = heartRate;
}

