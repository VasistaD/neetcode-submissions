class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int l=0,r=n-1;
        int maxArea = 0;
        while(l < r)
        {
            int minHeight = min(heights[l],heights[r]);
            int curArea = minHeight * (r-l);
            maxArea = max(curArea,maxArea);
            // cout<<maxArea<<endl;
            if(heights[l] < heights[r])
                l++;
            else
                r--;
        }
        return maxArea;
    }
};
