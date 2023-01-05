class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0 , right = 0 , end = s.size() - 1;
        unordered_map<char,int> map;
        int count = 0;
        
        while(right != s.size()){
            map[s[right]] += 1; 
            while(map['a'] and map['b'] and map['c']){
                count += 1 + (end - right);
                map[s[left]] -= 1; 
                left++;
            }
            right++;
        }
        return count;
    }
};