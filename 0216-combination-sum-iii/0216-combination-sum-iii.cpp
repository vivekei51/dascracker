class Solution {
public:
        void solve(vector<int>candidate,int k,int target,int i, vector<vector<int>>&ans,vector<int>st)
     {
          if(target==0&&k==0)
          {
            ans.push_back(st);
             return;
          }
        if(i>=candidate.size()||target<0||k<0)
        {
        return;
        }
           
        
        st.push_back(candidate[i]);
        solve(candidate,k-1,target-candidate[i],i+1,ans,st);
        st.pop_back();
        solve(candidate,k,target,i+1,ans,st);
     }
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<int>v;
         for(int i=1;i<=9;i++)
         {
            v.push_back(i);
         }
         vector<vector<int>>ans;
         vector<int>st;
        solve(v,k,n,0,ans,st);
        return ans;
    }
};