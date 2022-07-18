struct Node{
  
    Node *links[26];
    bool isend=false;
    
    bool containsKey(char ch)
    {
        if(links[ch-'a'] != NULL)
        {
            return true;
        }
        
        return false;
    }
    
    void putKey(char ch,Node *node)
    {
        links[ch-'a'] = node;
    }

    Node* getKey(char ch)
    {
        return links[ch-'a'];
    }
    
    bool isEnd()
    {
        if(isend == true)
        {
            return true;
        }
        
        return false;
    }
    
    void setEnd()
    {
        isend=true;
    }
    
};



class Trie {
    
    private:
      Node *root;
    
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        
        for(int i=0;i<word.size();i++)
        {
            if(!(node->containsKey(word[i])))
            {
                Node* temp = new Node();
                node->putKey(word[i],temp); 
            }
            node  = node->getKey(word[i]);
        }
        
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        
        for(int i=0;i<word.size();i++)
        {
            if(!(node->containsKey(word[i])))
            {
                return false;
            }
            
            node = node->getKey(word[i]);
        }
        
       return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        
        for(int i=0;i<prefix.size();i++)
        {
            if(!(node->containsKey(prefix[i])))
            {
                return false;
            }
            node = node->getKey(prefix[i]);
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */