#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int dataType;

typedef struct node {
        dataType item;
        struct node *next;
}Node;

typedef struct {
        Node *front;
        Node *rear;
}Queue;


Queue *newQueue();
void enQueue(Queue *q,dataType item);
dataType deQueue(Queue *q);
Node *newNode(dataType item);
bool isEmpty(Queue *q);


int main(int argc, char const *argv[]) {

        Queue *q = newQueue();

        for (int i = 0; i < 5; i++) {
            enQueue(q,i);
        }

        for (int i = 0; i < 6; i++) {
          printf("%d\n",deQueue(q) );
        }

        return EXIT_SUCCESS;
}

Queue *newQueue(){
        Queue *temp = (Queue*) malloc(sizeof(Queue));
        temp->front = temp->rear = NULL;
        return temp;
}



void enQueue(Queue *q,dataType item) {
        Node *temp = newNode(item);

        if (isEmpty(q)) {
                (q)->front = temp;
        }
        else{
                (q)->rear->next = temp;
        }

        (q)->rear = temp;

}


dataType deQueue(Queue *q) {
        dataType item;
        Node *temp;

        if (!isEmpty(q)) {
                temp = (q)->front;
                item = temp->item;

                (q)->front = (q)->front->next;
                if ((q)->front == NULL) {
                        (q)->rear = NULL;
                }
                free(temp);
                return item;
        }

        printf("%s\n","ERROR, EMPTY QUEUE!!");
        exit(EXIT_FAILURE);
}


Node *newNode(dataType item){
        Node *temp = (Node*) malloc(sizeof(Node*)); if (temp == NULL) printf("ERROR CREATING NODE\n");
        temp->item = item;
        temp->next = NULL;
        return temp;
}

bool isEmpty(Queue *q){
        return (q->front == NULL);
}
