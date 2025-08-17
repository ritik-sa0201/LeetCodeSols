class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        unordered_map<char,int> mp, temp;
        for(char ch : s1) mp[ch]++;

        int i = 0, j = 0, cnt = 0;
        int k = s1.size();

        for(j = 0; j < k; j++) {
            temp[s2[j]]++;
            if(mp.find(s2[j]) != mp.end() && mp[s2[j]] == temp[s2[j]]) {
                cnt++;
            }
        }
        if(cnt == mp.size()) return true;


        while(j < s2.size()) {
          
            if(mp.find(s2[i]) != mp.end() && mp[s2[i]] == temp[s2[i]]) {
                cnt--;
            }
            temp[s2[i]]--;
            i++;

        
            temp[s2[j]]++;
            if(mp.find(s2[j]) != mp.end() && mp[s2[j]] == temp[s2[j]]) {
                cnt++;
            }
            j++;

            if(cnt == mp.size()) return true;
        }

        return false;
    }
};
