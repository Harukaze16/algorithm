#include <iostream>
#include <vector>
using namespace std;

void insert_sort(vector<int> &vi) {
    int sz=vi.size();
    for(int i=1;i<sz;i++) {
        int cur=vi[i];
        int j;
        for(j=i-1;j>=0 && vi[j]>cur;j--) {
            vi[j+1]=vi[j];
        }
        vi[j+1]=cur;
    }
}
