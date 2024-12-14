class Trie {
public:
    
    bool fine;
    vector<Trie *> next;
    Trie() {
        fine=false;
        next.assign(26,nullptr);
    }
    
    void insert(string word) {
        Trie * att=this;
        for(int i=0;i<word.size();i++)
        {
            if(att->next[word[i]-'a']==nullptr)
                att->next[word[i]-'a']=new Trie();
            att=att->next[word[i]-'a'];
        }
        att->fine=true;
    }
    
    bool search(string word) {
        Trie * att=this;
        for(int i=0;i<word.size();i++)
        {
            if(att->next[word[i]-'a']!=nullptr)
            {
                att=att->next[word[i]-'a'];
            }
            else
                return false;
        }
        return att->fine;
    }
    
    bool startsWith(string prefix) {
        Trie * att=this;
        for(int i=0;i<prefix.size();i++)
        {
            if(att->next[prefix[i]-'a']!=nullptr)
            {
                att=att->next[prefix[i]-'a'];
            }
            else
                return false;
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
