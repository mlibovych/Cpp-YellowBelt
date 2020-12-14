#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    buses_to_stops[bus] = stops;
    for (const string& stop : stops) {
        stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    BusesForStopResponse res;

    if (stops_to_buses.count(stop)) {
        res.buses = stops_to_buses.at(stop);
    }
    return res;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
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

AllBusesResponse BusManager::GetAllBuses() const {
    AllBusesResponse res;

    res.buses = buses_to_stops;
    return res;
}