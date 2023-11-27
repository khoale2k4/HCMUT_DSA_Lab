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

int binarySearch(int arr[], int left, int right, int x)
{
    if(left > right) return -1;
    int mid = (left + right) / 2;
    cout << "We traverse on index: " << mid << endl;
    if(arr[mid] == x){
        return mid;
    }
    else if(arr[mid] > x){
        return binarySearch(arr, left, mid - 1, x);
    }
    else {
        return binarySearch(arr, mid + 1, right, x);
    }
}

int main(){
    
}