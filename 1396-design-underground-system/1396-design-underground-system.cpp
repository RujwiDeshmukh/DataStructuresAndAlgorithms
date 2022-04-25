class UndergroundSystem {
public:
    
    unordered_map<int, pair<string,int>>checkin;
    unordered_map<string, pair<double,int>> average;
   // https://leetcode.com/problems/design-underground-system/discuss/1977950/C%2B%2B-oror-2-Map-Easy-Sol-oror-YT-Link-To-Understand-Logic
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string entryStation = checkin[id].first + "->" + stationName;
        double diffTime = t - checkin[id].second;
        average[entryStation].first += diffTime;
        average[entryStation].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        string station = startStation + "->" + endStation;
        double totalTime = average[station].first;
        double count = average[station].second;
        return totalTime/count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */