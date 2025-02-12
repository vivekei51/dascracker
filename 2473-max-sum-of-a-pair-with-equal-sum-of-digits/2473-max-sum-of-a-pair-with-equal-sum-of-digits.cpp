class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            int sumDigit = 0;
            int num = nums[i];
            while (num > 0) {
                sumDigit += num % 10;
                num /= 10;
            }
            auto it = mp.find(sumDigit);
              if (it!=mp.end()) {
                    ans = max(ans, it->second + nums[i]);
                    if(mp[it->first]>nums[i])
                    {
                     continue;
                    }
                }
          
            mp[sumDigit] = nums[i];
        }
        return ans;
    }
};