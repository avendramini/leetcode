class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        for(int i=0;i<n/2;i++)
        {
            int x=i,y;
            for(int j=i;j<n-1-i;j++)
            {
                y=j;
                int attx=x,atty=y;
                int old=matrix[attx][atty];
                do
                {
                    int app=matrix[atty][n-1-attx];
                    matrix[atty][n-1-attx]=old;
                    old=app;
                    swap(attx,atty);
                    atty=n-1-atty;
                }while(attx!=x||atty!=y);
            }
        }
    }
};
