class Solution {
    void pse(vector<int>& arr, vector<int>& ans) {
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if (st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());
            st.push(i);
        }
    }

    void nse(vector<int>& arr, vector<int>& ans) {
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (st.empty()) ans.push_back(arr.size());
            else ans.push_back(st.top());
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        vector<int> prevSmaller, nextSmaller;

        pse(arr, prevSmaller);
        nse(arr, nextSmaller);

        long long result = 0;

        for (int i = 0; i < arr.size(); i++) {
            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;
            long long contribution = (left * right) % mod;
            contribution = (contribution * arr[i]) % mod;
            result = (result + contribution) % mod;
        }

        return (int)result;
    }
};
