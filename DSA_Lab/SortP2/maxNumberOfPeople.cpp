#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sort(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}
int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) {
    sort(rooms);
    sort(people);
    int i = 0, j = 0;
    int count = 0;
    while (i < rooms.size() && j < people.size()) {
        if (abs(rooms[i] - people[j]) <= k) {
            count++;
            i++;
            j++;
        }
        else if (rooms[i] < people[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    return count;
}

int main()
{
}
