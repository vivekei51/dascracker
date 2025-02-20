class Solution {
public:
    void solve(int n,string &s,int i ,vector<string>&ans)
    {
        if(n==i)
        {
            
            ans.push_back(s);
            return;
        }
      s[i]='0';
      solve(n,s,i+1,ans);
      s[i]='1';
      solve(n,s,i+1,ans);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
         string s(n, 'a');
         vector<string>ans;
         solve(n,s,0,ans);
         string a;
         for(int i=0;i<ans.size();i++)
         {
           auto it = find(nums.begin(), nums.end(), ans[i]);
           if(it==nums.end())
              return ans[i];
             
         }
         return "";
    }
};