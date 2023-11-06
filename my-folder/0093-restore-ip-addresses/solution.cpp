class Solution {
public:
    vector<string> ris;
    void back(int pos,string &s,vector<int> &punti)
    {
        if(pos>=s.size())
            return;
        if(punti.size()==3)
        {
            if(s.size()-pos>3)
                return;
            int k=0;
            string att="";
            string num="";
            for(int i=0;i<s.size();i++)
            {
                att+=s[i];
                num+=s[i];
                if(k<punti.size()&&punti[k]==i)
                {
                    cout<<num<<endl;
                    if(num!=""&&stoi(num)>255)
                        return;
                    if(stoi(num)!=0&& num[0]=='0')
                        return;
                    if(stoi(num)==0&&num.size()!=1)
                        return;
                    num="";
                    att+='.';
                    k++;
                }
            }
            if(stoi(num)<=255)
            {
                if(stoi(num)!=0 && num[0]=='0')
                    return;
                if(stoi(num)==0&&num.size()!=1)
                    return;
                ris.push_back(att);
            }
        }
        punti.push_back(pos);
        back(pos+1,s,punti);
        punti.pop_back();

        punti.push_back(pos+1);
        back(pos+2,s,punti);
        punti.pop_back();

        punti.push_back(pos+2);
        back(pos+3,s,punti);
        punti.pop_back();
    }
    vector<string> restoreIpAddresses(string s) {
        vector<int> punti;
        back(0,s,punti);
        return ris;
    }
};
