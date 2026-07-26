struct pairComp {
    bool operator()(pair<double,int> a, pair<double,int> b) {
        return a.first > b.first;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>,vector<pair<double,int>>, pairComp> pq;
        for(int i=0;i<points.size();i++)
        {
            double dist = sqrt(pow(points[i][0],2) + pow(points[i][1],2));
            // cout<<i<<" : "<<dist<<endl;
            pq.push({dist,i});
        }
        vector<vector<int>> res;
        while(k--)
        {
            cout<<pq.top().first<<endl;
            int ind = pq.top().second;
            res.push_back(points[ind]);
            pq.pop();
        }
        return res;
    }
};
