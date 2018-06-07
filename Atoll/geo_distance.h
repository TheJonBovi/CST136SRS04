/*
 * This file created using the code from ed-flanagan at https://gist.github.com/ed-flanagan/e6dc6b8d3383ef5a354a
 * Great-circle distance computational forumlas
 *
 * https://en.wikipedia.org/wiki/Great-circle_distance
 */

#pragma once
#include "stdafx.h"

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>

#ifndef M_PI
#define M_PI    3.1415926535897932384626433832795
#endif

double deg2rad(double deg);

double haversine_distance(double latitude1, double longitude1,
	double latitude2, double longitude2);

double vincenty_distance(double latitude1, double longitude1, double latitude2,
	double longitude2);
