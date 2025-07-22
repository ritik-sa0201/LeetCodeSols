class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string current = "";

        for (char c : s) {
            if (c == ' ') {
                reverse(current.begin(), current.end());
                words.push_back(current);
                current = "";
            } else {
                current += c;
            }
        }


        if (!current.empty()) {
            reverse(current.begin(), current.end());
            words.push_back(current);
        }

  
        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i != words.size() - 1) ans += ' ';
        }

        return ans;
    }
};
