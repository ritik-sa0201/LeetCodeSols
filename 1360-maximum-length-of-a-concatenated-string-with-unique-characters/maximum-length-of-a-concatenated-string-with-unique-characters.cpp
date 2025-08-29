class Solution {
    int solve(int i, set<char>& st, vector<string>& arr) {
        if (i == arr.size()) {
            return 0;
        }

        int ans = solve(i + 1, st, arr);

        set<char> wordSet(arr[i].begin(), arr[i].end());
        if (wordSet.size() != arr[i].size()) {
            return ans;
        }

  
        bool used = false;
        for (char c : arr[i]) {
            if (st.count(c)) {
                used = true;
                break;
            }
        }

    
        if (!used) {
            for (char c : arr[i]) st.insert(c);
            ans = max(ans, (int)arr[i].size() + solve(i + 1, st, arr));
            for (char c : arr[i]) st.erase(c); 
        }

        return ans;
    }

public:
    int maxLength(vector<string>& arr) {
        set<char> st;
        return solve(0, st, arr);
    }
};
