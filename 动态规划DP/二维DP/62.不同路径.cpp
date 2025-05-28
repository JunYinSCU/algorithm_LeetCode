/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 *
 * https://leetcode.cn/problems/unique-paths/description/
 *
 * algorithms
 * Medium (69.28%)
 * Likes:    2239
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 1.4M
 * Testcase Example:  '3\n7'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 * 
 * 问总共有多少条不同的路径？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：m = 3, n = 7
 * 输出：28
 * 
 * 示例 2：
 * 
 * 
 * 输入：m = 3, n = 2
 * 输出：3
 * 解释：
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向下
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：m = 7, n = 3
 * 输出：28
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：m = 3, n = 3
 * 输出：6
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= m, n <= 100
 * 题目数据保证答案小于等于 2 * 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        //当前位置[i,j],可以从[i-1,j]和[i,j-1]到达，路径总数为前两种情况之和
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1; //起点
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 1; //第一行和第一列的路径数为1,只能通过一个方向到达
                    continue; //跳过后续计算
                }
                int up = dp[i-1][j]; //从[i-1][j]到达
                int left = dp[i][j-1]; //从[i][j-1]到达
                dp[i][j] = up + left; //当前路径总数
            }
        }

        return dp[m-1][n-1];
    }
};
// @lc code=end

