#include <bits/stdc++.h>
using namespace std;

vector<int> topKfrequent(vector<int>& nums, int k){
    sort(nums.begin(), nums.end());
    map<int, int> m1;
    for(int i=0; i < nums.size(); i++){
        m1[nums[i]]++;
    }
    vector<int> counts = {};
    for(auto it = m1.begin(); it != m1.end(); it++){
        counts.push_back(it->second);
    }
    sort(counts.begin(), counts.end());
    reverse(counts.begin(),counts.end());
    vector<int> ans = {};
    int a = 0;
    while(ans.size() != k){
        for(auto it = m1.begin(); it != m1.end(); it++){
            if(it->second == counts[a] && a < k){
                ans.push_back(it->first);
                a++;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> elements = {1,1,1,2,2,3};
    vector<int> ans = topKfrequent(elements, 2);
    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}