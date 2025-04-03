/*
 * @lc app=leetcode.cn id=2982 lang=cpp
 *
 * [2982] 找出出现至少三次的最长特殊子字符串 II
 *
 * https://leetcode.cn/problems/find-longest-special-substring-that-occurs-thrice-ii/description/
 *
 * algorithms
 * Medium (51.90%)
 * Likes:    44
 * Dislikes: 0
 * Total Accepted:    21.9K
 * Total Submissions: 42.2K
 * Testcase Example:  '"aaaa"'
 *
 * 给你一个仅由小写英文字母组成的字符串 s 。
 * 
 * 如果一个字符串仅由单一字符组成，那么它被称为 特殊 字符串。例如，字符串 "abc" 不是特殊字符串，而字符串 "ddd"、"zz" 和 "f"
 * 是特殊字符串。
 * 
 * 返回在 s 中出现 至少三次 的 最长特殊子字符串 的长度，如果不存在出现至少三次的特殊子字符串，则返回 -1 。
 * 
 * 子字符串 是字符串中的一个连续 非空 字符序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aaaa"
 * 输出：2
 * 解释：出现三次的最长特殊子字符串是 "aa" ：子字符串 "aaaa"、"aaaa" 和 "aaaa"。
 * 可以证明最大长度是 2 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abcdef"
 * 输出：-1
 * 解释：不存在出现至少三次的特殊子字符串。因此返回 -1 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "abcaba"
 * 输出：1
 * 解释：出现三次的最长特殊子字符串是 "a" ：子字符串 "abcaba"、"abcaba" 和 "abcaba"。
 * 可以证明最大长度是 1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= s.length <= 5 * 10^5
 * s 仅由小写英文字母组成。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int left = 1,right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2; // 中点长度
            if (check(s, mid)) {
                left = mid + 1; // 能找到，尝试更长的
            } else {
                right = mid - 1; // 找不到，缩小范围
            }
        }
        return right == 0 ? -1:right;
    }

    bool check(string& s, int len) {
        bool allSame = true;
        unordered_map<char,int> cnt;
        string sub;
        for(int i = 0; i <= s.size()-len;i++){
            sub = s.substr(i,len);
            if(isSame(sub)){
                cnt[sub[0]]++;
                if(cnt[sub[0]] >= 3)
                return true;
            }
        }
        
        return false; // 没有找到
    }

    bool isSame(string& s){
        for(int i = 1; i < s.size(); i++){
            if(s[i] != s[0]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

