class Solution {
public:
    int maxDiff(int num) { 
        string b = to_string(num);
        char chMax = 0;
        for (char c : b) {
            if (c != '9') {
                chMax = c;
                break;
            }
        }
        if (chMax != 0) {
            for (char &c : b) {
                if (c == chMax) c = '9';
            }
        }

     
        string a = to_string(num);
        char chMin = 0;
        if (a[0] != '1') {
        
            chMin = a[0];
            for (char &c : a) {
                if (c == chMin) c = '1';
            }
        } else {
            
            for (int i = 1; i < a.size(); i++) {
                if (a[i] != '0' && a[i] != '1') {
                    chMin = a[i];
                    break;
                }
            }
            if (chMin != 0) {
                for (int i = 1; i < a.size(); i++) {
                    if (a[i] == chMin) a[i] = '0';
                }
            }
        }

        long long maxNum = stoll(b);
        long long minNum = stoll(a);
        return (int)(maxNum - minNum);
    }
};
