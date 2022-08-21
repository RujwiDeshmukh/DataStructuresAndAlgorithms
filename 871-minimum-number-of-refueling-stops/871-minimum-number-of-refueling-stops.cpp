class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int currentStationIndex=0;
        int totalStations = stations.size();
        int minStops = 0;
        priority_queue<int>pq;
        
       // https://leetcode.com/problems/minimum-number-of-refueling-stops/discuss/1266490/Minimum-Number-of-Refueling-Stops-or-Greedy-or-PriorityQueue
        
        while(startFuel < target)
        {
     while(currentStationIndex < totalStations && stations[currentStationIndex][0] <= startFuel)
            {
              pq.push(stations[currentStationIndex][1]);
              currentStationIndex++;
            }
            
            if(pq.empty())
            {
                return -1;
            }
            
            startFuel += pq.top();
            pq.pop();
            minStops++;
        }
        
        return minStops;
    }
};