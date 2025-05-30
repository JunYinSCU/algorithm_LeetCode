/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 *
 * [1234] 替换子串得到平衡字符串
 *
 * https://leetcode.cn/problems/replace-the-substring-for-balanced-string/description/
 *
 * algorithms
 * Medium (47.62%)
 * Likes:    324
 * Dislikes: 0
 * Total Accepted:    42.4K
 * Total Submissions: 88.9K
 * Testcase Example:  '"QWER"'
 *
 * 有一个只含有 'Q', 'W', 'E', 'R' 四种字符，且长度为 n 的字符串。
 * 
 * 假如在该字符串中，这四个字符都恰好出现 n/4 次，那么它就是一个「平衡字符串」。
 * 
 * 
 * 
 * 给你一个这样的字符串 s，请通过「替换一个子串」的方式，使原字符串 s 变成一个「平衡字符串」。
 * 
 * 你可以用和「待替换子串」长度相同的 任何 其他字符串来完成替换。
 * 
 * 请返回待替换子串的最小可能长度。
 * 
 * 如果原字符串自身就是一个平衡字符串，则返回 0。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "QWER"
 * 输出：0
 * 解释：s 已经是平衡的了。
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "QQWE"
 * 输出：1
 * 解释：我们需要把一个 'Q' 替换成 'R'，这样得到的 "RQWE" (或 "QRWE") 是平衡的。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "QQQW"
 * 输出：2
 * 解释：我们可以把前面的 "QQ" 替换成 "ER"。 
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "QQQQ"
 * 输出：3
 * 解释：我们可以替换后 3 个 'Q'，使 s = "QWER"。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s.length 是 4 的倍数
 * s 中只含有 'Q', 'W', 'E', 'R' 四种字符
 * 
 * 
 */

// @lc code=start
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    //时间复杂度O(n)
    //空间复杂度O(1)
    int balancedString(string s) {
        unordered_map<char, int> count;
        int n = s.size();
        int m = n / 4;
        int left = 0;
        int res = n;
        // 统计每个字符的数量
        for(int right = 0;right < n;right++)
        {
            count[s[right]]++;
        }
        // 如果每个字符的数量都是m，那么直接返回0
        if (count['Q'] == m && count['W'] == m && count['E'] == m && count['R'] == m)
            return 0;

        //逆向思维，如果在一个滑动窗口外的字符数量小于等于m，那么这个滑动窗口就是一个合法的滑动窗口
        for(int right = 0;right < n;right++)
        {
            count[s[right]]--;//记住现在是替换子串窗口，我们要看的是窗口外的字符是否小于等于m，所以要减1
            while(count['Q'] <= m && count['W'] <= m && count['E'] <= m && count['R'] <= m)
            {
                res = min(res, right - left + 1); //如果符合，则更新最小值
                count[s[left]]++; //移动窗口左端点，记得要加1，因为出了替换窗口
                left++;
            }   
            
        }

        return res;      

    }
};
// @lc code=end

