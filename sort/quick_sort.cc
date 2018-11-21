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
    int pivot = vi[beg],i=beg+1,j=end;
    while(i<j) {
        while(i<j && vi[i]<= pivot)
            i++;
        while(i<j && vi[j]>pivot)
            j--;
        if(i>=j)
            break;
        swap(vi[i++],vi[j--]);
    }
    int target;
   // if(i==j)
        target=(vi[j]>pivot)?j-1:j;
   // else
  //      target=j;
    swap(vi[beg],vi[target]);

    quick_sort(vi,beg,target-1);
    quick_sort(vi,target+1,end);
}
