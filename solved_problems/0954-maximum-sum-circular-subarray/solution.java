class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int gMax = nums[0], gMin = nums[0];
        int curMax = 0, curMin = 0;
        int t = 0;

        for(int i: nums){
            curMax = Math.max(curMax + i, i);
            curMin = Math.min(curMin + i, i);
            t += i; 
            gMax = Math.max(gMax, curMax);
            gMin = Math.min(gMin, curMin);
        }
        if(gMax > 0) return Math.max(gMax, t - gMin);
        else return gMax;
    }
}
