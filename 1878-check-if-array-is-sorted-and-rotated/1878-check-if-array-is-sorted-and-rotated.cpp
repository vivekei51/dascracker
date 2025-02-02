class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int breakpoint=-1,secondbreakpoint=-1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1]){
               breakpoint = i;
                 break;
                         }
        }
        if(breakpoint==-1)
          return true;
        vector<int>doublelength(2*n,0);
        for(int i=0;i<2*nums.size();i++)
        {
          doublelength[i]=nums[i%n];
        }
       for(int i=breakpoint;i<doublelength.size()-1;i++)
       {
        if(doublelength[i]>doublelength[i+1]){
                 secondbreakpoint = i+1;
                 break;
        }
       }
       if(n==secondbreakpoint-breakpoint)
          return true;
          return false;
    }
};