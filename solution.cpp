#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	if (is) {
		string operation_code;

		is >> operation_code;
		if (operation_code == "NEW_BUS") {
			q.type = QueryType::NewBus;
			is >> q.bus;
			int stop_count;
			is >> stop_count;
			q.stops.resize(0);
			for (int i = 0; i < stop_count; i++) {
				string stop;

				is >> stop;
				q.stops.push_back(stop);
			}
		}
		else if (operation_code == "BUSES_FOR_STOP") {
			q.type = QueryType::BusesForStop;
			is >> q.stop;
		}
		else if (operation_code == "STOPS_FOR_BUS") {
			q.type = QueryType::StopsForBus;
			is >> q.bus;
		}
		else if (operation_code == "ALL_BUSES") {
			q.type = QueryType::AllBuses;
		}
	}
	return is;
}

struct BusesForStopResponse {
	vector <string> buses;
};

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

struct StopsForBusResponse {
	vector<string> vstops;
	map <string, vector<string>> stops;
};

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

struct AllBusesResponse {
  map <string, vector<string>> buses;
};

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

class BusManager {
	map<string, vector<string>> buses_to_stops, stops_to_buses;
public:
    void AddBus(const string& bus, const vector<string>& stops) {
		buses_to_stops[bus] = stops;
		for (const string& stop : stops) {
			stops_to_buses[stop].push_back(bus);
      	}
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
		BusesForStopResponse res;

		if (stops_to_buses.count(stop)) {
			res.buses = stops_to_buses.at(stop);
		}
		return res;
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        StopsForBusResponse res;

		if (buses_to_stops.count(bus)) {
			for (const string& stop : buses_to_stops.at(bus)) {
				res.vstops.push_back(stop);
				if (stops_to_buses.at(stop).size() == 1) {
					res.stops[stop].push_back("no interchange");
				} else {
					for (const string& other_bus : stops_to_buses.at(stop)) {
						if (bus != other_bus) {
							res.stops[stop].push_back(other_bus);
						}
					}
				}
			}
		}
		return res;
    }

    AllBusesResponse GetAllBuses() const {
		AllBusesResponse res;

        res.buses = buses_to_stops;
		return res;
    }
};


int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
        case QueryType::NewBus:
			bm.AddBus(q.bus, q.stops);
			break;
        case QueryType::BusesForStop:
			cout << bm.GetBusesForStop(q.stop) << endl;
			break;
        case QueryType::StopsForBus:
			cout << bm.GetStopsForBus(q.bus) << endl;
			break;
        case QueryType::AllBuses:
			cout << bm.GetAllBuses() << endl;
			break;
        }
    }
    return 0;
}
