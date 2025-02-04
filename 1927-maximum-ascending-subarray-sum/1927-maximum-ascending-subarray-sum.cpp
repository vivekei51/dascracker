class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
          int start = 0, next = 1;
        int sumInc = nums[start], maxInc = INT_MIN;
         while (next < nums.size()) {
            if (nums[start] < nums[next])
                sumInc+=nums[next];
            else {
             maxInc = max(maxInc, sumInc);
                sumInc = nums[next];
                 }
           
            start++;
            next++;
        }
     maxInc = max(maxInc, sumInc);
     return maxInc;
    }
};