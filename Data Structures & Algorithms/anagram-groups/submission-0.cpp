class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map <string,vector<string>> mp;
        vector<vector<string>> ret;
        
        for(int i=0;i<strs.size();i++){
            string newStr = strs[i];
            sort(newStr.begin(), newStr.end());

            mp[newStr].push_back(strs[i]);  
        }

        for(const auto& [key, pair] :mp){
            ret.push_back(pair);
        }

        return ret; 
    }
};
