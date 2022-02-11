class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    double median = 0.0;
    priority_queue<double>max_heap;
    priority_queue<double,vector<double>,greater<double>>min_heap;
    
    void addNum(int num) {
        
        if(max_heap.empty() || max_heap.top() > num)
        {
            max_heap.push(num);
        }
        else
        {
            min_heap.push(num);
        }
        
        if(max_heap.size() > min_heap.size()+1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(min_heap.size() > max_heap.size()+1)
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        
        if(max_heap.size()==min_heap.size())
        {
            median = ((max_heap.top()+min_heap.top())/2.0);
        }
        else if(max_heap.size() > min_heap.size())
        {
            median = max_heap.top();
        }
        else 
        {
            median = min_heap.top();
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */