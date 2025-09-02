class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] > b[1];
        });

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
      
                if (points[i][0] <= points[j][0] && points[i][1] >= points[j][1]) {
                    bool blocked = false;

                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;

                        if (points[i][0] <= points[k][0] && points[k][0] <= points[j][0] &&
                            points[j][1] <= points[k][1] && points[k][1] <= points[i][1]) {
                            blocked = true;
                            break;
                        }
                    }

                    if (!blocked) count++;
                }
            }
        }
        return count;
    }
};
