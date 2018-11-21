#include <iostream>
//红黑树节点树结构
struct red_black_tree_node {
    int val;
    red_black_tree_node *left;
    red_black_tree_node *right;
    bool is_red;
    int node_num;
    red_black_tree_node(int value):
        val(value),node_num(1),left(NULL),right(NULL),is_red(true){};
};
bool is_red(red_black_tree_node *cur) ;  //该节点是否是红色
red_black_tree_node* rotate_left(red_black_tree_node *);     //  子树左旋，right_child must be red
red_black_tree_node* rotate_right(red_black_tree_node *);    //  子树右旋,left_child must be red
red_black_tree_node* flip_color(red_black_tree_node *);      //  反转此节点即子节点颜色 ,two child must be red
red_black_tree_node* insert(int val,red_black_tree_node* root);  //向树(含子树)插入数据,if existed ,false
red_black_tree_node* delete_key(int key,red_black_tree_node *root);  //删除数据
void output(red_black_tree_node *root); //输出节点

red_black_tree_node* delete_min_recur(red_black_tree_node *root); //删除当前子树的最小节点
red_black_tree_node* delete_max_recur(red_black_tree_node *root); //删除当前子树的最大节点


red_black_tree_node* make_left_red(red_black_tree_node* root);   //使得当前左子节点转为红色
red_black_tree_node* keep_balance(red_black_tree_node* root);    //使当前子树保持平衡

red_black_tree_node *min_node(red_black_tree_node* root);
red_black_tree_node *max_node(red_black_tree_node* root);

//根据key查找节点
red_black_tree_node *seek_key(red_black_tree_node *root,int val);
