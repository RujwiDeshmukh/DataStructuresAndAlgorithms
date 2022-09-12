class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int score=0;
        
      //  https://leetcode.com/problems/bag-of-tokens/discuss/2468056/C%2B%2B-or-Detailed-Explanation-w-WHY-or-Simple-Commented-Solution
       // https://leetcode.com/problems/bag-of-tokens/discuss/2564435/LeetCode-The-Hard-Way-Explained-Line-By-Line
        
        sort(tokens.begin(),tokens.end());
        int max_score=0;
        
        int n = tokens.size();
        
        int i=0;
        int j=n-1;
        
        while(i<=j)
        {
            //subtracting smaller values to get higher value of score
            if(power >= tokens[i])
            {
                power -= tokens[i];
                score ++;
                max_score = max(max_score,score);
                i++;
            }
            //adding larger value so that power will increase by great value
            //on loosing single score
            else if(score >= 1)
            {
                power += tokens[j];
                score--;
                j--;
            }
            else
            {
                break;
            }
        }
        
        
        return max_score;
        
    }
};