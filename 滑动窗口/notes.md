# 滑动窗口

## 定长滑动窗口
1. 题目常常固定要求有K个数，求最小和/积等
2. 解题时按照以下几步  
   * 入：下标为 i 的元素进入窗口，更新相关统计量。如果 i<k−1 则重复第一步。    
   * 更新：更新答案。一般是更新最大值/最小值。
   * 出：下标为 i−k+1 的元素离开窗口，更新相关统计量。
3. 巧用逆向思维，比如1423题，题目要求从两边取得最大和，那么等价于寻找中间的连续子数组，使和最小

## 最短子数组个数问题
1. 常出现以下字眼
    * 最多有...个
    * 和/积/个数严格小于...
    * <=、<
2. 在外层循环，一般要写 ans += right - left + 1。  
    滑动窗口的内层循环结束时，右端点固定在 right，左端点在 left,left+1,…,right 的所有子数组（子串）都是合法的，这一共有 right−left+1 个。
3. 最短子数组问题，只有 和/积/个数 **不符合要求**时才收缩窗口，当窗口停止收缩时，这时left点就是满足要求的最左点，那么left left+1 ... right都是满足的，一共right-left+1个

## 最长子数组个数问题
1. 常出现以下字眼
    * 最少有...个
    * 至少出现...次
    * 或者说允许有重复数字/字符的问题
    * .  >=、>
2. 在外层循环，一般要写 ans += left。  
    滑动窗口的内层循环结束时，右端点固定在 right，左端点在 0,1,2,…,left−1 的所有子数组（子串）都是合法的，这一共有 left 个。
3. 最长子数组问题，只要**满足要求**，就一直收缩窗口，寻找最后一个满足要求的时的left点，那么left及左边的就是符合要求的，所以ans += left。

## 恰好型子数组个数问题
1. 常出现以下字眼：
   * 和/积/个数恰好为...个

2. 有两种办法解决
   * 方法一：使用两个滑动窗口，<=k 减去 <=k-1 即两个最短子数组问题
   * 方法二：使用两个滑动窗口，>=k 减去 >=k+1 即两个最长子数组问题
   * 推荐用方法二，可以避免目标值k为0，导致k-1为负数的情况

