class Solution {
    string decToBinary(int n) { 
        string bin = "";
        while (n > 0) {
            bin.push_back('0' + (n % 2));
            n /= 2;
        }
        reverse(bin.begin(), bin.end());
        return bin;
    }

public:
    bool queryString(string s, int n) {
        for (int i = 1; i <= n; i++) {
            string bin = decToBinary(i);
            if (s.find(bin) == string::npos) return false;
        }
        return true;
    }
};
