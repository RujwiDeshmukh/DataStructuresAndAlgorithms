class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        //if end word is not present int the list then return 0 directly
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())
        {
            return 0;
        }
        
        int length=1;
        
        set<string>s(wordList.begin(),wordList.end());
        //https://leetcode.com/problems/word-ladder/discuss/898086/Easy-BFS-in-C%2B%2B-with-explanation-%3A-
        queue<string>q;
        q.push(beginWord);
        
        while(!q.empty())
        {
            
            int size = q.size();
            while(size--)
            {
            string st = q.front();
            q.pop();
                
                if(st == endWord)
                {
                    return length;
                }
            
    
            for(int i=0;i<st.length();i++)
            {
                string temp = st;
                for(char ch='a';ch<='z';ch++)     
                {
                    char letter = temp[i];
                    temp[i] = ch;
                    //if same character is replaced then skip the iteration
                    if(temp==st)
                    {
                        continue;
                    }
            
                    if(s.find(temp) != s.end())
                    {
                        q.push(temp);
                        s.erase(temp);
                    }
                }
                
            }
        }
            
            length++;
            
        }
        
        return 0;
}
};