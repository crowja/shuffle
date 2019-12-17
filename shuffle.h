/**
 *  @file shuffle.h
 *  @version 0.0.3-dev0
 *  @date Mon Dec 16 22:38:05 CST 2019
 *  @copyright %COPYRIGHT%
 */

#ifndef _SHUFFLE_H_
#define _SHUFFLE_H_

#ifdef  _PACKAGE_NAME
#undef  _PACKAGE_NAME
#endif
#define _PACKAGE_NAME "shuffle"

/**
 *  @brief Return the version of this package.
 */

const char *shuffle_version(void);

/**
 *  @brief Shuffle an array.
 *  @param[in, out] base: Pointer to the base of the array. Shuffled on return.
 *  @param[in] nmemb. Number of members in the array. 
 *  @param[in] size. Size in bytes of each member of the array. 
 *  @returns 0.
 */

int         shuffle_array(void *base, size_t nmemb, size_t size);

#endif
