#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* lchild;
    int data;
    struct node* rchild;
}*root=NULL;
struct node *create(int key)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=key;
    p->lchild=NULL;
    p->rchild=NULL;
    root=p;
    return p;
}

void insert(int key)
{
    struct node *r=NULL;
    struct node *p;
    struct node *t;
    t=root;
    if(root==NULL)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->data=key;
        p->lchild=NULL;
        p->rchild=NULL;
        root=p;
        return ;
    }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
        {
            t=t->lchild;
        }
        else if(key>t->data)
        {
            t=t->rchild;
        }
        else
        {
            return ;
        }
    }
    p=(struct node *)malloc(sizeof(struct node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data)
    {
        r->lchild=p;
    }
    else
    {
        r->rchild=p;
    }
}

struct node* search(int key)
{
    struct node *t=root;
    while(t!=NULL)
    {
        if(key==t->data)
        {
            return t;
        }
        else if(key<t->data)
        {
            t=t->lchild;
        }
        else
        {
            t=t->rchild;
        }
    }
    return NULL;
}
int count(struct node *p)
{
    int x , y;
    if(p!=NULL)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        return x+y+1;
    }
    return 0;
}

int sum(struct node *p)
{
    int x , y;
    if(p!=NULL)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        return x+y+p->data;
    } 
    return 0;
}

int count_degree1node(struct node *p)
{
    int x , y;
    if(p!=NULL)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        if((p->lchild!=NULL && p->rchild==NULL) || (p->rchild!=NULL && p->lchild==NULL))
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}

int sumdegree1node(struct node *p)
{
    int x , y;
    if(p!=NULL)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        if((p->lchild!=NULL && p->rchild==NULL) || (p->rchild!=NULL && p->lchild==NULL))
        {
            return x+y+p->data;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}


int count_degree2(struct node *p)
{
    int x , y;
    if(p!=NULL)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        if(p->lchild!=NULL && p->rchild!=NULL)
        return x+y+1;
        else
        return x+y;
    }
    return 0;
}

int sum_degree2(struct node *p)
{
    int x , y;
    if(p!=NULL)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        if(p->lchild!=NULL && p->rchild!=NULL)
        return x+y+p->data;
        else
        return x+y;
    }
    return 0;
}

int count_leafnode(struct node *p)
{
    int x , y;
    if(p!=NULL)
    {
        x=count_leafnode(p->lchild);
        y=count_leafnode(p->rchild);
        if(p->rchild==NULL && p->lchild==NULL)
        return x+y+1;
        else
        return x+y;
    }
    return 0;
}

int sum_leafnode(struct node *p)
{
    int x , y;
    if(p!=NULL)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL)
        return x+y+p->data;
        else
        return x+y;
    }
    return 0;
}

int count_leftmostnode(struct node*p)
{
    int x , y;
    if(p!=NULL)
    {
        x=count_leftmostnode(p->lchild);
        y=count_leftmostnode(p->rchild);
        if(p->lchild!=NULL && p->rchild==NULL)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}

int sum_leftnode(struct node*p)
{
    int x , y;
    if(p!=NULL)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        if(p->lchild!=NULL)
        {
            return x+y+p->data;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}

int count_rightnode(struct node*p)
{
    int x , y;
    if(p!=NULL)
    {
        x=count_rightnode(p->lchild);
        y=count_rightnode(p->rchild);
        if(p->rchild!=NULL && p->lchild==NULL )
        {
            return y+1; // tree ki right side ki sari right node count karega
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}



int count_rightchild(struct node*p)
{
    int x , y;
    if(p!=NULL)
    {
        x=count_rightchild(p->lchild);
        y=count_rightchild(p->rchild);
        if(p->rchild!=NULL)
        {
            return x+y+1; 
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}

int sum_rightnode(struct node*p)
{
    int x , y;
    if(p!=NULL)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        if(p->rchild!=NULL)
        {
            return x+y+p->data;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}

int max(struct node*p)
{
    while(p->rchild)
    {
        p=p->rchild;
    }
    return p->data;
}

int min(struct node*p)
{
    while(p->lchild)
    {
        p=p->lchild;
    }
    return p->data;
}

int height(struct node *p)
{
    int x , y;
    if(p!=NULL)
    {
        x=height(p->lchild);
        y=height(p->rchild);
        if(x>y)
        {
            return x+1;
        }
        else
        {
            return y+1;
        }
    }
}

int count_d1ord2(struct node *p)
{
    int x , y;
    if(p!=NULL)
    {
        x=height(p->lchild);
        y=height(p->rchild);
        if(p->rchild!=NULL || p->lchild!=NULL)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}

int sum_d1ord2(struct node *p)
{
    int x , y;
    if(p!=NULL)
    {
        x=height(p->lchild);
        y=height(p->rchild);
        if(p->rchild!=NULL || p->lchild!=NULL)
        {
            return x+y+p->data;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}
void inorder(struct node*p)
{
    if(p!=NULL)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void postorder(struct node*p)
{
    if(p!=NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

 struct node *inpre(struct node *p)
 {
    while(p && p->rchild!=NULL)
    {
        p=p->rchild;
    }
    return p;
 }
struct node *insucc(struct node *p)
 {
    while(p && p->lchild!=NULL)
    {
        p=p->lchild;
    }
    return p;
 }


 int  delete(struct node*p , int key)
 {
    struct node *q;
    if(p==NULL)
    {
        return NULL;
    }
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
        {
            root==NULL;
        }
        free(p);
        return NULL;
    }

    if(key<p->data)
    {
        p->lchild=delete(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild=delete(p->rchild,key);
    }
    else
    {
        if(height(p->lchild)>height(p->rchild))
        {
            q=inpre(p->lchild);
            p->data =  q->data;
            p->lchild=delete(p->lchild,q->data);
        }
        else
        {
            q=insucc(p->rchild);
            p->data =  q->data;
            p->rchild=delete(p->rchild,q->data);            
        }
    }
    return p;
 }
int main()
{
    insert(30);
    insert(15);
    insert(10);
    insert(50);
    insert(20);
    insert(40);
    insert(60);
    insert(100);
    printf("\n");
    delete(root , 30);
    inorder(root);
    printf("\n");

}


