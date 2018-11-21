#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

void quick_sort(vector<int> &vi,int beg,int end); 
void quick_sort(vector<int> &vi) {
    quick_sort(vi,0,vi.size()-1);
}

void quick_sort(vector<int> &vi,int beg,int end) {
    if(end<=beg)
        return;
    int pivot = vi[beg],i=beg,j=end;
    while(i<j) {
        while(vi[j]>pivot && j>i)
            j--;
        vi[i]=vi[j];
        while(vi[i]<=pivot && i<j)
            i++;
        vi[j]=vi[i];
    }

    vi[i]=pivot;

    quick_sort(vi,beg,i-1);
    quick_sort(vi,i+1,end);
}
