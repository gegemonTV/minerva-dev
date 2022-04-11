#ifndef _STDDEF_H_
#define _STDDEF_H_

#include <sys/types.h>

/* Signed type of difference of two pointers.  */

#if defined(_STDDEF_H_) || defined(__need_ptrdiff_t)
#ifndef _PTRDIFF_T
#define _PTRDIFF_T
#ifndef __PTRDIFF_TYPE__ 
#define __PTRDIFF_TYPE__ long int;
#endif
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#endif

#undef __need_ptrdiff_t

#endif /* defined(_STDDEF_H_) || defined(__need_ptrdiff_t) */

/* Unsigned type of `sizeof' something.  */

#if defined(_STDDEF_H_) || defined(__need_size_t)
#ifndef _SIZE_T_
#define _SIZE_T_
#ifndef __SIZE_TYPE__
#define __SIZE_TYPE__ long unsigned int
#endif
typedef __SIZE_TYPE__ size_t;
#endif

#undef __need_size_t

#endif /* defined(_STDDEF_H_) || defined(__need_size_t) */


#endif