#include <iostream>

using namespace std;

int foldShift(long long key, int addressSize)
{
    string num = to_string(key);
    int sum = 0;
    int len = num.length();
    //cout << key << endl;
    for(int i = 0; i < len; i += addressSize){
        int s = 0;
        for(int k = i; k < len && k - i < addressSize; k++){
            s = s * 10 + (num[k] - '0');
            //cout << s << endl;
        }
        sum += s;
    }
    int size = 1;
    while(addressSize--) size *= 10;
    return sum % size;
}

int rotation(long long key, int addressSize)
{
    string num = to_string(key);
    int len = num.length();
    char tem = num[len - 1];
    for(int i = len - 1; i > 0; i--){
        num[i] = num[i - 1];
    }
    num[0] = tem;
    //cout << num << endl;
    return foldShift(stoll(num), addressSize);
}

int main(){
    
}