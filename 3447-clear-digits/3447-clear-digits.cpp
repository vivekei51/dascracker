class Solution {
public:
    string clearDigits(string s) {
        stack<pair<char,int>>st;
        string a;
        int j=0;
        while(j<s.size())
        {
            if(!isdigit(s[j]))
            {
                st.push({s[j],j});
            }
            else
            {
                if(!st.empty())
                {
                  pair<char,int>p;
                  p=st.top();
                  s[p.second]='@';
                  cout<<p.second;
                  s[j]='@';
                  st.pop();
                }
            }
            j++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='@')
             {
                a+=s[i];
             }
        }
        return a;
    }
};