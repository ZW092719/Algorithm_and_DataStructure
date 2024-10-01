#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
    // 198.打家劫舍
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[0] = nums[0];
            }else if (i == 1) {
                dp[1] = max(dp[0],nums[1]);
            }else {
                dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
            }
        }
        return dp[n-1];
    }
    // 改进，状压DP
    int rob1(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int first,second;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                first = nums[0];
            }else if (i == 1) {
                second = max(first,nums[1]);
            }else {
                int temp = second;
                second = max(first + nums[i],second);
                first = temp;
            }
        }
        return second;
    }
    
    // 找到偷的是哪几家房子
    // const用来修饰vector，加上这个关键字意味着vector里的内容不可被修改
    vector<int> calculateIND(const vector<int>& FF, const vector<int>& M) {
    vector<int> IND;
    int ind = -1;
    // 找到第一个符合条件的索引
    // find方法，返回指向第一个匹配元素的迭代器，auto为c++中自动识别类型
    // 若未找到则返回该容器的最后迭代器
    auto it = find(FF.begin(), FF.end(), FF.back());
    if (it != FF.end()) {
        ind = distance(FF.begin(), it); // distance用于计算两个迭代器之间的距离这样由迭代器得到索引
        IND.push_back(ind);
    }
    // 循环处理直到满足条件
    while (ind >= 0 && FF[ind] > M[ind]) {
        it = find(FF.begin(), FF.end(), FF[ind] - M[ind]);
        if (it != FF.end()) {
            ind = distance(FF.begin(), it);
            IND.push_back(ind);
        } else {
            break; // 如果找不到匹配项则退出
        }
    }
    // 翻转结果
    reverse(IND.begin(), IND.end());
    return IND;
}







};