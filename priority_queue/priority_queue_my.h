#include <vector>

class priority_queue_my{
    private:
        std::vector<int> vi;
    public:
    	priority_queue_my(){};
    	priority_queue_my(const std::vector<int> &cp_vi);
        void insert(int x); //插入值为x的元素
        int maximum(); //返回最大元素
        int extract_max();  //返回最大元素，并删除该元素
        void increase_key(int index,int inc);     //将下标为index的元素增长inc
        void out_put_all();
};