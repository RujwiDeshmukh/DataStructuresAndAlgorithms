class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        
       // https://leetcode.com/problems/find-duplicate-file-in-system/discuss/1215522/Easy-Solutions-w-Explanation-Using-HashMap-or-C%2B%2B-custom-parsing-and-stringstream
        
        //https://leetcode.com/problems/find-duplicate-file-in-system/discuss/104123/C%2B%2B-clean-solution-answers-to-follow-up
        
        for(auto &path : paths)
        {
            int i=0,j;
            
            while(path[i] != ' ') i++;
            
            string dir = path.substr(0,i) , file, content;
            
            //as we know that i is space we will increment it by one
            
            i++;
            
            while(i < path.size())
            {
                j=i;
                while(path[i] != '(') i++;
                
                file = path.substr(j,i-j);
                
                i++;
                j=i;
                
                while(path[i] != ')') i++;
                
                content = path.substr(j,i-j);
                
                //now it is pointing to space
                i++;
                
                //we want it to point to next letter/char after space so increment it again
                i++;
                
                mp[content].push_back(dir+'/'+file);
            }
            
        }
            
            for(auto &m : mp)
            {
                if(m.second.size() > 1) //as we want duplicates
                {
                      ans.push_back(move(m.second));   
                }
            }
            
            return ans;
        
    }
};