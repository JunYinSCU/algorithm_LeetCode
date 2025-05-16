/*
 * @lc app=leetcode.cn id=2266 lang=cpp
 *
 * [2266] 统计打字方案数
 *
 * https://leetcode.cn/problems/count-number-of-texts/description/
 *
 * algorithms
 * Medium (52.32%)
 * Likes:    128
 * Dislikes: 0
 * Total Accepted:    30.8K
 * Total Submissions: 59K
 * Testcase Example:  '"22233"'
 *
 * Alice 在给 Bob 用手机打字。数字到字母的 对应 如下图所示。
 * 
 * 
 * 
 * 为了 打出 一个字母，Alice 需要 按 对应字母 i 次，i 是该字母在这个按键上所处的位置。
 * 
 * 
 * 比方说，为了按出字母 's' ，Alice 需要按 '7' 四次。类似的， Alice 需要按 '5' 两次得到字母  'k' 。
 * 注意，数字 '0' 和 '1' 不映射到任何字母，所以 Alice 不 使用它们。
 * 
 * 
 * 但是，由于传输的错误，Bob 没有收到 Alice 打字的字母信息，反而收到了 按键的字符串信息 。
 * 
 * 
 * 比方说，Alice 发出的信息为 "bob" ，Bob 将收到字符串 "2266622" 。
 * 
 * 
 * 给你一个字符串 pressedKeys ，表示 Bob 收到的字符串，请你返回 Alice 总共可能发出多少种文字信息 。
 * 
 * 由于答案可能很大，将它对 10^9 + 7 取余 后返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：pressedKeys = "22233"
 * 输出：8
 * 解释：
 * Alice 可能发出的文字信息包括：
 * "aaadd", "abdd", "badd", "cdd", "aaae", "abe", "bae" 和 "ce" 。
 * 由于总共有 8 种可能的信息，所以我们返回 8 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：pressedKeys = "222222222222222222222222222222222222"
 * 输出：82876089
 * 解释：
 * 总共有 2082876103 种 Alice 可能发出的文字信息。
 * 由于我们需要将答案对 10^9 + 7 取余，所以我们返回 2082876103 % (10^9 + 7) = 82876089 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= pressedKeys.length <= 10^5
 * pressedKeys 只包含数字 '2' 到 '9' 。
 * 
 * 
 */

// @lc code=start
class Solution {

public:
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        //由于按键对应的字母个数不同所以分开统计
        // 初始化dp，dp[i]表示连续i个相同数字时的方案个数，0个连续按键对应的方案数为1，最后依次为1,2,4
        vector<long long> dp3 = {1,1,2,4};
        vector<long long> dp4 = {1,1,2,4};

        //接下来计算i>4的情况，如果是7或者9，则方案数由dp4[i-1],dp4[i-2],dp4[i-3],dp4[i-4]组成
        for(int i = 4; i <= n; i++) {
            dp3.push_back((dp3[i-1] + dp3[i-2] + dp3[i-3]) % 1000000007);
            dp4.push_back((dp4[i-1] + dp4[i-2] + dp4[i-3] + dp4[i-4]) % 1000000007);
        }

        long long ans = 1;
        int cnt = 1;//记录每一段连续字符个数

        for(int i = 1; i < pressedKeys.size(); i++){
            if(pressedKeys[i] == pressedKeys[i-1]){
                cnt++;
            }else{
                if(pressedKeys[i-1] == '7' || pressedKeys[i-1] == '9'){
                    ans = (ans * dp4[cnt]) % 1000000007;
                }else{
                    ans = (ans * dp3[cnt]) % 1000000007;
                }
                cnt = 1;
            }
        }

        // 更新最后一段连续字符子串对应的方案数
        if (pressedKeys[n-1] == '7' || pressedKeys[n-1] == '9') {
            ans *= dp4[cnt];
        } else {
            ans *= dp3[cnt];
        }
        ans %= 1000000007;
        return ans;

    }
};
// @lc code=end

