// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
     //starting from the given target node
    int minimumTime(Node* target,unordered_map<Node*,Node*>& mp)
    {
        queue<Node*>q;
        q.push(target);
        unordered_set<Node*>st;
        st.insert(target);
        int time=0;
        
        while(!q.empty())
        {
            int size = q.size();
            int f1=0;
            //we want to process nodes of that level simultaneously
            for(int i=0;i<size;i++)
            {
                auto node = q.front();
                q.pop();
                
                if(node->left != NULL && st.find(node->left) == st.end())
                {
                    q.push(node->left);
                    st.insert(node->left);
                    f1=1;
                }
                 if(node->right != NULL && st.find(node->right) == st.end())
                {
                    q.push(node->right);
                    st.insert(node->right);
                    f1=1;
                }
                 if(mp[node] != NULL && st.find(mp[node]) == st.end())
                {
                    q.push(mp[node]);
                    st.insert(mp[node]);
                    f1=1;
                }
            }
            
            if(f1==1)
            {
                time++;
            }
        }
        
        return time;
    }
  
    Node* markParents(unordered_map<Node*,Node*>& mp, Node* root,int target)
    {
        queue<Node*>q;
        q.push(root);
        Node* ans=NULL;
        
        while(!q.empty())
        {
            Node* currentNode = q.front();
            if(currentNode->data==target)
            {
                ans=currentNode;
            }
            q.pop();
            
            if(currentNode->left != NULL)
            {
                mp[currentNode->left] = currentNode;
                q.push(currentNode->left);
            }
            
            if(currentNode->right != NULL)
            {
                mp[currentNode->right] = currentNode;
                q.push(currentNode->right);
            }
        }
        
        return ans;
    }
  
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*>mp;
        mp[root]=NULL;
        Node* targetNode = markParents(mp,root,target);
        return minimumTime(targetNode,mp);
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends