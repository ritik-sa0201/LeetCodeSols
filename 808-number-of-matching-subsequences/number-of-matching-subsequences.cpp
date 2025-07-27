class Solution {
public:
    bool isSubsequence(string& s, string& word) {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] == word[j]) j++;
            i++;
        }
        return j == word.size();
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, bool> cache;
        int count = 0;
        for (string& word : words) {
            if (cache.count(word)) {
                count += cache[word];
            } else {
                bool match = isSubsequence(s, word);
                cache[word] = match;
                count += match;
            }
        }
        return count;
    }
};
