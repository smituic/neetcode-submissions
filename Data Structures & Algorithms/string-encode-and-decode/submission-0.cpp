class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";

        for (string str : strs) {
            int len = str.length();
            s += to_string(len) + "#" + str;
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while (i < s.length()) {
            int j = i;

            while (s[j] != '#') {
                j++;
            }

            int length = stoi(s.substr(i, j - i));

            string str = s.substr(j + 1, length);
            res.push_back(str);

            i = j + 1 + length;
        }

        return res;
    }
};