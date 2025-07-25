class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

    for (char digit : num) {
        while (!st.empty() && k > 0 && st.top() > digit) {
            st.pop();
            k--;
        }
        st.push(digit);
    }

    // If k still > 0, remove from the end
    while (k-- > 0 && !st.empty()) {
        st.pop();
    }

    // Build the result from stack
    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());

    // Remove leading zeros
    int i = 0;
    while (i < result.size() && result[i] == '0') i++;
    result = result.substr(i);

    return result.empty() ? "0" : result;
    }
};