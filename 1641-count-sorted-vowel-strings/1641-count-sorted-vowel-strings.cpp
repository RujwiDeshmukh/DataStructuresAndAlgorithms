class Solution {
public:
    
    vector<int>vowels = {'a','e','i','o','u'};
    void countStrings(int n,char lastChar,int &count)
    {
        if(n==0)
        {
            count++;
            return ;
        }
        
        for(auto vowel : vowels)
        {//as we want to generate sorted string so we are comparing it with the lastCharacter
            if(lastChar <= vowel)
            {
                countStrings(n-1,vowel,count);
            }
        }
    }
    
    int countVowelStrings(int n) {
        int count=0;
        countStrings(n,' ',count);
        return count;
    }
};