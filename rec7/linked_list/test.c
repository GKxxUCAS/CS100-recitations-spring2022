#include "doubly_linked_list.h"
#include <assert.h>
#include <stdio.h>

int main() {
  List list;
  list_create(&list);
  for (int i = 0; i < 10; ++i)
    list_push_back(&list, i);
  for (Node *p = list.head; p; p = p->next)
    printf("%d ", p->data);
  puts("");
  for (Node *p = list.tail; p; p = p->prev)
    printf("%d ", p->data);
  puts("");
  assert(list.size == 10);
  assert(list.head->prev == NULL);
  assert(list.tail->next == NULL);
  list_reverse(&list);
  for (Node *p = list.head; p; p = p->next)
    printf("%d ", p->data);
  puts("");
  assert(list.head->prev == NULL);
  assert(list.tail->next == NULL);
  Node *pos = list_find_first(&list, 3);
  list_insert_after(&list, pos, 2313);
  pos = pos->next;
  pos = pos->next;
  list_erase(&list, pos);
  list_pop_back(&list);
  list_pop_front(&list);
  for (Node *p = list.head; p; p = p->next)
    printf("%d ", p->data);
  puts("");
  assert(list.head->prev == NULL);
  assert(list.tail->next == NULL);
  assert(list.size == 8);
  list_clear(&list);
  return 0;
}
