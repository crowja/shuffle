/**
 *  @file shuffle.h
 *  @version 0.1.1-dev0
 *  @date Sun Feb 16, 2020 05:01:16 PM CST
 *  @copyright 2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 */

#ifndef SHUFFLE_H
#define SHUFFLE_H

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
