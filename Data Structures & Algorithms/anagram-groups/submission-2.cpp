class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        vector<vector<string>> resGroup;
        for(auto s : strs) {
            vector<int> charFreq(26, 0);

            for(auto c : s) {
                charFreq[c-'a']++;
            }

            string res = "";
            for(auto i : charFreq) {
                res += ',' + to_string(i);
            }

            umap[res].push_back(s);

        }

        for(auto p : umap) {
            resGroup.push_back(p.second);
        }
        return resGroup;
        
    }
};
