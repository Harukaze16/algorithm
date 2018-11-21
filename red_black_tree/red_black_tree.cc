#include <iostream>
#include "red_black_tree.h"

void red_black_tree::insert_val(int val) {
    root = insert(val,root);
    root->is_red = false;
}

void red_black_tree::delete_min() {
    if(!root)
        return;
    if(!is_red(root->left) && !is_red(root->right))
        root->is_red = true;
    root = delete_min_recur(root);
    if(root)
        root->is_red = false;
}

void red_black_tree::delete_max() {
    if(!root)
        return;
    if(!is_red(root->left) && !is_red(root->right))
        root->is_red = true;
    root = delete_max_recur(root);
    if(root)
        root->is_red = false;
}

void red_black_tree::delete_val(int val) {
    if(!root)
        return;
    if(!get_num(val))
        return;  // 无此节点，返回之
    if(!is_red(root->left) && !is_red(root->right))
        root->is_red = true;
    root = delete_key(val, root);
    if(root)
        root->is_red = false;
}

//查询节点，根据key
bool red_black_tree::get_num(int val) {
    red_black_tree_node *cur =  seek_key(root, val);
    if(!cur)
        return false;
    return true;
}
