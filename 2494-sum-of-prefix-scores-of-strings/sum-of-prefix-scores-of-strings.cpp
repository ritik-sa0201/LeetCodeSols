class Solution {
public:
    struct node {
        bool isEnd;
        node* children[26];
        int prefixOf;
        node() {
            isEnd = false;
            prefixOf = 0;
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    node* getNode() {
        return new node();
    }

    void insert(node* root, string word) {
        node* temp = root;
        for (char ch : word) {
            int idx = ch - 'a';   
            if (temp->children[idx] == nullptr) {
                temp->children[idx] = getNode();
            }
            temp = temp->children[idx];
            temp->prefixOf++;
        }
        temp->isEnd = true;
    }

    int search(node* root, string s) {
        node* temp = root;
        int ans = 0;
        for (char ch : s) {
            int idx = ch - 'a'; 
            if (temp->children[idx] == nullptr) break;
            temp = temp->children[idx];
            ans += temp->prefixOf;
        }
        return ans;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        node* root = getNode();
        for (string &s : words) {
            insert(root, s);
        }
        vector<int> ans;
        for (string &s : words) {
            ans.push_back(search(root, s));
        }
        return ans;
    }
};
