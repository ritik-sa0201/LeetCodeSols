class Solution {
public:
    string convertToTitle(int c) {
        string res = "";
        while (c > 0) {
            c--;  
            int r = c % 26;
            res += char('A' + r);
            c /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
