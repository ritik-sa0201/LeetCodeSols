class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i=0;i<=num;i++){
            int a = i;
            string b =to_string(a);
            reverse(b.begin(),b.end());
            if(num == a+stoi(b))return true;
        }
        return false;
    }
};