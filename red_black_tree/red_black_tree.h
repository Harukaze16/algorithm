#include <iostream>
#include "red_black_tree_node.h"

class red_black_tree {
private:
    red_black_tree_node *root;
public:
    red_black_tree():root(NULL){};
    void insert_val(int val);
    void delete_min();
    void delete_max();
    void delete_val(int val);
    void out_put_all(){
        output(root);
    }
    //查询相关
    bool get_num(int val);
};
