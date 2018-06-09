#pragma once
#include "latitude.h"
#include "longitude.h"
#include <string>
#include "geo_distance.h"

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

		static double haversine_(const GPS::Location first, const GPS::Location second)
		{
			return haversine_distance(first.latitude_.get_total_(), first.longitude_.get_total_(),
										second.latitude_.get_total_(), second.longitude_.get_total_());
		}
	};

}
