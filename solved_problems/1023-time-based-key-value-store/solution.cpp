using namespace std;
class TimeMap {
public:
    unordered_map<string, set<pair<int,string> > > m;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto it=m[key].upper_bound({timestamp+1,""});

        if(it!=m[key].begin())
        {
            it--;
            if((*it).first==timestamp)
                m[key].erase(it);
        }
        m[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto it= m[key].upper_bound({timestamp+1,""});
        if(it==m[key].begin())
            return "";
        it--;
        return (*it).second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
