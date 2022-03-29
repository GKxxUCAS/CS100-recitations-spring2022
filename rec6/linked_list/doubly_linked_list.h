#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct _node_ {
  int data;
  struct _node_ *prev;
  struct _node_ *next;
} Node;

typedef struct {
  Node *head, *tail;
  size_t size;
} List;

/**
 * @brief Create a %Node object.
 *
 * @param value The data to be stored in this node.
 * @return Node* Points to the %Node created.
 *
 * This function creates a %Node object, sets its %data to a given @a value and
 * sets @c prev and @c next to NULL. We don't want any %Node object that is not
 * allocated on heap to appear, so we only provide this function (unlike what we
 * do in @c list_create).
 */
Node *create_list_node(int value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = value;
  new_node->prev = NULL;
  new_node->next = NULL;
  return new_node;
}

/**
 * @brief Initializes a list to an empty linked-list.
 *
 * @param list Points to a linked-list.
 *
 * The %List object that @a list points to could be either on heap or not.
 * @example
 *    List list;
 *    list_create(&list);
 * or:
 *    List *list = (List *)malloc(sizeof(List));
 *    list_create(list);
 * Whether the %List object is allocated on heap is up to the user.
 */
void list_create(List *list) {
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

/**
 * @brief Frees all the memory allocated for the nodes in the linked-list.
 *
 * @param list Points to a linked-list.
 *
 * This function clears the whole linked-list. After that, the %List object
 * pointed by @a list is an empty linked-list. Note that this function does not
 * care about whether the %List object itself is created on heap. Users need
 * to free it themselves if they created a %List on heap.
 */
void list_clear(List *list) {
  Node *cur = list->head;
  if (!cur)
    return;
  Node *next = cur->next;
  while (true) {
    free(cur);
    cur = next;
    if (!cur)
      break;
    next = cur->next;
  }
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

/**
 * @brief Inserts an element after a given position.
 *
 * @param list Points to the linked-list.
 * @param pos Points to a %Node.
 * @param value The element that needs to be inserted.
 * @return Node * Points to the node inserted.
 *
 * Inserts a node with @c data set to @a value at the position after @a pos.
 */
Node *list_insert_after(List *list, Node *pos, int value) {
  // YOUR CODE HERE!
}

/**
 * @brief Removes an element from a linked-list.
 *
 * @param list Points to the linked-list.
 * @param pos Points to the %Node to be removed.
 */
void list_erase(List *list, Node *pos) {
  // YOUR CODE HERE!
}

/**
 * @brief Appends an element to the end of a linked-list.
 *
 * @param list Points to the linked-list.
 * @param value The element to be appended.
 */
void list_push_back(List *list, int value) {
  // YOUR CODE HERE!
  // Hint: Simply call list_insert_after.
}

/**
 * @brief Removes the last element from a linked-list.
 *
 * @param list Points to the linked-list.
 */
void list_pop_back(List *list) {
  // YOUR CODE HERE!
  // Hint: Simply call list_erase.
}

/**
 * @brief Places an element at the beginning of a linked-list.
 * 
 * @param list Points to the linked-list.
 * @param value The element to be inserted.
 */
void list_push_front(List *list, int value) {
  // YOUR CODE HERE!
}

/**
 * @brief Removes the first element from a linked-list.
 * 
 * @param list Points to the linked-list.
 */
void list_pop_front(List *list) {
  // YOUR CODE HERE!
}

/**
 * @brief Finds the position where a given value appears the first time.
 *
 * @param list Points to the linked-list.
 * @param value The element to look for.
 * @return Node* Pointer to the %Node where @a value appears the first time, or
 * NULL if no such element exists.
 */
Node *list_find_first(List *list, int value) {
  // YOUR CODE HERE!
}

/**
 * @brief Reverses a given linked-list.
 * 
 * @param list Points to the linked-list to be reversed.
 */
void list_reverse(List *list) {
  // YOUR CODE HERE!
}

#endif // DOUBLY_LINKED_LIST
