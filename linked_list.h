#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "status.h"

typedef void* NODE;

/* Precondition: hList is a handle to a linked list. key and data are the key-data
   pair for the hash table element.
   Postcondition: inserts new key-data pair the at the head and returns SUCCESS.
   Allows for duplicates. Returns FAILURE for any memory allocation failure */
Status list_head_insert(NODE* phList, char* key, int data);

/* Precondition: hList is a handle to a linked list. key and data are the key-data
   pair for the hash table element.
   Postcondition: inserts new key-data pair and the head and returns SUCCESS.
   Allows for duplicates. Returns FAILURE for any memory allocation failure */
Status list_tail_insert(NODE* phList, char* key, int data);

/* Precondition: hNode is a handle to a node that exists in the linked list.
   Postcondition: the nodes data is updated with "data" */
void list_update_existing_node(NODE hNode, int data);

/* Precondition: phList is a pointer to a handle to a linked list. key is the key to be removed.
   Postcondion: returns SUCCESS if the key was found and removed. Else returns FAILURE.
   Must be a pointer for the edge case where they key to be removed is at the head so the
   head has to be updated */
Status list_remove(NODE* phList, char* key);

/* Precondition: hList is a handle to a linked list.
   Postcondition: sorts the list in order least to greatest using the lexicographical values of
   the keys and returns SUCCESS. Returns FAILURE if the list is empty. Uses merge sort */
Status list_mergeSort_LTG(NODE* phList);

/* Precondition: phList is a pointer to a handle to a valid linked list
   Postcondition: frees all memory associated with the linked list and sets the
   list pointer to NULL */
void list_destroy(NODE *phList);

/* Precondition: hList is a handle to a valid linked list.
   Postcondition:
     - list doesn't exist (hlist is NULL): returns true, sets status to FAILURE
     - list is empty: returns true, sets status to success
     - list is not empty: returns false, sets status to success */
Boolean list_is_empty(NODE hList, Status *pStatus);

/* Precondition: hList is a handle to a linked list. key is the key to be searched for.
   Postcondition: returns true if the key already exists and stores the node's address in pFoundNode
   and it's data in pData. Else returns FALSE.
   Note: you can pass NULL to pFoundNode and pData if you just want to see if the key exists. They function
   will just ignore them in this case. */
Boolean list_key_exists(NODE hList, char* key, NODE* pFoundNode, int* pData);

/* Precondition: hList is a handle to a linked list. key is the key to search for, data will
   store the data if found
   Postcondition: if key is found, returns SUCCESS and stores the data in "data". If the key
   is not found, returns FAILURE and stores a 0 in data */
Status list_get_data_by_key(NODE hList, char* key, int* pData);

/* Precondition: hList is a handle to a linked list
   Postcondition: prints the list in the respective order and returns SUCCESS.
   Returns FAILURE if the list is empty */
Status list_print_head_to_tail(NODE hList);
Status list_print_head_to_tail_one_line(NODE hList);

/* Displays all info about each node for debugging purposes: previous/current/next node address,
   the key, and the data */
Status list_debug(NODE hList);

/* Precondition: hListToCopy is a handle to a linked list. phNewList is a pointer to a handle to a
   linked list
   Postcondition: a copy of hListToCopy is made and stored in phNewList. Any list that was previously existing
   in phNewList is first destroyed. Returns SUCCESS else FAILURE if memory allocation fails */
Status list_copy_list(NODE hListToCopy, NODE* phNewList);

/* Same as the above function except keeps track of the tail pointer in the third argument. This is needed
   to more efficiently call the combine lists function below */
Status list_copy_list_modified(NODE hListToCopy, NODE* phNewList, NODE* phNewTail);

/* Same as list_tail_insert except it keeps track of the tail pointer. This is needed to more effciciently
   call the combine lists function below. This function in particular is called by list_copy_list_modified */
Status list_tail_insert_modified(NODE* phList, NODE* phNewTail, char* key, int data);

/* Creates a new linked list stored in phNewList by copying hList1 and hList2 and then appending
   the copy of hList2 to hList1. phNewListTail keeps track of the tail of the new combined list */
Status list_combine_two_lists(NODE hList1, NODE hList2, NODE* phNewList, NODE* phNewListTail);

#endif