#include <iostream>
#include <vector>

using namespace std;


void choose_sort(vector<int> &vi) {
    int n = vi.size();
    for(int i=0;i<n;i++){
        int min_index=i;
        for(int j=i;j<n;j++){
            if(vi[j]<vi[min_index])
                min_index=j;
        }
        swap(vi[i],vi[min_index]);
    }
}
