class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
     priority_queue<long long, vector<long long>, greater<long long>> minHeap;
     int ans=0;
     for(int i=0;i<nums.size();i++)
     {
        
         minHeap.push(nums[i]);
       

     }
       while(minHeap.size() > 1&& minHeap.top() < k )
       {
        long long firstNum = minHeap.top();
        minHeap.pop();
        long long secondNum = minHeap.top();
        minHeap.pop();
        long long addOne = firstNum*2+secondNum;
        minHeap.push(addOne);
        ans++;
       }
        return ans;
    }
};