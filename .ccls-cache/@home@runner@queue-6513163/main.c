#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "Node.h"

#include "Queue.h"

int main(int argc, char **argv) {
  NodePtr headPtr = NULL;
  NodePtr tailPtr = NULL;
  /* For struct Queue*/
  Queue q;
  q.headPtr = NULL;
  q.tailPtr = NULL;
  q.size = 0;

  int i, x, price;
  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "x") == 0) {
      x = dequeue_struct(&q);
      if (x > 0) {
        printf("You have to pay %d \n:", x);
        int cash;
        do {
          printf("Cash:");
          scanf("%d", &cash);
        } while (cash < x);
        printf("Thank you\n");
        if (x < cash)
          printf("Change is %d\n", cash - x);
      }
    } else {
      enqueue_struct(&q, atoi(argv[i]), atoi(argv[i + 1]));
      i++;
    }
  }
  printf("===================================\n");
  if (q.size == 1)
    printf("There is %d people left in the queue\n", q.size);
  else if (q.size > 1)
    printf("There are %d people left in the queue\n", q.size);
  else if (q.size ==0)
    printf("No queue\n");
  else if (q.size > 0)
    printf("clearing all node\n");
  int temp = q.size;
  for (int i = 0; i < temp; i++) {
    dequeue_struct(&q);
  }
  return 0;
}
