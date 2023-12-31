#ifndef SORTING_H
#define SORTING_H
#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting {
private:
    static T* Partition(T* start, T* end)
    {
        T p = start[0];    // pivot
        int i = 0;
        int j = end - start;
        do
        {
            do {
                i++;
            } while (start[i] <= p);
            do {
                j--;
            } while (start[j] > p);
            swap(start[i], start[j]);
        } while (i < j);
        swap(start[i], start[j]);
        swap(start[0], start[j]);
        return start + j;
    }
public:
    static void QuickSort(T* start, T* end)
    {
        if (start < end)
        {
            T* i = Partition(start, end);
            cout << i - start << " ";
            QuickSort(start, i);
            QuickSort(i + 1, end);
        }
    }
};
#endif /* SORTING_H */



int main()
{
}