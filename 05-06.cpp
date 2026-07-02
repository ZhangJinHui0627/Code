#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

// 二叉树节点结构定义
typedef struct node
{
    char data;
    struct node *lchild, *rchild;
    int size;
    int flag;
} node;
typedef node *bitree;

// 顺序循环队列结构定义
typedef struct
{
    bitree a[10];
    int front, rear;
} Queue;

// 前序遍历构建二叉树，' ' 字符表示空节点
void creat_tree(bitree *t)
{
    char ch = getchar();

    // 过滤掉输入的换行符
    while (ch == '\n')
        ch = getchar();

    if (ch == ' ')   // 若为空格，则构建空子树
    {
        *t = NULL;
    }
    else
    {
        *t = (bitree)malloc(sizeof(node));
        if (!*t) exit(0);

        (*t)->data = ch;

        creat_tree(&(*t)->lchild);
        creat_tree(&(*t)->rchild);
    }
}

// 打印二叉树树结构信息
void display(bitree t)
{
    if (t == NULL) return;

    printf("%c  ", t->data);

    if (t->lchild)
        printf("left: %c\n", t->lchild->data);
    else
        printf("left: NULL\n");

    if (t->rchild)
        printf("    right: %c\n", t->rchild->data);
    else
        printf("    right: NULL\n");

    display(t->lchild);
    display(t->rchild);
}

// 先序非递归遍历算法（辅助栈实现）
void preorder(bitree t)
{
    bitree stack[100];
    int top = -1;
    bitree p = t;

    while (p || top != -1)
    {
        while (p)
        {
            printf("%c ", p->data);
            stack[++top] = p;
            p = p->lchild;
        }

        if (top != -1)
        {
            p = stack[top--];
            p = p->rchild;
        }
    }
}

// 释放二叉树内存空间
void free_tree(bitree t)
{
    if (!t) return;
    free_tree(t->lchild);
    free_tree(t->rchild);
    free(t);
}

// 层次遍历算法（辅助队列实现）
void level_order(bitree t)
{
    // 队列结构初始化
    Queue q;
    q.front = 0;
    q.rear = 0;

    if (!t) return;

    bitree queue_arr[10];

    int front = 0, rear = 0;
    queue_arr[rear++] = t;
    
    while (front != rear)
    {
        bitree p = queue_arr[front++];
        printf("%c ", p->data);

        if (p->lchild)
        {
            printf("lchild: %c\n", p->lchild->data);
            queue_arr[rear++] = p->lchild;
        }
        if (p->rchild)
        {
            printf("rchild: %c\n", p->rchild->data);
            queue_arr[rear++] = p->rchild;
        }
    }
}

// 后序非递归遍历算法（辅助栈实现）
void postorder(bitree t)
{
    if (t == NULL) return;

    stack<bitree> s;
    bitree p = t;
    bitree last = NULL;

    while (p || !s.empty())
    {
        while (p)
        {
            s.push(p);
            p = p->lchild;
        }

        bitree curr = s.top();
        if (curr->rchild && curr->rchild != last)
        {
            p = curr->rchild;
        }
        else
        {
            printf("%c ", curr->data);
            s.pop();
            last = curr;
            p = NULL; // 元素出栈后，控制回溯
        }
    }
}

int main()
{
    bitree T = NULL;

    printf("请输入二叉树的前序序列（空格表示空树）：\n");

    creat_tree(&T);

    printf("\n二叉树结构：\n");
    display(T);

    printf("\n先序非递归遍历：\n");
    preorder(T);

    printf("\n层次顺序遍历：\n");
    level_order(T);

    printf("\n后序非递归遍历：\n");
    postorder(T);

    free_tree(T);
    return 0;
}
