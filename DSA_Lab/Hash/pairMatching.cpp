#include <iostream>

using namespace std;

int pairMatching(vector<int>& nums, int target) {
    unordered_map<int, int> freq; 
    int pairs = 0;

    for (int num : nums) {
        freq[num]++;
    }

    for (int num : nums) {
        if (freq[num] > 0 && freq[target - num] > 0) {
            if (num == target - num && freq[num] < 2) {
                continue;
            }
            pairs++;
            freq[num]--;
            freq[target - num]--;
        }
    }

    return pairs;
}

int main(){
    
}