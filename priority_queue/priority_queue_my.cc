#include "priority_queue_my.h"
#include "heap.h"
#include <iostream>

using std::cout;
using std::endl;
priority_queue_my::priority_queue_my(const std::vector<int> &cp_vi):vi(cp_vi){
    build_max_heap(vi,vi.size());
}
void priority_queue_my::insert(int x) {
   vi.push_back(x);
   float_max_heap(vi,vi.size()-1);
}
int priority_queue_my::maximum() {
    if(vi.size()>0)
        return vi[0];
    return -1;
}
int priority_queue_my::extract_max() {
    if(vi.size()<=0)
        return -1;
    int top=vi[0];
    vi[0]=vi[vi.size()-1];
    vi.pop_back();
    heap_max_heapify(vi,0,vi.size());
    return top;
}
void priority_queue_my::increase_key(int index,int inc) {
    if(index<0 || index>=vi.size())
        return;
    vi[index]+=inc;
    float_max_heap(vi,index);
}
void priority_queue_my::out_put_all(){
    cout<<"Now priority_queue_my:" << endl;
    for(auto i:vi) 
        cout<<i<<' ';
    cout<<endl;
}