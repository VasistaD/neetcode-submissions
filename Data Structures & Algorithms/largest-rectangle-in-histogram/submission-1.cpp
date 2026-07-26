class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int n = heights.size();
        int maxArea = 0;

        for(int i=0;i<n;i++)
        {
            if(!st.empty())
            {
                if(heights[i] > st.top().first)
                    st.push({heights[i],i});
                else
                {
                    int tp,posi;
                    while(!st.empty() && heights[i] <= st.top().first)
                    {   
                        tp = st.top().first;
                        posi = st.top().second;
                        maxArea = max(maxArea, tp * (i - posi));
                        st.pop();
                    }
                    st.push({heights[i],posi});
                }
            }
            else
                st.push({heights[i],i});
        }

        while(!st.empty())
        {
            maxArea = max(maxArea, st.top().first * (n - st.top().second));
            st.pop();
        }
        return maxArea;
    }
};
