class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
    vector<string> map = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
                          "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
                          "..-","...-",".--","-..-","-.--","--.."} ;
        
        unordered_set<string> st;
        
        for(auto word : words)
        {
            string code;
            
            for(auto w : word)
            {
                code += map[w-'a'];
                //map[0,...........,25]
            }
            
            st.insert(code);
        }
        
        return st.size();
    }
};