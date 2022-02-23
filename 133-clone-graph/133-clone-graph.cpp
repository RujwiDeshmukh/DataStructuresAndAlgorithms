/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        {
            return NULL;
        }
        
        Node* temp = new Node(node->val);
        unordered_map<int, Node*>mp;
        queue<pair<Node*,Node*>>q;
        q.push({node,temp});
        mp[node->val] = temp;
        
        while(!q.empty())
        {
            Node* currogr = q.front().first;
            Node* currcopy = q.front().second;
            q.pop();
            
            vector<Node*>neighbour;
            
            for(auto neigh : currogr->neighbors)
            {
                //for visited condition we are using map itself
                if(mp.count(neigh->val)==0)
                {
                    Node* temp = new Node(neigh->val);
                    mp[neigh->val] = temp;
                    q.push({neigh,temp});
                }
                
                 neighbour.push_back(mp[neigh->val]);
            }
                currcopy->neighbors = neighbour;
        }
        return temp;
    }
};