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
// 268.��ʧ������
    // ��һ��λ����汾
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
    // ԭ�ع�ϣ
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

// 448.�ҵ�������������ʧ������
    // ��һ������iλ��Ϊi+1
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        // ����Ϊ��iλ��Ϊi+1
        for (int i = 0; i < n; i++)
        {
            while (nums[i] != nums[nums[i] - 1]) {
                // ����ʹ��nums[i]!=i+1�������ѭ��������[2,1,1,4] 
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
    // �����������ϣ
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
    
    // 506.�������
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string>ans(n); // ����������С��ϰ��
        unordered_map<int,int>map; // ��ϣ��
        for (int i = 0; i < n; i++) {
            map[score[i]] = i; // score[i]�Ǽ���i��ֵ
        }
        sort(score.begin(),score.end(),greater<int>()); // �������У�greater<int>()��תĬ�Ϲ���
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans[map[score[0]]] = "Gold Medal";
            } else if (i == 1) {
                ans[map[score[1]]] = "Silver Medal";
            } else if (i == 2) {
                ans[map[score[2]]] = "Bronze Medal";
            }else {
                ans[map[score[i]]] = to_string(i+1); // תΪ�ַ���
            }
        }
        return ans;
    }
    
    



};

// 703.�������еĵ�k��
// ��ôд�Ļ���ʱ����Ϊ�������Խ��Խ������Ҫͨ����(���ȶ���)������k֮���Ԫ��
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
    priority_queue<int,vector<int>,greater<int>> q; // С����
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


// ����������־�ļ�
class Pairs {
    public:
    string s;
    int index;
    Pairs (string body,int id) {
        s = body;
        index = id;
    }
};
// c++�Զ���Ƚ�����java�ǲ�ͬ�ģ�����
// ����true�����һ���������ȼ��ߣ�����false����ڶ������ȼ����߻��������ȼ�һ��
int self_compare(Pairs o1, Pairs o2) {
    size_t space_pos1 = o1.s.find(" ");
    size_t space_pos2 = o2.s.find(" ");
    // ��ʶ����
    string tag1 = o1.s.substr(0, space_pos1);
    string tag2 = o2.s.substr(0, space_pos2);
    // ���ݲ���
    string cont1 = o1.s.substr(space_pos1 + 1);
    string cont2 = o2.s.substr(space_pos2 + 1);
    // �ж����������ֻ�����ĸ
    bool isdigit1 = isdigit(cont1[0]);
    bool isdigit2 = isdigit(cont2[0]);
    // ��������������ݣ��򱣳�ԭ��˳��
    if (isdigit1 && isdigit2) {
        return o1.index < o2.index;  // ������־��������˳��
    }
    // ���������ĸ����
    if (!isdigit1 && !isdigit2) {
        if (cont1 != cont2) {
            return cont1 < cont2;
        }
        return o1.s < o2.s;
    }
    // һ��������һ������ĸ����ĸ��ǰ
    return isdigit1 ? false : true;  // ������־������ĸ��־��
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

// 034.��֤������ʵ�
    bool isAlienSorted(vector<string>& words, string order) {
        int n = order.size();
        vector<int>cnt(26);
        for (int i = 0; i < n; i++) {
            cnt[order[i] - -'a'] = i+1; // ����˳��
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
        return s1.size() <= s2.size(); // ˭����С˭��ǰ
    }






int main() {
    
}



    
    

