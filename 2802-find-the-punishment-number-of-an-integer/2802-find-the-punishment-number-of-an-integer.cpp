class Solution {
public:
    void solve(string& squareNum, int i, int sum, int original, bool &found) {
        if (i == squareNum.size()) {
            if (sum == original) found = true;
            return;
        }

        int num = 0;
        for (int j = i; j < squareNum.size(); j++) {
            num = num * 10 + (squareNum[j] - '0');  
            if (sum + num > original) break; 
            solve(squareNum, j + 1, sum + num, original, found);
            if (found) return;
        }
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            string squareNum = to_string(i * i);
            bool found = false;
            solve(squareNum, 0, 0, i, found);
            if (found) ans += i * i;
        }
        return ans;
    }
};
