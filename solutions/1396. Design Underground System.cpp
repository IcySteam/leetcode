class Timestamp {
public:
    Timestamp (int pInt, string& pString) {
        t = pInt;
        station = pString;
    }
    int t;
    string station;
};
​
class UndergroundSystem {
public:
    unordered_map<string, unordered_map<string, vector<int>>> stationMap; // vector is {totalTime, numTrips}
    unordered_map<int, Timestamp*> pendingTrips;
    
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        pendingTrips[id] = new Timestamp(t, stationName);
    }
    
    void checkOut(int id, string stationName, int t) {
        int duration = t - pendingTrips[id]->t;
        if (!stationMap[pendingTrips[id]->station][stationName].size()) {
            stationMap[pendingTrips[id]->station][stationName].push_back(0);
            stationMap[pendingTrips[id]->station][stationName].push_back(0);
        }
        stationMap[pendingTrips[id]->station][stationName][0] += duration;
        stationMap[pendingTrips[id]->station][stationName][1]++;
        cout << stationMap[pendingTrips[id]->station][stationName][0] << " " << stationMap[pendingTrips[id]->station][stationName][1] << endl;
        delete pendingTrips[id];
        pendingTrips.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<int> resVec = stationMap[startStation][endStation];
        if (!resVec.size()) {return 0;}
        return (double)resVec[0] / (double)resVec[1];
    }
};
​
/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
