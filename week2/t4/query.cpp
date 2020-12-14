#include "query.h"

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