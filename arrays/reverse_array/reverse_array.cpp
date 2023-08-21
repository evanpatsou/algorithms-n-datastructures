#include <iostream>

using namespace std;

int main()
{
    char array[]= "reverse"; // esrever
    int size = sizeof(array) / sizeof(char);
    
    for(int i = 0; i < int(size/2); i++) {
        int pos_i = i;
        int pos_j = size-i-2;
        
        char temp = array[pos_i];
        array[pos_i] = array[pos_j];
        array[pos_j] = temp;
    }
    
    cout << array;

    return 0;
}
