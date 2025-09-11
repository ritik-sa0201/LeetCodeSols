class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;

        for (int i = 0; i < words.size(); i++) {
            sort(words[i].begin(), words[i].end());
        }

        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                int x = 0, y = 0;
                bool flag = false;
                int l1 = words[i].size(), l2 = words[j].size();


                while (x < l1 && y < l2) {
                    if (words[i][x] == words[j][y]) {
                        flag = true;
                        break;
                    } else if (words[i][x] < words[j][y]) {
                        x++;
                    } else {
                        y++;
                    }
                }

                if (!flag) ans = max(ans, l1 * l2);
            }
        }

        return ans;
    }
};
