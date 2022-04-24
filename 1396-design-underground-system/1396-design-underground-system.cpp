class UndergroundSystem {
public:
    map<int, pair<string,int>> in;
    map<pair<string,string>, vector<int>>ot;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id]={stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto cin=in[id];
        in.erase(id);
        ot[{cin.first, stationName}].push_back(t-cin.second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto v=ot[{startStation, endStation}];
        long s=accumulate(v.begin(), v.end(), 0ll);
        return (double)((1.0*s)/v.size());
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */