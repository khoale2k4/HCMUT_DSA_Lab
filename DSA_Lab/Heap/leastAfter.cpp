#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int leastAfter(std::vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());

    while (k--) {
        int smallest = minHeap.top();
        minHeap.pop();
        minHeap.push(smallest * 2);
    }

    return minHeap.top();
}

int main(){

}