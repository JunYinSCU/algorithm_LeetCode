/*
 * @lc app=leetcode.cn id=3361 lang=cpp
 *
 * [3361] 两个字符串的切换距离
 *
 * https://leetcode.cn/problems/shift-distance-between-two-strings/description/
 *
 * algorithms
 * Medium (51.38%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    2.9K
 * Total Submissions: 5.7K
 * Testcase Example:  '"abab"\n' +
  '"baba"\n' +
  '[100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]\n' +
  '[1,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]'
 *
 * 给你两个长度相同的字符串 s 和 t ，以及两个整数数组 nextCost 和 previousCost 。
 * 
 * 一次操作中，你可以选择 s 中的一个下标 i ，执行以下操作 之一 ：
 * 
 * 
 * 将 s[i] 切换为字母表中的下一个字母，如果 s[i] == 'z' ，切换后得到 'a' 。操作的代价为 nextCost[j] ，其中 j 表示
 * s[i] 在字母表中的下标。
 * 将 s[i] 切换为字母表中的上一个字母，如果 s[i] == 'a' ，切换后得到 'z' 。操作的代价为 previousCost[j] ，其中 j
 * 是 s[i] 在字母表中的下标。
 * 
 * 
 * 切换距离 指的是将字符串 s 变为字符串 t 的 最少 操作代价总和。
 * 
 * 请你返回从 s 到 t 的 切换距离 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abab", t = "baba", nextCost =
 * [100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0], previousCost =
 * [1,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
 * 
 * 输出：2
 * 
 * 解释：
 * 
 * 
 * 选择下标 i = 0 并将 s[0] 向前切换 25 次，总代价为 1 。
 * 选择下标 i = 1 并将 s[1] 向后切换 25 次，总代价为 0 。
 * 选择下标 i = 2 并将 s[2] 向前切换 25 次，总代价为 1 。
 * 选择下标 i = 3 并将 s[3] 向后切换 25 次，总代价为 0 。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "leet", t = "code", nextCost =
 * [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], previousCost =
 * [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
 * 
 * 输出：31
 * 
 * 解释：
 * 
 * 
 * 选择下标 i = 0 并将 s[0] 向前切换 9 次，总代价为 9 。
 * 选择下标 i = 1 并将 s[1] 向后切换 10 次，总代价为 10 。
 * 选择下标 i = 2 并将 s[2] 向前切换 1 次，总代价为 1 。
 * 选择下标 i = 3 并将 s[3] 向后切换 11 次，总代价为 11 。
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length == t.length <= 10^5
 * s 和 t 都只包含小写英文字母。
 * nextCost.length == previousCost.length == 26
 * 0 <= nextCost[i], previousCost[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        vector<long long> next(27);
        next[0] = 0;
        for (int i = 0; i < 26; i++) {
            next[i+1] = next[i] + nextCost[i];
        }

        vector<long long> pre(27);
        pre[26] = 0;
        for (int i = 25; i >= 0; i--) {
            pre[i] = pre[i+1] + previousCost[i];
        }

        long long ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int from = s[i] - 'a';
            int to = t[i] - 'a';
            
            if (from == to) continue;
    
            // 向后走的代价（可能绕圈）
            long long costForward = from < to ? next[to] - next[from] : next[26] - next[from] + next[to];
    
            // 向前走的代价（可能绕圈）
            long long costBackward = from > to ? pre[to] - pre[from] : pre[0] - pre[from] + pre[to];
    
            ans += min(costForward, costBackward);
        }
    

        return ans;
    }

    
};
// @lc code=end

