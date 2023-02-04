#include <bits/stdc++.h>
using namespace std;

vector<double> medianOfRunningStream(vector<int>& vec, int k){
    int N;
    vector<double> medians(N);
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double>> minHeap;
    maxHeap.push(vec[0]);
    medians[0] = vec[0];
    for(int i=1; i<N; i++){
        maxHeap.push(vec[i]);
        while(maxHeap.size() - minHeap.size() > 1){
            double top = maxHeap.top(); maxHeap.pop();
            minHeap.push(top);
        }
        if(i & 1){
            medians[i] = maxHeap.top();
        } else {
            medians[i] = (maxHeap.top() + minHeap.top())/2;
        }
    }
    return medians;
}

int main(){
    return 0;
}