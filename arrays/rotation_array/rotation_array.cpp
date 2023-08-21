#include <iostream>

using namespace std;

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(int);
    
        
    for (int i = 0; i < size; i ++) {
        printf("%d ", array[i]);   
    }
    
    // rotate the last one
    for(int i = size-1; i > 0; i--){
        int temp = array[i];
        array[i] = array[(i-1)];
        array[i-1] = temp;
    }
    
    cout << endl;
    
    for (int i = 0; i < size; i ++) {
        printf("%d ", array[i]);   
    }

    return 0;
}