class Solution {
    unordered_set<string> all;

    void pnc(int i, string &s) {
        if (i == s.size()) {
            all.insert(s); 
            return;
        }
        for (int j = i; j < s.size(); j++) {
            swap(s[i], s[j]);
            pnc(i + 1, s);
            swap(s[i], s[j]);
        }
    }

    void solve(int i, string &tiles, string &temp, unordered_set<string> &candi) {
        if (i == tiles.size()) {
            if (!temp.empty()) candi.insert(temp);
            return;
        }
        temp.push_back(tiles[i]);
        solve(i + 1, tiles, temp, candi);
        temp.pop_back();
        solve(i + 1, tiles, temp, candi);
    }

public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> candi;
        string temp = "";
        solve(0, tiles, temp, candi);

        for (auto &str : candi) {
            string t = str;
            pnc(0, t);
        }

        return all.size(); 
    }
};
