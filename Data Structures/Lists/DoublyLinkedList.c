#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int dataType;

typedef struct node {
        dataType item;
        struct node *next;
        struct node *prev;
}Node;

/***PROTOTYPES***/
void printList(const Node *const list);
int listLength(const Node *const list);
Node *createNode(dataType item,  Node *const prev,Node *const next);
void insertFirst(Node **const list,const dataType item);
void insertLast(Node **const list,const dataType item);
void insert(Node **const list,const dataType item,const int index);
void delete(Node **const list,const int index);

/***PROTOTYPES***/


int main(int argc, char const *argv[]) {
        Node *list=NULL;


        return EXIT_SUCCESS;
}

/**Prints the given list using recursion*/
void printList(const Node *const list) {

        if (!list) return;

        printf(" %d",list->item );
        printList(list->next);
}

/**Returns the length of the given list.**/
int listLength(const Node *const list){
        if (!list)
                return 0;
        else
                return 1 + listLength(list->next);
}

/**Creates and returns a new node with the given parameters.***/
Node *createNode(dataType item, Node *const prev, Node *const next){
        Node *n;
        n = (Node*) malloc(sizeof(Node));
        n->prev = prev;
        n->next = next;
        n->item = item;
        return n;
}

/**Inserts an element at the  first position*/
void insertFirst(Node **const list,const dataType item) {

        /**If the list is empty then  a new node is created with the prev and next
           fields pointing to NULL. Then the new node's reference is assigned to list*/
        if (!(*list))
                *list = createNode(item,NULL,NULL);

        /**Else a new node is created with the previous and next fields pointing to null and to the list respectively.
           Then the new node's reference is assigned to the list.prev and list respectively.
           NOTE: The list reference is also the first list element.*/
        else
                *list = (*list)->prev = createNode(item,NULL,(*list));


}

/**Inserts an element at the last position*/
void insertLast(Node **const list,const dataType item) {
        Node *startPoint = *list; //saving the beggining

        /**If the list is empty then  a new node is created with the prev and next
           fields pointing to NULL.Then the new node's reference is assigned to list */
        if (!(*list)) {
                *list = createNode(item,NULL,NULL);
        }
        /* If the link to next element in the current node is null means the last element has been found**/
        else if(!((*list)->next)) {
                (*list)->next = createNode(item,(*list),NULL);
        }
        /*if the list is not empty and the last element has not been found list is pointed to the next element and a
           recursive call to the function is made**/
        else{
                *list = (*list)->next;
                insertLast(list,item);
        }

        /*Finally if startPoint is not null then the startPoint value is assigned to *list
           Note: startPoint is the address to the first list element and
           each time the function is called it has a different value.
         */
        if (startPoint)
                *list = startPoint;

}


/**Inserts an element at the given index, the index must be above or equal to zero otherwise
   the element  IS NOT inserted.
   If the index is GREATER than the list length it'll be inserted at the end**/
void insert(Node **const list,const dataType item,const int index) {
        int pos = 0;
        Node *l = *list;

        if (index >= 0) {
                if (!index) {
                        insertFirst(list,item);
                }
                else if (index >= listLength(*list)) {
                        insertLast(list,item);
                }
                else{
                        while (++pos < index)
                                l = l->next;

                        l->next = l->next->prev = createNode(item,l,l->next);
                }

        }

}

/**Deletes and element from the list in the given index.
    The index MUST be above or equals to zero AND below than the list length.**/
void delete(Node **const list,const int index) {
        int pos=0;
        Node *l= *list;

        if (index >= 0 && index < listLength(*list) && !(*list)) {


                while (pos++ < index)
                        l = l->next;

                if (!pos) {
                        *list = l->next;
                        if (!(*list))
                                (*list)->prev = NULL;
                }

                else if (!(l->next)) {
                        (l->prev)->next = NULL;
                }
                else{
                        (l->prev)->next = l->next;
                        (l->next)->prev = l->prev;
                }



                free(l);
        }

}
