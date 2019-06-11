#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    int value;
    struct node *next;
}node;
typedef struct list
{
 struct node *head;
 struct node *tail;
}list;

 void init(list* l)
{
    l->head = NULL;
    l->tail = NULL;
}

void clear (list *l)
{
  node *ptr = l->head;
  node* tmp;
  while(ptr)
  {
      tmp = ptr;
    free(tmp);  
    ptr = ptr->next;
  }
     free(ptr);
     l->head = NULL;
    l->tail = NULL;
}

int push_back(list *l,int value)
{
 if(l->head==NULL && l->tail==NULL)
 {
      node* tmp = malloc(sizeof(node));
      l->head = tmp;
      l->tail = tmp;
      tmp->value = value;
      tmp->next = NULL;
 }else
 {
     node* tmp = malloc(sizeof(node));
     node* ptr = l->tail;
     tmp->value = value;
     ptr->next = tmp;
     l->tail = tmp;
 }
 return 0;
}
int push_front(list *l,int value)
{
    if(l->head==NULL && l->tail==NULL)
    {
      node* tmp = malloc(sizeof(node));
      l->head = tmp;
      l->tail = tmp;
      tmp->value = value;
      tmp->next = NULL;
    }
    else
    {
      node* tmp = malloc(sizeof(node));
      tmp->value = value;
      tmp->next = l->head;
      l->head = tmp;
      node* ptr = l->head;

    do
      {
       ptr = ptr->next;
       l->tail = ptr;
      }
    while(ptr->next!=NULL);
      return 0;
    }
}
int insertAfter(node *n,int value)
{ 
    node* tmp = malloc(sizeof(node)); 
    tmp->value = value;
    tmp->next = n->next;
    n->next = tmp;
    return 0;   
}
void print(list *l)
{
     node* ptrhead = l->head;
   for(;ptrhead!=NULL;ptrhead = ptrhead->next)
   {
    if(ptrhead->next!=NULL)printf("%d ",ptrhead->value);
    else  printf("%d",ptrhead->value);
   }
    printf("\n");
}

int isEmpty(list *l)
{
        if(l->head==NULL && l->tail==NULL) return 0;
        else return 1;
}

node* find(list *l,int value)
{
    node* ptr = l->head;
    {
        if(ptr->value == value)
        {
            return ptr; 
        }  
    }
    return NULL;
}
int findval(list *l,int value)
{
    node* ptr = l->head;
    for(;ptr!=NULL;ptr = ptr->next)
    {
        if(ptr->value == value)
        {
            return 1;
        }     
    }
    return 0;

}
int removenode(list *l,int value)
{   
    node *tmp;
    node *ptr = l->head;
    while(ptr!=NULL)
    { 
        if(ptr->value == value){ 
            tmp->next = ptr->next;
            free(ptr);break;}
        else {
            tmp = ptr;
            ptr = ptr->next;        
    }
    }
}
int addAfterCount(list *l,int value,unsigned n)
{ 
   int count = 0;
   node *ptr,*tmp1,*tmp2;
   ptr = l->head;
   while(count!=n)
   {
       tmp1 = ptr;
       ptr = ptr->next;
       count++;
   }
    tmp2 = malloc(sizeof(node));
    tmp2->value = value;
    tmp2->next = ptr;
    tmp1->next = tmp2;
}
int main ()
{
    struct list l;
    init(&l);
    unsigned n; scanf("%u",&n);
    for(unsigned i = 1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        push_back(&l,a);
    }
    print(&l);
    // 3 элемента k
    for(int i = 1; i<=3;i++)
    {
        int k;
        scanf("%d",&k);// 3 Ki
        printf("%d",findval(&l,k));
    }
    printf("\n");
    
    int m;
    scanf("%d",&m); // back
    push_back(&l,m);print(&l);

     scanf("%d",&m); // front
     push_front(&l,m);print(&l);

     unsigned j; int x;
     scanf("%u",&j);scanf("%d",&x); // dobavit` posle j - togo uzla
     addAfterCount(&l,x,j);
     print(&l);
     scanf("%d",&m);removenode(&l,m); // udalit`
     print(&l);
     clear(&l); // ochistka
}   

