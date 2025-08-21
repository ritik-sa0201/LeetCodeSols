class WordDictionary {
public:
    struct node {
        bool isEnd;
        node* children[26];
        node() {
            isEnd = false;
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    node* root;

    WordDictionary() {
        root = new node();
    }

   
    void addWord(string word) {
        node* temp = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (temp->children[idx] == nullptr) {
                temp->children[idx] = new node();
            }
            temp = temp->children[idx];
        }
        temp->isEnd = true;
    }


    bool dfs(node* cur, string &word, int i) {
        if (i == word.size()) return cur->isEnd;

        char ch = word[i];
        if (ch == '.') {
           
            for (int j = 0; j < 26; j++) {
                if (cur->children[j] && dfs(cur->children[j], word, i + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            int idx = ch - 'a';
            if (cur->children[idx] == nullptr) return false;
            return dfs(cur->children[idx], word, i + 1);
        }
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};
