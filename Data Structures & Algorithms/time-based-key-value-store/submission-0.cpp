class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> keyStore;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        keyStore[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto keyList = keyStore[key];
        int l=0, r=keyList.size()-1;
        string res = "";

        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(keyList[mid].first <= timestamp)
            {
                res = keyList[mid].second;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return res;
    }
};
