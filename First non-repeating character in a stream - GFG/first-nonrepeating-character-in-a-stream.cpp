// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    
		    //we can use queue here as we want remove elements from front
		    //that can be done using queue DS easily
		    
		    int n = A.size();
		    vector<int>visited(26,0);
		    //queue is used to maintain the order of elements 
		    //queue always store unique element at front
		    queue<char>q;
		    string ans="";
		    
		    for(int i=0;i<n;i++)
		    {
		        q.push(A[i]);
		        
		        visited[A[i]-'a']++;
		        
		        while(!q.empty())
		        {
		            if(visited[q.front()-'a'] > 1)
		            {
		                q.pop();
		            }
		            else
		            {
		                ans.push_back(q.front());
		                //we will use break when element is found
		                break;
		            }
		        }
		        
		        if(q.empty())
		        {
		            ans.push_back('#');
		        }
		    }
		    
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends