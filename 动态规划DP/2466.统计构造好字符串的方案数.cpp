/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 *
 * [2466] 统计构造好字符串的方案数
 *
 * https://leetcode.cn/problems/count-ways-to-build-good-strings/description/
 *
 * algorithms
 * Medium (48.72%)
 * Likes:    129
 * Dislikes: 0
 * Total Accepted:    32.2K
 * Total Submissions: 66.1K
 * Testcase Example:  '3\n3\n1\n1'
 *
 * 给你整数 zero ，one ，low 和 high ，我们从空字符串开始构造一个字符串，每一步执行下面操作中的一种：
 * 
 * 
 * 将 '0' 在字符串末尾添加 zero  次。
 * 将 '1' 在字符串末尾添加 one 次。
 * 
 * 
 * 以上操作可以执行任意次。
 * 
 * 如果通过以上过程得到一个 长度 在 low 和 high 之间（包含上下边界）的字符串，那么这个字符串我们称为 好 字符串。
 * 
 * 请你返回满足以上要求的 不同 好字符串数目。由于答案可能很大，请将结果对 10^9 + 7 取余 后返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：low = 3, high = 3, zero = 1, one = 1
 * 输出：8
 * 解释：
 * 一个可能的好字符串是 "011" 。
 * 可以这样构造得到："" -> "0" -> "01" -> "011" 。
 * 从 "000" 到 "111" 之间所有的二进制字符串都是好字符串。
 * 
 * 
 * 示例 2：
 * 
 * 输入：low = 2, high = 3, zero = 1, one = 2
 * 输出：5
 * 解释：好字符串为 "00" ，"11" ，"000" ，"110" 和 "011" 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= low <= high <= 10^5
 * 1 <= zero, one <= low
 * 
 * 
 */

// @lc code=start

//方法一：递归
// class Solution {
//     vector<int> memo;
//     int MOD = 1e9 + 7;
// public:
//     int countGoodStrings(int low, int high, int zero, int one) {
//         memo.resize(high + 1, -1);
//         int res = (addNum(high, zero, one) - addNum(low - 1, zero, one) + MOD) % MOD;
//         return res;
//     }

//     int addNum(int high, int numZero,int numOne){
//         if (high < 0) {
//             return 0;
//         }
//         if (high == 0) {
//             return 1; // 空字符串算作一种
//         }
//         if(memo[high] != -1){ //判断是否已经计算过
//             return memo[high];
//         }

        
//         long long res = 1;  //当前情况算一种
//         res = (res + addNum(high - numZero, numZero, numOne)) % MOD;    //计算子情况的种数
//         res = (res + addNum(high - numOne, numZero, numOne)) % MOD;     //计算子情况的种数

//         memo[high] =res; //记忆答案

//         return memo[high];
//     }
// };

//方法二：递推
class Solution {
    int MOD = 1e9 + 7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {

        vector<int> memo(high+1,0); //memo[i]定义了长度为i时满足的字符串个数
        memo[0] = 1;
        for(int i = 1; i <= high; i++){
            //第一次计算zero情况时，memo未初始化，可以不相加取余
            if(zero <= i){
                //memo[i] = (memo[i] + memo[i-zero]) % MOD;
                memo[i] = memo[i-zero];
            }
            if(one <= i){
                //这里必须要取余，因为可能zero情况可取，此时memo以及被赋值了，再计算one情况时必须相加取余
                memo[i] = (memo[i] + memo[i-one]) % MOD;
            }
            
        }

        int res = 0;
        //遍历low到high，取和每个长度时的结果
        for (int i = low; i <= high; ++i) {
            res = (res + memo[i]) % MOD;
        }

        return res;
    }
};
// @lc code=end

