class Solution {
public:
    bool canAliceWin(int n) {
        bool flag = true;
        int i = 10;
        while (n > 0 && i > 0) {
            if(i>n)break;
            n -= i;
            i--;
            flag = !flag;
        }
        return !flag; 
    }
};
