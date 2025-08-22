class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int j = s.size() - 1;
        string ans = "";
        while (j >= 0) {
        
            while (j >= 0 && s[j] != '[') {
                string ch(1, s[j]);   
                st.push(ch);
                j--;
            }

            if (j < 0) break;
            j--; 

            string curr = "";
           
            while (!st.empty() && st.top() != "]") {
                curr += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); 

    
            int numEnd = j;
            while (j >= 0 && isdigit(s[j])) j--;
            int times = stoi(s.substr(j + 1, numEnd - j));

            string temp = curr;
            string expanded = "";
            while (times--) expanded += curr;

            st.push(expanded);
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
