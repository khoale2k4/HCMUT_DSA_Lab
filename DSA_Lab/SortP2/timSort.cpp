#ifndef SORTING_H
#define SORTING_H
#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting {
public:
    static void printArray(T* start, T* end)
    {
        int  size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << " ";
        cout << start[size - 1];
        cout << endl;
    }

    static void merge(T* start, T* middle, T* end) {
        int lenl = middle - start + 1;
        int lenr = end - middle;
        T* la = new T[lenl];
        T* ra = new T[lenr];
        for (int i = 0; i < lenl; i++) {
            la[i] = start[i];
        }
        for (int i = 0; i < lenr; i++) {
            ra[i] = middle[i + 1];
        }
        int i = 0, j = 0, k = 0;
        while (i < lenl && j < lenr) {
            if (la[i] < ra[j]) {
                start[k++] = la[i++];
            }
            else {
                start[k++] = ra[j++];
            }
        }
        while (i < lenl) {
            start[k++] = la[i++];
        }
        while (j < lenr) {
            start[k++] = ra[j++];
        }
    }

    static void InsertionSort(T* start, T* end) {
        int len = end - start + 1;
        for (int i = 1; i < len; i++) {
            T key = start[i];
            int j = i - 1;

            while (j >= 0 && start[j] > key) {
                start[j + 1] = start[j];
                j--;
            }
            start[j + 1] = key;
        }
    }

    static void TimSort(T* start, T* end, int min_size) {
        int len = end - start;
        for (int i = 0; i < len; i += min_size) {
            int sub_len = min(min_size, len - i);
            InsertionSort(start + i, start + i + sub_len - 1);
        }
        cout << "Insertion Sort: ";
        printArray(start, end);
        int c = 1;
        for (int i = min_size; i < len; i *= 2) {
            for (int left = 0; left < len; left += 2 * i) {
                int mid = left + i - 1;
                int right = min(left + 2 * i - 1, len - 1);
                if (mid < right) {
                    merge(start + left, start + mid, start + right);
                }
                cout << "Merge " << c++ << ": ";
                printArray(start, end);
            }
        }
    }
};
#endif /* SORTING_H */
int main()
{
}