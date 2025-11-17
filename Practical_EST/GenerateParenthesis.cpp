class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""}; 

        for (int i = 1; i <= n; i++) {
            vector<string> temp;

            for (int left = 0; left < i; left++) {
                int right = i - 1 - left;

                for (string &l : dp[left]) {
                    for (string &r : dp[right]) {
                        temp.push_back("(" + l + ")" + r);
                    }
                }
            }

            dp[i] = temp;
        }

        return dp[n];
    }
};
