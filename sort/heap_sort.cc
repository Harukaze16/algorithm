#include <vector>
#include <iostream>

using std::vector;
using std::swap;
using std::cout;
using std::endl;
//最大堆

//该处元素下沉以维护堆性质
void heap_max_heapify(vector<int> &vi,int cur_index,int sz) {
    while(cur_index*2+1<sz){
        int max_index=cur_index*2+2;
        if((cur_index*2+2>= sz) ||
            (vi[cur_index*2+1]>vi[cur_index*2+2])) {
                max_index=cur_index*2+1;
            }
        if(vi[cur_index]>=vi[max_index])
            return;
        swap(vi[cur_index],vi[max_index]);
        cur_index=max_index;
    }
}
//建堆
void build_max_heap(vector<int> &vi,int sz) {
    for(int i=sz/2;i>=0;i--) {
        heap_max_heapify(vi,i,sz);
    }
}
//堆排序
void heap_sort(vector<int> &vi) {
    int sz=vi.size();
    build_max_heap(vi,sz);
    for(int i=sz-1;i>0;i--){
        swap(vi[i],vi[0]);
        heap_max_heapify(vi,0,i);
    }
}

