/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class TrieNode{
  public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode()
    {
        data = '\0';
        
        for(int i=0; i<26; i++)
            children[i] = NULL;
        
        isTerminal = false;
    }
    
    TrieNode(char c)
    {
        data = c;
        
        for(int i=0; i<26; i++)
            children[i] = NULL;
        
        isTerminal = false;
    }
};


class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        
        for(int i=0; i<word.length(); i++)
        {
            if(temp->children[word[i]-'a']==NULL)
            {
                TrieNode* n = new TrieNode(word[i]);
                
                temp->children[word[i]-'a'] = n;
                temp = n;
            }
            else
            {
                temp = temp->children[word[i]-'a'];
            }
        }
        
        temp->isTerminal = true;
        
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        
        for(int i=0; i<word.length(); i++)
        {
            if(temp->children[word[i]-'a'])
                temp = temp->children[word[i]-'a'];
            else
                return false;
        }
        
        return temp->isTerminal;
    }
    
    bool isEmpty(TrieNode* temp)
    {
        for(int i=0; i<26; i++)
            if(temp->children[i])
                return false;
        
        return true;
    }
    
    bool startUtil(TrieNode* temp)
    {
        if(temp==NULL)
            return true;
        
        if(isEmpty(temp))
            return temp->isTerminal;
        
        bool val = true;
        for(int i=0; i<26; i++)
        {
            val = val && startUtil(temp->children[i]);
        }
        
        return val;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        
        for(int i=0; i<prefix.length(); i++)
        {
            if(temp->children[prefix[i]-'a'])
                temp = temp->children[prefix[i]-'a'];
            else
                return false;
        }
        
        return startUtil(temp);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

