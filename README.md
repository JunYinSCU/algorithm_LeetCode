# algorithm_LeetCode
我的力扣算法刷题

## 更新日志
* 2025.4.16 新增4道前缀和题，解决一道未解决前缀和题
* 2025.4.15 新增3道前缀和算法题，以及一道枚举题。一道前缀和题未解决。
* 2025.4.14 新增2道枚举题
* 2025.4.13 新增4道枚举题
* 2025.4.9 新增1道二分答案最小化最大值的题和四道枚举题以及相关笔记
* 2025.4.8 新增2道二分答案最大化最小值的题
* 2025.4.7 新增3道二分答案最小化最大值的题，一题未解决
  * 初始化二维数组的方式
  ```
  vector<vector<bool>> visited(rows, vector<bool>(cols, false));
  cols 是传递给这个临时向量构造函数的第一个参数，它指定了内层向量（即列数）的大小.  
  false 是传递给这个临时向量构造函数的第二个参数，它指定了内层向量中所有元素的初始值。
  ```
* 2025.4.4 新增1道二分答案最小化最大值题，增加相关笔记
* 2025.4.3 新增4道二分答案求最大题，其中两道未解决
* 2025.4.2 新增4道二分答案求最小题
* 2025.4.1 新增3道二分查找算法以及两道未解决二分查找题（全部已解决）
  * 循环数组中求两个数下标距离的函数(C++)
  ```
  int getDistance(int a, int b, int n){
        return min( (a - b + n) % n, (b - a + n) % n);
    }
  ```
  
  
* 2025.3.31 新增4道二分查找算法
  * 对于某些题，如果顺序不影响结果，则可以考虑先排序。
  * 同时要结合贪心算法来解题
* 2025.3.30 新增5道二分查找算法题。
  * 对二分查找有了初步的认识
* 2025.3.29 新增4道双序列双指针题
* 2025.3.28 新增1道原地操作题
* 2025.3.28 新增5道原地操作题
* 2025.3.27 新增4道相向双指针+两道同向双指针
* 2025.3.26 新增8道相向双指针题
    * 感悟：做了几道基础题，对双指针有了大致的了解和思路
* 2025.3.24 新增四道恰好型滑动窗口+双指针+2道固定长度滑动窗口
    * 感悟：
    * 过了好几天再回看固定滑动窗口，发现还是遗忘了某些算法，应该及时回顾
    * 需想到逆向思维
* 2025.3.21 新增两道滑动窗口求最短子数组问题
* 2025.3.20 新增两道滑动窗口求最长子数组问题+两道最短子数组问题
    * 感悟：
    * 更新计数结果时，需要考虑每个题目的性质，不可单纯++，可以使用例子进行推演
* 2025.3.19 新增四道滑动窗口求子数组问题
    * 感悟：
    * Q：什么时候用哈希表，什么时候用数组？
    * A:当字符集较大、未知或需要存储额外信息时，使用哈希表。当字符集较小、已知，为连续整数时，使用数组。
* 2025.3.16 更新三道不定长滑动窗口（至少）
    * 感悟：分不同情况灵活使用双指针
* 2025.3.15 更新两道不定长滑动窗口（至多+至少）
* 2025.3.14 更新部分滑动窗口题：固定窗口和不固定窗口（至多）
  
