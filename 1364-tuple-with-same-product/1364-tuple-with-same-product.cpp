class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int>mp;
        int ans =0;
       for(int i=0;i<nums.size();i++)
       {
          for(int j=i+1;j<nums.size();j++)
          {
             mp[nums[i]*nums[j]]++;
          }
       }
    for(auto it:mp)
    {
        
        if(it.second>1)
          {
            int a = it.second-1;
        while(a>0)
        {
            ans+=8*a;
            a--;
        }
          }
    }
    return ans;
    }
};