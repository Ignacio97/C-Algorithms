#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//data type to be held
typedef int dataType;

//The node.
typedef struct node {
        dataType item;
        struct node *next;
}Node;


/****PROTOTYPES**/
Node *createNode(const dataType data);
int listLength(const Node *const list);
void insertFirst(Node **const list,const dataType data);
void insertLast(Node **const list,const dataType data);
void insert(Node **const list,const dataType data,const unsigned int position);
void delete(Node **const list,const unsigned int position);
void printList(const Node *list);
/***END PROTOTYPES**/


int main() {
        Node *list=NULL;

        insertLast(&list,2);
        insertLast(&list,22);
        insertLast(&list,23);
        printList(list);


        printf("\n list length:%d\n",listLength(list) );

        delete (&list,0);
        printList(list);
        printf("---------------\n" );

        delete (&list,1);
        printList(list);
        printf("----------------\n" );

        delete (&list,0);
        printList(list);
        printf("\n list length:%d\n",listLength(list) );
        return EXIT_SUCCESS;
}



/**Creates and returns a new node with the given data.
    The next node reference is set to NULL**/
Node *createNode(const dataType data){
        Node *tmp = (Node *) malloc(sizeof(Node));
        tmp->next = NULL;
        tmp->item = data;

        return tmp;
}

/*Return the length of the given list*/
int listLength(const Node *const list){
        if (list == NULL)
                return 0;
        else
                return 1 + listLength(list->next);
}

/**Inserts the given element in the first list position.*/
void insertFirst(Node **const list,const dataType data){
        Node *n = createNode(data);
        n->next = *list;
        *list = n;
}


/**Inserts the given element in the last list position**/
void insertLast(Node **const list,const dataType data){
        Node *startPoint = *list; //saving the beggining

        /* if list points to null it means the list is empty,
           so then we create a new node and assign the reference to the list.*/
        if (*list == NULL) {
                *list = createNode(data);
        }
        /*if list.next is equal to null we've found que last list element.
           Then we only have to create a new node and assign the reference to
           list.next.*/
        else if ((*list)->next == NULL) {
                (*list)->next = createNode(data);
        }
        /*if the function has reached to this points it mean that the list wasn't empty
           and the last list element has not been found, so we have to point list to the
           next list element and make a recursive call to the function. This action WILL
           modify the list (*list) address value that's why startPoint storages *list. */
        else{
                (*list) = (*list)->next;
                insertLast(list,data);
        }


        /*Finally if startPoint is not null then we assign startPoint to *list
           Keep in mind that startPoint is the address to the first list element and
           each time the function is called it has a different value.
         */
        if (startPoint) //if startPoint!= NULL
                *list = startPoint;

}

/*Inserts an element into the list in the given position,
   if the given position is greater than the list length
   the element is inserted at the end.*/
void insert(Node **const list,const dataType data,const unsigned int position) {

/*If the list is empty or position is equal to zero then we insert the data
   in the first position */
        if (!list || !position) {
                insertFirst(list, data); //previously declared, go above.
        }
        /**If the position is greater than the list length then we insert the element at the end**/
        else if(position > listLength(*list)) {
                insertLast(list,data); //previously declared, go above.
        }

        /**If list is not empty, position is not greater than list or position is no zero it means we have go to
           through the list until we find the given position.  */
        else{
                Node *aux,*prev = (*list);
                int pos = 0;

                /**Iterating through the nodes until we find the previous position to the given position**/
                while (++pos < position)
                        prev = prev->next;

                /*Creating the new node*/
                aux = createNode(data);
                /**assigning the position+1 reference to aux.next**/
                aux->next = prev->next;
                /**assigning the new node reference (aux) to the position-1 node (prev.next) **/
                prev->next = aux;
        }
}


/*Deletes an element from the list in the given position, if
   position is greater than the list length non action is executed.*/
void delete(Node **const list,const unsigned int position) {
        Node *tmp, *l = *list;
        int index  = 0;

/** If list is empty or the position is greater than the list
   length we don't do anything*/
        if (position < listLength(*list) && (*list))  {


                if (position == 0) {
                        tmp = *list;
                        *list = (*list)->next;
                }
                else  {

                        while (index++ < position-1)
                                l = l->next;

                        tmp = l->next;
                        l->next = (l->next)->next;
                }

                free(tmp);
        }

}


//Prints the list.
void printList(const Node *list){

        if (list == NULL) return; //base case

        printf("%d ",list->item);
        printList(list->next);
}
