    #include "stdio.h"
    #include "stdlib.h"
    typedef struct stack_node
    {
        struct tree_node *value;
        struct stack_node *next;
    }stack_node;
    typedef struct stack
    {
        stack_node *tail;
        stack_node *head;
    }stack;

    typedef struct tree_node
    {   
        struct tree_node* left;
        struct tree_node* right;
        int value;
        struct tree_node* parent;
        
    }tree_node;
    typedef struct tree
    {
      struct tree_node* root;
      int number;
    }tree;
      
void init_stack(stack* s)
    {
        s->head = NULL;
        s->tail = NULL;
    }
int isEmpty_stack(stack *s)
    {
      int flag = (s->tail==NULL);
      return flag;
    }

int push_stack(stack *s,tree_node *value)
{
    stack_node *temp = malloc(sizeof(stack_node));
    temp->value = value;
    if(s->head==NULL && s->tail==NULL)
    {
        s->tail=temp;
        s->head=temp;
        temp->next = NULL;
        return 0;
    }
    else
    {
       stack_node *ptr = s->head;
       temp->next = ptr;
       s->head = temp;
       return 0;
    }
    return 1;
}
tree_node* pop_stack(stack *s){
      stack_node *phead = s->head;
      tree_node *tempptr = s->head->value;

      s->head = s->head->next;

      if(s->head==NULL)
          s->tail=NULL;

      free(phead);

      return tempptr;
    }
void init (tree *t)
{
  t->root = NULL;
  t->number = 0;
}
int find(tree *t,int value,tree_node *n){
       tree_node *nodeptr = t->root;
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
      tree_node *tempptr = malloc(sizeof(tree_node));
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
              tree_node *prevptr;
              tree_node *ptr = t->root;
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
void printTree(tree *t, stack *s)
 {
      tree_node *ptr = t->root;
      int number = 0;
      push_stack(s,t->root);
      while(!isEmpty_stack(s))
      {
        tree_node *temp = pop_stack(s);
        number ++;
        if(number < t->number) printf("%d ",temp->value);
        else printf("%d\n",temp->value);

        if(temp->right!= NULL)
        push_stack(s,temp->right);
        if(temp->left!= NULL)
        push_stack(s,temp->left);
        
      }
    }
    
int main(){
    tree *t = malloc(sizeof(tree));
    stack *s = malloc(sizeof(stack));
    init(t);
    init_stack(s);
      for(int i = 0; i < 7; i++)
      {
        int number; scanf("%d",&number);
        insert(t,number);
      }
    printTree(t,s);
    }
