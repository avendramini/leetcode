class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int j=n-1;
        vector<int> ris;
        for(int i=0;i<n&&i<j;i++)
        {
            while(j>i&&numbers[j]+numbers[i]>target)
            {
                j--;
            }
            if(numbers[i]+numbers[j]==target)
            {
                
                ris.push_back(i+1);
                ris.push_back(j+1);
                return ris;
            }
        }
        return ris;
    }
};
