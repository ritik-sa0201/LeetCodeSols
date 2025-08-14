class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>maxh;
        for(int i=0;i<score.size();i++)maxh.push({score[i],i});
        int n=score.size();
        vector<string>a(n);
        int x=1;
        while(!maxh.empty()){
            int i=maxh.top().second;maxh.pop();
             if(x==1){
                a[i]="Gold Medal";
                x++;
             }
             else if(x==2){
                a[i]="Silver Medal";x++;
             }
             else if(x==3){
                a[i]="Bronze Medal";x++;
             }
             else{
             a[i]=to_string(x);
             x++;
             }
        }
        return a;
    }
};