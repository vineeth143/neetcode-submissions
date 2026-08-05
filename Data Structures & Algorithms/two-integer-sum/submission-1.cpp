class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        int n = nums.size();

        for(int i=0;i<n;i++) {
            umap[nums[i]] = i;
        }

        for(int i=0;i<n;i++) {
            if(umap.find(target-nums[i])!=umap.end()) {
                int j = umap[target-nums[i]];
                if(i!=j)
                    return {i,umap[target-nums[i]]};
            }
                
        }

        return {};
    }
};
