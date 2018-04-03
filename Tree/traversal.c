#include "tree.h"

/* 先序遍历二叉树 
* 根-左-右
* 采用方法:压栈法
* @root:根节点地址
* @count:节点个数
* */
void pre_order(BTree *root,int count)
{
    BTree *stack[MAXSIZE] = {NULL};  //创建栈
    int i = 0; //栈顶元素下标 0位置未使用
    BTree *cur = root; 

    while(NULL != cur || i > 0)
    {
        if(NULL != cur)
        {
            printf("%c  ",cur->value);//打印根节点值
            stack[++i] = cur; //将根节点压栈
            cur = cur->lchild;
        }
        else
        {
            cur = stack[i--];  //cur指向栈顶元素，栈顶元素出栈
            cur = cur->rchild;
        }
    }
    putchar(10);
}
/* 中序遍历二叉树 
* 左-根-右
* 采用方法:压栈法
* @root:根节点地址
* @count:节点个数
* */
void in_order(BTree *root,int count)
{
    BTree *stack[MAXSIZE];
    int i = 0;
    BTree *cur = root;

    while(NULL != cur || i > 0)
    {
        if(NULL != cur)
        {
            stack[++i] = cur;
            cur = cur->lchild;
        }
        else 
        {
            cur = stack[i--];
            printf("%c  ",cur->value);
            cur = cur->rchild;
        }
    }
    putchar(10);
}


/* 后序遍历二叉树 
* 左-右-根
* 采用方法:压栈法
* @root:根节点地址
* @count:节点个数
* */
void post_order(BTree *root,int count)
{
    BTree *stack[MAXSIZE];
    int i = 0;
    BTree *cur = root;
    int mark[MAXSIZE];
    /* mark数组说明: 
     * -1代表该节点左右孩子都没有访问
     * 0代表右孩子没有访问
     * 1代表左右孩子都访问过*/
    for(int k = 0;k < MAXSIZE;k++)
        mark[k] = -1;
    
    while(NULL != cur || i > 0)
    {
        if(NULL != cur)
        {
            stack[++i] = cur;
            cur = cur->lchild;
            mark[i] = 0;       //该节点标记为左孩子已访问
        }
        else
        {
            cur = stack[i--]; //cur取栈顶元素,栈顶元素出栈
            if(mark[i+1] == 0)   //如果刚出栈的元素右孩子还未访问
            {
                stack[++i] = cur; //继续压栈
                cur = cur->rchild;
                mark[i] = 1;
            }
            else if(mark[i+1] == 1) //刚出栈的元素左右孩子都访问
            {
                printf("%c  ",cur->value);
                cur = NULL;
            }
        }
    }
    putchar(10);
}

/* 层次遍历二叉树 
* 从上到下,从左到右
* 用到方法：队列的先进先出
* @root:根节点地址
* @count:节点个数
* */
void Transleve(BTree *root,int count)
{
    
    
}
