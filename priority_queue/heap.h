#include <vector>

using std::vector;
void heap_max_heapify(vector<int> &vi,int cur_index,int sz); //下沉
void build_max_heap(vector<int> &vi,int sz); //建堆
void float_max_heap(vector<int> &vi,int cur_index); //上浮