/*
Consider two map - one for keep track of total views and second for tracking best id with max view for each creator.

So the map storage looks like : { creator : view_count } & { creator : {view_count, id } }

So now just we need to keep track of max view count while adding to the map, and at the end, acan for the creators with sam view as that of max view found.

Note: Do not forget to define view count as long long as the view count can be more than max int size.
*/

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        
        unordered_map<string, long long> mp;
        unordered_map<string, pair<int, string>> imp;
        long long mx = -1;
        for(int i = 0; i < creators.size(); ++i){
            long long v = views[i];
            if(mp.find(creators[i]) == mp.end()) mp[creators[i]] = v; 
            else mp[creators[i]] += v;
            if(mx < mp[creators[i]]) mx = mp[creators[i]];
            
            if(imp.find(creators[i]) == imp.end())   imp[creators[i]] = {views[i], ids[i]};
            else{                                                           //Evaluate max view for each creator
                if( imp[creators[i]].first < views[i])  imp[creators[i]] = {views[i], ids[i]};
                else if(imp[creators[i]].first == views[i] && imp[creators[i]].second > ids[i]){
                    imp[creators[i]] = {views[i], ids[i]};
                }
            }
        }
        
        vector<vector<string>> ans;
        for(auto m: mp){                         //scan for the creators with view equal to max
            if(mx == m.second){
                ans.push_back({m.first, imp[m.first].second});
            }
        }
        return ans;
    }
};