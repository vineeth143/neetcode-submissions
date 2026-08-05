class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> umap;

        for(int i : nums) {
            umap[i]++;
        }

        for(int i : nums) {
            if(umap[i] > 1)
                return true;
        }

        return false;
    }
};