class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0;
        int count=0;
        while(i<flowerbed.size())
        {
        if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==flowerbed.size()-1 || flowerbed[i+1]==0))
        {
            flowerbed[i]=1;
            count++;
            i++;
            //we have to move 2 steps ahead
            //as we dont want adjacent same
        }
            
        if(count>=n)
        {
           return true;   
        }
            i++;
        }
        
        return false;
    }
};
