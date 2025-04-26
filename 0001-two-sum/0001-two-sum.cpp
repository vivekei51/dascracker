class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
             int check = target-nums[i];
            if(mp.find(check)!=mp.end())
               {
                ans ={i,mp[check]};
                return ans;
               }
            mp[nums[i]]=i;
        }
        return ans;
    }
};