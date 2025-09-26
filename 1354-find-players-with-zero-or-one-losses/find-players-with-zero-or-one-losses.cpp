class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> losses;
        set<int> players;
        for (auto &match : matches) {
            int a = match[0]; 
            int b = match[1];
            players.insert(a);
            players.insert(b);
            losses[b]++; 
        }
        vector<int> zeroLoss, oneLoss;
        for (auto &p : players) {
            if (losses.find(p) == losses.end()) {
                zeroLoss.push_back(p);
            }
        }
        for (auto &it : losses) {
            if (it.second == 1) {
                oneLoss.push_back(it.first);
            }
        }
        sort(zeroLoss.begin(), zeroLoss.end());
        sort(oneLoss.begin(), oneLoss.end());

        return {zeroLoss, oneLoss};
    }
};
