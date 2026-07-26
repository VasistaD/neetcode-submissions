class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        vector<int> count(26,0);
        int time=0;
        for(int task:tasks)
            count[task - 'A']++;
        
        for(int i=0;i<26;i++)
            if(count[i] > 0)
                pq.push(count[i]);

        while(!pq.empty() || !q.empty())
        {
            time++;
            if(pq.empty())
                time = q.front().second;
            else
            {
                int cnt = pq.top()-1;
                pq.pop();
                if(cnt>0)
                    q.push({cnt,time + n});
            }
            if(!q.empty() && q.front().second == time)
            {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
