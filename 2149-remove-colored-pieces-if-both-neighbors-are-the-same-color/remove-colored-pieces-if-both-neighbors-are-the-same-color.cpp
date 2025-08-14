class Solution {
public:
    bool winnerOfGame(string colors) {
        long long n = colors.size();
        long long a = 0, b = 0;
        long long i = 0, j = 0;

        // Count moves for A
        while (i < n) {
            if (colors[i] == 'A') {
                j = i;
                while (j < n && colors[j] == 'A') j++;
                if (j - i > 2) a += (j - i - 2);
                i = j;
            } else {
                i++;
            }
        }

     
        i = 0;
        while (i < n) {
            if (colors[i] == 'B') {
                j = i;
                while (j < n && colors[j] == 'B') j++;
                if (j - i > 2) b += (j - i - 2);
                i = j; 
            } else {
                i++;
            }
        }

        return a > b;
    }
};
