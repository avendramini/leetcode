class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> att;
        int n=path.size();
        att.push_back("/");
        for(int i=1;i<n;)
        {
            cout<<i<<endl;
            while(i<n&&path[i]=='/')
                i++;
            string parola="";
            while(i<n&&path[i]!='/')
            {
                parola+=path[i];
                i++;
            }
            if(parola=="..")
            {
                if(att.size()>2){
                    att.pop_back();
                    att.pop_back();
                }
                else if(att.size()==2)
                att.pop_back();
            }
            else if(parola=="."||parola=="")
            {
            }
            else
            {
                if(att.size()!=1)
                att.push_back("/");
                att.push_back(parola);
            }
            for(auto x: att)
                cout<<x<<endl;
        }
        string ris="";
        for(auto x: att)
            ris+=x;
        
        return ris;
    }
};
