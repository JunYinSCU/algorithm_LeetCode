/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode.cn/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (55.14%)
 * Likes:    3818
 * Dislikes: 0
 * Total Accepted:    1.8M
 * Total Submissions: 3.3M
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 2
 * 输出：2
 * 解释：有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 3
 * 输出：3
 * 解释：有三种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶 + 1 阶
 * 2. 1 阶 + 2 阶
 * 3. 2 阶 + 1 阶
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 45
 * 
 * 
 */

// @lc code=start
class Solution {
    vector<int> mem;    //记忆步数
public:
    int climbStairs(int n) {
        mem.resize(n+1,-1); //初始化mem
        return climb(n);
    }
    //方法一
    // int climb(int n){

    //     if(n <= 1){ //如果n等于1，说明只有1种爬法,即直接爬1步;

    //         return 1;
    //     }

    //     if(mem[n]!=-1){     //如果mem[n]不等于-1，说明已经计算过，直接返回
    //         return mem[n];
    //     }

    //     int sum = climb(n-1) + climb(n-2); //爬n-1步和爬n-2步的和

    //     mem[n] = sum;   //将结果存入mem[n]

    //     return sum;
    // }

    //方法二
    int climb(int n){
        //仅维护两个变量表示前两个状态的步数

        int a = 1;
        int b = 1;  //初始化a和b，分别表示爬1步和爬2步的方式
        for(int i = 2; i <= n; i++){
            int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};
// @lc code=end

