class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coor) {
        
        int xdiff = coor[1][0] - coor[0][0];
        int ydiff = coor[1][1] - coor[0][1];
        int n = coor.size();
        for(int i=2;i<n;i++)
        {
            if((coor[i][0]-coor[0][0])*ydiff != (coor[i][1]-coor[0][1])*xdiff)
            {
                  return false;
            }
            
            //(x2-x1)/(x-x1) = (y2-y1)/(y-y1)
        }
        
        return true;
    }
};