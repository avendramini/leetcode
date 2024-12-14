class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int n=height.size();
        int j=n-1;
        int massimo=(n-1)*min(height[0],height[n-1]);
        for(int i=0;i<j&&i<n;i++)
        {
            while(j>i&&height[j]<height[i])
            {
                massimo=max(massimo,(j-i)*min(height[i],height[j]));
                j--;
            }
            massimo=max(massimo,(j-i)*min(height[i],height[j]));
        }
        return massimo;
    }
};
