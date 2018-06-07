#pragma once
#include "latitude.h"
#include "longitude.h"
#include <string>

namespace GPS
{
	class Location
	{
	public:
		std::string const name_;
		Latitude const latitude_;
		Longitude const longitude_;

	public:
		Location(std::string const name, Latitude const latitude, Longitude const longitude) :
			name_{name},
			latitude_{latitude},
			longitude_{longitude}
		{
		}
	};
}
