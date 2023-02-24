typedef struct node{
   struct node* nextPtr;
   int order_number;
   int qty;
}order;

typedef order Node;
typedef  order* NodePtr;



typedef struct {
NodePtr headPtr,tailPtr;
int size;
}Queue;


void enqueue_struct(Queue* q, int x, int y){
 
  Node *new_node=(Node*) malloc(sizeof(Node));
if(new_node){
 /*Finish enqueue */
  new_node->order_number=x;
  new_node->qty=y;
  new_node->nextPtr=NULL;
 
  if(q->headPtr==NULL) q->headPtr=new_node;
  else (q->tailPtr)->nextPtr=new_node;
  (q->tailPtr)=new_node;
  q->size++; 
 }
}


int dequeue_struct(Queue *q){
   NodePtr t=q->headPtr;
  int price;
   if(q->size>0){
     switch(t->order_number){
       case 1: printf("Ramen\n");
         price = 100*t->qty;
         break;
       case 2: printf("Somtum\n");
         price = 20*t->qty;
         break;
       case 3: printf("KFC\n");
         price = 50*t->qty;
         break;
       default : printf("No Food/n");
     }

     q->size--;
     q->headPtr = t->nextPtr;
     if( q->headPtr==NULL)
     q->tailPtr=NULL;
      free(t);
       /*Finish dequeue */
     }
   return price;
     
  // printf("Empty queue");
   return 0;
}