class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),l=0,r=n-1;
        int maxL = height[0], maxR = height[n-1];
        int res = 0;
        while(l < r)
        {
            if(maxL < maxR)
            {
                
                res += maxL - height[l];
                l++;
                maxL = max(height[l],maxL);
                // l++;
            }
            else
            {
                res += maxR - height[r];
                r--;
                maxR = max(maxR, height[r]);
                // r--;
            }
        }
        return res;
    }
};
