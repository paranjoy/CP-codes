/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/
//code snippet

class Trie {
public:
    /** Initialize your data structure here. */  
    Trie() {
        this->root = getNode();     
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        struct TrieNode *pCrawl = this->root; 
  
        for (int i = 0; i < word.length(); i++){
            
            int index = word[i] - 'a'; 
            
            if (!pCrawl->children[index]) 
                pCrawl->children[index] = getNode(); 
  
            pCrawl = pCrawl->children[index]; 
        } 
        // mark last node as leaf 
        pCrawl->isEndOfWord = true; 
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        struct TrieNode *pCrawl = this->root; 
  
        for (int i = 0; i < word.length(); i++){
            
            int index = word[i] - 'a'; 
            
            if (!pCrawl->children[index]) 
                return false; 
  
            pCrawl = pCrawl->children[index]; 
        } 
  
        return (pCrawl != NULL && pCrawl->isEndOfWord); 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix){
        
        struct TrieNode *pCrawl = this->root; 
  
        for (int i = 0; i < prefix.length(); i++){
            
            int index = prefix[i] - 'a'; 
            
            if (!pCrawl->children[index]) 
                return false; 
  
            pCrawl = pCrawl->children[index]; 
        } 
        return true;
    }
    
private:
    
    struct TrieNode{ 
        struct TrieNode *children[26]; 
        bool isEndOfWord; // isEndOfWord is true if the node represents end of a word 
    } *root; 
    // Returns new trie node (initialized to NULLs) 
    struct TrieNode *getNode() { 
        
        struct TrieNode *pNode =  new TrieNode; 
  
        pNode->isEndOfWord = false; 
  
        for (int i = 0; i < 26; i++) 
            pNode->children[i] = NULL; 
  
        return pNode; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
