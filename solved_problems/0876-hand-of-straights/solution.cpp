class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)
            return false;
        map<int,int> occ;
        for(auto x: hand)
            occ[x]++;
        
        for(int j=0;j<hand.size();j+=groupSize)
        {
                int last=-1;
                vector<int> scelta;
                for(auto x: occ)
                {
                    if(scelta.size()==groupSize)
                        break;
                    if(x.first>last+1&&last!=-1)
                    {
                        return false;
                    }
                    else
                    {
                        scelta.push_back(x.first);
                        last=x.first;
                    }
                }
                if(scelta.size()!=groupSize)
                    return false;

                for(int i=0;i<scelta.size();i++)
                {
                    occ[scelta[i]]--;
                    if(occ[scelta[i]]==0)
                        occ.erase(scelta[i]);
                }
        }
        return true;
    }
};
