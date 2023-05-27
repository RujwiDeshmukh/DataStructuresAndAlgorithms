class KthLargest {
public:
    int size=0;
    priority_queue<int>pq;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(auto num : nums)
        {
            pq.push(-1*num);
            
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        
    }
    
    int add(int val) {
        pq.push(-1*val);
        
        if(pq.size() > size)
        {
            pq.pop();
        }
        
        return -1*pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */