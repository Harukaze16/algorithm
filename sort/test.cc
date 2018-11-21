#include "header.h"

#include <vector>
#include <iostream>

using namespace std;

int main() {
   // int arr[]={4,3,4,7,4,4,4,10,32,43,42};
    int arr2[]={1,2,3,4,5,6};
    int arr[]={9,2,3,14,51,9,29,24,1,30,22,13,41};
    int arr3[] = {3,24,0};
    vector<int> test(arr3,arr3+3);
    shell_sort(test);
    for(int i=0;i<3;i++)
        cout<<test[i]<<' ';
    cout<<endl;
    return 0;
}
