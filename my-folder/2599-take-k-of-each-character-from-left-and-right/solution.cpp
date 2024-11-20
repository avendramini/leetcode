class Solution {
public:
    bool checkValid(vector<int>& c,vector<int>& tolti,int k)
    {
        for(int i=0;i<3;i++)
        {
            if(c[i]-tolti[i]<k)
                return false;
        }
        return true;
    }
    int takeCharacters(string s, int k) {
        int caratteri=0;
        vector<int> v(3,0);
        for(auto x: s){
            v[x-'a']++;
        }
        for(auto x: v)
            if(x<k)
                return -1;
        caratteri=3;
        if(k*caratteri>s.size())
            return -1;
        if(k*caratteri==s.size())
            return s.size();
        int low=k*3;
        int high=s.size();
        int ris=0;
        while(low<=high)
        {
            int mid=(high+low)/2;
            int finestra=s.size()-mid;
            vector<int> tolti(3,0);
            bool valido=false;
            for(int i=0;i<finestra;i++)
            {
                tolti[s[i]-'a']++;
            }
            valido|=checkValid(v,tolti,k);
            for(int i=1;i<=s.size()-finestra;i++)
            {
                tolti[s[i-1]-'a']--;
                tolti[s[i+finestra-1]-'a']++;
                valido|=checkValid(v,tolti,k);
            }


            if(valido)
            {
                high=mid-1;
                ris=max(ris,finestra);
            }
            else
                low=mid+1;
        }
        return s.size()-ris;
        //binary search, girando il problema prendendo vettore contiguo dei non selezionati
    }
};
