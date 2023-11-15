class FreqStack {
public:
    
    unordered_map<int,int> mp; // It will map x->val ,i.e val for every x
// bcoz we will not push val into set,so we will get val from mp.
    unordered_map<int,int> freq; // It will keep freq of the val
    set<pair<int,int>> s; // {freq,x};
    int x=0; // x is maintained for second condition i.e 
// if freq tie, then we need to return latest element pushed.
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++; // increase the freq of val.
        mp[x]=val; // map x->val
        s.insert({freq[val],x++}); // {freq,x}
    }
    
    int pop() {
        auto it2=s.rbegin(); // return the iterater to last element in set i.e
// the one which is our ans with highest freq,if freq ties,
//then latest pushed,i.e having higher value of x.
        auto it=*(it2);// it gets the pair from the it2
        s.erase(it); // remove this pair from set
        int f=it.first;// freq
        int cur_x=it.second; // x
        int val=mp[cur_x]; // val i.e ans
        freq[val]--; // reduce the freq of val
        return val;
    }
};

