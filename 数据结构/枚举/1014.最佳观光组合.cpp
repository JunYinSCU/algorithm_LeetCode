/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 *
 * [1014] 最佳观光组合
 *
 * https://leetcode.cn/problems/best-sightseeing-pair/description/
 *
 * algorithms
 * Medium (58.42%)
 * Likes:    477
 * Dislikes: 0
 * Total Accepted:    87.8K
 * Total Submissions: 150.1K
 * Testcase Example:  '[8,1,5,2,6]'
 *
 * 给你一个正整数数组 values，其中 values[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的 距离 为 j - i。
 * 
 * 一对景点（i < j）组成的观光组合的得分为 values[i] + values[j] + i - j ，也就是景点的评分之和 减去
 * 它们两者之间的距离。
 * 
 * 返回一对观光景点能取得的最高分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：values = [8,1,5,2,6]
 * 输出：11
 * 解释：i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：values = [1,2]
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        //把得分分解为：(values[i] + i) + (values[j] - j)
        int res = 0;
        int maxVal = values[0];
        int maxIndex = 0;

        for(int i = 1; i < values.size(); i++) {
            res = max(res, maxVal + values[i] + maxIndex - i);
            //记录最大的value[i] + i,更新得分结果；
            if(maxVal + maxIndex < values[i] + i) {
                maxVal = values[i];
                maxIndex = i;
            }
        }
        return res;
    }
};
// @lc code=end

