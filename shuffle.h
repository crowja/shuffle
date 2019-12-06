/**
 *  @file shuffle.h
 *  @version 0.0.2-dev0
 *  @date Fri Dec  6 11:02:37 CST 2019
 *  @copyright %COPYRIGHT%
 *  @brief FIXME
 *  @details FIXME
 */

#ifndef _SHUFFLE_H_
#define _SHUFFLE_H_

#ifdef  _PACKAGE_NAME
#undef  _PACKAGE_NAME
#endif
#define _PACKAGE_NAME "shuffle"

int         shuffle_func1(const char *cp);

/**
 *  @brief Return the version of this package.
 *  @details FIXME longer description here ...
 */

const char *shuffle_version(void);

int         shuffle_array(void *base, size_t nmemb, size_t size);


#endif
