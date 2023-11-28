#include <iostream>

using namespace std;

void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    if(index > (numberOfElements)/2 || index<0)   return;
    int i= index;
    int largest_e=0;
        if((2*i + 1) < numberOfElements){
            int left_e= 2*i +1;        
            if((2*i +2) < numberOfElements){
                int right_e= 2*i +2;
                if(maxHeap[left_e] > maxHeap[right_e])    largest_e= left_e;
                else    largest_e= right_e;
            }
            else    largest_e= left_e;
        }
        else    return;
        if(maxHeap[i] < maxHeap[largest_e]){
            swap(maxHeap[i], maxHeap[largest_e]);
            reheapDown(maxHeap, numberOfElements, largest_e);
        }
    return;
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    if(index <= 0 || index >= numberOfElements) return;
    int parent = (index - 1) / 2;
    if(maxHeap[index] > maxHeap[parent]){
        swap(maxHeap[index], maxHeap[parent]);
        reheapUp(maxHeap, numberOfElements, parent);
    }
    return;
}

int main(){

}