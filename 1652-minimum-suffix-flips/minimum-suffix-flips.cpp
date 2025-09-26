class Solution {
public:
    int minFlips(string target) {
        int ans = 0;
        int i = 0;
        while(i < target.size() && target[i] == '0') i++;
        if (i == target.size()) return 0;
        for (; i < target.size()-1; i++) {
            if (target[i] != target[i+1]) ans++;
        }
        return ans + 1;
    }
};
