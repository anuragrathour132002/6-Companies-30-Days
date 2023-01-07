class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>points) {
    int res = 0;
    for (int i = 0; i < points.size(); ++i) {    
        unordered_map<long, int> group(points.size());
            for (int j = 0; j < points.size(); ++j) {
             if (j == i) continue;
            int dy = points[i].second - points[j].second;
            int dx = points[i].first - points[j].first;
            int key = dy * dy;
            key += dx * dx;
            ++group[key];
        }
        for (auto& p : group) {
            if (p.second > 1) {
                res += p.second * (p.second - 1);
            }
        }
    }
    
    return res;
 }
};