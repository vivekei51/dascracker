class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n = pizzas.size();
    sort(pizzas.begin(), pizzas.end()); // Sort in ascending order
     long long totalGain = 0;
      int day = n/4;
      int index=n-1;
      for(int i=1;i<=day;i+=2)
      {
        totalGain+=pizzas[index--];
      }
      index--;
      for(int i=2;i<=day;i+=2)
      {
        totalGain+=pizzas[index];
         index-=2;
      }

    return totalGain;
    }
};