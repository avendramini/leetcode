class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0;
        int r=matrix.size()-1;
        int riga=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            riga=mid;
            if(matrix[mid][0]<=target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        if(matrix[riga][0]>target)
            riga--;
        if(riga<0)  
        return false;
        l=0;
        r=matrix[0].size()-1;
        int col=0;
        while(l<=r) 
        {
            int mid=(l+r)/2;
            col=mid;
            if(matrix[riga][col]==target)
                return true;
            else if(matrix[riga][col]<target)
            {
                l=mid+1;
            }
            else
            r=mid-1;
        }
        return false;
    }
};
