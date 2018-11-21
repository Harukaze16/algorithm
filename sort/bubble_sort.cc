#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int> &vi) {
    int sz=vi.size();
    bool change=true;
    while(change) {
        change=false;
        for(int i=0;i<sz-1;i++) {
            if(vi[i]>vi[i+1]) {
                swap(vi[i],vi[i+1]);
                change=true;
            }
        }
    }
}
