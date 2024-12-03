// 利用前缀和快速得到区域累加和
// 测试链接 : https://leetcode.cn/problems/range-sum-query-immutable/

class NumArray {
public:

    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr.resize(nums.size());
        for(int i=0;i<nums.size();i++){
            arr[i] = nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        int res = 0;
        for(int i=left;i<=right;i++){
            res+=arr[i];
        }
        return res;
    }
};