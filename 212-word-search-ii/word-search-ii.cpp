class Solution {
    vector<string> result;
    int m, n;

    struct node {
        bool isEnd;
        vector<node*> children;
        string word;

        node() {
            isEnd = false;
            children.assign(26, nullptr);
            word = "";
        }
    };

    node* getNode() {
        return new node();
    }

    void insert(node* root, const string &word) {
        node* temp = root;
        for (char c : word) {
            int idx = c - 'a';
            if (temp->children[idx] == nullptr) {
                temp->children[idx] = getNode();
            }
            temp = temp->children[idx];
        }
        temp->isEnd = true;
        temp->word = word;
    }

    vector<pair<int, int>> directions{{-1, 0},{1, 0},{0, 1},{0, -1}};

    void helper(vector<vector<char>>& board, int i, int j, node* root) {
        if (i < 0 || i >= m || j < 0 || j >= n) return;

        char ch = board[i][j];
        if (ch == '$') return; 
        
        root = root->children[ch - 'a'];
        if (root == nullptr) return; 

        if (root->isEnd) {
            result.push_back(root->word);
            root->isEnd = false;
        }

        board[i][j] = '$';

        for (auto &p : directions) {
            helper(board, i + p.first, j + p.second, root);
        }

        board[i][j] = ch; 
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        node* root = getNode();
        for (auto &w : words) {
            insert(root, w);
        }

        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (root->children[board[i][j] - 'a'] != nullptr) {
                    helper(board, i, j, root);
                }
            }
        }
        return result;
    }
};
