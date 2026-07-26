class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int ele:nums)
            hashMap[ele]++;
        
        for(auto ele:hashMap)
        {
            int num = ele.first;
            int freq = ele.second;
            // cout<<num<<":"<<freq<<endl;
            if(pq.size() < k)
                pq.push({freq,num});
            else if(pq.top().first < freq)
            {
                pq.pop();
                pq.push({freq,num});
                // cout<<"POP"<<endl;
                // cout<<num<<":"<<freq<<endl;

            }
        }
        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
