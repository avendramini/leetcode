class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++)
        {
            int code;
            if(s[i]=='(' || s[i]==')')
                code=0;
            else if(s[i]=='['||s[i]==']')
                code=1;
            else if(s[i]=='{'||s[i]=='}')
                code=2;
            
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                {
                   st.push(code); 
                }
            else
            {
                if(st.size()==0)
                    return false;
                int top=st.top();
                st.pop();
                if(top!=code)
                return false;
            }
        }
        if(st.size()!=0)
        return false;
        return true;
    }
};
