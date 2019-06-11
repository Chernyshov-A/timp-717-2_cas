    #include "stdio.h"
    #include "stdlib.h"
    typedef struct list_node
    {
        struct node *value;
        struct list_node *next;
    }list_node;
    typedef struct list
    {
        list_node *tail;
        list_node *head;
    }list;

    typedef struct node
    {   
        struct node* left;
        struct node* right;
        int value;
        struct node* parent;
        
    }node;
    typedef struct tree
    {
      struct node* root;
      int number;
    }tree;

void init_list(list* l)
    {
        l->head = NULL;
        l->tail = NULL;
    }
void init (tree *t)
{
  t->root = NULL;
  t->number = 0;
}
int isEmpty_list(list *l)
    {
      int flag = (l->tail==NULL);
      return flag;
    }

int push_list(list *l,node *value)
    {
        list_node *tmp_l = malloc(sizeof(list_node));
        tmp_l->value = value;
        tmp_l->next = NULL;

        if(!isEmpty_list(l))
        {
          l->tail->next = tmp_l;
          l->tail = tmp_l;
        }else
        {
          l->head = l->tail = tmp_l;
        }
    }



node* remove_list(list *l){
      list_node *phead = l->head;
      node *tempptr = l->head->value;

      l->head = l->head->next;

      if(l->head==NULL)
          l->tail=NULL;

      free(phead);

      return tempptr;
    }
int find(tree *t,int value,node *n){
       node *nodeptr = t->root;
       if(!nodeptr){return 1;}
       else
       {
           while(nodeptr!=NULL)
           {

               if(value > nodeptr->value)
               {
                 nodeptr = nodeptr->right;continue;
               }
               if(value < nodeptr->value)
               {
                 nodeptr = nodeptr->left; continue;
               }
               if (value == nodeptr->value)
               {
                   if(n == NULL){return 0;}
                   else {
                     printf("there");
                     n = nodeptr;
                     printf("in function find %p\n",n);
                       return 0;}
               }               
           }
       }
       return 1;
   }
   int insert(tree *t,int value)
    {
      node *tempptr = malloc(sizeof(node));
        if(!tempptr){return 2;}
        tempptr->value = value;
        tempptr->right = tempptr->left = NULL;
                
            if(!t->root)
            {
              tempptr->parent = NULL;    
                t->root = tempptr;
                (t->number)++;
                return 0;   
            }
            if(!find(t,value,NULL)){return 1;}
            else
            {
              node *prevptr;
              node *ptr = t->root;
            while(ptr)
              {
                 prevptr = ptr;
                  if( value < ptr->value)
                  {
                    if(!ptr->left)
                    {
                    tempptr->parent = prevptr;
                    prevptr->left = tempptr;
                    t->number ++;
                    return 0; 
                    }
                    else {ptr = ptr->left; continue;}
                  }
                  else
                  {
                    if(!ptr->right) 
                    {
                      tempptr->parent = prevptr;
                      prevptr->right = tempptr;
                      t->number ++;
                    return 0; 
                    }
                    else {ptr = ptr->right; continue;}
                  }      
              }
      
            }
                        return 1;
    }
      void printTree(tree *t, list *l)
 {
      node *rootptr = t->root;
      int number = 0;
      push_list(l,rootptr);
      while(!isEmpty_list(l))
      {
        node *tmp = remove_list(l);
        number ++;
        if(number<t->number) printf("%d ",tmp->value);
        else printf("%d\n",tmp->value);
        
        if(tmp->left!=NULL)push_list(l,tmp->left);
        if(tmp->right!=NULL)push_list(l,tmp->right);
      }
    }
    
int main(){
    tree *t = malloc(sizeof(tree));
    list *l = malloc(sizeof(list));
    init(t);
    init_list(l);
      for(int i = 0; i < 7; i++)
      {
        int number; scanf("%d",&number);
        insert(t,number);
      }
    printTree(t,l);
    }
