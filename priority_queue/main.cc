#include <iostream>
#include <vector>
#include "priority_queue_my.h"

using std::cout;
using std::endl;

using std::vector;


int main() {
    int arr[16]={2,34,6,32,25,6,2,63,1,5,24,32,14,25,9,1};
    vector<int> vi(arr,arr+16);

    priority_queue_my myprio(vi);
    myprio.out_put_all();

    myprio.insert(35);
    myprio.out_put_all();
    
    cout<<"max element: ";
    cout<< myprio.maximum();
    cout<<endl;

    myprio.extract_max();
    myprio.out_put_all();

    myprio.increase_key(9,23);
    myprio.out_put_all();

    return 0;
}
