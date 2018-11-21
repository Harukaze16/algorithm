#include <iostream>

#include "red_black_tree_node.h"
//红黑树节点树结构
//返回该数中的节点数量



int node_nums(red_black_tree_node *cur) {
    if(!cur)
        return 0;
    return cur->node_num;
}

//该子树是否是红的
bool is_red(red_black_tree_node *cur) {
    if(!cur)
        return false;
    return cur->is_red;
}
//该子树左旋
red_black_tree_node* rotate_left(red_black_tree_node *old_root) {
    red_black_tree_node *new_root = old_root->right;
    old_root->right=new_root->left;
    new_root->left=old_root;
    new_root->is_red = old_root->is_red;
    old_root->is_red = true;
    old_root->node_num = node_nums(old_root->left) + node_nums(old_root->right)+1;
    new_root->node_num = node_nums(new_root->left) + node_nums(new_root->right)+1;
    return new_root;
}

//该子树右旋
red_black_tree_node* rotate_right(red_black_tree_node *old_root) {
    red_black_tree_node *new_root = old_root->left;
    old_root->left=new_root->right;
    new_root->right=old_root;
    new_root->is_red = old_root->is_red;
    old_root->is_red = true;
    
    old_root->node_num = node_nums(old_root->left) + node_nums(old_root->right)+1;
    new_root->node_num = node_nums(new_root->left) + node_nums(new_root->right)+1;
    return new_root;
}

//颜色反转
red_black_tree_node* flip_color(red_black_tree_node *root) {
    bool color = is_red(root);
    root->is_red = !color;
    if(root->left)
        root->left->is_red = color;
    if(root->right)
        root->right->is_red = color;
    
    return root;
}

//插入数据
red_black_tree_node* insert(int val,red_black_tree_node* root){
    if(!root) {
        red_black_tree_node *new_node = new red_black_tree_node(val);
        return new_node;
    } else {
        if(val <= root->val) {
            root->left = insert(val,root->left);
            root->node_num++;
        } else if(val>root->val) {
            root->right = insert(val,root->right);
            root->node_num++;
        }
    }
    if(is_red(root->left) && is_red(root->left->left)) 
        root = rotate_right(root);
    if(is_red(root->left) && is_red(root->right))
        root = flip_color(root);
    if(is_red(root->right))
        root = rotate_left(root);
    return root;
}

//删除当前子树的最小节点
red_black_tree_node* delete_min_recur(red_black_tree_node *root) {
    if(!root->left) {
        delete root;
        return NULL;
    }
    if(!is_red(root->left) && !is_red(root->right)) {
        root = make_left_red(root);
    }
    root->left = delete_min_recur(root->left);
    return keep_balance(root);
}

//当前节点左子节点和左孙节点均为黑色，使左子节点或左孙节点为红色
red_black_tree_node* make_left_red(red_black_tree_node* root) {
    root = flip_color(root);
    if(is_red(root->right->left)) {
        root->right = rotate_right(root->right);
        root = rotate_left(root);
        flip_color(root);
    }
    return root;
}

//当前节点右子节点和左孙节点均为黑色，使右子节点或右子节点的左节点为红色
red_black_tree_node* make_right_red(red_black_tree_node* root) {
    root = flip_color(root);
    if(is_red(root->left->left)) {
        root = rotate_right(root);
        flip_color(root);
    }
    return root;
}
// 树保持平衡
red_black_tree_node* keep_balance(red_black_tree_node *root) {
    if(is_red(root->right) && !is_red(root->left))
        root = rotate_left(root);
    if(is_red(root->left) && is_red(root->left->left))
        root = rotate_right(root);
    if(is_red(root->left) && is_red(root->right))
        root = flip_color(root);
    root->node_num = node_nums(root->left)+node_nums(root->right);
    return root;
}


//删除最大节点
red_black_tree_node* delete_max_recur(red_black_tree_node *root) {
    if(is_red(root->left))
        root = rotate_right(root);
    if(!root->right) {
        std::cout<<"cur"<<char(root->val)<<std::endl;
        delete root;
        return NULL;
    }
    if(!is_red(root->right) && !is_red(root->right->left)) {
        root = make_right_red(root);
    }
    root->right = delete_max_recur(root->right);
    return keep_balance(root);
}

void output(red_black_tree_node *root) {
    if(!root)
        return;
    std::cout<<"val: "<<char(root->val)<<";  nodes: "<<root->node_num<<";  is_red: "<<root->is_red <<std::endl;
    output(root->left);
    output(root->right);
}

//删除该节点,assert该节点必定能找得到
red_black_tree_node* delete_key(int key,red_black_tree_node *root) {
    int cur_val = root->val;
    if(key<cur_val) {
        if((!is_red(root->left)) && (!is_red(root->left->left))) {
            root = make_left_red(root);
        }
        root->left = delete_key(key,root->left);
    }
    else {
        if(is_red(root->left))
            root = rotate_right(root);
        cur_val = root->val;
        if(cur_val == key && !root->right) {
            delete root;
            return NULL;
        }
        if(!is_red(root->right) && !is_red(root->right->left)) {
            root = make_right_red(root);
        }
        //找到目标节点
        if(cur_val == key) {
            red_black_tree_node* min = min_node(root->right);
            root->val = min->val;
            root->right = delete_min_recur(root->right);
        }
        else {
            root->right = delete_key(key,root->right);
        }
    }
    return keep_balance(root);
}

// 获取该树的最小节点
red_black_tree_node* min_node(red_black_tree_node* root) {
    if(!root->left)
        return root;
    return min_node(root->left);
}
//获取该树的最大节点
red_black_tree_node* max_node(red_black_tree_node* root) {
    if(!root->right)
        return root;
    return max_node(root->right);
}

//根据key查找节点
red_black_tree_node *seek_key(red_black_tree_node *root,int val) {
    if(!root)
        return NULL;
    if(root->val == val) {
        return root;
    }
    if(root->val < val)
        return seek_key(root->right, val);
    else
        return seek_key(root->left, val);
}
