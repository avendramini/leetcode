class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26,0);
        for(int i=0;i<s.size();i++)
        {
            count[s[i]-'a']++;
        }
        priority_queue<pair<int,int> > q;
        for(int i=0;i<26;i++)
        {
            if(count[i]!=0)
            q.push({count[i],i});
        }
        int last=-1;
        string ris="";

        while(q.size()>0)
        {
            pair<int,int> top=q.top();
            q.pop();
            if(top.second==last)
            {
                if(q.size()==0)
                    return "";
                pair<int,int> ok=q.top();
                q.pop();
                q.push(top);
                top=ok;
            }
            ris+=(top.second+'a');
            last=top.second;
            if(top.first!=1)
            q.push({top.first-1,top.second});
        }
        return ris;

    }
};
