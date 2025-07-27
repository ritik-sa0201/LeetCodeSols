class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)return stones[0];
        priority_queue<int>maxh;
        for(int i:stones)maxh.push(i);
        
        while(maxh.size()>1){
            int top = maxh.top();maxh.pop();
            int second = maxh.top();maxh.pop();
            if(top !=second)maxh.push(abs(top-second));
        }
        return maxh.size()>0 ? maxh.top() : 0;
    }
};