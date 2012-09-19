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







# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stddef.h" 1 3 4
# 211 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stddef.h" 3 4
typedef unsigned int size_t;
# 323 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stddef.h" 3 4
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

# 277 "/usr/include/stdlib.h" 3 4

extern __inline double
__attribute__ ((__nothrow__)) atof (__const char *__nptr)
{
  return strtod (__nptr, (char **) ((void *)0));
}
extern __inline int
__attribute__ ((__nothrow__)) atoi (__const char *__nptr)
{
  return (int) strtol (__nptr, (char **) ((void *)0), 10);
}
extern __inline long int
__attribute__ ((__nothrow__)) atol (__const char *__nptr)
{
  return strtol (__nptr, (char **) ((void *)0), 10);
}




__extension__ extern __inline long long int
__attribute__ ((__nothrow__)) atoll (__const char *__nptr)
{
  return strtoll (__nptr, (char **) ((void *)0), 10);
}

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
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stddef.h" 1 3 4
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


__extension__ extern __inline unsigned int
__attribute__ ((__nothrow__)) gnu_dev_major (unsigned long long int __dev)
{
  return ((__dev >> 8) & 0xfff) | ((unsigned int) (__dev >> 32) & ~0xfff);
}

__extension__ extern __inline unsigned int
__attribute__ ((__nothrow__)) gnu_dev_minor (unsigned long long int __dev)
{
  return (__dev & 0xff) | ((unsigned int) (__dev >> 12) & ~0xff);
}

__extension__ extern __inline unsigned long long int
__attribute__ ((__nothrow__)) gnu_dev_makedev (unsigned int __major, unsigned int __minor)
{
  return ((__minor & 0xff) | ((__major & 0xfff) << 8)
   | (((unsigned long long int) (__minor & ~0xff)) << 12)
   | (((unsigned long long int) (__major & ~0xfff)) << 32));
}
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
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stddef.h" 1 3 4
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
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/gcc-plugin.h" 1
# 27 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/gcc-plugin.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config.h" 1





# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/auto-host.h" 1
# 7 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config.h" 2

# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/ansidecl.h" 1
# 9 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config.h" 2
# 28 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/gcc-plugin.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 1
# 28 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stdarg.h" 1 3 4
# 40 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 102 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;
# 29 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2
# 39 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stddef.h" 1 3 4
# 149 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 40 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2


# 1 "/usr/include/stdio.h" 1 3 4
# 30 "/usr/include/stdio.h" 3 4




# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stddef.h" 1 3 4
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
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stddef.h" 1 3 4
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
extern int fscanf (FILE *__restrict __stream, __const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf")

                               ;
extern int scanf (__const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf")
                              ;
extern int sscanf (__const char *__restrict __s, __const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf")

                          __attribute__ ((__nothrow__));
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
# 907 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/stdio.h" 1 3 4
# 36 "/usr/include/bits/stdio.h" 3 4
extern __inline int
vprintf (__const char *__restrict __fmt, __gnuc_va_list __arg)
{
  return vfprintf (stdout, __fmt, __arg);
}



extern __inline int
getchar (void)
{
  return _IO_getc (stdin);
}




extern __inline int
fgetc_unlocked (FILE *__fp)
{
  return (__builtin_expect (((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end), 0) ? __uflow (__fp) : *(unsigned char *) (__fp)->_IO_read_ptr++);
}





extern __inline int
getc_unlocked (FILE *__fp)
{
  return (__builtin_expect (((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end), 0) ? __uflow (__fp) : *(unsigned char *) (__fp)->_IO_read_ptr++);
}


extern __inline int
getchar_unlocked (void)
{
  return (__builtin_expect (((stdin)->_IO_read_ptr >= (stdin)->_IO_read_end), 0) ? __uflow (stdin) : *(unsigned char *) (stdin)->_IO_read_ptr++);
}




extern __inline int
putchar (int __c)
{
  return _IO_putc (__c, stdout);
}




extern __inline int
fputc_unlocked (int __c, FILE *__stream)
{
  return (__builtin_expect (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end), 0) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}





extern __inline int
putc_unlocked (int __c, FILE *__stream)
{
  return (__builtin_expect (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end), 0) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}


extern __inline int
putchar_unlocked (int __c)
{
  return (__builtin_expect (((stdout)->_IO_write_ptr >= (stdout)->_IO_write_end), 0) ? __overflow (stdout, (unsigned char) (__c)) : (unsigned char) (*(stdout)->_IO_write_ptr++ = (__c)));
}
# 125 "/usr/include/bits/stdio.h" 3 4
extern __inline int
__attribute__ ((__nothrow__)) feof_unlocked (FILE *__stream)
{
  return (((__stream)->_flags & 0x10) != 0);
}


extern __inline int
__attribute__ ((__nothrow__)) ferror_unlocked (FILE *__stream)
{
  return (((__stream)->_flags & 0x20) != 0);
}
# 908 "/usr/include/stdio.h" 2 3 4
# 916 "/usr/include/stdio.h" 3 4

# 43 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2
# 183 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/safe-ctype.h" 1
# 57 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/safe-ctype.h"
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
# 110 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/safe-ctype.h"
extern const unsigned char _sch_toupper[256];
extern const unsigned char _sch_tolower[256];
# 122 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/safe-ctype.h"
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
# 190 "/usr/include/ctype.h" 3 4
extern __inline int
__attribute__ ((__nothrow__)) tolower (int __c)
{
  return __c >= -128 && __c < 256 ? (*__ctype_tolower_loc ())[__c] : __c;
}

extern __inline int
__attribute__ ((__nothrow__)) toupper (int __c)
{
  return __c >= -128 && __c < 256 ? (*__ctype_toupper_loc ())[__c] : __c;
}
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

# 123 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/safe-ctype.h" 2
# 184 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2



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

# 188 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2
# 198 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
# 1 "/usr/include/string.h" 1 3 4
# 28 "/usr/include/string.h" 3 4





# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stddef.h" 1 3 4
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
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__))

                        __attribute__ ((__nonnull__ (2)));
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
# 632 "/usr/include/string.h" 3 4
# 1 "/usr/include/bits/string.h" 1 3 4
# 633 "/usr/include/string.h" 2 3 4


# 1 "/usr/include/bits/string2.h" 1 3 4
# 636 "/usr/include/string.h" 2 3 4
# 644 "/usr/include/string.h" 3 4

# 199 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2
# 1 "/usr/include/strings.h" 1 3 4
# 200 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2
# 236 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
# 1 "/usr/include/unistd.h" 1 3 4
# 28 "/usr/include/unistd.h" 3 4

# 203 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/bits/posix_opt.h" 1 3 4
# 204 "/usr/include/unistd.h" 2 3 4
# 227 "/usr/include/unistd.h" 3 4
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stddef.h" 1 3 4
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

# 237 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2



# 1 "/usr/include/sys/param.h" 1 3 4
# 26 "/usr/include/sys/param.h" 3 4
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include-fixed/limits.h" 1 3 4
# 34 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include-fixed/limits.h" 3 4
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include-fixed/syslimits.h" 1 3 4






# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include-fixed/limits.h" 1 3 4
# 169 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include-fixed/limits.h" 3 4
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
# 170 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include-fixed/limits.h" 2 3 4
# 8 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include-fixed/syslimits.h" 2 3 4
# 35 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include-fixed/limits.h" 2 3 4
# 27 "/usr/include/sys/param.h" 2 3 4

# 1 "/usr/include/linux/param.h" 1 3 4



# 1 "/usr/include/asm/param.h" 1 3 4
# 1 "/usr/include/asm-generic/param.h" 1 3 4
# 1 "/usr/include/asm/param.h" 2 3 4
# 5 "/usr/include/linux/param.h" 2 3 4
# 29 "/usr/include/sys/param.h" 2 3 4
# 241 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2





# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include-fixed/limits.h" 1 3 4
# 247 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2



# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/hwint.h" 1
# 251 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2
# 280 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
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

# 281 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2
# 1 "/usr/include/time.h" 1 3 4
# 30 "/usr/include/time.h" 3 4








# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stddef.h" 1 3 4
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

# 282 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2
# 293 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
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

# 294 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2
# 331 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
# 1 "/usr/include/sys/wait.h" 1 3 4
# 29 "/usr/include/sys/wait.h" 3 4


# 1 "/usr/include/signal.h" 1 3 4
# 31 "/usr/include/signal.h" 3 4


# 1 "/usr/include/bits/sigset.h" 1 3 4
# 104 "/usr/include/bits/sigset.h" 3 4
extern int __sigismember (__const __sigset_t *, int);
extern int __sigaddset (__sigset_t *, int);
extern int __sigdelset (__sigset_t *, int);
# 118 "/usr/include/bits/sigset.h" 3 4
extern __inline int __sigismember (__const __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return (__set->__val[__word] & __mask) ? 1 : 0; }
extern __inline int __sigaddset ( __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return ((__set->__val[__word] |= __mask), 0); }
extern __inline int __sigdelset ( __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return ((__set->__val[__word] &= ~__mask), 0); }
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






# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stddef.h" 1 3 4
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




# 332 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2
# 382 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
extern int getopt (int, char * const *, const char *);
# 402 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
# 1 "/usr/include/malloc.h" 1 3 4
# 25 "/usr/include/malloc.h" 3 4
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stddef.h" 1 3 4
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

extern void (*__free_hook) (void *__ptr, __const void *)
                             ;
extern void *(*__malloc_hook) (size_t __size, __const void *)
                                  ;
extern void *(*__realloc_hook) (void *__ptr, size_t __size, __const void *)
                                   ;
extern void *(*__memalign_hook) (size_t __alignment, size_t __size, __const void *)

                                    ;
extern void (*__after_morecore_hook) (void);


extern void __malloc_check_init (void) __attribute__ ((__nothrow__));



# 403 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2
# 418 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stdint.h" 1 3 4


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
# 4 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stdint.h" 2 3 4
# 419 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2



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
# 379 "/usr/include/inttypes.h" 3 4
__extension__
extern long long int __strtoll_internal (__const char *__restrict __nptr,
      char **__restrict __endptr,
      int __base, int __group)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern __inline intmax_t
__attribute__ ((__nothrow__)) strtoimax (__const char *__restrict nptr, char **__restrict endptr, int base)

{
  return __strtoll_internal (nptr, endptr, base, 0);
}

__extension__
extern unsigned long long int __strtoull_internal (__const char *
         __restrict __nptr,
         char **
         __restrict __endptr,
         int __base,
         int __group)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern __inline uintmax_t
__attribute__ ((__nothrow__)) strtoumax (__const char *__restrict nptr, char **__restrict endptr, int base)

{
  return __strtoull_internal (nptr, endptr, base, 0);
}

__extension__
extern long long int __wcstoll_internal (__const __gwchar_t *
      __restrict __nptr,
      __gwchar_t **__restrict __endptr,
      int __base, int __group)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern __inline intmax_t
__attribute__ ((__nothrow__)) wcstoimax (__const __gwchar_t *__restrict nptr, __gwchar_t **__restrict endptr, int base)

{
  return __wcstoll_internal (nptr, endptr, base, 0);
}


__extension__
extern unsigned long long int __wcstoull_internal (__const __gwchar_t *
         __restrict __nptr,
         __gwchar_t **
         __restrict __endptr,
         int __base,
         int __group)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern __inline uintmax_t
__attribute__ ((__nothrow__)) wcstoumax (__const __gwchar_t *__restrict nptr, __gwchar_t **__restrict endptr, int base)

{
  return __wcstoull_internal (nptr, endptr, base, 0);
}





# 423 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2
# 472 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
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




extern __inline int
__attribute__ ((__nothrow__)) stat (__const char *__path, struct stat *__statbuf)
{
  return __xstat (3, __path, __statbuf);
}


extern __inline int
__attribute__ ((__nothrow__)) lstat (__const char *__path, struct stat *__statbuf)
{
  return __lxstat (3, __path, __statbuf);
}


extern __inline int
__attribute__ ((__nothrow__)) fstat (int __fd, struct stat *__statbuf)
{
  return __fxstat (3, __fd, __statbuf);
}


extern __inline int
__attribute__ ((__nothrow__)) fstatat (int __fd, __const char *__filename, struct stat *__statbuf, int __flag)

{
  return __fxstatat (3, __fd, __filename, __statbuf, __flag);
}



extern __inline int
__attribute__ ((__nothrow__)) mknod (__const char *__path, __mode_t __mode, __dev_t __dev)
{
  return __xmknod (1, __path, __mode, &__dev);
}



extern __inline int
__attribute__ ((__nothrow__)) mknodat (int __fd, __const char *__path, __mode_t __mode, __dev_t __dev)

{
  return __xmknodat (1, __fd, __path, __mode, &__dev);
}
# 534 "/usr/include/sys/stat.h" 3 4

# 473 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2
# 540 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/filenames.h" 1
# 53 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/filenames.h"
extern int filename_cmp (const char *s1, const char *s2);
# 541 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2
# 551 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/libiberty.h" 1
# 46 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/libiberty.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stddef.h" 1 3 4
# 47 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/libiberty.h" 2
# 56 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/libiberty.h"
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
# 117 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/libiberty.h"
extern const char *lbasename (const char *);



extern char *lrealpath (const char *);





extern char *concat (const char *, ...) __attribute__ ((__malloc__)) __attribute__ ((__sentinel__));
# 136 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/libiberty.h"
extern char *reconcat (char *, const char *, ...) __attribute__ ((__malloc__)) __attribute__ ((__sentinel__));





extern unsigned long concat_length (const char *, ...) __attribute__ ((__sentinel__));






extern char *concat_copy (char *, const char *, ...) __attribute__ ((__sentinel__));






extern char *concat_copy2 (const char *, ...) __attribute__ ((__sentinel__));



extern char *libiberty_concat_ptr;
# 172 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/libiberty.h"
extern int fdmatch (int fd1, int fd2);
# 184 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/libiberty.h"
extern char * getpwd (void);
# 197 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/libiberty.h"
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
# 261 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/libiberty.h"
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
# 360 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/libiberty.h"
extern const unsigned char _hex_value[256];
extern void hex_init (void);
# 386 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/libiberty.h"
extern struct pex_obj *pex_init (int flags, const char *pname,
     const char *tempbase);
# 481 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/libiberty.h"
extern const char *pex_run (struct pex_obj *obj, int flags,
       const char *executable, char * const *argv,
       const char *outname, const char *errname,
       int *err);
# 496 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/libiberty.h"
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
# 571 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/libiberty.h"
extern const char *pex_one (int flags, const char *executable,
       char * const *argv, const char *pname,
       const char *outname, const char *errname,
       int *status, int *err);
# 590 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/libiberty.h"
extern int pexecute (const char *, char * const *, const char *,
                     const char *, char **, char **, int);



extern int pwait (int, int *, int);
# 634 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/libiberty.h"
extern void *C_alloca (size_t) __attribute__ ((__malloc__));
# 552 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h" 2
# 589 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
extern void fancy_abort (const char *, int, const char *) __attribute__ ((__noreturn__));
# 673 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
        




        



        
# 716 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
        
# 767 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
        
# 776 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
        
# 787 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
        
# 797 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/system.h"
        
# 29 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/gcc-plugin.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/highlev-plugin-common.h" 1
# 30 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/gcc-plugin.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/hashtab.h" 1
# 47 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/hashtab.h"
typedef unsigned int hashval_t;




typedef hashval_t (*htab_hash) (const void *);






typedef int (*htab_eq) (const void *, const void *);



typedef void (*htab_del) (void *);





typedef int (*htab_trav) (void **, void *);





typedef void *(*htab_alloc) (size_t, size_t);


typedef void (*htab_free) (void *);



typedef void *(*htab_alloc_with_arg) (void *, size_t, size_t);
typedef void (*htab_free_with_arg) (void *, void *);
# 100 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/hashtab.h"
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
# 31 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/gcc-plugin.h" 2


enum plugin_event
{

# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/plugin.def" 1
# 22 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/plugin.def"
PLUGIN_PASS_MANAGER_SETUP,


PLUGIN_FINISH_TYPE,


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
# 37 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/gcc-plugin.h" 2

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
# 96 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/gcc-plugin.h"
typedef int (*plugin_init_func) (struct plugin_name_args *plugin_info,
                                 struct plugin_gcc_version *version);






extern int plugin_init (struct plugin_name_args *plugin_info,
                        struct plugin_gcc_version *version);
# 115 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/gcc-plugin.h"
typedef void (*plugin_callback_func) (void *gcc_data, void *user_data);
# 128 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/gcc-plugin.h"
extern int get_event_last (void);

int get_named_event_id (const char *name, enum insert_option insert);






extern void register_callback (const char *plugin_name,
          int event,
                               plugin_callback_func callback,
                               void *user_data);

extern int unregister_callback (const char *plugin_name, int event);
# 24 "../../../src/plugin-utils.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h" 1
# 26 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/machmode.h" 1
# 25 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/machmode.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/insn-modes.h" 1






enum machine_mode
{
  VOIDmode,
  BLKmode,
  CCmode,
  CCGCmode,
  CCGOCmode,
  CCNOmode,
  CCAmode,
  CCCmode,
  CCOmode,
  CCSmode,
  CCZmode,
  CCFPmode,
  CCFPUmode,
  BImode,
  QImode,
  HImode,
  SImode,
  DImode,
  TImode,
  OImode,
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
  SFmode,
  DFmode,
  XFmode,
  TFmode,
  SDmode,
  DDmode,
  TDmode,
  CQImode,
  CHImode,
  CSImode,
  CDImode,
  CTImode,
  COImode,
  SCmode,
  DCmode,
  XCmode,
  TCmode,
  V2QImode,
  V4QImode,
  V2HImode,
  V1SImode,
  V8QImode,
  V4HImode,
  V2SImode,
  V1DImode,
  V16QImode,
  V8HImode,
  V4SImode,
  V2DImode,
  V1TImode,
  V32QImode,
  V16HImode,
  V8SImode,
  V4DImode,
  V2TImode,
  V64QImode,
  V32HImode,
  V16SImode,
  V8DImode,
  V4TImode,
  V2SFmode,
  V4SFmode,
  V2DFmode,
  V8SFmode,
  V4DFmode,
  V2TFmode,
  V16SFmode,
  V8DFmode,
  V4TFmode,
  MAX_MACHINE_MODE,

  MIN_MODE_RANDOM = VOIDmode,
  MAX_MODE_RANDOM = BLKmode,

  MIN_MODE_CC = CCmode,
  MAX_MODE_CC = CCFPUmode,

  MIN_MODE_INT = QImode,
  MAX_MODE_INT = OImode,

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

  MIN_MODE_FLOAT = SFmode,
  MAX_MODE_FLOAT = TFmode,

  MIN_MODE_DECIMAL_FLOAT = SDmode,
  MAX_MODE_DECIMAL_FLOAT = TDmode,

  MIN_MODE_COMPLEX_INT = CQImode,
  MAX_MODE_COMPLEX_INT = COImode,

  MIN_MODE_COMPLEX_FLOAT = SCmode,
  MAX_MODE_COMPLEX_FLOAT = TCmode,

  MIN_MODE_VECTOR_INT = V2QImode,
  MAX_MODE_VECTOR_INT = V4TImode,

  MIN_MODE_VECTOR_FRACT = VOIDmode,
  MAX_MODE_VECTOR_FRACT = VOIDmode,

  MIN_MODE_VECTOR_UFRACT = VOIDmode,
  MAX_MODE_VECTOR_UFRACT = VOIDmode,

  MIN_MODE_VECTOR_ACCUM = VOIDmode,
  MAX_MODE_VECTOR_ACCUM = VOIDmode,

  MIN_MODE_VECTOR_UACCUM = VOIDmode,
  MAX_MODE_VECTOR_UACCUM = VOIDmode,

  MIN_MODE_VECTOR_FLOAT = V2SFmode,
  MAX_MODE_VECTOR_FLOAT = V4TFmode,

  NUM_MACHINE_MODES = MAX_MACHINE_MODE
};
# 26 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/machmode.h" 2



extern const char * const mode_name[NUM_MACHINE_MODES];




# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/mode-classes.def" 1
# 35 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/machmode.h" 2

enum mode_class { MODE_RANDOM, MODE_CC, MODE_INT, MODE_PARTIAL_INT, MODE_FRACT, MODE_UFRACT, MODE_ACCUM, MODE_UACCUM, MODE_FLOAT, MODE_DECIMAL_FLOAT, MODE_COMPLEX_INT, MODE_COMPLEX_FLOAT, MODE_VECTOR_INT, MODE_VECTOR_FRACT, MODE_VECTOR_UFRACT, MODE_VECTOR_ACCUM, MODE_VECTOR_UACCUM, MODE_VECTOR_FLOAT, MAX_MODE_CLASS };






extern const unsigned char mode_class[NUM_MACHINE_MODES];
# 179 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/machmode.h"
extern unsigned char mode_size[NUM_MACHINE_MODES];




extern const unsigned short mode_precision[NUM_MACHINE_MODES];



extern const unsigned char mode_ibit[NUM_MACHINE_MODES];



extern const unsigned char mode_fbit[NUM_MACHINE_MODES];





extern const unsigned long mode_mask_array[NUM_MACHINE_MODES];





extern const unsigned char mode_inner[NUM_MACHINE_MODES];
# 216 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/machmode.h"
extern const unsigned char mode_nunits[NUM_MACHINE_MODES];




extern const unsigned char mode_wider[NUM_MACHINE_MODES];


extern const unsigned char mode_2xwider[NUM_MACHINE_MODES];






extern enum machine_mode mode_for_size (unsigned int, enum mode_class, int);



extern enum machine_mode smallest_mode_for_size (unsigned int,
       enum mode_class);





extern enum machine_mode int_mode_for_mode (enum machine_mode);



extern enum machine_mode get_best_mode (int, int, unsigned int,
     enum machine_mode, int);



extern unsigned char mode_base_align[NUM_MACHINE_MODES];

extern unsigned get_mode_alignment (enum machine_mode);





extern const unsigned char class_narrowest_mode[MAX_MODE_CLASS];






extern enum machine_mode byte_mode;
extern enum machine_mode word_mode;
extern enum machine_mode ptr_mode;


extern void init_adjust_machine_modes (void);
# 27 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/input.h" 1
# 25 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/input.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/line-map.h" 1
# 36 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/line-map.h"
enum lc_reason {LC_ENTER = 0, LC_LEAVE, LC_RENAME, LC_RENAME_VERBATIM};


typedef unsigned int linenum_type;




typedef unsigned int source_location;


typedef void *(*line_map_realloc) (void *, size_t);
# 61 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/line-map.h"
struct line_map {
  const char *to_file;
  linenum_type to_line;
  source_location start_location;
  int included_from;
  __extension__ enum lc_reason reason : 8;

  unsigned char sysp;

  unsigned int column_bits : 8;
};


struct line_maps {
  struct line_map * maps;
  unsigned int allocated;
  unsigned int used;

  unsigned int cache;




  int last_listed;


  unsigned int depth;


  unsigned char trace_includes;


  source_location highest_location;


  source_location highest_line;



  unsigned int max_column_hint;



  line_map_realloc reallocator;
};


extern void linemap_init (struct line_maps *);


extern void linemap_free (struct line_maps *);



extern void linemap_check_files_exited (struct line_maps *);







extern source_location linemap_line_start
(struct line_maps *set, linenum_type to_line, unsigned int max_column_hint);
# 137 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/line-map.h"
extern const struct line_map *linemap_add
  (struct line_maps *, enum lc_reason, unsigned int sysp,
   const char *to_file, linenum_type to_line);



extern const struct line_map *linemap_lookup
  (struct line_maps *, source_location);
# 192 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/line-map.h"
extern source_location
linemap_position_for_column (struct line_maps *set, unsigned int to_column);
# 26 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/input.h" 2

extern struct line_maps *line_table;
# 37 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/input.h"
extern char builtins_location_check[(((source_location) 1)
         < 2) ? 1 : -1];

typedef struct
{

  const char *file;


  int line;

  int column;


  unsigned char sysp;
} expanded_location;

extern expanded_location expand_location (source_location);



typedef source_location location_t;


extern const char *main_input_filename;

extern location_t input_location;
# 28 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/statistics.h" 1
# 41 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/statistics.h"
struct function;


extern void statistics_early_init (void);
extern void statistics_init (void);
extern void statistics_fini (void);
extern void statistics_fini_pass (void);
extern void statistics_counter_event (struct function *, const char *, int);
extern void statistics_histogram_event (struct function *, const char *, int);
# 29 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/vec.h" 1
# 421 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/vec.h"
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
# 1225 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/vec.h"
extern void *vec_stack_p_reserve (void *, int );
extern void *vec_stack_p_reserve_exact (void *, int );
extern void *vec_stack_p_reserve_exact_1 (int, void *);
extern void *vec_stack_o_reserve (void *, int, size_t, size_t );
extern void *vec_stack_o_reserve_exact (void *, int, size_t, size_t
      );
extern void vec_stack_free (void *);
# 30 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/double-int.h" 1
# 24 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/double-int.h"
# 1 "/usr/include/gmp.h" 1 3 4
# 43 "/usr/include/gmp.h" 3 4
# 1 "./include/gmp-i386.h" 1 3 4
# 53 "./include/gmp-i386.h" 3 4
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/include/stddef.h" 1 3 4
# 54 "./include/gmp-i386.h" 2 3 4
# 194 "./include/gmp-i386.h" 3 4
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
# 542 "./include/gmp-i386.h" 3 4
 void __gmp_set_memory_functions (void *(*) (size_t), void *(*) (void *, size_t, size_t), void (*) (void *, size_t))

                                                   ;


 void __gmp_get_memory_functions (void *(**) (size_t), void *(**) (void *, size_t, size_t), void (**) (void *, size_t))

                                                                                ;


 extern const int __gmp_bits_per_limb;


 extern int __gmp_errno;


 extern const char * const __gmp_version;






 void __gmp_randinit (gmp_randstate_t, gmp_randalg_t, ...);


 void __gmp_randinit_default (gmp_randstate_t);


 void __gmp_randinit_lc_2exp (gmp_randstate_t, mpz_srcptr, unsigned long int, unsigned long int)

                          ;


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
# 621 "./include/gmp-i386.h" 3 4
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
# 1480 "./include/gmp-i386.h" 3 4
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
# 1632 "./include/gmp-i386.h" 3 4
extern __inline__ void
__gmpz_abs (mpz_ptr __gmp_w, mpz_srcptr __gmp_u)
{
  if (__gmp_w != __gmp_u)
    __gmpz_set (__gmp_w, __gmp_u);
  __gmp_w->_mp_size = ((__gmp_w->_mp_size) >= 0 ? (__gmp_w->_mp_size) : -(__gmp_w->_mp_size));
}
# 1656 "./include/gmp-i386.h" 3 4
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
# 1712 "./include/gmp-i386.h" 3 4
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
# 2054 "./include/gmp-i386.h" 3 4
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
# 2211 "./include/gmp-i386.h" 3 4
enum
{
  GMP_ERROR_NONE = 0,
  GMP_ERROR_UNSUPPORTED_ARGUMENT = 1,
  GMP_ERROR_DIVISION_BY_ZERO = 2,
  GMP_ERROR_SQRT_OF_NEGATIVE = 4,
  GMP_ERROR_INVALID_ARGUMENT = 8
};
# 44 "/usr/include/gmp.h" 2 3 4
# 25 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/double-int.h" 2

# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/coretypes.h" 1
# 46 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/coretypes.h"
struct bitmap_head_def;
typedef struct bitmap_head_def *bitmap;
typedef const struct bitmap_head_def *const_bitmap;
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
struct cl_target_option;
struct cl_optimization;
struct gimple_seq_d;
typedef struct gimple_seq_d *gimple_seq;
typedef const struct gimple_seq_d *const_gimple_seq;
struct gimple_seq_node_d;
typedef struct gimple_seq_node_d *gimple_seq_node;
typedef const struct gimple_seq_node_d *const_gimple_seq_node;


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

struct edge_def;
typedef struct edge_def *edge;
typedef const struct edge_def *const_edge;
struct basic_block_def;
typedef struct basic_block_def *basic_block;
typedef const struct basic_block_def *const_basic_block;
# 27 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/double-int.h" 2
# 54 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/double-int.h"
typedef struct
{
  unsigned long low;
  long high;
} double_int;

union tree_node;



union tree_node *double_int_to_tree (union tree_node *, double_int);
unsigned char double_int_fits_to_tree_p (const union tree_node *, double_int);
double_int tree_to_double_int (const union tree_node *);




static __inline__ double_int
shwi_to_double_int (long cst)
{
  double_int r;

  r.low = (unsigned long) cst;
  r.high = cst < 0 ? -1 : 0;

  return r;
}
# 93 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/double-int.h"
static __inline__ double_int
uhwi_to_double_int (unsigned long cst)
{
  double_int r;

  r.low = cst;
  r.high = 0;

  return r;
}






double_int double_int_mul (double_int, double_int);
double_int double_int_add (double_int, double_int);
double_int double_int_neg (double_int);




unsigned char double_int_fits_in_hwi_p (double_int, unsigned char);
unsigned char double_int_fits_in_shwi_p (double_int);
unsigned char double_int_fits_in_uhwi_p (double_int);
long double_int_to_shwi (double_int);
unsigned long double_int_to_uhwi (double_int);
double_int double_int_div (double_int, double_int, unsigned char, unsigned);
double_int double_int_sdiv (double_int, double_int, unsigned);
double_int double_int_udiv (double_int, double_int, unsigned);
double_int double_int_mod (double_int, double_int, unsigned char, unsigned);
double_int double_int_smod (double_int, double_int, unsigned);
double_int double_int_umod (double_int, double_int, unsigned);
double_int double_int_divmod (double_int, double_int, unsigned char, unsigned, double_int *);
double_int double_int_sdivmod (double_int, double_int, unsigned, double_int *);
double_int double_int_udivmod (double_int, double_int, unsigned, double_int *);
unsigned char double_int_negative_p (double_int);
int double_int_cmp (double_int, double_int, unsigned char);
int double_int_scmp (double_int, double_int);
int double_int_ucmp (double_int, double_int);
void dump_double_int (FILE *, double_int, unsigned char);



double_int double_int_ext (double_int, unsigned, unsigned char);
double_int double_int_sext (double_int, unsigned);
double_int double_int_zext (double_int, unsigned);
double_int double_int_mask (unsigned);
# 151 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/double-int.h"
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
  return (cst.low == (~((unsigned long) 0)) && cst.high == -1);
}



static __inline__ unsigned char
double_int_equal_p (double_int cst1, double_int cst2)
{
  return cst1.low == cst2.low && cst1.high == cst2.high;
}




void mpz_set_double_int (mpz_t, double_int, unsigned char);
double_int mpz_get_double_int (const_tree, mpz_t, unsigned char);
# 31 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/alias.h" 1
# 31 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/alias.h"
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
extern int nonoverlapping_memrefs_p (const_rtx, const_rtx);
extern unsigned char insn_alias_sets_conflict_p (rtx, rtx);
# 32 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/options.h" 1





extern int target_flags;
extern int target_flags_explicit;

extern int extra_warnings;
extern int warn_abi;
extern int warn_address;
extern int warn_aggregate_return;
extern int warn_array_bounds;
extern int warn_assign_intercept;
extern int warn_attributes;
extern int warn_bad_function_cast;
extern int warn_cxx_compat;
extern int warn_cxx0x_compat;
extern int warn_cast_align;
extern int warn_cast_qual;
extern int warn_char_subscripts;
extern int warn_clobbered;
extern int warn_conversion;
extern int warn_conversion_null;
extern int warn_coverage_mismatch;
extern int warn_ctor_dtor_privacy;
extern int warn_declaration_after_statement;
extern int warn_deprecated;
extern int warn_deprecated_decl;
extern int warn_disabled_optimization;
extern int warn_div_by_zero;
extern int warn_ecpp;
extern int warn_empty_body;
extern int warn_enum_compare;
extern int warnings_are_errors;
extern int flag_extraneous_semicolon;
extern int flag_fatal_errors;
extern int warn_float_equal;
extern int warn_format_contains_nul;
extern int warn_format_extra_args;
extern int warn_format_nonliteral;
extern int warn_format_security;
extern int warn_format_y2k;
extern int warn_format_zero_length;
extern int warn_ignored_qualifiers;
extern int warn_implicit_function_declaration;
extern int warn_implicit_int;
extern int warn_init_self;
extern int warn_inline;
extern int warn_int_to_pointer_cast;
extern int warn_invalid_offsetof;
extern int warn_jump_misses_init;
extern int warn_logical_op;
extern int warn_long_long;
extern int warn_main;
extern int warn_missing_braces;
extern int warn_missing_declarations;
extern int warn_missing_field_initializers;
extern int warn_missing_format_attribute;
extern int warn_missing_noreturn;
extern int warn_missing_parameter_type;
extern int warn_missing_prototypes;
extern int warn_mudflap;
extern int warn_nested_externs;
extern int warn_nontemplate_friend;
extern int warn_nonvdtor;
extern int warn_nonnull;
extern int warn_old_style_cast;
extern int warn_old_style_declaration;
extern int warn_old_style_definition;
extern int flag_newer;
extern int warn_overflow;
extern int warn_overlength_strings;
extern int warn_overloaded_virtual;
extern int warn_override_init;
extern int warn_packed;
extern int warn_packed_bitfield_compat;
extern int warn_padded;
extern int warn_parentheses;
extern int warn_pmf2ptr;
extern int warn_pointer_arith;
extern int warn_pointer_sign;
extern int warn_pointer_to_int_cast;
extern int warn_pragmas;
extern int warn_protocol;
extern int warn_psabi;
extern int warn_redundant_decls;
extern int flag_redundant;
extern int warn_reorder;
extern int warn_return_type;
extern int warn_selector;
extern int warn_sequence_point;
extern int warn_shadow;
extern int warn_sign_compare;
extern int warn_sign_conversion;
extern int warn_sign_promo;
extern int warn_stack_protect;
extern int warn_strict_aliasing;
extern int warn_strict_overflow;
extern int warn_strict_prototypes;
extern int warn_strict_selector_match;
extern int warn_switch;
extern int warn_switch_default;
extern int warn_switch_enum;
extern int warn_sync_nand;
extern int warn_synth;
extern int warn_system_headers;
extern int warn_traditional;
extern int warn_traditional_conversion;
extern int warn_type_limits;
extern int warn_undeclared_selector;
extern int warn_uninitialized;
extern int warn_unsafe_loop_optimizations;
extern int warn_unsuffixed_float_constants;
extern int warn_unused;
extern int warn_unused_function;
extern int warn_unused_label;
extern int warn_unused_parameter;
extern int warn_unused_result;
extern int warn_unused_value;
extern int warn_unused_variable;
extern int warn_vla;
extern int warn_volatile_register_var;
extern int warn_write_strings;
extern int flag_pic;
extern int flag_pie;
extern int flag_abi_version;
extern int align_functions;
extern int align_jumps;
extern int align_labels;
extern int align_loops;
extern int flag_argument_noalias;
extern int flag_assert;
extern int flag_associative_math;
extern int flag_asynchronous_unwind_tables;
extern int flag_auto_inc_dec;
extern int flag_bootstrap_classes;
extern int flag_bounds_check;
extern int flag_branch_on_count_reg;
extern int flag_branch_probabilities;
extern int flag_branch_target_load_optimize;
extern int flag_branch_target_load_optimize2;
extern int flag_btr_bb_exclusive;
extern int flag_caller_saves;
extern int flag_check_data_deps;
extern int flag_check_references;
extern int flag_no_common;
extern int flag_compare_debug;
extern const char *flag_compare_debug_opt;
extern int flag_conserve_stack;
extern int flag_cprop_registers;
extern int flag_crossjumping;
extern int flag_cse_follow_jumps;
extern int flag_cx_fortran_rules;
extern int flag_cx_limited_range;
extern int flag_data_sections;
extern int flag_dce;
extern int flag_deduce_init_list;
extern int flag_defer_pop;
extern int flag_delayed_branch;
extern int flag_delete_null_pointer_checks;
extern int flag_dse;
extern const char *flag_dump_final_insns;
extern int flag_dump_noaddr;
extern int flag_dump_unnumbered;
extern int flag_dump_unnumbered_links;
extern int flag_dwarf2_cfi_asm;
extern int flag_early_inlining;
extern int flag_eliminate_dwarf2_dups;
extern int flag_debug_only_used_symbols;
extern int flag_eliminate_unused_debug_types;
extern int flag_emit_class_debug_always;
extern int flag_emit_class_files;
extern int flag_enable_icf_debug;
extern int flag_exceptions;
extern int flag_expensive_optimizations;
extern int flag_filelist_file;
extern int flag_finite_math_only;
extern int flag_float_store;
extern int flag_force_classes_archive_check;
extern int flag_forward_propagate;
extern int flag_friend_injection;
extern int flag_no_function_cse;
extern int flag_function_sections;
extern int flag_gcse;
extern int flag_gcse_after_reload;
extern int flag_gcse_las;
extern int flag_gcse_lm;
extern int flag_gcse_sm;
extern int flag_gnu89_inline;
extern int flag_graphite;
extern int flag_graphite_identity;
extern int flag_guess_branch_prob;
extern int flag_hash_synchronization;
extern int help_flag;
extern int flag_no_ident;
extern int flag_if_conversion;
extern int flag_if_conversion2;
extern int flag_indirect_classes;
extern int flag_indirect_dispatch;
extern int flag_indirect_inlining;
extern int flag_inhibit_size_directive;
extern int flag_no_inline;
extern int flag_inline_functions;
extern int flag_inline_functions_called_once;
extern int flag_inline_small_functions;
extern int flag_instrument_function_entry_exit;
extern int flag_ipa_cp;
extern int flag_ipa_cp_clone;
extern int flag_ipa_matrix_reorg;
extern int flag_ipa_pta;
extern int flag_ipa_pure_const;
extern int flag_ipa_reference;
extern int flag_ipa_sra;
extern int flag_ipa_struct_reorg;
extern int flag_ipa_type_escape;
extern int flag_ira_coalesce;
extern int flag_ira_loop_pressure;
extern int flag_ira_share_save_slots;
extern int flag_ira_share_spill_slots;
extern int flag_ivopts;
extern int flag_jni;
extern int flag_jump_tables;
extern int flag_keep_inline_functions;
extern int flag_keep_static_consts;
extern int flag_leading_underscore;
extern int flag_loop_block;
extern int flag_loop_interchange;
extern int flag_loop_parallelize_all;
extern int flag_loop_strip_mine;
extern int flag_lto;
extern int flag_lto_compression_level;
extern int flag_lto_report;
extern int flag_ltrans;
extern const char *ltrans_output_list;
extern int flag_errno_math;
extern int mem_report;
extern int flag_merge_constants;
extern int flag_merge_debug_strings;
extern int flag_modulo_sched;
extern int flag_modulo_sched_allow_regmoves;
extern int flag_move_loop_invariants;
extern int flag_mudflap;
extern int flag_mudflap_ignore_reads;
extern int flag_non_call_exceptions;
extern int flag_objc_call_cxx_cdtors;
extern int flag_objc_direct_dispatch;
extern int flag_objc_exceptions;
extern int flag_objc_gc;
extern int flag_objc_sjlj_exceptions;
extern int flag_omit_frame_pointer;
extern int flag_openmp;
extern int flag_regmove;
extern int flag_optimize_sibling_calls;
extern int flag_optimize_sci;
extern int flag_pack_struct;
extern int flag_pcc_struct_return;
extern int flag_peel_loops;
extern int flag_no_peephole;
extern int flag_peephole2;
extern int post_ipa_mem_report;
extern int pre_ipa_mem_report;
extern int flag_predictive_commoning;
extern int flag_prefetch_loop_arrays;
extern int profile_flag;
extern int profile_arc_flag;
extern int flag_profile_correction;
extern int flag_profile_use;
extern int flag_profile_values;
extern int flag_reciprocal_math;
extern int flag_record_gcc_switches;
extern int flag_reduced_reflection;
extern int flag_rename_registers;
extern int flag_reorder_blocks;
extern int flag_reorder_blocks_and_partition;
extern int flag_reorder_functions;
extern int flag_rerun_cse_after_loop;
extern int flag_resched_modulo_sched;
extern int flag_rounding_math;
extern int flag_sched_critical_path_heuristic;
extern int flag_sched_dep_count_heuristic;
extern int flag_sched_group_heuristic;
extern int flag_schedule_interblock;
extern int flag_sched_last_insn_heuristic;
extern int flag_sched_pressure;
extern int flag_sched_rank_heuristic;
extern int flag_schedule_speculative;
extern int flag_sched_spec_insn_heuristic;
extern int flag_schedule_speculative_load;
extern int flag_schedule_speculative_load_dangerous;
extern int flag_sched_stalled_insns;
extern int flag_sched_stalled_insns_dep;
extern int flag_sched2_use_superblocks;
extern int flag_schedule_insns;
extern int flag_schedule_insns_after_reload;
extern int flag_section_anchors;
extern int flag_sel_sched_pipelining;
extern int flag_sel_sched_pipelining_outer_loops;
extern int flag_sel_sched_reschedule_pipelined;
extern int flag_selective_scheduling;
extern int flag_selective_scheduling2;
extern int flag_show_column;
extern int flag_signaling_nans;
extern int flag_signed_zeros;
extern int flag_single_precision_constant;
extern int flag_split_ivs_in_unroller;
extern int flag_split_wide_types;
extern int flag_stack_protect;
extern int flag_store_check;
extern int flag_strict_aliasing;
extern int flag_strict_overflow;
extern int flag_syntax_only;
extern int flag_test_coverage;
extern int flag_thread_jumps;
extern int time_report;
extern int flag_toplevel_reorder;
extern int flag_tracer;
extern int flag_trapping_math;
extern int flag_trapv;
extern int flag_tree_builtin_call_dce;
extern int flag_tree_ccp;
extern int flag_tree_ch;
extern int flag_tree_copy_prop;
extern int flag_tree_copyrename;
extern int flag_tree_cselim;
extern int flag_tree_dce;
extern int flag_tree_dom;
extern int flag_tree_dse;
extern int flag_tree_forwprop;
extern int flag_tree_fre;
extern int flag_tree_loop_distribution;
extern int flag_tree_loop_im;
extern int flag_tree_loop_ivcanon;
extern int flag_tree_loop_linear;
extern int flag_tree_loop_optimize;
extern int flag_tree_live_range_split;
extern int flag_tree_parallelize_loops;
extern int flag_tree_phiprop;
extern int flag_tree_pre;
extern int flag_tree_pta;
extern int flag_tree_reassoc;
extern int flag_tree_scev_cprop;
extern int flag_tree_sink;
extern int flag_tree_slp_vectorize;
extern int flag_tree_sra;
extern int flag_tree_switch_conversion;
extern int flag_tree_ter;
extern int flag_tree_vect_loop_version;
extern int flag_tree_vectorize;
extern int flag_tree_vrp;
extern int flag_unit_at_a_time;
extern int flag_unroll_all_loops;
extern int flag_unroll_loops;
extern int flag_unsafe_loop_optimizations;
extern int flag_unsafe_math_optimizations;
extern int flag_unswitch_loops;
extern int flag_unwind_tables;
extern int flag_use_atomic_builtins;
extern int flag_use_boehm_gc;
extern int flag_use_divide_subroutine;
extern int flag_var_tracking;
extern int flag_var_tracking_assignments;
extern int flag_var_tracking_assignments_toggle;
extern int flag_var_tracking_uninit;
extern int flag_variable_expansion_in_unroller;
extern int flag_vect_cost_model;
extern int flag_verbose_asm;
extern int flag_visibility_ms_compat;
extern int flag_value_profile_transformations;
extern int flag_web;
extern int flag_whole_program;
extern int flag_whopr;
extern int flag_wpa;
extern int flag_wrapv;
extern int flag_zero_initialized_in_bss;
extern int dwarf_version;
extern int dwarf_strict;
extern int flag_gtoggle;
extern int ix86_isa_flags;
extern const char *ix86_abi_string;
extern const char *ix86_align_funcs_string;
extern const char *ix86_align_jumps_string;
extern const char *ix86_align_loops_string;
extern const char *ix86_arch_string;
extern const char *ix86_asm_string;
extern const char *ix86_branch_cost_string;
extern const char *ix86_cmodel_string;
extern int ix86_force_drap;
extern const char *ix86_fpmath_string;
extern int linux_uclibc;
extern const char *ix86_incoming_stack_boundary_string;
extern const char *ix86_section_threshold_string;
extern const char *ix87_precision_string;
extern const char *ix86_preferred_stack_boundary_string;
extern const char *ix86_regparm_string;
extern int ix86_sse2avx;
extern int ix86_force_align_arg_pointer;
extern const char *ix86_stringop_string;
extern const char *ix86_tls_dialect_string;
extern const char *ix86_tune_string;
extern const char *ix86_veclibabi_string;
extern int pedantic;
extern int quiet_flag;
extern int version_flag;
extern int inhibit_warnings;




struct cl_optimization
{
  int align_functions;
  int align_jumps;
  int align_labels;
  int align_loops;
  int flag_sched_stalled_insns;
  int flag_sched_stalled_insns_dep;
  unsigned char optimize;
  unsigned char optimize_size;
  signed char flag_argument_noalias;
  signed char flag_asynchronous_unwind_tables;
  signed char flag_branch_on_count_reg;
  signed char flag_branch_probabilities;
  signed char flag_branch_target_load_optimize;
  signed char flag_branch_target_load_optimize2;
  signed char flag_btr_bb_exclusive;
  signed char flag_caller_saves;
  signed char flag_no_common;
  signed char flag_conserve_stack;
  signed char flag_cprop_registers;
  signed char flag_crossjumping;
  signed char flag_cse_follow_jumps;
  signed char flag_cx_fortran_rules;
  signed char flag_cx_limited_range;
  signed char flag_data_sections;
  signed char flag_dce;
  signed char flag_defer_pop;
  signed char flag_delayed_branch;
  signed char flag_delete_null_pointer_checks;
  signed char flag_dse;
  signed char flag_early_inlining;
  signed char flag_exceptions;
  signed char flag_expensive_optimizations;
  signed char flag_finite_math_only;
  signed char flag_float_store;
  signed char flag_forward_propagate;
  signed char flag_gcse;
  signed char flag_gcse_after_reload;
  signed char flag_gcse_las;
  signed char flag_gcse_lm;
  signed char flag_gcse_sm;
  signed char flag_graphite_identity;
  signed char flag_guess_branch_prob;
  signed char flag_if_conversion;
  signed char flag_if_conversion2;
  signed char flag_inline_functions;
  signed char flag_inline_functions_called_once;
  signed char flag_inline_small_functions;
  signed char flag_ipa_cp;
  signed char flag_ipa_cp_clone;
  signed char flag_ipa_matrix_reorg;
  signed char flag_ipa_pta;
  signed char flag_ipa_pure_const;
  signed char flag_ipa_reference;
  signed char flag_ipa_sra;
  signed char flag_ipa_type_escape;
  signed char flag_ivopts;
  signed char flag_jump_tables;
  signed char flag_loop_block;
  signed char flag_loop_interchange;
  signed char flag_loop_parallelize_all;
  signed char flag_loop_strip_mine;
  signed char flag_lto_report;
  signed char flag_ltrans;
  signed char flag_errno_math;
  signed char flag_merge_constants;
  signed char flag_modulo_sched;
  signed char flag_move_loop_invariants;
  signed char flag_non_call_exceptions;
  signed char flag_omit_frame_pointer;
  signed char flag_regmove;
  signed char flag_optimize_sibling_calls;
  signed char flag_pack_struct;
  signed char flag_peel_loops;
  signed char flag_no_peephole;
  signed char flag_peephole2;
  signed char flag_predictive_commoning;
  signed char flag_prefetch_loop_arrays;
  signed char flag_pcc_struct_return;
  signed char flag_rename_registers;
  signed char flag_reorder_blocks;
  signed char flag_reorder_blocks_and_partition;
  signed char flag_reorder_functions;
  signed char flag_rerun_cse_after_loop;
  signed char flag_resched_modulo_sched;
  signed char flag_rounding_math;
  signed char flag_sched_critical_path_heuristic;
  signed char flag_sched_dep_count_heuristic;
  signed char flag_sched_group_heuristic;
  signed char flag_schedule_interblock;
  signed char flag_sched_last_insn_heuristic;
  signed char flag_sched_pressure;
  signed char flag_sched_rank_heuristic;
  signed char flag_schedule_speculative;
  signed char flag_sched_spec_insn_heuristic;
  signed char flag_schedule_speculative_load;
  signed char flag_schedule_speculative_load_dangerous;
  signed char flag_sched2_use_superblocks;
  signed char flag_schedule_insns;
  signed char flag_schedule_insns_after_reload;
  signed char flag_section_anchors;
  signed char flag_sel_sched_pipelining;
  signed char flag_sel_sched_pipelining_outer_loops;
  signed char flag_sel_sched_reschedule_pipelined;
  signed char flag_selective_scheduling;
  signed char flag_selective_scheduling2;
  signed char flag_signaling_nans;
  signed char flag_signed_zeros;
  signed char flag_single_precision_constant;
  signed char flag_split_ivs_in_unroller;
  signed char flag_split_wide_types;
  signed char flag_strict_aliasing;
  signed char flag_thread_jumps;
  signed char flag_toplevel_reorder;
  signed char flag_trapping_math;
  signed char flag_trapv;
  signed char flag_tree_builtin_call_dce;
  signed char flag_tree_ccp;
  signed char flag_tree_ch;
  signed char flag_tree_copy_prop;
  signed char flag_tree_copyrename;
  signed char flag_tree_cselim;
  signed char flag_tree_dce;
  signed char flag_tree_dom;
  signed char flag_tree_dse;
  signed char flag_tree_forwprop;
  signed char flag_tree_fre;
  signed char flag_tree_loop_distribution;
  signed char flag_tree_loop_im;
  signed char flag_tree_loop_ivcanon;
  signed char flag_tree_loop_linear;
  signed char flag_tree_loop_optimize;
  signed char flag_tree_live_range_split;
  signed char flag_tree_phiprop;
  signed char flag_tree_pre;
  signed char flag_tree_pta;
  signed char flag_tree_reassoc;
  signed char flag_tree_scev_cprop;
  signed char flag_tree_sink;
  signed char flag_tree_slp_vectorize;
  signed char flag_tree_sra;
  signed char flag_tree_switch_conversion;
  signed char flag_tree_ter;
  signed char flag_tree_vect_loop_version;
  signed char flag_tree_vectorize;
  signed char flag_tree_vrp;
  signed char flag_unit_at_a_time;
  signed char flag_unroll_all_loops;
  signed char flag_unroll_loops;
  signed char flag_unsafe_loop_optimizations;
  signed char flag_unsafe_math_optimizations;
  signed char flag_unswitch_loops;
  signed char flag_unwind_tables;
  signed char flag_var_tracking;
  signed char flag_var_tracking_assignments;
  signed char flag_var_tracking_assignments_toggle;
  signed char flag_var_tracking_uninit;
  signed char flag_variable_expansion_in_unroller;
  signed char flag_vect_cost_model;
  signed char flag_value_profile_transformations;
  signed char flag_web;
  signed char flag_whole_program;
  signed char flag_wpa;
  signed char flag_wrapv;
};


struct cl_target_option
{
  int ix86_isa_flags_explicit;
  int target_flags_explicit;
  int target_flags;
  int ix86_isa_flags;
  unsigned char arch;
  unsigned char arch_specified;
  unsigned char branch_cost;
  unsigned char fpmath;
  unsigned char schedule;
  unsigned char tune;
  unsigned char tune_defaulted;
};



extern void cl_optimization_save (struct cl_optimization *);


extern void cl_optimization_restore (struct cl_optimization *);


extern void cl_optimization_print (FILE *, int, struct cl_optimization *);


extern void cl_target_option_save (struct cl_target_option *);


extern void cl_target_option_restore (struct cl_target_option *);


extern void cl_target_option_print (FILE *, int, struct cl_target_option *);
# 723 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/options.h"
enum opt_code
{
  OPT__help,
  OPT__help_,
  OPT__output_pch_,
  OPT__param,
  OPT__target_help,
  OPT__version,
  OPT_A,
  OPT_C,
  OPT_CC,
  OPT_D,
  OPT_E,
  OPT_F,
  OPT_G,
  OPT_H,
  OPT_I,
  OPT_J,
  OPT_M,
  OPT_MD,
  OPT_MD_,
  OPT_MF,
  OPT_MG,
  OPT_MM,
  OPT_MMD,
  OPT_MMD_,
  OPT_MP,
  OPT_MQ,
  OPT_MT,
  OPT_O,
  OPT_Os,
  OPT_P,
  OPT_U,
  OPT_W,
  OPT_Wabi,
  OPT_Waddress,
  OPT_Waggregate_return,
  OPT_Waliasing,
  OPT_Walign_commons,
  OPT_Wall,
  OPT_Wall_deprecation,
  OPT_Wall_javadoc,
  OPT_Wampersand,
  OPT_Warray_bounds,
  OPT_Warray_temporaries,
  OPT_Wassert_identifier,
  OPT_Wassign_intercept,
  OPT_Wattributes,
  OPT_Wbad_function_cast,
  OPT_Wboxing,
  OPT_Wbuiltin_macro_redefined,
  OPT_Wc___compat,
  OPT_Wc__0x_compat,
  OPT_Wcast_align,
  OPT_Wcast_qual,
  OPT_Wchar_concat,
  OPT_Wchar_subscripts,
  OPT_Wcharacter_truncation,
  OPT_Wclobbered,
  OPT_Wcomment,
  OPT_Wcomments,
  OPT_Wcondition_assign,
  OPT_Wconstructor_name,
  OPT_Wconversion,
  OPT_Wconversion_null,
  OPT_Wcoverage_mismatch,
  OPT_Wctor_dtor_privacy,
  OPT_Wdeclaration_after_statement,
  OPT_Wdep_ann,
  OPT_Wdeprecated,
  OPT_Wdeprecated_declarations,
  OPT_Wdisabled_optimization,
  OPT_Wdiscouraged,
  OPT_Wdiv_by_zero,
  OPT_Weffc__,
  OPT_Wempty_block,
  OPT_Wempty_body,
  OPT_Wendif_labels,
  OPT_Wenum_compare,
  OPT_Wenum_identifier,
  OPT_Wenum_switch,
  OPT_Werror,
  OPT_Werror_implicit_function_declaration,
  OPT_Werror_,
  OPT_Wextra,
  OPT_Wextraneous_semicolon,
  OPT_Wfallthrough,
  OPT_Wfatal_errors,
  OPT_Wfield_hiding,
  OPT_Wfinal_bound,
  OPT_Wfinally,
  OPT_Wfloat_equal,
  OPT_Wforbidden,
  OPT_Wformat,
  OPT_Wformat_contains_nul,
  OPT_Wformat_extra_args,
  OPT_Wformat_nonliteral,
  OPT_Wformat_security,
  OPT_Wformat_y2k,
  OPT_Wformat_zero_length,
  OPT_Wformat_,
  OPT_Wframe_larger_than_,
  OPT_Whiding,
  OPT_Wignored_qualifiers,
  OPT_Wimplicit,
  OPT_Wimplicit_function_declaration,
  OPT_Wimplicit_int,
  OPT_Wimplicit_interface,
  OPT_Wimplicit_procedure,
  OPT_Wimport,
  OPT_Windirect_static,
  OPT_Winit_self,
  OPT_Winline,
  OPT_Wint_to_pointer_cast,
  OPT_Wintf_annotation,
  OPT_Wintf_non_inherited,
  OPT_Wintrinsic_shadow,
  OPT_Wintrinsics_std,
  OPT_Winvalid_offsetof,
  OPT_Winvalid_pch,
  OPT_Wjavadoc,
  OPT_Wjump_misses_init,
  OPT_Wlarger_than_,
  OPT_Wlarger_than_eq,
  OPT_Wline_truncation,
  OPT_Wlocal_hiding,
  OPT_Wlogical_op,
  OPT_Wlong_long,
  OPT_Wmain,
  OPT_Wmasked_catch_block,
  OPT_Wmissing_braces,
  OPT_Wmissing_declarations,
  OPT_Wmissing_field_initializers,
  OPT_Wmissing_format_attribute,
  OPT_Wmissing_include_dirs,
  OPT_Wmissing_noreturn,
  OPT_Wmissing_parameter_type,
  OPT_Wmissing_prototypes,
  OPT_Wmudflap,
  OPT_Wmultichar,
  OPT_Wnested_externs,
  OPT_Wnls,
  OPT_Wno_effect_assign,
  OPT_Wnon_template_friend,
  OPT_Wnon_virtual_dtor,
  OPT_Wnonnull,
  OPT_Wnormalized_,
  OPT_Wnull,
  OPT_Wold_style_cast,
  OPT_Wold_style_declaration,
  OPT_Wold_style_definition,
  OPT_Wout_of_date,
  OPT_Wover_ann,
  OPT_Woverflow,
  OPT_Woverlength_strings,
  OPT_Woverloaded_virtual,
  OPT_Woverride_init,
  OPT_Wpacked,
  OPT_Wpacked_bitfield_compat,
  OPT_Wpadded,
  OPT_Wparam_assign,
  OPT_Wparentheses,
  OPT_Wpkg_default_method,
  OPT_Wpmf_conversions,
  OPT_Wpointer_arith,
  OPT_Wpointer_sign,
  OPT_Wpointer_to_int_cast,
  OPT_Wpragmas,
  OPT_Wprotocol,
  OPT_Wpsabi,
  OPT_Wraw,
  OPT_Wredundant_decls,
  OPT_Wredundant_modifiers,
  OPT_Wreorder,
  OPT_Wreturn_type,
  OPT_Wselector,
  OPT_Wsequence_point,
  OPT_Wserial,
  OPT_Wshadow,
  OPT_Wsign_compare,
  OPT_Wsign_conversion,
  OPT_Wsign_promo,
  OPT_Wspecial_param_hiding,
  OPT_Wstack_protector,
  OPT_Wstatic_access,
  OPT_Wstatic_receiver,
  OPT_Wstrict_aliasing,
  OPT_Wstrict_aliasing_,
  OPT_Wstrict_null_sentinel,
  OPT_Wstrict_overflow,
  OPT_Wstrict_overflow_,
  OPT_Wstrict_prototypes,
  OPT_Wstrict_selector_match,
  OPT_Wsuppress,
  OPT_Wsurprising,
  OPT_Wswitch,
  OPT_Wswitch_default,
  OPT_Wswitch_enum,
  OPT_Wsync_nand,
  OPT_Wsynth,
  OPT_Wsynthetic_access,
  OPT_Wsystem_headers,
  OPT_Wtabs,
  OPT_Wtasks,
  OPT_Wtraditional,
  OPT_Wtraditional_conversion,
  OPT_Wtrigraphs,
  OPT_Wtype_hiding,
  OPT_Wtype_limits,
  OPT_Wuncheck,
  OPT_Wundeclared_selector,
  OPT_Wundef,
  OPT_Wunderflow,
  OPT_Wuninitialized,
  OPT_Wunknown_pragmas,
  OPT_Wunnecessary_else,
  OPT_Wunqualified_field,
  OPT_Wunreachable_code,
  OPT_Wunsafe_loop_optimizations,
  OPT_Wunsuffixed_float_constants,
  OPT_Wunused,
  OPT_Wunused_argument,
  OPT_Wunused_function,
  OPT_Wunused_import,
  OPT_Wunused_label,
  OPT_Wunused_local,
  OPT_Wunused_macros,
  OPT_Wunused_parameter,
  OPT_Wunused_private,
  OPT_Wunused_result,
  OPT_Wunused_thrown,
  OPT_Wunused_value,
  OPT_Wunused_variable,
  OPT_Wuseless_type_check,
  OPT_Wvarargs_cast,
  OPT_Wvariadic_macros,
  OPT_Wvla,
  OPT_Wvolatile_register_var,
  OPT_Wwarning_token,
  OPT_Wwrite_strings,
  OPT_ansi,
  OPT_aux_info,
  OPT_aux_info_,
  OPT_auxbase,
  OPT_auxbase_strip,
  OPT_cpp,
  OPT_d,
  OPT_dumpbase,
  OPT_dumpdir,
  OPT_fCLASSPATH_,
  OPT_fPIC,
  OPT_fPIE,
  OPT_fRTS_,
  OPT_fabi_version_,
  OPT_faccess_control,
  OPT_falign_commons,
  OPT_falign_functions,
  OPT_falign_functions_,
  OPT_falign_jumps,
  OPT_falign_jumps_,
  OPT_falign_labels,
  OPT_falign_labels_,
  OPT_falign_loops,
  OPT_falign_loops_,
  OPT_fall_intrinsics,
  OPT_fall_virtual,
  OPT_fallow_leading_underscore,
  OPT_falt_external_templates,
  OPT_fargument_alias,
  OPT_fargument_noalias,
  OPT_fargument_noalias_anything,
  OPT_fargument_noalias_global,
  OPT_fasm,
  OPT_fassert,
  OPT_fassociative_math,
  OPT_fassume_compiled,
  OPT_fassume_compiled_,
  OPT_fasynchronous_unwind_tables,
  OPT_fauto_inc_dec,
  OPT_fautomatic,
  OPT_faux_classpath,
  OPT_fbackslash,
  OPT_fbacktrace,
  OPT_fblas_matmul_limit_,
  OPT_fbootclasspath_,
  OPT_fbootstrap_classes,
  OPT_fbounds_check,
  OPT_fbranch_count_reg,
  OPT_fbranch_probabilities,
  OPT_fbranch_target_load_optimize,
  OPT_fbranch_target_load_optimize2,
  OPT_fbtr_bb_exclusive,
  OPT_fbuiltin,
  OPT_fbuiltin_,
  OPT_fcall_saved_,
  OPT_fcall_used_,
  OPT_fcaller_saves,
  OPT_fcheck_array_temporaries,
  OPT_fcheck_data_deps,
  OPT_fcheck_new,
  OPT_fcheck_references,
  OPT_fcheck_,
  OPT_fclasspath_,
  OPT_fcommon,
  OPT_fcompare_debug_second,
  OPT_fcompare_debug_,
  OPT_fcompile_resource_,
  OPT_fcond_mismatch,
  OPT_fconserve_space,
  OPT_fconserve_stack,
  OPT_fconstant_string_class_,
  OPT_fconvert_big_endian,
  OPT_fconvert_little_endian,
  OPT_fconvert_native,
  OPT_fconvert_swap,
  OPT_fcprop_registers,
  OPT_fcray_pointer,
  OPT_fcrossjumping,
  OPT_fcse_follow_jumps,
  OPT_fcse_skip_blocks,
  OPT_fcx_fortran_rules,
  OPT_fcx_limited_range,
  OPT_fd_lines_as_code,
  OPT_fd_lines_as_comments,
  OPT_fdata_sections,
  OPT_fdbg_cnt_list,
  OPT_fdbg_cnt_,
  OPT_fdce,
  OPT_fdebug_prefix_map_,
  OPT_fdeduce_init_list,
  OPT_fdefault_double_8,
  OPT_fdefault_inline,
  OPT_fdefault_integer_8,
  OPT_fdefault_real_8,
  OPT_fdefer_pop,
  OPT_fdelayed_branch,
  OPT_fdelete_null_pointer_checks,
  OPT_fdiagnostics_show_location_,
  OPT_fdiagnostics_show_option,
  OPT_fdirectives_only,
  OPT_fdisable_assertions,
  OPT_fdisable_assertions_,
  OPT_fdollar_ok,
  OPT_fdollars_in_identifiers,
  OPT_fdse,
  OPT_fdump_,
  OPT_fdump_core,
  OPT_fdump_final_insns_,
  OPT_fdump_noaddr,
  OPT_fdump_parse_tree,
  OPT_fdump_unnumbered,
  OPT_fdump_unnumbered_links,
  OPT_fdwarf2_cfi_asm,
  OPT_fearly_inlining,
  OPT_felide_constructors,
  OPT_feliminate_dwarf2_dups,
  OPT_feliminate_unused_debug_symbols,
  OPT_feliminate_unused_debug_types,
  OPT_femit_class_debug_always,
  OPT_femit_class_file,
  OPT_femit_class_files,
  OPT_femit_struct_debug_baseonly,
  OPT_femit_struct_debug_detailed_,
  OPT_femit_struct_debug_reduced,
  OPT_fenable_assertions,
  OPT_fenable_assertions_,
  OPT_fenable_icf_debug,
  OPT_fencoding_,
  OPT_fenforce_eh_specs,
  OPT_fenum_int_equiv,
  OPT_fexceptions,
  OPT_fexcess_precision_,
  OPT_fexec_charset_,
  OPT_fexpensive_optimizations,
  OPT_fextdirs_,
  OPT_fextended_identifiers,
  OPT_fexternal_blas,
  OPT_fexternal_templates,
  OPT_ff2c,
  OPT_ffast_math,
  OPT_ffilelist_file,
  OPT_ffinite_math_only,
  OPT_ffixed_,
  OPT_ffixed_form,
  OPT_ffixed_line_length_,
  OPT_ffixed_line_length_none,
  OPT_ffloat_store,
  OPT_ffor_scope,
  OPT_fforce_addr,
  OPT_fforce_classes_archive_check,
  OPT_fforward_propagate,
  OPT_ffpe_trap_,
  OPT_ffree_form,
  OPT_ffree_line_length_,
  OPT_ffree_line_length_none,
  OPT_ffreestanding,
  OPT_ffriend_injection,
  OPT_ffunction_cse,
  OPT_ffunction_sections,
  OPT_fgcse,
  OPT_fgcse_after_reload,
  OPT_fgcse_las,
  OPT_fgcse_lm,
  OPT_fgcse_sm,
  OPT_fgnu_keywords,
  OPT_fgnu_runtime,
  OPT_fgnu89_inline,
  OPT_fgraphite,
  OPT_fgraphite_identity,
  OPT_fguess_branch_probability,
  OPT_fguiding_decls,
  OPT_fhandle_exceptions,
  OPT_fhash_synchronization,
  OPT_fhelp,
  OPT_fhelp_,
  OPT_fhonor_std,
  OPT_fhosted,
  OPT_fhuge_objects,
  OPT_fident,
  OPT_fif_conversion,
  OPT_fif_conversion2,
  OPT_fimplement_inlines,
  OPT_fimplicit_inline_templates,
  OPT_fimplicit_none,
  OPT_fimplicit_templates,
  OPT_findirect_classes,
  OPT_findirect_dispatch,
  OPT_findirect_inlining,
  OPT_finhibit_size_directive,
  OPT_finit_character_,
  OPT_finit_integer_,
  OPT_finit_local_zero,
  OPT_finit_logical_,
  OPT_finit_real_,
  OPT_finline,
  OPT_finline_functions,
  OPT_finline_functions_called_once,
  OPT_finline_limit_,
  OPT_finline_limit_eq,
  OPT_finline_small_functions,
  OPT_finput_charset_,
  OPT_finstrument_functions,
  OPT_finstrument_functions_exclude_file_list_,
  OPT_finstrument_functions_exclude_function_list_,
  OPT_fintrinsic_modules_path,
  OPT_fipa_cp,
  OPT_fipa_cp_clone,
  OPT_fipa_matrix_reorg,
  OPT_fipa_pta,
  OPT_fipa_pure_const,
  OPT_fipa_reference,
  OPT_fipa_sra,
  OPT_fipa_struct_reorg,
  OPT_fipa_type_escape,
  OPT_fira_algorithm_,
  OPT_fira_coalesce,
  OPT_fira_loop_pressure,
  OPT_fira_region_,
  OPT_fira_share_save_slots,
  OPT_fira_share_spill_slots,
  OPT_fira_verbose_,
  OPT_fivopts,
  OPT_fjni,
  OPT_fjump_tables,
  OPT_fkeep_inline_functions,
  OPT_fkeep_static_consts,
  OPT_flabels_ok,
  OPT_flax_vector_conversions,
  OPT_fleading_underscore,
  OPT_floop_block,
  OPT_floop_interchange,
  OPT_floop_optimize,
  OPT_floop_parallelize_all,
  OPT_floop_strip_mine,
  OPT_flto,
  OPT_flto_compression_level_,
  OPT_flto_report,
  OPT_fltrans,
  OPT_fltrans_output_list_,
  OPT_fmath_errno,
  OPT_fmax_array_constructor_,
  OPT_fmax_errors_,
  OPT_fmax_identifier_length_,
  OPT_fmax_stack_var_size_,
  OPT_fmax_subrecord_length_,
  OPT_fmem_report,
  OPT_fmerge_all_constants,
  OPT_fmerge_constants,
  OPT_fmerge_debug_strings,
  OPT_fmessage_length_,
  OPT_fmodule_private,
  OPT_fmodulo_sched,
  OPT_fmodulo_sched_allow_regmoves,
  OPT_fmove_loop_invariants,
  OPT_fms_extensions,
  OPT_fmudflap,
  OPT_fmudflapir,
  OPT_fmudflapth,
  OPT_fname_mangling_version_,
  OPT_fnew_abi,
  OPT_fnext_runtime,
  OPT_fnil_receivers,
  OPT_fnon_call_exceptions,
  OPT_fnonansi_builtins,
  OPT_fnonnull_objects,
  OPT_fobjc_call_cxx_cdtors,
  OPT_fobjc_direct_dispatch,
  OPT_fobjc_exceptions,
  OPT_fobjc_gc,
  OPT_fobjc_sjlj_exceptions,
  OPT_fomit_frame_pointer,
  OPT_fopenmp,
  OPT_foperator_names,
  OPT_foptimize_register_move,
  OPT_foptimize_sibling_calls,
  OPT_foptimize_static_class_initialization,
  OPT_foptional_diags,
  OPT_foutput_class_dir_,
  OPT_fpack_derived,
  OPT_fpack_struct,
  OPT_fpack_struct_,
  OPT_fpcc_struct_return,
  OPT_fpch_deps,
  OPT_fpch_preprocess,
  OPT_fpeel_loops,
  OPT_fpeephole,
  OPT_fpeephole2,
  OPT_fpermissive,
  OPT_fpic,
  OPT_fpie,
  OPT_fplugin_arg_,
  OPT_fplugin_,
  OPT_fpost_ipa_mem_report,
  OPT_fpre_ipa_mem_report,
  OPT_fpredictive_commoning,
  OPT_fprefetch_loop_arrays,
  OPT_fpreprocessed,
  OPT_fpretty_templates,
  OPT_fprofile,
  OPT_fprofile_arcs,
  OPT_fprofile_correction,
  OPT_fprofile_dir_,
  OPT_fprofile_generate,
  OPT_fprofile_generate_,
  OPT_fprofile_use,
  OPT_fprofile_use_,
  OPT_fprofile_values,
  OPT_fprotect_parens,
  OPT_frandom_seed,
  OPT_frandom_seed_,
  OPT_frange_check,
  OPT_freciprocal_math,
  OPT_frecord_gcc_switches,
  OPT_frecord_marker_4,
  OPT_frecord_marker_8,
  OPT_frecursive,
  OPT_freduced_reflection,
  OPT_freg_struct_return,
  OPT_fregmove,
  OPT_frename_registers,
  OPT_freorder_blocks,
  OPT_freorder_blocks_and_partition,
  OPT_freorder_functions,
  OPT_frepack_arrays,
  OPT_freplace_objc_classes,
  OPT_frepo,
  OPT_frerun_cse_after_loop,
  OPT_frerun_loop_opt,
  OPT_freschedule_modulo_scheduled_loops,
  OPT_fresolution,
  OPT_frounding_math,
  OPT_frtti,
  OPT_fsaw_java_file,
  OPT_fsched_critical_path_heuristic,
  OPT_fsched_dep_count_heuristic,
  OPT_fsched_group_heuristic,
  OPT_fsched_interblock,
  OPT_fsched_last_insn_heuristic,
  OPT_fsched_pressure,
  OPT_fsched_rank_heuristic,
  OPT_fsched_spec,
  OPT_fsched_spec_insn_heuristic,
  OPT_fsched_spec_load,
  OPT_fsched_spec_load_dangerous,
  OPT_fsched_stalled_insns,
  OPT_fsched_stalled_insns_dep,
  OPT_fsched_stalled_insns_dep_,
  OPT_fsched_stalled_insns_,
  OPT_fsched_verbose_,
  OPT_fsched2_use_superblocks,
  OPT_fsched2_use_traces,
  OPT_fschedule_insns,
  OPT_fschedule_insns2,
  OPT_fsecond_underscore,
  OPT_fsection_anchors,
  OPT_fsee,
  OPT_fsel_sched_pipelining,
  OPT_fsel_sched_pipelining_outer_loops,
  OPT_fsel_sched_reschedule_pipelined,
  OPT_fselective_scheduling,
  OPT_fselective_scheduling2,
  OPT_fshort_double,
  OPT_fshort_enums,
  OPT_fshort_wchar,
  OPT_fshow_column,
  OPT_fsign_zero,
  OPT_fsignaling_nans,
  OPT_fsigned_bitfields,
  OPT_fsigned_char,
  OPT_fsigned_zeros,
  OPT_fsingle_precision_constant,
  OPT_fsource_filename_,
  OPT_fsource_,
  OPT_fsplit_ivs_in_unroller,
  OPT_fsplit_wide_types,
  OPT_fsquangle,
  OPT_fstack_check,
  OPT_fstack_check_,
  OPT_fstack_limit,
  OPT_fstack_limit_register_,
  OPT_fstack_limit_symbol_,
  OPT_fstack_protector,
  OPT_fstack_protector_all,
  OPT_fstats,
  OPT_fstore_check,
  OPT_fstrength_reduce,
  OPT_fstrict_aliasing,
  OPT_fstrict_overflow,
  OPT_fstrict_prototype,
  OPT_fsyntax_only,
  OPT_ftabstop_,
  OPT_ftarget_help,
  OPT_ftarget_,
  OPT_ftemplate_depth_,
  OPT_ftemplate_depth_eq,
  OPT_ftest_coverage,
  OPT_fthis_is_variable,
  OPT_fthread_jumps,
  OPT_fthreadsafe_statics,
  OPT_ftime_report,
  OPT_ftls_model_,
  OPT_ftoplevel_reorder,
  OPT_ftracer,
  OPT_ftrapping_math,
  OPT_ftrapv,
  OPT_ftree_builtin_call_dce,
  OPT_ftree_ccp,
  OPT_ftree_ch,
  OPT_ftree_copy_prop,
  OPT_ftree_copyrename,
  OPT_ftree_cselim,
  OPT_ftree_dce,
  OPT_ftree_dominator_opts,
  OPT_ftree_dse,
  OPT_ftree_forwprop,
  OPT_ftree_fre,
  OPT_ftree_loop_distribution,
  OPT_ftree_loop_im,
  OPT_ftree_loop_ivcanon,
  OPT_ftree_loop_linear,
  OPT_ftree_loop_optimize,
  OPT_ftree_lrs,
  OPT_ftree_parallelize_loops_,
  OPT_ftree_phiprop,
  OPT_ftree_pre,
  OPT_ftree_pta,
  OPT_ftree_reassoc,
  OPT_ftree_salias,
  OPT_ftree_scev_cprop,
  OPT_ftree_sink,
  OPT_ftree_slp_vectorize,
  OPT_ftree_sra,
  OPT_ftree_store_ccp,
  OPT_ftree_store_copy_prop,
  OPT_ftree_switch_conversion,
  OPT_ftree_ter,
  OPT_ftree_vect_loop_version,
  OPT_ftree_vectorize,
  OPT_ftree_vectorizer_verbose_,
  OPT_ftree_vrp,
  OPT_funderscoring,
  OPT_funit_at_a_time,
  OPT_funroll_all_loops,
  OPT_funroll_loops,
  OPT_funsafe_loop_optimizations,
  OPT_funsafe_math_optimizations,
  OPT_funsigned_bitfields,
  OPT_funsigned_char,
  OPT_funswitch_loops,
  OPT_funwind_tables,
  OPT_fuse_atomic_builtins,
  OPT_fuse_boehm_gc,
  OPT_fuse_cxa_atexit,
  OPT_fuse_cxa_get_exception_ptr,
  OPT_fuse_divide_subroutine,
  OPT_fuse_linker_plugin,
  OPT_fvar_tracking,
  OPT_fvar_tracking_assignments,
  OPT_fvar_tracking_assignments_toggle,
  OPT_fvar_tracking_uninit,
  OPT_fvariable_expansion_in_unroller,
  OPT_fvect_cost_model,
  OPT_fverbose_asm,
  OPT_fversion,
  OPT_fvisibility_inlines_hidden,
  OPT_fvisibility_ms_compat,
  OPT_fvisibility_,
  OPT_fvpt,
  OPT_fvtable_gc,
  OPT_fvtable_thunks,
  OPT_fweak,
  OPT_fweb,
  OPT_fwhole_file,
  OPT_fwhole_program,
  OPT_fwhopr,
  OPT_fwide_exec_charset_,
  OPT_fworking_directory,
  OPT_fwpa,
  OPT_fwrapv,
  OPT_fxref,
  OPT_fzero_initialized_in_bss,
  OPT_fzero_link,
  OPT_g,
  OPT_gant,
  OPT_gcoff,
  OPT_gdwarfplus,
  OPT_gdwarf_,
  OPT_gen_decls,
  OPT_ggdb,
  OPT_gnat,
  OPT_gnatO,
  OPT_gno_strict_dwarf,
  OPT_gstabs,
  OPT_gstabs_,
  OPT_gstrict_dwarf,
  OPT_gtoggle,
  OPT_gvms,
  OPT_gxcoff,
  OPT_gxcoff_,
  OPT_idirafter,
  OPT_imacros,
  OPT_imultilib,
  OPT_include,
  OPT_iprefix,
  OPT_iquote,
  OPT_isysroot,
  OPT_isystem,
  OPT_iwithprefix,
  OPT_iwithprefixbefore,
  OPT_lang_asm,
  OPT_lang_objc,
  OPT_m128bit_long_double,
  OPT_m32,
  OPT_m3dnow,
  OPT_m3dnowa,
  OPT_m64,
  OPT_m80387,
  OPT_m96bit_long_double,
  OPT_mabi_,
  OPT_mabm,
  OPT_maccumulate_outgoing_args,
  OPT_maes,
  OPT_malign_double,
  OPT_malign_functions_,
  OPT_malign_jumps_,
  OPT_malign_loops_,
  OPT_malign_stringops,
  OPT_march_,
  OPT_masm_,
  OPT_mavx,
  OPT_mbranch_cost_,
  OPT_mcld,
  OPT_mcmodel_,
  OPT_mcrc32,
  OPT_mcx16,
  OPT_mfancy_math_387,
  OPT_mfma,
  OPT_mfma4,
  OPT_mforce_drap,
  OPT_mfp_ret_in_387,
  OPT_mfpmath_,
  OPT_mfused_madd,
  OPT_mglibc,
  OPT_mhard_float,
  OPT_mieee_fp,
  OPT_mincoming_stack_boundary_,
  OPT_minline_all_stringops,
  OPT_minline_stringops_dynamically,
  OPT_mintel_syntax,
  OPT_mlarge_data_threshold_,
  OPT_mlwp,
  OPT_mmmx,
  OPT_mmovbe,
  OPT_mms_bitfields,
  OPT_mno_align_stringops,
  OPT_mno_fancy_math_387,
  OPT_mno_push_args,
  OPT_mno_red_zone,
  OPT_mno_sse4,
  OPT_momit_leaf_frame_pointer,
  OPT_mpc,
  OPT_mpclmul,
  OPT_mpopcnt,
  OPT_mpreferred_stack_boundary_,
  OPT_mpush_args,
  OPT_mrecip,
  OPT_mred_zone,
  OPT_mregparm_,
  OPT_mrtd,
  OPT_msahf,
  OPT_msoft_float,
  OPT_msse,
  OPT_msse2,
  OPT_msse2avx,
  OPT_msse3,
  OPT_msse4,
  OPT_msse4_1,
  OPT_msse4_2,
  OPT_msse4a,
  OPT_msseregparm,
  OPT_mssse3,
  OPT_mstack_arg_probe,
  OPT_mstackrealign,
  OPT_mstringop_strategy_,
  OPT_mtls_dialect_,
  OPT_mtls_direct_seg_refs,
  OPT_mtune_,
  OPT_muclibc,
  OPT_mveclibabi_,
  OPT_mxop,
  OPT_nocpp,
  OPT_nostdinc,
  OPT_nostdinc__,
  OPT_nostdlib,
  OPT_o,
  OPT_p,
  OPT_pedantic,
  OPT_pedantic_errors,
  OPT_pie,
  OPT_print_objc_runtime_info,
  OPT_print_pch_checksum,
  OPT_quiet,
  OPT_remap,
  OPT_shared,
  OPT_static_libgfortran,
  OPT_std_c__0x,
  OPT_std_c__98,
  OPT_std_c89,
  OPT_std_c90,
  OPT_std_c99,
  OPT_std_c9x,
  OPT_std_f2003,
  OPT_std_f2008,
  OPT_std_f95,
  OPT_std_gnu,
  OPT_std_gnu__0x,
  OPT_std_gnu__98,
  OPT_std_gnu89,
  OPT_std_gnu90,
  OPT_std_gnu99,
  OPT_std_gnu9x,
  OPT_std_iso9899_1990,
  OPT_std_iso9899_199409,
  OPT_std_iso9899_1999,
  OPT_std_iso9899_199x,
  OPT_std_legacy,
  OPT_traditional_cpp,
  OPT_trigraphs,
  OPT_undef,
  OPT_v,
  OPT_version,
  OPT_w,
  N_OPTS
};
# 33 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h" 2






enum tree_code {
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/all-tree.def" 1
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def" 1
# 42 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
ERROR_MARK,





IDENTIFIER_NODE,






TREE_LIST,


TREE_VEC,
# 79 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
BLOCK,
# 123 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
OFFSET_TYPE,
# 136 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
ENUMERAL_TYPE,



BOOLEAN_TYPE,
# 150 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
INTEGER_TYPE,



REAL_TYPE,
# 163 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
POINTER_TYPE,




FIXED_POINT_TYPE,



REFERENCE_TYPE,
# 181 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
COMPLEX_TYPE,




VECTOR_TYPE,
# 202 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
ARRAY_TYPE,
# 212 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
RECORD_TYPE,





UNION_TYPE,





QUAL_UNION_TYPE,






VOID_TYPE,







FUNCTION_TYPE,






METHOD_TYPE,





LANG_TYPE,
# 265 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
INTEGER_CST,


REAL_CST,


FIXED_CST,



COMPLEX_CST,


VECTOR_CST,


STRING_CST,
# 341 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
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
# 371 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
IMPORTED_DECL,



TRANSLATION_UNIT_DECL,
# 388 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
COMPONENT_REF,
# 398 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
BIT_FIELD_REF,



REALPART_EXPR,
IMAGPART_EXPR,






ARRAY_REF,




ARRAY_RANGE_REF,






INDIRECT_REF,



ALIGN_INDIRECT_REF,






MISALIGNED_INDIRECT_REF,
# 445 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
OBJ_TYPE_REF,
# 461 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
CONSTRUCTOR,
# 471 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
COMPOUND_EXPR,


MODIFY_EXPR,




INIT_EXPR,







TARGET_EXPR,
# 501 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
COND_EXPR,
# 513 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
VEC_COND_EXPR,
# 536 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
BIND_EXPR,







CALL_EXPR,






WITH_CLEANUP_EXPR,
# 568 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
CLEANUP_POINT_EXPR,
# 620 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
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
# 690 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
LSHIFT_EXPR,
RSHIFT_EXPR,
LROTATE_EXPR,
RROTATE_EXPR,


BIT_IOR_EXPR,
BIT_XOR_EXPR,
BIT_AND_EXPR,
BIT_NOT_EXPR,
# 710 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
TRUTH_ANDIF_EXPR,
TRUTH_ORIF_EXPR,
TRUTH_AND_EXPR,
TRUTH_OR_EXPR,
TRUTH_XOR_EXPR,
TRUTH_NOT_EXPR,







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
# 780 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
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
# 875 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
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
# 938 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
ASSERT_EXPR,



TREE_BINFO,






WITH_SIZE_EXPR,
# 960 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
REALIGN_LOAD_EXPR,
# 974 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
TARGET_MEM_REF,







OMP_PARALLEL,





OMP_TASK,
# 1009 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
OMP_FOR,




OMP_SECTIONS,




OMP_SINGLE,



OMP_SECTION,



OMP_MASTER,



OMP_ORDERED,




OMP_CRITICAL,







OMP_ATOMIC,


OMP_CLAUSE,







REDUC_MAX_EXPR,
REDUC_MIN_EXPR,
REDUC_PLUS_EXPR,
# 1068 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
DOT_PROD_EXPR,
# 1077 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.def"
WIDEN_SUM_EXPR,






WIDEN_MULT_EXPR,




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


VEC_EXTRACT_EVEN_EXPR,
VEC_EXTRACT_ODD_EXPR,


VEC_INTERLEAVE_HIGH_EXPR,
VEC_INTERLEAVE_LOW_EXPR,






PREDICT_EXPR,


OPTIMIZATION_NODE,


TARGET_OPTION_NODE,
# 2 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/all-tree.def" 2
LAST_AND_UNUSED_TREE_CODE,
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.def" 1
# 40 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.def"
C_MAYBE_CONST_EXPR,






EXCESS_PRECISION_EXPR,
# 4 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/all-tree.def" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/ada/gcc-interface/ada-tree.def" 1
# 29 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/ada/gcc-interface/ada-tree.def"
UNCONSTRAINED_ARRAY_TYPE,





UNCONSTRAINED_ARRAY_REF,




NULL_EXPR,



PLUS_NOMOD_EXPR,



MINUS_NOMOD_EXPR,




ATTR_ADDR_EXPR,
# 62 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/ada/gcc-interface/ada-tree.def"
STMT_STMT,






LOOP_STMT,





EXIT_STMT,
# 5 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/all-tree.def" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cp/cp-tree.def" 1
# 43 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cp/cp-tree.def"
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
# 109 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cp/cp-tree.def"
BASELINK,
# 126 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cp/cp-tree.def"
TEMPLATE_DECL,
# 161 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cp/cp-tree.def"
TEMPLATE_PARM_INDEX,
# 170 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cp/cp-tree.def"
TEMPLATE_TEMPLATE_PARM,
# 179 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cp/cp-tree.def"
TEMPLATE_TYPE_PARM,





TYPENAME_TYPE,



TYPEOF_TYPE,





BOUND_TEMPLATE_TEMPLATE_PARM,





UNBOUND_CLASS_TEMPLATE,





USING_DECL,


USING_STMT,




DEFAULT_ARG,






TEMPLATE_ID_EXPR,



OVERLOAD,
# 238 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cp/cp-tree.def"
PSEUDO_DTOR_EXPR,



MODOP_EXPR,
CAST_EXPR,
REINTERPRET_CAST_EXPR,
CONST_CAST_EXPR,
STATIC_CAST_EXPR,
DYNAMIC_CAST_EXPR,
DOTSTAR_EXPR,
TYPEID_EXPR,
# 260 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cp/cp-tree.def"
NON_DEPENDENT_EXPR,



CTOR_INITIALIZER,

TRY_BLOCK,

EH_SPEC_BLOCK,





HANDLER,



MUST_NOT_THROW_EXPR,




CLEANUP_STMT,





IF_STMT,



FOR_STMT,



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




STMT_EXPR,



UNARY_PLUS_EXPR,







STATIC_ASSERT,
# 366 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cp/cp-tree.def"
TYPE_ARGUMENT_PACK,
# 375 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cp/cp-tree.def"
NONTYPE_ARGUMENT_PACK,
# 398 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cp/cp-tree.def"
TYPE_PACK_EXPANSION,






EXPR_PACK_EXPANSION,
# 417 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cp/cp-tree.def"
ARGUMENT_PACK_SELECT,




TRAIT_EXPR,
# 431 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cp/cp-tree.def"
LAMBDA_EXPR,
# 440 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cp/cp-tree.def"
DECLTYPE_TYPE,
# 450 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cp/cp-tree.def"
TEMPLATE_INFO,
# 6 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/all-tree.def" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/java/java-tree.def" 1
# 23 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/java/java-tree.def"
URSHIFT_EXPR,



COMPARE_EXPR,


COMPARE_L_EXPR,

COMPARE_G_EXPR,
# 7 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/all-tree.def" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/objc/objc-tree.def" 1
# 25 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/objc/objc-tree.def"
CLASS_INTERFACE_TYPE,
CLASS_IMPLEMENTATION_TYPE,

CATEGORY_INTERFACE_TYPE,
CATEGORY_IMPLEMENTATION_TYPE,

PROTOCOL_INTERFACE_TYPE,


KEYWORD_DECL,
INSTANCE_METHOD_DECL,
CLASS_METHOD_DECL,


MESSAGE_SEND_EXPR,
CLASS_REFERENCE_EXPR,
# 7 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/all-tree.def" 2
# 41 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h" 2
MAX_TREE_CODES
};




extern unsigned char tree_contains_struct[MAX_TREE_CODES][64];
# 58 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
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
# 174 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern const unsigned char tree_code_length[];




extern const char *const tree_code_name[];


static __inline__ void VEC_tree_must_be_pointer_type (void) { (void)((tree)1 == (void *)1); } typedef struct VEC_tree_base { unsigned num; unsigned alloc; tree vec[1]; } VEC_tree_base; typedef struct VEC_tree_none { VEC_tree_base base; } VEC_tree_none; static __inline__ unsigned VEC_tree_base_length (const VEC_tree_base *vec_) { return vec_ ? vec_->num : 0; } static __inline__ tree VEC_tree_base_last (const VEC_tree_base *vec_ ) { (void)(vec_ && vec_->num); return vec_->vec[vec_->num - 1]; } static __inline__ tree VEC_tree_base_index (const VEC_tree_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->num); return vec_->vec[ix_]; } static __inline__ int VEC_tree_base_iterate (const VEC_tree_base *vec_, unsigned ix_, tree *ptr) { if (vec_ && ix_ < vec_->num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (tree) 0; return 0; } } static __inline__ size_t VEC_tree_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_tree_base, vec) + alloc_ * sizeof(tree); } static __inline__ void VEC_tree_base_embedded_init (VEC_tree_base *vec_, int alloc_) { vec_->num = 0; vec_->alloc = alloc_; } static __inline__ int VEC_tree_base_space (VEC_tree_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->alloc - vec_->num >= (unsigned)alloc_ : !alloc_; } static __inline__ tree *VEC_tree_base_quick_push (VEC_tree_base *vec_, tree obj_ ) { tree *slot_; (void)(vec_->num < vec_->alloc); slot_ = &vec_->vec[vec_->num++]; *slot_ = obj_; return slot_; } static __inline__ tree VEC_tree_base_pop (VEC_tree_base *vec_ ) { tree obj_; (void)(vec_->num); obj_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_tree_base_truncate (VEC_tree_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->num >= size_ : !size_); if (vec_) vec_->num = size_; } static __inline__ tree VEC_tree_base_replace (VEC_tree_base *vec_, unsigned ix_, tree obj_ ) { tree old_obj_; (void)(ix_ < vec_->num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ tree *VEC_tree_base_quick_insert (VEC_tree_base *vec_, unsigned ix_, tree obj_ ) { tree *slot_; (void)(vec_->num < vec_->alloc); (void)(ix_ <= vec_->num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->num++ - ix_) * sizeof (tree)); *slot_ = obj_; return slot_; } static __inline__ tree VEC_tree_base_ordered_remove (VEC_tree_base *vec_, unsigned ix_ ) { tree *slot_; tree obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->num - ix_) * sizeof (tree)); return obj_; } static __inline__ tree VEC_tree_base_unordered_remove (VEC_tree_base *vec_, unsigned ix_ ) { tree *slot_; tree obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_tree_base_block_remove (VEC_tree_base *vec_, unsigned ix_, unsigned len_ ) { tree *slot_; (void)(ix_ + len_ <= vec_->num); slot_ = &vec_->vec[ix_]; vec_->num -= len_; memmove (slot_, slot_ + len_, (vec_->num - ix_) * sizeof (tree)); } static __inline__ tree *VEC_tree_base_address (VEC_tree_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_tree_base_lower_bound (VEC_tree_base *vec_, const tree obj_, unsigned char (*lessthan_)(const tree, const tree) ) { unsigned int len_ = VEC_tree_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { tree middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_tree_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_tree_gc { VEC_tree_base base; } VEC_tree_gc; static __inline__ VEC_tree_gc *VEC_tree_gc_alloc (int alloc_ ) { return (VEC_tree_gc *) vec_gc_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_tree_gc_free (VEC_tree_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_tree_gc *VEC_tree_gc_copy (VEC_tree_base *vec_ ) { size_t len_ = vec_ ? vec_->num : 0; VEC_tree_gc *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_tree_gc *)(vec_gc_p_reserve_exact (((void *)0), len_ )); new_vec_->base.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (tree) * len_); } return new_vec_; } static __inline__ int VEC_tree_gc_reserve (VEC_tree_gc **vec_, int alloc_ ) { int extend = !VEC_tree_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_tree_gc *) vec_gc_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_tree_gc_reserve_exact (VEC_tree_gc **vec_, int alloc_ ) { int extend = !VEC_tree_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_tree_gc *) vec_gc_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_tree_gc_safe_grow (VEC_tree_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_tree_base_length ((*vec_) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_tree_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((*vec_) ? &(*vec_)->base : 0)->num : 0) ); ((*vec_) ? &(*vec_)->base : 0)->num = size_; } static __inline__ void VEC_tree_gc_safe_grow_cleared (VEC_tree_gc **vec_, int size_ ) { int oldsize = VEC_tree_base_length ((*vec_) ? &(*vec_)->base : 0); VEC_tree_gc_safe_grow (vec_, size_ ); memset (&(VEC_tree_base_address ((*vec_) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (tree) * (size_ - oldsize)); } static __inline__ tree *VEC_tree_gc_safe_push (VEC_tree_gc **vec_, tree obj_ ) { VEC_tree_gc_reserve (vec_, 1 ); return VEC_tree_base_quick_push (((*vec_) ? &(*vec_)->base : 0), obj_ ); } static __inline__ tree *VEC_tree_gc_safe_insert (VEC_tree_gc **vec_, unsigned ix_, tree obj_ ) { VEC_tree_gc_reserve (vec_, 1 ); return VEC_tree_base_quick_insert (((*vec_) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
typedef struct VEC_tree_heap { VEC_tree_base base; } VEC_tree_heap; static __inline__ VEC_tree_heap *VEC_tree_heap_alloc (int alloc_ ) { return (VEC_tree_heap *) vec_heap_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_tree_heap_free (VEC_tree_heap **vec_) { if (*vec_) free (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_tree_heap *VEC_tree_heap_copy (VEC_tree_base *vec_ ) { size_t len_ = vec_ ? vec_->num : 0; VEC_tree_heap *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_tree_heap *)(vec_heap_p_reserve_exact (((void *)0), len_ )); new_vec_->base.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (tree) * len_); } return new_vec_; } static __inline__ int VEC_tree_heap_reserve (VEC_tree_heap **vec_, int alloc_ ) { int extend = !VEC_tree_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_tree_heap *) vec_heap_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_tree_heap_reserve_exact (VEC_tree_heap **vec_, int alloc_ ) { int extend = !VEC_tree_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_tree_heap *) vec_heap_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_tree_heap_safe_grow (VEC_tree_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_tree_base_length ((*vec_) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_tree_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((*vec_) ? &(*vec_)->base : 0)->num : 0) ); ((*vec_) ? &(*vec_)->base : 0)->num = size_; } static __inline__ void VEC_tree_heap_safe_grow_cleared (VEC_tree_heap **vec_, int size_ ) { int oldsize = VEC_tree_base_length ((*vec_) ? &(*vec_)->base : 0); VEC_tree_heap_safe_grow (vec_, size_ ); memset (&(VEC_tree_base_address ((*vec_) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (tree) * (size_ - oldsize)); } static __inline__ tree *VEC_tree_heap_safe_push (VEC_tree_heap **vec_, tree obj_ ) { VEC_tree_heap_reserve (vec_, 1 ); return VEC_tree_base_quick_push (((*vec_) ? &(*vec_)->base : 0), obj_ ); } static __inline__ tree *VEC_tree_heap_safe_insert (VEC_tree_heap **vec_, unsigned ix_, tree obj_ ) { VEC_tree_heap_reserve (vec_, 1 ); return VEC_tree_base_quick_insert (((*vec_) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;





typedef struct alias_pair
{
  tree decl;
  tree target;
} alias_pair;


typedef struct VEC_alias_pair_base { unsigned num; unsigned alloc; alias_pair vec[1]; } VEC_alias_pair_base; typedef struct VEC_alias_pair_none { VEC_alias_pair_base base; } VEC_alias_pair_none; static __inline__ unsigned VEC_alias_pair_base_length (const VEC_alias_pair_base *vec_) { return vec_ ? vec_->num : 0; } static __inline__ alias_pair *VEC_alias_pair_base_last (VEC_alias_pair_base *vec_ ) { (void)(vec_ && vec_->num); return &vec_->vec[vec_->num - 1]; } static __inline__ alias_pair *VEC_alias_pair_base_index (VEC_alias_pair_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->num); return &vec_->vec[ix_]; } static __inline__ int VEC_alias_pair_base_iterate (VEC_alias_pair_base *vec_, unsigned ix_, alias_pair **ptr) { if (vec_ && ix_ < vec_->num) { *ptr = &vec_->vec[ix_]; return 1; } else { *ptr = 0; return 0; } } static __inline__ size_t VEC_alias_pair_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_alias_pair_base, vec) + alloc_ * sizeof(alias_pair); } static __inline__ void VEC_alias_pair_base_embedded_init (VEC_alias_pair_base *vec_, int alloc_) { vec_->num = 0; vec_->alloc = alloc_; } static __inline__ int VEC_alias_pair_base_space (VEC_alias_pair_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->alloc - vec_->num >= (unsigned)alloc_ : !alloc_; } static __inline__ alias_pair *VEC_alias_pair_base_quick_push (VEC_alias_pair_base *vec_, const alias_pair *obj_ ) { alias_pair *slot_; (void)(vec_->num < vec_->alloc); slot_ = &vec_->vec[vec_->num++]; if (obj_) *slot_ = *obj_; return slot_; } static __inline__ void VEC_alias_pair_base_pop (VEC_alias_pair_base *vec_ ) { (void)(vec_->num); --vec_->num; } static __inline__ void VEC_alias_pair_base_truncate (VEC_alias_pair_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->num >= size_ : !size_); if (vec_) vec_->num = size_; } static __inline__ alias_pair *VEC_alias_pair_base_replace (VEC_alias_pair_base *vec_, unsigned ix_, const alias_pair *obj_ ) { alias_pair *slot_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; if (obj_) *slot_ = *obj_; return slot_; } static __inline__ alias_pair *VEC_alias_pair_base_quick_insert (VEC_alias_pair_base *vec_, unsigned ix_, const alias_pair *obj_ ) { alias_pair *slot_; (void)(vec_->num < vec_->alloc); (void)(ix_ <= vec_->num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->num++ - ix_) * sizeof (alias_pair)); if (obj_) *slot_ = *obj_; return slot_; } static __inline__ void VEC_alias_pair_base_ordered_remove (VEC_alias_pair_base *vec_, unsigned ix_ ) { alias_pair *slot_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; memmove (slot_, slot_ + 1, (--vec_->num - ix_) * sizeof (alias_pair)); } static __inline__ void VEC_alias_pair_base_unordered_remove (VEC_alias_pair_base *vec_, unsigned ix_ ) { (void)(ix_ < vec_->num); vec_->vec[ix_] = vec_->vec[--vec_->num]; } static __inline__ void VEC_alias_pair_base_block_remove (VEC_alias_pair_base *vec_, unsigned ix_, unsigned len_ ) { alias_pair *slot_; (void)(ix_ + len_ <= vec_->num); slot_ = &vec_->vec[ix_]; vec_->num -= len_; memmove (slot_, slot_ + len_, (vec_->num - ix_) * sizeof (alias_pair)); } static __inline__ alias_pair *VEC_alias_pair_base_address (VEC_alias_pair_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_alias_pair_base_lower_bound (VEC_alias_pair_base *vec_, const alias_pair *obj_, unsigned char (*lessthan_)(const alias_pair *, const alias_pair *) ) { unsigned int len_ = VEC_alias_pair_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { alias_pair *middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_alias_pair_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_alias_pair_gc { VEC_alias_pair_base base; } VEC_alias_pair_gc; static __inline__ VEC_alias_pair_gc *VEC_alias_pair_gc_alloc (int alloc_ ) { return (VEC_alias_pair_gc *) vec_gc_o_reserve_exact (((void *)0), alloc_, __builtin_offsetof (VEC_alias_pair_gc, base.vec), sizeof (alias_pair) ); } static __inline__ VEC_alias_pair_gc *VEC_alias_pair_gc_copy (VEC_alias_pair_base *vec_ ) { size_t len_ = vec_ ? vec_->num : 0; VEC_alias_pair_gc *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_alias_pair_gc *)(vec_gc_o_reserve_exact (((void *)0), len_, __builtin_offsetof (VEC_alias_pair_gc, base.vec), sizeof (alias_pair) )); new_vec_->base.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (alias_pair) * len_); } return new_vec_; } static __inline__ void VEC_alias_pair_gc_free (VEC_alias_pair_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = ((void *)0); } static __inline__ int VEC_alias_pair_gc_reserve (VEC_alias_pair_gc **vec_, int alloc_ ) { int extend = !VEC_alias_pair_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_alias_pair_gc *) vec_gc_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_alias_pair_gc, base.vec), sizeof (alias_pair) ); return extend; } static __inline__ int VEC_alias_pair_gc_reserve_exact (VEC_alias_pair_gc **vec_, int alloc_ ) { int extend = !VEC_alias_pair_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_alias_pair_gc *) vec_gc_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_alias_pair_gc, base.vec), sizeof (alias_pair) ); return extend; } static __inline__ void VEC_alias_pair_gc_safe_grow (VEC_alias_pair_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_alias_pair_base_length ((*vec_) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_alias_pair_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((*vec_) ? &(*vec_)->base : 0)->num : 0) ); ((*vec_) ? &(*vec_)->base : 0)->num = size_; } static __inline__ void VEC_alias_pair_gc_safe_grow_cleared (VEC_alias_pair_gc **vec_, int size_ ) { int oldsize = VEC_alias_pair_base_length ((*vec_) ? &(*vec_)->base : 0); VEC_alias_pair_gc_safe_grow (vec_, size_ ); memset (&(VEC_alias_pair_base_address ((*vec_) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (alias_pair) * (size_ - oldsize)); } static __inline__ alias_pair *VEC_alias_pair_gc_safe_push (VEC_alias_pair_gc **vec_, const alias_pair *obj_ ) { VEC_alias_pair_gc_reserve (vec_, 1 ); return VEC_alias_pair_base_quick_push (((*vec_) ? &(*vec_)->base : 0), obj_ ); } static __inline__ alias_pair *VEC_alias_pair_gc_safe_insert (VEC_alias_pair_gc **vec_, unsigned ix_, const alias_pair *obj_ ) { VEC_alias_pair_gc_reserve (vec_, 1 ); return VEC_alias_pair_base_quick_insert (((*vec_) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;

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
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/builtins.def" 1
# 177 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/builtins.def"
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
BUILT_IN_ILOGB,
BUILT_IN_ILOGBF,
BUILT_IN_ILOGBL,
BUILT_IN_INF,
BUILT_IN_INFF,
BUILT_IN_INFL,
BUILT_IN_INFD32,
BUILT_IN_INFD64,
BUILT_IN_INFD128,
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
BUILT_IN_ARGS_INFO,
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
BUILT_IN_ADJUST_TRAMPOLINE,
BUILT_IN_NONLOCAL_GOTO,


BUILT_IN_SETJMP_SETUP,
BUILT_IN_SETJMP_DISPATCHER,
BUILT_IN_SETJMP_RECEIVER,


BUILT_IN_STACK_SAVE,
BUILT_IN_STACK_RESTORE,


BUILT_IN_OBJECT_SIZE,
BUILT_IN_MEMCPY_CHK,
BUILT_IN_MEMMOVE_CHK,
BUILT_IN_MEMPCPY_CHK,
BUILT_IN_MEMSET_CHK,
BUILT_IN_STPCPY_CHK,
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


# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/sync-builtins.def" 1
# 31 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/sync-builtins.def"
BUILT_IN_FETCH_AND_ADD_N,

BUILT_IN_FETCH_AND_ADD_1,

BUILT_IN_FETCH_AND_ADD_2,

BUILT_IN_FETCH_AND_ADD_4,

BUILT_IN_FETCH_AND_ADD_8,

BUILT_IN_FETCH_AND_ADD_16,


BUILT_IN_FETCH_AND_SUB_N,

BUILT_IN_FETCH_AND_SUB_1,

BUILT_IN_FETCH_AND_SUB_2,

BUILT_IN_FETCH_AND_SUB_4,

BUILT_IN_FETCH_AND_SUB_8,

BUILT_IN_FETCH_AND_SUB_16,


BUILT_IN_FETCH_AND_OR_N,

BUILT_IN_FETCH_AND_OR_1,

BUILT_IN_FETCH_AND_OR_2,

BUILT_IN_FETCH_AND_OR_4,

BUILT_IN_FETCH_AND_OR_8,

BUILT_IN_FETCH_AND_OR_16,


BUILT_IN_FETCH_AND_AND_N,

BUILT_IN_FETCH_AND_AND_1,

BUILT_IN_FETCH_AND_AND_2,

BUILT_IN_FETCH_AND_AND_4,

BUILT_IN_FETCH_AND_AND_8,

BUILT_IN_FETCH_AND_AND_16,


BUILT_IN_FETCH_AND_XOR_N,

BUILT_IN_FETCH_AND_XOR_1,

BUILT_IN_FETCH_AND_XOR_2,

BUILT_IN_FETCH_AND_XOR_4,

BUILT_IN_FETCH_AND_XOR_8,

BUILT_IN_FETCH_AND_XOR_16,


BUILT_IN_FETCH_AND_NAND_N,

BUILT_IN_FETCH_AND_NAND_1,

BUILT_IN_FETCH_AND_NAND_2,

BUILT_IN_FETCH_AND_NAND_4,

BUILT_IN_FETCH_AND_NAND_8,

BUILT_IN_FETCH_AND_NAND_16,


BUILT_IN_ADD_AND_FETCH_N,

BUILT_IN_ADD_AND_FETCH_1,

BUILT_IN_ADD_AND_FETCH_2,

BUILT_IN_ADD_AND_FETCH_4,

BUILT_IN_ADD_AND_FETCH_8,

BUILT_IN_ADD_AND_FETCH_16,


BUILT_IN_SUB_AND_FETCH_N,

BUILT_IN_SUB_AND_FETCH_1,

BUILT_IN_SUB_AND_FETCH_2,

BUILT_IN_SUB_AND_FETCH_4,

BUILT_IN_SUB_AND_FETCH_8,

BUILT_IN_SUB_AND_FETCH_16,


BUILT_IN_OR_AND_FETCH_N,

BUILT_IN_OR_AND_FETCH_1,

BUILT_IN_OR_AND_FETCH_2,

BUILT_IN_OR_AND_FETCH_4,

BUILT_IN_OR_AND_FETCH_8,

BUILT_IN_OR_AND_FETCH_16,


BUILT_IN_AND_AND_FETCH_N,

BUILT_IN_AND_AND_FETCH_1,

BUILT_IN_AND_AND_FETCH_2,

BUILT_IN_AND_AND_FETCH_4,

BUILT_IN_AND_AND_FETCH_8,

BUILT_IN_AND_AND_FETCH_16,


BUILT_IN_XOR_AND_FETCH_N,

BUILT_IN_XOR_AND_FETCH_1,

BUILT_IN_XOR_AND_FETCH_2,

BUILT_IN_XOR_AND_FETCH_4,

BUILT_IN_XOR_AND_FETCH_8,

BUILT_IN_XOR_AND_FETCH_16,


BUILT_IN_NAND_AND_FETCH_N,

BUILT_IN_NAND_AND_FETCH_1,

BUILT_IN_NAND_AND_FETCH_2,

BUILT_IN_NAND_AND_FETCH_4,

BUILT_IN_NAND_AND_FETCH_8,

BUILT_IN_NAND_AND_FETCH_16,


BUILT_IN_BOOL_COMPARE_AND_SWAP_N,


BUILT_IN_BOOL_COMPARE_AND_SWAP_1,


BUILT_IN_BOOL_COMPARE_AND_SWAP_2,


BUILT_IN_BOOL_COMPARE_AND_SWAP_4,


BUILT_IN_BOOL_COMPARE_AND_SWAP_8,


BUILT_IN_BOOL_COMPARE_AND_SWAP_16,



BUILT_IN_VAL_COMPARE_AND_SWAP_N,


BUILT_IN_VAL_COMPARE_AND_SWAP_1,


BUILT_IN_VAL_COMPARE_AND_SWAP_2,


BUILT_IN_VAL_COMPARE_AND_SWAP_4,


BUILT_IN_VAL_COMPARE_AND_SWAP_8,


BUILT_IN_VAL_COMPARE_AND_SWAP_16,



BUILT_IN_LOCK_TEST_AND_SET_N,

BUILT_IN_LOCK_TEST_AND_SET_1,

BUILT_IN_LOCK_TEST_AND_SET_2,

BUILT_IN_LOCK_TEST_AND_SET_4,

BUILT_IN_LOCK_TEST_AND_SET_8,

BUILT_IN_LOCK_TEST_AND_SET_16,


BUILT_IN_LOCK_RELEASE_N,

BUILT_IN_LOCK_RELEASE_1,

BUILT_IN_LOCK_RELEASE_2,

BUILT_IN_LOCK_RELEASE_4,

BUILT_IN_LOCK_RELEASE_8,

BUILT_IN_LOCK_RELEASE_16,


BUILT_IN_SYNCHRONIZE,
# 771 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/builtins.def" 2


# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/omp-builtins.def" 1
# 27 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/omp-builtins.def"
BUILT_IN_OMP_GET_THREAD_NUM,

BUILT_IN_OMP_GET_NUM_THREADS,


BUILT_IN_GOMP_ATOMIC_START,

BUILT_IN_GOMP_ATOMIC_END,

BUILT_IN_GOMP_BARRIER,

BUILT_IN_GOMP_TASKWAIT,

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
# 773 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/builtins.def" 2
# 223 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h" 2



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
# 269 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern tree built_in_decls[(int) END_BUILTINS];
extern tree implicit_built_in_decls[(int) END_BUILTINS];




extern unsigned const char omp_clause_num_ops[];
extern const char * const omp_clause_code_name[];



enum omp_clause_code
{


  OMP_CLAUSE_ERROR = 0,


  OMP_CLAUSE_PRIVATE,


  OMP_CLAUSE_SHARED,


  OMP_CLAUSE_FIRSTPRIVATE,


  OMP_CLAUSE_LASTPRIVATE,
# 305 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
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


  OMP_CLAUSE_UNTIED
};
# 360 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
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

  unsigned spare : 13;




  unsigned address_space : 8;
};

struct tree_common {
  struct tree_base base;
  tree chain;
  tree type;
};
# 630 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
enum tree_node_structure_enum {
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/treestruct.def" 1
# 33 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/treestruct.def"
TS_BASE,
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
TS_TYPE,
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
# 632 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h" 2
  LAST_TS_ENUM
};
# 941 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree-check.h" 1
# 942 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h" 2
# 1384 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
struct tree_int_cst {
  struct tree_common common;
  double_int int_cst;
};




struct real_value;




struct tree_real_cst {
  struct tree_common common;
  struct real_value * real_cst_ptr;
};


struct fixed_value;




struct tree_fixed_cst {
  struct tree_common common;
  struct fixed_value * fixed_cst_ptr;
};






struct tree_string {
  struct tree_common common;
  int length;
  char str[1];
};





struct tree_complex {
  struct tree_common common;
  tree real;
  tree imag;
};




struct tree_vector {
  struct tree_common common;
  tree elements;
};

# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/symtab.h" 1
# 22 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/symtab.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/obstack.h" 1
# 157 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/obstack.h"
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
# 23 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/symtab.h" 2







typedef struct ht_identifier ht_identifier;
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
# 1443 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h" 2
# 1460 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
struct tree_identifier {
  struct tree_common common;
  struct ht_identifier id;
};





struct tree_list {
  struct tree_common common;
  tree purpose;
  tree value;
};
# 1482 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
struct tree_vec {
  struct tree_common common;
  int length;
  tree a[1];
};
# 1532 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
typedef struct constructor_elt_d {
  tree index;
  tree value;
} constructor_elt;

typedef struct VEC_constructor_elt_base { unsigned num; unsigned alloc; constructor_elt vec[1]; } VEC_constructor_elt_base; typedef struct VEC_constructor_elt_none { VEC_constructor_elt_base base; } VEC_constructor_elt_none; static __inline__ unsigned VEC_constructor_elt_base_length (const VEC_constructor_elt_base *vec_) { return vec_ ? vec_->num : 0; } static __inline__ constructor_elt *VEC_constructor_elt_base_last (VEC_constructor_elt_base *vec_ ) { (void)(vec_ && vec_->num); return &vec_->vec[vec_->num - 1]; } static __inline__ constructor_elt *VEC_constructor_elt_base_index (VEC_constructor_elt_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->num); return &vec_->vec[ix_]; } static __inline__ int VEC_constructor_elt_base_iterate (VEC_constructor_elt_base *vec_, unsigned ix_, constructor_elt **ptr) { if (vec_ && ix_ < vec_->num) { *ptr = &vec_->vec[ix_]; return 1; } else { *ptr = 0; return 0; } } static __inline__ size_t VEC_constructor_elt_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_constructor_elt_base, vec) + alloc_ * sizeof(constructor_elt); } static __inline__ void VEC_constructor_elt_base_embedded_init (VEC_constructor_elt_base *vec_, int alloc_) { vec_->num = 0; vec_->alloc = alloc_; } static __inline__ int VEC_constructor_elt_base_space (VEC_constructor_elt_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->alloc - vec_->num >= (unsigned)alloc_ : !alloc_; } static __inline__ constructor_elt *VEC_constructor_elt_base_quick_push (VEC_constructor_elt_base *vec_, const constructor_elt *obj_ ) { constructor_elt *slot_; (void)(vec_->num < vec_->alloc); slot_ = &vec_->vec[vec_->num++]; if (obj_) *slot_ = *obj_; return slot_; } static __inline__ void VEC_constructor_elt_base_pop (VEC_constructor_elt_base *vec_ ) { (void)(vec_->num); --vec_->num; } static __inline__ void VEC_constructor_elt_base_truncate (VEC_constructor_elt_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->num >= size_ : !size_); if (vec_) vec_->num = size_; } static __inline__ constructor_elt *VEC_constructor_elt_base_replace (VEC_constructor_elt_base *vec_, unsigned ix_, const constructor_elt *obj_ ) { constructor_elt *slot_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; if (obj_) *slot_ = *obj_; return slot_; } static __inline__ constructor_elt *VEC_constructor_elt_base_quick_insert (VEC_constructor_elt_base *vec_, unsigned ix_, const constructor_elt *obj_ ) { constructor_elt *slot_; (void)(vec_->num < vec_->alloc); (void)(ix_ <= vec_->num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->num++ - ix_) * sizeof (constructor_elt)); if (obj_) *slot_ = *obj_; return slot_; } static __inline__ void VEC_constructor_elt_base_ordered_remove (VEC_constructor_elt_base *vec_, unsigned ix_ ) { constructor_elt *slot_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; memmove (slot_, slot_ + 1, (--vec_->num - ix_) * sizeof (constructor_elt)); } static __inline__ void VEC_constructor_elt_base_unordered_remove (VEC_constructor_elt_base *vec_, unsigned ix_ ) { (void)(ix_ < vec_->num); vec_->vec[ix_] = vec_->vec[--vec_->num]; } static __inline__ void VEC_constructor_elt_base_block_remove (VEC_constructor_elt_base *vec_, unsigned ix_, unsigned len_ ) { constructor_elt *slot_; (void)(ix_ + len_ <= vec_->num); slot_ = &vec_->vec[ix_]; vec_->num -= len_; memmove (slot_, slot_ + len_, (vec_->num - ix_) * sizeof (constructor_elt)); } static __inline__ constructor_elt *VEC_constructor_elt_base_address (VEC_constructor_elt_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_constructor_elt_base_lower_bound (VEC_constructor_elt_base *vec_, const constructor_elt *obj_, unsigned char (*lessthan_)(const constructor_elt *, const constructor_elt *) ) { unsigned int len_ = VEC_constructor_elt_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { constructor_elt *middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_constructor_elt_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_constructor_elt_gc { VEC_constructor_elt_base base; } VEC_constructor_elt_gc; static __inline__ VEC_constructor_elt_gc *VEC_constructor_elt_gc_alloc (int alloc_ ) { return (VEC_constructor_elt_gc *) vec_gc_o_reserve_exact (((void *)0), alloc_, __builtin_offsetof (VEC_constructor_elt_gc, base.vec), sizeof (constructor_elt) ); } static __inline__ VEC_constructor_elt_gc *VEC_constructor_elt_gc_copy (VEC_constructor_elt_base *vec_ ) { size_t len_ = vec_ ? vec_->num : 0; VEC_constructor_elt_gc *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_constructor_elt_gc *)(vec_gc_o_reserve_exact (((void *)0), len_, __builtin_offsetof (VEC_constructor_elt_gc, base.vec), sizeof (constructor_elt) )); new_vec_->base.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (constructor_elt) * len_); } return new_vec_; } static __inline__ void VEC_constructor_elt_gc_free (VEC_constructor_elt_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = ((void *)0); } static __inline__ int VEC_constructor_elt_gc_reserve (VEC_constructor_elt_gc **vec_, int alloc_ ) { int extend = !VEC_constructor_elt_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_constructor_elt_gc *) vec_gc_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_constructor_elt_gc, base.vec), sizeof (constructor_elt) ); return extend; } static __inline__ int VEC_constructor_elt_gc_reserve_exact (VEC_constructor_elt_gc **vec_, int alloc_ ) { int extend = !VEC_constructor_elt_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_constructor_elt_gc *) vec_gc_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_constructor_elt_gc, base.vec), sizeof (constructor_elt) ); return extend; } static __inline__ void VEC_constructor_elt_gc_safe_grow (VEC_constructor_elt_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_constructor_elt_base_length ((*vec_) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_constructor_elt_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((*vec_) ? &(*vec_)->base : 0)->num : 0) ); ((*vec_) ? &(*vec_)->base : 0)->num = size_; } static __inline__ void VEC_constructor_elt_gc_safe_grow_cleared (VEC_constructor_elt_gc **vec_, int size_ ) { int oldsize = VEC_constructor_elt_base_length ((*vec_) ? &(*vec_)->base : 0); VEC_constructor_elt_gc_safe_grow (vec_, size_ ); memset (&(VEC_constructor_elt_base_address ((*vec_) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (constructor_elt) * (size_ - oldsize)); } static __inline__ constructor_elt *VEC_constructor_elt_gc_safe_push (VEC_constructor_elt_gc **vec_, const constructor_elt *obj_ ) { VEC_constructor_elt_gc_reserve (vec_, 1 ); return VEC_constructor_elt_base_quick_push (((*vec_) ? &(*vec_)->base : 0), obj_ ); } static __inline__ constructor_elt *VEC_constructor_elt_gc_safe_insert (VEC_constructor_elt_gc **vec_, unsigned ix_, const constructor_elt *obj_ ) { VEC_constructor_elt_gc_reserve (vec_, 1 ); return VEC_constructor_elt_base_quick_insert (((*vec_) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;

struct tree_constructor {
  struct tree_common common;
  VEC_constructor_elt_gc *elts;
};
# 1583 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern void protected_set_expr_location (tree, location_t);
# 1805 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
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
  struct tree_common common;
  location_t locus;
  tree block;
  tree

    operands[1];
};
# 1876 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
struct ptr_info_def;






typedef struct ssa_use_operand_d {
  struct ssa_use_operand_d* prev;
  struct ssa_use_operand_d* next;





  union { gimple stmt; tree ssa_name; } loc;
  tree * use;
} ssa_use_operand_t;




struct tree_ssa_name {
  struct tree_common common;


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
# 1938 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
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


struct varray_head_tag;
# 2008 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
struct tree_block {
  struct tree_common common;

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
# 2070 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern enum machine_mode vector_type_mode (const_tree);
# 2277 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
struct die_struct;

struct tree_type {
  struct tree_common common;
  tree values;
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
  }
                    symtab;
  tree name;
  tree minval;
  tree maxval;
  tree next_variant;
  tree main_variant;
  tree binfo;
  tree context;
  tree canonical;

  struct lang_type *lang_specific;
};
# 2430 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
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
# 2465 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
enum symbol_visibility
{
  VISIBILITY_DEFAULT,
  VISIBILITY_PROTECTED,
  VISIBILITY_HIDDEN,
  VISIBILITY_INTERNAL
};


struct function;
# 2507 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
struct tree_decl_minimal {
  struct tree_common common;
  location_t locus;
  unsigned int uid;
  tree name;
  tree context;
};
# 2654 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
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


  unsigned decl_common_unused : 2;


  unsigned int off_align : 8;




  unsigned int align;

  tree size_unit;
  tree initial;
  tree attributes;
  tree abstract_origin;


  struct lang_decl *lang_specific;
};

extern tree decl_value_expr_lookup (tree);
extern void decl_value_expr_insert (tree, tree);
# 2758 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
struct tree_decl_with_rtl {
  struct tree_decl_common common;
  rtx rtl;
};
# 2826 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
struct tree_field_decl {
  struct tree_decl_common common;

  tree offset;
  tree bit_field_type;
  tree qualifier;
  tree bit_offset;
  tree fcontext;
};
# 2852 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
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
  struct tree_decl_with_rtl common;
};
# 2876 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
struct tree_parm_decl {
  struct tree_decl_with_rtl common;
  rtx incoming_rtl;
  struct var_ann_d *ann;
};
# 2986 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
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
 unsigned dllimport_flag : 1;

 unsigned shadowed_for_var_p : 1;

 unsigned weak_flag : 1;

 unsigned seen_in_bind_expr : 1;
 unsigned comdat_flag : 1;
 __extension__ enum symbol_visibility visibility : 2;
 unsigned visibility_specified : 1;

 __extension__ enum tls_model tls_model : 3;


 unsigned init_priority_p : 1;

};
# 3029 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern tree decl_debug_expr_lookup (tree);
extern void decl_debug_expr_insert (tree, tree);
# 3041 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
typedef unsigned short priority_type;

extern priority_type decl_init_priority_lookup (tree);
extern priority_type decl_fini_priority_lookup (tree);
extern void decl_init_priority_insert (tree, priority_type);
extern void decl_fini_priority_insert (tree, priority_type);
# 3095 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
struct tree_var_decl {
  struct tree_decl_with_vis common;
  struct var_ann_d *ann;
};
# 3115 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
struct
 tree_decl_non_common {
  struct tree_decl_with_vis common;

  tree saved_tree;

  tree arguments;

  tree result;

  tree vindex;
};
# 3250 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
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



};
# 3306 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
struct tree_type_decl {
  struct tree_decl_non_common common;

};
# 3322 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
struct tree_statement_list_node
 {
  struct tree_statement_list_node *prev;
  struct tree_statement_list_node *next;
  tree stmt;
};

struct tree_statement_list
 {
  struct tree_common common;
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






union
                                             tree_node {
  struct tree_base base;
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
  struct tree_type type;
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
# 3747 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
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
  itk_none
};

typedef enum integer_type_kind integer_type_kind;



extern tree integer_types[itk_none];
# 3783 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern enum tls_model flag_tls_default;
# 3807 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
enum ptrmemfunc_vbit_where_t
{
  ptrmemfunc_vbit_in_pfn,
  ptrmemfunc_vbit_in_delta
};



extern tree decl_assembler_name (tree);
extern unsigned char decl_assembler_name_equal (tree decl, const_tree asmname);
extern hashval_t decl_assembler_name_hash (const_tree asmname);




extern size_t tree_size (const_tree);




extern size_t tree_code_size (enum tree_code);





extern tree make_node_stat (enum tree_code );




extern tree copy_node_stat (tree );




extern tree copy_list (tree);


extern tree make_tree_binfo_stat (unsigned );




extern tree make_tree_vec_stat (int );





extern tree get_identifier (const char *);
# 3870 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern tree get_identifier_with_length (const char *, size_t);





extern tree maybe_get_identifier (const char *);



extern tree build_nt (enum tree_code, ...);
extern tree build_nt_call_list (tree, tree);
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



extern tree build_var_debug_value_stat (tree, tree );



extern tree build_int_cst (tree, long);
extern tree build_int_cst_type (tree, long);
extern tree build_int_cstu (tree, unsigned long);
extern tree build_int_cst_wide (tree, unsigned long, long);
extern tree build_int_cst_wide_type (tree,
         unsigned long, long);
extern tree build_vector (tree, tree);
extern tree build_vector_from_ctor (tree, VEC_constructor_elt_gc *);
extern tree build_constructor (tree, VEC_constructor_elt_gc *);
extern tree build_constructor_single (tree, tree, tree);
extern tree build_constructor_from_list (tree, tree);
extern tree build_real_from_int_cst (tree, const_tree);
extern tree build_complex (tree, tree, tree);
extern tree build_one_cst (tree);
extern tree build_string (int, const char *);
extern tree build_tree_list_stat (tree, tree );

extern tree build_tree_list_vec_stat (const VEC_tree_gc * );

extern tree build_decl_stat (location_t, enum tree_code,
        tree, tree );
extern tree build_fn_decl (const char *, tree);

extern tree build_block (tree, tree, tree, tree);
extern tree build_empty_stmt (location_t);
extern tree build_omp_clause (location_t, enum omp_clause_code);

extern tree build_vl_exp_stat (enum tree_code, int );


extern tree build_call_list (tree, tree, tree);
extern tree build_call_nary (tree, tree, int, ...);
extern tree build_call_valist (tree, tree, int, va_list);


extern tree build_call_array_loc (location_t, tree, tree, int, const tree *);
extern tree build_call_vec (tree, tree, VEC_tree_gc *);



extern tree make_signed_type (int);
extern tree make_unsigned_type (int);
extern tree signed_or_unsigned_type_for (int, tree);
extern tree signed_type_for (tree);
extern tree unsigned_type_for (tree);
extern void initialize_sizetypes (unsigned char);
extern void set_sizetype (tree);
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
extern tree build_index_2_type (tree, tree);
extern tree build_array_type (tree, tree);
extern tree build_function_type (tree, tree);
extern tree build_function_type_list (tree, ...);
extern tree build_function_type_skip_args (tree, bitmap);
extern tree build_function_decl_skip_args (tree, bitmap);
extern tree build_varargs_function_type_list (tree, ...);
extern tree build_method_type_directly (tree, tree, tree);
extern tree build_method_type (tree, tree);
extern tree build_offset_type (tree, tree);
extern tree build_complex_type (tree);
extern tree array_type_nelts (const_tree);
extern unsigned char in_array_bounds_p (tree);
extern unsigned char range_in_array_bounds_p (tree);

extern tree value_member (tree, tree);
extern tree purpose_member (const_tree, tree);
extern tree chain_index (int, tree);

extern int attribute_list_equal (const_tree, const_tree);
extern int attribute_list_contained (const_tree, const_tree);
extern int tree_int_cst_equal (const_tree, const_tree);
extern int tree_int_cst_lt (const_tree, const_tree);
extern int tree_int_cst_compare (const_tree, const_tree);
extern int host_integerp (const_tree, int);
extern long tree_low_cst (const_tree, int);
extern int tree_int_cst_msb (const_tree);
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
# 4035 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern tree make_tree (tree, rtx);







extern tree build_type_attribute_variant (tree, tree);
extern tree build_decl_attribute_variant (tree, tree);
extern tree build_type_attribute_qual_variant (tree, tree, int);


struct attribute_spec
{


  const char *const name;

  const int min_length;


  const int max_length;







  const unsigned char decl_required;


  const unsigned char type_required;




  const unsigned char function_type_required;
# 4088 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
  tree (*const handler) (tree *node, tree name, tree args,
     int flags, unsigned char *no_add_attrs);
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




extern int is_attribute_p (const char *, const_tree);




extern tree lookup_attribute (const char *, tree);




extern tree remove_attribute (const char *, tree);



extern tree merge_attributes (tree, tree);
# 4153 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern unsigned char check_qualified_type (const_tree, const_tree, int);





extern tree get_qualified_type (tree, int);




extern tree build_qualified_type (tree, int);
# 4178 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern tree build_distinct_type_copy (tree);
extern tree build_variant_type_copy (tree);




extern void finish_builtin_struct (tree, const char *,
        tree, tree);





extern void layout_type (tree);
# 4200 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
typedef struct record_layout_info_s
{

  tree t;


  tree offset;

  unsigned int offset_align;

  tree bitpos;

  unsigned int record_align;


  unsigned int unpacked_align;

  tree prev_field;


  tree pending_statics;

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
# 4255 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern void layout_decl (tree, unsigned);




extern void relayout_decl (tree);






extern enum machine_mode mode_for_size_tree (const_tree, enum mode_class, int);




extern tree non_lvalue_loc (location_t, tree);

extern tree convert (tree, tree);
extern unsigned int expr_align (const_tree);
extern tree expr_first (tree);
extern tree expr_last (tree);
extern tree size_in_bytes (const_tree);
extern long int_size_in_bytes (const_tree);
extern long max_int_size_in_bytes (const_tree);
extern tree tree_expr_size (const_tree);
extern tree bit_position (const_tree);
extern long int_bit_position (const_tree);
extern tree byte_position (const_tree);
extern long int_byte_position (const_tree);




enum size_type_kind
{
  SIZETYPE,
  SSIZETYPE,
  BITSIZETYPE,
  SBITSIZETYPE,
  TYPE_KIND_LAST};

extern tree sizetype_tab[(int) TYPE_KIND_LAST];






extern tree size_int_kind (long, enum size_type_kind);


extern tree size_binop_loc (location_t, enum tree_code, tree, tree);


extern tree size_diffop_loc (location_t, tree, tree);







extern tree round_up_loc (location_t, tree, int);

extern tree round_down_loc (location_t, tree, int);
extern tree get_pending_sizes (void);
extern void put_pending_size (tree);
extern void put_pending_sizes (tree);
extern void finalize_size_functions (void);
# 4335 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern unsigned int maximum_field_alignment;

extern unsigned int initial_max_fld_align;





extern tree chainon (tree, tree);



extern tree tree_cons_stat (tree, tree, tree );




extern tree tree_last (tree);



extern tree nreverse (tree);




extern int list_length (const_tree);



extern int fields_length (const_tree);



extern tree first_field (const_tree);




extern unsigned char initializer_zerop (const_tree);



extern tree ctor_to_list (tree);



extern VEC_tree_gc *ctor_to_vec (tree);
# 4395 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern unsigned char categorize_ctor_elements (const_tree, long *, long *,
          unsigned char *);

extern long count_type_elements (const_tree, unsigned char);



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
# 4469 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern unsigned char type_contains_placeholder_p (tree);
# 4478 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern void find_placeholder_in_expr (tree, VEC_tree_heap **);
# 4496 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern tree substitute_in_expr (tree, tree, tree);
# 4507 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern tree substitute_placeholder_in_expr (tree, tree);
# 4522 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
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





extern tree get_inner_reference (tree, long *, long *,
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
  tree fntype;
  tree next;
} function_args_iterator;



static __inline__ void
function_args_iter_init (function_args_iterator *i, tree fntype)
{
  i->fntype = fntype;
  i->next = ((fntype)->type.values);
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
  ((void)(!(i->next != (tree) ((void *)0)) ? fancy_abort ("/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h", 4672, __FUNCTION__), 0 : 0));
  i->next = ((i->next)->common.chain);
}



static __inline__ unsigned char
inlined_function_outer_scope_p (const_tree block)
{
 return ((block)->block.locus) != ((source_location) 0);
}
# 4703 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern unsigned crc32_string (unsigned, const char *);
extern void clean_symbol_name (char *);
extern tree get_file_function_name (const char *);
extern tree get_callee_fndecl (const_tree);
extern int type_num_arguments (const_tree);
extern unsigned char associative_tree_code (enum tree_code);
extern unsigned char commutative_tree_code (enum tree_code);
extern tree upper_bound_in_type (tree, tree);
extern tree lower_bound_in_type (tree, tree);
extern int operand_equal_for_phi_arg_p (const_tree, const_tree);
extern tree call_expr_arg (tree, int);
extern tree *call_expr_argp (tree, int);
extern tree call_expr_arglist (tree);
extern tree create_artificial_label (location_t);
extern const char *get_name (tree);
extern unsigned char stdarg_p (tree);
extern unsigned char prototype_p (tree);
extern unsigned char auto_var_in_fn_p (const_tree, const_tree);
extern tree build_low_bits_mask (tree, unsigned);
extern tree tree_strip_nop_conversions (tree);
extern tree tree_strip_sign_nop_conversions (tree);
extern tree lhd_gcc_personality (void);
extern void assign_assembler_name_if_neeeded (tree);



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

extern tree force_fit_type_double (tree, unsigned long, long,
       int, unsigned char);

extern int fit_double_type (unsigned long, long,
       unsigned long *, long *, const_tree);
extern int add_double_with_sign (unsigned long, long,
     unsigned long, long,
     unsigned long *, long *,
     unsigned char);


extern int neg_double (unsigned long, long,
         unsigned long *, long *);
extern int mul_double_with_sign (unsigned long, long,
     unsigned long, long,
     unsigned long *, long *,
     unsigned char);


extern void lshift_double (unsigned long, long,
      long, unsigned int,
      unsigned long *, long *, int);
extern void rshift_double (unsigned long, long,
      long, unsigned int,
      unsigned long *, long *, int);
extern void lrotate_double (unsigned long, long,
       long, unsigned int,
       unsigned long *, long *);
extern void rrotate_double (unsigned long, long,
       long, unsigned int,
       unsigned long *, long *);

extern int div_and_round_double (enum tree_code, int, unsigned long,
     long, unsigned long,
     long, unsigned long *,
     long *, unsigned long *,
     long *);

enum operand_equal_flag
{
  OEP_ONLY_CONST = 1,
  OEP_PURE_SAME = 2
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
extern tree int_const_binop (enum tree_code, const_tree, const_tree, int);


extern tree build_fold_addr_expr_loc (location_t, tree);


extern tree build_fold_addr_expr_with_type_loc (location_t, tree, tree);
extern tree fold_build_cleanup_point_expr (tree type, tree expr);
extern tree fold_strip_sign_ops (tree);


extern tree build_fold_indirect_ref_loc (location_t, tree);


extern tree fold_indirect_ref_loc (location_t, tree);
extern tree constant_boolean_node (int, tree);
extern tree div_if_zero_remainder (enum tree_code, const_tree, const_tree);

extern unsigned char tree_swap_operands_p (const_tree, const_tree, unsigned char);
extern enum tree_code swap_tree_comparison (enum tree_code);

extern unsigned char ptr_difference_const (tree, tree, long *);
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



extern tree fold_call_expr (location_t, tree, unsigned char);
extern tree fold_builtin_fputs (location_t, tree, tree, unsigned char, unsigned char, tree);
extern tree fold_builtin_strcpy (location_t, tree, tree, tree, tree);
extern tree fold_builtin_strncpy (location_t, tree, tree, tree, tree, tree);
extern tree fold_builtin_memory_chk (location_t, tree, tree, tree, tree, tree, tree, unsigned char,
         enum built_in_function);
extern tree fold_builtin_stxcpy_chk (location_t, tree, tree, tree, tree, tree, unsigned char,
         enum built_in_function);
extern tree fold_builtin_strncpy_chk (location_t, tree, tree, tree, tree, tree);
extern tree fold_builtin_snprintf_chk (location_t, tree, tree, enum built_in_function);
extern unsigned char fold_builtin_next_arg (tree, unsigned char);
extern enum built_in_function builtin_mathfn_code (const_tree);
extern tree build_function_call_expr (location_t, tree, tree);
extern tree fold_builtin_call_array (location_t, tree, tree, int, tree *);
extern tree build_call_expr_loc (location_t, tree, int, ...);
extern tree build_call_expr (tree, int, ...);
extern tree mathfn_built_in (tree, enum built_in_function fn);
extern tree c_strlen (tree, int);
extern tree std_gimplify_va_arg_expr (tree, tree, gimple_seq *, gimple_seq *);
extern tree build_va_arg_indirect_ref (tree);
extern tree build_string_literal (int, const char *);
extern unsigned char validate_arglist (const_tree, ...);
extern rtx builtin_memset_read_str (void *, long, enum machine_mode);
extern unsigned char can_trust_pointer_alignment (void);
extern int get_pointer_alignment (tree, unsigned int);
extern unsigned char is_builtin_name (const char *);
extern unsigned char is_builtin_fn (tree);
extern int get_object_alignment (tree, unsigned int, unsigned int);
extern tree fold_call_stmt (gimple, unsigned char);
extern tree gimple_fold_builtin_snprintf_chk (gimple, tree, enum built_in_function);
extern tree make_range (tree, int *, tree *, tree *, unsigned char *);
extern tree build_range_check (location_t, tree, tree, int, tree, tree);
extern unsigned char merge_ranges (int *, tree *, tree *, int, tree, tree, int,
     tree, tree);
extern void set_builtin_user_assembler_name (tree decl, const char *asmspec);


extern tree strip_float_extensions (tree);


extern int really_constant_p (const_tree);
extern unsigned char decl_address_invariant_p (const_tree);
extern unsigned char decl_address_ip_invariant_p (const_tree);
extern int int_fits_type_p (const_tree, const_tree);

extern void get_type_static_bounds (const_tree, mpz_t, mpz_t);

extern unsigned char variably_modified_type_p (tree, tree);
extern int tree_log2 (const_tree);
extern int tree_floor_log2 (const_tree);
extern int simple_cst_equal (const_tree, const_tree);
extern hashval_t iterative_hash_expr (const_tree, hashval_t);
extern hashval_t iterative_hash_exprs_commutative (const_tree,
                                                   const_tree, hashval_t);
extern hashval_t iterative_hash_host_wide_int (long, hashval_t);
extern hashval_t iterative_hash_hashval_t (hashval_t, hashval_t);
extern hashval_t iterative_hash_host_wide_int (long, hashval_t);
extern int compare_tree_int (const_tree, unsigned long);
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
extern void build_common_tree_nodes_2 (int);
extern void build_common_builtin_nodes (void);
extern tree build_nonstandard_integer_type (unsigned long, int);
extern tree build_range_type (tree, tree, tree);
extern unsigned char subrange_type_for_debug_p (const_tree, tree *, tree *);
extern long int_cst_value (const_tree);
extern long widest_int_cst_value (const_tree);

extern unsigned char fields_compatible_p (const_tree, const_tree);
extern tree find_compatible_field (tree, tree);

extern tree *tree_block (tree);
extern location_t *block_nonartificial_location (tree);
extern location_t tree_nonartificial_location (tree);

extern tree block_ultimate_origin (const_tree);


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

extern void dump_addr (FILE*, const char *, const void *);
extern void print_node (FILE *, const char *, tree, int);
extern void print_node_brief (FILE *, const char *, const_tree, int);
extern void indent_to (FILE *, int);



extern unsigned char debug_find_tree (tree, tree);


extern tree unsave_expr_now (tree);
extern tree build_duplicate_type (tree);
# 5100 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern int flags_from_decl_or_type (const_tree);
extern int call_expr_flags (const_tree);

extern int setjmp_call_p (const_tree);
extern unsigned char gimple_alloca_call_p (const_gimple);
extern unsigned char alloca_call_p (const_tree);
extern unsigned char must_pass_in_stack_var_size (enum machine_mode, const_tree);
extern unsigned char must_pass_in_stack_var_size_or_pad (enum machine_mode, const_tree);



extern const struct attribute_spec *lookup_attribute_spec (tree);
# 5121 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern tree decl_attributes (tree *, tree, int);


extern void set_decl_abstract_flags (tree, int);
extern void set_decl_origin_self (tree);


extern void set_min_and_max_values_for_integral_type (tree, int, unsigned char);
extern void fixup_signed_type (tree);
extern void internal_reference_types (void);
extern unsigned int update_alignment_for_field (record_layout_info, tree,
                                                unsigned int);

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
extern tree emutls_decl (tree);
extern void remove_unreachable_alias_pairs (void);


extern void expand_computed_goto (tree);
extern unsigned char parse_output_constraint (const char **, int, int, int,
         unsigned char *, unsigned char *, unsigned char *);
extern unsigned char parse_input_constraint (const char **, int, int, int, int,
        const char * const *, unsigned char *, unsigned char *);
extern void expand_asm_stmt (gimple);
extern tree resolve_asm_operand_names (tree, tree, tree, tree);
extern void expand_case (gimple);
extern void expand_decl (tree);
# 5170 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
extern char *dwarf2out_cfi_label (unsigned char);



extern void dwarf2out_def_cfa (const char *, unsigned, long);



extern void dwarf2out_window_save (const char *);



extern void dwarf2out_reg_save (const char *, unsigned, long);



extern void dwarf2out_return_save (const char *, long);



extern void dwarf2out_return_reg (const char *, unsigned);



extern void dwarf2out_reg_save_reg (const char *, rtx, rtx);





struct pointer_set_t;



typedef tree (*walk_tree_fn) (tree *, int *, void *);



typedef tree (*walk_tree_lh) (tree *, int *, tree (*) (tree *, int *, void *),
         void *, struct pointer_set_t*);

extern tree walk_tree_1 (tree*, walk_tree_fn, void*, struct pointer_set_t*,
    walk_tree_lh);
extern tree walk_tree_without_duplicates_1 (tree*, walk_tree_fn, void*,
         walk_tree_lh);
# 5223 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
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
  perm_list_kind,
  temp_list_kind,
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


extern void vect_set_verbosity_level (const char *);



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




struct tree_int_map {
  struct tree_map_base base;
  unsigned int to;
};







struct tree_priority_map {
  struct tree_map_base base;
  priority_type init;
  priority_type fini;
};







tree target_for_debug_bind (tree);


extern tree maybe_fold_offset_to_reference (location_t, tree, tree, tree);
extern tree maybe_fold_offset_to_address (location_t, tree, tree, tree);
extern tree maybe_fold_stmt_addition (location_t, tree, tree, tree);


extern tree tree_mem_ref_addr (tree, tree);
extern void copy_mem_ref_info (tree, tree);


extern unsigned char ssa_name_nonnegative_p (const_tree);


extern void init_object_sizes (void);
extern void fini_object_sizes (void);
extern unsigned long compute_builtin_object_size (tree, int);


extern unsigned long highest_pow2_factor (const_tree);
extern tree build_personality_function (const char *);



void init_inline_once (void);


extern tree memory_identifier_string;




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
# 5458 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h"
static __inline__ unsigned char
is_lang_specific (tree t)
{
  return ((enum tree_code) (t)->base.code) == LANG_TYPE || ((enum tree_code) (t)->base.code) >= ((int) LAST_AND_UNUSED_TREE_CODE);
}
# 25 "../../../src/plugin-utils.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tm.h" 1







# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/vxworks-dummy.h" 1
# 9 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/biarch64.h" 1
# 10 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h" 1
# 75 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/vxworks-dummy.h" 1
# 76 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h" 2


enum stringop_alg
{
   no_stringop,
   libcall,
   rep_prefix_1_byte,
   rep_prefix_4_byte,
   rep_prefix_8_byte,
   loop_1_byte,
   loop,
   unrolled_loop
};
# 101 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h"
struct stringop_algs
{
  const enum stringop_alg unknown_size;
  const struct stringop_strategy {
    const int max;
    const enum stringop_alg alg;
  } size [4];
};



struct processor_costs {
  const int add;
  const int lea;
  const int shift_var;
  const int shift_const;
  const int mult_init[5];

  const int mult_bit;
  const int divide[5];

  int movsx;
  int movzx;
  const int large_insn;
  const int move_ratio;

  const int movzbl_load;
  const int int_load[3];


  const int int_store[3];

  const int fp_move;
  const int fp_load[3];

  const int fp_store[3];

  const int mmx_move;
  const int mmx_load[2];

  const int mmx_store[2];

  const int sse_move;
  const int sse_load[3];

  const int sse_store[3];

  const int mmxsse_to_integer;

  const int l1_cache_size;
  const int l2_cache_size;
  const int prefetch_block;
  const int simultaneous_prefetches;

  const int branch_cost;
  const int fadd;
  const int fmul;
  const int fdiv;
  const int fabs;
  const int fchs;
  const int fsqrt;


  struct stringop_algs memcpy[2], memset[2];
  const int scalar_stmt_cost;

  const int scalar_load_cost;
  const int scalar_store_cost;
  const int vec_stmt_cost;


  const int vec_to_scalar_cost;
  const int scalar_to_vec_cost;
  const int vec_align_load_cost;
  const int vec_unalign_load_cost;
  const int vec_store_cost;
  const int cond_taken_branch_cost;

  const int cond_not_taken_branch_cost;

};

extern const struct processor_costs *ix86_cost;
extern const struct processor_costs ix86_size_cost;
# 246 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h"
enum ix86_tune_indices {
  X86_TUNE_USE_LEAVE,
  X86_TUNE_PUSH_MEMORY,
  X86_TUNE_ZERO_EXTEND_WITH_AND,
  X86_TUNE_UNROLL_STRLEN,
  X86_TUNE_DEEP_BRANCH_PREDICTION,
  X86_TUNE_BRANCH_PREDICTION_HINTS,
  X86_TUNE_DOUBLE_WITH_ADD,
  X86_TUNE_USE_SAHF,
  X86_TUNE_MOVX,
  X86_TUNE_PARTIAL_REG_STALL,
  X86_TUNE_PARTIAL_FLAG_REG_STALL,
  X86_TUNE_USE_HIMODE_FIOP,
  X86_TUNE_USE_SIMODE_FIOP,
  X86_TUNE_USE_MOV0,
  X86_TUNE_USE_CLTD,
  X86_TUNE_USE_XCHGB,
  X86_TUNE_SPLIT_LONG_MOVES,
  X86_TUNE_READ_MODIFY_WRITE,
  X86_TUNE_READ_MODIFY,
  X86_TUNE_PROMOTE_QIMODE,
  X86_TUNE_FAST_PREFIX,
  X86_TUNE_SINGLE_STRINGOP,
  X86_TUNE_QIMODE_MATH,
  X86_TUNE_HIMODE_MATH,
  X86_TUNE_PROMOTE_QI_REGS,
  X86_TUNE_PROMOTE_HI_REGS,
  X86_TUNE_ADD_ESP_4,
  X86_TUNE_ADD_ESP_8,
  X86_TUNE_SUB_ESP_4,
  X86_TUNE_SUB_ESP_8,
  X86_TUNE_INTEGER_DFMODE_MOVES,
  X86_TUNE_PARTIAL_REG_DEPENDENCY,
  X86_TUNE_SSE_PARTIAL_REG_DEPENDENCY,
  X86_TUNE_SSE_UNALIGNED_MOVE_OPTIMAL,
  X86_TUNE_SSE_SPLIT_REGS,
  X86_TUNE_SSE_TYPELESS_STORES,
  X86_TUNE_SSE_LOAD0_BY_PXOR,
  X86_TUNE_MEMORY_MISMATCH_STALL,
  X86_TUNE_PROLOGUE_USING_MOVE,
  X86_TUNE_EPILOGUE_USING_MOVE,
  X86_TUNE_SHIFT1,
  X86_TUNE_USE_FFREEP,
  X86_TUNE_INTER_UNIT_MOVES,
  X86_TUNE_INTER_UNIT_CONVERSIONS,
  X86_TUNE_FOUR_JUMP_LIMIT,
  X86_TUNE_SCHEDULE,
  X86_TUNE_USE_BT,
  X86_TUNE_USE_INCDEC,
  X86_TUNE_PAD_RETURNS,
  X86_TUNE_EXT_80387_CONSTANTS,
  X86_TUNE_SHORTEN_X87_SSE,
  X86_TUNE_AVOID_VECTOR_DECODE,
  X86_TUNE_PROMOTE_HIMODE_IMUL,
  X86_TUNE_SLOW_IMUL_IMM32_MEM,
  X86_TUNE_SLOW_IMUL_IMM8,
  X86_TUNE_MOVE_M1_VIA_OR,
  X86_TUNE_NOT_UNPAIRABLE,
  X86_TUNE_NOT_VECTORMODE,
  X86_TUNE_USE_VECTOR_FP_CONVERTS,
  X86_TUNE_USE_VECTOR_CONVERTS,
  X86_TUNE_FUSE_CMP_AND_BRANCH,
  X86_TUNE_OPT_AGU,

  X86_TUNE_LAST
};

extern unsigned char ix86_tune_features[X86_TUNE_LAST];
# 399 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h"
enum ix86_arch_indices {
  X86_ARCH_CMOVE,
  X86_ARCH_CMPXCHG,
  X86_ARCH_CMPXCHG8B,
  X86_ARCH_XADD,
  X86_ARCH_BSWAP,

  X86_ARCH_LAST
};

extern unsigned char ix86_arch_features[X86_ARCH_LAST];
# 419 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h"
extern int x86_prefetch_sse;
# 434 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h"
extern int ix86_isa_flags;
# 445 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h"
extern tree x86_mfence;
# 474 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h"
enum calling_abi
{
  SYSV_ABI = 0,
  MS_ABI = 1
};


extern enum calling_abi ix86_abi;
# 510 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h"
extern const char *host_detect_local_cpu (int argc, const char **argv);
# 568 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h"
enum target_cpu_default
{
  TARGET_CPU_DEFAULT_generic = 0,

  TARGET_CPU_DEFAULT_i386,
  TARGET_CPU_DEFAULT_i486,
  TARGET_CPU_DEFAULT_pentium,
  TARGET_CPU_DEFAULT_pentium_mmx,
  TARGET_CPU_DEFAULT_pentiumpro,
  TARGET_CPU_DEFAULT_pentium2,
  TARGET_CPU_DEFAULT_pentium3,
  TARGET_CPU_DEFAULT_pentium4,
  TARGET_CPU_DEFAULT_pentium_m,
  TARGET_CPU_DEFAULT_prescott,
  TARGET_CPU_DEFAULT_nocona,
  TARGET_CPU_DEFAULT_core2,
  TARGET_CPU_DEFAULT_atom,

  TARGET_CPU_DEFAULT_geode,
  TARGET_CPU_DEFAULT_k6,
  TARGET_CPU_DEFAULT_k6_2,
  TARGET_CPU_DEFAULT_k6_3,
  TARGET_CPU_DEFAULT_athlon,
  TARGET_CPU_DEFAULT_athlon_sse,
  TARGET_CPU_DEFAULT_k8,
  TARGET_CPU_DEFAULT_amdfam10,

  TARGET_CPU_DEFAULT_max
};
# 1188 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h"
enum reg_class
{
  NO_REGS,
  AREG, DREG, CREG, BREG, SIREG, DIREG,
  AD_REGS,
  CLOBBERED_REGS,
  Q_REGS,
  NON_Q_REGS,
  INDEX_REGS,
  LEGACY_REGS,
  GENERAL_REGS,
  FP_TOP_REG, FP_SECOND_REG,
  FLOAT_REGS,
  SSE_FIRST_REG,
  SSE_REGS,
  MMX_REGS,
  FP_TOP_SSE_REGS,
  FP_SECOND_SSE_REGS,
  FLOAT_SSE_REGS,
  FLOAT_INT_REGS,
  INT_SSE_REGS,
  FLOAT_INT_SSE_REGS,
  ALL_REGS, LIM_REG_CLASSES
};
# 1579 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h"
typedef struct ix86_args {
  int words;
  int nregs;
  int regno;
  int fastcall;
  int sse_words;
  int sse_nregs;
  int warn_avx;
  int warn_sse;
  int warn_mmx;
  int sse_regno;
  int mmx_words;
  int mmx_nregs;
  int mmx_regno;
  int maybe_vaarg;
  int float_in_sse;

  enum calling_abi call_abi;

} CUMULATIVE_ARGS;
# 2030 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h"
extern int const dbx_register_map[53];
extern int const dbx64_register_map[53];
extern int const svr4_dbx_register_map[53];
# 2181 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h"
enum processor_type
{
  PROCESSOR_I386 = 0,
  PROCESSOR_I486,
  PROCESSOR_PENTIUM,
  PROCESSOR_PENTIUMPRO,
  PROCESSOR_GEODE,
  PROCESSOR_K6,
  PROCESSOR_ATHLON,
  PROCESSOR_PENTIUM4,
  PROCESSOR_K8,
  PROCESSOR_NOCONA,
  PROCESSOR_CORE2,
  PROCESSOR_GENERIC32,
  PROCESSOR_GENERIC64,
  PROCESSOR_AMDFAM10,
  PROCESSOR_ATOM,
  PROCESSOR_max
};

extern enum processor_type ix86_tune;
extern enum processor_type ix86_arch;

enum fpmath_unit
{
  FPMATH_387 = 1,
  FPMATH_SSE = 2
};

extern enum fpmath_unit ix86_fpmath;

enum tls_dialect
{
  TLS_DIALECT_GNU,
  TLS_DIALECT_GNU2,
  TLS_DIALECT_SUN
};

extern enum tls_dialect ix86_tls_dialect;

enum cmodel {
  CM_32,
  CM_SMALL,
  CM_KERNEL,
  CM_MEDIUM,
  CM_LARGE,
  CM_SMALL_PIC,
  CM_MEDIUM_PIC,
  CM_LARGE_PIC
};

extern enum cmodel ix86_cmodel;






enum asm_dialect {
  ASM_ATT,
  ASM_INTEL
};

extern enum asm_dialect ix86_asm_dialect;
extern unsigned int ix86_preferred_stack_boundary;
extern unsigned int ix86_incoming_stack_boundary;
extern int ix86_branch_cost, ix86_section_threshold;


extern enum reg_class const regclass_map[53];

extern rtx ix86_compare_op0;
extern rtx ix86_compare_op1;

enum ix86_fpcmp_strategy {
  IX86_FPCMP_SAHF,
  IX86_FPCMP_COMI,
  IX86_FPCMP_ARITH
};
# 2276 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h"
enum ix86_entity
{
  I387_TRUNC = 0,
  I387_FLOOR,
  I387_CEIL,
  I387_MASK_PM,
  MAX_386_ENTITIES
};

enum ix86_stack_slot
{
  SLOT_VIRTUAL = 0,
  SLOT_TEMP,
  SLOT_CW_STORED,
  SLOT_CW_TRUNC,
  SLOT_CW_FLOOR,
  SLOT_CW_CEIL,
  SLOT_CW_MASK_PM,
  MAX_386_STACK_LOCALS
};
# 2352 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h"
struct machine_cfa_state
{
  rtx reg;
  long offset;
};

struct machine_function {
  struct stack_local_entry *stack_locals;
  const char *some_ld_name;
  int varargs_gpr_size;
  int varargs_fpr_size;
  int optimize_mode_switching[MAX_386_ENTITIES];



  int use_fast_prologue_epilogue_nregs;


  struct machine_cfa_state cfa;



  enum calling_abi call_abi;


  unsigned int accesses_prev_frame : 1;


  unsigned int needs_cld : 1;



  unsigned int use_fast_prologue_epilogue : 1;
# 2395 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/i386.h"
  unsigned int tls_descriptor_call_expanded_p : 1;



  unsigned int static_chain_on_stack : 1;
};
# 11 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/unix.h" 1
# 12 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/att.h" 1
# 13 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/dbxelf.h" 1
# 14 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/elfos.h" 1
# 15 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/svr4.h" 1
# 16 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/linux.h" 1
# 17 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/glibc-stdint.h" 1
# 18 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/x86-64.h" 1
# 19 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/config/i386/linux64.h" 1
# 20 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/defaults.h" 1
# 945 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/defaults.h"
       
# 21 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tm.h" 2


# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/insn-constants.h" 1
# 24 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/insn-flags.h" 1
# 2011 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/insn-flags.h"
extern rtx gen_x86_fnstsw_1 (rtx);
extern rtx gen_x86_sahf_1 (rtx);
extern rtx gen_popsi1 (rtx);
extern rtx gen_movsi_insv_1 (rtx, rtx);
extern rtx gen_movdi_insv_1_rex64 (rtx, rtx);
extern rtx gen_popdi1 (rtx);
extern rtx gen_swapxf (rtx, rtx);
extern rtx gen_zero_extendhisi2_and (rtx, rtx);
extern rtx gen_zero_extendsidi2_32 (rtx, rtx);
extern rtx gen_zero_extendsidi2_rex64 (rtx, rtx);
extern rtx gen_zero_extendhidi2 (rtx, rtx);
extern rtx gen_zero_extendqidi2 (rtx, rtx);
extern rtx gen_extendsidi2_rex64 (rtx, rtx);
extern rtx gen_extendhidi2 (rtx, rtx);
extern rtx gen_extendqidi2 (rtx, rtx);
extern rtx gen_extendhisi2 (rtx, rtx);
extern rtx gen_extendqihi2 (rtx, rtx);
extern rtx gen_extendqisi2 (rtx, rtx);
extern rtx gen_truncxfsf2_i387_noop (rtx, rtx);
extern rtx gen_truncxfdf2_i387_noop (rtx, rtx);
extern rtx gen_fix_truncsfdi_sse (rtx, rtx);
extern rtx gen_fix_truncdfdi_sse (rtx, rtx);
extern rtx gen_fix_truncsfsi_sse (rtx, rtx);
extern rtx gen_fix_truncdfsi_sse (rtx, rtx);
extern rtx gen_fix_trunchi_fisttp_i387_1 (rtx, rtx);
extern rtx gen_fix_truncsi_fisttp_i387_1 (rtx, rtx);
extern rtx gen_fix_truncdi_fisttp_i387_1 (rtx, rtx);
extern rtx gen_fix_trunchi_i387_fisttp (rtx, rtx);
extern rtx gen_fix_truncsi_i387_fisttp (rtx, rtx);
extern rtx gen_fix_truncdi_i387_fisttp (rtx, rtx);
extern rtx gen_fix_trunchi_i387_fisttp_with_temp (rtx, rtx, rtx);
extern rtx gen_fix_truncsi_i387_fisttp_with_temp (rtx, rtx, rtx);
extern rtx gen_fix_truncdi_i387_fisttp_with_temp (rtx, rtx, rtx);
extern rtx gen_fix_truncdi_i387 (rtx, rtx, rtx, rtx);
extern rtx gen_fix_truncdi_i387_with_temp (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_fix_trunchi_i387 (rtx, rtx, rtx, rtx);
extern rtx gen_fix_truncsi_i387 (rtx, rtx, rtx, rtx);
extern rtx gen_fix_trunchi_i387_with_temp (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_fix_truncsi_i387_with_temp (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_x86_fnstcw_1 (rtx);
extern rtx gen_x86_fldcw_1 (rtx);
extern rtx gen_floatdisf2_i387_with_xmm (rtx, rtx, rtx);
extern rtx gen_floatdidf2_i387_with_xmm (rtx, rtx, rtx);
extern rtx gen_floatdixf2_i387_with_xmm (rtx, rtx, rtx);
extern rtx gen_addqi3_cc (rtx, rtx, rtx);
extern rtx gen_addqi_ext_1 (rtx, rtx, rtx);
extern rtx gen_divqi3 (rtx, rtx, rtx);
extern rtx gen_udivqi3 (rtx, rtx, rtx);
extern rtx gen_andqi_ext_0 (rtx, rtx, rtx);
extern rtx gen_copysignsf3_const (rtx, rtx, rtx, rtx);
extern rtx gen_copysigndf3_const (rtx, rtx, rtx, rtx);
extern rtx gen_copysigntf3_const (rtx, rtx, rtx, rtx);
extern rtx gen_copysignsf3_var (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_copysigndf3_var (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_copysigntf3_var (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_x86_64_shld (rtx, rtx, rtx);
extern rtx gen_x86_shld (rtx, rtx, rtx);
extern rtx gen_x86_64_shrd (rtx, rtx, rtx);
extern rtx gen_ashrdi3_63_rex64 (rtx, rtx, rtx);
extern rtx gen_x86_shrd (rtx, rtx, rtx);
extern rtx gen_ix86_rotldi3 (rtx, rtx, rtx);
extern rtx gen_ix86_rotrdi3 (rtx, rtx, rtx);
extern rtx gen_jump (rtx);
extern rtx gen_blockage (void);
extern rtx gen_prologue_use (rtx);
extern rtx gen_return_internal (void);
extern rtx gen_return_internal_long (void);
extern rtx gen_return_pop_internal (rtx);
extern rtx gen_return_indirect_internal (rtx);
extern rtx gen_nop (void);
extern rtx gen_vswapmov (rtx, rtx);
extern rtx gen_pad (rtx);
extern rtx gen_set_got (rtx);
extern rtx gen_set_got_labelled (rtx, rtx);
extern rtx gen_set_got_rex64 (rtx);
extern rtx gen_set_rip_rex64 (rtx, rtx);
extern rtx gen_set_got_offset_rex64 (rtx, rtx);
extern rtx gen_eh_return_internal (void);
extern rtx gen_leave (void);
extern rtx gen_leave_rex64 (void);
extern rtx gen_ctzsi2 (rtx, rtx);
extern rtx gen_ctzdi2 (rtx, rtx);
extern rtx gen_clzsi2_abm (rtx, rtx);
extern rtx gen_bsr (rtx, rtx);
extern rtx gen_popcounthi2 (rtx, rtx);
extern rtx gen_popcountsi2 (rtx, rtx);
extern rtx gen_popcountdi2 (rtx, rtx);
extern rtx gen_bswaphi_lowpart (rtx);
extern rtx gen_clzdi2_abm (rtx, rtx);
extern rtx gen_bsr_rex64 (rtx, rtx);
extern rtx gen_clzhi2_abm (rtx, rtx);
extern rtx gen_paritydi2_cmp (rtx, rtx, rtx, rtx);
extern rtx gen_paritysi2_cmp (rtx, rtx, rtx);
extern rtx gen_truncxfsf2_i387_noop_unspec (rtx, rtx);
extern rtx gen_truncxfdf2_i387_noop_unspec (rtx, rtx);
extern rtx gen_sqrtxf2 (rtx, rtx);
extern rtx gen_sqrt_extendsfxf2_i387 (rtx, rtx);
extern rtx gen_sqrt_extenddfxf2_i387 (rtx, rtx);
extern rtx gen_fpremxf4_i387 (rtx, rtx, rtx, rtx);
extern rtx gen_fprem1xf4_i387 (rtx, rtx, rtx, rtx);
extern rtx gen_sincosxf3 (rtx, rtx, rtx);
extern rtx gen_sincos_extendsfxf3_i387 (rtx, rtx, rtx);
extern rtx gen_sincos_extenddfxf3_i387 (rtx, rtx, rtx);
extern rtx gen_fptanxf4_i387 (rtx, rtx, rtx, rtx);
extern rtx gen_fptan_extendsfxf4_i387 (rtx, rtx, rtx, rtx);
extern rtx gen_fptan_extenddfxf4_i387 (rtx, rtx, rtx, rtx);
extern rtx gen_fpatan_extendsfxf3_i387 (rtx, rtx, rtx);
extern rtx gen_fpatan_extenddfxf3_i387 (rtx, rtx, rtx);
extern rtx gen_fyl2xxf3_i387 (rtx, rtx, rtx);
extern rtx gen_fyl2x_extendsfxf3_i387 (rtx, rtx, rtx);
extern rtx gen_fyl2x_extenddfxf3_i387 (rtx, rtx, rtx);
extern rtx gen_fyl2xp1xf3_i387 (rtx, rtx, rtx);
extern rtx gen_fyl2xp1_extendsfxf3_i387 (rtx, rtx, rtx);
extern rtx gen_fyl2xp1_extenddfxf3_i387 (rtx, rtx, rtx);
extern rtx gen_fxtractxf3_i387 (rtx, rtx, rtx);
extern rtx gen_fxtract_extendsfxf3_i387 (rtx, rtx, rtx);
extern rtx gen_fxtract_extenddfxf3_i387 (rtx, rtx, rtx);
extern rtx gen_sse4_1_roundsf2 (rtx, rtx, rtx);
extern rtx gen_sse4_1_rounddf2 (rtx, rtx, rtx);
extern rtx gen_rintxf2 (rtx, rtx);
extern rtx gen_fistdi2 (rtx, rtx);
extern rtx gen_fistdi2_with_temp (rtx, rtx, rtx);
extern rtx gen_fisthi2 (rtx, rtx);
extern rtx gen_fistsi2 (rtx, rtx);
extern rtx gen_fisthi2_with_temp (rtx, rtx, rtx);
extern rtx gen_fistsi2_with_temp (rtx, rtx, rtx);
extern rtx gen_frndintxf2_floor (rtx, rtx);
extern rtx gen_frndintxf2_floor_i387 (rtx, rtx, rtx, rtx);
extern rtx gen_fistdi2_floor (rtx, rtx, rtx, rtx);
extern rtx gen_fistdi2_floor_with_temp (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_fisthi2_floor (rtx, rtx, rtx, rtx);
extern rtx gen_fistsi2_floor (rtx, rtx, rtx, rtx);
extern rtx gen_fisthi2_floor_with_temp (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_fistsi2_floor_with_temp (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_frndintxf2_ceil (rtx, rtx);
extern rtx gen_frndintxf2_ceil_i387 (rtx, rtx, rtx, rtx);
extern rtx gen_fistdi2_ceil (rtx, rtx, rtx, rtx);
extern rtx gen_fistdi2_ceil_with_temp (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_fisthi2_ceil (rtx, rtx, rtx, rtx);
extern rtx gen_fistsi2_ceil (rtx, rtx, rtx, rtx);
extern rtx gen_fisthi2_ceil_with_temp (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_fistsi2_ceil_with_temp (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_frndintxf2_trunc (rtx, rtx);
extern rtx gen_frndintxf2_trunc_i387 (rtx, rtx, rtx, rtx);
extern rtx gen_frndintxf2_mask_pm (rtx, rtx);
extern rtx gen_frndintxf2_mask_pm_i387 (rtx, rtx, rtx, rtx);
extern rtx gen_fxamsf2_i387 (rtx, rtx);
extern rtx gen_fxamdf2_i387 (rtx, rtx);
extern rtx gen_fxamxf2_i387 (rtx, rtx);
extern rtx gen_fxamsf2_i387_with_temp (rtx, rtx);
extern rtx gen_fxamdf2_i387_with_temp (rtx, rtx);
extern rtx gen_cld (void);
extern rtx gen_smaxsf3 (rtx, rtx, rtx);
extern rtx gen_sminsf3 (rtx, rtx, rtx);
extern rtx gen_smaxdf3 (rtx, rtx, rtx);
extern rtx gen_smindf3 (rtx, rtx, rtx);
extern rtx gen_pro_epilogue_adjust_stack_1 (rtx, rtx, rtx);
extern rtx gen_pro_epilogue_adjust_stack_rex64 (rtx, rtx, rtx);
extern rtx gen_pro_epilogue_adjust_stack_rex64_2 (rtx, rtx, rtx, rtx);
extern rtx gen_allocate_stack_worker_32 (rtx, rtx);
extern rtx gen_allocate_stack_worker_64 (rtx, rtx);
extern rtx gen_trap (void);
extern rtx gen_stack_protect_set_si (rtx, rtx);
extern rtx gen_stack_protect_set_di (rtx, rtx);
extern rtx gen_stack_tls_protect_set_si (rtx, rtx);
extern rtx gen_stack_tls_protect_set_di (rtx, rtx);
extern rtx gen_stack_protect_test_si (rtx, rtx, rtx);
extern rtx gen_stack_protect_test_di (rtx, rtx, rtx);
extern rtx gen_stack_tls_protect_test_si (rtx, rtx, rtx);
extern rtx gen_stack_tls_protect_test_di (rtx, rtx, rtx);
extern rtx gen_sse4_2_crc32qi (rtx, rtx, rtx);
extern rtx gen_sse4_2_crc32hi (rtx, rtx, rtx);
extern rtx gen_sse4_2_crc32si (rtx, rtx, rtx);
extern rtx gen_sse4_2_crc32di (rtx, rtx, rtx);
extern rtx gen_lwp_slwpcbsi (rtx);
extern rtx gen_lwp_slwpcbdi (rtx);
extern rtx gen_sse_movntdi (rtx, rtx);
extern rtx gen_mmx_rcpv2sf2 (rtx, rtx);
extern rtx gen_mmx_rcpit1v2sf3 (rtx, rtx, rtx);
extern rtx gen_mmx_rcpit2v2sf3 (rtx, rtx, rtx);
extern rtx gen_mmx_rsqrtv2sf2 (rtx, rtx);
extern rtx gen_mmx_rsqit1v2sf3 (rtx, rtx, rtx);
extern rtx gen_mmx_haddv2sf3 (rtx, rtx, rtx);
extern rtx gen_mmx_hsubv2sf3 (rtx, rtx, rtx);
extern rtx gen_mmx_addsubv2sf3 (rtx, rtx, rtx);
extern rtx gen_mmx_gtv2sf3 (rtx, rtx, rtx);
extern rtx gen_mmx_gev2sf3 (rtx, rtx, rtx);
extern rtx gen_mmx_pf2id (rtx, rtx);
extern rtx gen_mmx_pf2iw (rtx, rtx);
extern rtx gen_mmx_pi2fw (rtx, rtx);
extern rtx gen_mmx_floatv2si2 (rtx, rtx);
extern rtx gen_mmx_pswapdv2sf2 (rtx, rtx);
extern rtx gen_mmx_ashrv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_ashrv2si3 (rtx, rtx, rtx);
extern rtx gen_mmx_lshrv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_lshrv2si3 (rtx, rtx, rtx);
extern rtx gen_mmx_lshrv1di3 (rtx, rtx, rtx);
extern rtx gen_mmx_ashlv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_ashlv2si3 (rtx, rtx, rtx);
extern rtx gen_mmx_ashlv1di3 (rtx, rtx, rtx);
extern rtx gen_mmx_gtv8qi3 (rtx, rtx, rtx);
extern rtx gen_mmx_gtv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_gtv2si3 (rtx, rtx, rtx);
extern rtx gen_mmx_andnotv8qi3 (rtx, rtx, rtx);
extern rtx gen_mmx_andnotv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_andnotv2si3 (rtx, rtx, rtx);
extern rtx gen_mmx_packsswb (rtx, rtx, rtx);
extern rtx gen_mmx_packssdw (rtx, rtx, rtx);
extern rtx gen_mmx_packuswb (rtx, rtx, rtx);
extern rtx gen_mmx_punpckhbw (rtx, rtx, rtx);
extern rtx gen_mmx_punpcklbw (rtx, rtx, rtx);
extern rtx gen_mmx_punpckhwd (rtx, rtx, rtx);
extern rtx gen_mmx_punpcklwd (rtx, rtx, rtx);
extern rtx gen_mmx_punpckhdq (rtx, rtx, rtx);
extern rtx gen_mmx_punpckldq (rtx, rtx, rtx);
extern rtx gen_mmx_pextrw (rtx, rtx, rtx);
extern rtx gen_mmx_pshufw_1 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_mmx_pswapdv2si2 (rtx, rtx);
extern rtx gen_mmx_psadbw (rtx, rtx, rtx);
extern rtx gen_mmx_pmovmskb (rtx, rtx);
extern rtx gen_movdi_to_sse (rtx, rtx);
extern rtx gen_sse2_movq128 (rtx, rtx);
extern rtx gen_avx_movntv4sf (rtx, rtx);
extern rtx gen_avx_movntv2df (rtx, rtx);
extern rtx gen_avx_movntv8sf (rtx, rtx);
extern rtx gen_avx_movntv4df (rtx, rtx);
extern rtx gen_sse_movntv4sf (rtx, rtx);
extern rtx gen_sse2_movntv2df (rtx, rtx);
extern rtx gen_avx_movntv4di (rtx, rtx);
extern rtx gen_avx_movntv2di (rtx, rtx);
extern rtx gen_sse2_movntv2di (rtx, rtx);
extern rtx gen_sse2_movntsi (rtx, rtx);
extern rtx gen_avx_lddqu256 (rtx, rtx);
extern rtx gen_avx_lddqu (rtx, rtx);
extern rtx gen_sse3_lddqu (rtx, rtx);
extern rtx gen_sse_vmaddv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse_vmsubv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse2_vmaddv2df3 (rtx, rtx, rtx);
extern rtx gen_sse2_vmsubv2df3 (rtx, rtx, rtx);
extern rtx gen_sse_vmmulv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse2_vmmulv2df3 (rtx, rtx, rtx);
extern rtx gen_avx_divv4sf3 (rtx, rtx, rtx);
extern rtx gen_avx_divv2df3 (rtx, rtx, rtx);
extern rtx gen_avx_divv8sf3 (rtx, rtx, rtx);
extern rtx gen_avx_divv4df3 (rtx, rtx, rtx);
extern rtx gen_sse_divv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse2_divv2df3 (rtx, rtx, rtx);
extern rtx gen_sse_vmdivv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse2_vmdivv2df3 (rtx, rtx, rtx);
extern rtx gen_avx_rcpv8sf2 (rtx, rtx);
extern rtx gen_sse_rcpv4sf2 (rtx, rtx);
extern rtx gen_sse_vmrcpv4sf2 (rtx, rtx, rtx);
extern rtx gen_avx_sqrtv8sf2 (rtx, rtx);
extern rtx gen_sse_sqrtv4sf2 (rtx, rtx);
extern rtx gen_sqrtv4df2 (rtx, rtx);
extern rtx gen_sqrtv2df2 (rtx, rtx);
extern rtx gen_sse_vmsqrtv4sf2 (rtx, rtx, rtx);
extern rtx gen_sse2_vmsqrtv2df2 (rtx, rtx, rtx);
extern rtx gen_avx_rsqrtv8sf2 (rtx, rtx);
extern rtx gen_sse_rsqrtv4sf2 (rtx, rtx);
extern rtx gen_sse_vmrsqrtv4sf2 (rtx, rtx, rtx);
extern rtx gen_sse_vmsmaxv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse_vmsminv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse2_vmsmaxv2df3 (rtx, rtx, rtx);
extern rtx gen_sse2_vmsminv2df3 (rtx, rtx, rtx);
extern rtx gen_avx_addsubv8sf3 (rtx, rtx, rtx);
extern rtx gen_avx_addsubv4df3 (rtx, rtx, rtx);
extern rtx gen_sse3_addsubv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse3_addsubv2df3 (rtx, rtx, rtx);
extern rtx gen_avx_haddv4df3 (rtx, rtx, rtx);
extern rtx gen_avx_hsubv4df3 (rtx, rtx, rtx);
extern rtx gen_avx_haddv8sf3 (rtx, rtx, rtx);
extern rtx gen_avx_hsubv8sf3 (rtx, rtx, rtx);
extern rtx gen_sse3_haddv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse3_hsubv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse3_haddv2df3 (rtx, rtx, rtx);
extern rtx gen_sse3_hsubv2df3 (rtx, rtx, rtx);
extern rtx gen_avx_cmppsv4sf3 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_cmppdv2df3 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_cmppsv8sf3 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_cmppdv4df3 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_cmpssv4sf3 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_cmpsdv2df3 (rtx, rtx, rtx, rtx);
extern rtx gen_sse_maskcmpsf3 (rtx, rtx, rtx, rtx);
extern rtx gen_sse2_maskcmpdf3 (rtx, rtx, rtx, rtx);
extern rtx gen_sse_maskcmpv4sf3 (rtx, rtx, rtx, rtx);
extern rtx gen_sse2_maskcmpv2df3 (rtx, rtx, rtx, rtx);
extern rtx gen_sse_vmmaskcmpv4sf3 (rtx, rtx, rtx, rtx);
extern rtx gen_sse2_vmmaskcmpv2df3 (rtx, rtx, rtx, rtx);
extern rtx gen_sse_comi (rtx, rtx);
extern rtx gen_sse2_comi (rtx, rtx);
extern rtx gen_sse_ucomi (rtx, rtx);
extern rtx gen_sse2_ucomi (rtx, rtx);
extern rtx gen_avx_andnotv4sf3 (rtx, rtx, rtx);
extern rtx gen_avx_andnotv2df3 (rtx, rtx, rtx);
extern rtx gen_avx_andnotv8sf3 (rtx, rtx, rtx);
extern rtx gen_avx_andnotv4df3 (rtx, rtx, rtx);
extern rtx gen_sse_andnotv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse2_andnotv2df3 (rtx, rtx, rtx);
extern rtx gen_fma4_fmaddv8sf4256 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmaddv4df4256 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmsubv8sf4256 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmsubv4df4256 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fnmaddv8sf4256 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fnmaddv4df4256 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fnmsubv8sf4256 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fnmsubv4df4256 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmaddsf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmadddf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmaddv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmaddv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_vmfmaddv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_vmfmaddv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmsubsf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmsubdf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmsubv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmsubv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_vmfmsubv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_vmfmsubv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fnmaddsf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fnmadddf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fnmaddv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fnmaddv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_vmfnmaddv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_vmfnmaddv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fnmsubsf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fnmsubdf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fnmsubv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fnmsubv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_vmfnmsubv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_vmfnmsubv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmaddv8sf4256 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmaddv4df4256 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmsubv8sf4256 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmsubv4df4256 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fnmaddv8sf4256 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fnmaddv4df4256 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fnmsubv8sf4256 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fnmsubv4df4256 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmaddv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmaddv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmsubv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmsubv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fnmaddv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fnmaddv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fnmsubv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fnmsubv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_vmfmaddv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_vmfmaddv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_vmfmsubv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_vmfmsubv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_vmfnmaddv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_vmfnmaddv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_vmfnmsubv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_vmfnmsubv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmaddsubv8sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmaddsubv4df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmaddsubv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmaddsubv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmsubaddv8sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmsubaddv4df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmsubaddv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4_fmsubaddv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmaddsubv8sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmaddsubv4df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmaddsubv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmaddsubv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmsubaddv8sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmsubaddv4df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmsubaddv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmsubaddv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_sse_cvtpi2ps (rtx, rtx, rtx);
extern rtx gen_sse_cvtps2pi (rtx, rtx);
extern rtx gen_sse_cvttps2pi (rtx, rtx);
extern rtx gen_sse_cvtsi2ss (rtx, rtx, rtx);
extern rtx gen_sse_cvtsi2ssq (rtx, rtx, rtx);
extern rtx gen_sse_cvtss2si (rtx, rtx);
extern rtx gen_sse_cvtss2si_2 (rtx, rtx);
extern rtx gen_sse_cvtss2siq (rtx, rtx);
extern rtx gen_sse_cvtss2siq_2 (rtx, rtx);
extern rtx gen_sse_cvttss2si (rtx, rtx);
extern rtx gen_sse_cvttss2siq (rtx, rtx);
extern rtx gen_avx_cvtdq2ps (rtx, rtx);
extern rtx gen_avx_cvtdq2ps256 (rtx, rtx);
extern rtx gen_sse2_cvtdq2ps (rtx, rtx);
extern rtx gen_avx_cvtps2dq (rtx, rtx);
extern rtx gen_avx_cvtps2dq256 (rtx, rtx);
extern rtx gen_sse2_cvtps2dq (rtx, rtx);
extern rtx gen_avx_cvttps2dq (rtx, rtx);
extern rtx gen_avx_cvttps2dq256 (rtx, rtx);
extern rtx gen_sse2_cvttps2dq (rtx, rtx);
extern rtx gen_sse2_cvtpi2pd (rtx, rtx);
extern rtx gen_sse2_cvtpd2pi (rtx, rtx);
extern rtx gen_sse2_cvttpd2pi (rtx, rtx);
extern rtx gen_sse2_cvtsi2sd (rtx, rtx, rtx);
extern rtx gen_sse2_cvtsi2sdq (rtx, rtx, rtx);
extern rtx gen_sse2_cvtsd2si (rtx, rtx);
extern rtx gen_sse2_cvtsd2si_2 (rtx, rtx);
extern rtx gen_sse2_cvtsd2siq (rtx, rtx);
extern rtx gen_sse2_cvtsd2siq_2 (rtx, rtx);
extern rtx gen_sse2_cvttsd2si (rtx, rtx);
extern rtx gen_sse2_cvttsd2siq (rtx, rtx);
extern rtx gen_avx_cvtdq2pd256 (rtx, rtx);
extern rtx gen_sse2_cvtdq2pd (rtx, rtx);
extern rtx gen_avx_cvtpd2dq256 (rtx, rtx);
extern rtx gen_avx_cvttpd2dq256 (rtx, rtx);
extern rtx gen_sse2_cvtsd2ss (rtx, rtx, rtx);
extern rtx gen_sse2_cvtss2sd (rtx, rtx, rtx);
extern rtx gen_avx_cvtpd2ps256 (rtx, rtx);
extern rtx gen_avx_cvtps2pd256 (rtx, rtx);
extern rtx gen_sse2_cvtps2pd (rtx, rtx);
extern rtx gen_sse_movhlps (rtx, rtx, rtx);
extern rtx gen_sse_movlhps (rtx, rtx, rtx);
extern rtx gen_avx_unpckhps256 (rtx, rtx, rtx);
extern rtx gen_vec_interleave_highv4sf (rtx, rtx, rtx);
extern rtx gen_avx_unpcklps256 (rtx, rtx, rtx);
extern rtx gen_vec_interleave_lowv4sf (rtx, rtx, rtx);
extern rtx gen_avx_movshdup256 (rtx, rtx);
extern rtx gen_sse3_movshdup (rtx, rtx);
extern rtx gen_avx_movsldup256 (rtx, rtx);
extern rtx gen_sse3_movsldup (rtx, rtx);
extern rtx gen_avx_shufps256_1 (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse_shufps_v4sf (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse_shufps_v4si (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse_storehps (rtx, rtx);
extern rtx gen_sse_loadhps (rtx, rtx, rtx);
extern rtx gen_sse_storelps (rtx, rtx);
extern rtx gen_sse_loadlps (rtx, rtx, rtx);
extern rtx gen_sse_movss (rtx, rtx, rtx);
extern rtx gen_vec_setv4sf_0 (rtx, rtx, rtx);
extern rtx gen_vec_setv4si_0 (rtx, rtx, rtx);
extern rtx gen_sse4_1_insertps (rtx, rtx, rtx, rtx);
extern rtx gen_vec_extract_lo_v4di (rtx, rtx);
extern rtx gen_vec_extract_lo_v4df (rtx, rtx);
extern rtx gen_vec_extract_hi_v4di (rtx, rtx);
extern rtx gen_vec_extract_hi_v4df (rtx, rtx);
extern rtx gen_vec_extract_lo_v8si (rtx, rtx);
extern rtx gen_vec_extract_lo_v8sf (rtx, rtx);
extern rtx gen_vec_extract_hi_v8si (rtx, rtx);
extern rtx gen_vec_extract_hi_v8sf (rtx, rtx);
extern rtx gen_vec_extract_lo_v16hi (rtx, rtx);
extern rtx gen_vec_extract_hi_v16hi (rtx, rtx);
extern rtx gen_vec_extract_lo_v32qi (rtx, rtx);
extern rtx gen_vec_extract_hi_v32qi (rtx, rtx);
extern rtx gen_avx_unpckhpd256 (rtx, rtx, rtx);
extern rtx gen_avx_shufpd256_1 (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vec_interleave_highv2di (rtx, rtx, rtx);
extern rtx gen_vec_interleave_lowv2di (rtx, rtx, rtx);
extern rtx gen_sse2_shufpd_v2df (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse2_shufpd_v2di (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse2_storehpd (rtx, rtx);
extern rtx gen_sse2_storelpd (rtx, rtx);
extern rtx gen_sse2_loadhpd (rtx, rtx, rtx);
extern rtx gen_sse2_loadlpd (rtx, rtx, rtx);
extern rtx gen_sse2_movsd (rtx, rtx, rtx);
extern rtx gen_vec_dupv2df (rtx, rtx);
extern rtx gen_mulv16qi3 (rtx, rtx, rtx);
extern rtx gen_mulv2di3 (rtx, rtx, rtx);
extern rtx gen_ashrv8hi3 (rtx, rtx, rtx);
extern rtx gen_ashrv4si3 (rtx, rtx, rtx);
extern rtx gen_sse2_lshrv1ti3 (rtx, rtx, rtx);
extern rtx gen_lshrv8hi3 (rtx, rtx, rtx);
extern rtx gen_lshrv4si3 (rtx, rtx, rtx);
extern rtx gen_lshrv2di3 (rtx, rtx, rtx);
extern rtx gen_sse2_ashlv1ti3 (rtx, rtx, rtx);
extern rtx gen_ashlv8hi3 (rtx, rtx, rtx);
extern rtx gen_ashlv4si3 (rtx, rtx, rtx);
extern rtx gen_ashlv2di3 (rtx, rtx, rtx);
extern rtx gen_sse2_gtv16qi3 (rtx, rtx, rtx);
extern rtx gen_sse2_gtv8hi3 (rtx, rtx, rtx);
extern rtx gen_sse2_gtv4si3 (rtx, rtx, rtx);
extern rtx gen_sse4_2_gtv2di3 (rtx, rtx, rtx);
extern rtx gen_sse2_andnotv16qi3 (rtx, rtx, rtx);
extern rtx gen_sse2_andnotv8hi3 (rtx, rtx, rtx);
extern rtx gen_sse2_andnotv4si3 (rtx, rtx, rtx);
extern rtx gen_sse2_andnotv2di3 (rtx, rtx, rtx);
extern rtx gen_sse2_packsswb (rtx, rtx, rtx);
extern rtx gen_sse2_packssdw (rtx, rtx, rtx);
extern rtx gen_sse2_packuswb (rtx, rtx, rtx);
extern rtx gen_vec_interleave_highv16qi (rtx, rtx, rtx);
extern rtx gen_vec_interleave_lowv16qi (rtx, rtx, rtx);
extern rtx gen_vec_interleave_highv8hi (rtx, rtx, rtx);
extern rtx gen_vec_interleave_lowv8hi (rtx, rtx, rtx);
extern rtx gen_vec_interleave_highv4si (rtx, rtx, rtx);
extern rtx gen_vec_interleave_lowv4si (rtx, rtx, rtx);
extern rtx gen_sse2_pshufd_1 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse2_pshuflw_1 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse2_pshufhw_1 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse2_loadld (rtx, rtx, rtx);
extern rtx gen_sse2_stored (rtx, rtx);
extern rtx gen_vec_concatv2di (rtx, rtx, rtx);
extern rtx gen_sse2_psadbw (rtx, rtx, rtx);
extern rtx gen_avx_movmskps256 (rtx, rtx);
extern rtx gen_avx_movmskpd256 (rtx, rtx);
extern rtx gen_sse_movmskps (rtx, rtx);
extern rtx gen_sse2_movmskpd (rtx, rtx);
extern rtx gen_sse2_pmovmskb (rtx, rtx);
extern rtx gen_sse_ldmxcsr (rtx);
extern rtx gen_sse_stmxcsr (rtx);
extern rtx gen_sse2_clflush (rtx);
extern rtx gen_sse3_mwait (rtx, rtx);
extern rtx gen_sse3_monitor (rtx, rtx, rtx);
extern rtx gen_sse3_monitor64 (rtx, rtx, rtx);
extern rtx gen_ssse3_phaddwv8hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phaddwv4hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phadddv4si3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phadddv2si3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phaddswv8hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phaddswv4hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phsubwv8hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phsubwv4hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phsubdv4si3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phsubdv2si3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phsubswv8hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phsubswv4hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_pmaddubsw128 (rtx, rtx, rtx);
extern rtx gen_ssse3_pmaddubsw (rtx, rtx, rtx);
extern rtx gen_ssse3_pshufbv16qi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_pshufbv8qi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_psignv16qi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_psignv8hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_psignv4si3 (rtx, rtx, rtx);
extern rtx gen_ssse3_psignv8qi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_psignv4hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_psignv2si3 (rtx, rtx, rtx);
extern rtx gen_ssse3_palignrti (rtx, rtx, rtx, rtx);
extern rtx gen_ssse3_palignrdi (rtx, rtx, rtx, rtx);
extern rtx gen_absv16qi2 (rtx, rtx);
extern rtx gen_absv8hi2 (rtx, rtx);
extern rtx gen_absv4si2 (rtx, rtx);
extern rtx gen_absv8qi2 (rtx, rtx);
extern rtx gen_absv4hi2 (rtx, rtx);
extern rtx gen_absv2si2 (rtx, rtx);
extern rtx gen_sse4a_movntsf (rtx, rtx);
extern rtx gen_sse4a_movntdf (rtx, rtx);
extern rtx gen_sse4a_vmmovntv4sf (rtx, rtx);
extern rtx gen_sse4a_vmmovntv2df (rtx, rtx);
extern rtx gen_sse4a_extrqi (rtx, rtx, rtx, rtx);
extern rtx gen_sse4a_extrq (rtx, rtx, rtx);
extern rtx gen_sse4a_insertqi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse4a_insertq (rtx, rtx, rtx);
extern rtx gen_avx_blendps (rtx, rtx, rtx, rtx);
extern rtx gen_avx_blendpd (rtx, rtx, rtx, rtx);
extern rtx gen_avx_blendps256 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_blendpd256 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_blendvps (rtx, rtx, rtx, rtx);
extern rtx gen_avx_blendvpd (rtx, rtx, rtx, rtx);
extern rtx gen_avx_blendvps256 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_blendvpd256 (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_blendps (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_blendpd (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_blendvps (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_blendvpd (rtx, rtx, rtx, rtx);
extern rtx gen_avx_dpps (rtx, rtx, rtx, rtx);
extern rtx gen_avx_dppd (rtx, rtx, rtx, rtx);
extern rtx gen_avx_dpps256 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_dppd256 (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_dpps (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_dppd (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_movntdqa (rtx, rtx);
extern rtx gen_sse4_1_mpsadbw (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_packusdw (rtx, rtx, rtx);
extern rtx gen_sse4_1_pblendvb (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_pblendw (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_phminposuw (rtx, rtx);
extern rtx gen_sse4_1_extendv8qiv8hi2 (rtx, rtx);
extern rtx gen_sse4_1_extendv4qiv4si2 (rtx, rtx);
extern rtx gen_sse4_1_extendv2qiv2di2 (rtx, rtx);
extern rtx gen_sse4_1_extendv4hiv4si2 (rtx, rtx);
extern rtx gen_sse4_1_extendv2hiv2di2 (rtx, rtx);
extern rtx gen_sse4_1_extendv2siv2di2 (rtx, rtx);
extern rtx gen_sse4_1_zero_extendv8qiv8hi2 (rtx, rtx);
extern rtx gen_sse4_1_zero_extendv4qiv4si2 (rtx, rtx);
extern rtx gen_sse4_1_zero_extendv2qiv2di2 (rtx, rtx);
extern rtx gen_sse4_1_zero_extendv4hiv4si2 (rtx, rtx);
extern rtx gen_sse4_1_zero_extendv2hiv2di2 (rtx, rtx);
extern rtx gen_sse4_1_zero_extendv2siv2di2 (rtx, rtx);
extern rtx gen_avx_vtestps (rtx, rtx);
extern rtx gen_avx_vtestpd (rtx, rtx);
extern rtx gen_avx_vtestps256 (rtx, rtx);
extern rtx gen_avx_vtestpd256 (rtx, rtx);
extern rtx gen_avx_ptest256 (rtx, rtx);
extern rtx gen_sse4_1_ptest (rtx, rtx);
extern rtx gen_avx_roundps256 (rtx, rtx, rtx);
extern rtx gen_avx_roundpd256 (rtx, rtx, rtx);
extern rtx gen_sse4_1_roundps (rtx, rtx, rtx);
extern rtx gen_sse4_1_roundpd (rtx, rtx, rtx);
extern rtx gen_sse4_1_roundss (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_roundsd (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_2_pcmpestr (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse4_2_pcmpestri (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse4_2_pcmpestrm (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse4_2_pcmpestr_cconly (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse4_2_pcmpistr (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse4_2_pcmpistri (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_2_pcmpistrm (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_2_pcmpistr_cconly (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_xop_pmacsww (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pmacssww (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pmacsdd (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pmacssdd (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pmacssdql (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pmacssdqh (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pmacsdql (rtx, rtx, rtx, rtx);
extern rtx gen_xop_mulv2div2di3_low (rtx, rtx, rtx);
extern rtx gen_xop_pmacsdqh (rtx, rtx, rtx, rtx);
extern rtx gen_xop_mulv2div2di3_high (rtx, rtx, rtx);
extern rtx gen_xop_pmacsswd (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pmacswd (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pmadcsswd (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pmadcswd (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v16qi (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v8hi (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v4si (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v2di (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v4sf (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v2df (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v32qi256 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v16hi256 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v8si256 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v4di256 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v8sf256 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v4df256 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_phaddbw (rtx, rtx);
extern rtx gen_xop_phaddbd (rtx, rtx);
extern rtx gen_xop_phaddbq (rtx, rtx);
extern rtx gen_xop_phaddwd (rtx, rtx);
extern rtx gen_xop_phaddwq (rtx, rtx);
extern rtx gen_xop_phadddq (rtx, rtx);
extern rtx gen_xop_phaddubw (rtx, rtx);
extern rtx gen_xop_phaddubd (rtx, rtx);
extern rtx gen_xop_phaddubq (rtx, rtx);
extern rtx gen_xop_phadduwd (rtx, rtx);
extern rtx gen_xop_phadduwq (rtx, rtx);
extern rtx gen_xop_phaddudq (rtx, rtx);
extern rtx gen_xop_phsubbw (rtx, rtx);
extern rtx gen_xop_phsubwd (rtx, rtx);
extern rtx gen_xop_phsubdq (rtx, rtx);
extern rtx gen_xop_pperm (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pperm_pack_v2di_v4si (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pperm_pack_v4si_v8hi (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pperm_pack_v8hi_v16qi (rtx, rtx, rtx, rtx);
extern rtx gen_xop_rotlv16qi3 (rtx, rtx, rtx);
extern rtx gen_xop_rotlv8hi3 (rtx, rtx, rtx);
extern rtx gen_xop_rotlv4si3 (rtx, rtx, rtx);
extern rtx gen_xop_rotlv2di3 (rtx, rtx, rtx);
extern rtx gen_xop_rotrv16qi3 (rtx, rtx, rtx);
extern rtx gen_xop_rotrv8hi3 (rtx, rtx, rtx);
extern rtx gen_xop_rotrv4si3 (rtx, rtx, rtx);
extern rtx gen_xop_rotrv2di3 (rtx, rtx, rtx);
extern rtx gen_xop_vrotlv16qi3 (rtx, rtx, rtx);
extern rtx gen_xop_vrotlv8hi3 (rtx, rtx, rtx);
extern rtx gen_xop_vrotlv4si3 (rtx, rtx, rtx);
extern rtx gen_xop_vrotlv2di3 (rtx, rtx, rtx);
extern rtx gen_xop_ashlv16qi3 (rtx, rtx, rtx);
extern rtx gen_xop_ashlv8hi3 (rtx, rtx, rtx);
extern rtx gen_xop_ashlv4si3 (rtx, rtx, rtx);
extern rtx gen_xop_ashlv2di3 (rtx, rtx, rtx);
extern rtx gen_xop_lshlv16qi3 (rtx, rtx, rtx);
extern rtx gen_xop_lshlv8hi3 (rtx, rtx, rtx);
extern rtx gen_xop_lshlv4si3 (rtx, rtx, rtx);
extern rtx gen_xop_lshlv2di3 (rtx, rtx, rtx);
extern rtx gen_xop_frczv4sf2 (rtx, rtx);
extern rtx gen_xop_frczv2df2 (rtx, rtx);
extern rtx gen_xop_vmfrczv4sf2 (rtx, rtx, rtx);
extern rtx gen_xop_vmfrczv2df2 (rtx, rtx, rtx);
extern rtx gen_xop_frczv8sf2256 (rtx, rtx);
extern rtx gen_xop_frczv4df2256 (rtx, rtx);
extern rtx gen_xop_maskcmpv16qi3 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_maskcmpv8hi3 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_maskcmpv4si3 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_maskcmpv2di3 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_maskcmp_unsv16qi3 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_maskcmp_unsv8hi3 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_maskcmp_unsv4si3 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_maskcmp_unsv2di3 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_maskcmp_uns2v16qi3 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_maskcmp_uns2v8hi3 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_maskcmp_uns2v4si3 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_maskcmp_uns2v2di3 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcom_tfv16qi3 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcom_tfv8hi3 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcom_tfv4si3 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcom_tfv2di3 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_vpermil2v4sf3 (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_xop_vpermil2v2df3 (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_xop_vpermil2v8sf3 (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_xop_vpermil2v4df3 (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_aesenc (rtx, rtx, rtx);
extern rtx gen_aesenclast (rtx, rtx, rtx);
extern rtx gen_aesdec (rtx, rtx, rtx);
extern rtx gen_aesdeclast (rtx, rtx, rtx);
extern rtx gen_aesimc (rtx, rtx);
extern rtx gen_aeskeygenassist (rtx, rtx, rtx);
extern rtx gen_pclmulqdq (rtx, rtx, rtx, rtx);
extern rtx gen_vec_dupv8si (rtx, rtx);
extern rtx gen_vec_dupv8sf (rtx, rtx);
extern rtx gen_vec_dupv4di (rtx, rtx);
extern rtx gen_vec_dupv4df (rtx, rtx);
extern rtx gen_avx_vbroadcastf128_v32qi (rtx, rtx);
extern rtx gen_avx_vbroadcastf128_v16hi (rtx, rtx);
extern rtx gen_avx_vbroadcastf128_v8si (rtx, rtx);
extern rtx gen_avx_vbroadcastf128_v4di (rtx, rtx);
extern rtx gen_avx_vbroadcastf128_v8sf (rtx, rtx);
extern rtx gen_avx_vbroadcastf128_v4df (rtx, rtx);
extern rtx gen_avx_vpermilvarv4sf3 (rtx, rtx, rtx);
extern rtx gen_avx_vpermilvarv2df3 (rtx, rtx, rtx);
extern rtx gen_avx_vpermilvarv8sf3 (rtx, rtx, rtx);
extern rtx gen_avx_vpermilvarv4df3 (rtx, rtx, rtx);
extern rtx gen_vec_set_lo_v4di (rtx, rtx, rtx);
extern rtx gen_vec_set_lo_v4df (rtx, rtx, rtx);
extern rtx gen_vec_set_hi_v4di (rtx, rtx, rtx);
extern rtx gen_vec_set_hi_v4df (rtx, rtx, rtx);
extern rtx gen_vec_set_lo_v8si (rtx, rtx, rtx);
extern rtx gen_vec_set_lo_v8sf (rtx, rtx, rtx);
extern rtx gen_vec_set_hi_v8si (rtx, rtx, rtx);
extern rtx gen_vec_set_hi_v8sf (rtx, rtx, rtx);
extern rtx gen_vec_set_lo_v16hi (rtx, rtx, rtx);
extern rtx gen_vec_set_hi_v16hi (rtx, rtx, rtx);
extern rtx gen_vec_set_lo_v32qi (rtx, rtx, rtx);
extern rtx gen_vec_set_hi_v32qi (rtx, rtx, rtx);
extern rtx gen_avx_maskloadps (rtx, rtx, rtx);
extern rtx gen_avx_maskloadpd (rtx, rtx, rtx);
extern rtx gen_avx_maskloadps256 (rtx, rtx, rtx);
extern rtx gen_avx_maskloadpd256 (rtx, rtx, rtx);
extern rtx gen_avx_maskstoreps (rtx, rtx, rtx);
extern rtx gen_avx_maskstorepd (rtx, rtx, rtx);
extern rtx gen_avx_maskstoreps256 (rtx, rtx, rtx);
extern rtx gen_avx_maskstorepd256 (rtx, rtx, rtx);
extern rtx gen_avx_si256_si (rtx, rtx);
extern rtx gen_avx_ps256_ps (rtx, rtx);
extern rtx gen_avx_pd256_pd (rtx, rtx);
extern rtx gen_avx_si_si256 (rtx, rtx);
extern rtx gen_avx_ps_ps256 (rtx, rtx);
extern rtx gen_avx_pd_pd256 (rtx, rtx);
extern rtx gen_memory_barrier_nosse (rtx);
extern rtx gen_sync_double_compare_and_swapdi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sync_double_compare_and_swapti (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sync_old_addqi (rtx, rtx, rtx);
extern rtx gen_sync_old_addhi (rtx, rtx, rtx);
extern rtx gen_sync_old_addsi (rtx, rtx, rtx);
extern rtx gen_sync_old_adddi (rtx, rtx, rtx);
extern rtx gen_sync_lock_test_and_setqi (rtx, rtx, rtx);
extern rtx gen_sync_lock_test_and_sethi (rtx, rtx, rtx);
extern rtx gen_sync_lock_test_and_setsi (rtx, rtx, rtx);
extern rtx gen_sync_lock_test_and_setdi (rtx, rtx, rtx);
extern rtx gen_sync_addqi (rtx, rtx);
extern rtx gen_sync_addhi (rtx, rtx);
extern rtx gen_sync_addsi (rtx, rtx);
extern rtx gen_sync_adddi (rtx, rtx);
extern rtx gen_sync_subqi (rtx, rtx);
extern rtx gen_sync_subhi (rtx, rtx);
extern rtx gen_sync_subsi (rtx, rtx);
extern rtx gen_sync_subdi (rtx, rtx);
extern rtx gen_sync_andqi (rtx, rtx);
extern rtx gen_sync_iorqi (rtx, rtx);
extern rtx gen_sync_xorqi (rtx, rtx);
extern rtx gen_sync_andhi (rtx, rtx);
extern rtx gen_sync_iorhi (rtx, rtx);
extern rtx gen_sync_xorhi (rtx, rtx);
extern rtx gen_sync_andsi (rtx, rtx);
extern rtx gen_sync_iorsi (rtx, rtx);
extern rtx gen_sync_xorsi (rtx, rtx);
extern rtx gen_sync_anddi (rtx, rtx);
extern rtx gen_sync_iordi (rtx, rtx);
extern rtx gen_sync_xordi (rtx, rtx);
extern rtx gen_cbranchqi4 (rtx, rtx, rtx, rtx);
extern rtx gen_cbranchhi4 (rtx, rtx, rtx, rtx);
extern rtx gen_cbranchsi4 (rtx, rtx, rtx, rtx);
extern rtx gen_cbranchdi4 (rtx, rtx, rtx, rtx);
extern rtx gen_cbranchti4 (rtx, rtx, rtx, rtx);
extern rtx gen_cstoreqi4 (rtx, rtx, rtx, rtx);
extern rtx gen_cstorehi4 (rtx, rtx, rtx, rtx);
extern rtx gen_cstoresi4 (rtx, rtx, rtx, rtx);
extern rtx gen_cstoredi4 (rtx, rtx, rtx, rtx);
extern rtx gen_cmpsi_1 (rtx, rtx);
extern rtx gen_cmpdi_1 (rtx, rtx);
extern rtx gen_cmpqi_ext_3 (rtx, rtx);
extern rtx gen_cbranchxf4 (rtx, rtx, rtx, rtx);
extern rtx gen_cstorexf4 (rtx, rtx, rtx, rtx);
extern rtx gen_cbranchsf4 (rtx, rtx, rtx, rtx);
extern rtx gen_cbranchdf4 (rtx, rtx, rtx, rtx);
extern rtx gen_cstoresf4 (rtx, rtx, rtx, rtx);
extern rtx gen_cstoredf4 (rtx, rtx, rtx, rtx);
extern rtx gen_cbranchcc4 (rtx, rtx, rtx, rtx);
extern rtx gen_cstorecc4 (rtx, rtx, rtx, rtx);
extern rtx gen_movsi (rtx, rtx);
extern rtx gen_movhi (rtx, rtx);
extern rtx gen_movstricthi (rtx, rtx);
extern rtx gen_movqi (rtx, rtx);
extern rtx gen_movstrictqi (rtx, rtx);
extern rtx gen_movdi (rtx, rtx);
extern rtx gen_movoi (rtx, rtx);
extern rtx gen_movti (rtx, rtx);
extern rtx gen_movcdi (rtx, rtx);
extern rtx gen_movsf (rtx, rtx);
extern rtx gen_movdf (rtx, rtx);
extern rtx gen_movxf (rtx, rtx);
extern rtx gen_movtf (rtx, rtx);
extern rtx gen_zero_extendhisi2 (rtx, rtx);
extern rtx gen_zero_extendqihi2 (rtx, rtx);
extern rtx gen_zero_extendqisi2 (rtx, rtx);
extern rtx gen_zero_extendsidi2 (rtx, rtx);
extern rtx gen_extendsidi2 (rtx, rtx);
extern rtx gen_extendsfdf2 (rtx, rtx);
extern rtx gen_extendsfxf2 (rtx, rtx);
extern rtx gen_extenddfxf2 (rtx, rtx);
extern rtx gen_truncdfsf2 (rtx, rtx);
extern rtx gen_truncdfsf2_with_temp (rtx, rtx, rtx);
extern rtx gen_truncxfsf2 (rtx, rtx);
extern rtx gen_truncxfdf2 (rtx, rtx);
extern rtx gen_fix_truncxfdi2 (rtx, rtx);
extern rtx gen_fix_truncsfdi2 (rtx, rtx);
extern rtx gen_fix_truncdfdi2 (rtx, rtx);
extern rtx gen_fix_truncxfsi2 (rtx, rtx);
extern rtx gen_fix_truncsfsi2 (rtx, rtx);
extern rtx gen_fix_truncdfsi2 (rtx, rtx);
extern rtx gen_fix_truncsfhi2 (rtx, rtx);
extern rtx gen_fix_truncdfhi2 (rtx, rtx);
extern rtx gen_fix_truncxfhi2 (rtx, rtx);
extern rtx gen_fixuns_truncsfsi2 (rtx, rtx);
extern rtx gen_fixuns_truncdfsi2 (rtx, rtx);
extern rtx gen_fixuns_truncsfhi2 (rtx, rtx);
extern rtx gen_fixuns_truncdfhi2 (rtx, rtx);
extern rtx gen_floathisf2 (rtx, rtx);
extern rtx gen_floathidf2 (rtx, rtx);
extern rtx gen_floathixf2 (rtx, rtx);
extern rtx gen_floatsisf2 (rtx, rtx);
extern rtx gen_floatdisf2 (rtx, rtx);
extern rtx gen_floatsidf2 (rtx, rtx);
extern rtx gen_floatdidf2 (rtx, rtx);
extern rtx gen_floatsixf2 (rtx, rtx);
extern rtx gen_floatdixf2 (rtx, rtx);
extern rtx gen_floatunssisf2 (rtx, rtx);
extern rtx gen_floatunssidf2 (rtx, rtx);
extern rtx gen_floatunssixf2 (rtx, rtx);
extern rtx gen_floatunsdisf2 (rtx, rtx);
extern rtx gen_floatunsdidf2 (rtx, rtx);
extern rtx gen_addqi3 (rtx, rtx, rtx);
extern rtx gen_addhi3 (rtx, rtx, rtx);
extern rtx gen_addsi3 (rtx, rtx, rtx);
extern rtx gen_adddi3 (rtx, rtx, rtx);
extern rtx gen_addti3 (rtx, rtx, rtx);
extern rtx gen_subqi3 (rtx, rtx, rtx);
extern rtx gen_subhi3 (rtx, rtx, rtx);
extern rtx gen_subsi3 (rtx, rtx, rtx);
extern rtx gen_subdi3 (rtx, rtx, rtx);
extern rtx gen_subti3 (rtx, rtx, rtx);
extern rtx gen_addqi3_carry (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_subqi3_carry (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_addhi3_carry (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_subhi3_carry (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_addsi3_carry (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_subsi3_carry (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_adddi3_carry (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_subdi3_carry (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_addxf3 (rtx, rtx, rtx);
extern rtx gen_subxf3 (rtx, rtx, rtx);
extern rtx gen_addsf3 (rtx, rtx, rtx);
extern rtx gen_subsf3 (rtx, rtx, rtx);
extern rtx gen_adddf3 (rtx, rtx, rtx);
extern rtx gen_subdf3 (rtx, rtx, rtx);
extern rtx gen_mulhi3 (rtx, rtx, rtx);
extern rtx gen_mulsi3 (rtx, rtx, rtx);
extern rtx gen_muldi3 (rtx, rtx, rtx);
extern rtx gen_mulqi3 (rtx, rtx, rtx);
extern rtx gen_mulsidi3 (rtx, rtx, rtx);
extern rtx gen_umulsidi3 (rtx, rtx, rtx);
extern rtx gen_mulditi3 (rtx, rtx, rtx);
extern rtx gen_umulditi3 (rtx, rtx, rtx);
extern rtx gen_mulqihi3 (rtx, rtx, rtx);
extern rtx gen_umulqihi3 (rtx, rtx, rtx);
extern rtx gen_smulsi3_highpart (rtx, rtx, rtx);
extern rtx gen_umulsi3_highpart (rtx, rtx, rtx);
extern rtx gen_smuldi3_highpart (rtx, rtx, rtx);
extern rtx gen_umuldi3_highpart (rtx, rtx, rtx);
extern rtx gen_mulxf3 (rtx, rtx, rtx);
extern rtx gen_mulsf3 (rtx, rtx, rtx);
extern rtx gen_muldf3 (rtx, rtx, rtx);
extern rtx gen_divxf3 (rtx, rtx, rtx);
extern rtx gen_divdf3 (rtx, rtx, rtx);
extern rtx gen_divsf3 (rtx, rtx, rtx);
extern rtx gen_divmodhi4 (rtx, rtx, rtx, rtx);
extern rtx gen_divmodsi4 (rtx, rtx, rtx, rtx);
extern rtx gen_divmoddi4 (rtx, rtx, rtx, rtx);
extern rtx gen_udivmodhi4 (rtx, rtx, rtx, rtx);
extern rtx gen_udivmodsi4 (rtx, rtx, rtx, rtx);
extern rtx gen_udivmoddi4 (rtx, rtx, rtx, rtx);
extern rtx gen_testsi_ccno_1 (rtx, rtx);
extern rtx gen_testqi_ccz_1 (rtx, rtx);
extern rtx gen_testqi_ext_ccno_0 (rtx, rtx);
extern rtx gen_andqi3 (rtx, rtx, rtx);
extern rtx gen_andhi3 (rtx, rtx, rtx);
extern rtx gen_andsi3 (rtx, rtx, rtx);
extern rtx gen_anddi3 (rtx, rtx, rtx);
extern rtx gen_iorqi3 (rtx, rtx, rtx);
extern rtx gen_xorqi3 (rtx, rtx, rtx);
extern rtx gen_iorhi3 (rtx, rtx, rtx);
extern rtx gen_xorhi3 (rtx, rtx, rtx);
extern rtx gen_iorsi3 (rtx, rtx, rtx);
extern rtx gen_xorsi3 (rtx, rtx, rtx);
extern rtx gen_iordi3 (rtx, rtx, rtx);
extern rtx gen_xordi3 (rtx, rtx, rtx);
extern rtx gen_xorqi_cc_ext_1 (rtx, rtx, rtx);
extern rtx gen_negqi2 (rtx, rtx);
extern rtx gen_neghi2 (rtx, rtx);
extern rtx gen_negsi2 (rtx, rtx);
extern rtx gen_negdi2 (rtx, rtx);
extern rtx gen_negti2 (rtx, rtx);
extern rtx gen_abssf2 (rtx, rtx);
extern rtx gen_negsf2 (rtx, rtx);
extern rtx gen_absdf2 (rtx, rtx);
extern rtx gen_negdf2 (rtx, rtx);
extern rtx gen_absxf2 (rtx, rtx);
extern rtx gen_negxf2 (rtx, rtx);
extern rtx gen_abstf2 (rtx, rtx);
extern rtx gen_negtf2 (rtx, rtx);
extern rtx gen_copysignsf3 (rtx, rtx, rtx);
extern rtx gen_copysigndf3 (rtx, rtx, rtx);
extern rtx gen_copysigntf3 (rtx, rtx, rtx);
extern rtx gen_one_cmplqi2 (rtx, rtx);
extern rtx gen_one_cmplhi2 (rtx, rtx);
extern rtx gen_one_cmplsi2 (rtx, rtx);
extern rtx gen_one_cmpldi2 (rtx, rtx);
extern rtx gen_ashlti3 (rtx, rtx, rtx);
extern rtx gen_x86_64_shift_adj_1 (rtx, rtx, rtx, rtx);
extern rtx gen_x86_64_shift_adj_2 (rtx, rtx, rtx);
extern rtx gen_ashldi3 (rtx, rtx, rtx);
extern rtx gen_x86_shift_adj_1 (rtx, rtx, rtx, rtx);
extern rtx gen_x86_shift_adj_2 (rtx, rtx, rtx);
extern rtx gen_ashlsi3 (rtx, rtx, rtx);
extern rtx gen_ashlhi3 (rtx, rtx, rtx);
extern rtx gen_ashlqi3 (rtx, rtx, rtx);
extern rtx gen_ashrti3 (rtx, rtx, rtx);
extern rtx gen_ashrdi3 (rtx, rtx, rtx);
extern rtx gen_x86_64_shift_adj_3 (rtx, rtx, rtx);
extern rtx gen_x86_shift_adj_3 (rtx, rtx, rtx);
extern rtx gen_ashrsi3_31 (rtx, rtx, rtx);
extern rtx gen_ashrsi3 (rtx, rtx, rtx);
extern rtx gen_ashrhi3 (rtx, rtx, rtx);
extern rtx gen_ashrqi3 (rtx, rtx, rtx);
extern rtx gen_lshrti3 (rtx, rtx, rtx);
extern rtx gen_lshrdi3 (rtx, rtx, rtx);
extern rtx gen_lshrsi3 (rtx, rtx, rtx);
extern rtx gen_lshrhi3 (rtx, rtx, rtx);
extern rtx gen_lshrqi3 (rtx, rtx, rtx);
extern rtx gen_rotldi3 (rtx, rtx, rtx);
extern rtx gen_rotlsi3 (rtx, rtx, rtx);
extern rtx gen_rotlhi3 (rtx, rtx, rtx);
extern rtx gen_rotlqi3 (rtx, rtx, rtx);
extern rtx gen_rotrdi3 (rtx, rtx, rtx);
extern rtx gen_rotrsi3 (rtx, rtx, rtx);
extern rtx gen_rotrhi3 (rtx, rtx, rtx);
extern rtx gen_rotrqi3 (rtx, rtx, rtx);
extern rtx gen_extv (rtx, rtx, rtx, rtx);
extern rtx gen_extzv (rtx, rtx, rtx, rtx);
extern rtx gen_insv (rtx, rtx, rtx, rtx);
extern rtx gen_indirect_jump (rtx);
extern rtx gen_tablejump (rtx, rtx);

extern rtx gen_call_pop (rtx, rtx, rtx, rtx);

extern rtx gen_call (rtx, rtx, rtx);

extern rtx gen_sibcall (rtx, rtx, rtx);

extern rtx gen_call_value_pop (rtx, rtx, rtx, rtx, rtx);

extern rtx gen_call_value (rtx, rtx, rtx, rtx);

extern rtx gen_sibcall_value (rtx, rtx, rtx, rtx);
extern rtx gen_untyped_call (rtx, rtx, rtx);
extern rtx gen_memory_blockage (void);
extern rtx gen_return (void);
extern rtx gen_prologue (void);
extern rtx gen_epilogue (void);
extern rtx gen_sibcall_epilogue (void);
extern rtx gen_eh_return (rtx);
extern rtx gen_ffssi2 (rtx, rtx);
extern rtx gen_ffs_cmove (rtx, rtx);
extern rtx gen_ffsdi2 (rtx, rtx);
extern rtx gen_clzsi2 (rtx, rtx);
extern rtx gen_bswapsi2 (rtx, rtx);
extern rtx gen_bswapdi2 (rtx, rtx);
extern rtx gen_clzdi2 (rtx, rtx);
extern rtx gen_clzhi2 (rtx, rtx);
extern rtx gen_paritydi2 (rtx, rtx);
extern rtx gen_paritysi2 (rtx, rtx);
extern rtx gen_tls_global_dynamic_32 (rtx, rtx);
extern rtx gen_tls_global_dynamic_64 (rtx, rtx);
extern rtx gen_tls_local_dynamic_base_32 (rtx);
extern rtx gen_tls_local_dynamic_base_64 (rtx);
extern rtx gen_tls_dynamic_gnu2_32 (rtx, rtx, rtx);
extern rtx gen_tls_dynamic_gnu2_64 (rtx, rtx);
extern rtx gen_rsqrtsf2 (rtx, rtx);
extern rtx gen_sqrtsf2 (rtx, rtx);
extern rtx gen_sqrtdf2 (rtx, rtx);
extern rtx gen_fmodxf3 (rtx, rtx, rtx);
extern rtx gen_fmodsf3 (rtx, rtx, rtx);
extern rtx gen_fmoddf3 (rtx, rtx, rtx);
extern rtx gen_remainderxf3 (rtx, rtx, rtx);
extern rtx gen_remaindersf3 (rtx, rtx, rtx);
extern rtx gen_remainderdf3 (rtx, rtx, rtx);
extern rtx gen_sincossf3 (rtx, rtx, rtx);
extern rtx gen_sincosdf3 (rtx, rtx, rtx);
extern rtx gen_tanxf2 (rtx, rtx);
extern rtx gen_tansf2 (rtx, rtx);
extern rtx gen_tandf2 (rtx, rtx);
extern rtx gen_atan2xf3 (rtx, rtx, rtx);
extern rtx gen_atan2sf3 (rtx, rtx, rtx);
extern rtx gen_atan2df3 (rtx, rtx, rtx);
extern rtx gen_atanxf2 (rtx, rtx);
extern rtx gen_atansf2 (rtx, rtx);
extern rtx gen_atandf2 (rtx, rtx);
extern rtx gen_asinxf2 (rtx, rtx);
extern rtx gen_asinsf2 (rtx, rtx);
extern rtx gen_asindf2 (rtx, rtx);
extern rtx gen_acosxf2 (rtx, rtx);
extern rtx gen_acossf2 (rtx, rtx);
extern rtx gen_acosdf2 (rtx, rtx);
extern rtx gen_logxf2 (rtx, rtx);
extern rtx gen_logsf2 (rtx, rtx);
extern rtx gen_logdf2 (rtx, rtx);
extern rtx gen_log10xf2 (rtx, rtx);
extern rtx gen_log10sf2 (rtx, rtx);
extern rtx gen_log10df2 (rtx, rtx);
extern rtx gen_log2xf2 (rtx, rtx);
extern rtx gen_log2sf2 (rtx, rtx);
extern rtx gen_log2df2 (rtx, rtx);
extern rtx gen_log1pxf2 (rtx, rtx);
extern rtx gen_log1psf2 (rtx, rtx);
extern rtx gen_log1pdf2 (rtx, rtx);
extern rtx gen_logbxf2 (rtx, rtx);
extern rtx gen_logbsf2 (rtx, rtx);
extern rtx gen_logbdf2 (rtx, rtx);
extern rtx gen_ilogbxf2 (rtx, rtx);
extern rtx gen_ilogbsf2 (rtx, rtx);
extern rtx gen_ilogbdf2 (rtx, rtx);
extern rtx gen_expNcorexf3 (rtx, rtx, rtx);
extern rtx gen_expxf2 (rtx, rtx);
extern rtx gen_expsf2 (rtx, rtx);
extern rtx gen_expdf2 (rtx, rtx);
extern rtx gen_exp10xf2 (rtx, rtx);
extern rtx gen_exp10sf2 (rtx, rtx);
extern rtx gen_exp10df2 (rtx, rtx);
extern rtx gen_exp2xf2 (rtx, rtx);
extern rtx gen_exp2sf2 (rtx, rtx);
extern rtx gen_exp2df2 (rtx, rtx);
extern rtx gen_expm1xf2 (rtx, rtx);
extern rtx gen_expm1sf2 (rtx, rtx);
extern rtx gen_expm1df2 (rtx, rtx);
extern rtx gen_ldexpxf3 (rtx, rtx, rtx);
extern rtx gen_ldexpsf3 (rtx, rtx, rtx);
extern rtx gen_ldexpdf3 (rtx, rtx, rtx);
extern rtx gen_scalbxf3 (rtx, rtx, rtx);
extern rtx gen_scalbsf3 (rtx, rtx, rtx);
extern rtx gen_scalbdf3 (rtx, rtx, rtx);
extern rtx gen_significandxf2 (rtx, rtx);
extern rtx gen_significandsf2 (rtx, rtx);
extern rtx gen_significanddf2 (rtx, rtx);
extern rtx gen_rintsf2 (rtx, rtx);
extern rtx gen_rintdf2 (rtx, rtx);
extern rtx gen_roundsf2 (rtx, rtx);
extern rtx gen_rounddf2 (rtx, rtx);
extern rtx gen_lrintxfhi2 (rtx, rtx);
extern rtx gen_lrintxfsi2 (rtx, rtx);
extern rtx gen_lrintxfdi2 (rtx, rtx);
extern rtx gen_lrintsfsi2 (rtx, rtx);
extern rtx gen_lrintdfsi2 (rtx, rtx);
extern rtx gen_lrintsfdi2 (rtx, rtx);
extern rtx gen_lrintdfdi2 (rtx, rtx);
extern rtx gen_lroundsfsi2 (rtx, rtx);
extern rtx gen_lrounddfsi2 (rtx, rtx);
extern rtx gen_lroundsfdi2 (rtx, rtx);
extern rtx gen_lrounddfdi2 (rtx, rtx);
extern rtx gen_floorxf2 (rtx, rtx);
extern rtx gen_floorsf2 (rtx, rtx);
extern rtx gen_floordf2 (rtx, rtx);
extern rtx gen_lfloorxfhi2 (rtx, rtx);
extern rtx gen_lfloorxfsi2 (rtx, rtx);
extern rtx gen_lfloorxfdi2 (rtx, rtx);
extern rtx gen_lfloorsfsi2 (rtx, rtx);
extern rtx gen_lfloordfsi2 (rtx, rtx);
extern rtx gen_lfloorsfdi2 (rtx, rtx);
extern rtx gen_lfloordfdi2 (rtx, rtx);
extern rtx gen_ceilxf2 (rtx, rtx);
extern rtx gen_ceilsf2 (rtx, rtx);
extern rtx gen_ceildf2 (rtx, rtx);
extern rtx gen_lceilxfhi2 (rtx, rtx);
extern rtx gen_lceilxfsi2 (rtx, rtx);
extern rtx gen_lceilxfdi2 (rtx, rtx);
extern rtx gen_lceilsfsi2 (rtx, rtx);
extern rtx gen_lceildfsi2 (rtx, rtx);
extern rtx gen_lceilsfdi2 (rtx, rtx);
extern rtx gen_lceildfdi2 (rtx, rtx);
extern rtx gen_btruncxf2 (rtx, rtx);
extern rtx gen_btruncsf2 (rtx, rtx);
extern rtx gen_btruncdf2 (rtx, rtx);
extern rtx gen_nearbyintxf2 (rtx, rtx);
extern rtx gen_nearbyintsf2 (rtx, rtx);
extern rtx gen_nearbyintdf2 (rtx, rtx);
extern rtx gen_isinfxf2 (rtx, rtx);
extern rtx gen_isinfsf2 (rtx, rtx);
extern rtx gen_isinfdf2 (rtx, rtx);
extern rtx gen_signbitsf2 (rtx, rtx);
extern rtx gen_signbitdf2 (rtx, rtx);
extern rtx gen_signbitxf2 (rtx, rtx);
extern rtx gen_movmemsi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_movmemdi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_strmov (rtx, rtx, rtx, rtx);
extern rtx gen_strmov_singleop (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_rep_mov (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_setmemsi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_setmemdi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_strset (rtx, rtx, rtx);
extern rtx gen_strset_singleop (rtx, rtx, rtx, rtx);
extern rtx gen_rep_stos (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_cmpstrnsi (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_cmpintqi (rtx);
extern rtx gen_cmpstrnqi_nz_1 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_cmpstrnqi_1 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_strlensi (rtx, rtx, rtx, rtx);
extern rtx gen_strlendi (rtx, rtx, rtx, rtx);
extern rtx gen_strlenqi_1 (rtx, rtx, rtx);
extern rtx gen_movqicc (rtx, rtx, rtx, rtx);
extern rtx gen_movhicc (rtx, rtx, rtx, rtx);
extern rtx gen_movsicc (rtx, rtx, rtx, rtx);
extern rtx gen_movdicc (rtx, rtx, rtx, rtx);
extern rtx gen_x86_movsicc_0_m1 (rtx, rtx, rtx);
extern rtx gen_x86_movdicc_0_m1 (rtx, rtx, rtx);
extern rtx gen_movsfcc (rtx, rtx, rtx, rtx);
extern rtx gen_movdfcc (rtx, rtx, rtx, rtx);
extern rtx gen_movxfcc (rtx, rtx, rtx, rtx);
extern rtx gen_addqicc (rtx, rtx, rtx, rtx);
extern rtx gen_addhicc (rtx, rtx, rtx, rtx);
extern rtx gen_addsicc (rtx, rtx, rtx, rtx);
extern rtx gen_adddicc (rtx, rtx, rtx, rtx);
extern rtx gen_allocate_stack (rtx, rtx);
extern rtx gen_probe_stack (rtx);
extern rtx gen_builtin_setjmp_receiver (rtx);
extern rtx gen_sse_prologue_save (rtx, rtx, rtx, rtx);
extern rtx gen_prefetch (rtx, rtx, rtx);
extern rtx gen_stack_protect_set (rtx, rtx);
extern rtx gen_stack_protect_test (rtx, rtx, rtx);
extern rtx gen_rdpmc (rtx, rtx);
extern rtx gen_rdtsc (rtx);
extern rtx gen_rdtscp (rtx, rtx);
extern rtx gen_lwp_llwpcb (rtx);
extern rtx gen_lwp_slwpcb (rtx);
extern rtx gen_lwp_lwpvalsi3 (rtx, rtx, rtx, rtx);
extern rtx gen_lwp_lwpvaldi3 (rtx, rtx, rtx, rtx);
extern rtx gen_lwp_lwpinssi3 (rtx, rtx, rtx, rtx);
extern rtx gen_lwp_lwpinsdi3 (rtx, rtx, rtx, rtx);
extern rtx gen_movv8qi (rtx, rtx);
extern rtx gen_movv4hi (rtx, rtx);
extern rtx gen_movv2si (rtx, rtx);
extern rtx gen_movv1di (rtx, rtx);
extern rtx gen_movv2sf (rtx, rtx);
extern rtx gen_pushv8qi1 (rtx);
extern rtx gen_pushv4hi1 (rtx);
extern rtx gen_pushv2si1 (rtx);
extern rtx gen_pushv1di1 (rtx);
extern rtx gen_pushv2sf1 (rtx);
extern rtx gen_movmisalignv8qi (rtx, rtx);
extern rtx gen_movmisalignv4hi (rtx, rtx);
extern rtx gen_movmisalignv2si (rtx, rtx);
extern rtx gen_movmisalignv1di (rtx, rtx);
extern rtx gen_movmisalignv2sf (rtx, rtx);
extern rtx gen_mmx_addv2sf3 (rtx, rtx, rtx);
extern rtx gen_mmx_subv2sf3 (rtx, rtx, rtx);
extern rtx gen_mmx_subrv2sf3 (rtx, rtx, rtx);
extern rtx gen_mmx_mulv2sf3 (rtx, rtx, rtx);
extern rtx gen_mmx_smaxv2sf3 (rtx, rtx, rtx);
extern rtx gen_mmx_sminv2sf3 (rtx, rtx, rtx);
extern rtx gen_mmx_eqv2sf3 (rtx, rtx, rtx);
extern rtx gen_vec_setv2sf (rtx, rtx, rtx);
extern rtx gen_vec_extractv2sf (rtx, rtx, rtx);
extern rtx gen_vec_initv2sf (rtx, rtx);
extern rtx gen_mmx_addv8qi3 (rtx, rtx, rtx);
extern rtx gen_mmx_subv8qi3 (rtx, rtx, rtx);
extern rtx gen_mmx_addv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_subv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_addv2si3 (rtx, rtx, rtx);
extern rtx gen_mmx_subv2si3 (rtx, rtx, rtx);
extern rtx gen_mmx_addv1di3 (rtx, rtx, rtx);
extern rtx gen_mmx_subv1di3 (rtx, rtx, rtx);
extern rtx gen_mmx_ssaddv8qi3 (rtx, rtx, rtx);
extern rtx gen_mmx_usaddv8qi3 (rtx, rtx, rtx);
extern rtx gen_mmx_sssubv8qi3 (rtx, rtx, rtx);
extern rtx gen_mmx_ussubv8qi3 (rtx, rtx, rtx);
extern rtx gen_mmx_ssaddv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_usaddv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_sssubv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_ussubv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_mulv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_smulv4hi3_highpart (rtx, rtx, rtx);
extern rtx gen_mmx_umulv4hi3_highpart (rtx, rtx, rtx);
extern rtx gen_mmx_pmaddwd (rtx, rtx, rtx);
extern rtx gen_mmx_pmulhrwv4hi3 (rtx, rtx, rtx);
extern rtx gen_sse2_umulv1siv1di3 (rtx, rtx, rtx);
extern rtx gen_mmx_smaxv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_sminv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_umaxv8qi3 (rtx, rtx, rtx);
extern rtx gen_mmx_uminv8qi3 (rtx, rtx, rtx);
extern rtx gen_mmx_eqv8qi3 (rtx, rtx, rtx);
extern rtx gen_mmx_eqv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_eqv2si3 (rtx, rtx, rtx);
extern rtx gen_mmx_andv8qi3 (rtx, rtx, rtx);
extern rtx gen_mmx_iorv8qi3 (rtx, rtx, rtx);
extern rtx gen_mmx_xorv8qi3 (rtx, rtx, rtx);
extern rtx gen_mmx_andv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_iorv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_xorv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_andv2si3 (rtx, rtx, rtx);
extern rtx gen_mmx_iorv2si3 (rtx, rtx, rtx);
extern rtx gen_mmx_xorv2si3 (rtx, rtx, rtx);
extern rtx gen_mmx_pinsrw (rtx, rtx, rtx, rtx);
extern rtx gen_mmx_pshufw (rtx, rtx, rtx);
extern rtx gen_vec_setv2si (rtx, rtx, rtx);
extern rtx gen_vec_extractv2si (rtx, rtx, rtx);
extern rtx gen_vec_initv2si (rtx, rtx);
extern rtx gen_vec_setv4hi (rtx, rtx, rtx);
extern rtx gen_vec_extractv4hi (rtx, rtx, rtx);
extern rtx gen_vec_initv4hi (rtx, rtx);
extern rtx gen_vec_setv8qi (rtx, rtx, rtx);
extern rtx gen_vec_extractv8qi (rtx, rtx, rtx);
extern rtx gen_vec_initv8qi (rtx, rtx);
extern rtx gen_mmx_uavgv8qi3 (rtx, rtx, rtx);
extern rtx gen_mmx_uavgv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_maskmovq (rtx, rtx, rtx);
extern rtx gen_mmx_emms (void);
extern rtx gen_mmx_femms (void);
extern rtx gen_movv32qi (rtx, rtx);
extern rtx gen_movv16hi (rtx, rtx);
extern rtx gen_movv8si (rtx, rtx);
extern rtx gen_movv4di (rtx, rtx);
extern rtx gen_movv8sf (rtx, rtx);
extern rtx gen_movv4df (rtx, rtx);
extern rtx gen_movv16qi (rtx, rtx);
extern rtx gen_movv8hi (rtx, rtx);
extern rtx gen_movv4si (rtx, rtx);
extern rtx gen_movv2di (rtx, rtx);
extern rtx gen_movv1ti (rtx, rtx);
extern rtx gen_movv4sf (rtx, rtx);
extern rtx gen_movv2df (rtx, rtx);
extern rtx gen_pushv32qi1 (rtx);
extern rtx gen_pushv16hi1 (rtx);
extern rtx gen_pushv8si1 (rtx);
extern rtx gen_pushv4di1 (rtx);
extern rtx gen_pushv8sf1 (rtx);
extern rtx gen_pushv4df1 (rtx);
extern rtx gen_pushv16qi1 (rtx);
extern rtx gen_pushv8hi1 (rtx);
extern rtx gen_pushv4si1 (rtx);
extern rtx gen_pushv2di1 (rtx);
extern rtx gen_pushv1ti1 (rtx);
extern rtx gen_pushv4sf1 (rtx);
extern rtx gen_pushv2df1 (rtx);
extern rtx gen_movmisalignv32qi (rtx, rtx);
extern rtx gen_movmisalignv16hi (rtx, rtx);
extern rtx gen_movmisalignv8si (rtx, rtx);
extern rtx gen_movmisalignv4di (rtx, rtx);
extern rtx gen_movmisalignv8sf (rtx, rtx);
extern rtx gen_movmisalignv4df (rtx, rtx);
extern rtx gen_movmisalignv16qi (rtx, rtx);
extern rtx gen_movmisalignv8hi (rtx, rtx);
extern rtx gen_movmisalignv4si (rtx, rtx);
extern rtx gen_movmisalignv2di (rtx, rtx);
extern rtx gen_movmisalignv1ti (rtx, rtx);
extern rtx gen_movmisalignv4sf (rtx, rtx);
extern rtx gen_movmisalignv2df (rtx, rtx);
extern rtx gen_avx_movups (rtx, rtx);
extern rtx gen_avx_movupd (rtx, rtx);
extern rtx gen_avx_movups256 (rtx, rtx);
extern rtx gen_avx_movupd256 (rtx, rtx);
extern rtx gen_sse_movups (rtx, rtx);
extern rtx gen_sse2_movupd (rtx, rtx);
extern rtx gen_avx_movdqu256 (rtx, rtx);
extern rtx gen_avx_movdqu (rtx, rtx);
extern rtx gen_sse2_movdqu (rtx, rtx);
extern rtx gen_storentv4sf (rtx, rtx);
extern rtx gen_storentv2df (rtx, rtx);
extern rtx gen_storentsf (rtx, rtx);
extern rtx gen_storentdf (rtx, rtx);
extern rtx gen_storentv2di (rtx, rtx);
extern rtx gen_storentsi (rtx, rtx);
extern rtx gen_absv4sf2 (rtx, rtx);
extern rtx gen_negv4sf2 (rtx, rtx);
extern rtx gen_absv2df2 (rtx, rtx);
extern rtx gen_negv2df2 (rtx, rtx);
extern rtx gen_addv8sf3 (rtx, rtx, rtx);
extern rtx gen_subv8sf3 (rtx, rtx, rtx);
extern rtx gen_addv4df3 (rtx, rtx, rtx);
extern rtx gen_subv4df3 (rtx, rtx, rtx);
extern rtx gen_addv4sf3 (rtx, rtx, rtx);
extern rtx gen_subv4sf3 (rtx, rtx, rtx);
extern rtx gen_addv2df3 (rtx, rtx, rtx);
extern rtx gen_subv2df3 (rtx, rtx, rtx);
extern rtx gen_mulv8sf3 (rtx, rtx, rtx);
extern rtx gen_mulv4df3 (rtx, rtx, rtx);
extern rtx gen_mulv4sf3 (rtx, rtx, rtx);
extern rtx gen_mulv2df3 (rtx, rtx, rtx);
extern rtx gen_divv8sf3 (rtx, rtx, rtx);
extern rtx gen_divv4df3 (rtx, rtx, rtx);
extern rtx gen_divv4sf3 (rtx, rtx, rtx);
extern rtx gen_divv2df3 (rtx, rtx, rtx);
extern rtx gen_sqrtv8sf2 (rtx, rtx);
extern rtx gen_sqrtv4sf2 (rtx, rtx);
extern rtx gen_rsqrtv8sf2 (rtx, rtx);
extern rtx gen_rsqrtv4sf2 (rtx, rtx);
extern rtx gen_smaxv8sf3 (rtx, rtx, rtx);
extern rtx gen_sminv8sf3 (rtx, rtx, rtx);
extern rtx gen_smaxv4df3 (rtx, rtx, rtx);
extern rtx gen_sminv4df3 (rtx, rtx, rtx);
extern rtx gen_smaxv4sf3 (rtx, rtx, rtx);
extern rtx gen_sminv4sf3 (rtx, rtx, rtx);
extern rtx gen_smaxv2df3 (rtx, rtx, rtx);
extern rtx gen_sminv2df3 (rtx, rtx, rtx);
extern rtx gen_reduc_splus_v4sf (rtx, rtx);
extern rtx gen_reduc_splus_v2df (rtx, rtx);
extern rtx gen_reduc_smax_v4sf (rtx, rtx);
extern rtx gen_reduc_smin_v4sf (rtx, rtx);
extern rtx gen_vcondv4sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv2df (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_andv8sf3 (rtx, rtx, rtx);
extern rtx gen_iorv8sf3 (rtx, rtx, rtx);
extern rtx gen_xorv8sf3 (rtx, rtx, rtx);
extern rtx gen_andv4df3 (rtx, rtx, rtx);
extern rtx gen_iorv4df3 (rtx, rtx, rtx);
extern rtx gen_xorv4df3 (rtx, rtx, rtx);
extern rtx gen_andv4sf3 (rtx, rtx, rtx);
extern rtx gen_iorv4sf3 (rtx, rtx, rtx);
extern rtx gen_xorv4sf3 (rtx, rtx, rtx);
extern rtx gen_andv2df3 (rtx, rtx, rtx);
extern rtx gen_iorv2df3 (rtx, rtx, rtx);
extern rtx gen_xorv2df3 (rtx, rtx, rtx);
extern rtx gen_copysignv4sf3 (rtx, rtx, rtx);
extern rtx gen_copysignv2df3 (rtx, rtx, rtx);
extern rtx gen_sse2_cvtudq2ps (rtx, rtx);
extern rtx gen_sse2_cvtpd2dq (rtx, rtx);
extern rtx gen_sse2_cvttpd2dq (rtx, rtx);
extern rtx gen_sse2_cvtpd2ps (rtx, rtx);
extern rtx gen_vec_unpacks_hi_v4sf (rtx, rtx);
extern rtx gen_vec_unpacks_lo_v4sf (rtx, rtx);
extern rtx gen_vec_unpacks_float_hi_v8hi (rtx, rtx);
extern rtx gen_vec_unpacks_float_lo_v8hi (rtx, rtx);
extern rtx gen_vec_unpacku_float_hi_v8hi (rtx, rtx);
extern rtx gen_vec_unpacku_float_lo_v8hi (rtx, rtx);
extern rtx gen_vec_unpacks_float_hi_v4si (rtx, rtx);
extern rtx gen_vec_unpacks_float_lo_v4si (rtx, rtx);
extern rtx gen_vec_unpacku_float_hi_v4si (rtx, rtx);
extern rtx gen_vec_unpacku_float_lo_v4si (rtx, rtx);
extern rtx gen_vec_pack_trunc_v2df (rtx, rtx, rtx);
extern rtx gen_vec_pack_sfix_trunc_v2df (rtx, rtx, rtx);
extern rtx gen_vec_pack_sfix_v2df (rtx, rtx, rtx);
extern rtx gen_sse_movhlps_exp (rtx, rtx, rtx);
extern rtx gen_sse_movlhps_exp (rtx, rtx, rtx);
extern rtx gen_avx_shufps256 (rtx, rtx, rtx, rtx);
extern rtx gen_sse_shufps (rtx, rtx, rtx, rtx);
extern rtx gen_sse_loadhps_exp (rtx, rtx, rtx);
extern rtx gen_sse_loadlps_exp (rtx, rtx, rtx);
extern rtx gen_vec_dupv4sf (rtx, rtx);
extern rtx gen_vec_initv16qi (rtx, rtx);
extern rtx gen_vec_initv8hi (rtx, rtx);
extern rtx gen_vec_initv4si (rtx, rtx);
extern rtx gen_vec_initv2di (rtx, rtx);
extern rtx gen_vec_initv4sf (rtx, rtx);
extern rtx gen_vec_initv2df (rtx, rtx);
extern rtx gen_vec_setv16qi (rtx, rtx, rtx);
extern rtx gen_vec_setv8hi (rtx, rtx, rtx);
extern rtx gen_vec_setv4si (rtx, rtx, rtx);
extern rtx gen_vec_setv2di (rtx, rtx, rtx);
extern rtx gen_vec_setv4sf (rtx, rtx, rtx);
extern rtx gen_vec_setv2df (rtx, rtx, rtx);
extern rtx gen_avx_vextractf128v32qi (rtx, rtx, rtx);
extern rtx gen_avx_vextractf128v16hi (rtx, rtx, rtx);
extern rtx gen_avx_vextractf128v8si (rtx, rtx, rtx);
extern rtx gen_avx_vextractf128v4di (rtx, rtx, rtx);
extern rtx gen_avx_vextractf128v8sf (rtx, rtx, rtx);
extern rtx gen_avx_vextractf128v4df (rtx, rtx, rtx);
extern rtx gen_vec_extractv16qi (rtx, rtx, rtx);
extern rtx gen_vec_extractv8hi (rtx, rtx, rtx);
extern rtx gen_vec_extractv4si (rtx, rtx, rtx);
extern rtx gen_vec_extractv2di (rtx, rtx, rtx);
extern rtx gen_vec_extractv4sf (rtx, rtx, rtx);
extern rtx gen_vec_extractv2df (rtx, rtx, rtx);
extern rtx gen_vec_interleave_highv2df (rtx, rtx, rtx);
extern rtx gen_avx_movddup256 (rtx, rtx);
extern rtx gen_avx_unpcklpd256 (rtx, rtx, rtx);
extern rtx gen_vec_interleave_lowv2df (rtx, rtx, rtx);
extern rtx gen_avx_shufpd256 (rtx, rtx, rtx, rtx);
extern rtx gen_sse2_shufpd (rtx, rtx, rtx, rtx);
extern rtx gen_vec_extract_evenv4sf (rtx, rtx, rtx);
extern rtx gen_vec_extract_evenv2df (rtx, rtx, rtx);
extern rtx gen_vec_extract_evenv2di (rtx, rtx, rtx);
extern rtx gen_vec_extract_evenv4si (rtx, rtx, rtx);
extern rtx gen_vec_extract_evenv8hi (rtx, rtx, rtx);
extern rtx gen_vec_extract_evenv16qi (rtx, rtx, rtx);
extern rtx gen_vec_extract_evenv4df (rtx, rtx, rtx);
extern rtx gen_vec_extract_evenv8sf (rtx, rtx, rtx);
extern rtx gen_vec_extract_oddv4sf (rtx, rtx, rtx);
extern rtx gen_vec_extract_oddv2df (rtx, rtx, rtx);
extern rtx gen_vec_extract_oddv2di (rtx, rtx, rtx);
extern rtx gen_vec_extract_oddv4si (rtx, rtx, rtx);
extern rtx gen_vec_extract_oddv8hi (rtx, rtx, rtx);
extern rtx gen_vec_extract_oddv16qi (rtx, rtx, rtx);
extern rtx gen_vec_extract_oddv4df (rtx, rtx, rtx);
extern rtx gen_vec_extract_oddv8sf (rtx, rtx, rtx);
extern rtx gen_sse2_loadhpd_exp (rtx, rtx, rtx);
extern rtx gen_sse2_loadlpd_exp (rtx, rtx, rtx);
extern rtx gen_negv16qi2 (rtx, rtx);
extern rtx gen_negv8hi2 (rtx, rtx);
extern rtx gen_negv4si2 (rtx, rtx);
extern rtx gen_negv2di2 (rtx, rtx);
extern rtx gen_addv16qi3 (rtx, rtx, rtx);
extern rtx gen_subv16qi3 (rtx, rtx, rtx);
extern rtx gen_addv8hi3 (rtx, rtx, rtx);
extern rtx gen_subv8hi3 (rtx, rtx, rtx);
extern rtx gen_addv4si3 (rtx, rtx, rtx);
extern rtx gen_subv4si3 (rtx, rtx, rtx);
extern rtx gen_addv2di3 (rtx, rtx, rtx);
extern rtx gen_subv2di3 (rtx, rtx, rtx);
extern rtx gen_sse2_ssaddv16qi3 (rtx, rtx, rtx);
extern rtx gen_sse2_usaddv16qi3 (rtx, rtx, rtx);
extern rtx gen_sse2_sssubv16qi3 (rtx, rtx, rtx);
extern rtx gen_sse2_ussubv16qi3 (rtx, rtx, rtx);
extern rtx gen_sse2_ssaddv8hi3 (rtx, rtx, rtx);
extern rtx gen_sse2_usaddv8hi3 (rtx, rtx, rtx);
extern rtx gen_sse2_sssubv8hi3 (rtx, rtx, rtx);
extern rtx gen_sse2_ussubv8hi3 (rtx, rtx, rtx);
extern rtx gen_mulv8hi3 (rtx, rtx, rtx);
extern rtx gen_smulv8hi3_highpart (rtx, rtx, rtx);
extern rtx gen_umulv8hi3_highpart (rtx, rtx, rtx);
extern rtx gen_sse2_umulv2siv2di3 (rtx, rtx, rtx);
extern rtx gen_sse4_1_mulv2siv2di3 (rtx, rtx, rtx);
extern rtx gen_sse2_pmaddwd (rtx, rtx, rtx);
extern rtx gen_mulv4si3 (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_hi_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_lo_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_hi_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_lo_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_hi_v4si (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_lo_v4si (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_hi_v4si (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_lo_v4si (rtx, rtx, rtx);
extern rtx gen_sdot_prodv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_udot_prodv4si (rtx, rtx, rtx, rtx);
extern rtx gen_vec_shl_v16qi (rtx, rtx, rtx);
extern rtx gen_vec_shl_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_shl_v4si (rtx, rtx, rtx);
extern rtx gen_vec_shl_v2di (rtx, rtx, rtx);
extern rtx gen_vec_shr_v16qi (rtx, rtx, rtx);
extern rtx gen_vec_shr_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_shr_v4si (rtx, rtx, rtx);
extern rtx gen_vec_shr_v2di (rtx, rtx, rtx);
extern rtx gen_umaxv16qi3 (rtx, rtx, rtx);
extern rtx gen_uminv16qi3 (rtx, rtx, rtx);
extern rtx gen_smaxv8hi3 (rtx, rtx, rtx);
extern rtx gen_sminv8hi3 (rtx, rtx, rtx);
extern rtx gen_umaxv8hi3 (rtx, rtx, rtx);
extern rtx gen_smaxv16qi3 (rtx, rtx, rtx);
extern rtx gen_smaxv4si3 (rtx, rtx, rtx);
extern rtx gen_smaxv2di3 (rtx, rtx, rtx);
extern rtx gen_umaxv4si3 (rtx, rtx, rtx);
extern rtx gen_umaxv2di3 (rtx, rtx, rtx);
extern rtx gen_sminv16qi3 (rtx, rtx, rtx);
extern rtx gen_sminv4si3 (rtx, rtx, rtx);
extern rtx gen_sminv2di3 (rtx, rtx, rtx);
extern rtx gen_uminv8hi3 (rtx, rtx, rtx);
extern rtx gen_uminv4si3 (rtx, rtx, rtx);
extern rtx gen_uminv2di3 (rtx, rtx, rtx);
extern rtx gen_sse2_eqv16qi3 (rtx, rtx, rtx);
extern rtx gen_sse2_eqv8hi3 (rtx, rtx, rtx);
extern rtx gen_sse2_eqv4si3 (rtx, rtx, rtx);
extern rtx gen_sse4_1_eqv2di3 (rtx, rtx, rtx);
extern rtx gen_vcondv16qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv2di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv16qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv2di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_one_cmplv16qi2 (rtx, rtx);
extern rtx gen_one_cmplv8hi2 (rtx, rtx);
extern rtx gen_one_cmplv4si2 (rtx, rtx);
extern rtx gen_one_cmplv2di2 (rtx, rtx);
extern rtx gen_andv16qi3 (rtx, rtx, rtx);
extern rtx gen_iorv16qi3 (rtx, rtx, rtx);
extern rtx gen_xorv16qi3 (rtx, rtx, rtx);
extern rtx gen_andv8hi3 (rtx, rtx, rtx);
extern rtx gen_iorv8hi3 (rtx, rtx, rtx);
extern rtx gen_xorv8hi3 (rtx, rtx, rtx);
extern rtx gen_andv4si3 (rtx, rtx, rtx);
extern rtx gen_iorv4si3 (rtx, rtx, rtx);
extern rtx gen_xorv4si3 (rtx, rtx, rtx);
extern rtx gen_andv2di3 (rtx, rtx, rtx);
extern rtx gen_iorv2di3 (rtx, rtx, rtx);
extern rtx gen_xorv2di3 (rtx, rtx, rtx);
extern rtx gen_andtf3 (rtx, rtx, rtx);
extern rtx gen_iortf3 (rtx, rtx, rtx);
extern rtx gen_xortf3 (rtx, rtx, rtx);
extern rtx gen_vec_pack_trunc_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_pack_trunc_v4si (rtx, rtx, rtx);
extern rtx gen_vec_pack_trunc_v2di (rtx, rtx, rtx);
extern rtx gen_sse2_pshufd (rtx, rtx, rtx);
extern rtx gen_sse2_pshuflw (rtx, rtx, rtx);
extern rtx gen_sse2_pshufhw (rtx, rtx, rtx);
extern rtx gen_sse2_loadd (rtx, rtx);
extern rtx gen_sse_storeq (rtx, rtx);
extern rtx gen_vec_unpacku_hi_v16qi (rtx, rtx);
extern rtx gen_vec_unpacks_hi_v16qi (rtx, rtx);
extern rtx gen_vec_unpacku_lo_v16qi (rtx, rtx);
extern rtx gen_vec_unpacks_lo_v16qi (rtx, rtx);
extern rtx gen_vec_unpacku_hi_v8hi (rtx, rtx);
extern rtx gen_vec_unpacks_hi_v8hi (rtx, rtx);
extern rtx gen_vec_unpacku_lo_v8hi (rtx, rtx);
extern rtx gen_vec_unpacks_lo_v8hi (rtx, rtx);
extern rtx gen_vec_unpacku_hi_v4si (rtx, rtx);
extern rtx gen_vec_unpacks_hi_v4si (rtx, rtx);
extern rtx gen_vec_unpacku_lo_v4si (rtx, rtx);
extern rtx gen_vec_unpacks_lo_v4si (rtx, rtx);
extern rtx gen_sse2_uavgv16qi3 (rtx, rtx, rtx);
extern rtx gen_sse2_uavgv8hi3 (rtx, rtx, rtx);
extern rtx gen_sse2_maskmovdqu (rtx, rtx, rtx);
extern rtx gen_sse_sfence (void);
extern rtx gen_sse2_mfence (void);
extern rtx gen_sse2_lfence (void);
extern rtx gen_ssse3_pmulhrswv8hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_pmulhrswv4hi3 (rtx, rtx, rtx);
extern rtx gen_rotlv16qi3 (rtx, rtx, rtx);
extern rtx gen_rotlv8hi3 (rtx, rtx, rtx);
extern rtx gen_rotlv4si3 (rtx, rtx, rtx);
extern rtx gen_rotlv2di3 (rtx, rtx, rtx);
extern rtx gen_rotrv16qi3 (rtx, rtx, rtx);
extern rtx gen_rotrv8hi3 (rtx, rtx, rtx);
extern rtx gen_rotrv4si3 (rtx, rtx, rtx);
extern rtx gen_rotrv2di3 (rtx, rtx, rtx);
extern rtx gen_vrotrv16qi3 (rtx, rtx, rtx);
extern rtx gen_vrotrv8hi3 (rtx, rtx, rtx);
extern rtx gen_vrotrv4si3 (rtx, rtx, rtx);
extern rtx gen_vrotrv2di3 (rtx, rtx, rtx);
extern rtx gen_vrotlv16qi3 (rtx, rtx, rtx);
extern rtx gen_vrotlv8hi3 (rtx, rtx, rtx);
extern rtx gen_vrotlv4si3 (rtx, rtx, rtx);
extern rtx gen_vrotlv2di3 (rtx, rtx, rtx);
extern rtx gen_vlshrv16qi3 (rtx, rtx, rtx);
extern rtx gen_vlshrv8hi3 (rtx, rtx, rtx);
extern rtx gen_vlshrv4si3 (rtx, rtx, rtx);
extern rtx gen_vashrv16qi3 (rtx, rtx, rtx);
extern rtx gen_vashrv8hi3 (rtx, rtx, rtx);
extern rtx gen_vashrv4si3 (rtx, rtx, rtx);
extern rtx gen_vashlv16qi3 (rtx, rtx, rtx);
extern rtx gen_vashlv8hi3 (rtx, rtx, rtx);
extern rtx gen_vashlv4si3 (rtx, rtx, rtx);
extern rtx gen_ashlv16qi3 (rtx, rtx, rtx);
extern rtx gen_lshlv16qi3 (rtx, rtx, rtx);
extern rtx gen_ashrv16qi3 (rtx, rtx, rtx);
extern rtx gen_ashrv2di3 (rtx, rtx, rtx);
extern rtx gen_avx_vzeroall (void);
extern rtx gen_avx_vzeroupper (void);
extern rtx gen_avx_vpermilv2df (rtx, rtx, rtx);
extern rtx gen_avx_vpermilv4df (rtx, rtx, rtx);
extern rtx gen_avx_vpermilv4sf (rtx, rtx, rtx);
extern rtx gen_avx_vpermilv8sf (rtx, rtx, rtx);
extern rtx gen_avx_vperm2f128v8si3 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_vperm2f128v8sf3 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_vperm2f128v4df3 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_vinsertf128v32qi (rtx, rtx, rtx, rtx);
extern rtx gen_avx_vinsertf128v16hi (rtx, rtx, rtx, rtx);
extern rtx gen_avx_vinsertf128v8si (rtx, rtx, rtx, rtx);
extern rtx gen_avx_vinsertf128v4di (rtx, rtx, rtx, rtx);
extern rtx gen_avx_vinsertf128v8sf (rtx, rtx, rtx, rtx);
extern rtx gen_avx_vinsertf128v4df (rtx, rtx, rtx, rtx);
extern rtx gen_vec_initv32qi (rtx, rtx);
extern rtx gen_vec_initv16hi (rtx, rtx);
extern rtx gen_vec_initv8si (rtx, rtx);
extern rtx gen_vec_initv4di (rtx, rtx);
extern rtx gen_vec_initv8sf (rtx, rtx);
extern rtx gen_vec_initv4df (rtx, rtx);
extern rtx gen_memory_barrier (void);
extern rtx gen_sync_compare_and_swapqi (rtx, rtx, rtx, rtx);
extern rtx gen_sync_compare_and_swaphi (rtx, rtx, rtx, rtx);
extern rtx gen_sync_compare_and_swapsi (rtx, rtx, rtx, rtx);
extern rtx gen_sync_compare_and_swapdi (rtx, rtx, rtx, rtx);
extern rtx gen_sync_compare_and_swapti (rtx, rtx, rtx, rtx);
# 25 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tm.h" 2
# 26 "../../../src/plugin-utils.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/langhooks.h" 1
# 26 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/langhooks.h"
struct diagnostic_context;
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
# 107 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/langhooks.h"
  void (*register_builtin_type) (tree, const char *);





  void (*incomplete_type_error) (const_tree value, const_tree type);



  tree (*max_size) (const_tree);



  void (*omp_firstprivatize_type_sizes) (struct gimplify_omp_ctx *, tree);





  unsigned char (*type_hash_eq) (const_tree, const_tree);



  unsigned char (*get_array_descr_info) (const_tree, struct array_descr_info *);


  void (*get_subrange_bounds) (const_tree, tree *, tree *);





  tree (*reconstruct_complex_type) (tree, tree);




  unsigned char hash_types;
};



struct lang_hooks_for_decls
{


  int (*global_bindings_p) (void);





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




  unsigned int (*init_options) (unsigned int argc, const char **argv);



  void (*initialize_diagnostics) (struct diagnostic_context *);
# 290 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/langhooks.h"
  int (*handle_option) (size_t code, const char *arg, int value);



  unsigned char (*missing_argument) (const char *opt, size_t code);
# 304 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/langhooks.h"
  unsigned char (*post_options) (const char **);




  unsigned char (*init) (void);


  void (*finish) (void);



  void (*parse_file) (int);


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
# 363 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/langhooks.h"
  const char *(*decl_printable_name) (tree decl, int verbosity);




  const char *(*dwarf_name) (tree, int verbosity);




  int (*types_compatible_p) (tree x, tree y);


  void (*print_error_function) (struct diagnostic_context *, const char *,
    struct diagnostic_info *);
# 386 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/langhooks.h"
  long (*to_target_charset) (long);






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



  tree (*fold_obj_type_ref) (tree, tree);


  tree (*builtin_function) (tree decl);







  tree (*builtin_function_ext_scope) (tree decl);


  void (*init_ts) (void);




  tree (*expr_to_decl) (tree expr, unsigned char *tc, unsigned char *se);


  tree (*eh_personality) (void);


  tree (*eh_runtime_type) (tree);



  unsigned char eh_use_cxa_end_cleanup;



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
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-pragma.h" 1
# 24 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-pragma.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cpplib.h" 1
# 31 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cpplib.h"
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
# 143 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cpplib.h"
enum cpp_ttype
{
  CPP_EQ, CPP_NOT, CPP_GREATER, CPP_LESS, CPP_PLUS, CPP_MINUS, CPP_MULT, CPP_DIV, CPP_MOD, CPP_AND, CPP_OR, CPP_XOR, CPP_RSHIFT, CPP_LSHIFT, CPP_COMPL, CPP_AND_AND, CPP_OR_OR, CPP_QUERY, CPP_COLON, CPP_COMMA, CPP_OPEN_PAREN, CPP_CLOSE_PAREN, CPP_EOF, CPP_EQ_EQ, CPP_NOT_EQ, CPP_GREATER_EQ, CPP_LESS_EQ, CPP_PLUS_EQ, CPP_MINUS_EQ, CPP_MULT_EQ, CPP_DIV_EQ, CPP_MOD_EQ, CPP_AND_EQ, CPP_OR_EQ, CPP_XOR_EQ, CPP_RSHIFT_EQ, CPP_LSHIFT_EQ, CPP_HASH, CPP_PASTE, CPP_OPEN_SQUARE, CPP_CLOSE_SQUARE, CPP_OPEN_BRACE, CPP_CLOSE_BRACE, CPP_SEMICOLON, CPP_ELLIPSIS, CPP_PLUS_PLUS, CPP_MINUS_MINUS, CPP_DEREF, CPP_DOT, CPP_SCOPE, CPP_DEREF_STAR, CPP_DOT_STAR, CPP_ATSIGN, CPP_NAME, CPP_AT_NAME, CPP_NUMBER, CPP_CHAR, CPP_WCHAR, CPP_CHAR16, CPP_CHAR32, CPP_OTHER, CPP_STRING, CPP_WSTRING, CPP_STRING16, CPP_STRING32, CPP_UTF8STRING, CPP_OBJC_STRING, CPP_HEADER_NAME, CPP_COMMENT, CPP_MACRO_ARG, CPP_PRAGMA, CPP_PRAGMA_EOL, CPP_PADDING,
  N_TTYPES,


  CPP_LAST_EQ = CPP_LSHIFT,
  CPP_FIRST_DIGRAPH = CPP_HASH,
  CPP_LAST_PUNCTUATOR= CPP_ATSIGN,
  CPP_LAST_CPP_OP = CPP_LESS_EQ
};




enum c_lang {CLK_GNUC89 = 0, CLK_GNUC99, CLK_STDC89, CLK_STDC94, CLK_STDC99,
      CLK_GNUCXX, CLK_CXX98, CLK_GNUCXX0X, CLK_CXX0X, CLK_ASM};


struct cpp_string {
  unsigned int len;
  const unsigned char *text;
};
# 184 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cpplib.h"
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
# 258 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cpplib.h"
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


  unsigned char print_include_names;


  unsigned char warn_deprecated;


  unsigned char warn_comments;



  unsigned char warn_missing_include_dirs;


  unsigned char warn_trigraphs;


  unsigned char warn_multichar;



  unsigned char warn_traditional;


  unsigned char warn_long_long;


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


  unsigned char pedantic;



  unsigned char preprocessed;


  unsigned char show_column;


  unsigned char operator_names;


  unsigned char warn_cxx_operator_names;


  unsigned char traditional;


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
  void (*include) (cpp_reader *, unsigned int, const unsigned char *,
     const char *, int, const cpp_token **);
  void (*define) (cpp_reader *, unsigned int, cpp_hashnode *);
  void (*undef) (cpp_reader *, unsigned int, cpp_hashnode *);
  void (*ident) (cpp_reader *, unsigned int, const cpp_string *);
  void (*def_pragma) (cpp_reader *, unsigned int);
  int (*valid_pch) (cpp_reader *, const char *, int);
  void (*read_pch) (cpp_reader *, const char *, int, const char *);
  missing_header_cb missing_header;



  cpp_hashnode * (*macro_to_expand) (cpp_reader *, const cpp_token *);



  unsigned char (*error) (cpp_reader *, int, source_location, unsigned int,
   const char *, va_list *)
       __attribute__ ((__format__ (__printf__, 5, 0))) __attribute__ ((__nonnull__ (5)));



  void (*used_define) (cpp_reader *, unsigned int, cpp_hashnode *);
  void (*used_undef) (cpp_reader *, unsigned int, cpp_hashnode *);


  void (*before_define) (cpp_reader *);


  void (*used) (cpp_reader *, source_location, cpp_hashnode *);
};
# 523 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cpplib.h"
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
# 584 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cpplib.h"
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
  BT_COUNTER
};
# 614 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cpplib.h"
enum {
  NTV_MACRO,
  NTV_ANSWER,
  NTV_BUILTIN,
  NTV_ARGUMENT,
  NTV_NONE
};
# 633 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cpplib.h"
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
        const cpp_hashnode *);
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

extern cpp_macro *cpp_push_definition (cpp_reader *, const char *);
extern void cpp_pop_definition (cpp_reader *, const char *, cpp_macro *);


extern void cpp_undef_all (cpp_reader *);

extern cpp_buffer *cpp_push_buffer (cpp_reader *, const unsigned char *,
        size_t, int);
extern int cpp_defined (cpp_reader *, const unsigned char *, int);



typedef unsigned long cpp_num_part;
typedef struct cpp_num cpp_num;
struct cpp_num
{
  cpp_num_part high;
  cpp_num_part low;
  unsigned char unsignedp;
  unsigned char overflow;
};
# 818 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cpplib.h"
extern unsigned cpp_classify_number (cpp_reader *, const cpp_token *);


extern cpp_num cpp_interpret_integer (cpp_reader *, const cpp_token *,
          unsigned int type);



cpp_num cpp_num_sign_extend (cpp_num, size_t);
# 849 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cpplib.h"
extern unsigned char cpp_error (cpp_reader *, int, const char *msgid, ...)
  __attribute__ ((__format__ (__printf__, 3, 4))) __attribute__ ((__nonnull__ (3)));



extern unsigned char cpp_errno (cpp_reader *, int, const char *msgid);




extern unsigned char cpp_error_with_line (cpp_reader *, int, source_location, unsigned,
     const char *msgid, ...) __attribute__ ((__format__ (__printf__, 5, 6))) __attribute__ ((__nonnull__ (5)));


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
# 25 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-pragma.h" 2



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
  PRAGMA_OMP_CLAUSE_UNTIED
} pragma_omp_clause;

extern struct cpp_reader* parse_in;
# 98 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-pragma.h"
extern void push_visibility (const char *, int);
extern unsigned char pop_visibility (int);

extern void init_pragma (void);


typedef void (*pragma_handler)(struct cpp_reader *);
extern void c_register_pragma (const char *, const char *, pragma_handler);
extern void c_register_pragma_with_expansion (const char *, const char *,
           pragma_handler);
extern void c_invoke_pragma_handler (unsigned int);

extern void maybe_apply_pragma_weak (tree);
extern void maybe_apply_pending_pragma_weaks (void);
extern tree maybe_apply_renaming_pragma (tree, tree);
extern void add_to_renaming_pragma_list (tree, tree);

extern enum cpp_ttype pragma_lex (tree *);
# 128 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-pragma.h"
extern enum cpp_ttype c_lex_with_flags (tree *, location_t *, unsigned char *,
     int);

extern void c_pp_lookup_pragma (unsigned int, const char **, const char **);
# 39 "../../../src/plugin-utils.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.h" 1
# 25 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/splay-tree.h" 1
# 41 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/splay-tree.h"
  typedef unsigned long int libi_uhostptr_t;
  typedef long int libi_shostptr_t;
# 62 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/splay-tree.h"
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
# 26 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/cpplib.h" 1
# 27 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/ggc.h" 1
# 30 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/ggc.h"
extern const char empty_string[];
extern const char digit_vector[];






typedef void (*gt_pointer_operator) (void *, void *);

# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/gtype-desc.h" 1
# 23 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/gtype-desc.h"
enum gt_types_enum {
 gt_ggc_e_15interface_tuple,
 gt_ggc_e_16volatilized_type,
 gt_ggc_e_17string_descriptor,
 gt_ggc_e_15c_inline_static,
 gt_ggc_e_24VEC_c_goto_bindings_p_gc,
 gt_ggc_e_15c_goto_bindings,
 gt_ggc_e_7c_scope,
 gt_ggc_e_9c_binding,
 gt_ggc_e_12c_label_vars,
 gt_ggc_e_8c_parser,
 gt_ggc_e_9imp_entry,
 gt_ggc_e_16hashed_attribute,
 gt_ggc_e_12hashed_entry,
 gt_ggc_e_14type_assertion,
 gt_ggc_e_18treetreehash_entry,
 gt_ggc_e_5CPool,
 gt_ggc_e_3JCF,
 gt_ggc_e_17module_htab_entry,
 gt_ggc_e_13binding_level,
 gt_ggc_e_9opt_stack,
 gt_ggc_e_11align_stack,
 gt_ggc_e_18VEC_tree_gc_vec_gc,
 gt_ggc_e_19VEC_const_char_p_gc,
 gt_ggc_e_21pending_abstract_type,
 gt_ggc_e_15VEC_tree_int_gc,
 gt_ggc_e_9cp_parser,
 gt_ggc_e_17cp_parser_context,
 gt_ggc_e_8cp_lexer,
 gt_ggc_e_10tree_check,
 gt_ggc_e_22VEC_deferred_access_gc,
 gt_ggc_e_10spec_entry,
 gt_ggc_e_16pending_template,
 gt_ggc_e_21named_label_use_entry,
 gt_ggc_e_28VEC_deferred_access_check_gc,
 gt_ggc_e_18sorted_fields_type,
 gt_ggc_e_18VEC_tree_pair_s_gc,
 gt_ggc_e_17named_label_entry,
 gt_ggc_e_32VEC_qualified_typedef_usage_t_gc,
 gt_ggc_e_14cp_token_cache,
 gt_ggc_e_11saved_scope,
 gt_ggc_e_16cxx_int_tree_map,
 gt_ggc_e_23VEC_cp_class_binding_gc,
 gt_ggc_e_24VEC_cxx_saved_binding_gc,
 gt_ggc_e_16cp_binding_level,
 gt_ggc_e_11cxx_binding,
 gt_ggc_e_15binding_entry_s,
 gt_ggc_e_15binding_table_s,
 gt_ggc_e_11tinst_level,
 gt_ggc_e_14VEC_tinfo_s_gc,
 gt_ggc_e_18gnat_binding_level,
 gt_ggc_e_9elab_info,
 gt_ggc_e_10stmt_group,
 gt_ggc_e_16VEC_parm_attr_gc,
 gt_ggc_e_11parm_attr_d,
 gt_ggc_e_22VEC_ipa_edge_args_t_gc,
 gt_ggc_e_20lto_symtab_entry_def,
 gt_ggc_e_20ssa_operand_memory_d,
 gt_ggc_e_13scev_info_str,
 gt_ggc_e_24VEC_mem_addr_template_gc,
 gt_ggc_e_13VEC_gimple_gc,
 gt_ggc_e_9type_hash,
 gt_ggc_e_16string_pool_data,
 gt_ggc_e_13libfunc_entry,
 gt_ggc_e_23temp_slot_address_entry,
 gt_ggc_e_15throw_stmt_node,
 gt_ggc_e_21VEC_eh_landing_pad_gc,
 gt_ggc_e_16VEC_eh_region_gc,
 gt_ggc_e_10eh_catch_d,
 gt_ggc_e_16eh_landing_pad_d,
 gt_ggc_e_11eh_region_d,
 gt_ggc_e_10vcall_insn,
 gt_ggc_e_18VEC_vcall_entry_gc,
 gt_ggc_e_18VEC_dcall_entry_gc,
 gt_ggc_e_16var_loc_list_def,
 gt_ggc_e_12var_loc_node,
 gt_ggc_e_20VEC_die_arg_entry_gc,
 gt_ggc_e_16limbo_die_struct,
 gt_ggc_e_20VEC_pubname_entry_gc,
 gt_ggc_e_19VEC_dw_attr_node_gc,
 gt_ggc_e_18comdat_type_struct,
 gt_ggc_e_25dw_ranges_by_label_struct,
 gt_ggc_e_16dw_ranges_struct,
 gt_ggc_e_28dw_separate_line_info_struct,
 gt_ggc_e_19dw_line_info_struct,
 gt_ggc_e_25VEC_deferred_locations_gc,
 gt_ggc_e_18dw_loc_list_struct,
 gt_ggc_e_15dwarf_file_data,
 gt_ggc_e_15queued_reg_save,
 gt_ggc_e_20indirect_string_node,
 gt_ggc_e_19dw_loc_descr_struct,
 gt_ggc_e_13dw_fde_struct,
 gt_ggc_e_13dw_cfi_struct,
 gt_ggc_e_8typeinfo,
 gt_ggc_e_22VEC_alias_set_entry_gc,
 gt_ggc_e_17alias_set_entry_d,
 gt_ggc_e_24constant_descriptor_tree,
 gt_ggc_e_15cgraph_asm_node,
 gt_ggc_e_12varpool_node,
 gt_ggc_e_22VEC_cgraph_node_set_gc,
 gt_ggc_e_19cgraph_node_set_def,
 gt_ggc_e_27cgraph_node_set_element_def,
 gt_ggc_e_22VEC_cgraph_node_ptr_gc,
 gt_ggc_e_11cgraph_edge,
 gt_ggc_e_24VEC_ipa_replace_map_p_gc,
 gt_ggc_e_15ipa_replace_map,
 gt_ggc_e_11cgraph_node,
 gt_ggc_e_18VEC_basic_block_gc,
 gt_ggc_e_14gimple_bb_info,
 gt_ggc_e_11rtl_bb_info,
 gt_ggc_e_11VEC_edge_gc,
 gt_ggc_e_17cselib_val_struct,
 gt_ggc_e_12elt_loc_list,
 gt_ggc_e_13VEC_loop_p_gc,
 gt_ggc_e_4loop,
 gt_ggc_e_9loop_exit,
 gt_ggc_e_13nb_iter_bound,
 gt_ggc_e_24types_used_by_vars_entry,
 gt_ggc_e_17language_function,
 gt_ggc_e_5loops,
 gt_ggc_e_18control_flow_graph,
 gt_ggc_e_9eh_status,
 gt_ggc_e_20initial_value_struct,
 gt_ggc_e_17rtx_constant_pool,
 gt_ggc_e_18VEC_temp_slot_p_gc,
 gt_ggc_e_9temp_slot,
 gt_ggc_e_9gimple_df,
 gt_ggc_e_23VEC_call_site_record_gc,
 gt_ggc_e_18call_site_record_d,
 gt_ggc_e_14sequence_stack,
 gt_ggc_e_8elt_list,
 gt_ggc_e_17tree_priority_map,
 gt_ggc_e_12tree_int_map,
 gt_ggc_e_8tree_map,
 gt_ggc_e_14lang_tree_node,
 gt_ggc_e_24tree_statement_list_node,
 gt_ggc_e_9var_ann_d,
 gt_ggc_e_9lang_decl,
 gt_ggc_e_9lang_type,
 gt_ggc_e_10die_struct,
 gt_ggc_e_15varray_head_tag,
 gt_ggc_e_12ptr_info_def,
 gt_ggc_e_22VEC_constructor_elt_gc,
 gt_ggc_e_17VEC_alias_pair_gc,
 gt_ggc_e_11VEC_tree_gc,
 gt_ggc_e_12VEC_uchar_gc,
 gt_ggc_e_8function,
 gt_ggc_e_23constant_descriptor_rtx,
 gt_ggc_e_11fixed_value,
 gt_ggc_e_10real_value,
 gt_ggc_e_10VEC_rtx_gc,
 gt_ggc_e_12object_block,
 gt_ggc_e_9reg_attrs,
 gt_ggc_e_9mem_attrs,
 gt_ggc_e_14bitmap_obstack,
 gt_ggc_e_18bitmap_element_def,
 gt_ggc_e_16machine_function,
 gt_ggc_e_17stack_local_entry,
 gt_ggc_e_15basic_block_def,
 gt_ggc_e_8edge_def,
 gt_ggc_e_17gimple_seq_node_d,
 gt_ggc_e_12gimple_seq_d,
 gt_ggc_e_7section,
 gt_ggc_e_18gimple_statement_d,
 gt_ggc_e_9rtvec_def,
 gt_ggc_e_7rtx_def,
 gt_ggc_e_15bitmap_head_def,
 gt_ggc_e_9tree_node,
 gt_ggc_e_6answer,
 gt_ggc_e_9cpp_macro,
 gt_ggc_e_9cpp_token,
 gt_ggc_e_9line_maps,
 gt_e_II17splay_tree_node_s,
 gt_e_SP9tree_node17splay_tree_node_s,
 gt_e_P9tree_nodeP9tree_node17splay_tree_node_s,
 gt_e_IP9tree_node17splay_tree_node_s,
 gt_e_P15interface_tuple4htab,
 gt_e_P16volatilized_type4htab,
 gt_e_P17string_descriptor4htab,
 gt_e_P14type_assertion4htab,
 gt_e_P18treetreehash_entry4htab,
 gt_e_P17module_htab_entry4htab,
 gt_e_P21pending_abstract_type4htab,
 gt_e_P10spec_entry4htab,
 gt_e_P16cxx_int_tree_map4htab,
 gt_e_P17named_label_entry4htab,
 gt_e_P12tree_int_map4htab,
 gt_e_P20lto_symtab_entry_def4htab,
 gt_e_IP9tree_node12splay_tree_s,
 gt_e_P9tree_nodeP9tree_node12splay_tree_s,
 gt_e_P12varpool_node4htab,
 gt_e_P13scev_info_str4htab,
 gt_e_P23constant_descriptor_rtx4htab,
 gt_e_P24constant_descriptor_tree4htab,
 gt_e_P12object_block4htab,
 gt_e_P7section4htab,
 gt_e_P17tree_priority_map4htab,
 gt_e_P8tree_map4htab,
 gt_e_P9type_hash4htab,
 gt_e_P13libfunc_entry4htab,
 gt_e_P23temp_slot_address_entry4htab,
 gt_e_P15throw_stmt_node4htab,
 gt_e_P9reg_attrs4htab,
 gt_e_P9mem_attrs4htab,
 gt_e_P7rtx_def4htab,
 gt_e_SP9tree_node12splay_tree_s,
 gt_e_P10vcall_insn4htab,
 gt_e_P16var_loc_list_def4htab,
 gt_e_P10die_struct4htab,
 gt_e_P15dwarf_file_data4htab,
 gt_e_P20indirect_string_node4htab,
 gt_e_P11cgraph_node4htab,
 gt_e_II12splay_tree_s,
 gt_e_P27cgraph_node_set_element_def4htab,
 gt_e_P11cgraph_edge4htab,
 gt_e_P9loop_exit4htab,
 gt_e_P24types_used_by_vars_entry4htab,
 gt_e_P9tree_node4htab,
 gt_types_enum_last
};






extern void gt_ggc_mx_interface_tuple (void *);



extern void gt_ggc_mx_volatilized_type (void *);



extern void gt_ggc_mx_string_descriptor (void *);



extern void gt_ggc_mx_c_inline_static (void *);



extern void gt_ggc_mx_VEC_c_goto_bindings_p_gc (void *);



extern void gt_ggc_mx_c_goto_bindings (void *);



extern void gt_ggc_mx_c_scope (void *);



extern void gt_ggc_mx_c_binding (void *);



extern void gt_ggc_mx_c_label_vars (void *);



extern void gt_ggc_mx_c_parser (void *);



extern void gt_ggc_mx_imp_entry (void *);



extern void gt_ggc_mx_hashed_attribute (void *);



extern void gt_ggc_mx_hashed_entry (void *);



extern void gt_ggc_mx_type_assertion (void *);



extern void gt_ggc_mx_treetreehash_entry (void *);



extern void gt_ggc_mx_CPool (void *);



extern void gt_ggc_mx_JCF (void *);



extern void gt_ggc_mx_module_htab_entry (void *);



extern void gt_ggc_mx_binding_level (void *);



extern void gt_ggc_mx_opt_stack (void *);



extern void gt_ggc_mx_align_stack (void *);



extern void gt_ggc_mx_VEC_tree_gc_vec_gc (void *);



extern void gt_ggc_mx_VEC_const_char_p_gc (void *);



extern void gt_ggc_mx_pending_abstract_type (void *);



extern void gt_ggc_mx_VEC_tree_int_gc (void *);



extern void gt_ggc_mx_cp_parser (void *);



extern void gt_ggc_mx_cp_parser_context (void *);



extern void gt_ggc_mx_cp_lexer (void *);



extern void gt_ggc_mx_tree_check (void *);



extern void gt_ggc_mx_VEC_deferred_access_gc (void *);



extern void gt_ggc_mx_spec_entry (void *);



extern void gt_ggc_mx_pending_template (void *);



extern void gt_ggc_mx_named_label_use_entry (void *);



extern void gt_ggc_mx_VEC_deferred_access_check_gc (void *);



extern void gt_ggc_mx_sorted_fields_type (void *);



extern void gt_ggc_mx_VEC_tree_pair_s_gc (void *);



extern void gt_ggc_mx_named_label_entry (void *);



extern void gt_ggc_mx_VEC_qualified_typedef_usage_t_gc (void *);



extern void gt_ggc_mx_cp_token_cache (void *);



extern void gt_ggc_mx_saved_scope (void *);



extern void gt_ggc_mx_cxx_int_tree_map (void *);



extern void gt_ggc_mx_VEC_cp_class_binding_gc (void *);



extern void gt_ggc_mx_VEC_cxx_saved_binding_gc (void *);



extern void gt_ggc_mx_cp_binding_level (void *);



extern void gt_ggc_mx_cxx_binding (void *);



extern void gt_ggc_mx_binding_entry_s (void *);



extern void gt_ggc_mx_binding_table_s (void *);



extern void gt_ggc_mx_tinst_level (void *);



extern void gt_ggc_mx_VEC_tinfo_s_gc (void *);



extern void gt_ggc_mx_gnat_binding_level (void *);



extern void gt_ggc_mx_elab_info (void *);



extern void gt_ggc_mx_stmt_group (void *);



extern void gt_ggc_mx_VEC_parm_attr_gc (void *);



extern void gt_ggc_mx_parm_attr_d (void *);



extern void gt_ggc_mx_VEC_ipa_edge_args_t_gc (void *);



extern void gt_ggc_mx_lto_symtab_entry_def (void *);



extern void gt_ggc_mx_ssa_operand_memory_d (void *);



extern void gt_ggc_mx_scev_info_str (void *);



extern void gt_ggc_mx_VEC_mem_addr_template_gc (void *);



extern void gt_ggc_mx_VEC_gimple_gc (void *);



extern void gt_ggc_mx_type_hash (void *);



extern void gt_ggc_mx_string_pool_data (void *);



extern void gt_ggc_mx_libfunc_entry (void *);



extern void gt_ggc_mx_temp_slot_address_entry (void *);



extern void gt_ggc_mx_throw_stmt_node (void *);



extern void gt_ggc_mx_VEC_eh_landing_pad_gc (void *);



extern void gt_ggc_mx_VEC_eh_region_gc (void *);



extern void gt_ggc_mx_eh_catch_d (void *);



extern void gt_ggc_mx_eh_landing_pad_d (void *);



extern void gt_ggc_mx_eh_region_d (void *);



extern void gt_ggc_mx_vcall_insn (void *);



extern void gt_ggc_mx_VEC_vcall_entry_gc (void *);



extern void gt_ggc_mx_VEC_dcall_entry_gc (void *);



extern void gt_ggc_mx_var_loc_list_def (void *);



extern void gt_ggc_mx_var_loc_node (void *);



extern void gt_ggc_mx_VEC_die_arg_entry_gc (void *);



extern void gt_ggc_mx_limbo_die_struct (void *);



extern void gt_ggc_mx_VEC_pubname_entry_gc (void *);



extern void gt_ggc_mx_VEC_dw_attr_node_gc (void *);



extern void gt_ggc_mx_comdat_type_struct (void *);



extern void gt_ggc_mx_dw_ranges_by_label_struct (void *);



extern void gt_ggc_mx_dw_ranges_struct (void *);



extern void gt_ggc_mx_dw_separate_line_info_struct (void *);



extern void gt_ggc_mx_dw_line_info_struct (void *);



extern void gt_ggc_mx_VEC_deferred_locations_gc (void *);



extern void gt_ggc_mx_dw_loc_list_struct (void *);



extern void gt_ggc_mx_dwarf_file_data (void *);



extern void gt_ggc_mx_queued_reg_save (void *);



extern void gt_ggc_mx_indirect_string_node (void *);



extern void gt_ggc_mx_dw_loc_descr_struct (void *);



extern void gt_ggc_mx_dw_fde_struct (void *);



extern void gt_ggc_mx_dw_cfi_struct (void *);



extern void gt_ggc_mx_typeinfo (void *);



extern void gt_ggc_mx_VEC_alias_set_entry_gc (void *);



extern void gt_ggc_mx_alias_set_entry_d (void *);



extern void gt_ggc_mx_constant_descriptor_tree (void *);



extern void gt_ggc_mx_cgraph_asm_node (void *);



extern void gt_ggc_mx_varpool_node (void *);



extern void gt_ggc_mx_VEC_cgraph_node_set_gc (void *);



extern void gt_ggc_mx_cgraph_node_set_def (void *);



extern void gt_ggc_mx_cgraph_node_set_element_def (void *);



extern void gt_ggc_mx_VEC_cgraph_node_ptr_gc (void *);



extern void gt_ggc_mx_cgraph_edge (void *);



extern void gt_ggc_mx_VEC_ipa_replace_map_p_gc (void *);



extern void gt_ggc_mx_ipa_replace_map (void *);



extern void gt_ggc_mx_cgraph_node (void *);



extern void gt_ggc_mx_VEC_basic_block_gc (void *);



extern void gt_ggc_mx_gimple_bb_info (void *);



extern void gt_ggc_mx_rtl_bb_info (void *);



extern void gt_ggc_mx_VEC_edge_gc (void *);



extern void gt_ggc_mx_cselib_val_struct (void *);



extern void gt_ggc_mx_elt_loc_list (void *);



extern void gt_ggc_mx_VEC_loop_p_gc (void *);



extern void gt_ggc_mx_loop (void *);



extern void gt_ggc_mx_loop_exit (void *);



extern void gt_ggc_mx_nb_iter_bound (void *);



extern void gt_ggc_mx_types_used_by_vars_entry (void *);



extern void gt_ggc_mx_language_function (void *);



extern void gt_ggc_mx_loops (void *);



extern void gt_ggc_mx_control_flow_graph (void *);



extern void gt_ggc_mx_eh_status (void *);



extern void gt_ggc_mx_initial_value_struct (void *);



extern void gt_ggc_mx_rtx_constant_pool (void *);



extern void gt_ggc_mx_VEC_temp_slot_p_gc (void *);



extern void gt_ggc_mx_temp_slot (void *);



extern void gt_ggc_mx_gimple_df (void *);



extern void gt_ggc_mx_VEC_call_site_record_gc (void *);



extern void gt_ggc_mx_call_site_record_d (void *);



extern void gt_ggc_mx_sequence_stack (void *);



extern void gt_ggc_mx_elt_list (void *);



extern void gt_ggc_mx_tree_priority_map (void *);



extern void gt_ggc_mx_tree_int_map (void *);



extern void gt_ggc_mx_tree_map (void *);



extern void gt_ggc_mx_lang_tree_node (void *);



extern void gt_ggc_mx_tree_statement_list_node (void *);



extern void gt_ggc_mx_var_ann_d (void *);



extern void gt_ggc_mx_lang_decl (void *);



extern void gt_ggc_mx_lang_type (void *);



extern void gt_ggc_mx_die_struct (void *);



extern void gt_ggc_mx_varray_head_tag (void *);



extern void gt_ggc_mx_ptr_info_def (void *);



extern void gt_ggc_mx_VEC_constructor_elt_gc (void *);



extern void gt_ggc_mx_VEC_alias_pair_gc (void *);



extern void gt_ggc_mx_VEC_tree_gc (void *);



extern void gt_ggc_mx_VEC_uchar_gc (void *);



extern void gt_ggc_mx_function (void *);



extern void gt_ggc_mx_constant_descriptor_rtx (void *);



extern void gt_ggc_mx_fixed_value (void *);



extern void gt_ggc_mx_real_value (void *);



extern void gt_ggc_mx_VEC_rtx_gc (void *);



extern void gt_ggc_mx_object_block (void *);



extern void gt_ggc_mx_reg_attrs (void *);



extern void gt_ggc_mx_mem_attrs (void *);



extern void gt_ggc_mx_bitmap_obstack (void *);



extern void gt_ggc_mx_bitmap_element_def (void *);



extern void gt_ggc_mx_machine_function (void *);



extern void gt_ggc_mx_stack_local_entry (void *);



extern void gt_ggc_mx_basic_block_def (void *);



extern void gt_ggc_mx_edge_def (void *);



extern void gt_ggc_mx_gimple_seq_node_d (void *);



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
extern void gt_ggc_m_IP9tree_node17splay_tree_node_s (void *);
extern void gt_ggc_m_P15interface_tuple4htab (void *);
extern void gt_ggc_m_P16volatilized_type4htab (void *);
extern void gt_ggc_m_P17string_descriptor4htab (void *);
extern void gt_ggc_m_P14type_assertion4htab (void *);
extern void gt_ggc_m_P18treetreehash_entry4htab (void *);
extern void gt_ggc_m_P17module_htab_entry4htab (void *);
extern void gt_ggc_m_P21pending_abstract_type4htab (void *);
extern void gt_ggc_m_P10spec_entry4htab (void *);
extern void gt_ggc_m_P16cxx_int_tree_map4htab (void *);
extern void gt_ggc_m_P17named_label_entry4htab (void *);
extern void gt_ggc_m_P12tree_int_map4htab (void *);
extern void gt_ggc_m_P20lto_symtab_entry_def4htab (void *);
extern void gt_ggc_m_IP9tree_node12splay_tree_s (void *);
extern void gt_ggc_m_P9tree_nodeP9tree_node12splay_tree_s (void *);
extern void gt_ggc_m_P12varpool_node4htab (void *);
extern void gt_ggc_m_P13scev_info_str4htab (void *);
extern void gt_ggc_m_P23constant_descriptor_rtx4htab (void *);
extern void gt_ggc_m_P24constant_descriptor_tree4htab (void *);
extern void gt_ggc_m_P12object_block4htab (void *);
extern void gt_ggc_m_P7section4htab (void *);
extern void gt_ggc_m_P17tree_priority_map4htab (void *);
extern void gt_ggc_m_P8tree_map4htab (void *);
extern void gt_ggc_m_P9type_hash4htab (void *);
extern void gt_ggc_m_P13libfunc_entry4htab (void *);
extern void gt_ggc_m_P23temp_slot_address_entry4htab (void *);
extern void gt_ggc_m_P15throw_stmt_node4htab (void *);
extern void gt_ggc_m_P9reg_attrs4htab (void *);
extern void gt_ggc_m_P9mem_attrs4htab (void *);
extern void gt_ggc_m_P7rtx_def4htab (void *);
extern void gt_ggc_m_SP9tree_node12splay_tree_s (void *);
extern void gt_ggc_m_P10vcall_insn4htab (void *);
extern void gt_ggc_m_P16var_loc_list_def4htab (void *);
extern void gt_ggc_m_P10die_struct4htab (void *);
extern void gt_ggc_m_P15dwarf_file_data4htab (void *);
extern void gt_ggc_m_P20indirect_string_node4htab (void *);
extern void gt_ggc_m_P11cgraph_node4htab (void *);
extern void gt_ggc_m_II12splay_tree_s (void *);
extern void gt_ggc_m_P27cgraph_node_set_element_def4htab (void *);
extern void gt_ggc_m_P11cgraph_edge4htab (void *);
extern void gt_ggc_m_P9loop_exit4htab (void *);
extern void gt_ggc_m_P24types_used_by_vars_entry4htab (void *);
extern void gt_ggc_m_P9tree_node4htab (void *);
# 984 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/gtype-desc.h"
extern void gt_pch_nx_interface_tuple (void *);



extern void gt_pch_nx_volatilized_type (void *);



extern void gt_pch_nx_string_descriptor (void *);



extern void gt_pch_nx_c_inline_static (void *);



extern void gt_pch_nx_VEC_c_goto_bindings_p_gc (void *);



extern void gt_pch_nx_c_goto_bindings (void *);



extern void gt_pch_nx_c_scope (void *);



extern void gt_pch_nx_c_binding (void *);



extern void gt_pch_nx_c_label_vars (void *);



extern void gt_pch_nx_c_parser (void *);



extern void gt_pch_nx_imp_entry (void *);



extern void gt_pch_nx_hashed_attribute (void *);



extern void gt_pch_nx_hashed_entry (void *);



extern void gt_pch_nx_type_assertion (void *);



extern void gt_pch_nx_treetreehash_entry (void *);



extern void gt_pch_nx_CPool (void *);



extern void gt_pch_nx_JCF (void *);



extern void gt_pch_nx_module_htab_entry (void *);



extern void gt_pch_nx_binding_level (void *);



extern void gt_pch_nx_opt_stack (void *);



extern void gt_pch_nx_align_stack (void *);



extern void gt_pch_nx_VEC_tree_gc_vec_gc (void *);



extern void gt_pch_nx_VEC_const_char_p_gc (void *);



extern void gt_pch_nx_pending_abstract_type (void *);



extern void gt_pch_nx_VEC_tree_int_gc (void *);



extern void gt_pch_nx_cp_parser (void *);



extern void gt_pch_nx_cp_parser_context (void *);



extern void gt_pch_nx_cp_lexer (void *);



extern void gt_pch_nx_tree_check (void *);



extern void gt_pch_nx_VEC_deferred_access_gc (void *);



extern void gt_pch_nx_spec_entry (void *);



extern void gt_pch_nx_pending_template (void *);



extern void gt_pch_nx_named_label_use_entry (void *);



extern void gt_pch_nx_VEC_deferred_access_check_gc (void *);



extern void gt_pch_nx_sorted_fields_type (void *);



extern void gt_pch_nx_VEC_tree_pair_s_gc (void *);



extern void gt_pch_nx_named_label_entry (void *);



extern void gt_pch_nx_VEC_qualified_typedef_usage_t_gc (void *);



extern void gt_pch_nx_cp_token_cache (void *);



extern void gt_pch_nx_saved_scope (void *);



extern void gt_pch_nx_cxx_int_tree_map (void *);



extern void gt_pch_nx_VEC_cp_class_binding_gc (void *);



extern void gt_pch_nx_VEC_cxx_saved_binding_gc (void *);



extern void gt_pch_nx_cp_binding_level (void *);



extern void gt_pch_nx_cxx_binding (void *);



extern void gt_pch_nx_binding_entry_s (void *);



extern void gt_pch_nx_binding_table_s (void *);



extern void gt_pch_nx_tinst_level (void *);



extern void gt_pch_nx_VEC_tinfo_s_gc (void *);



extern void gt_pch_nx_gnat_binding_level (void *);



extern void gt_pch_nx_elab_info (void *);



extern void gt_pch_nx_stmt_group (void *);



extern void gt_pch_nx_VEC_parm_attr_gc (void *);



extern void gt_pch_nx_parm_attr_d (void *);



extern void gt_pch_nx_VEC_ipa_edge_args_t_gc (void *);



extern void gt_pch_nx_lto_symtab_entry_def (void *);



extern void gt_pch_nx_ssa_operand_memory_d (void *);



extern void gt_pch_nx_scev_info_str (void *);



extern void gt_pch_nx_VEC_mem_addr_template_gc (void *);



extern void gt_pch_nx_VEC_gimple_gc (void *);



extern void gt_pch_nx_type_hash (void *);



extern void gt_pch_nx_string_pool_data (void *);



extern void gt_pch_nx_libfunc_entry (void *);



extern void gt_pch_nx_temp_slot_address_entry (void *);



extern void gt_pch_nx_throw_stmt_node (void *);



extern void gt_pch_nx_VEC_eh_landing_pad_gc (void *);



extern void gt_pch_nx_VEC_eh_region_gc (void *);



extern void gt_pch_nx_eh_catch_d (void *);



extern void gt_pch_nx_eh_landing_pad_d (void *);



extern void gt_pch_nx_eh_region_d (void *);



extern void gt_pch_nx_vcall_insn (void *);



extern void gt_pch_nx_VEC_vcall_entry_gc (void *);



extern void gt_pch_nx_VEC_dcall_entry_gc (void *);



extern void gt_pch_nx_var_loc_list_def (void *);



extern void gt_pch_nx_var_loc_node (void *);



extern void gt_pch_nx_VEC_die_arg_entry_gc (void *);



extern void gt_pch_nx_limbo_die_struct (void *);



extern void gt_pch_nx_VEC_pubname_entry_gc (void *);



extern void gt_pch_nx_VEC_dw_attr_node_gc (void *);



extern void gt_pch_nx_comdat_type_struct (void *);



extern void gt_pch_nx_dw_ranges_by_label_struct (void *);



extern void gt_pch_nx_dw_ranges_struct (void *);



extern void gt_pch_nx_dw_separate_line_info_struct (void *);



extern void gt_pch_nx_dw_line_info_struct (void *);



extern void gt_pch_nx_VEC_deferred_locations_gc (void *);



extern void gt_pch_nx_dw_loc_list_struct (void *);



extern void gt_pch_nx_dwarf_file_data (void *);



extern void gt_pch_nx_queued_reg_save (void *);



extern void gt_pch_nx_indirect_string_node (void *);



extern void gt_pch_nx_dw_loc_descr_struct (void *);



extern void gt_pch_nx_dw_fde_struct (void *);



extern void gt_pch_nx_dw_cfi_struct (void *);



extern void gt_pch_nx_typeinfo (void *);



extern void gt_pch_nx_VEC_alias_set_entry_gc (void *);



extern void gt_pch_nx_alias_set_entry_d (void *);



extern void gt_pch_nx_constant_descriptor_tree (void *);



extern void gt_pch_nx_cgraph_asm_node (void *);



extern void gt_pch_nx_varpool_node (void *);



extern void gt_pch_nx_VEC_cgraph_node_set_gc (void *);



extern void gt_pch_nx_cgraph_node_set_def (void *);



extern void gt_pch_nx_cgraph_node_set_element_def (void *);



extern void gt_pch_nx_VEC_cgraph_node_ptr_gc (void *);



extern void gt_pch_nx_cgraph_edge (void *);



extern void gt_pch_nx_VEC_ipa_replace_map_p_gc (void *);



extern void gt_pch_nx_ipa_replace_map (void *);



extern void gt_pch_nx_cgraph_node (void *);



extern void gt_pch_nx_VEC_basic_block_gc (void *);



extern void gt_pch_nx_gimple_bb_info (void *);



extern void gt_pch_nx_rtl_bb_info (void *);



extern void gt_pch_nx_VEC_edge_gc (void *);



extern void gt_pch_nx_cselib_val_struct (void *);



extern void gt_pch_nx_elt_loc_list (void *);



extern void gt_pch_nx_VEC_loop_p_gc (void *);



extern void gt_pch_nx_loop (void *);



extern void gt_pch_nx_loop_exit (void *);



extern void gt_pch_nx_nb_iter_bound (void *);



extern void gt_pch_nx_types_used_by_vars_entry (void *);



extern void gt_pch_nx_language_function (void *);



extern void gt_pch_nx_loops (void *);



extern void gt_pch_nx_control_flow_graph (void *);



extern void gt_pch_nx_eh_status (void *);



extern void gt_pch_nx_initial_value_struct (void *);



extern void gt_pch_nx_rtx_constant_pool (void *);



extern void gt_pch_nx_VEC_temp_slot_p_gc (void *);



extern void gt_pch_nx_temp_slot (void *);



extern void gt_pch_nx_gimple_df (void *);



extern void gt_pch_nx_VEC_call_site_record_gc (void *);



extern void gt_pch_nx_call_site_record_d (void *);



extern void gt_pch_nx_sequence_stack (void *);



extern void gt_pch_nx_elt_list (void *);



extern void gt_pch_nx_tree_priority_map (void *);



extern void gt_pch_nx_tree_int_map (void *);



extern void gt_pch_nx_tree_map (void *);



extern void gt_pch_nx_lang_tree_node (void *);



extern void gt_pch_nx_tree_statement_list_node (void *);



extern void gt_pch_nx_var_ann_d (void *);



extern void gt_pch_nx_lang_decl (void *);



extern void gt_pch_nx_lang_type (void *);



extern void gt_pch_nx_die_struct (void *);



extern void gt_pch_nx_varray_head_tag (void *);



extern void gt_pch_nx_ptr_info_def (void *);



extern void gt_pch_nx_VEC_constructor_elt_gc (void *);



extern void gt_pch_nx_VEC_alias_pair_gc (void *);



extern void gt_pch_nx_VEC_tree_gc (void *);



extern void gt_pch_nx_VEC_uchar_gc (void *);



extern void gt_pch_nx_function (void *);



extern void gt_pch_nx_constant_descriptor_rtx (void *);



extern void gt_pch_nx_fixed_value (void *);



extern void gt_pch_nx_real_value (void *);



extern void gt_pch_nx_VEC_rtx_gc (void *);



extern void gt_pch_nx_object_block (void *);



extern void gt_pch_nx_reg_attrs (void *);



extern void gt_pch_nx_mem_attrs (void *);



extern void gt_pch_nx_bitmap_obstack (void *);



extern void gt_pch_nx_bitmap_element_def (void *);



extern void gt_pch_nx_machine_function (void *);



extern void gt_pch_nx_stack_local_entry (void *);



extern void gt_pch_nx_basic_block_def (void *);



extern void gt_pch_nx_edge_def (void *);



extern void gt_pch_nx_gimple_seq_node_d (void *);



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
extern void gt_pch_n_IP9tree_node17splay_tree_node_s (void *);
extern void gt_pch_n_P15interface_tuple4htab (void *);
extern void gt_pch_n_P16volatilized_type4htab (void *);
extern void gt_pch_n_P17string_descriptor4htab (void *);
extern void gt_pch_n_P14type_assertion4htab (void *);
extern void gt_pch_n_P18treetreehash_entry4htab (void *);
extern void gt_pch_n_P17module_htab_entry4htab (void *);
extern void gt_pch_n_P21pending_abstract_type4htab (void *);
extern void gt_pch_n_P10spec_entry4htab (void *);
extern void gt_pch_n_P16cxx_int_tree_map4htab (void *);
extern void gt_pch_n_P17named_label_entry4htab (void *);
extern void gt_pch_n_P12tree_int_map4htab (void *);
extern void gt_pch_n_P20lto_symtab_entry_def4htab (void *);
extern void gt_pch_n_IP9tree_node12splay_tree_s (void *);
extern void gt_pch_n_P9tree_nodeP9tree_node12splay_tree_s (void *);
extern void gt_pch_n_P12varpool_node4htab (void *);
extern void gt_pch_n_P13scev_info_str4htab (void *);
extern void gt_pch_n_P23constant_descriptor_rtx4htab (void *);
extern void gt_pch_n_P24constant_descriptor_tree4htab (void *);
extern void gt_pch_n_P12object_block4htab (void *);
extern void gt_pch_n_P7section4htab (void *);
extern void gt_pch_n_P17tree_priority_map4htab (void *);
extern void gt_pch_n_P8tree_map4htab (void *);
extern void gt_pch_n_P9type_hash4htab (void *);
extern void gt_pch_n_P13libfunc_entry4htab (void *);
extern void gt_pch_n_P23temp_slot_address_entry4htab (void *);
extern void gt_pch_n_P15throw_stmt_node4htab (void *);
extern void gt_pch_n_P9reg_attrs4htab (void *);
extern void gt_pch_n_P9mem_attrs4htab (void *);
extern void gt_pch_n_P7rtx_def4htab (void *);
extern void gt_pch_n_SP9tree_node12splay_tree_s (void *);
extern void gt_pch_n_P10vcall_insn4htab (void *);
extern void gt_pch_n_P16var_loc_list_def4htab (void *);
extern void gt_pch_n_P10die_struct4htab (void *);
extern void gt_pch_n_P15dwarf_file_data4htab (void *);
extern void gt_pch_n_P20indirect_string_node4htab (void *);
extern void gt_pch_n_P11cgraph_node4htab (void *);
extern void gt_pch_n_II12splay_tree_s (void *);
extern void gt_pch_n_P27cgraph_node_set_element_def4htab (void *);
extern void gt_pch_n_P11cgraph_edge4htab (void *);
extern void gt_pch_n_P9loop_exit4htab (void *);
extern void gt_pch_n_P24types_used_by_vars_entry4htab (void *);
extern void gt_pch_n_P9tree_node4htab (void *);




extern void gt_pch_p_15interface_tuple
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16volatilized_type
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17string_descriptor
    (void *, void *, gt_pointer_operator, void *);
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
extern void gt_pch_p_9imp_entry
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16hashed_attribute
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_12hashed_entry
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
extern void gt_pch_p_9opt_stack
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
extern void gt_pch_p_8cp_lexer
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_10tree_check
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_22VEC_deferred_access_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_10spec_entry
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16pending_template
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
extern void gt_pch_p_9elab_info
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_10stmt_group
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16VEC_parm_attr_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11parm_attr_d
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_22VEC_ipa_edge_args_t_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_20lto_symtab_entry_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_20ssa_operand_memory_d
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_13scev_info_str
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_24VEC_mem_addr_template_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_13VEC_gimple_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9type_hash
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16string_pool_data
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_13libfunc_entry
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
extern void gt_pch_p_10vcall_insn
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18VEC_vcall_entry_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18VEC_dcall_entry_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16var_loc_list_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_12var_loc_node
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_20VEC_die_arg_entry_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16limbo_die_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_20VEC_pubname_entry_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_19VEC_dw_attr_node_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18comdat_type_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_25dw_ranges_by_label_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16dw_ranges_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_28dw_separate_line_info_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_19dw_line_info_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_25VEC_deferred_locations_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18dw_loc_list_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_15dwarf_file_data
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_15queued_reg_save
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_20indirect_string_node
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_19dw_loc_descr_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_13dw_fde_struct
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
extern void gt_pch_p_12varpool_node
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_22VEC_cgraph_node_set_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_19cgraph_node_set_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_27cgraph_node_set_element_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_22VEC_cgraph_node_ptr_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11cgraph_edge
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_24VEC_ipa_replace_map_p_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_15ipa_replace_map
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
extern void gt_pch_p_17cselib_val_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_12elt_loc_list
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
extern void gt_pch_p_20initial_value_struct
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17rtx_constant_pool
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18VEC_temp_slot_p_gc
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
extern void gt_pch_p_8elt_list
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17tree_priority_map
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_12tree_int_map
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
extern void gt_pch_p_15varray_head_tag
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_12ptr_info_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_22VEC_constructor_elt_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17VEC_alias_pair_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11VEC_tree_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_12VEC_uchar_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_8function
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_23constant_descriptor_rtx
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_11fixed_value
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_10real_value
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_10VEC_rtx_gc
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_12object_block
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9reg_attrs
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_9mem_attrs
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_14bitmap_obstack
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_18bitmap_element_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_16machine_function
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17stack_local_entry
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_15basic_block_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_8edge_def
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_17gimple_seq_node_d
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
extern void gt_pch_p_IP9tree_node17splay_tree_node_s
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P15interface_tuple4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P16volatilized_type4htab
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
extern void gt_pch_p_P10spec_entry4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P16cxx_int_tree_map4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P17named_label_entry4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P12tree_int_map4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P20lto_symtab_entry_def4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_IP9tree_node12splay_tree_s
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P9tree_nodeP9tree_node12splay_tree_s
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P12varpool_node4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P13scev_info_str4htab
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
extern void gt_pch_p_P8tree_map4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P9type_hash4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P13libfunc_entry4htab
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
extern void gt_pch_p_SP9tree_node12splay_tree_s
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P10vcall_insn4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P16var_loc_list_def4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P10die_struct4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P15dwarf_file_data4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P20indirect_string_node4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P11cgraph_node4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_II12splay_tree_s
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P27cgraph_node_set_element_def4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P11cgraph_edge4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P9loop_exit4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P24types_used_by_vars_entry4htab
    (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_p_P9tree_node4htab
    (void *, void *, gt_pointer_operator, void *);
# 41 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/ggc.h" 2




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
# 114 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/ggc.h"
extern int ggc_set_mark (const void *);




extern int ggc_marked_p (const void *);


extern void ggc_mark_stringpool (void);


extern void ggc_purge_stringpool (void);



extern void ggc_mark_roots (void);



extern void gt_pch_save_stringpool (void);
extern void gt_pch_fixup_stringpool (void);
extern void gt_pch_restore_stringpool (void);



extern void gt_pch_p_S (void *, void *, gt_pointer_operator, void *);
extern void gt_pch_n_S (const void *);
extern void gt_ggc_m_S (const void *);


extern void init_stringpool (void);





struct alloc_zone;


extern void init_ggc (void);


extern struct alloc_zone *new_ggc_zone (const char *);


extern void destroy_ggc_zone (struct alloc_zone *);

struct ggc_pch_data;


extern struct ggc_pch_data *init_ggc_pch (void);





extern void ggc_pch_count_object (struct ggc_pch_data *, void *, size_t, unsigned char,
      enum gt_types_enum);



extern size_t ggc_pch_total_size (struct ggc_pch_data *);



extern void ggc_pch_this_base (struct ggc_pch_data *, void *);




extern char *ggc_pch_alloc_object (struct ggc_pch_data *, void *, size_t, unsigned char,
       enum gt_types_enum);


extern void ggc_pch_prepare_write (struct ggc_pch_data *, FILE *);


extern void ggc_pch_write_object (struct ggc_pch_data *, FILE *, void *,
      void *, size_t, unsigned char);


extern void ggc_pch_finish (struct ggc_pch_data *, FILE *);



extern void ggc_pch_read (FILE *, void *);





extern unsigned char ggc_force_collect;





extern unsigned char ggc_protect_identifiers;


extern void *ggc_alloc_stat (size_t );


extern void *ggc_alloc_typed_stat (enum gt_types_enum, size_t );


extern void *ggc_alloc_cleared_stat (size_t );


extern void *ggc_realloc_stat (void *, size_t );


extern void *ggc_calloc (size_t, size_t);

extern void ggc_free (void *);

extern void ggc_record_overhead (size_t, size_t, void * );
extern void ggc_free_overhead (void *);
extern void ggc_prune_overhead_list (void);

extern void dump_ggc_loc_statistics (unsigned char);
# 259 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/ggc.h"
extern void *ggc_splay_alloc (int, void *);
extern void ggc_splay_dont_free (void *, void *);




extern const char *ggc_alloc_string (const char *contents, int length);






extern void ggc_collect (void);



extern void ggc_register_root_tab (const struct ggc_root_tab *);



extern void ggc_register_cache_tab (const struct ggc_cache_tab *);


extern size_t ggc_get_size (const void *);


extern void gt_pch_save (FILE *f);


extern void gt_pch_restore (FILE *f);





typedef struct ggc_statistics
{

  int unused;
} ggc_statistics;



extern void ggc_print_common_statistics (FILE *, ggc_statistics *);


extern void ggc_print_statistics (void);
extern void stringpool_statistics (void);


extern int ggc_min_expand_heuristic (void);
extern int ggc_min_heapsize_heuristic (void);
extern void init_ggc_heuristics (void);
# 28 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.h" 2
# 48 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.h"
enum rid
{


  RID_STATIC = 0,
  RID_UNSIGNED, RID_LONG, RID_CONST, RID_EXTERN,
  RID_REGISTER, RID_TYPEDEF, RID_SHORT, RID_INLINE,
  RID_VOLATILE, RID_SIGNED, RID_AUTO, RID_RESTRICT,


  RID_COMPLEX, RID_THREAD, RID_SAT,


  RID_FRIEND, RID_VIRTUAL, RID_EXPLICIT, RID_EXPORT, RID_MUTABLE,


  RID_IN, RID_OUT, RID_INOUT, RID_BYCOPY, RID_BYREF, RID_ONEWAY,



  RID_IMAGINARY,


  RID_INT, RID_CHAR, RID_FLOAT, RID_DOUBLE, RID_VOID,
  RID_ENUM, RID_STRUCT, RID_UNION, RID_IF, RID_ELSE,
  RID_WHILE, RID_DO, RID_FOR, RID_SWITCH, RID_CASE,
  RID_DEFAULT, RID_BREAK, RID_CONTINUE, RID_RETURN, RID_GOTO,
  RID_SIZEOF,


  RID_ASM, RID_TYPEOF, RID_ALIGNOF, RID_ATTRIBUTE, RID_VA_ARG,
  RID_EXTENSION, RID_IMAGPART, RID_REALPART, RID_LABEL, RID_CHOOSE_EXPR,
  RID_TYPES_COMPATIBLE_P,
  RID_DFLOAT32, RID_DFLOAT64, RID_DFLOAT128,
  RID_FRACT, RID_ACCUM,



  RID_CXX_COMPAT_WARN,


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


  RID_HAS_NOTHROW_ASSIGN, RID_HAS_NOTHROW_CONSTRUCTOR,
  RID_HAS_NOTHROW_COPY, RID_HAS_TRIVIAL_ASSIGN,
  RID_HAS_TRIVIAL_CONSTRUCTOR, RID_HAS_TRIVIAL_COPY,
  RID_HAS_TRIVIAL_DESTRUCTOR, RID_HAS_VIRTUAL_DESTRUCTOR,
  RID_IS_ABSTRACT, RID_IS_BASE_OF,
  RID_IS_CONVERTIBLE_TO, RID_IS_CLASS,
  RID_IS_EMPTY, RID_IS_ENUM,
  RID_IS_POD, RID_IS_POLYMORPHIC,
  RID_IS_STD_LAYOUT, RID_IS_TRIVIAL,
  RID_IS_UNION,


  RID_STATIC_ASSERT, RID_CONSTEXPR, RID_DECLTYPE,


  RID_AT_ENCODE, RID_AT_END,
  RID_AT_CLASS, RID_AT_ALIAS, RID_AT_DEFS,
  RID_AT_PRIVATE, RID_AT_PROTECTED, RID_AT_PUBLIC,
  RID_AT_PROTOCOL, RID_AT_SELECTOR,
  RID_AT_THROW, RID_AT_TRY, RID_AT_CATCH,
  RID_AT_FINALLY, RID_AT_SYNCHRONIZED,
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

  RID_FIRST_CXX0X = RID_STATIC_ASSERT,
  RID_LAST_CXX0X = RID_DECLTYPE,
  RID_FIRST_AT = RID_AT_ENCODE,
  RID_LAST_AT = RID_AT_IMPLEMENTATION,
  RID_FIRST_PQ = RID_IN,
  RID_LAST_PQ = RID_ONEWAY
};
# 176 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.h"
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
# 261 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.h"
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
# 295 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.h"
extern const struct c_common_resword c_common_reswords[];


extern const unsigned int num_c_common_reswords;
# 365 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.h"
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

  tree x_cur_stmt_list;
# 428 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.h"
  int stmts_are_full_exprs_p;
};

typedef struct stmt_tree_s *stmt_tree;




struct c_language_function {


  struct stmt_tree_s x_stmt_tree;
};
# 452 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.h"
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





extern int flag_preprocess_only;




extern int flag_nil_receivers;



extern int flag_objc_exceptions;


extern int flag_objc_sjlj_exceptions;




extern int flag_zero_link;




extern int flag_replace_objc_classes;



extern char flag_no_line_commands;




extern char flag_no_output;




extern char flag_dump_macros;



extern char flag_dump_includes;



extern unsigned char flag_pch_preprocess;




extern const char *pch_file;




extern int flag_iso;




extern int flag_undef;



extern int flag_no_builtin;




extern int flag_no_nonansi_builtin;



extern int flag_short_double;



extern int flag_short_wchar;



extern int flag_lax_vector_conversions;


extern int flag_ms_extensions;



extern int flag_no_asm;




extern int flag_const_strings;



extern int flag_signed_bitfields;



extern int warn_unknown_pragmas;




extern int warn_format;
# 592 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.h"
extern int flag_cond_mismatch;



extern int flag_isoc94;



extern int flag_isoc99;



extern int flag_hosted;







extern int flag_gen_declaration;





extern int print_struct_values;



extern const char *constant_string_class_name;







extern int flag_no_gnu_keywords;




extern int flag_implement_inlines;



extern int flag_implicit_templates;





extern int flag_implicit_inline_templates;




extern int flag_use_repository;




extern int flag_optional_diags;



extern int flag_elide_constructors;




extern int flag_default_inline;




extern int flag_rtti;






extern int flag_conserve_space;



extern int flag_access_control;




extern int flag_check_new;



enum cxx_dialect {

  cxx98,


  cxx0x
};


extern enum cxx_dialect cxx_dialect;
# 707 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.h"
extern int flag_new_for_scope;





extern int flag_weak;






extern int flag_working_directory;




extern int flag_use_cxa_atexit;




extern int flag_use_cxa_get_exception_ptr;






extern int flag_enforce_eh_specs;




extern int flag_threadsafe_statics;




extern int flag_pretty_templates;



extern int warn_implicit;





extern int warn_strict_null_sentinel;





extern int max_tinst_depth;







extern int c_inhibit_evaluation_warnings;




extern unsigned char done_lexing;
# 795 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.h"
extern const struct attribute_spec c_common_attribute_table[];
extern const struct attribute_spec c_common_format_attribute_table[];






extern tree (*make_fname_decl) (location_t, tree, int);

extern unsigned char in_late_binary_op;
extern const char *c_addr_space_name (addr_space_t as);
extern tree identifier_global_value (tree);
extern void record_builtin_type (enum rid, const char *, tree);
extern tree build_void_list_node (void);
extern void start_fname_decls (void);
extern void finish_fname_decls (void);
extern const char *fname_as_string (int);
extern tree fname_decl (location_t, unsigned, tree);

extern void check_function_arguments (tree, int, tree *, tree);
extern void check_function_arguments_recurse (void (*)
           (void *, tree,
            unsigned long),
           void *, tree,
           unsigned long);
extern unsigned char check_builtin_function_arguments (tree, int, tree *);
extern void check_function_format (tree, int, tree *);
extern void set_Wformat (int);
extern tree handle_format_attribute (tree *, tree, tree, int, unsigned char *);
extern tree handle_format_arg_attribute (tree *, tree, tree, int, unsigned char *);
extern int c_common_handle_option (size_t code, const char *arg, int value);
extern unsigned char c_common_missing_argument (const char *opt, size_t code);
extern tree c_common_type_for_mode (enum machine_mode, int);
extern tree c_common_type_for_size (unsigned int, int);
extern tree c_common_fixed_point_type_for_size (unsigned int, unsigned int,
      int, int);
extern tree c_common_unsigned_type (tree);
extern tree c_common_signed_type (tree);
extern tree c_common_signed_or_unsigned_type (int, tree);
extern tree c_build_bitfield_integer_type (unsigned long, int);
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
struct varray_head_tag;
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





extern tree shorten_binary_op (tree result_type, tree op0, tree op1, unsigned char bitwise);




extern tree shorten_compare (tree *, tree *, tree *, enum tree_code *);

extern tree pointer_int_sum (location_t, enum tree_code, tree, tree);


extern tree c_build_qualified_type (tree, int);



extern void c_common_nodes_and_builtins (void);

extern void disable_builtin_function (const char *);

extern void set_compound_literal_name (tree decl);

extern tree build_va_arg (location_t, tree, tree);

extern unsigned int c_common_init_options (unsigned int, const char **);
extern unsigned char c_common_post_options (const char **);
extern unsigned char c_common_init (void);
extern void c_common_finish (void);
extern void c_common_parse_file (int);
extern alias_set_type c_common_get_alias_set (tree);
extern void c_register_builtin_type (tree, const char*);
extern unsigned char c_promoting_integer_type_p (const_tree);
extern int self_promoting_args_p (const_tree);
extern tree strip_pointer_operator (tree);
extern tree strip_pointer_or_array_types (tree);
extern long c_common_to_target_charset (long);


extern void c_parse_file (void);

extern void finish_file (void);
# 946 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/c-common.h"
extern tree do_case (location_t, tree, tree);
extern tree build_stmt (location_t, enum tree_code, ...);
extern tree build_case_label (location_t, tree, tree, tree);




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

extern tree fold_offsetof (tree, tree);




enum lvalue_use {
  lv_assign,
  lv_increment,
  lv_decrement,
  lv_addressof,
  lv_asm
};

extern void lvalue_error (enum lvalue_use);

extern int complete_array_type (tree *, tree, unsigned char);

extern tree builtin_type_for_size (int, unsigned char);

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
extern void set_underlying_type (tree x);
extern unsigned char is_typedef_decl (tree x);
extern VEC_tree_gc *make_tree_vector (void);
extern void release_tree_vector (VEC_tree_gc *);
extern VEC_tree_gc *make_tree_vector_single (tree);
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





extern tree objc_is_class_name (tree);
extern tree objc_is_object_ptr (tree);
extern void objc_check_decl (tree);
extern int objc_is_reserved_word (tree);
extern unsigned char objc_compare_types (tree, tree, int, tree);
extern void objc_volatilize_decl (tree);
extern unsigned char objc_type_quals_match (tree, tree);
extern tree objc_rewrite_function_call (tree, tree);
extern tree objc_message_selector (void);
extern tree objc_lookup_ivar (tree, tree);
extern void objc_clear_super_receiver (void);
extern int objc_is_public (tree, tree);
extern tree objc_is_id (tree);
extern void objc_declare_alias (tree, tree);
extern void objc_declare_class (tree);
extern void objc_declare_protocols (tree);
extern tree objc_build_message_expr (tree);
extern tree objc_finish_message_expr (tree, tree, tree);
extern tree objc_build_selector_expr (location_t, tree);
extern tree objc_build_protocol_expr (tree);
extern tree objc_build_encode_expr (tree);
extern tree objc_build_string_object (tree);
extern tree objc_get_protocol_qualified_type (tree, tree);
extern tree objc_get_class_reference (tree);
extern tree objc_get_class_ivars (tree);
extern void objc_start_class_interface (tree, tree, tree);
extern void objc_start_category_interface (tree, tree, tree);
extern void objc_start_protocol (tree, tree);
extern void objc_continue_interface (void);
extern void objc_finish_interface (void);
extern void objc_start_class_implementation (tree, tree);
extern void objc_start_category_implementation (tree, tree);
extern void objc_continue_implementation (void);
extern void objc_finish_implementation (void);
extern void objc_set_visibility (int);
extern void objc_set_method_type (enum tree_code);
extern tree objc_build_method_signature (tree, tree, tree, unsigned char);
extern void objc_add_method_declaration (tree);
extern void objc_start_method_definition (tree);
extern void objc_finish_method_definition (tree);
extern void objc_add_instance_variable (tree);
extern tree objc_build_keyword_decl (tree, tree, tree);
extern tree objc_build_throw_stmt (location_t, tree);
extern void objc_begin_try_stmt (location_t, tree);
extern tree objc_finish_try_stmt (void);
extern void objc_begin_catch_clause (tree);
extern void objc_finish_catch_clause (void);
extern void objc_build_finally_clause (location_t, tree);
extern tree objc_build_synchronized (location_t, tree, tree);
extern int objc_static_init_needed_p (void);
extern tree objc_generate_static_init_call (tree);
extern tree objc_generate_write_barrier (tree, enum tree_code, tree);



extern void *objc_get_current_scope (void);
extern void objc_mark_locals_volatile (void *);


extern void init_pp_output (FILE *);
extern void preprocess_file (cpp_reader *);
extern void pp_file_change (const struct line_map *);
extern void pp_dir_change (cpp_reader *, const char *);
extern unsigned char check_missing_format_attribute (tree, tree);


extern tree c_finish_omp_master (location_t, tree);
extern tree c_finish_omp_critical (location_t, tree, tree);
extern tree c_finish_omp_ordered (location_t, tree);
extern void c_finish_omp_barrier (location_t);
extern tree c_finish_omp_atomic (location_t, enum tree_code, tree, tree);
extern void c_finish_omp_flush (location_t);
extern void c_finish_omp_taskwait (location_t);
extern tree c_finish_omp_for (location_t, tree, tree, tree, tree, tree, tree);
extern void c_split_parallel_clauses (location_t, tree, tree *, tree *);
extern enum omp_clause_default_kind c_omp_predetermined_sharing (tree);


extern unsigned char c_omp_sharing_predetermined (tree);
extern tree c_omp_remap_decl (tree, unsigned char);
extern void record_types_used_by_current_var_decl (tree);
# 40 "../../../src/plugin-utils.h" 2

# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/function.h" 1
# 25 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/function.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/tree.h" 1
# 26 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/function.h" 2

# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/vecprim.h" 1
# 23 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/vecprim.h"
static __inline__ void VEC_char_must_be_integral_type (void) { (void)~(char)0; } typedef struct VEC_char_base { unsigned num; unsigned alloc; char vec[1]; } VEC_char_base; typedef struct VEC_char_none { VEC_char_base base; } VEC_char_none; static __inline__ unsigned VEC_char_base_length (const VEC_char_base *vec_) { return vec_ ? vec_->num : 0; } static __inline__ char VEC_char_base_last (const VEC_char_base *vec_ ) { (void)(vec_ && vec_->num); return vec_->vec[vec_->num - 1]; } static __inline__ char VEC_char_base_index (const VEC_char_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->num); return vec_->vec[ix_]; } static __inline__ int VEC_char_base_iterate (const VEC_char_base *vec_, unsigned ix_, char *ptr) { if (vec_ && ix_ < vec_->num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (char) 0; return 0; } } static __inline__ size_t VEC_char_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_char_base, vec) + alloc_ * sizeof(char); } static __inline__ void VEC_char_base_embedded_init (VEC_char_base *vec_, int alloc_) { vec_->num = 0; vec_->alloc = alloc_; } static __inline__ int VEC_char_base_space (VEC_char_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->alloc - vec_->num >= (unsigned)alloc_ : !alloc_; } static __inline__ char *VEC_char_base_quick_push (VEC_char_base *vec_, char obj_ ) { char *slot_; (void)(vec_->num < vec_->alloc); slot_ = &vec_->vec[vec_->num++]; *slot_ = obj_; return slot_; } static __inline__ char VEC_char_base_pop (VEC_char_base *vec_ ) { char obj_; (void)(vec_->num); obj_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_char_base_truncate (VEC_char_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->num >= size_ : !size_); if (vec_) vec_->num = size_; } static __inline__ char VEC_char_base_replace (VEC_char_base *vec_, unsigned ix_, char obj_ ) { char old_obj_; (void)(ix_ < vec_->num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ char *VEC_char_base_quick_insert (VEC_char_base *vec_, unsigned ix_, char obj_ ) { char *slot_; (void)(vec_->num < vec_->alloc); (void)(ix_ <= vec_->num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->num++ - ix_) * sizeof (char)); *slot_ = obj_; return slot_; } static __inline__ char VEC_char_base_ordered_remove (VEC_char_base *vec_, unsigned ix_ ) { char *slot_; char obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->num - ix_) * sizeof (char)); return obj_; } static __inline__ char VEC_char_base_unordered_remove (VEC_char_base *vec_, unsigned ix_ ) { char *slot_; char obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_char_base_block_remove (VEC_char_base *vec_, unsigned ix_, unsigned len_ ) { char *slot_; (void)(ix_ + len_ <= vec_->num); slot_ = &vec_->vec[ix_]; vec_->num -= len_; memmove (slot_, slot_ + len_, (vec_->num - ix_) * sizeof (char)); } static __inline__ char *VEC_char_base_address (VEC_char_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_char_base_lower_bound (VEC_char_base *vec_, const char obj_, unsigned char (*lessthan_)(const char, const char) ) { unsigned int len_ = VEC_char_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { char middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_char_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_char_heap { VEC_char_base base; } VEC_char_heap; static __inline__ VEC_char_heap *VEC_char_heap_alloc (int alloc_ ) { return (VEC_char_heap *) vec_heap_o_reserve_exact (((void *)0), alloc_, __builtin_offsetof (VEC_char_heap, base.vec), sizeof (char) ); } static __inline__ VEC_char_heap *VEC_char_heap_copy (VEC_char_base *vec_ ) { size_t len_ = vec_ ? vec_->num : 0; VEC_char_heap *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_char_heap *)(vec_heap_o_reserve_exact (((void *)0), len_, __builtin_offsetof (VEC_char_heap, base.vec), sizeof (char) )); new_vec_->base.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (char) * len_); } return new_vec_; } static __inline__ void VEC_char_heap_free (VEC_char_heap **vec_) { if (*vec_) free (*vec_); *vec_ = ((void *)0); } static __inline__ int VEC_char_heap_reserve (VEC_char_heap **vec_, int alloc_ ) { int extend = !VEC_char_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_char_heap *) vec_heap_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_char_heap, base.vec), sizeof (char) ); return extend; } static __inline__ int VEC_char_heap_reserve_exact (VEC_char_heap **vec_, int alloc_ ) { int extend = !VEC_char_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_char_heap *) vec_heap_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_char_heap, base.vec), sizeof (char) ); return extend; } static __inline__ void VEC_char_heap_safe_grow (VEC_char_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_char_base_length ((*vec_) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_char_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((*vec_) ? &(*vec_)->base : 0)->num : 0) ); ((*vec_) ? &(*vec_)->base : 0)->num = size_; } static __inline__ void VEC_char_heap_safe_grow_cleared (VEC_char_heap **vec_, int size_ ) { int oldsize = VEC_char_base_length ((*vec_) ? &(*vec_)->base : 0); VEC_char_heap_safe_grow (vec_, size_ ); memset (&(VEC_char_base_address ((*vec_) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (char) * (size_ - oldsize)); } static __inline__ char *VEC_char_heap_safe_push (VEC_char_heap **vec_, const char obj_ ) { VEC_char_heap_reserve (vec_, 1 ); return VEC_char_base_quick_push (((*vec_) ? &(*vec_)->base : 0), obj_ ); } static __inline__ char *VEC_char_heap_safe_insert (VEC_char_heap **vec_, unsigned ix_, const char obj_ ) { VEC_char_heap_reserve (vec_, 1 ); return VEC_char_base_quick_insert (((*vec_) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;

typedef unsigned char uchar;
static __inline__ void VEC_uchar_must_be_integral_type (void) { (void)~(uchar)0; } typedef struct VEC_uchar_base { unsigned num; unsigned alloc; uchar vec[1]; } VEC_uchar_base; typedef struct VEC_uchar_none { VEC_uchar_base base; } VEC_uchar_none; static __inline__ unsigned VEC_uchar_base_length (const VEC_uchar_base *vec_) { return vec_ ? vec_->num : 0; } static __inline__ uchar VEC_uchar_base_last (const VEC_uchar_base *vec_ ) { (void)(vec_ && vec_->num); return vec_->vec[vec_->num - 1]; } static __inline__ uchar VEC_uchar_base_index (const VEC_uchar_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->num); return vec_->vec[ix_]; } static __inline__ int VEC_uchar_base_iterate (const VEC_uchar_base *vec_, unsigned ix_, uchar *ptr) { if (vec_ && ix_ < vec_->num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (uchar) 0; return 0; } } static __inline__ size_t VEC_uchar_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_uchar_base, vec) + alloc_ * sizeof(uchar); } static __inline__ void VEC_uchar_base_embedded_init (VEC_uchar_base *vec_, int alloc_) { vec_->num = 0; vec_->alloc = alloc_; } static __inline__ int VEC_uchar_base_space (VEC_uchar_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->alloc - vec_->num >= (unsigned)alloc_ : !alloc_; } static __inline__ uchar *VEC_uchar_base_quick_push (VEC_uchar_base *vec_, uchar obj_ ) { uchar *slot_; (void)(vec_->num < vec_->alloc); slot_ = &vec_->vec[vec_->num++]; *slot_ = obj_; return slot_; } static __inline__ uchar VEC_uchar_base_pop (VEC_uchar_base *vec_ ) { uchar obj_; (void)(vec_->num); obj_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_uchar_base_truncate (VEC_uchar_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->num >= size_ : !size_); if (vec_) vec_->num = size_; } static __inline__ uchar VEC_uchar_base_replace (VEC_uchar_base *vec_, unsigned ix_, uchar obj_ ) { uchar old_obj_; (void)(ix_ < vec_->num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ uchar *VEC_uchar_base_quick_insert (VEC_uchar_base *vec_, unsigned ix_, uchar obj_ ) { uchar *slot_; (void)(vec_->num < vec_->alloc); (void)(ix_ <= vec_->num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->num++ - ix_) * sizeof (uchar)); *slot_ = obj_; return slot_; } static __inline__ uchar VEC_uchar_base_ordered_remove (VEC_uchar_base *vec_, unsigned ix_ ) { uchar *slot_; uchar obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->num - ix_) * sizeof (uchar)); return obj_; } static __inline__ uchar VEC_uchar_base_unordered_remove (VEC_uchar_base *vec_, unsigned ix_ ) { uchar *slot_; uchar obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_uchar_base_block_remove (VEC_uchar_base *vec_, unsigned ix_, unsigned len_ ) { uchar *slot_; (void)(ix_ + len_ <= vec_->num); slot_ = &vec_->vec[ix_]; vec_->num -= len_; memmove (slot_, slot_ + len_, (vec_->num - ix_) * sizeof (uchar)); } static __inline__ uchar *VEC_uchar_base_address (VEC_uchar_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_uchar_base_lower_bound (VEC_uchar_base *vec_, const uchar obj_, unsigned char (*lessthan_)(const uchar, const uchar) ) { unsigned int len_ = VEC_uchar_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { uchar middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_uchar_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_uchar_heap { VEC_uchar_base base; } VEC_uchar_heap; static __inline__ VEC_uchar_heap *VEC_uchar_heap_alloc (int alloc_ ) { return (VEC_uchar_heap *) vec_heap_o_reserve_exact (((void *)0), alloc_, __builtin_offsetof (VEC_uchar_heap, base.vec), sizeof (uchar) ); } static __inline__ VEC_uchar_heap *VEC_uchar_heap_copy (VEC_uchar_base *vec_ ) { size_t len_ = vec_ ? vec_->num : 0; VEC_uchar_heap *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_uchar_heap *)(vec_heap_o_reserve_exact (((void *)0), len_, __builtin_offsetof (VEC_uchar_heap, base.vec), sizeof (uchar) )); new_vec_->base.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (uchar) * len_); } return new_vec_; } static __inline__ void VEC_uchar_heap_free (VEC_uchar_heap **vec_) { if (*vec_) free (*vec_); *vec_ = ((void *)0); } static __inline__ int VEC_uchar_heap_reserve (VEC_uchar_heap **vec_, int alloc_ ) { int extend = !VEC_uchar_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_uchar_heap *) vec_heap_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_uchar_heap, base.vec), sizeof (uchar) ); return extend; } static __inline__ int VEC_uchar_heap_reserve_exact (VEC_uchar_heap **vec_, int alloc_ ) { int extend = !VEC_uchar_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_uchar_heap *) vec_heap_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_uchar_heap, base.vec), sizeof (uchar) ); return extend; } static __inline__ void VEC_uchar_heap_safe_grow (VEC_uchar_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_uchar_base_length ((*vec_) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_uchar_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((*vec_) ? &(*vec_)->base : 0)->num : 0) ); ((*vec_) ? &(*vec_)->base : 0)->num = size_; } static __inline__ void VEC_uchar_heap_safe_grow_cleared (VEC_uchar_heap **vec_, int size_ ) { int oldsize = VEC_uchar_base_length ((*vec_) ? &(*vec_)->base : 0); VEC_uchar_heap_safe_grow (vec_, size_ ); memset (&(VEC_uchar_base_address ((*vec_) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (uchar) * (size_ - oldsize)); } static __inline__ uchar *VEC_uchar_heap_safe_push (VEC_uchar_heap **vec_, const uchar obj_ ) { VEC_uchar_heap_reserve (vec_, 1 ); return VEC_uchar_base_quick_push (((*vec_) ? &(*vec_)->base : 0), obj_ ); } static __inline__ uchar *VEC_uchar_heap_safe_insert (VEC_uchar_heap **vec_, unsigned ix_, const uchar obj_ ) { VEC_uchar_heap_reserve (vec_, 1 ); return VEC_uchar_base_quick_insert (((*vec_) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
typedef struct VEC_uchar_gc { VEC_uchar_base base; } VEC_uchar_gc; static __inline__ VEC_uchar_gc *VEC_uchar_gc_alloc (int alloc_ ) { return (VEC_uchar_gc *) vec_gc_o_reserve_exact (((void *)0), alloc_, __builtin_offsetof (VEC_uchar_gc, base.vec), sizeof (uchar) ); } static __inline__ VEC_uchar_gc *VEC_uchar_gc_copy (VEC_uchar_base *vec_ ) { size_t len_ = vec_ ? vec_->num : 0; VEC_uchar_gc *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_uchar_gc *)(vec_gc_o_reserve_exact (((void *)0), len_, __builtin_offsetof (VEC_uchar_gc, base.vec), sizeof (uchar) )); new_vec_->base.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (uchar) * len_); } return new_vec_; } static __inline__ void VEC_uchar_gc_free (VEC_uchar_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = ((void *)0); } static __inline__ int VEC_uchar_gc_reserve (VEC_uchar_gc **vec_, int alloc_ ) { int extend = !VEC_uchar_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_uchar_gc *) vec_gc_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_uchar_gc, base.vec), sizeof (uchar) ); return extend; } static __inline__ int VEC_uchar_gc_reserve_exact (VEC_uchar_gc **vec_, int alloc_ ) { int extend = !VEC_uchar_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_uchar_gc *) vec_gc_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_uchar_gc, base.vec), sizeof (uchar) ); return extend; } static __inline__ void VEC_uchar_gc_safe_grow (VEC_uchar_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_uchar_base_length ((*vec_) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_uchar_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((*vec_) ? &(*vec_)->base : 0)->num : 0) ); ((*vec_) ? &(*vec_)->base : 0)->num = size_; } static __inline__ void VEC_uchar_gc_safe_grow_cleared (VEC_uchar_gc **vec_, int size_ ) { int oldsize = VEC_uchar_base_length ((*vec_) ? &(*vec_)->base : 0); VEC_uchar_gc_safe_grow (vec_, size_ ); memset (&(VEC_uchar_base_address ((*vec_) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (uchar) * (size_ - oldsize)); } static __inline__ uchar *VEC_uchar_gc_safe_push (VEC_uchar_gc **vec_, const uchar obj_ ) { VEC_uchar_gc_reserve (vec_, 1 ); return VEC_uchar_base_quick_push (((*vec_) ? &(*vec_)->base : 0), obj_ ); } static __inline__ uchar *VEC_uchar_gc_safe_insert (VEC_uchar_gc **vec_, unsigned ix_, const uchar obj_ ) { VEC_uchar_gc_reserve (vec_, 1 ); return VEC_uchar_base_quick_insert (((*vec_) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;

static __inline__ void VEC_int_must_be_integral_type (void) { (void)~(int)0; } typedef struct VEC_int_base { unsigned num; unsigned alloc; int vec[1]; } VEC_int_base; typedef struct VEC_int_none { VEC_int_base base; } VEC_int_none; static __inline__ unsigned VEC_int_base_length (const VEC_int_base *vec_) { return vec_ ? vec_->num : 0; } static __inline__ int VEC_int_base_last (const VEC_int_base *vec_ ) { (void)(vec_ && vec_->num); return vec_->vec[vec_->num - 1]; } static __inline__ int VEC_int_base_index (const VEC_int_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->num); return vec_->vec[ix_]; } static __inline__ int VEC_int_base_iterate (const VEC_int_base *vec_, unsigned ix_, int *ptr) { if (vec_ && ix_ < vec_->num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (int) 0; return 0; } } static __inline__ size_t VEC_int_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_int_base, vec) + alloc_ * sizeof(int); } static __inline__ void VEC_int_base_embedded_init (VEC_int_base *vec_, int alloc_) { vec_->num = 0; vec_->alloc = alloc_; } static __inline__ int VEC_int_base_space (VEC_int_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->alloc - vec_->num >= (unsigned)alloc_ : !alloc_; } static __inline__ int *VEC_int_base_quick_push (VEC_int_base *vec_, int obj_ ) { int *slot_; (void)(vec_->num < vec_->alloc); slot_ = &vec_->vec[vec_->num++]; *slot_ = obj_; return slot_; } static __inline__ int VEC_int_base_pop (VEC_int_base *vec_ ) { int obj_; (void)(vec_->num); obj_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_int_base_truncate (VEC_int_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->num >= size_ : !size_); if (vec_) vec_->num = size_; } static __inline__ int VEC_int_base_replace (VEC_int_base *vec_, unsigned ix_, int obj_ ) { int old_obj_; (void)(ix_ < vec_->num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ int *VEC_int_base_quick_insert (VEC_int_base *vec_, unsigned ix_, int obj_ ) { int *slot_; (void)(vec_->num < vec_->alloc); (void)(ix_ <= vec_->num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->num++ - ix_) * sizeof (int)); *slot_ = obj_; return slot_; } static __inline__ int VEC_int_base_ordered_remove (VEC_int_base *vec_, unsigned ix_ ) { int *slot_; int obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->num - ix_) * sizeof (int)); return obj_; } static __inline__ int VEC_int_base_unordered_remove (VEC_int_base *vec_, unsigned ix_ ) { int *slot_; int obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_int_base_block_remove (VEC_int_base *vec_, unsigned ix_, unsigned len_ ) { int *slot_; (void)(ix_ + len_ <= vec_->num); slot_ = &vec_->vec[ix_]; vec_->num -= len_; memmove (slot_, slot_ + len_, (vec_->num - ix_) * sizeof (int)); } static __inline__ int *VEC_int_base_address (VEC_int_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_int_base_lower_bound (VEC_int_base *vec_, const int obj_, unsigned char (*lessthan_)(const int, const int) ) { unsigned int len_ = VEC_int_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { int middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_int_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_int_heap { VEC_int_base base; } VEC_int_heap; static __inline__ VEC_int_heap *VEC_int_heap_alloc (int alloc_ ) { return (VEC_int_heap *) vec_heap_o_reserve_exact (((void *)0), alloc_, __builtin_offsetof (VEC_int_heap, base.vec), sizeof (int) ); } static __inline__ VEC_int_heap *VEC_int_heap_copy (VEC_int_base *vec_ ) { size_t len_ = vec_ ? vec_->num : 0; VEC_int_heap *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_int_heap *)(vec_heap_o_reserve_exact (((void *)0), len_, __builtin_offsetof (VEC_int_heap, base.vec), sizeof (int) )); new_vec_->base.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (int) * len_); } return new_vec_; } static __inline__ void VEC_int_heap_free (VEC_int_heap **vec_) { if (*vec_) free (*vec_); *vec_ = ((void *)0); } static __inline__ int VEC_int_heap_reserve (VEC_int_heap **vec_, int alloc_ ) { int extend = !VEC_int_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_int_heap *) vec_heap_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_int_heap, base.vec), sizeof (int) ); return extend; } static __inline__ int VEC_int_heap_reserve_exact (VEC_int_heap **vec_, int alloc_ ) { int extend = !VEC_int_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_int_heap *) vec_heap_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_int_heap, base.vec), sizeof (int) ); return extend; } static __inline__ void VEC_int_heap_safe_grow (VEC_int_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_int_base_length ((*vec_) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_int_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((*vec_) ? &(*vec_)->base : 0)->num : 0) ); ((*vec_) ? &(*vec_)->base : 0)->num = size_; } static __inline__ void VEC_int_heap_safe_grow_cleared (VEC_int_heap **vec_, int size_ ) { int oldsize = VEC_int_base_length ((*vec_) ? &(*vec_)->base : 0); VEC_int_heap_safe_grow (vec_, size_ ); memset (&(VEC_int_base_address ((*vec_) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (int) * (size_ - oldsize)); } static __inline__ int *VEC_int_heap_safe_push (VEC_int_heap **vec_, const int obj_ ) { VEC_int_heap_reserve (vec_, 1 ); return VEC_int_base_quick_push (((*vec_) ? &(*vec_)->base : 0), obj_ ); } static __inline__ int *VEC_int_heap_safe_insert (VEC_int_heap **vec_, unsigned ix_, const int obj_ ) { VEC_int_heap_reserve (vec_, 1 ); return VEC_int_base_quick_insert (((*vec_) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;

static __inline__ void VEC_unsigned_must_be_integral_type (void) { (void)~(unsigned)0; } typedef struct VEC_unsigned_base { unsigned num; unsigned alloc; unsigned vec[1]; } VEC_unsigned_base; typedef struct VEC_unsigned_none { VEC_unsigned_base base; } VEC_unsigned_none; static __inline__ unsigned VEC_unsigned_base_length (const VEC_unsigned_base *vec_) { return vec_ ? vec_->num : 0; } static __inline__ unsigned VEC_unsigned_base_last (const VEC_unsigned_base *vec_ ) { (void)(vec_ && vec_->num); return vec_->vec[vec_->num - 1]; } static __inline__ unsigned VEC_unsigned_base_index (const VEC_unsigned_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->num); return vec_->vec[ix_]; } static __inline__ int VEC_unsigned_base_iterate (const VEC_unsigned_base *vec_, unsigned ix_, unsigned *ptr) { if (vec_ && ix_ < vec_->num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (unsigned) 0; return 0; } } static __inline__ size_t VEC_unsigned_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_unsigned_base, vec) + alloc_ * sizeof(unsigned); } static __inline__ void VEC_unsigned_base_embedded_init (VEC_unsigned_base *vec_, int alloc_) { vec_->num = 0; vec_->alloc = alloc_; } static __inline__ int VEC_unsigned_base_space (VEC_unsigned_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->alloc - vec_->num >= (unsigned)alloc_ : !alloc_; } static __inline__ unsigned *VEC_unsigned_base_quick_push (VEC_unsigned_base *vec_, unsigned obj_ ) { unsigned *slot_; (void)(vec_->num < vec_->alloc); slot_ = &vec_->vec[vec_->num++]; *slot_ = obj_; return slot_; } static __inline__ unsigned VEC_unsigned_base_pop (VEC_unsigned_base *vec_ ) { unsigned obj_; (void)(vec_->num); obj_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_unsigned_base_truncate (VEC_unsigned_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->num >= size_ : !size_); if (vec_) vec_->num = size_; } static __inline__ unsigned VEC_unsigned_base_replace (VEC_unsigned_base *vec_, unsigned ix_, unsigned obj_ ) { unsigned old_obj_; (void)(ix_ < vec_->num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ unsigned *VEC_unsigned_base_quick_insert (VEC_unsigned_base *vec_, unsigned ix_, unsigned obj_ ) { unsigned *slot_; (void)(vec_->num < vec_->alloc); (void)(ix_ <= vec_->num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->num++ - ix_) * sizeof (unsigned)); *slot_ = obj_; return slot_; } static __inline__ unsigned VEC_unsigned_base_ordered_remove (VEC_unsigned_base *vec_, unsigned ix_ ) { unsigned *slot_; unsigned obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->num - ix_) * sizeof (unsigned)); return obj_; } static __inline__ unsigned VEC_unsigned_base_unordered_remove (VEC_unsigned_base *vec_, unsigned ix_ ) { unsigned *slot_; unsigned obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_unsigned_base_block_remove (VEC_unsigned_base *vec_, unsigned ix_, unsigned len_ ) { unsigned *slot_; (void)(ix_ + len_ <= vec_->num); slot_ = &vec_->vec[ix_]; vec_->num -= len_; memmove (slot_, slot_ + len_, (vec_->num - ix_) * sizeof (unsigned)); } static __inline__ unsigned *VEC_unsigned_base_address (VEC_unsigned_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_unsigned_base_lower_bound (VEC_unsigned_base *vec_, const unsigned obj_, unsigned char (*lessthan_)(const unsigned, const unsigned) ) { unsigned int len_ = VEC_unsigned_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { unsigned middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_unsigned_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_unsigned_heap { VEC_unsigned_base base; } VEC_unsigned_heap; static __inline__ VEC_unsigned_heap *VEC_unsigned_heap_alloc (int alloc_ ) { return (VEC_unsigned_heap *) vec_heap_o_reserve_exact (((void *)0), alloc_, __builtin_offsetof (VEC_unsigned_heap, base.vec), sizeof (unsigned) ); } static __inline__ VEC_unsigned_heap *VEC_unsigned_heap_copy (VEC_unsigned_base *vec_ ) { size_t len_ = vec_ ? vec_->num : 0; VEC_unsigned_heap *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_unsigned_heap *)(vec_heap_o_reserve_exact (((void *)0), len_, __builtin_offsetof (VEC_unsigned_heap, base.vec), sizeof (unsigned) )); new_vec_->base.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (unsigned) * len_); } return new_vec_; } static __inline__ void VEC_unsigned_heap_free (VEC_unsigned_heap **vec_) { if (*vec_) free (*vec_); *vec_ = ((void *)0); } static __inline__ int VEC_unsigned_heap_reserve (VEC_unsigned_heap **vec_, int alloc_ ) { int extend = !VEC_unsigned_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_unsigned_heap *) vec_heap_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_unsigned_heap, base.vec), sizeof (unsigned) ); return extend; } static __inline__ int VEC_unsigned_heap_reserve_exact (VEC_unsigned_heap **vec_, int alloc_ ) { int extend = !VEC_unsigned_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_unsigned_heap *) vec_heap_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_unsigned_heap, base.vec), sizeof (unsigned) ); return extend; } static __inline__ void VEC_unsigned_heap_safe_grow (VEC_unsigned_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_unsigned_base_length ((*vec_) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_unsigned_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((*vec_) ? &(*vec_)->base : 0)->num : 0) ); ((*vec_) ? &(*vec_)->base : 0)->num = size_; } static __inline__ void VEC_unsigned_heap_safe_grow_cleared (VEC_unsigned_heap **vec_, int size_ ) { int oldsize = VEC_unsigned_base_length ((*vec_) ? &(*vec_)->base : 0); VEC_unsigned_heap_safe_grow (vec_, size_ ); memset (&(VEC_unsigned_base_address ((*vec_) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (unsigned) * (size_ - oldsize)); } static __inline__ unsigned *VEC_unsigned_heap_safe_push (VEC_unsigned_heap **vec_, const unsigned obj_ ) { VEC_unsigned_heap_reserve (vec_, 1 ); return VEC_unsigned_base_quick_push (((*vec_) ? &(*vec_)->base : 0), obj_ ); } static __inline__ unsigned *VEC_unsigned_heap_safe_insert (VEC_unsigned_heap **vec_, unsigned ix_, const unsigned obj_ ) { VEC_unsigned_heap_reserve (vec_, 1 ); return VEC_unsigned_base_quick_insert (((*vec_) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
# 28 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/function.h" 2






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







extern rtx * regno_reg_rtx;







struct expr_status {


  int x_pending_stack_adjust;
# 121 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/function.h"
  int x_inhibit_defer_pop;





  int x_stack_pointer_delta;




  rtx x_saveregs_value;


  rtx x_apply_args_value;


  rtx x_forced_labels;
};

typedef struct call_site_record_d *call_site_record;
static __inline__ void VEC_call_site_record_must_be_pointer_type (void) { (void)((call_site_record)1 == (void *)1); } typedef struct VEC_call_site_record_base { unsigned num; unsigned alloc; call_site_record vec[1]; } VEC_call_site_record_base; typedef struct VEC_call_site_record_none { VEC_call_site_record_base base; } VEC_call_site_record_none; static __inline__ unsigned VEC_call_site_record_base_length (const VEC_call_site_record_base *vec_) { return vec_ ? vec_->num : 0; } static __inline__ call_site_record VEC_call_site_record_base_last (const VEC_call_site_record_base *vec_ ) { (void)(vec_ && vec_->num); return vec_->vec[vec_->num - 1]; } static __inline__ call_site_record VEC_call_site_record_base_index (const VEC_call_site_record_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->num); return vec_->vec[ix_]; } static __inline__ int VEC_call_site_record_base_iterate (const VEC_call_site_record_base *vec_, unsigned ix_, call_site_record *ptr) { if (vec_ && ix_ < vec_->num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (call_site_record) 0; return 0; } } static __inline__ size_t VEC_call_site_record_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_call_site_record_base, vec) + alloc_ * sizeof(call_site_record); } static __inline__ void VEC_call_site_record_base_embedded_init (VEC_call_site_record_base *vec_, int alloc_) { vec_->num = 0; vec_->alloc = alloc_; } static __inline__ int VEC_call_site_record_base_space (VEC_call_site_record_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->alloc - vec_->num >= (unsigned)alloc_ : !alloc_; } static __inline__ call_site_record *VEC_call_site_record_base_quick_push (VEC_call_site_record_base *vec_, call_site_record obj_ ) { call_site_record *slot_; (void)(vec_->num < vec_->alloc); slot_ = &vec_->vec[vec_->num++]; *slot_ = obj_; return slot_; } static __inline__ call_site_record VEC_call_site_record_base_pop (VEC_call_site_record_base *vec_ ) { call_site_record obj_; (void)(vec_->num); obj_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_call_site_record_base_truncate (VEC_call_site_record_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->num >= size_ : !size_); if (vec_) vec_->num = size_; } static __inline__ call_site_record VEC_call_site_record_base_replace (VEC_call_site_record_base *vec_, unsigned ix_, call_site_record obj_ ) { call_site_record old_obj_; (void)(ix_ < vec_->num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ call_site_record *VEC_call_site_record_base_quick_insert (VEC_call_site_record_base *vec_, unsigned ix_, call_site_record obj_ ) { call_site_record *slot_; (void)(vec_->num < vec_->alloc); (void)(ix_ <= vec_->num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->num++ - ix_) * sizeof (call_site_record)); *slot_ = obj_; return slot_; } static __inline__ call_site_record VEC_call_site_record_base_ordered_remove (VEC_call_site_record_base *vec_, unsigned ix_ ) { call_site_record *slot_; call_site_record obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->num - ix_) * sizeof (call_site_record)); return obj_; } static __inline__ call_site_record VEC_call_site_record_base_unordered_remove (VEC_call_site_record_base *vec_, unsigned ix_ ) { call_site_record *slot_; call_site_record obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_call_site_record_base_block_remove (VEC_call_site_record_base *vec_, unsigned ix_, unsigned len_ ) { call_site_record *slot_; (void)(ix_ + len_ <= vec_->num); slot_ = &vec_->vec[ix_]; vec_->num -= len_; memmove (slot_, slot_ + len_, (vec_->num - ix_) * sizeof (call_site_record)); } static __inline__ call_site_record *VEC_call_site_record_base_address (VEC_call_site_record_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_call_site_record_base_lower_bound (VEC_call_site_record_base *vec_, const call_site_record obj_, unsigned char (*lessthan_)(const call_site_record, const call_site_record) ) { unsigned int len_ = VEC_call_site_record_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { call_site_record middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_call_site_record_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_call_site_record_gc { VEC_call_site_record_base base; } VEC_call_site_record_gc; static __inline__ VEC_call_site_record_gc *VEC_call_site_record_gc_alloc (int alloc_ ) { return (VEC_call_site_record_gc *) vec_gc_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_call_site_record_gc_free (VEC_call_site_record_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_call_site_record_gc *VEC_call_site_record_gc_copy (VEC_call_site_record_base *vec_ ) { size_t len_ = vec_ ? vec_->num : 0; VEC_call_site_record_gc *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_call_site_record_gc *)(vec_gc_p_reserve_exact (((void *)0), len_ )); new_vec_->base.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (call_site_record) * len_); } return new_vec_; } static __inline__ int VEC_call_site_record_gc_reserve (VEC_call_site_record_gc **vec_, int alloc_ ) { int extend = !VEC_call_site_record_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_call_site_record_gc *) vec_gc_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_call_site_record_gc_reserve_exact (VEC_call_site_record_gc **vec_, int alloc_ ) { int extend = !VEC_call_site_record_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_call_site_record_gc *) vec_gc_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_call_site_record_gc_safe_grow (VEC_call_site_record_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_call_site_record_base_length ((*vec_) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_call_site_record_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((*vec_) ? &(*vec_)->base : 0)->num : 0) ); ((*vec_) ? &(*vec_)->base : 0)->num = size_; } static __inline__ void VEC_call_site_record_gc_safe_grow_cleared (VEC_call_site_record_gc **vec_, int size_ ) { int oldsize = VEC_call_site_record_base_length ((*vec_) ? &(*vec_)->base : 0); VEC_call_site_record_gc_safe_grow (vec_, size_ ); memset (&(VEC_call_site_record_base_address ((*vec_) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (call_site_record) * (size_ - oldsize)); } static __inline__ call_site_record *VEC_call_site_record_gc_safe_push (VEC_call_site_record_gc **vec_, call_site_record obj_ ) { VEC_call_site_record_gc_reserve (vec_, 1 ); return VEC_call_site_record_base_quick_push (((*vec_) ? &(*vec_)->base : 0), obj_ ); } static __inline__ call_site_record *VEC_call_site_record_gc_safe_insert (VEC_call_site_record_gc **vec_, unsigned ix_, call_site_record obj_ ) { VEC_call_site_record_gc_reserve (vec_, 1 ); return VEC_call_site_record_base_quick_insert (((*vec_) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;


struct rtl_eh {
  rtx ehr_stackadj;
  rtx ehr_handler;
  rtx ehr_label;

  rtx sjlj_fc;
  rtx sjlj_exit_after;

  VEC_uchar_gc *action_record_data;

  VEC_call_site_record_gc *call_site_record[2];
};
# 166 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/function.h"
struct gimple_df;
struct temp_slot;
typedef struct temp_slot *temp_slot_p;
struct call_site_record_d;

static __inline__ void VEC_temp_slot_p_must_be_pointer_type (void) { (void)((temp_slot_p)1 == (void *)1); } typedef struct VEC_temp_slot_p_base { unsigned num; unsigned alloc; temp_slot_p vec[1]; } VEC_temp_slot_p_base; typedef struct VEC_temp_slot_p_none { VEC_temp_slot_p_base base; } VEC_temp_slot_p_none; static __inline__ unsigned VEC_temp_slot_p_base_length (const VEC_temp_slot_p_base *vec_) { return vec_ ? vec_->num : 0; } static __inline__ temp_slot_p VEC_temp_slot_p_base_last (const VEC_temp_slot_p_base *vec_ ) { (void)(vec_ && vec_->num); return vec_->vec[vec_->num - 1]; } static __inline__ temp_slot_p VEC_temp_slot_p_base_index (const VEC_temp_slot_p_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->num); return vec_->vec[ix_]; } static __inline__ int VEC_temp_slot_p_base_iterate (const VEC_temp_slot_p_base *vec_, unsigned ix_, temp_slot_p *ptr) { if (vec_ && ix_ < vec_->num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (temp_slot_p) 0; return 0; } } static __inline__ size_t VEC_temp_slot_p_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_temp_slot_p_base, vec) + alloc_ * sizeof(temp_slot_p); } static __inline__ void VEC_temp_slot_p_base_embedded_init (VEC_temp_slot_p_base *vec_, int alloc_) { vec_->num = 0; vec_->alloc = alloc_; } static __inline__ int VEC_temp_slot_p_base_space (VEC_temp_slot_p_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->alloc - vec_->num >= (unsigned)alloc_ : !alloc_; } static __inline__ temp_slot_p *VEC_temp_slot_p_base_quick_push (VEC_temp_slot_p_base *vec_, temp_slot_p obj_ ) { temp_slot_p *slot_; (void)(vec_->num < vec_->alloc); slot_ = &vec_->vec[vec_->num++]; *slot_ = obj_; return slot_; } static __inline__ temp_slot_p VEC_temp_slot_p_base_pop (VEC_temp_slot_p_base *vec_ ) { temp_slot_p obj_; (void)(vec_->num); obj_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_temp_slot_p_base_truncate (VEC_temp_slot_p_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->num >= size_ : !size_); if (vec_) vec_->num = size_; } static __inline__ temp_slot_p VEC_temp_slot_p_base_replace (VEC_temp_slot_p_base *vec_, unsigned ix_, temp_slot_p obj_ ) { temp_slot_p old_obj_; (void)(ix_ < vec_->num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ temp_slot_p *VEC_temp_slot_p_base_quick_insert (VEC_temp_slot_p_base *vec_, unsigned ix_, temp_slot_p obj_ ) { temp_slot_p *slot_; (void)(vec_->num < vec_->alloc); (void)(ix_ <= vec_->num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->num++ - ix_) * sizeof (temp_slot_p)); *slot_ = obj_; return slot_; } static __inline__ temp_slot_p VEC_temp_slot_p_base_ordered_remove (VEC_temp_slot_p_base *vec_, unsigned ix_ ) { temp_slot_p *slot_; temp_slot_p obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->num - ix_) * sizeof (temp_slot_p)); return obj_; } static __inline__ temp_slot_p VEC_temp_slot_p_base_unordered_remove (VEC_temp_slot_p_base *vec_, unsigned ix_ ) { temp_slot_p *slot_; temp_slot_p obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_temp_slot_p_base_block_remove (VEC_temp_slot_p_base *vec_, unsigned ix_, unsigned len_ ) { temp_slot_p *slot_; (void)(ix_ + len_ <= vec_->num); slot_ = &vec_->vec[ix_]; vec_->num -= len_; memmove (slot_, slot_ + len_, (vec_->num - ix_) * sizeof (temp_slot_p)); } static __inline__ temp_slot_p *VEC_temp_slot_p_base_address (VEC_temp_slot_p_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_temp_slot_p_base_lower_bound (VEC_temp_slot_p_base *vec_, const temp_slot_p obj_, unsigned char (*lessthan_)(const temp_slot_p, const temp_slot_p) ) { unsigned int len_ = VEC_temp_slot_p_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { temp_slot_p middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_temp_slot_p_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_temp_slot_p_gc { VEC_temp_slot_p_base base; } VEC_temp_slot_p_gc; static __inline__ VEC_temp_slot_p_gc *VEC_temp_slot_p_gc_alloc (int alloc_ ) { return (VEC_temp_slot_p_gc *) vec_gc_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_temp_slot_p_gc_free (VEC_temp_slot_p_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_temp_slot_p_gc *VEC_temp_slot_p_gc_copy (VEC_temp_slot_p_base *vec_ ) { size_t len_ = vec_ ? vec_->num : 0; VEC_temp_slot_p_gc *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_temp_slot_p_gc *)(vec_gc_p_reserve_exact (((void *)0), len_ )); new_vec_->base.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (temp_slot_p) * len_); } return new_vec_; } static __inline__ int VEC_temp_slot_p_gc_reserve (VEC_temp_slot_p_gc **vec_, int alloc_ ) { int extend = !VEC_temp_slot_p_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_temp_slot_p_gc *) vec_gc_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_temp_slot_p_gc_reserve_exact (VEC_temp_slot_p_gc **vec_, int alloc_ ) { int extend = !VEC_temp_slot_p_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_temp_slot_p_gc *) vec_gc_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_temp_slot_p_gc_safe_grow (VEC_temp_slot_p_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_temp_slot_p_base_length ((*vec_) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_temp_slot_p_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((*vec_) ? &(*vec_)->base : 0)->num : 0) ); ((*vec_) ? &(*vec_)->base : 0)->num = size_; } static __inline__ void VEC_temp_slot_p_gc_safe_grow_cleared (VEC_temp_slot_p_gc **vec_, int size_ ) { int oldsize = VEC_temp_slot_p_base_length ((*vec_) ? &(*vec_)->base : 0); VEC_temp_slot_p_gc_safe_grow (vec_, size_ ); memset (&(VEC_temp_slot_p_base_address ((*vec_) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (temp_slot_p) * (size_ - oldsize)); } static __inline__ temp_slot_p *VEC_temp_slot_p_gc_safe_push (VEC_temp_slot_p_gc **vec_, temp_slot_p obj_ ) { VEC_temp_slot_p_gc_reserve (vec_, 1 ); return VEC_temp_slot_p_base_quick_push (((*vec_) ? &(*vec_)->base : 0), obj_ ); } static __inline__ temp_slot_p *VEC_temp_slot_p_gc_safe_insert (VEC_temp_slot_p_gc **vec_, unsigned ix_, temp_slot_p obj_ ) { VEC_temp_slot_p_gc_reserve (vec_, 1 ); return VEC_temp_slot_p_base_quick_insert (((*vec_) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
struct ipa_opt_pass_d;
typedef struct ipa_opt_pass_d *ipa_opt_pass;

static __inline__ void VEC_ipa_opt_pass_must_be_pointer_type (void) { (void)((ipa_opt_pass)1 == (void *)1); } typedef struct VEC_ipa_opt_pass_base { unsigned num; unsigned alloc; ipa_opt_pass vec[1]; } VEC_ipa_opt_pass_base; typedef struct VEC_ipa_opt_pass_none { VEC_ipa_opt_pass_base base; } VEC_ipa_opt_pass_none; static __inline__ unsigned VEC_ipa_opt_pass_base_length (const VEC_ipa_opt_pass_base *vec_) { return vec_ ? vec_->num : 0; } static __inline__ ipa_opt_pass VEC_ipa_opt_pass_base_last (const VEC_ipa_opt_pass_base *vec_ ) { (void)(vec_ && vec_->num); return vec_->vec[vec_->num - 1]; } static __inline__ ipa_opt_pass VEC_ipa_opt_pass_base_index (const VEC_ipa_opt_pass_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->num); return vec_->vec[ix_]; } static __inline__ int VEC_ipa_opt_pass_base_iterate (const VEC_ipa_opt_pass_base *vec_, unsigned ix_, ipa_opt_pass *ptr) { if (vec_ && ix_ < vec_->num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (ipa_opt_pass) 0; return 0; } } static __inline__ size_t VEC_ipa_opt_pass_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_ipa_opt_pass_base, vec) + alloc_ * sizeof(ipa_opt_pass); } static __inline__ void VEC_ipa_opt_pass_base_embedded_init (VEC_ipa_opt_pass_base *vec_, int alloc_) { vec_->num = 0; vec_->alloc = alloc_; } static __inline__ int VEC_ipa_opt_pass_base_space (VEC_ipa_opt_pass_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->alloc - vec_->num >= (unsigned)alloc_ : !alloc_; } static __inline__ ipa_opt_pass *VEC_ipa_opt_pass_base_quick_push (VEC_ipa_opt_pass_base *vec_, ipa_opt_pass obj_ ) { ipa_opt_pass *slot_; (void)(vec_->num < vec_->alloc); slot_ = &vec_->vec[vec_->num++]; *slot_ = obj_; return slot_; } static __inline__ ipa_opt_pass VEC_ipa_opt_pass_base_pop (VEC_ipa_opt_pass_base *vec_ ) { ipa_opt_pass obj_; (void)(vec_->num); obj_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_ipa_opt_pass_base_truncate (VEC_ipa_opt_pass_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->num >= size_ : !size_); if (vec_) vec_->num = size_; } static __inline__ ipa_opt_pass VEC_ipa_opt_pass_base_replace (VEC_ipa_opt_pass_base *vec_, unsigned ix_, ipa_opt_pass obj_ ) { ipa_opt_pass old_obj_; (void)(ix_ < vec_->num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ ipa_opt_pass *VEC_ipa_opt_pass_base_quick_insert (VEC_ipa_opt_pass_base *vec_, unsigned ix_, ipa_opt_pass obj_ ) { ipa_opt_pass *slot_; (void)(vec_->num < vec_->alloc); (void)(ix_ <= vec_->num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->num++ - ix_) * sizeof (ipa_opt_pass)); *slot_ = obj_; return slot_; } static __inline__ ipa_opt_pass VEC_ipa_opt_pass_base_ordered_remove (VEC_ipa_opt_pass_base *vec_, unsigned ix_ ) { ipa_opt_pass *slot_; ipa_opt_pass obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->num - ix_) * sizeof (ipa_opt_pass)); return obj_; } static __inline__ ipa_opt_pass VEC_ipa_opt_pass_base_unordered_remove (VEC_ipa_opt_pass_base *vec_, unsigned ix_ ) { ipa_opt_pass *slot_; ipa_opt_pass obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_ipa_opt_pass_base_block_remove (VEC_ipa_opt_pass_base *vec_, unsigned ix_, unsigned len_ ) { ipa_opt_pass *slot_; (void)(ix_ + len_ <= vec_->num); slot_ = &vec_->vec[ix_]; vec_->num -= len_; memmove (slot_, slot_ + len_, (vec_->num - ix_) * sizeof (ipa_opt_pass)); } static __inline__ ipa_opt_pass *VEC_ipa_opt_pass_base_address (VEC_ipa_opt_pass_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_ipa_opt_pass_base_lower_bound (VEC_ipa_opt_pass_base *vec_, const ipa_opt_pass obj_, unsigned char (*lessthan_)(const ipa_opt_pass, const ipa_opt_pass) ) { unsigned int len_ = VEC_ipa_opt_pass_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { ipa_opt_pass middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_ipa_opt_pass_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_ipa_opt_pass_heap { VEC_ipa_opt_pass_base base; } VEC_ipa_opt_pass_heap; static __inline__ VEC_ipa_opt_pass_heap *VEC_ipa_opt_pass_heap_alloc (int alloc_ ) { return (VEC_ipa_opt_pass_heap *) vec_heap_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_ipa_opt_pass_heap_free (VEC_ipa_opt_pass_heap **vec_) { if (*vec_) free (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_ipa_opt_pass_heap *VEC_ipa_opt_pass_heap_copy (VEC_ipa_opt_pass_base *vec_ ) { size_t len_ = vec_ ? vec_->num : 0; VEC_ipa_opt_pass_heap *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_ipa_opt_pass_heap *)(vec_heap_p_reserve_exact (((void *)0), len_ )); new_vec_->base.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (ipa_opt_pass) * len_); } return new_vec_; } static __inline__ int VEC_ipa_opt_pass_heap_reserve (VEC_ipa_opt_pass_heap **vec_, int alloc_ ) { int extend = !VEC_ipa_opt_pass_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_ipa_opt_pass_heap *) vec_heap_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_ipa_opt_pass_heap_reserve_exact (VEC_ipa_opt_pass_heap **vec_, int alloc_ ) { int extend = !VEC_ipa_opt_pass_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_ipa_opt_pass_heap *) vec_heap_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_ipa_opt_pass_heap_safe_grow (VEC_ipa_opt_pass_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_ipa_opt_pass_base_length ((*vec_) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_ipa_opt_pass_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((*vec_) ? &(*vec_)->base : 0)->num : 0) ); ((*vec_) ? &(*vec_)->base : 0)->num = size_; } static __inline__ void VEC_ipa_opt_pass_heap_safe_grow_cleared (VEC_ipa_opt_pass_heap **vec_, int size_ ) { int oldsize = VEC_ipa_opt_pass_base_length ((*vec_) ? &(*vec_)->base : 0); VEC_ipa_opt_pass_heap_safe_grow (vec_, size_ ); memset (&(VEC_ipa_opt_pass_base_address ((*vec_) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (ipa_opt_pass) * (size_ - oldsize)); } static __inline__ ipa_opt_pass *VEC_ipa_opt_pass_heap_safe_push (VEC_ipa_opt_pass_heap **vec_, ipa_opt_pass obj_ ) { VEC_ipa_opt_pass_heap_reserve (vec_, 1 ); return VEC_ipa_opt_pass_base_quick_push (((*vec_) ? &(*vec_)->base : 0), obj_ ); } static __inline__ ipa_opt_pass *VEC_ipa_opt_pass_heap_safe_insert (VEC_ipa_opt_pass_heap **vec_, unsigned ix_, ipa_opt_pass obj_ ) { VEC_ipa_opt_pass_heap_reserve (vec_, 1 ); return VEC_ipa_opt_pass_base_quick_insert (((*vec_) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;

enum function_frequency {


  FUNCTION_FREQUENCY_UNLIKELY_EXECUTED,

  FUNCTION_FREQUENCY_NORMAL,


  FUNCTION_FREQUENCY_HOT
};

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




  const char *unlikely_text_section_name;
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


  rtx x_stack_check_probe_note;





  rtx x_arg_pointer_save_area;


  rtx drap_reg;




  long x_frame_offset;


  rtx x_parm_birth_insn;


  VEC_temp_slot_p_gc *x_used_temp_slots;


  struct temp_slot *x_avail_temp_slots;


  int x_temp_slot_level;



  unsigned int stack_alignment_needed;



  unsigned int preferred_stack_boundary;


  unsigned int parm_stack_boundary;


  unsigned int max_used_stack_slot_alignment;
# 342 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/function.h"
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
};
# 453 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/function.h"
extern struct rtl_data x_rtl;
# 463 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/function.h"
struct function {
  struct eh_status *eh;


  struct control_flow_graph *cfg;


  struct gimple_seq_d *gimple_body;


  struct gimple_df *gimple_df;


  struct loops *x_current_loops;


  htab_t value_histograms;




  tree decl;



  tree static_chain_decl;




  tree nonlocal_goto_save_area;


  tree local_decls;




  struct machine_function * machine;


  struct language_function * language;


  htab_t used_types_hash;


  int last_stmt_uid;


  int funcdef_no;


  location_t function_start_locus;


  location_t function_end_locus;


  unsigned int curr_properties;
  unsigned int last_verified;




  const char * cannot_be_copied_reason;






  unsigned int va_list_gpr_size : 8;



  unsigned int va_list_fpr_size : 8;



  __extension__ enum function_frequency function_frequency : 2;


  unsigned int calls_setjmp : 1;



  unsigned int calls_alloca : 1;



  unsigned int has_nonlocal_label : 1;




  unsigned int cannot_be_copied_set : 1;


  unsigned int stdarg : 1;
# 571 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/function.h"
  unsigned int dont_save_pending_sizes_p : 1;

  unsigned int after_inlining : 1;
  unsigned int always_inline_functions_inlined : 1;






  unsigned int returns_struct : 1;



  unsigned int returns_pcc_struct : 1;


  unsigned int after_tree_profile : 1;



  unsigned int has_local_explicit_reg_vars : 1;





  unsigned int is_thunk : 1;
};







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



extern tree types_used_by_cur_var_decl;



extern void set_cfun (struct function *new_cfun);
extern void push_cfun (struct function *new_cfun);
extern void pop_cfun (void);
extern void instantiate_decl_rtl (rtx x);
# 658 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/function.h"
extern void reorder_blocks (void);


extern void number_blocks (tree);

extern void clear_block_marks (tree);
extern tree blocks_nreverse (tree);




extern long get_frame_size (void);




extern unsigned char frame_offset_overflow (long, tree);



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
# 42 "../../../src/plugin-utils.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h" 1
# 28 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/real.h" 1
# 26 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/real.h"
# 1 "/usr/include/gmp.h" 1 3 4
# 27 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/real.h" 2
# 1 "/usr/include/mpfr.h" 1 3 4
# 72 "/usr/include/mpfr.h" 3 4
typedef enum {
  GMP_RNDN=0,
  GMP_RNDZ,
  GMP_RNDU,
  GMP_RNDD,
  GMP_RND_MAX,

  GMP_RNDNA=-1
} mpfr_rnd_t;
# 96 "/usr/include/mpfr.h" 3 4
typedef unsigned long mpfr_prec_t;
# 106 "/usr/include/mpfr.h" 3 4
typedef int mpfr_sign_t;






typedef struct {
  mpfr_prec_t _mpfr_prec;
  mpfr_sign_t _mpfr_sign;
  mp_exp_t _mpfr_exp;
  mp_limb_t *_mpfr_d;
} __mpfr_struct;
# 139 "/usr/include/mpfr.h" 3 4
typedef __mpfr_struct mpfr_t[1];
typedef __mpfr_struct *mpfr_ptr;
typedef const __mpfr_struct *mpfr_srcptr;
# 152 "/usr/include/mpfr.h" 3 4
typedef enum {
  MPFR_NAN_KIND = 0,
  MPFR_INF_KIND = 1, MPFR_ZERO_KIND = 2, MPFR_REGULAR_KIND = 3
} mpfr_kind_t;
# 204 "/usr/include/mpfr.h" 3 4
 const char * mpfr_get_version (void);
 const char * mpfr_get_patches (void);

 mp_exp_t mpfr_get_emin (void);
 int mpfr_set_emin (mp_exp_t);
 mp_exp_t mpfr_get_emin_min (void);
 mp_exp_t mpfr_get_emin_max (void);
 mp_exp_t mpfr_get_emax (void);
 int mpfr_set_emax (mp_exp_t);
 mp_exp_t mpfr_get_emax_min (void);
 mp_exp_t mpfr_get_emax_max (void);

 void mpfr_set_default_rounding_mode (mpfr_rnd_t);
 mpfr_rnd_t mpfr_get_default_rounding_mode (void);
 const char *
   mpfr_print_rnd_mode (mpfr_rnd_t);

 void mpfr_clear_flags (void);
 void mpfr_clear_underflow (void);
 void mpfr_clear_overflow (void);
 void mpfr_clear_nanflag (void);
 void mpfr_clear_inexflag (void);
 void mpfr_clear_erangeflag (void);

 void mpfr_set_underflow (void);
 void mpfr_set_overflow (void);
 void mpfr_set_nanflag (void);
 void mpfr_set_inexflag (void);
 void mpfr_set_erangeflag (void);

 int mpfr_underflow_p (void);
 int mpfr_overflow_p (void);
 int mpfr_nanflag_p (void);
 int mpfr_inexflag_p (void);
 int mpfr_erangeflag_p (void);

 int
  mpfr_check_range (mpfr_ptr, int, mpfr_rnd_t);

 void mpfr_init2 (mpfr_ptr, mpfr_prec_t);
 void mpfr_init (mpfr_ptr);
 void mpfr_clear (mpfr_ptr);

 void
  mpfr_inits2 (mpfr_prec_t, mpfr_ptr, ...) __attribute__ ((sentinel));
 void
  mpfr_inits (mpfr_ptr, ...) __attribute__ ((sentinel));
 void
  mpfr_clears (mpfr_ptr, ...) __attribute__ ((sentinel));

 int
  mpfr_prec_round (mpfr_ptr, mpfr_prec_t, mpfr_rnd_t);
 int
  mpfr_can_round (mpfr_srcptr, mp_exp_t, mpfr_rnd_t, mpfr_rnd_t, mpfr_prec_t)
                                            ;

 mp_exp_t mpfr_get_exp (mpfr_srcptr);
 int mpfr_set_exp (mpfr_ptr, mp_exp_t);
 mpfr_prec_t mpfr_get_prec (mpfr_srcptr);
 void mpfr_set_prec (mpfr_ptr, mpfr_prec_t);
 void mpfr_set_prec_raw (mpfr_ptr, mpfr_prec_t);
 void mpfr_set_default_prec (mpfr_prec_t);
 mpfr_prec_t mpfr_get_default_prec (void);

 int mpfr_set_d (mpfr_ptr, double, mpfr_rnd_t);




 int
  mpfr_set_ld (mpfr_ptr, long double, mpfr_rnd_t);
 int
  mpfr_set_z (mpfr_ptr, mpz_srcptr, mpfr_rnd_t);
 void mpfr_set_nan (mpfr_ptr);
 void mpfr_set_inf (mpfr_ptr, int);
 int
  mpfr_set_f (mpfr_ptr, mpf_srcptr, mpfr_rnd_t);
 int
  mpfr_get_f (mpf_ptr, mpfr_srcptr, mpfr_rnd_t);
 int mpfr_set_si (mpfr_ptr, long, mpfr_rnd_t);
 int
  mpfr_set_ui (mpfr_ptr, unsigned long, mpfr_rnd_t);
 int
  mpfr_set_si_2exp (mpfr_ptr, long, mp_exp_t, mpfr_rnd_t);
 int
  mpfr_set_ui_2exp (mpfr_ptr,unsigned long,mp_exp_t,mpfr_rnd_t);
 int
  mpfr_set_q (mpfr_ptr, mpq_srcptr, mpfr_rnd_t);
 int
  mpfr_set_str (mpfr_ptr, const char *, int, mpfr_rnd_t);
 int
  mpfr_init_set_str (mpfr_ptr, const char *, int, mpfr_rnd_t)
                                              ;
 int
  mpfr_set4 (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t, int);
 int
  mpfr_abs (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t);
 int
  mpfr_set (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t);
 int mpfr_neg (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t);
 int mpfr_signbit (mpfr_srcptr);
 int
  mpfr_setsign (mpfr_ptr, mpfr_srcptr, int, mpfr_rnd_t);
 int
  mpfr_copysign (mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t);
# 317 "/usr/include/mpfr.h" 3 4
 int __gmpfr_set_sj (mpfr_t, intmax_t, mpfr_rnd_t);
 int
  __gmpfr_set_sj_2exp (mpfr_t, intmax_t, intmax_t, mpfr_rnd_t);
 int __gmpfr_set_uj (mpfr_t, uintmax_t, mpfr_rnd_t);
 int
  __gmpfr_set_uj_2exp (mpfr_t, uintmax_t, intmax_t, mpfr_rnd_t);
 intmax_t __gmpfr_mpfr_get_sj (mpfr_srcptr, mpfr_rnd_t);
 uintmax_t __gmpfr_mpfr_get_uj (mpfr_srcptr, mpfr_rnd_t);


 mp_exp_t mpfr_get_z_exp (mpz_ptr, mpfr_srcptr);
 double mpfr_get_d (mpfr_srcptr, mpfr_rnd_t);




 long double mpfr_get_ld (mpfr_srcptr, mpfr_rnd_t)
                                                                  ;
 double mpfr_get_d1 (mpfr_srcptr);
 double mpfr_get_d_2exp (long*, mpfr_srcptr, mpfr_rnd_t)
                                                                 ;
 long double mpfr_get_ld_2exp (long*, mpfr_srcptr, mpfr_rnd_t)
                                                                       ;
 long mpfr_get_si (mpfr_srcptr, mpfr_rnd_t);
 unsigned long mpfr_get_ui (mpfr_srcptr, mpfr_rnd_t)
                                                                    ;
 char*mpfr_get_str (char*, mp_exp_t*, int, size_t, mpfr_srcptr, mpfr_rnd_t)
                                                                         ;
 void mpfr_get_z (mpz_ptr z, mpfr_srcptr f, mpfr_rnd_t)
                                                          ;

 void mpfr_free_str (char *);


 void mpfr_random (mpfr_ptr);
 void mpfr_random2 (mpfr_ptr,mp_size_t,mp_exp_t);
 int mpfr_urandomb (mpfr_ptr, gmp_randstate_t);

 void mpfr_nextabove (mpfr_ptr);
 void mpfr_nextbelow (mpfr_ptr);
 void mpfr_nexttoward (mpfr_ptr, mpfr_srcptr);




 size_t __gmpfr_inp_str (mpfr_ptr, FILE*, int, mpfr_rnd_t)
                                                              ;
 size_t __gmpfr_out_str (FILE*, int, size_t, mpfr_srcptr, mpfr_rnd_t)
                                                                           ;

 int __gmpfr_fprintf (FILE*, const char*, ...)
                                                    ;

 int mpfr_printf (const char*, ...);
 int mpfr_asprintf (char**, const char*, ...)
                                                     ;
 int mpfr_sprintf (char*, const char*, ...)
                                                    ;
 int mpfr_snprintf (char*, size_t, const char*, ...)
                                                                        ;




 int __gmpfr_vfprintf (FILE*, const char*, va_list)
                                                         ;





 int __gmpfr_vprintf (const char*, va_list);
 int __gmpfr_vasprintf (char**, const char*, va_list)
                                                          ;
 int __gmpfr_vsprintf (char*, const char*, va_list)
                                                        ;
 int __gmpfr_vsnprintf (char*, size_t, const char*, va_list)
                                                                            ;


 int mpfr_pow (mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t)
                                                                    ;
 int mpfr_pow_si (mpfr_ptr, mpfr_srcptr, long int, mpfr_rnd_t)
                                                                    ;
 int mpfr_pow_ui (mpfr_ptr, mpfr_srcptr, unsigned long int, mpfr_rnd_t)
                                                                             ;
 int mpfr_ui_pow_ui (mpfr_ptr, unsigned long int, unsigned long int, mpfr_rnd_t)
                                                                            ;
 int mpfr_ui_pow (mpfr_ptr, unsigned long int, mpfr_srcptr, mpfr_rnd_t)
                                                                       ;
 int mpfr_pow_z (mpfr_ptr, mpfr_srcptr, mpz_srcptr, mpfr_rnd_t)
                                                                     ;

 int mpfr_sqrt (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t)
                                                        ;
 int mpfr_sqrt_ui (mpfr_ptr, unsigned long, mpfr_rnd_t)
                                                           ;
 int mpfr_rec_sqrt (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t)
                                                            ;

 int mpfr_add (mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t)
                                                                    ;
 int mpfr_sub (mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t)
                                                                    ;
 int mpfr_mul (mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t)
                                                                    ;
 int mpfr_div (mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t)
                                                                    ;

 int mpfr_add_ui (mpfr_ptr, mpfr_srcptr, unsigned long, mpfr_rnd_t)
                                                                         ;
 int mpfr_sub_ui (mpfr_ptr, mpfr_srcptr, unsigned long, mpfr_rnd_t)
                                                                         ;
 int mpfr_ui_sub (mpfr_ptr, unsigned long, mpfr_srcptr, mpfr_rnd_t)
                                                                       ;
 int mpfr_mul_ui (mpfr_ptr, mpfr_srcptr, unsigned long, mpfr_rnd_t)
                                                                         ;
 int mpfr_div_ui (mpfr_ptr, mpfr_srcptr, unsigned long, mpfr_rnd_t)
                                                                         ;
 int mpfr_ui_div (mpfr_ptr, unsigned long, mpfr_srcptr, mpfr_rnd_t)
                                                                       ;

 int mpfr_add_si (mpfr_ptr, mpfr_srcptr, long int, mpfr_rnd_t)
                                                                    ;
 int mpfr_sub_si (mpfr_ptr, mpfr_srcptr, long int, mpfr_rnd_t)
                                                                    ;
 int mpfr_si_sub (mpfr_ptr, long int, mpfr_srcptr, mpfr_rnd_t)
                                                                       ;
 int mpfr_mul_si (mpfr_ptr, mpfr_srcptr, long int, mpfr_rnd_t)
                                                                    ;
 int mpfr_div_si (mpfr_ptr, mpfr_srcptr, long int, mpfr_rnd_t)
                                                                    ;
 int mpfr_si_div (mpfr_ptr, long int, mpfr_srcptr, mpfr_rnd_t)
                                                                       ;

 int mpfr_add_d (mpfr_ptr, mpfr_srcptr, double, mpfr_rnd_t)
                                                                  ;
 int mpfr_sub_d (mpfr_ptr, mpfr_srcptr, double, mpfr_rnd_t)
                                                                  ;
 int mpfr_d_sub (mpfr_ptr, double, mpfr_srcptr, mpfr_rnd_t)
                                                                       ;
 int mpfr_mul_d (mpfr_ptr, mpfr_srcptr, double, mpfr_rnd_t)
                                                                  ;
 int mpfr_div_d (mpfr_ptr, mpfr_srcptr, double, mpfr_rnd_t)
                                                                  ;
 int mpfr_d_div (mpfr_ptr, double, mpfr_srcptr, mpfr_rnd_t)
                                                                       ;

 int mpfr_sqr (mpfr_ptr, mpfr_srcptr,mpfr_rnd_t);

 int mpfr_const_pi (mpfr_ptr, mpfr_rnd_t);
 int mpfr_const_log2 (mpfr_ptr, mpfr_rnd_t);
 int mpfr_const_euler (mpfr_ptr, mpfr_rnd_t);
 int mpfr_const_catalan (mpfr_ptr, mpfr_rnd_t);

 int mpfr_agm (mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t)
                                                       ;

 int mpfr_log (mpfr_ptr, mpfr_srcptr,mpfr_rnd_t);
 int mpfr_log2 (mpfr_ptr,mpfr_srcptr,mpfr_rnd_t);
 int mpfr_log10 (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t)
                                                         ;
 int mpfr_log1p (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t)
                                                         ;

 int mpfr_exp (mpfr_ptr, mpfr_srcptr,mpfr_rnd_t);
 int mpfr_exp2 (mpfr_ptr,mpfr_srcptr,mpfr_rnd_t);
 int mpfr_exp10 (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t)
                                                         ;
 int mpfr_expm1 (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t)
                                                         ;
 int mpfr_eint (mpfr_ptr,mpfr_srcptr,mpfr_rnd_t);
 int mpfr_li2 (mpfr_ptr,mpfr_srcptr,mpfr_rnd_t);

 int mpfr_cmp (mpfr_srcptr, mpfr_srcptr);
 int mpfr_cmp3 (mpfr_srcptr, mpfr_srcptr, int);
 int mpfr_cmp_d (mpfr_srcptr, double);
 int mpfr_cmp_ld (mpfr_srcptr, long double);
 int mpfr_cmpabs (mpfr_srcptr, mpfr_srcptr);
 int mpfr_cmp_ui (mpfr_srcptr, unsigned long);
 int mpfr_cmp_si (mpfr_srcptr, long);
 int mpfr_cmp_ui_2exp (mpfr_srcptr, unsigned long, mp_exp_t)
                                                             ;
 int mpfr_cmp_si_2exp (mpfr_srcptr, long, mp_exp_t)
                                                             ;
 void mpfr_reldiff (mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t)
                                                                         ;
 int mpfr_eq (mpfr_srcptr, mpfr_srcptr, unsigned long)
                                                        ;
 int mpfr_sgn (mpfr_srcptr);

 int mpfr_mul_2exp (mpfr_ptr, mpfr_srcptr, unsigned long, mpfr_rnd_t)
                                                                           ;
 int mpfr_div_2exp (mpfr_ptr, mpfr_srcptr, unsigned long, mpfr_rnd_t)
                                                                           ;
 int mpfr_mul_2ui (mpfr_ptr, mpfr_srcptr, unsigned long, mpfr_rnd_t)
                                                                          ;
 int mpfr_div_2ui (mpfr_ptr, mpfr_srcptr, unsigned long, mpfr_rnd_t)
                                                                          ;
 int mpfr_mul_2si (mpfr_ptr, mpfr_srcptr, long, mpfr_rnd_t)
                                                                 ;
 int mpfr_div_2si (mpfr_ptr, mpfr_srcptr, long, mpfr_rnd_t)
                                                                 ;

 int mpfr_rint (mpfr_ptr,mpfr_srcptr, mpfr_rnd_t);
 int mpfr_round (mpfr_ptr, mpfr_srcptr);
 int mpfr_trunc (mpfr_ptr, mpfr_srcptr);
 int mpfr_ceil (mpfr_ptr, mpfr_srcptr);
 int mpfr_floor (mpfr_ptr, mpfr_srcptr);
 int mpfr_rint_round (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t)
                                                              ;
 int mpfr_rint_trunc (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t)
                                                              ;
 int mpfr_rint_ceil (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t)
                                                             ;
 int mpfr_rint_floor (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t)
                                                              ;
 int mpfr_frac (mpfr_ptr,mpfr_srcptr,mpfr_rnd_t);
 int mpfr_modf (mpfr_ptr, mpfr_ptr, mpfr_srcptr, mpfr_rnd_t)
                                                              ;
 int mpfr_remquo (mpfr_ptr, long*, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t)
                                                                     ;
 int mpfr_remainder (mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t)
                                                                        ;
 int mpfr_fmod (mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t)
                                                                        ;

 int mpfr_fits_ulong_p (mpfr_srcptr, mpfr_rnd_t);
 int mpfr_fits_slong_p (mpfr_srcptr, mpfr_rnd_t);
 int mpfr_fits_uint_p (mpfr_srcptr, mpfr_rnd_t);
 int mpfr_fits_sint_p (mpfr_srcptr, mpfr_rnd_t);
 int mpfr_fits_ushort_p (mpfr_srcptr, mpfr_rnd_t);
 int mpfr_fits_sshort_p (mpfr_srcptr, mpfr_rnd_t);
 int mpfr_fits_uintmax_p (mpfr_srcptr,mpfr_rnd_t);
 int mpfr_fits_intmax_p (mpfr_srcptr, mpfr_rnd_t);

 void mpfr_extract (mpz_ptr, mpfr_srcptr, unsigned int)
                                                              ;
 void mpfr_swap (mpfr_ptr, mpfr_ptr);
 void mpfr_dump (mpfr_srcptr);

 int mpfr_nan_p (mpfr_srcptr);
 int mpfr_inf_p (mpfr_srcptr);
 int mpfr_number_p (mpfr_srcptr);
 int mpfr_integer_p (mpfr_srcptr);
 int mpfr_zero_p (mpfr_srcptr);

 int mpfr_greater_p (mpfr_srcptr, mpfr_srcptr);
 int mpfr_greaterequal_p (mpfr_srcptr, mpfr_srcptr)
                                                                   ;
 int mpfr_less_p (mpfr_srcptr, mpfr_srcptr);
 int mpfr_lessequal_p (mpfr_srcptr, mpfr_srcptr);
 int mpfr_lessgreater_p (mpfr_srcptr,mpfr_srcptr);
 int mpfr_equal_p (mpfr_srcptr, mpfr_srcptr);
 int mpfr_unordered_p (mpfr_srcptr, mpfr_srcptr);

 int mpfr_atanh (mpfr_ptr,mpfr_srcptr,mpfr_rnd_t);
 int mpfr_acosh (mpfr_ptr,mpfr_srcptr,mpfr_rnd_t);
 int mpfr_asinh (mpfr_ptr,mpfr_srcptr,mpfr_rnd_t);
 int mpfr_cosh (mpfr_ptr,mpfr_srcptr, mpfr_rnd_t);
 int mpfr_sinh (mpfr_ptr,mpfr_srcptr, mpfr_rnd_t);
 int mpfr_tanh (mpfr_ptr,mpfr_srcptr, mpfr_rnd_t);
 int mpfr_sinh_cosh (mpfr_ptr, mpfr_ptr, mpfr_srcptr, mpfr_rnd_t)
                                                                        ;

 int mpfr_sech (mpfr_ptr, mpfr_srcptr,mpfr_rnd_t);
 int mpfr_csch (mpfr_ptr, mpfr_srcptr,mpfr_rnd_t);
 int mpfr_coth (mpfr_ptr, mpfr_srcptr,mpfr_rnd_t);

 int mpfr_acos (mpfr_ptr,mpfr_srcptr,mpfr_rnd_t);
 int mpfr_asin (mpfr_ptr,mpfr_srcptr,mpfr_rnd_t);
 int mpfr_atan (mpfr_ptr,mpfr_srcptr,mpfr_rnd_t);
 int mpfr_sin (mpfr_ptr, mpfr_srcptr,mpfr_rnd_t);
 int mpfr_sin_cos (mpfr_ptr, mpfr_ptr, mpfr_srcptr, mpfr_rnd_t)
                                                                        ;
 int mpfr_cos (mpfr_ptr, mpfr_srcptr,mpfr_rnd_t);
 int mpfr_tan (mpfr_ptr, mpfr_srcptr,mpfr_rnd_t);
 int mpfr_atan2 (mpfr_ptr,mpfr_srcptr,mpfr_srcptr, mpfr_rnd_t)
                                                         ;
 int mpfr_sec (mpfr_ptr, mpfr_srcptr,mpfr_rnd_t);
 int mpfr_csc (mpfr_ptr, mpfr_srcptr,mpfr_rnd_t);
 int mpfr_cot (mpfr_ptr, mpfr_srcptr,mpfr_rnd_t);

 int mpfr_hypot (mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t)
                                                                      ;
 int mpfr_erf (mpfr_ptr, mpfr_srcptr,mpfr_rnd_t);
 int mpfr_erfc (mpfr_ptr, mpfr_srcptr,mpfr_rnd_t);
 int mpfr_cbrt (mpfr_ptr,mpfr_srcptr,mpfr_rnd_t);
 int mpfr_root (mpfr_ptr,mpfr_srcptr,unsigned long,mpfr_rnd_t);
 int mpfr_gamma (mpfr_ptr,mpfr_srcptr,mpfr_rnd_t);
 int mpfr_lngamma (mpfr_ptr,mpfr_srcptr,mpfr_rnd_t);
 int mpfr_lgamma (mpfr_ptr,int*,mpfr_srcptr,mpfr_rnd_t);
 int mpfr_zeta (mpfr_ptr,mpfr_srcptr,mpfr_rnd_t);
 int mpfr_zeta_ui (mpfr_ptr,unsigned long,mpfr_rnd_t);
 int mpfr_fac_ui (mpfr_ptr, unsigned long int, mpfr_rnd_t)
                                                          ;
 int mpfr_j0 (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t);
 int mpfr_j1 (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t);
 int mpfr_jn (mpfr_ptr, long, mpfr_srcptr, mpfr_rnd_t)
                                                      ;
 int mpfr_y0 (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t);
 int mpfr_y1 (mpfr_ptr, mpfr_srcptr, mpfr_rnd_t);
 int mpfr_yn (mpfr_ptr, long, mpfr_srcptr, mpfr_rnd_t)
                                                      ;

 int mpfr_min (mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t)
                                                       ;
 int mpfr_max (mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t)
                                                       ;
 int mpfr_dim (mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t)
                                                       ;

 int mpfr_mul_z (mpfr_ptr, mpfr_srcptr, mpz_srcptr, mpfr_rnd_t)
                                                                     ;
 int mpfr_div_z (mpfr_ptr, mpfr_srcptr, mpz_srcptr, mpfr_rnd_t)
                                                                     ;
 int mpfr_add_z (mpfr_ptr, mpfr_srcptr, mpz_srcptr, mpfr_rnd_t)
                                                                     ;
 int mpfr_sub_z (mpfr_ptr, mpfr_srcptr, mpz_srcptr, mpfr_rnd_t)
                                                                     ;
 int mpfr_cmp_z (mpfr_srcptr, mpz_srcptr);

 int mpfr_mul_q (mpfr_ptr, mpfr_srcptr, mpq_srcptr, mpfr_rnd_t)
                                                                     ;
 int mpfr_div_q (mpfr_ptr, mpfr_srcptr, mpq_srcptr, mpfr_rnd_t)
                                                                     ;
 int mpfr_add_q (mpfr_ptr, mpfr_srcptr, mpq_srcptr, mpfr_rnd_t)
                                                                     ;
 int mpfr_sub_q (mpfr_ptr, mpfr_srcptr, mpq_srcptr, mpfr_rnd_t)
                                                                     ;
 int mpfr_cmp_q (mpfr_srcptr, mpq_srcptr);

 int mpfr_cmp_f (mpfr_srcptr, mpf_srcptr);

 int mpfr_fma (mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t)
                                                                    ;
 int mpfr_fms (mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t)
                                                                    ;
 int mpfr_sum (mpfr_ptr, mpfr_ptr *const, unsigned long, mpfr_rnd_t)
                                                                      ;

 void mpfr_free_cache (void);

 int mpfr_subnormalize (mpfr_ptr, int, mpfr_rnd_t)
                                                               ;

 int mpfr_strtofr (mpfr_ptr, const char *, char **, int, mpfr_rnd_t)
                                                                          ;

 size_t mpfr_custom_get_size (mpfr_prec_t);
 void mpfr_custom_init (void *, mpfr_prec_t);
 void * mpfr_custom_get_mantissa (mpfr_srcptr);
 mp_exp_t mpfr_custom_get_exp (mpfr_srcptr);
 void mpfr_custom_move (mpfr_ptr, void *);
 void mpfr_custom_init_set (mpfr_ptr, int, mp_exp_t, mpfr_prec_t, void *)
                                                                            ;
 int mpfr_custom_get_kind (mpfr_srcptr);
# 28 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/real.h" 2
# 1 "/usr/include/mpc.h" 1 3 4
# 25 "/usr/include/mpc.h" 3 4
# 1 "/usr/include/gmp.h" 1 3 4
# 26 "/usr/include/mpc.h" 2 3 4
# 1 "/usr/include/mpfr.h" 1 3 4
# 27 "/usr/include/mpc.h" 2 3 4
# 70 "/usr/include/mpc.h" 3 4
typedef int mpc_rnd_t;
# 99 "/usr/include/mpc.h" 3 4
typedef struct {
  mpfr_t re;
  mpfr_t im;
}
__mpc_struct;

typedef __mpc_struct mpc_t[1];
typedef __mpc_struct *mpc_ptr;
typedef const __mpc_struct *mpc_srcptr;
# 131 "/usr/include/mpc.h" 3 4
 int mpc_add (mpc_ptr, mpc_srcptr, mpc_srcptr, mpc_rnd_t);
 int mpc_add_fr (mpc_ptr, mpc_srcptr, mpfr_srcptr, mpc_rnd_t);
 int mpc_add_ui (mpc_ptr, mpc_srcptr, unsigned long int, mpc_rnd_t);
 int mpc_sub (mpc_ptr, mpc_srcptr, mpc_srcptr, mpc_rnd_t);
 int mpc_sub_fr (mpc_ptr, mpc_srcptr, mpfr_srcptr, mpc_rnd_t);
 int mpc_fr_sub (mpc_ptr, mpfr_srcptr, mpc_srcptr, mpc_rnd_t);
 int mpc_sub_ui (mpc_ptr, mpc_srcptr, unsigned long int, mpc_rnd_t);
 int mpc_ui_ui_sub (mpc_ptr, unsigned long int, unsigned long int, mpc_srcptr, mpc_rnd_t);
 int mpc_mul (mpc_ptr, mpc_srcptr, mpc_srcptr, mpc_rnd_t);
 int mpc_mul_fr (mpc_ptr, mpc_srcptr, mpfr_srcptr, mpc_rnd_t);
 int mpc_mul_ui (mpc_ptr, mpc_srcptr, unsigned long int, mpc_rnd_t);
 int mpc_mul_si (mpc_ptr, mpc_srcptr, long int, mpc_rnd_t);
 int mpc_mul_i (mpc_ptr, mpc_srcptr, int, mpc_rnd_t);
 int mpc_sqr (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_div (mpc_ptr, mpc_srcptr, mpc_srcptr, mpc_rnd_t);
 int mpc_pow (mpc_ptr, mpc_srcptr, mpc_srcptr, mpc_rnd_t);
 int mpc_pow_fr (mpc_ptr, mpc_srcptr, mpfr_srcptr, mpc_rnd_t);
 int mpc_pow_ld (mpc_ptr, mpc_srcptr, long double, mpc_rnd_t);
 int mpc_pow_d (mpc_ptr, mpc_srcptr, double, mpc_rnd_t);
 int mpc_pow_si (mpc_ptr, mpc_srcptr, long, mpc_rnd_t);
 int mpc_pow_ui (mpc_ptr, mpc_srcptr, unsigned long, mpc_rnd_t);
 int mpc_pow_z (mpc_ptr, mpc_srcptr, mpz_srcptr, mpc_rnd_t);
 int mpc_div_fr (mpc_ptr, mpc_srcptr, mpfr_srcptr, mpc_rnd_t);
 int mpc_fr_div (mpc_ptr, mpfr_srcptr, mpc_srcptr, mpc_rnd_t);
 int mpc_div_ui (mpc_ptr, mpc_srcptr, unsigned long int, mpc_rnd_t);
 int mpc_ui_div (mpc_ptr, unsigned long int, mpc_srcptr, mpc_rnd_t);
 int mpc_div_2exp (mpc_ptr, mpc_srcptr, unsigned long int, mpc_rnd_t);
 int mpc_mul_2exp (mpc_ptr, mpc_srcptr, unsigned long int, mpc_rnd_t);
 int mpc_conj (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_neg (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_norm (mpfr_ptr, mpc_srcptr, mpfr_rnd_t);
 int mpc_abs (mpfr_ptr, mpc_srcptr, mpfr_rnd_t);
 int mpc_sqrt (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_set (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_set_d (mpc_ptr, double, mpc_rnd_t);
 int mpc_set_d_d (mpc_ptr, double, double, mpc_rnd_t);
 int mpc_set_ld (mpc_ptr, long double, mpc_rnd_t);
 int mpc_set_ld_ld (mpc_ptr, long double, long double, mpc_rnd_t);
 int mpc_set_f (mpc_ptr, mpf_srcptr, mpc_rnd_t);
 int mpc_set_f_f (mpc_ptr, mpf_srcptr, mpf_srcptr, mpc_rnd_t);
 int mpc_set_fr (mpc_ptr, mpfr_srcptr, mpc_rnd_t);
 int mpc_set_fr_fr (mpc_ptr, mpfr_srcptr, mpfr_srcptr, mpc_rnd_t);
 int mpc_set_q (mpc_ptr, mpq_srcptr, mpc_rnd_t);
 int mpc_set_q_q (mpc_ptr, mpq_srcptr, mpq_srcptr, mpc_rnd_t);
 int mpc_set_si (mpc_ptr, long int, mpc_rnd_t);
 int mpc_set_si_si (mpc_ptr, long int, long int, mpc_rnd_t);
 int mpc_set_ui (mpc_ptr, unsigned long int, mpc_rnd_t);
 int mpc_set_ui_ui (mpc_ptr, unsigned long int, unsigned long int, mpc_rnd_t);
 int mpc_set_z (mpc_ptr, mpz_srcptr, mpc_rnd_t);
 int mpc_set_z_z (mpc_ptr, mpz_srcptr, mpz_srcptr, mpc_rnd_t);
 void mpc_swap (mpc_ptr, mpc_ptr);


 int mpc_set_sj (mpc_ptr, intmax_t, mpc_rnd_t);
 int mpc_set_uj (mpc_ptr, uintmax_t, mpc_rnd_t);
 int mpc_set_sj_sj (mpc_ptr, intmax_t, intmax_t, mpc_rnd_t);
 int mpc_set_uj_uj (mpc_ptr, uintmax_t, uintmax_t, mpc_rnd_t);


 void mpc_set_nan (mpc_ptr);

 int mpc_real (mpfr_ptr, mpc_srcptr, mpfr_rnd_t);
 int mpc_imag (mpfr_ptr, mpc_srcptr, mpfr_rnd_t);
 int mpc_arg (mpfr_ptr, mpc_srcptr, mpfr_rnd_t);
 int mpc_proj (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_cmp (mpc_srcptr, mpc_srcptr);
 int mpc_cmp_si_si (mpc_srcptr, long int, long int);
 int mpc_exp (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_log (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_sin (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_cos (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_tan (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_sinh (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_cosh (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_tanh (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_asin (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_acos (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_atan (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_asinh (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_acosh (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 int mpc_atanh (mpc_ptr, mpc_srcptr, mpc_rnd_t);
 void mpc_clear (mpc_ptr);
 int mpc_urandom (mpc_ptr, gmp_randstate_t);
 void mpc_init2 (mpc_ptr, mpfr_prec_t);
 void mpc_init3 (mpc_ptr, mpfr_prec_t, mpfr_prec_t);
 mpfr_prec_t mpc_get_prec (mpc_srcptr x);
 void mpc_get_prec2 (mpfr_prec_t *pr, mpfr_prec_t *pi, mpc_srcptr x);
 void mpc_set_prec (mpc_ptr, mpfr_prec_t);
 const char * mpc_get_version (void);

 int mpc_strtoc (mpc_ptr, char *, char **, int, mpc_rnd_t);
 int mpc_set_str (mpc_ptr, char *, int, mpc_rnd_t);
 char * mpc_get_str (int, size_t, mpc_srcptr, mpc_rnd_t);
 void mpc_free_str (char *);

 int mpc_inp_str (mpc_ptr, FILE *, size_t *, int, mpc_rnd_t);
 size_t mpc_out_str (FILE *, int, size_t, mpc_srcptr, mpc_rnd_t);
# 29 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/real.h" 2
extern tree do_mpc_arg2 (tree, tree, tree, int, int (*)(mpc_ptr, mpc_srcptr, mpc_srcptr, mpc_rnd_t));






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
  unsigned long sig[((128 + (8 * 8)) / (8 * 8))];
};
# 83 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/real.h"
extern char test_real_width
  [sizeof(struct real_value) <= (((128 + (8 * 8)) + 32)/(8 * 8) + (((128 + (8 * 8)) + 32)%(8 * 8) ? 1 : 0))*sizeof(long) ? 1 : -1];
# 121 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/real.h"
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
# 232 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/real.h"
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


extern long real_to_integer (const struct real_value *);
extern void real_to_integer2 (long *, long *,
         const struct real_value *);



extern int real_from_string (struct real_value *, const char *);

extern void real_from_string3 (struct real_value *, const char *, enum machine_mode);


extern void real_from_integer (struct real_value *, enum machine_mode,
          unsigned long, long, int);

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
# 391 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/real.h"
extern struct real_value real_value_truncate (enum machine_mode,
         struct real_value);




extern struct real_value real_arithmetic2 (int, const struct real_value *,
      const struct real_value *);







extern int significand_size (enum machine_mode);

extern struct real_value real_from_string2 (const char *, enum machine_mode);
# 426 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/real.h"
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
# 465 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/real.h"
extern rtx const_double_from_real_value (struct real_value, enum machine_mode);


extern unsigned char exact_real_inverse (enum machine_mode, struct real_value *);




unsigned char real_can_shorten_arithmetic (enum machine_mode, enum machine_mode);


extern tree build_real (tree, struct real_value);


extern unsigned char real_sqrt (struct real_value *, enum machine_mode,
         const struct real_value *);


extern unsigned char real_powi (struct real_value *, enum machine_mode,
         const struct real_value *, long);


extern void real_trunc (struct real_value *, enum machine_mode,
   const struct real_value *);
extern void real_floor (struct real_value *, enum machine_mode,
   const struct real_value *);
extern void real_ceil (struct real_value *, enum machine_mode,
         const struct real_value *);
extern void real_round (struct real_value *, enum machine_mode,
   const struct real_value *);


extern void real_copysign (struct real_value *, const struct real_value *);





extern void real_from_mpfr (struct real_value *, mpfr_srcptr, tree, mpfr_rnd_t);
extern void mpfr_from_real (mpfr_ptr, const struct real_value *, mpfr_rnd_t);



extern unsigned char real_isinteger (const struct real_value *c, enum machine_mode mode);




extern void get_max_float (const struct real_format *, char *, size_t);
# 29 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h" 2

# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/fixed-value.h" 1
# 27 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/fixed-value.h"
struct fixed_value
{
  double_int data;
  enum machine_mode mode;
};
# 40 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/fixed-value.h"
extern struct fixed_value fconst0[18];
extern struct fixed_value fconst1[8];
# 50 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/fixed-value.h"
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
# 31 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h" 2
# 45 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
enum rtx_code {


# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def" 1
# 82 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
UNKNOWN ,






VALUE ,



DEBUG_EXPR ,






EXPR_LIST ,



INSN_LIST ,





SEQUENCE ,


ADDRESS ,
# 126 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
DEBUG_INSN ,


INSN ,



JUMP_INSN ,






CALL_INSN ,


BARRIER ,







CODE_LABEL ,






NOTE ,
# 171 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
COND_EXEC ,


PARALLEL ,







ASM_INPUT ,
# 196 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
ASM_OPERANDS ,
# 214 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
UNSPEC ,


UNSPEC_VOLATILE ,



ADDR_VEC ,
# 246 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
ADDR_DIFF_VEC ,
# 257 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
PREFETCH ,
# 269 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
SET ,
# 278 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
USE ,
# 287 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
CLOBBER ,





CALL ,



RETURN ,



EH_RETURN ,





TRAP_IF ,






CONST_INT ,


CONST_FIXED ,




CONST_DOUBLE ,


CONST_VECTOR ,




CONST_STRING ,





CONST ,



PC ,
# 350 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
REG ,






SCRATCH ,



SUBREG ,
# 374 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
STRICT_LOW_PART ,





CONCAT ,





CONCATN ,




MEM ,



LABEL_REF ,






SYMBOL_REF ,






CC0 ,
# 421 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
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
# 478 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
SMIN ,
SMAX ,
UMIN ,
UMAX ,
# 490 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
PRE_DEC ,
PRE_INC ,
POST_DEC ,
POST_INC ,
# 507 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
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
# 579 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
FRACT_CONVERT ,






UNSIGNED_FRACT_CONVERT ,







SAT_FRACT ,





UNSIGNED_SAT_FRACT ,


ABS ,


SQRT ,


BSWAP ,




FFS ,


CLZ ,


CTZ ,


POPCOUNT ,


PARITY ,
# 638 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.def"
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




VAR_LOCATION ,
# 49 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h" 2


  LAST_AND_UNUSED_RTX_CODE};
# 60 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
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
# 98 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
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
# 142 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
typedef struct mem_attrs
{
  tree expr;
  rtx offset;
  rtx size;
  alias_set_type alias;
  unsigned int align;
  unsigned char addrspace;
} mem_attrs;
# 159 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
typedef struct reg_attrs {
  tree decl;
  long offset;
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
  struct bitmap_head_def *rt_bit;
  tree rt_tree;
  struct basic_block_def *rt_bb;
  mem_attrs *rt_mem;
  reg_attrs *rt_reg;
  struct constant_descriptor_rtx *rt_constant;
};
typedef union rtunion_def rtunion;




struct block_symbol {

  rtunion fld[3];


  struct object_block *block;



  long offset;
};

static __inline__ void VEC_rtx_must_be_pointer_type (void) { (void)((rtx)1 == (void *)1); } typedef struct VEC_rtx_base { unsigned num; unsigned alloc; rtx vec[1]; } VEC_rtx_base; typedef struct VEC_rtx_none { VEC_rtx_base base; } VEC_rtx_none; static __inline__ unsigned VEC_rtx_base_length (const VEC_rtx_base *vec_) { return vec_ ? vec_->num : 0; } static __inline__ rtx VEC_rtx_base_last (const VEC_rtx_base *vec_ ) { (void)(vec_ && vec_->num); return vec_->vec[vec_->num - 1]; } static __inline__ rtx VEC_rtx_base_index (const VEC_rtx_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->num); return vec_->vec[ix_]; } static __inline__ int VEC_rtx_base_iterate (const VEC_rtx_base *vec_, unsigned ix_, rtx *ptr) { if (vec_ && ix_ < vec_->num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (rtx) 0; return 0; } } static __inline__ size_t VEC_rtx_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_rtx_base, vec) + alloc_ * sizeof(rtx); } static __inline__ void VEC_rtx_base_embedded_init (VEC_rtx_base *vec_, int alloc_) { vec_->num = 0; vec_->alloc = alloc_; } static __inline__ int VEC_rtx_base_space (VEC_rtx_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->alloc - vec_->num >= (unsigned)alloc_ : !alloc_; } static __inline__ rtx *VEC_rtx_base_quick_push (VEC_rtx_base *vec_, rtx obj_ ) { rtx *slot_; (void)(vec_->num < vec_->alloc); slot_ = &vec_->vec[vec_->num++]; *slot_ = obj_; return slot_; } static __inline__ rtx VEC_rtx_base_pop (VEC_rtx_base *vec_ ) { rtx obj_; (void)(vec_->num); obj_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_rtx_base_truncate (VEC_rtx_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->num >= size_ : !size_); if (vec_) vec_->num = size_; } static __inline__ rtx VEC_rtx_base_replace (VEC_rtx_base *vec_, unsigned ix_, rtx obj_ ) { rtx old_obj_; (void)(ix_ < vec_->num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static __inline__ rtx *VEC_rtx_base_quick_insert (VEC_rtx_base *vec_, unsigned ix_, rtx obj_ ) { rtx *slot_; (void)(vec_->num < vec_->alloc); (void)(ix_ <= vec_->num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->num++ - ix_) * sizeof (rtx)); *slot_ = obj_; return slot_; } static __inline__ rtx VEC_rtx_base_ordered_remove (VEC_rtx_base *vec_, unsigned ix_ ) { rtx *slot_; rtx obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->num - ix_) * sizeof (rtx)); return obj_; } static __inline__ rtx VEC_rtx_base_unordered_remove (VEC_rtx_base *vec_, unsigned ix_ ) { rtx *slot_; rtx obj_; (void)(ix_ < vec_->num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->num]; return obj_; } static __inline__ void VEC_rtx_base_block_remove (VEC_rtx_base *vec_, unsigned ix_, unsigned len_ ) { rtx *slot_; (void)(ix_ + len_ <= vec_->num); slot_ = &vec_->vec[ix_]; vec_->num -= len_; memmove (slot_, slot_ + len_, (vec_->num - ix_) * sizeof (rtx)); } static __inline__ rtx *VEC_rtx_base_address (VEC_rtx_base *vec_) { return vec_ ? vec_->vec : 0; } static __inline__ unsigned VEC_rtx_base_lower_bound (VEC_rtx_base *vec_, const rtx obj_, unsigned char (*lessthan_)(const rtx, const rtx) ) { unsigned int len_ = VEC_rtx_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { rtx middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_rtx_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_rtx_heap { VEC_rtx_base base; } VEC_rtx_heap; static __inline__ VEC_rtx_heap *VEC_rtx_heap_alloc (int alloc_ ) { return (VEC_rtx_heap *) vec_heap_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_rtx_heap_free (VEC_rtx_heap **vec_) { if (*vec_) free (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_rtx_heap *VEC_rtx_heap_copy (VEC_rtx_base *vec_ ) { size_t len_ = vec_ ? vec_->num : 0; VEC_rtx_heap *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_rtx_heap *)(vec_heap_p_reserve_exact (((void *)0), len_ )); new_vec_->base.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (rtx) * len_); } return new_vec_; } static __inline__ int VEC_rtx_heap_reserve (VEC_rtx_heap **vec_, int alloc_ ) { int extend = !VEC_rtx_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_rtx_heap *) vec_heap_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_rtx_heap_reserve_exact (VEC_rtx_heap **vec_, int alloc_ ) { int extend = !VEC_rtx_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_rtx_heap *) vec_heap_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_rtx_heap_safe_grow (VEC_rtx_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_rtx_base_length ((*vec_) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_rtx_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((*vec_) ? &(*vec_)->base : 0)->num : 0) ); ((*vec_) ? &(*vec_)->base : 0)->num = size_; } static __inline__ void VEC_rtx_heap_safe_grow_cleared (VEC_rtx_heap **vec_, int size_ ) { int oldsize = VEC_rtx_base_length ((*vec_) ? &(*vec_)->base : 0); VEC_rtx_heap_safe_grow (vec_, size_ ); memset (&(VEC_rtx_base_address ((*vec_) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (rtx) * (size_ - oldsize)); } static __inline__ rtx *VEC_rtx_heap_safe_push (VEC_rtx_heap **vec_, rtx obj_ ) { VEC_rtx_heap_reserve (vec_, 1 ); return VEC_rtx_base_quick_push (((*vec_) ? &(*vec_)->base : 0), obj_ ); } static __inline__ rtx *VEC_rtx_heap_safe_insert (VEC_rtx_heap **vec_, unsigned ix_, rtx obj_ ) { VEC_rtx_heap_reserve (vec_, 1 ); return VEC_rtx_base_quick_insert (((*vec_) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
typedef struct VEC_rtx_gc { VEC_rtx_base base; } VEC_rtx_gc; static __inline__ VEC_rtx_gc *VEC_rtx_gc_alloc (int alloc_ ) { return (VEC_rtx_gc *) vec_gc_p_reserve_exact (((void *)0), alloc_ ); } static __inline__ void VEC_rtx_gc_free (VEC_rtx_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = ((void *)0); } static __inline__ VEC_rtx_gc *VEC_rtx_gc_copy (VEC_rtx_base *vec_ ) { size_t len_ = vec_ ? vec_->num : 0; VEC_rtx_gc *new_vec_ = ((void *)0); if (len_) { new_vec_ = (VEC_rtx_gc *)(vec_gc_p_reserve_exact (((void *)0), len_ )); new_vec_->base.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (rtx) * len_); } return new_vec_; } static __inline__ int VEC_rtx_gc_reserve (VEC_rtx_gc **vec_, int alloc_ ) { int extend = !VEC_rtx_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_rtx_gc *) vec_gc_p_reserve (*vec_, alloc_ ); return extend; } static __inline__ int VEC_rtx_gc_reserve_exact (VEC_rtx_gc **vec_, int alloc_ ) { int extend = !VEC_rtx_base_space (((*vec_) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_rtx_gc *) vec_gc_p_reserve_exact (*vec_, alloc_ ); return extend; } static __inline__ void VEC_rtx_gc_safe_grow (VEC_rtx_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_rtx_base_length ((*vec_) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_rtx_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((*vec_) ? &(*vec_)->base : 0)->num : 0) ); ((*vec_) ? &(*vec_)->base : 0)->num = size_; } static __inline__ void VEC_rtx_gc_safe_grow_cleared (VEC_rtx_gc **vec_, int size_ ) { int oldsize = VEC_rtx_base_length ((*vec_) ? &(*vec_)->base : 0); VEC_rtx_gc_safe_grow (vec_, size_ ); memset (&(VEC_rtx_base_address ((*vec_) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (rtx) * (size_ - oldsize)); } static __inline__ rtx *VEC_rtx_gc_safe_push (VEC_rtx_gc **vec_, rtx obj_ ) { VEC_rtx_gc_reserve (vec_, 1 ); return VEC_rtx_base_quick_push (((*vec_) ? &(*vec_)->base : 0), obj_ ); } static __inline__ rtx *VEC_rtx_gc_safe_insert (VEC_rtx_gc **vec_, unsigned ix_, rtx obj_ ) { VEC_rtx_gc_reserve (vec_, 1 ); return VEC_rtx_base_quick_insert (((*vec_) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;



struct object_block {

  section *sect;


  unsigned int alignment;


  long size;
# 224 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
  VEC_rtx_gc *objects;
# 234 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
  VEC_rtx_gc *anchors;
};



struct
                                      rtx_def {

  __extension__ enum rtx_code code: 16;


  __extension__ enum machine_mode mode : 8;






  unsigned int jump : 1;




  unsigned int call : 1;







  unsigned int unchanging : 1;
# 277 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
  unsigned int volatil : 1;
# 291 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
  unsigned int in_struct : 1;






  unsigned int used : 1;






  unsigned frame_related : 1;




  unsigned return_val : 1;




  union u {
    rtunion fld[1];
    long hwint[1];
    struct block_symbol block_sym;
    struct real_value rv;
    struct fixed_value fv;
  } u;
};
# 359 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
struct rtvec_def {
  int num_elem;
  rtx elem[1];
};
# 836 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
enum reg_note
{

# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/reg-notes.def" 1
# 33 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/reg-notes.def"
REG_DEP_TRUE,




REG_DEAD,


REG_INC,
# 52 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/reg-notes.def"
REG_EQUIV,




REG_EQUAL,






REG_NONNEG,


REG_UNUSED,
# 76 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/reg-notes.def"
REG_CC_SETTER,
REG_CC_USER,




REG_LABEL_TARGET,





REG_LABEL_OPERAND,




REG_DEP_OUTPUT,
REG_DEP_ANTI,





REG_BR_PROB,




REG_VALUE_PROFILE,



REG_NOALIAS,





REG_BR_PRED,




REG_FRAME_RELATED_EXPR,
# 130 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/reg-notes.def"
REG_CFA_DEF_CFA,







REG_CFA_ADJUST_CFA,





REG_CFA_OFFSET,




REG_CFA_REGISTER,





REG_CFA_RESTORE,




REG_CFA_SET_VDRAP,




REG_EH_CONTEXT,





REG_EH_REGION,


REG_SAVE_NOTE,


REG_NORETURN,



REG_NON_LOCAL_GOTO,




REG_CROSSING_JUMP,



REG_SETJMP,
# 840 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h" 2

  REG_NOTE_MAX
};
# 851 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
extern const char * const reg_note_name[];
# 940 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
enum var_init_status
{
  VAR_INIT_STATUS_UNKNOWN,
  VAR_INIT_STATUS_UNINITIALIZED,
  VAR_INIT_STATUS_INITIALIZED
};
# 956 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
enum insn_note
{

# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/insn-notes.def" 1
# 35 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/insn-notes.def"
NOTE_INSN_DELETED,


NOTE_INSN_DELETED_LABEL,



NOTE_INSN_BLOCK_BEG,
NOTE_INSN_BLOCK_END,




NOTE_INSN_FUNCTION_BEG,


NOTE_INSN_PROLOGUE_END,


NOTE_INSN_EPILOGUE_BEG,



NOTE_INSN_EH_REGION_BEG,
NOTE_INSN_EH_REGION_END,


NOTE_INSN_VAR_LOCATION,




NOTE_INSN_BASIC_BLOCK,



NOTE_INSN_SWITCH_TEXT_SECTIONS,



NOTE_INSN_CFA_RESTORE_STATE,
# 960 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h" 2


  NOTE_INSN_MAX
};



extern const char * const note_insn_name[NOTE_INSN_MAX];
# 982 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
enum label_kind
{
  LABEL_NORMAL = 0,
  LABEL_STATIC_ENTRY,
  LABEL_GLOBAL_ENTRY,
  LABEL_WEAK_ENTRY
};
# 1050 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
static __inline__ unsigned int
rhs_regno (const_rtx x)
{
  return (((x)->u.fld[0]).rt_uint);
}
# 1124 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
extern void init_rtlanal (void);
extern int rtx_cost (rtx, enum rtx_code, unsigned char);
extern int address_cost (rtx, enum machine_mode, addr_space_t, unsigned char);
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
extern unsigned long nonzero_bits (const_rtx, enum machine_mode);
extern unsigned int num_sign_bit_copies (const_rtx, enum machine_mode);
extern unsigned char constant_pool_constant_p (rtx);
extern unsigned char truncated_to_mode (enum machine_mode, const_rtx);
extern int low_bitmask_len (enum machine_mode, unsigned long);
# 1543 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
extern int generating_concat_p;


extern int currently_expanding_to_rtl;




extern int ceil_log2 (unsigned long);


extern void set_stack_check_libfunc (rtx);
extern long trunc_int_for_mode (long, enum machine_mode);
extern rtx plus_constant (rtx, long);


extern rtx gen_blockage (void);
extern rtvec gen_rtvec (int, ...);
extern rtx copy_insn_1 (rtx);
extern rtx copy_insn (rtx);
extern rtx gen_int_mode (long, enum machine_mode);
extern rtx emit_copy_of_insn_after (rtx, rtx);
extern void set_reg_attrs_from_value (rtx, rtx);
extern void set_reg_attrs_for_parm (rtx, rtx);
extern void set_reg_attrs_for_decl_rtl (tree t, rtx x);
extern void adjust_reg_mode (rtx, enum machine_mode);
extern int mem_expr_equal_p (const_tree, const_tree);


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
extern int subreg_lowpart_p (const_rtx);
extern unsigned int subreg_lowpart_offset (enum machine_mode,
        enum machine_mode);
extern unsigned int subreg_highpart_offset (enum machine_mode,
         enum machine_mode);
extern int byte_lowpart_offset (enum machine_mode, enum machine_mode);
extern rtx make_safe_from (rtx, rtx);
extern rtx convert_memory_address_addr_space (enum machine_mode, rtx,
           addr_space_t);


extern rtx get_insns (void);
extern const char *get_insn_name (int);
extern rtx get_last_insn (void);
extern rtx get_last_insn_anywhere (void);
extern rtx get_first_nonnote_insn (void);
extern rtx get_last_nonnote_insn (void);
extern void start_sequence (void);
extern void push_to_sequence (rtx);
extern void push_to_sequence2 (rtx, rtx);
extern void end_sequence (void);
extern rtx immed_double_const (long, long,
          enum machine_mode);



extern rtx lowpart_subreg (enum machine_mode, rtx, enum machine_mode);


extern rtx force_const_mem (enum machine_mode, rtx);



struct function;
extern rtx get_pool_constant (rtx);
extern rtx get_pool_constant_mark (rtx, unsigned char *);
extern enum machine_mode get_pool_mode (const_rtx);
extern rtx simplify_subtraction (rtx);


extern rtx assign_stack_local (enum machine_mode, long, int);
extern rtx assign_stack_local_1 (enum machine_mode, long, int, unsigned char);
extern rtx assign_stack_temp (enum machine_mode, long, int);
extern rtx assign_stack_temp_for_type (enum machine_mode,
           long, int, tree);
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
extern rtx prev_label (rtx);
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


extern enum machine_mode choose_hard_reg_mode (unsigned int, unsigned int,
            unsigned char);


extern rtx set_unique_reg_note (rtx, enum reg_note, rtx);
extern void set_insn_deleted (rtx);
# 1808 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
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
extern long get_integer_term (const_rtx);
extern rtx get_related_value (const_rtx);
extern unsigned char offset_within_block_p (const_rtx, long);
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
extern enum reg_class reg_cover_class (int);
extern void setup_reg_classes (int, enum reg_class, enum reg_class,
          enum reg_class);

extern void split_all_insns (void);
extern unsigned int split_all_insns_noflow (void);


extern rtx const_int_rtx[64 * 2 + 1];





extern rtx const_true_rtx;

extern rtx const_tiny_rtx[3][(int) MAX_MACHINE_MODE];
# 1997 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
enum global_rtl_index
{
  GR_PC,
  GR_CC0,
  GR_STACK_POINTER,
  GR_FRAME_POINTER,
# 2012 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
  GR_HARD_FRAME_POINTER,





  GR_ARG_POINTER,


  GR_VIRTUAL_INCOMING_ARGS,
  GR_VIRTUAL_STACK_ARGS,
  GR_VIRTUAL_STACK_DYNAMIC,
  GR_VIRTUAL_OUTGOING_ARGS,
  GR_VIRTUAL_CFA,

  GR_MAX
};


extern rtx global_rtl[GR_MAX];
# 2045 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
extern rtx pic_offset_table_rtx;
extern rtx return_address_pointer_rtx;




# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/genrtl.h" 1







extern rtx gen_rtx_fmt_0_stat (enum rtx_code, enum machine_mode mode );



extern rtx gen_rtx_fmt_ee_stat (enum rtx_code, enum machine_mode mode,
           rtx arg0, rtx arg1 );



extern rtx gen_rtx_fmt_ue_stat (enum rtx_code, enum machine_mode mode,
           rtx arg0, rtx arg1 );



extern rtx gen_rtx_fmt_E_stat (enum rtx_code, enum machine_mode mode,
           rtvec arg0 );



extern rtx gen_rtx_fmt_e_stat (enum rtx_code, enum machine_mode mode,
           rtx arg0 );



extern rtx gen_rtx_fmt_iuuBieie_stat (enum rtx_code, enum machine_mode mode,
           int arg0, rtx arg1, rtx arg2,
           struct basic_block_def *arg3,
           int arg4, rtx arg5, int arg6,
           rtx arg7 );



extern rtx gen_rtx_fmt_iuuBieie0_stat (enum rtx_code, enum machine_mode mode,
           int arg0, rtx arg1, rtx arg2,
           struct basic_block_def *arg3,
           int arg4, rtx arg5, int arg6,
           rtx arg7 );



extern rtx gen_rtx_fmt_iuuBieiee_stat (enum rtx_code, enum machine_mode mode,
           int arg0, rtx arg1, rtx arg2,
           struct basic_block_def *arg3,
           int arg4, rtx arg5, int arg6,
           rtx arg7, rtx arg8 );



extern rtx gen_rtx_fmt_iuu00000_stat (enum rtx_code, enum machine_mode mode,
           int arg0, rtx arg1, rtx arg2 );



extern rtx gen_rtx_fmt_iuuB00is_stat (enum rtx_code, enum machine_mode mode,
           int arg0, rtx arg1, rtx arg2,
           struct basic_block_def *arg3,
           int arg4, const char *arg5 );



extern rtx gen_rtx_fmt_si_stat (enum rtx_code, enum machine_mode mode,
           const char *arg0, int arg1 );



extern rtx gen_rtx_fmt_ssiEEEi_stat (enum rtx_code, enum machine_mode mode,
           const char *arg0, const char *arg1,
           int arg2, rtvec arg3, rtvec arg4,
           rtvec arg5, int arg6 );



extern rtx gen_rtx_fmt_Ei_stat (enum rtx_code, enum machine_mode mode,
           rtvec arg0, int arg1 );



extern rtx gen_rtx_fmt_eEee0_stat (enum rtx_code, enum machine_mode mode,
           rtx arg0, rtvec arg1, rtx arg2,
           rtx arg3 );



extern rtx gen_rtx_fmt_eee_stat (enum rtx_code, enum machine_mode mode,
           rtx arg0, rtx arg1, rtx arg2 );



extern rtx gen_rtx_fmt__stat (enum rtx_code, enum machine_mode mode );



extern rtx gen_rtx_fmt_w_stat (enum rtx_code, enum machine_mode mode,
           long arg0 );



extern rtx gen_rtx_fmt_www_stat (enum rtx_code, enum machine_mode mode,
           long arg0,
           long arg1,
           long arg2 );



extern rtx gen_rtx_fmt_s_stat (enum rtx_code, enum machine_mode mode,
           const char *arg0 );



extern rtx gen_rtx_fmt_i00_stat (enum rtx_code, enum machine_mode mode,
           int arg0 );



extern rtx gen_rtx_fmt_ei_stat (enum rtx_code, enum machine_mode mode,
           rtx arg0, int arg1 );



extern rtx gen_rtx_fmt_e0_stat (enum rtx_code, enum machine_mode mode,
           rtx arg0 );



extern rtx gen_rtx_fmt_u_stat (enum rtx_code, enum machine_mode mode,
           rtx arg0 );



extern rtx gen_rtx_fmt_s00_stat (enum rtx_code, enum machine_mode mode,
           const char *arg0 );



extern rtx gen_rtx_fmt_tei_stat (enum rtx_code, enum machine_mode mode,
           union tree_node *arg0, rtx arg1,
           int arg2 );



extern rtx gen_rtx_fmt_iss_stat (enum rtx_code, enum machine_mode mode,
           int arg0, const char *arg1,
           const char *arg2 );



extern rtx gen_rtx_fmt_is_stat (enum rtx_code, enum machine_mode mode,
           int arg0, const char *arg1 );



extern rtx gen_rtx_fmt_isE_stat (enum rtx_code, enum machine_mode mode,
           int arg0, const char *arg1,
           rtvec arg2 );



extern rtx gen_rtx_fmt_i_stat (enum rtx_code, enum machine_mode mode,
           int arg0 );



extern rtx gen_rtx_fmt_iE_stat (enum rtx_code, enum machine_mode mode,
           int arg0, rtvec arg1 );



extern rtx gen_rtx_fmt_ss_stat (enum rtx_code, enum machine_mode mode,
           const char *arg0, const char *arg1 );



extern rtx gen_rtx_fmt_sEss_stat (enum rtx_code, enum machine_mode mode,
           const char *arg0, rtvec arg1,
           const char *arg2, const char *arg3 );



extern rtx gen_rtx_fmt_eE_stat (enum rtx_code, enum machine_mode mode,
           rtx arg0, rtvec arg1 );



extern rtx gen_rtx_fmt_Ess_stat (enum rtx_code, enum machine_mode mode,
           rtvec arg0, const char *arg1,
           const char *arg2 );



extern rtx gen_rtx_fmt_ses_stat (enum rtx_code, enum machine_mode mode,
           const char *arg0, rtx arg1,
           const char *arg2 );



extern rtx gen_rtx_fmt_sss_stat (enum rtx_code, enum machine_mode mode,
           const char *arg0, const char *arg1,
           const char *arg2 );



extern rtx gen_rtx_fmt_sse_stat (enum rtx_code, enum machine_mode mode,
           const char *arg0, const char *arg1,
           rtx arg2 );



extern rtx gen_rtx_fmt_sies_stat (enum rtx_code, enum machine_mode mode,
           const char *arg0, int arg1,
           rtx arg2, const char *arg3 );



extern rtx gen_rtx_fmt_sE_stat (enum rtx_code, enum machine_mode mode,
           const char *arg0, rtvec arg1 );



extern rtx gen_rtx_fmt_ii_stat (enum rtx_code, enum machine_mode mode,
           int arg0, int arg1 );



extern rtx gen_rtx_fmt_Ee_stat (enum rtx_code, enum machine_mode mode,
           rtvec arg0, rtx arg1 );
# 2052 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h" 2
# 2063 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
extern rtx gen_rtx_CONST_INT (enum machine_mode, long);
extern rtx gen_rtx_CONST_VECTOR (enum machine_mode, rtvec);
extern rtx gen_raw_REG (enum machine_mode, int);
extern rtx gen_rtx_REG (enum machine_mode, unsigned);
extern rtx gen_rtx_SUBREG (enum machine_mode, rtx, int);
extern rtx gen_rtx_MEM (enum machine_mode, rtx);
# 2136 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
extern rtx output_constant_def (tree, int);
extern rtx lookup_constant_def (tree);




extern int reload_completed;


extern int epilogue_completed;




extern int reload_in_progress;
# 2160 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
extern int regstack_completed;
# 2169 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/rtl.h"
extern int cse_not_expected;





extern int rtx_to_tree_code (enum rtx_code);


extern int delete_trivially_dead_insns (rtx, int);
extern int cse_main (rtx, int);
extern int exp_equiv_p (const_rtx, const_rtx, int, unsigned char);
extern unsigned hash_rtx (const_rtx x, enum machine_mode, int *, int *, unsigned char);


extern int comparison_dominates_p (enum rtx_code, enum rtx_code);
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
extern int get_max_uid (void);
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
extern void set_first_insn (rtx);
extern void set_last_insn (rtx);
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


extern void fix_sched_param (const char *, const char *);


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
extern void maybe_copy_epilogue_insn (rtx, rtx);


extern void expand_null_return (void);
extern void expand_naked_return (void);
extern void emit_jump (rtx);


extern rtx move_by_pieces (rtx, rtx, unsigned long,
      unsigned int, int);


extern void print_rtl_with_bb (FILE *, const_rtx);


extern void dump_reg_info (FILE *);
extern void dump_flow_info (FILE *, int);


extern void init_expmed (void);
extern void expand_inc (rtx, rtx);
extern void expand_dec (rtx, rtx);


extern unsigned char can_copy_p (enum machine_mode);
extern unsigned char can_assign_to_reg_without_clobbers_p (rtx);
extern rtx fis_get_condition (rtx);





extern void mark_elimination (int, int);


extern int reg_classes_intersect_p (enum reg_class, enum reg_class);
extern int reg_class_subset_p (enum reg_class, enum reg_class);
extern void globalize_reg (int);
extern void init_reg_modes_target (void);
extern void init_regs (void);
extern void reinit_regs (void);
extern void init_fake_stack_mems (void);
extern void save_register_info (void);
extern void init_reg_sets (void);
extern void regclass (rtx, int);
extern void reg_scan (rtx, unsigned int);
extern void fix_register (const char *, int, int);
extern unsigned char invalid_mode_change_p (unsigned int, enum reg_class,
       enum machine_mode);


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
extern enum tls_model decl_default_tls_model (const_tree);


extern void traverse_md_constants (int (*) (void **, void *), void *);
struct md_constant { char *name, *value; };


extern int read_skip_spaces (FILE *);
extern unsigned char read_rtx (FILE *, rtx *, int *);
extern void copy_rtx_ptr_loc (const void *, const void *);
extern void print_rtx_ptr_loc (const void *);
extern const char *join_c_conditions (const char *, const char *);
extern void print_c_condition (const char *);
extern const char *read_rtx_filename;
extern int read_rtx_lineno;


extern rtx canon_rtx (rtx);
extern int true_dependence (const_rtx, enum machine_mode, const_rtx, unsigned char (*)(const_rtx, unsigned char));
extern rtx get_addr (rtx);
extern int canon_true_dependence (const_rtx, enum machine_mode, rtx, const_rtx,
      rtx, unsigned char (*)(const_rtx, unsigned char));
extern int read_dependence (const_rtx, const_rtx);
extern int anti_dependence (const_rtx, const_rtx);
extern int output_dependence (const_rtx, const_rtx);
extern void init_alias_target (void);
extern void init_alias_analysis (void);
extern void end_alias_analysis (void);
extern unsigned char memory_modified_in_insn_p (const_rtx, const_rtx);
extern rtx find_base_term (rtx);
extern rtx gen_hard_reg_clobber (enum machine_mode, unsigned int);
extern rtx get_reg_known_value (unsigned int);
extern unsigned char get_reg_known_equiv_p (unsigned int);


extern int stack_regs_mentioned (const_rtx insn);



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
      unsigned long, unsigned long *);
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
# 43 "../../../src/plugin-utils.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/emit-rtl.h" 1
# 24 "/work1/ferranti/build-gcc/gcc-4.5.2/install/lib/gcc/x86_64-unknown-linux-gnu/4.5.2/plugin/include/emit-rtl.h"
extern void set_mem_alias_set (rtx, alias_set_type);


extern void set_mem_align (rtx, unsigned int);


extern void set_mem_addr_space (rtx, addr_space_t);


extern void set_mem_expr (rtx, tree);


extern void set_mem_offset (rtx, rtx);


extern void set_mem_size (rtx, rtx);


extern void set_mem_attrs_for_spill (rtx);
extern tree get_spill_slot_decl (unsigned char);





extern rtx replace_equiv_address (rtx, rtx);


extern rtx replace_equiv_address_nv (rtx, rtx);
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
