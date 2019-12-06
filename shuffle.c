/**
 *  @file shuffle.c
 *  @version 0.0.2-dev0
 *  @date Fri Dec  6 11:02:37 CST 2019
 *  @copyright %COPYRIGHT%
 *  @brief FIXME
 *  @details FIXME
 */

#include <stdlib.h>
#include <stdio.h>
#include "shuffle.h"

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  _FREE
#undef  _FREE
#endif
#define _FREE(p)      ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

/**
 *  Byte-wise swap two items of size <size>.
 *  Swiped from https://code.woboq.org/userspace/glibc/stdlib/qsort.c.html.
 *  See also http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.14.8162&rep=rep1&type=pdf.
 */
#ifdef  _SWAP
#undef  _SWAP
#endif
#define _SWAP(a, b, size)             \
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

/*** shuffle_version() ***/

const char *
shuffle_version(void)
{
   return "0.0.2-dev0";
}

/*** shuffle_array() ***/

int
shuffle_array(void *base, size_t nmemb, size_t size)
{
   unsigned    i;
   char       *basep = base;

   srand((unsigned) time(NULL));                 /* FIXME not needed in practice */

   for (i = 0; i < nmemb - 1; i++) {
      unsigned    j = _random_int(i, nmemb - 1);
      _SWAP(basep + i * sizeof(char *), basep + j * sizeof(char *), size);
   }

   return 0;
}

#undef _IS_NULL
#undef _FREE
