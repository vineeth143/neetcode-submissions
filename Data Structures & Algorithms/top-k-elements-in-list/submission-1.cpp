class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> umap;

        for(auto i : nums) {
            umap[i]++;
        }

        vector<vector<int>> freq(n+1, vector<int>());

        for(auto p : umap) {
            freq[p.second].push_back(p.first);
        }

        vector<int> res;
        for(int i=n;i>=0;i--) {
            if(k==0)
                break;
            else {
                if(freq[i].size()) {
                    for(auto e : freq[i]) {
                        res.push_back(e);
                        k--;
                    }
                    
                }
            }
        }
        return res;
        
    }
};
