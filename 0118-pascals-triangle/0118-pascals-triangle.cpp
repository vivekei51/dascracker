class Solution {
public:
  int nCr (int n , int r)
  {
    long long ans=1;
    for(int i=0;i<r;i++)
    {
        ans = ans*(n-i);
        ans=ans/(i+1);
    }
    return (int)(ans);
  }
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>>ans;
        for(int i=1;i<=n;i++)
        {
            vector<int>v;
            for(int j=1;j<=i;j++)
            {
               int ncr = nCr(i-1,j-1);
               v.push_back(ncr);
            }
            ans.push_back(v);
        }
        return ans;
    }
};