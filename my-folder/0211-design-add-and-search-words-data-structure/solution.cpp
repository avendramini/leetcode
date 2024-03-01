#define trie WordDictionary
class WordDictionary {
public:
    bool fine;
    vector<WordDictionary * > next;
    WordDictionary() {
        fine=false;
        next.assign(26,nullptr);
    }
    
    void addWord(string word) {
        WordDictionary* att=this;
        for(int i=0;i<word.size();i++)
        {
            if(att->next[word[i]-'a']!=nullptr)
            {
                att=att->next[word[i]-'a'];
            }
            else
            {
                att->next[word[i]-'a']=new trie();
                att=att->next[word[i]-'a'];
            }
        }
        att->fine=true;
    }
    
    bool search(string word) {
        int car=0;
        queue<trie*> q;
        q.push(this);
        int cont=1;
        while(q.size()>0)
        {
            trie* att=q.front();
            q.pop();
            cont--;
            if(car==word.size())
            {
                if(att->fine)
                    return true;
                continue;
            }
            if(word[car]=='.')
            {
                for(int i=0;i<26;i++)
                {
                    if(att->next[i]!=nullptr)
                    {
                        q.push(att->next[i]);
                    }
                }
            }
            else if(att->next[word[car]-'a']!=nullptr)
            {
                q.push(att->next[word[car]-'a']);
            }
            if(cont==0)
            {
                cont=q.size();
                car++;
            }
        }
        return false;

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
