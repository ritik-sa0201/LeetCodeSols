struct TrieNode {
    vector<string> w;
    unordered_map<char, TrieNode*> nxt;
};

class Solution {
public:
    vector<string> spellchecker(vector<string>& wl, vector<string>& qs) {
        unordered_set<char> vowSet = {'a','e','i','o','u'};
        
        TrieNode* exRoot = new TrieNode;
        TrieNode* lowRoot = new TrieNode;
        TrieNode* vowRoot = new TrieNode;
        
        for (auto& s : wl) {
            TrieNode* ex = exRoot;
            TrieNode* low = lowRoot;
            TrieNode* vow = vowRoot;
            for (auto c : s) {
                if (!ex->nxt.count(c)) ex->nxt[c] = new TrieNode;
                ex = ex->nxt[c];
                
                if (c <= 'Z') c += 32;
                if (!low->nxt.count(c)) low->nxt[c] = new TrieNode;
                low = low->nxt[c];
                
                char k = (vowSet.count(c) ? '*' : c);
                if (!vow->nxt.count(k)) vow->nxt[k] = new TrieNode;
                vow = vow->nxt[k];
            }
            ex->w.push_back(s);
            low->w.push_back(s);
            vow->w.push_back(s);
        }
        
        vector<string> ans;
        for (auto& s : qs) {
            TrieNode* ex = exRoot;
            TrieNode* low = lowRoot;
            TrieNode* vow = vowRoot;
            for (auto c : s) {
                if (ex && ex->nxt.count(c)) ex = ex->nxt[c];
                else ex = nullptr;
                
                if (c <= 'Z') c += 32;
                if (low && low->nxt.count(c)) low = low->nxt[c];
                else low = nullptr;
                
                char k = (vowSet.count(c) ? '*' : c);
                if (vow && vow->nxt.count(k)) vow = vow->nxt[k];
                else vow = nullptr;
            }
            if (ex && !ex->w.empty()) ans.push_back(ex->w[0]);
            else if (low && !low->w.empty()) ans.push_back(low->w[0]);
            else if (vow && !vow->w.empty()) ans.push_back(vow->w[0]);
            else ans.push_back("");
        }
        return ans;
    }
};
