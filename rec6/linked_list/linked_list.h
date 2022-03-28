#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct _node_ {
  int value;
  struct _node_ *next;
} Node;

Node *node_create(int v) {
  Node *ret = (Node *)malloc(sizeof(Node));
  ret->value = v;
  ret->next = NULL;
  return ret;
}

typedef struct {
  Node *head;
  size_t length;
} Linked_list;

Linked_list *linked_list_create() {
  Linked_list *ret = (Linked_list *)malloc(sizeof(Linked_list));
  ret->head = NULL;
  ret->length = 0;
  return ret;
}

void linked_list_clear_tail(Node *cur) {
  if (!cur)
    return;
  linked_list_clear_tail(cur->next);
  free(cur);
}

void linked_list_destroy(Linked_list *list) {
  if (list) {
    linked_list_clear_tail(list->head);
    free(list);
  }
}

void linked_list_push_front(Linked_list *list, int v) {
  Node *new_node = node_create(v);
  new_node->next = list->head;
  list->head = new_node;
  ++list->length;
}

void linked_list_pop_front(Linked_list *list) {
  Node *front = list->head;
  list->head = list->head->next;
  free(front);
  --list->length;
}

void linked_list_insert_after(Linked_list *list, Node *pos, int v) {
  Node *new_node = node_create(v);
  new_node->next = pos->next;
  pos->next = new_node;
  ++list->length;
}

void linked_list_erase_after(Linked_list *list, Node *pos) {
  Node *next = pos->next;
  pos->next = next->next;
  free(next);
  --list->length;
}

/* -------------------------------------------------------------------------- */

size_t linked_list_count(Linked_list *list, int want) {
  size_t cnt = 0;
  for (Node *p = list->head; p; p = p->next)
    if (p->value == want)
      ++cnt;
  return cnt;
}

Linked_list *reversed_linked_list(Linked_list *list) {
  Linked_list *ret = linked_list_create();
  for (Node *p = list->head; p; p = p->next)
    linked_list_push_front(ret, p->value);
  return ret;
}

Linked_list *filter_linked_list(Linked_list *list,
                                       bool (*condition)(int)) {
  Linked_list *ret = linked_list_create();
  Node *tail = NULL;
  for (Node *p = list->head; p; p = p->next)
    if (condition(p->value)) {
      if (tail) {
        linked_list_insert_after(ret, tail, p->value);
        tail = tail->next;
      } else {
        linked_list_push_front(ret, p->value);
        tail = ret->head;
      }
    }
  return ret;
}

Linked_list *map_linked_list(Linked_list *list, int (*mapping)(int)) {
  Linked_list *ret = linked_list_create();
  Node *tail = NULL;
  for (Node *p = list->head; p; p = p->next)
    if (tail) {
      linked_list_insert_after(ret, tail, mapping(p->value));
      tail = tail->next;
    } else {
      linked_list_push_front(ret, mapping(p->value));
      tail = ret->head;
    }
  return ret;
}

int reduce_linked_list(Linked_list *list, int (*function)(int, int)) {
  int result = list->head->value;
  for (Node *p = list->head->next; p; p = p->next)
    result = function(result, p->value);
  return result;
}

void for_each_linked_list(Linked_list *list, void (*function)(int)) {
  for (Node *p = list->head; p; p = p->next)
    function(p->value);
}

bool equal_linked_list(Linked_list *lhs, Linked_list *rhs) {
  if (lhs->length != rhs->length)
    return false;
  for (Node *p = lhs->head, *q = rhs->head; p; p = p->next, q = q->next)
    if (p->value != q->value)
      return false;
  return true;
}

bool less_than_linked_list(Linked_list *lhs, Linked_list *rhs) {
  for (Node *p = lhs->head, *q = rhs->head; p && q; p = p->next, q = q->next) {
    if (p->value < q->value)
      return true;
    if (p->value > q->value)
      return false;
  }
  return lhs->length < rhs->length;
}

#endif // _LINKED_LIST_H_
