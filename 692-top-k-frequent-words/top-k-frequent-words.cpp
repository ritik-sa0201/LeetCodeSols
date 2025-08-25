class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for (auto& w : words) {
            mp[w]++;
        }

        struct cmp {
            bool operator()(const pair<int,string>& a, const pair<int,string>& b) {
                if (a.first == b.first)
                    return a.second < b.second; 
                return a.first > b.first; 
            }
        };

        priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> minh;

        for (auto& it : mp) {
            minh.push({it.second, it.first});
            if (minh.size() > k) minh.pop();
        }

        vector<string> ans;
        while (!minh.empty()) {
            ans.push_back(minh.top().second);
            minh.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
