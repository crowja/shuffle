#include <stdlib.h>
#include <stdio.h>
#include "shuffle.h"

char *x[] = {"ant", "cat", "dog", "mouse", "zebra"};

static int
_cmp(const void *a, const void *b)
{
#if 0
   if (((struct spmat_coo_triple *) a)->i < ((struct spmat_coo_triple *) b)->i)
      return -1;
   if (((struct spmat_coo_triple *) a)->i > ((struct spmat_coo_triple *) b)->i)
      return 1;
   if (((struct spmat_coo_triple *) a)->j < ((struct spmat_coo_triple *) b)->j)
      return -1;
   if (((struct spmat_coo_triple *) a)->j > ((struct spmat_coo_triple *) b)->j)
      return 1;
   if (((struct spmat_coo_triple *) a)->v < ((struct spmat_coo_triple *) b)->v)
      return -1;
   if (((struct spmat_coo_triple *) a)->v > ((struct spmat_coo_triple *) b)->v)
      return 1;

   return 0;
#endif

   return -strcmp(a, b);
}

int
main(int argc, char *argv[])
{
   int i;

   printf("=====\n");
   for (i = 0; i < 5; i++)
      printf("%s\n", x[i]);

#if 1
   shuffle_array(x, 5, sizeof(char *));
#else
   /* TODO this pattern works, so see what we're doing wrong with what's above */
   qsort(x, 5, sizeof(char *), _cmp);
#endif

   printf("=====\n");
   for (i = 0; i < 5; i++)
      printf("%s\n", x[i]);

   return 0;
}
