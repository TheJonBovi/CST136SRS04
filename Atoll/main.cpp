﻿// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <array>
#include <vector>

#include "longitude.h"
#include "latitude.h"
#include "location.h"
#include "geo_distance.h"
#include <numeric>

std::vector<double> calc_dist(std::vector<std::reference_wrapper<GPS::Location>> const vector)
{
	std::vector<double> result;
	for(auto i: vector)
	{
		result[i] = i.get().haversine_(i.get(), i.get());
	}

	return result;
}

double sort_NS(std::array<GPS::Location, 12> island_array)
{
	std::vector<std::reference_wrapper<GPS::Location>> island_vector(island_array.begin(), island_array.end());

	std::sort(island_vector.begin(), island_vector.end(), 
		[](GPS::Location const first, GPS::Location const second) {
		return first.latitude_ < second.latitude_;
	});

	auto distances{ calc_dist(island_vector) };

	return std::accumulate(distances.begin(), distances.end(), 0);
}

int main()
{
	using namespace std::literals::string_literals;

	std::array<GPS::Location, 12> const island
	{
		GPS::Location{ "Faichuk Islands"s  , GPS::Latitude{ GPS::Latitude::Cardinal::N,  7, 21,  8 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 151, 36, 30 } },
		GPS::Location{ "Hawaii"s           , GPS::Latitude{ GPS::Latitude::Cardinal::N, 21, 18, 41 }, GPS::Longitude{ GPS::Longitude::Cardinal::W, 157, 47, 47 } },
		GPS::Location{ "Mariana Islands"s  , GPS::Latitude{ GPS::Latitude::Cardinal::N, 17,  0,  0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 146,  0,  0 } },
		GPS::Location{ "Johnston Atoll"s   , GPS::Latitude{ GPS::Latitude::Cardinal::N, 16, 44, 13 }, GPS::Longitude{ GPS::Longitude::Cardinal::W, 169, 31, 26 } },
		GPS::Location{ "Kosrae"s           , GPS::Latitude{ GPS::Latitude::Cardinal::N,  5, 19,  0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 162, 59,  0 } },
		GPS::Location{ "Falalop"s          , GPS::Latitude{ GPS::Latitude::Cardinal::N, 10,  1, 14 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 139, 47, 23 } },
		GPS::Location{ "Guam"s             , GPS::Latitude{ GPS::Latitude::Cardinal::N, 13, 30,  0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 144, 48,  0 } },
		GPS::Location{ "Pohnpei"s          , GPS::Latitude{ GPS::Latitude::Cardinal::N,  6, 51,  0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 158, 13,  0 } },
		GPS::Location{ "Marshall Islands"s , GPS::Latitude{ GPS::Latitude::Cardinal::N,  7,  7,  0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 171,  4,  0 } },
		GPS::Location{ "Yap"s              , GPS::Latitude{ GPS::Latitude::Cardinal::N,  9, 32,  0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 138,  7,  0 } },
		GPS::Location{ "Wake Island"s      , GPS::Latitude{ GPS::Latitude::Cardinal::N, 19, 17, 43 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 166, 37, 52 } },
		GPS::Location{ "New Zealand"s      , GPS::Latitude{ GPS::Latitude::Cardinal::S, 41, 17,  0 }, GPS::Longitude{ GPS::Longitude::Cardinal::E, 174, 27,  0 } },
	};

	auto total_distance{ sort_NS(island) };

    return 0;
}

