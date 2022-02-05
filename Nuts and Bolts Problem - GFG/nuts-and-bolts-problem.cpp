// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    unordered_map<char,int>mp;
	    map<char,int>st;
	    //populating the map for the sake of order
	    //in which order we that output
	    
	    mp['!']=1;
	    mp['#']=2;
	    mp['$']=3;
	    mp['%']=4;
	    mp['&']=5;
	    mp['*']=6;
	    mp['@']=7;
	    mp['^']=8;
	    mp['~']=9;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(mp.find(nuts[i]) != mp.end())
	        {
	            auto it = mp.find(nuts[i]);
	            st[it->first] = it->second;
	        }
	    }
	    
	    int i=0;
	    for(auto s : st)
	    {
	        nuts[i] = s.first;
	        bolts[i] = s.first;
	        i++;
	    }
	    
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends