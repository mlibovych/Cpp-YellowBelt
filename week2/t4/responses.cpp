#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (!r.buses.size()) {
		os << "No stop";
	} 
	else {
		for (const string& bus : r.buses) {
			os << bus << " ";
		}
	}
  	return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	int first = 0;
	if (r.stops.empty()) {
        os << "No bus";
    }
	for (const auto& stop : r.vstops) {
		if (!first) {
			first++;
		}
		else {
			os << endl;
		}
		os << "Stop " << stop << ": ";
		for (const auto& bus : r.stops.at(stop)) {
			os << bus << " ";
		}
  	}
  	return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.buses.empty()) {
        os << "No buses";
    } 
	else {
		int first = 0;

    	for (const auto& bus_item : r.buses) {
			if (!first) {
				first++;
			}
			else {
				os << endl;
			}
          	os << "Bus " << bus_item.first << ": ";
          	for (const string& stop : bus_item.second) {
            	os << stop << " ";
          	}
        }
    }
  	return os;
}