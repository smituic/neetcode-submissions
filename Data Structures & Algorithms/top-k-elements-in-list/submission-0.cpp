class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map <int,int> mp;
        vector<int> res;
        int c = 0;
        int largestKey;
        int largest;

        for(int n:nums){
            mp[n]++;
        }
        
        while(c<k){
            largest = -999;
            largestKey = 0;
            
            for(auto [key,value] : mp){
                if (value>largest){
                    largest = value;
                    largestKey = key;
                }
            }
            res.push_back(largestKey);
            mp.erase(largestKey);
            c++;
        }

        return res;
    }
};
