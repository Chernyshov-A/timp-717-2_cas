    #include "stdio.h"
    #include "stdlib.h"
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
    int number = 0;
void printTree(tree *t,tree_node *node){
  if (node!= NULL){
        if(node->left != NULL)
          printTree(t,node->left);
        if(node->right != NULL)
          printTree(t,node->right);

        number++;

        if(number != t->number)
          printf("%d ", node->value);
        else 
          printf("%d\n",node->value);    
    }
    
  }
    
int main(){
    tree *t = malloc(sizeof(tree));
    init(t);
      for(int i = 0; i < 7; i++)
      {
        int number; scanf("%d",&number);
        insert(t,number);
      }
    printTree(t,t->root);
    }
