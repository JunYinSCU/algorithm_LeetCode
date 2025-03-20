/*
 * @lc app=leetcode.cn id=3298 lang=cpp
 *
 * [3298] 统计重新排列后包含另一个字符串的子字符串数目 II
 *
 * https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/description/
 *
 * algorithms
 * Hard (69.23%)
 * Likes:    39
 * Dislikes: 0
 * Total Accepted:    18.4K
 * Total Submissions: 26.7K
 * Testcase Example:  '"bcca"\n"abc"'
 *
 * 给你两个字符串 word1 和 word2 。
 * 
 * 如果一个字符串 x 重新排列后，word2 是重排字符串的 前缀 ，那么我们称字符串 x 是 合法的 。
 * 
 * 请你返回 word1 中 合法 子字符串 的数目。
 * 
 * 注意 ，这个问题中的内存限制比其他题目要 小 ，所以你 必须 实现一个线性复杂度的解法。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：word1 = "bcca", word2 = "abc"
 * 
 * 输出：1
 * 
 * 解释：
 * 
 * 唯一合法的子字符串是 "bcca" ，可以重新排列得到 "abcc" ，"abc" 是它的前缀。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：word1 = "abcabc", word2 = "abc"
 * 
 * 输出：10
 * 
 * 解释：
 * 
 * 除了长度为 1 和 2 的所有子字符串都是合法的。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：word1 = "abcabc", word2 = "aaabc"
 * 
 * 输出：0
 * 
 * 
 * 
 * 
 * 解释：
 * 
 * 
 * 1 <= word1.length <= 10^6
 * 1 <= word2.length <= 10^4
 * word1 和 word2 都只包含小写英文字母。
 * 
 * 
 */

// @lc code=start
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    //时间复杂度O(n)
    //空间复杂度O(1)
    long long validSubstringCount(string word1, string word2) {
        if(word1.size() < word2.size()){
            return 0;
        }
        long long res = 0;
        int left = 0;
        int w1[26] = {0}; //像这种需要统计的字符是连续的，且数量已知，可以使用数组统计
        int w2[26] = {0};

        for(int i = 0;i < word2.size();i++){
            w2[word2[i] - 'a']++;
        }
        for(int right = 0;right < word1.size();right++){
            w1[word1[right] - 'a']++;

            while(isValid(w1,w2)){
                res += word1.size() - right; //该字符串以及以其开头的后面的字符串都符合
                w1[word1[left] - 'a']--;//窗口滑动
                left++;
            }
        }
        return res;
    }

    bool isValid(int w1[],int w2[]){ //如果w1中字母个数大于等于w2中字母个数，那么这个字符串是合法的
        for(int i = 0;i < 26;i++){
            if(w1[i] < w2[i]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

