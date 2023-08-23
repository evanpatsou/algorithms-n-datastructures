#include <iostream>

using namespace std;

int main() {
    // Step 1: initialize the constants
    int array[] = {1,-3,2,-4,5,-6};
    int size = sizeof(array)/sizeof(int);
    
    // Step 2: Perform the re-arrange
    for(int i = 0; i < size; i++){
        int number = array[i];
        if (number < 0) {
            int j = i;
            while(j > 0 && array[j-1] >= 0) {
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
                j--;
            }
        }
    }
    
    // Step3: Print the array
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }

    return 0;
}