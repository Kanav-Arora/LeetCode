/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childcount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        isTerminal = false;
        childcount = 0;
    }
};


class WordDictionary {
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        if (root->children[word[0] - 'a'] != NULL) // char already exists
        {
            insertUtil(root->children[word[0] - 'a'], word.substr(1, word.length() - 1));
        }
        else
        {
            TrieNode *n = new TrieNode(word[0]);
            root->children[word[0] - 'a'] = n;
            root->childcount++;
            insertUtil(n, word.substr(1, word.length() - 1));
        }
    }
    
    void addWord(string word) {
        insertUtil(root, word);
    }
    
    bool helper(string word, TrieNode *node){
        for(int i=0;i<word.length();i++){
            if(word[i]=='.'){
                for(char ch='a';ch<='z';ch++){
                    if(node->children[ch-'a'] && helper(word.substr(i+1),node->children[ch-'a'])) 
                        return true;
                }
                return false;
            }
            else{
            if(!node->children[word[i]-'a']){
                return false;
            }
            node = node->children[word[i]-'a'];
            }
        }
        return node->isTerminal;   
    }
    
    bool search(string word) {
        TrieNode *node  = root;
        return helper(word,node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

