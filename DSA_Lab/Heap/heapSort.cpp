#define SEPARATOR "#<ab@17943918#@>#"
#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <queue>
using namespace std;
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    
    
    //Helping functions go here
    void reheapDown(int maxHeap[], int numberOfElements, int index) {
        int largerChild;
        int temp = maxHeap[index];

        while (index < numberOfElements / 2) {
            int leftChild = 2 * index + 1;
            int rightChild = leftChild + 1;

            if (rightChild < numberOfElements && maxHeap[rightChild] > maxHeap[leftChild]) {
                largerChild = rightChild;
            } else {
                largerChild = leftChild;
            }

            if (temp >= maxHeap[largerChild]) {
                break;
            }

            maxHeap[index] = maxHeap[largerChild];
            index = largerChild;
        }

        maxHeap[index] = temp;
    }

    static void heapSort(T* start, T* end){
        //TODO
        Sorting<int> obj;
        int size = end - start;

        for (int i = size / 2 - 1; i >= 0; i--) {
            obj.reheapDown(start, size, i);
        }

        for (int i = size - 1; i > 0; i--) {
            swap(start[0], start[i]);
            obj.reheapDown(start, i, 0);
        }
        
        Sorting<T>::printArray(start, end);
    }
    
};
#endif /* SORTING_H */


int main(){

}