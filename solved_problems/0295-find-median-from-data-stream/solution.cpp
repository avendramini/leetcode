class MedianFinder {
public:
    multiset<int> m;
    multiset<int >::iterator it;
    multiset<int >::iterator it2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(m.size()==0||m.size()==1)
        {
            m.insert(num);
            it=m.begin();
            it2=m.begin();
            advance(it2,1);
        }
        else if(num>=*it2)
        {
            if(m.size()%2==0){
            m.insert(num);
            advance(it,1);
            }
            else
            {
                m.insert(num);
                advance(it2,1);
            }
            cout<<*it<<" "<<*it2<<endl;
        }
        else if(num<*it)
        {
            if(m.size()%2==0)
            {
                 m.insert(num);
                advance(it2,-1);
            }
            else{
                 m.insert(num);
                advance(it,-1);
            }
            cout<<*it<<" "<<*it2<<endl;
        }
        else
        {
            m.insert(num);
            advance(it,1);
            advance(it2,-1);
            cout<<*it<<" "<<*it2<<endl;
        }
    }
    
    double findMedian() {
        if(m.size()%2==0)
        {
            
            return ((*it) + (*it2)+0.0)/2.0;
        }
        return *it;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
