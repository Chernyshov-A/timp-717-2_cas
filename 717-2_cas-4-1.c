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

    node* remove_list(list *l)
    {
      list_node *phead = l->head;
      node *tempptr = l->head->value;

      l->head = l->head->next;

      if(l->head==NULL)
          l->tail=NULL;

      free(phead);

      return tempptr;
    }

    int isNULL_list(list *l)
    {
      list_node *phead = l->head;
      while(phead!=NULL)
        {
          if(phead->value!=NULL)
          return 0;

          phead = phead->next;
        }
      return 1;
    }

    void print_list(list *l)
    {
      list_node *phead = l->head;
      while(phead)
      {
        if(!phead->value)
            printf("_");
        else printf("%d",phead->value->value);

        if(phead->next)
        printf(" ");

        phead = phead->next;
      }
      printf("\n");
    }
    void clear(tree *t,list *l)
    {
        
      node *proot = t->root;
      node *tempptr;
      push_list(l,proot);
            while(isEmpty_list(l))
      {
       
        tempptr = proot;
        proot = remove_list(l);

        free(tempptr);

        if(tempptr->left != NULL)
          {
            
            push_list(l,proot->left);
          }
        else if(tempptr->right!=NULL) {
           
            push_list(l,tempptr->right);
          }
      }
        t->root = NULL;
    }

    void init(tree *t)
    {
      
        t->number = 0;
        t->root = NULL;
    }

   int find(tree *t,int value,node *n)
   {
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

 int deleteNode_tree(tree* t, int value)
    {
      node* tempptr = t->root;
	    node* tmp1;
	    node* tmp2;

      while(tempptr != NULL) {
        if(tempptr->value == value)
          break;

        if(value > tempptr->value) {
          if(tempptr->right == NULL) {
            return 1;
          }
          tempptr = tempptr->right;
        }
        else  {
          if(tempptr->left == NULL) {
            return 1;
          }
          tempptr = tempptr->left;
        }
	      }

        if(tempptr->value == t->root->value) {
          tmp1 = tempptr;
          if(tempptr->right != NULL) {
            tmp1 = tempptr->right;

            while(tmp1->left != NULL) {
              tmp1 = tmp1->left;
            }
          }
          tmp1->parent = NULL;
          tmp1->left = tempptr->left;
          tmp2 = tempptr;
          tmp2 = tmp2->left;
          tmp2->parent = tmp1;
          
          t->root = tmp1;
          free(tempptr);
          t->number--;
          return 1;
        }
        return 0;
      }


  void findParent_tree(tree *t,int value)
   {
      node *nodeptr = t->root;
       if(!nodeptr){printf("_");}
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
                 break;
               }               
           }
        if(!nodeptr->parent) printf("_ ");
        else
        {
          printf("%d ",nodeptr->parent->value);
        }
        if(!nodeptr->left) printf("_ ");
        else
        {
          printf("%d ",nodeptr->left->value);
        }
        if(!nodeptr->right)printf("_");
        else
        {
          printf("%d",nodeptr->right->value);
        }
       }
       printf("\n");
   }
  void findChild_tree(tree *t,int value)
   {
      node *nodeptr = t->root;
       if(!nodeptr){printf("-");}
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
                 break;
               }               
           }
        if(!nodeptr){printf("-\n"); return;}
        if(!nodeptr->parent) printf("_ ");
        else
        {
          printf("%d ",nodeptr->parent->value);
        }
        if(!nodeptr->left) printf("_ ");
        else
        {
          printf("%d ",nodeptr->left->value);
        }
        if(!nodeptr->right)printf("_");
        else
        {
          printf("%d",nodeptr->right->value);
        }
       }
       printf("\n");
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
        node *proot = t->root;
        list *l_tmp = malloc(sizeof(list));
        init_list(l_tmp);
        if(!proot)
        {
          printf("-\n");
          return;
        }
        push_list(l,proot);
        print_list(l);
          
        for(;;) 
        {

          while(!isEmpty_list(l))
          { 
            proot = remove_list(l);
            push_list(l_tmp,proot);
          }
          
            while(!isEmpty_list(l_tmp))
            {
              proot = remove_list(l_tmp);
              if(!proot)
              {
                push_list(l,NULL);
                push_list(l,NULL);
              }
              else
              {
                push_list(l,proot->left);
                push_list(l,proot->right);
              }
              
            } 
              if(isNULL_list(l)){
                while(!isEmpty_list(l))
                  remove_list(l);  
                break;
              }
              
             print_list(l); 
          }
        
      }
    
    int rotateLeft(tree *t) 
    {
      node *parent = NULL,
          *prev = NULL,
          *next = NULL, 
          *now = NULL;
        if(!t->root->right) return 1;

      while(t->root->right)
      {
      next = t->root;
      parent = next->parent;
      now = next->right;
      if (now == NULL) {
          return 1;
      }
      prev = now->left;
  
      now->left = next;
      next->right = prev;
      if (prev) {
          prev->parent = next;
      }
      now->parent = parent;
      if (parent) {
          if (parent->left == next) {
              parent->left = now;
          } else {
              parent->right = now;
          }
      }
      next->parent = now;
      if (!parent) {
          t->root = (t->root)->parent;
      }
        }   
        return 0;
  } 

int rotareRight(tree *t) {
    node *parent = NULL,
         *prev = NULL,
         *next = NULL, 
         *now = NULL;
         if(!t->root->left) return 1;

    while(t->root->left)
    {
          now = (t->root);
          parent = now->parent;
          next = now->left;
          if (next == NULL) {
              return 1;
          }
          prev = next->right;
      
          next->right = now;
          now->left = prev;
          if (prev) {
              prev->parent = now;
          }
          next->parent = parent;
          if (parent) {
              if (parent->left == now) {
                  parent->left = next;
              } else {
                  parent->right = next;
              }
          }
          now->parent = next;
      
          t->root = (t->root)->parent;
          
    }
   return 0;
}


    int main()
    {
      tree *t = malloc(sizeof(tree));
      list *l = malloc(sizeof(list));
      init(t);
      init_list(l);
      for(int i = 0; i < 4; i++)
      {
        int next; scanf("%d",&next);
        insert(t,next);
      }
     printTree(t,l);
     for(int i = 0; i < 3; i++)
     {
       int next;scanf("%d",&next);
       insert(t,next);
     }printTree(t,l);

     int m1;scanf("%d",&m1);
     findParent_tree(t,m1);

     int m2; scanf("%d",&m2);
     findChild_tree(t,m2); 

     int m3; scanf("%d",&m3);

     deleteNode_tree(t,m3);printTree(t,l);

     rotateLeft(t);printTree(t,l);

     rotareRight(t);printTree(t,l);

     printf("%d\n",t->number); 

     clear(t,l);printTree(t,l); 
    }
