class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int n = nums.size();
        vector<int> res;
        for(int i=0;i<k;i++)
            pq.push({nums[i],i});
        for(int i=k;i<n;i++)
        {
            while(pq.top().second < i-k)
            {
                pq.pop();
            }
            res.push_back(pq.top().first);
            pq.push({nums[i],i});
        }
        while(pq.top().second < n-k)
        {
            pq.pop();
        }
        res.push_back(pq.top().first);
        return res;
    }
};
