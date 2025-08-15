class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};
        
        unordered_map<char, int> mp, curr;
        for (char ch : p) mp[ch]++;

        int i = 0, j = 0, n = p.size(), cnt = 0;
        vector<int> ans;

       
        for (j = 0; j < n; j++) {
            if (mp.find(s[j]) != mp.end()) {
                curr[s[j]]++;
                if (curr[s[j]] == mp[s[j]]) cnt++;
            }
        }
        if (cnt == mp.size()) ans.push_back(i);

     
        while (j < s.size()) {
        
            char left = s[i];
            if (mp.find(left) != mp.end()) {
                if (curr[left] == mp[left]) cnt--;
                curr[left]--;
            }
            i++;
            char right = s[j];
            if (mp.find(right) != mp.end()) {
                curr[right]++;
                if (curr[right] == mp[right]) cnt++;
            }
            j++;

            if (cnt == mp.size()) ans.push_back(i);
        }
        return ans;
    }
};
