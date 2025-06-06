/*
 * @lc app=leetcode.cn id=2320 lang=cpp
 *
 * [2320] 统计放置房子的方式数
 *
 * https://leetcode.cn/problems/count-number-of-ways-to-place-houses/description/
 *
 * algorithms
 * Medium (45.86%)
 * Likes:    75
 * Dislikes: 0
 * Total Accepted:    21.8K
 * Total Submissions: 47.3K
 * Testcase Example:  '1'
 *
 * 一条街道上共有 n * 2 个 地块 ，街道的两侧各有 n 个地块。每一边的地块都按从 1 到 n 编号。每个地块上都可以放置一所房子。
 * 
 * 现要求街道同一侧不能存在两所房子相邻的情况，请你计算并返回放置房屋的方式数目。由于答案可能很大，需要对 10^9 + 7 取余后再返回。
 * 
 * 注意，如果一所房子放置在这条街某一侧上的第 i 个地块，不影响在另一侧的第 i 个地块放置房子。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 1
 * 输出：4
 * 解释：
 * 可能的放置方式：
 * 1. 所有地块都不放置房子。
 * 2. 一所房子放在街道的某一侧。
 * 3. 一所房子放在街道的另一侧。
 * 4. 放置两所房子，街道两侧各放置一所。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 2
 * 输出：9
 * 解释：如上图所示，共有 9 种可能的放置方式。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countHousePlacements(int n) {
        vector<long long> dp(n+1);
        long long MOD = 1000000000 + 7;
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i <= n; i++){
            dp[i] = (dp[i-2] + dp[i-1]) % MOD;
        }

        return (dp[n]*dp[n]) % MOD;
    }
};
// @lc code=end

