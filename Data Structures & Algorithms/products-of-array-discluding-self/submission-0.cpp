class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProd(n,1);
        vector<int> rightProd(n,1);
        leftProd[0] = nums[0];
        for(int i=1;i<n;i++) {
            leftProd[i] = leftProd[i-1]*nums[i];
        }

        rightProd[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--) {
            rightProd[i] = rightProd[i+1]*nums[i];
        }

        vector<int> res;
        for(int i=0;i<n;i++) {
            if(i==0)
                res.push_back(rightProd[i+1]);
            else if(i==n-1)
                res.push_back(leftProd[i-1]);
            else {
                res.push_back(leftProd[i-1]*rightProd[i+1]);
            }
        }
        return res;
    }
};
