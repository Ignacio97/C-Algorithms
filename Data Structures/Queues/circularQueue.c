#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 50
#define cls() system("clear"); //for linux/mac users
//#define cls() system("cls"); //for windows users

//dataType type the stack will hold.
typedef int dataType;

typedef struct {
  int capacity;
  int size;
  int front;
  int rear;
  dataType *array;
}circularQueue;

/****PROTOTYPES***/
void throwError(char *message);
int size(circularQueue *q);
bool isFull(circularQueue *q);
bool isEmpty(circularQueue *q);
dataType peek(circularQueue **q);
dataType deQueue(circularQueue **q);
void enQueue(circularQueue **q,dataType item);
circularQueue *newCircularQueue(int arraySize);
/****END PROTOTYPES***/


/*****MAIN****/
int main(int argc, char const *argv[]) {

circularQueue *queue = newCircularQueue(10);
int i;
  
printf("empty? %d\n",isEmpty(queue)); //should print true.
printf("full? %d\n",isFull(queue)); //should print false.
printf("size: %d\n",size(queue)); //should print 0, cuz' no item has been enqueued.

for (i = 0; i < 10; ++i)
  enQueue(&queue, i+5*21);




    return EXIT_SUCCESS;
}
/*****END MAIN****/

circularQueue *newCircularQueue(int arraySize) {
  circularQueue *temp = (circularQueue*)malloc(sizeof(circularQueue));

  temp->capacity = arraySize+1;
  temp->size = 0;
  temp->front = 0;
  temp->rear = 0;
  temp->array = (dataType*) malloc(sizeof(dataType) * arraySize+1);
  
  return temp;
}

void enQueue(circularQueue **q,dataType item) {
  if (isFull(*q)) throwError("FULL QUEUE!!!");
 
  (*q)->rear = (*q)->rear+1 % (*q)->capacity;

  (*q)->array[(*q)->rear] = item; 
  
}

dataType deQueue(circularQueue **q){
  if (isEmpty(*q))   throwError("EMPTY QUEUE!!");

(*q)->front = (*q)->front +1 % (*q)->capacity;


return (*q)->array[(*q)->front];
}


dataType peek(circularQueue **q){

  if (isEmpty(*q)) throwError("EMPTY QUEUE!!");


 return (*q)->array[(*q)->front+1];
}

bool isEmpty(circularQueue *q) {

return q->front == q->rear;
}

bool isFull(circularQueue *q){

return (q->front == q->rear +1 % q->capacity); 
}

int size(circularQueue *q){

return q->size;
}

void throwError(char *message) {
  printf("%s\n",message);
  exit(EXIT_FAILURE);
}
