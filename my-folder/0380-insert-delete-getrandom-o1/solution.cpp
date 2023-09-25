class RandomizedSet {
public:
    map<int,bool> m;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.count(val)>0)
        return false;
        m[val]=true;
        return true;
    }
    
    bool remove(int val) {
        if(m.count(val)>0)
        {
            m.erase(val);
            return true;
        }
        return false;
        
    }
    
    int getRandom() {
        int x=rand()%m.size();
        auto it=m.begin();
        advance(it,x);
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
