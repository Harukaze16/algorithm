#include <vector>
#include <iostream>

using std::vector;
using std::swap;
using std::cout;
using std::endl;

void quick_sort(vector<int> &vi,int beg,int end); 
void quick_sort(vector<int> &vi) {
    quick_sort(vi,0,vi.size()-1);
}

void quick_sort(vector<int> &vi,int beg,int end) {
    if(end<=beg)
        return;
    int pivot = vi[beg],i=beg;
    int first_greater=end+1;
    int last_less = beg-1;
    while(i<first_greater) {
        if(vi[i]<pivot) {
            swap(vi[i++],vi[++last_less]);
        }
        else if(vi[i]==pivot)
            i++;
        else {
            swap(vi[i],vi[--first_greater]);
        }
    }

    quick_sort(vi,beg,last_less);
    quick_sort(vi,first_greater,end);
}
