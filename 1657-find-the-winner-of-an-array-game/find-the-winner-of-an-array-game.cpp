class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>arr.size())return *max_element(arr.begin(),arr.end());
        deque<int>q;
        for(int x : arr)q.push_back(x);
        int curr = q.front();
        int temp = 0;
        while(!q.empty()){
            int a = q.front();
            q.pop_front();
            int b = q.front();
            q.pop_front();
            if(a>b){
                q.push_back(b);
                q.push_front(a);
                temp++;
                if(temp==k)return curr;
            }
            else{
                 q.push_front(b);
                 q.push_back(a);
                 temp = 1;
                 curr = b;
                 if(temp==k)return curr;
            }
        }
        return -1;
    }
};