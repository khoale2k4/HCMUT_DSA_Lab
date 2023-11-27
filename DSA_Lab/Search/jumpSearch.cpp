#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <set>

using namespace std;

int jumpSearch(int arr[], int x, int n) {
    // TODO: print the traversed indexes and return the index of value x in array if x is found, otherwise, return -1.
    int m = sqrt(n);
    int i = 0;
    while(arr[i] < x && i < n){
        cout << i << " ";
        i += m;
    }
    
    if(i < n) cout << i << " ";
    if(i < n && arr[i] == x) return i;
    
    int k = i - m + 1;
    for(; k < i && k < n; k++){
        if(arr[k] == x) {
            cout << k;
            return k;
        }
        else
            cout << k << " ";
    }
    if(k >= n) cout << k;
    return -1;
}

int main(){
    
}