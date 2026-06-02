class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1;
        vector<int> leftArr;
        leftArr.push_back(left);

        for (int i=1;i<nums.size();i++){
            left *= nums[i-1];
            leftArr.push_back(left);
        }

        int right = 1;
        deque<int> rightArr;
        rightArr.push_front(right);

        for (int i=nums.size()-1;i>0;i--){
            right *= nums[i];
            rightArr.push_front(right);
        }

        vector<int> ret;

        for (int i=0;i<nums.size();i++){
            ret.push_back(leftArr[i] * rightArr[i]);
        }

        return ret;
    }
};
