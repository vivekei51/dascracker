class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int start = 0, next = 1;
        if(nums.size()==1)
             return 1;
        int countInc = 1, countDec = 1, maxInc = INT_MIN, maxDec = INT_MIN;
        while (next < nums.size()) {
            if (nums[start] < nums[next])
                countInc++;
            else {
                countInc = 1;
            }
            if (nums[start] > nums[next]) {
                countDec++;
            } else {
                countDec = 1;
            }
            maxInc = max(maxInc, countInc);

            maxDec = max(maxDec, countDec);
            start++;
            next++;
        }
      
            return max(maxDec, maxInc);
    }
};