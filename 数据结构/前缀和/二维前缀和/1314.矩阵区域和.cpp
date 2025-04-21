/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 *
 * https://leetcode.cn/problems/matrix-block-sum/description/
 *
 * algorithms
 * Medium (74.49%)
 * Likes:    212
 * Dislikes: 0
 * Total Accepted:    32K
 * Total Submissions: 42.9K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]\n1'
 *
 * 给你一个 m x n 的矩阵 mat 和一个整数 k ，请你返回一个矩阵 answer ，其中每个 answer[i][j] 是所有满足下述条件的元素
 * mat[r][c] 的和： 
 * 
 * 
 * i - k 
 * j - k  且
 * (r, c) 在矩阵内。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
 * 输出：[[12,21,16],[27,45,33],[24,39,28]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
 * 输出：[[45,45,45],[45,45,45],[45,45,45]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> sum(n+1,vector<int>(m+1,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + mat[i][j];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int startRow = (i - k) < 0 ? 0 : i - k;
                int endRow = (i + k) > n - 1 ? n - 1 : i + k;
                int startCol = (j - k) < 0 ? 0 : j - k;
                int endCol = (j + k) > m - 1 ? m - 1 : j + k;
                mat[i][j] = sum[endRow+1][endCol+1] - sum[endRow+1][startCol] - sum[startRow][endCol+1] + sum[startRow][startCol];
            }
        }

        return mat;
    }
};
// @lc code=end

