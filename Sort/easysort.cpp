#include <vector>
#include<iostream>
#include <string>
#include<algorithm>
#include<unordered_map>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
// 268.丢失的数字
    // 法一：位运算版本
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int all = 0;
        for (int i = 0; i <= n; i++)
        {
            all ^= i;
        }
        int exist = 0;
        for (int i = 0; i < n; i++)
        {
            exist ^= nums[i];
        }
        return all ^ exist;
    }
    // 原地哈希
    int missingNumber1(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] < n && nums[nums[i]] != nums[i]) {
                swap(nums, i, nums[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i != nums[i])
            {
                return i;
            }
        }
    }
    void swap(vector<int> &nums, int a, int b)
    {
        int temp = nums[b];
        nums[b] = nums[a];
        nums[a] = temp;
    }

// 448.找到所有数组中消失的数字
    // 法一：调整i位置为i+1
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        // 调整为：i位置为i+1
        for (int i = 0; i < n; i++)
        {
            while (nums[i] != nums[nums[i] - 1]) {
                // 不能使用nums[i]!=i+1会出现死循环，例如[2,1,1,4] 
                swap(nums,nums[i]-1,i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i+1)
            {
                nums.push_back(i+1);   
            }
        }
        return ans;
    }
    // 法二：额外哈希
    vector<int>findDisappearedNumbers2(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        vector<bool>map(n+1);
        for (int i = 0; i < n; i++) {
            map[nums[i]] = true;
        }
        for (int i = 1; i <=n; i++) {
            if (!map[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    
    // 506.相对名次
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string>ans(n); // 养成声明大小的习惯
        unordered_map<int,int>map; // 哈希表
        for (int i = 0; i < n; i++) {
            map[score[i]] = i; // score[i]是键，i是值
        }
        sort(score.begin(),score.end(),greater<int>()); // 降序排列（greater<int>()反转默认规则）
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans[map[score[0]]] = "Gold Medal";
            } else if (i == 1) {
                ans[map[score[1]]] = "Silver Medal";
            } else if (i == 2) {
                ans[map[score[2]]] = "Bronze Medal";
            }else {
                ans[map[score[i]]] = to_string(i+1); // 转为字符串
            }
        }
        return ans;
    }
    
    



};

// 703.数据流中的第k大
// 这么写的话超时，因为数组会变得越来越长，需要通过堆(优先队列)来弹出k之外的元素
class KthLargest {
    public:
    int k;
    vector<int>list;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            list.push_back(nums[i]);
        }
    }
    
    int add(int val) {
        list.push_back(val);
        sort(list.begin(),list.end());
        return list[list.size()-k];
    }
};
class KthLargest {
    public:
    int k;
    priority_queue<int,vector<int>,greater<int>> q; // 小根堆
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto& i : nums) {
            add(i);
        }
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > k) {
            q.pop();
        }
        return q.top();
    }
};


// 重新排列日志文件
class Pairs {
    public:
    string s;
    int index;
    Pairs (string body,int id) {
        s = body;
        index = id;
    }
};
// c++自定义比较器与java是不同的！！！
// 返回true代表第一个参数优先级高，返回false代表第二个优先级更高或两者优先级一样
int self_compare(Pairs o1, Pairs o2) {
    size_t space_pos1 = o1.s.find(" ");
    size_t space_pos2 = o2.s.find(" ");
    // 标识部分
    string tag1 = o1.s.substr(0, space_pos1);
    string tag2 = o2.s.substr(0, space_pos2);
    // 内容部分
    string cont1 = o1.s.substr(space_pos1 + 1);
    string cont2 = o2.s.substr(space_pos2 + 1);
    // 判断内容是数字还是字母
    bool isdigit1 = isdigit(cont1[0]);
    bool isdigit2 = isdigit(cont2[0]);
    // 如果都是数字内容，则保持原有顺序
    if (isdigit1 && isdigit2) {
        return o1.index < o2.index;  // 数字日志保持输入顺序
    }
    // 如果都是字母内容
    if (!isdigit1 && !isdigit2) {
        if (cont1 != cont2) {
            return cont1 < cont2;
        }
        return o1.s < o2.s;
    }
    // 一个是数字一个是字母，字母在前
    return isdigit1 ? false : true;  // 数字日志排在字母日志后
}

vector<string> reorderLogFiles(vector<string>& logs) {
    vector<Pairs>arr;
    for (int i = 0; i < logs.size(); i++) {
        arr.push_back(Pairs(logs[i],i));
    }
    sort(arr.begin(),arr.end(),self_compare);
    for (int i = 0; i < logs.size(); i++) {
        logs[i] = arr[i].s;
    }
    return logs;
}

// 034.验证外星语词典
    bool isAlienSorted(vector<string>& words, string order) {
        int n = order.size();
        vector<int>cnt(26);
        for (int i = 0; i < n; i++) {
            cnt[order[i] - -'a'] = i+1; // 构造顺序
        }
        string initial = words[0];
        for (int i = 1; i < words.size(); i++) {
            if (isorder(words[i], initial,cnt)) {
                initial = words[i];
            }else {
                return false;
            }
        }
        return true;
    }
    bool isorder(string s1, string s2, vector<int>& cnt) {
        int n = s1.size() < s2.size() ? s1.size() : s2.size();
        for (int i = 0; i < n; i++) {
            if (cnt[s1[i]-'a'] < cnt[s2[i] - 'a']) {
                return true;
            }else if (cnt[s1[i]-'a'] > cnt[s2[i] - 'a']) {
                return false;
            }
        }
        return s1.size() <= s2.size(); // 谁长度小谁在前
    }






int main() {
    
}



    
    

