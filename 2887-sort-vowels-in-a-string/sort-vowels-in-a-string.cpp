class Solution {
public:
    string sortVowels(string s) {
        vector<int> v(10, 0);
        for (char ch : s) {
            if (ch == 'A') v[0]++;
            else if (ch == 'E') v[1]++;
            else if (ch == 'I') v[2]++;
            else if (ch == 'O') v[3]++;
            else if (ch == 'U') v[4]++;
            else if (ch == 'a') v[5]++;
            else if (ch == 'e') v[6]++;
            else if (ch == 'i') v[7]++;
            else if (ch == 'o') v[8]++;
            else if (ch == 'u') v[9]++;
        }
        string mapping = "AEIOUaeiou";  
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            if (string("AEIOUaeiou").find(s[j]) != string::npos) {
                while (i < 10 && v[i] == 0) i++; 
                s[j] = mapping[i];   
                v[i]--;    
            }
        }

        return s;
    }
};
