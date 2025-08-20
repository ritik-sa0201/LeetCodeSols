class Solution {
    struct node {
        bool isEnd;
        string nword;
        node* children[26];
        node() {
            isEnd = false;
            nword = "";
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    node* getNode() {
        return new node();
    }

    void insertTree(node* root, string word) {
        node* temp = root;
        for (char ch : word) {
            if (temp->children[ch - 'a'] == nullptr) {
                temp->children[ch - 'a'] = getNode();
            }
            temp = temp->children[ch - 'a'];
        }
        temp->isEnd = true;
        temp->nword = word;
    }

    string replace(node* root, string word) {
        node* temp = root;
        for (char ch : word) {
            if (temp->children[ch - 'a'] == nullptr) {
                return word; 
            }
            temp = temp->children[ch - 'a'];
            if (temp->isEnd) {
                return temp->nword;
            }
        }
        return word;
    }

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        node* root = getNode();
        for (string s : dictionary) {
            insertTree(root, s);
        }

        string ans = "";
        string curr = "";

        for (char ch : sentence) {
            if (ch == ' ') {
                ans += replace(root, curr);
                ans += ' ';
                curr = "";
            } else {
                curr += ch;
            }
        }

        if (!curr.empty()) {
            ans += replace(root, curr);
        }

        return ans;
    }
};
