class Solution {
   int maxi(const string& answerKey, int k, char ch) {
        int i = 0, j = 0, count = 0, maxlen = 0;

        while (j < answerKey.size()) {
            if (answerKey[j] == ch) count++;

            while (count > k) {
                if (answerKey[i] == ch) count--;
                i++;
            }

            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        return maxlen;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
           int ans = INT_MIN;
           ans = max(ans,maxi(answerKey,k,'F'));
           ans = max(ans,maxi(answerKey,k,'T'));
           return ans;
    }
};