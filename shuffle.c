/**
 *  @file shuffle.c
 *  @version 0.1.1-dev0
 *  @date Sun Feb 16, 2020 05:01:16 PM CST
 *  @copyright 2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 */

#include <stdlib.h>
#include <stdio.h>
#include "shuffle.h"

/**
 *  Byte-wise swap two items of size <size>.
 *  Swiped from https://code.woboq.org/userspace/glibc/stdlib/qsort.c.html.
 *  See also http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.14.8162&rep=rep1&type=pdf.
 */
#ifdef  SWAP
#undef  SWAP
#endif
#define SWAP(a, b, size)             \
  do                                  \
    {                                 \
      size_t __size = (size);         \
      char *__a = (a), *__b = (b);    \
      do                              \
        {                             \
          char __tmp = *__a;          \
          *__a++ = *__b;              \
          *__b++ = __tmp;             \
        } while (--__size > 0);       \
    } while (0)

/* Randomly generate an integer between a and b, inclusive */
static int
_random_int(int a, int b)
{
   double      u = rand() / (double) RAND_MAX;
   return a + (1 + b - a) * u;
}

const char *
shuffle_version(void)
{
   return "0.1.1-dev0";
}

int
shuffle_array(void *base, size_t nmemb, size_t size)
{
   unsigned    i;
   char       *basep = base;

   srand((unsigned) time(NULL));                 /* FIXME not needed in practice */

   for (i = 0; i < nmemb - 1; i++) {
      unsigned    j = _random_int(i, nmemb - 1);
      SWAP(basep + i * sizeof(char *), basep + j * sizeof(char *), size);
   }

   return 0;
}
