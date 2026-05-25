class Solution {
public:
    int helper(int hi, int lo, vector<int> &list, int goal){
        int mid = (hi+lo)/2;
        while(lo<=hi){
            if (list.at(mid)==goal){
                return mid;
            }
            else if (list.at(mid)>goal){
                return helper(mid-1,lo,list,goal);
            }
            else{
                return helper(hi,mid+1,list,goal);
            }
        }
        return -1;

        
    }
    int search(vector<int>& nums, int target) {
        return helper(nums.size()-1,0,nums,target);
    }
};
