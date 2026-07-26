class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0,r=0;
        int n = nums.size();
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        while(r <= n)
        {
            // if(r < k || pq.empty())
            // {
            //     // continue;
            //     // pq.push({nums[r],r});
            //     cout<<"bro"<<endl;
            // }
            if(r >= k && !pq.empty())
            {
                int maxEle = pq.top().first;
                int maxInd = pq.top().second;
                // cout<<maxInd<<" : "<<maxEle<<endl;
                while(!pq.empty() && maxInd < l)
                {
                    pq.pop();
                    maxEle = pq.top().first;
                    maxInd = pq.top().second;
                }
                res.push_back(maxEle);
                // pq.push({nums[r],r});
                l++;
            }
            pq.push({nums[r],r});
            r++;
            // cout<<l<<","<<r<<endl;
        }
        return res;
    }
};
