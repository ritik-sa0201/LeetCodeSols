class Solution {
public:
        int countBits(long long num) { 
        int count = 0; 
        while (num > 0) { 
            count += num & 1; 
            num >>= 1; 
        } 
        return count; 
    } 

    int makeTheIntegerZero(int num1, int num2) {
            if(num2>num1)return -1;

            
        for (int i = 0; i <= 60; i++) { 
            long long diff = num1 - (num2)*1LL*i; 
            int bits = countBits(diff); 
            if (bits <= i && i<=diff) { 
                return i; 
            } 
        } 
 
        return -1; 


    }
};