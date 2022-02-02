class Solution {
public:
    
    void floodfill(vector<vector<int>>& image, int sr, int sc,int color,int newColor)
    {
        int n = image.size();
        int m = image[0].size();
        
        if(sr<0 || sc<0 || sc>=m || sr>= n || image[sr][sc] != color)
        {
            return ;
        }
        
        image[sr][sc] = newColor;
        
        if(color != newColor)
        {
        floodfill(image,sr+1,sc,color,newColor);
        floodfill(image,sr-1,sc,color,newColor);
        floodfill(image,sr,sc+1,color,newColor);
        floodfill(image,sr,sc-1,color,newColor);    
            
        }
    }
    
    
    //TC----->O(n*m)
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int color= image[sr][sc];
        
        if(color == newColor)
        {
            return image;
        }
        
        floodfill(image,sr,sc,color,newColor);
        
        return image;
    }
};