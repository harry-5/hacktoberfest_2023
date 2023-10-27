class Solution_1 {
public:
    int longestValidParentheses(string &s) {
        int n = s.size();
        if (n == 0) return 0;
        int dp[n];
        memset(dp, 0, sizeof(dp));
        int max_len = 0;
        for(int i = 1; i < n; i++){
            if(s[i] == ')') {
                if(s[i-1] == '(') {
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                } else if (i - dp[i-1] > 0 && s[i-dp[i-1]-1] == '(') {
                    dp[i] = dp[i-1] + 2 + (i - dp[i-1] >= 2 ? dp[i-dp[i-1]-2] : 0);
                }
            }
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};


class Solution {
   public:
    int longestValidParentheses(string &s) {
        int n = s.size(), i = 0, ans = 0, k = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == '(') {
                k++;
            } else if (s[j] == ')') {
                k--;
                if (k == 0) ans = max(ans, j - i + 1);
            }
            if (k < 0) {
                k = 0;
                i = j + 1;
            }
        }
        k = 0, i = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            if (s[j] == ')') {
                k++;
            } else if (s[j] == '(') {
                k--;
                if (k == 0) ans = max(ans, i - j + 1);
            }
            if (k < 0) {
                k = 0;
                i = j - 1;
            }
        }
        return ans;
    }
};
