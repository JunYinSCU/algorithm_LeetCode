/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 *
 * https://leetcode.cn/problems/minimum-falling-path-sum/description/
 *
 * algorithms
 * Medium (67.83%)
 * Likes:    407
 * Dislikes: 0
 * Total Accepted:    138.4K
 * Total Submissions: 203.9K
 * Testcase Example:  '[[2,1,3],[6,5,4],[7,8,9]]'
 *
 * 给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。
 * 
 * 下降路径
 * 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置
 * (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1)
 * 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：matrix = [[2,1,3],[6,5,4],[7,8,9]]
 * 输出：13
 * 解释：如图所示，为和最小的两条下降路径
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：matrix = [[-19,57],[-40,-5]]
 * 输出：-59
 * 解释：如图所示，为和最小的下降路径
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 100
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;

        vector dp(n,vector<int>(n));    //dp[i][j]表示从第一排到i,j处的最小值

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == 0){ //第一排初始化为matrix的值
                    dp[i][j] = matrix[i][j];
                    continue;
                }

                if(j == 0){
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j+1]) + matrix[i][j];
                }else if(j == n-1){
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]) + matrix[i][j];
                }else{
                    //如果不是两侧的列则取三者最小值
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1])) + matrix[i][j];
                }
            }
        }

        for(int i = 0; i < n; i++){
            //找出到最后一排时最小值
            if(ans > dp[n-1][i]){
                ans = dp[n-1][i];
            }
        }

        return ans;
    }
};
// @lc code=end

