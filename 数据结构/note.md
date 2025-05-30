# 常见数据结构

## 枚举技巧

1. 枚举右，维护左
   * 对于**双变量**问题，例如两数之和 ai+aj=t，可以枚举右边的 aj，转换成单变量问题，也就是在 aj左边找是否有 ai=t−aj，这可以用哈希表维护。
    ```
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int x : nums) { // x = nums[j]
            ans += cnt[x]++;
        }
        return ans;
    }
    ```

2. 前缀和
   * 可以用一个数组记录前缀和，或者任意前缀的最小值最大值等，只用一次遍历即可获取所有信息。
   * 同理后缀类似
   * 对于环形前缀和，可以通过加倍数组长度来实现前缀和，例题请看3361
   * 常见前缀和题目解法：
       * 和为奇数的子数组个数：统计前缀和奇偶性不同的组合数
       * 子数组和为固定值 K 的个数：转换为pre[j+1] - k = pre[i]，利用哈希表进行判断
       * 子数组和为 K 的倍数：转为preSum[j] % k == preSum[i-1] % k，利用哈希表统计当前位置的前缀和模 k 的个数。
       * ```(pre[i] % k + k) % k``` 可以通过这种除法来确保余数始终为正数。
   * 二维前缀和的前缀数组生成方法：详见[304题](https://leetcode.cn/problems/range-sum-query-2d-immutable/solutions/2667331/tu-jie-yi-zhang-tu-miao-dong-er-wei-qian-84qp/)
   ```cpp
    int pre[1001][1001];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            pre[i+1][j+1] = pre[i+1][j] + pre[i][j+1] - pre[i][j] + a[i][j];
        }
    }
   ```
   <div align=center> <img src=https://raw.githubusercontent.com/JunYinSCU/PicBed/main/img/20250420173312.png width=80%/> </div>  

    * 二维前缀和的查询方法：  
  
    ```cpp
     int query(int x1, int y1, int x2, int y2) {
          return pre[x2+1][y2+1] - pre[x1][y2+1] - pre[x2+1][y1] + pre[x1][y1];
     }
    ```
    <div align=center> <img src=https://raw.githubusercontent.com/JunYinSCU/PicBed/main/img/20250420173345.png width=80%/> </div>

3. 哈希表
    * 在使用哈希表求类似a+b=target,或者a-b=target的问题时，可以枚举，转换成单变量问题，也就是在遍历元素左边找是否有a=target-b或者b=target-a，一定要转为减法形式。


4. 回文
    * 详见1177题 [题解](https://leetcode.cn/problems/can-make-palindrome-from-substring/solutions/2309725/yi-bu-bu-you-hua-cong-qian-zhui-he-dao-q-yh5p/)
    * 回文意味着从左往右第 i 个字母和从右往左第 i 个字母是相同的。（回文串关于回文中心是对称的。）
    * 如果有偶数个 a，那么可以均分成两部分，分别放置在字符串的中心对称位置上。例如有 4 个 a，可以在字符串的最左边放置 2 个 a，最右边放置 2 个 a，这样字符串中的 a 是回文的。其它字母如果出现偶数次，也同理。  
    * 如果有奇数个 a，多出的一个 a 要单独拿出来讨论：  
    * 假如只有 a 出现奇数次，其它字母都出现偶数次。此时字符串的长度一定是奇数，那么可以把多出的这个 a 放在字符串的中心，我们仍然可以得到一个回文串，无需替换任何字母。  
    * 如果有两种字母出现奇数次（假设是字母 a,b），由于多出的一个 a 和一个 b 无法组成回文串，可以把一个 b 改成 a（或者把一个 a 改成 b），这样 a 和 b 就都出现偶数次了。  
    * 如果有三种字母出现奇数次（假设是字母 a,b,c），把一个 b 改成 c，就转换成只有 a 出现奇数次的情况了。  
    一般地，如果有 m 种字母出现奇数次，只需修改其中 ⌊m/2⌋ 个字母。换句话说，如果第 i 次询问有⌊m/2⌋ <= k，那么 answer[i] 为真，反之为假。

5. 栈
   栈常用于处理括号匹配、表达式求值、单调栈等问题。

6. 单调栈
    * 单调栈是一个单调递增或单调递减的栈，常用于求解区间最值、下一个更大元素等问题。
    * 单调栈的基本思路是维护一个单调的栈，遍历数组时根据当前元素与栈顶元素的大小关系进行入栈或出栈操作。
    * 例如，求解下一个更大元素的问题，可以使用单调递减栈来维护当前元素与栈顶元素的大小关系，从而找到下一个更大元素。
    * [例题853](https://leetcode.cn/problems/car-fleet/description/)使用倒序遍历单调栈来判断车队，不同于一般的做法