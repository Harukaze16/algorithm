#include "heap.h"
using std::swap;
//该处元素下沉
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

//上浮
void float_max_heap(vector<int> &vi,int cur_index) {
    while(cur_index>0 && vi[(cur_index-1)/2]<vi[cur_index]) {
        swap(vi[cur_index],vi[(cur_index-1)/2]);
        cur_index=(cur_index-1)/2;
    }
}