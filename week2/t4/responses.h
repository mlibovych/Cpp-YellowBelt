#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

struct BusesForStopResponse {
	vector <string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	vector<string> vstops;
	map <string, vector<string>> stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
  map <string, vector<string>> buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);
