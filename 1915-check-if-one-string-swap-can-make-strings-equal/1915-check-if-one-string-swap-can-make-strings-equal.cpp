class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
      if(s1==s2)return true;
    for(int i=0;i<s1.size();i++)
    {
        char firstStr = s1[i];
        char secondStr = s2[i];

        if(firstStr!=secondStr)
           {
              int  j=i;
                  while(j<=s1.size())
                  {
                    if(s1[j]==secondStr&&s2[j]==firstStr){
                        swap(s1[i],s1[j]);
                          if(s1!=s2)
                            return false;
                            else
                            return true;
                                }
                          j++;
                  }
                 
           }
    }
  return false;
    }
};