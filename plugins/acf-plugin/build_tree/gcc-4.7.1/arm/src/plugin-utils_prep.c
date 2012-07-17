# 1 "../../../src/plugin-utils.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "../../../src/plugin-utils.c"
# 20 "../../../src/plugin-utils.c"
# 1 "/usr/include/stdlib.h" 1 3 4
# 25 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 313 "/usr/include/features.h" 3 4
# 1 "/usr/include/bits/predefs.h" 1 3 4
# 314 "/usr/include/features.h" 2 3 4
# 346 "/usr/include/features.h" 3 4
# 1 "/usr/include/sys/cdefs.h" 1 3 4
# 353 "/usr/include/sys/cdefs.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 354 "/usr/include/sys/cdefs.h" 2 3 4
# 347 "/usr/include/features.h" 2 3 4
# 378 "/usr/include/features.h" 3 4
# 1 "/usr/include/gnu/stubs.h" 1 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 5 "/usr/include/gnu/stubs.h" 2 3 4
# 1 "/usr/include/gnu/stubs-32.h" 1 3 4
# 8 "/usr/include/gnu/stubs.h" 2 3 4
# 379 "/usr/include/features.h" 2 3 4
# 26 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 211 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 3 4
typedef unsigned int size_t;
# 323 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 3 4
typedef int wchar_t;
# 34 "/usr/include/stdlib.h" 2 3 4
# 96 "/usr/include/stdlib.h" 3 4
typedef struct
  {
    int quot;
    int rem;
  } div_t;
typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;
__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;
# 140 "/usr/include/stdlib.h" 3 4
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__)) ;
extern double atof (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern int atoi (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern long int atol (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
__extension__ extern long long int atoll (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern double strtod (__const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern float strtof (__const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern long double strtold (__const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern long int strtol (__const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern unsigned long int strtoul (__const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
__extension__
extern long long int strtoq (__const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
__extension__
extern unsigned long long int strtouq (__const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
__extension__
extern long long int strtoll (__const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
__extension__
extern unsigned long long int strtoull (__const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
# 311 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n) __attribute__ ((__nothrow__)) ;
extern long int a64l (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
# 1 "/usr/include/sys/types.h" 1 3 4
# 29 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/bits/types.h" 1 3 4
# 28 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/bits/types.h" 2 3 4
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;
__extension__ typedef long long int __quad_t;
__extension__ typedef unsigned long long int __u_quad_t;
# 131 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/typesizes.h" 1 3 4
# 132 "/usr/include/bits/types.h" 2 3 4
__extension__ typedef __u_quad_t __dev_t;
__extension__ typedef unsigned int __uid_t;
__extension__ typedef unsigned int __gid_t;
__extension__ typedef unsigned long int __ino_t;
__extension__ typedef __u_quad_t __ino64_t;
__extension__ typedef unsigned int __mode_t;
__extension__ typedef unsigned int __nlink_t;
__extension__ typedef long int __off_t;
__extension__ typedef __quad_t __off64_t;
__extension__ typedef int __pid_t;
__extension__ typedef struct { int __val[2]; } __fsid_t;
__extension__ typedef long int __clock_t;
__extension__ typedef unsigned long int __rlim_t;
__extension__ typedef __u_quad_t __rlim64_t;
__extension__ typedef unsigned int __id_t;
__extension__ typedef long int __time_t;
__extension__ typedef unsigned int __useconds_t;
__extension__ typedef long int __suseconds_t;
__extension__ typedef int __daddr_t;
__extension__ typedef long int __swblk_t;
__extension__ typedef int __key_t;
__extension__ typedef int __clockid_t;
__extension__ typedef void * __timer_t;
__extension__ typedef long int __blksize_t;
__extension__ typedef long int __blkcnt_t;
__extension__ typedef __quad_t __blkcnt64_t;
__extension__ typedef unsigned long int __fsblkcnt_t;
__extension__ typedef __u_quad_t __fsblkcnt64_t;
__extension__ typedef unsigned long int __fsfilcnt_t;
__extension__ typedef __u_quad_t __fsfilcnt64_t;
__extension__ typedef int __ssize_t;
typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;
__extension__ typedef int __intptr_t;
__extension__ typedef unsigned int __socklen_t;
# 32 "/usr/include/sys/types.h" 2 3 4
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
# 62 "/usr/include/sys/types.h" 3 4
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __off_t off_t;
# 100 "/usr/include/sys/types.h" 3 4
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __ssize_t ssize_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
# 133 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 74 "/usr/include/time.h" 3 4
typedef __time_t time_t;
# 92 "/usr/include/time.h" 3 4
typedef __clockid_t clockid_t;
# 104 "/usr/include/time.h" 3 4
typedef __timer_t timer_t;
# 134 "/usr/include/sys/types.h" 2 3 4
# 147 "/usr/include/sys/types.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 148 "/usr/include/sys/types.h" 2 3 4
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
# 195 "/usr/include/sys/types.h" 3 4
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));
typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));
typedef int register_t __attribute__ ((__mode__ (__word__)));
# 217 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 37 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/endian.h" 1 3 4
# 38 "/usr/include/endian.h" 2 3 4
# 61 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/byteswap.h" 1 3 4
# 28 "/usr/include/bits/byteswap.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/bits/byteswap.h" 2 3 4
# 62 "/usr/include/endian.h" 2 3 4
# 218 "/usr/include/sys/types.h" 2 3 4
# 1 "/usr/include/sys/select.h" 1 3 4
# 31 "/usr/include/sys/select.h" 3 4
# 1 "/usr/include/bits/select.h" 1 3 4
# 23 "/usr/include/bits/select.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 24 "/usr/include/bits/select.h" 2 3 4
# 32 "/usr/include/sys/select.h" 2 3 4
# 1 "/usr/include/bits/sigset.h" 1 3 4
# 24 "/usr/include/bits/sigset.h" 3 4
typedef int __sig_atomic_t;
typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
# 35 "/usr/include/sys/select.h" 2 3 4
typedef __sigset_t sigset_t;
# 1 "/usr/include/time.h" 1 3 4
# 120 "/usr/include/time.h" 3 4
struct timespec
  {
    __time_t tv_sec;
    long int tv_nsec;
  };
# 45 "/usr/include/sys/select.h" 2 3 4
# 1 "/usr/include/bits/time.h" 1 3 4
# 69 "/usr/include/bits/time.h" 3 4
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
# 47 "/usr/include/sys/select.h" 2 3 4
typedef __suseconds_t suseconds_t;
typedef long int __fd_mask;
# 67 "/usr/include/sys/select.h" 3 4
typedef struct
  {
    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];
  } fd_set;
typedef __fd_mask fd_mask;
# 99 "/usr/include/sys/select.h" 3 4
# 109 "/usr/include/sys/select.h" 3 4
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 121 "/usr/include/sys/select.h" 3 4
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
# 221 "/usr/include/sys/types.h" 2 3 4
# 1 "/usr/include/sys/sysmacros.h" 1 3 4
# 30 "/usr/include/sys/sysmacros.h" 3 4
__extension__
extern unsigned int gnu_dev_major (unsigned long long int __dev)
     __attribute__ ((__nothrow__));
__extension__
extern unsigned int gnu_dev_minor (unsigned long long int __dev)
     __attribute__ ((__nothrow__));
__extension__
extern unsigned long long int gnu_dev_makedev (unsigned int __major,
            unsigned int __minor)
     __attribute__ ((__nothrow__));
# 224 "/usr/include/sys/types.h" 2 3 4
# 235 "/usr/include/sys/types.h" 3 4
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
# 270 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/bits/pthreadtypes.h" 1 3 4
# 23 "/usr/include/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 24 "/usr/include/bits/pthreadtypes.h" 2 3 4
# 50 "/usr/include/bits/pthreadtypes.h" 3 4
typedef unsigned long int pthread_t;
typedef union
{
  char __size[36];
  long int __align;
} pthread_attr_t;
# 67 "/usr/include/bits/pthreadtypes.h" 3 4
typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;
    int __kind;
    unsigned int __nusers;
    __extension__ union
    {
      int __spins;
      __pthread_slist_t __list;
    };
  } __data;
  char __size[24];
  long int __align;
} pthread_mutex_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;
typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
typedef union
{
# 170 "/usr/include/bits/pthreadtypes.h" 3 4
  struct
  {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;
    unsigned char __flags;
    unsigned char __shared;
    unsigned char __pad1;
    unsigned char __pad2;
    int __writer;
  } __data;
  char __size[32];
  long int __align;
} pthread_rwlock_t;
typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union
{
  char __size[20];
  long int __align;
} pthread_barrier_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 271 "/usr/include/sys/types.h" 2 3 4
# 321 "/usr/include/stdlib.h" 2 3 4
extern long int random (void) __attribute__ ((__nothrow__));
extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__));
extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };
extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));
extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int rand (void) __attribute__ ((__nothrow__));
extern void srand (unsigned int __seed) __attribute__ ((__nothrow__));
extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__));
extern double drand48 (void) __attribute__ ((__nothrow__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern long int lrand48 (void) __attribute__ ((__nothrow__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern long int mrand48 (void) __attribute__ ((__nothrow__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern void srand48 (long int __seedval) __attribute__ ((__nothrow__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
  };
extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *malloc (size_t __size) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;
extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;
extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__warn_unused_result__));
extern void free (void *__ptr) __attribute__ ((__nothrow__));
extern void cfree (void *__ptr) __attribute__ ((__nothrow__));
# 1 "/usr/include/alloca.h" 1 3 4
# 25 "/usr/include/alloca.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 26 "/usr/include/alloca.h" 2 3 4
extern void *alloca (size_t __size) __attribute__ ((__nothrow__));
# 498 "/usr/include/stdlib.h" 2 3 4
extern void *valloc (size_t __size) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;
extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern void abort (void) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));
extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 530 "/usr/include/stdlib.h" 3 4
extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern void exit (int __status) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));
# 553 "/usr/include/stdlib.h" 3 4
extern void _Exit (int __status) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));
extern char *getenv (__const char *__name) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern char *__secure_getenv (__const char *__name)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int putenv (char *__string) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int setenv (__const char *__name, __const char *__value, int __replace)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int unsetenv (__const char *__name) __attribute__ ((__nothrow__));
extern int clearenv (void) __attribute__ ((__nothrow__));
# 604 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
# 615 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 637 "/usr/include/stdlib.h" 3 4
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
# 658 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
# 707 "/usr/include/stdlib.h" 3 4
extern int system (__const char *__command) ;
# 729 "/usr/include/stdlib.h" 3 4
extern char *realpath (__const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__)) ;
typedef int (*__compar_fn_t) (__const void *, __const void *);
# 747 "/usr/include/stdlib.h" 3 4
extern void *bsearch (__const void *__key, __const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;
extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
# 766 "/usr/include/stdlib.h" 3 4
extern int abs (int __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
# 802 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3))) ;
extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3))) ;
extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int mblen (__const char *__s, size_t __n) __attribute__ ((__nothrow__)) ;
extern int mbtowc (wchar_t *__restrict __pwc,
     __const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__)) ;
extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__)) ;
extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   __const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__));
extern size_t wcstombs (char *__restrict __s,
   __const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__));
extern int rpmatch (__const char *__response) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
# 907 "/usr/include/stdlib.h" 3 4
extern int posix_openpt (int __oflag) ;
# 942 "/usr/include/stdlib.h" 3 4
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 958 "/usr/include/stdlib.h" 3 4
# 21 "../../../src/plugin-utils.c" 2
# 1 "../../../src/plugin-utils.h" 1
# 23 "../../../src/plugin-utils.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gcc-plugin.h" 1
# 27 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gcc-plugin.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config.h" 1
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/auto-host.h" 1
# 7 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/ansidecl.h" 1
# 9 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config.h" 2
# 28 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gcc-plugin.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 1
# 28 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 102 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;
# 29 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 39 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 149 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 40 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 1 "/usr/include/stdio.h" 1 3 4
# 30 "/usr/include/stdio.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 35 "/usr/include/stdio.h" 2 3 4
# 45 "/usr/include/stdio.h" 3 4
struct _IO_FILE;
typedef struct _IO_FILE FILE;
# 65 "/usr/include/stdio.h" 3 4
typedef struct _IO_FILE __FILE;
# 75 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/libio.h" 1 3 4
# 32 "/usr/include/libio.h" 3 4
# 1 "/usr/include/_G_config.h" 1 3 4
# 15 "/usr/include/_G_config.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 16 "/usr/include/_G_config.h" 2 3 4
# 1 "/usr/include/wchar.h" 1 3 4
# 83 "/usr/include/wchar.h" 3 4
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 21 "/usr/include/_G_config.h" 2 3 4
typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 53 "/usr/include/_G_config.h" 3 4
typedef int _G_int16_t __attribute__ ((__mode__ (__HI__)));
typedef int _G_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int _G_uint16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int _G_uint32_t __attribute__ ((__mode__ (__SI__)));
# 33 "/usr/include/libio.h" 2 3 4
# 170 "/usr/include/libio.h" 3 4
struct _IO_jump_t; struct _IO_FILE;
# 180 "/usr/include/libio.h" 3 4
typedef void _IO_lock_t;
struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  int _pos;
# 203 "/usr/include/libio.h" 3 4
};
enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
# 271 "/usr/include/libio.h" 3 4
struct _IO_FILE {
  int _flags;
  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
# 319 "/usr/include/libio.h" 3 4
  __off64_t _offset;
# 328 "/usr/include/libio.h" 3 4
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
typedef struct _IO_FILE _IO_FILE;
struct _IO_FILE_plus;
extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 364 "/usr/include/libio.h" 3 4
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);
typedef __ssize_t __io_write_fn (void *__cookie, __const char *__buf,
     size_t __n);
typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);
typedef int __io_close_fn (void *__cookie);
typedef __io_read_fn cookie_read_function_t;
typedef __io_write_fn cookie_write_function_t;
typedef __io_seek_fn cookie_seek_function_t;
typedef __io_close_fn cookie_close_function_t;
typedef struct
{
  __io_read_fn *read;
  __io_write_fn *write;
  __io_seek_fn *seek;
  __io_close_fn *close;
} _IO_cookie_io_functions_t;
typedef _IO_cookie_io_functions_t cookie_io_functions_t;
struct _IO_cookie_file;
extern void _IO_cookie_init (struct _IO_cookie_file *__cfile, int __read_write,
        void *__cookie, _IO_cookie_io_functions_t __fns);
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
# 460 "/usr/include/libio.h" 3 4
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__));
extern int _IO_peekc_locked (_IO_FILE *__fp);
extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__));
# 490 "/usr/include/libio.h" 3 4
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);
extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);
extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__));
# 76 "/usr/include/stdio.h" 2 3 4
# 89 "/usr/include/stdio.h" 3 4
typedef _G_fpos_t fpos_t;
# 141 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 142 "/usr/include/stdio.h" 2 3 4
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;
extern int remove (__const char *__filename) __attribute__ ((__nothrow__));
extern int rename (__const char *__old, __const char *__new) __attribute__ ((__nothrow__));
extern int renameat (int __oldfd, __const char *__old, int __newfd,
       __const char *__new) __attribute__ ((__nothrow__));
extern FILE *tmpfile (void) ;
# 186 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__)) ;
extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__)) ;
# 204 "/usr/include/stdio.h" 3 4
extern char *tempnam (__const char *__dir, __const char *__pfx)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;
extern int fclose (FILE *__stream);
extern int fflush (FILE *__stream);
# 229 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 243 "/usr/include/stdio.h" 3 4
extern FILE *fopen (__const char *__restrict __filename,
      __const char *__restrict __modes) ;
extern FILE *freopen (__const char *__restrict __filename,
        __const char *__restrict __modes,
        FILE *__restrict __stream) ;
# 272 "/usr/include/stdio.h" 3 4
# 283 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd, __const char *__modes) __attribute__ ((__nothrow__)) ;
# 296 "/usr/include/stdio.h" 3 4
extern FILE *fmemopen (void *__s, size_t __len, __const char *__modes)
  __attribute__ ((__nothrow__)) ;
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__)) ;
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__));
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__));
extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__));
extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__));
extern int fprintf (FILE *__restrict __stream,
      __const char *__restrict __format, ...);
extern int printf (__const char *__restrict __format, ...);
extern int sprintf (char *__restrict __s,
      __const char *__restrict __format, ...) __attribute__ ((__nothrow__));
extern int vfprintf (FILE *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg);
extern int vprintf (__const char *__restrict __format, __gnuc_va_list __arg);
extern int vsprintf (char *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));
extern int snprintf (char *__restrict __s, size_t __maxlen,
       __const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));
extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));
# 394 "/usr/include/stdio.h" 3 4
extern int vdprintf (int __fd, __const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, __const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));
extern int fscanf (FILE *__restrict __stream,
     __const char *__restrict __format, ...) ;
extern int scanf (__const char *__restrict __format, ...) ;
extern int sscanf (__const char *__restrict __s,
     __const char *__restrict __format, ...) __attribute__ ((__nothrow__));
# 425 "/usr/include/stdio.h" 3 4
extern int fscanf (FILE *__restrict __stream, __const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf") ;
extern int scanf (__const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf") ;
extern int sscanf (__const char *__restrict __s, __const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__));
# 445 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (__const char *__restrict __s,
      __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
# 476 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (__const char *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf")
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
# 504 "/usr/include/stdio.h" 3 4
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);
extern int getchar (void);
# 532 "/usr/include/stdio.h" 3 4
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 543 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);
extern int putchar (int __c);
# 576 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);
extern int getw (FILE *__stream);
extern int putw (int __w, FILE *__stream);
extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;
extern char *gets (char *__s) ;
# 638 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char **__restrict __lineptr,
          size_t *__restrict __n, int __delimiter,
          FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
        size_t *__restrict __n, int __delimiter,
        FILE *__restrict __stream) ;
extern __ssize_t getline (char **__restrict __lineptr,
       size_t *__restrict __n,
       FILE *__restrict __stream) ;
extern int fputs (__const char *__restrict __s, FILE *__restrict __stream);
extern int puts (__const char *__s);
extern int ungetc (int __c, FILE *__stream);
extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite (__const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);
# 710 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (__const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);
extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream) ;
extern void rewind (FILE *__stream);
# 746 "/usr/include/stdio.h" 3 4
extern int fseeko (FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello (FILE *__stream) ;
# 765 "/usr/include/stdio.h" 3 4
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
extern int fsetpos (FILE *__stream, __const fpos_t *__pos);
# 788 "/usr/include/stdio.h" 3 4
# 797 "/usr/include/stdio.h" 3 4
extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__));
extern int feof (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int ferror (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern void perror (__const char *__s);
# 1 "/usr/include/bits/sys_errlist.h" 1 3 4
# 27 "/usr/include/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern __const char *__const sys_errlist[];
# 827 "/usr/include/stdio.h" 2 3 4
extern int fileno (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
# 846 "/usr/include/stdio.h" 3 4
extern FILE *popen (__const char *__command, __const char *__modes) ;
extern int pclose (FILE *__stream);
extern char *ctermid (char *__s) __attribute__ ((__nothrow__));
# 886 "/usr/include/stdio.h" 3 4
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__));
extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__));
# 916 "/usr/include/stdio.h" 3 4
# 43 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 196 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/safe-ctype.h" 1
# 57 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/safe-ctype.h"
enum {
  _sch_isblank = 0x0001,
  _sch_iscntrl = 0x0002,
  _sch_isdigit = 0x0004,
  _sch_islower = 0x0008,
  _sch_isprint = 0x0010,
  _sch_ispunct = 0x0020,
  _sch_isspace = 0x0040,
  _sch_isupper = 0x0080,
  _sch_isxdigit = 0x0100,
  _sch_isidst = 0x0200,
  _sch_isvsp = 0x0400,
  _sch_isnvsp = 0x0800,
  _sch_isalpha = _sch_isupper|_sch_islower,
  _sch_isalnum = _sch_isalpha|_sch_isdigit,
  _sch_isidnum = _sch_isidst|_sch_isdigit,
  _sch_isgraph = _sch_isalnum|_sch_ispunct,
  _sch_iscppsp = _sch_isvsp|_sch_isnvsp,
  _sch_isbasic = _sch_isprint|_sch_iscppsp
};
extern const unsigned short _sch_istable[256];
# 110 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/safe-ctype.h"
extern const unsigned char _sch_toupper[256];
extern const unsigned char _sch_tolower[256];
# 122 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/safe-ctype.h"
# 1 "/usr/include/ctype.h" 1 3 4
# 30 "/usr/include/ctype.h" 3 4
# 48 "/usr/include/ctype.h" 3 4
enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
# 81 "/usr/include/ctype.h" 3 4
extern __const unsigned short int **__ctype_b_loc (void)
     __attribute__ ((__nothrow__)) __attribute__ ((__const));
extern __const __int32_t **__ctype_tolower_loc (void)
     __attribute__ ((__nothrow__)) __attribute__ ((__const));
extern __const __int32_t **__ctype_toupper_loc (void)
     __attribute__ ((__nothrow__)) __attribute__ ((__const));
# 96 "/usr/include/ctype.h" 3 4
extern int isalnum (int) __attribute__ ((__nothrow__));
extern int isalpha (int) __attribute__ ((__nothrow__));
extern int iscntrl (int) __attribute__ ((__nothrow__));
extern int isdigit (int) __attribute__ ((__nothrow__));
extern int islower (int) __attribute__ ((__nothrow__));
extern int isgraph (int) __attribute__ ((__nothrow__));
extern int isprint (int) __attribute__ ((__nothrow__));
extern int ispunct (int) __attribute__ ((__nothrow__));
extern int isspace (int) __attribute__ ((__nothrow__));
extern int isupper (int) __attribute__ ((__nothrow__));
extern int isxdigit (int) __attribute__ ((__nothrow__));
extern int tolower (int __c) __attribute__ ((__nothrow__));
extern int toupper (int __c) __attribute__ ((__nothrow__));
extern int isblank (int) __attribute__ ((__nothrow__));
# 142 "/usr/include/ctype.h" 3 4
extern int isascii (int __c) __attribute__ ((__nothrow__));
extern int toascii (int __c) __attribute__ ((__nothrow__));
extern int _toupper (int) __attribute__ ((__nothrow__));
extern int _tolower (int) __attribute__ ((__nothrow__));
# 233 "/usr/include/ctype.h" 3 4
# 1 "/usr/include/xlocale.h" 1 3 4
# 28 "/usr/include/xlocale.h" 3 4
typedef struct __locale_struct
{
  struct locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
} *__locale_t;
typedef __locale_t locale_t;
# 234 "/usr/include/ctype.h" 2 3 4
# 247 "/usr/include/ctype.h" 3 4
extern int isalnum_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isalpha_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int iscntrl_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isdigit_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int islower_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isgraph_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isprint_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int ispunct_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isspace_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isupper_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isxdigit_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isblank_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int __tolower_l (int __c, __locale_t __l) __attribute__ ((__nothrow__));
extern int tolower_l (int __c, __locale_t __l) __attribute__ ((__nothrow__));
extern int __toupper_l (int __c, __locale_t __l) __attribute__ ((__nothrow__));
extern int toupper_l (int __c, __locale_t __l) __attribute__ ((__nothrow__));
# 323 "/usr/include/ctype.h" 3 4
# 123 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/safe-ctype.h" 2
# 197 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 1 "/usr/include/errno.h" 1 3 4
# 32 "/usr/include/errno.h" 3 4
# 1 "/usr/include/bits/errno.h" 1 3 4
# 25 "/usr/include/bits/errno.h" 3 4
# 1 "/usr/include/linux/errno.h" 1 3 4
# 1 "/usr/include/asm/errno.h" 1 3 4
# 1 "/usr/include/asm-generic/errno.h" 1 3 4
# 1 "/usr/include/asm-generic/errno-base.h" 1 3 4
# 5 "/usr/include/asm-generic/errno.h" 2 3 4
# 1 "/usr/include/asm/errno.h" 2 3 4
# 5 "/usr/include/linux/errno.h" 2 3 4
# 26 "/usr/include/bits/errno.h" 2 3 4
# 43 "/usr/include/bits/errno.h" 3 4
extern int *__errno_location (void) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
# 37 "/usr/include/errno.h" 2 3 4
# 59 "/usr/include/errno.h" 3 4
# 201 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 215 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
# 1 "/usr/include/string.h" 1 3 4
# 28 "/usr/include/string.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 34 "/usr/include/string.h" 2 3 4
extern void *memcpy (void *__restrict __dest,
       __const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memmove (void *__dest, __const void *__src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memccpy (void *__restrict __dest, __const void *__restrict __src,
        int __c, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int memcmp (__const void *__s1, __const void *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 94 "/usr/include/string.h" 3 4
extern void *memchr (__const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 125 "/usr/include/string.h" 3 4
extern char *strcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncpy (char *__restrict __dest,
        __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strcat (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncat (char *__restrict __dest, __const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncmp (__const char *__s1, __const char *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcoll (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strxfrm (char *__restrict __dest,
         __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
# 164 "/usr/include/string.h" 3 4
extern int strcoll_l (__const char *__s1, __const char *__s2, __locale_t __l)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern size_t strxfrm_l (char *__dest, __const char *__src, size_t __n,
    __locale_t __l) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));
extern char *strdup (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strndup (__const char *__string, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 208 "/usr/include/string.h" 3 4
# 233 "/usr/include/string.h" 3 4
extern char *strchr (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 260 "/usr/include/string.h" 3 4
extern char *strrchr (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 279 "/usr/include/string.h" 3 4
extern size_t strcspn (__const char *__s, __const char *__reject)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strspn (__const char *__s, __const char *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 312 "/usr/include/string.h" 3 4
extern char *strpbrk (__const char *__s, __const char *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 340 "/usr/include/string.h" 3 4
extern char *strstr (__const char *__haystack, __const char *__needle)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strtok (char *__restrict __s, __const char *__restrict __delim)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern char *__strtok_r (char *__restrict __s,
    __const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));
extern char *strtok_r (char *__restrict __s, __const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));
# 395 "/usr/include/string.h" 3 4
extern size_t strlen (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern size_t strnlen (__const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strerror (int __errnum) __attribute__ ((__nothrow__));
# 425 "/usr/include/string.h" 3 4
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
# 443 "/usr/include/string.h" 3 4
extern char *strerror_l (int __errnum, __locale_t __l) __attribute__ ((__nothrow__));
extern void __bzero (void *__s, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern void bcopy (__const void *__src, void *__dest, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int bcmp (__const void *__s1, __const void *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 487 "/usr/include/string.h" 3 4
extern char *index (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 515 "/usr/include/string.h" 3 4
extern char *rindex (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern int ffs (int __i) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
# 534 "/usr/include/string.h" 3 4
extern int strcasecmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncasecmp (__const char *__s1, __const char *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 557 "/usr/include/string.h" 3 4
extern char *strsep (char **__restrict __stringp,
       __const char *__restrict __delim)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strsignal (int __sig) __attribute__ ((__nothrow__));
extern char *__stpcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *__stpncpy (char *__restrict __dest,
   __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
# 644 "/usr/include/string.h" 3 4
# 216 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 1 "/usr/include/strings.h" 1 3 4
# 217 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 253 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
# 1 "/usr/include/unistd.h" 1 3 4
# 28 "/usr/include/unistd.h" 3 4
# 203 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/bits/posix_opt.h" 1 3 4
# 204 "/usr/include/unistd.h" 2 3 4
# 227 "/usr/include/unistd.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 228 "/usr/include/unistd.h" 2 3 4
# 256 "/usr/include/unistd.h" 3 4
typedef __useconds_t useconds_t;
# 268 "/usr/include/unistd.h" 3 4
typedef __intptr_t intptr_t;
typedef __socklen_t socklen_t;
# 288 "/usr/include/unistd.h" 3 4
extern int access (__const char *__name, int __type) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 305 "/usr/include/unistd.h" 3 4
extern int faccessat (int __fd, __const char *__file, int __type, int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2))) ;
# 331 "/usr/include/unistd.h" 3 4
extern __off_t lseek (int __fd, __off_t __offset, int __whence) __attribute__ ((__nothrow__));
# 350 "/usr/include/unistd.h" 3 4
extern int close (int __fd);
extern ssize_t read (int __fd, void *__buf, size_t __nbytes) ;
extern ssize_t write (int __fd, __const void *__buf, size_t __n) ;
# 414 "/usr/include/unistd.h" 3 4
extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__)) ;
# 429 "/usr/include/unistd.h" 3 4
extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__));
# 441 "/usr/include/unistd.h" 3 4
extern unsigned int sleep (unsigned int __seconds);
extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     __attribute__ ((__nothrow__));
extern int usleep (__useconds_t __useconds);
# 465 "/usr/include/unistd.h" 3 4
extern int pause (void);
extern int chown (__const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__)) ;
extern int lchown (__const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchownat (int __fd, __const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2))) ;
extern int chdir (__const char *__path) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchdir (int __fd) __attribute__ ((__nothrow__)) ;
# 507 "/usr/include/unistd.h" 3 4
extern char *getcwd (char *__buf, size_t __size) __attribute__ ((__nothrow__)) ;
# 520 "/usr/include/unistd.h" 3 4
extern char *getwd (char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__)) ;
extern int dup (int __fd) __attribute__ ((__nothrow__)) ;
extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__));
# 538 "/usr/include/unistd.h" 3 4
extern char **__environ;
extern int execve (__const char *__path, char *__const __argv[],
     char *__const __envp[]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int fexecve (int __fd, char *__const __argv[], char *__const __envp[])
     __attribute__ ((__nothrow__));
extern int execv (__const char *__path, char *__const __argv[])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int execle (__const char *__path, __const char *__arg, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int execl (__const char *__path, __const char *__arg, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int execvp (__const char *__file, char *__const __argv[])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int execlp (__const char *__file, __const char *__arg, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 593 "/usr/include/unistd.h" 3 4
extern int nice (int __inc) __attribute__ ((__nothrow__)) ;
extern void _exit (int __status) __attribute__ ((__noreturn__));
# 1 "/usr/include/bits/confname.h" 1 3 4
# 26 "/usr/include/bits/confname.h" 3 4
enum
  {
    _PC_LINK_MAX,
    _PC_MAX_CANON,
    _PC_MAX_INPUT,
    _PC_NAME_MAX,
    _PC_PATH_MAX,
    _PC_PIPE_BUF,
    _PC_CHOWN_RESTRICTED,
    _PC_NO_TRUNC,
    _PC_VDISABLE,
    _PC_SYNC_IO,
    _PC_ASYNC_IO,
    _PC_PRIO_IO,
    _PC_SOCK_MAXBUF,
    _PC_FILESIZEBITS,
    _PC_REC_INCR_XFER_SIZE,
    _PC_REC_MAX_XFER_SIZE,
    _PC_REC_MIN_XFER_SIZE,
    _PC_REC_XFER_ALIGN,
    _PC_ALLOC_SIZE_MIN,
    _PC_SYMLINK_MAX,
    _PC_2_SYMLINKS
  };
enum
  {
    _SC_ARG_MAX,
    _SC_CHILD_MAX,
    _SC_CLK_TCK,
    _SC_NGROUPS_MAX,
    _SC_OPEN_MAX,
    _SC_STREAM_MAX,
    _SC_TZNAME_MAX,
    _SC_JOB_CONTROL,
    _SC_SAVED_IDS,
    _SC_REALTIME_SIGNALS,
    _SC_PRIORITY_SCHEDULING,
    _SC_TIMERS,
    _SC_ASYNCHRONOUS_IO,
    _SC_PRIORITIZED_IO,
    _SC_SYNCHRONIZED_IO,
    _SC_FSYNC,
    _SC_MAPPED_FILES,
    _SC_MEMLOCK,
    _SC_MEMLOCK_RANGE,
    _SC_MEMORY_PROTECTION,
    _SC_MESSAGE_PASSING,
    _SC_SEMAPHORES,
    _SC_SHARED_MEMORY_OBJECTS,
    _SC_AIO_LISTIO_MAX,
    _SC_AIO_MAX,
    _SC_AIO_PRIO_DELTA_MAX,
    _SC_DELAYTIMER_MAX,
    _SC_MQ_OPEN_MAX,
    _SC_MQ_PRIO_MAX,
    _SC_VERSION,
    _SC_PAGESIZE,
    _SC_RTSIG_MAX,
    _SC_SEM_NSEMS_MAX,
    _SC_SEM_VALUE_MAX,
    _SC_SIGQUEUE_MAX,
    _SC_TIMER_MAX,
    _SC_BC_BASE_MAX,
    _SC_BC_DIM_MAX,
    _SC_BC_SCALE_MAX,
    _SC_BC_STRING_MAX,
    _SC_COLL_WEIGHTS_MAX,
    _SC_EQUIV_CLASS_MAX,
    _SC_EXPR_NEST_MAX,
    _SC_LINE_MAX,
    _SC_RE_DUP_MAX,
    _SC_CHARCLASS_NAME_MAX,
    _SC_2_VERSION,
    _SC_2_C_BIND,
    _SC_2_C_DEV,
    _SC_2_FORT_DEV,
    _SC_2_FORT_RUN,
    _SC_2_SW_DEV,
    _SC_2_LOCALEDEF,
    _SC_PII,
    _SC_PII_XTI,
    _SC_PII_SOCKET,
    _SC_PII_INTERNET,
    _SC_PII_OSI,
    _SC_POLL,
    _SC_SELECT,
    _SC_UIO_MAXIOV,
    _SC_IOV_MAX = _SC_UIO_MAXIOV,
    _SC_PII_INTERNET_STREAM,
    _SC_PII_INTERNET_DGRAM,
    _SC_PII_OSI_COTS,
    _SC_PII_OSI_CLTS,
    _SC_PII_OSI_M,
    _SC_T_IOV_MAX,
    _SC_THREADS,
    _SC_THREAD_SAFE_FUNCTIONS,
    _SC_GETGR_R_SIZE_MAX,
    _SC_GETPW_R_SIZE_MAX,
    _SC_LOGIN_NAME_MAX,
    _SC_TTY_NAME_MAX,
    _SC_THREAD_DESTRUCTOR_ITERATIONS,
    _SC_THREAD_KEYS_MAX,
    _SC_THREAD_STACK_MIN,
    _SC_THREAD_THREADS_MAX,
    _SC_THREAD_ATTR_STACKADDR,
    _SC_THREAD_ATTR_STACKSIZE,
    _SC_THREAD_PRIORITY_SCHEDULING,
    _SC_THREAD_PRIO_INHERIT,
    _SC_THREAD_PRIO_PROTECT,
    _SC_THREAD_PROCESS_SHARED,
    _SC_NPROCESSORS_CONF,
    _SC_NPROCESSORS_ONLN,
    _SC_PHYS_PAGES,
    _SC_AVPHYS_PAGES,
    _SC_ATEXIT_MAX,
    _SC_PASS_MAX,
    _SC_XOPEN_VERSION,
    _SC_XOPEN_XCU_VERSION,
    _SC_XOPEN_UNIX,
    _SC_XOPEN_CRYPT,
    _SC_XOPEN_ENH_I18N,
    _SC_XOPEN_SHM,
    _SC_2_CHAR_TERM,
    _SC_2_C_VERSION,
    _SC_2_UPE,
    _SC_XOPEN_XPG2,
    _SC_XOPEN_XPG3,
    _SC_XOPEN_XPG4,
    _SC_CHAR_BIT,
    _SC_CHAR_MAX,
    _SC_CHAR_MIN,
    _SC_INT_MAX,
    _SC_INT_MIN,
    _SC_LONG_BIT,
    _SC_WORD_BIT,
    _SC_MB_LEN_MAX,
    _SC_NZERO,
    _SC_SSIZE_MAX,
    _SC_SCHAR_MAX,
    _SC_SCHAR_MIN,
    _SC_SHRT_MAX,
    _SC_SHRT_MIN,
    _SC_UCHAR_MAX,
    _SC_UINT_MAX,
    _SC_ULONG_MAX,
    _SC_USHRT_MAX,
    _SC_NL_ARGMAX,
    _SC_NL_LANGMAX,
    _SC_NL_MSGMAX,
    _SC_NL_NMAX,
    _SC_NL_SETMAX,
    _SC_NL_TEXTMAX,
    _SC_XBS5_ILP32_OFF32,
    _SC_XBS5_ILP32_OFFBIG,
    _SC_XBS5_LP64_OFF64,
    _SC_XBS5_LPBIG_OFFBIG,
    _SC_XOPEN_LEGACY,
    _SC_XOPEN_REALTIME,
    _SC_XOPEN_REALTIME_THREADS,
    _SC_ADVISORY_INFO,
    _SC_BARRIERS,
    _SC_BASE,
    _SC_C_LANG_SUPPORT,
    _SC_C_LANG_SUPPORT_R,
    _SC_CLOCK_SELECTION,
    _SC_CPUTIME,
    _SC_THREAD_CPUTIME,
    _SC_DEVICE_IO,
    _SC_DEVICE_SPECIFIC,
    _SC_DEVICE_SPECIFIC_R,
    _SC_FD_MGMT,
    _SC_FIFO,
    _SC_PIPE,
    _SC_FILE_ATTRIBUTES,
    _SC_FILE_LOCKING,
    _SC_FILE_SYSTEM,
    _SC_MONOTONIC_CLOCK,
    _SC_MULTI_PROCESS,
    _SC_SINGLE_PROCESS,
    _SC_NETWORKING,
    _SC_READER_WRITER_LOCKS,
    _SC_SPIN_LOCKS,
    _SC_REGEXP,
    _SC_REGEX_VERSION,
    _SC_SHELL,
    _SC_SIGNALS,
    _SC_SPAWN,
    _SC_SPORADIC_SERVER,
    _SC_THREAD_SPORADIC_SERVER,
    _SC_SYSTEM_DATABASE,
    _SC_SYSTEM_DATABASE_R,
    _SC_TIMEOUTS,
    _SC_TYPED_MEMORY_OBJECTS,
    _SC_USER_GROUPS,
    _SC_USER_GROUPS_R,
    _SC_2_PBS,
    _SC_2_PBS_ACCOUNTING,
    _SC_2_PBS_LOCATE,
    _SC_2_PBS_MESSAGE,
    _SC_2_PBS_TRACK,
    _SC_SYMLOOP_MAX,
    _SC_STREAMS,
    _SC_2_PBS_CHECKPOINT,
    _SC_V6_ILP32_OFF32,
    _SC_V6_ILP32_OFFBIG,
    _SC_V6_LP64_OFF64,
    _SC_V6_LPBIG_OFFBIG,
    _SC_HOST_NAME_MAX,
    _SC_TRACE,
    _SC_TRACE_EVENT_FILTER,
    _SC_TRACE_INHERIT,
    _SC_TRACE_LOG,
    _SC_LEVEL1_ICACHE_SIZE,
    _SC_LEVEL1_ICACHE_ASSOC,
    _SC_LEVEL1_ICACHE_LINESIZE,
    _SC_LEVEL1_DCACHE_SIZE,
    _SC_LEVEL1_DCACHE_ASSOC,
    _SC_LEVEL1_DCACHE_LINESIZE,
    _SC_LEVEL2_CACHE_SIZE,
    _SC_LEVEL2_CACHE_ASSOC,
    _SC_LEVEL2_CACHE_LINESIZE,
    _SC_LEVEL3_CACHE_SIZE,
    _SC_LEVEL3_CACHE_ASSOC,
    _SC_LEVEL3_CACHE_LINESIZE,
    _SC_LEVEL4_CACHE_SIZE,
    _SC_LEVEL4_CACHE_ASSOC,
    _SC_LEVEL4_CACHE_LINESIZE,
    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,
    _SC_RAW_SOCKETS,
    _SC_V7_ILP32_OFF32,
    _SC_V7_ILP32_OFFBIG,
    _SC_V7_LP64_OFF64,
    _SC_V7_LPBIG_OFFBIG,
    _SC_SS_REPL_MAX,
    _SC_TRACE_EVENT_NAME_MAX,
    _SC_TRACE_NAME_MAX,
    _SC_TRACE_SYS_MAX,
    _SC_TRACE_USER_EVENT_MAX,
    _SC_XOPEN_STREAMS,
    _SC_THREAD_ROBUST_PRIO_INHERIT,
    _SC_THREAD_ROBUST_PRIO_PROTECT
  };
enum
  {
    _CS_PATH,
    _CS_V6_WIDTH_RESTRICTED_ENVS,
    _CS_GNU_LIBC_VERSION,
    _CS_GNU_LIBPTHREAD_VERSION,
    _CS_V5_WIDTH_RESTRICTED_ENVS,
    _CS_V7_WIDTH_RESTRICTED_ENVS,
    _CS_LFS_CFLAGS = 1000,
    _CS_LFS_LDFLAGS,
    _CS_LFS_LIBS,
    _CS_LFS_LINTFLAGS,
    _CS_LFS64_CFLAGS,
    _CS_LFS64_LDFLAGS,
    _CS_LFS64_LIBS,
    _CS_LFS64_LINTFLAGS,
    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS,
    _CS_XBS5_ILP32_OFF32_LIBS,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LIBS,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,
    _CS_XBS5_LP64_OFF64_CFLAGS,
    _CS_XBS5_LP64_OFF64_LDFLAGS,
    _CS_XBS5_LP64_OFF64_LIBS,
    _CS_XBS5_LP64_OFF64_LINTFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LIBS,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LIBS,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LIBS,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LIBS,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LIBS,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS
  };
# 605 "/usr/include/unistd.h" 2 3 4
extern long int pathconf (__const char *__path, int __name)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__));
extern long int sysconf (int __name) __attribute__ ((__nothrow__));
extern size_t confstr (int __name, char *__buf, size_t __len) __attribute__ ((__nothrow__));
extern __pid_t getpid (void) __attribute__ ((__nothrow__));
extern __pid_t getppid (void) __attribute__ ((__nothrow__));
extern __pid_t getpgrp (void) __attribute__ ((__nothrow__));
# 641 "/usr/include/unistd.h" 3 4
extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__));
# 650 "/usr/include/unistd.h" 3 4
extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__));
# 667 "/usr/include/unistd.h" 3 4
extern int setpgrp (void) __attribute__ ((__nothrow__));
# 684 "/usr/include/unistd.h" 3 4
extern __pid_t setsid (void) __attribute__ ((__nothrow__));
extern __uid_t getuid (void) __attribute__ ((__nothrow__));
extern __uid_t geteuid (void) __attribute__ ((__nothrow__));
extern __gid_t getgid (void) __attribute__ ((__nothrow__));
extern __gid_t getegid (void) __attribute__ ((__nothrow__));
extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__)) ;
# 717 "/usr/include/unistd.h" 3 4
extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__));
extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__));
extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__));
extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__));
extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__));
extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__));
# 773 "/usr/include/unistd.h" 3 4
extern __pid_t fork (void) __attribute__ ((__nothrow__));
extern __pid_t vfork (void) __attribute__ ((__nothrow__));
extern char *ttyname (int __fd) __attribute__ ((__nothrow__));
extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2))) ;
extern int isatty (int __fd) __attribute__ ((__nothrow__));
extern int ttyslot (void) __attribute__ ((__nothrow__));
extern int link (__const char *__from, __const char *__to)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern int linkat (int __fromfd, __const char *__from, int __tofd,
     __const char *__to, int __flags)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4))) ;
extern int symlink (__const char *__from, __const char *__to)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern ssize_t readlink (__const char *__restrict __path,
    char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern int symlinkat (__const char *__from, int __tofd,
        __const char *__to) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3))) ;
extern ssize_t readlinkat (int __fd, __const char *__restrict __path,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3))) ;
extern int unlink (__const char *__name) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int unlinkat (int __fd, __const char *__name, int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int rmdir (__const char *__path) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__));
extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__));
extern char *getlogin (void);
extern int getlogin_r (char *__name, size_t __name_len) __attribute__ ((__nonnull__ (1)));
extern int setlogin (__const char *__name) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 887 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/getopt.h" 1 3 4
# 59 "/usr/include/getopt.h" 3 4
extern char *optarg;
# 73 "/usr/include/getopt.h" 3 4
extern int optind;
extern int opterr;
extern int optopt;
# 152 "/usr/include/getopt.h" 3 4
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       __attribute__ ((__nothrow__));
# 888 "/usr/include/unistd.h" 2 3 4
extern int gethostname (char *__name, size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int sethostname (__const char *__name, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int sethostid (long int __id) __attribute__ ((__nothrow__)) ;
extern int getdomainname (char *__name, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int setdomainname (__const char *__name, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int vhangup (void) __attribute__ ((__nothrow__));
extern int revoke (__const char *__file) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int profil (unsigned short int *__sample_buffer, size_t __size,
     size_t __offset, unsigned int __scale)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int acct (__const char *__name) __attribute__ ((__nothrow__));
extern char *getusershell (void) __attribute__ ((__nothrow__));
extern void endusershell (void) __attribute__ ((__nothrow__));
extern void setusershell (void) __attribute__ ((__nothrow__));
extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__)) ;
extern int chroot (__const char *__path) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern char *getpass (__const char *__prompt) __attribute__ ((__nonnull__ (1)));
# 973 "/usr/include/unistd.h" 3 4
extern int fsync (int __fd);
extern long int gethostid (void);
extern void sync (void) __attribute__ ((__nothrow__));
extern int getpagesize (void) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int getdtablesize (void) __attribute__ ((__nothrow__));
extern int truncate (__const char *__file, __off_t __length)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
# 1020 "/usr/include/unistd.h" 3 4
extern int ftruncate (int __fd, __off_t __length) __attribute__ ((__nothrow__)) ;
# 1040 "/usr/include/unistd.h" 3 4
extern int brk (void *__addr) __attribute__ ((__nothrow__)) ;
extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__));
# 1061 "/usr/include/unistd.h" 3 4
extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__));
# 1084 "/usr/include/unistd.h" 3 4
extern int lockf (int __fd, int __cmd, __off_t __len) ;
# 1115 "/usr/include/unistd.h" 3 4
extern int fdatasync (int __fildes);
# 1153 "/usr/include/unistd.h" 3 4
# 254 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 1 "/usr/include/sys/param.h" 1 3 4
# 26 "/usr/include/sys/param.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include-fixed/limits.h" 1 3 4
# 11 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include-fixed/limits.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include-fixed/syslimits.h" 1 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include-fixed/limits.h" 1 3 4
# 122 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include-fixed/limits.h" 3 4
# 1 "/usr/include/limits.h" 1 3 4
# 145 "/usr/include/limits.h" 3 4
# 1 "/usr/include/bits/posix1_lim.h" 1 3 4
# 157 "/usr/include/bits/posix1_lim.h" 3 4
# 1 "/usr/include/bits/local_lim.h" 1 3 4
# 39 "/usr/include/bits/local_lim.h" 3 4
# 1 "/usr/include/linux/limits.h" 1 3 4
# 40 "/usr/include/bits/local_lim.h" 2 3 4
# 158 "/usr/include/bits/posix1_lim.h" 2 3 4
# 146 "/usr/include/limits.h" 2 3 4
# 1 "/usr/include/bits/posix2_lim.h" 1 3 4
# 150 "/usr/include/limits.h" 2 3 4
# 123 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include-fixed/limits.h" 2 3 4
# 8 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include-fixed/syslimits.h" 2 3 4
# 12 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include-fixed/limits.h" 2 3 4
# 27 "/usr/include/sys/param.h" 2 3 4
# 1 "/usr/include/linux/param.h" 1 3 4
# 1 "/usr/include/asm/param.h" 1 3 4
# 1 "/usr/include/asm-generic/param.h" 1 3 4
# 1 "/usr/include/asm/param.h" 2 3 4
# 5 "/usr/include/linux/param.h" 2 3 4
# 29 "/usr/include/sys/param.h" 2 3 4
# 258 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include-fixed/limits.h" 1 3 4
# 264 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/hwint.h" 1
# 180 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/hwint.h"
static __inline__ int
clz_hwi (unsigned long long x)
{
  if (x == 0)
    return (8 * 8);
  return __builtin_clzll (x);
}
static __inline__ int
ctz_hwi (unsigned long long x)
{
  if (x == 0)
    return (8 * 8);
  return __builtin_ctzll (x);
}
static __inline__ int
ffs_hwi (unsigned long long x)
{
  return __builtin_ffsll (x);
}
static __inline__ int
floor_log2 (unsigned long long x)
{
  return (8 * 8) - 1 - clz_hwi (x);
}
static __inline__ int
exact_log2 (unsigned long long x)
{
  return x == (x & -x) && x ? ctz_hwi (x) : -1;
}
extern long long abs_hwi (long long);
extern unsigned long long absu_hwi (long long);
extern long long gcd (long long, long long);
extern long long pos_mul_hwi (long long, long long);
extern long long mul_hwi (long long, long long);
extern long long least_common_multiple (long long, long long);
# 268 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 297 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
# 1 "/usr/include/sys/time.h" 1 3 4
# 27 "/usr/include/sys/time.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 28 "/usr/include/sys/time.h" 2 3 4
# 1 "/usr/include/bits/time.h" 1 3 4
# 30 "/usr/include/sys/time.h" 2 3 4
# 39 "/usr/include/sys/time.h" 3 4
# 57 "/usr/include/sys/time.h" 3 4
struct timezone
  {
    int tz_minuteswest;
    int tz_dsttime;
  };
typedef struct timezone *__restrict __timezone_ptr_t;
# 73 "/usr/include/sys/time.h" 3 4
extern int gettimeofday (struct timeval *__restrict __tv,
    __timezone_ptr_t __tz) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int settimeofday (__const struct timeval *__tv,
    __const struct timezone *__tz)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int adjtime (__const struct timeval *__delta,
      struct timeval *__olddelta) __attribute__ ((__nothrow__));
enum __itimer_which
  {
    ITIMER_REAL = 0,
    ITIMER_VIRTUAL = 1,
    ITIMER_PROF = 2
  };
struct itimerval
  {
    struct timeval it_interval;
    struct timeval it_value;
  };
typedef int __itimer_which_t;
extern int getitimer (__itimer_which_t __which,
        struct itimerval *__value) __attribute__ ((__nothrow__));
extern int setitimer (__itimer_which_t __which,
        __const struct itimerval *__restrict __new,
        struct itimerval *__restrict __old) __attribute__ ((__nothrow__));
extern int utimes (__const char *__file, __const struct timeval __tvp[2])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int lutimes (__const char *__file, __const struct timeval __tvp[2])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int futimes (int __fd, __const struct timeval __tvp[2]) __attribute__ ((__nothrow__));
# 191 "/usr/include/sys/time.h" 3 4
# 298 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 1 "/usr/include/time.h" 1 3 4
# 30 "/usr/include/time.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 39 "/usr/include/time.h" 2 3 4
# 1 "/usr/include/bits/time.h" 1 3 4
# 43 "/usr/include/time.h" 2 3 4
# 58 "/usr/include/time.h" 3 4
typedef __clock_t clock_t;
# 131 "/usr/include/time.h" 3 4
struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long int tm_gmtoff;
  __const char *tm_zone;
};
struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };
struct sigevent;
# 180 "/usr/include/time.h" 3 4
extern clock_t clock (void) __attribute__ ((__nothrow__));
extern time_t time (time_t *__timer) __attribute__ ((__nothrow__));
extern double difftime (time_t __time1, time_t __time0)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__));
extern size_t strftime (char *__restrict __s, size_t __maxsize,
   __const char *__restrict __format,
   __const struct tm *__restrict __tp) __attribute__ ((__nothrow__));
# 217 "/usr/include/time.h" 3 4
extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     __const char *__restrict __format,
     __const struct tm *__restrict __tp,
     __locale_t __loc) __attribute__ ((__nothrow__));
# 230 "/usr/include/time.h" 3 4
extern struct tm *gmtime (__const time_t *__timer) __attribute__ ((__nothrow__));
extern struct tm *localtime (__const time_t *__timer) __attribute__ ((__nothrow__));
extern struct tm *gmtime_r (__const time_t *__restrict __timer,
       struct tm *__restrict __tp) __attribute__ ((__nothrow__));
extern struct tm *localtime_r (__const time_t *__restrict __timer,
          struct tm *__restrict __tp) __attribute__ ((__nothrow__));
extern char *asctime (__const struct tm *__tp) __attribute__ ((__nothrow__));
extern char *ctime (__const time_t *__timer) __attribute__ ((__nothrow__));
extern char *asctime_r (__const struct tm *__restrict __tp,
   char *__restrict __buf) __attribute__ ((__nothrow__));
extern char *ctime_r (__const time_t *__restrict __timer,
        char *__restrict __buf) __attribute__ ((__nothrow__));
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;
extern char *tzname[2];
extern void tzset (void) __attribute__ ((__nothrow__));
extern int daylight;
extern long int timezone;
extern int stime (__const time_t *__when) __attribute__ ((__nothrow__));
# 313 "/usr/include/time.h" 3 4
extern time_t timegm (struct tm *__tp) __attribute__ ((__nothrow__));
extern time_t timelocal (struct tm *__tp) __attribute__ ((__nothrow__));
extern int dysize (int __year) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
# 328 "/usr/include/time.h" 3 4
extern int nanosleep (__const struct timespec *__requested_time,
        struct timespec *__remaining);
extern int clock_getres (clockid_t __clock_id, struct timespec *__res) __attribute__ ((__nothrow__));
extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) __attribute__ ((__nothrow__));
extern int clock_settime (clockid_t __clock_id, __const struct timespec *__tp)
     __attribute__ ((__nothrow__));
extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       __const struct timespec *__req,
       struct timespec *__rem);
extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) __attribute__ ((__nothrow__));
extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,
    timer_t *__restrict __timerid) __attribute__ ((__nothrow__));
extern int timer_delete (timer_t __timerid) __attribute__ ((__nothrow__));
extern int timer_settime (timer_t __timerid, int __flags,
     __const struct itimerspec *__restrict __value,
     struct itimerspec *__restrict __ovalue) __attribute__ ((__nothrow__));
extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     __attribute__ ((__nothrow__));
extern int timer_getoverrun (timer_t __timerid) __attribute__ ((__nothrow__));
# 417 "/usr/include/time.h" 3 4
# 299 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 310 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
# 1 "/usr/include/fcntl.h" 1 3 4
# 30 "/usr/include/fcntl.h" 3 4
# 1 "/usr/include/bits/fcntl.h" 1 3 4
# 25 "/usr/include/bits/fcntl.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 26 "/usr/include/bits/fcntl.h" 2 3 4
# 160 "/usr/include/bits/fcntl.h" 3 4
struct flock
  {
    short int l_type;
    short int l_whence;
    __off_t l_start;
    __off_t l_len;
    __pid_t l_pid;
  };
# 257 "/usr/include/bits/fcntl.h" 3 4
# 302 "/usr/include/bits/fcntl.h" 3 4
# 35 "/usr/include/fcntl.h" 2 3 4
# 64 "/usr/include/fcntl.h" 3 4
extern int fcntl (int __fd, int __cmd, ...);
# 73 "/usr/include/fcntl.h" 3 4
extern int open (__const char *__file, int __oflag, ...) __attribute__ ((__nonnull__ (1)));
# 97 "/usr/include/fcntl.h" 3 4
extern int openat (int __fd, __const char *__file, int __oflag, ...)
     __attribute__ ((__nonnull__ (2)));
# 108 "/usr/include/fcntl.h" 3 4
extern int openat64 (int __fd, __const char *__file, int __oflag, ...)
     __attribute__ ((__nonnull__ (2)));
# 118 "/usr/include/fcntl.h" 3 4
extern int creat (__const char *__file, __mode_t __mode) __attribute__ ((__nonnull__ (1)));
# 164 "/usr/include/fcntl.h" 3 4
extern int posix_fadvise (int __fd, __off_t __offset, __off_t __len,
     int __advise) __attribute__ ((__nothrow__));
# 186 "/usr/include/fcntl.h" 3 4
extern int posix_fallocate (int __fd, __off_t __offset, __off_t __len);
# 208 "/usr/include/fcntl.h" 3 4
# 311 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 351 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
# 1 "/usr/include/sys/wait.h" 1 3 4
# 29 "/usr/include/sys/wait.h" 3 4
# 1 "/usr/include/signal.h" 1 3 4
# 31 "/usr/include/signal.h" 3 4
# 1 "/usr/include/bits/sigset.h" 1 3 4
# 104 "/usr/include/bits/sigset.h" 3 4
extern int __sigismember (__const __sigset_t *, int);
extern int __sigaddset (__sigset_t *, int);
extern int __sigdelset (__sigset_t *, int);
# 34 "/usr/include/signal.h" 2 3 4
typedef __sig_atomic_t sig_atomic_t;
# 58 "/usr/include/signal.h" 3 4
# 1 "/usr/include/bits/signum.h" 1 3 4
# 59 "/usr/include/signal.h" 2 3 4
# 79 "/usr/include/signal.h" 3 4
# 1 "/usr/include/bits/siginfo.h" 1 3 4
# 25 "/usr/include/bits/siginfo.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 26 "/usr/include/bits/siginfo.h" 2 3 4
typedef union sigval
  {
    int sival_int;
    void *sival_ptr;
  } sigval_t;
# 51 "/usr/include/bits/siginfo.h" 3 4
typedef struct siginfo
  {
    int si_signo;
    int si_errno;
    int si_code;
    union
      {
 int _pad[((128 / sizeof (int)) - 3)];
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
   } _kill;
 struct
   {
     int si_tid;
     int si_overrun;
     sigval_t si_sigval;
   } _timer;
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     sigval_t si_sigval;
   } _rt;
 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     int si_status;
     __clock_t si_utime;
     __clock_t si_stime;
   } _sigchld;
 struct
   {
     void *si_addr;
   } _sigfault;
 struct
   {
     long int si_band;
     int si_fd;
   } _sigpoll;
      } _sifields;
  } siginfo_t;
# 129 "/usr/include/bits/siginfo.h" 3 4
enum
{
  SI_ASYNCNL = -60,
  SI_TKILL = -6,
  SI_SIGIO,
  SI_ASYNCIO,
  SI_MESGQ,
  SI_TIMER,
  SI_QUEUE,
  SI_USER,
  SI_KERNEL = 0x80
};
enum
{
  ILL_ILLOPC = 1,
  ILL_ILLOPN,
  ILL_ILLADR,
  ILL_ILLTRP,
  ILL_PRVOPC,
  ILL_PRVREG,
  ILL_COPROC,
  ILL_BADSTK
};
enum
{
  FPE_INTDIV = 1,
  FPE_INTOVF,
  FPE_FLTDIV,
  FPE_FLTOVF,
  FPE_FLTUND,
  FPE_FLTRES,
  FPE_FLTINV,
  FPE_FLTSUB
};
enum
{
  SEGV_MAPERR = 1,
  SEGV_ACCERR
};
enum
{
  BUS_ADRALN = 1,
  BUS_ADRERR,
  BUS_OBJERR
};
enum
{
  TRAP_BRKPT = 1,
  TRAP_TRACE
};
enum
{
  CLD_EXITED = 1,
  CLD_KILLED,
  CLD_DUMPED,
  CLD_TRAPPED,
  CLD_STOPPED,
  CLD_CONTINUED
};
enum
{
  POLL_IN = 1,
  POLL_OUT,
  POLL_MSG,
  POLL_ERR,
  POLL_PRI,
  POLL_HUP
};
# 273 "/usr/include/bits/siginfo.h" 3 4
typedef struct sigevent
  {
    sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;
    union
      {
 int _pad[((64 / sizeof (int)) - 3)];
 __pid_t _tid;
 struct
   {
     void (*_function) (sigval_t);
     void *_attribute;
   } _sigev_thread;
      } _sigev_un;
  } sigevent_t;
enum
{
  SIGEV_SIGNAL = 0,
  SIGEV_NONE,
  SIGEV_THREAD,
  SIGEV_THREAD_ID = 4
};
# 80 "/usr/include/signal.h" 2 3 4
typedef void (*__sighandler_t) (int);
extern __sighandler_t __sysv_signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__));
# 99 "/usr/include/signal.h" 3 4
extern __sighandler_t signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__));
# 113 "/usr/include/signal.h" 3 4
# 126 "/usr/include/signal.h" 3 4
extern int kill (__pid_t __pid, int __sig) __attribute__ ((__nothrow__));
extern int killpg (__pid_t __pgrp, int __sig) __attribute__ ((__nothrow__));
extern int raise (int __sig) __attribute__ ((__nothrow__));
extern __sighandler_t ssignal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__));
extern int gsignal (int __sig) __attribute__ ((__nothrow__));
extern void psignal (int __sig, __const char *__s);
extern void psiginfo (__const siginfo_t *__pinfo, __const char *__s);
# 168 "/usr/include/signal.h" 3 4
extern int __sigpause (int __sig_or_mask, int __is_sig);
# 196 "/usr/include/signal.h" 3 4
extern int sigblock (int __mask) __attribute__ ((__nothrow__)) __attribute__ ((__deprecated__));
extern int sigsetmask (int __mask) __attribute__ ((__nothrow__)) __attribute__ ((__deprecated__));
extern int siggetmask (void) __attribute__ ((__nothrow__)) __attribute__ ((__deprecated__));
# 216 "/usr/include/signal.h" 3 4
typedef __sighandler_t sig_t;
extern int sigemptyset (sigset_t *__set) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int sigfillset (sigset_t *__set) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int sigaddset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int sigdelset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int sigismember (__const sigset_t *__set, int __signo)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 252 "/usr/include/signal.h" 3 4
# 1 "/usr/include/bits/sigaction.h" 1 3 4
# 25 "/usr/include/bits/sigaction.h" 3 4
struct sigaction
  {
    union
      {
 __sighandler_t sa_handler;
 void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;
    __sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer) (void);
  };
# 253 "/usr/include/signal.h" 2 3 4
extern int sigprocmask (int __how, __const sigset_t *__restrict __set,
   sigset_t *__restrict __oset) __attribute__ ((__nothrow__));
extern int sigsuspend (__const sigset_t *__set) __attribute__ ((__nonnull__ (1)));
extern int sigaction (int __sig, __const struct sigaction *__restrict __act,
        struct sigaction *__restrict __oact) __attribute__ ((__nothrow__));
extern int sigpending (sigset_t *__set) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int sigwait (__const sigset_t *__restrict __set, int *__restrict __sig)
     __attribute__ ((__nonnull__ (1, 2)));
extern int sigwaitinfo (__const sigset_t *__restrict __set,
   siginfo_t *__restrict __info) __attribute__ ((__nonnull__ (1)));
extern int sigtimedwait (__const sigset_t *__restrict __set,
    siginfo_t *__restrict __info,
    __const struct timespec *__restrict __timeout)
     __attribute__ ((__nonnull__ (1)));
extern int sigqueue (__pid_t __pid, int __sig, __const union sigval __val)
     __attribute__ ((__nothrow__));
# 310 "/usr/include/signal.h" 3 4
extern __const char *__const _sys_siglist[65];
extern __const char *__const sys_siglist[65];
struct sigvec
  {
    __sighandler_t sv_handler;
    int sv_mask;
    int sv_flags;
  };
# 334 "/usr/include/signal.h" 3 4
extern int sigvec (int __sig, __const struct sigvec *__vec,
     struct sigvec *__ovec) __attribute__ ((__nothrow__));
# 1 "/usr/include/bits/sigcontext.h" 1 3 4
# 26 "/usr/include/bits/sigcontext.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 27 "/usr/include/bits/sigcontext.h" 2 3 4
struct _fpreg
{
  unsigned short significand[4];
  unsigned short exponent;
};
struct _fpxreg
{
  unsigned short significand[4];
  unsigned short exponent;
  unsigned short padding[3];
};
struct _xmmreg
{
  __uint32_t element[4];
};
struct _fpstate
{
  __uint32_t cw;
  __uint32_t sw;
  __uint32_t tag;
  __uint32_t ipoff;
  __uint32_t cssel;
  __uint32_t dataoff;
  __uint32_t datasel;
  struct _fpreg _st[8];
  unsigned short status;
  unsigned short magic;
  __uint32_t _fxsr_env[6];
  __uint32_t mxcsr;
  __uint32_t reserved;
  struct _fpxreg _fxsr_st[8];
  struct _xmmreg _xmm[8];
  __uint32_t padding[56];
};
# 81 "/usr/include/bits/sigcontext.h" 3 4
struct sigcontext
{
  unsigned short gs, __gsh;
  unsigned short fs, __fsh;
  unsigned short es, __esh;
  unsigned short ds, __dsh;
  unsigned long edi;
  unsigned long esi;
  unsigned long ebp;
  unsigned long esp;
  unsigned long ebx;
  unsigned long edx;
  unsigned long ecx;
  unsigned long eax;
  unsigned long trapno;
  unsigned long err;
  unsigned long eip;
  unsigned short cs, __csh;
  unsigned long eflags;
  unsigned long esp_at_signal;
  unsigned short ss, __ssh;
  struct _fpstate * fpstate;
  unsigned long oldmask;
  unsigned long cr2;
};
# 340 "/usr/include/signal.h" 2 3 4
extern int sigreturn (struct sigcontext *__scp) __attribute__ ((__nothrow__));
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 350 "/usr/include/signal.h" 2 3 4
extern int siginterrupt (int __sig, int __interrupt) __attribute__ ((__nothrow__));
# 1 "/usr/include/bits/sigstack.h" 1 3 4
# 26 "/usr/include/bits/sigstack.h" 3 4
struct sigstack
  {
    void *ss_sp;
    int ss_onstack;
  };
enum
{
  SS_ONSTACK = 1,
  SS_DISABLE
};
# 50 "/usr/include/bits/sigstack.h" 3 4
typedef struct sigaltstack
  {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
  } stack_t;
# 357 "/usr/include/signal.h" 2 3 4
# 365 "/usr/include/signal.h" 3 4
extern int sigstack (struct sigstack *__ss, struct sigstack *__oss)
     __attribute__ ((__nothrow__)) __attribute__ ((__deprecated__));
extern int sigaltstack (__const struct sigaltstack *__restrict __ss,
   struct sigaltstack *__restrict __oss) __attribute__ ((__nothrow__));
# 395 "/usr/include/signal.h" 3 4
# 1 "/usr/include/bits/sigthread.h" 1 3 4
# 31 "/usr/include/bits/sigthread.h" 3 4
extern int pthread_sigmask (int __how,
       __const __sigset_t *__restrict __newmask,
       __sigset_t *__restrict __oldmask)__attribute__ ((__nothrow__));
extern int pthread_kill (pthread_t __threadid, int __signo) __attribute__ ((__nothrow__));
# 396 "/usr/include/signal.h" 2 3 4
extern int __libc_current_sigrtmin (void) __attribute__ ((__nothrow__));
extern int __libc_current_sigrtmax (void) __attribute__ ((__nothrow__));
# 32 "/usr/include/sys/wait.h" 2 3 4
# 1 "/usr/include/sys/resource.h" 1 3 4
# 25 "/usr/include/sys/resource.h" 3 4
# 1 "/usr/include/bits/resource.h" 1 3 4
# 33 "/usr/include/bits/resource.h" 3 4
enum __rlimit_resource
{
  RLIMIT_CPU = 0,
  RLIMIT_FSIZE = 1,
  RLIMIT_DATA = 2,
  RLIMIT_STACK = 3,
  RLIMIT_CORE = 4,
  __RLIMIT_RSS = 5,
  RLIMIT_NOFILE = 7,
  __RLIMIT_OFILE = RLIMIT_NOFILE,
  RLIMIT_AS = 9,
  __RLIMIT_NPROC = 6,
  __RLIMIT_MEMLOCK = 8,
  __RLIMIT_LOCKS = 10,
  __RLIMIT_SIGPENDING = 11,
  __RLIMIT_MSGQUEUE = 12,
  __RLIMIT_NICE = 13,
  __RLIMIT_RTPRIO = 14,
  __RLIMIT_NLIMITS = 15,
  __RLIM_NLIMITS = __RLIMIT_NLIMITS
};
# 127 "/usr/include/bits/resource.h" 3 4
typedef __rlim_t rlim_t;
struct rlimit
  {
    rlim_t rlim_cur;
    rlim_t rlim_max;
  };
# 154 "/usr/include/bits/resource.h" 3 4
enum __rusage_who
{
  RUSAGE_SELF = 0,
  RUSAGE_CHILDREN = -1
# 172 "/usr/include/bits/resource.h" 3 4
};
# 1 "/usr/include/bits/time.h" 1 3 4
# 176 "/usr/include/bits/resource.h" 2 3 4
struct rusage
  {
    struct timeval ru_utime;
    struct timeval ru_stime;
    long int ru_maxrss;
    long int ru_ixrss;
    long int ru_idrss;
    long int ru_isrss;
    long int ru_minflt;
    long int ru_majflt;
    long int ru_nswap;
    long int ru_inblock;
    long int ru_oublock;
    long int ru_msgsnd;
    long int ru_msgrcv;
    long int ru_nsignals;
    long int ru_nvcsw;
    long int ru_nivcsw;
  };
enum __priority_which
{
  PRIO_PROCESS = 0,
  PRIO_PGRP = 1,
  PRIO_USER = 2
};
# 26 "/usr/include/sys/resource.h" 2 3 4
# 43 "/usr/include/sys/resource.h" 3 4
typedef int __rlimit_resource_t;
typedef int __rusage_who_t;
typedef int __priority_which_t;
extern int getrlimit (__rlimit_resource_t __resource,
        struct rlimit *__rlimits) __attribute__ ((__nothrow__));
# 70 "/usr/include/sys/resource.h" 3 4
extern int setrlimit (__rlimit_resource_t __resource,
        __const struct rlimit *__rlimits) __attribute__ ((__nothrow__));
# 88 "/usr/include/sys/resource.h" 3 4
extern int getrusage (__rusage_who_t __who, struct rusage *__usage) __attribute__ ((__nothrow__));
extern int getpriority (__priority_which_t __which, id_t __who) __attribute__ ((__nothrow__));
extern int setpriority (__priority_which_t __which, id_t __who, int __prio)
     __attribute__ ((__nothrow__));
# 33 "/usr/include/sys/wait.h" 2 3 4
# 1 "/usr/include/bits/waitflags.h" 1 3 4
# 39 "/usr/include/sys/wait.h" 2 3 4
# 63 "/usr/include/sys/wait.h" 3 4
typedef union
  {
    union wait *__uptr;
    int *__iptr;
  } __WAIT_STATUS __attribute__ ((__transparent_union__));
# 80 "/usr/include/sys/wait.h" 3 4
# 1 "/usr/include/bits/waitstatus.h" 1 3 4
# 67 "/usr/include/bits/waitstatus.h" 3 4
union wait
  {
    int w_status;
    struct
      {
 unsigned int __w_termsig:7;
 unsigned int __w_coredump:1;
 unsigned int __w_retcode:8;
 unsigned int:16;
      } __wait_terminated;
    struct
      {
 unsigned int __w_stopval:8;
 unsigned int __w_stopsig:8;
 unsigned int:16;
      } __wait_stopped;
  };
# 81 "/usr/include/sys/wait.h" 2 3 4
# 102 "/usr/include/sys/wait.h" 3 4
typedef enum
{
  P_ALL,
  P_PID,
  P_PGID
} idtype_t;
# 116 "/usr/include/sys/wait.h" 3 4
extern __pid_t wait (__WAIT_STATUS __stat_loc);
# 139 "/usr/include/sys/wait.h" 3 4
extern __pid_t waitpid (__pid_t __pid, int *__stat_loc, int __options);
# 1 "/usr/include/bits/siginfo.h" 1 3 4
# 25 "/usr/include/bits/siginfo.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 26 "/usr/include/bits/siginfo.h" 2 3 4
# 144 "/usr/include/sys/wait.h" 2 3 4
# 155 "/usr/include/sys/wait.h" 3 4
extern int waitid (idtype_t __idtype, __id_t __id, siginfo_t *__infop,
     int __options);
struct rusage;
extern __pid_t wait3 (__WAIT_STATUS __stat_loc, int __options,
        struct rusage * __usage) __attribute__ ((__nothrow__));
extern __pid_t wait4 (__pid_t __pid, __WAIT_STATUS __stat_loc, int __options,
        struct rusage *__usage) __attribute__ ((__nothrow__));
# 352 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 382 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
# 1 "/usr/include/sys/mman.h" 1 3 4
# 26 "/usr/include/sys/mman.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 27 "/usr/include/sys/mman.h" 2 3 4
# 42 "/usr/include/sys/mman.h" 3 4
# 1 "/usr/include/bits/mman.h" 1 3 4
# 43 "/usr/include/sys/mman.h" 2 3 4
# 58 "/usr/include/sys/mman.h" 3 4
extern void *mmap (void *__addr, size_t __len, int __prot,
     int __flags, int __fd, __off_t __offset) __attribute__ ((__nothrow__));
# 77 "/usr/include/sys/mman.h" 3 4
extern int munmap (void *__addr, size_t __len) __attribute__ ((__nothrow__));
extern int mprotect (void *__addr, size_t __len, int __prot) __attribute__ ((__nothrow__));
extern int msync (void *__addr, size_t __len, int __flags);
extern int madvise (void *__addr, size_t __len, int __advice) __attribute__ ((__nothrow__));
extern int posix_madvise (void *__addr, size_t __len, int __advice) __attribute__ ((__nothrow__));
extern int mlock (__const void *__addr, size_t __len) __attribute__ ((__nothrow__));
extern int munlock (__const void *__addr, size_t __len) __attribute__ ((__nothrow__));
extern int mlockall (int __flags) __attribute__ ((__nothrow__));
extern int munlockall (void) __attribute__ ((__nothrow__));
extern int mincore (void *__start, size_t __len, unsigned char *__vec)
     __attribute__ ((__nothrow__));
# 145 "/usr/include/sys/mman.h" 3 4
extern int shm_open (__const char *__name, int __oflag, mode_t __mode);
extern int shm_unlink (__const char *__name);
# 383 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 398 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
# 1 "/usr/include/sys/times.h" 1 3 4
# 32 "/usr/include/sys/times.h" 3 4
struct tms
  {
    clock_t tms_utime;
    clock_t tms_stime;
    clock_t tms_cutime;
    clock_t tms_cstime;
  };
extern clock_t times (struct tms *__buffer) __attribute__ ((__nothrow__));
# 399 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 431 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
extern int getopt (int, char * const *, const char *);
# 459 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
# 1 "/usr/include/malloc.h" 1 3 4
# 25 "/usr/include/malloc.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 26 "/usr/include/malloc.h" 2 3 4
# 48 "/usr/include/malloc.h" 3 4
extern void *malloc (size_t __size) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;
extern void *calloc (size_t __nmemb, size_t __size) __attribute__ ((__nothrow__))
       __attribute__ ((__malloc__)) ;
extern void *realloc (void *__ptr, size_t __size) __attribute__ ((__nothrow__))
       __attribute__ ((__warn_unused_result__));
extern void free (void *__ptr) __attribute__ ((__nothrow__));
extern void cfree (void *__ptr) __attribute__ ((__nothrow__));
extern void *memalign (size_t __alignment, size_t __size) __attribute__ ((__nothrow__))
       __attribute__ ((__malloc__)) ;
extern void *valloc (size_t __size) __attribute__ ((__nothrow__))
       __attribute__ ((__malloc__)) ;
extern void * pvalloc (size_t __size) __attribute__ ((__nothrow__))
       __attribute__ ((__malloc__)) ;
extern void *(*__morecore) (ptrdiff_t __size);
extern void *__default_morecore (ptrdiff_t __size) __attribute__ ((__nothrow__))
       __attribute__ ((__malloc__));
struct mallinfo {
  int arena;
  int ordblks;
  int smblks;
  int hblks;
  int hblkhd;
  int usmblks;
  int fsmblks;
  int uordblks;
  int fordblks;
  int keepcost;
};
extern struct mallinfo mallinfo (void) __attribute__ ((__nothrow__));
# 135 "/usr/include/malloc.h" 3 4
extern int mallopt (int __param, int __val) __attribute__ ((__nothrow__));
extern int malloc_trim (size_t __pad) __attribute__ ((__nothrow__));
extern size_t malloc_usable_size (void *__ptr) __attribute__ ((__nothrow__));
extern void malloc_stats (void) __attribute__ ((__nothrow__));
extern int malloc_info (int __options, FILE *__fp);
extern void *malloc_get_state (void) __attribute__ ((__nothrow__));
extern int malloc_set_state (void *__ptr) __attribute__ ((__nothrow__));
extern void (*__malloc_initialize_hook) (void);
extern void (*__free_hook) (void *__ptr, __const void *);
extern void *(*__malloc_hook) (size_t __size, __const void *);
extern void *(*__realloc_hook) (void *__ptr, size_t __size, __const void *);
extern void *(*__memalign_hook) (size_t __alignment, size_t __size, __const void *);
extern void (*__after_morecore_hook) (void);
extern void __malloc_check_init (void) __attribute__ ((__nothrow__));
# 460 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 483 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
# 1 "/usr/include/stdint.h" 1 3 4
# 27 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/bits/wchar.h" 1 3 4
# 28 "/usr/include/stdint.h" 2 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/stdint.h" 2 3 4
# 49 "/usr/include/stdint.h" 3 4
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
__extension__
typedef unsigned long long int uint64_t;
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;
__extension__
typedef long long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;
__extension__
typedef unsigned long long int uint_least64_t;
typedef signed char int_fast8_t;
typedef int int_fast16_t;
typedef int int_fast32_t;
__extension__
typedef long long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
__extension__
typedef unsigned long long int uint_fast64_t;
# 129 "/usr/include/stdint.h" 3 4
typedef unsigned int uintptr_t;
# 138 "/usr/include/stdint.h" 3 4
__extension__
typedef long long int intmax_t;
__extension__
typedef unsigned long long int uintmax_t;
# 484 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 1 "/usr/include/inttypes.h" 1 3 4
# 35 "/usr/include/inttypes.h" 3 4
typedef int __gwchar_t;
# 274 "/usr/include/inttypes.h" 3 4
# 288 "/usr/include/inttypes.h" 3 4
typedef struct
  {
    long long int quot;
    long long int rem;
  } imaxdiv_t;
extern intmax_t imaxabs (intmax_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern imaxdiv_t imaxdiv (intmax_t __numer, intmax_t __denom)
      __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern intmax_t strtoimax (__const char *__restrict __nptr,
      char **__restrict __endptr, int __base) __attribute__ ((__nothrow__));
extern uintmax_t strtoumax (__const char *__restrict __nptr,
       char ** __restrict __endptr, int __base) __attribute__ ((__nothrow__));
extern intmax_t wcstoimax (__const __gwchar_t *__restrict __nptr,
      __gwchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__));
extern uintmax_t wcstoumax (__const __gwchar_t *__restrict __nptr,
       __gwchar_t ** __restrict __endptr, int __base)
     __attribute__ ((__nothrow__));
# 442 "/usr/include/inttypes.h" 3 4
# 488 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 551 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
# 1 "/usr/include/sys/stat.h" 1 3 4
# 105 "/usr/include/sys/stat.h" 3 4
# 1 "/usr/include/bits/stat.h" 1 3 4
# 43 "/usr/include/bits/stat.h" 3 4
struct stat
  {
    __dev_t st_dev;
    unsigned short int __pad1;
    __ino_t st_ino;
    __mode_t st_mode;
    __nlink_t st_nlink;
    __uid_t st_uid;
    __gid_t st_gid;
    __dev_t st_rdev;
    unsigned short int __pad2;
    __off_t st_size;
    __blksize_t st_blksize;
    __blkcnt_t st_blocks;
# 88 "/usr/include/bits/stat.h" 3 4
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
# 106 "/usr/include/bits/stat.h" 3 4
    unsigned long int __unused4;
    unsigned long int __unused5;
  };
# 108 "/usr/include/sys/stat.h" 2 3 4
# 209 "/usr/include/sys/stat.h" 3 4
extern int stat (__const char *__restrict __file,
   struct stat *__restrict __buf) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int fstat (int __fd, struct stat *__buf) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
# 238 "/usr/include/sys/stat.h" 3 4
extern int fstatat (int __fd, __const char *__restrict __file,
      struct stat *__restrict __buf, int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));
# 263 "/usr/include/sys/stat.h" 3 4
extern int lstat (__const char *__restrict __file,
    struct stat *__restrict __buf) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
# 284 "/usr/include/sys/stat.h" 3 4
extern int chmod (__const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int lchmod (__const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int fchmod (int __fd, __mode_t __mode) __attribute__ ((__nothrow__));
extern int fchmodat (int __fd, __const char *__file, __mode_t __mode,
       int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2))) ;
extern __mode_t umask (__mode_t __mask) __attribute__ ((__nothrow__));
# 321 "/usr/include/sys/stat.h" 3 4
extern int mkdir (__const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int mkdirat (int __fd, __const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int mknod (__const char *__path, __mode_t __mode, __dev_t __dev)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int mknodat (int __fd, __const char *__path, __mode_t __mode,
      __dev_t __dev) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int mkfifo (__const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int mkfifoat (int __fd, __const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int utimensat (int __fd, __const char *__path,
        __const struct timespec __times[2],
        int __flags)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int futimens (int __fd, __const struct timespec __times[2]) __attribute__ ((__nothrow__));
# 399 "/usr/include/sys/stat.h" 3 4
extern int __fxstat (int __ver, int __fildes, struct stat *__stat_buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3)));
extern int __xstat (int __ver, __const char *__filename,
      struct stat *__stat_buf) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));
extern int __lxstat (int __ver, __const char *__filename,
       struct stat *__stat_buf) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));
extern int __fxstatat (int __ver, int __fildes, __const char *__filename,
         struct stat *__stat_buf, int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4)));
# 442 "/usr/include/sys/stat.h" 3 4
extern int __xmknod (int __ver, __const char *__path, __mode_t __mode,
       __dev_t *__dev) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));
extern int __xmknodat (int __ver, int __fd, __const char *__path,
         __mode_t __mode, __dev_t *__dev)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 5)));
# 534 "/usr/include/sys/stat.h" 3 4
# 552 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 623 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/filenames.h" 1
# 81 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/filenames.h"
extern int filename_cmp (const char *s1, const char *s2);
extern int filename_ncmp (const char *s1, const char *s2,
     size_t n);
# 624 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 635 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
# 1 "/usr/include/dlfcn.h" 1 3 4
# 25 "/usr/include/dlfcn.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 26 "/usr/include/dlfcn.h" 2 3 4
# 1 "/usr/include/bits/dlfcn.h" 1 3 4
# 29 "/usr/include/dlfcn.h" 2 3 4
# 53 "/usr/include/dlfcn.h" 3 4
extern void *dlopen (__const char *__file, int __mode) __attribute__ ((__nothrow__));
extern int dlclose (void *__handle) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern void *dlsym (void *__restrict __handle,
      __const char *__restrict __name) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
# 83 "/usr/include/dlfcn.h" 3 4
extern char *dlerror (void) __attribute__ ((__nothrow__));
# 189 "/usr/include/dlfcn.h" 3 4
# 636 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h" 1
# 46 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h"
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 47 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h" 2
# 56 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h"
extern void unlock_stream (FILE *);
extern void unlock_std_streams (void);
extern FILE *fopen_unlocked (const char *, const char *);
extern FILE *fdopen_unlocked (int, const char *);
extern FILE *freopen_unlocked (const char *, const char *, FILE *);
extern char **buildargv (const char *) __attribute__ ((__malloc__));
extern void freeargv (char **);
extern char **dupargv (char **) __attribute__ ((__malloc__));
extern void expandargv (int *, char ***);
extern int writeargv (char **, FILE *);
extern int countargv (char**);
# 121 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h"
extern const char *lbasename (const char *);
extern const char *dos_lbasename (const char *);
extern const char *unix_lbasename (const char *);
extern char *lrealpath (const char *);
extern char *concat (const char *, ...) __attribute__ ((__malloc__)) __attribute__ ((__sentinel__));
# 151 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h"
extern char *reconcat (char *, const char *, ...) __attribute__ ((__malloc__)) __attribute__ ((__sentinel__));
extern unsigned long concat_length (const char *, ...) __attribute__ ((__sentinel__));
extern char *concat_copy (char *, const char *, ...) __attribute__ ((__sentinel__));
extern char *concat_copy2 (const char *, ...) __attribute__ ((__sentinel__));
extern char *libiberty_concat_ptr;
# 187 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h"
extern int fdmatch (int fd1, int fd2);
# 199 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h"
extern char * getpwd (void);
# 212 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h"
extern long get_run_time (void);
extern char *make_relative_prefix (const char *, const char *,
                                   const char *) __attribute__ ((__malloc__));
extern char *make_relative_prefix_ignore_links (const char *, const char *,
      const char *) __attribute__ ((__malloc__));
extern char *choose_temp_base (void) __attribute__ ((__malloc__));
extern char *make_temp_file (const char *) __attribute__ ((__malloc__));
extern int unlink_if_ordinary (const char *);
extern const char *spaces (int count);
extern int errno_max (void);
extern const char *strerrno (int);
extern int strtoerrno (const char *);
extern char *xstrerror (int);
extern int signo_max (void);
# 276 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h"
extern const char *strsigno (int);
extern int strtosigno (const char *);
extern int xatexit (void (*fn) (void));
extern void xexit (int status) __attribute__ ((__noreturn__));
extern void xmalloc_set_program_name (const char *);
extern void xmalloc_failed (size_t) __attribute__ ((__noreturn__));
extern void *xmalloc (size_t) __attribute__ ((__malloc__));
extern void *xrealloc (void *, size_t);
extern void *xcalloc (size_t, size_t) __attribute__ ((__malloc__));
extern char *xstrdup (const char *) __attribute__ ((__malloc__));
extern char *xstrndup (const char *, size_t) __attribute__ ((__malloc__));
extern void *xmemdup (const void *, size_t, size_t) __attribute__ ((__malloc__));
extern double physmem_total (void);
extern double physmem_available (void);
extern unsigned int xcrc32 (const unsigned char *, int, unsigned int);
# 375 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h"
extern const unsigned char _hex_value[256];
extern void hex_init (void);
# 401 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h"
extern struct pex_obj *pex_init (int flags, const char *pname,
     const char *tempbase);
# 496 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h"
extern const char *pex_run (struct pex_obj *obj, int flags,
       const char *executable, char * const *argv,
       const char *outname, const char *errname,
       int *err);
# 511 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h"
extern const char *pex_run_in_environment (struct pex_obj *obj, int flags,
                      const char *executable,
                                           char * const *argv,
                                           char * const *env,
                              const char *outname,
        const char *errname, int *err);
extern FILE *pex_input_file (struct pex_obj *obj, int flags,
                             const char *in_name);
extern FILE *pex_input_pipe (struct pex_obj *obj, int binary);
extern FILE *pex_read_output (struct pex_obj *, int binary);
extern FILE *pex_read_err (struct pex_obj *, int binary);
extern int pex_get_status (struct pex_obj *, int count, int *vector);
struct pex_time
{
  unsigned long user_seconds;
  unsigned long user_microseconds;
  unsigned long system_seconds;
  unsigned long system_microseconds;
};
extern int pex_get_times (struct pex_obj *, int count,
     struct pex_time *vector);
extern void pex_free (struct pex_obj *);
# 586 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h"
extern const char *pex_one (int flags, const char *executable,
       char * const *argv, const char *pname,
       const char *outname, const char *errname,
       int *status, int *err);
# 605 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h"
extern int pexecute (const char *, char * const *, const char *,
                     const char *, char **, char **, int);
extern int pwait (int, int *, int);
# 642 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h"
extern void setproctitle (const char *name, ...);
extern void stack_limit_increase (unsigned long);
# 655 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/libiberty.h"
extern void *C_alloca (size_t) __attribute__ ((__malloc__));
# 640 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h" 2
# 668 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
extern void fancy_abort (const char *, int, const char *) __attribute__ ((__noreturn__));
# 758 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
        
        
        
        
# 814 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
        
        
# 884 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
        
# 896 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
        
        
        
# 914 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
        
# 930 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/system.h"
        
# 29 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gcc-plugin.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/coretypes.h" 1
# 47 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/coretypes.h"
struct bitmap_head_def;
typedef struct bitmap_head_def *bitmap;
typedef const struct bitmap_head_def *const_bitmap;
struct simple_bitmap_def;
typedef struct simple_bitmap_def *sbitmap;
typedef const struct simple_bitmap_def *const_sbitmap;
struct rtx_def;
typedef struct rtx_def *rtx;
typedef const struct rtx_def *const_rtx;
struct rtvec_def;
typedef struct rtvec_def *rtvec;
typedef const struct rtvec_def *const_rtvec;
union tree_node;
typedef union tree_node *tree;
union gimple_statement_d;
typedef union gimple_statement_d *gimple;
typedef const union tree_node *const_tree;
typedef const union gimple_statement_d *const_gimple;
union section;
typedef union section section;
struct gcc_options;
struct cl_target_option;
struct cl_optimization;
struct cl_option;
struct cl_decoded_option;
struct cl_option_handlers;
struct diagnostic_context;
typedef struct diagnostic_context diagnostic_context;
struct gimple_seq_d;
typedef struct gimple_seq_d *gimple_seq;
typedef const struct gimple_seq_d *const_gimple_seq;
typedef unsigned char addr_space_t;
enum ir_type {
  IR_GIMPLE,
  IR_RTL_CFGRTL,
  IR_RTL_CFGLAYOUT
};
struct cpp_reader;
struct cpp_token;
enum tls_model {
  TLS_MODEL_NONE,
  TLS_MODEL_EMULATED,
  TLS_MODEL_REAL,
  TLS_MODEL_GLOBAL_DYNAMIC = TLS_MODEL_REAL,
  TLS_MODEL_LOCAL_DYNAMIC,
  TLS_MODEL_INITIAL_EXEC,
  TLS_MODEL_LOCAL_EXEC
};
enum unwind_info_type
{
  UI_NONE,
  UI_SJLJ,
  UI_DWARF2,
  UI_TARGET
};
enum node_frequency {
  NODE_FREQUENCY_UNLIKELY_EXECUTED,
  NODE_FREQUENCY_EXECUTED_ONCE,
  NODE_FREQUENCY_NORMAL,
  NODE_FREQUENCY_HOT
};
enum var_init_status
{
  VAR_INIT_STATUS_UNKNOWN,
  VAR_INIT_STATUS_UNINITIALIZED,
  VAR_INIT_STATUS_INITIALIZED
};
struct edge_def;
typedef struct edge_def *edge;
typedef const struct edge_def *const_edge;
struct basic_block_def;
typedef struct basic_block_def *basic_block;
typedef const struct basic_block_def *const_basic_block;
# 168 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/coretypes.h"
typedef int reg_class_t;
# 186 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/coretypes.h"
enum memmodel
{
  MEMMODEL_RELAXED = 0,
  MEMMODEL_CONSUME = 1,
  MEMMODEL_ACQUIRE = 2,
  MEMMODEL_RELEASE = 3,
  MEMMODEL_ACQ_REL = 4,
  MEMMODEL_SEQ_CST = 5,
  MEMMODEL_LAST = 6
};
# 30 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gcc-plugin.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/highlev-plugin-common.h" 1
# 31 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gcc-plugin.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/hashtab.h" 1
# 47 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/hashtab.h"
typedef unsigned int hashval_t;
typedef hashval_t (*htab_hash) (const void *);
typedef int (*htab_eq) (const void *, const void *);
typedef void (*htab_del) (void *);
typedef int (*htab_trav) (void **, void *);
typedef void *(*htab_alloc) (size_t, size_t);
typedef void (*htab_free) (void *);
typedef void *(*htab_alloc_with_arg) (void *, size_t, size_t);
typedef void (*htab_free_with_arg) (void *, void *);
# 100 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/hashtab.h"
struct htab {
  htab_hash hash_f;
  htab_eq eq_f;
  htab_del del_f;
  void ** entries;
  size_t size;
  size_t n_elements;
  size_t n_deleted;
  unsigned int searches;
  unsigned int collisions;
  htab_alloc alloc_f;
  htab_free free_f;
  void * alloc_arg;
  htab_alloc_with_arg alloc_with_arg_f;
  htab_free_with_arg free_with_arg_f;
  unsigned int size_prime_index;
};
typedef struct htab *htab_t;
enum insert_option {NO_INSERT, INSERT};
extern htab_t htab_create_alloc (size_t, htab_hash,
                                    htab_eq, htab_del,
                                    htab_alloc, htab_free);
extern htab_t htab_create_alloc_ex (size_t, htab_hash,
                                      htab_eq, htab_del,
                                      void *, htab_alloc_with_arg,
                                      htab_free_with_arg);
extern htab_t htab_create_typed_alloc (size_t, htab_hash, htab_eq, htab_del,
     htab_alloc, htab_alloc, htab_free);
extern htab_t htab_create (size_t, htab_hash, htab_eq, htab_del);
extern htab_t htab_try_create (size_t, htab_hash, htab_eq, htab_del);
extern void htab_set_functions_ex (htab_t, htab_hash,
                                       htab_eq, htab_del,
                                       void *, htab_alloc_with_arg,
                                       htab_free_with_arg);
extern void htab_delete (htab_t);
extern void htab_empty (htab_t);
extern void * htab_find (htab_t, const void *);
extern void ** htab_find_slot (htab_t, const void *, enum insert_option);
extern void * htab_find_with_hash (htab_t, const void *, hashval_t);
extern void ** htab_find_slot_with_hash (htab_t, const void *,
       hashval_t, enum insert_option);
extern void htab_clear_slot (htab_t, void **);
extern void htab_remove_elt (htab_t, void *);
extern void htab_remove_elt_with_hash (htab_t, void *, hashval_t);
extern void htab_traverse (htab_t, htab_trav, void *);
extern void htab_traverse_noresize (htab_t, htab_trav, void *);
extern size_t htab_size (htab_t);
extern size_t htab_elements (htab_t);
extern double htab_collisions (htab_t);
extern htab_hash htab_hash_pointer;
extern htab_eq htab_eq_pointer;
extern hashval_t htab_hash_string (const void *);
extern hashval_t iterative_hash (const void *, size_t, hashval_t);
# 32 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gcc-plugin.h" 2
enum plugin_event
{
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/plugin.def" 1
# 22 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/plugin.def"
PLUGIN_PASS_MANAGER_SETUP,
PLUGIN_FINISH_TYPE,
PLUGIN_FINISH_DECL,
PLUGIN_FINISH_UNIT,
PLUGIN_PRE_GENERICIZE,
PLUGIN_FINISH,
PLUGIN_INFO,
PLUGIN_GGC_START,
PLUGIN_GGC_MARKING,
PLUGIN_GGC_END,
PLUGIN_REGISTER_GGC_ROOTS,
PLUGIN_REGISTER_GGC_CACHES,
PLUGIN_ATTRIBUTES,
PLUGIN_START_UNIT,
PLUGIN_PRAGMAS,
PLUGIN_ALL_PASSES_START,
PLUGIN_ALL_PASSES_END,
PLUGIN_ALL_IPA_PASSES_START,
PLUGIN_ALL_IPA_PASSES_END,
PLUGIN_OVERRIDE_GATE,
PLUGIN_PASS_EXECUTION,
PLUGIN_EARLY_GIMPLE_PASSES_START,
PLUGIN_EARLY_GIMPLE_PASSES_END,
PLUGIN_NEW_PASS,
# 38 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gcc-plugin.h" 2
  PLUGIN_EVENT_FIRST_DYNAMIC
};
extern const char **plugin_event_name;
struct plugin_argument
{
  char *key;
  char *value;
};
struct plugin_info
{
  const char *version;
  const char *help;
};
struct plugin_gcc_version
{
  const char *basever;
  const char *datestamp;
  const char *devphase;
  const char *revision;
  const char *configuration_arguments;
};
struct plugin_name_args
{
  char *base_name;
  const char *full_name;
  int argc;
  struct plugin_argument *argv;
  const char *version;
  const char *help;
};
extern unsigned char plugin_default_version_check (struct plugin_gcc_version *,
       struct plugin_gcc_version *);
# 103 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gcc-plugin.h"
typedef int (*plugin_init_func) (struct plugin_name_args *plugin_info,
                                 struct plugin_gcc_version *version);
extern int plugin_init (struct plugin_name_args *plugin_info,
                        struct plugin_gcc_version *version);
typedef void (*plugin_callback_func) (void *gcc_data, void *user_data);
# 129 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gcc-plugin.h"
extern int get_event_last (void);
int get_named_event_id (const char *name, enum insert_option insert);
extern void register_callback (const char *plugin_name,
          int event,
                               plugin_callback_func callback,
                               void *user_data);
extern int unregister_callback (const char *plugin_name, int event);
extern const char* default_plugin_dir_name (void);
# 161 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gcc-plugin.h"
extern int plugin_is_GPL_compatible;
# 24 "../../../src/plugin-utils.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h" 1
# 26 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/machmode.h" 1
# 25 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/machmode.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/insn-modes.h" 1
enum machine_mode
{
  VOIDmode,
  BLKmode,
  CCmode,
  CC_NOOVmode,
  CC_Zmode,
  CC_CZmode,
  CC_NCVmode,
  CC_SWPmode,
  CCFPmode,
  CCFPEmode,
  CC_DNEmode,
  CC_DEQmode,
  CC_DLEmode,
  CC_DLTmode,
  CC_DGEmode,
  CC_DGTmode,
  CC_DLEUmode,
  CC_DLTUmode,
  CC_DGEUmode,
  CC_DGTUmode,
  CC_Cmode,
  CC_Nmode,
  BImode,
  QImode,
  HImode,
  SImode,
  DImode,
  TImode,
  EImode,
  OImode,
  CImode,
  XImode,
  QQmode,
  HQmode,
  SQmode,
  DQmode,
  TQmode,
  UQQmode,
  UHQmode,
  USQmode,
  UDQmode,
  UTQmode,
  HAmode,
  SAmode,
  DAmode,
  TAmode,
  UHAmode,
  USAmode,
  UDAmode,
  UTAmode,
  HFmode,
  SFmode,
  DFmode,
  XFmode,
  SDmode,
  DDmode,
  TDmode,
  CQImode,
  CHImode,
  CSImode,
  CDImode,
  CTImode,
  CEImode,
  COImode,
  CCImode,
  CXImode,
  HCmode,
  SCmode,
  DCmode,
  XCmode,
  V4QImode,
  V2HImode,
  V8QImode,
  V4HImode,
  V2SImode,
  V16QImode,
  V8HImode,
  V4SImode,
  V2DImode,
  V4QQmode,
  V2HQmode,
  V4UQQmode,
  V2UHQmode,
  V2HAmode,
  V2UHAmode,
  V4HFmode,
  V2SFmode,
  V8HFmode,
  V4SFmode,
  V2DFmode,
  MAX_MACHINE_MODE,
  MIN_MODE_RANDOM = VOIDmode,
  MAX_MODE_RANDOM = BLKmode,
  MIN_MODE_CC = CCmode,
  MAX_MODE_CC = CC_Nmode,
  MIN_MODE_INT = QImode,
  MAX_MODE_INT = XImode,
  MIN_MODE_PARTIAL_INT = VOIDmode,
  MAX_MODE_PARTIAL_INT = VOIDmode,
  MIN_MODE_FRACT = QQmode,
  MAX_MODE_FRACT = TQmode,
  MIN_MODE_UFRACT = UQQmode,
  MAX_MODE_UFRACT = UTQmode,
  MIN_MODE_ACCUM = HAmode,
  MAX_MODE_ACCUM = TAmode,
  MIN_MODE_UACCUM = UHAmode,
  MAX_MODE_UACCUM = UTAmode,
  MIN_MODE_FLOAT = HFmode,
  MAX_MODE_FLOAT = XFmode,
  MIN_MODE_DECIMAL_FLOAT = SDmode,
  MAX_MODE_DECIMAL_FLOAT = TDmode,
  MIN_MODE_COMPLEX_INT = CQImode,
  MAX_MODE_COMPLEX_INT = CXImode,
  MIN_MODE_COMPLEX_FLOAT = HCmode,
  MAX_MODE_COMPLEX_FLOAT = XCmode,
  MIN_MODE_VECTOR_INT = V4QImode,
  MAX_MODE_VECTOR_INT = V2DImode,
  MIN_MODE_VECTOR_FRACT = V4QQmode,
  MAX_MODE_VECTOR_FRACT = V2HQmode,
  MIN_MODE_VECTOR_UFRACT = V4UQQmode,
  MAX_MODE_VECTOR_UFRACT = V2UHQmode,
  MIN_MODE_VECTOR_ACCUM = V2HAmode,
  MAX_MODE_VECTOR_ACCUM = V2HAmode,
  MIN_MODE_VECTOR_UACCUM = V2UHAmode,
  MAX_MODE_VECTOR_UACCUM = V2UHAmode,
  MIN_MODE_VECTOR_FLOAT = V4HFmode,
  MAX_MODE_VECTOR_FLOAT = V2DFmode,
  NUM_MACHINE_MODES = MAX_MACHINE_MODE
};
# 26 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/machmode.h" 2
extern const char * const mode_name[NUM_MACHINE_MODES];
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/mode-classes.def" 1
# 35 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/machmode.h" 2
enum mode_class { MODE_RANDOM, MODE_CC, MODE_INT, MODE_PARTIAL_INT, MODE_FRACT, MODE_UFRACT, MODE_ACCUM, MODE_UACCUM, MODE_FLOAT, MODE_DECIMAL_FLOAT, MODE_COMPLEX_INT, MODE_COMPLEX_FLOAT, MODE_VECTOR_INT, MODE_VECTOR_FRACT, MODE_VECTOR_UFRACT, MODE_VECTOR_ACCUM, MODE_VECTOR_UACCUM, MODE_VECTOR_FLOAT, MAX_MODE_CLASS };
extern const unsigned char mode_class[NUM_MACHINE_MODES];
# 179 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/machmode.h"
extern const unsigned char mode_size[NUM_MACHINE_MODES];
extern const unsigned short mode_precision[NUM_MACHINE_MODES];
extern const unsigned char mode_ibit[NUM_MACHINE_MODES];
extern const unsigned char mode_fbit[NUM_MACHINE_MODES];
extern const unsigned long long mode_mask_array[NUM_MACHINE_MODES];
extern const unsigned char mode_inner[NUM_MACHINE_MODES];
# 216 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/machmode.h"
extern const unsigned char mode_nunits[NUM_MACHINE_MODES];
extern const unsigned char mode_wider[NUM_MACHINE_MODES];
extern const unsigned char mode_2xwider[NUM_MACHINE_MODES];
extern enum machine_mode mode_for_size (unsigned int, enum mode_class, int);
extern enum machine_mode smallest_mode_for_size (unsigned int,
       enum mode_class);
extern enum machine_mode int_mode_for_mode (enum machine_mode);
extern enum machine_mode mode_for_vector (enum machine_mode, unsigned);
extern enum machine_mode get_best_mode (int, int,
     unsigned long long,
     unsigned long long,
     unsigned int,
     enum machine_mode, int);
extern const unsigned char mode_base_align[NUM_MACHINE_MODES];
extern unsigned get_mode_alignment (enum machine_mode);
extern const unsigned char class_narrowest_mode[MAX_MODE_CLASS];
extern enum machine_mode byte_mode;
extern enum machine_mode word_mode;
extern enum machine_mode ptr_mode;
extern void init_adjust_machine_modes (void);
# 27 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/input.h" 1
# 25 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/input.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/line-map.h" 1
# 37 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/line-map.h"
enum lc_reason
{
  LC_ENTER = 0,
  LC_LEAVE,
  LC_RENAME,
  LC_RENAME_VERBATIM,
  LC_ENTER_MACRO
};
typedef unsigned int linenum_type;
typedef unsigned int source_location;
typedef void *(*line_map_realloc) (void *, size_t);
typedef size_t (*line_map_round_alloc_size_func) (size_t);
# 71 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/line-map.h"
struct line_map_ordinary {
  const char *to_file;
  linenum_type to_line;
  int included_from;
  unsigned char sysp;
  unsigned int column_bits : 8;
};
struct cpp_hashnode;
# 105 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/line-map.h"
struct line_map_macro {
  struct cpp_hashnode *
    macro;
  unsigned int n_tokens;
# 168 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/line-map.h"
  source_location * macro_locations;
  source_location expansion;
};
# 204 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/line-map.h"
struct line_map {
  source_location start_location;
  __extension__ enum lc_reason reason : 8;
  union map_u {
    struct line_map_ordinary ordinary;
    struct line_map_macro macro;
  } d;
};
# 244 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/line-map.h"
struct maps_info {
  struct line_map * maps;
  unsigned int allocated;
  unsigned int used;
  unsigned int cache;
};
struct line_maps {
  struct maps_info info_ordinary;
  struct maps_info info_macro;
  unsigned int depth;
  unsigned char trace_includes;
  source_location highest_location;
  source_location highest_line;
  unsigned int max_column_hint;
  line_map_realloc reallocator;
  line_map_round_alloc_size_func round_alloc_size;
};
# 412 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/line-map.h"
extern void linemap_init (struct line_maps *);
extern void linemap_check_files_exited (struct line_maps *);
extern source_location linemap_line_start
(struct line_maps *set, linenum_type to_line, unsigned int max_column_hint);
# 440 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/line-map.h"
extern const struct line_map *linemap_add
  (struct line_maps *, enum lc_reason, unsigned int sysp,
   const char *to_file, linenum_type to_line);
extern const struct line_map *linemap_lookup
  (struct line_maps *, source_location);
unsigned char linemap_tracks_macro_expansion_locs_p (struct line_maps *);
unsigned char linemap_macro_expansion_map_p (const struct line_map *);
const char* linemap_map_get_macro_name (const struct line_map*);
# 473 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/line-map.h"
int linemap_location_in_system_header_p (struct line_maps *,
      source_location);
unsigned char linemap_location_from_macro_expansion_p (struct line_maps *,
           source_location);
# 550 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/line-map.h"
extern source_location
linemap_position_for_column (struct line_maps *, unsigned int);
source_location linemap_position_for_line_and_column (struct line_map *,
            linenum_type,
            unsigned int);
# 577 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/line-map.h"
int linemap_compare_locations (struct line_maps *set,
          source_location pre,
          source_location post);
typedef struct
{
  const char *file;
  int line;
  int column;
  unsigned char sysp;
} expanded_location;
enum location_resolution_kind
{
  LRK_MACRO_EXPANSION_POINT,
  LRK_SPELLING_LOCATION,
  LRK_MACRO_DEFINITION_LOCATION
};
# 659 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/line-map.h"
source_location linemap_resolve_location (struct line_maps *,
       source_location loc,
       enum location_resolution_kind lrk,
       const struct line_map **loc_map);
# 671 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/line-map.h"
source_location linemap_unwind_toward_expansion (struct line_maps *,
       source_location loc,
       const struct line_map **loc_map);
expanded_location linemap_expand_location (struct line_maps *,
        const struct line_map *,
        source_location loc);
struct linemap_stats
{
  long num_ordinary_maps_allocated;
  long num_ordinary_maps_used;
  long ordinary_maps_allocated_size;
  long ordinary_maps_used_size;
  long num_expanded_macros;
  long num_macro_tokens;
  long num_macro_maps_used;
  long macro_maps_allocated_size;
  long macro_maps_used_size;
  long macro_maps_locations_size;
  long duplicated_macro_maps_locations_size;
};
void linemap_get_statistics (struct line_maps *, struct linemap_stats *);
void linemap_dump_location (struct line_maps *, source_location, FILE *);
void linemap_dump (FILE *, struct line_maps *, unsigned, unsigned char);
void line_table_dump (FILE *, struct line_maps *, unsigned int, unsigned int);
# 26 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/input.h" 2
extern struct line_maps *line_table;
# 37 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/input.h"
extern char builtins_location_check[(((source_location) 1)
         < 2) ? 1 : -1];
extern expanded_location expand_location (source_location);
typedef source_location location_t;
extern location_t input_location;
# 58 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/input.h"
void dump_line_table_statistics (void);
# 28 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/statistics.h" 1
# 41 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/statistics.h"
struct function;
extern void statistics_early_init (void);
extern void statistics_init (void);
extern void statistics_fini (void);
extern void statistics_fini_pass (void);
extern void statistics_counter_event (struct function *, const char *, int);
extern void statistics_histogram_event (struct function *, const char *, int);
# 29 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/vec.h" 1
# 472 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/vec.h"
extern void *vec_gc_p_reserve (void *, int );
extern void *vec_gc_p_reserve_exact (void *, int );
extern void *vec_gc_o_reserve (void *, int, size_t, size_t );
extern void *vec_gc_o_reserve_exact (void *, int, size_t, size_t
         );
extern void ggc_free (void *);
extern void *vec_heap_p_reserve (void *, int );
extern void *vec_heap_p_reserve_exact (void *, int );
extern void *vec_heap_o_reserve (void *, int, size_t, size_t );
extern void *vec_heap_o_reserve_exact (void *, int, size_t, size_t
           );
extern void dump_vec_loc_statistics (void);
# 514 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/vec.h"
typedef struct vec_prefix
{
  unsigned num;
  unsigned alloc;
} vec_prefix;
# 1351 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/vec.h"
extern void *vec_stack_p_reserve (void *, int );
extern void *vec_stack_p_reserve_exact (void *, int );
extern void *vec_stack_p_reserve_exact_1 (int, void *);
extern void *vec_stack_o_reserve (void *, int, size_t, size_t );
extern void *vec_stack_o_reserve_exact (void *, int, size_t, size_t
      );
extern void vec_stack_free (void *);
# 30 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/vecir.h" 1
# 28 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/vecir.h"
static __inline__ void VEC_tree_must_be_pointer_type (void) { (void)((tree)1 == (void *)1); } typedef struct VEC_tree_base { struct vec_prefix prefix; tree vec[1]; } VEC_tree_base; typedef struct VEC_tree_none { VEC_tree_base base; } VEC_tree_none; static __inline__ unsigned VEC_tree_base_length (const VEC_tree_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static __inline__ tree VEC_tree_base_last (const VEC_tree_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static __inline__ tree VEC_tree_base_index (const VEC_tree_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static __inline__ int VEC_tree_base_iterate (const VEC_tree_base *vec_, unsigned ix_, tree *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (tree) 0; return 0; } } static __inline__ size_t VEC_tree_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_tree_base, vec) + alloc_ * sizeof(tree); } static __inline__ void VEC_tree_base_embedded_init (VEC_tree_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static __inline__ int VEC_tree_base_space (VEC_tree_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static __inline__ void VEC_tree_base_splice (VEC_tree_base *dst_, VEC_tree_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (tree)); dst_->prefix.num += len_; } } static __inline__ tree *VEC_tree_base_quick_push (VEC_tree_base *vec_, tree obj_ ) { tree *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static __inline__ tree VEC_tree_base_pop (VEC_tree_base *vec_ ) { tree obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_tree_base_truncate (VEC_tree_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static __inline__ tree VEC_tree_base_replace (VEC_tree_base *vec_, unsigned ix_, tree obj_ ) { tree old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ tree *VEC_tree_base_quick_insert (VEC_tree_base *vec_, unsigned ix_, tree obj_ ) { tree *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (tree)); *slot_ = obj_; return slot_; } static __inline__ tree VEC_tree_base_ordered_remove (VEC_tree_base *vec_, unsigned ix_ ) { tree *slot_; tree obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (tree)); return obj_; } static __inline__ tree VEC_tree_base_unordered_remove (VEC_tree_base *vec_, unsigned ix_ ) { tree *slot_; tree obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_tree_base_block_remove (VEC_tree_base *vec_, unsigned ix_, unsigned len_ ) { tree *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (tree)); } static __inline__ tree *VEC_tree_base_address (VEC_tree_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_tree_base_lower_bound (VEC_tree_base *vec_, const tree obj_, unsigned char (*lessthan_)(const tree, const tree) ) { unsigned int len_ = VEC_tree_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { tree middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_tree_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_tree_gc { VEC_tree_base base; } VEC_tree_gc; static __inline__ VEC_tree_gc *VEC_tree_gc_alloc (int alloc_ ) { return (VEC_tree_gc *) vec_gc_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_tree_gc_free (VEC_tree_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_tree_gc *VEC_tree_gc_copy (VEC_tree_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_tree_gc *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_tree_gc *)(vec_gc_p_reserve_exact (((void *)0), len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (tree) * len_); } return new_vec_; } static __inline__ int VEC_tree_gc_reserve (VEC_tree_gc **vec_, int alloc_ ) { int extend = !VEC_tree_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_tree_gc *) vec_gc_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_tree_gc_reserve_exact (VEC_tree_gc **vec_, int alloc_ ) { int extend = !VEC_tree_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_tree_gc *) vec_gc_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_tree_gc_safe_grow (VEC_tree_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_tree_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_tree_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_tree_gc_safe_grow_cleared (VEC_tree_gc **vec_, int size_ ) { int oldsize = VEC_tree_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_tree_gc_safe_grow (vec_, size_ ); memset (&(VEC_tree_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (tree) * (size_ - oldsize)); } static __inline__ void VEC_tree_gc_safe_splice (VEC_tree_gc **dst_, VEC_tree_base *src_ ) { if (src_) { VEC_tree_gc_reserve_exact (dst_, src_->prefix.num ); VEC_tree_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ tree *VEC_tree_gc_safe_push (VEC_tree_gc **vec_, tree obj_ ) { VEC_tree_gc_reserve (vec_, 1 ); return VEC_tree_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ tree *VEC_tree_gc_safe_insert (VEC_tree_gc **vec_, unsigned ix_, tree obj_ ) { VEC_tree_gc_reserve (vec_, 1 ); return VEC_tree_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
typedef struct VEC_tree_heap { VEC_tree_base base; } VEC_tree_heap; static __inline__ VEC_tree_heap *VEC_tree_heap_alloc (int alloc_ ) { return (VEC_tree_heap *) vec_heap_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_tree_heap_free (VEC_tree_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_tree_heap *VEC_tree_heap_copy (VEC_tree_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_tree_heap *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_tree_heap *)(vec_heap_p_reserve_exact (((void *)0), len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (tree) * len_); } return new_vec_; } static __inline__ int VEC_tree_heap_reserve (VEC_tree_heap **vec_, int alloc_ ) { int extend = !VEC_tree_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_tree_heap *) vec_heap_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_tree_heap_reserve_exact (VEC_tree_heap **vec_, int alloc_ ) { int extend = !VEC_tree_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_tree_heap *) vec_heap_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_tree_heap_safe_grow (VEC_tree_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_tree_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_tree_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_tree_heap_safe_grow_cleared (VEC_tree_heap **vec_, int size_ ) { int oldsize = VEC_tree_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_tree_heap_safe_grow (vec_, size_ ); memset (&(VEC_tree_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (tree) * (size_ - oldsize)); } static __inline__ void VEC_tree_heap_safe_splice (VEC_tree_heap **dst_, VEC_tree_base *src_ ) { if (src_) { VEC_tree_heap_reserve_exact (dst_, src_->prefix.num ); VEC_tree_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ tree *VEC_tree_heap_safe_push (VEC_tree_heap **vec_, tree obj_ ) { VEC_tree_heap_reserve (vec_, 1 ); return VEC_tree_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ tree *VEC_tree_heap_safe_insert (VEC_tree_heap **vec_, unsigned ix_, tree obj_ ) { VEC_tree_heap_reserve (vec_, 1 ); return VEC_tree_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
static __inline__ void VEC_gimple_must_be_pointer_type (void) { (void)((gimple)1 == (void *)1); } typedef struct VEC_gimple_base { struct vec_prefix prefix; gimple vec[1]; } VEC_gimple_base; typedef struct VEC_gimple_none { VEC_gimple_base base; } VEC_gimple_none; static __inline__ unsigned VEC_gimple_base_length (const VEC_gimple_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static __inline__ gimple VEC_gimple_base_last (const VEC_gimple_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static __inline__ gimple VEC_gimple_base_index (const VEC_gimple_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static __inline__ int VEC_gimple_base_iterate (const VEC_gimple_base *vec_, unsigned ix_, gimple *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (gimple) 0; return 0; } } static __inline__ size_t VEC_gimple_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_gimple_base, vec) + alloc_ * sizeof(gimple); } static __inline__ void VEC_gimple_base_embedded_init (VEC_gimple_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static __inline__ int VEC_gimple_base_space (VEC_gimple_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static __inline__ void VEC_gimple_base_splice (VEC_gimple_base *dst_, VEC_gimple_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (gimple)); dst_->prefix.num += len_; } } static __inline__ gimple *VEC_gimple_base_quick_push (VEC_gimple_base *vec_, gimple obj_ ) { gimple *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static __inline__ gimple VEC_gimple_base_pop (VEC_gimple_base *vec_ ) { gimple obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_gimple_base_truncate (VEC_gimple_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static __inline__ gimple VEC_gimple_base_replace (VEC_gimple_base *vec_, unsigned ix_, gimple obj_ ) { gimple old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ gimple *VEC_gimple_base_quick_insert (VEC_gimple_base *vec_, unsigned ix_, gimple obj_ ) { gimple *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (gimple)); *slot_ = obj_; return slot_; } static __inline__ gimple VEC_gimple_base_ordered_remove (VEC_gimple_base *vec_, unsigned ix_ ) { gimple *slot_; gimple obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (gimple)); return obj_; } static __inline__ gimple VEC_gimple_base_unordered_remove (VEC_gimple_base *vec_, unsigned ix_ ) { gimple *slot_; gimple obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_gimple_base_block_remove (VEC_gimple_base *vec_, unsigned ix_, unsigned len_ ) { gimple *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (gimple)); } static __inline__ gimple *VEC_gimple_base_address (VEC_gimple_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_gimple_base_lower_bound (VEC_gimple_base *vec_, const gimple obj_, unsigned char (*lessthan_)(const gimple, const gimple) ) { unsigned int len_ = VEC_gimple_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { gimple middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_gimple_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_gimple_heap { VEC_gimple_base base; } VEC_gimple_heap; static __inline__ VEC_gimple_heap *VEC_gimple_heap_alloc (int alloc_ ) { return (VEC_gimple_heap *) vec_heap_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_gimple_heap_free (VEC_gimple_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_gimple_heap *VEC_gimple_heap_copy (VEC_gimple_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_gimple_heap *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_gimple_heap *)(vec_heap_p_reserve_exact (((void *)0), len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (gimple) * len_); } return new_vec_; } static __inline__ int VEC_gimple_heap_reserve (VEC_gimple_heap **vec_, int alloc_ ) { int extend = !VEC_gimple_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_heap *) vec_heap_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_gimple_heap_reserve_exact (VEC_gimple_heap **vec_, int alloc_ ) { int extend = !VEC_gimple_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_heap *) vec_heap_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_gimple_heap_safe_grow (VEC_gimple_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_gimple_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_gimple_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_gimple_heap_safe_grow_cleared (VEC_gimple_heap **vec_, int size_ ) { int oldsize = VEC_gimple_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_gimple_heap_safe_grow (vec_, size_ ); memset (&(VEC_gimple_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (gimple) * (size_ - oldsize)); } static __inline__ void VEC_gimple_heap_safe_splice (VEC_gimple_heap **dst_, VEC_gimple_base *src_ ) { if (src_) { VEC_gimple_heap_reserve_exact (dst_, src_->prefix.num ); VEC_gimple_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ gimple *VEC_gimple_heap_safe_push (VEC_gimple_heap **vec_, gimple obj_ ) { VEC_gimple_heap_reserve (vec_, 1 ); return VEC_gimple_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ gimple *VEC_gimple_heap_safe_insert (VEC_gimple_heap **vec_, unsigned ix_, gimple obj_ ) { VEC_gimple_heap_reserve (vec_, 1 ); return VEC_gimple_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
typedef struct VEC_gimple_gc { VEC_gimple_base base; } VEC_gimple_gc; static __inline__ VEC_gimple_gc *VEC_gimple_gc_alloc (int alloc_ ) { return (VEC_gimple_gc *) vec_gc_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_gimple_gc_free (VEC_gimple_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_gimple_gc *VEC_gimple_gc_copy (VEC_gimple_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_gimple_gc *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_gimple_gc *)(vec_gc_p_reserve_exact (((void *)0), len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (gimple) * len_); } return new_vec_; } static __inline__ int VEC_gimple_gc_reserve (VEC_gimple_gc **vec_, int alloc_ ) { int extend = !VEC_gimple_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_gc *) vec_gc_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_gimple_gc_reserve_exact (VEC_gimple_gc **vec_, int alloc_ ) { int extend = !VEC_gimple_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_gc *) vec_gc_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_gimple_gc_safe_grow (VEC_gimple_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_gimple_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_gimple_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_gimple_gc_safe_grow_cleared (VEC_gimple_gc **vec_, int size_ ) { int oldsize = VEC_gimple_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_gimple_gc_safe_grow (vec_, size_ ); memset (&(VEC_gimple_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (gimple) * (size_ - oldsize)); } static __inline__ void VEC_gimple_gc_safe_splice (VEC_gimple_gc **dst_, VEC_gimple_base *src_ ) { if (src_) { VEC_gimple_gc_reserve_exact (dst_, src_->prefix.num ); VEC_gimple_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ gimple *VEC_gimple_gc_safe_push (VEC_gimple_gc **vec_, gimple obj_ ) { VEC_gimple_gc_reserve (vec_, 1 ); return VEC_gimple_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ gimple *VEC_gimple_gc_safe_insert (VEC_gimple_gc **vec_, unsigned ix_, gimple obj_ ) { VEC_gimple_gc_reserve (vec_, 1 ); return VEC_gimple_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
typedef gimple *gimple_p;
static __inline__ void VEC_gimple_p_must_be_pointer_type (void) { (void)((gimple_p)1 == (void *)1); } typedef struct VEC_gimple_p_base { struct vec_prefix prefix; gimple_p vec[1]; } VEC_gimple_p_base; typedef struct VEC_gimple_p_none { VEC_gimple_p_base base; } VEC_gimple_p_none; static __inline__ unsigned VEC_gimple_p_base_length (const VEC_gimple_p_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static __inline__ gimple_p VEC_gimple_p_base_last (const VEC_gimple_p_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static __inline__ gimple_p VEC_gimple_p_base_index (const VEC_gimple_p_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static __inline__ int VEC_gimple_p_base_iterate (const VEC_gimple_p_base *vec_, unsigned ix_, gimple_p *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (gimple_p) 0; return 0; } } static __inline__ size_t VEC_gimple_p_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_gimple_p_base, vec) + alloc_ * sizeof(gimple_p); } static __inline__ void VEC_gimple_p_base_embedded_init (VEC_gimple_p_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static __inline__ int VEC_gimple_p_base_space (VEC_gimple_p_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static __inline__ void VEC_gimple_p_base_splice (VEC_gimple_p_base *dst_, VEC_gimple_p_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (gimple_p)); dst_->prefix.num += len_; } } static __inline__ gimple_p *VEC_gimple_p_base_quick_push (VEC_gimple_p_base *vec_, gimple_p obj_ ) { gimple_p *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static __inline__ gimple_p VEC_gimple_p_base_pop (VEC_gimple_p_base *vec_ ) { gimple_p obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_gimple_p_base_truncate (VEC_gimple_p_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static __inline__ gimple_p VEC_gimple_p_base_replace (VEC_gimple_p_base *vec_, unsigned ix_, gimple_p obj_ ) { gimple_p old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ gimple_p *VEC_gimple_p_base_quick_insert (VEC_gimple_p_base *vec_, unsigned ix_, gimple_p obj_ ) { gimple_p *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (gimple_p)); *slot_ = obj_; return slot_; } static __inline__ gimple_p VEC_gimple_p_base_ordered_remove (VEC_gimple_p_base *vec_, unsigned ix_ ) { gimple_p *slot_; gimple_p obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (gimple_p)); return obj_; } static __inline__ gimple_p VEC_gimple_p_base_unordered_remove (VEC_gimple_p_base *vec_, unsigned ix_ ) { gimple_p *slot_; gimple_p obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_gimple_p_base_block_remove (VEC_gimple_p_base *vec_, unsigned ix_, unsigned len_ ) { gimple_p *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (gimple_p)); } static __inline__ gimple_p *VEC_gimple_p_base_address (VEC_gimple_p_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_gimple_p_base_lower_bound (VEC_gimple_p_base *vec_, const gimple_p obj_, unsigned char (*lessthan_)(const gimple_p, const gimple_p) ) { unsigned int len_ = VEC_gimple_p_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { gimple_p middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_gimple_p_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_gimple_p_heap { VEC_gimple_p_base base; } VEC_gimple_p_heap; static __inline__ VEC_gimple_p_heap *VEC_gimple_p_heap_alloc (int alloc_ ) { return (VEC_gimple_p_heap *) vec_heap_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_gimple_p_heap_free (VEC_gimple_p_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_gimple_p_heap *VEC_gimple_p_heap_copy (VEC_gimple_p_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_gimple_p_heap *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_gimple_p_heap *)(vec_heap_p_reserve_exact (((void *)0), len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (gimple_p) * len_); } return new_vec_; } static __inline__ int VEC_gimple_p_heap_reserve (VEC_gimple_p_heap **vec_, int alloc_ ) { int extend = !VEC_gimple_p_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_p_heap *) vec_heap_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_gimple_p_heap_reserve_exact (VEC_gimple_p_heap **vec_, int alloc_ ) { int extend = !VEC_gimple_p_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_p_heap *) vec_heap_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_gimple_p_heap_safe_grow (VEC_gimple_p_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_gimple_p_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_gimple_p_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_gimple_p_heap_safe_grow_cleared (VEC_gimple_p_heap **vec_, int size_ ) { int oldsize = VEC_gimple_p_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_gimple_p_heap_safe_grow (vec_, size_ ); memset (&(VEC_gimple_p_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (gimple_p) * (size_ - oldsize)); } static __inline__ void VEC_gimple_p_heap_safe_splice (VEC_gimple_p_heap **dst_, VEC_gimple_p_base *src_ ) { if (src_) { VEC_gimple_p_heap_reserve_exact (dst_, src_->prefix.num ); VEC_gimple_p_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ gimple_p *VEC_gimple_p_heap_safe_push (VEC_gimple_p_heap **vec_, gimple_p obj_ ) { VEC_gimple_p_heap_reserve (vec_, 1 ); return VEC_gimple_p_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ gimple_p *VEC_gimple_p_heap_safe_insert (VEC_gimple_p_heap **vec_, unsigned ix_, gimple_p obj_ ) { VEC_gimple_p_heap_reserve (vec_, 1 ); return VEC_gimple_p_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
static __inline__ void VEC_gimple_seq_must_be_pointer_type (void) { (void)((gimple_seq)1 == (void *)1); } typedef struct VEC_gimple_seq_base { struct vec_prefix prefix; gimple_seq vec[1]; } VEC_gimple_seq_base; typedef struct VEC_gimple_seq_none { VEC_gimple_seq_base base; } VEC_gimple_seq_none; static __inline__ unsigned VEC_gimple_seq_base_length (const VEC_gimple_seq_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static __inline__ gimple_seq VEC_gimple_seq_base_last (const VEC_gimple_seq_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static __inline__ gimple_seq VEC_gimple_seq_base_index (const VEC_gimple_seq_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static __inline__ int VEC_gimple_seq_base_iterate (const VEC_gimple_seq_base *vec_, unsigned ix_, gimple_seq *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (gimple_seq) 0; return 0; } } static __inline__ size_t VEC_gimple_seq_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_gimple_seq_base, vec) + alloc_ * sizeof(gimple_seq); } static __inline__ void VEC_gimple_seq_base_embedded_init (VEC_gimple_seq_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static __inline__ int VEC_gimple_seq_base_space (VEC_gimple_seq_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static __inline__ void VEC_gimple_seq_base_splice (VEC_gimple_seq_base *dst_, VEC_gimple_seq_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (gimple_seq)); dst_->prefix.num += len_; } } static __inline__ gimple_seq *VEC_gimple_seq_base_quick_push (VEC_gimple_seq_base *vec_, gimple_seq obj_ ) { gimple_seq *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static __inline__ gimple_seq VEC_gimple_seq_base_pop (VEC_gimple_seq_base *vec_ ) { gimple_seq obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_gimple_seq_base_truncate (VEC_gimple_seq_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static __inline__ gimple_seq VEC_gimple_seq_base_replace (VEC_gimple_seq_base *vec_, unsigned ix_, gimple_seq obj_ ) { gimple_seq old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ gimple_seq *VEC_gimple_seq_base_quick_insert (VEC_gimple_seq_base *vec_, unsigned ix_, gimple_seq obj_ ) { gimple_seq *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (gimple_seq)); *slot_ = obj_; return slot_; } static __inline__ gimple_seq VEC_gimple_seq_base_ordered_remove (VEC_gimple_seq_base *vec_, unsigned ix_ ) { gimple_seq *slot_; gimple_seq obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (gimple_seq)); return obj_; } static __inline__ gimple_seq VEC_gimple_seq_base_unordered_remove (VEC_gimple_seq_base *vec_, unsigned ix_ ) { gimple_seq *slot_; gimple_seq obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_gimple_seq_base_block_remove (VEC_gimple_seq_base *vec_, unsigned ix_, unsigned len_ ) { gimple_seq *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (gimple_seq)); } static __inline__ gimple_seq *VEC_gimple_seq_base_address (VEC_gimple_seq_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_gimple_seq_base_lower_bound (VEC_gimple_seq_base *vec_, const gimple_seq obj_, unsigned char (*lessthan_)(const gimple_seq, const gimple_seq) ) { unsigned int len_ = VEC_gimple_seq_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { gimple_seq middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_gimple_seq_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_gimple_seq_gc { VEC_gimple_seq_base base; } VEC_gimple_seq_gc; static __inline__ VEC_gimple_seq_gc *VEC_gimple_seq_gc_alloc (int alloc_ ) { return (VEC_gimple_seq_gc *) vec_gc_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_gimple_seq_gc_free (VEC_gimple_seq_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_gimple_seq_gc *VEC_gimple_seq_gc_copy (VEC_gimple_seq_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_gimple_seq_gc *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_gimple_seq_gc *)(vec_gc_p_reserve_exact (((void *)0), len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (gimple_seq) * len_); } return new_vec_; } static __inline__ int VEC_gimple_seq_gc_reserve (VEC_gimple_seq_gc **vec_, int alloc_ ) { int extend = !VEC_gimple_seq_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_seq_gc *) vec_gc_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_gimple_seq_gc_reserve_exact (VEC_gimple_seq_gc **vec_, int alloc_ ) { int extend = !VEC_gimple_seq_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_seq_gc *) vec_gc_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_gimple_seq_gc_safe_grow (VEC_gimple_seq_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_gimple_seq_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_gimple_seq_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_gimple_seq_gc_safe_grow_cleared (VEC_gimple_seq_gc **vec_, int size_ ) { int oldsize = VEC_gimple_seq_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_gimple_seq_gc_safe_grow (vec_, size_ ); memset (&(VEC_gimple_seq_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (gimple_seq) * (size_ - oldsize)); } static __inline__ void VEC_gimple_seq_gc_safe_splice (VEC_gimple_seq_gc **dst_, VEC_gimple_seq_base *src_ ) { if (src_) { VEC_gimple_seq_gc_reserve_exact (dst_, src_->prefix.num ); VEC_gimple_seq_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ gimple_seq *VEC_gimple_seq_gc_safe_push (VEC_gimple_seq_gc **vec_, gimple_seq obj_ ) { VEC_gimple_seq_gc_reserve (vec_, 1 ); return VEC_gimple_seq_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ gimple_seq *VEC_gimple_seq_gc_safe_insert (VEC_gimple_seq_gc **vec_, unsigned ix_, gimple_seq obj_ ) { VEC_gimple_seq_gc_reserve (vec_, 1 ); return VEC_gimple_seq_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
typedef struct VEC_gimple_seq_heap { VEC_gimple_seq_base base; } VEC_gimple_seq_heap; static __inline__ VEC_gimple_seq_heap *VEC_gimple_seq_heap_alloc (int alloc_ ) { return (VEC_gimple_seq_heap *) vec_heap_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_gimple_seq_heap_free (VEC_gimple_seq_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_gimple_seq_heap *VEC_gimple_seq_heap_copy (VEC_gimple_seq_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_gimple_seq_heap *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_gimple_seq_heap *)(vec_heap_p_reserve_exact (((void *)0), len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (gimple_seq) * len_); } return new_vec_; } static __inline__ int VEC_gimple_seq_heap_reserve (VEC_gimple_seq_heap **vec_, int alloc_ ) { int extend = !VEC_gimple_seq_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_seq_heap *) vec_heap_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_gimple_seq_heap_reserve_exact (VEC_gimple_seq_heap **vec_, int alloc_ ) { int extend = !VEC_gimple_seq_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_seq_heap *) vec_heap_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_gimple_seq_heap_safe_grow (VEC_gimple_seq_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_gimple_seq_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_gimple_seq_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_gimple_seq_heap_safe_grow_cleared (VEC_gimple_seq_heap **vec_, int size_ ) { int oldsize = VEC_gimple_seq_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_gimple_seq_heap_safe_grow (vec_, size_ ); memset (&(VEC_gimple_seq_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (gimple_seq) * (size_ - oldsize)); } static __inline__ void VEC_gimple_seq_heap_safe_splice (VEC_gimple_seq_heap **dst_, VEC_gimple_seq_base *src_ ) { if (src_) { VEC_gimple_seq_heap_reserve_exact (dst_, src_->prefix.num ); VEC_gimple_seq_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ gimple_seq *VEC_gimple_seq_heap_safe_push (VEC_gimple_seq_heap **vec_, gimple_seq obj_ ) { VEC_gimple_seq_heap_reserve (vec_, 1 ); return VEC_gimple_seq_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ gimple_seq *VEC_gimple_seq_heap_safe_insert (VEC_gimple_seq_heap **vec_, unsigned ix_, gimple_seq obj_ ) { VEC_gimple_seq_heap_reserve (vec_, 1 ); return VEC_gimple_seq_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
static __inline__ void VEC_rtx_must_be_pointer_type (void) { (void)((rtx)1 == (void *)1); } typedef struct VEC_rtx_base { struct vec_prefix prefix; rtx vec[1]; } VEC_rtx_base; typedef struct VEC_rtx_none { VEC_rtx_base base; } VEC_rtx_none; static __inline__ unsigned VEC_rtx_base_length (const VEC_rtx_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static __inline__ rtx VEC_rtx_base_last (const VEC_rtx_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static __inline__ rtx VEC_rtx_base_index (const VEC_rtx_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static __inline__ int VEC_rtx_base_iterate (const VEC_rtx_base *vec_, unsigned ix_, rtx *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (rtx) 0; return 0; } } static __inline__ size_t VEC_rtx_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_rtx_base, vec) + alloc_ * sizeof(rtx); } static __inline__ void VEC_rtx_base_embedded_init (VEC_rtx_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static __inline__ int VEC_rtx_base_space (VEC_rtx_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static __inline__ void VEC_rtx_base_splice (VEC_rtx_base *dst_, VEC_rtx_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (rtx)); dst_->prefix.num += len_; } } static __inline__ rtx *VEC_rtx_base_quick_push (VEC_rtx_base *vec_, rtx obj_ ) { rtx *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static __inline__ rtx VEC_rtx_base_pop (VEC_rtx_base *vec_ ) { rtx obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_rtx_base_truncate (VEC_rtx_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static __inline__ rtx VEC_rtx_base_replace (VEC_rtx_base *vec_, unsigned ix_, rtx obj_ ) { rtx old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ rtx *VEC_rtx_base_quick_insert (VEC_rtx_base *vec_, unsigned ix_, rtx obj_ ) { rtx *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (rtx)); *slot_ = obj_; return slot_; } static __inline__ rtx VEC_rtx_base_ordered_remove (VEC_rtx_base *vec_, unsigned ix_ ) { rtx *slot_; rtx obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (rtx)); return obj_; } static __inline__ rtx VEC_rtx_base_unordered_remove (VEC_rtx_base *vec_, unsigned ix_ ) { rtx *slot_; rtx obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_rtx_base_block_remove (VEC_rtx_base *vec_, unsigned ix_, unsigned len_ ) { rtx *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (rtx)); } static __inline__ rtx *VEC_rtx_base_address (VEC_rtx_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_rtx_base_lower_bound (VEC_rtx_base *vec_, const rtx obj_, unsigned char (*lessthan_)(const rtx, const rtx) ) { unsigned int len_ = VEC_rtx_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { rtx middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_rtx_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_rtx_heap { VEC_rtx_base base; } VEC_rtx_heap; static __inline__ VEC_rtx_heap *VEC_rtx_heap_alloc (int alloc_ ) { return (VEC_rtx_heap *) vec_heap_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_rtx_heap_free (VEC_rtx_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_rtx_heap *VEC_rtx_heap_copy (VEC_rtx_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_rtx_heap *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_rtx_heap *)(vec_heap_p_reserve_exact (((void *)0), len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (rtx) * len_); } return new_vec_; } static __inline__ int VEC_rtx_heap_reserve (VEC_rtx_heap **vec_, int alloc_ ) { int extend = !VEC_rtx_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_rtx_heap *) vec_heap_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_rtx_heap_reserve_exact (VEC_rtx_heap **vec_, int alloc_ ) { int extend = !VEC_rtx_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_rtx_heap *) vec_heap_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_rtx_heap_safe_grow (VEC_rtx_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_rtx_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_rtx_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_rtx_heap_safe_grow_cleared (VEC_rtx_heap **vec_, int size_ ) { int oldsize = VEC_rtx_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_rtx_heap_safe_grow (vec_, size_ ); memset (&(VEC_rtx_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (rtx) * (size_ - oldsize)); } static __inline__ void VEC_rtx_heap_safe_splice (VEC_rtx_heap **dst_, VEC_rtx_base *src_ ) { if (src_) { VEC_rtx_heap_reserve_exact (dst_, src_->prefix.num ); VEC_rtx_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ rtx *VEC_rtx_heap_safe_push (VEC_rtx_heap **vec_, rtx obj_ ) { VEC_rtx_heap_reserve (vec_, 1 ); return VEC_rtx_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ rtx *VEC_rtx_heap_safe_insert (VEC_rtx_heap **vec_, unsigned ix_, rtx obj_ ) { VEC_rtx_heap_reserve (vec_, 1 ); return VEC_rtx_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
typedef struct VEC_rtx_gc { VEC_rtx_base base; } VEC_rtx_gc; static __inline__ VEC_rtx_gc *VEC_rtx_gc_alloc (int alloc_ ) { return (VEC_rtx_gc *) vec_gc_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_rtx_gc_free (VEC_rtx_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_rtx_gc *VEC_rtx_gc_copy (VEC_rtx_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_rtx_gc *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_rtx_gc *)(vec_gc_p_reserve_exact (((void *)0), len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (rtx) * len_); } return new_vec_; } static __inline__ int VEC_rtx_gc_reserve (VEC_rtx_gc **vec_, int alloc_ ) { int extend = !VEC_rtx_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_rtx_gc *) vec_gc_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_rtx_gc_reserve_exact (VEC_rtx_gc **vec_, int alloc_ ) { int extend = !VEC_rtx_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_rtx_gc *) vec_gc_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_rtx_gc_safe_grow (VEC_rtx_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_rtx_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_rtx_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_rtx_gc_safe_grow_cleared (VEC_rtx_gc **vec_, int size_ ) { int oldsize = VEC_rtx_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_rtx_gc_safe_grow (vec_, size_ ); memset (&(VEC_rtx_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (rtx) * (size_ - oldsize)); } static __inline__ void VEC_rtx_gc_safe_splice (VEC_rtx_gc **dst_, VEC_rtx_base *src_ ) { if (src_) { VEC_rtx_gc_reserve_exact (dst_, src_->prefix.num ); VEC_rtx_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ rtx *VEC_rtx_gc_safe_push (VEC_rtx_gc **vec_, rtx obj_ ) { VEC_rtx_gc_reserve (vec_, 1 ); return VEC_rtx_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ rtx *VEC_rtx_gc_safe_insert (VEC_rtx_gc **vec_, unsigned ix_, rtx obj_ ) { VEC_rtx_gc_reserve (vec_, 1 ); return VEC_rtx_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
# 31 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/double-int.h" 1
# 24 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/double-int.h"
# 1 "/usr/include/gmp.h" 1 3 4
# 43 "/usr/include/gmp.h" 3 4
# 1 "/usr/include/gmp-i386.h" 1 3 4
# 53 "/usr/include/gmp-i386.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 54 "/usr/include/gmp-i386.h" 2 3 4
# 194 "/usr/include/gmp-i386.h" 3 4
typedef unsigned long int mp_limb_t;
typedef long int mp_limb_signed_t;
typedef struct
{
  int _mp_alloc;
  int _mp_size;
  mp_limb_t *_mp_d;
} __mpz_struct;
typedef __mpz_struct MP_INT;
typedef __mpz_struct mpz_t[1];
typedef mp_limb_t * mp_ptr;
typedef const mp_limb_t * mp_srcptr;
typedef long int mp_size_t;
typedef long int mp_exp_t;
typedef struct
{
  __mpz_struct _mp_num;
  __mpz_struct _mp_den;
} __mpq_struct;
typedef __mpq_struct MP_RAT;
typedef __mpq_struct mpq_t[1];
typedef struct
{
  int _mp_prec;
  int _mp_size;
  mp_exp_t _mp_exp;
  mp_limb_t *_mp_d;
} __mpf_struct;
typedef __mpf_struct mpf_t[1];
typedef enum
{
  GMP_RAND_ALG_DEFAULT = 0,
  GMP_RAND_ALG_LC = GMP_RAND_ALG_DEFAULT
} gmp_randalg_t;
typedef struct
{
  mpz_t _mp_seed;
  gmp_randalg_t _mp_alg;
  union {
    void *_mp_lc;
  } _mp_algdata;
} __gmp_randstate_struct;
typedef __gmp_randstate_struct gmp_randstate_t[1];
typedef const __mpz_struct *mpz_srcptr;
typedef __mpz_struct *mpz_ptr;
typedef const __mpf_struct *mpf_srcptr;
typedef __mpf_struct *mpf_ptr;
typedef const __mpq_struct *mpq_srcptr;
typedef __mpq_struct *mpq_ptr;
# 542 "/usr/include/gmp-i386.h" 3 4
 void __gmp_set_memory_functions (void *(*) (size_t), void *(*) (void *, size_t, size_t), void (*) (void *, size_t)) ;
 void __gmp_get_memory_functions (void *(**) (size_t), void *(**) (void *, size_t, size_t), void (**) (void *, size_t)) ;
 extern const int __gmp_bits_per_limb;
 extern int __gmp_errno;
 extern const char * const __gmp_version;
 void __gmp_randinit (gmp_randstate_t, gmp_randalg_t, ...);
 void __gmp_randinit_default (gmp_randstate_t);
 void __gmp_randinit_lc_2exp (gmp_randstate_t, mpz_srcptr, unsigned long int, unsigned long int);
 int __gmp_randinit_lc_2exp_size (gmp_randstate_t, unsigned long);
 void __gmp_randinit_mt (gmp_randstate_t);
 void __gmp_randinit_set (gmp_randstate_t, const __gmp_randstate_struct *);
 void __gmp_randseed (gmp_randstate_t, mpz_srcptr);
 void __gmp_randseed_ui (gmp_randstate_t, unsigned long int);
 void __gmp_randclear (gmp_randstate_t);
 unsigned long __gmp_urandomb_ui (gmp_randstate_t, unsigned long);
 unsigned long __gmp_urandomm_ui (gmp_randstate_t, unsigned long);
 int __gmp_asprintf (char **, const char *, ...);
 int __gmp_fprintf (FILE *, const char *, ...);
# 621 "/usr/include/gmp-i386.h" 3 4
 int __gmp_printf (const char *, ...);
 int __gmp_snprintf (char *, size_t, const char *, ...);
 int __gmp_sprintf (char *, const char *, ...);
 int __gmp_vasprintf (char **, const char *, va_list);
 int __gmp_vfprintf (FILE *, const char *, va_list);
 int __gmp_vprintf (const char *, va_list);
 int __gmp_vsnprintf (char *, size_t, const char *, va_list);
 int __gmp_vsprintf (char *, const char *, va_list);
 int __gmp_fscanf (FILE *, const char *, ...);
 int __gmp_scanf (const char *, ...);
 int __gmp_sscanf (const char *, const char *, ...);
 int __gmp_vfscanf (FILE *, const char *, va_list);
 int __gmp_vscanf (const char *, va_list);
 int __gmp_vsscanf (const char *, const char *, va_list);
 void *__gmpz_realloc (mpz_ptr, mp_size_t);
 void __gmpz_abs (mpz_ptr, mpz_srcptr);
 void __gmpz_add (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_add_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_addmul (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_addmul_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_and (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_array_init (mpz_ptr, mp_size_t, mp_size_t);
 void __gmpz_bin_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_bin_uiui (mpz_ptr, unsigned long int, unsigned long int);
 void __gmpz_cdiv_q (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_cdiv_q_2exp (mpz_ptr, mpz_srcptr, unsigned long);
 unsigned long int __gmpz_cdiv_q_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_cdiv_qr (mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr);
 unsigned long int __gmpz_cdiv_qr_ui (mpz_ptr, mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_cdiv_r (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_cdiv_r_2exp (mpz_ptr, mpz_srcptr, unsigned long);
 unsigned long int __gmpz_cdiv_r_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 unsigned long int __gmpz_cdiv_ui (mpz_srcptr, unsigned long int) __attribute__ ((__pure__));
 void __gmpz_clear (mpz_ptr);
 void __gmpz_clrbit (mpz_ptr, unsigned long int);
 int __gmpz_cmp (mpz_srcptr, mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_cmp_d (mpz_srcptr, double) __attribute__ ((__pure__));
 int __gmpz_cmp_si (mpz_srcptr, signed long int) __attribute__ ((__pure__));
 int __gmpz_cmp_ui (mpz_srcptr, unsigned long int) __attribute__ ((__pure__));
 int __gmpz_cmpabs (mpz_srcptr, mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_cmpabs_d (mpz_srcptr, double) __attribute__ ((__pure__));
 int __gmpz_cmpabs_ui (mpz_srcptr, unsigned long int) __attribute__ ((__pure__));
 void __gmpz_com (mpz_ptr, mpz_srcptr);
 void __gmpz_combit (mpz_ptr, unsigned long int);
 int __gmpz_congruent_p (mpz_srcptr, mpz_srcptr, mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_congruent_2exp_p (mpz_srcptr, mpz_srcptr, unsigned long) __attribute__ ((__pure__));
 int __gmpz_congruent_ui_p (mpz_srcptr, unsigned long, unsigned long) __attribute__ ((__pure__));
 void __gmpz_divexact (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_divexact_ui (mpz_ptr, mpz_srcptr, unsigned long);
 int __gmpz_divisible_p (mpz_srcptr, mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_divisible_ui_p (mpz_srcptr, unsigned long) __attribute__ ((__pure__));
 int __gmpz_divisible_2exp_p (mpz_srcptr, unsigned long) __attribute__ ((__pure__));
 void __gmpz_dump (mpz_srcptr);
 void *__gmpz_export (void *, size_t *, int, size_t, int, size_t, mpz_srcptr);
 void __gmpz_fac_ui (mpz_ptr, unsigned long int);
 void __gmpz_fdiv_q (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_fdiv_q_2exp (mpz_ptr, mpz_srcptr, unsigned long int);
 unsigned long int __gmpz_fdiv_q_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_fdiv_qr (mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr);
 unsigned long int __gmpz_fdiv_qr_ui (mpz_ptr, mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_fdiv_r (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_fdiv_r_2exp (mpz_ptr, mpz_srcptr, unsigned long int);
 unsigned long int __gmpz_fdiv_r_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 unsigned long int __gmpz_fdiv_ui (mpz_srcptr, unsigned long int) __attribute__ ((__pure__));
 void __gmpz_fib_ui (mpz_ptr, unsigned long int);
 void __gmpz_fib2_ui (mpz_ptr, mpz_ptr, unsigned long int);
 int __gmpz_fits_sint_p (mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_fits_slong_p (mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_fits_sshort_p (mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_fits_uint_p (mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_fits_ulong_p (mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_fits_ushort_p (mpz_srcptr) __attribute__ ((__pure__));
 void __gmpz_gcd (mpz_ptr, mpz_srcptr, mpz_srcptr);
 unsigned long int __gmpz_gcd_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_gcdext (mpz_ptr, mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr);
 double __gmpz_get_d (mpz_srcptr) __attribute__ ((__pure__));
 double __gmpz_get_d_2exp (signed long int *, mpz_srcptr);
 long int __gmpz_get_si (mpz_srcptr) __attribute__ ((__pure__));
 char *__gmpz_get_str (char *, int, mpz_srcptr);
 unsigned long int __gmpz_get_ui (mpz_srcptr) __attribute__ ((__pure__));
 mp_limb_t __gmpz_getlimbn (mpz_srcptr, mp_size_t) __attribute__ ((__pure__));
 unsigned long int __gmpz_hamdist (mpz_srcptr, mpz_srcptr) __attribute__ ((__pure__));
 void __gmpz_import (mpz_ptr, size_t, int, size_t, int, size_t, const void *);
 void __gmpz_init (mpz_ptr);
 void __gmpz_init2 (mpz_ptr, unsigned long);
 void __gmpz_init_set (mpz_ptr, mpz_srcptr);
 void __gmpz_init_set_d (mpz_ptr, double);
 void __gmpz_init_set_si (mpz_ptr, signed long int);
 int __gmpz_init_set_str (mpz_ptr, const char *, int);
 void __gmpz_init_set_ui (mpz_ptr, unsigned long int);
 size_t __gmpz_inp_raw (mpz_ptr, FILE *);
 size_t __gmpz_inp_str (mpz_ptr, FILE *, int);
 int __gmpz_invert (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_ior (mpz_ptr, mpz_srcptr, mpz_srcptr);
 int __gmpz_jacobi (mpz_srcptr, mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_kronecker_si (mpz_srcptr, long) __attribute__ ((__pure__));
 int __gmpz_kronecker_ui (mpz_srcptr, unsigned long) __attribute__ ((__pure__));
 int __gmpz_si_kronecker (long, mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_ui_kronecker (unsigned long, mpz_srcptr) __attribute__ ((__pure__));
 void __gmpz_lcm (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_lcm_ui (mpz_ptr, mpz_srcptr, unsigned long);
 void __gmpz_lucnum_ui (mpz_ptr, unsigned long int);
 void __gmpz_lucnum2_ui (mpz_ptr, mpz_ptr, unsigned long int);
 int __gmpz_millerrabin (mpz_srcptr, int) __attribute__ ((__pure__));
 void __gmpz_mod (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_mul (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_mul_2exp (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_mul_si (mpz_ptr, mpz_srcptr, long int);
 void __gmpz_mul_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_neg (mpz_ptr, mpz_srcptr);
 void __gmpz_nextprime (mpz_ptr, mpz_srcptr);
 size_t __gmpz_out_raw (FILE *, mpz_srcptr);
 size_t __gmpz_out_str (FILE *, int, mpz_srcptr);
 int __gmpz_perfect_power_p (mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_perfect_square_p (mpz_srcptr) __attribute__ ((__pure__));
 unsigned long int __gmpz_popcount (mpz_srcptr) __attribute__ ((__pure__));
 void __gmpz_pow_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_powm (mpz_ptr, mpz_srcptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_powm_ui (mpz_ptr, mpz_srcptr, unsigned long int, mpz_srcptr);
 int __gmpz_probab_prime_p (mpz_srcptr, int) __attribute__ ((__pure__));
 void __gmpz_random (mpz_ptr, mp_size_t);
 void __gmpz_random2 (mpz_ptr, mp_size_t);
 void __gmpz_realloc2 (mpz_ptr, unsigned long);
 unsigned long int __gmpz_remove (mpz_ptr, mpz_srcptr, mpz_srcptr);
 int __gmpz_root (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_rootrem (mpz_ptr,mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_rrandomb (mpz_ptr, gmp_randstate_t, unsigned long int);
 unsigned long int __gmpz_scan0 (mpz_srcptr, unsigned long int) __attribute__ ((__pure__));
 unsigned long int __gmpz_scan1 (mpz_srcptr, unsigned long int) __attribute__ ((__pure__));
 void __gmpz_set (mpz_ptr, mpz_srcptr);
 void __gmpz_set_d (mpz_ptr, double);
 void __gmpz_set_f (mpz_ptr, mpf_srcptr);
 void __gmpz_set_q (mpz_ptr, mpq_srcptr);
 void __gmpz_set_si (mpz_ptr, signed long int);
 int __gmpz_set_str (mpz_ptr, const char *, int);
 void __gmpz_set_ui (mpz_ptr, unsigned long int);
 void __gmpz_setbit (mpz_ptr, unsigned long int);
 size_t __gmpz_size (mpz_srcptr) __attribute__ ((__pure__));
 size_t __gmpz_sizeinbase (mpz_srcptr, int) __attribute__ ((__pure__));
 void __gmpz_sqrt (mpz_ptr, mpz_srcptr);
 void __gmpz_sqrtrem (mpz_ptr, mpz_ptr, mpz_srcptr);
 void __gmpz_sub (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_sub_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_ui_sub (mpz_ptr, unsigned long int, mpz_srcptr);
 void __gmpz_submul (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_submul_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_swap (mpz_ptr, mpz_ptr) ;
 unsigned long int __gmpz_tdiv_ui (mpz_srcptr, unsigned long int) __attribute__ ((__pure__));
 void __gmpz_tdiv_q (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_tdiv_q_2exp (mpz_ptr, mpz_srcptr, unsigned long int);
 unsigned long int __gmpz_tdiv_q_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_tdiv_qr (mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr);
 unsigned long int __gmpz_tdiv_qr_ui (mpz_ptr, mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_tdiv_r (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_tdiv_r_2exp (mpz_ptr, mpz_srcptr, unsigned long int);
 unsigned long int __gmpz_tdiv_r_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 int __gmpz_tstbit (mpz_srcptr, unsigned long int) __attribute__ ((__pure__));
 void __gmpz_ui_pow_ui (mpz_ptr, unsigned long int, unsigned long int);
 void __gmpz_urandomb (mpz_ptr, gmp_randstate_t, unsigned long int);
 void __gmpz_urandomm (mpz_ptr, gmp_randstate_t, mpz_srcptr);
 void __gmpz_xor (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpq_abs (mpq_ptr, mpq_srcptr);
 void __gmpq_add (mpq_ptr, mpq_srcptr, mpq_srcptr);
 void __gmpq_canonicalize (mpq_ptr);
 void __gmpq_clear (mpq_ptr);
 int __gmpq_cmp (mpq_srcptr, mpq_srcptr) __attribute__ ((__pure__));
 int __gmpq_cmp_si (mpq_srcptr, long, unsigned long) __attribute__ ((__pure__));
 int __gmpq_cmp_ui (mpq_srcptr, unsigned long int, unsigned long int) __attribute__ ((__pure__));
 void __gmpq_div (mpq_ptr, mpq_srcptr, mpq_srcptr);
 void __gmpq_div_2exp (mpq_ptr, mpq_srcptr, unsigned long);
 int __gmpq_equal (mpq_srcptr, mpq_srcptr) __attribute__ ((__pure__));
 void __gmpq_get_num (mpz_ptr, mpq_srcptr);
 void __gmpq_get_den (mpz_ptr, mpq_srcptr);
 double __gmpq_get_d (mpq_srcptr) __attribute__ ((__pure__));
 char *__gmpq_get_str (char *, int, mpq_srcptr);
 void __gmpq_init (mpq_ptr);
 size_t __gmpq_inp_str (mpq_ptr, FILE *, int);
 void __gmpq_inv (mpq_ptr, mpq_srcptr);
 void __gmpq_mul (mpq_ptr, mpq_srcptr, mpq_srcptr);
 void __gmpq_mul_2exp (mpq_ptr, mpq_srcptr, unsigned long);
 void __gmpq_neg (mpq_ptr, mpq_srcptr);
 size_t __gmpq_out_str (FILE *, int, mpq_srcptr);
 void __gmpq_set (mpq_ptr, mpq_srcptr);
 void __gmpq_set_d (mpq_ptr, double);
 void __gmpq_set_den (mpq_ptr, mpz_srcptr);
 void __gmpq_set_f (mpq_ptr, mpf_srcptr);
 void __gmpq_set_num (mpq_ptr, mpz_srcptr);
 void __gmpq_set_si (mpq_ptr, signed long int, unsigned long int);
 int __gmpq_set_str (mpq_ptr, const char *, int);
 void __gmpq_set_ui (mpq_ptr, unsigned long int, unsigned long int);
 void __gmpq_set_z (mpq_ptr, mpz_srcptr);
 void __gmpq_sub (mpq_ptr, mpq_srcptr, mpq_srcptr);
 void __gmpq_swap (mpq_ptr, mpq_ptr) ;
 void __gmpf_abs (mpf_ptr, mpf_srcptr);
 void __gmpf_add (mpf_ptr, mpf_srcptr, mpf_srcptr);
 void __gmpf_add_ui (mpf_ptr, mpf_srcptr, unsigned long int);
 void __gmpf_ceil (mpf_ptr, mpf_srcptr);
 void __gmpf_clear (mpf_ptr);
 int __gmpf_cmp (mpf_srcptr, mpf_srcptr) __attribute__ ((__pure__));
 int __gmpf_cmp_d (mpf_srcptr, double) __attribute__ ((__pure__));
 int __gmpf_cmp_si (mpf_srcptr, signed long int) __attribute__ ((__pure__));
 int __gmpf_cmp_ui (mpf_srcptr, unsigned long int) __attribute__ ((__pure__));
 void __gmpf_div (mpf_ptr, mpf_srcptr, mpf_srcptr);
 void __gmpf_div_2exp (mpf_ptr, mpf_srcptr, unsigned long int);
 void __gmpf_div_ui (mpf_ptr, mpf_srcptr, unsigned long int);
 void __gmpf_dump (mpf_srcptr);
 int __gmpf_eq (mpf_srcptr, mpf_srcptr, unsigned long int) __attribute__ ((__pure__));
 int __gmpf_fits_sint_p (mpf_srcptr) __attribute__ ((__pure__));
 int __gmpf_fits_slong_p (mpf_srcptr) __attribute__ ((__pure__));
 int __gmpf_fits_sshort_p (mpf_srcptr) __attribute__ ((__pure__));
 int __gmpf_fits_uint_p (mpf_srcptr) __attribute__ ((__pure__));
 int __gmpf_fits_ulong_p (mpf_srcptr) __attribute__ ((__pure__));
 int __gmpf_fits_ushort_p (mpf_srcptr) __attribute__ ((__pure__));
 void __gmpf_floor (mpf_ptr, mpf_srcptr);
 double __gmpf_get_d (mpf_srcptr) __attribute__ ((__pure__));
 double __gmpf_get_d_2exp (signed long int *, mpf_srcptr);
 unsigned long int __gmpf_get_default_prec (void) __attribute__ ((__pure__));
 unsigned long int __gmpf_get_prec (mpf_srcptr) __attribute__ ((__pure__));
 long __gmpf_get_si (mpf_srcptr) __attribute__ ((__pure__));
 char *__gmpf_get_str (char *, mp_exp_t *, int, size_t, mpf_srcptr);
 unsigned long __gmpf_get_ui (mpf_srcptr) __attribute__ ((__pure__));
 void __gmpf_init (mpf_ptr);
 void __gmpf_init2 (mpf_ptr, unsigned long int);
 void __gmpf_init_set (mpf_ptr, mpf_srcptr);
 void __gmpf_init_set_d (mpf_ptr, double);
 void __gmpf_init_set_si (mpf_ptr, signed long int);
 int __gmpf_init_set_str (mpf_ptr, const char *, int);
 void __gmpf_init_set_ui (mpf_ptr, unsigned long int);
 size_t __gmpf_inp_str (mpf_ptr, FILE *, int);
 int __gmpf_integer_p (mpf_srcptr) __attribute__ ((__pure__));
 void __gmpf_mul (mpf_ptr, mpf_srcptr, mpf_srcptr);
 void __gmpf_mul_2exp (mpf_ptr, mpf_srcptr, unsigned long int);
 void __gmpf_mul_ui (mpf_ptr, mpf_srcptr, unsigned long int);
 void __gmpf_neg (mpf_ptr, mpf_srcptr);
 size_t __gmpf_out_str (FILE *, int, size_t, mpf_srcptr);
 void __gmpf_pow_ui (mpf_ptr, mpf_srcptr, unsigned long int);
 void __gmpf_random2 (mpf_ptr, mp_size_t, mp_exp_t);
 void __gmpf_reldiff (mpf_ptr, mpf_srcptr, mpf_srcptr);
 void __gmpf_set (mpf_ptr, mpf_srcptr);
 void __gmpf_set_d (mpf_ptr, double);
 void __gmpf_set_default_prec (unsigned long int) ;
 void __gmpf_set_prec (mpf_ptr, unsigned long int);
 void __gmpf_set_prec_raw (mpf_ptr, unsigned long int) ;
 void __gmpf_set_q (mpf_ptr, mpq_srcptr);
 void __gmpf_set_si (mpf_ptr, signed long int);
 int __gmpf_set_str (mpf_ptr, const char *, int);
 void __gmpf_set_ui (mpf_ptr, unsigned long int);
 void __gmpf_set_z (mpf_ptr, mpz_srcptr);
 size_t __gmpf_size (mpf_srcptr) __attribute__ ((__pure__));
 void __gmpf_sqrt (mpf_ptr, mpf_srcptr);
 void __gmpf_sqrt_ui (mpf_ptr, unsigned long int);
 void __gmpf_sub (mpf_ptr, mpf_srcptr, mpf_srcptr);
 void __gmpf_sub_ui (mpf_ptr, mpf_srcptr, unsigned long int);
 void __gmpf_swap (mpf_ptr, mpf_ptr) ;
 void __gmpf_trunc (mpf_ptr, mpf_srcptr);
 void __gmpf_ui_div (mpf_ptr, unsigned long int, mpf_srcptr);
 void __gmpf_ui_sub (mpf_ptr, unsigned long int, mpf_srcptr);
 void __gmpf_urandomb (mpf_t, gmp_randstate_t, unsigned long int);
# 1480 "/usr/include/gmp-i386.h" 3 4
 mp_limb_t __gmpn_add (mp_ptr, mp_srcptr, mp_size_t, mp_srcptr,mp_size_t);
 mp_limb_t __gmpn_add_1 (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t) ;
 mp_limb_t __gmpn_add_n (mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);
 mp_limb_t __gmpn_addmul_1 (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);
 mp_limb_t __gmpn_bdivmod (mp_ptr, mp_ptr, mp_size_t, mp_srcptr, mp_size_t, unsigned long int);
 int __gmpn_cmp (mp_srcptr, mp_srcptr, mp_size_t) __attribute__ ((__pure__));
 mp_limb_t __gmpn_divexact_by3c (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);
 mp_limb_t __gmpn_divrem (mp_ptr, mp_size_t, mp_ptr, mp_size_t, mp_srcptr, mp_size_t);
 mp_limb_t __gmpn_divrem_1 (mp_ptr, mp_size_t, mp_srcptr, mp_size_t, mp_limb_t);
 mp_limb_t __gmpn_divrem_2 (mp_ptr, mp_size_t, mp_ptr, mp_size_t, mp_srcptr);
 mp_size_t __gmpn_gcd (mp_ptr, mp_ptr, mp_size_t, mp_ptr, mp_size_t);
 mp_limb_t __gmpn_gcd_1 (mp_srcptr, mp_size_t, mp_limb_t) __attribute__ ((__pure__));
 mp_limb_t __gmpn_gcdext_1 (mp_limb_signed_t *, mp_limb_signed_t *, mp_limb_t, mp_limb_t);
 mp_size_t __gmpn_gcdext (mp_ptr, mp_ptr, mp_size_t *, mp_ptr, mp_size_t, mp_ptr, mp_size_t);
 size_t __gmpn_get_str (unsigned char *, int, mp_ptr, mp_size_t);
 unsigned long int __gmpn_hamdist (mp_srcptr, mp_srcptr, mp_size_t) __attribute__ ((__pure__));
 mp_limb_t __gmpn_lshift (mp_ptr, mp_srcptr, mp_size_t, unsigned int);
 mp_limb_t __gmpn_mod_1 (mp_srcptr, mp_size_t, mp_limb_t) __attribute__ ((__pure__));
 mp_limb_t __gmpn_mul (mp_ptr, mp_srcptr, mp_size_t, mp_srcptr, mp_size_t);
 mp_limb_t __gmpn_mul_1 (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);
 void __gmpn_mul_n (mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);
 void __gmpn_sqr (mp_ptr, mp_srcptr, mp_size_t);
 mp_limb_t __gmpn_neg_n (mp_ptr, mp_srcptr, mp_size_t);
 int __gmpn_perfect_square_p (mp_srcptr, mp_size_t) __attribute__ ((__pure__));
 unsigned long int __gmpn_popcount (mp_srcptr, mp_size_t) __attribute__ ((__pure__));
 mp_size_t __gmpn_pow_1 (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t, mp_ptr);
 mp_limb_t __gmpn_preinv_mod_1 (mp_srcptr, mp_size_t, mp_limb_t, mp_limb_t) __attribute__ ((__pure__));
 void __gmpn_random (mp_ptr, mp_size_t);
 void __gmpn_random2 (mp_ptr, mp_size_t);
 mp_limb_t __gmpn_rshift (mp_ptr, mp_srcptr, mp_size_t, unsigned int);
 unsigned long int __gmpn_scan0 (mp_srcptr, unsigned long int) __attribute__ ((__pure__));
 unsigned long int __gmpn_scan1 (mp_srcptr, unsigned long int) __attribute__ ((__pure__));
 mp_size_t __gmpn_set_str (mp_ptr, const unsigned char *, size_t, int);
 mp_size_t __gmpn_sqrtrem (mp_ptr, mp_ptr, mp_srcptr, mp_size_t);
 mp_limb_t __gmpn_sub (mp_ptr, mp_srcptr, mp_size_t, mp_srcptr,mp_size_t);
 mp_limb_t __gmpn_sub_1 (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t) ;
 mp_limb_t __gmpn_sub_n (mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);
 mp_limb_t __gmpn_submul_1 (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);
 void __gmpn_tdiv_qr (mp_ptr, mp_ptr, mp_size_t, mp_srcptr, mp_size_t, mp_srcptr, mp_size_t);
# 1632 "/usr/include/gmp-i386.h" 3 4
extern __inline__ void
__gmpz_abs (mpz_ptr __gmp_w, mpz_srcptr __gmp_u)
{
  if (__gmp_w != __gmp_u)
    __gmpz_set (__gmp_w, __gmp_u);
  __gmp_w->_mp_size = ((__gmp_w->_mp_size) >= 0 ? (__gmp_w->_mp_size) : -(__gmp_w->_mp_size));
}
# 1656 "/usr/include/gmp-i386.h" 3 4
extern __inline__
int
__gmpz_fits_uint_p (mpz_srcptr __gmp_z)
{
  mp_size_t __gmp_n = __gmp_z->_mp_size; mp_ptr __gmp_p = __gmp_z->_mp_d; return (__gmp_n == 0 || (__gmp_n == 1 && __gmp_p[0] <= (~ (unsigned) 0)));;
}
extern __inline__
int
__gmpz_fits_ulong_p (mpz_srcptr __gmp_z)
{
  mp_size_t __gmp_n = __gmp_z->_mp_size; mp_ptr __gmp_p = __gmp_z->_mp_d; return (__gmp_n == 0 || (__gmp_n == 1 && __gmp_p[0] <= (~ (unsigned long) 0)));;
}
extern __inline__
int
__gmpz_fits_ushort_p (mpz_srcptr __gmp_z)
{
  mp_size_t __gmp_n = __gmp_z->_mp_size; mp_ptr __gmp_p = __gmp_z->_mp_d; return (__gmp_n == 0 || (__gmp_n == 1 && __gmp_p[0] <= ((unsigned short) ~0)));;
}
extern __inline__
unsigned long
__gmpz_get_ui (mpz_srcptr __gmp_z)
{
  mp_ptr __gmp_p = __gmp_z->_mp_d;
  mp_size_t __gmp_n = __gmp_z->_mp_size;
  mp_limb_t __gmp_l = __gmp_p[0];
  return (__gmp_n != 0 ? __gmp_l : 0);
# 1712 "/usr/include/gmp-i386.h" 3 4
}
extern __inline__
mp_limb_t
__gmpz_getlimbn (mpz_srcptr __gmp_z, mp_size_t __gmp_n)
{
  mp_limb_t __gmp_result = 0;
  if (__builtin_expect ((__gmp_n >= 0 && __gmp_n < ((__gmp_z->_mp_size) >= 0 ? (__gmp_z->_mp_size) : -(__gmp_z->_mp_size))) != 0, 1))
    __gmp_result = __gmp_z->_mp_d[__gmp_n];
  return __gmp_result;
}
extern __inline__ void
__gmpz_neg (mpz_ptr __gmp_w, mpz_srcptr __gmp_u)
{
  if (__gmp_w != __gmp_u)
    __gmpz_set (__gmp_w, __gmp_u);
  __gmp_w->_mp_size = - __gmp_w->_mp_size;
}
extern __inline__
int
__gmpz_perfect_square_p (mpz_srcptr __gmp_a)
{
  mp_size_t __gmp_asize;
  int __gmp_result;
  __gmp_asize = __gmp_a->_mp_size;
  __gmp_result = (__gmp_asize >= 0);
  if (__builtin_expect ((__gmp_asize > 0) != 0, 1))
    __gmp_result = __gmpn_perfect_square_p (__gmp_a->_mp_d, __gmp_asize);
  return __gmp_result;
}
extern __inline__
unsigned long
__gmpz_popcount (mpz_srcptr __gmp_u)
{
  mp_size_t __gmp_usize;
  unsigned long __gmp_result;
  __gmp_usize = __gmp_u->_mp_size;
  __gmp_result = (__gmp_usize < 0 ? (~ (unsigned long) 0) : 0);
  if (__builtin_expect ((__gmp_usize > 0) != 0, 1))
    __gmp_result = __gmpn_popcount (__gmp_u->_mp_d, __gmp_usize);
  return __gmp_result;
}
extern __inline__
void
__gmpz_set_q (mpz_ptr __gmp_w, mpq_srcptr __gmp_u)
{
  __gmpz_tdiv_q (__gmp_w, (&((__gmp_u)->_mp_num)), (&((__gmp_u)->_mp_den)));
}
extern __inline__
size_t
__gmpz_size (mpz_srcptr __gmp_z)
{
  return ((__gmp_z->_mp_size) >= 0 ? (__gmp_z->_mp_size) : -(__gmp_z->_mp_size));
}
extern __inline__ void
__gmpq_abs (mpq_ptr __gmp_w, mpq_srcptr __gmp_u)
{
  if (__gmp_w != __gmp_u)
    __gmpq_set (__gmp_w, __gmp_u);
  __gmp_w->_mp_num._mp_size = ((__gmp_w->_mp_num._mp_size) >= 0 ? (__gmp_w->_mp_num._mp_size) : -(__gmp_w->_mp_num._mp_size));
}
extern __inline__ void
__gmpq_neg (mpq_ptr __gmp_w, mpq_srcptr __gmp_u)
{
  if (__gmp_w != __gmp_u)
    __gmpq_set (__gmp_w, __gmp_u);
  __gmp_w->_mp_num._mp_size = - __gmp_w->_mp_num._mp_size;
}
# 2054 "/usr/include/gmp-i386.h" 3 4
extern __inline__
mp_limb_t
__gmpn_add (mp_ptr __gmp_wp, mp_srcptr __gmp_xp, mp_size_t __gmp_xsize, mp_srcptr __gmp_yp, mp_size_t __gmp_ysize)
{
  mp_limb_t __gmp_c;
  do { mp_size_t __gmp_i; mp_limb_t __gmp_x; __gmp_i = (__gmp_ysize); if (__gmp_i != 0) { if (__gmpn_add_n (__gmp_wp, __gmp_xp, __gmp_yp, __gmp_i)) { do { if (__gmp_i >= (__gmp_xsize)) { (__gmp_c) = 1; goto __gmp_done; } __gmp_x = (__gmp_xp)[__gmp_i]; } while ((((__gmp_wp)[__gmp_i++] = (__gmp_x + 1) & ((~ ((mp_limb_t) (0))) >> 0)) == 0)); } } if ((__gmp_wp) != (__gmp_xp)) do { mp_size_t __gmp_j; ; for (__gmp_j = (__gmp_i); __gmp_j < (__gmp_xsize); __gmp_j++) (__gmp_wp)[__gmp_j] = (__gmp_xp)[__gmp_j]; } while (0); (__gmp_c) = 0; __gmp_done: ; } while (0);
  return __gmp_c;
}
extern __inline__
mp_limb_t
__gmpn_add_1 (mp_ptr __gmp_dst, mp_srcptr __gmp_src, mp_size_t __gmp_size, mp_limb_t __gmp_n)
{
  mp_limb_t __gmp_c;
  do { mp_size_t __gmp_i; mp_limb_t __gmp_x, __gmp_r; __gmp_x = (__gmp_src)[0]; __gmp_r = __gmp_x + (__gmp_n); (__gmp_dst)[0] = __gmp_r; if (((__gmp_r) < ((__gmp_n)))) { (__gmp_c) = 1; for (__gmp_i = 1; __gmp_i < (__gmp_size);) { __gmp_x = (__gmp_src)[__gmp_i]; __gmp_r = __gmp_x + 1; (__gmp_dst)[__gmp_i] = __gmp_r; ++__gmp_i; if (!((__gmp_r) < (1))) { if ((__gmp_src) != (__gmp_dst)) do { mp_size_t __gmp_j; ; for (__gmp_j = (__gmp_i); __gmp_j < (__gmp_size); __gmp_j++) (__gmp_dst)[__gmp_j] = (__gmp_src)[__gmp_j]; } while (0); (__gmp_c) = 0; break; } } } else { if ((__gmp_src) != (__gmp_dst)) do { mp_size_t __gmp_j; ; for (__gmp_j = (1); __gmp_j < (__gmp_size); __gmp_j++) (__gmp_dst)[__gmp_j] = (__gmp_src)[__gmp_j]; } while (0); (__gmp_c) = 0; } } while (0);
  return __gmp_c;
}
extern __inline__
int
__gmpn_cmp (mp_srcptr __gmp_xp, mp_srcptr __gmp_yp, mp_size_t __gmp_size)
{
  int __gmp_result;
  do { mp_size_t __gmp_i; mp_limb_t __gmp_x, __gmp_y; (__gmp_result) = 0; __gmp_i = (__gmp_size); while (--__gmp_i >= 0) { __gmp_x = (__gmp_xp)[__gmp_i]; __gmp_y = (__gmp_yp)[__gmp_i]; if (__gmp_x != __gmp_y) { (__gmp_result) = (__gmp_x > __gmp_y ? 1 : -1); break; } } } while (0);
  return __gmp_result;
}
extern __inline__
mp_limb_t
__gmpn_sub (mp_ptr __gmp_wp, mp_srcptr __gmp_xp, mp_size_t __gmp_xsize, mp_srcptr __gmp_yp, mp_size_t __gmp_ysize)
{
  mp_limb_t __gmp_c;
  do { mp_size_t __gmp_i; mp_limb_t __gmp_x; __gmp_i = (__gmp_ysize); if (__gmp_i != 0) { if (__gmpn_sub_n (__gmp_wp, __gmp_xp, __gmp_yp, __gmp_i)) { do { if (__gmp_i >= (__gmp_xsize)) { (__gmp_c) = 1; goto __gmp_done; } __gmp_x = (__gmp_xp)[__gmp_i]; } while ((((__gmp_wp)[__gmp_i++] = (__gmp_x - 1) & ((~ ((mp_limb_t) (0))) >> 0)), __gmp_x == 0)); } } if ((__gmp_wp) != (__gmp_xp)) do { mp_size_t __gmp_j; ; for (__gmp_j = (__gmp_i); __gmp_j < (__gmp_xsize); __gmp_j++) (__gmp_wp)[__gmp_j] = (__gmp_xp)[__gmp_j]; } while (0); (__gmp_c) = 0; __gmp_done: ; } while (0);
  return __gmp_c;
}
extern __inline__
mp_limb_t
__gmpn_sub_1 (mp_ptr __gmp_dst, mp_srcptr __gmp_src, mp_size_t __gmp_size, mp_limb_t __gmp_n)
{
  mp_limb_t __gmp_c;
  do { mp_size_t __gmp_i; mp_limb_t __gmp_x, __gmp_r; __gmp_x = (__gmp_src)[0]; __gmp_r = __gmp_x - (__gmp_n); (__gmp_dst)[0] = __gmp_r; if (((__gmp_x) < ((__gmp_n)))) { (__gmp_c) = 1; for (__gmp_i = 1; __gmp_i < (__gmp_size);) { __gmp_x = (__gmp_src)[__gmp_i]; __gmp_r = __gmp_x - 1; (__gmp_dst)[__gmp_i] = __gmp_r; ++__gmp_i; if (!((__gmp_x) < (1))) { if ((__gmp_src) != (__gmp_dst)) do { mp_size_t __gmp_j; ; for (__gmp_j = (__gmp_i); __gmp_j < (__gmp_size); __gmp_j++) (__gmp_dst)[__gmp_j] = (__gmp_src)[__gmp_j]; } while (0); (__gmp_c) = 0; break; } } } else { if ((__gmp_src) != (__gmp_dst)) do { mp_size_t __gmp_j; ; for (__gmp_j = (1); __gmp_j < (__gmp_size); __gmp_j++) (__gmp_dst)[__gmp_j] = (__gmp_src)[__gmp_j]; } while (0); (__gmp_c) = 0; } } while (0);
  return __gmp_c;
}
extern __inline__
mp_limb_t
__gmpn_neg_n (mp_ptr __gmp_rp, mp_srcptr __gmp_up, mp_size_t __gmp_n)
{
  mp_limb_t __gmp_ul, __gmp_cy;
  __gmp_cy = 0;
  do {
      __gmp_ul = *__gmp_up++;
      *__gmp_rp++ = -__gmp_ul - __gmp_cy;
      __gmp_cy |= __gmp_ul != 0;
  } while (--__gmp_n != 0);
  return __gmp_cy;
}
# 2211 "/usr/include/gmp-i386.h" 3 4
enum
{
  GMP_ERROR_NONE = 0,
  GMP_ERROR_UNSUPPORTED_ARGUMENT = 1,
  GMP_ERROR_DIVISION_BY_ZERO = 2,
  GMP_ERROR_SQRT_OF_NEGATIVE = 4,
  GMP_ERROR_INVALID_ARGUMENT = 8
};
# 44 "/usr/include/gmp.h" 2 3 4
# 25 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/double-int.h" 2
# 54 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/double-int.h"
typedef struct
{
  unsigned long long low;
  long long high;
} double_int;
# 67 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/double-int.h"
static __inline__ double_int
shwi_to_double_int (long long cst)
{
  double_int r;
  r.low = (unsigned long long) cst;
  r.high = cst < 0 ? -1 : 0;
  return r;
}
# 89 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/double-int.h"
static __inline__ double_int
uhwi_to_double_int (unsigned long long cst)
{
  double_int r;
  r.low = cst;
  r.high = 0;
  return r;
}
static __inline__ long long
double_int_to_shwi (double_int cst)
{
  return (long long) cst.low;
}
static __inline__ unsigned long long
double_int_to_uhwi (double_int cst)
{
  return cst.low;
}
unsigned char double_int_fits_in_hwi_p (double_int, unsigned char);
unsigned char double_int_fits_in_shwi_p (double_int);
static __inline__ unsigned char
double_int_fits_in_uhwi_p (double_int cst)
{
  return cst.high == 0;
}
double_int double_int_mul (double_int, double_int);
double_int double_int_mul_with_sign (double_int, double_int, unsigned char, int *);
double_int double_int_add (double_int, double_int);
double_int double_int_sub (double_int, double_int);
double_int double_int_neg (double_int);
double_int double_int_div (double_int, double_int, unsigned char, unsigned);
double_int double_int_sdiv (double_int, double_int, unsigned);
double_int double_int_udiv (double_int, double_int, unsigned);
double_int double_int_mod (double_int, double_int, unsigned char, unsigned);
double_int double_int_smod (double_int, double_int, unsigned);
double_int double_int_umod (double_int, double_int, unsigned);
double_int double_int_divmod (double_int, double_int, unsigned char, unsigned, double_int *);
double_int double_int_sdivmod (double_int, double_int, unsigned, double_int *);
double_int double_int_udivmod (double_int, double_int, unsigned, double_int *);
double_int double_int_setbit (double_int, unsigned);
int double_int_ctz (double_int);
static __inline__ double_int
double_int_not (double_int a)
{
  a.low = ~a.low;
  a.high = ~a.high;
  return a;
}
static __inline__ double_int
double_int_ior (double_int a, double_int b)
{
  a.low |= b.low;
  a.high |= b.high;
  return a;
}
static __inline__ double_int
double_int_and (double_int a, double_int b)
{
  a.low &= b.low;
  a.high &= b.high;
  return a;
}
static __inline__ double_int
double_int_and_not (double_int a, double_int b)
{
  a.low &= ~b.low;
  a.high &= ~b.high;
  return a;
}
static __inline__ double_int
double_int_xor (double_int a, double_int b)
{
  a.low ^= b.low;
  a.high ^= b.high;
  return a;
}
double_int double_int_lshift (double_int, long long, unsigned int, unsigned char);
double_int double_int_rshift (double_int, long long, unsigned int, unsigned char);
double_int double_int_lrotate (double_int, long long, unsigned int);
double_int double_int_rrotate (double_int, long long, unsigned int);
static __inline__ unsigned char
double_int_negative_p (double_int cst)
{
  return cst.high < 0;
}
int double_int_cmp (double_int, double_int, unsigned char);
int double_int_scmp (double_int, double_int);
int double_int_ucmp (double_int, double_int);
double_int double_int_max (double_int, double_int, unsigned char);
double_int double_int_smax (double_int, double_int);
double_int double_int_umax (double_int, double_int);
double_int double_int_min (double_int, double_int, unsigned char);
double_int double_int_smin (double_int, double_int);
double_int double_int_umin (double_int, double_int);
void dump_double_int (FILE *, double_int, unsigned char);
double_int double_int_ext (double_int, unsigned, unsigned char);
double_int double_int_sext (double_int, unsigned);
double_int double_int_zext (double_int, unsigned);
double_int double_int_mask (unsigned);
# 253 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/double-int.h"
static __inline__ unsigned char
double_int_zero_p (double_int cst)
{
  return cst.low == 0 && cst.high == 0;
}
static __inline__ unsigned char
double_int_one_p (double_int cst)
{
  return cst.low == 1 && cst.high == 0;
}
static __inline__ unsigned char
double_int_minus_one_p (double_int cst)
{
  return (cst.low == (~((unsigned long long) 0)) && cst.high == -1);
}
static __inline__ unsigned char
double_int_equal_p (double_int cst1, double_int cst2)
{
  return cst1.low == cst2.low && cst1.high == cst2.high;
}
extern int add_double_with_sign (unsigned long long, long long,
     unsigned long long, long long,
     unsigned long long *, long long *,
     unsigned char);
extern int neg_double (unsigned long long, long long,
         unsigned long long *, long long *);
extern int mul_double_with_sign (unsigned long long, long long,
     unsigned long long, long long,
     unsigned long long *, long long *,
     unsigned char);
extern void lshift_double (unsigned long long, long long,
      long long, unsigned int,
      unsigned long long *, long long *, unsigned char);
extern void rshift_double (unsigned long long, long long,
      long long, unsigned int,
      unsigned long long *, long long *, unsigned char);
extern int div_and_round_double (unsigned, int, unsigned long long,
     long long, unsigned long long,
     long long, unsigned long long *,
     long long *, unsigned long long *,
     long long *);
void mpz_set_double_int (mpz_t, double_int, unsigned char);
double_int mpz_get_double_int (const_tree, mpz_t, unsigned char);
# 32 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/real.h" 1
# 30 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/real.h"
enum real_value_class {
  rvc_zero,
  rvc_normal,
  rvc_inf,
  rvc_nan
};
struct real_value {
  unsigned int cl : 2;
  unsigned int decimal : 1;
  unsigned int sign : 1;
  unsigned int signalling : 1;
  unsigned int canonical : 1;
  unsigned int uexp : (32 - 6);
  unsigned long sig[((128 + (8 * 4)) / (8 * 4))];
};
# 77 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/real.h"
extern char test_real_width
  [sizeof(struct real_value) <= (((128 + (8 * 4)) + 32)/(8 * 8) + (((128 + (8 * 4)) + 32)%(8 * 8) ? 1 : 0))*sizeof(long long) ? 1 : -1];
# 115 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/real.h"
struct real_format
{
  void (*encode) (const struct real_format *, long *,
    const struct real_value *);
  void (*decode) (const struct real_format *, struct real_value *,
    const long *);
  int b;
  int p;
  int pnan;
  int emin;
  int emax;
  int signbit_ro;
  int signbit_rw;
  unsigned char round_towards_zero;
  unsigned char has_sign_dependent_rounding;
  unsigned char has_nans;
  unsigned char has_inf;
  unsigned char has_denorm;
  unsigned char has_signed_zero;
  unsigned char qnan_msb_set;
  unsigned char canonical_nan_lsbs_set;
};
extern const struct real_format *
  real_format_for_mode[MAX_MODE_FLOAT - MIN_MODE_FLOAT + 1
         + MAX_MODE_DECIMAL_FLOAT - MIN_MODE_DECIMAL_FLOAT + 1];
# 226 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/real.h"
extern unsigned char real_arithmetic (struct real_value *, int, const struct real_value *,
        const struct real_value *);
extern unsigned char real_compare (int, const struct real_value *, const struct real_value *);
extern unsigned char real_isinf (const struct real_value *);
extern unsigned char real_isnan (const struct real_value *);
extern unsigned char real_isfinite (const struct real_value *);
extern unsigned char real_isneg (const struct real_value *);
extern unsigned char real_isnegzero (const struct real_value *);
extern unsigned char real_identical (const struct real_value *, const struct real_value *);
extern void real_convert (struct real_value *, enum machine_mode,
     const struct real_value *);
extern unsigned char exact_real_truncate (enum machine_mode, const struct real_value *);
extern void real_to_decimal (char *, const struct real_value *, size_t,
        size_t, int);
extern void real_to_decimal_for_mode (char *, const struct real_value *, size_t,
          size_t, int, enum machine_mode);
extern void real_to_hexadecimal (char *, const struct real_value *,
     size_t, size_t, int);
extern long long real_to_integer (const struct real_value *);
extern void real_to_integer2 (long long *, long long *,
         const struct real_value *);
extern int real_from_string (struct real_value *, const char *);
extern void real_from_string3 (struct real_value *, const char *, enum machine_mode);
extern void real_from_integer (struct real_value *, enum machine_mode,
          unsigned long long, long long, int);
extern long real_to_target_fmt (long *, const struct real_value *,
    const struct real_format *);
extern long real_to_target (long *, const struct real_value *, enum machine_mode);
extern void real_from_target_fmt (struct real_value *, const long *,
      const struct real_format *);
extern void real_from_target (struct real_value *, const long *,
         enum machine_mode);
extern void real_inf (struct real_value *);
extern unsigned char real_nan (struct real_value *, const char *, int, enum machine_mode);
extern void real_maxval (struct real_value *, int, enum machine_mode);
extern void real_2expN (struct real_value *, int, enum machine_mode);
extern unsigned int real_hash (const struct real_value *);
extern const struct real_format ieee_single_format;
extern const struct real_format mips_single_format;
extern const struct real_format motorola_single_format;
extern const struct real_format spu_single_format;
extern const struct real_format ieee_double_format;
extern const struct real_format mips_double_format;
extern const struct real_format motorola_double_format;
extern const struct real_format ieee_extended_motorola_format;
extern const struct real_format ieee_extended_intel_96_format;
extern const struct real_format ieee_extended_intel_96_round_53_format;
extern const struct real_format ieee_extended_intel_128_format;
extern const struct real_format ibm_extended_format;
extern const struct real_format mips_extended_format;
extern const struct real_format ieee_quad_format;
extern const struct real_format mips_quad_format;
extern const struct real_format vax_f_format;
extern const struct real_format vax_d_format;
extern const struct real_format vax_g_format;
extern const struct real_format real_internal_format;
extern const struct real_format decimal_single_format;
extern const struct real_format decimal_double_format;
extern const struct real_format decimal_quad_format;
extern const struct real_format ieee_half_format;
extern const struct real_format arm_half_format;
# 385 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/real.h"
extern struct real_value real_value_truncate (enum machine_mode,
         struct real_value);
extern struct real_value real_value_negate (const struct real_value *);
extern struct real_value real_value_abs (const struct real_value *);
extern int significand_size (enum machine_mode);
extern struct real_value real_from_string2 (const char *, enum machine_mode);
# 414 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/real.h"
extern int real_exponent (const struct real_value *);
extern void real_ldexp (struct real_value *, const struct real_value *, int);
extern struct real_value dconst0;
extern struct real_value dconst1;
extern struct real_value dconst2;
extern struct real_value dconstm1;
extern struct real_value dconsthalf;
extern const struct real_value * dconst_e_ptr (void);
extern const struct real_value * dconst_third_ptr (void);
extern const struct real_value * dconst_sqrt2_ptr (void);
struct real_value real_value_from_int_cst (const_tree, const_tree);
# 453 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/real.h"
extern rtx const_double_from_real_value (struct real_value, enum machine_mode);
extern unsigned char exact_real_inverse (enum machine_mode, struct real_value *);
unsigned char real_can_shorten_arithmetic (enum machine_mode, enum machine_mode);
extern tree build_real (tree, struct real_value);
extern unsigned char real_sqrt (struct real_value *, enum machine_mode,
         const struct real_value *);
extern unsigned char real_powi (struct real_value *, enum machine_mode,
         const struct real_value *, long long);
extern void real_trunc (struct real_value *, enum machine_mode,
   const struct real_value *);
extern void real_floor (struct real_value *, enum machine_mode,
   const struct real_value *);
extern void real_ceil (struct real_value *, enum machine_mode,
         const struct real_value *);
extern void real_round (struct real_value *, enum machine_mode,
   const struct real_value *);
extern void real_copysign (struct real_value *, const struct real_value *);
extern unsigned char real_isinteger (const struct real_value *c, enum machine_mode mode);
extern void get_max_float (const struct real_format *, char *, size_t);
# 33 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/fixed-value.h" 1
# 27 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/fixed-value.h"
struct fixed_value
{
  double_int data;
  enum machine_mode mode;
};
# 40 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/fixed-value.h"
extern struct fixed_value fconst0[18];
extern struct fixed_value fconst1[8];
# 50 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/fixed-value.h"
extern rtx const_fixed_from_fixed_value (struct fixed_value, enum machine_mode);
extern void fixed_from_string (struct fixed_value *, const char *,
          enum machine_mode);
extern tree build_fixed (tree, struct fixed_value);
extern unsigned char fixed_convert (struct fixed_value *, enum machine_mode,
      const struct fixed_value *, unsigned char);
extern unsigned char fixed_convert_from_int (struct fixed_value *, enum machine_mode,
        double_int, unsigned char, unsigned char);
extern unsigned char fixed_convert_from_real (struct fixed_value *, enum machine_mode,
         const struct real_value *, unsigned char);
extern void real_convert_from_fixed (struct real_value *, enum machine_mode,
         const struct fixed_value *);
extern unsigned char fixed_identical (const struct fixed_value *, const struct fixed_value *);
extern unsigned int fixed_hash (const struct fixed_value *);
extern void fixed_to_decimal (char *str, const struct fixed_value *, size_t);
extern unsigned char fixed_arithmetic (struct fixed_value *, int, const struct fixed_value *,
         const struct fixed_value *, unsigned char);
extern unsigned char fixed_compare (int, const struct fixed_value *,
      const struct fixed_value *);
extern unsigned char fixed_isneg (const struct fixed_value *);
# 34 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/alias.h" 1
# 31 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/alias.h"
typedef int alias_set_type;
extern alias_set_type new_alias_set (void);
extern alias_set_type get_alias_set (tree);
extern alias_set_type get_deref_alias_set (tree);
extern alias_set_type get_varargs_alias_set (void);
extern alias_set_type get_frame_alias_set (void);
extern unsigned char component_uses_parent_alias_set (const_tree);
extern unsigned char alias_set_subset_of (alias_set_type, alias_set_type);
extern void record_alias_subset (alias_set_type, alias_set_type);
extern void record_component_aliases (tree);
extern int alias_sets_conflict_p (alias_set_type, alias_set_type);
extern int alias_sets_must_conflict_p (alias_set_type, alias_set_type);
extern int objects_must_conflict_p (tree, tree);
extern int nonoverlapping_memrefs_p (const_rtx, const_rtx, unsigned char);
# 35 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/flags.h" 1
# 26 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/flags.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/flag-types.h" 1
# 25 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/flag-types.h"
enum debug_info_type
{
  NO_DEBUG,
  DBX_DEBUG,
  SDB_DEBUG,
  DWARF2_DEBUG,
  XCOFF_DEBUG,
  VMS_DEBUG,
  VMS_AND_DWARF2_DEBUG
};
enum debug_info_levels
{
  DINFO_LEVEL_NONE,
  DINFO_LEVEL_TERSE,
  DINFO_LEVEL_NORMAL,
  DINFO_LEVEL_VERBOSE
};
# 53 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/flag-types.h"
enum debug_info_usage
{
  DINFO_USAGE_DFN,
  DINFO_USAGE_DIR_USE,
  DINFO_USAGE_IND_USE,
  DINFO_USAGE_NUM_ENUMS
};
# 86 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/flag-types.h"
enum debug_struct_file
{
  DINFO_STRUCT_FILE_NONE,
  DINFO_STRUCT_FILE_BASE,
  DINFO_STRUCT_FILE_SYS,
  DINFO_STRUCT_FILE_ANY
};
enum symbol_visibility
{
  VISIBILITY_DEFAULT,
  VISIBILITY_PROTECTED,
  VISIBILITY_HIDDEN,
  VISIBILITY_INTERNAL
};
enum ira_algorithm
{
  IRA_ALGORITHM_CB,
  IRA_ALGORITHM_PRIORITY
};
enum ira_region
{
  IRA_REGION_ONE,
  IRA_REGION_ALL,
  IRA_REGION_MIXED,
  IRA_REGION_AUTODETECT
};
enum excess_precision
{
  EXCESS_PRECISION_DEFAULT,
  EXCESS_PRECISION_FAST,
  EXCESS_PRECISION_STANDARD
};
enum graph_dump_types
{
  no_graph = 0,
  vcg
};
enum stack_check_type
{
  NO_STACK_CHECK = 0,
  GENERIC_STACK_CHECK,
  STATIC_BUILTIN_STACK_CHECK,
  FULL_BUILTIN_STACK_CHECK
};
enum warn_strict_overflow_code
{
  WARN_STRICT_OVERFLOW_ALL = 1,
  WARN_STRICT_OVERFLOW_CONDITIONAL = 2,
  WARN_STRICT_OVERFLOW_COMPARISON = 3,
  WARN_STRICT_OVERFLOW_MISC = 4,
  WARN_STRICT_OVERFLOW_MAGNITUDE = 5
};
enum fp_contract_mode {
  FP_CONTRACT_OFF = 0,
  FP_CONTRACT_ON = 1,
  FP_CONTRACT_FAST = 2
};
enum vect_verbosity_levels {
  REPORT_NONE,
  REPORT_VECTORIZED_LOCATIONS,
  REPORT_UNVECTORIZED_LOCATIONS,
  REPORT_COST,
  REPORT_ALIGNMENT,
  REPORT_DR_DETAILS,
  REPORT_BAD_FORM_LOOPS,
  REPORT_OUTER_LOOPS,
  REPORT_SLP,
  REPORT_DETAILS,
  MAX_VERBOSITY_LEVEL
};
# 27 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/flags.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/options.h" 1
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm-opts.h" 1
# 26 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm-opts.h"
enum processor_type
{
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm-cores.def" 1
# 39 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm-cores.def"
arm2,
arm250,
arm3,
arm6,
arm60,
arm600,
arm610,
arm620,
arm7,
arm7d,
arm7di,
arm70,
arm700,
arm700i,
arm710,
arm720,
arm710c,
arm7100,
arm7500,
arm7500fe,
arm7m,
arm7dm,
arm7dmi,
arm8,
arm810,
strongarm,
strongarm110,
strongarm1100,
strongarm1110,
fa526,
fa626,
arm7tdmi,
arm7tdmis,
arm710t,
arm720t,
arm740t,
arm9,
arm9tdmi,
arm920,
arm920t,
arm922t,
arm940t,
ep9312,
arm10tdmi,
arm1020t,
arm9e,
arm946es,
arm966es,
arm968es,
arm10e,
arm1020e,
arm1022e,
xscale,
iwmmxt,
iwmmxt2,
fa606te,
fa626te,
fmp626,
fa726te,
arm926ejs,
arm1026ejs,
arm1136js,
arm1136jfs,
arm1176jzs,
arm1176jzfs,
mpcorenovfp,
mpcore,
arm1156t2s,
arm1156t2fs,
genericv7a,
cortexa5,
cortexa7,
cortexa8,
cortexa9,
cortexa15,
cortexr4,
cortexr4f,
cortexr5,
cortexm4,
cortexm3,
cortexm1,
cortexm0,
# 31 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm-opts.h" 2
  arm_none
};
enum arm_fp16_format_type
{
  ARM_FP16_FORMAT_NONE = 0,
  ARM_FP16_FORMAT_IEEE = 1,
  ARM_FP16_FORMAT_ALTERNATIVE = 2
};
enum arm_abi_type
{
  ARM_ABI_APCS,
  ARM_ABI_ATPCS,
  ARM_ABI_AAPCS,
  ARM_ABI_IWMMXT,
  ARM_ABI_AAPCS_LINUX
};
enum float_abi_type
{
  ARM_FLOAT_ABI_SOFT,
  ARM_FLOAT_ABI_SOFTFP,
  ARM_FLOAT_ABI_HARD
};
enum arm_tp_type {
  TP_AUTO,
  TP_SOFT,
  TP_CP15
};
enum arm_tls_type {
  TLS_GNU,
  TLS_GNU2
};
# 9 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/options.h" 2
struct gcc_options
{
  long long x_frame_larger_than_size;
  long long x_larger_than_size;
  unsigned char x_exit_after_options;
  unsigned char x_flag_dump_all_passed;
  unsigned char x_flag_opts_finished;
  unsigned char x_flag_stack_usage_info;
  unsigned char x_flag_warn_unused_result;
  unsigned char x_in_lto_p;
  unsigned char x_use_gnu_debug_info_extensions;
  unsigned char x_warn_frame_larger_than;
  unsigned char x_warn_larger_than;
  char * x_help_enum_printed;
  char * x_help_printed;
  const char * x_main_input_basename;
  const char * x_main_input_filename;
  enum debug_info_levels x_debug_info_level;
  enum debug_info_type x_write_symbols;
  enum debug_struct_file x_debug_struct_generic[DINFO_USAGE_NUM_ENUMS];
  enum debug_struct_file x_debug_struct_ordinary[DINFO_USAGE_NUM_ENUMS];
  enum graph_dump_types x_graph_dump_format;
  enum stack_check_type x_flag_stack_check;
  enum vect_verbosity_levels x_user_vect_verbosity_level;
  int * x_param_values;
  int x_flag_complex_method;
  int x_flag_debug_asm;
  int x_flag_dump_rtl_in_asm;
  int x_flag_evaluation_order;
  int x_flag_gen_aux_info;
  int x_flag_generate_lto;
  int x_flag_print_asm_name;
  int x_flag_shlib;
  int x_main_input_baselength;
  int x_optimize;
  int x_optimize_fast;
  int x_optimize_size;
  int x_rtl_dump_and_exit;
  int x_target_flags;
  unsigned int x_help_columns;
  unsigned int x_initial_max_fld_align;
  void * x_flag_instrument_functions_exclude_files;
  void * x_flag_instrument_functions_exclude_functions;
  int x_help_flag;
  int x_flag_preprocess_only;
  int x_warn_abi;
  int x_warn_address;
  int x_warn_aggregate_return;
  int x_warn_array_bounds;
  int x_warn_assign_intercept;
  int x_warn_attributes;
  int x_warn_bad_function_cast;
  int x_warn_cxx_compat;
  int x_warn_cxx0x_compat;
  int x_warn_cast_align;
  int x_warn_cast_qual;
  int x_warn_char_subscripts;
  int x_warn_clobbered;
  int x_warn_conversion;
  int x_warn_conversion_null;
  int x_warn_coverage_mismatch;
  int x_warn_cpp;
  int x_warn_ctor_dtor_privacy;
  int x_warn_declaration_after_statement;
  int x_warn_delnonvdtor;
  int x_warn_deprecated;
  int x_warn_deprecated_decl;
  int x_warn_disabled_optimization;
  int x_warn_div_by_zero;
  int x_warn_double_promotion;
  int x_warn_ecpp;
  int x_warn_empty_body;
  int x_warn_enum_compare;
  int x_warnings_are_errors;
  int x_extra_warnings;
  int x_flag_extraneous_semicolon;
  int x_flag_fatal_errors;
  int x_warn_float_equal;
  int x_warn_format_contains_nul;
  int x_warn_format_extra_args;
  int x_warn_format_nonliteral;
  int x_warn_format_security;
  int x_warn_format_y2k;
  int x_warn_format_zero_length;
  int x_warn_free_nonheap_object;
  int x_warn_ignored_qualifiers;
  int x_warn_implicit;
  int x_warn_implicit_function_declaration;
  int x_warn_implicit_int;
  int x_warn_init_self;
  int x_warn_inline;
  int x_warn_int_to_pointer_cast;
  int x_warn_invalid_memory_model;
  int x_warn_invalid_offsetof;
  int x_warn_jump_misses_init;
  int x_warn_logical_op;
  int x_warn_long_long;
  int x_warn_main;
  int x_warn_maybe_uninitialized;
  int x_warn_missing_braces;
  int x_warn_missing_declarations;
  int x_warn_missing_field_initializers;
  int x_warn_missing_format_attribute;
  int x_warn_missing_noreturn;
  int x_warn_missing_parameter_type;
  int x_warn_missing_prototypes;
  int x_warn_mudflap;
  int x_warn_narrowing;
  int x_warn_nested_externs;
  int x_warn_noexcept;
  int x_warn_nontemplate_friend;
  int x_warn_nonvdtor;
  int x_warn_nonnull;
  int x_warn_old_style_cast;
  int x_warn_old_style_declaration;
  int x_warn_old_style_definition;
  int x_flag_newer;
  int x_warn_overflow;
  int x_warn_overlength_strings;
  int x_warn_overloaded_virtual;
  int x_warn_override_init;
  int x_warn_packed;
  int x_warn_packed_bitfield_compat;
  int x_warn_padded;
  int x_warn_parentheses;
  int x_warn_pmf2ptr;
  int x_warn_pointer_arith;
  int x_warn_pointer_sign;
  int x_warn_pointer_to_int_cast;
  int x_warn_pragmas;
  int x_warn_property_assign_default;
  int x_warn_protocol;
  int x_warn_psabi;
  int x_warn_redundant_decls;
  int x_flag_redundant;
  int x_warn_reorder;
  int x_warn_return_type;
  int x_warn_selector;
  int x_warn_sequence_point;
  int x_warn_shadow;
  int x_warn_sign_compare;
  int x_warn_sign_conversion;
  int x_warn_sign_promo;
  int x_warn_stack_protect;
  int x_warn_stack_usage;
  int x_warn_strict_aliasing;
  int x_warn_strict_null_sentinel;
  int x_warn_strict_overflow;
  int x_warn_strict_prototypes;
  int x_warn_strict_selector_match;
  int x_warn_suggest_attribute_const;
  int x_warn_suggest_attribute_noreturn;
  int x_warn_suggest_attribute_pure;
  int x_warn_switch;
  int x_warn_switch_default;
  int x_warn_switch_enum;
  int x_warn_sync_nand;
  int x_warn_synth;
  int x_warn_system_headers;
  int x_warn_traditional;
  int x_warn_traditional_conversion;
  int x_warn_trampolines;
  int x_warn_type_limits;
  int x_warn_undeclared_selector;
  int x_warn_uninitialized;
  int x_warn_unsafe_loop_optimizations;
  int x_warn_unsuffixed_float_constants;
  int x_warn_unused;
  int x_warn_unused_but_set_parameter;
  int x_warn_unused_but_set_variable;
  int x_warn_unused_function;
  int x_warn_unused_label;
  int x_warn_unused_local_typedefs;
  int x_warn_unused_parameter;
  int x_warn_unused_result;
  int x_warn_unused_value;
  int x_warn_unused_variable;
  int x_warn_vector_operation_performance;
  int x_warn_vla;
  int x_warn_volatile_register_var;
  int x_warn_write_strings;
  int x_warn_zero_as_null_pointer_constant;
  const char *x_aux_info_file_name;
  const char *x_aux_base_name;
  const char *x_dump_base_name;
  const char *x_dump_dir_name;
  int x_flag_pic;
  int x_flag_pie;
  int x_flag_abi_version;
  int x_flag_access_control;
  int x_align_functions;
  int x_align_jumps;
  int x_align_labels;
  int x_align_loops;
  int x_flag_allow_parameterless_variadic_functions;
  int x_flag_no_asm;
  int x_flag_assert;
  int x_flag_associative_math;
  int x_flag_asynchronous_unwind_tables;
  int x_flag_auto_inc_dec;
  int x_flag_bootstrap_classes;
  int x_flag_bounds_check;
  int x_flag_branch_on_count_reg;
  int x_flag_branch_probabilities;
  int x_flag_branch_target_load_optimize;
  int x_flag_branch_target_load_optimize2;
  int x_flag_btr_bb_exclusive;
  int x_flag_building_libgcc;
  int x_flag_no_builtin;
  void *x_common_deferred_options;
  int x_flag_caller_saves;
  int x_flag_check_data_deps;
  int x_flag_check_new;
  int x_flag_check_references;
  int x_flag_combine_stack_adjustments;
  int x_flag_no_common;
  int x_flag_compare_debug;
  const char *x_flag_compare_debug_opt;
  int x_flag_compare_elim_after_reload;
  int x_flag_conserve_space;
  int x_flag_conserve_stack;
  int x_max_constexpr_depth;
  int x_flag_cprop_registers;
  int x_flag_crossjumping;
  int x_flag_cse_follow_jumps;
  int x_flag_cx_fortran_rules;
  int x_flag_cx_limited_range;
  int x_flag_data_sections;
  int x_flag_dce;
  int x_flag_debug_types_section;
  int x_flag_deduce_init_list;
  int x_flag_defer_pop;
  int x_flag_delayed_branch;
  int x_flag_delete_null_pointer_checks;
  int x_flag_devirtualize;
  int x_flag_diagnostics_show_option;
  int x_flag_dse;
  const char *x_flag_dump_final_insns;
  const char *x_flag_dump_go_spec;
  int x_flag_dump_noaddr;
  int x_flag_dump_passes;
  int x_flag_dump_unnumbered;
  int x_flag_dump_unnumbered_links;
  int x_flag_dwarf2_cfi_asm;
  int x_flag_early_inlining;
  int x_flag_elide_constructors;
  int x_flag_eliminate_dwarf2_dups;
  int x_flag_debug_only_used_symbols;
  int x_flag_eliminate_unused_debug_types;
  int x_flag_emit_class_debug_always;
  int x_flag_emit_class_files;
  int x_flag_enforce_eh_specs;
  int x_flag_exceptions;
  enum excess_precision x_flag_excess_precision_cmdline;
  int x_flag_expensive_optimizations;
  int x_flag_fat_lto_objects;
  int x_flag_filelist_file;
  int x_flag_finite_math_only;
  int x_flag_float_store;
  int x_flag_new_for_scope;
  int x_flag_force_classes_archive_check;
  int x_flag_forward_propagate;
  enum fp_contract_mode x_flag_fp_contract_mode;
  int x_flag_friend_injection;
  int x_flag_no_function_cse;
  int x_flag_function_sections;
  int x_flag_gcse;
  int x_flag_gcse_after_reload;
  int x_flag_gcse_las;
  int x_flag_gcse_lm;
  int x_flag_gcse_sm;
  int x_flag_no_gnu_keywords;
  int x_flag_next_runtime;
  int x_flag_tm;
  int x_flag_gnu89_inline;
  int x_go_check_divide_overflow;
  int x_go_check_divide_zero;
  int x_flag_graphite;
  int x_flag_graphite_identity;
  int x_flag_guess_branch_prob;
  int x_flag_hash_synchronization;
  int x_flag_no_ident;
  int x_flag_if_conversion;
  int x_flag_if_conversion2;
  int x_flag_implement_inlines;
  int x_flag_implicit_inline_templates;
  int x_flag_implicit_templates;
  int x_flag_indirect_classes;
  int x_flag_indirect_dispatch;
  int x_flag_indirect_inlining;
  int x_flag_inhibit_size_directive;
  int x_flag_no_inline;
  int x_flag_inline_atomics;
  int x_flag_inline_functions;
  int x_flag_inline_functions_called_once;
  int x_flag_inline_small_functions;
  int x_flag_instrument_function_entry_exit;
  int x_flag_ipa_cp;
  int x_flag_ipa_cp_clone;
  int x_flag_ipa_matrix_reorg;
  int x_flag_ipa_profile;
  int x_flag_ipa_pta;
  int x_flag_ipa_pure_const;
  int x_flag_ipa_reference;
  int x_flag_ipa_sra;
  enum ira_algorithm x_flag_ira_algorithm;
  int x_flag_ira_loop_pressure;
  enum ira_region x_flag_ira_region;
  int x_flag_ira_share_save_slots;
  int x_flag_ira_share_spill_slots;
  int x_flag_ira_verbose;
  int x_flag_ivopts;
  int x_flag_jni;
  int x_flag_jump_tables;
  int x_flag_keep_inline_dllexport;
  int x_flag_keep_inline_functions;
  int x_flag_keep_static_consts;
  int x_flag_lax_vector_conversions;
  int x_flag_leading_underscore;
  int x_flag_loop_block;
  int x_flag_loop_flatten;
  int x_flag_loop_interchange;
  int x_flag_loop_parallelize_all;
  int x_flag_loop_strip_mine;
  int x_flag_lto_compression_level;
  int x_flag_lto_partition_1to1;
  int x_flag_lto_partition_balanced;
  int x_flag_lto_partition_none;
  int x_flag_lto_report;
  const char *x_flag_lto;
  int x_flag_ltrans;
  const char *x_ltrans_output_list;
  int x_flag_errno_math;
  int x_flag_max_errors;
  int x_mem_report;
  int x_flag_merge_constants;
  int x_flag_merge_debug_strings;
  int x_flag_modulo_sched;
  int x_flag_modulo_sched_allow_regmoves;
  int x_flag_move_loop_invariants;
  int x_flag_ms_extensions;
  int x_flag_mudflap;
  int x_flag_mudflap_ignore_reads;
  int x_flag_nil_receivers;
  int x_flag_non_call_exceptions;
  int x_flag_no_nonansi_builtin;
  int x_flag_nothrow_opt;
  int x_flag_objc_abi;
  int x_flag_objc_call_cxx_cdtors;
  int x_flag_objc_direct_dispatch;
  int x_flag_objc_exceptions;
  int x_flag_objc_gc;
  int x_flag_objc_nilcheck;
  int x_flag_objc_sjlj_exceptions;
  int x_flag_objc1_only;
  int x_flag_omit_frame_pointer;
  int x_flag_openmp;
  int x_flag_regmove;
  int x_flag_optimize_sibling_calls;
  int x_flag_optimize_sci;
  int x_flag_optimize_strlen;
  int x_flag_pack_struct;
  int x_flag_partial_inlining;
  int x_flag_pcc_struct_return;
  int x_flag_peel_loops;
  int x_flag_no_peephole;
  int x_flag_peephole2;
  int x_flag_plan9_extensions;
  int x_post_ipa_mem_report;
  int x_pre_ipa_mem_report;
  int x_flag_predictive_commoning;
  int x_flag_prefetch_loop_arrays;
  int x_flag_pretty_templates;
  int x_profile_flag;
  int x_profile_arc_flag;
  int x_flag_profile_correction;
  const char *x_profile_data_prefix;
  int x_flag_profile_use;
  int x_flag_profile_values;
  int x_flag_reciprocal_math;
  int x_flag_record_gcc_switches;
  int x_flag_reduced_reflection;
  int x_flag_ree;
  int x_flag_rename_registers;
  int x_flag_reorder_blocks;
  int x_flag_reorder_blocks_and_partition;
  int x_flag_reorder_functions;
  int x_flag_replace_objc_classes;
  int x_go_require_return_statement;
  int x_flag_rerun_cse_after_loop;
  int x_flag_resched_modulo_sched;
  int x_flag_rounding_math;
  int x_flag_rtti;
  int x_flag_sched_critical_path_heuristic;
  int x_flag_sched_dep_count_heuristic;
  int x_flag_sched_group_heuristic;
  int x_flag_schedule_interblock;
  int x_flag_sched_last_insn_heuristic;
  int x_flag_sched_pressure;
  int x_flag_sched_rank_heuristic;
  int x_flag_schedule_speculative;
  int x_flag_sched_spec_insn_heuristic;
  int x_flag_schedule_speculative_load;
  int x_flag_schedule_speculative_load_dangerous;
  int x_flag_sched_stalled_insns;
  int x_flag_sched_stalled_insns_dep;
  int x_sched_verbose_param;
  int x_flag_sched2_use_superblocks;
  int x_flag_schedule_insns;
  int x_flag_schedule_insns_after_reload;
  int x_flag_section_anchors;
  int x_flag_sel_sched_pipelining;
  int x_flag_sel_sched_pipelining_outer_loops;
  int x_flag_sel_sched_reschedule_pipelined;
  int x_flag_selective_scheduling;
  int x_flag_selective_scheduling2;
  int x_flag_short_double;
  int x_flag_short_enums;
  int x_flag_short_wchar;
  int x_flag_show_column;
  int x_flag_shrink_wrap;
  int x_flag_signaling_nans;
  int x_flag_signed_bitfields;
  int x_flag_signed_char;
  int x_flag_signed_zeros;
  int x_flag_single_precision_constant;
  int x_flag_split_ivs_in_unroller;
  int x_flag_split_stack;
  int x_flag_split_wide_types;
  int x_flag_stack_protect;
  int x_flag_stack_usage;
  int x_flag_detailed_statistics;
  int x_flag_store_check;
  int x_flag_strict_aliasing;
  int x_flag_strict_enums;
  int x_flag_strict_overflow;
  int x_flag_strict_volatile_bitfields;
  int x_flag_syntax_only;
  int x_flag_test_coverage;
  int x_flag_thread_jumps;
  int x_flag_threadsafe_statics;
  int x_time_report;
  enum tls_model x_flag_tls_default;
  int x_flag_toplevel_reorder;
  int x_flag_tracer;
  int x_flag_trapping_math;
  int x_flag_trapv;
  int x_flag_tree_bit_ccp;
  int x_flag_tree_builtin_call_dce;
  int x_flag_tree_ccp;
  int x_flag_tree_ch;
  int x_flag_tree_copy_prop;
  int x_flag_tree_copyrename;
  int x_flag_tree_cselim;
  int x_flag_tree_dce;
  int x_flag_tree_dom;
  int x_flag_tree_dse;
  int x_flag_tree_forwprop;
  int x_flag_tree_fre;
  int x_flag_tree_loop_distribute_patterns;
  int x_flag_tree_loop_distribution;
  int x_flag_tree_loop_if_convert;
  int x_flag_tree_loop_if_convert_stores;
  int x_flag_tree_loop_im;
  int x_flag_tree_loop_ivcanon;
  int x_flag_tree_loop_optimize;
  int x_flag_tree_live_range_split;
  int x_flag_tree_parallelize_loops;
  int x_flag_tree_phiprop;
  int x_flag_tree_pre;
  int x_flag_tree_pta;
  int x_flag_tree_reassoc;
  int x_flag_tree_scev_cprop;
  int x_flag_tree_sink;
  int x_flag_tree_slp_vectorize;
  int x_flag_tree_sra;
  int x_flag_tree_switch_conversion;
  int x_flag_tree_tail_merge;
  int x_flag_tree_ter;
  int x_flag_tree_vect_loop_version;
  int x_flag_tree_vectorize;
  int x_flag_tree_vrp;
  int x_flag_unit_at_a_time;
  int x_flag_unroll_all_loops;
  int x_flag_unroll_loops;
  int x_flag_unsafe_loop_optimizations;
  int x_flag_unsafe_math_optimizations;
  int x_flag_unswitch_loops;
  int x_flag_unwind_tables;
  int x_flag_use_atomic_builtins;
  int x_flag_use_boehm_gc;
  int x_flag_use_cxa_atexit;
  int x_flag_use_cxa_get_exception_ptr;
  int x_flag_use_divide_subroutine;
  int x_flag_var_tracking;
  int x_flag_var_tracking_assignments;
  int x_flag_var_tracking_assignments_toggle;
  int x_flag_var_tracking_uninit;
  int x_flag_variable_expansion_in_unroller;
  int x_flag_vect_cost_model;
  int x_flag_verbose_asm;
  int x_flag_visibility_ms_compat;
  enum symbol_visibility x_default_visibility;
  int x_flag_value_profile_transformations;
  int x_flag_weak;
  int x_flag_web;
  int x_flag_whole_program;
  int x_flag_working_directory;
  int x_flag_wpa;
  int x_flag_wrapv;
  int x_flag_zero_initialized_in_bss;
  int x_flag_zero_link;
  int x_dwarf_version;
  int x_flag_gen_declaration;
  int x_dwarf_record_gcc_switches;
  int x_dwarf_strict;
  int x_flag_gtoggle;
  const char *x_plugindir_string;
  enum arm_abi_type x_arm_abi;
  int x_flag_android;
  int x_arm_arch_option;
  int x_linux_libc;
  enum processor_type x_arm_cpu_option;
  int x_fix_cm3_ldrd;
  enum float_abi_type x_arm_float_abi;
  enum arm_fp16_format_type x_arm_fp16_format;
  int x_arm_fpu_index;
  const char *x_arm_pic_register_string;
  int x_arm_structure_size_boundary;
  enum arm_tls_type x_target_tls_dialect;
  enum arm_tp_type x_target_thread_pointer;
  enum processor_type x_arm_tune_option;
  int x_unaligned_access;
  int x_target_word_relocations;
  const char *x_asm_file_name;
  int x_pass_exit_codes;
  int x_pedantic;
  int x_flag_pedantic_errors;
  int x_use_pipes;
  const char *x_print_file_name;
  int x_print_multi_directory;
  int x_print_multi_lib;
  int x_print_multi_os_directory;
  const char *x_print_prog_name;
  int x_print_search_dirs;
  int x_print_sysroot;
  int x_print_sysroot_headers_suffix;
  int x_quiet_flag;
  int x_report_times;
  int x_flag_undef;
  int x_verbose_flag;
  int x_version_flag;
  int x_inhibit_warnings;
  const char *x_wrapper_string;
  unsigned char frontend_set_flag_associative_math;
  unsigned char frontend_set_flag_cx_limited_range;
  unsigned char frontend_set_flag_finite_math_only;
  unsigned char frontend_set_flag_errno_math;
  unsigned char frontend_set_flag_reciprocal_math;
  unsigned char frontend_set_flag_rounding_math;
  unsigned char frontend_set_flag_signaling_nans;
  unsigned char frontend_set_flag_signed_zeros;
  unsigned char frontend_set_flag_trapping_math;
  unsigned char frontend_set_flag_unsafe_math_optimizations;
};
extern struct gcc_options global_options;
extern const struct gcc_options global_options_init;
extern struct gcc_options global_options_set;
struct cl_optimization
{
  int x_align_functions;
  int x_align_jumps;
  int x_align_labels;
  int x_align_loops;
  int x_flag_sched_stalled_insns;
  int x_flag_sched_stalled_insns_dep;
  enum fp_contract_mode x_flag_fp_contract_mode;
  unsigned char x_optimize;
  unsigned char x_optimize_size;
  signed char x_flag_asynchronous_unwind_tables;
  signed char x_flag_branch_on_count_reg;
  signed char x_flag_branch_probabilities;
  signed char x_flag_branch_target_load_optimize;
  signed char x_flag_branch_target_load_optimize2;
  signed char x_flag_btr_bb_exclusive;
  signed char x_flag_caller_saves;
  signed char x_flag_combine_stack_adjustments;
  signed char x_flag_no_common;
  signed char x_flag_compare_elim_after_reload;
  signed char x_flag_conserve_stack;
  signed char x_flag_cprop_registers;
  signed char x_flag_crossjumping;
  signed char x_flag_cse_follow_jumps;
  signed char x_flag_cx_fortran_rules;
  signed char x_flag_cx_limited_range;
  signed char x_flag_data_sections;
  signed char x_flag_dce;
  signed char x_flag_defer_pop;
  signed char x_flag_delayed_branch;
  signed char x_flag_delete_null_pointer_checks;
  signed char x_flag_devirtualize;
  signed char x_flag_dse;
  signed char x_flag_early_inlining;
  signed char x_flag_exceptions;
  signed char x_flag_expensive_optimizations;
  signed char x_flag_finite_math_only;
  signed char x_flag_float_store;
  signed char x_flag_forward_propagate;
  signed char x_flag_gcse;
  signed char x_flag_gcse_after_reload;
  signed char x_flag_gcse_las;
  signed char x_flag_gcse_lm;
  signed char x_flag_gcse_sm;
  signed char x_flag_graphite_identity;
  signed char x_flag_guess_branch_prob;
  signed char x_flag_if_conversion;
  signed char x_flag_if_conversion2;
  signed char x_flag_inline_atomics;
  signed char x_flag_inline_functions;
  signed char x_flag_inline_functions_called_once;
  signed char x_flag_inline_small_functions;
  signed char x_flag_ipa_cp;
  signed char x_flag_ipa_cp_clone;
  signed char x_flag_ipa_matrix_reorg;
  signed char x_flag_ipa_profile;
  signed char x_flag_ipa_pta;
  signed char x_flag_ipa_pure_const;
  signed char x_flag_ipa_reference;
  signed char x_flag_ipa_sra;
  signed char x_flag_ivopts;
  signed char x_flag_jump_tables;
  signed char x_flag_loop_block;
  signed char x_flag_loop_flatten;
  signed char x_flag_loop_interchange;
  signed char x_flag_loop_parallelize_all;
  signed char x_flag_loop_strip_mine;
  signed char x_flag_errno_math;
  signed char x_flag_merge_constants;
  signed char x_flag_modulo_sched;
  signed char x_flag_move_loop_invariants;
  signed char x_flag_non_call_exceptions;
  signed char x_flag_nothrow_opt;
  signed char x_flag_omit_frame_pointer;
  signed char x_flag_regmove;
  signed char x_flag_optimize_sibling_calls;
  signed char x_flag_optimize_strlen;
  signed char x_flag_pack_struct;
  signed char x_flag_peel_loops;
  signed char x_flag_no_peephole;
  signed char x_flag_peephole2;
  signed char x_flag_predictive_commoning;
  signed char x_flag_prefetch_loop_arrays;
  signed char x_flag_pcc_struct_return;
  signed char x_flag_rename_registers;
  signed char x_flag_reorder_blocks;
  signed char x_flag_reorder_blocks_and_partition;
  signed char x_flag_reorder_functions;
  signed char x_flag_rerun_cse_after_loop;
  signed char x_flag_resched_modulo_sched;
  signed char x_flag_rounding_math;
  signed char x_flag_rtti;
  signed char x_flag_sched_critical_path_heuristic;
  signed char x_flag_sched_dep_count_heuristic;
  signed char x_flag_sched_group_heuristic;
  signed char x_flag_schedule_interblock;
  signed char x_flag_sched_last_insn_heuristic;
  signed char x_flag_sched_pressure;
  signed char x_flag_sched_rank_heuristic;
  signed char x_flag_schedule_speculative;
  signed char x_flag_sched_spec_insn_heuristic;
  signed char x_flag_schedule_speculative_load;
  signed char x_flag_schedule_speculative_load_dangerous;
  signed char x_flag_sched2_use_superblocks;
  signed char x_flag_schedule_insns;
  signed char x_flag_schedule_insns_after_reload;
  signed char x_flag_section_anchors;
  signed char x_flag_sel_sched_pipelining;
  signed char x_flag_sel_sched_pipelining_outer_loops;
  signed char x_flag_sel_sched_reschedule_pipelined;
  signed char x_flag_selective_scheduling;
  signed char x_flag_selective_scheduling2;
  signed char x_flag_short_double;
  signed char x_flag_short_enums;
  signed char x_flag_short_wchar;
  signed char x_flag_shrink_wrap;
  signed char x_flag_signaling_nans;
  signed char x_flag_signed_zeros;
  signed char x_flag_single_precision_constant;
  signed char x_flag_split_ivs_in_unroller;
  signed char x_flag_split_wide_types;
  signed char x_flag_strict_aliasing;
  signed char x_flag_strict_enums;
  signed char x_flag_thread_jumps;
  signed char x_flag_threadsafe_statics;
  signed char x_flag_toplevel_reorder;
  signed char x_flag_trapping_math;
  signed char x_flag_trapv;
  signed char x_flag_tree_bit_ccp;
  signed char x_flag_tree_builtin_call_dce;
  signed char x_flag_tree_ccp;
  signed char x_flag_tree_ch;
  signed char x_flag_tree_copy_prop;
  signed char x_flag_tree_copyrename;
  signed char x_flag_tree_cselim;
  signed char x_flag_tree_dce;
  signed char x_flag_tree_dom;
  signed char x_flag_tree_dse;
  signed char x_flag_tree_forwprop;
  signed char x_flag_tree_fre;
  signed char x_flag_tree_loop_distribute_patterns;
  signed char x_flag_tree_loop_distribution;
  signed char x_flag_tree_loop_if_convert;
  signed char x_flag_tree_loop_if_convert_stores;
  signed char x_flag_tree_loop_im;
  signed char x_flag_tree_loop_ivcanon;
  signed char x_flag_tree_loop_optimize;
  signed char x_flag_tree_live_range_split;
  signed char x_flag_tree_phiprop;
  signed char x_flag_tree_pre;
  signed char x_flag_tree_pta;
  signed char x_flag_tree_reassoc;
  signed char x_flag_tree_scev_cprop;
  signed char x_flag_tree_sink;
  signed char x_flag_tree_slp_vectorize;
  signed char x_flag_tree_sra;
  signed char x_flag_tree_switch_conversion;
  signed char x_flag_tree_tail_merge;
  signed char x_flag_tree_ter;
  signed char x_flag_tree_vect_loop_version;
  signed char x_flag_tree_vectorize;
  signed char x_flag_tree_vrp;
  signed char x_flag_unit_at_a_time;
  signed char x_flag_unroll_all_loops;
  signed char x_flag_unroll_loops;
  signed char x_flag_unsafe_loop_optimizations;
  signed char x_flag_unsafe_math_optimizations;
  signed char x_flag_unswitch_loops;
  signed char x_flag_unwind_tables;
  signed char x_flag_var_tracking;
  signed char x_flag_var_tracking_assignments;
  signed char x_flag_var_tracking_assignments_toggle;
  signed char x_flag_var_tracking_uninit;
  signed char x_flag_variable_expansion_in_unroller;
  signed char x_flag_vect_cost_model;
  signed char x_flag_value_profile_transformations;
  signed char x_flag_web;
  signed char x_flag_whole_program;
  signed char x_flag_wrapv;
};
struct cl_target_option
{
  int x_target_flags;
};
extern void cl_optimization_save (struct cl_optimization *, struct gcc_options *);
extern void cl_optimization_restore (struct gcc_options *, struct cl_optimization *);
extern void cl_optimization_print (FILE *, int, struct cl_optimization *);
extern void cl_target_option_save (struct cl_target_option *, struct gcc_options *);
extern void cl_target_option_restore (struct gcc_options *, struct cl_target_option *);
extern void cl_target_option_print (FILE *, int, struct cl_target_option *);
# 3638 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/options.h"
enum opt_code
{
  OPT____ = 0,
# 3672 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/options.h"
  OPT__help = 32,
  OPT__help_ = 33,
# 3705 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/options.h"
  OPT__output_pch_ = 65,
  OPT__param = 67,
# 3739 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/options.h"
  OPT__sysroot_ = 99,
  OPT__target_help = 100,
# 3750 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/options.h"
  OPT__version = 110,
  OPT_A = 113,
  OPT_B = 114,
  OPT_C = 115,
  OPT_CC = 116,
  OPT_D = 118,
  OPT_E = 119,
  OPT_F = 120,
  OPT_H = 121,
  OPT_I = 122,
  OPT_J = 123,
  OPT_L = 124,
  OPT_M = 125,
  OPT_MD = 126,
  OPT_MD_ = 127,
  OPT_MF = 128,
  OPT_MG = 129,
  OPT_MM = 130,
  OPT_MMD = 131,
  OPT_MMD_ = 132,
  OPT_MP = 133,
  OPT_MQ = 134,
  OPT_MT = 135,
  OPT_N = 136,
  OPT_O = 137,
  OPT_Ofast = 138,
  OPT_Os = 139,
  OPT_P = 140,
  OPT_Q = 141,
  OPT_Qn = 142,
  OPT_Qy = 143,
  OPT_R = 144,
  OPT_S = 145,
  OPT_T = 146,
  OPT_Tbss = 147,
  OPT_Tbss_ = 148,
  OPT_Tdata = 149,
  OPT_Tdata_ = 150,
  OPT_Ttext = 151,
  OPT_Ttext_ = 152,
  OPT_U = 153,
  OPT_Wa_ = 155,
  OPT_Wabi = 156,
  OPT_Waddress = 157,
  OPT_Waggregate_return = 158,
  OPT_Waliasing = 159,
  OPT_Walign_commons = 160,
  OPT_Wall = 161,
  OPT_Wall_deprecation = 162,
  OPT_Wall_javadoc = 163,
  OPT_Wampersand = 164,
  OPT_Warray_bounds = 165,
  OPT_Warray_temporaries = 166,
  OPT_Wassert_identifier = 167,
  OPT_Wassign_intercept = 168,
  OPT_Wattributes = 169,
  OPT_Wbad_function_cast = 170,
  OPT_Wboxing = 171,
  OPT_Wbuiltin_macro_redefined = 172,
  OPT_Wc___compat = 173,
  OPT_Wc__0x_compat = 174,
  OPT_Wcast_align = 176,
  OPT_Wcast_qual = 177,
  OPT_Wchar_concat = 178,
  OPT_Wchar_subscripts = 179,
  OPT_Wcharacter_truncation = 180,
  OPT_Wclobbered = 181,
  OPT_Wcomment = 182,
  OPT_Wcondition_assign = 184,
  OPT_Wconstructor_name = 185,
  OPT_Wconversion = 186,
  OPT_Wconversion_extra = 187,
  OPT_Wconversion_null = 188,
  OPT_Wcoverage_mismatch = 189,
  OPT_Wcpp = 190,
  OPT_Wctor_dtor_privacy = 191,
  OPT_Wdeclaration_after_statement = 192,
  OPT_Wdelete_non_virtual_dtor = 193,
  OPT_Wdep_ann = 194,
  OPT_Wdeprecated = 195,
  OPT_Wdeprecated_declarations = 196,
  OPT_Wdisabled_optimization = 197,
  OPT_Wdiscouraged = 198,
  OPT_Wdiv_by_zero = 199,
  OPT_Wdouble_promotion = 200,
  OPT_Weffc__ = 201,
  OPT_Wempty_block = 202,
  OPT_Wempty_body = 203,
  OPT_Wendif_labels = 204,
  OPT_Wenum_compare = 205,
  OPT_Wenum_identifier = 206,
  OPT_Wenum_switch = 207,
  OPT_Werror = 208,
  OPT_Werror_ = 210,
  OPT_Wextra = 211,
  OPT_Wextraneous_semicolon = 212,
  OPT_Wfallthrough = 213,
  OPT_Wfatal_errors = 214,
  OPT_Wfield_hiding = 215,
  OPT_Wfinal_bound = 216,
  OPT_Wfinally = 217,
  OPT_Wfloat_equal = 218,
  OPT_Wforbidden = 219,
  OPT_Wformat = 220,
  OPT_Wformat_contains_nul = 221,
  OPT_Wformat_extra_args = 222,
  OPT_Wformat_nonliteral = 223,
  OPT_Wformat_security = 224,
  OPT_Wformat_y2k = 225,
  OPT_Wformat_zero_length = 226,
  OPT_Wformat_ = 227,
  OPT_Wframe_larger_than_ = 228,
  OPT_Wfree_nonheap_object = 229,
  OPT_Wfunction_elimination = 230,
  OPT_Whiding = 231,
  OPT_Wignored_qualifiers = 232,
  OPT_Wimplicit = 233,
  OPT_Wimplicit_function_declaration = 234,
  OPT_Wimplicit_int = 235,
  OPT_Wimplicit_interface = 236,
  OPT_Wimplicit_procedure = 237,
  OPT_Windirect_static = 239,
  OPT_Winit_self = 240,
  OPT_Winline = 241,
  OPT_Wint_to_pointer_cast = 242,
  OPT_Wintf_annotation = 243,
  OPT_Wintf_non_inherited = 244,
  OPT_Wintrinsic_shadow = 245,
  OPT_Wintrinsics_std = 246,
  OPT_Winvalid_memory_model = 247,
  OPT_Winvalid_offsetof = 248,
  OPT_Winvalid_pch = 249,
  OPT_Wjavadoc = 250,
  OPT_Wjump_misses_init = 251,
  OPT_Wl_ = 252,
  OPT_Wlarger_than_ = 254,
  OPT_Wline_truncation = 255,
  OPT_Wlocal_hiding = 256,
  OPT_Wlogical_op = 257,
  OPT_Wlong_long = 258,
  OPT_Wmain = 259,
  OPT_Wmasked_catch_block = 260,
  OPT_Wmaybe_uninitialized = 261,
  OPT_Wmissing_braces = 262,
  OPT_Wmissing_declarations = 263,
  OPT_Wmissing_field_initializers = 264,
  OPT_Wmissing_format_attribute = 265,
  OPT_Wmissing_include_dirs = 266,
  OPT_Wmissing_noreturn = 267,
  OPT_Wmissing_parameter_type = 268,
  OPT_Wmissing_prototypes = 269,
  OPT_Wmudflap = 270,
  OPT_Wmultichar = 271,
  OPT_Wnarrowing = 272,
  OPT_Wnested_externs = 273,
  OPT_Wnls = 274,
  OPT_Wno_effect_assign = 275,
  OPT_Wnoexcept = 276,
  OPT_Wnon_template_friend = 277,
  OPT_Wnon_virtual_dtor = 278,
  OPT_Wnonnull = 279,
  OPT_Wnormalized_ = 280,
  OPT_Wnull = 281,
  OPT_Wold_style_cast = 282,
  OPT_Wold_style_declaration = 283,
  OPT_Wold_style_definition = 284,
  OPT_Wout_of_date = 285,
  OPT_Wover_ann = 286,
  OPT_Woverflow = 287,
  OPT_Woverlength_strings = 288,
  OPT_Woverloaded_virtual = 289,
  OPT_Woverride_init = 290,
  OPT_Wp_ = 291,
  OPT_Wpacked = 292,
  OPT_Wpacked_bitfield_compat = 293,
  OPT_Wpadded = 294,
  OPT_Wparam_assign = 295,
  OPT_Wparentheses = 296,
  OPT_Wpkg_default_method = 297,
  OPT_Wpmf_conversions = 298,
  OPT_Wpointer_arith = 299,
  OPT_Wpointer_sign = 300,
  OPT_Wpointer_to_int_cast = 301,
  OPT_Wpragmas = 302,
  OPT_Wproperty_assign_default = 303,
  OPT_Wprotocol = 304,
  OPT_Wpsabi = 305,
  OPT_Wraw = 306,
  OPT_Wreal_q_constant = 307,
  OPT_Wredundant_decls = 308,
  OPT_Wredundant_modifiers = 309,
  OPT_Wreorder = 310,
  OPT_Wreturn_type = 311,
  OPT_Wselector = 312,
  OPT_Wsequence_point = 313,
  OPT_Wserial = 314,
  OPT_Wshadow = 315,
  OPT_Wsign_compare = 316,
  OPT_Wsign_conversion = 317,
  OPT_Wsign_promo = 318,
  OPT_Wspecial_param_hiding = 319,
  OPT_Wstack_protector = 320,
  OPT_Wstack_usage_ = 321,
  OPT_Wstatic_access = 322,
  OPT_Wstatic_receiver = 323,
  OPT_Wstrict_aliasing = 324,
  OPT_Wstrict_aliasing_ = 325,
  OPT_Wstrict_null_sentinel = 326,
  OPT_Wstrict_overflow = 327,
  OPT_Wstrict_overflow_ = 328,
  OPT_Wstrict_prototypes = 329,
  OPT_Wstrict_selector_match = 330,
  OPT_Wsuggest_attribute_const = 331,
  OPT_Wsuggest_attribute_noreturn = 332,
  OPT_Wsuggest_attribute_pure = 333,
  OPT_Wsuppress = 334,
  OPT_Wsurprising = 335,
  OPT_Wswitch = 336,
  OPT_Wswitch_default = 337,
  OPT_Wswitch_enum = 338,
  OPT_Wsync_nand = 339,
  OPT_Wsynth = 340,
  OPT_Wsynthetic_access = 341,
  OPT_Wsystem_headers = 342,
  OPT_Wtabs = 343,
  OPT_Wtasks = 344,
  OPT_Wtraditional = 345,
  OPT_Wtraditional_conversion = 346,
  OPT_Wtrampolines = 347,
  OPT_Wtrigraphs = 348,
  OPT_Wtype_hiding = 349,
  OPT_Wtype_limits = 350,
  OPT_Wuncheck = 351,
  OPT_Wundeclared_selector = 352,
  OPT_Wundef = 353,
  OPT_Wunderflow = 354,
  OPT_Wuninitialized = 355,
  OPT_Wunknown_pragmas = 356,
  OPT_Wunnecessary_else = 357,
  OPT_Wunqualified_field = 358,
  OPT_Wunsafe_loop_optimizations = 360,
  OPT_Wunsuffixed_float_constants = 361,
  OPT_Wunused = 362,
  OPT_Wunused_argument = 363,
  OPT_Wunused_but_set_parameter = 364,
  OPT_Wunused_but_set_variable = 365,
  OPT_Wunused_dummy_argument = 366,
  OPT_Wunused_function = 367,
  OPT_Wunused_import = 368,
  OPT_Wunused_label = 369,
  OPT_Wunused_local = 370,
  OPT_Wunused_local_typedefs = 371,
  OPT_Wunused_macros = 372,
  OPT_Wunused_parameter = 373,
  OPT_Wunused_private = 374,
  OPT_Wunused_result = 375,
  OPT_Wunused_thrown = 376,
  OPT_Wunused_value = 377,
  OPT_Wunused_variable = 378,
  OPT_Wuseless_type_check = 379,
  OPT_Wvarargs_cast = 380,
  OPT_Wvariadic_macros = 381,
  OPT_Wvector_operation_performance = 382,
  OPT_Wvla = 383,
  OPT_Wvolatile_register_var = 384,
  OPT_Wwarning_token = 385,
  OPT_Wwrite_strings = 386,
  OPT_Wzero_as_null_pointer_constant = 387,
  OPT_Xassembler = 388,
  OPT_Xlinker = 389,
  OPT_Xpreprocessor = 390,
  OPT_Z = 391,
  OPT_ansi = 392,
  OPT_aux_info = 393,
  OPT_auxbase = 395,
  OPT_auxbase_strip = 396,
  OPT_c = 398,
  OPT_coverage = 400,
  OPT_cpp = 401,
  OPT_cpp_ = 402,
  OPT_d = 403,
  OPT_dumpbase = 404,
  OPT_dumpdir = 405,
  OPT_dumpmachine = 406,
  OPT_dumpspecs = 407,
  OPT_dumpversion = 408,
  OPT_e = 409,
  OPT_export_dynamic = 411,
  OPT_extdirs = 412,
  OPT_fPIC = 414,
  OPT_fPIE = 415,
  OPT_fRTS_ = 416,
  OPT_fabi_version_ = 417,
  OPT_faccess_control = 418,
  OPT_faggressive_function_elimination = 419,
  OPT_falign_commons = 420,
  OPT_falign_functions = 421,
  OPT_falign_functions_ = 422,
  OPT_falign_jumps = 423,
  OPT_falign_jumps_ = 424,
  OPT_falign_labels = 425,
  OPT_falign_labels_ = 426,
  OPT_falign_loops = 427,
  OPT_falign_loops_ = 428,
  OPT_fall_intrinsics = 429,
  OPT_fallow_leading_underscore = 431,
  OPT_fallow_parameterless_variadic_functions = 432,
  OPT_fasm = 438,
  OPT_fassert = 439,
  OPT_fassociative_math = 440,
  OPT_fassume_compiled = 441,
  OPT_fassume_compiled_ = 442,
  OPT_fasynchronous_unwind_tables = 443,
  OPT_fauto_inc_dec = 444,
  OPT_fautomatic = 445,
  OPT_faux_classpath = 446,
  OPT_fbackslash = 447,
  OPT_fbacktrace = 448,
  OPT_fblas_matmul_limit_ = 449,
  OPT_fbootclasspath_ = 450,
  OPT_fbootstrap_classes = 451,
  OPT_fbounds_check = 452,
  OPT_fbranch_count_reg = 453,
  OPT_fbranch_probabilities = 454,
  OPT_fbranch_target_load_optimize = 455,
  OPT_fbranch_target_load_optimize2 = 456,
  OPT_fbtr_bb_exclusive = 457,
  OPT_fbuilding_libgcc = 458,
  OPT_fbuiltin = 459,
  OPT_fbuiltin_ = 460,
  OPT_fcall_saved_ = 461,
  OPT_fcall_used_ = 462,
  OPT_fcaller_saves = 463,
  OPT_fcheck_array_temporaries = 464,
  OPT_fcheck_data_deps = 465,
  OPT_fcheck_new = 466,
  OPT_fcheck_references = 467,
  OPT_fcheck_ = 468,
  OPT_fclasspath_ = 469,
  OPT_fcoarray_ = 470,
  OPT_fcombine_stack_adjustments = 471,
  OPT_fcommon = 472,
  OPT_fcompare_debug = 473,
  OPT_fcompare_debug_second = 474,
  OPT_fcompare_debug_ = 475,
  OPT_fcompare_elim = 476,
  OPT_fcompile_resource_ = 477,
  OPT_fcond_mismatch = 478,
  OPT_fconserve_space = 479,
  OPT_fconserve_stack = 480,
  OPT_fconstant_string_class_ = 481,
  OPT_fconstexpr_depth_ = 482,
  OPT_fconvert_big_endian = 483,
  OPT_fconvert_little_endian = 484,
  OPT_fconvert_native = 485,
  OPT_fconvert_swap = 486,
  OPT_fcprop_registers = 487,
  OPT_fcray_pointer = 488,
  OPT_fcrossjumping = 489,
  OPT_fcse_follow_jumps = 490,
  OPT_fcx_fortran_rules = 492,
  OPT_fcx_limited_range = 493,
  OPT_fd_lines_as_code = 494,
  OPT_fd_lines_as_comments = 495,
  OPT_fdata_sections = 496,
  OPT_fdbg_cnt_list = 497,
  OPT_fdbg_cnt_ = 498,
  OPT_fdce = 499,
  OPT_fdebug_cpp = 500,
  OPT_fdebug_prefix_map_ = 501,
  OPT_fdebug_types_section = 502,
  OPT_fdeduce_init_list = 503,
  OPT_fdefault_double_8 = 504,
  OPT_fdefault_integer_8 = 506,
  OPT_fdefault_real_8 = 507,
  OPT_fdefer_pop = 508,
  OPT_fdelayed_branch = 509,
  OPT_fdelete_null_pointer_checks = 510,
  OPT_fdevirtualize = 511,
  OPT_fdiagnostics_show_location_ = 512,
  OPT_fdiagnostics_show_option = 513,
  OPT_fdirectives_only = 514,
  OPT_fdisable_ = 515,
  OPT_fdisable_assertions = 516,
  OPT_fdisable_assertions_ = 517,
  OPT_fdollar_ok = 518,
  OPT_fdollars_in_identifiers = 519,
  OPT_fdse = 520,
  OPT_fdump_ = 521,
  OPT_fdump_final_insns = 523,
  OPT_fdump_final_insns_ = 524,
  OPT_fdump_fortran_optimized = 525,
  OPT_fdump_fortran_original = 526,
  OPT_fdump_go_spec_ = 527,
  OPT_fdump_noaddr = 528,
  OPT_fdump_parse_tree = 529,
  OPT_fdump_passes = 530,
  OPT_fdump_unnumbered = 531,
  OPT_fdump_unnumbered_links = 532,
  OPT_fdwarf2_cfi_asm = 533,
  OPT_fearly_inlining = 534,
  OPT_felide_constructors = 535,
  OPT_feliminate_dwarf2_dups = 536,
  OPT_feliminate_unused_debug_symbols = 537,
  OPT_feliminate_unused_debug_types = 538,
  OPT_femit_class_debug_always = 539,
  OPT_femit_class_file = 540,
  OPT_femit_class_files = 541,
  OPT_femit_struct_debug_baseonly = 542,
  OPT_femit_struct_debug_detailed_ = 543,
  OPT_femit_struct_debug_reduced = 544,
  OPT_fenable_ = 545,
  OPT_fenable_assertions = 546,
  OPT_fenable_assertions_ = 547,
  OPT_fencoding_ = 548,
  OPT_fenforce_eh_specs = 549,
  OPT_fexceptions = 551,
  OPT_fexcess_precision_ = 552,
  OPT_fexec_charset_ = 553,
  OPT_fexpensive_optimizations = 554,
  OPT_fextdirs_ = 555,
  OPT_fextended_identifiers = 556,
  OPT_fexternal_blas = 557,
  OPT_ff2c = 559,
  OPT_ffast_math = 560,
  OPT_ffat_lto_objects = 561,
  OPT_ffilelist_file = 562,
  OPT_ffinite_math_only = 563,
  OPT_ffixed_ = 564,
  OPT_ffixed_form = 565,
  OPT_ffixed_line_length_ = 566,
  OPT_ffixed_line_length_none = 567,
  OPT_ffloat_store = 568,
  OPT_ffor_scope = 569,
  OPT_fforce_classes_archive_check = 571,
  OPT_fforward_propagate = 572,
  OPT_ffp_contract_ = 573,
  OPT_ffpe_trap_ = 574,
  OPT_ffree_form = 575,
  OPT_ffree_line_length_ = 576,
  OPT_ffree_line_length_none = 577,
  OPT_ffreestanding = 578,
  OPT_ffriend_injection = 579,
  OPT_ffrontend_optimize = 580,
  OPT_ffunction_cse = 581,
  OPT_ffunction_sections = 582,
  OPT_fgcse = 583,
  OPT_fgcse_after_reload = 584,
  OPT_fgcse_las = 585,
  OPT_fgcse_lm = 586,
  OPT_fgcse_sm = 587,
  OPT_fgnu_keywords = 588,
  OPT_fgnu_runtime = 589,
  OPT_fgnu_tm = 590,
  OPT_fgnu89_inline = 591,
  OPT_fgo_check_divide_overflow = 592,
  OPT_fgo_check_divide_zero = 593,
  OPT_fgo_dump_ = 594,
  OPT_fgo_optimize_ = 595,
  OPT_fgo_pkgpath_ = 596,
  OPT_fgo_prefix_ = 597,
  OPT_fgraphite = 598,
  OPT_fgraphite_identity = 599,
  OPT_fguess_branch_probability = 600,
  OPT_fhash_synchronization = 603,
  OPT_fhosted = 607,
  OPT_fident = 609,
  OPT_fif_conversion = 610,
  OPT_fif_conversion2 = 611,
  OPT_fimplement_inlines = 612,
  OPT_fimplicit_inline_templates = 613,
  OPT_fimplicit_none = 614,
  OPT_fimplicit_templates = 615,
  OPT_findirect_classes = 616,
  OPT_findirect_dispatch = 617,
  OPT_findirect_inlining = 618,
  OPT_finhibit_size_directive = 619,
  OPT_finit_character_ = 620,
  OPT_finit_integer_ = 621,
  OPT_finit_local_zero = 622,
  OPT_finit_logical_ = 623,
  OPT_finit_real_ = 624,
  OPT_finline = 625,
  OPT_finline_atomics = 626,
  OPT_finline_functions = 627,
  OPT_finline_functions_called_once = 628,
  OPT_finline_limit_ = 630,
  OPT_finline_small_functions = 631,
  OPT_finput_charset_ = 632,
  OPT_finstrument_functions = 633,
  OPT_finstrument_functions_exclude_file_list_ = 634,
  OPT_finstrument_functions_exclude_function_list_ = 635,
  OPT_finteger_4_integer_8 = 636,
  OPT_fintrinsic_modules_path = 637,
  OPT_fipa_cp = 638,
  OPT_fipa_cp_clone = 639,
  OPT_fipa_matrix_reorg = 640,
  OPT_fipa_profile = 641,
  OPT_fipa_pta = 642,
  OPT_fipa_pure_const = 643,
  OPT_fipa_reference = 644,
  OPT_fipa_sra = 645,
  OPT_fira_algorithm_ = 647,
  OPT_fira_loop_pressure = 648,
  OPT_fira_region_ = 649,
  OPT_fira_share_save_slots = 650,
  OPT_fira_share_spill_slots = 651,
  OPT_fira_verbose_ = 652,
  OPT_fivopts = 653,
  OPT_fjni = 654,
  OPT_fjump_tables = 655,
  OPT_fkeep_inline_dllexport = 656,
  OPT_fkeep_inline_functions = 657,
  OPT_fkeep_static_consts = 658,
  OPT_flax_vector_conversions = 660,
  OPT_fleading_underscore = 661,
  OPT_floop_block = 662,
  OPT_floop_flatten = 663,
  OPT_floop_interchange = 664,
  OPT_floop_parallelize_all = 666,
  OPT_floop_strip_mine = 667,
  OPT_flto = 668,
  OPT_flto_compression_level_ = 669,
  OPT_flto_partition_1to1 = 670,
  OPT_flto_partition_balanced = 671,
  OPT_flto_partition_none = 672,
  OPT_flto_report = 673,
  OPT_flto_ = 674,
  OPT_fltrans = 675,
  OPT_fltrans_output_list_ = 676,
  OPT_fmain_ = 677,
  OPT_fmath_errno = 678,
  OPT_fmax_array_constructor_ = 679,
  OPT_fmax_errors_ = 680,
  OPT_fmax_identifier_length_ = 681,
  OPT_fmax_stack_var_size_ = 682,
  OPT_fmax_subrecord_length_ = 683,
  OPT_fmem_report = 684,
  OPT_fmerge_all_constants = 685,
  OPT_fmerge_constants = 686,
  OPT_fmerge_debug_strings = 687,
  OPT_fmessage_length_ = 688,
  OPT_fmodule_private = 689,
  OPT_fmodulo_sched = 690,
  OPT_fmodulo_sched_allow_regmoves = 691,
  OPT_fmove_loop_invariants = 692,
  OPT_fms_extensions = 693,
  OPT_fmudflap = 694,
  OPT_fmudflapir = 695,
  OPT_fmudflapth = 696,
  OPT_fnext_runtime = 699,
  OPT_fnil_receivers = 700,
  OPT_fnon_call_exceptions = 701,
  OPT_fnonansi_builtins = 702,
  OPT_fnothrow_opt = 704,
  OPT_fobjc_abi_version_ = 705,
  OPT_fobjc_call_cxx_cdtors = 706,
  OPT_fobjc_direct_dispatch = 707,
  OPT_fobjc_exceptions = 708,
  OPT_fobjc_gc = 709,
  OPT_fobjc_nilcheck = 710,
  OPT_fobjc_sjlj_exceptions = 711,
  OPT_fobjc_std_objc1 = 712,
  OPT_fomit_frame_pointer = 713,
  OPT_fopenmp = 714,
  OPT_foperator_names = 715,
  OPT_foptimize_register_move = 716,
  OPT_foptimize_sibling_calls = 717,
  OPT_foptimize_static_class_initialization = 718,
  OPT_foptimize_strlen = 719,
  OPT_foutput_class_dir_ = 721,
  OPT_fpack_derived = 722,
  OPT_fpack_struct = 723,
  OPT_fpack_struct_ = 724,
  OPT_fpartial_inlining = 725,
  OPT_fpcc_struct_return = 726,
  OPT_fpch_deps = 727,
  OPT_fpch_preprocess = 728,
  OPT_fpeel_loops = 729,
  OPT_fpeephole = 730,
  OPT_fpeephole2 = 731,
  OPT_fpermissive = 732,
  OPT_fpic = 733,
  OPT_fpie = 734,
  OPT_fplan9_extensions = 735,
  OPT_fplugin_arg_ = 736,
  OPT_fplugin_ = 737,
  OPT_fpost_ipa_mem_report = 738,
  OPT_fpre_ipa_mem_report = 739,
  OPT_fpredictive_commoning = 740,
  OPT_fprefetch_loop_arrays = 741,
  OPT_fpreprocessed = 742,
  OPT_fpretty_templates = 743,
  OPT_fprofile = 744,
  OPT_fprofile_arcs = 745,
  OPT_fprofile_correction = 746,
  OPT_fprofile_dir_ = 747,
  OPT_fprofile_generate = 748,
  OPT_fprofile_generate_ = 749,
  OPT_fprofile_use = 750,
  OPT_fprofile_use_ = 751,
  OPT_fprofile_values = 752,
  OPT_fprotect_parens = 753,
  OPT_frandom_seed = 754,
  OPT_frandom_seed_ = 755,
  OPT_frange_check = 756,
  OPT_freal_4_real_10 = 757,
  OPT_freal_4_real_16 = 758,
  OPT_freal_4_real_8 = 759,
  OPT_freal_8_real_10 = 760,
  OPT_freal_8_real_16 = 761,
  OPT_freal_8_real_4 = 762,
  OPT_frealloc_lhs = 763,
  OPT_freciprocal_math = 764,
  OPT_frecord_gcc_switches = 765,
  OPT_frecord_marker_4 = 766,
  OPT_frecord_marker_8 = 767,
  OPT_frecursive = 768,
  OPT_freduced_reflection = 769,
  OPT_free = 770,
  OPT_freg_struct_return = 771,
  OPT_fregmove = 772,
  OPT_frename_registers = 773,
  OPT_freorder_blocks = 774,
  OPT_freorder_blocks_and_partition = 775,
  OPT_freorder_functions = 776,
  OPT_frepack_arrays = 777,
  OPT_freplace_objc_classes = 778,
  OPT_frepo = 779,
  OPT_frequire_return_statement = 780,
  OPT_frerun_cse_after_loop = 781,
  OPT_freschedule_modulo_scheduled_loops = 783,
  OPT_fresolution_ = 784,
  OPT_frounding_math = 785,
  OPT_frtti = 786,
  OPT_fsaw_java_file = 787,
  OPT_fsched_critical_path_heuristic = 788,
  OPT_fsched_dep_count_heuristic = 789,
  OPT_fsched_group_heuristic = 790,
  OPT_fsched_interblock = 791,
  OPT_fsched_last_insn_heuristic = 792,
  OPT_fsched_pressure = 793,
  OPT_fsched_rank_heuristic = 794,
  OPT_fsched_spec = 795,
  OPT_fsched_spec_insn_heuristic = 796,
  OPT_fsched_spec_load = 797,
  OPT_fsched_spec_load_dangerous = 798,
  OPT_fsched_stalled_insns = 799,
  OPT_fsched_stalled_insns_dep = 800,
  OPT_fsched_stalled_insns_dep_ = 801,
  OPT_fsched_stalled_insns_ = 802,
  OPT_fsched_verbose_ = 803,
  OPT_fsched2_use_superblocks = 804,
  OPT_fschedule_insns = 806,
  OPT_fschedule_insns2 = 807,
  OPT_fsecond_underscore = 808,
  OPT_fsection_anchors = 809,
  OPT_fsel_sched_pipelining = 811,
  OPT_fsel_sched_pipelining_outer_loops = 812,
  OPT_fsel_sched_reschedule_pipelined = 813,
  OPT_fselective_scheduling = 814,
  OPT_fselective_scheduling2 = 815,
  OPT_fshort_double = 816,
  OPT_fshort_enums = 817,
  OPT_fshort_wchar = 818,
  OPT_fshow_column = 819,
  OPT_fshrink_wrap = 820,
  OPT_fsign_zero = 821,
  OPT_fsignaling_nans = 822,
  OPT_fsigned_bitfields = 823,
  OPT_fsigned_char = 824,
  OPT_fsigned_zeros = 825,
  OPT_fsingle_precision_constant = 826,
  OPT_fsource_filename_ = 827,
  OPT_fsource_ = 828,
  OPT_fsplit_ivs_in_unroller = 829,
  OPT_fsplit_stack = 830,
  OPT_fsplit_wide_types = 831,
  OPT_fstack_arrays = 833,
  OPT_fstack_check_ = 835,
  OPT_fstack_limit = 836,
  OPT_fstack_limit_register_ = 837,
  OPT_fstack_limit_symbol_ = 838,
  OPT_fstack_protector = 839,
  OPT_fstack_protector_all = 840,
  OPT_fstack_usage = 841,
  OPT_fstats = 842,
  OPT_fstore_check = 843,
  OPT_fstrict_aliasing = 845,
  OPT_fstrict_enums = 846,
  OPT_fstrict_overflow = 847,
  OPT_fstrict_volatile_bitfields = 849,
  OPT_fsyntax_only = 850,
  OPT_ftabstop_ = 851,
  OPT_ftarget_ = 853,
  OPT_ftemplate_depth_ = 855,
  OPT_ftest_coverage = 856,
  OPT_fthread_jumps = 858,
  OPT_fthreadsafe_statics = 859,
  OPT_ftime_report = 860,
  OPT_ftls_model_ = 861,
  OPT_ftoplevel_reorder = 862,
  OPT_ftracer = 863,
  OPT_ftrack_macro_expansion = 864,
  OPT_ftrack_macro_expansion_ = 865,
  OPT_ftrapping_math = 866,
  OPT_ftrapv = 867,
  OPT_ftree_bit_ccp = 868,
  OPT_ftree_builtin_call_dce = 869,
  OPT_ftree_ccp = 870,
  OPT_ftree_ch = 871,
  OPT_ftree_copy_prop = 872,
  OPT_ftree_copyrename = 873,
  OPT_ftree_cselim = 874,
  OPT_ftree_dce = 875,
  OPT_ftree_dominator_opts = 876,
  OPT_ftree_dse = 877,
  OPT_ftree_forwprop = 878,
  OPT_ftree_fre = 879,
  OPT_ftree_loop_distribute_patterns = 880,
  OPT_ftree_loop_distribution = 881,
  OPT_ftree_loop_if_convert = 882,
  OPT_ftree_loop_if_convert_stores = 883,
  OPT_ftree_loop_im = 884,
  OPT_ftree_loop_ivcanon = 885,
  OPT_ftree_loop_optimize = 887,
  OPT_ftree_lrs = 888,
  OPT_ftree_parallelize_loops_ = 889,
  OPT_ftree_phiprop = 890,
  OPT_ftree_pre = 891,
  OPT_ftree_pta = 892,
  OPT_ftree_reassoc = 893,
  OPT_ftree_scev_cprop = 895,
  OPT_ftree_sink = 896,
  OPT_ftree_slp_vectorize = 897,
  OPT_ftree_sra = 898,
  OPT_ftree_switch_conversion = 901,
  OPT_ftree_tail_merge = 902,
  OPT_ftree_ter = 903,
  OPT_ftree_vect_loop_version = 904,
  OPT_ftree_vectorize = 905,
  OPT_ftree_vectorizer_verbose_ = 906,
  OPT_ftree_vrp = 907,
  OPT_funderscoring = 908,
  OPT_funit_at_a_time = 909,
  OPT_funroll_all_loops = 910,
  OPT_funroll_loops = 911,
  OPT_funsafe_loop_optimizations = 912,
  OPT_funsafe_math_optimizations = 913,
  OPT_funsigned_bitfields = 914,
  OPT_funsigned_char = 915,
  OPT_funswitch_loops = 916,
  OPT_funwind_tables = 917,
  OPT_fuse_atomic_builtins = 918,
  OPT_fuse_boehm_gc = 919,
  OPT_fuse_cxa_atexit = 920,
  OPT_fuse_cxa_get_exception_ptr = 921,
  OPT_fuse_divide_subroutine = 922,
  OPT_fuse_linker_plugin = 923,
  OPT_fvar_tracking = 924,
  OPT_fvar_tracking_assignments = 925,
  OPT_fvar_tracking_assignments_toggle = 926,
  OPT_fvar_tracking_uninit = 927,
  OPT_fvariable_expansion_in_unroller = 928,
  OPT_fvect_cost_model = 929,
  OPT_fverbose_asm = 930,
  OPT_fvisibility_inlines_hidden = 932,
  OPT_fvisibility_ms_compat = 933,
  OPT_fvisibility_ = 934,
  OPT_fvpt = 935,
  OPT_fweak = 938,
  OPT_fweb = 939,
  OPT_fwhole_file = 940,
  OPT_fwhole_program = 941,
  OPT_fwide_exec_charset_ = 942,
  OPT_fworking_directory = 943,
  OPT_fwpa = 944,
  OPT_fwrapv = 945,
  OPT_fzero_initialized_in_bss = 948,
  OPT_fzero_link = 949,
  OPT_g = 950,
  OPT_gant = 951,
  OPT_gcoff = 952,
  OPT_gdwarf_ = 953,
  OPT_gen_decls = 954,
  OPT_ggdb = 955,
  OPT_gnat = 956,
  OPT_gnatO = 957,
  OPT_gno_record_gcc_switches = 958,
  OPT_gno_strict_dwarf = 959,
  OPT_grecord_gcc_switches = 960,
  OPT_gstabs = 961,
  OPT_gstabs_ = 962,
  OPT_gstrict_dwarf = 963,
  OPT_gtoggle = 964,
  OPT_gvms = 965,
  OPT_gxcoff = 966,
  OPT_gxcoff_ = 967,
  OPT_h = 968,
  OPT_idirafter = 969,
  OPT_imacros = 970,
  OPT_imultilib = 971,
  OPT_include = 972,
  OPT_iplugindir_ = 973,
  OPT_iprefix = 974,
  OPT_iquote = 975,
  OPT_isysroot = 976,
  OPT_isystem = 977,
  OPT_iwithprefix = 978,
  OPT_iwithprefixbefore = 979,
  OPT_k8 = 980,
  OPT_l = 981,
  OPT_lang_asm = 982,
  OPT_mabi_ = 983,
  OPT_mabort_on_noreturn = 984,
  OPT_mandroid = 985,
  OPT_mapcs = 986,
  OPT_mapcs_float = 987,
  OPT_mapcs_frame = 988,
  OPT_mapcs_reentrant = 989,
  OPT_mapcs_stack_check = 990,
  OPT_march_ = 991,
  OPT_marm = 992,
  OPT_mbig_endian = 993,
  OPT_mbionic = 994,
  OPT_mcallee_super_interworking = 995,
  OPT_mcaller_super_interworking = 996,
  OPT_mcirrus_fix_invalid_insns = 997,
  OPT_mcpu_ = 998,
  OPT_mfix_cortex_m3_ldrd = 999,
  OPT_mfloat_abi_ = 1000,
  OPT_mfp16_format_ = 1001,
  OPT_mfpe = 1004,
  OPT_mfpu_ = 1007,
  OPT_mglibc = 1008,
  OPT_mlittle_endian = 1010,
  OPT_mlong_calls = 1011,
  OPT_mpic_register_ = 1012,
  OPT_mpoke_function_name = 1013,
  OPT_msched_prolog = 1014,
  OPT_msingle_pic_base = 1015,
  OPT_mstructure_size_boundary_ = 1017,
  OPT_mthumb = 1018,
  OPT_mthumb_interwork = 1019,
  OPT_mtls_dialect_ = 1020,
  OPT_mtp_ = 1021,
  OPT_mtpcs_frame = 1022,
  OPT_mtpcs_leaf_frame = 1023,
  OPT_mtune_ = 1024,
  OPT_muclibc = 1025,
  OPT_munaligned_access = 1026,
  OPT_mvectorize_with_neon_double = 1027,
  OPT_mvectorize_with_neon_quad = 1028,
  OPT_mword_relocations = 1029,
  OPT_mwords_little_endian = 1030,
  OPT_n = 1031,
  OPT_no_canonical_prefixes = 1032,
  OPT_no_integrated_cpp = 1033,
  OPT_nocpp = 1034,
  OPT_nodefaultlibs = 1035,
  OPT_nostartfiles = 1036,
  OPT_nostdinc = 1037,
  OPT_nostdinc__ = 1038,
  OPT_nostdlib = 1039,
  OPT_o = 1040,
  OPT_p = 1041,
  OPT_pass_exit_codes = 1042,
  OPT_pedantic = 1043,
  OPT_pedantic_errors = 1044,
  OPT_pg = 1045,
  OPT_pie = 1046,
  OPT_pipe = 1047,
  OPT_posix = 1048,
  OPT_print_file_name_ = 1049,
  OPT_print_libgcc_file_name = 1050,
  OPT_print_multi_directory = 1051,
  OPT_print_multi_lib = 1052,
  OPT_print_multi_os_directory = 1053,
  OPT_print_objc_runtime_info = 1054,
  OPT_print_prog_name_ = 1055,
  OPT_print_search_dirs = 1056,
  OPT_print_sysroot = 1057,
  OPT_print_sysroot_headers_suffix = 1058,
  OPT_profile = 1059,
  OPT_pthread = 1060,
  OPT_quiet = 1061,
  OPT_r = 1062,
  OPT_rdynamic = 1063,
  OPT_remap = 1064,
  OPT_s = 1065,
  OPT_s_bc_abi = 1066,
  OPT_save_temps = 1067,
  OPT_save_temps_ = 1068,
  OPT_shared = 1069,
  OPT_shared_libgcc = 1070,
  OPT_specs_ = 1072,
  OPT_static = 1073,
  OPT_static_libgcc = 1074,
  OPT_static_libgcj = 1075,
  OPT_static_libgfortran = 1076,
  OPT_static_libgo = 1077,
  OPT_static_libstdc__ = 1078,
  OPT_std_c__11 = 1081,
  OPT_std_c__98 = 1082,
  OPT_std_c11 = 1083,
  OPT_std_c90 = 1086,
  OPT_std_c99 = 1087,
  OPT_std_f2003 = 1089,
  OPT_std_f2008 = 1090,
  OPT_std_f2008ts = 1091,
  OPT_std_f95 = 1092,
  OPT_std_gnu = 1093,
  OPT_std_gnu__11 = 1096,
  OPT_std_gnu__98 = 1097,
  OPT_std_gnu11 = 1098,
  OPT_std_gnu90 = 1101,
  OPT_std_gnu99 = 1102,
  OPT_std_iso9899_199409 = 1105,
  OPT_std_legacy = 1109,
  OPT_symbolic = 1110,
  OPT_t = 1111,
  OPT_time = 1112,
  OPT_time_ = 1113,
  OPT_tno_android_cc = 1114,
  OPT_tno_android_ld = 1115,
  OPT_traditional = 1116,
  OPT_traditional_cpp = 1117,
  OPT_trigraphs = 1118,
  OPT_u = 1119,
  OPT_undef = 1120,
  OPT_v = 1121,
  OPT_version = 1122,
  OPT_w = 1123,
  OPT_wrapper = 1124,
  OPT_x = 1125,
  OPT_z = 1126,
  N_OPTS,
  OPT_SPECIAL_unknown,
  OPT_SPECIAL_ignore,
  OPT_SPECIAL_program_name,
  OPT_SPECIAL_input_file
};
# 28 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/flags.h" 2
extern const char *const debug_type_names[];
extern void strip_off_ending (char *, int);
extern int base_of_path (const char *path, const char **base_out);
extern unsigned char fast_math_flags_set_p (const struct gcc_options *);
extern unsigned char fast_math_flags_struct_set_p (struct cl_optimization *);
# 48 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/flags.h"
extern void set_Wstrict_aliasing (struct gcc_options *opts, int onoff);
extern unsigned char final_insns_dump_p;
extern int flag_permissive;
struct target_flag_state {
  int x_align_loops_log;
  int x_align_loops_max_skip;
  int x_align_jumps_log;
  int x_align_jumps_max_skip;
  int x_align_labels_log;
  int x_align_labels_max_skip;
  int x_align_functions_log;
  enum excess_precision x_flag_excess_precision;
};
extern struct target_flag_state default_target_flag_state;
# 105 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/flags.h"
extern int dump_for_graph;
# 36 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h" 2
enum tree_code {
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/all-tree.def" 1
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def" 1
# 42 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
ERROR_MARK,
IDENTIFIER_NODE,
TREE_LIST,
TREE_VEC,
# 79 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
BLOCK,
# 123 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
OFFSET_TYPE,
# 136 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
ENUMERAL_TYPE,
BOOLEAN_TYPE,
# 150 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
INTEGER_TYPE,
REAL_TYPE,
# 163 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
POINTER_TYPE,
REFERENCE_TYPE,
NULLPTR_TYPE,
FIXED_POINT_TYPE,
# 184 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
COMPLEX_TYPE,
VECTOR_TYPE,
# 205 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
ARRAY_TYPE,
# 215 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
RECORD_TYPE,
UNION_TYPE,
QUAL_UNION_TYPE,
VOID_TYPE,
FUNCTION_TYPE,
METHOD_TYPE,
LANG_TYPE,
# 268 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
INTEGER_CST,
REAL_CST,
FIXED_CST,
COMPLEX_CST,
VECTOR_CST,
STRING_CST,
# 344 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
FUNCTION_DECL,
LABEL_DECL,
FIELD_DECL,
VAR_DECL,
CONST_DECL,
PARM_DECL,
TYPE_DECL,
RESULT_DECL,
DEBUG_EXPR_DECL,
NAMESPACE_DECL,
# 374 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
IMPORTED_DECL,
TRANSLATION_UNIT_DECL,
# 391 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
COMPONENT_REF,
# 401 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
BIT_FIELD_REF,
REALPART_EXPR,
IMAGPART_EXPR,
ARRAY_REF,
ARRAY_RANGE_REF,
INDIRECT_REF,
# 430 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
OBJ_TYPE_REF,
# 446 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
CONSTRUCTOR,
# 456 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
COMPOUND_EXPR,
MODIFY_EXPR,
INIT_EXPR,
TARGET_EXPR,
# 486 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
COND_EXPR,
# 498 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
VEC_COND_EXPR,
# 512 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
VEC_PERM_EXPR,
# 535 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
BIND_EXPR,
CALL_EXPR,
WITH_CLEANUP_EXPR,
# 567 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
CLEANUP_POINT_EXPR,
# 619 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
PLACEHOLDER_EXPR,
PLUS_EXPR,
MINUS_EXPR,
MULT_EXPR,
POINTER_PLUS_EXPR,
TRUNC_DIV_EXPR,
CEIL_DIV_EXPR,
FLOOR_DIV_EXPR,
ROUND_DIV_EXPR,
TRUNC_MOD_EXPR,
CEIL_MOD_EXPR,
FLOOR_MOD_EXPR,
ROUND_MOD_EXPR,
RDIV_EXPR,
EXACT_DIV_EXPR,
FIX_TRUNC_EXPR,
FLOAT_EXPR,
NEGATE_EXPR,
MIN_EXPR,
MAX_EXPR,
ABS_EXPR,
# 689 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
LSHIFT_EXPR,
RSHIFT_EXPR,
LROTATE_EXPR,
RROTATE_EXPR,
BIT_IOR_EXPR,
BIT_XOR_EXPR,
BIT_AND_EXPR,
BIT_NOT_EXPR,
# 709 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
TRUTH_ANDIF_EXPR,
TRUTH_ORIF_EXPR,
TRUTH_AND_EXPR,
TRUTH_OR_EXPR,
TRUTH_XOR_EXPR,
TRUTH_NOT_EXPR,
# 725 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
LT_EXPR,
LE_EXPR,
GT_EXPR,
GE_EXPR,
EQ_EXPR,
NE_EXPR,
UNORDERED_EXPR,
ORDERED_EXPR,
UNLT_EXPR,
UNLE_EXPR,
UNGT_EXPR,
UNGE_EXPR,
UNEQ_EXPR,
LTGT_EXPR,
RANGE_EXPR,
PAREN_EXPR,
CONVERT_EXPR,
ADDR_SPACE_CONVERT_EXPR,
FIXED_CONVERT_EXPR,
NOP_EXPR,
NON_LVALUE_EXPR,
# 782 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
VIEW_CONVERT_EXPR,
COMPOUND_LITERAL_EXPR,
SAVE_EXPR,
ADDR_EXPR,
FDESC_EXPR,
COMPLEX_EXPR,
CONJ_EXPR,
PREDECREMENT_EXPR,
PREINCREMENT_EXPR,
POSTDECREMENT_EXPR,
POSTINCREMENT_EXPR,
VA_ARG_EXPR,
TRY_CATCH_EXPR,
TRY_FINALLY_EXPR,
DECL_EXPR,
LABEL_EXPR,
GOTO_EXPR,
RETURN_EXPR,
EXIT_EXPR,
LOOP_EXPR,
# 877 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
SWITCH_EXPR,
CASE_LABEL_EXPR,
ASM_EXPR,
SSA_NAME,
CATCH_EXPR,
EH_FILTER_EXPR,
SCEV_KNOWN,
SCEV_NOT_KNOWN,
POLYNOMIAL_CHREC,
STATEMENT_LIST,
# 939 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
ASSERT_EXPR,
TREE_BINFO,
WITH_SIZE_EXPR,
# 961 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
REALIGN_LOAD_EXPR,
# 977 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
TARGET_MEM_REF,
# 987 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
MEM_REF,
OMP_PARALLEL,
OMP_TASK,
# 1022 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
OMP_FOR,
OMP_SECTIONS,
OMP_SINGLE,
OMP_SECTION,
OMP_MASTER,
OMP_ORDERED,
OMP_CRITICAL,
OMP_ATOMIC,
OMP_ATOMIC_READ,
# 1072 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
OMP_ATOMIC_CAPTURE_OLD,
OMP_ATOMIC_CAPTURE_NEW,
OMP_CLAUSE,
TRANSACTION_EXPR,
REDUC_MAX_EXPR,
REDUC_MIN_EXPR,
REDUC_PLUS_EXPR,
# 1101 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
DOT_PROD_EXPR,
# 1110 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
WIDEN_SUM_EXPR,
WIDEN_MULT_EXPR,
# 1126 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
WIDEN_MULT_PLUS_EXPR,
WIDEN_MULT_MINUS_EXPR,
# 1142 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
WIDEN_LSHIFT_EXPR,
FMA_EXPR,
VEC_LSHIFT_EXPR,
VEC_RSHIFT_EXPR,
VEC_WIDEN_MULT_HI_EXPR,
VEC_WIDEN_MULT_LO_EXPR,
VEC_UNPACK_HI_EXPR,
VEC_UNPACK_LO_EXPR,
VEC_UNPACK_FLOAT_HI_EXPR,
VEC_UNPACK_FLOAT_LO_EXPR,
VEC_PACK_TRUNC_EXPR,
VEC_PACK_SAT_EXPR,
VEC_PACK_FIX_TRUNC_EXPR,
# 1198 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.def"
VEC_WIDEN_LSHIFT_HI_EXPR,
VEC_WIDEN_LSHIFT_LO_EXPR,
PREDICT_EXPR,
OPTIMIZATION_NODE,
TARGET_OPTION_NODE,
# 2 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/all-tree.def" 2
LAST_AND_UNUSED_TREE_CODE,
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-family/c-common.def" 1
# 41 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-family/c-common.def"
C_MAYBE_CONST_EXPR,
EXCESS_PRECISION_EXPR,
USERDEF_LITERAL,
# 4 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/all-tree.def" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/ada/gcc-interface/ada-tree.def" 1
# 29 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/ada/gcc-interface/ada-tree.def"
UNCONSTRAINED_ARRAY_TYPE,
UNCONSTRAINED_ARRAY_REF,
NULL_EXPR,
PLUS_NOMOD_EXPR,
MINUS_NOMOD_EXPR,
ATTR_ADDR_EXPR,
# 62 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/ada/gcc-interface/ada-tree.def"
STMT_STMT,
LOOP_STMT,
EXIT_STMT,
# 5 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/all-tree.def" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cp/cp-tree.def" 1
# 43 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cp/cp-tree.def"
OFFSET_REF,
PTRMEM_CST,
NEW_EXPR,
VEC_NEW_EXPR,
DELETE_EXPR,
VEC_DELETE_EXPR,
SCOPE_REF,
MEMBER_REF,
TYPE_EXPR,
AGGR_INIT_EXPR,
VEC_INIT_EXPR,
THROW_EXPR,
EMPTY_CLASS_EXPR,
# 109 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cp/cp-tree.def"
BASELINK,
# 126 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cp/cp-tree.def"
TEMPLATE_DECL,
# 161 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cp/cp-tree.def"
TEMPLATE_PARM_INDEX,
# 170 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cp/cp-tree.def"
TEMPLATE_TEMPLATE_PARM,
# 179 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cp/cp-tree.def"
TEMPLATE_TYPE_PARM,
TYPENAME_TYPE,
TYPEOF_TYPE,
BOUND_TEMPLATE_TEMPLATE_PARM,
UNBOUND_CLASS_TEMPLATE,
USING_DECL,
USING_STMT,
DEFAULT_ARG,
DEFERRED_NOEXCEPT,
TEMPLATE_ID_EXPR,
OVERLOAD,
# 243 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cp/cp-tree.def"
PSEUDO_DTOR_EXPR,
MODOP_EXPR,
CAST_EXPR,
REINTERPRET_CAST_EXPR,
CONST_CAST_EXPR,
STATIC_CAST_EXPR,
DYNAMIC_CAST_EXPR,
IMPLICIT_CONV_EXPR,
DOTSTAR_EXPR,
TYPEID_EXPR,
NOEXCEPT_EXPR,
# 267 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cp/cp-tree.def"
NON_DEPENDENT_EXPR,
CTOR_INITIALIZER,
TRY_BLOCK,
EH_SPEC_BLOCK,
HANDLER,
MUST_NOT_THROW_EXPR,
CLEANUP_STMT,
IF_STMT,
FOR_STMT,
RANGE_FOR_STMT,
WHILE_STMT,
DO_STMT,
BREAK_STMT,
CONTINUE_STMT,
SWITCH_STMT,
EXPR_STMT,
TAG_DEFN,
OFFSETOF_EXPR,
SIZEOF_EXPR,
ARROW_EXPR,
ALIGNOF_EXPR,
AT_ENCODE_EXPR,
STMT_EXPR,
UNARY_PLUS_EXPR,
STATIC_ASSERT,
# 384 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cp/cp-tree.def"
TYPE_ARGUMENT_PACK,
# 393 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cp/cp-tree.def"
NONTYPE_ARGUMENT_PACK,
# 416 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cp/cp-tree.def"
TYPE_PACK_EXPANSION,
EXPR_PACK_EXPANSION,
# 435 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cp/cp-tree.def"
ARGUMENT_PACK_SELECT,
TRAIT_EXPR,
# 451 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cp/cp-tree.def"
LAMBDA_EXPR,
# 460 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cp/cp-tree.def"
DECLTYPE_TYPE,
UNDERLYING_TYPE,
BASES,
# 478 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cp/cp-tree.def"
TEMPLATE_INFO,
# 6 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/all-tree.def" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/java/java-tree.def" 1
# 23 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/java/java-tree.def"
URSHIFT_EXPR,
COMPARE_EXPR,
COMPARE_L_EXPR,
COMPARE_G_EXPR,
# 7 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/all-tree.def" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/objc/objc-tree.def" 1
# 25 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/objc/objc-tree.def"
CLASS_INTERFACE_TYPE,
CLASS_IMPLEMENTATION_TYPE,
CATEGORY_INTERFACE_TYPE,
CATEGORY_IMPLEMENTATION_TYPE,
PROTOCOL_INTERFACE_TYPE,
KEYWORD_DECL,
INSTANCE_METHOD_DECL,
CLASS_METHOD_DECL,
PROPERTY_DECL,
MESSAGE_SEND_EXPR,
CLASS_REFERENCE_EXPR,
# 71 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/objc/objc-tree.def"
PROPERTY_REF,
# 7 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/all-tree.def" 2
# 44 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h" 2
MAX_TREE_CODES
};
extern unsigned char tree_contains_struct[MAX_TREE_CODES][64];
# 121 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
enum tree_code_class {
  tcc_exceptional,
  tcc_constant,
  tcc_type,
  tcc_declaration,
  tcc_reference,
  tcc_comparison,
  tcc_unary,
  tcc_binary,
  tcc_statement,
  tcc_vl_exp,
  tcc_expression
};
extern const char *const tree_code_class_strings[];
extern const enum tree_code_class tree_code_type[];
# 235 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern const unsigned char tree_code_length[];
extern const char *const tree_code_name[];
# 250 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
typedef enum {
  ALIAS_DIAG_NONE = 0x0,
  ALIAS_DIAG_TO_UNDEF = 0x1,
  ALIAS_DIAG_TO_EXTERN = 0x2
} alias_diag_flags;
typedef struct alias_pair
{
  tree decl;
  tree target;
  int emitted_diags;
} alias_pair;
typedef struct VEC_alias_pair_base { struct vec_prefix prefix; alias_pair vec[1]; } VEC_alias_pair_base; typedef struct VEC_alias_pair_none { VEC_alias_pair_base base; } VEC_alias_pair_none; static __inline__ unsigned VEC_alias_pair_base_length (const VEC_alias_pair_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static __inline__ alias_pair *VEC_alias_pair_base_last (VEC_alias_pair_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return &vec_->vec[vec_->prefix.num - 1]; } static __inline__ alias_pair *VEC_alias_pair_base_index (VEC_alias_pair_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return &vec_->vec[ix_]; } static __inline__ int VEC_alias_pair_base_iterate (VEC_alias_pair_base *vec_, unsigned ix_, alias_pair **ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = &vec_->vec[ix_]; return 1; } else { *ptr = 0; return 0; } } static __inline__ size_t VEC_alias_pair_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_alias_pair_base, vec) + alloc_ * sizeof(alias_pair); } static __inline__ void VEC_alias_pair_base_embedded_init (VEC_alias_pair_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static __inline__ int VEC_alias_pair_base_space (VEC_alias_pair_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static __inline__ void VEC_alias_pair_base_splice (VEC_alias_pair_base *dst_, VEC_alias_pair_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (alias_pair)); dst_->prefix.num += len_; } } static __inline__ alias_pair *VEC_alias_pair_base_quick_push (VEC_alias_pair_base *vec_, const alias_pair *obj_ ) { alias_pair *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; if (obj_) *slot_ = *obj_; return slot_; } static __inline__ void VEC_alias_pair_base_pop (VEC_alias_pair_base *vec_ ) { (void)(vec_->prefix.num); --vec_->prefix.num; } static __inline__ void VEC_alias_pair_base_truncate (VEC_alias_pair_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static __inline__ alias_pair *VEC_alias_pair_base_replace (VEC_alias_pair_base *vec_, unsigned ix_, const alias_pair *obj_ ) { alias_pair *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; if (obj_) *slot_ = *obj_; return slot_; } static __inline__ alias_pair *VEC_alias_pair_base_quick_insert (VEC_alias_pair_base *vec_, unsigned ix_, const alias_pair *obj_ ) { alias_pair *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (alias_pair)); if (obj_) *slot_ = *obj_; return slot_; } static __inline__ void VEC_alias_pair_base_ordered_remove (VEC_alias_pair_base *vec_, unsigned ix_ ) { alias_pair *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (alias_pair)); } static __inline__ void VEC_alias_pair_base_unordered_remove (VEC_alias_pair_base *vec_, unsigned ix_ ) { (void)(ix_ < vec_->prefix.num); vec_->vec[ix_] = vec_->vec[--vec_->prefix.num]; } static __inline__ void VEC_alias_pair_base_block_remove (VEC_alias_pair_base *vec_, unsigned ix_, unsigned len_ ) { alias_pair *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (alias_pair)); } static __inline__ alias_pair *VEC_alias_pair_base_address (VEC_alias_pair_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_alias_pair_base_lower_bound (VEC_alias_pair_base *vec_, const alias_pair *obj_, unsigned char (*lessthan_)(const alias_pair *, const alias_pair *) ) { unsigned int len_ = VEC_alias_pair_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { alias_pair *middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_alias_pair_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_alias_pair_gc { VEC_alias_pair_base base; } VEC_alias_pair_gc; static __inline__ VEC_alias_pair_gc *VEC_alias_pair_gc_alloc (int alloc_ ) { return (VEC_alias_pair_gc *) vec_gc_o_reserve_exact (((void *)0), alloc_, __builtin_offsetof (VEC_alias_pair_gc, base.vec), sizeof (alias_pair) ); } static __inline__ VEC_alias_pair_gc *VEC_alias_pair_gc_copy (VEC_alias_pair_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_alias_pair_gc *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_alias_pair_gc *)(vec_gc_o_reserve_exact (((void *)0), len_, __builtin_offsetof (VEC_alias_pair_gc, base.vec), sizeof (alias_pair) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (alias_pair) * len_); } return new_vec_; } static __inline__ void VEC_alias_pair_gc_free (VEC_alias_pair_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = ((void *)0); } static __inline__ int VEC_alias_pair_gc_reserve (VEC_alias_pair_gc **vec_, int alloc_ ) { int extend = !VEC_alias_pair_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_alias_pair_gc *) vec_gc_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_alias_pair_gc, base.vec), sizeof (alias_pair) ); return extend; } static __inline__ int VEC_alias_pair_gc_reserve_exact (VEC_alias_pair_gc **vec_, int alloc_ ) { int extend = !VEC_alias_pair_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_alias_pair_gc *) vec_gc_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_alias_pair_gc, base.vec), sizeof (alias_pair) ); return extend; } static __inline__ void VEC_alias_pair_gc_safe_grow (VEC_alias_pair_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_alias_pair_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_alias_pair_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_alias_pair_gc_safe_grow_cleared (VEC_alias_pair_gc **vec_, int size_ ) { int oldsize = VEC_alias_pair_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_alias_pair_gc_safe_grow (vec_, size_ ); memset (&(VEC_alias_pair_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (alias_pair) * (size_ - oldsize)); } static __inline__ void VEC_alias_pair_gc_safe_splice (VEC_alias_pair_gc **dst_, VEC_alias_pair_base *src_ ) { if (src_) { VEC_alias_pair_gc_reserve_exact (dst_, src_->prefix.num ); VEC_alias_pair_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ alias_pair *VEC_alias_pair_gc_safe_push (VEC_alias_pair_gc **vec_, const alias_pair *obj_ ) { VEC_alias_pair_gc_reserve (vec_, 1 ); return VEC_alias_pair_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ alias_pair *VEC_alias_pair_gc_safe_insert (VEC_alias_pair_gc **vec_, unsigned ix_, const alias_pair *obj_ ) { VEC_alias_pair_gc_reserve (vec_, 1 ); return VEC_alias_pair_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
extern VEC_alias_pair_gc * alias_pairs;
enum built_in_class
{
  NOT_BUILT_IN = 0,
  BUILT_IN_FRONTEND,
  BUILT_IN_MD,
  BUILT_IN_NORMAL
};
extern const char *const built_in_class_names[4];
enum built_in_function
{
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/builtins.def" 1
# 184 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/builtins.def"
BUILT_IN_NONE,
BUILT_IN_ACOS,
BUILT_IN_ACOSF,
BUILT_IN_ACOSH,
BUILT_IN_ACOSHF,
BUILT_IN_ACOSHL,
BUILT_IN_ACOSL,
BUILT_IN_ASIN,
BUILT_IN_ASINF,
BUILT_IN_ASINH,
BUILT_IN_ASINHF,
BUILT_IN_ASINHL,
BUILT_IN_ASINL,
BUILT_IN_ATAN,
BUILT_IN_ATAN2,
BUILT_IN_ATAN2F,
BUILT_IN_ATAN2L,
BUILT_IN_ATANF,
BUILT_IN_ATANH,
BUILT_IN_ATANHF,
BUILT_IN_ATANHL,
BUILT_IN_ATANL,
BUILT_IN_CBRT,
BUILT_IN_CBRTF,
BUILT_IN_CBRTL,
BUILT_IN_CEIL,
BUILT_IN_CEILF,
BUILT_IN_CEILL,
BUILT_IN_COPYSIGN,
BUILT_IN_COPYSIGNF,
BUILT_IN_COPYSIGNL,
BUILT_IN_COS,
BUILT_IN_COSF,
BUILT_IN_COSH,
BUILT_IN_COSHF,
BUILT_IN_COSHL,
BUILT_IN_COSL,
BUILT_IN_DREM,
BUILT_IN_DREMF,
BUILT_IN_DREML,
BUILT_IN_ERF,
BUILT_IN_ERFC,
BUILT_IN_ERFCF,
BUILT_IN_ERFCL,
BUILT_IN_ERFF,
BUILT_IN_ERFL,
BUILT_IN_EXP,
BUILT_IN_EXP10,
BUILT_IN_EXP10F,
BUILT_IN_EXP10L,
BUILT_IN_EXP2,
BUILT_IN_EXP2F,
BUILT_IN_EXP2L,
BUILT_IN_EXPF,
BUILT_IN_EXPL,
BUILT_IN_EXPM1,
BUILT_IN_EXPM1F,
BUILT_IN_EXPM1L,
BUILT_IN_FABS,
BUILT_IN_FABSF,
BUILT_IN_FABSL,
BUILT_IN_FDIM,
BUILT_IN_FDIMF,
BUILT_IN_FDIML,
BUILT_IN_FLOOR,
BUILT_IN_FLOORF,
BUILT_IN_FLOORL,
BUILT_IN_FMA,
BUILT_IN_FMAF,
BUILT_IN_FMAL,
BUILT_IN_FMAX,
BUILT_IN_FMAXF,
BUILT_IN_FMAXL,
BUILT_IN_FMIN,
BUILT_IN_FMINF,
BUILT_IN_FMINL,
BUILT_IN_FMOD,
BUILT_IN_FMODF,
BUILT_IN_FMODL,
BUILT_IN_FREXP,
BUILT_IN_FREXPF,
BUILT_IN_FREXPL,
BUILT_IN_GAMMA,
BUILT_IN_GAMMAF,
BUILT_IN_GAMMAL,
BUILT_IN_GAMMA_R,
BUILT_IN_GAMMAF_R,
BUILT_IN_GAMMAL_R,
BUILT_IN_HUGE_VAL,
BUILT_IN_HUGE_VALF,
BUILT_IN_HUGE_VALL,
BUILT_IN_HYPOT,
BUILT_IN_HYPOTF,
BUILT_IN_HYPOTL,
BUILT_IN_ICEIL,
BUILT_IN_ICEILF,
BUILT_IN_ICEILL,
BUILT_IN_IFLOOR,
BUILT_IN_IFLOORF,
BUILT_IN_IFLOORL,
BUILT_IN_ILOGB,
BUILT_IN_ILOGBF,
BUILT_IN_ILOGBL,
BUILT_IN_INF,
BUILT_IN_INFF,
BUILT_IN_INFL,
BUILT_IN_INFD32,
BUILT_IN_INFD64,
BUILT_IN_INFD128,
BUILT_IN_IRINT,
BUILT_IN_IRINTF,
BUILT_IN_IRINTL,
BUILT_IN_IROUND,
BUILT_IN_IROUNDF,
BUILT_IN_IROUNDL,
BUILT_IN_J0,
BUILT_IN_J0F,
BUILT_IN_J0L,
BUILT_IN_J1,
BUILT_IN_J1F,
BUILT_IN_J1L,
BUILT_IN_JN,
BUILT_IN_JNF,
BUILT_IN_JNL,
BUILT_IN_LCEIL,
BUILT_IN_LCEILF,
BUILT_IN_LCEILL,
BUILT_IN_LDEXP,
BUILT_IN_LDEXPF,
BUILT_IN_LDEXPL,
BUILT_IN_LFLOOR,
BUILT_IN_LFLOORF,
BUILT_IN_LFLOORL,
BUILT_IN_LGAMMA,
BUILT_IN_LGAMMAF,
BUILT_IN_LGAMMAL,
BUILT_IN_LGAMMA_R,
BUILT_IN_LGAMMAF_R,
BUILT_IN_LGAMMAL_R,
BUILT_IN_LLCEIL,
BUILT_IN_LLCEILF,
BUILT_IN_LLCEILL,
BUILT_IN_LLFLOOR,
BUILT_IN_LLFLOORF,
BUILT_IN_LLFLOORL,
BUILT_IN_LLRINT,
BUILT_IN_LLRINTF,
BUILT_IN_LLRINTL,
BUILT_IN_LLROUND,
BUILT_IN_LLROUNDF,
BUILT_IN_LLROUNDL,
BUILT_IN_LOG,
BUILT_IN_LOG10,
BUILT_IN_LOG10F,
BUILT_IN_LOG10L,
BUILT_IN_LOG1P,
BUILT_IN_LOG1PF,
BUILT_IN_LOG1PL,
BUILT_IN_LOG2,
BUILT_IN_LOG2F,
BUILT_IN_LOG2L,
BUILT_IN_LOGB,
BUILT_IN_LOGBF,
BUILT_IN_LOGBL,
BUILT_IN_LOGF,
BUILT_IN_LOGL,
BUILT_IN_LRINT,
BUILT_IN_LRINTF,
BUILT_IN_LRINTL,
BUILT_IN_LROUND,
BUILT_IN_LROUNDF,
BUILT_IN_LROUNDL,
BUILT_IN_MODF,
BUILT_IN_MODFF,
BUILT_IN_MODFL,
BUILT_IN_NAN,
BUILT_IN_NANF,
BUILT_IN_NANL,
BUILT_IN_NAND32,
BUILT_IN_NAND64,
BUILT_IN_NAND128,
BUILT_IN_NANS,
BUILT_IN_NANSF,
BUILT_IN_NANSL,
BUILT_IN_NEARBYINT,
BUILT_IN_NEARBYINTF,
BUILT_IN_NEARBYINTL,
BUILT_IN_NEXTAFTER,
BUILT_IN_NEXTAFTERF,
BUILT_IN_NEXTAFTERL,
BUILT_IN_NEXTTOWARD,
BUILT_IN_NEXTTOWARDF,
BUILT_IN_NEXTTOWARDL,
BUILT_IN_POW,
BUILT_IN_POW10,
BUILT_IN_POW10F,
BUILT_IN_POW10L,
BUILT_IN_POWF,
BUILT_IN_POWI,
BUILT_IN_POWIF,
BUILT_IN_POWIL,
BUILT_IN_POWL,
BUILT_IN_REMAINDER,
BUILT_IN_REMAINDERF,
BUILT_IN_REMAINDERL,
BUILT_IN_REMQUO,
BUILT_IN_REMQUOF,
BUILT_IN_REMQUOL,
BUILT_IN_RINT,
BUILT_IN_RINTF,
BUILT_IN_RINTL,
BUILT_IN_ROUND,
BUILT_IN_ROUNDF,
BUILT_IN_ROUNDL,
BUILT_IN_SCALB,
BUILT_IN_SCALBF,
BUILT_IN_SCALBL,
BUILT_IN_SCALBLN,
BUILT_IN_SCALBLNF,
BUILT_IN_SCALBLNL,
BUILT_IN_SCALBN,
BUILT_IN_SCALBNF,
BUILT_IN_SCALBNL,
BUILT_IN_SIGNBIT,
BUILT_IN_SIGNBITF,
BUILT_IN_SIGNBITL,
BUILT_IN_SIGNBITD32,
BUILT_IN_SIGNBITD64,
BUILT_IN_SIGNBITD128,
BUILT_IN_SIGNIFICAND,
BUILT_IN_SIGNIFICANDF,
BUILT_IN_SIGNIFICANDL,
BUILT_IN_SIN,
BUILT_IN_SINCOS,
BUILT_IN_SINCOSF,
BUILT_IN_SINCOSL,
BUILT_IN_SINF,
BUILT_IN_SINH,
BUILT_IN_SINHF,
BUILT_IN_SINHL,
BUILT_IN_SINL,
BUILT_IN_SQRT,
BUILT_IN_SQRTF,
BUILT_IN_SQRTL,
BUILT_IN_TAN,
BUILT_IN_TANF,
BUILT_IN_TANH,
BUILT_IN_TANHF,
BUILT_IN_TANHL,
BUILT_IN_TANL,
BUILT_IN_TGAMMA,
BUILT_IN_TGAMMAF,
BUILT_IN_TGAMMAL,
BUILT_IN_TRUNC,
BUILT_IN_TRUNCF,
BUILT_IN_TRUNCL,
BUILT_IN_Y0,
BUILT_IN_Y0F,
BUILT_IN_Y0L,
BUILT_IN_Y1,
BUILT_IN_Y1F,
BUILT_IN_Y1L,
BUILT_IN_YN,
BUILT_IN_YNF,
BUILT_IN_YNL,
BUILT_IN_CABS,
BUILT_IN_CABSF,
BUILT_IN_CABSL,
BUILT_IN_CACOS,
BUILT_IN_CACOSF,
BUILT_IN_CACOSH,
BUILT_IN_CACOSHF,
BUILT_IN_CACOSHL,
BUILT_IN_CACOSL,
BUILT_IN_CARG,
BUILT_IN_CARGF,
BUILT_IN_CARGL,
BUILT_IN_CASIN,
BUILT_IN_CASINF,
BUILT_IN_CASINH,
BUILT_IN_CASINHF,
BUILT_IN_CASINHL,
BUILT_IN_CASINL,
BUILT_IN_CATAN,
BUILT_IN_CATANF,
BUILT_IN_CATANH,
BUILT_IN_CATANHF,
BUILT_IN_CATANHL,
BUILT_IN_CATANL,
BUILT_IN_CCOS,
BUILT_IN_CCOSF,
BUILT_IN_CCOSH,
BUILT_IN_CCOSHF,
BUILT_IN_CCOSHL,
BUILT_IN_CCOSL,
BUILT_IN_CEXP,
BUILT_IN_CEXPF,
BUILT_IN_CEXPL,
BUILT_IN_CEXPI,
BUILT_IN_CEXPIF,
BUILT_IN_CEXPIL,
BUILT_IN_CIMAG,
BUILT_IN_CIMAGF,
BUILT_IN_CIMAGL,
BUILT_IN_CLOG,
BUILT_IN_CLOGF,
BUILT_IN_CLOGL,
BUILT_IN_CLOG10,
BUILT_IN_CLOG10F,
BUILT_IN_CLOG10L,
BUILT_IN_CONJ,
BUILT_IN_CONJF,
BUILT_IN_CONJL,
BUILT_IN_CPOW,
BUILT_IN_CPOWF,
BUILT_IN_CPOWL,
BUILT_IN_CPROJ,
BUILT_IN_CPROJF,
BUILT_IN_CPROJL,
BUILT_IN_CREAL,
BUILT_IN_CREALF,
BUILT_IN_CREALL,
BUILT_IN_CSIN,
BUILT_IN_CSINF,
BUILT_IN_CSINH,
BUILT_IN_CSINHF,
BUILT_IN_CSINHL,
BUILT_IN_CSINL,
BUILT_IN_CSQRT,
BUILT_IN_CSQRTF,
BUILT_IN_CSQRTL,
BUILT_IN_CTAN,
BUILT_IN_CTANF,
BUILT_IN_CTANH,
BUILT_IN_CTANHF,
BUILT_IN_CTANHL,
BUILT_IN_CTANL,
BUILT_IN_BCMP,
BUILT_IN_BCOPY,
BUILT_IN_BZERO,
BUILT_IN_INDEX,
BUILT_IN_MEMCHR,
BUILT_IN_MEMCMP,
BUILT_IN_MEMCPY,
BUILT_IN_MEMMOVE,
BUILT_IN_MEMPCPY,
BUILT_IN_MEMSET,
BUILT_IN_RINDEX,
BUILT_IN_STPCPY,
BUILT_IN_STPNCPY,
BUILT_IN_STRCASECMP,
BUILT_IN_STRCAT,
BUILT_IN_STRCHR,
BUILT_IN_STRCMP,
BUILT_IN_STRCPY,
BUILT_IN_STRCSPN,
BUILT_IN_STRDUP,
BUILT_IN_STRNDUP,
BUILT_IN_STRLEN,
BUILT_IN_STRNCASECMP,
BUILT_IN_STRNCAT,
BUILT_IN_STRNCMP,
BUILT_IN_STRNCPY,
BUILT_IN_STRPBRK,
BUILT_IN_STRRCHR,
BUILT_IN_STRSPN,
BUILT_IN_STRSTR,
BUILT_IN_FPRINTF,
BUILT_IN_FPRINTF_UNLOCKED,
BUILT_IN_PUTC,
BUILT_IN_PUTC_UNLOCKED,
BUILT_IN_FPUTC,
BUILT_IN_FPUTC_UNLOCKED,
BUILT_IN_FPUTS,
BUILT_IN_FPUTS_UNLOCKED,
BUILT_IN_FSCANF,
BUILT_IN_FWRITE,
BUILT_IN_FWRITE_UNLOCKED,
BUILT_IN_PRINTF,
BUILT_IN_PRINTF_UNLOCKED,
BUILT_IN_PUTCHAR,
BUILT_IN_PUTCHAR_UNLOCKED,
BUILT_IN_PUTS,
BUILT_IN_PUTS_UNLOCKED,
BUILT_IN_SCANF,
BUILT_IN_SNPRINTF,
BUILT_IN_SPRINTF,
BUILT_IN_SSCANF,
BUILT_IN_VFPRINTF,
BUILT_IN_VFSCANF,
BUILT_IN_VPRINTF,
BUILT_IN_VSCANF,
BUILT_IN_VSNPRINTF,
BUILT_IN_VSPRINTF,
BUILT_IN_VSSCANF,
BUILT_IN_ISALNUM,
BUILT_IN_ISALPHA,
BUILT_IN_ISASCII,
BUILT_IN_ISBLANK,
BUILT_IN_ISCNTRL,
BUILT_IN_ISDIGIT,
BUILT_IN_ISGRAPH,
BUILT_IN_ISLOWER,
BUILT_IN_ISPRINT,
BUILT_IN_ISPUNCT,
BUILT_IN_ISSPACE,
BUILT_IN_ISUPPER,
BUILT_IN_ISXDIGIT,
BUILT_IN_TOASCII,
BUILT_IN_TOLOWER,
BUILT_IN_TOUPPER,
BUILT_IN_ISWALNUM,
BUILT_IN_ISWALPHA,
BUILT_IN_ISWBLANK,
BUILT_IN_ISWCNTRL,
BUILT_IN_ISWDIGIT,
BUILT_IN_ISWGRAPH,
BUILT_IN_ISWLOWER,
BUILT_IN_ISWPRINT,
BUILT_IN_ISWPUNCT,
BUILT_IN_ISWSPACE,
BUILT_IN_ISWUPPER,
BUILT_IN_ISWXDIGIT,
BUILT_IN_TOWLOWER,
BUILT_IN_TOWUPPER,
BUILT_IN_ABORT,
BUILT_IN_ABS,
BUILT_IN_AGGREGATE_INCOMING_ADDRESS,
BUILT_IN_ALLOCA,
BUILT_IN_APPLY,
BUILT_IN_APPLY_ARGS,
BUILT_IN_BSWAP32,
BUILT_IN_BSWAP64,
BUILT_IN_CLEAR_CACHE,
BUILT_IN_CALLOC,
BUILT_IN_CLASSIFY_TYPE,
BUILT_IN_CLZ,
BUILT_IN_CLZIMAX,
BUILT_IN_CLZL,
BUILT_IN_CLZLL,
BUILT_IN_CONSTANT_P,
BUILT_IN_CTZ,
BUILT_IN_CTZIMAX,
BUILT_IN_CTZL,
BUILT_IN_CTZLL,
BUILT_IN_CLRSB,
BUILT_IN_CLRSBIMAX,
BUILT_IN_CLRSBL,
BUILT_IN_CLRSBLL,
BUILT_IN_DCGETTEXT,
BUILT_IN_DGETTEXT,
BUILT_IN_DWARF_CFA,
BUILT_IN_DWARF_SP_COLUMN,
BUILT_IN_EH_RETURN,
BUILT_IN_EH_RETURN_DATA_REGNO,
BUILT_IN_EXECL,
BUILT_IN_EXECLP,
BUILT_IN_EXECLE,
BUILT_IN_EXECV,
BUILT_IN_EXECVP,
BUILT_IN_EXECVE,
BUILT_IN_EXIT,
BUILT_IN_EXPECT,
BUILT_IN_ASSUME_ALIGNED,
BUILT_IN_EXTEND_POINTER,
BUILT_IN_EXTRACT_RETURN_ADDR,
BUILT_IN_FFS,
BUILT_IN_FFSIMAX,
BUILT_IN_FFSL,
BUILT_IN_FFSLL,
BUILT_IN_FORK,
BUILT_IN_FRAME_ADDRESS,
BUILT_IN_FREE,
BUILT_IN_FROB_RETURN_ADDR,
BUILT_IN_GETTEXT,
BUILT_IN_IMAXABS,
BUILT_IN_INIT_DWARF_REG_SIZES,
BUILT_IN_FINITE,
BUILT_IN_FINITEF,
BUILT_IN_FINITEL,
BUILT_IN_FINITED32,
BUILT_IN_FINITED64,
BUILT_IN_FINITED128,
BUILT_IN_FPCLASSIFY,
BUILT_IN_ISFINITE,
BUILT_IN_ISINF_SIGN,
BUILT_IN_ISINF,
BUILT_IN_ISINFF,
BUILT_IN_ISINFL,
BUILT_IN_ISINFD32,
BUILT_IN_ISINFD64,
BUILT_IN_ISINFD128,
BUILT_IN_ISNAN,
BUILT_IN_ISNANF,
BUILT_IN_ISNANL,
BUILT_IN_ISNAND32,
BUILT_IN_ISNAND64,
BUILT_IN_ISNAND128,
BUILT_IN_ISNORMAL,
BUILT_IN_ISGREATER,
BUILT_IN_ISGREATEREQUAL,
BUILT_IN_ISLESS,
BUILT_IN_ISLESSEQUAL,
BUILT_IN_ISLESSGREATER,
BUILT_IN_ISUNORDERED,
BUILT_IN_LABS,
BUILT_IN_LLABS,
BUILT_IN_LONGJMP,
BUILT_IN_MALLOC,
BUILT_IN_NEXT_ARG,
BUILT_IN_PARITY,
BUILT_IN_PARITYIMAX,
BUILT_IN_PARITYL,
BUILT_IN_PARITYLL,
BUILT_IN_POPCOUNT,
BUILT_IN_POPCOUNTIMAX,
BUILT_IN_POPCOUNTL,
BUILT_IN_POPCOUNTLL,
BUILT_IN_PREFETCH,
BUILT_IN_REALLOC,
BUILT_IN_RETURN,
BUILT_IN_RETURN_ADDRESS,
BUILT_IN_SAVEREGS,
BUILT_IN_SETJMP,
BUILT_IN_STRFMON,
BUILT_IN_STRFTIME,
BUILT_IN_TRAP,
BUILT_IN_UNREACHABLE,
BUILT_IN_UNWIND_INIT,
BUILT_IN_UPDATE_SETJMP_BUF,
BUILT_IN_VA_COPY,
BUILT_IN_VA_END,
BUILT_IN_VA_START,
BUILT_IN_VA_ARG_PACK,
BUILT_IN_VA_ARG_PACK_LEN,
BUILT_IN__EXIT,
BUILT_IN__EXIT2,
BUILT_IN_INIT_TRAMPOLINE,
BUILT_IN_INIT_HEAP_TRAMPOLINE,
BUILT_IN_ADJUST_TRAMPOLINE,
BUILT_IN_NONLOCAL_GOTO,
BUILT_IN_SETJMP_SETUP,
BUILT_IN_SETJMP_DISPATCHER,
BUILT_IN_SETJMP_RECEIVER,
BUILT_IN_STACK_SAVE,
BUILT_IN_STACK_RESTORE,
BUILT_IN_ALLOCA_WITH_ALIGN,
BUILT_IN_OBJECT_SIZE,
BUILT_IN_MEMCPY_CHK,
BUILT_IN_MEMMOVE_CHK,
BUILT_IN_MEMPCPY_CHK,
BUILT_IN_MEMSET_CHK,
BUILT_IN_STPCPY_CHK,
BUILT_IN_STPNCPY_CHK,
BUILT_IN_STRCAT_CHK,
BUILT_IN_STRCPY_CHK,
BUILT_IN_STRNCAT_CHK,
BUILT_IN_STRNCPY_CHK,
BUILT_IN_SNPRINTF_CHK,
BUILT_IN_SPRINTF_CHK,
BUILT_IN_VSNPRINTF_CHK,
BUILT_IN_VSPRINTF_CHK,
BUILT_IN_FPRINTF_CHK,
BUILT_IN_PRINTF_CHK,
BUILT_IN_VFPRINTF_CHK,
BUILT_IN_VPRINTF_CHK,
BUILT_IN_PROFILE_FUNC_ENTER,
BUILT_IN_PROFILE_FUNC_EXIT,
BUILT_IN_EMUTLS_GET_ADDRESS,
BUILT_IN_EMUTLS_REGISTER_COMMON,
BUILT_IN_UNWIND_RESUME,
BUILT_IN_CXA_END_CLEANUP,
BUILT_IN_EH_POINTER,
BUILT_IN_EH_FILTER,
BUILT_IN_EH_COPY_VALUES,
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/sync-builtins.def" 1
# 31 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/sync-builtins.def"
BUILT_IN_SYNC_FETCH_AND_ADD_N,
BUILT_IN_SYNC_FETCH_AND_ADD_1,
BUILT_IN_SYNC_FETCH_AND_ADD_2,
BUILT_IN_SYNC_FETCH_AND_ADD_4,
BUILT_IN_SYNC_FETCH_AND_ADD_8,
BUILT_IN_SYNC_FETCH_AND_ADD_16,
BUILT_IN_SYNC_FETCH_AND_SUB_N,
BUILT_IN_SYNC_FETCH_AND_SUB_1,
BUILT_IN_SYNC_FETCH_AND_SUB_2,
BUILT_IN_SYNC_FETCH_AND_SUB_4,
BUILT_IN_SYNC_FETCH_AND_SUB_8,
BUILT_IN_SYNC_FETCH_AND_SUB_16,
BUILT_IN_SYNC_FETCH_AND_OR_N,
BUILT_IN_SYNC_FETCH_AND_OR_1,
BUILT_IN_SYNC_FETCH_AND_OR_2,
BUILT_IN_SYNC_FETCH_AND_OR_4,
BUILT_IN_SYNC_FETCH_AND_OR_8,
BUILT_IN_SYNC_FETCH_AND_OR_16,
BUILT_IN_SYNC_FETCH_AND_AND_N,
BUILT_IN_SYNC_FETCH_AND_AND_1,
BUILT_IN_SYNC_FETCH_AND_AND_2,
BUILT_IN_SYNC_FETCH_AND_AND_4,
BUILT_IN_SYNC_FETCH_AND_AND_8,
BUILT_IN_SYNC_FETCH_AND_AND_16,
BUILT_IN_SYNC_FETCH_AND_XOR_N,
BUILT_IN_SYNC_FETCH_AND_XOR_1,
BUILT_IN_SYNC_FETCH_AND_XOR_2,
BUILT_IN_SYNC_FETCH_AND_XOR_4,
BUILT_IN_SYNC_FETCH_AND_XOR_8,
BUILT_IN_SYNC_FETCH_AND_XOR_16,
BUILT_IN_SYNC_FETCH_AND_NAND_N,
BUILT_IN_SYNC_FETCH_AND_NAND_1,
BUILT_IN_SYNC_FETCH_AND_NAND_2,
BUILT_IN_SYNC_FETCH_AND_NAND_4,
BUILT_IN_SYNC_FETCH_AND_NAND_8,
BUILT_IN_SYNC_FETCH_AND_NAND_16,
BUILT_IN_SYNC_ADD_AND_FETCH_N,
BUILT_IN_SYNC_ADD_AND_FETCH_1,
BUILT_IN_SYNC_ADD_AND_FETCH_2,
BUILT_IN_SYNC_ADD_AND_FETCH_4,
BUILT_IN_SYNC_ADD_AND_FETCH_8,
BUILT_IN_SYNC_ADD_AND_FETCH_16,
BUILT_IN_SYNC_SUB_AND_FETCH_N,
BUILT_IN_SYNC_SUB_AND_FETCH_1,
BUILT_IN_SYNC_SUB_AND_FETCH_2,
BUILT_IN_SYNC_SUB_AND_FETCH_4,
BUILT_IN_SYNC_SUB_AND_FETCH_8,
BUILT_IN_SYNC_SUB_AND_FETCH_16,
BUILT_IN_SYNC_OR_AND_FETCH_N,
BUILT_IN_SYNC_OR_AND_FETCH_1,
BUILT_IN_SYNC_OR_AND_FETCH_2,
BUILT_IN_SYNC_OR_AND_FETCH_4,
BUILT_IN_SYNC_OR_AND_FETCH_8,
BUILT_IN_SYNC_OR_AND_FETCH_16,
BUILT_IN_SYNC_AND_AND_FETCH_N,
BUILT_IN_SYNC_AND_AND_FETCH_1,
BUILT_IN_SYNC_AND_AND_FETCH_2,
BUILT_IN_SYNC_AND_AND_FETCH_4,
BUILT_IN_SYNC_AND_AND_FETCH_8,
BUILT_IN_SYNC_AND_AND_FETCH_16,
BUILT_IN_SYNC_XOR_AND_FETCH_N,
BUILT_IN_SYNC_XOR_AND_FETCH_1,
BUILT_IN_SYNC_XOR_AND_FETCH_2,
BUILT_IN_SYNC_XOR_AND_FETCH_4,
BUILT_IN_SYNC_XOR_AND_FETCH_8,
BUILT_IN_SYNC_XOR_AND_FETCH_16,
BUILT_IN_SYNC_NAND_AND_FETCH_N,
BUILT_IN_SYNC_NAND_AND_FETCH_1,
BUILT_IN_SYNC_NAND_AND_FETCH_2,
BUILT_IN_SYNC_NAND_AND_FETCH_4,
BUILT_IN_SYNC_NAND_AND_FETCH_8,
BUILT_IN_SYNC_NAND_AND_FETCH_16,
BUILT_IN_SYNC_BOOL_COMPARE_AND_SWAP_N,
BUILT_IN_SYNC_BOOL_COMPARE_AND_SWAP_1,
BUILT_IN_SYNC_BOOL_COMPARE_AND_SWAP_2,
BUILT_IN_SYNC_BOOL_COMPARE_AND_SWAP_4,
BUILT_IN_SYNC_BOOL_COMPARE_AND_SWAP_8,
BUILT_IN_SYNC_BOOL_COMPARE_AND_SWAP_16,
BUILT_IN_SYNC_VAL_COMPARE_AND_SWAP_N,
BUILT_IN_SYNC_VAL_COMPARE_AND_SWAP_1,
BUILT_IN_SYNC_VAL_COMPARE_AND_SWAP_2,
BUILT_IN_SYNC_VAL_COMPARE_AND_SWAP_4,
BUILT_IN_SYNC_VAL_COMPARE_AND_SWAP_8,
BUILT_IN_SYNC_VAL_COMPARE_AND_SWAP_16,
BUILT_IN_SYNC_LOCK_TEST_AND_SET_N,
BUILT_IN_SYNC_LOCK_TEST_AND_SET_1,
BUILT_IN_SYNC_LOCK_TEST_AND_SET_2,
BUILT_IN_SYNC_LOCK_TEST_AND_SET_4,
BUILT_IN_SYNC_LOCK_TEST_AND_SET_8,
BUILT_IN_SYNC_LOCK_TEST_AND_SET_16,
BUILT_IN_SYNC_LOCK_RELEASE_N,
BUILT_IN_SYNC_LOCK_RELEASE_1,
BUILT_IN_SYNC_LOCK_RELEASE_2,
BUILT_IN_SYNC_LOCK_RELEASE_4,
BUILT_IN_SYNC_LOCK_RELEASE_8,
BUILT_IN_SYNC_LOCK_RELEASE_16,
BUILT_IN_SYNC_SYNCHRONIZE,
BUILT_IN_ATOMIC_TEST_AND_SET,
BUILT_IN_ATOMIC_CLEAR,
BUILT_IN_ATOMIC_EXCHANGE,
BUILT_IN_ATOMIC_EXCHANGE_N,
BUILT_IN_ATOMIC_EXCHANGE_1,
BUILT_IN_ATOMIC_EXCHANGE_2,
BUILT_IN_ATOMIC_EXCHANGE_4,
BUILT_IN_ATOMIC_EXCHANGE_8,
BUILT_IN_ATOMIC_EXCHANGE_16,
BUILT_IN_ATOMIC_LOAD,
BUILT_IN_ATOMIC_LOAD_N,
BUILT_IN_ATOMIC_LOAD_1,
BUILT_IN_ATOMIC_LOAD_2,
BUILT_IN_ATOMIC_LOAD_4,
BUILT_IN_ATOMIC_LOAD_8,
BUILT_IN_ATOMIC_LOAD_16,
BUILT_IN_ATOMIC_COMPARE_EXCHANGE,
BUILT_IN_ATOMIC_COMPARE_EXCHANGE_N,
BUILT_IN_ATOMIC_COMPARE_EXCHANGE_1,
BUILT_IN_ATOMIC_COMPARE_EXCHANGE_2,
BUILT_IN_ATOMIC_COMPARE_EXCHANGE_4,
BUILT_IN_ATOMIC_COMPARE_EXCHANGE_8,
BUILT_IN_ATOMIC_COMPARE_EXCHANGE_16,
BUILT_IN_ATOMIC_STORE,
BUILT_IN_ATOMIC_STORE_N,
BUILT_IN_ATOMIC_STORE_1,
BUILT_IN_ATOMIC_STORE_2,
BUILT_IN_ATOMIC_STORE_4,
BUILT_IN_ATOMIC_STORE_8,
BUILT_IN_ATOMIC_STORE_16,
BUILT_IN_ATOMIC_ADD_FETCH_N,
BUILT_IN_ATOMIC_ADD_FETCH_1,
BUILT_IN_ATOMIC_ADD_FETCH_2,
BUILT_IN_ATOMIC_ADD_FETCH_4,
BUILT_IN_ATOMIC_ADD_FETCH_8,
BUILT_IN_ATOMIC_ADD_FETCH_16,
BUILT_IN_ATOMIC_SUB_FETCH_N,
BUILT_IN_ATOMIC_SUB_FETCH_1,
BUILT_IN_ATOMIC_SUB_FETCH_2,
BUILT_IN_ATOMIC_SUB_FETCH_4,
BUILT_IN_ATOMIC_SUB_FETCH_8,
BUILT_IN_ATOMIC_SUB_FETCH_16,
BUILT_IN_ATOMIC_AND_FETCH_N,
BUILT_IN_ATOMIC_AND_FETCH_1,
BUILT_IN_ATOMIC_AND_FETCH_2,
BUILT_IN_ATOMIC_AND_FETCH_4,
BUILT_IN_ATOMIC_AND_FETCH_8,
BUILT_IN_ATOMIC_AND_FETCH_16,
BUILT_IN_ATOMIC_NAND_FETCH_N,
BUILT_IN_ATOMIC_NAND_FETCH_1,
BUILT_IN_ATOMIC_NAND_FETCH_2,
BUILT_IN_ATOMIC_NAND_FETCH_4,
BUILT_IN_ATOMIC_NAND_FETCH_8,
BUILT_IN_ATOMIC_NAND_FETCH_16,
BUILT_IN_ATOMIC_XOR_FETCH_N,
BUILT_IN_ATOMIC_XOR_FETCH_1,
BUILT_IN_ATOMIC_XOR_FETCH_2,
BUILT_IN_ATOMIC_XOR_FETCH_4,
BUILT_IN_ATOMIC_XOR_FETCH_8,
BUILT_IN_ATOMIC_XOR_FETCH_16,
BUILT_IN_ATOMIC_OR_FETCH_N,
BUILT_IN_ATOMIC_OR_FETCH_1,
BUILT_IN_ATOMIC_OR_FETCH_2,
BUILT_IN_ATOMIC_OR_FETCH_4,
BUILT_IN_ATOMIC_OR_FETCH_8,
BUILT_IN_ATOMIC_OR_FETCH_16,
BUILT_IN_ATOMIC_FETCH_ADD_N,
BUILT_IN_ATOMIC_FETCH_ADD_1,
BUILT_IN_ATOMIC_FETCH_ADD_2,
BUILT_IN_ATOMIC_FETCH_ADD_4,
BUILT_IN_ATOMIC_FETCH_ADD_8,
BUILT_IN_ATOMIC_FETCH_ADD_16,
BUILT_IN_ATOMIC_FETCH_SUB_N,
BUILT_IN_ATOMIC_FETCH_SUB_1,
BUILT_IN_ATOMIC_FETCH_SUB_2,
BUILT_IN_ATOMIC_FETCH_SUB_4,
BUILT_IN_ATOMIC_FETCH_SUB_8,
BUILT_IN_ATOMIC_FETCH_SUB_16,
BUILT_IN_ATOMIC_FETCH_AND_N,
BUILT_IN_ATOMIC_FETCH_AND_1,
BUILT_IN_ATOMIC_FETCH_AND_2,
BUILT_IN_ATOMIC_FETCH_AND_4,
BUILT_IN_ATOMIC_FETCH_AND_8,
BUILT_IN_ATOMIC_FETCH_AND_16,
BUILT_IN_ATOMIC_FETCH_NAND_N,
BUILT_IN_ATOMIC_FETCH_NAND_1,
BUILT_IN_ATOMIC_FETCH_NAND_2,
BUILT_IN_ATOMIC_FETCH_NAND_4,
BUILT_IN_ATOMIC_FETCH_NAND_8,
BUILT_IN_ATOMIC_FETCH_NAND_16,
BUILT_IN_ATOMIC_FETCH_XOR_N,
BUILT_IN_ATOMIC_FETCH_XOR_1,
BUILT_IN_ATOMIC_FETCH_XOR_2,
BUILT_IN_ATOMIC_FETCH_XOR_4,
BUILT_IN_ATOMIC_FETCH_XOR_8,
BUILT_IN_ATOMIC_FETCH_XOR_16,
BUILT_IN_ATOMIC_FETCH_OR_N,
BUILT_IN_ATOMIC_FETCH_OR_1,
BUILT_IN_ATOMIC_FETCH_OR_2,
BUILT_IN_ATOMIC_FETCH_OR_4,
BUILT_IN_ATOMIC_FETCH_OR_8,
BUILT_IN_ATOMIC_FETCH_OR_16,
BUILT_IN_ATOMIC_ALWAYS_LOCK_FREE,
BUILT_IN_ATOMIC_IS_LOCK_FREE,
BUILT_IN_ATOMIC_THREAD_FENCE,
BUILT_IN_ATOMIC_SIGNAL_FENCE,
# 805 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/builtins.def" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/omp-builtins.def" 1
# 27 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/omp-builtins.def"
BUILT_IN_OMP_GET_THREAD_NUM,
BUILT_IN_OMP_GET_NUM_THREADS,
BUILT_IN_GOMP_ATOMIC_START,
BUILT_IN_GOMP_ATOMIC_END,
BUILT_IN_GOMP_BARRIER,
BUILT_IN_GOMP_TASKWAIT,
BUILT_IN_GOMP_TASKYIELD,
BUILT_IN_GOMP_CRITICAL_START,
BUILT_IN_GOMP_CRITICAL_END,
BUILT_IN_GOMP_CRITICAL_NAME_START,
BUILT_IN_GOMP_CRITICAL_NAME_END,
BUILT_IN_GOMP_LOOP_STATIC_START,
BUILT_IN_GOMP_LOOP_DYNAMIC_START,
BUILT_IN_GOMP_LOOP_GUIDED_START,
BUILT_IN_GOMP_LOOP_RUNTIME_START,
BUILT_IN_GOMP_LOOP_ORDERED_STATIC_START,
BUILT_IN_GOMP_LOOP_ORDERED_DYNAMIC_START,
BUILT_IN_GOMP_LOOP_ORDERED_GUIDED_START,
BUILT_IN_GOMP_LOOP_ORDERED_RUNTIME_START,
BUILT_IN_GOMP_LOOP_STATIC_NEXT,
BUILT_IN_GOMP_LOOP_DYNAMIC_NEXT,
BUILT_IN_GOMP_LOOP_GUIDED_NEXT,
BUILT_IN_GOMP_LOOP_RUNTIME_NEXT,
BUILT_IN_GOMP_LOOP_ORDERED_STATIC_NEXT,
BUILT_IN_GOMP_LOOP_ORDERED_DYNAMIC_NEXT,
BUILT_IN_GOMP_LOOP_ORDERED_GUIDED_NEXT,
BUILT_IN_GOMP_LOOP_ORDERED_RUNTIME_NEXT,
BUILT_IN_GOMP_LOOP_ULL_STATIC_START,
BUILT_IN_GOMP_LOOP_ULL_DYNAMIC_START,
BUILT_IN_GOMP_LOOP_ULL_GUIDED_START,
BUILT_IN_GOMP_LOOP_ULL_RUNTIME_START,
BUILT_IN_GOMP_LOOP_ULL_ORDERED_STATIC_START,
BUILT_IN_GOMP_LOOP_ULL_ORDERED_DYNAMIC_START,
BUILT_IN_GOMP_LOOP_ULL_ORDERED_GUIDED_START,
BUILT_IN_GOMP_LOOP_ULL_ORDERED_RUNTIME_START,
BUILT_IN_GOMP_LOOP_ULL_STATIC_NEXT,
BUILT_IN_GOMP_LOOP_ULL_DYNAMIC_NEXT,
BUILT_IN_GOMP_LOOP_ULL_GUIDED_NEXT,
BUILT_IN_GOMP_LOOP_ULL_RUNTIME_NEXT,
BUILT_IN_GOMP_LOOP_ULL_ORDERED_STATIC_NEXT,
BUILT_IN_GOMP_LOOP_ULL_ORDERED_DYNAMIC_NEXT,
BUILT_IN_GOMP_LOOP_ULL_ORDERED_GUIDED_NEXT,
BUILT_IN_GOMP_LOOP_ULL_ORDERED_RUNTIME_NEXT,
BUILT_IN_GOMP_PARALLEL_LOOP_STATIC_START,
BUILT_IN_GOMP_PARALLEL_LOOP_DYNAMIC_START,
BUILT_IN_GOMP_PARALLEL_LOOP_GUIDED_START,
BUILT_IN_GOMP_PARALLEL_LOOP_RUNTIME_START,
BUILT_IN_GOMP_LOOP_END,
BUILT_IN_GOMP_LOOP_END_NOWAIT,
BUILT_IN_GOMP_ORDERED_START,
BUILT_IN_GOMP_ORDERED_END,
BUILT_IN_GOMP_PARALLEL_START,
BUILT_IN_GOMP_PARALLEL_END,
BUILT_IN_GOMP_TASK,
BUILT_IN_GOMP_SECTIONS_START,
BUILT_IN_GOMP_SECTIONS_NEXT,
BUILT_IN_GOMP_PARALLEL_SECTIONS_START,
BUILT_IN_GOMP_SECTIONS_END,
BUILT_IN_GOMP_SECTIONS_END_NOWAIT,
BUILT_IN_GOMP_SINGLE_START,
BUILT_IN_GOMP_SINGLE_COPY_START,
BUILT_IN_GOMP_SINGLE_COPY_END,
# 808 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/builtins.def" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gtm-builtins.def" 1
BUILT_IN_TM_START,
BUILT_IN_TM_COMMIT,
BUILT_IN_TM_COMMIT_EH,
BUILT_IN_TM_ABORT,
BUILT_IN_TM_IRREVOCABLE,
BUILT_IN_TM_MEMCPY,
BUILT_IN_TM_MEMMOVE,
BUILT_IN_TM_MEMSET,
BUILT_IN_TM_GETTMCLONE_IRR,
BUILT_IN_TM_GETTMCLONE_SAFE,
BUILT_IN_TM_MALLOC,
BUILT_IN_TM_CALLOC,
BUILT_IN_TM_FREE,
BUILT_IN_TM_LOG_1,
BUILT_IN_TM_LOG_2,
BUILT_IN_TM_LOG_4,
BUILT_IN_TM_LOG_8,
BUILT_IN_TM_LOG_FLOAT,
BUILT_IN_TM_LOG_DOUBLE,
BUILT_IN_TM_LOG_LDOUBLE,
BUILT_IN_TM_LOG,
BUILT_IN_TM_LOG_M64,
BUILT_IN_TM_LOG_M128,
BUILT_IN_TM_LOG_M256,
# 63 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gtm-builtins.def"
BUILT_IN_TM_STORE_1,
BUILT_IN_TM_STORE_WAR_1,
BUILT_IN_TM_STORE_WAW_1,
BUILT_IN_TM_STORE_2,
BUILT_IN_TM_STORE_WAR_2,
BUILT_IN_TM_STORE_WAW_2,
BUILT_IN_TM_STORE_4,
BUILT_IN_TM_STORE_WAR_4,
BUILT_IN_TM_STORE_WAW_4,
BUILT_IN_TM_STORE_8,
BUILT_IN_TM_STORE_WAR_8,
BUILT_IN_TM_STORE_WAW_8,
BUILT_IN_TM_STORE_FLOAT,
BUILT_IN_TM_STORE_WAR_FLOAT,
BUILT_IN_TM_STORE_WAW_FLOAT,
BUILT_IN_TM_STORE_DOUBLE,
BUILT_IN_TM_STORE_WAR_DOUBLE,
BUILT_IN_TM_STORE_WAW_DOUBLE,
BUILT_IN_TM_STORE_M64,
BUILT_IN_TM_STORE_WAR_M64,
BUILT_IN_TM_STORE_WAW_M64,
BUILT_IN_TM_STORE_M128,
BUILT_IN_TM_STORE_WAR_M128,
BUILT_IN_TM_STORE_WAW_M128,
BUILT_IN_TM_STORE_M256,
BUILT_IN_TM_STORE_WAR_M256,
BUILT_IN_TM_STORE_WAW_M256,
BUILT_IN_TM_STORE_LDOUBLE,
BUILT_IN_TM_STORE_WAR_LDOUBLE,
BUILT_IN_TM_STORE_WAW_LDOUBLE,
# 129 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gtm-builtins.def"
BUILT_IN_TM_LOAD_1,
BUILT_IN_TM_LOAD_RAR_1,
BUILT_IN_TM_LOAD_RAW_1,
BUILT_IN_TM_LOAD_RFW_1,
BUILT_IN_TM_LOAD_2,
BUILT_IN_TM_LOAD_RAR_2,
BUILT_IN_TM_LOAD_RAW_2,
BUILT_IN_TM_LOAD_RFW_2,
BUILT_IN_TM_LOAD_4,
BUILT_IN_TM_LOAD_RAR_4,
BUILT_IN_TM_LOAD_RAW_4,
BUILT_IN_TM_LOAD_RFW_4,
BUILT_IN_TM_LOAD_8,
BUILT_IN_TM_LOAD_RAR_8,
BUILT_IN_TM_LOAD_RAW_8,
BUILT_IN_TM_LOAD_RFW_8,
BUILT_IN_TM_LOAD_FLOAT,
BUILT_IN_TM_LOAD_RAR_FLOAT,
BUILT_IN_TM_LOAD_RAW_FLOAT,
BUILT_IN_TM_LOAD_RFW_FLOAT,
BUILT_IN_TM_LOAD_DOUBLE,
BUILT_IN_TM_LOAD_RAR_DOUBLE,
BUILT_IN_TM_LOAD_RAW_DOUBLE,
BUILT_IN_TM_LOAD_RFW_DOUBLE,
BUILT_IN_TM_LOAD_M64,
BUILT_IN_TM_LOAD_RAR_M64,
BUILT_IN_TM_LOAD_RAW_M64,
BUILT_IN_TM_LOAD_RFW_M64,
BUILT_IN_TM_LOAD_M128,
BUILT_IN_TM_LOAD_RAR_M128,
BUILT_IN_TM_LOAD_RAW_M128,
BUILT_IN_TM_LOAD_RFW_M128,
BUILT_IN_TM_LOAD_M256,
BUILT_IN_TM_LOAD_RAR_M256,
BUILT_IN_TM_LOAD_RAW_M256,
BUILT_IN_TM_LOAD_RFW_M256,
BUILT_IN_TM_LOAD_LDOUBLE,
BUILT_IN_TM_LOAD_RAR_LDOUBLE,
BUILT_IN_TM_LOAD_RAW_LDOUBLE,
BUILT_IN_TM_LOAD_RFW_LDOUBLE,
# 810 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/builtins.def" 2
# 294 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h" 2
  BUILT_IN_COMPLEX_MUL_MIN,
  BUILT_IN_COMPLEX_MUL_MAX
    = BUILT_IN_COMPLEX_MUL_MIN
      + MAX_MODE_COMPLEX_FLOAT
      - MIN_MODE_COMPLEX_FLOAT,
  BUILT_IN_COMPLEX_DIV_MIN,
  BUILT_IN_COMPLEX_DIV_MAX
    = BUILT_IN_COMPLEX_DIV_MIN
      + MAX_MODE_COMPLEX_FLOAT
      - MIN_MODE_COMPLEX_FLOAT,
  END_BUILTINS
};
extern const char * built_in_names[(int) END_BUILTINS];
# 342 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern unsigned const char omp_clause_num_ops[];
extern const char * const omp_clause_code_name[];
enum omp_clause_code
{
  OMP_CLAUSE_ERROR = 0,
  OMP_CLAUSE_PRIVATE,
  OMP_CLAUSE_SHARED,
  OMP_CLAUSE_FIRSTPRIVATE,
  OMP_CLAUSE_LASTPRIVATE,
# 372 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
  OMP_CLAUSE_REDUCTION,
  OMP_CLAUSE_COPYIN,
  OMP_CLAUSE_COPYPRIVATE,
  OMP_CLAUSE_IF,
  OMP_CLAUSE_NUM_THREADS,
  OMP_CLAUSE_SCHEDULE,
  OMP_CLAUSE_NOWAIT,
  OMP_CLAUSE_ORDERED,
  OMP_CLAUSE_DEFAULT,
  OMP_CLAUSE_COLLAPSE,
  OMP_CLAUSE_UNTIED,
  OMP_CLAUSE_FINAL,
  OMP_CLAUSE_MERGEABLE
};
# 433 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_base {
  __extension__ enum tree_code code : 16;
  unsigned side_effects_flag : 1;
  unsigned constant_flag : 1;
  unsigned addressable_flag : 1;
  unsigned volatile_flag : 1;
  unsigned readonly_flag : 1;
  unsigned unsigned_flag : 1;
  unsigned asm_written_flag: 1;
  unsigned nowarning_flag : 1;
  unsigned used_flag : 1;
  unsigned nothrow_flag : 1;
  unsigned static_flag : 1;
  unsigned public_flag : 1;
  unsigned private_flag : 1;
  unsigned protected_flag : 1;
  unsigned deprecated_flag : 1;
  unsigned saturating_flag : 1;
  unsigned default_def_flag : 1;
  unsigned lang_flag_0 : 1;
  unsigned lang_flag_1 : 1;
  unsigned lang_flag_2 : 1;
  unsigned lang_flag_3 : 1;
  unsigned lang_flag_4 : 1;
  unsigned lang_flag_5 : 1;
  unsigned lang_flag_6 : 1;
  unsigned visited : 1;
  unsigned packed_flag : 1;
  unsigned user_align : 1;
  unsigned nameless_flag : 1;
  unsigned spare : 12;
  unsigned address_space : 8;
};
struct tree_typed {
  struct tree_base base;
  tree type;
};
struct tree_common {
  struct tree_typed typed;
  tree chain;
};
# 712 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
enum tree_node_structure_enum {
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/treestruct.def" 1
# 33 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/treestruct.def"
TS_BASE,
TS_TYPED,
TS_COMMON,
TS_INT_CST,
TS_REAL_CST,
TS_FIXED_CST,
TS_VECTOR,
TS_STRING,
TS_COMPLEX,
TS_IDENTIFIER,
TS_DECL_MINIMAL,
TS_DECL_COMMON,
TS_DECL_WRTL,
TS_DECL_NON_COMMON,
TS_DECL_WITH_VIS,
TS_FIELD_DECL,
TS_VAR_DECL,
TS_PARM_DECL,
TS_LABEL_DECL,
TS_RESULT_DECL,
TS_CONST_DECL,
TS_TYPE_DECL,
TS_FUNCTION_DECL,
TS_TRANSLATION_UNIT_DECL,
TS_TYPE_COMMON,
TS_TYPE_WITH_LANG_SPECIFIC,
TS_TYPE_NON_COMMON,
TS_LIST,
TS_VEC,
TS_EXP,
TS_SSA_NAME,
TS_BLOCK,
TS_BINFO,
TS_STATEMENT_LIST,
TS_CONSTRUCTOR,
TS_OMP_CLAUSE,
TS_OPTIMIZATION,
TS_TARGET_OPTION,
# 714 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h" 2
  LAST_TS_ENUM
};
# 1012 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree-check.h" 1
# 1013 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h" 2
# 1484 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_int_cst {
  struct tree_typed typed;
  double_int int_cst;
};
struct real_value;
struct tree_real_cst {
  struct tree_typed typed;
  struct real_value * real_cst_ptr;
};
struct fixed_value;
struct tree_fixed_cst {
  struct tree_typed typed;
  struct fixed_value * fixed_cst_ptr;
};
struct tree_string {
  struct tree_typed typed;
  int length;
  char str[1];
};
struct tree_complex {
  struct tree_typed typed;
  tree real;
  tree imag;
};
struct tree_vector {
  struct tree_typed typed;
  tree elements;
};
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/symtab.h" 1
# 22 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/symtab.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/obstack.h" 1
# 157 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/obstack.h"
struct _obstack_chunk
{
  char *limit;
  struct _obstack_chunk *prev;
  char contents[4];
};
struct obstack
{
  long chunk_size;
  struct _obstack_chunk *chunk;
  char *object_base;
  char *next_free;
  char *chunk_limit;
  int temp;
  int alignment_mask;
  struct _obstack_chunk *(*chunkfun) (void *, long);
  void (*freefun) (void *, struct _obstack_chunk *);
  void *extra_arg;
  unsigned use_extra_arg:1;
  unsigned maybe_empty_object:1;
  unsigned alloc_failed:1;
};
extern void _obstack_newchunk (struct obstack *, int);
extern void _obstack_free (struct obstack *, void *);
extern int _obstack_begin (struct obstack *, int, int,
       void *(*) (long), void (*) (void *));
extern int _obstack_begin_1 (struct obstack *, int, int,
        void *(*) (void *, long),
        void (*) (void *, void *), void *);
extern int _obstack_memory_used (struct obstack *);
void obstack_init (struct obstack *obstack);
void * obstack_alloc (struct obstack *obstack, int size);
void * obstack_copy (struct obstack *obstack, void *address, int size);
void * obstack_copy0 (struct obstack *obstack, void *address, int size);
void obstack_free (struct obstack *obstack, void *block);
void obstack_blank (struct obstack *obstack, int size);
void obstack_grow (struct obstack *obstack, void *data, int size);
void obstack_grow0 (struct obstack *obstack, void *data, int size);
void obstack_1grow (struct obstack *obstack, int data_char);
void obstack_ptr_grow (struct obstack *obstack, void *data);
void obstack_int_grow (struct obstack *obstack, int data);
void * obstack_finish (struct obstack *obstack);
int obstack_object_size (struct obstack *obstack);
int obstack_room (struct obstack *obstack);
void obstack_make_room (struct obstack *obstack, int size);
void obstack_1grow_fast (struct obstack *obstack, int data_char);
void obstack_ptr_grow_fast (struct obstack *obstack, void *data);
void obstack_int_grow_fast (struct obstack *obstack, int data);
void obstack_blank_fast (struct obstack *obstack, int size);
void * obstack_base (struct obstack *obstack);
void * obstack_next_free (struct obstack *obstack);
int obstack_alignment_mask (struct obstack *obstack);
int obstack_chunk_size (struct obstack *obstack);
int obstack_memory_used (struct obstack *obstack);
extern void (*obstack_alloc_failed_handler) (void);
extern int obstack_exit_failure;
# 23 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/symtab.h" 2
typedef struct ht_identifier ht_identifier;
typedef struct ht_identifier *ht_identifier_ptr;
struct ht_identifier {
  const unsigned char *str;
  unsigned int len;
  unsigned int hash_value;
};
typedef struct ht hash_table;
typedef struct ht_identifier *hashnode;
enum ht_lookup_option {HT_NO_INSERT = 0, HT_ALLOC};
struct ht
{
  struct obstack stack;
  hashnode *entries;
  hashnode (*alloc_node) (hash_table *);
  void * (*alloc_subobject) (size_t);
  unsigned int nslots;
  unsigned int nelements;
  struct cpp_reader *pfile;
  unsigned int searches;
  unsigned int collisions;
  unsigned char entries_owned;
};
extern hash_table *ht_create (unsigned int order);
extern void ht_destroy (hash_table *);
extern hashnode ht_lookup (hash_table *, const unsigned char *,
      size_t, enum ht_lookup_option);
extern hashnode ht_lookup_with_hash (hash_table *, const unsigned char *,
                                     size_t, unsigned int,
                                     enum ht_lookup_option);
typedef int (*ht_cb) (struct cpp_reader *, hashnode, const void *);
extern void ht_forall (hash_table *, ht_cb, const void *);
extern void ht_purge (hash_table *, ht_cb, const void *);
extern void ht_load (hash_table *ht, hashnode *entries,
       unsigned int nslots, unsigned int nelements, unsigned char own);
extern void ht_dump_statistics (hash_table *);
# 1545 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h" 2
# 1562 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_identifier {
  struct tree_common common;
  struct ht_identifier id;
};
struct tree_list {
  struct tree_common common;
  tree purpose;
  tree value;
};
# 1584 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_vec {
  struct tree_common common;
  int length;
  tree a[1];
};
# 1643 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
typedef struct constructor_elt_d {
  tree index;
  tree value;
} constructor_elt;
typedef struct VEC_constructor_elt_base { struct vec_prefix prefix; constructor_elt vec[1]; } VEC_constructor_elt_base; typedef struct VEC_constructor_elt_none { VEC_constructor_elt_base base; } VEC_constructor_elt_none; static __inline__ unsigned VEC_constructor_elt_base_length (const VEC_constructor_elt_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static __inline__ constructor_elt *VEC_constructor_elt_base_last (VEC_constructor_elt_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return &vec_->vec[vec_->prefix.num - 1]; } static __inline__ constructor_elt *VEC_constructor_elt_base_index (VEC_constructor_elt_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return &vec_->vec[ix_]; } static __inline__ int VEC_constructor_elt_base_iterate (VEC_constructor_elt_base *vec_, unsigned ix_, constructor_elt **ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = &vec_->vec[ix_]; return 1; } else { *ptr = 0; return 0; } } static __inline__ size_t VEC_constructor_elt_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_constructor_elt_base, vec) + alloc_ * sizeof(constructor_elt); } static __inline__ void VEC_constructor_elt_base_embedded_init (VEC_constructor_elt_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static __inline__ int VEC_constructor_elt_base_space (VEC_constructor_elt_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static __inline__ void VEC_constructor_elt_base_splice (VEC_constructor_elt_base *dst_, VEC_constructor_elt_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (constructor_elt)); dst_->prefix.num += len_; } } static __inline__ constructor_elt *VEC_constructor_elt_base_quick_push (VEC_constructor_elt_base *vec_, const constructor_elt *obj_ ) { constructor_elt *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; if (obj_) *slot_ = *obj_; return slot_; } static __inline__ void VEC_constructor_elt_base_pop (VEC_constructor_elt_base *vec_ ) { (void)(vec_->prefix.num); --vec_->prefix.num; } static __inline__ void VEC_constructor_elt_base_truncate (VEC_constructor_elt_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static __inline__ constructor_elt *VEC_constructor_elt_base_replace (VEC_constructor_elt_base *vec_, unsigned ix_, const constructor_elt *obj_ ) { constructor_elt *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; if (obj_) *slot_ = *obj_; return slot_; } static __inline__ constructor_elt *VEC_constructor_elt_base_quick_insert (VEC_constructor_elt_base *vec_, unsigned ix_, const constructor_elt *obj_ ) { constructor_elt *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (constructor_elt)); if (obj_) *slot_ = *obj_; return slot_; } static __inline__ void VEC_constructor_elt_base_ordered_remove (VEC_constructor_elt_base *vec_, unsigned ix_ ) { constructor_elt *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (constructor_elt)); } static __inline__ void VEC_constructor_elt_base_unordered_remove (VEC_constructor_elt_base *vec_, unsigned ix_ ) { (void)(ix_ < vec_->prefix.num); vec_->vec[ix_] = vec_->vec[--vec_->prefix.num]; } static __inline__ void VEC_constructor_elt_base_block_remove (VEC_constructor_elt_base *vec_, unsigned ix_, unsigned len_ ) { constructor_elt *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (constructor_elt)); } static __inline__ constructor_elt *VEC_constructor_elt_base_address (VEC_constructor_elt_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_constructor_elt_base_lower_bound (VEC_constructor_elt_base *vec_, const constructor_elt *obj_, unsigned char (*lessthan_)(const constructor_elt *, const constructor_elt *) ) { unsigned int len_ = VEC_constructor_elt_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { constructor_elt *middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_constructor_elt_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_constructor_elt_gc { VEC_constructor_elt_base base; } VEC_constructor_elt_gc; static __inline__ VEC_constructor_elt_gc *VEC_constructor_elt_gc_alloc (int alloc_ ) { return (VEC_constructor_elt_gc *) vec_gc_o_reserve_exact (((void *)0), alloc_, __builtin_offsetof (VEC_constructor_elt_gc, base.vec), sizeof (constructor_elt) ); } static __inline__ VEC_constructor_elt_gc *VEC_constructor_elt_gc_copy (VEC_constructor_elt_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_constructor_elt_gc *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_constructor_elt_gc *)(vec_gc_o_reserve_exact (((void *)0), len_, __builtin_offsetof (VEC_constructor_elt_gc, base.vec), sizeof (constructor_elt) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (constructor_elt) * len_); } return new_vec_; } static __inline__ void VEC_constructor_elt_gc_free (VEC_constructor_elt_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = ((void *)0); } static __inline__ int VEC_constructor_elt_gc_reserve (VEC_constructor_elt_gc **vec_, int alloc_ ) { int extend = !VEC_constructor_elt_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_constructor_elt_gc *) vec_gc_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_constructor_elt_gc, base.vec), sizeof (constructor_elt) ); return extend; } static __inline__ int VEC_constructor_elt_gc_reserve_exact (VEC_constructor_elt_gc **vec_, int alloc_ ) { int extend = !VEC_constructor_elt_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_constructor_elt_gc *) vec_gc_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_constructor_elt_gc, base.vec), sizeof (constructor_elt) ); return extend; } static __inline__ void VEC_constructor_elt_gc_safe_grow (VEC_constructor_elt_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_constructor_elt_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_constructor_elt_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_constructor_elt_gc_safe_grow_cleared (VEC_constructor_elt_gc **vec_, int size_ ) { int oldsize = VEC_constructor_elt_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_constructor_elt_gc_safe_grow (vec_, size_ ); memset (&(VEC_constructor_elt_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (constructor_elt) * (size_ - oldsize)); } static __inline__ void VEC_constructor_elt_gc_safe_splice (VEC_constructor_elt_gc **dst_, VEC_constructor_elt_base *src_ ) { if (src_) { VEC_constructor_elt_gc_reserve_exact (dst_, src_->prefix.num ); VEC_constructor_elt_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ constructor_elt *VEC_constructor_elt_gc_safe_push (VEC_constructor_elt_gc **vec_, const constructor_elt *obj_ ) { VEC_constructor_elt_gc_reserve (vec_, 1 ); return VEC_constructor_elt_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ constructor_elt *VEC_constructor_elt_gc_safe_insert (VEC_constructor_elt_gc **vec_, unsigned ix_, const constructor_elt *obj_ ) { VEC_constructor_elt_gc_reserve (vec_, 1 ); return VEC_constructor_elt_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
struct tree_constructor {
  struct tree_typed typed;
  VEC_constructor_elt_gc *elts;
};
# 1696 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern void protected_set_expr_location (tree, location_t);
# 1928 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
enum omp_clause_schedule_kind
{
  OMP_CLAUSE_SCHEDULE_STATIC,
  OMP_CLAUSE_SCHEDULE_DYNAMIC,
  OMP_CLAUSE_SCHEDULE_GUIDED,
  OMP_CLAUSE_SCHEDULE_AUTO,
  OMP_CLAUSE_SCHEDULE_RUNTIME
};
enum omp_clause_default_kind
{
  OMP_CLAUSE_DEFAULT_UNSPECIFIED,
  OMP_CLAUSE_DEFAULT_SHARED,
  OMP_CLAUSE_DEFAULT_NONE,
  OMP_CLAUSE_DEFAULT_PRIVATE,
  OMP_CLAUSE_DEFAULT_FIRSTPRIVATE
};
struct tree_exp {
  struct tree_typed typed;
  location_t locus;
  tree block;
  tree
    operands[1];
};
# 1999 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct ptr_info_def;
typedef struct ssa_use_operand_d {
  struct ssa_use_operand_d* prev;
  struct ssa_use_operand_d* next;
  union { gimple stmt; tree ssa_name; } loc;
  tree * use;
} ssa_use_operand_t;
struct tree_ssa_name {
  struct tree_typed typed;
  tree var;
  gimple def_stmt;
  unsigned int version;
  struct ptr_info_def *ptr_info;
  struct ssa_use_operand_d imm_uses;
};
struct phi_arg_d {
  struct ssa_use_operand_d imm_use;
  tree def;
  location_t locus;
};
# 2058 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_omp_clause {
  struct tree_common common;
  location_t locus;
  enum omp_clause_code code;
  union omp_clause_subcode {
    enum omp_clause_default_kind default_kind;
    enum omp_clause_schedule_kind schedule_kind;
    enum tree_code reduction_code;
  } subcode;
  gimple_seq gimple_reduction_init;
  gimple_seq gimple_reduction_merge;
  tree ops[1];
};
# 2127 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_block {
  struct tree_base base;
  tree chain;
  unsigned abstract_flag : 1;
  unsigned block_num : 31;
  location_t locus;
  tree vars;
  VEC_tree_gc *nonlocalized_vars;
  tree subblocks;
  tree supercontext;
  tree abstract_origin;
  tree fragment_origin;
  tree fragment_chain;
};
# 2169 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern enum machine_mode vector_type_mode (const_tree);
# 2279 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
enum cv_qualifier
  {
    TYPE_UNQUALIFIED = 0x0,
    TYPE_QUAL_CONST = 0x1,
    TYPE_QUAL_VOLATILE = 0x2,
    TYPE_QUAL_RESTRICT = 0x4
  };
# 2402 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct die_struct;
struct tree_type_common {
  struct tree_common common;
  tree size;
  tree size_unit;
  tree attributes;
  unsigned int uid;
  unsigned int precision : 10;
  unsigned no_force_blk_flag : 1;
  unsigned needs_constructing_flag : 1;
  unsigned transparent_aggr_flag : 1;
  unsigned restrict_flag : 1;
  unsigned contains_placeholder_bits : 2;
  __extension__ enum machine_mode mode : 8;
  unsigned string_flag : 1;
  unsigned lang_flag_0 : 1;
  unsigned lang_flag_1 : 1;
  unsigned lang_flag_2 : 1;
  unsigned lang_flag_3 : 1;
  unsigned lang_flag_4 : 1;
  unsigned lang_flag_5 : 1;
  unsigned lang_flag_6 : 1;
  unsigned int align;
  alias_set_type alias_set;
  tree pointer_to;
  tree reference_to;
  union tree_type_symtab {
    int address;
    const char * pointer;
    struct die_struct * die;
  } symtab;
  tree name;
  tree next_variant;
  tree main_variant;
  tree context;
  tree canonical;
};
struct tree_type_with_lang_specific {
  struct tree_type_common common;
  struct lang_type *lang_specific;
};
# 2496 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_type_non_common {
  struct tree_type_with_lang_specific with_lang_specific;
  tree values;
  tree minval;
  tree maxval;
  tree binfo;
};
# 2607 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_binfo {
  struct tree_common common;
  tree offset;
  tree vtable;
  tree virtuals;
  tree vptr_field;
  VEC_tree_gc *base_accesses;
  tree inheritance;
  tree vtt_subvtt;
  tree vtt_vptr;
  VEC_tree_none base_binfos;
};
# 2651 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct function;
# 2706 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_decl_minimal {
  struct tree_common common;
  location_t locus;
  unsigned int uid;
  tree name;
  tree context;
};
# 2874 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_decl_common {
  struct tree_decl_minimal common;
  tree size;
  __extension__ enum machine_mode mode : 8;
  unsigned nonlocal_flag : 1;
  unsigned virtual_flag : 1;
  unsigned ignored_flag : 1;
  unsigned abstract_flag : 1;
  unsigned artificial_flag : 1;
  unsigned preserve_flag: 1;
  unsigned debug_expr_is_from : 1;
  unsigned lang_flag_0 : 1;
  unsigned lang_flag_1 : 1;
  unsigned lang_flag_2 : 1;
  unsigned lang_flag_3 : 1;
  unsigned lang_flag_4 : 1;
  unsigned lang_flag_5 : 1;
  unsigned lang_flag_6 : 1;
  unsigned lang_flag_7 : 1;
  unsigned lang_flag_8 : 1;
  unsigned decl_flag_0 : 1;
  unsigned decl_flag_1 : 1;
  unsigned decl_flag_2 : 1;
  unsigned gimple_reg_flag : 1;
  unsigned decl_by_reference_flag : 1;
  unsigned decl_restricted_flag : 1;
  unsigned decl_read_flag : 1;
  unsigned decl_nonshareable_flag : 1;
  unsigned int off_align : 8;
  unsigned int align;
  unsigned int pt_uid;
  tree size_unit;
  tree initial;
  tree attributes;
  tree abstract_origin;
  struct lang_decl *lang_specific;
};
extern tree decl_value_expr_lookup (tree);
extern void decl_value_expr_insert (tree, tree);
# 3001 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_decl_with_rtl {
  struct tree_decl_common common;
  rtx rtl;
};
# 3074 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_field_decl {
  struct tree_decl_common common;
  tree offset;
  tree bit_field_type;
  tree qualifier;
  tree bit_offset;
  tree fcontext;
};
# 3100 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_label_decl {
  struct tree_decl_with_rtl common;
  int label_decl_uid;
  int eh_landing_pad_nr;
};
struct var_ann_d;
struct tree_result_decl {
  struct tree_decl_with_rtl common;
  struct var_ann_d *ann;
};
struct tree_const_decl {
  struct tree_decl_common common;
};
# 3125 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_parm_decl {
  struct tree_decl_with_rtl common;
  rtx incoming_rtl;
  struct var_ann_d *ann;
};
# 3264 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_decl_with_vis {
 struct tree_decl_with_rtl common;
 tree assembler_name;
 tree section_name;
 tree comdat_group;
 unsigned defer_output : 1;
 unsigned hard_register : 1;
 unsigned thread_local : 1;
 unsigned common_flag : 1;
 unsigned in_text_section : 1;
 unsigned in_constant_pool : 1;
 unsigned dllimport_flag : 1;
 unsigned weak_flag : 1;
 unsigned seen_in_bind_expr : 1;
 unsigned comdat_flag : 1;
 __extension__ enum symbol_visibility visibility : 2;
 unsigned visibility_specified : 1;
 __extension__ enum tls_model tls_model : 3;
 unsigned init_priority_p : 1;
 unsigned shadowed_for_var_p : 1;
 unsigned implicit_section_name_p : 1;
};
extern tree decl_debug_expr_lookup (tree);
extern void decl_debug_expr_insert (tree, tree);
# 3309 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
typedef unsigned short priority_type;
extern priority_type decl_init_priority_lookup (tree);
extern priority_type decl_fini_priority_lookup (tree);
extern void decl_init_priority_insert (tree, priority_type);
extern void decl_fini_priority_insert (tree, priority_type);
# 3348 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_var_decl {
  struct tree_decl_with_vis common;
  struct var_ann_d *ann;
};
# 3370 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct
 tree_decl_non_common {
  struct tree_decl_with_vis common;
  tree saved_tree;
  tree arguments;
  tree result;
  tree vindex;
};
# 3500 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern VEC_tree_gc **decl_debug_args_lookup (tree);
extern VEC_tree_gc **decl_debug_args_insert (tree);
# 3542 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_function_decl {
  struct tree_decl_non_common common;
  struct function *f;
  tree personality;
  tree function_specific_target;
  tree function_specific_optimization;
  __extension__ enum built_in_function function_code : 11;
  __extension__ enum built_in_class built_in_class : 2;
  unsigned static_ctor_flag : 1;
  unsigned static_dtor_flag : 1;
  unsigned uninlinable : 1;
  unsigned possibly_inlined : 1;
  unsigned novops_flag : 1;
  unsigned returns_twice_flag : 1;
  unsigned malloc_flag : 1;
  unsigned operator_new_flag : 1;
  unsigned declared_inline_flag : 1;
  unsigned regdecl_flag : 1;
  unsigned no_inline_warning_flag : 1;
  unsigned no_instrument_function_entry_exit : 1;
  unsigned no_limit_stack : 1;
  unsigned disregard_inline_limits : 1;
  unsigned pure_flag : 1;
  unsigned looping_const_or_pure_flag : 1;
  unsigned has_debug_args_flag : 1;
  unsigned tm_clone_flag : 1;
};
struct tree_translation_unit_decl {
  struct tree_decl_common common;
  const char * language;
};
extern VEC_tree_gc *all_translation_units;
# 3617 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_type_decl {
  struct tree_decl_non_common common;
};
# 3633 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct tree_statement_list_node
 {
  struct tree_statement_list_node *prev;
  struct tree_statement_list_node *next;
  tree stmt;
};
struct tree_statement_list
 {
  struct tree_typed typed;
  struct tree_statement_list_node *head;
  struct tree_statement_list_node *tail;
};
struct tree_optimization_option {
  struct tree_common common;
  struct cl_optimization opts;
};
extern tree build_optimization_node (void);
struct tree_target_option {
  struct tree_common common;
  struct cl_target_option opts;
};
extern tree build_target_option_node (void);
union tree_node {
  struct tree_base base;
  struct tree_typed typed;
  struct tree_common common;
  struct tree_int_cst int_cst;
  struct tree_real_cst real_cst;
  struct tree_fixed_cst fixed_cst;
  struct tree_vector vector;
  struct tree_string string;
  struct tree_complex complex;
  struct tree_identifier identifier;
  struct tree_decl_minimal decl_minimal;
  struct tree_decl_common decl_common;
  struct tree_decl_with_rtl decl_with_rtl;
  struct tree_decl_non_common decl_non_common;
  struct tree_parm_decl parm_decl;
  struct tree_decl_with_vis decl_with_vis;
  struct tree_var_decl var_decl;
  struct tree_field_decl field_decl;
  struct tree_label_decl label_decl;
  struct tree_result_decl result_decl;
  struct tree_const_decl const_decl;
  struct tree_type_decl type_decl;
  struct tree_function_decl function_decl;
  struct tree_translation_unit_decl
    translation_unit_decl;
  struct tree_type_common type_common;
  struct tree_type_with_lang_specific
    type_with_lang_specific;
  struct tree_type_non_common
    type_non_common;
  struct tree_list list;
  struct tree_vec vec;
  struct tree_exp exp;
  struct tree_ssa_name ssa_name;
  struct tree_block block;
  struct tree_binfo binfo;
  struct tree_statement_list stmt_list;
  struct tree_constructor constructor;
  struct tree_omp_clause omp_clause;
  struct tree_optimization_option optimization;
  struct tree_target_option target_option;
};
enum tree_index
{
  TI_ERROR_MARK,
  TI_INTQI_TYPE,
  TI_INTHI_TYPE,
  TI_INTSI_TYPE,
  TI_INTDI_TYPE,
  TI_INTTI_TYPE,
  TI_UINTQI_TYPE,
  TI_UINTHI_TYPE,
  TI_UINTSI_TYPE,
  TI_UINTDI_TYPE,
  TI_UINTTI_TYPE,
  TI_UINT32_TYPE,
  TI_UINT64_TYPE,
  TI_INTEGER_ZERO,
  TI_INTEGER_ONE,
  TI_INTEGER_THREE,
  TI_INTEGER_MINUS_ONE,
  TI_NULL_POINTER,
  TI_SIZE_ZERO,
  TI_SIZE_ONE,
  TI_BITSIZE_ZERO,
  TI_BITSIZE_ONE,
  TI_BITSIZE_UNIT,
  TI_PUBLIC,
  TI_PROTECTED,
  TI_PRIVATE,
  TI_BOOLEAN_FALSE,
  TI_BOOLEAN_TRUE,
  TI_COMPLEX_INTEGER_TYPE,
  TI_COMPLEX_FLOAT_TYPE,
  TI_COMPLEX_DOUBLE_TYPE,
  TI_COMPLEX_LONG_DOUBLE_TYPE,
  TI_FLOAT_TYPE,
  TI_DOUBLE_TYPE,
  TI_LONG_DOUBLE_TYPE,
  TI_FLOAT_PTR_TYPE,
  TI_DOUBLE_PTR_TYPE,
  TI_LONG_DOUBLE_PTR_TYPE,
  TI_INTEGER_PTR_TYPE,
  TI_VOID_TYPE,
  TI_PTR_TYPE,
  TI_CONST_PTR_TYPE,
  TI_SIZE_TYPE,
  TI_PID_TYPE,
  TI_PTRDIFF_TYPE,
  TI_VA_LIST_TYPE,
  TI_VA_LIST_GPR_COUNTER_FIELD,
  TI_VA_LIST_FPR_COUNTER_FIELD,
  TI_BOOLEAN_TYPE,
  TI_FILEPTR_TYPE,
  TI_DFLOAT32_TYPE,
  TI_DFLOAT64_TYPE,
  TI_DFLOAT128_TYPE,
  TI_DFLOAT32_PTR_TYPE,
  TI_DFLOAT64_PTR_TYPE,
  TI_DFLOAT128_PTR_TYPE,
  TI_VOID_LIST_NODE,
  TI_MAIN_IDENTIFIER,
  TI_SAT_SFRACT_TYPE,
  TI_SAT_FRACT_TYPE,
  TI_SAT_LFRACT_TYPE,
  TI_SAT_LLFRACT_TYPE,
  TI_SAT_USFRACT_TYPE,
  TI_SAT_UFRACT_TYPE,
  TI_SAT_ULFRACT_TYPE,
  TI_SAT_ULLFRACT_TYPE,
  TI_SFRACT_TYPE,
  TI_FRACT_TYPE,
  TI_LFRACT_TYPE,
  TI_LLFRACT_TYPE,
  TI_USFRACT_TYPE,
  TI_UFRACT_TYPE,
  TI_ULFRACT_TYPE,
  TI_ULLFRACT_TYPE,
  TI_SAT_SACCUM_TYPE,
  TI_SAT_ACCUM_TYPE,
  TI_SAT_LACCUM_TYPE,
  TI_SAT_LLACCUM_TYPE,
  TI_SAT_USACCUM_TYPE,
  TI_SAT_UACCUM_TYPE,
  TI_SAT_ULACCUM_TYPE,
  TI_SAT_ULLACCUM_TYPE,
  TI_SACCUM_TYPE,
  TI_ACCUM_TYPE,
  TI_LACCUM_TYPE,
  TI_LLACCUM_TYPE,
  TI_USACCUM_TYPE,
  TI_UACCUM_TYPE,
  TI_ULACCUM_TYPE,
  TI_ULLACCUM_TYPE,
  TI_QQ_TYPE,
  TI_HQ_TYPE,
  TI_SQ_TYPE,
  TI_DQ_TYPE,
  TI_TQ_TYPE,
  TI_UQQ_TYPE,
  TI_UHQ_TYPE,
  TI_USQ_TYPE,
  TI_UDQ_TYPE,
  TI_UTQ_TYPE,
  TI_SAT_QQ_TYPE,
  TI_SAT_HQ_TYPE,
  TI_SAT_SQ_TYPE,
  TI_SAT_DQ_TYPE,
  TI_SAT_TQ_TYPE,
  TI_SAT_UQQ_TYPE,
  TI_SAT_UHQ_TYPE,
  TI_SAT_USQ_TYPE,
  TI_SAT_UDQ_TYPE,
  TI_SAT_UTQ_TYPE,
  TI_HA_TYPE,
  TI_SA_TYPE,
  TI_DA_TYPE,
  TI_TA_TYPE,
  TI_UHA_TYPE,
  TI_USA_TYPE,
  TI_UDA_TYPE,
  TI_UTA_TYPE,
  TI_SAT_HA_TYPE,
  TI_SAT_SA_TYPE,
  TI_SAT_DA_TYPE,
  TI_SAT_TA_TYPE,
  TI_SAT_UHA_TYPE,
  TI_SAT_USA_TYPE,
  TI_SAT_UDA_TYPE,
  TI_SAT_UTA_TYPE,
  TI_OPTIMIZATION_DEFAULT,
  TI_OPTIMIZATION_CURRENT,
  TI_TARGET_OPTION_DEFAULT,
  TI_TARGET_OPTION_CURRENT,
  TI_CURRENT_TARGET_PRAGMA,
  TI_CURRENT_OPTIMIZE_PRAGMA,
  TI_MAX
};
extern tree global_trees[TI_MAX];
# 4068 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
enum integer_type_kind
{
  itk_char,
  itk_signed_char,
  itk_unsigned_char,
  itk_short,
  itk_unsigned_short,
  itk_int,
  itk_unsigned_int,
  itk_long,
  itk_unsigned_long,
  itk_long_long,
  itk_unsigned_long_long,
  itk_int128,
  itk_unsigned_int128,
  itk_none
};
typedef enum integer_type_kind integer_type_kind;
extern tree integer_types[itk_none];
# 4127 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
enum ptrmemfunc_vbit_where_t
{
  ptrmemfunc_vbit_in_pfn,
  ptrmemfunc_vbit_in_delta
};
# 4141 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern tree decl_assembler_name (tree);
extern unsigned char decl_assembler_name_equal (tree decl, const_tree asmname);
extern hashval_t decl_assembler_name_hash (const_tree asmname);
extern size_t tree_size (const_tree);
extern size_t tree_code_size (enum tree_code);
extern int allocate_decl_uid (void);
extern tree make_node_stat (enum tree_code );
extern tree copy_node_stat (tree );
extern tree copy_list (tree);
extern tree build_case_label (tree, tree, tree);
extern tree make_tree_binfo_stat (unsigned );
extern tree make_tree_vec_stat (int );
extern tree get_identifier (const char *);
# 4203 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern tree get_identifier_with_length (const char *, size_t);
extern tree maybe_get_identifier (const char *);
extern tree build_nt (enum tree_code, ...);
extern tree build_nt_call_vec (tree, VEC_tree_gc *);
extern tree build0_stat (enum tree_code, tree );
extern tree build1_stat (enum tree_code, tree, tree );
extern tree build2_stat (enum tree_code, tree, tree, tree );
extern tree build3_stat (enum tree_code, tree, tree, tree, tree );
extern tree build4_stat (enum tree_code, tree, tree, tree, tree,
    tree );
extern tree build5_stat (enum tree_code, tree, tree, tree, tree, tree,
    tree );
extern tree build6_stat (enum tree_code, tree, tree, tree, tree, tree,
    tree, tree );
static __inline__ tree
build1_stat_loc (location_t loc, enum tree_code code, tree type,
   tree arg1 )
{
  tree t = build1_stat (code, type, arg1 );
  if (((t) && ((tree_code_type[(int) (((enum tree_code) (t)->base.code))]) >= tcc_reference && (tree_code_type[(int) (((enum tree_code) (t)->base.code))]) <= tcc_expression)))
    ((t))->exp.locus = (loc);
  return t;
}
static __inline__ tree
build2_stat_loc (location_t loc, enum tree_code code, tree type, tree arg0,
   tree arg1 )
{
  tree t = build2_stat (code, type, arg0, arg1 );
  if (((t) && ((tree_code_type[(int) (((enum tree_code) (t)->base.code))]) >= tcc_reference && (tree_code_type[(int) (((enum tree_code) (t)->base.code))]) <= tcc_expression)))
    ((t))->exp.locus = (loc);
  return t;
}
static __inline__ tree
build3_stat_loc (location_t loc, enum tree_code code, tree type, tree arg0,
   tree arg1, tree arg2 )
{
  tree t = build3_stat (code, type, arg0, arg1, arg2 );
  if (((t) && ((tree_code_type[(int) (((enum tree_code) (t)->base.code))]) >= tcc_reference && (tree_code_type[(int) (((enum tree_code) (t)->base.code))]) <= tcc_expression)))
    ((t))->exp.locus = (loc);
  return t;
}
static __inline__ tree
build4_stat_loc (location_t loc, enum tree_code code, tree type, tree arg0,
   tree arg1, tree arg2, tree arg3 )
{
  tree t = build4_stat (code, type, arg0, arg1, arg2, arg3 );
  if (((t) && ((tree_code_type[(int) (((enum tree_code) (t)->base.code))]) >= tcc_reference && (tree_code_type[(int) (((enum tree_code) (t)->base.code))]) <= tcc_expression)))
    ((t))->exp.locus = (loc);
  return t;
}
static __inline__ tree
build5_stat_loc (location_t loc, enum tree_code code, tree type, tree arg0,
   tree arg1, tree arg2, tree arg3, tree arg4 )
{
  tree t = build5_stat (code, type, arg0, arg1, arg2, arg3,
   arg4 );
  if (((t) && ((tree_code_type[(int) (((enum tree_code) (t)->base.code))]) >= tcc_reference && (tree_code_type[(int) (((enum tree_code) (t)->base.code))]) <= tcc_expression)))
    ((t))->exp.locus = (loc);
  return t;
}
static __inline__ tree
build6_stat_loc (location_t loc, enum tree_code code, tree type, tree arg0,
   tree arg1, tree arg2, tree arg3, tree arg4,
   tree arg5 )
{
  tree t = build6_stat (code, type, arg0, arg1, arg2, arg3, arg4,
   arg5 );
  if (((t) && ((tree_code_type[(int) (((enum tree_code) (t)->base.code))]) >= tcc_reference && (tree_code_type[(int) (((enum tree_code) (t)->base.code))]) <= tcc_expression)))
    ((t))->exp.locus = (loc);
  return t;
}
extern tree build_var_debug_value_stat (tree, tree );
static __inline__ double_int
tree_to_double_int (const_tree cst)
{
  return ((cst)->int_cst.int_cst);
}
extern tree double_int_to_tree (tree, double_int);
extern unsigned char double_int_fits_to_tree_p (const_tree, double_int);
extern tree force_fit_type_double (tree, double_int, int, unsigned char);
static __inline__ tree
build_int_cstu (tree type, unsigned long long cst)
{
  return double_int_to_tree (type, uhwi_to_double_int (cst));
}
extern tree build_int_cst (tree, long long);
extern tree build_int_cst_type (tree, long long);
extern tree build_int_cst_wide (tree, unsigned long long, long long);
extern tree build_vector (tree, tree);
extern tree build_vector_from_ctor (tree, VEC_constructor_elt_gc *);
extern tree build_vector_from_val (tree, tree);
extern tree build_constructor (tree, VEC_constructor_elt_gc *);
extern tree build_constructor_single (tree, tree, tree);
extern tree build_constructor_from_list (tree, tree);
extern tree build_real_from_int_cst (tree, const_tree);
extern tree build_complex (tree, tree, tree);
extern tree build_one_cst (tree);
extern tree build_zero_cst (tree);
extern tree build_string (int, const char *);
extern tree build_tree_list_stat (tree, tree );
extern tree build_tree_list_vec_stat (const VEC_tree_gc * );
extern tree build_decl_stat (location_t, enum tree_code,
        tree, tree );
extern tree build_fn_decl (const char *, tree);
extern tree build_translation_unit_decl (tree);
extern tree build_block (tree, tree, tree, tree);
extern tree build_empty_stmt (location_t);
extern tree build_omp_clause (location_t, enum omp_clause_code);
extern tree build_vl_exp_stat (enum tree_code, int );
extern tree build_call_nary (tree, tree, int, ...);
extern tree build_call_valist (tree, tree, int, va_list);
extern tree build_call_array_loc (location_t, tree, tree, int, const tree *);
extern tree build_call_vec (tree, tree, VEC_tree_gc *);
extern tree make_signed_type (int);
extern tree make_unsigned_type (int);
extern tree signed_or_unsigned_type_for (int, tree);
extern tree signed_type_for (tree);
extern tree unsigned_type_for (tree);
extern void initialize_sizetypes (void);
extern void fixup_unsigned_type (tree);
extern tree build_pointer_type_for_mode (tree, enum machine_mode, unsigned char);
extern tree build_pointer_type (tree);
extern tree build_reference_type_for_mode (tree, enum machine_mode, unsigned char);
extern tree build_reference_type (tree);
extern tree build_vector_type_for_mode (tree, enum machine_mode);
extern tree build_vector_type (tree innertype, int nunits);
extern tree build_opaque_vector_type (tree innertype, int nunits);
extern tree build_type_no_quals (tree);
extern tree build_index_type (tree);
extern tree build_array_type (tree, tree);
extern tree build_nonshared_array_type (tree, tree);
extern tree build_array_type_nelts (tree, unsigned long long);
extern tree build_function_type (tree, tree);
extern tree build_function_type_list (tree, ...);
extern tree build_function_decl_skip_args (tree, bitmap, unsigned char);
extern tree build_varargs_function_type_list (tree, ...);
extern tree build_function_type_array (tree, int, tree *);
extern tree build_varargs_function_type_array (tree, int, tree *);
extern tree build_method_type_directly (tree, tree, tree);
extern tree build_method_type (tree, tree);
extern tree build_offset_type (tree, tree);
extern tree build_complex_type (tree);
extern tree array_type_nelts (const_tree);
extern unsigned char in_array_bounds_p (tree);
extern unsigned char range_in_array_bounds_p (tree);
extern tree value_member (tree, tree);
extern tree purpose_member (const_tree, tree);
extern unsigned char vec_member (const_tree, VEC_tree_gc *);
extern tree chain_index (int, tree);
extern int attribute_list_equal (const_tree, const_tree);
extern int attribute_list_contained (const_tree, const_tree);
extern int tree_int_cst_equal (const_tree, const_tree);
extern int tree_int_cst_lt (const_tree, const_tree);
extern int tree_int_cst_compare (const_tree, const_tree);
extern int host_integerp (const_tree, int)
  __attribute__ ((__pure__))
  ;
extern long long tree_low_cst (const_tree, int);
extern __inline__ __attribute__ ((__gnu_inline__)) long long
tree_low_cst (const_tree t, int pos)
{
  ((void)(!(host_integerp (t, pos)) ? fancy_abort ("/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h", 4431, __FUNCTION__), 0 : 0));
  return (((t)->int_cst.int_cst).low);
}
extern long long size_low_cst (const_tree);
extern int tree_int_cst_sgn (const_tree);
extern int tree_int_cst_sign_bit (const_tree);
extern unsigned int tree_int_cst_min_precision (tree, unsigned char);
extern unsigned char tree_expr_nonnegative_p (tree);
extern unsigned char tree_expr_nonnegative_warnv_p (tree, unsigned char *);
extern unsigned char may_negate_without_overflow_p (const_tree);
extern tree strip_array_types (tree);
extern tree excess_precision_type (tree);
extern tree make_fract_type (int, int, int);
extern tree make_accum_type (int, int, int);
# 4480 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern tree make_tree (tree, rtx);
extern tree build_type_attribute_variant (tree, tree);
extern tree build_decl_attribute_variant (tree, tree);
extern tree build_type_attribute_qual_variant (tree, tree, int);
extern int comp_type_attributes (const_tree, const_tree);
struct attribute_spec
{
  const char *const name;
  const int min_length;
  const int max_length;
  const unsigned char decl_required;
  const unsigned char type_required;
  const unsigned char function_type_required;
# 4538 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
  tree (*const handler) (tree *node, tree name, tree args,
     int flags, unsigned char *no_add_attrs);
  const unsigned char affects_type_identity;
};
enum attribute_flags
{
  ATTR_FLAG_DECL_NEXT = 1,
  ATTR_FLAG_FUNCTION_NEXT = 2,
  ATTR_FLAG_ARRAY_NEXT = 4,
  ATTR_FLAG_TYPE_IN_PLACE = 8,
  ATTR_FLAG_BUILT_IN = 16
};
extern tree merge_decl_attributes (tree, tree);
extern tree merge_type_attributes (tree, tree);
extern tree private_lookup_attribute (const char *, size_t, tree);
# 4586 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
static __inline__ tree
lookup_attribute (const char *attr_name, tree list)
{
  ((void)(0 && (attr_name[0] != '_')));
  if (list == (tree) ((void *)0))
    return (tree) ((void *)0);
  else
    return private_lookup_attribute (attr_name, strlen (attr_name), list);
}
extern unsigned char private_is_attribute_p (const char *, size_t, const_tree);
static __inline__ unsigned char
is_attribute_p (const char *attr_name, const_tree ident)
{
  ((void)(0 && (attr_name[0] != '_')));
  return private_is_attribute_p (attr_name, strlen (attr_name), ident);
}
extern tree remove_attribute (const char *, tree);
extern tree merge_attributes (tree, tree);
# 4641 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern unsigned char check_qualified_type (const_tree, const_tree, int);
extern tree get_qualified_type (tree, int);
extern tree build_qualified_type (tree, int);
extern tree build_aligned_type (tree, unsigned int);
# 4670 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern tree build_distinct_type_copy (tree);
extern tree build_variant_type_copy (tree);
extern void finish_builtin_struct (tree, const char *,
        tree, tree);
extern void layout_type (tree);
# 4692 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
typedef struct record_layout_info_s
{
  tree t;
  tree offset;
  unsigned int offset_align;
  tree bitpos;
  unsigned int record_align;
  unsigned int unpacked_align;
  tree prev_field;
  VEC_tree_gc *pending_statics;
  int remaining_in_alignment;
  int packed_maybe_necessary;
} *record_layout_info;
extern record_layout_info start_record_layout (tree);
extern tree bit_from_pos (tree, tree);
extern tree byte_from_pos (tree, tree);
extern void pos_from_bit (tree *, tree *, unsigned int, tree);
extern void normalize_offset (tree *, tree *, unsigned int);
extern tree rli_size_unit_so_far (record_layout_info);
extern tree rli_size_so_far (record_layout_info);
extern void normalize_rli (record_layout_info);
extern void place_field (record_layout_info, tree);
extern void compute_record_mode (tree);
extern void finish_record_layout (record_layout_info, int);
extern tree type_hash_canon (unsigned int, tree);
# 4747 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern void layout_decl (tree, unsigned);
extern void relayout_decl (tree);
extern enum machine_mode mode_for_size_tree (const_tree, enum mode_class, int);
extern tree non_lvalue_loc (location_t, tree);
extern tree convert (tree, tree);
extern unsigned int expr_align (const_tree);
extern tree expr_first (tree);
extern tree expr_last (tree);
extern tree size_in_bytes (const_tree);
extern long long int_size_in_bytes (const_tree);
extern long long max_int_size_in_bytes (const_tree);
extern tree tree_expr_size (const_tree);
extern tree bit_position (const_tree);
extern long long int_bit_position (const_tree);
extern tree byte_position (const_tree);
extern long long int_byte_position (const_tree);
enum size_type_kind
{
  SIZETYPE,
  SSIZETYPE,
  BITSIZETYPE,
  SBITSIZETYPE,
  TYPE_KIND_LAST};
extern tree sizetype_tab[(int) TYPE_KIND_LAST];
extern tree size_int_kind (long long, enum size_type_kind);
extern tree size_binop_loc (location_t, enum tree_code, tree, tree);
extern tree size_diffop_loc (location_t, tree, tree);
extern tree round_up_loc (location_t, tree, int);
extern tree round_down_loc (location_t, tree, int);
extern void finalize_size_functions (void);
# 4824 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern unsigned int maximum_field_alignment;
extern tree chainon (tree, tree);
extern tree tree_cons_stat (tree, tree, tree );
extern tree tree_last (tree);
extern tree nreverse (tree);
extern int list_length (const_tree);
extern int fields_length (const_tree);
extern tree first_field (const_tree);
extern unsigned char initializer_zerop (const_tree);
extern VEC_tree_gc *ctor_to_vec (tree);
extern unsigned char categorize_ctor_elements (const_tree, long long *,
          long long *, unsigned char *);
extern unsigned char complete_ctor_at_level_p (const_tree, long long, const_tree);
extern int integer_zerop (const_tree);
extern int integer_onep (const_tree);
extern int integer_all_onesp (const_tree);
extern int integer_pow2p (const_tree);
extern int integer_nonzerop (const_tree);
extern unsigned char cst_and_fits_in_hwi (const_tree);
extern tree num_ending_zeros (const_tree);
extern int fixed_zerop (const_tree);
extern tree staticp (tree);
extern tree save_expr (tree);
extern tree skip_simple_arithmetic (tree);
enum tree_node_structure_enum tree_node_structure (const_tree);
extern unsigned char contains_placeholder_p (const_tree);
# 4938 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern unsigned char type_contains_placeholder_p (tree);
# 4947 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern void find_placeholder_in_expr (tree, VEC_tree_heap **);
# 4965 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern tree substitute_in_expr (tree, tree, tree);
# 4976 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern tree substitute_placeholder_in_expr (tree, tree);
# 4991 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern tree variable_size (tree);
extern tree stabilize_reference (tree);
extern tree stabilize_reference_1 (tree);
extern tree get_unwidened (tree, tree);
extern tree get_narrower (tree, int *);
static __inline__ unsigned char
handled_component_p (const_tree t)
{
  switch (((enum tree_code) (t)->base.code))
    {
    case BIT_FIELD_REF:
    case COMPONENT_REF:
    case ARRAY_REF:
    case ARRAY_RANGE_REF:
    case VIEW_CONVERT_EXPR:
    case REALPART_EXPR:
    case IMAGPART_EXPR:
      return 1;
    default:
      return 0;
    }
}
extern tree get_inner_reference (tree, long long *, long long *,
     tree *, enum machine_mode *, int *, int *,
     unsigned char);
extern unsigned char contains_packed_reference (const_tree exp);
extern tree array_ref_element_size (tree);
extern tree array_ref_low_bound (tree);
extern tree array_ref_up_bound (tree);
extern tree component_ref_field_offset (tree);
extern tree get_containing_scope (const_tree);
extern tree decl_function_context (const_tree);
extern tree decl_type_context (const_tree);
extern int real_zerop (const_tree);
extern int pedantic_lvalues;
extern tree current_function_decl;
extern const char * current_function_func_begin_label;
typedef struct {
  tree next;
} function_args_iterator;
static __inline__ void
function_args_iter_init (function_args_iterator *i, const_tree fntype)
{
  i->next = ((fntype)->type_non_common.values);
}
static __inline__ tree *
function_args_iter_cond_ptr (function_args_iterator *i)
{
  return (i->next) ? &((i->next)->list.value) : ((void *)0);
}
static __inline__ tree
function_args_iter_cond (function_args_iterator *i)
{
  return (i->next) ? ((i->next)->list.value) : (tree) ((void *)0);
}
static __inline__ void
function_args_iter_next (function_args_iterator *i)
{
  ((void)(!(i->next != (tree) ((void *)0)) ? fancy_abort ("/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h", 5139, __FUNCTION__), 0 : 0));
  i->next = ((i->next)->common.chain);
}
static __inline__ unsigned char
inlined_function_outer_scope_p (const_tree block)
{
 return ((block)->block.locus) != ((source_location) 0);
}
# 5170 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern unsigned crc32_string (unsigned, const char *);
extern unsigned crc32_byte (unsigned, char);
extern void clean_symbol_name (char *);
extern tree get_file_function_name (const char *);
extern tree get_callee_fndecl (const_tree);
extern int type_num_arguments (const_tree);
extern unsigned char associative_tree_code (enum tree_code);
extern unsigned char commutative_tree_code (enum tree_code);
extern unsigned char commutative_ternary_tree_code (enum tree_code);
extern tree upper_bound_in_type (tree, tree);
extern tree lower_bound_in_type (tree, tree);
extern int operand_equal_for_phi_arg_p (const_tree, const_tree);
extern tree create_artificial_label (location_t);
extern const char *get_name (tree);
extern unsigned char stdarg_p (const_tree);
extern unsigned char prototype_p (tree);
extern unsigned char is_typedef_decl (tree x);
extern unsigned char typedef_variant_p (tree);
extern unsigned char auto_var_in_fn_p (const_tree, const_tree);
extern tree build_low_bits_mask (tree, unsigned);
extern tree tree_strip_nop_conversions (tree);
extern tree tree_strip_sign_nop_conversions (tree);
extern const_tree strip_invariant_refs (const_tree);
extern tree lhd_gcc_personality (void);
extern void assign_assembler_name_if_neeeded (tree);
extern void warn_deprecated_use (tree, tree);
extern void change_decl_assembler_name (tree, tree);
extern tree unshare_expr (tree);
extern void expand_expr_stmt (tree);
extern int warn_if_unused_value (const_tree, location_t);
extern void expand_label (tree);
extern void expand_goto (tree);
extern rtx expand_stack_save (void);
extern void expand_stack_restore (tree);
extern void expand_return (tree);
extern void using_eh_for_cleanups (void);
static __inline__ int
struct_ptr_eq (const void *a, const void *b)
{
  const void * const * x = (const void * const *) a;
  const void * const * y = (const void * const *) b;
  return *x == *y;
}
static __inline__ hashval_t
struct_ptr_hash (const void *a)
{
  const void * const * x = (const void * const *) a;
  return (intptr_t)*x >> 4;
}
extern int folding_initializer;
extern int native_encode_expr (const_tree, unsigned char *, int);
extern tree native_interpret_expr (tree, const unsigned char *, int);
extern tree fold (tree);
extern tree fold_unary_loc (location_t, enum tree_code, tree, tree);
extern tree fold_unary_ignore_overflow_loc (location_t, enum tree_code, tree, tree);
extern tree fold_binary_loc (location_t, enum tree_code, tree, tree, tree);
extern tree fold_ternary_loc (location_t, enum tree_code, tree, tree, tree, tree);
extern tree fold_build1_stat_loc (location_t, enum tree_code, tree,
      tree );
extern tree fold_build2_stat_loc (location_t, enum tree_code, tree, tree,
      tree );
extern tree fold_build3_stat_loc (location_t, enum tree_code, tree, tree, tree,
      tree );
extern tree fold_build1_initializer_loc (location_t, enum tree_code, tree, tree);
extern tree fold_build2_initializer_loc (location_t, enum tree_code, tree, tree, tree);
extern tree fold_build3_initializer_loc (location_t, enum tree_code, tree, tree, tree, tree);
extern tree fold_build_call_array_loc (location_t, tree, tree, int, tree *);
extern tree fold_build_call_array_initializer_loc (location_t, tree, tree, int, tree *);
extern unsigned char fold_convertible_p (const_tree, const_tree);
extern tree fold_convert_loc (location_t, tree, tree);
extern tree fold_single_bit_test (location_t, enum tree_code, tree, tree, tree);
extern tree fold_ignored_result (tree);
extern tree fold_abs_const (tree, tree);
extern tree fold_indirect_ref_1 (location_t, tree, tree);
extern void fold_defer_overflow_warnings (void);
extern void fold_undefer_overflow_warnings (unsigned char, const_gimple, int);
extern void fold_undefer_and_ignore_overflow_warnings (void);
extern unsigned char fold_deferring_overflow_warnings_p (void);
extern tree fold_fma (location_t, tree, tree, tree, tree);
enum operand_equal_flag
{
  OEP_ONLY_CONST = 1,
  OEP_PURE_SAME = 2,
  OEP_CONSTANT_ADDRESS_OF = 4
};
extern int operand_equal_p (const_tree, const_tree, unsigned int);
extern int multiple_of_p (tree, const_tree, const_tree);
extern tree omit_one_operand_loc (location_t, tree, tree, tree);
extern tree omit_two_operands_loc (location_t, tree, tree, tree, tree);
extern tree invert_truthvalue_loc (location_t, tree);
extern tree fold_truth_not_expr (location_t, tree);
extern tree fold_unary_to_constant (enum tree_code, tree, tree);
extern tree fold_binary_to_constant (enum tree_code, tree, tree, tree);
extern tree fold_read_from_constant_string (tree);
extern tree int_const_binop (enum tree_code, const_tree, const_tree);
extern tree build_fold_addr_expr_loc (location_t, tree);
extern tree build_fold_addr_expr_with_type_loc (location_t, tree, tree);
extern tree fold_build_cleanup_point_expr (tree type, tree expr);
extern tree fold_strip_sign_ops (tree);
extern tree build_fold_indirect_ref_loc (location_t, tree);
extern tree fold_indirect_ref_loc (location_t, tree);
extern tree build_simple_mem_ref_loc (location_t, tree);
extern double_int mem_ref_offset (const_tree);
extern tree reference_alias_ptr_type (const_tree);
extern tree build_invariant_address (tree, tree, long long);
extern tree constant_boolean_node (unsigned char, tree);
extern tree div_if_zero_remainder (enum tree_code, const_tree, const_tree);
extern unsigned char tree_swap_operands_p (const_tree, const_tree, unsigned char);
extern enum tree_code swap_tree_comparison (enum tree_code);
extern unsigned char ptr_difference_const (tree, tree, long long *);
extern enum tree_code invert_tree_comparison (enum tree_code, unsigned char);
extern unsigned char tree_expr_nonzero_p (tree);
extern unsigned char tree_unary_nonzero_warnv_p (enum tree_code, tree, tree, unsigned char *);
extern unsigned char tree_binary_nonzero_warnv_p (enum tree_code, tree, tree, tree op1,
                                         unsigned char *);
extern unsigned char tree_single_nonzero_warnv_p (tree, unsigned char *);
extern unsigned char tree_unary_nonnegative_warnv_p (enum tree_code, tree, tree, unsigned char *);
extern unsigned char tree_binary_nonnegative_warnv_p (enum tree_code, tree, tree, tree,
                                             unsigned char *);
extern unsigned char tree_single_nonnegative_warnv_p (tree t, unsigned char *strict_overflow_p);
extern unsigned char tree_invalid_nonnegative_warnv_p (tree t, unsigned char *strict_overflow_p);
extern unsigned char tree_call_nonnegative_warnv_p (tree, tree, tree, tree, unsigned char *);
extern unsigned char tree_expr_nonzero_warnv_p (tree, unsigned char *);
extern unsigned char fold_real_zero_addition_p (const_tree, const_tree, int);
extern tree combine_comparisons (location_t, enum tree_code, enum tree_code,
     enum tree_code, tree, tree, tree);
extern void debug_fold_checksum (const_tree);
static __inline__ unsigned char
truth_value_p (enum tree_code code)
{
  return (tree_code_type[(int) (code)] == tcc_comparison
   || code == TRUTH_AND_EXPR || code == TRUTH_ANDIF_EXPR
   || code == TRUTH_OR_EXPR || code == TRUTH_ORIF_EXPR
   || code == TRUTH_XOR_EXPR || code == TRUTH_NOT_EXPR);
}
static __inline__ unsigned char
ptrofftype_p (tree type)
{
  return ((((enum tree_code) (type)->base.code) == ENUMERAL_TYPE || ((enum tree_code) (type)->base.code) == BOOLEAN_TYPE || ((enum tree_code) (type)->base.code) == INTEGER_TYPE)
   && ((type)->type_common.precision) == ((sizetype_tab[(int) SIZETYPE])->type_common.precision)
   && ((type)->base.unsigned_flag) == ((sizetype_tab[(int) SIZETYPE])->base.unsigned_flag));
}
static __inline__ tree
convert_to_ptrofftype_loc (location_t loc, tree off)
{
  return fold_convert_loc (loc, sizetype_tab[(int) SIZETYPE], off);
}
static __inline__ tree
fold_build_pointer_plus_loc (location_t loc, tree ptr, tree off)
{
  return fold_build2_stat_loc (loc, POINTER_PLUS_EXPR, ((ptr)->typed.type), ptr, fold_convert_loc (loc, sizetype_tab[(int) SIZETYPE], off) );
}
static __inline__ tree
fold_build_pointer_plus_hwi_loc (location_t loc, tree ptr, long long off)
{
  return fold_build2_stat_loc (loc, POINTER_PLUS_EXPR, ((ptr)->typed.type), ptr, size_int_kind (off, SIZETYPE) );
}
extern unsigned char avoid_folding_inline_builtin (tree);
extern tree fold_call_expr (location_t, tree, unsigned char);
extern tree fold_builtin_fputs (location_t, tree, tree, unsigned char, unsigned char, tree);
extern tree fold_builtin_strcpy (location_t, tree, tree, tree, tree);
extern tree fold_builtin_strncpy (location_t, tree, tree, tree, tree, tree);
extern tree fold_builtin_memory_chk (location_t, tree, tree, tree, tree, tree, tree, unsigned char,
         enum built_in_function);
extern tree fold_builtin_stxcpy_chk (location_t, tree, tree, tree, tree, tree, unsigned char,
         enum built_in_function);
extern tree fold_builtin_stxncpy_chk (location_t, tree, tree, tree, tree, tree, unsigned char,
          enum built_in_function);
extern tree fold_builtin_snprintf_chk (location_t, tree, tree, enum built_in_function);
extern unsigned char fold_builtin_next_arg (tree, unsigned char);
extern enum built_in_function builtin_mathfn_code (const_tree);
extern tree fold_builtin_call_array (location_t, tree, tree, int, tree *);
extern tree build_call_expr_loc_array (location_t, tree, int, tree *);
extern tree build_call_expr_loc_vec (location_t, tree, VEC_tree_gc *);
extern tree build_call_expr_loc (location_t, tree, int, ...);
extern tree build_call_expr (tree, int, ...);
extern tree mathfn_built_in (tree, enum built_in_function fn);
extern tree c_strlen (tree, int);
extern tree std_gimplify_va_arg_expr (tree, tree, gimple_seq *, gimple_seq *);
extern tree build_va_arg_indirect_ref (tree);
extern tree build_string_literal (int, const char *);
extern unsigned char validate_arglist (const_tree, ...);
extern rtx builtin_memset_read_str (void *, long long, enum machine_mode);
extern unsigned char is_builtin_fn (tree);
extern unsigned int get_object_alignment_1 (tree, unsigned long long *);
extern unsigned int get_object_alignment (tree);
extern unsigned int get_object_or_type_alignment (tree);
extern unsigned int get_pointer_alignment_1 (tree, unsigned long long *);
extern unsigned int get_pointer_alignment (tree);
extern tree fold_call_stmt (gimple, unsigned char);
extern tree gimple_fold_builtin_snprintf_chk (gimple, tree, enum built_in_function);
extern tree make_range (tree, int *, tree *, tree *, unsigned char *);
extern tree make_range_step (location_t, enum tree_code, tree, tree, tree,
        tree *, tree *, int *, unsigned char *);
extern tree build_range_check (location_t, tree, tree, int, tree, tree);
extern unsigned char merge_ranges (int *, tree *, tree *, int, tree, tree, int,
     tree, tree);
extern void set_builtin_user_assembler_name (tree decl, const char *asmspec);
extern unsigned char is_simple_builtin (tree);
extern unsigned char is_inexpensive_builtin (tree);
extern tree strip_float_extensions (tree);
extern int really_constant_p (const_tree);
extern unsigned char decl_address_invariant_p (const_tree);
extern unsigned char decl_address_ip_invariant_p (const_tree);
extern unsigned char int_fits_type_p (const_tree, const_tree);
extern void get_type_static_bounds (const_tree, mpz_t, mpz_t);
extern unsigned char variably_modified_type_p (tree, tree);
extern int tree_log2 (const_tree);
extern int tree_floor_log2 (const_tree);
extern int simple_cst_equal (const_tree, const_tree);
extern hashval_t iterative_hash_expr (const_tree, hashval_t);
extern hashval_t iterative_hash_exprs_commutative (const_tree,
                                                   const_tree, hashval_t);
extern hashval_t iterative_hash_host_wide_int (long long, hashval_t);
extern hashval_t iterative_hash_hashval_t (hashval_t, hashval_t);
extern hashval_t iterative_hash_host_wide_int (long long, hashval_t);
extern int compare_tree_int (const_tree, unsigned long long);
extern int type_list_equal (const_tree, const_tree);
extern int chain_member (const_tree, const_tree);
extern tree type_hash_lookup (unsigned int, tree);
extern void type_hash_add (unsigned int, tree);
extern int simple_cst_list_equal (const_tree, const_tree);
extern void dump_tree_statistics (void);
extern void recompute_tree_invariant_for_addr_expr (tree);
extern unsigned char needs_to_live_in_memory (const_tree);
extern tree reconstruct_complex_type (tree, tree);
extern int real_onep (const_tree);
extern int real_twop (const_tree);
extern int real_minus_onep (const_tree);
extern void init_ttree (void);
extern void build_common_tree_nodes (unsigned char, unsigned char);
extern void build_common_builtin_nodes (void);
extern tree build_nonstandard_integer_type (unsigned long long, int);
extern tree build_range_type (tree, tree, tree);
extern tree build_nonshared_range_type (tree, tree, tree);
extern unsigned char subrange_type_for_debug_p (const_tree, tree *, tree *);
extern long long int_cst_value (const_tree);
extern long long widest_int_cst_value (const_tree);
extern tree *tree_block (tree);
extern location_t *block_nonartificial_location (tree);
extern location_t tree_nonartificial_location (tree);
extern tree block_ultimate_origin (const_tree);
extern tree get_binfo_at_offset (tree, long long, tree);
extern tree build_addr (tree, tree);
extern void expand_main_function (void);
extern void expand_function_end (void);
extern void expand_function_start (tree);
extern void stack_protect_prologue (void);
extern void stack_protect_epilogue (void);
extern void init_dummy_function_start (void);
extern void expand_dummy_function_end (void);
extern unsigned int init_function_for_compilation (void);
extern void allocate_struct_function (tree, unsigned char);
extern void push_struct_function (tree fndecl);
extern void init_function_start (tree);
extern unsigned char use_register_for_decl (const_tree);
extern void generate_setjmp_warnings (void);
extern void init_temp_slots (void);
extern void free_temp_slots (void);
extern void pop_temp_slots (void);
extern void push_temp_slots (void);
extern void preserve_temp_slots (rtx);
extern int aggregate_value_p (const_tree, const_tree);
extern void push_function_context (void);
extern void pop_function_context (void);
extern gimple_seq gimplify_parameters (void);
extern void print_rtl (FILE *, const_rtx);
extern void debug_tree (tree);
extern void debug_vec_tree (VEC_tree_gc *);
extern void dump_addr (FILE*, const char *, const void *);
extern void print_node (FILE *, const char *, tree, int);
extern void print_vec_tree (FILE *, const char *, VEC_tree_gc *, int);
extern void print_node_brief (FILE *, const char *, const_tree, int);
extern void indent_to (FILE *, int);
extern unsigned char debug_find_tree (tree, tree);
extern tree unsave_expr_now (tree);
extern tree build_duplicate_type (tree);
# 5612 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern int flags_from_decl_or_type (const_tree);
extern int call_expr_flags (const_tree);
# 5639 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern int setjmp_call_p (const_tree);
extern unsigned char gimple_alloca_call_p (const_gimple);
extern unsigned char alloca_call_p (const_tree);
extern unsigned char must_pass_in_stack_var_size (enum machine_mode, const_tree);
extern unsigned char must_pass_in_stack_var_size_or_pad (enum machine_mode, const_tree);
extern const struct attribute_spec *lookup_attribute_spec (const_tree);
extern void init_attributes (void);
# 5659 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern tree decl_attributes (tree *, tree, int);
extern void apply_tm_attr (tree, tree);
extern void set_decl_abstract_flags (tree, int);
extern void set_decl_origin_self (tree);
extern void set_min_and_max_values_for_integral_type (tree, int, unsigned char);
extern void fixup_signed_type (tree);
extern void internal_reference_types (void);
extern unsigned int update_alignment_for_field (record_layout_info, tree,
                                                unsigned int);
extern tree tree_output_constant_def (tree);
extern void make_decl_rtl (tree);
extern rtx make_decl_rtl_for_debug (tree);
extern void make_decl_one_only (tree, tree);
extern int supports_one_only (void);
extern void resolve_unique_section (tree, int, int);
extern void mark_referenced (tree);
extern void mark_decl_referenced (tree);
extern void notice_global_symbol (tree);
extern void set_user_assembler_name (tree, const char *);
extern void process_pending_assemble_externals (void);
extern void finish_aliases_1 (void);
extern void finish_aliases_2 (void);
extern void remove_unreachable_alias_pairs (void);
extern unsigned char decl_replaceable_p (tree);
extern unsigned char decl_binds_to_current_def_p (tree);
typedef struct pointer_set_t symbol_alias_set_t;
extern void symbol_alias_set_destroy (symbol_alias_set_t *);
extern int symbol_alias_set_contains (const symbol_alias_set_t *, tree);
extern symbol_alias_set_t * propagate_aliases_backward (unsigned char (*)
        (tree, tree, void *),
       void *);
extern void expand_computed_goto (tree);
extern unsigned char parse_output_constraint (const char **, int, int, int,
         unsigned char *, unsigned char *, unsigned char *);
extern unsigned char parse_input_constraint (const char **, int, int, int, int,
        const char * const *, unsigned char *, unsigned char *);
extern void expand_asm_stmt (gimple);
extern tree resolve_asm_operand_names (tree, tree, tree, tree);
extern unsigned char expand_switch_using_bit_tests_p (tree, tree, unsigned int,
          unsigned int);
extern void expand_case (gimple);
extern void expand_decl (tree);
# 5725 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
struct pointer_set_t;
typedef tree (*walk_tree_fn) (tree *, int *, void *);
typedef tree (*walk_tree_lh) (tree *, int *, tree (*) (tree *, int *, void *),
         void *, struct pointer_set_t*);
extern tree walk_tree_1 (tree*, walk_tree_fn, void*, struct pointer_set_t*,
    walk_tree_lh);
extern tree walk_tree_without_duplicates_1 (tree*, walk_tree_fn, void*,
         walk_tree_lh);
# 5748 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
extern void set_decl_rtl (tree, rtx);
extern void set_decl_incoming_rtl (tree, rtx, unsigned char);
typedef enum
{
  d_kind,
  t_kind,
  b_kind,
  s_kind,
  r_kind,
  e_kind,
  c_kind,
  id_kind,
  vec_kind,
  binfo_kind,
  ssa_name_kind,
  constr_kind,
  x_kind,
  lang_decl,
  lang_type,
  omp_clause_kind,
  all_kinds
} tree_node_kind;
extern int tree_node_counts[];
extern int tree_node_sizes[];
extern unsigned char in_gimple_form;
extern tree get_base_address (tree t);
extern void mark_addressable (tree);
struct tree_map_base {
  tree from;
};
extern int tree_map_base_eq (const void *, const void *);
extern unsigned int tree_map_base_hash (const void *);
extern int tree_map_base_marked_p (const void *);
extern unsigned char list_equal_p (const_tree, const_tree);
struct tree_map {
  struct tree_map_base base;
  unsigned int hash;
  tree to;
};
extern unsigned int tree_map_hash (const void *);
struct tree_decl_map {
  struct tree_map_base base;
  tree to;
};
extern unsigned int tree_decl_map_hash (const void *);
struct tree_int_map {
  struct tree_map_base base;
  unsigned int to;
};
struct tree_priority_map {
  struct tree_map_base base;
  priority_type init;
  priority_type fini;
};
struct tree_vec_map {
  struct tree_map_base base;
  VEC_tree_gc *to;
};
tree target_for_debug_bind (tree);
extern tree tree_mem_ref_addr (tree, tree);
extern void copy_mem_ref_info (tree, tree);
extern void copy_ref_info (tree, tree);
extern unsigned char ssa_name_nonnegative_p (const_tree);
extern void init_object_sizes (void);
extern void fini_object_sizes (void);
extern unsigned long long compute_builtin_object_size (tree, int);
extern unsigned long long highest_pow2_factor (const_tree);
extern tree build_personality_function (const char *);
extern tree build_tm_abort_call (location_t, unsigned char);
extern unsigned char is_tm_safe (const_tree);
extern unsigned char is_tm_pure (const_tree);
extern unsigned char is_tm_may_cancel_outer (tree);
extern unsigned char is_tm_ending_fndecl (tree);
extern void record_tm_replacement (tree, tree);
extern void tm_malloc_replacement (tree);
static __inline__ unsigned char
is_tm_safe_or_pure (const_tree x)
{
  return is_tm_safe (x) || is_tm_pure (x);
}
void init_inline_once (void);
static __inline__ int
tree_operand_length (const_tree node)
{
  if ((tree_code_type[(int) (((enum tree_code) (node)->base.code))] == tcc_vl_exp))
    return ((int)((((node)->exp.operands[0])->int_cst.int_cst).low));
  else
    return tree_code_length[(int) (((enum tree_code) (node)->base.code))];
}
typedef struct call_expr_arg_iterator_d {
  tree t;
  int n;
  int i;
} call_expr_arg_iterator;
typedef struct const_call_expr_arg_iterator_d {
  const_tree t;
  int n;
  int i;
} const_call_expr_arg_iterator;
static __inline__ void
init_call_expr_arg_iterator (tree exp, call_expr_arg_iterator *iter)
{
  iter->t = exp;
  iter->n = (((int)((((exp)->exp.operands[0])->int_cst.int_cst).low)) - 3);
  iter->i = 0;
}
static __inline__ void
init_const_call_expr_arg_iterator (const_tree exp, const_call_expr_arg_iterator *iter)
{
  iter->t = exp;
  iter->n = (((int)((((exp)->exp.operands[0])->int_cst.int_cst).low)) - 3);
  iter->i = 0;
}
static __inline__ tree
next_call_expr_arg (call_expr_arg_iterator *iter)
{
  tree result;
  if (iter->i >= iter->n)
    return (tree) ((void *)0);
  result = (((iter->t))->exp.operands[(iter->i) + 3]);
  iter->i++;
  return result;
}
static __inline__ const_tree
next_const_call_expr_arg (const_call_expr_arg_iterator *iter)
{
  const_tree result;
  if (iter->i >= iter->n)
    return (tree) ((void *)0);
  result = (((iter->t))->exp.operands[(iter->i) + 3]);
  iter->i++;
  return result;
}
static __inline__ tree
first_call_expr_arg (tree exp, call_expr_arg_iterator *iter)
{
  init_call_expr_arg_iterator (exp, iter);
  return next_call_expr_arg (iter);
}
static __inline__ const_tree
first_const_call_expr_arg (const_tree exp, const_call_expr_arg_iterator *iter)
{
  init_const_call_expr_arg_iterator (exp, iter);
  return next_const_call_expr_arg (iter);
}
static __inline__ unsigned char
more_call_expr_args_p (const call_expr_arg_iterator *iter)
{
  return (iter->i < iter->n);
}
static __inline__ unsigned char
more_const_call_expr_args_p (const const_call_expr_arg_iterator *iter)
{
  return (iter->i < iter->n);
}
# 6008 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
static __inline__ unsigned char
is_lang_specific (tree t)
{
  return ((enum tree_code) (t)->base.code) == LANG_TYPE || ((enum tree_code) (t)->base.code) >= ((int) LAST_AND_UNUSED_TREE_CODE);
}
extern unsigned char block_may_fallthru (const_tree);
# 6024 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h"
typedef struct builtin_info_type_d {
  tree decl[(int)END_BUILTINS];
  unsigned char implicit_p[(int)END_BUILTINS];
} builtin_info_type;
extern builtin_info_type builtin_info;
static __inline__ tree
builtin_decl_explicit (enum built_in_function fncode)
{
  ((void)(0 && ((((unsigned long long) ((int)fncode) - (unsigned long long) (((int)BUILT_IN_NONE) + 1) <= (unsigned long long) (((int) END_BUILTINS) - 1) - (unsigned long long) (((int)BUILT_IN_NONE) + 1))))));
  return builtin_info.decl[(size_t)fncode];
}
static __inline__ tree
builtin_decl_implicit (enum built_in_function fncode)
{
  size_t uns_fncode = (size_t)fncode;
  ((void)(0 && ((((unsigned long long) ((int)fncode) - (unsigned long long) (((int)BUILT_IN_NONE) + 1) <= (unsigned long long) (((int) END_BUILTINS) - 1) - (unsigned long long) (((int)BUILT_IN_NONE) + 1))))));
  if (!builtin_info.implicit_p[uns_fncode])
    return (tree) ((void *)0);
  return builtin_info.decl[uns_fncode];
}
static __inline__ void
set_builtin_decl (enum built_in_function fncode, tree decl, unsigned char implicit_p)
{
  size_t ufncode = (size_t)fncode;
  ((void)(0 && ((((unsigned long long) ((int)fncode) - (unsigned long long) (((int)BUILT_IN_NONE) + 1) <= (unsigned long long) (((int) END_BUILTINS) - 1) - (unsigned long long) (((int)BUILT_IN_NONE) + 1))) && (decl != (tree) ((void *)0) || !implicit_p))));
  builtin_info.decl[ufncode] = decl;
  builtin_info.implicit_p[ufncode] = implicit_p;
}
static __inline__ void
set_builtin_decl_implicit_p (enum built_in_function fncode, unsigned char implicit_p)
{
  size_t uns_fncode = (size_t)fncode;
  ((void)(0 && ((((unsigned long long) ((int)fncode) - (unsigned long long) (((int)BUILT_IN_NONE) + 1) <= (unsigned long long) (((int) END_BUILTINS) - 1) - (unsigned long long) (((int)BUILT_IN_NONE) + 1))) && builtin_info.decl[uns_fncode] != (tree) ((void *)0))));
  builtin_info.implicit_p[uns_fncode] = implicit_p;
}
static __inline__ unsigned char
builtin_decl_explicit_p (enum built_in_function fncode)
{
  ((void)(0 && ((((unsigned long long) ((int)fncode) - (unsigned long long) (((int)BUILT_IN_NONE) + 1) <= (unsigned long long) (((int) END_BUILTINS) - 1) - (unsigned long long) (((int)BUILT_IN_NONE) + 1))))));
  return (builtin_info.decl[(size_t)fncode] != (tree) ((void *)0));
}
static __inline__ unsigned char
builtin_decl_implicit_p (enum built_in_function fncode)
{
  size_t uns_fncode = (size_t)fncode;
  ((void)(0 && ((((unsigned long long) ((int)fncode) - (unsigned long long) (((int)BUILT_IN_NONE) + 1) <= (unsigned long long) (((int) END_BUILTINS) - 1) - (unsigned long long) (((int)BUILT_IN_NONE) + 1))))));
  return (builtin_info.decl[uns_fncode] != (tree) ((void *)0)
   && builtin_info.implicit_p[uns_fncode]);
}
# 25 "../../../src/plugin-utils.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 1
# 21 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/insn-constants.h" 1
# 27 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/insn-constants.h"
enum unspec {
  UNSPEC_SIN = 0,
  UNPSEC_COS = 1,
  UNSPEC_PUSH_MULT = 2,
  UNSPEC_PIC_SYM = 3,
  UNSPEC_PIC_BASE = 4,
  UNSPEC_PRLG_STK = 5,
  UNSPEC_PROLOGUE_USE = 6,
  UNSPEC_CHECK_ARCH = 7,
  UNSPEC_WSHUFH = 8,
  UNSPEC_WACC = 9,
  UNSPEC_TMOVMSK = 10,
  UNSPEC_WSAD = 11,
  UNSPEC_WSADZ = 12,
  UNSPEC_WMACS = 13,
  UNSPEC_WMACU = 14,
  UNSPEC_WMACSZ = 15,
  UNSPEC_WMACUZ = 16,
  UNSPEC_CLRDI = 17,
  UNSPEC_WMADDS = 18,
  UNSPEC_WMADDU = 19,
  UNSPEC_TLS = 20,
  UNSPEC_PIC_LABEL = 21,
  UNSPEC_PIC_OFFSET = 22,
  UNSPEC_GOTSYM_OFF = 23,
  UNSPEC_THUMB1_CASESI = 24,
  UNSPEC_RBIT = 25,
  UNSPEC_SYMBOL_OFFSET = 26,
  UNSPEC_MEMORY_BARRIER = 27,
  UNSPEC_UNALIGNED_LOAD = 28,
  UNSPEC_UNALIGNED_STORE = 29,
  UNSPEC_PIC_UNIFIED = 30,
  UNSPEC_ASHIFT_SIGNED = 31,
  UNSPEC_ASHIFT_UNSIGNED = 32,
  UNSPEC_VABD = 33,
  UNSPEC_VABDL = 34,
  UNSPEC_VADD = 35,
  UNSPEC_VADDHN = 36,
  UNSPEC_VADDL = 37,
  UNSPEC_VADDW = 38,
  UNSPEC_VBSL = 39,
  UNSPEC_VCAGE = 40,
  UNSPEC_VCAGT = 41,
  UNSPEC_VCEQ = 42,
  UNSPEC_VCGE = 43,
  UNSPEC_VCGEU = 44,
  UNSPEC_VCGT = 45,
  UNSPEC_VCGTU = 46,
  UNSPEC_VCLS = 47,
  UNSPEC_VCONCAT = 48,
  UNSPEC_VCVT = 49,
  UNSPEC_VCVT_N = 50,
  UNSPEC_VEXT = 51,
  UNSPEC_VHADD = 52,
  UNSPEC_VHSUB = 53,
  UNSPEC_VLD1 = 54,
  UNSPEC_VLD1_DUP = 55,
  UNSPEC_VLD1_LANE = 56,
  UNSPEC_VLD2 = 57,
  UNSPEC_VLD2_DUP = 58,
  UNSPEC_VLD2_LANE = 59,
  UNSPEC_VLD3 = 60,
  UNSPEC_VLD3A = 61,
  UNSPEC_VLD3B = 62,
  UNSPEC_VLD3_DUP = 63,
  UNSPEC_VLD3_LANE = 64,
  UNSPEC_VLD4 = 65,
  UNSPEC_VLD4A = 66,
  UNSPEC_VLD4B = 67,
  UNSPEC_VLD4_DUP = 68,
  UNSPEC_VLD4_LANE = 69,
  UNSPEC_VMAX = 70,
  UNSPEC_VMIN = 71,
  UNSPEC_VMLA = 72,
  UNSPEC_VMLAL = 73,
  UNSPEC_VMLA_LANE = 74,
  UNSPEC_VMLAL_LANE = 75,
  UNSPEC_VMLS = 76,
  UNSPEC_VMLSL = 77,
  UNSPEC_VMLS_LANE = 78,
  UNSPEC_VMLSL_LANE = 79,
  UNSPEC_VMOVL = 80,
  UNSPEC_VMOVN = 81,
  UNSPEC_VMUL = 82,
  UNSPEC_VMULL = 83,
  UNSPEC_VMUL_LANE = 84,
  UNSPEC_VMULL_LANE = 85,
  UNSPEC_VPADAL = 86,
  UNSPEC_VPADD = 87,
  UNSPEC_VPADDL = 88,
  UNSPEC_VPMAX = 89,
  UNSPEC_VPMIN = 90,
  UNSPEC_VPSMAX = 91,
  UNSPEC_VPSMIN = 92,
  UNSPEC_VPUMAX = 93,
  UNSPEC_VPUMIN = 94,
  UNSPEC_VQABS = 95,
  UNSPEC_VQADD = 96,
  UNSPEC_VQDMLAL = 97,
  UNSPEC_VQDMLAL_LANE = 98,
  UNSPEC_VQDMLSL = 99,
  UNSPEC_VQDMLSL_LANE = 100,
  UNSPEC_VQDMULH = 101,
  UNSPEC_VQDMULH_LANE = 102,
  UNSPEC_VQDMULL = 103,
  UNSPEC_VQDMULL_LANE = 104,
  UNSPEC_VQMOVN = 105,
  UNSPEC_VQMOVUN = 106,
  UNSPEC_VQNEG = 107,
  UNSPEC_VQSHL = 108,
  UNSPEC_VQSHL_N = 109,
  UNSPEC_VQSHLU_N = 110,
  UNSPEC_VQSHRN_N = 111,
  UNSPEC_VQSHRUN_N = 112,
  UNSPEC_VQSUB = 113,
  UNSPEC_VRECPE = 114,
  UNSPEC_VRECPS = 115,
  UNSPEC_VREV16 = 116,
  UNSPEC_VREV32 = 117,
  UNSPEC_VREV64 = 118,
  UNSPEC_VRSQRTE = 119,
  UNSPEC_VRSQRTS = 120,
  UNSPEC_VSHL = 121,
  UNSPEC_VSHLL_N = 122,
  UNSPEC_VSHL_N = 123,
  UNSPEC_VSHR_N = 124,
  UNSPEC_VSHRN_N = 125,
  UNSPEC_VSLI = 126,
  UNSPEC_VSRA_N = 127,
  UNSPEC_VSRI = 128,
  UNSPEC_VST1 = 129,
  UNSPEC_VST1_LANE = 130,
  UNSPEC_VST2 = 131,
  UNSPEC_VST2_LANE = 132,
  UNSPEC_VST3 = 133,
  UNSPEC_VST3A = 134,
  UNSPEC_VST3B = 135,
  UNSPEC_VST3_LANE = 136,
  UNSPEC_VST4 = 137,
  UNSPEC_VST4A = 138,
  UNSPEC_VST4B = 139,
  UNSPEC_VST4_LANE = 140,
  UNSPEC_VSTRUCTDUMMY = 141,
  UNSPEC_VSUB = 142,
  UNSPEC_VSUBHN = 143,
  UNSPEC_VSUBL = 144,
  UNSPEC_VSUBW = 145,
  UNSPEC_VTBL = 146,
  UNSPEC_VTBX = 147,
  UNSPEC_VTRN1 = 148,
  UNSPEC_VTRN2 = 149,
  UNSPEC_VTST = 150,
  UNSPEC_VUZP1 = 151,
  UNSPEC_VUZP2 = 152,
  UNSPEC_VZIP1 = 153,
  UNSPEC_VZIP2 = 154,
  UNSPEC_MISALIGNED_ACCESS = 155,
  UNSPEC_VCLE = 156,
  UNSPEC_VCLT = 157
};
extern const char *const unspec_strings[];
enum unspecv {
  VUNSPEC_BLOCKAGE = 0,
  VUNSPEC_EPILOGUE = 1,
  VUNSPEC_THUMB1_INTERWORK = 2,
  VUNSPEC_ALIGN = 3,
  VUNSPEC_POOL_END = 4,
  VUNSPEC_POOL_1 = 5,
  VUNSPEC_POOL_2 = 6,
  VUNSPEC_POOL_4 = 7,
  VUNSPEC_POOL_8 = 8,
  VUNSPEC_POOL_16 = 9,
  VUNSPEC_TMRC = 10,
  VUNSPEC_TMCR = 11,
  VUNSPEC_ALIGN8 = 12,
  VUNSPEC_WCMP_EQ = 13,
  VUNSPEC_WCMP_GTU = 14,
  VUNSPEC_WCMP_GT = 15,
  VUNSPEC_EH_RETURN = 16,
  VUNSPEC_ATOMIC_CAS = 17,
  VUNSPEC_ATOMIC_XCHG = 18,
  VUNSPEC_ATOMIC_OP = 19,
  VUNSPEC_LL = 20,
  VUNSPEC_SC = 21
};
extern const char *const unspecv_strings[];
# 22 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/dbxelf.h" 1
# 23 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/elfos.h" 1
# 24 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/gnu-user.h" 1
# 25 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/linux.h" 1
# 26 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/linux-android.h" 1
# 27 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/glibc-stdint.h" 1
# 28 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/elf.h" 1
# 29 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/linux-gas.h" 1
# 30 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/linux-elf.h" 1
# 31 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/bpabi.h" 1
# 32 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/linux-eabi.h" 1
# 33 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/aout.h" 1
# 34 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm.h" 1
# 35 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/insn-modes.h" 1
# 36 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/config/vxworks-dummy.h" 1
# 40 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm.h" 2
extern char arm_arch_name[];
# 112 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm-opts.h" 1
# 113 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm.h" 2
enum target_cpus
{
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm-cores.def" 1
# 39 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm-cores.def"
TARGET_CPU_arm2,
TARGET_CPU_arm250,
TARGET_CPU_arm3,
TARGET_CPU_arm6,
TARGET_CPU_arm60,
TARGET_CPU_arm600,
TARGET_CPU_arm610,
TARGET_CPU_arm620,
TARGET_CPU_arm7,
TARGET_CPU_arm7d,
TARGET_CPU_arm7di,
TARGET_CPU_arm70,
TARGET_CPU_arm700,
TARGET_CPU_arm700i,
TARGET_CPU_arm710,
TARGET_CPU_arm720,
TARGET_CPU_arm710c,
TARGET_CPU_arm7100,
TARGET_CPU_arm7500,
TARGET_CPU_arm7500fe,
TARGET_CPU_arm7m,
TARGET_CPU_arm7dm,
TARGET_CPU_arm7dmi,
TARGET_CPU_arm8,
TARGET_CPU_arm810,
TARGET_CPU_strongarm,
TARGET_CPU_strongarm110,
TARGET_CPU_strongarm1100,
TARGET_CPU_strongarm1110,
TARGET_CPU_fa526,
TARGET_CPU_fa626,
TARGET_CPU_arm7tdmi,
TARGET_CPU_arm7tdmis,
TARGET_CPU_arm710t,
TARGET_CPU_arm720t,
TARGET_CPU_arm740t,
TARGET_CPU_arm9,
TARGET_CPU_arm9tdmi,
TARGET_CPU_arm920,
TARGET_CPU_arm920t,
TARGET_CPU_arm922t,
TARGET_CPU_arm940t,
TARGET_CPU_ep9312,
TARGET_CPU_arm10tdmi,
TARGET_CPU_arm1020t,
TARGET_CPU_arm9e,
TARGET_CPU_arm946es,
TARGET_CPU_arm966es,
TARGET_CPU_arm968es,
TARGET_CPU_arm10e,
TARGET_CPU_arm1020e,
TARGET_CPU_arm1022e,
TARGET_CPU_xscale,
TARGET_CPU_iwmmxt,
TARGET_CPU_iwmmxt2,
TARGET_CPU_fa606te,
TARGET_CPU_fa626te,
TARGET_CPU_fmp626,
TARGET_CPU_fa726te,
TARGET_CPU_arm926ejs,
TARGET_CPU_arm1026ejs,
TARGET_CPU_arm1136js,
TARGET_CPU_arm1136jfs,
TARGET_CPU_arm1176jzs,
TARGET_CPU_arm1176jzfs,
TARGET_CPU_mpcorenovfp,
TARGET_CPU_mpcore,
TARGET_CPU_arm1156t2s,
TARGET_CPU_arm1156t2fs,
TARGET_CPU_genericv7a,
TARGET_CPU_cortexa5,
TARGET_CPU_cortexa7,
TARGET_CPU_cortexa8,
TARGET_CPU_cortexa9,
TARGET_CPU_cortexa15,
TARGET_CPU_cortexr4,
TARGET_CPU_cortexr4f,
TARGET_CPU_cortexr5,
TARGET_CPU_cortexm4,
TARGET_CPU_cortexm3,
TARGET_CPU_cortexm1,
TARGET_CPU_cortexm0,
# 119 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm.h" 2
  TARGET_CPU_generic
};
extern enum processor_type arm_tune;
typedef enum arm_cond_code
{
  ARM_EQ = 0, ARM_NE, ARM_CS, ARM_CC, ARM_MI, ARM_PL, ARM_VS, ARM_VC,
  ARM_HI, ARM_LS, ARM_GE, ARM_LT, ARM_GT, ARM_LE, ARM_AL, ARM_NV
}
arm_cc;
extern arm_cc arm_current_cc;
extern int arm_target_label;
extern int arm_ccfsm_state;
extern rtx arm_target_insn;
extern rtx pool_vector_label;
extern int return_used_this_function;
extern void (*arm_lang_output_object_attributes_hook)(void);
# 322 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm.h"
enum arm_fp_model
{
  ARM_FP_MODEL_UNKNOWN,
  ARM_FP_MODEL_FPA,
  ARM_FP_MODEL_MAVERICK,
  ARM_FP_MODEL_VFP
};
enum vfp_reg_type
{
  VFP_NONE = 0,
  VFP_REG_D16,
  VFP_REG_D32,
  VFP_REG_SINGLE
};
extern const struct arm_fpu_desc
{
  const char *name;
  enum arm_fp_model model;
  int rev;
  enum vfp_reg_type regs;
  int neon;
  int fp16;
} *arm_fpu_desc;
extern int arm_fpu_attr;
# 366 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm.h"
extern int arm_arch3m;
extern int arm_arch4;
extern int arm_arch4t;
extern int arm_arch5;
extern int arm_arch5e;
extern int arm_arch6;
extern int arm_arch6k;
extern int arm_arch7;
extern int arm_arch_notm;
extern int arm_arch7em;
extern int arm_ld_sched;
extern int thumb_code;
extern int thumb1_code;
extern int arm_tune_strongarm;
extern int arm_arch_cirrus;
extern int arm_arch_iwmmxt;
extern int arm_arch_xscale;
extern int arm_tune_xscale;
extern int arm_tune_wbuf;
extern int arm_tune_cortex_a9;
extern int arm_cpp_interwork;
extern int arm_arch_thumb2;
extern int arm_arch_arm_hwdiv;
extern int arm_arch_thumb_hwdiv;
# 986 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm.h"
extern int arm_regs_in_sequence[];
# 1039 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm.h"
enum reg_class
{
  NO_REGS,
  FPA_REGS,
  CIRRUS_REGS,
  VFP_D0_D7_REGS,
  VFP_LO_REGS,
  VFP_HI_REGS,
  VFP_REGS,
  IWMMXT_GR_REGS,
  IWMMXT_REGS,
  LO_REGS,
  STACK_REG,
  BASE_REGS,
  HI_REGS,
  CC_REG,
  VFPCC_REG,
  GENERAL_REGS,
  CORE_REGS,
  ALL_REGS,
  LIM_REG_CLASSES
};
# 1364 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm.h"
typedef struct arm_stack_offsets
{
  int saved_args;
  int frame;
  int saved_regs;
  int soft_frame;
  int locals_base;
  int outgoing_args;
  unsigned int saved_regs_mask;
}
arm_stack_offsets;
typedef struct machine_function
{
  rtx eh_epilogue_sp_ofs;
  int far_jump_used;
  int arg_pointer_live;
  int lr_save_eliminated;
  arm_stack_offsets stack_offsets;
  unsigned long func_type;
  int uses_anonymous_args;
  int sibcall_blocked;
  rtx pic_reg;
  rtx call_via[14];
  int return_used_this_function;
  rtx thumb1_cc_insn;
  rtx thumb1_cc_op0;
  rtx thumb1_cc_op1;
  enum machine_mode thumb1_cc_mode;
}
machine_function;
extern rtx thumb_call_via_label[14];
enum arm_pcs
{
  ARM_PCS_AAPCS,
  ARM_PCS_AAPCS_VFP,
  ARM_PCS_AAPCS_IWMMXT,
  ARM_PCS_AAPCS_LOCAL,
  ARM_PCS_ATPCS,
  ARM_PCS_APCS,
  ARM_PCS_UNKNOWN
};
extern enum arm_pcs arm_pcs_default;
typedef struct
{
  int nregs;
  int iwmmxt_nregs;
  int named_count;
  int nargs;
  enum arm_pcs pcs_variant;
  int aapcs_arg_processed;
  int aapcs_cprc_slot;
  int aapcs_ncrn;
  int aapcs_next_ncrn;
  rtx aapcs_reg;
  int aapcs_partial;
  int aapcs_cprc_failed[1];
  int can_split;
  unsigned aapcs_vfp_regs_free;
  unsigned aapcs_vfp_reg_alloc;
  int aapcs_vfp_rcount;
  enum machine_mode aapcs_vfp_rmode;
} CUMULATIVE_ARGS;
# 1928 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm.h"
extern unsigned arm_pic_register;
# 1949 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/arm/arm.h"
extern int making_const_table;
# 35 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/config/initfini-array.h" 1
# 36 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/insn-flags.h" 1
# 2272 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/insn-flags.h"
extern rtx gen_addsi3_compare0 (rtx, rtx, rtx);
extern rtx gen_thumb1_subsi3_insn (rtx, rtx, rtx);
extern rtx gen_mulhisi3 (rtx, rtx, rtx);
extern rtx gen_maddhisi4 (rtx, rtx, rtx, rtx);
extern rtx gen_maddhidi4 (rtx, rtx, rtx, rtx);
extern rtx gen_insv_zero (rtx, rtx, rtx);
extern rtx gen_insv_t2 (rtx, rtx, rtx, rtx);
extern rtx gen_andsi_notsi_si (rtx, rtx, rtx);
extern rtx gen_thumb1_bicsi3 (rtx, rtx, rtx);
extern rtx gen_andsi_not_shiftsi_si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_arm_ashldi3_1bit (rtx, rtx);
extern rtx gen_arm_ashrdi3_1bit (rtx, rtx);
extern rtx gen_arm_lshrdi3_1bit (rtx, rtx);
extern rtx gen_unaligned_loadsi (rtx, rtx);
extern rtx gen_unaligned_loadhis (rtx, rtx);
extern rtx gen_unaligned_loadhiu (rtx, rtx);
extern rtx gen_unaligned_storesi (rtx, rtx);
extern rtx gen_unaligned_storehi (rtx, rtx);
extern rtx gen_extzv_t2 (rtx, rtx, rtx, rtx);
extern rtx gen_divsi3 (rtx, rtx, rtx);
extern rtx gen_udivsi3 (rtx, rtx, rtx);
extern rtx gen_one_cmpldi2 (rtx, rtx);
extern rtx gen_zero_extendqidi2 (rtx, rtx);
extern rtx gen_zero_extendhidi2 (rtx, rtx);
extern rtx gen_zero_extendsidi2 (rtx, rtx);
extern rtx gen_extendqidi2 (rtx, rtx);
extern rtx gen_extendhidi2 (rtx, rtx);
extern rtx gen_extendsidi2 (rtx, rtx);
extern rtx gen_thumb1_extendhisi2 (rtx, rtx);
extern rtx gen_thumb1_extendqisi2 (rtx, rtx);
extern rtx gen_pic_load_addr_unified (rtx, rtx, rtx);
extern rtx gen_pic_load_addr_32bit (rtx, rtx);
extern rtx gen_pic_load_addr_thumb1 (rtx, rtx);
extern rtx gen_pic_add_dot_plus_four (rtx, rtx, rtx);
extern rtx gen_pic_add_dot_plus_eight (rtx, rtx, rtx);
extern rtx gen_tls_load_dot_plus_eight (rtx, rtx, rtx);
static __inline__ rtx gen_pic_offset_arm (rtx, rtx, rtx);
static __inline__ rtx
gen_pic_offset_arm(rtx a __attribute__ ((__unused__)), rtx b __attribute__ ((__unused__)), rtx c __attribute__ ((__unused__)))
{
  return 0;
}
extern rtx gen_movmem12b (rtx, rtx, rtx, rtx);
extern rtx gen_movmem8b (rtx, rtx, rtx, rtx);
extern rtx gen_cbranchsi4_insn (rtx, rtx, rtx, rtx);
extern rtx gen_cbranchsi4_scratch (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_cstoresi_nltu_thumb1 (rtx, rtx, rtx);
extern rtx gen_cstoresi_ltu_thumb1 (rtx, rtx, rtx);
extern rtx gen_thumb1_addsi3_addgeu (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_blockage (void);
extern rtx gen_arm_casesi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_thumb1_casesi_dispatch (rtx);
extern rtx gen_nop (void);
extern rtx gen_movcond (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_prologue_thumb1_interwork (void);
extern rtx gen_sibcall_epilogue (void);
extern rtx gen_stack_tie (rtx, rtx);
extern rtx gen_align_4 (void);
extern rtx gen_align_8 (void);
extern rtx gen_consttable_end (void);
extern rtx gen_consttable_1 (rtx);
extern rtx gen_consttable_2 (rtx);
extern rtx gen_consttable_4 (rtx);
extern rtx gen_consttable_8 (rtx);
extern rtx gen_consttable_16 (rtx);
extern rtx gen_clzsi2 (rtx, rtx);
extern rtx gen_rbitsi2 (rtx, rtx);
extern rtx gen_prefetch (rtx, rtx, rtx);
extern rtx gen_prologue_use (rtx);
extern rtx gen_arm_eh_return (rtx);
extern rtx gen_thumb_eh_return (rtx);
extern rtx gen_load_tp_hard (rtx);
extern rtx gen_load_tp_soft (void);
extern rtx gen_tlscall (rtx, rtx);
extern rtx gen_cirrus_adddi3 (rtx, rtx, rtx);
extern rtx gen_cirrus_subdi3 (rtx, rtx, rtx);
extern rtx gen_muldi3 (rtx, rtx, rtx);
static __inline__ rtx gen_cirrus_ashl_const (rtx, rtx, rtx);
static __inline__ rtx
gen_cirrus_ashl_const(rtx a __attribute__ ((__unused__)), rtx b __attribute__ ((__unused__)), rtx c __attribute__ ((__unused__)))
{
  return 0;
}
static __inline__ rtx gen_cirrus_ashiftrt_const (rtx, rtx, rtx);
static __inline__ rtx
gen_cirrus_ashiftrt_const(rtx a __attribute__ ((__unused__)), rtx b __attribute__ ((__unused__)), rtx c __attribute__ ((__unused__)))
{
  return 0;
}
static __inline__ rtx gen_cirrus_ashlsi3 (rtx, rtx, rtx);
static __inline__ rtx
gen_cirrus_ashlsi3(rtx a __attribute__ ((__unused__)), rtx b __attribute__ ((__unused__)), rtx c __attribute__ ((__unused__)))
{
  return 0;
}
extern rtx gen_ashldi3_cirrus (rtx, rtx, rtx);
extern rtx gen_cirrus_ashldi_const (rtx, rtx, rtx);
extern rtx gen_cirrus_ashiftrtdi_const (rtx, rtx, rtx);
extern rtx gen_cirrus_floatsisf2 (rtx, rtx);
extern rtx gen_cirrus_floatsidf2 (rtx, rtx);
extern rtx gen_floatdisf2 (rtx, rtx);
extern rtx gen_floatdidf2 (rtx, rtx);
extern rtx gen_cirrus_truncsfsi2 (rtx, rtx);
extern rtx gen_cirrus_truncdfsi2 (rtx, rtx);
extern rtx gen_iwmmxt_iordi3 (rtx, rtx, rtx);
extern rtx gen_iwmmxt_xordi3 (rtx, rtx, rtx);
extern rtx gen_iwmmxt_anddi3 (rtx, rtx, rtx);
extern rtx gen_iwmmxt_nanddi3 (rtx, rtx, rtx);
extern rtx gen_movv2si_internal (rtx, rtx);
extern rtx gen_movv4hi_internal (rtx, rtx);
extern rtx gen_movv8qi_internal (rtx, rtx);
extern rtx gen_ssaddv8qi3 (rtx, rtx, rtx);
extern rtx gen_ssaddv4hi3 (rtx, rtx, rtx);
extern rtx gen_ssaddv2si3 (rtx, rtx, rtx);
extern rtx gen_usaddv8qi3 (rtx, rtx, rtx);
extern rtx gen_usaddv4hi3 (rtx, rtx, rtx);
extern rtx gen_usaddv2si3 (rtx, rtx, rtx);
extern rtx gen_sssubv8qi3 (rtx, rtx, rtx);
extern rtx gen_sssubv4hi3 (rtx, rtx, rtx);
extern rtx gen_sssubv2si3 (rtx, rtx, rtx);
extern rtx gen_ussubv8qi3 (rtx, rtx, rtx);
extern rtx gen_ussubv4hi3 (rtx, rtx, rtx);
extern rtx gen_ussubv2si3 (rtx, rtx, rtx);
extern rtx gen_smulv4hi3_highpart (rtx, rtx, rtx);
extern rtx gen_umulv4hi3_highpart (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wmacs (rtx, rtx, rtx, rtx);
extern rtx gen_iwmmxt_wmacsz (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wmacu (rtx, rtx, rtx, rtx);
extern rtx gen_iwmmxt_wmacuz (rtx, rtx, rtx);
extern rtx gen_iwmmxt_clrdi (rtx);
extern rtx gen_iwmmxt_uavgrndv8qi3 (rtx, rtx, rtx);
extern rtx gen_iwmmxt_uavgrndv4hi3 (rtx, rtx, rtx);
extern rtx gen_iwmmxt_uavgv8qi3 (rtx, rtx, rtx);
extern rtx gen_iwmmxt_uavgv4hi3 (rtx, rtx, rtx);
extern rtx gen_iwmmxt_psadbw (rtx, rtx, rtx);
extern rtx gen_iwmmxt_tinsrb (rtx, rtx, rtx, rtx);
extern rtx gen_iwmmxt_tinsrh (rtx, rtx, rtx, rtx);
extern rtx gen_iwmmxt_tinsrw (rtx, rtx, rtx, rtx);
extern rtx gen_iwmmxt_textrmub (rtx, rtx, rtx);
extern rtx gen_iwmmxt_textrmsb (rtx, rtx, rtx);
extern rtx gen_iwmmxt_textrmuh (rtx, rtx, rtx);
extern rtx gen_iwmmxt_textrmsh (rtx, rtx, rtx);
extern rtx gen_iwmmxt_textrmw (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wshufh (rtx, rtx, rtx);
extern rtx gen_eqv8qi3 (rtx, rtx, rtx);
extern rtx gen_eqv4hi3 (rtx, rtx, rtx);
extern rtx gen_eqv2si3 (rtx, rtx, rtx);
extern rtx gen_gtuv8qi3 (rtx, rtx, rtx);
extern rtx gen_gtuv4hi3 (rtx, rtx, rtx);
extern rtx gen_gtuv2si3 (rtx, rtx, rtx);
extern rtx gen_gtv8qi3 (rtx, rtx, rtx);
extern rtx gen_gtv4hi3 (rtx, rtx, rtx);
extern rtx gen_gtv2si3 (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wpackhss (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wpackwss (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wpackdss (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wpackhus (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wpackwus (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wpackdus (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wunpckihb (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wunpckihh (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wunpckihw (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wunpckilb (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wunpckilh (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wunpckilw (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wunpckehub (rtx, rtx);
extern rtx gen_iwmmxt_wunpckehuh (rtx, rtx);
extern rtx gen_iwmmxt_wunpckehuw (rtx, rtx);
extern rtx gen_iwmmxt_wunpckehsb (rtx, rtx);
extern rtx gen_iwmmxt_wunpckehsh (rtx, rtx);
extern rtx gen_iwmmxt_wunpckehsw (rtx, rtx);
extern rtx gen_iwmmxt_wunpckelub (rtx, rtx);
extern rtx gen_iwmmxt_wunpckeluh (rtx, rtx);
extern rtx gen_iwmmxt_wunpckeluw (rtx, rtx);
extern rtx gen_iwmmxt_wunpckelsb (rtx, rtx);
extern rtx gen_iwmmxt_wunpckelsh (rtx, rtx);
extern rtx gen_iwmmxt_wunpckelsw (rtx, rtx);
extern rtx gen_rorv4hi3 (rtx, rtx, rtx);
extern rtx gen_rorv2si3 (rtx, rtx, rtx);
extern rtx gen_rordi3 (rtx, rtx, rtx);
extern rtx gen_ashrv4hi3_iwmmxt (rtx, rtx, rtx);
extern rtx gen_ashrv2si3_iwmmxt (rtx, rtx, rtx);
extern rtx gen_ashrdi3_iwmmxt (rtx, rtx, rtx);
extern rtx gen_lshrv4hi3_iwmmxt (rtx, rtx, rtx);
extern rtx gen_lshrv2si3_iwmmxt (rtx, rtx, rtx);
extern rtx gen_lshrdi3_iwmmxt (rtx, rtx, rtx);
extern rtx gen_ashlv4hi3_iwmmxt (rtx, rtx, rtx);
extern rtx gen_ashlv2si3_iwmmxt (rtx, rtx, rtx);
extern rtx gen_ashldi3_iwmmxt (rtx, rtx, rtx);
extern rtx gen_rorv4hi3_di (rtx, rtx, rtx);
extern rtx gen_rorv2si3_di (rtx, rtx, rtx);
extern rtx gen_rordi3_di (rtx, rtx, rtx);
extern rtx gen_ashrv4hi3_di (rtx, rtx, rtx);
extern rtx gen_ashrv2si3_di (rtx, rtx, rtx);
extern rtx gen_ashrdi3_di (rtx, rtx, rtx);
extern rtx gen_lshrv4hi3_di (rtx, rtx, rtx);
extern rtx gen_lshrv2si3_di (rtx, rtx, rtx);
extern rtx gen_lshrdi3_di (rtx, rtx, rtx);
extern rtx gen_ashlv4hi3_di (rtx, rtx, rtx);
extern rtx gen_ashlv2si3_di (rtx, rtx, rtx);
extern rtx gen_ashldi3_di (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wmadds (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wmaddu (rtx, rtx, rtx);
extern rtx gen_iwmmxt_tmia (rtx, rtx, rtx, rtx);
extern rtx gen_iwmmxt_tmiaph (rtx, rtx, rtx, rtx);
extern rtx gen_iwmmxt_tmiabb (rtx, rtx, rtx, rtx);
extern rtx gen_iwmmxt_tmiatb (rtx, rtx, rtx, rtx);
extern rtx gen_iwmmxt_tmiabt (rtx, rtx, rtx, rtx);
extern rtx gen_iwmmxt_tmiatt (rtx, rtx, rtx, rtx);
extern rtx gen_iwmmxt_tbcstqi (rtx, rtx);
extern rtx gen_iwmmxt_tbcsthi (rtx, rtx);
extern rtx gen_iwmmxt_tbcstsi (rtx, rtx);
extern rtx gen_iwmmxt_tmovmskb (rtx, rtx);
extern rtx gen_iwmmxt_tmovmskh (rtx, rtx);
extern rtx gen_iwmmxt_tmovmskw (rtx, rtx);
extern rtx gen_iwmmxt_waccb (rtx, rtx);
extern rtx gen_iwmmxt_wacch (rtx, rtx);
extern rtx gen_iwmmxt_waccw (rtx, rtx);
extern rtx gen_iwmmxt_walign (rtx, rtx, rtx, rtx);
extern rtx gen_iwmmxt_tmrc (rtx, rtx);
extern rtx gen_iwmmxt_tmcr (rtx, rtx);
extern rtx gen_iwmmxt_wsadb (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wsadh (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wsadbz (rtx, rtx, rtx);
extern rtx gen_iwmmxt_wsadhz (rtx, rtx, rtx);
extern rtx gen_extendhfsf2 (rtx, rtx);
extern rtx gen_truncsfhf2 (rtx, rtx);
extern rtx gen_fixuns_truncsfsi2 (rtx, rtx);
extern rtx gen_fixuns_truncdfsi2 (rtx, rtx);
extern rtx gen_floatunssisf2 (rtx, rtx);
extern rtx gen_floatunssidf2 (rtx, rtx);
extern rtx gen_tls_load_dot_plus_four (rtx, rtx, rtx, rtx);
extern rtx gen_thumb2_zero_extendqisi2_v6 (rtx, rtx);
extern rtx gen_thumb2_casesi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_thumb2_casesi_internal_pic (rtx, rtx, rtx, rtx);
extern rtx gen_thumb2_eh_return (rtx);
extern rtx gen_thumb2_addsi3_compare0 (rtx, rtx, rtx);
extern rtx gen_vec_setv8qi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_vec_setv4hi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_vec_setv2si_internal (rtx, rtx, rtx, rtx);
extern rtx gen_vec_setv2sf_internal (rtx, rtx, rtx, rtx);
extern rtx gen_vec_setv16qi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_vec_setv8hi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_vec_setv4si_internal (rtx, rtx, rtx, rtx);
extern rtx gen_vec_setv4sf_internal (rtx, rtx, rtx, rtx);
extern rtx gen_vec_setv2di_internal (rtx, rtx, rtx, rtx);
extern rtx gen_vec_extractv8qi (rtx, rtx, rtx);
extern rtx gen_vec_extractv4hi (rtx, rtx, rtx);
extern rtx gen_vec_extractv2si (rtx, rtx, rtx);
extern rtx gen_vec_extractv2sf (rtx, rtx, rtx);
extern rtx gen_vec_extractv16qi (rtx, rtx, rtx);
extern rtx gen_vec_extractv8hi (rtx, rtx, rtx);
extern rtx gen_vec_extractv4si (rtx, rtx, rtx);
extern rtx gen_vec_extractv4sf (rtx, rtx, rtx);
extern rtx gen_vec_extractv2di (rtx, rtx, rtx);
extern rtx gen_adddi3_neon (rtx, rtx, rtx);
extern rtx gen_subdi3_neon (rtx, rtx, rtx);
extern rtx gen_mulv8qi3addv8qi_neon (rtx, rtx, rtx, rtx);
extern rtx gen_mulv16qi3addv16qi_neon (rtx, rtx, rtx, rtx);
extern rtx gen_mulv4hi3addv4hi_neon (rtx, rtx, rtx, rtx);
extern rtx gen_mulv8hi3addv8hi_neon (rtx, rtx, rtx, rtx);
extern rtx gen_mulv2si3addv2si_neon (rtx, rtx, rtx, rtx);
extern rtx gen_mulv4si3addv4si_neon (rtx, rtx, rtx, rtx);
extern rtx gen_mulv2sf3addv2sf_neon (rtx, rtx, rtx, rtx);
extern rtx gen_mulv4sf3addv4sf_neon (rtx, rtx, rtx, rtx);
extern rtx gen_mulv2di3addv2di_neon (rtx, rtx, rtx, rtx);
extern rtx gen_mulv8qi3negv8qiaddv8qi_neon (rtx, rtx, rtx, rtx);
extern rtx gen_mulv16qi3negv16qiaddv16qi_neon (rtx, rtx, rtx, rtx);
extern rtx gen_mulv4hi3negv4hiaddv4hi_neon (rtx, rtx, rtx, rtx);
extern rtx gen_mulv8hi3negv8hiaddv8hi_neon (rtx, rtx, rtx, rtx);
extern rtx gen_mulv2si3negv2siaddv2si_neon (rtx, rtx, rtx, rtx);
extern rtx gen_mulv4si3negv4siaddv4si_neon (rtx, rtx, rtx, rtx);
extern rtx gen_mulv2sf3negv2sfaddv2sf_neon (rtx, rtx, rtx, rtx);
extern rtx gen_mulv4sf3negv4sfaddv4sf_neon (rtx, rtx, rtx, rtx);
extern rtx gen_mulv2di3negv2diaddv2di_neon (rtx, rtx, rtx, rtx);
extern rtx gen_iorv8qi3 (rtx, rtx, rtx);
extern rtx gen_iorv16qi3 (rtx, rtx, rtx);
extern rtx gen_iorv4hi3 (rtx, rtx, rtx);
extern rtx gen_iorv8hi3 (rtx, rtx, rtx);
extern rtx gen_iorv2si3 (rtx, rtx, rtx);
extern rtx gen_iorv4si3 (rtx, rtx, rtx);
extern rtx gen_iorv2sf3 (rtx, rtx, rtx);
extern rtx gen_iorv4sf3 (rtx, rtx, rtx);
extern rtx gen_iorv2di3 (rtx, rtx, rtx);
extern rtx gen_iordi3_neon (rtx, rtx, rtx);
extern rtx gen_andv8qi3 (rtx, rtx, rtx);
extern rtx gen_andv16qi3 (rtx, rtx, rtx);
extern rtx gen_andv4hi3 (rtx, rtx, rtx);
extern rtx gen_andv8hi3 (rtx, rtx, rtx);
extern rtx gen_andv2si3 (rtx, rtx, rtx);
extern rtx gen_andv4si3 (rtx, rtx, rtx);
extern rtx gen_andv2sf3 (rtx, rtx, rtx);
extern rtx gen_andv4sf3 (rtx, rtx, rtx);
extern rtx gen_andv2di3 (rtx, rtx, rtx);
extern rtx gen_anddi3_neon (rtx, rtx, rtx);
extern rtx gen_ornv8qi3_neon (rtx, rtx, rtx);
extern rtx gen_ornv16qi3_neon (rtx, rtx, rtx);
extern rtx gen_ornv4hi3_neon (rtx, rtx, rtx);
extern rtx gen_ornv8hi3_neon (rtx, rtx, rtx);
extern rtx gen_ornv2si3_neon (rtx, rtx, rtx);
extern rtx gen_ornv4si3_neon (rtx, rtx, rtx);
extern rtx gen_ornv2sf3_neon (rtx, rtx, rtx);
extern rtx gen_ornv4sf3_neon (rtx, rtx, rtx);
extern rtx gen_ornv2di3_neon (rtx, rtx, rtx);
extern rtx gen_orndi3_neon (rtx, rtx, rtx);
extern rtx gen_bicv8qi3_neon (rtx, rtx, rtx);
extern rtx gen_bicv16qi3_neon (rtx, rtx, rtx);
extern rtx gen_bicv4hi3_neon (rtx, rtx, rtx);
extern rtx gen_bicv8hi3_neon (rtx, rtx, rtx);
extern rtx gen_bicv2si3_neon (rtx, rtx, rtx);
extern rtx gen_bicv4si3_neon (rtx, rtx, rtx);
extern rtx gen_bicv2sf3_neon (rtx, rtx, rtx);
extern rtx gen_bicv4sf3_neon (rtx, rtx, rtx);
extern rtx gen_bicv2di3_neon (rtx, rtx, rtx);
extern rtx gen_bicdi3_neon (rtx, rtx, rtx);
extern rtx gen_xorv8qi3 (rtx, rtx, rtx);
extern rtx gen_xorv16qi3 (rtx, rtx, rtx);
extern rtx gen_xorv4hi3 (rtx, rtx, rtx);
extern rtx gen_xorv8hi3 (rtx, rtx, rtx);
extern rtx gen_xorv2si3 (rtx, rtx, rtx);
extern rtx gen_xorv4si3 (rtx, rtx, rtx);
extern rtx gen_xorv2sf3 (rtx, rtx, rtx);
extern rtx gen_xorv4sf3 (rtx, rtx, rtx);
extern rtx gen_xorv2di3 (rtx, rtx, rtx);
extern rtx gen_xordi3_neon (rtx, rtx, rtx);
extern rtx gen_one_cmplv8qi2 (rtx, rtx);
extern rtx gen_one_cmplv16qi2 (rtx, rtx);
extern rtx gen_one_cmplv4hi2 (rtx, rtx);
extern rtx gen_one_cmplv8hi2 (rtx, rtx);
extern rtx gen_one_cmplv2si2 (rtx, rtx);
extern rtx gen_one_cmplv4si2 (rtx, rtx);
extern rtx gen_one_cmplv2sf2 (rtx, rtx);
extern rtx gen_one_cmplv4sf2 (rtx, rtx);
extern rtx gen_one_cmplv2di2 (rtx, rtx);
extern rtx gen_absv8qi2 (rtx, rtx);
extern rtx gen_absv16qi2 (rtx, rtx);
extern rtx gen_absv4hi2 (rtx, rtx);
extern rtx gen_absv8hi2 (rtx, rtx);
extern rtx gen_absv2si2 (rtx, rtx);
extern rtx gen_absv4si2 (rtx, rtx);
extern rtx gen_absv2sf2 (rtx, rtx);
extern rtx gen_absv4sf2 (rtx, rtx);
extern rtx gen_negv8qi2 (rtx, rtx);
extern rtx gen_negv16qi2 (rtx, rtx);
extern rtx gen_negv4hi2 (rtx, rtx);
extern rtx gen_negv8hi2 (rtx, rtx);
extern rtx gen_negv2si2 (rtx, rtx);
extern rtx gen_negv4si2 (rtx, rtx);
extern rtx gen_negv2sf2 (rtx, rtx);
extern rtx gen_negv4sf2 (rtx, rtx);
extern rtx gen_vashlv8qi3 (rtx, rtx, rtx);
extern rtx gen_vashlv16qi3 (rtx, rtx, rtx);
extern rtx gen_vashlv4hi3 (rtx, rtx, rtx);
extern rtx gen_vashlv8hi3 (rtx, rtx, rtx);
extern rtx gen_vashlv2si3 (rtx, rtx, rtx);
extern rtx gen_vashlv4si3 (rtx, rtx, rtx);
extern rtx gen_vashrv8qi3_imm (rtx, rtx, rtx);
extern rtx gen_vashrv16qi3_imm (rtx, rtx, rtx);
extern rtx gen_vashrv4hi3_imm (rtx, rtx, rtx);
extern rtx gen_vashrv8hi3_imm (rtx, rtx, rtx);
extern rtx gen_vashrv2si3_imm (rtx, rtx, rtx);
extern rtx gen_vashrv4si3_imm (rtx, rtx, rtx);
extern rtx gen_vlshrv8qi3_imm (rtx, rtx, rtx);
extern rtx gen_vlshrv16qi3_imm (rtx, rtx, rtx);
extern rtx gen_vlshrv4hi3_imm (rtx, rtx, rtx);
extern rtx gen_vlshrv8hi3_imm (rtx, rtx, rtx);
extern rtx gen_vlshrv2si3_imm (rtx, rtx, rtx);
extern rtx gen_vlshrv4si3_imm (rtx, rtx, rtx);
extern rtx gen_ashlv8qi3_signed (rtx, rtx, rtx);
extern rtx gen_ashlv16qi3_signed (rtx, rtx, rtx);
extern rtx gen_ashlv4hi3_signed (rtx, rtx, rtx);
extern rtx gen_ashlv8hi3_signed (rtx, rtx, rtx);
extern rtx gen_ashlv2si3_signed (rtx, rtx, rtx);
extern rtx gen_ashlv4si3_signed (rtx, rtx, rtx);
extern rtx gen_ashlv2di3_signed (rtx, rtx, rtx);
extern rtx gen_ashlv8qi3_unsigned (rtx, rtx, rtx);
extern rtx gen_ashlv16qi3_unsigned (rtx, rtx, rtx);
extern rtx gen_ashlv4hi3_unsigned (rtx, rtx, rtx);
extern rtx gen_ashlv8hi3_unsigned (rtx, rtx, rtx);
extern rtx gen_ashlv2si3_unsigned (rtx, rtx, rtx);
extern rtx gen_ashlv4si3_unsigned (rtx, rtx, rtx);
extern rtx gen_ashlv2di3_unsigned (rtx, rtx, rtx);
extern rtx gen_widen_ssumv8qi3 (rtx, rtx, rtx);
extern rtx gen_widen_ssumv4hi3 (rtx, rtx, rtx);
extern rtx gen_widen_ssumv2si3 (rtx, rtx, rtx);
extern rtx gen_widen_usumv8qi3 (rtx, rtx, rtx);
extern rtx gen_widen_usumv4hi3 (rtx, rtx, rtx);
extern rtx gen_widen_usumv2si3 (rtx, rtx, rtx);
extern rtx gen_quad_halves_plusv4si (rtx, rtx);
extern rtx gen_quad_halves_sminv4si (rtx, rtx);
extern rtx gen_quad_halves_smaxv4si (rtx, rtx);
extern rtx gen_quad_halves_uminv4si (rtx, rtx);
extern rtx gen_quad_halves_umaxv4si (rtx, rtx);
extern rtx gen_quad_halves_plusv4sf (rtx, rtx);
extern rtx gen_quad_halves_sminv4sf (rtx, rtx);
extern rtx gen_quad_halves_smaxv4sf (rtx, rtx);
extern rtx gen_quad_halves_plusv8hi (rtx, rtx);
extern rtx gen_quad_halves_sminv8hi (rtx, rtx);
extern rtx gen_quad_halves_smaxv8hi (rtx, rtx);
extern rtx gen_quad_halves_uminv8hi (rtx, rtx);
extern rtx gen_quad_halves_umaxv8hi (rtx, rtx);
extern rtx gen_quad_halves_plusv16qi (rtx, rtx);
extern rtx gen_quad_halves_sminv16qi (rtx, rtx);
extern rtx gen_quad_halves_smaxv16qi (rtx, rtx);
extern rtx gen_quad_halves_uminv16qi (rtx, rtx);
extern rtx gen_quad_halves_umaxv16qi (rtx, rtx);
extern rtx gen_reduc_splus_v2di (rtx, rtx);
extern rtx gen_neon_vpadd_internalv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vpadd_internalv4hi (rtx, rtx, rtx);
extern rtx gen_neon_vpadd_internalv2si (rtx, rtx, rtx);
extern rtx gen_neon_vpadd_internalv2sf (rtx, rtx, rtx);
extern rtx gen_neon_vpsminv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vpsminv4hi (rtx, rtx, rtx);
extern rtx gen_neon_vpsminv2si (rtx, rtx, rtx);
extern rtx gen_neon_vpsminv2sf (rtx, rtx, rtx);
extern rtx gen_neon_vpsmaxv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vpsmaxv4hi (rtx, rtx, rtx);
extern rtx gen_neon_vpsmaxv2si (rtx, rtx, rtx);
extern rtx gen_neon_vpsmaxv2sf (rtx, rtx, rtx);
extern rtx gen_neon_vpuminv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vpuminv4hi (rtx, rtx, rtx);
extern rtx gen_neon_vpuminv2si (rtx, rtx, rtx);
extern rtx gen_neon_vpumaxv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vpumaxv4hi (rtx, rtx, rtx);
extern rtx gen_neon_vpumaxv2si (rtx, rtx, rtx);
extern rtx gen_neon_vaddv8qi_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vaddv16qi_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vaddv4hi_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vaddv8hi_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vaddv2si_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vaddv4si_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vaddv2sf_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vaddv4sf_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vadddi_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vaddv2di_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vaddlv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vaddlv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vaddlv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vaddwv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vaddwv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vaddwv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vhaddv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vhaddv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vhaddv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vhaddv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vhaddv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vhaddv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqaddv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqaddv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqaddv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqaddv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqaddv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqaddv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqadddi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqaddv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vaddhnv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vaddhnv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vaddhnv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmulv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmulv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmulv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmulv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmulv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmulv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmulv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmulv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlav8qi_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlav16qi_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlav4hi_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlav8hi_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlav2si_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlav4si_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlav2sf_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlav4sf_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlav2di_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlalv8qi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlalv4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlalv2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsv8qi_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsv16qi_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsv4hi_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsv8hi_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsv2si_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsv4si_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsv2sf_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsv4sf_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsv2di_unspec (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlslv8qi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlslv4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlslv2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmulhv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmulhv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmulhv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmulhv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmlalv4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmlalv2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmlslv4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmlslv2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmullv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmullv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmullv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmullv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmullv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsubv8qi_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vsubv16qi_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vsubv4hi_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vsubv8hi_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vsubv2si_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vsubv4si_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vsubv2sf_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vsubv4sf_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vsubdi_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vsubv2di_unspec (rtx, rtx, rtx);
extern rtx gen_neon_vsublv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsublv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsublv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsubwv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsubwv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsubwv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqsubv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqsubv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqsubv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqsubv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqsubv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqsubv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqsubdi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqsubv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vhsubv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vhsubv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vhsubv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vhsubv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vhsubv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vhsubv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsubhnv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsubhnv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsubhnv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vceqv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vceqv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vceqv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vceqv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vceqv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vceqv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vceqv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vceqv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgev8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgev16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgev4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgev8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgev2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgev4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgev2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgev4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgeuv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgeuv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgeuv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgeuv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgeuv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgeuv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgtv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgtv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgtv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgtv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgtv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgtv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgtv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgtv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgtuv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgtuv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgtuv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgtuv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgtuv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcgtuv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vclev8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vclev16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vclev4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vclev8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vclev2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vclev4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vclev2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vclev4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcltv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcltv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcltv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcltv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcltv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcltv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcltv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcltv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcagev2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcagev4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcagtv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcagtv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtstv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtstv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtstv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtstv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtstv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtstv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabdv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabdv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabdv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabdv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabdv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabdv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabdv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabdv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabdlv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabdlv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabdlv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabav8qi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabav16qi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabav4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabav8hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabav2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabav4si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabalv8qi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabalv4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabalv2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmaxv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmaxv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmaxv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmaxv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmaxv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmaxv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmaxv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmaxv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vminv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vminv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vminv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vminv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vminv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vminv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vminv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vminv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpaddlv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vpaddlv16qi (rtx, rtx, rtx);
extern rtx gen_neon_vpaddlv4hi (rtx, rtx, rtx);
extern rtx gen_neon_vpaddlv8hi (rtx, rtx, rtx);
extern rtx gen_neon_vpaddlv2si (rtx, rtx, rtx);
extern rtx gen_neon_vpaddlv4si (rtx, rtx, rtx);
extern rtx gen_neon_vpadalv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpadalv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpadalv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpadalv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpadalv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpadalv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpmaxv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpmaxv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpmaxv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpmaxv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpminv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpminv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpminv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpminv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vrecpsv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vrecpsv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vrsqrtsv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vrsqrtsv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqabsv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vqabsv16qi (rtx, rtx, rtx);
extern rtx gen_neon_vqabsv4hi (rtx, rtx, rtx);
extern rtx gen_neon_vqabsv8hi (rtx, rtx, rtx);
extern rtx gen_neon_vqabsv2si (rtx, rtx, rtx);
extern rtx gen_neon_vqabsv4si (rtx, rtx, rtx);
extern rtx gen_neon_vqnegv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vqnegv16qi (rtx, rtx, rtx);
extern rtx gen_neon_vqnegv4hi (rtx, rtx, rtx);
extern rtx gen_neon_vqnegv8hi (rtx, rtx, rtx);
extern rtx gen_neon_vqnegv2si (rtx, rtx, rtx);
extern rtx gen_neon_vqnegv4si (rtx, rtx, rtx);
extern rtx gen_neon_vclsv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vclsv16qi (rtx, rtx, rtx);
extern rtx gen_neon_vclsv4hi (rtx, rtx, rtx);
extern rtx gen_neon_vclsv8hi (rtx, rtx, rtx);
extern rtx gen_neon_vclsv2si (rtx, rtx, rtx);
extern rtx gen_neon_vclsv4si (rtx, rtx, rtx);
extern rtx gen_clzv8qi2 (rtx, rtx);
extern rtx gen_clzv16qi2 (rtx, rtx);
extern rtx gen_clzv4hi2 (rtx, rtx);
extern rtx gen_clzv8hi2 (rtx, rtx);
extern rtx gen_clzv2si2 (rtx, rtx);
extern rtx gen_clzv4si2 (rtx, rtx);
extern rtx gen_popcountv8qi2 (rtx, rtx);
extern rtx gen_popcountv16qi2 (rtx, rtx);
extern rtx gen_neon_vrecpev2si (rtx, rtx, rtx);
extern rtx gen_neon_vrecpev2sf (rtx, rtx, rtx);
extern rtx gen_neon_vrecpev4si (rtx, rtx, rtx);
extern rtx gen_neon_vrecpev4sf (rtx, rtx, rtx);
extern rtx gen_neon_vrsqrtev2si (rtx, rtx, rtx);
extern rtx gen_neon_vrsqrtev2sf (rtx, rtx, rtx);
extern rtx gen_neon_vrsqrtev4si (rtx, rtx, rtx);
extern rtx gen_neon_vrsqrtev4sf (rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev8qi_sext_internal (rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev4hi_sext_internal (rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev2si_sext_internal (rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev2sf_sext_internal (rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev8qi_zext_internal (rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev4hi_zext_internal (rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev2si_zext_internal (rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev2sf_zext_internal (rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev16qi_sext_internal (rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev8hi_sext_internal (rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev4si_sext_internal (rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev4sf_sext_internal (rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev16qi_zext_internal (rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev8hi_zext_internal (rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev4si_zext_internal (rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev4sf_zext_internal (rtx, rtx, rtx);
extern rtx gen_neon_vdup_nv8qi (rtx, rtx);
extern rtx gen_neon_vdup_nv4hi (rtx, rtx);
extern rtx gen_neon_vdup_nv16qi (rtx, rtx);
extern rtx gen_neon_vdup_nv8hi (rtx, rtx);
extern rtx gen_neon_vdup_nv2si (rtx, rtx);
extern rtx gen_neon_vdup_nv2sf (rtx, rtx);
extern rtx gen_neon_vdup_nv4si (rtx, rtx);
extern rtx gen_neon_vdup_nv4sf (rtx, rtx);
extern rtx gen_neon_vdup_nv2di (rtx, rtx);
extern rtx gen_neon_vdup_lanev8qi_internal (rtx, rtx, rtx);
extern rtx gen_neon_vdup_lanev16qi_internal (rtx, rtx, rtx);
extern rtx gen_neon_vdup_lanev4hi_internal (rtx, rtx, rtx);
extern rtx gen_neon_vdup_lanev8hi_internal (rtx, rtx, rtx);
extern rtx gen_neon_vdup_lanev2si_internal (rtx, rtx, rtx);
extern rtx gen_neon_vdup_lanev4si_internal (rtx, rtx, rtx);
extern rtx gen_neon_vdup_lanev2sf_internal (rtx, rtx, rtx);
extern rtx gen_neon_vdup_lanev4sf_internal (rtx, rtx, rtx);
extern rtx gen_neon_vcombinev8qi (rtx, rtx, rtx);
extern rtx gen_neon_vcombinev4hi (rtx, rtx, rtx);
extern rtx gen_neon_vcombinev2si (rtx, rtx, rtx);
extern rtx gen_neon_vcombinev2sf (rtx, rtx, rtx);
extern rtx gen_neon_vcombinedi (rtx, rtx, rtx);
extern rtx gen_floatv2siv2sf2 (rtx, rtx);
extern rtx gen_floatv4siv4sf2 (rtx, rtx);
extern rtx gen_floatunsv2siv2sf2 (rtx, rtx);
extern rtx gen_floatunsv4siv4sf2 (rtx, rtx);
extern rtx gen_fix_truncv2sfv2si2 (rtx, rtx);
extern rtx gen_fix_truncv4sfv4si2 (rtx, rtx);
extern rtx gen_fixuns_truncv2sfv2si2 (rtx, rtx);
extern rtx gen_fixuns_truncv4sfv4si2 (rtx, rtx);
extern rtx gen_neon_vcvtv2sf (rtx, rtx, rtx);
extern rtx gen_neon_vcvtv4sf (rtx, rtx, rtx);
extern rtx gen_neon_vcvtv2si (rtx, rtx, rtx);
extern rtx gen_neon_vcvtv4si (rtx, rtx, rtx);
extern rtx gen_neon_vcvt_nv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcvt_nv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcvt_nv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcvt_nv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmovnv8hi (rtx, rtx, rtx);
extern rtx gen_neon_vmovnv4si (rtx, rtx, rtx);
extern rtx gen_neon_vmovnv2di (rtx, rtx, rtx);
extern rtx gen_neon_vqmovnv8hi (rtx, rtx, rtx);
extern rtx gen_neon_vqmovnv4si (rtx, rtx, rtx);
extern rtx gen_neon_vqmovnv2di (rtx, rtx, rtx);
extern rtx gen_neon_vqmovunv8hi (rtx, rtx, rtx);
extern rtx gen_neon_vqmovunv4si (rtx, rtx, rtx);
extern rtx gen_neon_vqmovunv2di (rtx, rtx, rtx);
extern rtx gen_neon_vmovlv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vmovlv4hi (rtx, rtx, rtx);
extern rtx gen_neon_vmovlv2si (rtx, rtx, rtx);
extern rtx gen_neon_vmul_lanev4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmul_lanev2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmul_lanev2sf (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmul_lanev8hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmul_lanev4si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmul_lanev4sf (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmull_lanev4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmull_lanev2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmull_lanev4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmull_lanev2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmulh_lanev8hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmulh_lanev4si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmulh_lanev4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmulh_lanev2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmla_lanev4hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmla_lanev2si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmla_lanev2sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmla_lanev8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmla_lanev4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmla_lanev4sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlal_lanev4hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlal_lanev2si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmlal_lanev4hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmlal_lanev2si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmls_lanev4hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmls_lanev2si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmls_lanev2sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmls_lanev8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmls_lanev4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmls_lanev4sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsl_lanev4hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsl_lanev2si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmlsl_lanev4hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmlsl_lanev2si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vextv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vextv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vextv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vextv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vextv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vextv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vextv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vextv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vextdi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vextv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vrev64v8qi (rtx, rtx, rtx);
extern rtx gen_neon_vrev64v16qi (rtx, rtx, rtx);
extern rtx gen_neon_vrev64v4hi (rtx, rtx, rtx);
extern rtx gen_neon_vrev64v8hi (rtx, rtx, rtx);
extern rtx gen_neon_vrev64v2si (rtx, rtx, rtx);
extern rtx gen_neon_vrev64v4si (rtx, rtx, rtx);
extern rtx gen_neon_vrev64v2sf (rtx, rtx, rtx);
extern rtx gen_neon_vrev64v4sf (rtx, rtx, rtx);
extern rtx gen_neon_vrev64v2di (rtx, rtx, rtx);
extern rtx gen_neon_vrev32v8qi (rtx, rtx, rtx);
extern rtx gen_neon_vrev32v4hi (rtx, rtx, rtx);
extern rtx gen_neon_vrev32v16qi (rtx, rtx, rtx);
extern rtx gen_neon_vrev32v8hi (rtx, rtx, rtx);
extern rtx gen_neon_vrev16v8qi (rtx, rtx, rtx);
extern rtx gen_neon_vrev16v16qi (rtx, rtx, rtx);
extern rtx gen_neon_vbslv8qi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbslv16qi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbslv4hi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbslv8hi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbslv2si_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbslv4si_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbslv2sf_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbslv4sf_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbsldi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbslv2di_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshlv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshlv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshlv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshlv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshlv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshlv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshldi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshlv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshlv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshlv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshlv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshlv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshlv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshlv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshldi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshlv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshr_nv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshr_nv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshr_nv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshr_nv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshr_nv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshr_nv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshr_ndi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshr_nv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshrn_nv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshrn_nv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshrn_nv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshrn_nv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshrn_nv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshrn_nv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshrun_nv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshrun_nv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshrun_nv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshl_nv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshl_nv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshl_nv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshl_nv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshl_nv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshl_nv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshl_ndi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshl_nv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshl_nv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshl_nv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshl_nv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshl_nv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshl_nv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshl_nv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshl_ndi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshl_nv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshlu_nv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshlu_nv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshlu_nv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshlu_nv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshlu_nv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshlu_nv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshlu_ndi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqshlu_nv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshll_nv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshll_nv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vshll_nv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsra_nv8qi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsra_nv16qi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsra_nv4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsra_nv8hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsra_nv2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsra_nv4si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsra_ndi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsra_nv2di (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsri_nv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsri_nv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsri_nv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsri_nv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsri_nv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsri_nv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsri_ndi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsri_nv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsli_nv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsli_nv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsli_nv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsli_nv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsli_nv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsli_nv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsli_ndi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsli_nv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtbl1v8qi (rtx, rtx, rtx);
extern rtx gen_neon_vtbl2v8qi (rtx, rtx, rtx);
extern rtx gen_neon_vtbl3v8qi (rtx, rtx, rtx);
extern rtx gen_neon_vtbl4v8qi (rtx, rtx, rtx);
extern rtx gen_neon_vtbl1v16qi (rtx, rtx, rtx);
extern rtx gen_neon_vtbl2v16qi (rtx, rtx, rtx);
extern rtx gen_neon_vcombinev16qi (rtx, rtx, rtx);
extern rtx gen_neon_vtbx1v8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtbx2v8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtbx3v8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtbx4v8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtrnv8qi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtrnv16qi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtrnv4hi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtrnv8hi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtrnv2si_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtrnv4si_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtrnv2sf_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtrnv4sf_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vzipv8qi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vzipv16qi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vzipv4hi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vzipv8hi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vzipv2si_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vzipv4si_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vzipv2sf_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vzipv4sf_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vuzpv8qi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vuzpv16qi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vuzpv4hi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vuzpv8hi_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vuzpv2si_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vuzpv4si_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vuzpv2sf_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vuzpv4sf_internal (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld1v8qi (rtx, rtx);
extern rtx gen_neon_vld1v16qi (rtx, rtx);
extern rtx gen_neon_vld1v4hi (rtx, rtx);
extern rtx gen_neon_vld1v8hi (rtx, rtx);
extern rtx gen_neon_vld1v2si (rtx, rtx);
extern rtx gen_neon_vld1v4si (rtx, rtx);
extern rtx gen_neon_vld1v2sf (rtx, rtx);
extern rtx gen_neon_vld1v4sf (rtx, rtx);
extern rtx gen_neon_vld1di (rtx, rtx);
extern rtx gen_neon_vld1v2di (rtx, rtx);
extern rtx gen_neon_vld1_lanev8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld1_lanev4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld1_lanev2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld1_lanev2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld1_lanedi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld1_lanev16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld1_lanev8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld1_lanev4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld1_lanev4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld1_lanev2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld1_dupv8qi (rtx, rtx);
extern rtx gen_neon_vld1_dupv4hi (rtx, rtx);
extern rtx gen_neon_vld1_dupv2si (rtx, rtx);
extern rtx gen_neon_vld1_dupv2sf (rtx, rtx);
extern rtx gen_neon_vld1_dupdi (rtx, rtx);
extern rtx gen_neon_vld1_dupv16qi (rtx, rtx);
extern rtx gen_neon_vld1_dupv8hi (rtx, rtx);
extern rtx gen_neon_vld1_dupv4si (rtx, rtx);
extern rtx gen_neon_vld1_dupv4sf (rtx, rtx);
extern rtx gen_neon_vld1_dupv2di (rtx, rtx);
extern rtx gen_neon_vst1v8qi (rtx, rtx);
extern rtx gen_neon_vst1v16qi (rtx, rtx);
extern rtx gen_neon_vst1v4hi (rtx, rtx);
extern rtx gen_neon_vst1v8hi (rtx, rtx);
extern rtx gen_neon_vst1v2si (rtx, rtx);
extern rtx gen_neon_vst1v4si (rtx, rtx);
extern rtx gen_neon_vst1v2sf (rtx, rtx);
extern rtx gen_neon_vst1v4sf (rtx, rtx);
extern rtx gen_neon_vst1di (rtx, rtx);
extern rtx gen_neon_vst1v2di (rtx, rtx);
extern rtx gen_neon_vst1_lanev8qi (rtx, rtx, rtx);
extern rtx gen_neon_vst1_lanev4hi (rtx, rtx, rtx);
extern rtx gen_neon_vst1_lanev2si (rtx, rtx, rtx);
extern rtx gen_neon_vst1_lanev2sf (rtx, rtx, rtx);
extern rtx gen_neon_vst1_lanedi (rtx, rtx, rtx);
extern rtx gen_neon_vst1_lanev16qi (rtx, rtx, rtx);
extern rtx gen_neon_vst1_lanev8hi (rtx, rtx, rtx);
extern rtx gen_neon_vst1_lanev4si (rtx, rtx, rtx);
extern rtx gen_neon_vst1_lanev4sf (rtx, rtx, rtx);
extern rtx gen_neon_vst1_lanev2di (rtx, rtx, rtx);
extern rtx gen_neon_vld2v8qi (rtx, rtx);
extern rtx gen_neon_vld2v4hi (rtx, rtx);
extern rtx gen_neon_vld2v2si (rtx, rtx);
extern rtx gen_neon_vld2v2sf (rtx, rtx);
extern rtx gen_neon_vld2di (rtx, rtx);
extern rtx gen_neon_vld2v16qi (rtx, rtx);
extern rtx gen_neon_vld2v8hi (rtx, rtx);
extern rtx gen_neon_vld2v4si (rtx, rtx);
extern rtx gen_neon_vld2v4sf (rtx, rtx);
extern rtx gen_neon_vld2_lanev8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld2_lanev4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld2_lanev2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld2_lanev2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld2_lanev8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld2_lanev4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld2_lanev4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld2_dupv8qi (rtx, rtx);
extern rtx gen_neon_vld2_dupv4hi (rtx, rtx);
extern rtx gen_neon_vld2_dupv2si (rtx, rtx);
extern rtx gen_neon_vld2_dupv2sf (rtx, rtx);
extern rtx gen_neon_vld2_dupdi (rtx, rtx);
extern rtx gen_neon_vst2v8qi (rtx, rtx);
extern rtx gen_neon_vst2v4hi (rtx, rtx);
extern rtx gen_neon_vst2v2si (rtx, rtx);
extern rtx gen_neon_vst2v2sf (rtx, rtx);
extern rtx gen_neon_vst2di (rtx, rtx);
extern rtx gen_neon_vst2v16qi (rtx, rtx);
extern rtx gen_neon_vst2v8hi (rtx, rtx);
extern rtx gen_neon_vst2v4si (rtx, rtx);
extern rtx gen_neon_vst2v4sf (rtx, rtx);
extern rtx gen_neon_vst2_lanev8qi (rtx, rtx, rtx);
extern rtx gen_neon_vst2_lanev4hi (rtx, rtx, rtx);
extern rtx gen_neon_vst2_lanev2si (rtx, rtx, rtx);
extern rtx gen_neon_vst2_lanev2sf (rtx, rtx, rtx);
extern rtx gen_neon_vst2_lanev8hi (rtx, rtx, rtx);
extern rtx gen_neon_vst2_lanev4si (rtx, rtx, rtx);
extern rtx gen_neon_vst2_lanev4sf (rtx, rtx, rtx);
extern rtx gen_neon_vld3v8qi (rtx, rtx);
extern rtx gen_neon_vld3v4hi (rtx, rtx);
extern rtx gen_neon_vld3v2si (rtx, rtx);
extern rtx gen_neon_vld3v2sf (rtx, rtx);
extern rtx gen_neon_vld3di (rtx, rtx);
extern rtx gen_neon_vld3qav16qi (rtx, rtx);
extern rtx gen_neon_vld3qav8hi (rtx, rtx);
extern rtx gen_neon_vld3qav4si (rtx, rtx);
extern rtx gen_neon_vld3qav4sf (rtx, rtx);
extern rtx gen_neon_vld3qbv16qi (rtx, rtx, rtx);
extern rtx gen_neon_vld3qbv8hi (rtx, rtx, rtx);
extern rtx gen_neon_vld3qbv4si (rtx, rtx, rtx);
extern rtx gen_neon_vld3qbv4sf (rtx, rtx, rtx);
extern rtx gen_neon_vld3_lanev8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld3_lanev4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld3_lanev2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld3_lanev2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld3_lanev8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld3_lanev4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld3_lanev4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld3_dupv8qi (rtx, rtx);
extern rtx gen_neon_vld3_dupv4hi (rtx, rtx);
extern rtx gen_neon_vld3_dupv2si (rtx, rtx);
extern rtx gen_neon_vld3_dupv2sf (rtx, rtx);
extern rtx gen_neon_vld3_dupdi (rtx, rtx);
extern rtx gen_neon_vst3v8qi (rtx, rtx);
extern rtx gen_neon_vst3v4hi (rtx, rtx);
extern rtx gen_neon_vst3v2si (rtx, rtx);
extern rtx gen_neon_vst3v2sf (rtx, rtx);
extern rtx gen_neon_vst3di (rtx, rtx);
extern rtx gen_neon_vst3qav16qi (rtx, rtx);
extern rtx gen_neon_vst3qav8hi (rtx, rtx);
extern rtx gen_neon_vst3qav4si (rtx, rtx);
extern rtx gen_neon_vst3qav4sf (rtx, rtx);
extern rtx gen_neon_vst3qbv16qi (rtx, rtx);
extern rtx gen_neon_vst3qbv8hi (rtx, rtx);
extern rtx gen_neon_vst3qbv4si (rtx, rtx);
extern rtx gen_neon_vst3qbv4sf (rtx, rtx);
extern rtx gen_neon_vst3_lanev8qi (rtx, rtx, rtx);
extern rtx gen_neon_vst3_lanev4hi (rtx, rtx, rtx);
extern rtx gen_neon_vst3_lanev2si (rtx, rtx, rtx);
extern rtx gen_neon_vst3_lanev2sf (rtx, rtx, rtx);
extern rtx gen_neon_vst3_lanev8hi (rtx, rtx, rtx);
extern rtx gen_neon_vst3_lanev4si (rtx, rtx, rtx);
extern rtx gen_neon_vst3_lanev4sf (rtx, rtx, rtx);
extern rtx gen_neon_vld4v8qi (rtx, rtx);
extern rtx gen_neon_vld4v4hi (rtx, rtx);
extern rtx gen_neon_vld4v2si (rtx, rtx);
extern rtx gen_neon_vld4v2sf (rtx, rtx);
extern rtx gen_neon_vld4di (rtx, rtx);
extern rtx gen_neon_vld4qav16qi (rtx, rtx);
extern rtx gen_neon_vld4qav8hi (rtx, rtx);
extern rtx gen_neon_vld4qav4si (rtx, rtx);
extern rtx gen_neon_vld4qav4sf (rtx, rtx);
extern rtx gen_neon_vld4qbv16qi (rtx, rtx, rtx);
extern rtx gen_neon_vld4qbv8hi (rtx, rtx, rtx);
extern rtx gen_neon_vld4qbv4si (rtx, rtx, rtx);
extern rtx gen_neon_vld4qbv4sf (rtx, rtx, rtx);
extern rtx gen_neon_vld4_lanev8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld4_lanev4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld4_lanev2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld4_lanev2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld4_lanev8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld4_lanev4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld4_lanev4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vld4_dupv8qi (rtx, rtx);
extern rtx gen_neon_vld4_dupv4hi (rtx, rtx);
extern rtx gen_neon_vld4_dupv2si (rtx, rtx);
extern rtx gen_neon_vld4_dupv2sf (rtx, rtx);
extern rtx gen_neon_vld4_dupdi (rtx, rtx);
extern rtx gen_neon_vst4v8qi (rtx, rtx);
extern rtx gen_neon_vst4v4hi (rtx, rtx);
extern rtx gen_neon_vst4v2si (rtx, rtx);
extern rtx gen_neon_vst4v2sf (rtx, rtx);
extern rtx gen_neon_vst4di (rtx, rtx);
extern rtx gen_neon_vst4qav16qi (rtx, rtx);
extern rtx gen_neon_vst4qav8hi (rtx, rtx);
extern rtx gen_neon_vst4qav4si (rtx, rtx);
extern rtx gen_neon_vst4qav4sf (rtx, rtx);
extern rtx gen_neon_vst4qbv16qi (rtx, rtx);
extern rtx gen_neon_vst4qbv8hi (rtx, rtx);
extern rtx gen_neon_vst4qbv4si (rtx, rtx);
extern rtx gen_neon_vst4qbv4sf (rtx, rtx);
extern rtx gen_neon_vst4_lanev8qi (rtx, rtx, rtx);
extern rtx gen_neon_vst4_lanev4hi (rtx, rtx, rtx);
extern rtx gen_neon_vst4_lanev2si (rtx, rtx, rtx);
extern rtx gen_neon_vst4_lanev2sf (rtx, rtx, rtx);
extern rtx gen_neon_vst4_lanev8hi (rtx, rtx, rtx);
extern rtx gen_neon_vst4_lanev4si (rtx, rtx, rtx);
extern rtx gen_neon_vst4_lanev4sf (rtx, rtx, rtx);
extern rtx gen_neon_vec_unpacks_lo_v16qi (rtx, rtx, rtx);
extern rtx gen_neon_vec_unpacku_lo_v16qi (rtx, rtx, rtx);
extern rtx gen_neon_vec_unpacks_lo_v8hi (rtx, rtx, rtx);
extern rtx gen_neon_vec_unpacku_lo_v8hi (rtx, rtx, rtx);
extern rtx gen_neon_vec_unpacks_lo_v4si (rtx, rtx, rtx);
extern rtx gen_neon_vec_unpacku_lo_v4si (rtx, rtx, rtx);
extern rtx gen_neon_vec_unpacks_hi_v16qi (rtx, rtx, rtx);
extern rtx gen_neon_vec_unpacku_hi_v16qi (rtx, rtx, rtx);
extern rtx gen_neon_vec_unpacks_hi_v8hi (rtx, rtx, rtx);
extern rtx gen_neon_vec_unpacku_hi_v8hi (rtx, rtx, rtx);
extern rtx gen_neon_vec_unpacks_hi_v4si (rtx, rtx, rtx);
extern rtx gen_neon_vec_unpacku_hi_v4si (rtx, rtx, rtx);
extern rtx gen_neon_vec_smult_lo_v16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vec_umult_lo_v16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vec_smult_lo_v8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vec_umult_lo_v8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vec_smult_lo_v4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vec_umult_lo_v4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vec_smult_hi_v16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vec_umult_hi_v16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vec_smult_hi_v8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vec_umult_hi_v8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vec_smult_hi_v4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vec_umult_hi_v4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vec_sshiftl_v8qi (rtx, rtx, rtx);
extern rtx gen_neon_vec_ushiftl_v8qi (rtx, rtx, rtx);
extern rtx gen_neon_vec_sshiftl_v4hi (rtx, rtx, rtx);
extern rtx gen_neon_vec_ushiftl_v4hi (rtx, rtx, rtx);
extern rtx gen_neon_vec_sshiftl_v2si (rtx, rtx, rtx);
extern rtx gen_neon_vec_ushiftl_v2si (rtx, rtx, rtx);
extern rtx gen_neon_unpacks_v8qi (rtx, rtx);
extern rtx gen_neon_unpacku_v8qi (rtx, rtx);
extern rtx gen_neon_unpacks_v4hi (rtx, rtx);
extern rtx gen_neon_unpacku_v4hi (rtx, rtx);
extern rtx gen_neon_unpacks_v2si (rtx, rtx);
extern rtx gen_neon_unpacku_v2si (rtx, rtx);
extern rtx gen_neon_vec_smult_v8qi (rtx, rtx, rtx);
extern rtx gen_neon_vec_umult_v8qi (rtx, rtx, rtx);
extern rtx gen_neon_vec_smult_v4hi (rtx, rtx, rtx);
extern rtx gen_neon_vec_umult_v4hi (rtx, rtx, rtx);
extern rtx gen_neon_vec_smult_v2si (rtx, rtx, rtx);
extern rtx gen_neon_vec_umult_v2si (rtx, rtx, rtx);
extern rtx gen_vec_pack_trunc_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_pack_trunc_v4si (rtx, rtx, rtx);
extern rtx gen_vec_pack_trunc_v2di (rtx, rtx, rtx);
extern rtx gen_neon_vec_pack_trunc_v8hi (rtx, rtx);
extern rtx gen_neon_vec_pack_trunc_v4si (rtx, rtx);
extern rtx gen_neon_vec_pack_trunc_v2di (rtx, rtx);
extern rtx gen_neon_vabdv8qi_2 (rtx, rtx, rtx);
extern rtx gen_neon_vabdv16qi_2 (rtx, rtx, rtx);
extern rtx gen_neon_vabdv4hi_2 (rtx, rtx, rtx);
extern rtx gen_neon_vabdv8hi_2 (rtx, rtx, rtx);
extern rtx gen_neon_vabdv2si_2 (rtx, rtx, rtx);
extern rtx gen_neon_vabdv4si_2 (rtx, rtx, rtx);
extern rtx gen_neon_vabdv2sf_2 (rtx, rtx, rtx);
extern rtx gen_neon_vabdv4sf_2 (rtx, rtx, rtx);
extern rtx gen_neon_vabdv2di_2 (rtx, rtx, rtx);
extern rtx gen_neon_vabdv8qi_3 (rtx, rtx, rtx);
extern rtx gen_neon_vabdv16qi_3 (rtx, rtx, rtx);
extern rtx gen_neon_vabdv4hi_3 (rtx, rtx, rtx);
extern rtx gen_neon_vabdv8hi_3 (rtx, rtx, rtx);
extern rtx gen_neon_vabdv2si_3 (rtx, rtx, rtx);
extern rtx gen_neon_vabdv4si_3 (rtx, rtx, rtx);
extern rtx gen_neon_vabdv2sf_3 (rtx, rtx, rtx);
extern rtx gen_neon_vabdv4sf_3 (rtx, rtx, rtx);
extern rtx gen_neon_vabdv2di_3 (rtx, rtx, rtx);
extern rtx gen_atomic_compare_and_swapqi_1 (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_atomic_compare_and_swaphi_1 (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_atomic_compare_and_swapsi_1 (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_atomic_compare_and_swapdi_1 (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_atomic_exchangeqi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_exchangehi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_exchangesi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_exchangedi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_addqi (rtx, rtx, rtx);
extern rtx gen_atomic_subqi (rtx, rtx, rtx);
extern rtx gen_atomic_orqi (rtx, rtx, rtx);
extern rtx gen_atomic_xorqi (rtx, rtx, rtx);
extern rtx gen_atomic_andqi (rtx, rtx, rtx);
extern rtx gen_atomic_addhi (rtx, rtx, rtx);
extern rtx gen_atomic_subhi (rtx, rtx, rtx);
extern rtx gen_atomic_orhi (rtx, rtx, rtx);
extern rtx gen_atomic_xorhi (rtx, rtx, rtx);
extern rtx gen_atomic_andhi (rtx, rtx, rtx);
extern rtx gen_atomic_addsi (rtx, rtx, rtx);
extern rtx gen_atomic_subsi (rtx, rtx, rtx);
extern rtx gen_atomic_orsi (rtx, rtx, rtx);
extern rtx gen_atomic_xorsi (rtx, rtx, rtx);
extern rtx gen_atomic_andsi (rtx, rtx, rtx);
extern rtx gen_atomic_adddi (rtx, rtx, rtx);
extern rtx gen_atomic_subdi (rtx, rtx, rtx);
extern rtx gen_atomic_ordi (rtx, rtx, rtx);
extern rtx gen_atomic_xordi (rtx, rtx, rtx);
extern rtx gen_atomic_anddi (rtx, rtx, rtx);
extern rtx gen_atomic_nandqi (rtx, rtx, rtx);
extern rtx gen_atomic_nandhi (rtx, rtx, rtx);
extern rtx gen_atomic_nandsi (rtx, rtx, rtx);
extern rtx gen_atomic_nanddi (rtx, rtx, rtx);
extern rtx gen_atomic_fetch_addqi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_subqi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_orqi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_xorqi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_andqi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_addhi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_subhi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_orhi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_xorhi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_andhi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_addsi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_subsi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_orsi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_xorsi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_andsi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_adddi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_subdi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_ordi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_xordi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_anddi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_nandqi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_nandhi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_nandsi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_nanddi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_add_fetchqi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_sub_fetchqi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_or_fetchqi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_xor_fetchqi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_and_fetchqi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_add_fetchhi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_sub_fetchhi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_or_fetchhi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_xor_fetchhi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_and_fetchhi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_add_fetchsi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_sub_fetchsi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_or_fetchsi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_xor_fetchsi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_and_fetchsi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_add_fetchdi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_sub_fetchdi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_or_fetchdi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_xor_fetchdi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_and_fetchdi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_nand_fetchqi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_nand_fetchhi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_nand_fetchsi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_nand_fetchdi (rtx, rtx, rtx, rtx);
extern rtx gen_arm_load_exclusiveqi (rtx, rtx);
extern rtx gen_arm_load_exclusivehi (rtx, rtx);
extern rtx gen_arm_load_exclusivesi (rtx, rtx);
extern rtx gen_arm_load_exclusivedi (rtx, rtx);
extern rtx gen_arm_store_exclusiveqi (rtx, rtx, rtx);
extern rtx gen_arm_store_exclusivehi (rtx, rtx, rtx);
extern rtx gen_arm_store_exclusivesi (rtx, rtx, rtx);
extern rtx gen_arm_store_exclusivedi (rtx, rtx, rtx);
extern rtx gen_addqq3 (rtx, rtx, rtx);
extern rtx gen_addhq3 (rtx, rtx, rtx);
extern rtx gen_addsq3 (rtx, rtx, rtx);
extern rtx gen_adduqq3 (rtx, rtx, rtx);
extern rtx gen_adduhq3 (rtx, rtx, rtx);
extern rtx gen_addusq3 (rtx, rtx, rtx);
extern rtx gen_addha3 (rtx, rtx, rtx);
extern rtx gen_addsa3 (rtx, rtx, rtx);
extern rtx gen_adduha3 (rtx, rtx, rtx);
extern rtx gen_addusa3 (rtx, rtx, rtx);
extern rtx gen_addv4qq3 (rtx, rtx, rtx);
extern rtx gen_addv2hq3 (rtx, rtx, rtx);
extern rtx gen_addv2ha3 (rtx, rtx, rtx);
extern rtx gen_usaddv4uqq3 (rtx, rtx, rtx);
extern rtx gen_usaddv2uhq3 (rtx, rtx, rtx);
extern rtx gen_usadduqq3 (rtx, rtx, rtx);
extern rtx gen_usadduhq3 (rtx, rtx, rtx);
extern rtx gen_usaddv2uha3 (rtx, rtx, rtx);
extern rtx gen_usadduha3 (rtx, rtx, rtx);
extern rtx gen_ssaddv4qq3 (rtx, rtx, rtx);
extern rtx gen_ssaddv2hq3 (rtx, rtx, rtx);
extern rtx gen_ssaddqq3 (rtx, rtx, rtx);
extern rtx gen_ssaddhq3 (rtx, rtx, rtx);
extern rtx gen_ssaddv2ha3 (rtx, rtx, rtx);
extern rtx gen_ssaddha3 (rtx, rtx, rtx);
extern rtx gen_ssaddsq3 (rtx, rtx, rtx);
extern rtx gen_ssaddsa3 (rtx, rtx, rtx);
extern rtx gen_subqq3 (rtx, rtx, rtx);
extern rtx gen_subhq3 (rtx, rtx, rtx);
extern rtx gen_subsq3 (rtx, rtx, rtx);
extern rtx gen_subuqq3 (rtx, rtx, rtx);
extern rtx gen_subuhq3 (rtx, rtx, rtx);
extern rtx gen_subusq3 (rtx, rtx, rtx);
extern rtx gen_subha3 (rtx, rtx, rtx);
extern rtx gen_subsa3 (rtx, rtx, rtx);
extern rtx gen_subuha3 (rtx, rtx, rtx);
extern rtx gen_subusa3 (rtx, rtx, rtx);
extern rtx gen_subv4qq3 (rtx, rtx, rtx);
extern rtx gen_subv2hq3 (rtx, rtx, rtx);
extern rtx gen_subv2ha3 (rtx, rtx, rtx);
extern rtx gen_ussubv4uqq3 (rtx, rtx, rtx);
extern rtx gen_ussubv2uhq3 (rtx, rtx, rtx);
extern rtx gen_ussubuqq3 (rtx, rtx, rtx);
extern rtx gen_ussubuhq3 (rtx, rtx, rtx);
extern rtx gen_ussubv2uha3 (rtx, rtx, rtx);
extern rtx gen_ussubuha3 (rtx, rtx, rtx);
extern rtx gen_sssubv4qq3 (rtx, rtx, rtx);
extern rtx gen_sssubv2hq3 (rtx, rtx, rtx);
extern rtx gen_sssubqq3 (rtx, rtx, rtx);
extern rtx gen_sssubhq3 (rtx, rtx, rtx);
extern rtx gen_sssubv2ha3 (rtx, rtx, rtx);
extern rtx gen_sssubha3 (rtx, rtx, rtx);
extern rtx gen_sssubsq3 (rtx, rtx, rtx);
extern rtx gen_sssubsa3 (rtx, rtx, rtx);
extern rtx gen_ssmulsa3 (rtx, rtx, rtx);
extern rtx gen_usmulusa3 (rtx, rtx, rtx);
extern rtx gen_arm_ssatsihi_shift (rtx, rtx, rtx, rtx);
extern rtx gen_arm_usatsihi (rtx, rtx);
extern rtx gen_adddi3 (rtx, rtx, rtx);
extern rtx gen_addsi3 (rtx, rtx, rtx);
extern rtx gen_incscc (rtx, rtx, rtx, rtx);
extern rtx gen_addsf3 (rtx, rtx, rtx);
extern rtx gen_adddf3 (rtx, rtx, rtx);
extern rtx gen_subdi3 (rtx, rtx, rtx);
extern rtx gen_subsi3 (rtx, rtx, rtx);
extern rtx gen_decscc (rtx, rtx, rtx, rtx);
extern rtx gen_subsf3 (rtx, rtx, rtx);
extern rtx gen_subdf3 (rtx, rtx, rtx);
extern rtx gen_mulsi3 (rtx, rtx, rtx);
extern rtx gen_maddsidi4 (rtx, rtx, rtx, rtx);
extern rtx gen_mulsidi3 (rtx, rtx, rtx);
extern rtx gen_umulsidi3 (rtx, rtx, rtx);
extern rtx gen_umaddsidi4 (rtx, rtx, rtx, rtx);
extern rtx gen_smulsi3_highpart (rtx, rtx, rtx);
extern rtx gen_umulsi3_highpart (rtx, rtx, rtx);
extern rtx gen_mulsf3 (rtx, rtx, rtx);
extern rtx gen_muldf3 (rtx, rtx, rtx);
extern rtx gen_divsf3 (rtx, rtx, rtx);
extern rtx gen_divdf3 (rtx, rtx, rtx);
extern rtx gen_modsf3 (rtx, rtx, rtx);
extern rtx gen_moddf3 (rtx, rtx, rtx);
extern rtx gen_anddi3 (rtx, rtx, rtx);
extern rtx gen_andsi3 (rtx, rtx, rtx);
extern rtx gen_insv (rtx, rtx, rtx, rtx);
extern rtx gen_iordi3 (rtx, rtx, rtx);
extern rtx gen_iorsi3 (rtx, rtx, rtx);
extern rtx gen_xordi3 (rtx, rtx, rtx);
extern rtx gen_xorsi3 (rtx, rtx, rtx);
extern rtx gen_smaxsi3 (rtx, rtx, rtx);
extern rtx gen_sminsi3 (rtx, rtx, rtx);
extern rtx gen_umaxsi3 (rtx, rtx, rtx);
extern rtx gen_uminsi3 (rtx, rtx, rtx);
extern rtx gen_ashldi3 (rtx, rtx, rtx);
extern rtx gen_ashlsi3 (rtx, rtx, rtx);
extern rtx gen_ashrdi3 (rtx, rtx, rtx);
extern rtx gen_ashrsi3 (rtx, rtx, rtx);
extern rtx gen_lshrdi3 (rtx, rtx, rtx);
extern rtx gen_lshrsi3 (rtx, rtx, rtx);
extern rtx gen_rotlsi3 (rtx, rtx, rtx);
extern rtx gen_rotrsi3 (rtx, rtx, rtx);
extern rtx gen_extzv (rtx, rtx, rtx, rtx);
extern rtx gen_extzv_t1 (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_extv (rtx, rtx, rtx, rtx);
extern rtx gen_extv_regsi (rtx, rtx, rtx, rtx);
extern rtx gen_negdi2 (rtx, rtx);
extern rtx gen_negsi2 (rtx, rtx);
extern rtx gen_negsf2 (rtx, rtx);
extern rtx gen_negdf2 (rtx, rtx);
extern rtx gen_abssi2 (rtx, rtx);
extern rtx gen_abssf2 (rtx, rtx);
extern rtx gen_absdf2 (rtx, rtx);
extern rtx gen_sqrtsf2 (rtx, rtx);
extern rtx gen_sqrtdf2 (rtx, rtx);
extern rtx gen_one_cmplsi2 (rtx, rtx);
extern rtx gen_floatsihf2 (rtx, rtx);
extern rtx gen_floatdihf2 (rtx, rtx);
extern rtx gen_floatsisf2 (rtx, rtx);
extern rtx gen_floatsidf2 (rtx, rtx);
extern rtx gen_fix_trunchfsi2 (rtx, rtx);
extern rtx gen_fix_trunchfdi2 (rtx, rtx);
extern rtx gen_fix_truncsfsi2 (rtx, rtx);
extern rtx gen_fix_truncdfsi2 (rtx, rtx);
extern rtx gen_truncdfsf2 (rtx, rtx);
extern rtx gen_truncdfhf2 (rtx, rtx);
extern rtx gen_zero_extendhisi2 (rtx, rtx);
extern rtx gen_zero_extendqisi2 (rtx, rtx);
extern rtx gen_extendhisi2 (rtx, rtx);
extern rtx gen_extendhisi2_mem (rtx, rtx);
extern rtx gen_extendqihi2 (rtx, rtx);
extern rtx gen_extendqisi2 (rtx, rtx);
extern rtx gen_extendsfdf2 (rtx, rtx);
extern rtx gen_extendhfdf2 (rtx, rtx);
extern rtx gen_movdi (rtx, rtx);
extern rtx gen_movsi (rtx, rtx);
extern rtx gen_calculate_pic_address (rtx, rtx, rtx);
extern rtx gen_builtin_setjmp_receiver (rtx);
extern rtx gen_storehi (rtx, rtx);
extern rtx gen_storehi_bigend (rtx, rtx);
extern rtx gen_storeinthi (rtx, rtx);
extern rtx gen_storehi_single_op (rtx, rtx);
extern rtx gen_movhi (rtx, rtx);
extern rtx gen_movhi_bytes (rtx, rtx);
extern rtx gen_movhi_bigend (rtx, rtx);
extern rtx gen_thumb_movhi_clobber (rtx, rtx, rtx);
extern rtx gen_reload_outhi (rtx, rtx, rtx);
extern rtx gen_reload_inhi (rtx, rtx, rtx);
extern rtx gen_movqi (rtx, rtx);
extern rtx gen_movhf (rtx, rtx);
extern rtx gen_movsf (rtx, rtx);
extern rtx gen_movdf (rtx, rtx);
extern rtx gen_reload_outdf (rtx, rtx, rtx);
extern rtx gen_movxf (rtx, rtx);
extern rtx gen_load_multiple (rtx, rtx, rtx);
extern rtx gen_store_multiple (rtx, rtx, rtx);
extern rtx gen_movmemqi (rtx, rtx, rtx, rtx);
extern rtx gen_cbranchsi4 (rtx, rtx, rtx, rtx);
extern rtx gen_cbranchqi4 (rtx, rtx, rtx, rtx);
extern rtx gen_cbranchsf4 (rtx, rtx, rtx, rtx);
extern rtx gen_cbranchdf4 (rtx, rtx, rtx, rtx);
extern rtx gen_cbranchdi4 (rtx, rtx, rtx, rtx);
extern rtx gen_cbranch_cc (rtx, rtx, rtx, rtx);
extern rtx gen_cstore_cc (rtx, rtx, rtx, rtx);
extern rtx gen_cstoresi4 (rtx, rtx, rtx, rtx);
extern rtx gen_cstoresf4 (rtx, rtx, rtx, rtx);
extern rtx gen_cstoredf4 (rtx, rtx, rtx, rtx);
extern rtx gen_cstoredi4 (rtx, rtx, rtx, rtx);
extern rtx gen_cstoresi_eq0_thumb1 (rtx, rtx);
extern rtx gen_cstoresi_ne0_thumb1 (rtx, rtx);
extern rtx gen_movsicc (rtx, rtx, rtx, rtx);
extern rtx gen_movsfcc (rtx, rtx, rtx, rtx);
extern rtx gen_movdfcc (rtx, rtx, rtx, rtx);
extern rtx gen_jump (rtx);
extern rtx gen_call (rtx, rtx, rtx);
extern rtx gen_call_internal (rtx, rtx, rtx);
extern rtx gen_call_value (rtx, rtx, rtx, rtx);
extern rtx gen_call_value_internal (rtx, rtx, rtx, rtx);
extern rtx gen_sibcall (rtx, rtx, rtx);
extern rtx gen_sibcall_value (rtx, rtx, rtx, rtx);
extern rtx gen_return (void);
extern rtx gen_return_addr_mask (rtx);
extern rtx gen_untyped_call (rtx, rtx, rtx);
extern rtx gen_untyped_return (rtx, rtx);
extern rtx gen_casesi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_thumb1_casesi_internal_pic (rtx, rtx, rtx, rtx);
extern rtx gen_indirect_jump (rtx);
extern rtx gen_prologue (void);
extern rtx gen_epilogue (void);
extern rtx gen_eh_epilogue (rtx, rtx, rtx);
extern rtx gen_tablejump (rtx, rtx);
extern rtx gen_ctzsi2 (rtx, rtx);
extern rtx gen_eh_return (rtx);
extern rtx gen_arm_legacy_rev (rtx, rtx, rtx, rtx);
extern rtx gen_thumb_legacy_rev (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_bswapsi2 (rtx, rtx);
extern rtx gen_movv2di (rtx, rtx);
extern rtx gen_movv2si (rtx, rtx);
extern rtx gen_movv4hi (rtx, rtx);
extern rtx gen_movv8qi (rtx, rtx);
extern rtx gen_movv2sf (rtx, rtx);
extern rtx gen_movv4si (rtx, rtx);
extern rtx gen_movv8hi (rtx, rtx);
extern rtx gen_movv16qi (rtx, rtx);
extern rtx gen_movv4sf (rtx, rtx);
extern rtx gen_addv2di3 (rtx, rtx, rtx);
extern rtx gen_addv2si3 (rtx, rtx, rtx);
extern rtx gen_addv4hi3 (rtx, rtx, rtx);
extern rtx gen_addv8qi3 (rtx, rtx, rtx);
extern rtx gen_addv2sf3 (rtx, rtx, rtx);
extern rtx gen_addv4si3 (rtx, rtx, rtx);
extern rtx gen_addv8hi3 (rtx, rtx, rtx);
extern rtx gen_addv16qi3 (rtx, rtx, rtx);
extern rtx gen_addv4sf3 (rtx, rtx, rtx);
extern rtx gen_subv2di3 (rtx, rtx, rtx);
extern rtx gen_subv2si3 (rtx, rtx, rtx);
extern rtx gen_subv4hi3 (rtx, rtx, rtx);
extern rtx gen_subv8qi3 (rtx, rtx, rtx);
extern rtx gen_subv2sf3 (rtx, rtx, rtx);
extern rtx gen_subv4si3 (rtx, rtx, rtx);
extern rtx gen_subv8hi3 (rtx, rtx, rtx);
extern rtx gen_subv16qi3 (rtx, rtx, rtx);
extern rtx gen_subv4sf3 (rtx, rtx, rtx);
extern rtx gen_mulv2si3 (rtx, rtx, rtx);
extern rtx gen_mulv4hi3 (rtx, rtx, rtx);
extern rtx gen_mulv8qi3 (rtx, rtx, rtx);
extern rtx gen_mulv2sf3 (rtx, rtx, rtx);
extern rtx gen_mulv4si3 (rtx, rtx, rtx);
extern rtx gen_mulv8hi3 (rtx, rtx, rtx);
extern rtx gen_mulv16qi3 (rtx, rtx, rtx);
extern rtx gen_mulv4sf3 (rtx, rtx, rtx);
extern rtx gen_sminv2si3 (rtx, rtx, rtx);
extern rtx gen_sminv4hi3 (rtx, rtx, rtx);
extern rtx gen_sminv8qi3 (rtx, rtx, rtx);
extern rtx gen_sminv2sf3 (rtx, rtx, rtx);
extern rtx gen_sminv4si3 (rtx, rtx, rtx);
extern rtx gen_sminv8hi3 (rtx, rtx, rtx);
extern rtx gen_sminv16qi3 (rtx, rtx, rtx);
extern rtx gen_sminv4sf3 (rtx, rtx, rtx);
extern rtx gen_uminv2si3 (rtx, rtx, rtx);
extern rtx gen_uminv4hi3 (rtx, rtx, rtx);
extern rtx gen_uminv8qi3 (rtx, rtx, rtx);
extern rtx gen_uminv4si3 (rtx, rtx, rtx);
extern rtx gen_uminv8hi3 (rtx, rtx, rtx);
extern rtx gen_uminv16qi3 (rtx, rtx, rtx);
extern rtx gen_smaxv2si3 (rtx, rtx, rtx);
extern rtx gen_smaxv4hi3 (rtx, rtx, rtx);
extern rtx gen_smaxv8qi3 (rtx, rtx, rtx);
extern rtx gen_smaxv2sf3 (rtx, rtx, rtx);
extern rtx gen_smaxv4si3 (rtx, rtx, rtx);
extern rtx gen_smaxv8hi3 (rtx, rtx, rtx);
extern rtx gen_smaxv16qi3 (rtx, rtx, rtx);
extern rtx gen_smaxv4sf3 (rtx, rtx, rtx);
extern rtx gen_umaxv2si3 (rtx, rtx, rtx);
extern rtx gen_umaxv4hi3 (rtx, rtx, rtx);
extern rtx gen_umaxv8qi3 (rtx, rtx, rtx);
extern rtx gen_umaxv4si3 (rtx, rtx, rtx);
extern rtx gen_umaxv8hi3 (rtx, rtx, rtx);
extern rtx gen_umaxv16qi3 (rtx, rtx, rtx);
extern rtx gen_vec_perm_constv2di (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv2si (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv4si (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_vec_permv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_vec_permv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_doloop_end (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_movti (rtx, rtx);
extern rtx gen_movei (rtx, rtx);
extern rtx gen_movoi (rtx, rtx);
extern rtx gen_movci (rtx, rtx);
extern rtx gen_movxi (rtx, rtx);
extern rtx gen_movmisalignv8qi (rtx, rtx);
extern rtx gen_movmisalignv16qi (rtx, rtx);
extern rtx gen_movmisalignv4hi (rtx, rtx);
extern rtx gen_movmisalignv8hi (rtx, rtx);
extern rtx gen_movmisalignv2si (rtx, rtx);
extern rtx gen_movmisalignv4si (rtx, rtx);
extern rtx gen_movmisalignv2sf (rtx, rtx);
extern rtx gen_movmisalignv4sf (rtx, rtx);
extern rtx gen_movmisaligndi (rtx, rtx);
extern rtx gen_movmisalignv2di (rtx, rtx);
extern rtx gen_vec_setv8qi (rtx, rtx, rtx);
extern rtx gen_vec_setv16qi (rtx, rtx, rtx);
extern rtx gen_vec_setv4hi (rtx, rtx, rtx);
extern rtx gen_vec_setv8hi (rtx, rtx, rtx);
extern rtx gen_vec_setv2si (rtx, rtx, rtx);
extern rtx gen_vec_setv4si (rtx, rtx, rtx);
extern rtx gen_vec_setv2sf (rtx, rtx, rtx);
extern rtx gen_vec_setv4sf (rtx, rtx, rtx);
extern rtx gen_vec_setv2di (rtx, rtx, rtx);
extern rtx gen_vec_initv8qi (rtx, rtx);
extern rtx gen_vec_initv16qi (rtx, rtx);
extern rtx gen_vec_initv4hi (rtx, rtx);
extern rtx gen_vec_initv8hi (rtx, rtx);
extern rtx gen_vec_initv2si (rtx, rtx);
extern rtx gen_vec_initv4si (rtx, rtx);
extern rtx gen_vec_initv2sf (rtx, rtx);
extern rtx gen_vec_initv4sf (rtx, rtx);
extern rtx gen_vec_initv2di (rtx, rtx);
extern rtx gen_vashrv8qi3 (rtx, rtx, rtx);
extern rtx gen_vashrv16qi3 (rtx, rtx, rtx);
extern rtx gen_vashrv4hi3 (rtx, rtx, rtx);
extern rtx gen_vashrv8hi3 (rtx, rtx, rtx);
extern rtx gen_vashrv2si3 (rtx, rtx, rtx);
extern rtx gen_vashrv4si3 (rtx, rtx, rtx);
extern rtx gen_vlshrv8qi3 (rtx, rtx, rtx);
extern rtx gen_vlshrv16qi3 (rtx, rtx, rtx);
extern rtx gen_vlshrv4hi3 (rtx, rtx, rtx);
extern rtx gen_vlshrv8hi3 (rtx, rtx, rtx);
extern rtx gen_vlshrv2si3 (rtx, rtx, rtx);
extern rtx gen_vlshrv4si3 (rtx, rtx, rtx);
extern rtx gen_vec_shr_v8qi (rtx, rtx, rtx);
extern rtx gen_vec_shr_v16qi (rtx, rtx, rtx);
extern rtx gen_vec_shr_v4hi (rtx, rtx, rtx);
extern rtx gen_vec_shr_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_shr_v2si (rtx, rtx, rtx);
extern rtx gen_vec_shr_v4si (rtx, rtx, rtx);
extern rtx gen_vec_shr_v2sf (rtx, rtx, rtx);
extern rtx gen_vec_shr_v4sf (rtx, rtx, rtx);
extern rtx gen_vec_shr_v2di (rtx, rtx, rtx);
extern rtx gen_vec_shl_v8qi (rtx, rtx, rtx);
extern rtx gen_vec_shl_v16qi (rtx, rtx, rtx);
extern rtx gen_vec_shl_v4hi (rtx, rtx, rtx);
extern rtx gen_vec_shl_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_shl_v2si (rtx, rtx, rtx);
extern rtx gen_vec_shl_v4si (rtx, rtx, rtx);
extern rtx gen_vec_shl_v2sf (rtx, rtx, rtx);
extern rtx gen_vec_shl_v4sf (rtx, rtx, rtx);
extern rtx gen_vec_shl_v2di (rtx, rtx, rtx);
extern rtx gen_move_hi_quad_v2di (rtx, rtx);
extern rtx gen_move_hi_quad_v2df (rtx, rtx);
extern rtx gen_move_hi_quad_v16qi (rtx, rtx);
extern rtx gen_move_hi_quad_v8hi (rtx, rtx);
extern rtx gen_move_hi_quad_v4si (rtx, rtx);
extern rtx gen_move_hi_quad_v4sf (rtx, rtx);
extern rtx gen_move_lo_quad_v2di (rtx, rtx);
extern rtx gen_move_lo_quad_v2df (rtx, rtx);
extern rtx gen_move_lo_quad_v16qi (rtx, rtx);
extern rtx gen_move_lo_quad_v8hi (rtx, rtx);
extern rtx gen_move_lo_quad_v4si (rtx, rtx);
extern rtx gen_move_lo_quad_v4sf (rtx, rtx);
extern rtx gen_reduc_splus_v8qi (rtx, rtx);
extern rtx gen_reduc_splus_v4hi (rtx, rtx);
extern rtx gen_reduc_splus_v2si (rtx, rtx);
extern rtx gen_reduc_splus_v2sf (rtx, rtx);
extern rtx gen_reduc_splus_v16qi (rtx, rtx);
extern rtx gen_reduc_splus_v8hi (rtx, rtx);
extern rtx gen_reduc_splus_v4si (rtx, rtx);
extern rtx gen_reduc_splus_v4sf (rtx, rtx);
extern rtx gen_reduc_uplus_v8qi (rtx, rtx);
extern rtx gen_reduc_uplus_v16qi (rtx, rtx);
extern rtx gen_reduc_uplus_v4hi (rtx, rtx);
extern rtx gen_reduc_uplus_v8hi (rtx, rtx);
extern rtx gen_reduc_uplus_v2si (rtx, rtx);
extern rtx gen_reduc_uplus_v4si (rtx, rtx);
extern rtx gen_reduc_uplus_v2di (rtx, rtx);
extern rtx gen_reduc_smin_v8qi (rtx, rtx);
extern rtx gen_reduc_smin_v4hi (rtx, rtx);
extern rtx gen_reduc_smin_v2si (rtx, rtx);
extern rtx gen_reduc_smin_v2sf (rtx, rtx);
extern rtx gen_reduc_smin_v16qi (rtx, rtx);
extern rtx gen_reduc_smin_v8hi (rtx, rtx);
extern rtx gen_reduc_smin_v4si (rtx, rtx);
extern rtx gen_reduc_smin_v4sf (rtx, rtx);
extern rtx gen_reduc_smax_v8qi (rtx, rtx);
extern rtx gen_reduc_smax_v4hi (rtx, rtx);
extern rtx gen_reduc_smax_v2si (rtx, rtx);
extern rtx gen_reduc_smax_v2sf (rtx, rtx);
extern rtx gen_reduc_smax_v16qi (rtx, rtx);
extern rtx gen_reduc_smax_v8hi (rtx, rtx);
extern rtx gen_reduc_smax_v4si (rtx, rtx);
extern rtx gen_reduc_smax_v4sf (rtx, rtx);
extern rtx gen_reduc_umin_v8qi (rtx, rtx);
extern rtx gen_reduc_umin_v4hi (rtx, rtx);
extern rtx gen_reduc_umin_v2si (rtx, rtx);
extern rtx gen_reduc_umin_v16qi (rtx, rtx);
extern rtx gen_reduc_umin_v8hi (rtx, rtx);
extern rtx gen_reduc_umin_v4si (rtx, rtx);
extern rtx gen_reduc_umax_v8qi (rtx, rtx);
extern rtx gen_reduc_umax_v4hi (rtx, rtx);
extern rtx gen_reduc_umax_v2si (rtx, rtx);
extern rtx gen_reduc_umax_v16qi (rtx, rtx);
extern rtx gen_reduc_umax_v8hi (rtx, rtx);
extern rtx gen_reduc_umax_v4si (rtx, rtx);
extern rtx gen_vcondv8qiv8qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv16qiv16qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4hiv4hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8hiv8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv2siv2si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4siv4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv2sfv2sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4sfv4sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv8qiv8qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv16qiv16qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv4hiv4hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv8hiv8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv2siv2si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv4siv4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vaddv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vaddv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vaddv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vaddv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vaddv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vaddv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vaddv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vaddv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vadddi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vaddv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlav8qi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlav16qi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlav4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlav8hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlav2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlav4si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlav2sf (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlav4sf (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsv8qi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsv16qi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsv4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsv8hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsv2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsv4si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsv2sf (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsv4sf (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsubv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsubv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsubv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsubv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsubv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsubv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsubv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsubv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsubdi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vsubv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpaddv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpaddv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpaddv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vpaddv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vabsv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vabsv16qi (rtx, rtx, rtx);
extern rtx gen_neon_vabsv4hi (rtx, rtx, rtx);
extern rtx gen_neon_vabsv8hi (rtx, rtx, rtx);
extern rtx gen_neon_vabsv2si (rtx, rtx, rtx);
extern rtx gen_neon_vabsv4si (rtx, rtx, rtx);
extern rtx gen_neon_vabsv2sf (rtx, rtx, rtx);
extern rtx gen_neon_vabsv4sf (rtx, rtx, rtx);
extern rtx gen_neon_vnegv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vnegv16qi (rtx, rtx, rtx);
extern rtx gen_neon_vnegv4hi (rtx, rtx, rtx);
extern rtx gen_neon_vnegv8hi (rtx, rtx, rtx);
extern rtx gen_neon_vnegv2si (rtx, rtx, rtx);
extern rtx gen_neon_vnegv4si (rtx, rtx, rtx);
extern rtx gen_neon_vnegv2sf (rtx, rtx, rtx);
extern rtx gen_neon_vnegv4sf (rtx, rtx, rtx);
extern rtx gen_neon_vclzv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vclzv16qi (rtx, rtx, rtx);
extern rtx gen_neon_vclzv4hi (rtx, rtx, rtx);
extern rtx gen_neon_vclzv8hi (rtx, rtx, rtx);
extern rtx gen_neon_vclzv2si (rtx, rtx, rtx);
extern rtx gen_neon_vclzv4si (rtx, rtx, rtx);
extern rtx gen_neon_vcntv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vcntv16qi (rtx, rtx, rtx);
extern rtx gen_neon_vmvnv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vmvnv16qi (rtx, rtx, rtx);
extern rtx gen_neon_vmvnv4hi (rtx, rtx, rtx);
extern rtx gen_neon_vmvnv8hi (rtx, rtx, rtx);
extern rtx gen_neon_vmvnv2si (rtx, rtx, rtx);
extern rtx gen_neon_vmvnv4si (rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vget_lanedi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vget_lanev2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vset_lanev8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vset_lanev16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vset_lanev4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vset_lanev8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vset_lanev2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vset_lanev4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vset_lanev2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vset_lanev4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vset_lanev2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vset_lanedi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vcreatev8qi (rtx, rtx);
extern rtx gen_neon_vcreatev4hi (rtx, rtx);
extern rtx gen_neon_vcreatev2si (rtx, rtx);
extern rtx gen_neon_vcreatev2sf (rtx, rtx);
extern rtx gen_neon_vcreatedi (rtx, rtx);
extern rtx gen_neon_vdup_ndi (rtx, rtx);
extern rtx gen_neon_vdup_lanev8qi (rtx, rtx, rtx);
extern rtx gen_neon_vdup_lanev16qi (rtx, rtx, rtx);
extern rtx gen_neon_vdup_lanev4hi (rtx, rtx, rtx);
extern rtx gen_neon_vdup_lanev8hi (rtx, rtx, rtx);
extern rtx gen_neon_vdup_lanev2si (rtx, rtx, rtx);
extern rtx gen_neon_vdup_lanev4si (rtx, rtx, rtx);
extern rtx gen_neon_vdup_lanev2sf (rtx, rtx, rtx);
extern rtx gen_neon_vdup_lanev4sf (rtx, rtx, rtx);
extern rtx gen_neon_vdup_lanedi (rtx, rtx, rtx);
extern rtx gen_neon_vdup_lanev2di (rtx, rtx, rtx);
extern rtx gen_neon_vget_highv16qi (rtx, rtx);
extern rtx gen_neon_vget_highv8hi (rtx, rtx);
extern rtx gen_neon_vget_highv4si (rtx, rtx);
extern rtx gen_neon_vget_highv4sf (rtx, rtx);
extern rtx gen_neon_vget_highv2di (rtx, rtx);
extern rtx gen_neon_vget_lowv16qi (rtx, rtx);
extern rtx gen_neon_vget_lowv8hi (rtx, rtx);
extern rtx gen_neon_vget_lowv4si (rtx, rtx);
extern rtx gen_neon_vget_lowv4sf (rtx, rtx);
extern rtx gen_neon_vget_lowv2di (rtx, rtx);
extern rtx gen_neon_vmul_nv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmul_nv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmul_nv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmul_nv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmul_nv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmul_nv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmull_nv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmull_nv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmull_nv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmull_nv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmulh_nv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmulh_nv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmulh_nv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmulh_nv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmla_nv4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmla_nv2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmla_nv2sf (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmla_nv8hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmla_nv4si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmla_nv4sf (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlal_nv4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlal_nv2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmlal_nv4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmlal_nv2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmls_nv4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmls_nv2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmls_nv2sf (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmls_nv8hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmls_nv4si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmls_nv4sf (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsl_nv4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vmlsl_nv2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmlsl_nv4hi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vqdmlsl_nv2si (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbslv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbslv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbslv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbslv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbslv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbslv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbslv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbslv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbsldi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbslv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vtrnv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vtrnv16qi (rtx, rtx, rtx);
extern rtx gen_neon_vtrnv4hi (rtx, rtx, rtx);
extern rtx gen_neon_vtrnv8hi (rtx, rtx, rtx);
extern rtx gen_neon_vtrnv2si (rtx, rtx, rtx);
extern rtx gen_neon_vtrnv4si (rtx, rtx, rtx);
extern rtx gen_neon_vtrnv2sf (rtx, rtx, rtx);
extern rtx gen_neon_vtrnv4sf (rtx, rtx, rtx);
extern rtx gen_neon_vzipv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vzipv16qi (rtx, rtx, rtx);
extern rtx gen_neon_vzipv4hi (rtx, rtx, rtx);
extern rtx gen_neon_vzipv8hi (rtx, rtx, rtx);
extern rtx gen_neon_vzipv2si (rtx, rtx, rtx);
extern rtx gen_neon_vzipv4si (rtx, rtx, rtx);
extern rtx gen_neon_vzipv2sf (rtx, rtx, rtx);
extern rtx gen_neon_vzipv4sf (rtx, rtx, rtx);
extern rtx gen_neon_vuzpv8qi (rtx, rtx, rtx);
extern rtx gen_neon_vuzpv16qi (rtx, rtx, rtx);
extern rtx gen_neon_vuzpv4hi (rtx, rtx, rtx);
extern rtx gen_neon_vuzpv8hi (rtx, rtx, rtx);
extern rtx gen_neon_vuzpv2si (rtx, rtx, rtx);
extern rtx gen_neon_vuzpv4si (rtx, rtx, rtx);
extern rtx gen_neon_vuzpv2sf (rtx, rtx, rtx);
extern rtx gen_neon_vuzpv4sf (rtx, rtx, rtx);
extern rtx gen_neon_vreinterpretv8qiv8qi (rtx, rtx);
extern rtx gen_neon_vreinterpretv8qiv4hi (rtx, rtx);
extern rtx gen_neon_vreinterpretv8qiv2si (rtx, rtx);
extern rtx gen_neon_vreinterpretv8qiv2sf (rtx, rtx);
extern rtx gen_neon_vreinterpretv8qidi (rtx, rtx);
extern rtx gen_neon_vreinterpretv4hiv8qi (rtx, rtx);
extern rtx gen_neon_vreinterpretv4hiv4hi (rtx, rtx);
extern rtx gen_neon_vreinterpretv4hiv2si (rtx, rtx);
extern rtx gen_neon_vreinterpretv4hiv2sf (rtx, rtx);
extern rtx gen_neon_vreinterpretv4hidi (rtx, rtx);
extern rtx gen_neon_vreinterpretv2siv8qi (rtx, rtx);
extern rtx gen_neon_vreinterpretv2siv4hi (rtx, rtx);
extern rtx gen_neon_vreinterpretv2siv2si (rtx, rtx);
extern rtx gen_neon_vreinterpretv2siv2sf (rtx, rtx);
extern rtx gen_neon_vreinterpretv2sidi (rtx, rtx);
extern rtx gen_neon_vreinterpretv2sfv8qi (rtx, rtx);
extern rtx gen_neon_vreinterpretv2sfv4hi (rtx, rtx);
extern rtx gen_neon_vreinterpretv2sfv2si (rtx, rtx);
extern rtx gen_neon_vreinterpretv2sfv2sf (rtx, rtx);
extern rtx gen_neon_vreinterpretv2sfdi (rtx, rtx);
extern rtx gen_neon_vreinterpretdiv8qi (rtx, rtx);
extern rtx gen_neon_vreinterpretdiv4hi (rtx, rtx);
extern rtx gen_neon_vreinterpretdiv2si (rtx, rtx);
extern rtx gen_neon_vreinterpretdiv2sf (rtx, rtx);
extern rtx gen_neon_vreinterpretdidi (rtx, rtx);
extern rtx gen_neon_vreinterpretv16qiv16qi (rtx, rtx);
extern rtx gen_neon_vreinterpretv16qiv8hi (rtx, rtx);
extern rtx gen_neon_vreinterpretv16qiv4si (rtx, rtx);
extern rtx gen_neon_vreinterpretv16qiv4sf (rtx, rtx);
extern rtx gen_neon_vreinterpretv16qiv2di (rtx, rtx);
extern rtx gen_neon_vreinterpretv8hiv16qi (rtx, rtx);
extern rtx gen_neon_vreinterpretv8hiv8hi (rtx, rtx);
extern rtx gen_neon_vreinterpretv8hiv4si (rtx, rtx);
extern rtx gen_neon_vreinterpretv8hiv4sf (rtx, rtx);
extern rtx gen_neon_vreinterpretv8hiv2di (rtx, rtx);
extern rtx gen_neon_vreinterpretv4siv16qi (rtx, rtx);
extern rtx gen_neon_vreinterpretv4siv8hi (rtx, rtx);
extern rtx gen_neon_vreinterpretv4siv4si (rtx, rtx);
extern rtx gen_neon_vreinterpretv4siv4sf (rtx, rtx);
extern rtx gen_neon_vreinterpretv4siv2di (rtx, rtx);
extern rtx gen_neon_vreinterpretv4sfv16qi (rtx, rtx);
extern rtx gen_neon_vreinterpretv4sfv8hi (rtx, rtx);
extern rtx gen_neon_vreinterpretv4sfv4si (rtx, rtx);
extern rtx gen_neon_vreinterpretv4sfv4sf (rtx, rtx);
extern rtx gen_neon_vreinterpretv4sfv2di (rtx, rtx);
extern rtx gen_neon_vreinterpretv2div16qi (rtx, rtx);
extern rtx gen_neon_vreinterpretv2div8hi (rtx, rtx);
extern rtx gen_neon_vreinterpretv2div4si (rtx, rtx);
extern rtx gen_neon_vreinterpretv2div4sf (rtx, rtx);
extern rtx gen_neon_vreinterpretv2div2di (rtx, rtx);
extern rtx gen_vec_load_lanesv8qiv8qi (rtx, rtx);
extern rtx gen_vec_load_lanesv16qiv16qi (rtx, rtx);
extern rtx gen_vec_load_lanesv4hiv4hi (rtx, rtx);
extern rtx gen_vec_load_lanesv8hiv8hi (rtx, rtx);
extern rtx gen_vec_load_lanesv2siv2si (rtx, rtx);
extern rtx gen_vec_load_lanesv4siv4si (rtx, rtx);
extern rtx gen_vec_load_lanesv2sfv2sf (rtx, rtx);
extern rtx gen_vec_load_lanesv4sfv4sf (rtx, rtx);
extern rtx gen_vec_load_lanesdidi (rtx, rtx);
extern rtx gen_vec_load_lanesv2div2di (rtx, rtx);
extern rtx gen_vec_store_lanesv8qiv8qi (rtx, rtx);
extern rtx gen_vec_store_lanesv16qiv16qi (rtx, rtx);
extern rtx gen_vec_store_lanesv4hiv4hi (rtx, rtx);
extern rtx gen_vec_store_lanesv8hiv8hi (rtx, rtx);
extern rtx gen_vec_store_lanesv2siv2si (rtx, rtx);
extern rtx gen_vec_store_lanesv4siv4si (rtx, rtx);
extern rtx gen_vec_store_lanesv2sfv2sf (rtx, rtx);
extern rtx gen_vec_store_lanesv4sfv4sf (rtx, rtx);
extern rtx gen_vec_store_lanesdidi (rtx, rtx);
extern rtx gen_vec_store_lanesv2div2di (rtx, rtx);
extern rtx gen_vec_load_lanestiv8qi (rtx, rtx);
extern rtx gen_vec_load_lanestiv4hi (rtx, rtx);
extern rtx gen_vec_load_lanestiv2si (rtx, rtx);
extern rtx gen_vec_load_lanestiv2sf (rtx, rtx);
extern rtx gen_vec_load_lanestidi (rtx, rtx);
extern rtx gen_vec_load_lanesoiv16qi (rtx, rtx);
extern rtx gen_vec_load_lanesoiv8hi (rtx, rtx);
extern rtx gen_vec_load_lanesoiv4si (rtx, rtx);
extern rtx gen_vec_load_lanesoiv4sf (rtx, rtx);
extern rtx gen_vec_store_lanestiv8qi (rtx, rtx);
extern rtx gen_vec_store_lanestiv4hi (rtx, rtx);
extern rtx gen_vec_store_lanestiv2si (rtx, rtx);
extern rtx gen_vec_store_lanestiv2sf (rtx, rtx);
extern rtx gen_vec_store_lanestidi (rtx, rtx);
extern rtx gen_vec_store_lanesoiv16qi (rtx, rtx);
extern rtx gen_vec_store_lanesoiv8hi (rtx, rtx);
extern rtx gen_vec_store_lanesoiv4si (rtx, rtx);
extern rtx gen_vec_store_lanesoiv4sf (rtx, rtx);
extern rtx gen_vec_load_laneseiv8qi (rtx, rtx);
extern rtx gen_vec_load_laneseiv4hi (rtx, rtx);
extern rtx gen_vec_load_laneseiv2si (rtx, rtx);
extern rtx gen_vec_load_laneseiv2sf (rtx, rtx);
extern rtx gen_vec_load_laneseidi (rtx, rtx);
extern rtx gen_vec_load_lanesciv16qi (rtx, rtx);
extern rtx gen_vec_load_lanesciv8hi (rtx, rtx);
extern rtx gen_vec_load_lanesciv4si (rtx, rtx);
extern rtx gen_vec_load_lanesciv4sf (rtx, rtx);
extern rtx gen_neon_vld3v16qi (rtx, rtx);
extern rtx gen_neon_vld3v8hi (rtx, rtx);
extern rtx gen_neon_vld3v4si (rtx, rtx);
extern rtx gen_neon_vld3v4sf (rtx, rtx);
extern rtx gen_vec_store_laneseiv8qi (rtx, rtx);
extern rtx gen_vec_store_laneseiv4hi (rtx, rtx);
extern rtx gen_vec_store_laneseiv2si (rtx, rtx);
extern rtx gen_vec_store_laneseiv2sf (rtx, rtx);
extern rtx gen_vec_store_laneseidi (rtx, rtx);
extern rtx gen_vec_store_lanesciv16qi (rtx, rtx);
extern rtx gen_vec_store_lanesciv8hi (rtx, rtx);
extern rtx gen_vec_store_lanesciv4si (rtx, rtx);
extern rtx gen_vec_store_lanesciv4sf (rtx, rtx);
extern rtx gen_neon_vst3v16qi (rtx, rtx);
extern rtx gen_neon_vst3v8hi (rtx, rtx);
extern rtx gen_neon_vst3v4si (rtx, rtx);
extern rtx gen_neon_vst3v4sf (rtx, rtx);
extern rtx gen_vec_load_lanesoiv8qi (rtx, rtx);
extern rtx gen_vec_load_lanesoiv4hi (rtx, rtx);
extern rtx gen_vec_load_lanesoiv2si (rtx, rtx);
extern rtx gen_vec_load_lanesoiv2sf (rtx, rtx);
extern rtx gen_vec_load_lanesoidi (rtx, rtx);
extern rtx gen_vec_load_lanesxiv16qi (rtx, rtx);
extern rtx gen_vec_load_lanesxiv8hi (rtx, rtx);
extern rtx gen_vec_load_lanesxiv4si (rtx, rtx);
extern rtx gen_vec_load_lanesxiv4sf (rtx, rtx);
extern rtx gen_neon_vld4v16qi (rtx, rtx);
extern rtx gen_neon_vld4v8hi (rtx, rtx);
extern rtx gen_neon_vld4v4si (rtx, rtx);
extern rtx gen_neon_vld4v4sf (rtx, rtx);
extern rtx gen_vec_store_lanesoiv8qi (rtx, rtx);
extern rtx gen_vec_store_lanesoiv4hi (rtx, rtx);
extern rtx gen_vec_store_lanesoiv2si (rtx, rtx);
extern rtx gen_vec_store_lanesoiv2sf (rtx, rtx);
extern rtx gen_vec_store_lanesoidi (rtx, rtx);
extern rtx gen_vec_store_lanesxiv16qi (rtx, rtx);
extern rtx gen_vec_store_lanesxiv8hi (rtx, rtx);
extern rtx gen_vec_store_lanesxiv4si (rtx, rtx);
extern rtx gen_vec_store_lanesxiv4sf (rtx, rtx);
extern rtx gen_neon_vst4v16qi (rtx, rtx);
extern rtx gen_neon_vst4v8hi (rtx, rtx);
extern rtx gen_neon_vst4v4si (rtx, rtx);
extern rtx gen_neon_vst4v4sf (rtx, rtx);
extern rtx gen_neon_vandv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vandv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vandv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vandv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vandv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vandv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vandv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vandv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vanddi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vandv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vorrv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vorrv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vorrv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vorrv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vorrv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vorrv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vorrv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vorrv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vorrdi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vorrv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_veorv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_veorv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_veorv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_veorv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_veorv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_veorv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_veorv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_veorv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_veordi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_veorv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbicv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbicv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbicv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbicv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbicv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbicv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbicv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbicv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbicdi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vbicv2di (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vornv8qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vornv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vornv4hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vornv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vornv2si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vornv4si (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vornv2sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vornv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vorndi (rtx, rtx, rtx, rtx);
extern rtx gen_neon_vornv2di (rtx, rtx, rtx, rtx);
extern rtx gen_vec_unpacks_hi_v16qi (rtx, rtx);
extern rtx gen_vec_unpacku_hi_v16qi (rtx, rtx);
extern rtx gen_vec_unpacks_hi_v8hi (rtx, rtx);
extern rtx gen_vec_unpacku_hi_v8hi (rtx, rtx);
extern rtx gen_vec_unpacks_hi_v4si (rtx, rtx);
extern rtx gen_vec_unpacku_hi_v4si (rtx, rtx);
extern rtx gen_vec_unpacks_lo_v16qi (rtx, rtx);
extern rtx gen_vec_unpacku_lo_v16qi (rtx, rtx);
extern rtx gen_vec_unpacks_lo_v8hi (rtx, rtx);
extern rtx gen_vec_unpacku_lo_v8hi (rtx, rtx);
extern rtx gen_vec_unpacks_lo_v4si (rtx, rtx);
extern rtx gen_vec_unpacku_lo_v4si (rtx, rtx);
extern rtx gen_vec_widen_smult_lo_v16qi (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_lo_v16qi (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_lo_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_lo_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_lo_v4si (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_lo_v4si (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_hi_v16qi (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_hi_v16qi (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_hi_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_hi_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_hi_v4si (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_hi_v4si (rtx, rtx, rtx);
extern rtx gen_vec_widen_sshiftl_lo_v16qi (rtx, rtx, rtx);
extern rtx gen_vec_widen_ushiftl_lo_v16qi (rtx, rtx, rtx);
extern rtx gen_vec_widen_sshiftl_lo_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_ushiftl_lo_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_sshiftl_lo_v4si (rtx, rtx, rtx);
extern rtx gen_vec_widen_ushiftl_lo_v4si (rtx, rtx, rtx);
extern rtx gen_vec_widen_sshiftl_hi_v16qi (rtx, rtx, rtx);
extern rtx gen_vec_widen_ushiftl_hi_v16qi (rtx, rtx, rtx);
extern rtx gen_vec_widen_sshiftl_hi_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_ushiftl_hi_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_sshiftl_hi_v4si (rtx, rtx, rtx);
extern rtx gen_vec_widen_ushiftl_hi_v4si (rtx, rtx, rtx);
extern rtx gen_vec_unpacks_lo_v8qi (rtx, rtx);
extern rtx gen_vec_unpacku_lo_v8qi (rtx, rtx);
extern rtx gen_vec_unpacks_lo_v4hi (rtx, rtx);
extern rtx gen_vec_unpacku_lo_v4hi (rtx, rtx);
extern rtx gen_vec_unpacks_lo_v2si (rtx, rtx);
extern rtx gen_vec_unpacku_lo_v2si (rtx, rtx);
extern rtx gen_vec_unpacks_hi_v8qi (rtx, rtx);
extern rtx gen_vec_unpacku_hi_v8qi (rtx, rtx);
extern rtx gen_vec_unpacks_hi_v4hi (rtx, rtx);
extern rtx gen_vec_unpacku_hi_v4hi (rtx, rtx);
extern rtx gen_vec_unpacks_hi_v2si (rtx, rtx);
extern rtx gen_vec_unpacku_hi_v2si (rtx, rtx);
extern rtx gen_vec_widen_smult_hi_v8qi (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_hi_v8qi (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_hi_v4hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_hi_v4hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_hi_v2si (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_hi_v2si (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_lo_v8qi (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_lo_v8qi (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_lo_v4hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_lo_v4hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_lo_v2si (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_lo_v2si (rtx, rtx, rtx);
extern rtx gen_vec_widen_sshiftl_hi_v8qi (rtx, rtx, rtx);
extern rtx gen_vec_widen_ushiftl_hi_v8qi (rtx, rtx, rtx);
extern rtx gen_vec_widen_sshiftl_hi_v4hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_ushiftl_hi_v4hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_sshiftl_hi_v2si (rtx, rtx, rtx);
extern rtx gen_vec_widen_ushiftl_hi_v2si (rtx, rtx, rtx);
extern rtx gen_vec_widen_sshiftl_lo_v8qi (rtx, rtx, rtx);
extern rtx gen_vec_widen_ushiftl_lo_v8qi (rtx, rtx, rtx);
extern rtx gen_vec_widen_sshiftl_lo_v4hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_ushiftl_lo_v4hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_sshiftl_lo_v2si (rtx, rtx, rtx);
extern rtx gen_vec_widen_ushiftl_lo_v2si (rtx, rtx, rtx);
extern rtx gen_vec_pack_trunc_v4hi (rtx, rtx, rtx);
extern rtx gen_vec_pack_trunc_v2si (rtx, rtx, rtx);
extern rtx gen_vec_pack_trunc_di (rtx, rtx, rtx);
extern rtx gen_memory_barrier (void);
extern rtx gen_atomic_compare_and_swapqi (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_atomic_compare_and_swaphi (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_atomic_compare_and_swapsi (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_atomic_compare_and_swapdi (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_mulqq3 (rtx, rtx, rtx);
extern rtx gen_mulhq3 (rtx, rtx, rtx);
extern rtx gen_mulsq3 (rtx, rtx, rtx);
extern rtx gen_mulsa3 (rtx, rtx, rtx);
extern rtx gen_mulusa3 (rtx, rtx, rtx);
extern rtx gen_mulha3 (rtx, rtx, rtx);
extern rtx gen_muluha3 (rtx, rtx, rtx);
extern rtx gen_ssmulha3 (rtx, rtx, rtx);
extern rtx gen_usmuluha3 (rtx, rtx, rtx);
# 39 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/defaults.h" 1
# 1007 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/defaults.h"
       
# 41 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 2
# 26 "../../../src/plugin-utils.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/langhooks.h" 1
# 26 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/langhooks.h"
struct diagnostic_info;
struct gimplify_omp_ctx;
struct array_descr_info;
typedef void (*lang_print_tree_hook) (FILE *, tree, int indent);
enum classify_record
  { RECORD_IS_STRUCT, RECORD_IS_CLASS, RECORD_IS_INTERFACE };
struct lang_hooks_for_tree_inlining
{
  unsigned char (*var_mod_type_p) (tree, tree);
};
struct lang_hooks_for_callgraph
{
  tree (*analyze_expr) (tree *, int *);
};
struct lang_hooks_for_tree_dump
{
  unsigned char (*dump_tree) (void *, tree);
  int (*type_quals) (const_tree);
};
struct lang_hooks_for_types
{
  tree (*make_type) (enum tree_code);
  enum classify_record (*classify_record) (tree);
  tree (*type_for_mode) (enum machine_mode, int);
  tree (*type_for_size) (unsigned, int);
  unsigned char (*generic_p) (const_tree);
  tree (*get_argument_pack_elems) (const_tree);
  tree (*type_promotes_to) (tree);
# 106 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/langhooks.h"
  void (*register_builtin_type) (tree, const char *);
  void (*incomplete_type_error) (const_tree value, const_tree type);
  tree (*max_size) (const_tree);
  void (*omp_firstprivatize_type_sizes) (struct gimplify_omp_ctx *, tree);
  unsigned char (*type_hash_eq) (const_tree, const_tree);
  unsigned char (*get_array_descr_info) (const_tree, struct array_descr_info *);
  void (*get_subrange_bounds) (const_tree, tree *, tree *);
  tree (*descriptive_type) (const_tree);
  tree (*reconstruct_complex_type) (tree, tree);
};
struct lang_hooks_for_decls
{
  unsigned char (*global_bindings_p) (void);
  tree (*pushdecl) (tree);
  tree (*getdecls) (void);
  unsigned char (*function_decl_explicit_p) (tree);
  unsigned char (*generic_generic_parameter_decl_p) (const_tree);
  unsigned char (*function_parm_expanded_from_pack_p) (tree, tree);
  tree (*get_generic_function_decl) (const_tree);
  unsigned char (*warn_unused_global) (const_tree);
  void (*final_write_globals) (void);
  unsigned char (*ok_for_sibcall) (const_tree);
  unsigned char (*omp_privatize_by_reference) (const_tree);
  enum omp_clause_default_kind (*omp_predetermined_sharing) (tree);
  tree (*omp_report_decl) (tree);
  unsigned char (*omp_disregard_value_expr) (tree, unsigned char);
  unsigned char (*omp_private_debug_clause) (tree, unsigned char);
  unsigned char (*omp_private_outer_ref) (tree);
  tree (*omp_clause_default_ctor) (tree clause, tree decl, tree outer);
  tree (*omp_clause_copy_ctor) (tree clause, tree dst, tree src);
  tree (*omp_clause_assign_op) (tree clause, tree dst, tree src);
  tree (*omp_clause_dtor) (tree clause, tree decl);
  void (*omp_finish_clause) (tree clause);
};
struct lang_hooks_for_lto
{
  void (*begin_section) (const char *name);
  void (*append_data) (const void *data, size_t len, void *block);
  void (*end_section) (void);
};
struct lang_hooks
{
  const char *name;
  size_t identifier_size;
  void (*free_lang_data) (tree);
  size_t (*tree_size) (enum tree_code);
  unsigned int (*option_lang_mask) (void);
  void (*init_options_struct) (struct gcc_options *opts);
  void (*init_options) (unsigned int decoded_options_count,
   struct cl_decoded_option *decoded_options);
  void (*initialize_diagnostics) (diagnostic_context *);
  unsigned char (*complain_wrong_lang_p) (const struct cl_option *option);
# 304 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/langhooks.h"
  unsigned char (*handle_option) (size_t code, const char *arg, int value, int kind,
    location_t loc,
    const struct cl_option_handlers *handlers);
# 316 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/langhooks.h"
  unsigned char (*post_options) (const char **);
  unsigned char (*init) (void);
  void (*finish) (void);
  void (*parse_file) (void);
  unsigned char (*missing_noreturn_ok_p) (tree);
  alias_set_type (*get_alias_set) (tree);
  void (*finish_incomplete_decl) (tree);
  void (*dup_lang_specific_decl) (tree);
  void (*set_decl_assembler_name) (tree);
  void (*print_statistics) (void);
  lang_print_tree_hook print_xnode;
  lang_print_tree_hook print_decl;
  lang_print_tree_hook print_type;
  lang_print_tree_hook print_identifier;
# 374 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/langhooks.h"
  const char *(*decl_printable_name) (tree decl, int verbosity);
  const char *(*dwarf_name) (tree, int verbosity);
  int (*types_compatible_p) (tree x, tree y);
  void (*print_error_function) (diagnostic_context *, const char *,
    struct diagnostic_info *);
# 397 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/langhooks.h"
  long long (*to_target_charset) (long long);
  const struct attribute_spec *attribute_table;
  const struct attribute_spec *common_attribute_table;
  const struct attribute_spec *format_attribute_table;
  struct lang_hooks_for_tree_inlining tree_inlining;
  struct lang_hooks_for_callgraph callgraph;
  struct lang_hooks_for_tree_dump tree_dump;
  struct lang_hooks_for_decls decls;
  struct lang_hooks_for_types types;
  struct lang_hooks_for_lto lto;
  tree (*get_innermost_generic_parms) (const_tree);
  tree (*get_innermost_generic_args) (const_tree);
  unsigned char (*function_parameter_pack_p) (const_tree);
  int (*gimplify_expr) (tree *, gimple_seq *, gimple_seq *);
  tree (*builtin_function) (tree decl);
  tree (*builtin_function_ext_scope) (tree decl);
  void (*init_ts) (void);
  tree (*expr_to_decl) (tree expr, unsigned char *tc, unsigned char *se);
  tree (*eh_personality) (void);
  tree (*eh_runtime_type) (tree);
  tree (*eh_protect_cleanup_actions) (void);
  unsigned char eh_use_cxa_end_cleanup;
  unsigned char deep_unsharing;
};
extern struct lang_hooks lang_hooks;
extern tree add_builtin_function (const char *name, tree type,
      int function_code, enum built_in_class cl,
      const char *library_name,
      tree attrs);
extern tree add_builtin_function_ext_scope (const char *name, tree type,
         int function_code,
         enum built_in_class cl,
         const char *library_name,
         tree attrs);
# 27 "../../../src/plugin-utils.h" 2
# 38 "../../../src/plugin-utils.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-pragma.h" 1
# 24 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-pragma.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cpplib.h" 1
# 31 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cpplib.h"
typedef struct cpp_reader cpp_reader;
typedef struct cpp_buffer cpp_buffer;
typedef struct cpp_options cpp_options;
typedef struct cpp_token cpp_token;
typedef struct cpp_string cpp_string;
typedef struct cpp_hashnode cpp_hashnode;
typedef struct cpp_macro cpp_macro;
typedef struct cpp_callbacks cpp_callbacks;
typedef struct cpp_dir cpp_dir;
struct answer;
struct _cpp_file;
# 153 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cpplib.h"
enum cpp_ttype
{
  CPP_EQ, CPP_NOT, CPP_GREATER, CPP_LESS, CPP_PLUS, CPP_MINUS, CPP_MULT, CPP_DIV, CPP_MOD, CPP_AND, CPP_OR, CPP_XOR, CPP_RSHIFT, CPP_LSHIFT, CPP_COMPL, CPP_AND_AND, CPP_OR_OR, CPP_QUERY, CPP_COLON, CPP_COMMA, CPP_OPEN_PAREN, CPP_CLOSE_PAREN, CPP_EOF, CPP_EQ_EQ, CPP_NOT_EQ, CPP_GREATER_EQ, CPP_LESS_EQ, CPP_PLUS_EQ, CPP_MINUS_EQ, CPP_MULT_EQ, CPP_DIV_EQ, CPP_MOD_EQ, CPP_AND_EQ, CPP_OR_EQ, CPP_XOR_EQ, CPP_RSHIFT_EQ, CPP_LSHIFT_EQ, CPP_HASH, CPP_PASTE, CPP_OPEN_SQUARE, CPP_CLOSE_SQUARE, CPP_OPEN_BRACE, CPP_CLOSE_BRACE, CPP_SEMICOLON, CPP_ELLIPSIS, CPP_PLUS_PLUS, CPP_MINUS_MINUS, CPP_DEREF, CPP_DOT, CPP_SCOPE, CPP_DEREF_STAR, CPP_DOT_STAR, CPP_ATSIGN, CPP_NAME, CPP_AT_NAME, CPP_NUMBER, CPP_CHAR, CPP_WCHAR, CPP_CHAR16, CPP_CHAR32, CPP_OTHER, CPP_STRING, CPP_WSTRING, CPP_STRING16, CPP_STRING32, CPP_UTF8STRING, CPP_OBJC_STRING, CPP_HEADER_NAME, CPP_CHAR_USERDEF, CPP_WCHAR_USERDEF, CPP_CHAR16_USERDEF, CPP_CHAR32_USERDEF, CPP_STRING_USERDEF, CPP_WSTRING_USERDEF, CPP_STRING16_USERDEF, CPP_STRING32_USERDEF, CPP_UTF8STRING_USERDEF, CPP_COMMENT, CPP_MACRO_ARG, CPP_PRAGMA, CPP_PRAGMA_EOL, CPP_PADDING,
  N_TTYPES,
  CPP_LAST_EQ = CPP_LSHIFT,
  CPP_FIRST_DIGRAPH = CPP_HASH,
  CPP_LAST_PUNCTUATOR= CPP_ATSIGN,
  CPP_LAST_CPP_OP = CPP_LESS_EQ
};
enum c_lang {CLK_GNUC89 = 0, CLK_GNUC99, CLK_GNUC11,
      CLK_STDC89, CLK_STDC94, CLK_STDC99, CLK_STDC11,
      CLK_GNUCXX, CLK_CXX98, CLK_GNUCXX11, CLK_CXX11, CLK_ASM};
struct cpp_string {
  unsigned int len;
  const unsigned char *text;
};
# 195 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cpplib.h"
enum cpp_token_fld_kind {
  CPP_TOKEN_FLD_NODE,
  CPP_TOKEN_FLD_SOURCE,
  CPP_TOKEN_FLD_STR,
  CPP_TOKEN_FLD_ARG_NO,
  CPP_TOKEN_FLD_TOKEN_NO,
  CPP_TOKEN_FLD_PRAGMA,
  CPP_TOKEN_FLD_NONE
};
struct cpp_macro_arg {
  unsigned int arg_no;
};
struct cpp_identifier {
  cpp_hashnode *
   
       node;
};
struct cpp_token {
  source_location src_loc;
  __extension__ enum cpp_ttype type : 8;
  unsigned short flags;
  union cpp_token_u
  {
    struct cpp_identifier node;
    cpp_token * source;
    struct cpp_string str;
    struct cpp_macro_arg macro_arg;
    unsigned int token_no;
    unsigned int pragma;
  } val;
};
extern enum cpp_token_fld_kind cpp_token_val_index (cpp_token *tok);
# 269 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cpplib.h"
typedef unsigned int cppchar_t;
typedef int cppchar_signed_t;
enum cpp_deps_style { DEPS_NONE = 0, DEPS_USER, DEPS_SYSTEM };
enum cpp_normalize_level {
  normalized_KC = 0,
  normalized_C,
  normalized_identifier_C,
  normalized_none
};
struct cpp_options
{
  unsigned int tabstop;
  enum c_lang lang;
  unsigned char cplusplus;
  unsigned char cplusplus_comments;
  unsigned char objc;
  unsigned char discard_comments;
  unsigned char discard_comments_in_macro_exp;
  unsigned char trigraphs;
  unsigned char digraphs;
  unsigned char extended_numbers;
  unsigned char uliterals;
  unsigned char rliterals;
  unsigned char print_include_names;
  unsigned char cpp_warn_deprecated;
  unsigned char warn_comments;
  unsigned char warn_missing_include_dirs;
  unsigned char warn_trigraphs;
  unsigned char warn_multichar;
  unsigned char cpp_warn_traditional;
  unsigned char cpp_warn_long_long;
  unsigned char warn_endif_labels;
  unsigned char warn_num_sign_change;
  unsigned char warn_variadic_macros;
  unsigned char warn_builtin_macro_redefined;
  unsigned char remap;
  unsigned char dollars_in_ident;
  unsigned char extended_identifiers;
  unsigned char warn_dollars;
  unsigned char warn_undef;
  unsigned char warn_unused_macros;
  unsigned char c99;
  unsigned char std;
  unsigned char cpp_pedantic;
  unsigned char preprocessed;
  unsigned char debug;
  unsigned char track_macro_expansion;
  unsigned char operator_names;
  unsigned char warn_cxx_operator_names;
  unsigned char traditional;
  unsigned char user_literals;
  const char *narrow_charset;
  const char *wide_charset;
  const char *input_charset;
  enum cpp_normalize_level warn_normalize;
  unsigned char warn_invalid_pch;
  unsigned char restore_pch_deps;
  struct
  {
    enum cpp_deps_style style;
    unsigned char missing_files;
    unsigned char phony_targets;
    unsigned char ignore_main_file;
    unsigned char need_preprocessor_output;
  } deps;
  size_t precision, char_precision, int_precision, wchar_precision;
  unsigned char unsigned_char, unsigned_wchar;
  unsigned char bytes_big_endian;
  unsigned char stdc_0_in_system_headers;
  unsigned char directives_only;
};
typedef const char *(*missing_header_cb)(cpp_reader *, const char *header, cpp_dir **);
struct cpp_callbacks
{
  void (*line_change) (cpp_reader *, const cpp_token *, int);
  void (*file_change) (cpp_reader *, const struct line_map *);
  void (*dir_change) (cpp_reader *, const char *);
  void (*include) (cpp_reader *, source_location, const unsigned char *,
     const char *, int, const cpp_token **);
  void (*define) (cpp_reader *, source_location, cpp_hashnode *);
  void (*undef) (cpp_reader *, source_location, cpp_hashnode *);
  void (*ident) (cpp_reader *, source_location, const cpp_string *);
  void (*def_pragma) (cpp_reader *, source_location);
  int (*valid_pch) (cpp_reader *, const char *, int);
  void (*read_pch) (cpp_reader *, const char *, int, const char *);
  missing_header_cb missing_header;
  cpp_hashnode * (*macro_to_expand) (cpp_reader *, const cpp_token *);
  unsigned char (*error) (cpp_reader *, int, int, source_location, unsigned int,
   const char *, va_list *)
       __attribute__ ((__format__ (__printf__, 6, 0))) __attribute__ ((__nonnull__ (6)));
  void (*used_define) (cpp_reader *, source_location, cpp_hashnode *);
  void (*used_undef) (cpp_reader *, source_location, cpp_hashnode *);
  void (*before_define) (cpp_reader *);
  void (*used) (cpp_reader *, source_location, cpp_hashnode *);
  unsigned char (*user_builtin_macro) (cpp_reader *, cpp_hashnode *);
};
# 553 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cpplib.h"
struct cpp_dir
{
  struct cpp_dir *next;
  char *name;
  unsigned int len;
  unsigned char sysp;
  unsigned char user_supplied_p;
  char *canonical_name;
  const char **name_map;
  char *(*construct) (const char *header, cpp_dir *dir);
  ino_t ino;
  dev_t dev;
};
# 614 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cpplib.h"
enum node_type
{
  NT_VOID = 0,
  NT_MACRO,
  NT_ASSERTION
};
enum cpp_builtin_type
{
  BT_SPECLINE = 0,
  BT_DATE,
  BT_FILE,
  BT_BASE_FILE,
  BT_INCLUDE_LEVEL,
  BT_TIME,
  BT_STDC,
  BT_PRAGMA,
  BT_TIMESTAMP,
  BT_COUNTER,
  BT_FIRST_USER,
  BT_LAST_USER = BT_FIRST_USER + 31
};
# 646 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cpplib.h"
enum {
  NTV_MACRO,
  NTV_ANSWER,
  NTV_BUILTIN,
  NTV_ARGUMENT,
  NTV_NONE
};
# 665 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cpplib.h"
union _cpp_hashnode_value {
  cpp_macro * macro;
  struct answer * answers;
  enum cpp_builtin_type builtin;
  unsigned short arg_index;
};
struct cpp_hashnode {
  struct ht_identifier ident;
  unsigned int is_directive : 1;
  unsigned int directive_index : 7;
  unsigned char rid_code;
  __extension__ enum node_type type : 6;
  unsigned int flags : 10;
  union _cpp_hashnode_value value;
};
extern cpp_reader *cpp_create_reader (enum c_lang, struct ht *,
          struct line_maps *);
extern void cpp_set_line_map (cpp_reader *, struct line_maps *);
extern void cpp_set_lang (cpp_reader *, enum c_lang);
extern void cpp_set_include_chains (cpp_reader *, cpp_dir *, cpp_dir *, int);
extern cpp_options *cpp_get_options (cpp_reader *);
extern cpp_callbacks *cpp_get_callbacks (cpp_reader *);
extern void cpp_set_callbacks (cpp_reader *, cpp_callbacks *);
extern struct deps *cpp_get_deps (cpp_reader *);
extern const char *cpp_read_main_file (cpp_reader *, const char *);
extern void cpp_init_special_builtins (cpp_reader *);
extern void cpp_init_builtins (cpp_reader *, int);
extern void cpp_post_options (cpp_reader *);
extern void cpp_init_iconv (cpp_reader *);
extern void cpp_finish (cpp_reader *, FILE *deps_stream);
extern void cpp_destroy (cpp_reader *);
extern unsigned int cpp_token_len (const cpp_token *);
extern unsigned char *cpp_token_as_text (cpp_reader *, const cpp_token *);
extern unsigned char *cpp_spell_token (cpp_reader *, const cpp_token *,
           unsigned char *, unsigned char);
extern void cpp_register_pragma (cpp_reader *, const char *, const char *,
     void (*) (cpp_reader *), unsigned char);
extern void cpp_register_deferred_pragma (cpp_reader *, const char *,
       const char *, unsigned, unsigned char, unsigned char);
extern int cpp_avoid_paste (cpp_reader *, const cpp_token *,
       const cpp_token *);
extern const cpp_token *cpp_get_token (cpp_reader *);
extern const cpp_token *cpp_get_token_with_location (cpp_reader *,
           source_location *);
extern const unsigned char *cpp_macro_definition (cpp_reader *,
        cpp_hashnode *);
extern void _cpp_backup_tokens (cpp_reader *, unsigned int);
extern const cpp_token *cpp_peek_token (cpp_reader *, int);
extern cppchar_t cpp_interpret_charconst (cpp_reader *, const cpp_token *,
       unsigned int *, int *);
extern unsigned char cpp_interpret_string (cpp_reader *,
      const cpp_string *, size_t,
      cpp_string *, enum cpp_ttype);
extern unsigned char cpp_interpret_string_notranslate (cpp_reader *,
           const cpp_string *, size_t,
           cpp_string *, enum cpp_ttype);
extern cppchar_t cpp_host_to_exec_charset (cpp_reader *, cppchar_t);
extern void cpp_define (cpp_reader *, const char *);
extern void cpp_define_formatted (cpp_reader *pfile,
      const char *fmt, ...) __attribute__ ((__format__ (__printf__, 2, 3))) __attribute__ ((__nonnull__ (2)));
extern void cpp_assert (cpp_reader *, const char *);
extern void cpp_undef (cpp_reader *, const char *);
extern void cpp_unassert (cpp_reader *, const char *);
extern void cpp_undef_all (cpp_reader *);
extern cpp_buffer *cpp_push_buffer (cpp_reader *, const unsigned char *,
        size_t, int);
extern int cpp_defined (cpp_reader *, const unsigned char *, int);
typedef unsigned long long cpp_num_part;
typedef struct cpp_num cpp_num;
struct cpp_num
{
  cpp_num_part high;
  cpp_num_part low;
  unsigned char unsignedp;
  unsigned char overflow;
};
# 849 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cpplib.h"
extern unsigned cpp_classify_number (cpp_reader *, const cpp_token *,
         const char **);
extern unsigned int cpp_interpret_float_suffix (const char *, size_t);
extern unsigned int cpp_interpret_int_suffix (const char *, size_t);
extern cpp_num cpp_interpret_integer (cpp_reader *, const cpp_token *,
          unsigned int);
cpp_num cpp_num_sign_extend (cpp_num, size_t);
enum {
  CPP_DL_WARNING = 0,
  CPP_DL_WARNING_SYSHDR,
  CPP_DL_PEDWARN,
  CPP_DL_ERROR,
  CPP_DL_ICE,
  CPP_DL_NOTE,
  CPP_DL_FATAL
};
enum {
  CPP_W_NONE = 0,
  CPP_W_DEPRECATED,
  CPP_W_COMMENTS,
  CPP_W_MISSING_INCLUDE_DIRS,
  CPP_W_TRIGRAPHS,
  CPP_W_MULTICHAR,
  CPP_W_TRADITIONAL,
  CPP_W_LONG_LONG,
  CPP_W_ENDIF_LABELS,
  CPP_W_NUM_SIGN_CHANGE,
  CPP_W_VARIADIC_MACROS,
  CPP_W_BUILTIN_MACRO_REDEFINED,
  CPP_W_DOLLARS,
  CPP_W_UNDEF,
  CPP_W_UNUSED_MACROS,
  CPP_W_CXX_OPERATOR_NAMES,
  CPP_W_NORMALIZE,
  CPP_W_INVALID_PCH,
  CPP_W_WARNING_DIRECTIVE
};
extern unsigned char cpp_error (cpp_reader *, int, const char *msgid, ...)
  __attribute__ ((__format__ (__printf__, 3, 4))) __attribute__ ((__nonnull__ (3)));
extern unsigned char cpp_warning (cpp_reader *, int, const char *msgid, ...)
  __attribute__ ((__format__ (__printf__, 3, 4))) __attribute__ ((__nonnull__ (3)));
extern unsigned char cpp_pedwarning (cpp_reader *, int, const char *msgid, ...)
  __attribute__ ((__format__ (__printf__, 3, 4))) __attribute__ ((__nonnull__ (3)));
extern unsigned char cpp_warning_syshdr (cpp_reader *, int, const char *msgid, ...)
  __attribute__ ((__format__ (__printf__, 3, 4))) __attribute__ ((__nonnull__ (3)));
extern unsigned char cpp_errno (cpp_reader *, int, const char *msgid);
extern unsigned char cpp_error_with_line (cpp_reader *, int, source_location,
                                 unsigned, const char *msgid, ...)
  __attribute__ ((__format__ (__printf__, 5, 6))) __attribute__ ((__nonnull__ (5)));
extern unsigned char cpp_warning_with_line (cpp_reader *, int, source_location,
                                   unsigned, const char *msgid, ...)
  __attribute__ ((__format__ (__printf__, 5, 6))) __attribute__ ((__nonnull__ (5)));
extern unsigned char cpp_pedwarning_with_line (cpp_reader *, int, source_location,
                                      unsigned, const char *msgid, ...)
  __attribute__ ((__format__ (__printf__, 5, 6))) __attribute__ ((__nonnull__ (5)));
extern unsigned char cpp_warning_with_line_syshdr (cpp_reader *, int, source_location,
                                          unsigned, const char *msgid, ...)
  __attribute__ ((__format__ (__printf__, 5, 6))) __attribute__ ((__nonnull__ (5)));
extern int cpp_ideq (const cpp_token *, const char *);
extern void cpp_output_line (cpp_reader *, FILE *);
extern unsigned char *cpp_output_line_to_string (cpp_reader *,
       const unsigned char *);
extern void cpp_output_token (const cpp_token *, FILE *);
extern const char *cpp_type2name (enum cpp_ttype, unsigned char flags);
extern cppchar_t cpp_parse_escape (cpp_reader *, const unsigned char ** pstr,
       const unsigned char *limit, int wide);
typedef struct
{
  char *comment;
  source_location sloc;
} cpp_comment;
typedef struct
{
  cpp_comment *entries;
  int count;
  int allocated;
} cpp_comment_table;
extern cpp_comment_table *cpp_get_comments (cpp_reader *);
extern cpp_hashnode *cpp_lookup (cpp_reader *, const unsigned char *,
     unsigned int);
typedef int (*cpp_cb) (cpp_reader *, cpp_hashnode *, void *);
extern void cpp_forall_identifiers (cpp_reader *, cpp_cb, void *);
extern void cpp_scan_nooutput (cpp_reader *);
extern int cpp_sys_macro_p (cpp_reader *);
extern unsigned char *cpp_quote_string (unsigned char *, const unsigned char *,
     unsigned int);
extern unsigned char cpp_included (cpp_reader *, const char *);
extern unsigned char cpp_included_before (cpp_reader *, const char *, source_location);
extern void cpp_make_system_header (cpp_reader *, int, int);
extern unsigned char cpp_push_include (cpp_reader *, const char *);
extern void cpp_change_file (cpp_reader *, enum lc_reason, const char *);
extern const char *cpp_get_path (struct _cpp_file *);
extern cpp_dir *cpp_get_dir (struct _cpp_file *);
extern cpp_buffer *cpp_get_buffer (cpp_reader *);
extern struct _cpp_file *cpp_get_file (cpp_buffer *);
extern cpp_buffer *cpp_get_prev (cpp_buffer *);
extern void cpp_clear_file_cache (cpp_reader *);
struct save_macro_data;
extern int cpp_save_state (cpp_reader *, FILE *);
extern int cpp_write_pch_deps (cpp_reader *, FILE *);
extern int cpp_write_pch_state (cpp_reader *, FILE *);
extern int cpp_valid_state (cpp_reader *, const char *, int);
extern void cpp_prepare_state (cpp_reader *, struct save_macro_data **);
extern int cpp_read_state (cpp_reader *, const char *, FILE *,
      struct save_macro_data *);
extern void cpp_force_token_locations (cpp_reader *, source_location *);
extern void cpp_stop_forcing_token_locations (cpp_reader *);
extern enum cpp_ttype cpp_userdef_string_remove_type
  (enum cpp_ttype type);
extern enum cpp_ttype cpp_userdef_string_add_type
  (enum cpp_ttype type);
extern enum cpp_ttype cpp_userdef_char_remove_type
  (enum cpp_ttype type);
extern enum cpp_ttype cpp_userdef_char_add_type
  (enum cpp_ttype type);
extern unsigned char cpp_userdef_string_p
  (enum cpp_ttype type);
extern unsigned char cpp_userdef_char_p
  (enum cpp_ttype type);
extern const char * cpp_get_userdef_suffix
  (const cpp_token *);
# 25 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-pragma.h" 2
typedef enum pragma_kind {
  PRAGMA_NONE = 0,
  PRAGMA_OMP_ATOMIC,
  PRAGMA_OMP_BARRIER,
  PRAGMA_OMP_CRITICAL,
  PRAGMA_OMP_FLUSH,
  PRAGMA_OMP_FOR,
  PRAGMA_OMP_MASTER,
  PRAGMA_OMP_ORDERED,
  PRAGMA_OMP_PARALLEL,
  PRAGMA_OMP_PARALLEL_FOR,
  PRAGMA_OMP_PARALLEL_SECTIONS,
  PRAGMA_OMP_SECTION,
  PRAGMA_OMP_SECTIONS,
  PRAGMA_OMP_SINGLE,
  PRAGMA_OMP_TASK,
  PRAGMA_OMP_TASKWAIT,
  PRAGMA_OMP_TASKYIELD,
  PRAGMA_OMP_THREADPRIVATE,
  PRAGMA_GCC_PCH_PREPROCESS,
  PRAGMA_FIRST_EXTERNAL
} pragma_kind;
typedef enum pragma_omp_clause {
  PRAGMA_OMP_CLAUSE_NONE = 0,
  PRAGMA_OMP_CLAUSE_COLLAPSE,
  PRAGMA_OMP_CLAUSE_COPYIN,
  PRAGMA_OMP_CLAUSE_COPYPRIVATE,
  PRAGMA_OMP_CLAUSE_DEFAULT,
  PRAGMA_OMP_CLAUSE_FIRSTPRIVATE,
  PRAGMA_OMP_CLAUSE_IF,
  PRAGMA_OMP_CLAUSE_LASTPRIVATE,
  PRAGMA_OMP_CLAUSE_NOWAIT,
  PRAGMA_OMP_CLAUSE_NUM_THREADS,
  PRAGMA_OMP_CLAUSE_ORDERED,
  PRAGMA_OMP_CLAUSE_PRIVATE,
  PRAGMA_OMP_CLAUSE_REDUCTION,
  PRAGMA_OMP_CLAUSE_SCHEDULE,
  PRAGMA_OMP_CLAUSE_SHARED,
  PRAGMA_OMP_CLAUSE_UNTIED,
  PRAGMA_OMP_CLAUSE_FINAL,
  PRAGMA_OMP_CLAUSE_MERGEABLE
} pragma_omp_clause;
extern struct cpp_reader* parse_in;
extern void push_visibility (const char *, int);
extern unsigned char pop_visibility (int);
extern void init_pragma (void);
typedef void (*pragma_handler_1arg)(struct cpp_reader *);
typedef void (*pragma_handler_2arg)(struct cpp_reader *, void *);
union gen_pragma_handler {
  pragma_handler_1arg handler_1arg;
  pragma_handler_2arg handler_2arg;
};
struct internal_pragma_handler_d {
  union gen_pragma_handler handler;
  unsigned char extra_data;
  void * data;
};
typedef struct internal_pragma_handler_d internal_pragma_handler;
extern void c_register_pragma (const char *space, const char *name,
                               pragma_handler_1arg handler);
extern void c_register_pragma_with_data (const char *space, const char *name,
                                         pragma_handler_2arg handler,
                                         void *data);
extern void c_register_pragma_with_expansion (const char *space,
                                              const char *name,
                                              pragma_handler_1arg handler);
extern void c_register_pragma_with_expansion_and_data (const char *space,
                                                       const char *name,
                                                   pragma_handler_2arg handler,
                                                       void *data);
extern void c_invoke_pragma_handler (unsigned int);
extern void maybe_apply_pragma_weak (tree);
extern void maybe_apply_pending_pragma_weaks (void);
extern tree maybe_apply_renaming_pragma (tree, tree);
extern void add_to_renaming_pragma_list (tree, tree);
extern enum cpp_ttype pragma_lex (tree *);
# 144 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-pragma.h"
extern enum cpp_ttype c_lex_with_flags (tree *, location_t *, unsigned char *,
     int);
extern void c_pp_lookup_pragma (unsigned int, const char **, const char **);
extern tree pragma_extern_prefix;
# 39 "../../../src/plugin-utils.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h" 1
# 25 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/splay-tree.h" 1
# 41 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/splay-tree.h"
  typedef unsigned long int libi_uhostptr_t;
  typedef long int libi_shostptr_t;
# 62 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/splay-tree.h"
typedef libi_uhostptr_t splay_tree_key;
typedef libi_uhostptr_t splay_tree_value;
typedef struct splay_tree_node_s *splay_tree_node;
typedef int (*splay_tree_compare_fn) (splay_tree_key, splay_tree_key);
typedef void (*splay_tree_delete_key_fn) (splay_tree_key);
typedef void (*splay_tree_delete_value_fn) (splay_tree_value);
typedef int (*splay_tree_foreach_fn) (splay_tree_node, void*);
typedef void *(*splay_tree_allocate_fn) (int, void *);
typedef void (*splay_tree_deallocate_fn) (void *, void *);
struct splay_tree_node_s {
  splay_tree_key key;
  splay_tree_value value;
  splay_tree_node left;
  splay_tree_node right;
};
struct splay_tree_s {
  splay_tree_node root;
  splay_tree_compare_fn comp;
  splay_tree_delete_key_fn delete_key;
  splay_tree_delete_value_fn delete_value;
  splay_tree_allocate_fn allocate;
  splay_tree_deallocate_fn deallocate;
  void * allocate_data;
};
typedef struct splay_tree_s *splay_tree;
extern splay_tree splay_tree_new (splay_tree_compare_fn,
      splay_tree_delete_key_fn,
      splay_tree_delete_value_fn);
extern splay_tree splay_tree_new_with_allocator (splay_tree_compare_fn,
       splay_tree_delete_key_fn,
       splay_tree_delete_value_fn,
       splay_tree_allocate_fn,
       splay_tree_deallocate_fn,
       void *);
extern splay_tree splay_tree_new_typed_alloc (splay_tree_compare_fn,
           splay_tree_delete_key_fn,
           splay_tree_delete_value_fn,
           splay_tree_allocate_fn,
           splay_tree_allocate_fn,
           splay_tree_deallocate_fn,
           void *);
extern void splay_tree_delete (splay_tree);
extern splay_tree_node splay_tree_insert (splay_tree,
       splay_tree_key,
       splay_tree_value);
extern void splay_tree_remove (splay_tree, splay_tree_key);
extern splay_tree_node splay_tree_lookup (splay_tree, splay_tree_key);
extern splay_tree_node splay_tree_predecessor (splay_tree, splay_tree_key);
extern splay_tree_node splay_tree_successor (splay_tree, splay_tree_key);
extern splay_tree_node splay_tree_max (splay_tree);
extern splay_tree_node splay_tree_min (splay_tree);
extern int splay_tree_foreach (splay_tree, splay_tree_foreach_fn, void*);
extern int splay_tree_compare_ints (splay_tree_key, splay_tree_key);
extern int splay_tree_compare_pointers (splay_tree_key, splay_tree_key);
# 26 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/ggc.h" 1
# 30 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/ggc.h"
extern const char empty_string[];
typedef void (*gt_pointer_operator) (void *, void *);
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gtype-desc.h" 1
# 23 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gtype-desc.h"
enum gt_types_enum {
 gt_ggc_e_24lazy_hex_fp_value_struct,
 gt_ggc_e_15c_inline_static,
 gt_ggc_e_24VEC_c_goto_bindings_p_gc,
 gt_ggc_e_26VEC_c_goto_bindings_p_base,
 gt_ggc_e_15c_goto_bindings,
 gt_ggc_e_7c_scope,
 gt_ggc_e_9c_binding,
 gt_ggc_e_12c_label_vars,
 gt_ggc_e_15c_spot_bindings,
 gt_ggc_e_8c_parser,
 gt_ggc_e_7c_token,
 gt_ggc_e_20VEC_ivarref_entry_gc,
 gt_ggc_e_22VEC_ivarref_entry_base,
 gt_ggc_e_13ivarref_entry,
 gt_ggc_e_22VEC_prot_list_entry_gc,
 gt_ggc_e_24VEC_prot_list_entry_base,
 gt_ggc_e_15prot_list_entry,
 gt_ggc_e_19VEC_msgref_entry_gc,
 gt_ggc_e_21VEC_msgref_entry_base,
 gt_ggc_e_12msgref_entry,
 gt_ggc_e_23VEC_ident_data_tuple_gc,
 gt_ggc_e_25VEC_ident_data_tuple_base,
 gt_ggc_e_16ident_data_tuple,
 gt_ggc_e_17string_descriptor,
 gt_ggc_e_9imp_entry,
 gt_ggc_e_16hashed_attribute,
 gt_ggc_e_12hashed_entry,
 gt_ggc_e_16objc_map_private,
 gt_ggc_e_14builtin_record,
 gt_ggc_e_14string_or_tree,
 gt_ggc_e_11cpool_entry,
 gt_ggc_e_19VEC_method_entry_gc,
 gt_ggc_e_21VEC_method_entry_base,
 gt_ggc_e_14method_entry_d,
 gt_ggc_e_13lang_decl_var,
 gt_ggc_e_14type_assertion,
 gt_ggc_e_14lang_decl_func,
 gt_ggc_e_18treetreehash_entry,
 gt_ggc_e_5CPool,
 gt_ggc_e_3JCF,
 gt_ggc_e_16gfc_powdecl_list,
 gt_ggc_e_16gfc_st_parameter,
 gt_ggc_e_22gfc_st_parameter_field,
 gt_ggc_e_19gfc_intrinsic_map_t,
 gt_ggc_e_17module_htab_entry,
 gt_ggc_e_13binding_level,
 gt_ggc_e_23VEC_pending_noexcept_gc,
 gt_ggc_e_25VEC_pending_noexcept_base,
 gt_ggc_e_16pending_noexcept,
 gt_ggc_e_9opt_stack,
 gt_ggc_e_27VEC_pending_redefinition_gc,
 gt_ggc_e_29VEC_pending_redefinition_base,
 gt_ggc_e_22pending_redefinition_d,
 gt_ggc_e_19VEC_pending_weak_gc,
 gt_ggc_e_21VEC_pending_weak_base,
 gt_ggc_e_14pending_weak_d,
 gt_ggc_e_11align_stack,
 gt_ggc_e_18VEC_tree_gc_vec_gc,
 gt_ggc_e_20VEC_tree_gc_vec_base,
 gt_ggc_e_19VEC_const_char_p_gc,
 gt_ggc_e_21VEC_const_char_p_base,
 gt_ggc_e_21pending_abstract_type,
 gt_ggc_e_15VEC_tree_int_gc,
 gt_ggc_e_17VEC_tree_int_base,
 gt_ggc_e_8tree_int,
 gt_ggc_e_9cp_parser,
 gt_ggc_e_17cp_parser_context,
 gt_ggc_e_34VEC_cp_unparsed_functions_entry_gc,
 gt_ggc_e_36VEC_cp_unparsed_functions_entry_base,
 gt_ggc_e_29cp_unparsed_functions_entry_d,
 gt_ggc_e_27VEC_cp_default_arg_entry_gc,
 gt_ggc_e_29VEC_cp_default_arg_entry_base,
 gt_ggc_e_22cp_default_arg_entry_d,
 gt_ggc_e_8cp_lexer,
 gt_ggc_e_15VEC_cp_token_gc,
 gt_ggc_e_17VEC_cp_token_base,
 gt_ggc_e_8cp_token,
 gt_ggc_e_14cp_token_value,
 gt_ggc_e_10tree_check,
 gt_ggc_e_14constexpr_call,
 gt_ggc_e_16constexpr_fundef,
 gt_ggc_e_22VEC_deferred_access_gc,
 gt_ggc_e_24VEC_deferred_access_base,
 gt_ggc_e_15deferred_access,
 gt_ggc_e_10spec_entry,
 gt_ggc_e_16pending_template,
 gt_ggc_e_21VEC_incomplete_var_gc,
 gt_ggc_e_23VEC_incomplete_var_base,
 gt_ggc_e_16incomplete_var_d,
 gt_ggc_e_21named_label_use_entry,
 gt_ggc_e_28VEC_deferred_access_check_gc,
 gt_ggc_e_30VEC_deferred_access_check_base,
 gt_ggc_e_21deferred_access_check,
 gt_ggc_e_20operator_name_info_t,
 gt_ggc_e_11lang_decl_u,
 gt_ggc_e_14lang_decl_parm,
 gt_ggc_e_12lang_decl_ns,
 gt_ggc_e_12lang_decl_fn,
 gt_ggc_e_12lang_decl_u3,
 gt_ggc_e_12lang_decl_u5,
 gt_ggc_e_13lang_decl_min,
 gt_ggc_e_12lang_decl_u2,
 gt_ggc_e_14lang_decl_base,
 gt_ggc_e_11lang_type_u,
 gt_ggc_e_16lang_type_ptrmem,
 gt_ggc_e_15lang_type_class,
 gt_ggc_e_18sorted_fields_type,
 gt_ggc_e_16lang_type_header,
 gt_ggc_e_18VEC_tree_pair_s_gc,
 gt_ggc_e_20VEC_tree_pair_s_base,
 gt_ggc_e_11tree_pair_s,
 gt_ggc_e_17named_label_entry,
 gt_ggc_e_19c_language_function,
 gt_ggc_e_11stmt_tree_s,
 gt_ggc_e_20tree_userdef_literal,
 gt_ggc_e_18tree_template_info,
 gt_ggc_e_32VEC_qualified_typedef_usage_t_gc,
 gt_ggc_e_34VEC_qualified_typedef_usage_t_base,
 gt_ggc_e_25qualified_typedef_usage_s,
 gt_ggc_e_16tree_lambda_expr,
 gt_ggc_e_15tree_trait_expr,
 gt_ggc_e_25tree_argument_pack_select,
 gt_ggc_e_18tree_static_assert,
 gt_ggc_e_22tree_deferred_noexcept,
 gt_ggc_e_16tree_default_arg,
 gt_ggc_e_14cp_token_cache,
 gt_ggc_e_13tree_baselink,
 gt_ggc_e_13tree_overload,
 gt_ggc_e_10ptrmem_cst,
 gt_ggc_e_21template_parm_index_s,
 gt_ggc_e_15lang_identifier,
 gt_ggc_e_19c_common_identifier,
 gt_ggc_e_11saved_scope,
 gt_ggc_e_16cxx_int_tree_map,
 gt_ggc_e_23VEC_cp_label_binding_gc,
 gt_ggc_e_25VEC_cp_label_binding_base,
 gt_ggc_e_16cp_label_binding,
 gt_ggc_e_23VEC_cp_class_binding_gc,
 gt_ggc_e_25VEC_cp_class_binding_base,
 gt_ggc_e_16cp_class_binding,
 gt_ggc_e_24VEC_cxx_saved_binding_gc,
 gt_ggc_e_26VEC_cxx_saved_binding_base,
 gt_ggc_e_17cxx_saved_binding,
 gt_ggc_e_16cp_binding_level,
 gt_ggc_e_11cxx_binding,
 gt_ggc_e_15binding_entry_s,
 gt_ggc_e_15binding_table_s,
 gt_ggc_e_11tinst_level,
 gt_ggc_e_7globals,
 gt_ggc_e_14VEC_tinfo_s_gc,
 gt_ggc_e_16VEC_tinfo_s_base,
 gt_ggc_e_7tinfo_s,
 gt_ggc_e_18gnat_binding_level,
 gt_ggc_e_16VEC_loop_info_gc,
 gt_ggc_e_18VEC_loop_info_base,
 gt_ggc_e_11loop_info_d,
 gt_ggc_e_23VEC_range_check_info_gc,
 gt_ggc_e_25VEC_range_check_info_base,
 gt_ggc_e_18range_check_info_d,
 gt_ggc_e_9elab_info,
 gt_ggc_e_10stmt_group,
 gt_ggc_e_16VEC_parm_attr_gc,
 gt_ggc_e_18VEC_parm_attr_base,
 gt_ggc_e_11parm_attr_d,
 gt_ggc_e_23VEC_inline_summary_t_gc,
 gt_ggc_e_25VEC_inline_summary_t_base,
 gt_ggc_e_22VEC_size_time_entry_gc,
 gt_ggc_e_24VEC_size_time_entry_base,
 gt_ggc_e_15size_time_entry,
 gt_ggc_e_9predicate,
 gt_ggc_e_16VEC_condition_gc,
 gt_ggc_e_18VEC_condition_base,
 gt_ggc_e_9condition,
 gt_ggc_e_18lto_tree_ref_table,
 gt_ggc_e_17lto_in_decl_state,
 gt_ggc_e_22VEC_ipa_edge_args_t_gc,
 gt_ggc_e_24VEC_ipa_edge_args_t_base,
 gt_ggc_e_22VEC_ipa_jump_func_t_gc,
 gt_ggc_e_24VEC_ipa_jump_func_t_base,
 gt_ggc_e_15jump_func_value,
 gt_ggc_e_18ipa_member_ptr_cst,
 gt_ggc_e_20ipa_ancestor_jf_data,
 gt_ggc_e_21ipa_pass_through_data,
 gt_ggc_e_19ipa_known_type_data,
 gt_ggc_e_20lto_symtab_entry_def,
 gt_ggc_e_20ssa_operand_memory_d,
 gt_ggc_e_13scev_info_str,
 gt_ggc_e_24VEC_mem_addr_template_gc,
 gt_ggc_e_26VEC_mem_addr_template_base,
 gt_ggc_e_17mem_addr_template,
 gt_ggc_e_12ssa_operands,
 gt_ggc_e_15tm_restart_node,
 gt_ggc_e_26gimple_type_leader_entry_s,
 gt_ggc_e_28gimple_statement_transaction,
 gt_ggc_e_33gimple_statement_omp_atomic_store,
 gt_ggc_e_32gimple_statement_omp_atomic_load,
 gt_ggc_e_27gimple_statement_omp_single,
 gt_ggc_e_29gimple_statement_omp_continue,
 gt_ggc_e_29gimple_statement_omp_sections,
 gt_ggc_e_25gimple_statement_omp_task,
 gt_ggc_e_29gimple_statement_omp_parallel,
 gt_ggc_e_24gimple_statement_omp_for,
 gt_ggc_e_19gimple_omp_for_iter,
 gt_ggc_e_29gimple_statement_omp_critical,
 gt_ggc_e_20gimple_statement_asm,
 gt_ggc_e_20gimple_statement_wce,
 gt_ggc_e_20gimple_statement_try,
 gt_ggc_e_24gimple_statement_eh_ctrl,
 gt_ggc_e_20gimple_statement_phi,
 gt_ggc_e_23gimple_statement_eh_mnt,
 gt_ggc_e_24gimple_statement_eh_else,
 gt_ggc_e_26gimple_statement_eh_filter,
 gt_ggc_e_22gimple_statement_catch,
 gt_ggc_e_21gimple_statement_bind,
 gt_ggc_e_20gimple_statement_omp,
 gt_ggc_e_21gimple_statement_call,
 gt_ggc_e_11pt_solution,
 gt_ggc_e_32gimple_statement_with_memory_ops,
 gt_ggc_e_37gimple_statement_with_memory_ops_base,
 gt_ggc_e_25gimple_statement_with_ops,
 gt_ggc_e_30gimple_statement_with_ops_base,
 gt_ggc_e_21gimple_statement_base,
 gt_ggc_e_17gimple_seq_node_d,
 gt_ggc_e_9type_hash,
 gt_ggc_e_16string_pool_data,
 gt_ggc_e_18initial_value_pair,
 gt_ggc_e_23temp_slot_address_entry,
 gt_ggc_e_11eh_status_u,
 gt_ggc_e_15throw_stmt_node,
 gt_ggc_e_21VEC_eh_landing_pad_gc,
 gt_ggc_e_23VEC_eh_landing_pad_base,
 gt_ggc_e_16VEC_eh_region_gc,
 gt_ggc_e_18VEC_eh_region_base,
 gt_ggc_e_11eh_region_u,
 gt_ggc_e_26eh_region_u_must_not_throw,
 gt_ggc_e_19eh_region_u_allowed,
 gt_ggc_e_15eh_region_u_try,
 gt_ggc_e_10eh_catch_d,
 gt_ggc_e_16eh_landing_pad_d,
 gt_ggc_e_11eh_region_d,
 gt_ggc_e_22cached_dw_loc_list_def,
 gt_ggc_e_17call_arg_loc_node,
 gt_ggc_e_16var_loc_list_def,
 gt_ggc_e_12var_loc_node,
 gt_ggc_e_20VEC_die_arg_entry_gc,
 gt_ggc_e_22VEC_die_arg_entry_base,
 gt_ggc_e_20die_arg_entry_struct,
 gt_ggc_e_16limbo_die_struct,
 gt_ggc_e_20VEC_macinfo_entry_gc,
 gt_ggc_e_22VEC_macinfo_entry_base,
 gt_ggc_e_14macinfo_struct,
 gt_ggc_e_20VEC_pubname_entry_gc,
 gt_ggc_e_22VEC_pubname_entry_base,
 gt_ggc_e_23die_symbol_or_type_node,
 gt_ggc_e_19VEC_dw_attr_node_gc,
 gt_ggc_e_21VEC_dw_attr_node_base,
 gt_ggc_e_27VEC_dw_line_info_table_p_gc,
 gt_ggc_e_29VEC_dw_line_info_table_p_base,
 gt_ggc_e_25dw_line_info_table_struct,
 gt_ggc_e_25VEC_dw_line_info_entry_gc,
 gt_ggc_e_27VEC_dw_line_info_entry_base,
 gt_ggc_e_18comdat_type_struct,
 gt_ggc_e_25dw_ranges_by_label_struct,
 gt_ggc_e_16dw_ranges_struct,
 gt_ggc_e_14pubname_struct,
 gt_ggc_e_19dw_line_info_struct,
 gt_ggc_e_14dw_attr_struct,
 gt_ggc_e_25VEC_deferred_locations_gc,
 gt_ggc_e_27VEC_deferred_locations_base,
 gt_ggc_e_25deferred_locations_struct,
 gt_ggc_e_17VEC_dw_fde_ref_gc,
 gt_ggc_e_19VEC_dw_fde_ref_base,
 gt_ggc_e_24reg_saved_in_data_struct,
 gt_ggc_e_17dw_cfi_row_struct,
 gt_ggc_e_19dw_val_struct_union,
 gt_ggc_e_22dw_val_vms_delta_union,
 gt_ggc_e_15dwarf_file_data,
 gt_ggc_e_20indirect_string_node,
 gt_ggc_e_16dw_val_die_union,
 gt_ggc_e_13dw_vec_struct,
 gt_ggc_e_7cfa_loc,
 gt_ggc_e_17VEC_dw_cfi_ref_gc,
 gt_ggc_e_19VEC_dw_cfi_ref_base,
 gt_ggc_e_19dw_cfi_oprnd_struct,
 gt_ggc_e_18dw_loc_list_struct,
 gt_ggc_e_19dw_loc_descr_struct,
 gt_ggc_e_13dw_cfi_struct,
 gt_ggc_e_13dw_val_struct,
 gt_ggc_e_8typeinfo,
 gt_ggc_e_14inline_summary,
 gt_ggc_e_13ipa_edge_args,
 gt_ggc_e_13ipa_jump_func,
 gt_ggc_e_22VEC_alias_set_entry_gc,
 gt_ggc_e_24VEC_alias_set_entry_base,
 gt_ggc_e_17alias_set_entry_d,
 gt_ggc_e_24constant_descriptor_tree,
 gt_ggc_e_15cgraph_asm_node,
 gt_ggc_e_25cgraph_indirect_call_info,
 gt_ggc_e_11cgraph_edge,
 gt_ggc_e_17cgraph_clone_info,
 gt_ggc_e_24VEC_ipa_replace_map_p_gc,
 gt_ggc_e_26VEC_ipa_replace_map_p_base,
 gt_ggc_e_15ipa_replace_map,
 gt_ggc_e_15cgraph_rtl_info,
 gt_ggc_e_18cgraph_global_info,
 gt_ggc_e_17cgraph_local_info,
 gt_ggc_e_17cgraph_thunk_info,
 gt_ggc_e_18lto_file_decl_data,
 gt_ggc_e_12ipa_ref_list,
 gt_ggc_e_16VEC_ipa_ref_t_gc,
 gt_ggc_e_18VEC_ipa_ref_t_base,
 gt_ggc_e_7ipa_ref,
 gt_ggc_e_13ipa_ref_ptr_u,
 gt_ggc_e_12varpool_node,
 gt_ggc_e_11cgraph_node,
 gt_ggc_e_18VEC_basic_block_gc,
 gt_ggc_e_20VEC_basic_block_base,
 gt_ggc_e_24basic_block_il_dependent,
 gt_ggc_e_14gimple_bb_info,
 gt_ggc_e_11rtl_bb_info,
 gt_ggc_e_11VEC_edge_gc,
 gt_ggc_e_13VEC_edge_base,
 gt_ggc_e_14edge_def_insns,
 gt_ggc_e_13VEC_loop_p_gc,
 gt_ggc_e_15VEC_loop_p_base,
 gt_ggc_e_4loop,
 gt_ggc_e_9loop_exit,
 gt_ggc_e_13nb_iter_bound,
 gt_ggc_e_12lpt_decision,
 gt_ggc_e_16noswitch_section,
 gt_ggc_e_15unnamed_section,
 gt_ggc_e_13named_section,
 gt_ggc_e_14section_common,
 gt_ggc_e_24types_used_by_vars_entry,
 gt_ggc_e_17language_function,
 gt_ggc_e_5loops,
 gt_ggc_e_18control_flow_graph,
 gt_ggc_e_9eh_status,
 gt_ggc_e_11stack_usage,
 gt_ggc_e_8rtl_data,
 gt_ggc_e_20initial_value_struct,
 gt_ggc_e_11frame_space,
 gt_ggc_e_20function_subsections,
 gt_ggc_e_13incoming_args,
 gt_ggc_e_13varasm_status,
 gt_ggc_e_17rtx_constant_pool,
 gt_ggc_e_18VEC_temp_slot_p_gc,
 gt_ggc_e_20VEC_temp_slot_p_base,
 gt_ggc_e_13dw_fde_struct,
 gt_ggc_e_9temp_slot,
 gt_ggc_e_9gimple_df,
 gt_ggc_e_6rtl_eh,
 gt_ggc_e_23VEC_call_site_record_gc,
 gt_ggc_e_25VEC_call_site_record_base,
 gt_ggc_e_18call_site_record_d,
 gt_ggc_e_11expr_status,
 gt_ggc_e_11emit_status,
 gt_ggc_e_14sequence_stack,
 gt_ggc_e_15target_libfuncs,
 gt_ggc_e_13libfunc_entry,
 gt_ggc_e_19builtin_info_type_d,
 gt_ggc_e_12tree_vec_map,
 gt_ggc_e_17tree_priority_map,
 gt_ggc_e_12tree_int_map,
 gt_ggc_e_13tree_decl_map,
 gt_ggc_e_8tree_map,
 gt_ggc_e_13tree_map_base,
 gt_ggc_e_14lang_tree_node,
 gt_ggc_e_18tree_target_option,
 gt_ggc_e_24tree_optimization_option,
 gt_ggc_e_19tree_statement_list,
 gt_ggc_e_24tree_statement_list_node,
 gt_ggc_e_14tree_type_decl,
 gt_ggc_e_26tree_translation_unit_decl,
 gt_ggc_e_18tree_function_decl,
 gt_ggc_e_20tree_decl_non_common,
 gt_ggc_e_13tree_var_decl,
 gt_ggc_e_18tree_decl_with_vis,
 gt_ggc_e_14tree_parm_decl,
 gt_ggc_e_15tree_const_decl,
 gt_ggc_e_16tree_result_decl,
 gt_ggc_e_9var_ann_d,
 gt_ggc_e_15tree_label_decl,
 gt_ggc_e_15tree_field_decl,
 gt_ggc_e_18tree_decl_with_rtl,
 gt_ggc_e_16tree_decl_common,
 gt_ggc_e_9lang_decl,
 gt_ggc_e_17tree_decl_minimal,
 gt_ggc_e_10tree_binfo,
 gt_ggc_e_20tree_type_non_common,
 gt_ggc_e_28tree_type_with_lang_specific,
 gt_ggc_e_9lang_type,
 gt_ggc_e_16tree_type_common,
 gt_ggc_e_16tree_type_symtab,
 gt_ggc_e_10die_struct,
 gt_ggc_e_10tree_block,
 gt_ggc_e_15tree_omp_clause,
 gt_ggc_e_9phi_arg_d,
 gt_ggc_e_13tree_ssa_name,
 gt_ggc_e_17ssa_use_operand_d,
 gt_ggc_e_12ptr_info_def,
 gt_ggc_e_8tree_exp,
 gt_ggc_e_17tree_exp_subunion,
 gt_ggc_e_16tree_constructor,
 gt_ggc_e_22VEC_constructor_elt_gc,
 gt_ggc_e_24VEC_constructor_elt_base,
 gt_ggc_e_17constructor_elt_d,
 gt_ggc_e_8tree_vec,
 gt_ggc_e_9tree_list,
 gt_ggc_e_15tree_identifier,
 gt_ggc_e_11tree_vector,
 gt_ggc_e_12tree_complex,
 gt_ggc_e_11tree_string,
 gt_ggc_e_14tree_fixed_cst,
 gt_ggc_e_13tree_real_cst,
 gt_ggc_e_12tree_int_cst,
 gt_ggc_e_11tree_common,
 gt_ggc_e_10tree_typed,
 gt_ggc_e_9tree_base,
 gt_ggc_e_17VEC_alias_pair_gc,
 gt_ggc_e_19VEC_alias_pair_base,
 gt_ggc_e_10alias_pair,
 gt_ggc_e_10target_rtl,
 gt_ggc_e_8function,
 gt_ggc_e_16rtx_def_subunion,
 gt_ggc_e_27rtx_def_debug_parameter_ref,
 gt_ggc_e_19rtx_def_entry_value,
 gt_ggc_e_26rtx_def_debug_implicit_ptr,
 gt_ggc_e_20rtx_def_var_location,
 gt_ggc_e_11rtx_def_fma,
 gt_ggc_e_19rtx_def_us_truncate,
 gt_ggc_e_19rtx_def_ss_truncate,
 gt_ggc_e_16rtx_def_us_minus,
 gt_ggc_e_17rtx_def_us_ashift,
 gt_ggc_e_17rtx_def_ss_ashift,
 gt_ggc_e_14rtx_def_ss_abs,
 gt_ggc_e_14rtx_def_us_neg,
 gt_ggc_e_14rtx_def_ss_neg,
 gt_ggc_e_16rtx_def_ss_minus,
 gt_ggc_e_15rtx_def_us_plus,
 gt_ggc_e_15rtx_def_ss_plus,
 gt_ggc_e_21rtx_def_vec_duplicate,
 gt_ggc_e_18rtx_def_vec_concat,
 gt_ggc_e_18rtx_def_vec_select,
 gt_ggc_e_17rtx_def_vec_merge,
 gt_ggc_e_14rtx_def_lo_sum,
 gt_ggc_e_12rtx_def_high,
 gt_ggc_e_20rtx_def_zero_extract,
 gt_ggc_e_20rtx_def_sign_extract,
 gt_ggc_e_14rtx_def_parity,
 gt_ggc_e_16rtx_def_popcount,
 gt_ggc_e_11rtx_def_ctz,
 gt_ggc_e_11rtx_def_clz,
 gt_ggc_e_13rtx_def_clrsb,
 gt_ggc_e_11rtx_def_ffs,
 gt_ggc_e_13rtx_def_bswap,
 gt_ggc_e_12rtx_def_sqrt,
 gt_ggc_e_11rtx_def_abs,
 gt_ggc_e_26rtx_def_unsigned_sat_fract,
 gt_ggc_e_17rtx_def_sat_fract,
 gt_ggc_e_30rtx_def_unsigned_fract_convert,
 gt_ggc_e_21rtx_def_fract_convert,
 gt_ggc_e_20rtx_def_unsigned_fix,
 gt_ggc_e_22rtx_def_unsigned_float,
 gt_ggc_e_11rtx_def_fix,
 gt_ggc_e_13rtx_def_float,
 gt_ggc_e_22rtx_def_float_truncate,
 gt_ggc_e_20rtx_def_float_extend,
 gt_ggc_e_16rtx_def_truncate,
 gt_ggc_e_19rtx_def_zero_extend,
 gt_ggc_e_19rtx_def_sign_extend,
 gt_ggc_e_12rtx_def_ltgt,
 gt_ggc_e_12rtx_def_unlt,
 gt_ggc_e_12rtx_def_unle,
 gt_ggc_e_12rtx_def_ungt,
 gt_ggc_e_12rtx_def_unge,
 gt_ggc_e_12rtx_def_uneq,
 gt_ggc_e_15rtx_def_ordered,
 gt_ggc_e_17rtx_def_unordered,
 gt_ggc_e_11rtx_def_ltu,
 gt_ggc_e_11rtx_def_leu,
 gt_ggc_e_11rtx_def_gtu,
 gt_ggc_e_11rtx_def_geu,
 gt_ggc_e_10rtx_def_lt,
 gt_ggc_e_10rtx_def_le,
 gt_ggc_e_10rtx_def_gt,
 gt_ggc_e_10rtx_def_ge,
 gt_ggc_e_10rtx_def_eq,
 gt_ggc_e_10rtx_def_ne,
 gt_ggc_e_19rtx_def_post_modify,
 gt_ggc_e_18rtx_def_pre_modify,
 gt_ggc_e_16rtx_def_post_inc,
 gt_ggc_e_16rtx_def_post_dec,
 gt_ggc_e_15rtx_def_pre_inc,
 gt_ggc_e_15rtx_def_pre_dec,
 gt_ggc_e_12rtx_def_umax,
 gt_ggc_e_12rtx_def_umin,
 gt_ggc_e_12rtx_def_smax,
 gt_ggc_e_12rtx_def_smin,
 gt_ggc_e_16rtx_def_rotatert,
 gt_ggc_e_16rtx_def_lshiftrt,
 gt_ggc_e_16rtx_def_ashiftrt,
 gt_ggc_e_14rtx_def_rotate,
 gt_ggc_e_14rtx_def_ashift,
 gt_ggc_e_11rtx_def_not,
 gt_ggc_e_11rtx_def_xor,
 gt_ggc_e_11rtx_def_ior,
 gt_ggc_e_11rtx_def_and,
 gt_ggc_e_12rtx_def_umod,
 gt_ggc_e_12rtx_def_udiv,
 gt_ggc_e_11rtx_def_mod,
 gt_ggc_e_14rtx_def_us_div,
 gt_ggc_e_14rtx_def_ss_div,
 gt_ggc_e_11rtx_def_div,
 gt_ggc_e_15rtx_def_us_mult,
 gt_ggc_e_15rtx_def_ss_mult,
 gt_ggc_e_12rtx_def_mult,
 gt_ggc_e_11rtx_def_neg,
 gt_ggc_e_13rtx_def_minus,
 gt_ggc_e_12rtx_def_plus,
 gt_ggc_e_15rtx_def_compare,
 gt_ggc_e_20rtx_def_if_then_else,
 gt_ggc_e_11rtx_def_cc0,
 gt_ggc_e_18rtx_def_symbol_ref,
 gt_ggc_e_12fake_union_1,
 gt_ggc_e_17rtx_def_label_ref,
 gt_ggc_e_11rtx_def_mem,
 gt_ggc_e_15rtx_def_concatn,
 gt_ggc_e_14rtx_def_concat,
 gt_ggc_e_23rtx_def_strict_low_part,
 gt_ggc_e_14rtx_def_subreg,
 gt_ggc_e_15rtx_def_scratch,
 gt_ggc_e_11rtx_def_reg,
 gt_ggc_e_10rtx_def_pc,
 gt_ggc_e_13rtx_def_const,
 gt_ggc_e_20rtx_def_const_string,
 gt_ggc_e_20rtx_def_const_vector,
 gt_ggc_e_20rtx_def_const_double,
 gt_ggc_e_19rtx_def_const_fixed,
 gt_ggc_e_17rtx_def_const_int,
 gt_ggc_e_15rtx_def_trap_if,
 gt_ggc_e_17rtx_def_eh_return,
 gt_ggc_e_21rtx_def_simple_return,
 gt_ggc_e_14rtx_def_return,
 gt_ggc_e_12rtx_def_call,
 gt_ggc_e_15rtx_def_clobber,
 gt_ggc_e_11rtx_def_use,
 gt_ggc_e_11rtx_def_set,
 gt_ggc_e_16rtx_def_prefetch,
 gt_ggc_e_21rtx_def_addr_diff_vec,
 gt_ggc_e_16rtx_def_addr_vec,
 gt_ggc_e_23rtx_def_unspec_volatile,
 gt_ggc_e_14rtx_def_unspec,
 gt_ggc_e_20rtx_def_asm_operands,
 gt_ggc_e_17rtx_def_asm_input,
 gt_ggc_e_16rtx_def_parallel,
 gt_ggc_e_17rtx_def_cond_exec,
 gt_ggc_e_12rtx_def_note,
 gt_ggc_e_18rtx_def_code_label,
 gt_ggc_e_15rtx_def_barrier,
 gt_ggc_e_17rtx_def_call_insn,
 gt_ggc_e_17rtx_def_jump_insn,
 gt_ggc_e_12rtx_def_insn,
 gt_ggc_e_18rtx_def_debug_insn,
 gt_ggc_e_15rtx_def_address,
 gt_ggc_e_16rtx_def_sequence,
 gt_ggc_e_17rtx_def_insn_list,
 gt_ggc_e_17rtx_def_expr_list,
 gt_ggc_e_18rtx_def_debug_expr,
 gt_ggc_e_13rtx_def_value,
 gt_ggc_e_15rtx_def_UnKnown,
 gt_ggc_e_23rtx_def_symbol_subunion,
 gt_ggc_e_21rtx_def_note_subunion,
 gt_ggc_e_23constant_descriptor_rtx,
 gt_ggc_e_11fixed_value,
 gt_ggc_e_10real_value,
 gt_ggc_e_12block_symbol,
 gt_ggc_e_12object_block,
 gt_ggc_e_9reg_attrs,
 gt_ggc_e_9mem_attrs,
 gt_ggc_e_13coverage_data,
 gt_ggc_e_14bitmap_obstack,
 gt_ggc_e_18bitmap_element_def,
 gt_ggc_e_12splay_tree_s,
 gt_ggc_e_17splay_tree_node_s,
 gt_ggc_e_4htab,
 gt_ggc_e_16machine_function,
 gt_ggc_e_17arm_stack_offsets,
 gt_ggc_e_10VEC_rtx_gc,
 gt_ggc_e_12VEC_rtx_base,
 gt_ggc_e_13VEC_gimple_gc,
 gt_ggc_e_15VEC_gimple_base,
 gt_ggc_e_11VEC_tree_gc,
 gt_ggc_e_13VEC_tree_none,
 gt_ggc_e_13VEC_tree_base,
 gt_ggc_e_12VEC_uchar_gc,
 gt_ggc_e_14VEC_uchar_base,
 gt_ggc_e_10vec_prefix,
 gt_ggc_e_15basic_block_def,
 gt_ggc_e_8edge_def,
 gt_ggc_e_12gimple_seq_d,
 gt_ggc_e_15cl_optimization,
 gt_ggc_e_16cl_target_option,
 gt_ggc_e_7section,
 gt_ggc_e_18gimple_statement_d,
 gt_ggc_e_9rtvec_def,
 gt_ggc_e_7rtx_def,
 gt_ggc_e_15bitmap_head_def,
 gt_ggc_e_11cpp_macro_u,
 gt_ggc_e_13ht_identifier,
 gt_ggc_e_19_cpp_hashnode_value,
 gt_ggc_e_11cpp_token_u,
 gt_ggc_e_14cpp_identifier,
 gt_ggc_e_13cpp_macro_arg,
 gt_ggc_e_6answer,
 gt_ggc_e_9cpp_macro,
 gt_ggc_e_10cpp_string,
 gt_ggc_e_9cpp_token,
 gt_ggc_e_9line_maps,
 gt_ggc_e_9maps_info,
 gt_ggc_e_8line_map,
 gt_ggc_e_5map_u,
 gt_ggc_e_14line_map_macro,
 gt_ggc_e_9tree_node,
 gt_ggc_e_12cpp_hashnode,
 gt_ggc_e_17line_map_ordinary,
 gt_e_II17splay_tree_node_s,
 gt_e_SP9tree_node17splay_tree_node_s,
 gt_e_P9tree_nodeP9tree_node17splay_tree_node_s,
 gt_e_P17string_descriptor4htab,
 gt_e_P14type_assertion4htab,
 gt_e_P18treetreehash_entry4htab,
 gt_e_P17module_htab_entry4htab,
 gt_e_P21pending_abstract_type4htab,
 gt_e_P14constexpr_call4htab,
 gt_e_P16constexpr_fundef4htab,
 gt_e_P10spec_entry4htab,
 gt_e_P16cxx_int_tree_map4htab,
 gt_e_P17named_label_entry4htab,
 gt_e_P17lto_in_decl_state4htab,
 gt_e_P20lto_symtab_entry_def4htab,
 gt_e_P9tree_nodeP9tree_node12splay_tree_s,
 gt_e_P12varpool_node4htab,
 gt_e_P13scev_info_str4htab,
 gt_e_P15tm_restart_node4htab,
 gt_e_P12tree_int_map4htab,
 gt_e_P8tree_map4htab,
 gt_e_P23constant_descriptor_rtx4htab,
 gt_e_P24constant_descriptor_tree4htab,
 gt_e_P12object_block4htab,
 gt_e_P7section4htab,
 gt_e_P17tree_priority_map4htab,
 gt_e_P12tree_vec_map4htab,
 gt_e_P13tree_decl_map4htab,
 gt_e_P9type_hash4htab,
 gt_e_P23temp_slot_address_entry4htab,
 gt_e_P15throw_stmt_node4htab,
 gt_e_P9reg_attrs4htab,
 gt_e_P9mem_attrs4htab,
 gt_e_P7rtx_def4htab,
 gt_e_P22cached_dw_loc_list_def4htab,
 gt_e_P16var_loc_list_def4htab,
 gt_e_P10die_struct4htab,
 gt_e_P15dwarf_file_data4htab,
 gt_e_P20indirect_string_node4htab,
 gt_e_SP9tree_node12splay_tree_s,
 gt_e_P11cgraph_node4htab,
 gt_e_II12splay_tree_s,
 gt_e_P11cgraph_edge4htab,
 gt_e_P9loop_exit4htab,
 gt_e_P24types_used_by_vars_entry4htab,
 gt_e_P9tree_node4htab,
 gt_e_P13libfunc_entry4htab,
 gt_types_enum_last
};
# 6579 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gtype-desc.h"
extern void gt_ggc_mx_c_inline_static (void *);
extern void gt_ggc_mx_VEC_c_goto_bindings_p_gc (void *);
extern void gt_ggc_mx_c_goto_bindings (void *);
extern void gt_ggc_mx_c_scope (void *);
extern void gt_ggc_mx_c_binding (void *);
extern void gt_ggc_mx_c_label_vars (void *);
extern void gt_ggc_mx_c_parser (void *);
extern void gt_ggc_mx_VEC_ivarref_entry_gc (void *);
extern void gt_ggc_mx_VEC_prot_list_entry_gc (void *);
extern void gt_ggc_mx_VEC_msgref_entry_gc (void *);
extern void gt_ggc_mx_VEC_ident_data_tuple_gc (void *);
extern void gt_ggc_mx_string_descriptor (void *);
extern void gt_ggc_mx_imp_entry (void *);
extern void gt_ggc_mx_hashed_attribute (void *);
extern void gt_ggc_mx_hashed_entry (void *);
extern void gt_ggc_mx_objc_map_private (void *);
extern void gt_ggc_mx_VEC_method_entry_gc (void *);
extern void gt_ggc_mx_type_assertion (void *);
extern void gt_ggc_mx_treetreehash_entry (void *);
extern void gt_ggc_mx_CPool (void *);
extern void gt_ggc_mx_JCF (void *);
extern void gt_ggc_mx_module_htab_entry (void *);
extern void gt_ggc_mx_binding_level (void *);
extern void gt_ggc_mx_VEC_pending_noexcept_gc (void *);
extern void gt_ggc_mx_opt_stack (void *);
extern void gt_ggc_mx_VEC_pending_redefinition_gc (void *);
extern void gt_ggc_mx_VEC_pending_weak_gc (void *);
extern void gt_ggc_mx_align_stack (void *);
extern void gt_ggc_mx_VEC_tree_gc_vec_gc (void *);
extern void gt_ggc_mx_VEC_const_char_p_gc (void *);
extern void gt_ggc_mx_pending_abstract_type (void *);
extern void gt_ggc_mx_VEC_tree_int_gc (void *);
extern void gt_ggc_mx_cp_parser (void *);
extern void gt_ggc_mx_cp_parser_context (void *);
extern void gt_ggc_mx_VEC_cp_unparsed_functions_entry_gc (void *);
extern void gt_ggc_mx_VEC_cp_default_arg_entry_gc (void *);
extern void gt_ggc_mx_cp_lexer (void *);
extern void gt_ggc_mx_VEC_cp_token_gc (void *);
extern void gt_ggc_mx_tree_check (void *);
extern void gt_ggc_mx_constexpr_call (void *);
extern void gt_ggc_mx_constexpr_fundef (void *);
extern void gt_ggc_mx_VEC_deferred_access_gc (void *);
extern void gt_ggc_mx_spec_entry (void *);
extern void gt_ggc_mx_pending_template (void *);
extern void gt_ggc_mx_VEC_incomplete_var_gc (void *);
extern void gt_ggc_mx_named_label_use_entry (void *);
extern void gt_ggc_mx_VEC_deferred_access_check_gc (void *);
extern void gt_ggc_mx_sorted_fields_type (void *);
extern void gt_ggc_mx_VEC_tree_pair_s_gc (void *);
extern void gt_ggc_mx_named_label_entry (void *);
extern void gt_ggc_mx_VEC_qualified_typedef_usage_t_gc (void *);
extern void gt_ggc_mx_cp_token_cache (void *);
extern void gt_ggc_mx_saved_scope (void *);
extern void gt_ggc_mx_cxx_int_tree_map (void *);
extern void gt_ggc_mx_VEC_cp_label_binding_gc (void *);
extern void gt_ggc_mx_VEC_cp_class_binding_gc (void *);
extern void gt_ggc_mx_VEC_cxx_saved_binding_gc (void *);
extern void gt_ggc_mx_cp_binding_level (void *);
extern void gt_ggc_mx_cxx_binding (void *);
extern void gt_ggc_mx_binding_entry_s (void *);
extern void gt_ggc_mx_binding_table_s (void *);
extern void gt_ggc_mx_tinst_level (void *);
extern void gt_ggc_mx_VEC_tinfo_s_gc (void *);
extern void gt_ggc_mx_gnat_binding_level (void *);
extern void gt_ggc_mx_VEC_loop_info_gc (void *);
extern void gt_ggc_mx_loop_info_d (void *);
extern void gt_ggc_mx_VEC_range_check_info_gc (void *);
extern void gt_ggc_mx_range_check_info_d (void *);
extern void gt_ggc_mx_elab_info (void *);
extern void gt_ggc_mx_stmt_group (void *);
extern void gt_ggc_mx_VEC_parm_attr_gc (void *);
extern void gt_ggc_mx_parm_attr_d (void *);
extern void gt_ggc_mx_VEC_inline_summary_t_gc (void *);
extern void gt_ggc_mx_VEC_size_time_entry_gc (void *);
extern void gt_ggc_mx_VEC_condition_gc (void *);
extern void gt_ggc_mx_lto_in_decl_state (void *);
extern void gt_ggc_mx_VEC_ipa_edge_args_t_gc (void *);
extern void gt_ggc_mx_VEC_ipa_jump_func_t_gc (void *);
extern void gt_ggc_mx_lto_symtab_entry_def (void *);
extern void gt_ggc_mx_ssa_operand_memory_d (void *);
extern void gt_ggc_mx_scev_info_str (void *);
extern void gt_ggc_mx_VEC_mem_addr_template_gc (void *);
extern void gt_ggc_mx_tm_restart_node (void *);
extern void gt_ggc_mx_gimple_type_leader_entry_s (void *);
extern void gt_ggc_mx_gimple_seq_node_d (void *);
extern void gt_ggc_mx_type_hash (void *);
extern void gt_ggc_mx_string_pool_data (void *);
extern void gt_ggc_mx_temp_slot_address_entry (void *);
extern void gt_ggc_mx_throw_stmt_node (void *);
extern void gt_ggc_mx_VEC_eh_landing_pad_gc (void *);
extern void gt_ggc_mx_VEC_eh_region_gc (void *);
extern void gt_ggc_mx_eh_catch_d (void *);
extern void gt_ggc_mx_eh_landing_pad_d (void *);
extern void gt_ggc_mx_eh_region_d (void *);
extern void gt_ggc_mx_cached_dw_loc_list_def (void *);
extern void gt_ggc_mx_call_arg_loc_node (void *);
extern void gt_ggc_mx_var_loc_list_def (void *);
extern void gt_ggc_mx_var_loc_node (void *);
extern void gt_ggc_mx_VEC_die_arg_entry_gc (void *);
extern void gt_ggc_mx_limbo_die_struct (void *);
extern void gt_ggc_mx_VEC_macinfo_entry_gc (void *);
extern void gt_ggc_mx_VEC_pubname_entry_gc (void *);
extern void gt_ggc_mx_VEC_dw_attr_node_gc (void *);
extern void gt_ggc_mx_VEC_dw_line_info_table_p_gc (void *);
extern void gt_ggc_mx_dw_line_info_table_struct (void *);
extern void gt_ggc_mx_VEC_dw_line_info_entry_gc (void *);
extern void gt_ggc_mx_comdat_type_struct (void *);
extern void gt_ggc_mx_dw_ranges_by_label_struct (void *);
extern void gt_ggc_mx_dw_ranges_struct (void *);
extern void gt_ggc_mx_VEC_deferred_locations_gc (void *);
extern void gt_ggc_mx_VEC_dw_fde_ref_gc (void *);
extern void gt_ggc_mx_reg_saved_in_data_struct (void *);
extern void gt_ggc_mx_dw_cfi_row_struct (void *);
extern void gt_ggc_mx_dwarf_file_data (void *);
extern void gt_ggc_mx_indirect_string_node (void *);
extern void gt_ggc_mx_VEC_dw_cfi_ref_gc (void *);
extern void gt_ggc_mx_dw_loc_list_struct (void *);
extern void gt_ggc_mx_dw_loc_descr_struct (void *);
extern void gt_ggc_mx_dw_cfi_struct (void *);
extern void gt_ggc_mx_typeinfo (void *);
extern void gt_ggc_mx_VEC_alias_set_entry_gc (void *);
extern void gt_ggc_mx_alias_set_entry_d (void *);
extern void gt_ggc_mx_constant_descriptor_tree (void *);
extern void gt_ggc_mx_cgraph_asm_node (void *);
extern void gt_ggc_mx_cgraph_indirect_call_info (void *);
extern void gt_ggc_mx_cgraph_edge (void *);
extern void gt_ggc_mx_VEC_ipa_replace_map_p_gc (void *);
extern void gt_ggc_mx_ipa_replace_map (void *);
extern void gt_ggc_mx_lto_file_decl_data (void *);
extern void gt_ggc_mx_VEC_ipa_ref_t_gc (void *);
extern void gt_ggc_mx_varpool_node (void *);
extern void gt_ggc_mx_cgraph_node (void *);
extern void gt_ggc_mx_VEC_basic_block_gc (void *);
extern void gt_ggc_mx_gimple_bb_info (void *);
extern void gt_ggc_mx_rtl_bb_info (void *);
extern void gt_ggc_mx_VEC_edge_gc (void *);
extern void gt_ggc_mx_VEC_loop_p_gc (void *);
extern void gt_ggc_mx_loop (void *);
extern void gt_ggc_mx_loop_exit (void *);
extern void gt_ggc_mx_nb_iter_bound (void *);
extern void gt_ggc_mx_types_used_by_vars_entry (void *);
extern void gt_ggc_mx_language_function (void *);
extern void gt_ggc_mx_loops (void *);
extern void gt_ggc_mx_control_flow_graph (void *);
extern void gt_ggc_mx_eh_status (void *);
extern void gt_ggc_mx_stack_usage (void *);
extern void gt_ggc_mx_initial_value_struct (void *);
extern void gt_ggc_mx_frame_space (void *);
extern void gt_ggc_mx_rtx_constant_pool (void *);
extern void gt_ggc_mx_VEC_temp_slot_p_gc (void *);
extern void gt_ggc_mx_dw_fde_struct (void *);
extern void gt_ggc_mx_temp_slot (void *);
extern void gt_ggc_mx_gimple_df (void *);
extern void gt_ggc_mx_VEC_call_site_record_gc (void *);
extern void gt_ggc_mx_call_site_record_d (void *);
extern void gt_ggc_mx_sequence_stack (void *);
extern void gt_ggc_mx_libfunc_entry (void *);
extern void gt_ggc_mx_tree_vec_map (void *);
extern void gt_ggc_mx_tree_priority_map (void *);
extern void gt_ggc_mx_tree_int_map (void *);
extern void gt_ggc_mx_tree_decl_map (void *);
extern void gt_ggc_mx_tree_map (void *);
extern void gt_ggc_mx_lang_tree_node (void *);
extern void gt_ggc_mx_tree_statement_list_node (void *);
extern void gt_ggc_mx_var_ann_d (void *);
extern void gt_ggc_mx_lang_decl (void *);
extern void gt_ggc_mx_lang_type (void *);
extern void gt_ggc_mx_die_struct (void *);
extern void gt_ggc_mx_ptr_info_def (void *);
extern void gt_ggc_mx_VEC_constructor_elt_gc (void *);
extern void gt_ggc_mx_VEC_alias_pair_gc (void *);
extern void gt_ggc_mx_function (void *);
extern void gt_ggc_mx_constant_descriptor_rtx (void *);
extern void gt_ggc_mx_fixed_value (void *);
extern void gt_ggc_mx_real_value (void *);
extern void gt_ggc_mx_object_block (void *);
extern void gt_ggc_mx_reg_attrs (void *);
extern void gt_ggc_mx_mem_attrs (void *);
extern void gt_ggc_mx_coverage_data (void *);
extern void gt_ggc_mx_bitmap_obstack (void *);
extern void gt_ggc_mx_bitmap_element_def (void *);
extern void gt_ggc_mx_machine_function (void *);
extern void gt_ggc_mx_VEC_rtx_gc (void *);
extern void gt_ggc_mx_VEC_gimple_gc (void *);
extern void gt_ggc_mx_VEC_tree_gc (void *);
extern void gt_ggc_mx_VEC_uchar_gc (void *);
extern void gt_ggc_mx_basic_block_def (void *);
extern void gt_ggc_mx_edge_def (void *);
extern void gt_ggc_mx_gimple_seq_d (void *);
extern void gt_ggc_mx_section (void *);
extern void gt_ggc_mx_gimple_statement_d (void *);
extern void gt_ggc_mx_rtvec_def (void *);
extern void gt_ggc_mx_rtx_def (void *);
extern void gt_ggc_mx_bitmap_head_def (void *);
extern void gt_ggc_mx_answer (void *);
extern void gt_ggc_mx_cpp_macro (void *);
extern void gt_ggc_mx_cpp_token (void *);
extern void gt_ggc_mx_line_maps (void *);
extern void gt_ggc_m_II17splay_tree_node_s (void *);
extern void gt_ggc_m_SP9tree_node17splay_tree_node_s (void *);
extern void gt_ggc_m_P9tree_nodeP9tree_node17splay_tree_node_s (void *);
extern void gt_ggc_m_P17string_descriptor4htab (void *);
extern void gt_ggc_m_P14type_assertion4htab (void *);
extern void gt_ggc_m_P18treetreehash_entry4htab (void *);
extern void gt_ggc_m_P17module_htab_entry4htab (void *);
extern void gt_ggc_m_P21pending_abstract_type4htab (void *);
extern void gt_ggc_m_P14constexpr_call4htab (void *);
extern void gt_ggc_m_P16constexpr_fundef4htab (void *);
extern void gt_ggc_m_P10spec_entry4htab (void *);
extern void gt_ggc_m_P16cxx_int_tree_map4htab (void *);
extern void gt_ggc_m_P17named_label_entry4htab (void *);
extern void gt_ggc_m_P17lto_in_decl_state4htab (void *);
extern void gt_ggc_m_P20lto_symtab_entry_def4htab (void *);
extern void gt_ggc_m_P9tree_nodeP9tree_node12splay_tree_s (void *);
extern void gt_ggc_m_P12varpool_node4htab (void *);
extern void gt_ggc_m_P13scev_info_str4htab (void *);
extern void gt_ggc_m_P15tm_restart_node4htab (void *);
extern void gt_ggc_m_P12tree_int_map4htab (void *);
extern void gt_ggc_m_P8tree_map4htab (void *);
extern void gt_ggc_m_P23constant_descriptor_rtx4htab (void *);
extern void gt_ggc_m_P24constant_descriptor_tree4htab (void *);
extern void gt_ggc_m_P12object_block4htab (void *);
extern void gt_ggc_m_P7section4htab (void *);
extern void gt_ggc_m_P17tree_priority_map4htab (void *);
extern void gt_ggc_m_P12tree_vec_map4htab (void *);
extern void gt_ggc_m_P13tree_decl_map4htab (void *);
extern void gt_ggc_m_P9type_hash4htab (void *);
extern void gt_ggc_m_P23temp_slot_address_entry4htab (void *);
extern void gt_ggc_m_P15throw_stmt_node4htab (void *);
extern void gt_ggc_m_P9reg_attrs4htab (void *);
extern void gt_ggc_m_P9mem_attrs4htab (void *);
extern void gt_ggc_m_P7rtx_def4htab (void *);
extern void gt_ggc_m_P22cached_dw_loc_list_def4htab (void *);
extern void gt_ggc_m_P16var_loc_list_def4htab (void *);
extern void gt_ggc_m_P10die_struct4htab (void *);
extern void gt_ggc_m_P15dwarf_file_data4htab (void *);
extern void gt_ggc_m_P20indirect_string_node4htab (void *);
extern void gt_ggc_m_SP9tree_node12splay_tree_s (void *);
extern void gt_ggc_m_P11cgraph_node4htab (void *);
extern void gt_ggc_m_II12splay_tree_s (void *);
extern void gt_ggc_m_P11cgraph_edge4htab (void *);
extern void gt_ggc_m_P9loop_exit4htab (void *);
extern void gt_ggc_m_P24types_used_by_vars_entry4htab (void *);
extern void gt_ggc_m_P9tree_node4htab (void *);
extern void gt_ggc_m_P13libfunc_entry4htab (void *);
# 7427 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/gtype-desc.h"
extern void gt_pch_nx_c_inline_static (void *);
extern void gt_pch_nx_VEC_c_goto_bindings_p_gc (void *);
extern void gt_pch_nx_c_goto_bindings (void *);
extern void gt_pch_nx_c_scope (void *);
extern void gt_pch_nx_c_binding (void *);
extern void gt_pch_nx_c_label_vars (void *);
extern void gt_pch_nx_c_parser (void *);
extern void gt_pch_nx_VEC_ivarref_entry_gc (void *);
extern void gt_pch_nx_VEC_prot_list_entry_gc (void *);
extern void gt_pch_nx_VEC_msgref_entry_gc (void *);
extern void gt_pch_nx_VEC_ident_data_tuple_gc (void *);
extern void gt_pch_nx_string_descriptor (void *);
extern void gt_pch_nx_imp_entry (void *);
extern void gt_pch_nx_hashed_attribute (void *);
extern void gt_pch_nx_hashed_entry (void *);
extern void gt_pch_nx_objc_map_private (void *);
extern void gt_pch_nx_VEC_method_entry_gc (void *);
extern void gt_pch_nx_type_assertion (void *);
extern void gt_pch_nx_treetreehash_entry (void *);
extern void gt_pch_nx_CPool (void *);
extern void gt_pch_nx_JCF (void *);
extern void gt_pch_nx_module_htab_entry (void *);
extern void gt_pch_nx_binding_level (void *);
extern void gt_pch_nx_VEC_pending_noexcept_gc (void *);
extern void gt_pch_nx_opt_stack (void *);
extern void gt_pch_nx_VEC_pending_redefinition_gc (void *);
extern void gt_pch_nx_VEC_pending_weak_gc (void *);
extern void gt_pch_nx_align_stack (void *);
extern void gt_pch_nx_VEC_tree_gc_vec_gc (void *);
extern void gt_pch_nx_VEC_const_char_p_gc (void *);
extern void gt_pch_nx_pending_abstract_type (void *);
extern void gt_pch_nx_VEC_tree_int_gc (void *);
extern void gt_pch_nx_cp_parser (void *);
extern void gt_pch_nx_cp_parser_context (void *);
extern void gt_pch_nx_VEC_cp_unparsed_functions_entry_gc (void *);
extern void gt_pch_nx_VEC_cp_default_arg_entry_gc (void *);
extern void gt_pch_nx_cp_lexer (void *);
extern void gt_pch_nx_VEC_cp_token_gc (void *);
extern void gt_pch_nx_tree_check (void *);
extern void gt_pch_nx_constexpr_call (void *);
extern void gt_pch_nx_constexpr_fundef (void *);
extern void gt_pch_nx_VEC_deferred_access_gc (void *);
extern void gt_pch_nx_spec_entry (void *);
extern void gt_pch_nx_pending_template (void *);
extern void gt_pch_nx_VEC_incomplete_var_gc (void *);
extern void gt_pch_nx_named_label_use_entry (void *);
extern void gt_pch_nx_VEC_deferred_access_check_gc (void *);
extern void gt_pch_nx_sorted_fields_type (void *);
extern void gt_pch_nx_VEC_tree_pair_s_gc (void *);
extern void gt_pch_nx_named_label_entry (void *);
extern void gt_pch_nx_VEC_qualified_typedef_usage_t_gc (void *);
extern void gt_pch_nx_cp_token_cache (void *);
extern void gt_pch_nx_saved_scope (void *);
extern void gt_pch_nx_cxx_int_tree_map (void *);
extern void gt_pch_nx_VEC_cp_label_binding_gc (void *);
extern void gt_pch_nx_VEC_cp_class_binding_gc (void *);
extern void gt_pch_nx_VEC_cxx_saved_binding_gc (void *);
extern void gt_pch_nx_cp_binding_level (void *);
extern void gt_pch_nx_cxx_binding (void *);
extern void gt_pch_nx_binding_entry_s (void *);
extern void gt_pch_nx_binding_table_s (void *);
extern void gt_pch_nx_tinst_level (void *);
extern void gt_pch_nx_VEC_tinfo_s_gc (void *);
extern void gt_pch_nx_gnat_binding_level (void *);
extern void gt_pch_nx_VEC_loop_info_gc (void *);
extern void gt_pch_nx_loop_info_d (void *);
extern void gt_pch_nx_VEC_range_check_info_gc (void *);
extern void gt_pch_nx_range_check_info_d (void *);
extern void gt_pch_nx_elab_info (void *);
extern void gt_pch_nx_stmt_group (void *);
extern void gt_pch_nx_VEC_parm_attr_gc (void *);
extern void gt_pch_nx_parm_attr_d (void *);
extern void gt_pch_nx_VEC_inline_summary_t_gc (void *);
extern void gt_pch_nx_VEC_size_time_entry_gc (void *);
extern void gt_pch_nx_VEC_condition_gc (void *);
extern void gt_pch_nx_lto_in_decl_state (void *);
extern void gt_pch_nx_VEC_ipa_edge_args_t_gc (void *);
extern void gt_pch_nx_VEC_ipa_jump_func_t_gc (void *);
extern void gt_pch_nx_lto_symtab_entry_def (void *);
extern void gt_pch_nx_ssa_operand_memory_d (void *);
extern void gt_pch_nx_scev_info_str (void *);
extern void gt_pch_nx_VEC_mem_addr_template_gc (void *);
extern void gt_pch_nx_tm_restart_node (void *);
extern void gt_pch_nx_gimple_type_leader_entry_s (void *);
extern void gt_pch_nx_gimple_seq_node_d (void *);
extern void gt_pch_nx_type_hash (void *);
extern void gt_pch_nx_string_pool_data (void *);
extern void gt_pch_nx_temp_slot_address_entry (void *);
extern void gt_pch_nx_throw_stmt_node (void *);
extern void gt_pch_nx_VEC_eh_landing_pad_gc (void *);
extern void gt_pch_nx_VEC_eh_region_gc (void *);
extern void gt_pch_nx_eh_catch_d (void *);
extern void gt_pch_nx_eh_landing_pad_d (void *);
extern void gt_pch_nx_eh_region_d (void *);
extern void gt_pch_nx_cached_dw_loc_list_def (void *);
extern void gt_pch_nx_call_arg_loc_node (void *);
extern void gt_pch_nx_var_loc_list_def (void *);
extern void gt_pch_nx_var_loc_node (void *);
extern void gt_pch_nx_VEC_die_arg_entry_gc (void *);
extern void gt_pch_nx_limbo_die_struct (void *);
extern void gt_pch_nx_VEC_macinfo_entry_gc (void *);
extern void gt_pch_nx_VEC_pubname_entry_gc (void *);
extern void gt_pch_nx_VEC_dw_attr_node_gc (void *);
extern void gt_pch_nx_VEC_dw_line_info_table_p_gc (void *);
extern void gt_pch_nx_dw_line_info_table_struct (void *);
extern void gt_pch_nx_VEC_dw_line_info_entry_gc (void *);
extern void gt_pch_nx_comdat_type_struct (void *);
extern void gt_pch_nx_dw_ranges_by_label_struct (void *);
extern void gt_pch_nx_dw_ranges_struct (void *);
extern void gt_pch_nx_VEC_deferred_locations_gc (void *);
extern void gt_pch_nx_VEC_dw_fde_ref_gc (void *);
extern void gt_pch_nx_reg_saved_in_data_struct (void *);
extern void gt_pch_nx_dw_cfi_row_struct (void *);
extern void gt_pch_nx_dwarf_file_data (void *);
extern void gt_pch_nx_indirect_string_node (void *);
extern void gt_pch_nx_VEC_dw_cfi_ref_gc (void *);
extern void gt_pch_nx_dw_loc_list_struct (void *);
extern void gt_pch_nx_dw_loc_descr_struct (void *);
extern void gt_pch_nx_dw_cfi_struct (void *);
extern void gt_pch_nx_typeinfo (void *);
extern void gt_pch_nx_VEC_alias_set_entry_gc (void *);
extern void gt_pch_nx_alias_set_entry_d (void *);
extern void gt_pch_nx_constant_descriptor_tree (void *);
extern void gt_pch_nx_cgraph_asm_node (void *);
extern void gt_pch_nx_cgraph_indirect_call_info (void *);
extern void gt_pch_nx_cgraph_edge (void *);
extern void gt_pch_nx_VEC_ipa_replace_map_p_gc (void *);
extern void gt_pch_nx_ipa_replace_map (void *);
extern void gt_pch_nx_lto_file_decl_data (void *);
extern void gt_pch_nx_VEC_ipa_ref_t_gc (void *);
extern void gt_pch_nx_varpool_node (void *);
extern void gt_pch_nx_cgraph_node (void *);
extern void gt_pch_nx_VEC_basic_block_gc (void *);
extern void gt_pch_nx_gimple_bb_info (void *);
extern void gt_pch_nx_rtl_bb_info (void *);
extern void gt_pch_nx_VEC_edge_gc (void *);
extern void gt_pch_nx_VEC_loop_p_gc (void *);
extern void gt_pch_nx_loop (void *);
extern void gt_pch_nx_loop_exit (void *);
extern void gt_pch_nx_nb_iter_bound (void *);
extern void gt_pch_nx_types_used_by_vars_entry (void *);
extern void gt_pch_nx_language_function (void *);
extern void gt_pch_nx_loops (void *);
extern void gt_pch_nx_control_flow_graph (void *);
extern void gt_pch_nx_eh_status (void *);
extern void gt_pch_nx_stack_usage (void *);
extern void gt_pch_nx_initial_value_struct (void *);
extern void gt_pch_nx_frame_space (void *);
extern void gt_pch_nx_rtx_constant_pool (void *);
extern void gt_pch_nx_VEC_temp_slot_p_gc (void *);
extern void gt_pch_nx_dw_fde_struct (void *);
extern void gt_pch_nx_temp_slot (void *);
extern void gt_pch_nx_gimple_df (void *);
extern void gt_pch_nx_VEC_call_site_record_gc (void *);
extern void gt_pch_nx_call_site_record_d (void *);
extern void gt_pch_nx_sequence_stack (void *);
extern void gt_pch_nx_libfunc_entry (void *);
extern void gt_pch_nx_tree_vec_map (void *);
extern void gt_pch_nx_tree_priority_map (void *);
extern void gt_pch_nx_tree_int_map (void *);
extern void gt_pch_nx_tree_decl_map (void *);
extern void gt_pch_nx_tree_map (void *);
extern void gt_pch_nx_lang_tree_node (void *);
extern void gt_pch_nx_tree_statement_list_node (void *);
extern void gt_pch_nx_var_ann_d (void *);
extern void gt_pch_nx_lang_decl (void *);
extern void gt_pch_nx_lang_type (void *);
extern void gt_pch_nx_die_struct (void *);
extern void gt_pch_nx_ptr_info_def (void *);
extern void gt_pch_nx_VEC_constructor_elt_gc (void *);
extern void gt_pch_nx_VEC_alias_pair_gc (void *);
extern void gt_pch_nx_function (void *);
extern void gt_pch_nx_constant_descriptor_rtx (void *);
extern void gt_pch_nx_fixed_value (void *);
extern void gt_pch_nx_real_value (void *);
extern void gt_pch_nx_object_block (void *);
extern void gt_pch_nx_reg_attrs (void *);
extern void gt_pch_nx_mem_attrs (void *);
extern void gt_pch_nx_coverage_data (void *);
extern void gt_pch_nx_bitmap_obstack (void *);
extern void gt_pch_nx_bitmap_element_def (void *);
extern void gt_pch_nx_machine_function (void *);
extern void gt_pch_nx_VEC_rtx_gc (void *);
extern void gt_pch_nx_VEC_gimple_gc (void *);
extern void gt_pch_nx_VEC_tree_gc (void *);
extern void gt_pch_nx_VEC_uchar_gc (void *);
extern void gt_pch_nx_basic_block_def (void *);
extern void gt_pch_nx_edge_def (void *);
extern void gt_pch_nx_gimple_seq_d (void *);
extern void gt_pch_nx_section (void *);
extern void gt_pch_nx_gimple_statement_d (void *);
extern void gt_pch_nx_rtvec_def (void *);
extern void gt_pch_nx_rtx_def (void *);
extern void gt_pch_nx_bitmap_head_def (void *);
extern void gt_pch_nx_answer (void *);
extern void gt_pch_nx_cpp_macro (void *);
extern void gt_pch_nx_cpp_token (void *);
extern void gt_pch_nx_line_maps (void *);
extern void gt_pch_n_II17splay_tree_node_s (void *);
extern void gt_pch_n_SP9tree_node17splay_tree_node_s (void *);
extern void gt_pch_n_P9tree_nodeP9tree_node17splay_tree_node_s (void *);
extern void gt_pch_n_P17string_descriptor4htab (void *);
extern void gt_pch_n_P14type_assertion4htab (void *);
extern void gt_pch_n_P18treetreehash_entry4htab (void *);
extern void gt_pch_n_P17module_htab_entry4htab (void *);
extern void gt_pch_n_P21pending_abstract_type4htab (void *);
extern void gt_pch_n_P14constexpr_call4htab (void *);
extern void gt_pch_n_P16constexpr_fundef4htab (void *);
extern void gt_pch_n_P10spec_entry4htab (void *);
extern void gt_pch_n_P16cxx_int_tree_map4htab (void *);
extern void gt_pch_n_P17named_label_entry4htab (void *);
extern void gt_pch_n_P17lto_in_decl_state4htab (void *);
extern void gt_pch_n_P20lto_symtab_entry_def4htab (void *);
extern void gt_pch_n_P9tree_nodeP9tree_node12splay_tree_s (void *);
extern void gt_pch_n_P12varpool_node4htab (void *);
extern void gt_pch_n_P13scev_info_str4htab (void *);
extern void gt_pch_n_P15tm_restart_node4htab (void *);
extern void gt_pch_n_P12tree_int_map4htab (void *);
extern void gt_pch_n_P8tree_map4htab (void *);
extern void gt_pch_n_P23constant_descriptor_rtx4htab (void *);
extern void gt_pch_n_P24constant_descriptor_tree4htab (void *);
extern void gt_pch_n_P12object_block4htab (void *);
extern void gt_pch_n_P7section4htab (void *);
extern void gt_pch_n_P17tree_priority_map4htab (void *);
extern void gt_pch_n_P12tree_vec_map4htab (void *);
extern void gt_pch_n_P13tree_decl_map4htab (void *);
extern void gt_pch_n_P9type_hash4htab (void *);
extern void gt_pch_n_P23temp_slot_address_entry4htab (void *);
extern void gt_pch_n_P15throw_stmt_node4htab (void *);
extern void gt_pch_n_P9reg_attrs4htab (void *);
extern void gt_pch_n_P9mem_attrs4htab (void *);
extern void gt_pch_n_P7rtx_def4htab (void *);
extern void gt_pch_n_P22cached_dw_loc_list_def4htab (void *);
extern void gt_pch_n_P16var_loc_list_def4htab (void *);
extern void gt_pch_n_P10die_struct4htab (void *);
extern void gt_pch_n_P15dwarf_file_data4htab (void *);
extern void gt_pch_n_P20indirect_string_node4htab (void *);
extern void gt_pch_n_SP9tree_node12splay_tree_s (void *);
extern void gt_pch_n_P11cgraph_node4htab (void *);
extern void gt_pch_n_II12splay_tree_s (void *);
extern void gt_pch_n_P11cgraph_edge4htab (void *);
extern void gt_pch_n_P9loop_exit4htab (void *);
extern void gt_pch_n_P24types_used_by_vars_entry4htab (void *);
extern void gt_pch_n_P9tree_node4htab (void *);
extern void gt_pch_n_P13libfunc_entry4htab (void *);
extern void gt_pch_p_15c_inline_static
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_24VEC_c_goto_bindings_p_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_15c_goto_bindings
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_7c_scope
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9c_binding
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_12c_label_vars
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_8c_parser
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_20VEC_ivarref_entry_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_22VEC_prot_list_entry_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_19VEC_msgref_entry_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_23VEC_ident_data_tuple_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17string_descriptor
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9imp_entry
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16hashed_attribute
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_12hashed_entry
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16objc_map_private
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_19VEC_method_entry_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_14type_assertion
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18treetreehash_entry
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_5CPool
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_3JCF
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17module_htab_entry
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_13binding_level
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_23VEC_pending_noexcept_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9opt_stack
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_27VEC_pending_redefinition_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_19VEC_pending_weak_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11align_stack
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18VEC_tree_gc_vec_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_19VEC_const_char_p_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_21pending_abstract_type
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_15VEC_tree_int_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9cp_parser
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17cp_parser_context
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_34VEC_cp_unparsed_functions_entry_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_27VEC_cp_default_arg_entry_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_8cp_lexer
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_15VEC_cp_token_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_10tree_check
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_14constexpr_call
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16constexpr_fundef
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_22VEC_deferred_access_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_10spec_entry
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16pending_template
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_21VEC_incomplete_var_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_21named_label_use_entry
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_28VEC_deferred_access_check_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18sorted_fields_type
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18VEC_tree_pair_s_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17named_label_entry
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_32VEC_qualified_typedef_usage_t_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_14cp_token_cache
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11saved_scope
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16cxx_int_tree_map
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_23VEC_cp_label_binding_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_23VEC_cp_class_binding_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_24VEC_cxx_saved_binding_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16cp_binding_level
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11cxx_binding
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_15binding_entry_s
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_15binding_table_s
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11tinst_level
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_14VEC_tinfo_s_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18gnat_binding_level
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16VEC_loop_info_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11loop_info_d
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_23VEC_range_check_info_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18range_check_info_d
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9elab_info
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_10stmt_group
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16VEC_parm_attr_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11parm_attr_d
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_23VEC_inline_summary_t_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_22VEC_size_time_entry_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16VEC_condition_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17lto_in_decl_state
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_22VEC_ipa_edge_args_t_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_22VEC_ipa_jump_func_t_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_20lto_symtab_entry_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_20ssa_operand_memory_d
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_13scev_info_str
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_24VEC_mem_addr_template_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_15tm_restart_node
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_26gimple_type_leader_entry_s
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17gimple_seq_node_d
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9type_hash
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16string_pool_data
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_23temp_slot_address_entry
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_15throw_stmt_node
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_21VEC_eh_landing_pad_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16VEC_eh_region_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_10eh_catch_d
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16eh_landing_pad_d
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11eh_region_d
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_22cached_dw_loc_list_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17call_arg_loc_node
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16var_loc_list_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_12var_loc_node
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_20VEC_die_arg_entry_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16limbo_die_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_20VEC_macinfo_entry_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_20VEC_pubname_entry_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_19VEC_dw_attr_node_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_27VEC_dw_line_info_table_p_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_25dw_line_info_table_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_25VEC_dw_line_info_entry_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18comdat_type_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_25dw_ranges_by_label_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16dw_ranges_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_25VEC_deferred_locations_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17VEC_dw_fde_ref_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_24reg_saved_in_data_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17dw_cfi_row_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_15dwarf_file_data
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_20indirect_string_node
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17VEC_dw_cfi_ref_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18dw_loc_list_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_19dw_loc_descr_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_13dw_cfi_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_8typeinfo
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_22VEC_alias_set_entry_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17alias_set_entry_d
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_24constant_descriptor_tree
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_15cgraph_asm_node
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_25cgraph_indirect_call_info
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11cgraph_edge
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_24VEC_ipa_replace_map_p_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_15ipa_replace_map
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18lto_file_decl_data
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16VEC_ipa_ref_t_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_12varpool_node
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11cgraph_node
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18VEC_basic_block_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_14gimple_bb_info
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11rtl_bb_info
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11VEC_edge_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_13VEC_loop_p_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_4loop
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9loop_exit
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_13nb_iter_bound
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_24types_used_by_vars_entry
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17language_function
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_5loops
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18control_flow_graph
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9eh_status
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11stack_usage
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_20initial_value_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11frame_space
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17rtx_constant_pool
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18VEC_temp_slot_p_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_13dw_fde_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9temp_slot
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9gimple_df
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_23VEC_call_site_record_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18call_site_record_d
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_14sequence_stack
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_13libfunc_entry
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_12tree_vec_map
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17tree_priority_map
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_12tree_int_map
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_13tree_decl_map
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_8tree_map
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_14lang_tree_node
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_24tree_statement_list_node
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9var_ann_d
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9lang_decl
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9lang_type
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_10die_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_12ptr_info_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_22VEC_constructor_elt_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17VEC_alias_pair_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_8function
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_23constant_descriptor_rtx
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11fixed_value
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_10real_value
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_12object_block
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9reg_attrs
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9mem_attrs
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_13coverage_data
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_14bitmap_obstack
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18bitmap_element_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16machine_function
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_10VEC_rtx_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_13VEC_gimple_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11VEC_tree_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_12VEC_uchar_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_15basic_block_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_8edge_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_12gimple_seq_d
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_7section
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18gimple_statement_d
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9rtvec_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_7rtx_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_15bitmap_head_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_6answer
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9cpp_macro
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9cpp_token
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9line_maps
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_II17splay_tree_node_s
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_SP9tree_node17splay_tree_node_s
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P9tree_nodeP9tree_node17splay_tree_node_s
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P17string_descriptor4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P14type_assertion4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P18treetreehash_entry4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P17module_htab_entry4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P21pending_abstract_type4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P14constexpr_call4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P16constexpr_fundef4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P10spec_entry4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P16cxx_int_tree_map4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P17named_label_entry4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P17lto_in_decl_state4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P20lto_symtab_entry_def4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P9tree_nodeP9tree_node12splay_tree_s
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P12varpool_node4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P13scev_info_str4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P15tm_restart_node4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P12tree_int_map4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P8tree_map4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P23constant_descriptor_rtx4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P24constant_descriptor_tree4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P12object_block4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P7section4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P17tree_priority_map4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P12tree_vec_map4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P13tree_decl_map4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P9type_hash4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P23temp_slot_address_entry4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P15throw_stmt_node4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P9reg_attrs4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P9mem_attrs4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P7rtx_def4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P22cached_dw_loc_list_def4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P16var_loc_list_def4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P10die_struct4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P15dwarf_file_data4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P20indirect_string_node4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_SP9tree_node12splay_tree_s
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P11cgraph_node4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_II12splay_tree_s
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P11cgraph_edge4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P9loop_exit4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P24types_used_by_vars_entry4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P9tree_node4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P13libfunc_entry4htab
    (void *, void *, gt_pointer_operator, void *);
extern void * ggc_alloc_splay_tree_scalar_scalar_splay_tree_node_s (int, void *);
extern void * ggc_alloc_splay_tree_str_tree_node_splay_tree_node_s (int, void *);
extern void * ggc_alloc_splay_tree_tree_node_tree_node_splay_tree_node_s (int, void *);
extern void * ggc_alloc_splay_tree_string_descriptor_htab (int, void *);
extern void * ggc_alloc_splay_tree_type_assertion_htab (int, void *);
extern void * ggc_alloc_splay_tree_treetreehash_entry_htab (int, void *);
extern void * ggc_alloc_splay_tree_module_htab_entry_htab (int, void *);
extern void * ggc_alloc_splay_tree_pending_abstract_type_htab (int, void *);
extern void * ggc_alloc_splay_tree_constexpr_call_htab (int, void *);
extern void * ggc_alloc_splay_tree_constexpr_fundef_htab (int, void *);
extern void * ggc_alloc_splay_tree_spec_entry_htab (int, void *);
extern void * ggc_alloc_splay_tree_cxx_int_tree_map_htab (int, void *);
extern void * ggc_alloc_splay_tree_named_label_entry_htab (int, void *);
extern void * ggc_alloc_splay_tree_lto_in_decl_state_htab (int, void *);
extern void * ggc_alloc_splay_tree_lto_symtab_entry_def_htab (int, void *);
extern void * ggc_alloc_splay_tree_tree_node_tree_node_splay_tree_s (int, void *);
extern void * ggc_alloc_splay_tree_varpool_node_htab (int, void *);
extern void * ggc_alloc_splay_tree_scev_info_str_htab (int, void *);
extern void * ggc_alloc_splay_tree_tm_restart_node_htab (int, void *);
extern void * ggc_alloc_splay_tree_tree_int_map_htab (int, void *);
extern void * ggc_alloc_splay_tree_tree_map_htab (int, void *);
extern void * ggc_alloc_splay_tree_constant_descriptor_rtx_htab (int, void *);
extern void * ggc_alloc_splay_tree_constant_descriptor_tree_htab (int, void *);
extern void * ggc_alloc_splay_tree_object_block_htab (int, void *);
extern void * ggc_alloc_splay_tree_section_htab (int, void *);
extern void * ggc_alloc_splay_tree_tree_priority_map_htab (int, void *);
extern void * ggc_alloc_splay_tree_tree_vec_map_htab (int, void *);
extern void * ggc_alloc_splay_tree_tree_decl_map_htab (int, void *);
extern void * ggc_alloc_splay_tree_type_hash_htab (int, void *);
extern void * ggc_alloc_splay_tree_temp_slot_address_entry_htab (int, void *);
extern void * ggc_alloc_splay_tree_throw_stmt_node_htab (int, void *);
extern void * ggc_alloc_splay_tree_reg_attrs_htab (int, void *);
extern void * ggc_alloc_splay_tree_mem_attrs_htab (int, void *);
extern void * ggc_alloc_splay_tree_rtx_def_htab (int, void *);
extern void * ggc_alloc_splay_tree_cached_dw_loc_list_def_htab (int, void *);
extern void * ggc_alloc_splay_tree_var_loc_list_def_htab (int, void *);
extern void * ggc_alloc_splay_tree_die_struct_htab (int, void *);
extern void * ggc_alloc_splay_tree_dwarf_file_data_htab (int, void *);
extern void * ggc_alloc_splay_tree_indirect_string_node_htab (int, void *);
extern void * ggc_alloc_splay_tree_str_tree_node_splay_tree_s (int, void *);
extern void * ggc_alloc_splay_tree_cgraph_node_htab (int, void *);
extern void * ggc_alloc_splay_tree_scalar_scalar_splay_tree_s (int, void *);
extern void * ggc_alloc_splay_tree_cgraph_edge_htab (int, void *);
extern void * ggc_alloc_splay_tree_loop_exit_htab (int, void *);
extern void * ggc_alloc_splay_tree_types_used_by_vars_entry_htab (int, void *);
extern void * ggc_alloc_splay_tree_tree_node_htab (int, void *);
extern void * ggc_alloc_splay_tree_libfunc_entry_htab (int, void *);
# 39 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/ggc.h" 2
typedef void (*gt_note_pointers) (void *, void *, gt_pointer_operator,
      void *);
typedef void (*gt_handle_reorder) (void *, void *, gt_pointer_operator,
       void *);
extern int gt_pch_note_object (void *, void *, gt_note_pointers,
          enum gt_types_enum);
extern void gt_pch_note_reorder (void *, void *, gt_handle_reorder);
typedef void (*gt_pointer_walker) (void *);
struct ggc_root_tab {
  void *base;
  size_t nelt;
  size_t stride;
  gt_pointer_walker cb;
  gt_pointer_walker pchw;
};
extern const struct ggc_root_tab * const gt_ggc_rtab[];
extern const struct ggc_root_tab * const gt_ggc_deletable_rtab[];
extern const struct ggc_root_tab * const gt_pch_cache_rtab[];
extern const struct ggc_root_tab * const gt_pch_scalar_rtab[];
struct htab;
struct ggc_cache_tab {
  struct htab * *base;
  size_t nelt;
  size_t stride;
  gt_pointer_walker cb;
  gt_pointer_walker pchw;
  int (*marked_p) (const void *);
};
extern const struct ggc_cache_tab * const gt_ggc_cache_rtab[];
# 112 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/ggc.h"
extern int ggc_set_mark (const void *);
extern int ggc_marked_p (const void *);
extern void gt_pch_n_S (const void *);
extern void gt_ggc_m_S (const void *);
struct alloc_zone;
extern void init_stringpool (void);
extern void init_ggc (void);
extern unsigned char ggc_protect_identifiers;
extern void gt_pch_save (FILE *f);
extern void *ggc_internal_alloc_stat (size_t );
extern size_t ggc_round_alloc_size (size_t requested_size);
extern void *ggc_alloc_typed_stat (enum gt_types_enum, size_t );
extern void *ggc_internal_cleared_alloc_stat (size_t );
extern void *ggc_realloc_stat (void *, size_t );
extern void ggc_free (void *);
extern void ggc_record_overhead (size_t, size_t, void * );
extern void ggc_free_overhead (void *);
extern void ggc_prune_overhead_list (void);
extern void dump_ggc_loc_statistics (unsigned char);
# 179 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/ggc.h"
static __inline__ void *
ggc_internal_vec_alloc_stat (size_t s, size_t c )
{
    return ggc_internal_alloc_stat (c * s );
}
static __inline__ void *
ggc_internal_cleared_vec_alloc_stat (size_t s, size_t c )
{
    return ggc_internal_cleared_alloc_stat (c * s );
}
static __inline__ void *
ggc_alloc_atomic_stat (size_t s )
{
    return ggc_internal_alloc_stat (s );
}
extern void * ggc_cleared_alloc_htab_ignore_args (size_t, size_t);
extern void * ggc_cleared_alloc_ptr_array_two_args (size_t, size_t);
# 219 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/ggc.h"
extern void *ggc_splay_alloc (enum gt_types_enum, int, void *);
extern void ggc_splay_dont_free (void *, void *);
extern const char *ggc_alloc_string_stat (const char *contents, int length
                                          );
# 236 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/ggc.h"
extern void ggc_collect (void);
extern void ggc_register_root_tab (const struct ggc_root_tab *);
extern void ggc_register_cache_tab (const struct ggc_cache_tab *);
extern void gt_pch_restore (FILE *f);
extern void ggc_print_statistics (void);
extern void stringpool_statistics (void);
extern void init_ggc_heuristics (void);
extern struct alloc_zone rtl_zone;
extern struct alloc_zone tree_zone;
extern struct alloc_zone tree_id_zone;
# 307 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/ggc.h"
static __inline__ void *
ggc_internal_zone_alloc_stat (struct alloc_zone * z __attribute__ ((__unused__)),
                              size_t s )
{
    return ggc_internal_alloc_stat (s );
}
static __inline__ void *
ggc_internal_zone_cleared_alloc_stat (struct alloc_zone * z __attribute__ ((__unused__)),
                                      size_t s )
{
    return ggc_internal_cleared_alloc_stat (s );
}
static __inline__ void *
ggc_internal_zone_vec_alloc_stat (struct alloc_zone * z __attribute__ ((__unused__)),
                                  size_t s, size_t n )
{
    return ggc_internal_vec_alloc_stat (s, n );
}
static __inline__ struct rtx_def *
ggc_alloc_zone_rtx_def_stat (struct alloc_zone * z, size_t s )
{
  return (struct rtx_def *) ggc_internal_zone_alloc_stat (z, s );
}
static __inline__ union tree_node *
ggc_alloc_zone_tree_node_stat (struct alloc_zone * z, size_t s )
{
  return (union tree_node *) ggc_internal_zone_alloc_stat (z, s );
}
static __inline__ union tree_node *
ggc_alloc_zone_cleared_tree_node_stat (struct alloc_zone * z, size_t s
                                       )
{
  return (union tree_node *)
    ggc_internal_zone_cleared_alloc_stat (z, s );
}
static __inline__ union gimple_statement_d *
ggc_alloc_cleared_gimple_statement_d_stat (size_t s )
{
  return (union gimple_statement_d *)
    ggc_internal_cleared_alloc_stat (s );
}
# 28 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h" 2
# 43 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/diagnostic-core.h" 1
# 28 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/diagnostic-core.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/bversion.h" 1
# 29 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/diagnostic-core.h" 2
typedef enum
{
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/diagnostic.def" 1
# 25 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/diagnostic.def"
DK_UNSPECIFIED,
DK_IGNORED,
DK_FATAL,
DK_ICE,
DK_ERROR,
DK_SORRY,
DK_WARNING,
DK_ANACHRONISM,
DK_NOTE,
DK_DEBUG,
DK_PEDWARN,
DK_PERMERROR,
# 35 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/diagnostic-core.h" 2
  DK_LAST_DIAGNOSTIC_KIND,
  DK_POP
} diagnostic_t;
extern const char *progname;
extern const char *trim_filename (const char *);
# 59 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/diagnostic-core.h"
extern void internal_error (const char *, ...) __attribute__ ((__nonnull__ (1)))
     __attribute__ ((__noreturn__));
extern unsigned char warning (int, const char *, ...) __attribute__ ((__nonnull__ (2)));
extern unsigned char warning_at (location_t, int, const char *, ...)
    __attribute__ ((__nonnull__ (3)));
extern void error (const char *, ...) __attribute__ ((__nonnull__ (1)));
extern void error_n (location_t, int, const char *, const char *, ...)
    __attribute__ ((__nonnull__ (3))) __attribute__ ((__nonnull__ (4)));
extern void error_at (location_t, const char *, ...) __attribute__ ((__nonnull__ (2)));
extern void fatal_error (const char *, ...) __attribute__ ((__nonnull__ (1)))
     __attribute__ ((__noreturn__));
extern unsigned char pedwarn (location_t, int, const char *, ...)
     __attribute__ ((__nonnull__ (3)));
extern unsigned char permerror (location_t, const char *, ...) __attribute__ ((__nonnull__ (2)));
extern void sorry (const char *, ...) __attribute__ ((__nonnull__ (1)));
extern void inform (location_t, const char *, ...) __attribute__ ((__nonnull__ (2)));
extern void inform_n (location_t, int, const char *, const char *, ...)
    __attribute__ ((__nonnull__ (3))) __attribute__ ((__nonnull__ (4)));
extern void verbatim (const char *, ...) __attribute__ ((__nonnull__ (1)));
extern unsigned char emit_diagnostic (diagnostic_t, location_t, int,
        const char *, ...) __attribute__ ((__nonnull__ (4)));
extern unsigned char seen_error (void);
extern void fnotice (FILE *, const char *, ...)
     __attribute__ ((__format__ (__printf__, 2, 3))) __attribute__ ((__nonnull__ (2)));
# 44 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h" 2
# 63 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h"
enum rid
{
  RID_STATIC = 0,
  RID_UNSIGNED, RID_LONG, RID_CONST, RID_EXTERN,
  RID_REGISTER, RID_TYPEDEF, RID_SHORT, RID_INLINE,
  RID_VOLATILE, RID_SIGNED, RID_AUTO, RID_RESTRICT,
  RID_NORETURN,
  RID_COMPLEX, RID_THREAD, RID_SAT,
  RID_FRIEND, RID_VIRTUAL, RID_EXPLICIT, RID_EXPORT, RID_MUTABLE,
  RID_IN, RID_OUT, RID_INOUT, RID_BYCOPY, RID_BYREF, RID_ONEWAY,
  RID_GETTER, RID_SETTER,
  RID_READONLY, RID_READWRITE,
  RID_ASSIGN, RID_RETAIN, RID_COPY,
  RID_NONATOMIC,
  RID_IMAGINARY,
  RID_INT, RID_CHAR, RID_FLOAT, RID_DOUBLE, RID_VOID,
  RID_INT128,
  RID_ENUM, RID_STRUCT, RID_UNION, RID_IF, RID_ELSE,
  RID_WHILE, RID_DO, RID_FOR, RID_SWITCH, RID_CASE,
  RID_DEFAULT, RID_BREAK, RID_CONTINUE, RID_RETURN, RID_GOTO,
  RID_SIZEOF,
  RID_ASM, RID_TYPEOF, RID_ALIGNOF, RID_ATTRIBUTE, RID_VA_ARG,
  RID_EXTENSION, RID_IMAGPART, RID_REALPART, RID_LABEL, RID_CHOOSE_EXPR,
  RID_TYPES_COMPATIBLE_P, RID_BUILTIN_COMPLEX, RID_BUILTIN_SHUFFLE,
  RID_DFLOAT32, RID_DFLOAT64, RID_DFLOAT128,
  RID_FRACT, RID_ACCUM,
  RID_ALIGNAS,
  RID_CXX_COMPAT_WARN,
  RID_TRANSACTION_ATOMIC, RID_TRANSACTION_RELAXED, RID_TRANSACTION_CANCEL,
  RID_FUNCTION_NAME, RID_PRETTY_FUNCTION_NAME, RID_C99_FUNCTION_NAME,
  RID_BOOL, RID_WCHAR, RID_CLASS,
  RID_PUBLIC, RID_PRIVATE, RID_PROTECTED,
  RID_TEMPLATE, RID_NULL, RID_CATCH,
  RID_DELETE, RID_FALSE, RID_NAMESPACE,
  RID_NEW, RID_OFFSETOF, RID_OPERATOR,
  RID_THIS, RID_THROW, RID_TRUE,
  RID_TRY, RID_TYPENAME, RID_TYPEID,
  RID_USING, RID_CHAR16, RID_CHAR32,
  RID_CONSTCAST, RID_DYNCAST, RID_REINTCAST, RID_STATCAST,
  RID_BASES, RID_DIRECT_BASES,
  RID_HAS_NOTHROW_ASSIGN, RID_HAS_NOTHROW_CONSTRUCTOR,
  RID_HAS_NOTHROW_COPY, RID_HAS_TRIVIAL_ASSIGN,
  RID_HAS_TRIVIAL_CONSTRUCTOR, RID_HAS_TRIVIAL_COPY,
  RID_HAS_TRIVIAL_DESTRUCTOR, RID_HAS_VIRTUAL_DESTRUCTOR,
  RID_IS_ABSTRACT, RID_IS_BASE_OF,
  RID_IS_CLASS, RID_IS_CONVERTIBLE_TO,
  RID_IS_EMPTY, RID_IS_ENUM,
  RID_IS_FINAL, RID_IS_LITERAL_TYPE,
  RID_IS_POD, RID_IS_POLYMORPHIC,
  RID_IS_STD_LAYOUT, RID_IS_TRIVIAL,
  RID_IS_UNION, RID_UNDERLYING_TYPE,
  RID_CONSTEXPR, RID_DECLTYPE, RID_NOEXCEPT, RID_NULLPTR, RID_STATIC_ASSERT,
  RID_AT_ENCODE, RID_AT_END,
  RID_AT_CLASS, RID_AT_ALIAS, RID_AT_DEFS,
  RID_AT_PRIVATE, RID_AT_PROTECTED, RID_AT_PUBLIC, RID_AT_PACKAGE,
  RID_AT_PROTOCOL, RID_AT_SELECTOR,
  RID_AT_THROW, RID_AT_TRY, RID_AT_CATCH,
  RID_AT_FINALLY, RID_AT_SYNCHRONIZED,
  RID_AT_OPTIONAL, RID_AT_REQUIRED, RID_AT_PROPERTY,
  RID_AT_SYNTHESIZE, RID_AT_DYNAMIC,
  RID_AT_INTERFACE,
  RID_AT_IMPLEMENTATION,
  RID_ADDR_SPACE_0,
  RID_ADDR_SPACE_1,
  RID_ADDR_SPACE_2,
  RID_ADDR_SPACE_3,
  RID_ADDR_SPACE_4,
  RID_ADDR_SPACE_5,
  RID_ADDR_SPACE_6,
  RID_ADDR_SPACE_7,
  RID_ADDR_SPACE_8,
  RID_ADDR_SPACE_9,
  RID_ADDR_SPACE_10,
  RID_ADDR_SPACE_11,
  RID_ADDR_SPACE_12,
  RID_ADDR_SPACE_13,
  RID_ADDR_SPACE_14,
  RID_ADDR_SPACE_15,
  RID_FIRST_ADDR_SPACE = RID_ADDR_SPACE_0,
  RID_LAST_ADDR_SPACE = RID_ADDR_SPACE_15,
  RID_MAX,
  RID_FIRST_MODIFIER = RID_STATIC,
  RID_LAST_MODIFIER = RID_ONEWAY,
  RID_FIRST_CXX0X = RID_CONSTEXPR,
  RID_LAST_CXX0X = RID_STATIC_ASSERT,
  RID_FIRST_AT = RID_AT_ENCODE,
  RID_LAST_AT = RID_AT_IMPLEMENTATION,
  RID_FIRST_PQ = RID_IN,
  RID_LAST_PQ = RID_ONEWAY,
  RID_FIRST_PATTR = RID_GETTER,
  RID_LAST_PATTR = RID_NONATOMIC
};
# 231 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h"
extern tree *ridpointers;
enum c_tree_index
{
    CTI_CHAR16_TYPE,
    CTI_CHAR32_TYPE,
    CTI_WCHAR_TYPE,
    CTI_UNDERLYING_WCHAR_TYPE,
    CTI_WINT_TYPE,
    CTI_SIGNED_SIZE_TYPE,
    CTI_UNSIGNED_PTRDIFF_TYPE,
    CTI_INTMAX_TYPE,
    CTI_UINTMAX_TYPE,
    CTI_WIDEST_INT_LIT_TYPE,
    CTI_WIDEST_UINT_LIT_TYPE,
    CTI_SIG_ATOMIC_TYPE,
    CTI_INT8_TYPE,
    CTI_INT16_TYPE,
    CTI_INT32_TYPE,
    CTI_INT64_TYPE,
    CTI_UINT8_TYPE,
    CTI_UINT16_TYPE,
    CTI_UINT32_TYPE,
    CTI_UINT64_TYPE,
    CTI_INT_LEAST8_TYPE,
    CTI_INT_LEAST16_TYPE,
    CTI_INT_LEAST32_TYPE,
    CTI_INT_LEAST64_TYPE,
    CTI_UINT_LEAST8_TYPE,
    CTI_UINT_LEAST16_TYPE,
    CTI_UINT_LEAST32_TYPE,
    CTI_UINT_LEAST64_TYPE,
    CTI_INT_FAST8_TYPE,
    CTI_INT_FAST16_TYPE,
    CTI_INT_FAST32_TYPE,
    CTI_INT_FAST64_TYPE,
    CTI_UINT_FAST8_TYPE,
    CTI_UINT_FAST16_TYPE,
    CTI_UINT_FAST32_TYPE,
    CTI_UINT_FAST64_TYPE,
    CTI_INTPTR_TYPE,
    CTI_UINTPTR_TYPE,
    CTI_CHAR_ARRAY_TYPE,
    CTI_CHAR16_ARRAY_TYPE,
    CTI_CHAR32_ARRAY_TYPE,
    CTI_WCHAR_ARRAY_TYPE,
    CTI_INT_ARRAY_TYPE,
    CTI_STRING_TYPE,
    CTI_CONST_STRING_TYPE,
    CTI_TRUTHVALUE_TYPE,
    CTI_TRUTHVALUE_TRUE,
    CTI_TRUTHVALUE_FALSE,
    CTI_DEFAULT_FUNCTION_TYPE,
    CTI_FUNCTION_NAME_DECL,
    CTI_PRETTY_FUNCTION_NAME_DECL,
    CTI_C99_FUNCTION_NAME_DECL,
    CTI_SAVED_FUNCTION_NAME_DECLS,
    CTI_VOID_ZERO,
    CTI_NULL,
    CTI_MAX
};
# 316 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h"
struct c_common_identifier {
  struct tree_common common;
  struct cpp_hashnode node;
};
struct c_common_resword
{
  const char *const word;
  __extension__ enum rid const rid : 16;
  const unsigned int disable : 16;
};
# 370 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h"
extern const struct c_common_resword c_common_reswords[];
extern const unsigned int num_c_common_reswords;
# 440 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h"
extern tree c_global_trees[CTI_MAX];
struct sorted_fields_type {
  int len;
  tree elts[1];
};
typedef enum c_language_kind
{
  clk_c = 0,
  clk_objc = 1,
  clk_cxx = 2,
  clk_objcxx = 3
}
c_language_kind;
extern c_language_kind c_language;
typedef enum ref_operator {
  RO_NULL,
  RO_ARRAY_INDEXING,
  RO_UNARY_STAR,
  RO_ARROW,
  RO_IMPLICIT_CONVERSION
} ref_operator;
struct stmt_tree_s {
  VEC_tree_gc *x_cur_stmt_list;
# 498 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h"
  int stmts_are_full_exprs_p;
};
typedef struct stmt_tree_s *stmt_tree;
struct c_language_function {
  struct stmt_tree_s x_stmt_tree;
  VEC_tree_gc *local_typedefs;
};
# 532 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h"
extern void (*lang_post_pch_load) (void);
extern void push_file_scope (void);
extern void pop_file_scope (void);
extern stmt_tree current_stmt_tree (void);
extern tree push_stmt_list (void);
extern tree pop_stmt_list (tree);
extern tree add_stmt (tree);
extern void push_cleanup (tree, tree, unsigned char);
extern tree pushdecl_top_level (tree);
extern tree pushdecl (tree);
extern tree build_modify_expr (location_t, tree, tree, enum tree_code,
          location_t, tree, tree);
extern tree build_indirect_ref (location_t, tree, ref_operator);
extern int c_expand_decl (tree);
extern int field_decl_cmp (const void *, const void *);
extern void resort_sorted_fields (void *, void *, gt_pointer_operator,
      void *);
extern unsigned char has_c_linkage (const_tree decl);
extern char flag_no_line_commands;
extern char flag_no_output;
extern char flag_dump_macros;
extern char flag_dump_includes;
extern unsigned char flag_pch_preprocess;
extern const char *pch_file;
extern int flag_iso;
extern int warn_unknown_pragmas;
extern int warn_format;
# 604 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h"
extern int flag_cond_mismatch;
extern int flag_isoc94;
extern int flag_isoc99;
extern int flag_isoc11;
extern int flag_hosted;
# 629 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h"
extern int print_struct_values;
extern const char *constant_string_class_name;
# 642 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h"
extern int flag_use_repository;
enum cxx_dialect {
  cxx98,
  cxx03 = cxx98,
  cxx0x,
  cxx11 = cxx0x
};
extern enum cxx_dialect cxx_dialect;
extern int max_tinst_depth;
extern int c_inhibit_evaluation_warnings;
extern unsigned char done_lexing;
# 693 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h"
struct visibility_flags
{
  unsigned inpragma : 1;
  unsigned inlines_hidden : 1;
};
extern struct visibility_flags visibility_options;
extern const struct attribute_spec c_common_attribute_table[];
extern const struct attribute_spec c_common_format_attribute_table[];
extern tree (*make_fname_decl) (location_t, tree, int);
extern void c_register_addr_space (const char *str, addr_space_t as);
extern unsigned char in_late_binary_op;
extern const char *c_addr_space_name (addr_space_t as);
extern tree identifier_global_value (tree);
extern tree c_linkage_bindings (tree);
extern void record_builtin_type (enum rid, const char *, tree);
extern tree build_void_list_node (void);
extern void start_fname_decls (void);
extern void finish_fname_decls (void);
extern const char *fname_as_string (int);
extern tree fname_decl (location_t, unsigned, tree);
extern int check_user_alignment (const_tree, unsigned char);
extern void check_function_arguments (const_tree, int, tree *);
extern void check_function_arguments_recurse (void (*)
           (void *, tree,
            unsigned long long),
           void *, tree,
           unsigned long long);
extern unsigned char check_builtin_function_arguments (tree, int, tree *);
extern void check_function_format (tree, int, tree *);
extern void set_Wformat (int);
extern tree handle_format_attribute (tree *, tree, tree, int, unsigned char *);
extern tree handle_format_arg_attribute (tree *, tree, tree, int, unsigned char *);
extern unsigned char attribute_takes_identifier_p (const_tree);
extern unsigned char c_common_handle_option (size_t, const char *, int, int, location_t,
        const struct cl_option_handlers *);
extern unsigned char default_handle_c_option (size_t, const char *, int);
extern tree c_common_type_for_mode (enum machine_mode, int);
extern tree c_common_type_for_size (unsigned int, int);
extern tree c_common_fixed_point_type_for_size (unsigned int, unsigned int,
      int, int);
extern tree c_common_unsigned_type (tree);
extern tree c_common_signed_type (tree);
extern tree c_common_signed_or_unsigned_type (int, tree);
extern void c_common_init_ts (void);
extern tree c_build_bitfield_integer_type (unsigned long long, int);
extern unsigned char unsafe_conversion_p (tree, tree, unsigned char);
extern unsigned char decl_with_nonnull_addr_p (const_tree);
extern tree c_fully_fold (tree, unsigned char, unsigned char *);
extern tree decl_constant_value_for_optimization (tree);
extern tree c_wrap_maybe_const (tree, unsigned char);
extern tree c_save_expr (tree);
extern tree c_common_truthvalue_conversion (location_t, tree);
extern void c_apply_type_quals_to_decl (int, tree);
extern tree c_sizeof_or_alignof_type (location_t, tree, unsigned char, int);
extern tree c_alignof_expr (location_t, tree);
extern void binary_op_error (location_t, enum tree_code, tree, tree);
extern tree fix_string_type (tree);
extern void constant_expression_warning (tree);
extern void constant_expression_error (tree);
extern unsigned char strict_aliasing_warning (tree, tree, tree);
extern void warnings_for_convert_and_check (tree, tree, tree);
extern tree convert_and_check (tree, tree);
extern void overflow_warning (location_t, tree);
extern void warn_logical_operator (location_t, enum tree_code, tree,
       enum tree_code, tree, enum tree_code, tree);
extern void check_main_parameter_types (tree decl);
extern unsigned char c_determine_visibility (tree);
extern unsigned char same_scalar_type_ignoring_signedness (tree, tree);
extern void mark_valid_location_for_stdc_pragma (unsigned char);
extern unsigned char valid_location_for_stdc_pragma_p (void);
extern void set_float_const_decimal64 (void);
extern void clear_float_const_decimal64 (void);
extern unsigned char float_const_decimal64_p (void);
extern unsigned char keyword_begins_type_specifier (enum rid);
extern unsigned char keyword_is_storage_class_specifier (enum rid);
extern unsigned char keyword_is_type_qualifier (enum rid);
extern unsigned char keyword_is_decl_specifier (enum rid);
extern tree shorten_binary_op (tree result_type, tree op0, tree op1, unsigned char bitwise);
extern tree shorten_compare (tree *, tree *, tree *, enum tree_code *);
extern tree pointer_int_sum (location_t, enum tree_code, tree, tree);
extern tree c_build_qualified_type (tree, int);
extern void c_common_nodes_and_builtins (void);
extern void disable_builtin_function (const char *);
extern void set_compound_literal_name (tree decl);
extern tree build_va_arg (location_t, tree, tree);
extern const unsigned int c_family_lang_mask;
extern unsigned int c_common_option_lang_mask (void);
extern void c_common_initialize_diagnostics (diagnostic_context *);
extern unsigned char c_common_complain_wrong_lang_p (const struct cl_option *);
extern void c_common_init_options_struct (struct gcc_options *);
extern void c_common_init_options (unsigned int, struct cl_decoded_option *);
extern unsigned char c_common_post_options (const char **);
extern unsigned char c_common_init (void);
extern void c_common_finish (void);
extern void c_common_parse_file (void);
extern alias_set_type c_common_get_alias_set (tree);
extern void c_register_builtin_type (tree, const char*);
extern unsigned char c_promoting_integer_type_p (const_tree);
extern int self_promoting_args_p (const_tree);
extern tree strip_pointer_operator (tree);
extern tree strip_pointer_or_array_types (tree);
extern long long c_common_to_target_charset (long long);
extern void c_parse_file (void);
extern void warn_for_omitted_condop (location_t, tree);
# 872 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h"
extern tree do_case (location_t, tree, tree);
extern tree build_stmt (location_t, enum tree_code, ...);
extern tree build_real_imag_expr (location_t, enum tree_code, tree);
extern tree build_unary_op (location_t, enum tree_code, tree, int);
extern tree build_binary_op (location_t, enum tree_code, tree, tree, int);
extern tree perform_integral_promotions (tree);
extern tree default_conversion (tree);
extern tree common_type (tree, tree);
extern tree decl_constant_value (tree);
extern tree boolean_increment (enum tree_code, tree);
extern int case_compare (splay_tree_key, splay_tree_key);
extern tree c_add_case_label (location_t, splay_tree, tree, tree, tree, tree);
extern void c_do_switch_warnings (splay_tree, location_t, tree, tree);
extern tree build_function_call (location_t, tree, tree);
extern tree build_function_call_vec (location_t, tree,
             VEC_tree_gc *, VEC_tree_gc *);
extern tree resolve_overloaded_builtin (location_t, tree, VEC_tree_gc *);
extern tree finish_label_address_expr (tree, location_t);
extern tree lookup_label (tree);
extern tree lookup_name (tree);
extern unsigned char lvalue_p (const_tree);
extern unsigned char vector_targets_convertible_p (const_tree t1, const_tree t2);
extern unsigned char vector_types_convertible_p (const_tree t1, const_tree t2, unsigned char emit_lax_note);
extern rtx c_expand_expr (tree, rtx, enum machine_mode, int, rtx *);
extern void init_c_lex (void);
extern void c_cpp_builtins (cpp_reader *);
extern void c_cpp_builtins_optimize_pragma (cpp_reader *, tree, tree);
extern unsigned char c_cpp_error (cpp_reader *, int, int, location_t, unsigned int,
    const char *, va_list *)
     __attribute__ ((__nonnull__ (6)));
extern unsigned char parse_optimize_options (tree, unsigned char);
extern int pending_lang_change;
struct c_fileinfo
{
  int time;
  short interface_only;
  short interface_unknown;
};
struct c_fileinfo *get_fileinfo (const char *);
extern void dump_time_statistics (void);
extern unsigned char c_dump_tree (void *, tree);
extern void verify_sequence_points (tree);
extern tree fold_offsetof_1 (tree);
extern tree fold_offsetof (tree);
enum lvalue_use {
  lv_assign,
  lv_increment,
  lv_decrement,
  lv_addressof,
  lv_asm
};
extern void readonly_error (tree, enum lvalue_use);
extern void lvalue_error (location_t, enum lvalue_use);
extern void invalid_indirection_error (location_t, tree, ref_operator);
extern int complete_array_type (tree *, tree, unsigned char);
extern tree builtin_type_for_size (int, unsigned char);
extern void c_common_mark_addressable_vec (tree);
extern void warn_array_subscript_with_type_char (tree);
extern void warn_about_parentheses (enum tree_code,
        enum tree_code, tree,
        enum tree_code, tree);
extern void warn_for_unused_label (tree label);
extern void warn_for_div_by_zero (location_t, tree divisor);
extern void warn_for_sign_compare (location_t,
       tree orig_op0, tree orig_op1,
       tree op0, tree op1,
       tree result_type,
       enum tree_code resultcode);
extern void do_warn_double_promotion (tree, tree, tree, const char *,
          location_t);
extern void set_underlying_type (tree);
extern void record_locally_defined_typedef (tree);
extern void maybe_record_typedef_use (tree);
extern void maybe_warn_unused_local_typedefs (void);
extern VEC_tree_gc *make_tree_vector (void);
extern void release_tree_vector (VEC_tree_gc *);
extern VEC_tree_gc *make_tree_vector_single (tree);
extern VEC_tree_gc *make_tree_vector_from_list (tree);
extern VEC_tree_gc *make_tree_vector_copy (const VEC_tree_gc *);
extern void c_genericize (tree);
extern int c_gimplify_expr (tree *, gimple_seq *, gimple_seq *);
extern tree c_build_bind_expr (location_t, tree, tree);
extern void pch_init (void);
extern int c_common_valid_pch (cpp_reader *pfile, const char *name, int fd);
extern void c_common_read_pch (cpp_reader *pfile, const char *name, int fd,
          const char *orig);
extern void c_common_write_pch (void);
extern void c_common_no_more_pch (void);
extern void c_common_pch_pragma (cpp_reader *pfile, const char *);
extern void c_common_print_pch_checksum (FILE *f);
extern const unsigned char executable_checksum[16];
extern void builtin_define_std (const char *macro);
extern void builtin_define_with_value (const char *, const char *, int);
extern void c_stddef_cpp_builtins (void);
extern void fe_file_change (const struct line_map *);
extern void c_parse_error (const char *, enum cpp_ttype, tree, unsigned char);
extern void init_pp_output (FILE *);
extern void preprocess_file (cpp_reader *);
extern void pp_file_change (const struct line_map *);
extern void pp_dir_change (cpp_reader *, const char *);
extern unsigned char check_missing_format_attribute (tree, tree);
extern tree c_finish_omp_master (location_t, tree);
extern tree c_finish_omp_critical (location_t, tree, tree);
extern tree c_finish_omp_ordered (location_t, tree);
extern void c_finish_omp_barrier (location_t);
extern tree c_finish_omp_atomic (location_t, enum tree_code, enum tree_code,
     tree, tree, tree, tree, tree);
extern void c_finish_omp_flush (location_t);
extern void c_finish_omp_taskwait (location_t);
extern void c_finish_omp_taskyield (location_t);
extern tree c_finish_omp_for (location_t, tree, tree, tree, tree, tree, tree);
extern void c_split_parallel_clauses (location_t, tree, tree *, tree *);
extern enum omp_clause_default_kind c_omp_predetermined_sharing (tree);
extern unsigned char c_omp_sharing_predetermined (tree);
extern tree c_omp_remap_decl (tree, unsigned char);
extern void record_types_used_by_current_var_decl (tree);
static __inline__ tree
c_tree_chain_next (tree t)
{
  if ((tree_contains_struct[(((enum tree_code) (t)->base.code))][(TS_TYPE_COMMON)]))
    return ((t)->type_common.next_variant);
  if ((tree_contains_struct[(((enum tree_code) (t)->base.code))][(TS_COMMON)]))
    return ((t)->common.chain);
  return ((void *)0);
}
extern int parse_tm_stmt_attr (tree, int);
# 1092 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h"
extern int tm_attr_to_mask (tree);
extern tree tm_mask_to_attr (int);
extern tree find_tm_attribute (tree);
struct tree_userdef_literal {
  struct tree_base base;
  tree suffix_id;
  tree value;
  tree num_string;
};
# 1117 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/c-common.h"
extern tree build_userdef_literal (tree suffix_id, tree value, tree num_string);
# 40 "../../../src/plugin-utils.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/function.h" 1
# 25 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/function.h"
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tree.h" 1
# 26 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/function.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/vecprim.h" 1
# 23 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/vecprim.h"
static __inline__ void VEC_char_must_be_integral_type (void) { (void)~(char)0; } typedef struct VEC_char_base { struct vec_prefix prefix; char vec[1]; } VEC_char_base; typedef struct VEC_char_none { VEC_char_base base; } VEC_char_none; static __inline__ unsigned VEC_char_base_length (const VEC_char_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static __inline__ char VEC_char_base_last (const VEC_char_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static __inline__ char VEC_char_base_index (const VEC_char_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static __inline__ int VEC_char_base_iterate (const VEC_char_base *vec_, unsigned ix_, char *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (char) 0; return 0; } } static __inline__ size_t VEC_char_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_char_base, vec) + alloc_ * sizeof(char); } static __inline__ void VEC_char_base_embedded_init (VEC_char_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static __inline__ int VEC_char_base_space (VEC_char_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static __inline__ void VEC_char_base_splice (VEC_char_base *dst_, VEC_char_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (char)); dst_->prefix.num += len_; } } static __inline__ char *VEC_char_base_quick_push (VEC_char_base *vec_, char obj_ ) { char *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static __inline__ char VEC_char_base_pop (VEC_char_base *vec_ ) { char obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_char_base_truncate (VEC_char_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static __inline__ char VEC_char_base_replace (VEC_char_base *vec_, unsigned ix_, char obj_ ) { char old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ char *VEC_char_base_quick_insert (VEC_char_base *vec_, unsigned ix_, char obj_ ) { char *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (char)); *slot_ = obj_; return slot_; } static __inline__ char VEC_char_base_ordered_remove (VEC_char_base *vec_, unsigned ix_ ) { char *slot_; char obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (char)); return obj_; } static __inline__ char VEC_char_base_unordered_remove (VEC_char_base *vec_, unsigned ix_ ) { char *slot_; char obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_char_base_block_remove (VEC_char_base *vec_, unsigned ix_, unsigned len_ ) { char *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (char)); } static __inline__ char *VEC_char_base_address (VEC_char_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_char_base_lower_bound (VEC_char_base *vec_, const char obj_, unsigned char (*lessthan_)(const char, const char) ) { unsigned int len_ = VEC_char_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { char middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_char_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_char_heap { VEC_char_base base; } VEC_char_heap; static __inline__ VEC_char_heap *VEC_char_heap_alloc (int alloc_ ) { return (VEC_char_heap *) vec_heap_o_reserve_exact (((void *)0), alloc_, __builtin_offsetof (VEC_char_heap, base.vec), sizeof (char) ); } static __inline__ VEC_char_heap *VEC_char_heap_copy (VEC_char_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_char_heap *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_char_heap *)(vec_heap_o_reserve_exact (((void *)0), len_, __builtin_offsetof (VEC_char_heap, base.vec), sizeof (char) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (char) * len_); } return new_vec_; } static __inline__ void VEC_char_heap_free (VEC_char_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = ((void *)0); } static __inline__ int VEC_char_heap_reserve (VEC_char_heap **vec_, int alloc_ ) { int extend = !VEC_char_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_char_heap *) vec_heap_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_char_heap, base.vec), sizeof (char) ); return extend; } static __inline__ int VEC_char_heap_reserve_exact (VEC_char_heap **vec_, int alloc_ ) { int extend = !VEC_char_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_char_heap *) vec_heap_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_char_heap, base.vec), sizeof (char) ); return extend; } static __inline__ void VEC_char_heap_safe_grow (VEC_char_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_char_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_char_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_char_heap_safe_grow_cleared (VEC_char_heap **vec_, int size_ ) { int oldsize = VEC_char_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_char_heap_safe_grow (vec_, size_ ); memset (&(VEC_char_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (char) * (size_ - oldsize)); } static __inline__ void VEC_char_heap_safe_splice (VEC_char_heap **dst_, VEC_char_base *src_ ) { if (src_) { VEC_char_heap_reserve_exact (dst_, src_->prefix.num ); VEC_char_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ char *VEC_char_heap_safe_push (VEC_char_heap **vec_, const char obj_ ) { VEC_char_heap_reserve (vec_, 1 ); return VEC_char_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ char *VEC_char_heap_safe_insert (VEC_char_heap **vec_, unsigned ix_, const char obj_ ) { VEC_char_heap_reserve (vec_, 1 ); return VEC_char_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
typedef unsigned char uchar;
static __inline__ void VEC_uchar_must_be_integral_type (void) { (void)~(uchar)0; } typedef struct VEC_uchar_base { struct vec_prefix prefix; uchar vec[1]; } VEC_uchar_base; typedef struct VEC_uchar_none { VEC_uchar_base base; } VEC_uchar_none; static __inline__ unsigned VEC_uchar_base_length (const VEC_uchar_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static __inline__ uchar VEC_uchar_base_last (const VEC_uchar_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static __inline__ uchar VEC_uchar_base_index (const VEC_uchar_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static __inline__ int VEC_uchar_base_iterate (const VEC_uchar_base *vec_, unsigned ix_, uchar *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (uchar) 0; return 0; } } static __inline__ size_t VEC_uchar_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_uchar_base, vec) + alloc_ * sizeof(uchar); } static __inline__ void VEC_uchar_base_embedded_init (VEC_uchar_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static __inline__ int VEC_uchar_base_space (VEC_uchar_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static __inline__ void VEC_uchar_base_splice (VEC_uchar_base *dst_, VEC_uchar_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (uchar)); dst_->prefix.num += len_; } } static __inline__ uchar *VEC_uchar_base_quick_push (VEC_uchar_base *vec_, uchar obj_ ) { uchar *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static __inline__ uchar VEC_uchar_base_pop (VEC_uchar_base *vec_ ) { uchar obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_uchar_base_truncate (VEC_uchar_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static __inline__ uchar VEC_uchar_base_replace (VEC_uchar_base *vec_, unsigned ix_, uchar obj_ ) { uchar old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ uchar *VEC_uchar_base_quick_insert (VEC_uchar_base *vec_, unsigned ix_, uchar obj_ ) { uchar *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (uchar)); *slot_ = obj_; return slot_; } static __inline__ uchar VEC_uchar_base_ordered_remove (VEC_uchar_base *vec_, unsigned ix_ ) { uchar *slot_; uchar obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (uchar)); return obj_; } static __inline__ uchar VEC_uchar_base_unordered_remove (VEC_uchar_base *vec_, unsigned ix_ ) { uchar *slot_; uchar obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_uchar_base_block_remove (VEC_uchar_base *vec_, unsigned ix_, unsigned len_ ) { uchar *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (uchar)); } static __inline__ uchar *VEC_uchar_base_address (VEC_uchar_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_uchar_base_lower_bound (VEC_uchar_base *vec_, const uchar obj_, unsigned char (*lessthan_)(const uchar, const uchar) ) { unsigned int len_ = VEC_uchar_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { uchar middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_uchar_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_uchar_heap { VEC_uchar_base base; } VEC_uchar_heap; static __inline__ VEC_uchar_heap *VEC_uchar_heap_alloc (int alloc_ ) { return (VEC_uchar_heap *) vec_heap_o_reserve_exact (((void *)0), alloc_, __builtin_offsetof (VEC_uchar_heap, base.vec), sizeof (uchar) ); } static __inline__ VEC_uchar_heap *VEC_uchar_heap_copy (VEC_uchar_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_uchar_heap *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_uchar_heap *)(vec_heap_o_reserve_exact (((void *)0), len_, __builtin_offsetof (VEC_uchar_heap, base.vec), sizeof (uchar) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (uchar) * len_); } return new_vec_; } static __inline__ void VEC_uchar_heap_free (VEC_uchar_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = ((void *)0); } static __inline__ int VEC_uchar_heap_reserve (VEC_uchar_heap **vec_, int alloc_ ) { int extend = !VEC_uchar_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_uchar_heap *) vec_heap_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_uchar_heap, base.vec), sizeof (uchar) ); return extend; } static __inline__ int VEC_uchar_heap_reserve_exact (VEC_uchar_heap **vec_, int alloc_ ) { int extend = !VEC_uchar_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_uchar_heap *) vec_heap_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_uchar_heap, base.vec), sizeof (uchar) ); return extend; } static __inline__ void VEC_uchar_heap_safe_grow (VEC_uchar_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_uchar_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_uchar_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_uchar_heap_safe_grow_cleared (VEC_uchar_heap **vec_, int size_ ) { int oldsize = VEC_uchar_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_uchar_heap_safe_grow (vec_, size_ ); memset (&(VEC_uchar_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (uchar) * (size_ - oldsize)); } static __inline__ void VEC_uchar_heap_safe_splice (VEC_uchar_heap **dst_, VEC_uchar_base *src_ ) { if (src_) { VEC_uchar_heap_reserve_exact (dst_, src_->prefix.num ); VEC_uchar_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ uchar *VEC_uchar_heap_safe_push (VEC_uchar_heap **vec_, const uchar obj_ ) { VEC_uchar_heap_reserve (vec_, 1 ); return VEC_uchar_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ uchar *VEC_uchar_heap_safe_insert (VEC_uchar_heap **vec_, unsigned ix_, const uchar obj_ ) { VEC_uchar_heap_reserve (vec_, 1 ); return VEC_uchar_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
typedef struct VEC_uchar_gc { VEC_uchar_base base; } VEC_uchar_gc; static __inline__ VEC_uchar_gc *VEC_uchar_gc_alloc (int alloc_ ) { return (VEC_uchar_gc *) vec_gc_o_reserve_exact (((void *)0), alloc_, __builtin_offsetof (VEC_uchar_gc, base.vec), sizeof (uchar) ); } static __inline__ VEC_uchar_gc *VEC_uchar_gc_copy (VEC_uchar_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_uchar_gc *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_uchar_gc *)(vec_gc_o_reserve_exact (((void *)0), len_, __builtin_offsetof (VEC_uchar_gc, base.vec), sizeof (uchar) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (uchar) * len_); } return new_vec_; } static __inline__ void VEC_uchar_gc_free (VEC_uchar_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = ((void *)0); } static __inline__ int VEC_uchar_gc_reserve (VEC_uchar_gc **vec_, int alloc_ ) { int extend = !VEC_uchar_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_uchar_gc *) vec_gc_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_uchar_gc, base.vec), sizeof (uchar) ); return extend; } static __inline__ int VEC_uchar_gc_reserve_exact (VEC_uchar_gc **vec_, int alloc_ ) { int extend = !VEC_uchar_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_uchar_gc *) vec_gc_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_uchar_gc, base.vec), sizeof (uchar) ); return extend; } static __inline__ void VEC_uchar_gc_safe_grow (VEC_uchar_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_uchar_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_uchar_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_uchar_gc_safe_grow_cleared (VEC_uchar_gc **vec_, int size_ ) { int oldsize = VEC_uchar_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_uchar_gc_safe_grow (vec_, size_ ); memset (&(VEC_uchar_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (uchar) * (size_ - oldsize)); } static __inline__ void VEC_uchar_gc_safe_splice (VEC_uchar_gc **dst_, VEC_uchar_base *src_ ) { if (src_) { VEC_uchar_gc_reserve_exact (dst_, src_->prefix.num ); VEC_uchar_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ uchar *VEC_uchar_gc_safe_push (VEC_uchar_gc **vec_, const uchar obj_ ) { VEC_uchar_gc_reserve (vec_, 1 ); return VEC_uchar_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ uchar *VEC_uchar_gc_safe_insert (VEC_uchar_gc **vec_, unsigned ix_, const uchar obj_ ) { VEC_uchar_gc_reserve (vec_, 1 ); return VEC_uchar_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
static __inline__ void VEC_int_must_be_integral_type (void) { (void)~(int)0; } typedef struct VEC_int_base { struct vec_prefix prefix; int vec[1]; } VEC_int_base; typedef struct VEC_int_none { VEC_int_base base; } VEC_int_none; static __inline__ unsigned VEC_int_base_length (const VEC_int_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static __inline__ int VEC_int_base_last (const VEC_int_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static __inline__ int VEC_int_base_index (const VEC_int_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static __inline__ int VEC_int_base_iterate (const VEC_int_base *vec_, unsigned ix_, int *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (int) 0; return 0; } } static __inline__ size_t VEC_int_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_int_base, vec) + alloc_ * sizeof(int); } static __inline__ void VEC_int_base_embedded_init (VEC_int_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static __inline__ int VEC_int_base_space (VEC_int_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static __inline__ void VEC_int_base_splice (VEC_int_base *dst_, VEC_int_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (int)); dst_->prefix.num += len_; } } static __inline__ int *VEC_int_base_quick_push (VEC_int_base *vec_, int obj_ ) { int *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static __inline__ int VEC_int_base_pop (VEC_int_base *vec_ ) { int obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_int_base_truncate (VEC_int_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static __inline__ int VEC_int_base_replace (VEC_int_base *vec_, unsigned ix_, int obj_ ) { int old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ int *VEC_int_base_quick_insert (VEC_int_base *vec_, unsigned ix_, int obj_ ) { int *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (int)); *slot_ = obj_; return slot_; } static __inline__ int VEC_int_base_ordered_remove (VEC_int_base *vec_, unsigned ix_ ) { int *slot_; int obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (int)); return obj_; } static __inline__ int VEC_int_base_unordered_remove (VEC_int_base *vec_, unsigned ix_ ) { int *slot_; int obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_int_base_block_remove (VEC_int_base *vec_, unsigned ix_, unsigned len_ ) { int *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (int)); } static __inline__ int *VEC_int_base_address (VEC_int_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_int_base_lower_bound (VEC_int_base *vec_, const int obj_, unsigned char (*lessthan_)(const int, const int) ) { unsigned int len_ = VEC_int_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { int middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_int_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_int_heap { VEC_int_base base; } VEC_int_heap; static __inline__ VEC_int_heap *VEC_int_heap_alloc (int alloc_ ) { return (VEC_int_heap *) vec_heap_o_reserve_exact (((void *)0), alloc_, __builtin_offsetof (VEC_int_heap, base.vec), sizeof (int) ); } static __inline__ VEC_int_heap *VEC_int_heap_copy (VEC_int_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_int_heap *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_int_heap *)(vec_heap_o_reserve_exact (((void *)0), len_, __builtin_offsetof (VEC_int_heap, base.vec), sizeof (int) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (int) * len_); } return new_vec_; } static __inline__ void VEC_int_heap_free (VEC_int_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = ((void *)0); } static __inline__ int VEC_int_heap_reserve (VEC_int_heap **vec_, int alloc_ ) { int extend = !VEC_int_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_int_heap *) vec_heap_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_int_heap, base.vec), sizeof (int) ); return extend; } static __inline__ int VEC_int_heap_reserve_exact (VEC_int_heap **vec_, int alloc_ ) { int extend = !VEC_int_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_int_heap *) vec_heap_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_int_heap, base.vec), sizeof (int) ); return extend; } static __inline__ void VEC_int_heap_safe_grow (VEC_int_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_int_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_int_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_int_heap_safe_grow_cleared (VEC_int_heap **vec_, int size_ ) { int oldsize = VEC_int_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_int_heap_safe_grow (vec_, size_ ); memset (&(VEC_int_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (int) * (size_ - oldsize)); } static __inline__ void VEC_int_heap_safe_splice (VEC_int_heap **dst_, VEC_int_base *src_ ) { if (src_) { VEC_int_heap_reserve_exact (dst_, src_->prefix.num ); VEC_int_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ int *VEC_int_heap_safe_push (VEC_int_heap **vec_, const int obj_ ) { VEC_int_heap_reserve (vec_, 1 ); return VEC_int_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ int *VEC_int_heap_safe_insert (VEC_int_heap **vec_, unsigned ix_, const int obj_ ) { VEC_int_heap_reserve (vec_, 1 ); return VEC_int_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
static __inline__ void VEC_unsigned_must_be_integral_type (void) { (void)~(unsigned)0; } typedef struct VEC_unsigned_base { struct vec_prefix prefix; unsigned vec[1]; } VEC_unsigned_base; typedef struct VEC_unsigned_none { VEC_unsigned_base base; } VEC_unsigned_none; static __inline__ unsigned VEC_unsigned_base_length (const VEC_unsigned_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static __inline__ unsigned VEC_unsigned_base_last (const VEC_unsigned_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static __inline__ unsigned VEC_unsigned_base_index (const VEC_unsigned_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static __inline__ int VEC_unsigned_base_iterate (const VEC_unsigned_base *vec_, unsigned ix_, unsigned *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (unsigned) 0; return 0; } } static __inline__ size_t VEC_unsigned_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_unsigned_base, vec) + alloc_ * sizeof(unsigned); } static __inline__ void VEC_unsigned_base_embedded_init (VEC_unsigned_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static __inline__ int VEC_unsigned_base_space (VEC_unsigned_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static __inline__ void VEC_unsigned_base_splice (VEC_unsigned_base *dst_, VEC_unsigned_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (unsigned)); dst_->prefix.num += len_; } } static __inline__ unsigned *VEC_unsigned_base_quick_push (VEC_unsigned_base *vec_, unsigned obj_ ) { unsigned *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static __inline__ unsigned VEC_unsigned_base_pop (VEC_unsigned_base *vec_ ) { unsigned obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_unsigned_base_truncate (VEC_unsigned_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static __inline__ unsigned VEC_unsigned_base_replace (VEC_unsigned_base *vec_, unsigned ix_, unsigned obj_ ) { unsigned old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ unsigned *VEC_unsigned_base_quick_insert (VEC_unsigned_base *vec_, unsigned ix_, unsigned obj_ ) { unsigned *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (unsigned)); *slot_ = obj_; return slot_; } static __inline__ unsigned VEC_unsigned_base_ordered_remove (VEC_unsigned_base *vec_, unsigned ix_ ) { unsigned *slot_; unsigned obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (unsigned)); return obj_; } static __inline__ unsigned VEC_unsigned_base_unordered_remove (VEC_unsigned_base *vec_, unsigned ix_ ) { unsigned *slot_; unsigned obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_unsigned_base_block_remove (VEC_unsigned_base *vec_, unsigned ix_, unsigned len_ ) { unsigned *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (unsigned)); } static __inline__ unsigned *VEC_unsigned_base_address (VEC_unsigned_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_unsigned_base_lower_bound (VEC_unsigned_base *vec_, const unsigned obj_, unsigned char (*lessthan_)(const unsigned, const unsigned) ) { unsigned int len_ = VEC_unsigned_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { unsigned middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_unsigned_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_unsigned_heap { VEC_unsigned_base base; } VEC_unsigned_heap; static __inline__ VEC_unsigned_heap *VEC_unsigned_heap_alloc (int alloc_ ) { return (VEC_unsigned_heap *) vec_heap_o_reserve_exact (((void *)0), alloc_, __builtin_offsetof (VEC_unsigned_heap, base.vec), sizeof (unsigned) ); } static __inline__ VEC_unsigned_heap *VEC_unsigned_heap_copy (VEC_unsigned_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_unsigned_heap *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_unsigned_heap *)(vec_heap_o_reserve_exact (((void *)0), len_, __builtin_offsetof (VEC_unsigned_heap, base.vec), sizeof (unsigned) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (unsigned) * len_); } return new_vec_; } static __inline__ void VEC_unsigned_heap_free (VEC_unsigned_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = ((void *)0); } static __inline__ int VEC_unsigned_heap_reserve (VEC_unsigned_heap **vec_, int alloc_ ) { int extend = !VEC_unsigned_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_unsigned_heap *) vec_heap_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_unsigned_heap, base.vec), sizeof (unsigned) ); return extend; } static __inline__ int VEC_unsigned_heap_reserve_exact (VEC_unsigned_heap **vec_, int alloc_ ) { int extend = !VEC_unsigned_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_unsigned_heap *) vec_heap_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_unsigned_heap, base.vec), sizeof (unsigned) ); return extend; } static __inline__ void VEC_unsigned_heap_safe_grow (VEC_unsigned_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_unsigned_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_unsigned_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_unsigned_heap_safe_grow_cleared (VEC_unsigned_heap **vec_, int size_ ) { int oldsize = VEC_unsigned_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_unsigned_heap_safe_grow (vec_, size_ ); memset (&(VEC_unsigned_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (unsigned) * (size_ - oldsize)); } static __inline__ void VEC_unsigned_heap_safe_splice (VEC_unsigned_heap **dst_, VEC_unsigned_base *src_ ) { if (src_) { VEC_unsigned_heap_reserve_exact (dst_, src_->prefix.num ); VEC_unsigned_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ unsigned *VEC_unsigned_heap_safe_push (VEC_unsigned_heap **vec_, const unsigned obj_ ) { VEC_unsigned_heap_reserve (vec_, 1 ); return VEC_unsigned_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ unsigned *VEC_unsigned_heap_safe_insert (VEC_unsigned_heap **vec_, unsigned ix_, const unsigned obj_ ) { VEC_unsigned_heap_reserve (vec_, 1 ); return VEC_unsigned_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
# 28 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/function.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/tm.h" 1
# 29 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/function.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/hard-reg-set.h" 1
# 42 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/hard-reg-set.h"
typedef unsigned long HARD_REG_ELT_TYPE;
# 53 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/hard-reg-set.h"
typedef HARD_REG_ELT_TYPE HARD_REG_SET[((128 + (8 * 4) - 1) / (8 * 4))];
struct hard_reg_set_container
{
  HARD_REG_SET set;
};
# 361 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/hard-reg-set.h"
static __inline__ unsigned char
hard_reg_set_subset_p (const HARD_REG_SET x, const HARD_REG_SET y)
{
  return ((x[0] & ~y[0]) == 0
   && (x[1] & ~y[1]) == 0
   && (x[2] & ~y[2]) == 0
   && (x[3] & ~y[3]) == 0);
}
static __inline__ unsigned char
hard_reg_set_equal_p (const HARD_REG_SET x, const HARD_REG_SET y)
{
  return x[0] == y[0] && x[1] == y[1] && x[2] == y[2] && x[3] == y[3];
}
static __inline__ unsigned char
hard_reg_set_intersect_p (const HARD_REG_SET x, const HARD_REG_SET y)
{
  return ((x[0] & y[0]) != 0
   || (x[1] & y[1]) != 0
   || (x[2] & y[2]) != 0
   || (x[3] & y[3]) != 0);
}
static __inline__ unsigned char
hard_reg_set_empty_p (const HARD_REG_SET x)
{
  return x[0] == 0 && x[1] == 0 && x[2] == 0 && x[3] == 0;
}
# 492 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/hard-reg-set.h"
typedef struct
{
  HARD_REG_ELT_TYPE *pelt;
  unsigned short length;
  unsigned short word_no;
  HARD_REG_ELT_TYPE bits;
} hard_reg_set_iterator;
static __inline__ void
hard_reg_set_iter_init (hard_reg_set_iterator *iter, HARD_REG_SET set,
                        unsigned min, unsigned *regno)
{
  iter->pelt = set;
  iter->length = ((128 + (8 * 4) - 1) / (8 * 4));
  iter->word_no = min / ((unsigned) (8 * 4));
  if (iter->word_no < iter->length)
    {
      iter->bits = iter->pelt[iter->word_no];
      iter->bits >>= min % ((unsigned) (8 * 4));
      min += !iter->bits;
    }
  *regno = min;
}
static __inline__ unsigned char
hard_reg_set_iter_set (hard_reg_set_iterator *iter, unsigned *regno)
{
  while (1)
    {
      if (iter->word_no >= iter->length)
        return 0;
      if (iter->bits)
        {
          while (!(iter->bits & 1))
            {
              iter->bits >>= 1;
              *regno += 1;
            }
          return (*regno < 128);
        }
      *regno = (*regno + ((unsigned) (8 * 4)) - 1);
      *regno -= *regno % ((unsigned) (8 * 4));
      while (++iter->word_no < iter->length)
        {
          iter->bits = iter->pelt[iter->word_no];
          if (iter->bits)
            break;
          *regno += ((unsigned) (8 * 4));
        }
    }
}
static __inline__ void
hard_reg_set_iter_next (hard_reg_set_iterator *iter, unsigned *regno)
{
  iter->bits >>= 1;
  *regno += 1;
}
# 591 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/hard-reg-set.h"
extern char global_regs[128];
struct target_hard_regs {
  HARD_REG_SET x_accessible_reg_set;
  HARD_REG_SET x_operand_reg_set;
  char x_fixed_regs[128];
  HARD_REG_SET x_fixed_reg_set;
  char x_call_used_regs[128];
  char x_call_really_used_regs[128];
  HARD_REG_SET x_call_used_reg_set;
  HARD_REG_SET x_call_fixed_reg_set;
  HARD_REG_SET x_regs_invalidated_by_call;
  HARD_REG_SET x_no_caller_save_reg_set;
  int x_reg_alloc_order[128];
  int x_inv_reg_alloc_order[128];
  HARD_REG_SET x_reg_class_contents[(int) LIM_REG_CLASSES];
  unsigned char x_class_only_fixed_regs[(int) LIM_REG_CLASSES];
  unsigned int x_reg_class_size[(int) LIM_REG_CLASSES];
  enum reg_class x_reg_class_subclasses[(int) LIM_REG_CLASSES][(int) LIM_REG_CLASSES];
  enum reg_class x_reg_class_subunion[(int) LIM_REG_CLASSES][(int) LIM_REG_CLASSES];
  enum reg_class x_reg_class_superunion[(int) LIM_REG_CLASSES][(int) LIM_REG_CLASSES];
  const char *x_reg_names[128];
};
extern struct target_hard_regs default_target_hard_regs;
# 718 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/hard-reg-set.h"
extern const char * reg_class_names[];
# 30 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/function.h" 2
struct sequence_stack {
  rtx first;
  rtx last;
  struct sequence_stack *next;
};
struct emit_status {
  int x_reg_rtx_no;
  int x_first_label_num;
  rtx x_first_insn;
  rtx x_last_insn;
  struct sequence_stack *sequence_stack;
  int x_cur_insn_uid;
  int x_cur_debug_insn_uid;
  location_t x_last_location;
  int regno_pointer_align_length;
  unsigned char * regno_pointer_align;
};
# 98 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/function.h"
extern rtx * regno_reg_rtx;
struct expr_status {
  int x_pending_stack_adjust;
# 126 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/function.h"
  int x_inhibit_defer_pop;
  int x_stack_pointer_delta;
  rtx x_saveregs_value;
  rtx x_apply_args_value;
  rtx x_forced_labels;
};
typedef struct call_site_record_d *call_site_record;
static __inline__ void VEC_call_site_record_must_be_pointer_type (void) { (void)((call_site_record)1 == (void *)1); } typedef struct VEC_call_site_record_base { struct vec_prefix prefix; call_site_record vec[1]; } VEC_call_site_record_base; typedef struct VEC_call_site_record_none { VEC_call_site_record_base base; } VEC_call_site_record_none; static __inline__ unsigned VEC_call_site_record_base_length (const VEC_call_site_record_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static __inline__ call_site_record VEC_call_site_record_base_last (const VEC_call_site_record_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static __inline__ call_site_record VEC_call_site_record_base_index (const VEC_call_site_record_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static __inline__ int VEC_call_site_record_base_iterate (const VEC_call_site_record_base *vec_, unsigned ix_, call_site_record *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (call_site_record) 0; return 0; } } static __inline__ size_t VEC_call_site_record_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_call_site_record_base, vec) + alloc_ * sizeof(call_site_record); } static __inline__ void VEC_call_site_record_base_embedded_init (VEC_call_site_record_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static __inline__ int VEC_call_site_record_base_space (VEC_call_site_record_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static __inline__ void VEC_call_site_record_base_splice (VEC_call_site_record_base *dst_, VEC_call_site_record_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (call_site_record)); dst_->prefix.num += len_; } } static __inline__ call_site_record *VEC_call_site_record_base_quick_push (VEC_call_site_record_base *vec_, call_site_record obj_ ) { call_site_record *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static __inline__ call_site_record VEC_call_site_record_base_pop (VEC_call_site_record_base *vec_ ) { call_site_record obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_call_site_record_base_truncate (VEC_call_site_record_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static __inline__ call_site_record VEC_call_site_record_base_replace (VEC_call_site_record_base *vec_, unsigned ix_, call_site_record obj_ ) { call_site_record old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ call_site_record *VEC_call_site_record_base_quick_insert (VEC_call_site_record_base *vec_, unsigned ix_, call_site_record obj_ ) { call_site_record *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (call_site_record)); *slot_ = obj_; return slot_; } static __inline__ call_site_record VEC_call_site_record_base_ordered_remove (VEC_call_site_record_base *vec_, unsigned ix_ ) { call_site_record *slot_; call_site_record obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (call_site_record)); return obj_; } static __inline__ call_site_record VEC_call_site_record_base_unordered_remove (VEC_call_site_record_base *vec_, unsigned ix_ ) { call_site_record *slot_; call_site_record obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_call_site_record_base_block_remove (VEC_call_site_record_base *vec_, unsigned ix_, unsigned len_ ) { call_site_record *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (call_site_record)); } static __inline__ call_site_record *VEC_call_site_record_base_address (VEC_call_site_record_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_call_site_record_base_lower_bound (VEC_call_site_record_base *vec_, const call_site_record obj_, unsigned char (*lessthan_)(const call_site_record, const call_site_record) ) { unsigned int len_ = VEC_call_site_record_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { call_site_record middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_call_site_record_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_call_site_record_gc { VEC_call_site_record_base base; } VEC_call_site_record_gc; static __inline__ VEC_call_site_record_gc *VEC_call_site_record_gc_alloc (int alloc_ ) { return (VEC_call_site_record_gc *) vec_gc_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_call_site_record_gc_free (VEC_call_site_record_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_call_site_record_gc *VEC_call_site_record_gc_copy (VEC_call_site_record_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_call_site_record_gc *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_call_site_record_gc *)(vec_gc_p_reserve_exact (((void *)0), len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (call_site_record) * len_); } return new_vec_; } static __inline__ int VEC_call_site_record_gc_reserve (VEC_call_site_record_gc **vec_, int alloc_ ) { int extend = !VEC_call_site_record_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_call_site_record_gc *) vec_gc_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_call_site_record_gc_reserve_exact (VEC_call_site_record_gc **vec_, int alloc_ ) { int extend = !VEC_call_site_record_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_call_site_record_gc *) vec_gc_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_call_site_record_gc_safe_grow (VEC_call_site_record_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_call_site_record_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_call_site_record_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_call_site_record_gc_safe_grow_cleared (VEC_call_site_record_gc **vec_, int size_ ) { int oldsize = VEC_call_site_record_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_call_site_record_gc_safe_grow (vec_, size_ ); memset (&(VEC_call_site_record_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (call_site_record) * (size_ - oldsize)); } static __inline__ void VEC_call_site_record_gc_safe_splice (VEC_call_site_record_gc **dst_, VEC_call_site_record_base *src_ ) { if (src_) { VEC_call_site_record_gc_reserve_exact (dst_, src_->prefix.num ); VEC_call_site_record_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ call_site_record *VEC_call_site_record_gc_safe_push (VEC_call_site_record_gc **vec_, call_site_record obj_ ) { VEC_call_site_record_gc_reserve (vec_, 1 ); return VEC_call_site_record_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ call_site_record *VEC_call_site_record_gc_safe_insert (VEC_call_site_record_gc **vec_, unsigned ix_, call_site_record obj_ ) { VEC_call_site_record_gc_reserve (vec_, 1 ); return VEC_call_site_record_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
struct rtl_eh {
  rtx ehr_stackadj;
  rtx ehr_handler;
  rtx ehr_label;
  rtx sjlj_fc;
  rtx sjlj_exit_after;
  VEC_uchar_gc *action_record_data;
  VEC_call_site_record_gc *call_site_record[2];
};
# 171 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/function.h"
struct gimple_df;
struct temp_slot;
typedef struct temp_slot *temp_slot_p;
struct call_site_record_d;
struct dw_fde_struct;
static __inline__ void VEC_temp_slot_p_must_be_pointer_type (void) { (void)((temp_slot_p)1 == (void *)1); } typedef struct VEC_temp_slot_p_base { struct vec_prefix prefix; temp_slot_p vec[1]; } VEC_temp_slot_p_base; typedef struct VEC_temp_slot_p_none { VEC_temp_slot_p_base base; } VEC_temp_slot_p_none; static __inline__ unsigned VEC_temp_slot_p_base_length (const VEC_temp_slot_p_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static __inline__ temp_slot_p VEC_temp_slot_p_base_last (const VEC_temp_slot_p_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static __inline__ temp_slot_p VEC_temp_slot_p_base_index (const VEC_temp_slot_p_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static __inline__ int VEC_temp_slot_p_base_iterate (const VEC_temp_slot_p_base *vec_, unsigned ix_, temp_slot_p *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (temp_slot_p) 0; return 0; } } static __inline__ size_t VEC_temp_slot_p_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_temp_slot_p_base, vec) + alloc_ * sizeof(temp_slot_p); } static __inline__ void VEC_temp_slot_p_base_embedded_init (VEC_temp_slot_p_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static __inline__ int VEC_temp_slot_p_base_space (VEC_temp_slot_p_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static __inline__ void VEC_temp_slot_p_base_splice (VEC_temp_slot_p_base *dst_, VEC_temp_slot_p_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (temp_slot_p)); dst_->prefix.num += len_; } } static __inline__ temp_slot_p *VEC_temp_slot_p_base_quick_push (VEC_temp_slot_p_base *vec_, temp_slot_p obj_ ) { temp_slot_p *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static __inline__ temp_slot_p VEC_temp_slot_p_base_pop (VEC_temp_slot_p_base *vec_ ) { temp_slot_p obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_temp_slot_p_base_truncate (VEC_temp_slot_p_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static __inline__ temp_slot_p VEC_temp_slot_p_base_replace (VEC_temp_slot_p_base *vec_, unsigned ix_, temp_slot_p obj_ ) { temp_slot_p old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ temp_slot_p *VEC_temp_slot_p_base_quick_insert (VEC_temp_slot_p_base *vec_, unsigned ix_, temp_slot_p obj_ ) { temp_slot_p *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (temp_slot_p)); *slot_ = obj_; return slot_; } static __inline__ temp_slot_p VEC_temp_slot_p_base_ordered_remove (VEC_temp_slot_p_base *vec_, unsigned ix_ ) { temp_slot_p *slot_; temp_slot_p obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (temp_slot_p)); return obj_; } static __inline__ temp_slot_p VEC_temp_slot_p_base_unordered_remove (VEC_temp_slot_p_base *vec_, unsigned ix_ ) { temp_slot_p *slot_; temp_slot_p obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_temp_slot_p_base_block_remove (VEC_temp_slot_p_base *vec_, unsigned ix_, unsigned len_ ) { temp_slot_p *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (temp_slot_p)); } static __inline__ temp_slot_p *VEC_temp_slot_p_base_address (VEC_temp_slot_p_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_temp_slot_p_base_lower_bound (VEC_temp_slot_p_base *vec_, const temp_slot_p obj_, unsigned char (*lessthan_)(const temp_slot_p, const temp_slot_p) ) { unsigned int len_ = VEC_temp_slot_p_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { temp_slot_p middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_temp_slot_p_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_temp_slot_p_gc { VEC_temp_slot_p_base base; } VEC_temp_slot_p_gc; static __inline__ VEC_temp_slot_p_gc *VEC_temp_slot_p_gc_alloc (int alloc_ ) { return (VEC_temp_slot_p_gc *) vec_gc_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_temp_slot_p_gc_free (VEC_temp_slot_p_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_temp_slot_p_gc *VEC_temp_slot_p_gc_copy (VEC_temp_slot_p_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_temp_slot_p_gc *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_temp_slot_p_gc *)(vec_gc_p_reserve_exact (((void *)0), len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (temp_slot_p) * len_); } return new_vec_; } static __inline__ int VEC_temp_slot_p_gc_reserve (VEC_temp_slot_p_gc **vec_, int alloc_ ) { int extend = !VEC_temp_slot_p_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_temp_slot_p_gc *) vec_gc_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_temp_slot_p_gc_reserve_exact (VEC_temp_slot_p_gc **vec_, int alloc_ ) { int extend = !VEC_temp_slot_p_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_temp_slot_p_gc *) vec_gc_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_temp_slot_p_gc_safe_grow (VEC_temp_slot_p_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_temp_slot_p_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_temp_slot_p_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_temp_slot_p_gc_safe_grow_cleared (VEC_temp_slot_p_gc **vec_, int size_ ) { int oldsize = VEC_temp_slot_p_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_temp_slot_p_gc_safe_grow (vec_, size_ ); memset (&(VEC_temp_slot_p_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (temp_slot_p) * (size_ - oldsize)); } static __inline__ void VEC_temp_slot_p_gc_safe_splice (VEC_temp_slot_p_gc **dst_, VEC_temp_slot_p_base *src_ ) { if (src_) { VEC_temp_slot_p_gc_reserve_exact (dst_, src_->prefix.num ); VEC_temp_slot_p_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ temp_slot_p *VEC_temp_slot_p_gc_safe_push (VEC_temp_slot_p_gc **vec_, temp_slot_p obj_ ) { VEC_temp_slot_p_gc_reserve (vec_, 1 ); return VEC_temp_slot_p_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ temp_slot_p *VEC_temp_slot_p_gc_safe_insert (VEC_temp_slot_p_gc **vec_, unsigned ix_, temp_slot_p obj_ ) { VEC_temp_slot_p_gc_reserve (vec_, 1 ); return VEC_temp_slot_p_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
struct ipa_opt_pass_d;
typedef struct ipa_opt_pass_d *ipa_opt_pass;
static __inline__ void VEC_ipa_opt_pass_must_be_pointer_type (void) { (void)((ipa_opt_pass)1 == (void *)1); } typedef struct VEC_ipa_opt_pass_base { struct vec_prefix prefix; ipa_opt_pass vec[1]; } VEC_ipa_opt_pass_base; typedef struct VEC_ipa_opt_pass_none { VEC_ipa_opt_pass_base base; } VEC_ipa_opt_pass_none; static __inline__ unsigned VEC_ipa_opt_pass_base_length (const VEC_ipa_opt_pass_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static __inline__ ipa_opt_pass VEC_ipa_opt_pass_base_last (const VEC_ipa_opt_pass_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static __inline__ ipa_opt_pass VEC_ipa_opt_pass_base_index (const VEC_ipa_opt_pass_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static __inline__ int VEC_ipa_opt_pass_base_iterate (const VEC_ipa_opt_pass_base *vec_, unsigned ix_, ipa_opt_pass *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (ipa_opt_pass) 0; return 0; } } static __inline__ size_t VEC_ipa_opt_pass_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_ipa_opt_pass_base, vec) + alloc_ * sizeof(ipa_opt_pass); } static __inline__ void VEC_ipa_opt_pass_base_embedded_init (VEC_ipa_opt_pass_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static __inline__ int VEC_ipa_opt_pass_base_space (VEC_ipa_opt_pass_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static __inline__ void VEC_ipa_opt_pass_base_splice (VEC_ipa_opt_pass_base *dst_, VEC_ipa_opt_pass_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (ipa_opt_pass)); dst_->prefix.num += len_; } } static __inline__ ipa_opt_pass *VEC_ipa_opt_pass_base_quick_push (VEC_ipa_opt_pass_base *vec_, ipa_opt_pass obj_ ) { ipa_opt_pass *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static __inline__ ipa_opt_pass VEC_ipa_opt_pass_base_pop (VEC_ipa_opt_pass_base *vec_ ) { ipa_opt_pass obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_ipa_opt_pass_base_truncate (VEC_ipa_opt_pass_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static __inline__ ipa_opt_pass VEC_ipa_opt_pass_base_replace (VEC_ipa_opt_pass_base *vec_, unsigned ix_, ipa_opt_pass obj_ ) { ipa_opt_pass old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ ipa_opt_pass *VEC_ipa_opt_pass_base_quick_insert (VEC_ipa_opt_pass_base *vec_, unsigned ix_, ipa_opt_pass obj_ ) { ipa_opt_pass *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (ipa_opt_pass)); *slot_ = obj_; return slot_; } static __inline__ ipa_opt_pass VEC_ipa_opt_pass_base_ordered_remove (VEC_ipa_opt_pass_base *vec_, unsigned ix_ ) { ipa_opt_pass *slot_; ipa_opt_pass obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (ipa_opt_pass)); return obj_; } static __inline__ ipa_opt_pass VEC_ipa_opt_pass_base_unordered_remove (VEC_ipa_opt_pass_base *vec_, unsigned ix_ ) { ipa_opt_pass *slot_; ipa_opt_pass obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static __inline__ void VEC_ipa_opt_pass_base_block_remove (VEC_ipa_opt_pass_base *vec_, unsigned ix_, unsigned len_ ) { ipa_opt_pass *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (ipa_opt_pass)); } static __inline__ ipa_opt_pass *VEC_ipa_opt_pass_base_address (VEC_ipa_opt_pass_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_ipa_opt_pass_base_lower_bound (VEC_ipa_opt_pass_base *vec_, const ipa_opt_pass obj_, unsigned char (*lessthan_)(const ipa_opt_pass, const ipa_opt_pass) ) { unsigned int len_ = VEC_ipa_opt_pass_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { ipa_opt_pass middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_ipa_opt_pass_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_ipa_opt_pass_heap { VEC_ipa_opt_pass_base base; } VEC_ipa_opt_pass_heap; static __inline__ VEC_ipa_opt_pass_heap *VEC_ipa_opt_pass_heap_alloc (int alloc_ ) { return (VEC_ipa_opt_pass_heap *) vec_heap_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_ipa_opt_pass_heap_free (VEC_ipa_opt_pass_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_ipa_opt_pass_heap *VEC_ipa_opt_pass_heap_copy (VEC_ipa_opt_pass_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_ipa_opt_pass_heap *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_ipa_opt_pass_heap *)(vec_heap_p_reserve_exact (((void *)0), len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (ipa_opt_pass) * len_); } return new_vec_; } static __inline__ int VEC_ipa_opt_pass_heap_reserve (VEC_ipa_opt_pass_heap **vec_, int alloc_ ) { int extend = !VEC_ipa_opt_pass_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_ipa_opt_pass_heap *) vec_heap_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_ipa_opt_pass_heap_reserve_exact (VEC_ipa_opt_pass_heap **vec_, int alloc_ ) { int extend = !VEC_ipa_opt_pass_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_ipa_opt_pass_heap *) vec_heap_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_ipa_opt_pass_heap_safe_grow (VEC_ipa_opt_pass_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_ipa_opt_pass_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_ipa_opt_pass_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static __inline__ void VEC_ipa_opt_pass_heap_safe_grow_cleared (VEC_ipa_opt_pass_heap **vec_, int size_ ) { int oldsize = VEC_ipa_opt_pass_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_ipa_opt_pass_heap_safe_grow (vec_, size_ ); memset (&(VEC_ipa_opt_pass_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (ipa_opt_pass) * (size_ - oldsize)); } static __inline__ void VEC_ipa_opt_pass_heap_safe_splice (VEC_ipa_opt_pass_heap **dst_, VEC_ipa_opt_pass_base *src_ ) { if (src_) { VEC_ipa_opt_pass_heap_reserve_exact (dst_, src_->prefix.num ); VEC_ipa_opt_pass_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static __inline__ ipa_opt_pass *VEC_ipa_opt_pass_heap_safe_push (VEC_ipa_opt_pass_heap **vec_, ipa_opt_pass obj_ ) { VEC_ipa_opt_pass_heap_reserve (vec_, 1 ); return VEC_ipa_opt_pass_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static __inline__ ipa_opt_pass *VEC_ipa_opt_pass_heap_safe_insert (VEC_ipa_opt_pass_heap **vec_, unsigned ix_, ipa_opt_pass obj_ ) { VEC_ipa_opt_pass_heap_reserve (vec_, 1 ); return VEC_ipa_opt_pass_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
struct varasm_status {
  struct rtx_constant_pool *pool;
  unsigned int deferred_constants;
};
struct incoming_args {
  int pops_args;
  int size;
  int pretend_args_size;
  rtx arg_offset_rtx;
  CUMULATIVE_ARGS info;
  rtx internal_arg_pointer;
};
struct function_subsections {
  const char *hot_section_label;
  const char *cold_section_label;
  const char *hot_section_end_label;
  const char *cold_section_end_label;
};
struct frame_space
{
  struct frame_space *next;
  long long start;
  long long length;
};
struct rtl_data {
  struct expr_status expr;
  struct emit_status emit;
  struct varasm_status varasm;
  struct incoming_args args;
  struct function_subsections subsections;
  struct rtl_eh eh;
  int outgoing_args_size;
  rtx return_rtx;
  struct initial_value_struct *hard_reg_initial_vals;
  tree stack_protect_guard;
  rtx x_nonlocal_goto_handler_labels;
  rtx x_return_label;
  rtx x_naked_return_label;
  rtx x_stack_slot_list;
  struct frame_space *frame_space_list;
  rtx x_stack_check_probe_note;
  rtx x_arg_pointer_save_area;
  rtx drap_reg;
  long long x_frame_offset;
  rtx x_parm_birth_insn;
  VEC_temp_slot_p_gc *x_used_temp_slots;
  struct temp_slot *x_avail_temp_slots;
  int x_temp_slot_level;
  unsigned int stack_alignment_needed;
  unsigned int preferred_stack_boundary;
  unsigned int parm_stack_boundary;
  unsigned int max_used_stack_slot_alignment;
# 346 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/function.h"
  unsigned int stack_alignment_estimated;
  rtx epilogue_delay_list;
  unsigned char accesses_prior_frames;
  unsigned char calls_eh_return;
  unsigned char saves_all_registers;
  unsigned char has_nonlocal_goto;
  unsigned char has_asm_statement;
  unsigned char all_throwers_are_sibcalls;
  unsigned char limit_stack;
  unsigned char profile;
  unsigned char uses_const_pool;
  unsigned char uses_pic_offset_table;
  unsigned char uses_eh_lsda;
  unsigned char tail_call_emit;
  unsigned char arg_pointer_save_area_init;
  unsigned char frame_pointer_needed;
  unsigned char maybe_hot_insn_p;
  unsigned char stack_realign_needed;
  unsigned char stack_realign_tried;
  unsigned char need_drap;
  unsigned char stack_realign_processed;
  unsigned char stack_realign_finalized;
  unsigned char dbr_scheduled_p;
  unsigned char nothrow;
  unsigned char shrink_wrapped;
  HARD_REG_SET asm_clobbers;
};
# 466 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/function.h"
extern struct rtl_data x_rtl;
struct stack_usage
{
  long long static_stack_size;
  long long dynamic_stack_size;
  int pushed_stack_size;
  unsigned int has_unbounded_dynamic_stack_size : 1;
};
# 503 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/function.h"
struct function {
  struct eh_status *eh;
  struct control_flow_graph *cfg;
  struct gimple_seq_d *gimple_body;
  struct gimple_df *gimple_df;
  struct loops *x_current_loops;
  struct stack_usage *su;
  htab_t value_histograms;
  tree decl;
  tree static_chain_decl;
  tree nonlocal_goto_save_area;
  VEC_tree_gc *local_decls;
  struct machine_function * machine;
  struct language_function * language;
  htab_t used_types_hash;
  struct dw_fde_struct *fde;
  int last_stmt_uid;
  int funcdef_no;
  location_t function_start_locus;
  location_t function_end_locus;
  unsigned int curr_properties;
  unsigned int last_verified;
  const char * cannot_be_copied_reason;
  unsigned int va_list_gpr_size : 8;
  unsigned int va_list_fpr_size : 8;
  unsigned int calls_setjmp : 1;
  unsigned int calls_alloca : 1;
  unsigned int has_nonlocal_label : 1;
  unsigned int cannot_be_copied_set : 1;
  unsigned int stdarg : 1;
  unsigned int after_inlining : 1;
  unsigned int always_inline_functions_inlined : 1;
  unsigned int can_throw_non_call_exceptions : 1;
  unsigned int returns_struct : 1;
  unsigned int returns_pcc_struct : 1;
  unsigned int after_tree_profile : 1;
  unsigned int has_local_explicit_reg_vars : 1;
  unsigned int is_thunk : 1;
};
static __inline__ void
add_local_decl (struct function *fun, tree d)
{
  (VEC_tree_gc_safe_push(&(fun->local_decls),d ));
}
# 657 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/function.h"
extern struct function *cfun;
extern int virtuals_instantiated;
extern int trampolines_created;
struct types_used_by_vars_entry {
  tree type;
  tree var_decl;
};
extern htab_t
  types_used_by_vars_hash;
hashval_t types_used_by_vars_do_hash (const void*);
int types_used_by_vars_eq (const void *, const void *);
void types_used_by_var_decl_insert (tree type, tree var_decl);
extern VEC_tree_gc *types_used_by_cur_var_decl;
extern void set_cfun (struct function *new_cfun);
extern void push_cfun (struct function *new_cfun);
extern void pop_cfun (void);
extern void instantiate_decl_rtl (rtx x);
# 708 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/function.h"
extern void reorder_blocks (void);
extern void number_blocks (tree);
extern void clear_block_marks (tree);
extern tree blocks_nreverse (tree);
extern tree block_chainon (tree, tree);
extern long long get_frame_size (void);
extern unsigned char frame_offset_overflow (long long, tree);
extern struct machine_function * (*init_machine_status) (void);
extern void free_after_parsing (struct function *);
extern void free_after_compilation (struct function *);
extern void init_varasm_status (void);
extern rtx get_arg_pointer_save_area (void);
extern const char *current_function_name (void);
extern void do_warn_unused_parameter (tree);
extern unsigned char pass_by_reference (CUMULATIVE_ARGS *, enum machine_mode,
          tree, unsigned char);
extern unsigned char reference_callee_copied (CUMULATIVE_ARGS *, enum machine_mode,
         tree, unsigned char);
extern void used_types_insert (tree);
extern int get_next_funcdef_no (void);
extern int get_last_funcdef_no (void);
extern unsigned char optimize_function_for_size_p (struct function *);
extern unsigned char optimize_function_for_speed_p (struct function *);
# 42 "../../../src/plugin-utils.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h" 1
# 47 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
enum rtx_code {
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def" 1
# 82 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
UNKNOWN ,
VALUE ,
DEBUG_EXPR ,
EXPR_LIST ,
INSN_LIST ,
SEQUENCE ,
ADDRESS ,
# 126 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
DEBUG_INSN ,
INSN ,
JUMP_INSN ,
CALL_INSN ,
BARRIER ,
CODE_LABEL ,
NOTE ,
# 171 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
COND_EXEC ,
PARALLEL ,
ASM_INPUT ,
# 196 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
ASM_OPERANDS ,
# 214 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
UNSPEC ,
UNSPEC_VOLATILE ,
ADDR_VEC ,
# 246 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
ADDR_DIFF_VEC ,
# 257 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
PREFETCH ,
# 269 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
SET ,
# 278 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
USE ,
# 287 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
CLOBBER ,
CALL ,
RETURN ,
SIMPLE_RETURN ,
EH_RETURN ,
TRAP_IF ,
CONST_INT ,
CONST_FIXED ,
CONST_DOUBLE ,
CONST_VECTOR ,
CONST_STRING ,
CONST ,
PC ,
# 356 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
REG ,
SCRATCH ,
SUBREG ,
# 380 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
STRICT_LOW_PART ,
CONCAT ,
CONCATN ,
MEM ,
LABEL_REF ,
SYMBOL_REF ,
CC0 ,
# 427 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
IF_THEN_ELSE ,
COMPARE ,
PLUS ,
MINUS ,
NEG ,
MULT ,
SS_MULT ,
US_MULT ,
DIV ,
SS_DIV ,
US_DIV ,
MOD ,
UDIV ,
UMOD ,
AND ,
IOR ,
XOR ,
NOT ,
ASHIFT ,
ROTATE ,
ASHIFTRT ,
LSHIFTRT ,
ROTATERT ,
# 484 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
SMIN ,
SMAX ,
UMIN ,
UMAX ,
# 496 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
PRE_DEC ,
PRE_INC ,
POST_DEC ,
POST_INC ,
# 513 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
PRE_MODIFY ,
POST_MODIFY ,
NE ,
EQ ,
GE ,
GT ,
LE ,
LT ,
GEU ,
GTU ,
LEU ,
LTU ,
UNORDERED ,
ORDERED ,
UNEQ ,
UNGE ,
UNGT ,
UNLE ,
UNLT ,
LTGT ,
SIGN_EXTEND ,
ZERO_EXTEND ,
TRUNCATE ,
FLOAT_EXTEND ,
FLOAT_TRUNCATE ,
FLOAT ,
FIX ,
UNSIGNED_FLOAT ,
UNSIGNED_FIX ,
# 585 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
FRACT_CONVERT ,
UNSIGNED_FRACT_CONVERT ,
SAT_FRACT ,
UNSIGNED_SAT_FRACT ,
ABS ,
SQRT ,
BSWAP ,
FFS ,
CLRSB ,
CLZ ,
CTZ ,
POPCOUNT ,
PARITY ,
# 648 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.def"
SIGN_EXTRACT ,
ZERO_EXTRACT ,
HIGH ,
LO_SUM ,
VEC_MERGE ,
VEC_SELECT ,
VEC_CONCAT ,
VEC_DUPLICATE ,
SS_PLUS ,
US_PLUS ,
SS_MINUS ,
SS_NEG ,
US_NEG ,
SS_ABS ,
SS_ASHIFT ,
US_ASHIFT ,
US_MINUS ,
SS_TRUNCATE ,
US_TRUNCATE ,
FMA ,
VAR_LOCATION ,
DEBUG_IMPLICIT_PTR ,
ENTRY_VALUE ,
DEBUG_PARAMETER_REF ,
# 51 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h" 2
  LAST_AND_UNUSED_RTX_CODE};
# 62 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
enum rtx_class {
  RTX_COMPARE,
  RTX_COMM_COMPARE,
  RTX_BIN_ARITH,
  RTX_COMM_ARITH,
  RTX_UNARY,
  RTX_EXTRA,
  RTX_MATCH,
  RTX_INSN,
  RTX_OBJ,
  RTX_CONST_OBJ,
  RTX_TERNARY,
  RTX_BITFIELD_OPS,
  RTX_AUTOINC
};
# 100 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
extern const unsigned char rtx_length[((int) LAST_AND_UNUSED_RTX_CODE)];
extern const char * const rtx_name[((int) LAST_AND_UNUSED_RTX_CODE)];
extern const char * const rtx_format[((int) LAST_AND_UNUSED_RTX_CODE)];
extern const enum rtx_class rtx_class[((int) LAST_AND_UNUSED_RTX_CODE)];
extern const unsigned char rtx_code_size[((int) LAST_AND_UNUSED_RTX_CODE)];
extern const unsigned char rtx_next[((int) LAST_AND_UNUSED_RTX_CODE)];
typedef struct
{
  unsigned min_align: 8;
  unsigned base_after_vec: 1;
  unsigned min_after_vec: 1;
  unsigned max_after_vec: 1;
  unsigned min_after_base: 1;
  unsigned max_after_base: 1;
  unsigned offset_unsigned: 1;
  unsigned : 2;
  unsigned scale : 8;
} addr_diff_vec_flags;
typedef struct mem_attrs
{
  tree expr;
  long long offset;
  long long size;
  alias_set_type alias;
  unsigned int align;
  unsigned char addrspace;
  unsigned char offset_known_p;
  unsigned char size_known_p;
} mem_attrs;
# 180 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
typedef struct reg_attrs {
  tree decl;
  long long offset;
} reg_attrs;
union rtunion_def
{
  int rt_int;
  unsigned int rt_uint;
  const char *rt_str;
  rtx rt_rtx;
  rtvec rt_rtvec;
  enum machine_mode rt_type;
  addr_diff_vec_flags rt_addr_diff_vec_flags;
  struct cselib_val_struct *rt_cselib;
  tree rt_tree;
  struct basic_block_def *rt_bb;
  mem_attrs *rt_mem;
  reg_attrs *rt_reg;
  struct constant_descriptor_rtx *rt_constant;
  struct dw_cfi_struct *rt_cfi;
};
typedef union rtunion_def rtunion;
struct block_symbol {
  rtunion fld[3];
  struct object_block *block;
  long long offset;
};
struct object_block {
  section *sect;
  unsigned int alignment;
  long long size;
# 241 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
  VEC_rtx_gc *objects;
# 251 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
  VEC_rtx_gc *anchors;
};
struct rtx_def {
  __extension__ enum rtx_code code: 16;
  __extension__ enum machine_mode mode : 8;
  unsigned int jump : 1;
  unsigned int call : 1;
# 285 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
  unsigned int unchanging : 1;
# 298 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
  unsigned int volatil : 1;
# 312 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
  unsigned int in_struct : 1;
# 321 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
  unsigned int used : 1;
  unsigned frame_related : 1;
  unsigned return_val : 1;
  union u {
    rtunion fld[1];
    long long hwint[1];
    struct block_symbol block_sym;
    struct real_value rv;
    struct fixed_value fv;
  } u;
};
# 384 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
struct rtvec_def {
  int num_elem;
  rtx elem[1];
};
# 874 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
enum reg_note
{
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/reg-notes.def" 1
# 33 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/reg-notes.def"
REG_DEP_TRUE,
REG_DEAD,
REG_INC,
# 52 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/reg-notes.def"
REG_EQUIV,
REG_EQUAL,
REG_NONNEG,
REG_UNUSED,
# 76 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/reg-notes.def"
REG_CC_SETTER,
REG_CC_USER,
REG_LABEL_TARGET,
REG_LABEL_OPERAND,
REG_DEP_OUTPUT,
REG_DEP_ANTI,
REG_DEP_CONTROL,
REG_BR_PROB,
REG_NOALIAS,
REG_BR_PRED,
REG_FRAME_RELATED_EXPR,
# 126 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/reg-notes.def"
REG_CFA_DEF_CFA,
REG_CFA_ADJUST_CFA,
REG_CFA_OFFSET,
REG_CFA_REGISTER,
REG_CFA_EXPRESSION,
REG_CFA_RESTORE,
REG_CFA_SET_VDRAP,
REG_CFA_WINDOW_SAVE,
REG_CFA_FLUSH_QUEUE,
REG_EH_CONTEXT,
REG_EH_REGION,
REG_SAVE_NOTE,
REG_NORETURN,
REG_NON_LOCAL_GOTO,
REG_CROSSING_JUMP,
REG_SETJMP,
REG_TM,
REG_ARGS_SIZE,
# 878 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h" 2
  REG_NOTE_MAX
};
# 889 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
extern const char * const reg_note_name[];
# 992 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
enum insn_note
{
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/insn-notes.def" 1
# 35 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/insn-notes.def"
NOTE_INSN_DELETED,
NOTE_INSN_DELETED_LABEL,
NOTE_INSN_DELETED_DEBUG_LABEL,
NOTE_INSN_BLOCK_BEG,
NOTE_INSN_BLOCK_END,
NOTE_INSN_FUNCTION_BEG,
NOTE_INSN_PROLOGUE_END,
NOTE_INSN_EPILOGUE_BEG,
NOTE_INSN_EH_REGION_BEG,
NOTE_INSN_EH_REGION_END,
NOTE_INSN_VAR_LOCATION,
NOTE_INSN_CALL_ARG_LOCATION,
NOTE_INSN_BASIC_BLOCK,
NOTE_INSN_SWITCH_TEXT_SECTIONS,
NOTE_INSN_CFI,
NOTE_INSN_CFI_LABEL,
# 996 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h" 2
  NOTE_INSN_MAX
};
extern const char * const note_insn_name[NOTE_INSN_MAX];
# 1018 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
enum label_kind
{
  LABEL_NORMAL = 0,
  LABEL_STATIC_ENTRY,
  LABEL_GLOBAL_ENTRY,
  LABEL_WEAK_ENTRY
};
# 1087 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
static __inline__ unsigned int
rhs_regno (const_rtx x)
{
  return (((x)->u.fld[0]).rt_uint);
}
# 1162 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
struct full_rtx_costs
{
  int speed;
  int size;
};
static __inline__ void
init_costs_to_max (struct full_rtx_costs *c)
{
  c->speed = 2147483647;
  c->size = 2147483647;
}
static __inline__ void
init_costs_to_zero (struct full_rtx_costs *c)
{
  c->speed = 0;
  c->size = 0;
}
static __inline__ unsigned char
costs_lt_p (struct full_rtx_costs *a, struct full_rtx_costs *b,
     unsigned char speed)
{
  if (speed)
    return (a->speed < b->speed
     || (a->speed == b->speed && a->size < b->size));
  else
    return (a->size < b->size
     || (a->size == b->size && a->speed < b->speed));
}
static __inline__ void
costs_add_n_insns (struct full_rtx_costs *c, int n)
{
  c->speed += ((n) * 4);
  c->size += ((n) * 4);
}
extern void init_rtlanal (void);
extern int rtx_cost (rtx, enum rtx_code, int, unsigned char);
extern int address_cost (rtx, enum machine_mode, addr_space_t, unsigned char);
extern void get_full_rtx_cost (rtx, enum rtx_code, int,
          struct full_rtx_costs *);
extern unsigned int subreg_lsb (const_rtx);
extern unsigned int subreg_lsb_1 (enum machine_mode, enum machine_mode,
      unsigned int);
extern unsigned int subreg_regno_offset (unsigned int, enum machine_mode,
      unsigned int, enum machine_mode);
extern unsigned char subreg_offset_representable_p (unsigned int, enum machine_mode,
        unsigned int, enum machine_mode);
extern unsigned int subreg_regno (const_rtx);
extern int simplify_subreg_regno (unsigned int, enum machine_mode,
      unsigned int, enum machine_mode);
extern unsigned int subreg_nregs (const_rtx);
extern unsigned int subreg_nregs_with_regno (unsigned int, const_rtx);
extern unsigned long long nonzero_bits (const_rtx, enum machine_mode);
extern unsigned int num_sign_bit_copies (const_rtx, enum machine_mode);
extern unsigned char constant_pool_constant_p (rtx);
extern unsigned char truncated_to_mode (enum machine_mode, const_rtx);
extern int low_bitmask_len (enum machine_mode, unsigned long long);
static __inline__ int
set_rtx_cost (rtx x, unsigned char speed_p)
{
  return rtx_cost (x, INSN, 4, speed_p);
}
static __inline__ void
get_full_set_rtx_cost (rtx x, struct full_rtx_costs *c)
{
  get_full_rtx_cost (x, INSN, 4, c);
}
static __inline__ int
set_src_cost (rtx x, unsigned char speed_p)
{
  return rtx_cost (x, SET, 1, speed_p);
}
static __inline__ void
get_full_set_src_cost (rtx x, struct full_rtx_costs *c)
{
  get_full_rtx_cost (x, SET, 1, c);
}
# 1634 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
extern int generating_concat_p;
extern int currently_expanding_to_rtl;
extern int ceil_log2 (unsigned long long);
extern long long trunc_int_for_mode (long long, enum machine_mode);
extern rtx plus_constant (rtx, long long);
extern rtx rtx_alloc_stat (enum rtx_code );
extern rtvec rtvec_alloc (int);
extern rtvec shallow_copy_rtvec (rtvec);
extern unsigned char shared_const_p (const_rtx);
extern rtx copy_rtx (rtx);
extern void dump_rtx_statistics (void);
extern rtx copy_rtx_if_shared (rtx);
extern unsigned int rtx_size (const_rtx);
extern rtx shallow_copy_rtx_stat (const_rtx );
extern int rtx_equal_p (const_rtx, const_rtx);
extern hashval_t iterative_hash_rtx (const_rtx, hashval_t);
extern rtvec gen_rtvec_v (int, rtx *);
extern rtx gen_reg_rtx (enum machine_mode);
extern rtx gen_rtx_REG_offset (rtx, enum machine_mode, unsigned int, int);
extern rtx gen_reg_rtx_offset (rtx, enum machine_mode, int);
extern rtx gen_reg_rtx_and_attrs (rtx);
extern rtx gen_label_rtx (void);
extern rtx gen_lowpart_common (enum machine_mode, rtx);
extern rtx gen_lowpart_if_possible (enum machine_mode, rtx);
extern rtx gen_highpart (enum machine_mode, rtx);
extern rtx gen_highpart_mode (enum machine_mode, enum machine_mode, rtx);
extern rtx operand_subword (rtx, unsigned int, int, enum machine_mode);
extern rtx operand_subword_force (rtx, unsigned int, enum machine_mode);
extern unsigned char paradoxical_subreg_p (const_rtx);
extern int subreg_lowpart_p (const_rtx);
extern unsigned int subreg_lowpart_offset (enum machine_mode,
        enum machine_mode);
extern unsigned int subreg_highpart_offset (enum machine_mode,
         enum machine_mode);
extern int byte_lowpart_offset (enum machine_mode, enum machine_mode);
extern rtx make_safe_from (rtx, rtx);
extern rtx convert_memory_address_addr_space (enum machine_mode, rtx,
           addr_space_t);
extern const char *get_insn_name (int);
extern rtx get_last_insn_anywhere (void);
extern rtx get_first_nonnote_insn (void);
extern rtx get_last_nonnote_insn (void);
extern void start_sequence (void);
extern void push_to_sequence (rtx);
extern void push_to_sequence2 (rtx, rtx);
extern void end_sequence (void);
extern double_int rtx_to_double_int (const_rtx);
extern rtx immed_double_int_const (double_int, enum machine_mode);
extern rtx immed_double_const (long long, long long,
          enum machine_mode);
extern rtx lowpart_subreg (enum machine_mode, rtx, enum machine_mode);
extern rtx force_const_mem (enum machine_mode, rtx);
struct function;
extern rtx get_pool_constant (rtx);
extern rtx get_pool_constant_mark (rtx, unsigned char *);
extern enum machine_mode get_pool_mode (const_rtx);
extern rtx simplify_subtraction (rtx);
extern void decide_function_section (tree);
extern rtx assign_stack_local (enum machine_mode, long long, int);
extern rtx assign_stack_local_1 (enum machine_mode, long long, int, int);
extern rtx assign_stack_temp (enum machine_mode, long long, int);
extern rtx assign_stack_temp_for_type (enum machine_mode,
           long long, int, tree);
extern rtx assign_temp (tree, int, int, int);
extern rtx emit_insn_before (rtx, rtx);
extern rtx emit_insn_before_noloc (rtx, rtx, struct basic_block_def *);
extern rtx emit_insn_before_setloc (rtx, rtx, int);
extern rtx emit_jump_insn_before (rtx, rtx);
extern rtx emit_jump_insn_before_noloc (rtx, rtx);
extern rtx emit_jump_insn_before_setloc (rtx, rtx, int);
extern rtx emit_call_insn_before (rtx, rtx);
extern rtx emit_call_insn_before_noloc (rtx, rtx);
extern rtx emit_call_insn_before_setloc (rtx, rtx, int);
extern rtx emit_debug_insn_before (rtx, rtx);
extern rtx emit_debug_insn_before_noloc (rtx, rtx);
extern rtx emit_debug_insn_before_setloc (rtx, rtx, int);
extern rtx emit_barrier_before (rtx);
extern rtx emit_label_before (rtx, rtx);
extern rtx emit_note_before (enum insn_note, rtx);
extern rtx emit_insn_after (rtx, rtx);
extern rtx emit_insn_after_noloc (rtx, rtx, struct basic_block_def *);
extern rtx emit_insn_after_setloc (rtx, rtx, int);
extern rtx emit_jump_insn_after (rtx, rtx);
extern rtx emit_jump_insn_after_noloc (rtx, rtx);
extern rtx emit_jump_insn_after_setloc (rtx, rtx, int);
extern rtx emit_call_insn_after (rtx, rtx);
extern rtx emit_call_insn_after_noloc (rtx, rtx);
extern rtx emit_call_insn_after_setloc (rtx, rtx, int);
extern rtx emit_debug_insn_after (rtx, rtx);
extern rtx emit_debug_insn_after_noloc (rtx, rtx);
extern rtx emit_debug_insn_after_setloc (rtx, rtx, int);
extern rtx emit_barrier_after (rtx);
extern rtx emit_label_after (rtx, rtx);
extern rtx emit_note_after (enum insn_note, rtx);
extern rtx emit_insn (rtx);
extern rtx emit_debug_insn (rtx);
extern rtx emit_jump_insn (rtx);
extern rtx emit_call_insn (rtx);
extern rtx emit_label (rtx);
extern rtx emit_barrier (void);
extern rtx emit_note (enum insn_note);
extern rtx emit_note_copy (rtx);
extern rtx gen_clobber (rtx);
extern rtx emit_clobber (rtx);
extern rtx gen_use (rtx);
extern rtx emit_use (rtx);
extern rtx make_insn_raw (rtx);
extern rtx make_debug_insn_raw (rtx);
extern rtx make_jump_insn_raw (rtx);
extern void add_function_usage_to (rtx, rtx);
extern rtx last_call_insn (void);
extern rtx previous_insn (rtx);
extern rtx next_insn (rtx);
extern rtx prev_nonnote_insn (rtx);
extern rtx prev_nonnote_insn_bb (rtx);
extern rtx next_nonnote_insn (rtx);
extern rtx next_nonnote_insn_bb (rtx);
extern rtx prev_nondebug_insn (rtx);
extern rtx next_nondebug_insn (rtx);
extern rtx prev_nonnote_nondebug_insn (rtx);
extern rtx next_nonnote_nondebug_insn (rtx);
extern rtx prev_real_insn (rtx);
extern rtx next_real_insn (rtx);
extern rtx prev_active_insn (rtx);
extern rtx next_active_insn (rtx);
extern int active_insn_p (const_rtx);
extern rtx next_label (rtx);
extern rtx skip_consecutive_labels (rtx);
extern rtx next_cc0_user (rtx);
extern rtx prev_cc0_setter (rtx);
extern int insn_line (const_rtx);
extern const char * insn_file (const_rtx);
extern location_t locator_location (int);
extern int locator_line (int);
extern const char * locator_file (int);
extern unsigned char locator_eq (int, int);
extern int prologue_locator, epilogue_locator;
extern enum rtx_code reverse_condition (enum rtx_code);
extern enum rtx_code reverse_condition_maybe_unordered (enum rtx_code);
extern enum rtx_code swap_condition (enum rtx_code);
extern enum rtx_code unsigned_condition (enum rtx_code);
extern enum rtx_code signed_condition (enum rtx_code);
extern void mark_jump_label (rtx, rtx, int);
extern unsigned int cleanup_barriers (void);
extern rtx delete_related_insns (rtx);
extern rtx *find_constant_term_loc (rtx *);
extern rtx try_split (rtx, rtx, int);
extern int split_branch_probability;
extern rtx split_insns (rtx, rtx);
extern rtx simplify_const_unary_operation (enum rtx_code, enum machine_mode,
        rtx, enum machine_mode);
extern rtx simplify_unary_operation (enum rtx_code, enum machine_mode, rtx,
         enum machine_mode);
extern rtx simplify_const_binary_operation (enum rtx_code, enum machine_mode,
         rtx, rtx);
extern rtx simplify_binary_operation (enum rtx_code, enum machine_mode, rtx,
          rtx);
extern rtx simplify_ternary_operation (enum rtx_code, enum machine_mode,
           enum machine_mode, rtx, rtx, rtx);
extern rtx simplify_const_relational_operation (enum rtx_code,
      enum machine_mode, rtx, rtx);
extern rtx simplify_relational_operation (enum rtx_code, enum machine_mode,
       enum machine_mode, rtx, rtx);
extern rtx simplify_gen_binary (enum rtx_code, enum machine_mode, rtx, rtx);
extern rtx simplify_gen_unary (enum rtx_code, enum machine_mode, rtx,
          enum machine_mode);
extern rtx simplify_gen_ternary (enum rtx_code, enum machine_mode,
     enum machine_mode, rtx, rtx, rtx);
extern rtx simplify_gen_relational (enum rtx_code, enum machine_mode,
        enum machine_mode, rtx, rtx);
extern rtx simplify_subreg (enum machine_mode, rtx, enum machine_mode,
       unsigned int);
extern rtx simplify_gen_subreg (enum machine_mode, rtx, enum machine_mode,
    unsigned int);
extern rtx simplify_replace_fn_rtx (rtx, const_rtx,
        rtx (*fn) (rtx, const_rtx, void *), void *);
extern rtx simplify_replace_rtx (rtx, const_rtx, rtx);
extern rtx simplify_rtx (const_rtx);
extern rtx avoid_constant_pool_reference (rtx);
extern rtx delegitimize_mem_from_attrs (rtx);
extern unsigned char mode_signbit_p (enum machine_mode, const_rtx);
extern unsigned char val_signbit_p (enum machine_mode, unsigned long long);
extern unsigned char val_signbit_known_set_p (enum machine_mode,
         unsigned long long);
extern unsigned char val_signbit_known_clear_p (enum machine_mode,
           unsigned long long);
extern enum machine_mode choose_hard_reg_mode (unsigned int, unsigned int,
            unsigned char);
extern rtx set_unique_reg_note (rtx, enum reg_note, rtx);
extern rtx set_dst_reg_note (rtx, enum reg_note, rtx, rtx);
extern void set_insn_deleted (rtx);
# 1895 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
typedef struct replace_label_data
{
  rtx r1;
  rtx r2;
  unsigned char update_label_nuses;
} replace_label_data;
extern int rtx_addr_can_trap_p (const_rtx);
extern unsigned char nonzero_address_p (const_rtx);
extern int rtx_unstable_p (const_rtx);
extern unsigned char rtx_varies_p (const_rtx, unsigned char);
extern unsigned char rtx_addr_varies_p (const_rtx, unsigned char);
extern long long get_integer_term (const_rtx);
extern rtx get_related_value (const_rtx);
extern unsigned char offset_within_block_p (const_rtx, long long);
extern void split_const (rtx, rtx *, rtx *);
extern int reg_mentioned_p (const_rtx, const_rtx);
extern int count_occurrences (const_rtx, const_rtx, int);
extern int reg_referenced_p (const_rtx, const_rtx);
extern int reg_used_between_p (const_rtx, const_rtx, const_rtx);
extern int reg_set_between_p (const_rtx, const_rtx, const_rtx);
extern int commutative_operand_precedence (rtx);
extern unsigned char swap_commutative_operands_p (rtx, rtx);
extern int modified_between_p (const_rtx, const_rtx, const_rtx);
extern int no_labels_between_p (const_rtx, const_rtx);
extern int modified_in_p (const_rtx, const_rtx);
extern int reg_set_p (const_rtx, const_rtx);
extern rtx single_set_2 (const_rtx, const_rtx);
extern int multiple_sets (const_rtx);
extern int set_noop_p (const_rtx);
extern int noop_move_p (const_rtx);
extern rtx find_last_value (rtx, rtx *, rtx, int);
extern int refers_to_regno_p (unsigned int, unsigned int, const_rtx, rtx *);
extern int reg_overlap_mentioned_p (const_rtx, const_rtx);
extern const_rtx set_of (const_rtx, const_rtx);
extern void record_hard_reg_sets (rtx, const_rtx, void *);
extern void record_hard_reg_uses (rtx *, void *);
extern void find_all_hard_reg_sets (const_rtx, HARD_REG_SET *);
extern void note_stores (const_rtx, void (*) (rtx, const_rtx, void *), void *);
extern void note_uses (rtx *, void (*) (rtx *, void *), void *);
extern int dead_or_set_p (const_rtx, const_rtx);
extern int dead_or_set_regno_p (const_rtx, unsigned int);
extern rtx find_reg_note (const_rtx, enum reg_note, const_rtx);
extern rtx find_regno_note (const_rtx, enum reg_note, unsigned int);
extern rtx find_reg_equal_equiv_note (const_rtx);
extern rtx find_constant_src (const_rtx);
extern int find_reg_fusage (const_rtx, enum rtx_code, const_rtx);
extern int find_regno_fusage (const_rtx, enum rtx_code, unsigned int);
extern rtx alloc_reg_note (enum reg_note, rtx, rtx);
extern void add_reg_note (rtx, enum reg_note, rtx);
extern void remove_note (rtx, const_rtx);
extern void remove_reg_equal_equiv_notes (rtx);
extern void remove_reg_equal_equiv_notes_for_regno (unsigned int);
extern int side_effects_p (const_rtx);
extern int volatile_refs_p (const_rtx);
extern int volatile_insn_p (const_rtx);
extern int may_trap_p_1 (const_rtx, unsigned);
extern int may_trap_p (const_rtx);
extern int may_trap_or_fault_p (const_rtx);
extern unsigned char can_throw_internal (const_rtx);
extern unsigned char can_throw_external (const_rtx);
extern unsigned char insn_could_throw_p (const_rtx);
extern unsigned char insn_nothrow_p (const_rtx);
extern unsigned char can_nonlocal_goto (const_rtx);
extern void copy_reg_eh_region_note_forward (rtx, rtx, rtx);
extern void copy_reg_eh_region_note_backward(rtx, rtx, rtx);
extern int inequality_comparisons_p (const_rtx);
extern rtx replace_rtx (rtx, rtx, rtx);
extern int replace_label (rtx *, void *);
extern int rtx_referenced_p (rtx, rtx);
extern unsigned char tablejump_p (const_rtx, rtx *, rtx *);
extern int computed_jump_p (const_rtx);
typedef int (*rtx_function) (rtx *, void *);
extern int for_each_rtx (rtx *, rtx_function, void *);
# 1980 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
typedef int (*for_each_inc_dec_fn) (rtx mem, rtx op, rtx dest, rtx src,
        rtx srcoff, void *arg);
extern int for_each_inc_dec (rtx *, for_each_inc_dec_fn, void *arg);
typedef int (*rtx_equal_p_callback_function) (const_rtx *, const_rtx *,
                                              rtx *, rtx *);
extern int rtx_equal_p_cb (const_rtx, const_rtx,
                           rtx_equal_p_callback_function);
typedef int (*hash_rtx_callback_function) (const_rtx, enum machine_mode, rtx *,
                                           enum machine_mode *);
extern unsigned hash_rtx_cb (const_rtx, enum machine_mode, int *, int *,
                             unsigned char, hash_rtx_callback_function);
extern rtx regno_use_in (unsigned int, rtx);
extern int auto_inc_p (const_rtx);
extern int in_expr_list_p (const_rtx, const_rtx);
extern void remove_node_from_expr_list (const_rtx, rtx *);
extern int loc_mentioned_in_p (rtx *, const_rtx);
extern rtx find_first_parameter_load (rtx, rtx);
extern unsigned char keep_with_call_p (const_rtx);
extern unsigned char label_is_jump_target_p (const_rtx, const_rtx);
extern int insn_rtx_cost (rtx, unsigned char);
extern rtx canonicalize_condition (rtx, rtx, int, rtx *, rtx, int, int);
extern rtx get_condition (rtx, rtx *, int, int);
struct subreg_info
{
  int offset;
  int nregs;
  unsigned char representable_p;
};
extern void subreg_get_info (unsigned int, enum machine_mode,
        unsigned int, enum machine_mode,
        struct subreg_info *);
extern void free_EXPR_LIST_list (rtx *);
extern void free_INSN_LIST_list (rtx *);
extern void free_EXPR_LIST_node (rtx);
extern void free_INSN_LIST_node (rtx);
extern rtx alloc_INSN_LIST (rtx, rtx);
extern rtx copy_INSN_LIST (rtx);
extern rtx concat_INSN_LIST (rtx, rtx);
extern rtx alloc_EXPR_LIST (int, rtx, rtx);
extern void remove_free_INSN_LIST_elem (rtx, rtx *);
extern rtx remove_list_elem (rtx, rtx *);
extern rtx remove_free_INSN_LIST_node (rtx *);
extern rtx remove_free_EXPR_LIST_node (rtx *);
extern void init_move_cost (enum machine_mode);
extern unsigned char resize_reg_info (void);
extern void free_reg_info (void);
extern void init_subregs_of_mode (void);
extern void finish_subregs_of_mode (void);
extern rtx extract_asm_operands (rtx);
extern int asm_noperands (const_rtx);
extern const char *decode_asm_operands (rtx, rtx *, rtx **, const char **,
     enum machine_mode *, location_t *);
extern enum reg_class reg_preferred_class (int);
extern enum reg_class reg_alternate_class (int);
extern enum reg_class reg_allocno_class (int);
extern void setup_reg_classes (int, enum reg_class, enum reg_class,
          enum reg_class);
extern void split_all_insns (void);
extern unsigned int split_all_insns_noflow (void);
extern rtx const_int_rtx[64 * 2 + 1];
extern rtx const_true_rtx;
extern rtx const_tiny_rtx[4][(int) MAX_MACHINE_MODE];
# 2113 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
enum global_rtl_index
{
  GR_PC,
  GR_CC0,
  GR_RETURN,
  GR_SIMPLE_RETURN,
  GR_STACK_POINTER,
  GR_FRAME_POINTER,
# 2130 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
  GR_HARD_FRAME_POINTER,
  GR_ARG_POINTER,
  GR_VIRTUAL_INCOMING_ARGS,
  GR_VIRTUAL_STACK_ARGS,
  GR_VIRTUAL_STACK_DYNAMIC,
  GR_VIRTUAL_OUTGOING_ARGS,
  GR_VIRTUAL_CFA,
  GR_VIRTUAL_PREFERRED_STACK_BOUNDARY,
  GR_MAX
};
struct target_rtl {
# 2166 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
  rtx x_global_rtl[GR_MAX];
  rtx x_pic_offset_table_rtx;
  rtx x_return_address_pointer_rtx;
  rtx x_initial_regno_reg_rtx[128];
  rtx x_top_of_stack[MAX_MACHINE_MODE];
  rtx x_static_reg_base_value[128];
  struct mem_attrs *x_mode_mem_attrs[(int) MAX_MACHINE_MODE];
};
extern struct target_rtl default_target_rtl;
# 2227 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
static __inline__ struct mem_attrs *
get_mem_attrs (const_rtx x)
{
  struct mem_attrs *attrs;
  attrs = (((x)->u.fld[1]).rt_mem);
  if (!attrs)
    attrs = ((&default_target_rtl)->x_mode_mem_attrs)[(int) ((enum machine_mode) (x)->mode)];
  return attrs;
}
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/genrtl.h" 1
static __inline__ rtx
gen_rtx_fmt_0_stat (enum rtx_code code, enum machine_mode mode )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtx) = (rtx) 0;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_ee_stat (enum rtx_code code, enum machine_mode mode,
 rtx arg0,
 rtx arg1 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtx) = arg0;
  (((rt)->u.fld[1]).rt_rtx) = arg1;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_ue_stat (enum rtx_code code, enum machine_mode mode,
 rtx arg0,
 rtx arg1 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtx) = arg0;
  (((rt)->u.fld[1]).rt_rtx) = arg1;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_E_stat (enum rtx_code code, enum machine_mode mode,
 rtvec arg0 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtvec) = arg0;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_e_stat (enum rtx_code code, enum machine_mode mode,
 rtx arg0 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtx) = arg0;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_iuuBeiie_stat (enum rtx_code code, enum machine_mode mode,
 int arg0,
 rtx arg1,
 rtx arg2,
 struct basic_block_def *arg3,
 rtx arg4,
 int arg5,
 int arg6,
 rtx arg7 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_int) = arg0;
  (((rt)->u.fld[1]).rt_rtx) = arg1;
  (((rt)->u.fld[2]).rt_rtx) = arg2;
  (((rt)->u.fld[3]).rt_bb) = arg3;
  (((rt)->u.fld[4]).rt_rtx) = arg4;
  (((rt)->u.fld[5]).rt_int) = arg5;
  (((rt)->u.fld[6]).rt_int) = arg6;
  (((rt)->u.fld[7]).rt_rtx) = arg7;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_iuuBeiie0_stat (enum rtx_code code, enum machine_mode mode,
 int arg0,
 rtx arg1,
 rtx arg2,
 struct basic_block_def *arg3,
 rtx arg4,
 int arg5,
 int arg6,
 rtx arg7 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_int) = arg0;
  (((rt)->u.fld[1]).rt_rtx) = arg1;
  (((rt)->u.fld[2]).rt_rtx) = arg2;
  (((rt)->u.fld[3]).rt_bb) = arg3;
  (((rt)->u.fld[4]).rt_rtx) = arg4;
  (((rt)->u.fld[5]).rt_int) = arg5;
  (((rt)->u.fld[6]).rt_int) = arg6;
  (((rt)->u.fld[7]).rt_rtx) = arg7;
  (((rt)->u.fld[8]).rt_rtx) = (rtx) 0;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_iuuBeiiee_stat (enum rtx_code code, enum machine_mode mode,
 int arg0,
 rtx arg1,
 rtx arg2,
 struct basic_block_def *arg3,
 rtx arg4,
 int arg5,
 int arg6,
 rtx arg7,
 rtx arg8 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_int) = arg0;
  (((rt)->u.fld[1]).rt_rtx) = arg1;
  (((rt)->u.fld[2]).rt_rtx) = arg2;
  (((rt)->u.fld[3]).rt_bb) = arg3;
  (((rt)->u.fld[4]).rt_rtx) = arg4;
  (((rt)->u.fld[5]).rt_int) = arg5;
  (((rt)->u.fld[6]).rt_int) = arg6;
  (((rt)->u.fld[7]).rt_rtx) = arg7;
  (((rt)->u.fld[8]).rt_rtx) = arg8;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_iuu00000_stat (enum rtx_code code, enum machine_mode mode,
 int arg0,
 rtx arg1,
 rtx arg2 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_int) = arg0;
  (((rt)->u.fld[1]).rt_rtx) = arg1;
  (((rt)->u.fld[2]).rt_rtx) = arg2;
  (((rt)->u.fld[3]).rt_rtx) = (rtx) 0;
  (((rt)->u.fld[4]).rt_rtx) = (rtx) 0;
  (((rt)->u.fld[5]).rt_rtx) = (rtx) 0;
  (((rt)->u.fld[6]).rt_rtx) = (rtx) 0;
  (((rt)->u.fld[7]).rt_rtx) = (rtx) 0;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_iuuB00is_stat (enum rtx_code code, enum machine_mode mode,
 int arg0,
 rtx arg1,
 rtx arg2,
 struct basic_block_def *arg3,
 int arg4,
 const char *arg5 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_int) = arg0;
  (((rt)->u.fld[1]).rt_rtx) = arg1;
  (((rt)->u.fld[2]).rt_rtx) = arg2;
  (((rt)->u.fld[3]).rt_bb) = arg3;
  (((rt)->u.fld[4]).rt_rtx) = (rtx) 0;
  (((rt)->u.fld[5]).rt_rtx) = (rtx) 0;
  (((rt)->u.fld[6]).rt_int) = arg4;
  (((rt)->u.fld[7]).rt_str) = arg5;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_si_stat (enum rtx_code code, enum machine_mode mode,
 const char *arg0,
 int arg1 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_str) = arg0;
  (((rt)->u.fld[1]).rt_int) = arg1;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_ssiEEEi_stat (enum rtx_code code, enum machine_mode mode,
 const char *arg0,
 const char *arg1,
 int arg2,
 rtvec arg3,
 rtvec arg4,
 rtvec arg5,
 int arg6 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_str) = arg0;
  (((rt)->u.fld[1]).rt_str) = arg1;
  (((rt)->u.fld[2]).rt_int) = arg2;
  (((rt)->u.fld[3]).rt_rtvec) = arg3;
  (((rt)->u.fld[4]).rt_rtvec) = arg4;
  (((rt)->u.fld[5]).rt_rtvec) = arg5;
  (((rt)->u.fld[6]).rt_int) = arg6;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_Ei_stat (enum rtx_code code, enum machine_mode mode,
 rtvec arg0,
 int arg1 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtvec) = arg0;
  (((rt)->u.fld[1]).rt_int) = arg1;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_eEee0_stat (enum rtx_code code, enum machine_mode mode,
 rtx arg0,
 rtvec arg1,
 rtx arg2,
 rtx arg3 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtx) = arg0;
  (((rt)->u.fld[1]).rt_rtvec) = arg1;
  (((rt)->u.fld[2]).rt_rtx) = arg2;
  (((rt)->u.fld[3]).rt_rtx) = arg3;
  (((rt)->u.fld[4]).rt_rtx) = (rtx) 0;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_eee_stat (enum rtx_code code, enum machine_mode mode,
 rtx arg0,
 rtx arg1,
 rtx arg2 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtx) = arg0;
  (((rt)->u.fld[1]).rt_rtx) = arg1;
  (((rt)->u.fld[2]).rt_rtx) = arg2;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt__stat (enum rtx_code code, enum machine_mode mode )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_w_stat (enum rtx_code code, enum machine_mode mode,
 long long arg0 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  ((rt)->u.hwint[0]) = arg0;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_www_stat (enum rtx_code code, enum machine_mode mode,
 long long arg0,
 long long arg1,
 long long arg2 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  ((rt)->u.hwint[0]) = arg0;
  ((rt)->u.hwint[1]) = arg1;
  ((rt)->u.hwint[2]) = arg2;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_s_stat (enum rtx_code code, enum machine_mode mode,
 const char *arg0 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_str) = arg0;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_i00_stat (enum rtx_code code, enum machine_mode mode,
 int arg0 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_int) = arg0;
  (((rt)->u.fld[1]).rt_rtx) = (rtx) 0;
  (((rt)->u.fld[2]).rt_rtx) = (rtx) 0;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_ei_stat (enum rtx_code code, enum machine_mode mode,
 rtx arg0,
 int arg1 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtx) = arg0;
  (((rt)->u.fld[1]).rt_int) = arg1;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_e0_stat (enum rtx_code code, enum machine_mode mode,
 rtx arg0 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtx) = arg0;
  (((rt)->u.fld[1]).rt_rtx) = (rtx) 0;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_u_stat (enum rtx_code code, enum machine_mode mode,
 rtx arg0 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtx) = arg0;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_s00_stat (enum rtx_code code, enum machine_mode mode,
 const char *arg0 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_str) = arg0;
  (((rt)->u.fld[1]).rt_rtx) = (rtx) 0;
  (((rt)->u.fld[2]).rt_rtx) = (rtx) 0;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_tei_stat (enum rtx_code code, enum machine_mode mode,
 union tree_node *arg0,
 rtx arg1,
 int arg2 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_tree) = arg0;
  (((rt)->u.fld[1]).rt_rtx) = arg1;
  (((rt)->u.fld[2]).rt_int) = arg2;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_t_stat (enum rtx_code code, enum machine_mode mode,
 union tree_node *arg0 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_tree) = arg0;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_iss_stat (enum rtx_code code, enum machine_mode mode,
 int arg0,
 const char *arg1,
 const char *arg2 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_int) = arg0;
  (((rt)->u.fld[1]).rt_str) = arg1;
  (((rt)->u.fld[2]).rt_str) = arg2;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_is_stat (enum rtx_code code, enum machine_mode mode,
 int arg0,
 const char *arg1 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_int) = arg0;
  (((rt)->u.fld[1]).rt_str) = arg1;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_isE_stat (enum rtx_code code, enum machine_mode mode,
 int arg0,
 const char *arg1,
 rtvec arg2 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_int) = arg0;
  (((rt)->u.fld[1]).rt_str) = arg1;
  (((rt)->u.fld[2]).rt_rtvec) = arg2;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_i_stat (enum rtx_code code, enum machine_mode mode,
 int arg0 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_int) = arg0;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_iE_stat (enum rtx_code code, enum machine_mode mode,
 int arg0,
 rtvec arg1 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_int) = arg0;
  (((rt)->u.fld[1]).rt_rtvec) = arg1;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_ss_stat (enum rtx_code code, enum machine_mode mode,
 const char *arg0,
 const char *arg1 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_str) = arg0;
  (((rt)->u.fld[1]).rt_str) = arg1;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_sEss_stat (enum rtx_code code, enum machine_mode mode,
 const char *arg0,
 rtvec arg1,
 const char *arg2,
 const char *arg3 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_str) = arg0;
  (((rt)->u.fld[1]).rt_rtvec) = arg1;
  (((rt)->u.fld[2]).rt_str) = arg2;
  (((rt)->u.fld[3]).rt_str) = arg3;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_eE_stat (enum rtx_code code, enum machine_mode mode,
 rtx arg0,
 rtvec arg1 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtx) = arg0;
  (((rt)->u.fld[1]).rt_rtvec) = arg1;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_Ess_stat (enum rtx_code code, enum machine_mode mode,
 rtvec arg0,
 const char *arg1,
 const char *arg2 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtvec) = arg0;
  (((rt)->u.fld[1]).rt_str) = arg1;
  (((rt)->u.fld[2]).rt_str) = arg2;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_ses_stat (enum rtx_code code, enum machine_mode mode,
 const char *arg0,
 rtx arg1,
 const char *arg2 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_str) = arg0;
  (((rt)->u.fld[1]).rt_rtx) = arg1;
  (((rt)->u.fld[2]).rt_str) = arg2;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_sss_stat (enum rtx_code code, enum machine_mode mode,
 const char *arg0,
 const char *arg1,
 const char *arg2 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_str) = arg0;
  (((rt)->u.fld[1]).rt_str) = arg1;
  (((rt)->u.fld[2]).rt_str) = arg2;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_sse_stat (enum rtx_code code, enum machine_mode mode,
 const char *arg0,
 const char *arg1,
 rtx arg2 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_str) = arg0;
  (((rt)->u.fld[1]).rt_str) = arg1;
  (((rt)->u.fld[2]).rt_rtx) = arg2;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_sies_stat (enum rtx_code code, enum machine_mode mode,
 const char *arg0,
 int arg1,
 rtx arg2,
 const char *arg3 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_str) = arg0;
  (((rt)->u.fld[1]).rt_int) = arg1;
  (((rt)->u.fld[2]).rt_rtx) = arg2;
  (((rt)->u.fld[3]).rt_str) = arg3;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_sE_stat (enum rtx_code code, enum machine_mode mode,
 const char *arg0,
 rtvec arg1 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_str) = arg0;
  (((rt)->u.fld[1]).rt_rtvec) = arg1;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_ii_stat (enum rtx_code code, enum machine_mode mode,
 int arg0,
 int arg1 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_int) = arg0;
  (((rt)->u.fld[1]).rt_int) = arg1;
  return rt;
}
static __inline__ rtx
gen_rtx_fmt_Ee_stat (enum rtx_code code, enum machine_mode mode,
 rtvec arg0,
 rtx arg1 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );
  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtvec) = arg0;
  (((rt)->u.fld[1]).rt_rtx) = arg1;
  return rt;
}
# 2243 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h" 2
# 2254 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
extern rtx gen_rtx_CONST_INT (enum machine_mode, long long);
extern rtx gen_rtx_CONST_VECTOR (enum machine_mode, rtvec);
extern rtx gen_raw_REG (enum machine_mode, int);
extern rtx gen_rtx_REG (enum machine_mode, unsigned);
extern rtx gen_rtx_SUBREG (enum machine_mode, rtx, int);
extern rtx gen_rtx_MEM (enum machine_mode, rtx);
# 2338 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
extern rtx output_constant_def (tree, int);
extern rtx lookup_constant_def (tree);
extern int reload_completed;
extern int epilogue_completed;
extern int reload_in_progress;
# 2371 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/rtl.h"
extern int cse_not_expected;
extern int rtx_to_tree_code (enum rtx_code);
extern int delete_trivially_dead_insns (rtx, int);
extern int cse_main (rtx, int);
extern int exp_equiv_p (const_rtx, const_rtx, int, unsigned char);
extern unsigned hash_rtx (const_rtx x, enum machine_mode, int *, int *, unsigned char);
extern unsigned char check_for_inc_dec (rtx insn);
extern int comparison_dominates_p (enum rtx_code, enum rtx_code);
extern unsigned char jump_to_label_p (rtx);
extern int condjump_p (const_rtx);
extern int any_condjump_p (const_rtx);
extern int any_uncondjump_p (const_rtx);
extern rtx pc_set (const_rtx);
extern rtx condjump_label (const_rtx);
extern int simplejump_p (const_rtx);
extern int returnjump_p (rtx);
extern int eh_returnjump_p (rtx);
extern int onlyjump_p (const_rtx);
extern int only_sets_cc0_p (const_rtx);
extern int sets_cc0_p (const_rtx);
extern int invert_jump_1 (rtx, rtx);
extern int invert_jump (rtx, rtx, int);
extern int rtx_renumbered_equal_p (const_rtx, const_rtx);
extern int true_regnum (const_rtx);
extern unsigned int reg_or_subregno (const_rtx);
extern int redirect_jump_1 (rtx, rtx);
extern void redirect_jump_2 (rtx, rtx, rtx, int, int);
extern int redirect_jump (rtx, rtx, int);
extern void rebuild_jump_labels (rtx);
extern void rebuild_jump_labels_chain (rtx);
extern rtx reversed_comparison (const_rtx, enum machine_mode);
extern enum rtx_code reversed_comparison_code (const_rtx, const_rtx);
extern enum rtx_code reversed_comparison_code_parts (enum rtx_code, const_rtx,
           const_rtx, const_rtx);
extern void delete_for_peephole (rtx, rtx);
extern int condjump_in_parallel_p (const_rtx);
extern int max_reg_num (void);
extern int max_label_num (void);
extern int get_first_label_num (void);
extern void maybe_set_first_label_num (rtx);
extern void delete_insns_since (rtx);
extern void mark_reg_pointer (rtx, int);
extern void mark_user_reg (rtx);
extern void reset_used_flags (rtx);
extern void set_used_flags (rtx);
extern void reorder_insns (rtx, rtx, rtx);
extern void reorder_insns_nobb (rtx, rtx, rtx);
extern int get_max_insn_count (void);
extern int in_sequence_p (void);
extern void force_next_line_note (void);
extern void init_emit (void);
extern void init_emit_regs (void);
extern void init_emit_once (void);
extern void push_topmost_sequence (void);
extern void pop_topmost_sequence (void);
extern void set_new_first_and_last_insn (rtx, rtx);
extern unsigned int unshare_all_rtl (void);
extern void unshare_all_rtl_again (rtx);
extern void unshare_all_rtl_in_chain (rtx);
extern void verify_rtl_sharing (void);
extern void link_cc0_insns (rtx);
extern void add_insn (rtx);
extern void add_insn_before (rtx, rtx, struct basic_block_def *);
extern void add_insn_after (rtx, rtx, struct basic_block_def *);
extern void remove_insn (rtx);
extern rtx emit (rtx);
extern rtx delete_insn (rtx);
extern rtx entry_of_function (void);
extern void emit_insn_at_entry (rtx);
extern void delete_insn_chain (rtx, rtx, unsigned char);
extern rtx unlink_insn_chain (rtx, rtx);
extern rtx delete_insn_and_edges (rtx);
extern rtx gen_lowpart_SUBREG (enum machine_mode, rtx);
extern rtx gen_const_mem (enum machine_mode, rtx);
extern rtx gen_frame_mem (enum machine_mode, rtx);
extern rtx gen_tmp_stack_mem (enum machine_mode, rtx);
extern unsigned char validate_subreg (enum machine_mode, enum machine_mode,
        const_rtx, unsigned int);
extern unsigned int extended_count (const_rtx, enum machine_mode, int);
extern rtx remove_death (unsigned int, rtx);
extern void dump_combine_stats (FILE *);
extern void dump_combine_total_stats (FILE *);
extern void delete_dead_jumptables (void);
extern void debug_bb_n_slim (int);
extern void debug_bb_slim (struct basic_block_def *);
extern void print_rtl_slim (FILE *, rtx, rtx, int, int);
extern void print_rtl_slim_with_bb (FILE *, rtx, int);
extern void dump_insn_slim (FILE *f, rtx x);
extern void debug_insn_slim (rtx x);
extern void schedule_insns (void);
extern void schedule_ebbs (void);
extern void sel_sched_fix_param (const char *param, const char *val);
extern const char *print_rtx_head;
extern void debug_rtx (const_rtx);
extern void debug_rtx_list (const_rtx, int);
extern void debug_rtx_range (const_rtx, const_rtx);
extern const_rtx debug_rtx_find (const_rtx, int);
extern void print_mem_expr (FILE *, const_tree);
extern void print_rtl (FILE *, const_rtx);
extern void print_simple_rtl (FILE *, const_rtx);
extern int print_rtl_single (FILE *, const_rtx);
extern void print_inline_rtx (FILE *, const_rtx, int);
extern void reposition_prologue_and_epilogue_notes (void);
extern int prologue_epilogue_contains (const_rtx);
extern int sibcall_epilogue_contains (const_rtx);
extern void mark_temp_addr_taken (rtx);
extern void update_temp_slot_address (rtx, rtx);
extern void maybe_copy_prologue_epilogue_insn (rtx, rtx);
extern void set_return_jump_label (rtx);
extern void expand_null_return (void);
extern void expand_naked_return (void);
extern void emit_jump (rtx);
extern rtx move_by_pieces (rtx, rtx, unsigned long long,
      unsigned int, int);
extern long long find_args_size_adjust (rtx);
extern int fixup_args_size_notes (rtx, rtx, int);
extern void print_rtl_with_bb (FILE *, const_rtx);
extern void dump_reg_info (FILE *);
extern void dump_flow_info (FILE *, int);
extern void init_expmed (void);
extern void expand_inc (rtx, rtx);
extern void expand_dec (rtx, rtx);
extern unsigned char can_copy_p (enum machine_mode);
extern unsigned char can_assign_to_reg_without_clobbers_p (rtx);
extern rtx fis_get_condition (rtx);
extern HARD_REG_SET eliminable_regset;
extern void mark_elimination (int, int);
extern int reg_classes_intersect_p (reg_class_t, reg_class_t);
extern int reg_class_subset_p (reg_class_t, reg_class_t);
extern void globalize_reg (tree, int);
extern void init_reg_modes_target (void);
extern void init_regs (void);
extern void reinit_regs (void);
extern void init_fake_stack_mems (void);
extern void save_register_info (void);
extern void init_reg_sets (void);
extern void regclass (rtx, int);
extern void reg_scan (rtx, unsigned int);
extern void fix_register (const char *, int, int);
extern unsigned char invalid_mode_change_p (unsigned int, enum reg_class);
extern void dbr_schedule (rtx);
extern int function_invariant_p (const_rtx);
enum libcall_type
{
  LCT_NORMAL = 0,
  LCT_CONST = 1,
  LCT_PURE = 2,
  LCT_NORETURN = 3,
  LCT_THROW = 4,
  LCT_RETURNS_TWICE = 5
};
extern void emit_library_call (rtx, enum libcall_type, enum machine_mode, int,
          ...);
extern rtx emit_library_call_value (rtx, rtx, enum libcall_type,
        enum machine_mode, int, ...);
extern void init_varasm_once (void);
extern rtx make_debug_expr_from_rtl (const_rtx);
extern unsigned char read_rtx (const char *, rtx *);
extern rtx canon_rtx (rtx);
extern int true_dependence (const_rtx, enum machine_mode, const_rtx);
extern rtx get_addr (rtx);
extern int canon_true_dependence (const_rtx, enum machine_mode, rtx,
      const_rtx, rtx);
extern int read_dependence (const_rtx, const_rtx);
extern int anti_dependence (const_rtx, const_rtx);
extern int output_dependence (const_rtx, const_rtx);
extern int may_alias_p (const_rtx, const_rtx);
extern void init_alias_target (void);
extern void init_alias_analysis (void);
extern void end_alias_analysis (void);
extern void vt_equate_reg_base_value (const_rtx, const_rtx);
extern unsigned char memory_modified_in_insn_p (const_rtx, const_rtx);
extern rtx find_base_term (rtx);
extern rtx gen_hard_reg_clobber (enum machine_mode, unsigned int);
extern rtx get_reg_known_value (unsigned int);
extern unsigned char get_reg_known_equiv_p (unsigned int);
extern rtx get_reg_base_value (unsigned int);
extern rtx stack_limit_rtx;
extern void invert_br_probabilities (rtx);
extern unsigned char expensive_function_p (int);
extern unsigned int variable_tracking_main (void);
extern void get_mode_bounds (enum machine_mode, int, enum machine_mode,
        rtx *, rtx *);
extern rtx reversed_condition (rtx);
extern rtx compare_and_jump_seq (rtx, rtx, enum rtx_code, rtx, int, rtx);
extern rtx canon_condition (rtx);
extern void simplify_using_condition (rtx, rtx *, struct bitmap_head_def *);
extern unsigned int compute_alignments (void);
extern int asm_str_count (const char *templ);
struct rtl_hooks
{
  rtx (*gen_lowpart) (enum machine_mode, rtx);
  rtx (*gen_lowpart_no_emit) (enum machine_mode, rtx);
  rtx (*reg_nonzero_bits) (const_rtx, enum machine_mode, const_rtx, enum machine_mode,
      unsigned long long, unsigned long long *);
  rtx (*reg_num_sign_bit_copies) (const_rtx, enum machine_mode, const_rtx, enum machine_mode,
      unsigned int, unsigned int *);
  unsigned char (*reg_truncated_to_mode) (enum machine_mode, const_rtx);
};
extern struct rtl_hooks rtl_hooks;
extern const struct rtl_hooks general_rtl_hooks;
extern void insn_locators_alloc (void);
extern void insn_locators_free (void);
extern void insn_locators_finalize (void);
extern void set_curr_insn_source_location (location_t);
extern location_t get_curr_insn_source_location (void);
extern void set_curr_insn_block (tree);
extern tree get_curr_insn_block (void);
extern int curr_insn_locator (void);
extern unsigned char optimize_insn_for_size_p (void);
extern unsigned char optimize_insn_for_speed_p (void);
extern void _fatal_insn_not_found (const_rtx, const char *, int, const char *)
     __attribute__ ((__noreturn__));
extern void _fatal_insn (const char *, const_rtx, const char *, int, const char *)
     __attribute__ ((__noreturn__));
# 43 "../../../src/plugin-utils.h" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/emit-rtl.h" 1
# 24 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/emit-rtl.h"
extern void set_mem_alias_set (rtx, alias_set_type);
extern void set_mem_align (rtx, unsigned int);
extern void set_mem_addr_space (rtx, addr_space_t);
extern void set_mem_expr (rtx, tree);
extern void set_mem_offset (rtx, long long);
extern void clear_mem_offset (rtx);
extern void set_mem_size (rtx, long long);
extern void clear_mem_size (rtx);
extern void set_mem_attrs_for_spill (rtx);
extern tree get_spill_slot_decl (unsigned char);
extern rtx replace_equiv_address (rtx, rtx);
extern rtx replace_equiv_address_nv (rtx, rtx);
extern rtx gen_blockage (void);
extern rtvec gen_rtvec (int, ...);
extern rtx copy_insn_1 (rtx);
extern rtx copy_insn (rtx);
extern rtx gen_int_mode (long long, enum machine_mode);
extern rtx emit_copy_of_insn_after (rtx, rtx);
extern void set_reg_attrs_from_value (rtx, rtx);
extern void set_reg_attrs_for_parm (rtx, rtx);
extern void set_reg_attrs_for_decl_rtl (tree t, rtx x);
extern void adjust_reg_mode (rtx, enum machine_mode);
extern int mem_expr_equal_p (const_tree, const_tree);
static __inline__ rtx
get_insns (void)
{
  return (&x_rtl)->emit.x_first_insn;
}
static __inline__ void
set_first_insn (rtx insn)
{
  ((void)(0 && (!insn || !(((insn)->u.fld[1]).rt_rtx))));
  (&x_rtl)->emit.x_first_insn = insn;
}
static __inline__ rtx
get_last_insn (void)
{
  return (&x_rtl)->emit.x_last_insn;
}
static __inline__ void
set_last_insn (rtx insn)
{
  ((void)(0 && (!insn || !(((insn)->u.fld[2]).rt_rtx))));
  (&x_rtl)->emit.x_last_insn = insn;
}
static __inline__ int
get_max_uid (void)
{
  return (&x_rtl)->emit.x_cur_insn_uid;
}
# 44 "../../../src/plugin-utils.h" 2
# 208 "../../../src/plugin-utils.h"
int is_gcc();
int is_gpp();
int is_lto();
void cpp_include(const char *file);
unsigned char is_targetable_decl(tree decl);
# 325 "../../../src/plugin-utils.h"
unsigned char comparison_set_rtx_1(rtx match_input,rtx *cc_op,rtx *op1,rtx *op2);
# 22 "../../../src/plugin-utils.c" 2
# 1 "/work1/moynault/Android-r1d-SRC/ndk/toolchains/arm-linux-androideabi-4.7.1/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7.1/plugin/include/cpplib.h" 1
# 23 "../../../src/plugin-utils.c" 2
static int is_gcc_cache=-1;
static int is_gpp_cache=-1;
static int is_lto_cache=-1;
int is_gcc(){
 if(is_gcc_cache==-1){
  is_gcc_cache=!strcmp(lang_hooks.name,"GNU C");
 }
 return is_gcc_cache;
}
int is_gpp(){
 if(is_gpp_cache==-1){
  is_gpp_cache=!strcmp(lang_hooks.name,"GNU C++");
 }
 return is_gpp_cache;
}
int is_lto(){
 if(is_lto_cache==-1){
  is_lto_cache=!strcmp(lang_hooks.name,"GNU GIMPLE");
 }
 return is_lto_cache;
}
void cpp_include(const char *file){
 cpp_push_include(parse_in,file);
}
# 72 "../../../src/plugin-utils.c"
unsigned char comparison_set_rtx_1(rtx match_input,rtx *cc_op,rtx *op1,rtx *op2){
 if(((enum rtx_code) (match_input)->code)==SET){
  rtx compare=(((match_input)->u.fld[1]).rt_rtx);
  *cc_op=(((match_input)->u.fld[0]).rt_rtx);
  if(((enum mode_class) mode_class[((enum machine_mode) (*cc_op)->mode)])==MODE_CC&&((enum rtx_code) (compare)->code)==COMPARE){
   *op1=(((compare)->u.fld[0]).rt_rtx);
   *op2=(((compare)->u.fld[1]).rt_rtx);
   return 1;
  }
 }
 return 0;
}
