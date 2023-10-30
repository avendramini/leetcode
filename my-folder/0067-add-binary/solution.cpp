class Solution {
public:
    string addBinary(string a, string b) {
        string ris="";
        bool resto=false;
        if(a.size()<b.size())
        {
            while(a.size()<b.size())
            a='0'+a;
        }
        else{
            while(b.size()<a.size())
                b='0'+b;
        }
        
        for(int i=0;i<a.size();i++)
        {
            char add='0';
            string check="00";
            check[0]=a[a.size()-1-i];
            check[1]=b[b.size()-1-i];
            if(check=="00")
            {
                if(resto)
                    add='1';
                resto=false;
            }
            else if(check=="01"||check=="10")
            {
                if(resto)
                    add='0';
                else
                    add='1';
            }       
            else
            {
                if(resto)
                {
                    add='1';
                }
                else
                {
                    resto=true;
                    add='0';
                }
            }
            ris+=add;
        }
        
        if(resto)
            ris+='1';
        reverse(ris.begin(),ris.end());
        return ris;
    }
};
