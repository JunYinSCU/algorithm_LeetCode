/*
 * @lc app=leetcode.cn id=1358 lang=cpp
 *
 * [1358] 包含所有三种字符的子字符串数目
 *
 * https://leetcode.cn/problems/number-of-substrings-containing-all-three-characters/description/
 *
 * algorithms
 * Medium (61.31%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    21K
 * Total Submissions: 34K
 * Testcase Example:  '"abcabc"'
 *
 * 给你一个字符串 s ，它只包含三种字符 a, b 和 c 。
 * 
 * 请你返回 a，b 和 c 都 至少 出现过一次的子字符串数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "abcabc"
 * 输出：10
 * 解释：包含 a，b 和 c 各至少一次的子字符串为 "abc", "abca", "abcab", "abcabc", "bca", "bcab",
 * "bcabc", "cab", "cabc" 和 "abc" (相同字符串算多次)。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "aaacb"
 * 输出：3
 * 解释：包含 a，b 和 c 各至少一次的子字符串为 "aaacb", "aacb" 和 "acb" 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "abc"
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= s.length <= 5 x 10^4
 * s 只包含字符 a，b 和 c 。
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
public:
    //时间复杂度O(n)
    //空间复杂度O(1)
    // int numberOfSubstrings(string s) {
    //     int n = s.size();
    //     int res = 0;
    //     int left = 0;
    //     unordered_map<char,int> window;
    //     for(int right = 0;right < n;right++){
    //         window[s[right]]++;
    //         while(window.size() == 3){ // 说明当前窗口包含了所有的字符
    //             res += n - right;  //结果统计是关键，如果当前子串符合，那么当前子串加上后面的子串都符合，自身加上后面共有n-right个子串
    //             window[s[left]]--;
    //             if(window[s[left]] == 0){ // 如果当前字符个数为0，那么就删除这个字符
    //                 window.erase(s[left]);
    //             }
    //             left++;
    //         }

    //     }
    //     return res;
    // }

    //方法二：时间更短，内存更小
    int numberOfSubstrings(string s) {
        int n = s.size();
        int res = 0;
        int left = 0;
        int cnt[3] = {0};
        for(int right = 0;right < n;right++){
            cnt[s[right] - 'a']++;
            while(cnt[0] && cnt[1] && cnt[2]){ // 说明当前窗口包含了所有的字符
                //res += n - right;  //结果统计是关键，如果当前子串符合，那么当前子串加上后面的子串都符合，自身加上后面共有n-right个子串
                cnt[s[left] - 'a']--;
                left++;
            }
            //或者在最后进行结果统计
            res += left; //如果当前窗口包含了所有的字符，那么当前窗口加上前面的窗口都符合

        }
        return res;
    }
};
// @lc code=end

