class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int, int> s; 
        s[d(p1, p2)]++;
        s[d(p1, p3)]++;
        s[d(p1, p4)]++;
        s[d(p2, p3)]++;
        s[d(p2, p4)]++;
        s[d(p3, p4)]++;
        if (s.size() != 2) return false;
        return s.begin()->second == 4 && s.rbegin()->second == 2;
    }

    int d(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};