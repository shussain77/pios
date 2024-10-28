#include <stdio.h>

char glbl[128];

extern char __bss_start;
extern char __bss_end; // NAK Adding exter symbols

// Defining list_element struct 

struct list_el {
  struct list_el *next;
  int data;
};

void list_add(struct list_el **list_head, struct list_el *new_el);
void list_remove(struct list_el **list_head, struct list_el *el);

// Add element to the beginning of the list

void list_add(struct list_el **list_head, struct list_el *new_el) {
  if (new_el == NULL) return;
  new_el->next = *list_head; // New element now points to the current head
  **list_head = *new_el; // Updating list
}

// Remove element from the list

void list_remove(struct list_el **list_head, struct list_el *el) {
  if (*list_head == NULL || el == NULL) return;
  if (*list_head == el) { // If the element is the head, change head to next
    *list_head = el->next;
    return;
  }

// Find next 

  struct list_el *current = *list_head;
  while (current->next != NULL && current->next != el) {
    current = current->next;
  }

// Updating

  if (current->next == el) {
    current->next = el->next;
  }
}

// Test function to print the list

void print_list(struct list_el *head) {
  struct list_el *current = head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

 
int clearbss() {
  char *bssstart, *bssend;
  bssstart = &__bss_start;
  bssend = &__bss_end;
  for (char *ptr = bssstart; ptr < bssend; ptr++) { 
  *ptr = 0; // Sets all to 0, clearing the segment
  }
}


int kernel_main() {

// Clearing the segment
  
  clearbss();

  struct list_el c = { NULL, 0};
  struct list_el b = { &c, 0 };
  struct list_el a = { &b, 0 };
  struct list_el *head = &a;

// Testing 

  printf("initial list:\n");
  print_list(head);

  struct list_el new_el = { NULL, 1 };
  list_add(&head, &new_el);
  
  printf("\nlist after adding new element:\n");
  print_list(head);

  list_remove(&head, &b);

  printf("\nlist after removing element:\n");
  print_list(head);

  return 0;

}
