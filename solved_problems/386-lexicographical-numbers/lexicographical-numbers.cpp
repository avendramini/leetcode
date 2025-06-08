class Solution {
public:
    vector<int> ris;
    int n;
    void back(int num,int pos)
    {
        if(num*10+pos>n)
        {
            return;
        }
        else
        {
            ris.push_back(num*10+pos);
        }
        back(num*10+pos,0);
        if(pos!=9)
            back(num,pos+1);

    }
    vector<int> lexicalOrder(int x) {
        n=x;
        for(int i=1;i<=9;i++)
        {
            if(i<=n)
                ris.push_back(i);
            back(i,0);
        }
        return ris;
    }
};