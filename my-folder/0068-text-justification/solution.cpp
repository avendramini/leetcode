class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ris;
        int i=0;
        do
        {
            int tot=words[i].size();
            i++;
            vector<int> scelte;
            scelte.push_back(i-1);
            while(i<words.size()&&tot+1+words[i].size()<=maxWidth){
                tot+=1+words[i].size();
                scelte.push_back(i);
                i++;
            }
            bool ultima=false;
            if(i==words.size())
            ultima=true;
            
            int spazi=maxWidth-tot+scelte.size()-1;
            string s="";
            int parole=scelte.size();
            if(ultima)
            {
                for(int i=0;i<scelte.size();i++){
                    s+=words[scelte[i]];
                    if(i!=scelte.size()-1){
                    s+=' ';
                    spazi--;
                    }
                }
                for(int j=0;j<spazi;j++)
                {
                    s+=' ';
                }
            }
            else{
                for(int i=0;i<scelte.size();i++)
                {
                    s+=words[scelte[i]];
                    if(scelte.size()==1)
                    {
                        for(int j=0;j<spazi;j++)
                        {
                            s+=' ';
                        }
                    }
                    else if(i!=scelte.size()-1){
                    for(int j=0;j<spazi/(parole-1);j++)
                    {
                        s+=' ';
                    }
                    if(i<spazi%(parole-1))
                        s+=' ';
                    }
                }
            }
            ris.push_back(s);
        }while(i<words.size());
    return ris;
    }
};
