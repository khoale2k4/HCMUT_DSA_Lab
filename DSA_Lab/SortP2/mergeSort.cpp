#ifndef SORTING_H
#define SORTING_H
#include <iostream>
using namespace std;
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T* start, T* end)
    {
        long size = end - start + 1;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void merge(T* left, T* middle, T* right) {
        /*TODO*/
        int lenl = middle - left + 1;
        int lenr = right - middle;
        T* leftar = new T[lenl];
        T* rightar = new T[lenr];
        for (int i = 0; i < lenl; i++) {
            leftar[i] = left[i];
        }
        for (int i = 0; i < lenr; i++) {
            rightar[i] = middle[i + 1];
        }
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < lenl && j < lenr) {
            if (leftar[i] < rightar[j]) {
                left[k++] = leftar[i++];
            }
            else {
                left[k++] = middle[1 + j++];
            }
        }
        while (i < lenl) {
            left[k++] = leftar[i++];
        }
        while (j < lenr) {
            left[k++] = rightar[j++];
        }
        Sorting::printArray(left, right);
    }
    static void mergeSort(T* start, T* end) {
        /*TODO*/
        if (start >= end) return;
        T* mid = start + (end - start) / 2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        merge(start, mid, end);
    }
};
#endif /* SORTING_H */
int main()
{
    std::cout << "Hello World!\n";
}