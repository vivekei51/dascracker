class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
      unordered_map<int,int>mp1,mp2;
      vector<int>ans;
      int cnt =0;
      for(int i=0;i<queries.size();i++)
      {
       if(mp1.find(queries[i][0])==mp1.end())
           {
            mp1[queries[i][0]]=queries[i][1];
            mp2[queries[i][1]]++;
          }
        else if (mp1.find(queries[i][0])!=mp1.end())
          {
             int a = mp1[queries[i][0]];
         cout<<a;
                mp2[a]--;
             
cout<<mp2[a];
              if(mp2[a]==0)
                mp2.erase(a);
               
             mp1[queries[i][0]]=queries[i][1];
             mp2[queries[i][1]]++;
          }
          else
          {

          }
          ans.push_back(mp2.size());
      }  
      return ans; 
    }
};