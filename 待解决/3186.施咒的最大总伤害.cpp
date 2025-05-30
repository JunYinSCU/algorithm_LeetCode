/*
 * @lc app=leetcode.cn id=3186 lang=cpp
 *
 * [3186] 施咒的最大总伤害
 *
 * https://leetcode.cn/problems/maximum-total-damage-with-spell-casting/description/
 *
 * algorithms
 * Medium (35.51%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    13.8K
 * Total Submissions: 38.6K
 * Testcase Example:  '[1,1,3,4]'
 *
 * 一个魔法师有许多不同的咒语。
 * 
 * 给你一个数组 power ，其中每个元素表示一个咒语的伤害值，可能会有多个咒语有相同的伤害值。
 * 
 * 已知魔法师使用伤害值为 power[i] 的咒语时，他们就 不能 使用伤害为 power[i] - 2 ，power[i] - 1 ，power[i]
 * + 1 或者 power[i] + 2 的咒语。
 * 
 * 每个咒语最多只能被使用 一次 。
 * 
 * 请你返回这个魔法师可以达到的伤害值之和的 最大值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：power = [1,1,3,4]
 * 
 * 输出：6
 * 
 * 解释：
 * 
 * 可以使用咒语 0，1，3，伤害值分别为 1，1，4，总伤害值为 6 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：power = [7,1,6,6]
 * 
 * 输出：13
 * 
 * 解释：
 * 
 * 可以使用咒语 1，2，3，伤害值分别为 1，6，6，总伤害值为 13 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= power.length <= 10^5
 * 1 <= power[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        
    }
};
// @lc code=end

