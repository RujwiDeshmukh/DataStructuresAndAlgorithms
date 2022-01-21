class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size1 = gas.size();
        int size2 = cost.size();
        int sum_gas = 0;
        int sum_cost =0;
        int total=0;
        int start=0;
        
        for(int i=0;i<size1;i++)
        {
            sum_cost += cost[i];
            sum_gas  += gas[i];
            total += gas[i] - cost[i];
            
            if(total < 0)
            {
                start=i+1;
                total=0;
            }
        }
        
        if(sum_cost>sum_gas)
        {
            return -1;
        }
        
        return start;
    }
};