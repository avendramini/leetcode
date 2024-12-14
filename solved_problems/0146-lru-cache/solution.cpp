class LRUCache {
public:
    unordered_map<int,int > m;
    queue<pair<int,int> > usati;
    unordered_map<int,int> time;
    int cap=0;
    int tempo=0;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(m.count(key)==0)
            return -1;
        tempo++;
        time[key]=tempo;
        usati.push({tempo,key});
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.count(key)==0&&m.size()==cap)
        {
            while(m.count(usati.front().second)==0||time[usati.front().second]!=usati.front().first)
                usati.pop();
            m.erase(usati.front().second);
            usati.pop();
        }
        tempo++;
        time[key]=tempo;
        m[key]=value;
        usati.push({tempo,key});
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
