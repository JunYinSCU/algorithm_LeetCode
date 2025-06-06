/*
 * @lc app=leetcode.cn id=3393 lang=cpp
 *
 * [3393] 统计异或值为给定值的路径数目
 *
 * https://leetcode.cn/problems/count-paths-with-the-given-xor-value/description/
 *
 * algorithms
 * Medium (54.59%)
 * Likes:    9
 * Dislikes: 0
 * Total Accepted:    4.6K
 * Total Submissions: 8.3K
 * Testcase Example:  '[[2,1,5],[7,10,0],[12,6,4]]\n11'
 *
 * 给你一个大小为 m x n 的二维整数数组 grid 和一个整数 k 。
 * 
 * 你的任务是统计满足以下 条件 且从左上格子 (0, 0) 出发到达右下格子 (m - 1, n - 1) 的路径数目：
 * 
 * 
 * 每一步你可以向右或者向下走，也就是如果格子存在的话，可以从格子 (i, j) 走到格子 (i, j + 1) 或者格子 (i + 1, j) 。
 * 路径上经过的所有数字 XOR 异或值必须 等于 k 。
 * 
 * 
 * 请你返回满足上述条件的路径总数。
 * 
 * 由于答案可能很大，请你将答案对 10^9 + 7 取余 后返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [[2, 1, 5], [7, 10, 0], [12, 6, 4]], k = 11
 * 
 * 输出：3
 * 
 * 解释：
 * 
 * 3 条路径分别为：
 * 
 * 
 * (0, 0) → (1, 0) → (2, 0) → (2, 1) → (2, 2)
 * (0, 0) → (1, 0) → (1, 1) → (1, 2) → (2, 2)
 * (0, 0) → (0, 1) → (1, 1) → (2, 1) → (2, 2)
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [[1, 3, 3, 3], [0, 3, 3, 2], [3, 0, 1, 1]], k = 2
 * 
 * 输出：5
 * 
 * 解释：
 * 
 * 5 条路径分别为：
 * 
 * 
 * (0, 0) → (1, 0) → (2, 0) → (2, 1) → (2, 2) → (2, 3)
 * (0, 0) → (1, 0) → (1, 1) → (2, 1) → (2, 2) → (2, 3)
 * (0, 0) → (1, 0) → (1, 1) → (1, 2) → (1, 3) → (2, 3)
 * (0, 0) → (0, 1) → (1, 1) → (1, 2) → (2, 2) → (2, 3)
 * (0, 0) → (0, 1) → (0, 2) → (1, 2) → (2, 2) → (2, 3)
 * 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：grid = [[1, 1, 1, 2], [3, 0, 3, 2], [3, 0, 2, 2]], k = 10
 * 
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= m == grid.length <= 300
 * 1 <= n == grid[r].length <= 300
 * 0 <= grid[r][c] < 16
 * 0 <= k < 16
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        const int MOD = 1'000'000'007;
        int mx = 0; //记录最大的数
        for (auto& row : grid) {
            mx = max(mx, ranges::max(row));
        }
        int u = 1 << bit_width((unsigned) mx);  //u代表grid数组中所有元素的最大值的二进制位数，这是异或值的上限。
        if (k >= u) {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();
        //由于需要记录每个位置的所有可能的异或值，因此需要增加一个纬度
        vector dp(m+1,vector(n+1,vector<int>(u)));
        dp[0][1][0] = 1;    //这样初始化为了在计算 f[1][1] 时可以从左边或上方“转移”而无需特殊处理。

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int val = grid[i][j];
                for(int x = 0; x < u; x++){
                    //计算从左和上方中，疑惑和为x^val的路径数
                    dp[i+1][j+1][x] = (dp[i][j+1][x^val] + dp[i+1][j][x^val]) % MOD;
                }
            }
        }

        return dp[m][n][k];
    }
};
// @lc code=end

