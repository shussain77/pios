#include <stdio.h>

char glbl[128];

struct list_el {
  int data;
  struct list_el *next;
};
 
int clearbss() {

  char *bssstart, *bssend;
  bssstart = &__bss_start;
  bssend = &__bss_end;
  for (char *ptr = bssstart; ptr < bssend; ptr++) {
  *ptr = 0;
}

/*
  for(int k = 0; k < 10; k++) {
  printf("[%d @ %p] 0x%lx\n", k, &glbl[k], glbl[k]);
}
*/
return 0;
}

/*
void list_add(struct list_el **list_head, struct list_el *new_el){
  struct list_el* new_el
    = (struct list_el*)
}
void list_remove(struct list_el *elm, int x) {
  if ((*elm) != NULL) {
   if (x == (*elm)->data)
     (*elm) = (*elm)->next;
   else
     list_remove(x, &((*elm)->next));
}
*/

void kernel_main() {

  extern int __bss_start, __bss_end;
/*
  bssstart = &__bss_start;
  bssend = &__bss_end;
*/
  while(1){
  }

}
