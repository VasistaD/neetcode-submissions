class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> hashMaps1;
        unordered_map<char,int> hashMaps2;

        for(char ch:s1)
            hashMaps1[ch]++;

        int l=0,r=0,n=s2.size();
        // bool flag=false;

        while(r < n)
        {
            if(hashMaps1.count(s2[r]) == 0)
            {
                // cout<<s2[r]<<" not present"<<endl;
                l=r;
                l++;
                r++;
                hashMaps2.clear();
            }
            else
            {
                hashMaps2[s2[r]]++;
                // cout<<s2[r]<<" is present"<<endl;
                while(l < r && hashMaps2[s2[r]] > hashMaps1[s2[r]])
                {
                    hashMaps2[s2[l]]--;
                    if(hashMaps2[s2[l]] == 0)
                        hashMaps2.erase(s2[l]);
                    // cout<<s2[l]<<" removed from left"<<endl;
                    l++;
                }
                // cout<<"hashmaps1:"<<endl;
                // for(auto ele:hashMaps1)
                //     cout<<ele.first<<":"<<ele.second<<endl;
                // cout<<"hashmaps2:"<<endl;
                // for(auto ele:hashMaps2)
                //     cout<<ele.first<<":"<<ele.second<<endl;
                if(hashMaps2 == hashMaps1)
                    return true;
                r++;
            }
        }
        return false;
    }
};
