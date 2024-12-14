class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ris(m+n);
        int a=0,b=0;
        for(int i=0;a!=m||b!=n;i++)
        {
            if(a==m)
            {
                ris[i]=nums2[b++];
            }
            else if(b==n)
            {
                ris[i]=nums1[a++];
            }
            else
            {
                if(nums1[a]<nums2[b])
                ris[i]=nums1[a++];
                else
                ris[i]=nums2[b++];
            }
        }
        for(int i=0;i<n+m;i++)
        nums1[i]=ris[i];
        
    }
};
