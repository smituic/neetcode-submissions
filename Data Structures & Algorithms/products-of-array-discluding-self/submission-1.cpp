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

        int right =1;
        for (int i=nums.size()-1;i>=0;i--){
            leftArr[i] *= right;

            right *= nums[i];
            
        }

        

        return leftArr;
    }
};