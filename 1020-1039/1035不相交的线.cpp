#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * dp[i][j] 代表考虑 s1 的前 i 个字符、考虑 s2 的前 j 的字符，形成的最长公共子序列长度。
 */
class Solution {
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            int num1 = nums1[i - 1];
            for (int j = 1; j <= n; j++) {
                int num2 = nums2[j - 1];
                if (num1 == num2) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    vector<int> nums1 = { 1, 4, 2 };
    vector<int> nums2 = { 1, 2, 4 };

    Solution s;
    cout << s.maxUncrossedLines(nums1, nums2) << endl;

    return 0;
}