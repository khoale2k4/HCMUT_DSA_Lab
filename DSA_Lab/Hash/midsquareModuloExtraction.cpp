#include <iostream>

using namespace std;

long int midSquare(long int seed)
{
    long int rs = seed * seed;
    rs /= 100;
    return rs % 10000;
}
long int moduloDivision(long int seed, long int mod)
{
    return seed % mod;
}
long int digitExtraction(long int seed,int* extractDigits,int size)
{
    string num = to_string(seed);
    int len = 0;
    while(seed){
        len++;
        seed /= 10;
    }
    string rs = "";
    for(int i = 0; i < size; i++){
        rs += num[extractDigits[i]];
    }
    return stoi(rs);
}

int main(){
    
}