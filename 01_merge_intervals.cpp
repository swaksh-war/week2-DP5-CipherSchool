#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals){
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    vector<int> temp = intervals[0];

    for(auto it: intervals)
    {
        if(temp[1] >= it[0]){
            temp[1] = max(temp[1], it[1]);
        }
        else{
            ans.push_back(temp);
            temp = it;
        }
    }
    ans.push_back(temp);
    return ans;
}

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(intervals);
    for(auto it: ans){
        for(auto j: it){
            cout << j << " ";
        }
        cout << "   ";
    }
    return 0;
}