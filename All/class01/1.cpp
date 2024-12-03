// 利用前缀和快速得到区域累加和
// 测试链接 : https://leetcode.cn/problems/range-sum-query-immutable/

class NumArray {
public:

    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr.resize(nums.size()+1);
        for(int i=1;i<=nums.size();i++){
            arr[i] = nums[i-1]+arr[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return arr[right+1]-arr[left];
    }
};