/*
 * @lc app=leetcode.cn id=3325 lang=cpp
 *
 * [3325] 字符至少出现 K 次的子字符串 I
 *
 * https://leetcode.cn/problems/count-substrings-with-k-frequency-characters-i/description/
 *
 * algorithms
 * Medium (64.41%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    7.4K
 * Total Submissions: 11.4K
 * Testcase Example:  '"abacb"\n2'
 *
 * 给你一个字符串 s 和一个整数 k，在 s 的所有子字符串中，请你统计并返回 至少有一个 字符 至少出现 k 次的子字符串总数。
 * 
 * 子字符串 是字符串中的一个连续、 非空 的字符序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： s = "abacb", k = 2
 * 
 * 输出： 4
 * 
 * 解释：
 * 
 * 符合条件的子字符串如下：
 * 
 * 
 * "aba"（字符 'a' 出现 2 次）。
 * "abac"（字符 'a' 出现 2 次）。
 * "abacb"（字符 'a' 出现 2 次）。
 * "bacb"（字符 'b' 出现 2 次）。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： s = "abcde", k = 1
 * 
 * 输出： 15
 * 
 * 解释：
 * 
 * 所有子字符串都有效，因为每个字符至少出现一次。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 3000
 * 1 <= k <= s.length
 * s 仅由小写英文字母组成。
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    //时间复杂度O(n)
    //空间复杂度O(1)
    int numberOfSubstrings(string s, int k) {
        vector<int> cnt(26, 0);
        int res = 0;
        int left = 0;

        for(int right = 0;right < s.size();right++){
            cnt[s[right] - 'a']++;

            //为什么只需判断cnt[s[right] - 'a'] >= k？
            //因为只有 cnt[s[right] - 'a']++ 导致了 cnt[s[right] - 'a'] 达到 k
            //所以其余字母的出现次数必然小于 k，无需判断
            while(cnt[s[right] - 'a'] >= k){
                cnt[s[left] - 'a']--;
                left++;
            }
            res += left;
        }
        return res;
    }
};
// @lc code=end

