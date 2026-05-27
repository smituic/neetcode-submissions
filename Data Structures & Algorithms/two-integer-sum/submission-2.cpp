class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> map;

        for (int i=0; i<nums.size();i++){
            int want = target - nums[i];

            if(map.count(want)){
                return {map[want],i};
            }

            map[nums[i]] = i;
        }

        return {};
    }
};
