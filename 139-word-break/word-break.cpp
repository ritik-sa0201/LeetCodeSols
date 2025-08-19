class Solution {
public:
    struct node {
        bool isEnd;
        node* children[26];
    };

    node* createNode() {
        node* newNode = new node;
        newNode->isEnd = false;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = nullptr;
        }
        return newNode;
    }

    void insert(node* root, string word) {
        node* temp = root;
        for (char ch : word) {
            if (temp->children[ch - 'a'] == nullptr) {
                temp->children[ch - 'a'] = createNode();
            }
            temp = temp->children[ch - 'a'];
        }
        temp->isEnd = true;
    }

    bool dfs(string& s, int index, node* root, vector<int>& dp) {
        if (index == s.size()) return true;
        if (dp[index] != -1) return dp[index];

        node* temp = root;
        for (int i = index; i < s.size(); i++) {
            if (temp->children[s[i] - 'a'] == nullptr) break;
            temp = temp->children[s[i] - 'a'];
            if (temp->isEnd && dfs(s, i + 1, root, dp)) {
                return dp[index] = true;
            }
        }
        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        node* root = createNode();
        for (string& x : wordDict) {
            insert(root, x);
        }
        vector<int> dp(s.size(), -1); 
        return dfs(s, 0, root, dp);
    }
};
