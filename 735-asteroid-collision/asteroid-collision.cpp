class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];
            bool destroyed = false;

            while (!st.empty() && curr < 0 && st.top() > 0) {
                if (st.top() < -curr) {
                    st.pop(); 
                    continue;
                } else if (st.top() == -curr) {
                    st.pop(); 
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; 
                    break;
                }
            }

            if (!destroyed) {
                st.push(curr);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
