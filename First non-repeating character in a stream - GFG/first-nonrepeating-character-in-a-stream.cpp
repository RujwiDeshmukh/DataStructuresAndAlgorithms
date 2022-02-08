// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    
		    vector<int>visited(26,0);
		    //vector array v store only unique elements
		    vector<char>v;
		    string ans="";
		    
		    for(int i=0;i<A.length();i++)
		    {
		        if(!visited[A[i]-'a'])
		        {
		            v.push_back(A[i]);
		        }
		        
		        visited[A[i]-'a']++;
		        
		        int flag=0;
		        int m = v.size();
		        
		        for(int j=0;j<m;j++)
		        {
		       //it is unique first one then we will add them to answer string
		            if(visited[v[j]-'a']==1)
		            {
		                flag=1;
		                ans.push_back(v[j]);
		                break;
		            }
		            //we cant write else here as we want only want to add
		            //first non-repeating one
		        }
		        
		        if(flag==0)
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