# 1 "../../../src/plugin-utils.c"
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







# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 1 3 4
# 213 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 3 4
typedef unsigned int size_t;
# 34 "/usr/include/stdlib.h" 2 3 4

extern "C" {






# 1 "/usr/include/bits/waitflags.h" 1 3 4
# 43 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/bits/waitstatus.h" 1 3 4
# 65 "/usr/include/bits/waitstatus.h" 3 4
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
# 66 "/usr/include/bits/waitstatus.h" 2 3 4

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
# 44 "/usr/include/stdlib.h" 2 3 4
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
extern size_t __ctype_get_mb_cur_max (void) throw () ;




extern double atof (__const char *__nptr)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern int atoi (__const char *__nptr)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern long int atol (__const char *__nptr)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





__extension__ extern long long int atoll (__const char *__nptr)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





extern double strtod (__const char *__restrict __nptr,
        char **__restrict __endptr)
     throw () __attribute__ ((__nonnull__ (1))) ;





extern float strtof (__const char *__restrict __nptr,
       char **__restrict __endptr) throw () __attribute__ ((__nonnull__ (1))) ;

extern long double strtold (__const char *__restrict __nptr,
       char **__restrict __endptr)
     throw () __attribute__ ((__nonnull__ (1))) ;





extern long int strtol (__const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     throw () __attribute__ ((__nonnull__ (1))) ;

extern unsigned long int strtoul (__const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     throw () __attribute__ ((__nonnull__ (1))) ;




__extension__
extern long long int strtoq (__const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     throw () __attribute__ ((__nonnull__ (1))) ;

__extension__
extern unsigned long long int strtouq (__const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     throw () __attribute__ ((__nonnull__ (1))) ;





__extension__
extern long long int strtoll (__const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     throw () __attribute__ ((__nonnull__ (1))) ;

__extension__
extern unsigned long long int strtoull (__const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     throw () __attribute__ ((__nonnull__ (1))) ;

# 236 "/usr/include/stdlib.h" 3 4
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
# 237 "/usr/include/stdlib.h" 2 3 4



extern long int strtol_l (__const char *__restrict __nptr,
     char **__restrict __endptr, int __base,
     __locale_t __loc) throw () __attribute__ ((__nonnull__ (1, 4))) ;

extern unsigned long int strtoul_l (__const char *__restrict __nptr,
        char **__restrict __endptr,
        int __base, __locale_t __loc)
     throw () __attribute__ ((__nonnull__ (1, 4))) ;

__extension__
extern long long int strtoll_l (__const char *__restrict __nptr,
    char **__restrict __endptr, int __base,
    __locale_t __loc)
     throw () __attribute__ ((__nonnull__ (1, 4))) ;

__extension__
extern unsigned long long int strtoull_l (__const char *__restrict __nptr,
       char **__restrict __endptr,
       int __base, __locale_t __loc)
     throw () __attribute__ ((__nonnull__ (1, 4))) ;

extern double strtod_l (__const char *__restrict __nptr,
   char **__restrict __endptr, __locale_t __loc)
     throw () __attribute__ ((__nonnull__ (1, 3))) ;

extern float strtof_l (__const char *__restrict __nptr,
         char **__restrict __endptr, __locale_t __loc)
     throw () __attribute__ ((__nonnull__ (1, 3))) ;

extern long double strtold_l (__const char *__restrict __nptr,
         char **__restrict __endptr,
         __locale_t __loc)
     throw () __attribute__ ((__nonnull__ (1, 3))) ;





extern __inline __attribute__ ((__gnu_inline__)) double
atof (__const char *__nptr) throw ()
{
  return strtod (__nptr, (char **) __null);
}
extern __inline __attribute__ ((__gnu_inline__)) int
atoi (__const char *__nptr) throw ()
{
  return (int) strtol (__nptr, (char **) __null, 10);
}
extern __inline __attribute__ ((__gnu_inline__)) long int
atol (__const char *__nptr) throw ()
{
  return strtol (__nptr, (char **) __null, 10);
}




__extension__ extern __inline __attribute__ ((__gnu_inline__)) long long int
atoll (__const char *__nptr) throw ()
{
  return strtoll (__nptr, (char **) __null, 10);
}

# 311 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n) throw () ;


extern long int a64l (__const char *__s)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;




# 1 "/usr/include/sys/types.h" 1 3 4
# 29 "/usr/include/sys/types.h" 3 4
extern "C" {

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






typedef __ino64_t ino64_t;




typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;






typedef __off64_t off64_t;




typedef __pid_t pid_t;




typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 133 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 58 "/usr/include/time.h" 3 4


typedef __clock_t clock_t;



# 74 "/usr/include/time.h" 3 4


typedef __time_t time_t;



# 92 "/usr/include/time.h" 3 4
typedef __clockid_t clockid_t;
# 104 "/usr/include/time.h" 3 4
typedef __timer_t timer_t;
# 134 "/usr/include/sys/types.h" 2 3 4



typedef __useconds_t useconds_t;



typedef __suseconds_t suseconds_t;





# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 1 3 4
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
# 220 "/usr/include/sys/types.h" 3 4
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
# 55 "/usr/include/sys/select.h" 3 4
typedef long int __fd_mask;
# 67 "/usr/include/sys/select.h" 3 4
typedef struct
  {



    __fd_mask fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];





  } fd_set;






typedef __fd_mask fd_mask;
# 99 "/usr/include/sys/select.h" 3 4
extern "C" {
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


}
# 221 "/usr/include/sys/types.h" 2 3 4


# 1 "/usr/include/sys/sysmacros.h" 1 3 4
# 30 "/usr/include/sys/sysmacros.h" 3 4
__extension__
extern unsigned int gnu_dev_major (unsigned long long int __dev)
     throw ();
__extension__
extern unsigned int gnu_dev_minor (unsigned long long int __dev)
     throw ();
__extension__
extern unsigned long long int gnu_dev_makedev (unsigned int __major,
            unsigned int __minor)
     throw ();


__extension__ extern __inline __attribute__ ((__gnu_inline__)) unsigned int
gnu_dev_major (unsigned long long int __dev) throw ()
{
  return ((__dev >> 8) & 0xfff) | ((unsigned int) (__dev >> 32) & ~0xfff);
}

__extension__ extern __inline __attribute__ ((__gnu_inline__)) unsigned int
gnu_dev_minor (unsigned long long int __dev) throw ()
{
  return (__dev & 0xff) | ((unsigned int) (__dev >> 12) & ~0xff);
}

__extension__ extern __inline __attribute__ ((__gnu_inline__)) unsigned long long int
gnu_dev_makedev (unsigned int __major, unsigned int __minor) throw ()
{
  return ((__minor & 0xff) | ((__major & 0xfff) << 8)
   | (((unsigned long long int) (__minor & ~0xff)) << 12)
   | (((unsigned long long int) (__major & ~0xfff)) << 32));
}
# 224 "/usr/include/sys/types.h" 2 3 4




typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 262 "/usr/include/sys/types.h" 3 4
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;





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


}
# 321 "/usr/include/stdlib.h" 2 3 4






extern long int random (void) throw ();


extern void srandom (unsigned int __seed) throw ();





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) throw () __attribute__ ((__nonnull__ (2)));



extern char *setstate (char *__statebuf) throw () __attribute__ ((__nonnull__ (1)));







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
       int32_t *__restrict __result) throw () __attribute__ ((__nonnull__ (1, 2)));

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     throw () __attribute__ ((__nonnull__ (2)));

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     throw () __attribute__ ((__nonnull__ (2, 4)));

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     throw () __attribute__ ((__nonnull__ (1, 2)));






extern int rand (void) throw ();

extern void srand (unsigned int __seed) throw ();




extern int rand_r (unsigned int *__seed) throw ();







extern double drand48 (void) throw ();
extern double erand48 (unsigned short int __xsubi[3]) throw () __attribute__ ((__nonnull__ (1)));


extern long int lrand48 (void) throw ();
extern long int nrand48 (unsigned short int __xsubi[3])
     throw () __attribute__ ((__nonnull__ (1)));


extern long int mrand48 (void) throw ();
extern long int jrand48 (unsigned short int __xsubi[3])
     throw () __attribute__ ((__nonnull__ (1)));


extern void srand48 (long int __seedval) throw ();
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     throw () __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) throw () __attribute__ ((__nonnull__ (1)));





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) throw () __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) throw () __attribute__ ((__nonnull__ (1, 2)));


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     throw () __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     throw () __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     throw () __attribute__ ((__nonnull__ (2)));

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) throw () __attribute__ ((__nonnull__ (1, 2)));

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     throw () __attribute__ ((__nonnull__ (1, 2)));









extern void *malloc (size_t __size) throw () __attribute__ ((__malloc__)) ;

extern void *calloc (size_t __nmemb, size_t __size)
     throw () __attribute__ ((__malloc__)) ;










extern void *realloc (void *__ptr, size_t __size)
     throw () __attribute__ ((__warn_unused_result__));

extern void free (void *__ptr) throw ();




extern void cfree (void *__ptr) throw ();



# 1 "/usr/include/alloca.h" 1 3 4
# 25 "/usr/include/alloca.h" 3 4
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 1 3 4
# 26 "/usr/include/alloca.h" 2 3 4

extern "C" {





extern void *alloca (size_t __size) throw ();





}
# 498 "/usr/include/stdlib.h" 2 3 4




extern void *valloc (size_t __size) throw () __attribute__ ((__malloc__)) ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     throw () __attribute__ ((__nonnull__ (1))) ;




extern void abort (void) throw () __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) throw () __attribute__ ((__nonnull__ (1)));






extern "C++" int at_quick_exit (void (*__func) (void))
     throw () __asm ("at_quick_exit") __attribute__ ((__nonnull__ (1)));









extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     throw () __attribute__ ((__nonnull__ (1)));






extern void exit (int __status) throw () __attribute__ ((__noreturn__));







extern void quick_exit (int __status) throw () __attribute__ ((__noreturn__));







extern void _Exit (int __status) throw () __attribute__ ((__noreturn__));






extern char *getenv (__const char *__name) throw () __attribute__ ((__nonnull__ (1))) ;




extern char *__secure_getenv (__const char *__name)
     throw () __attribute__ ((__nonnull__ (1))) ;





extern int putenv (char *__string) throw () __attribute__ ((__nonnull__ (1)));





extern int setenv (__const char *__name, __const char *__value, int __replace)
     throw () __attribute__ ((__nonnull__ (2)));


extern int unsetenv (__const char *__name) throw ();






extern int clearenv (void) throw ();
# 604 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) throw () __attribute__ ((__nonnull__ (1))) ;
# 615 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 625 "/usr/include/stdlib.h" 3 4
extern int mkstemp64 (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 637 "/usr/include/stdlib.h" 3 4
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
# 647 "/usr/include/stdlib.h" 3 4
extern int mkstemps64 (char *__template, int __suffixlen)
     __attribute__ ((__nonnull__ (1))) ;
# 658 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) throw () __attribute__ ((__nonnull__ (1))) ;
# 669 "/usr/include/stdlib.h" 3 4
extern int mkostemp (char *__template, int __flags) __attribute__ ((__nonnull__ (1))) ;
# 679 "/usr/include/stdlib.h" 3 4
extern int mkostemp64 (char *__template, int __flags) __attribute__ ((__nonnull__ (1))) ;
# 689 "/usr/include/stdlib.h" 3 4
extern int mkostemps (char *__template, int __suffixlen, int __flags)
     __attribute__ ((__nonnull__ (1))) ;
# 701 "/usr/include/stdlib.h" 3 4
extern int mkostemps64 (char *__template, int __suffixlen, int __flags)
     __attribute__ ((__nonnull__ (1))) ;









extern int system (__const char *__command) ;






extern char *canonicalize_file_name (__const char *__name)
     throw () __attribute__ ((__nonnull__ (1))) ;
# 729 "/usr/include/stdlib.h" 3 4
extern char *realpath (__const char *__restrict __name,
         char *__restrict __resolved) throw () ;






typedef int (*__compar_fn_t) (__const void *, __const void *);


typedef __compar_fn_t comparison_fn_t;



typedef int (*__compar_d_fn_t) (__const void *, __const void *, void *);





extern void *bsearch (__const void *__key, __const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;



extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));

extern void qsort_r (void *__base, size_t __nmemb, size_t __size,
       __compar_d_fn_t __compar, void *__arg)
  __attribute__ ((__nonnull__ (1, 4)));




extern int abs (int __x) throw () __attribute__ ((__const__)) ;
extern long int labs (long int __x) throw () __attribute__ ((__const__)) ;



__extension__ extern long long int llabs (long long int __x)
     throw () __attribute__ ((__const__)) ;







extern div_t div (int __numer, int __denom)
     throw () __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     throw () __attribute__ ((__const__)) ;




__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     throw () __attribute__ ((__const__)) ;

# 802 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) throw () __attribute__ ((__nonnull__ (3, 4))) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) throw () __attribute__ ((__nonnull__ (3, 4))) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     throw () __attribute__ ((__nonnull__ (3))) ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     throw () __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     throw () __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     throw () __attribute__ ((__nonnull__ (3))) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) throw () __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) throw () __attribute__ ((__nonnull__ (3, 4, 5)));

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     throw () __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     throw () __attribute__ ((__nonnull__ (3, 4, 5)));







extern int mblen (__const char *__s, size_t __n) throw () ;


extern int mbtowc (wchar_t *__restrict __pwc,
     __const char *__restrict __s, size_t __n) throw () ;


extern int wctomb (char *__s, wchar_t __wchar) throw () ;



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   __const char *__restrict __s, size_t __n) throw ();

extern size_t wcstombs (char *__restrict __s,
   __const wchar_t *__restrict __pwcs, size_t __n)
     throw ();








extern int rpmatch (__const char *__response) throw () __attribute__ ((__nonnull__ (1))) ;
# 890 "/usr/include/stdlib.h" 3 4
extern int getsubopt (char **__restrict __optionp,
        char *__const *__restrict __tokens,
        char **__restrict __valuep)
     throw () __attribute__ ((__nonnull__ (1, 2, 3))) ;





extern void setkey (__const char *__key) throw () __attribute__ ((__nonnull__ (1)));







extern int posix_openpt (int __oflag) ;







extern int grantpt (int __fd) throw ();



extern int unlockpt (int __fd) throw ();




extern char *ptsname (int __fd) throw () ;






extern int ptsname_r (int __fd, char *__buf, size_t __buflen)
     throw () __attribute__ ((__nonnull__ (2)));


extern int getpt (void);






extern int getloadavg (double __loadavg[], int __nelem)
     throw () __attribute__ ((__nonnull__ (1)));
# 958 "/usr/include/stdlib.h" 3 4
}
# 21 "../../../src/plugin-utils.c" 2
# 1 "../../../src/plugin-utils.h" 1
# 23 "../../../src/plugin-utils.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/gcc-plugin.h" 1
# 27 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/gcc-plugin.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config.h" 1





# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/auto-host.h" 1
# 7 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config.h" 2

# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/ansidecl.h" 1
# 119 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/ansidecl.h"
extern "C" {
# 431 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/ansidecl.h"
}
# 9 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config.h" 2
# 28 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/gcc-plugin.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 1
# 28 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stdarg.h" 1 3 4
# 40 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 102 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;
# 29 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2
# 39 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 1 3 4
# 150 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 40 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2


# 1 "/usr/include/stdio.h" 1 3 4
# 30 "/usr/include/stdio.h" 3 4
extern "C" {



# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 1 3 4
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
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 1 3 4
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




extern "C" {


extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
# 460 "/usr/include/libio.h" 3 4
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) throw ();
extern int _IO_ferror (_IO_FILE *__fp) throw ();

extern int _IO_peekc_locked (_IO_FILE *__fp);





extern void _IO_flockfile (_IO_FILE *) throw ();
extern void _IO_funlockfile (_IO_FILE *) throw ();
extern int _IO_ftrylockfile (_IO_FILE *) throw ();
# 490 "/usr/include/libio.h" 3 4
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);

extern void _IO_free_backup_area (_IO_FILE *) throw ();
# 552 "/usr/include/libio.h" 3 4
}
# 76 "/usr/include/stdio.h" 2 3 4
# 89 "/usr/include/stdio.h" 3 4


typedef _G_fpos_t fpos_t;





typedef _G_fpos64_t fpos64_t;
# 141 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 142 "/usr/include/stdio.h" 2 3 4



extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;







extern int remove (__const char *__filename) throw ();

extern int rename (__const char *__old, __const char *__new) throw ();




extern int renameat (int __oldfd, __const char *__old, int __newfd,
       __const char *__new) throw ();








extern FILE *tmpfile (void) ;
# 182 "/usr/include/stdio.h" 3 4
extern FILE *tmpfile64 (void) ;



extern char *tmpnam (char *__s) throw () ;





extern char *tmpnam_r (char *__s) throw () ;
# 204 "/usr/include/stdio.h" 3 4
extern char *tempnam (__const char *__dir, __const char *__pfx)
     throw () __attribute__ ((__malloc__)) ;








extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);

# 229 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 239 "/usr/include/stdio.h" 3 4
extern int fcloseall (void);









extern FILE *fopen (__const char *__restrict __filename,
      __const char *__restrict __modes) ;




extern FILE *freopen (__const char *__restrict __filename,
        __const char *__restrict __modes,
        FILE *__restrict __stream) ;
# 272 "/usr/include/stdio.h" 3 4


extern FILE *fopen64 (__const char *__restrict __filename,
        __const char *__restrict __modes) ;
extern FILE *freopen64 (__const char *__restrict __filename,
   __const char *__restrict __modes,
   FILE *__restrict __stream) ;




extern FILE *fdopen (int __fd, __const char *__modes) throw () ;





extern FILE *fopencookie (void *__restrict __magic_cookie,
     __const char *__restrict __modes,
     _IO_cookie_io_functions_t __io_funcs) throw () ;




extern FILE *fmemopen (void *__s, size_t __len, __const char *__modes)
  throw () ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) throw () ;






extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) throw ();



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) throw ();





extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) throw ();


extern void setlinebuf (FILE *__stream) throw ();








extern int fprintf (FILE *__restrict __stream,
      __const char *__restrict __format, ...);




extern int printf (__const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      __const char *__restrict __format, ...) throw ();





extern int vfprintf (FILE *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg);




extern int vprintf (__const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg) throw ();





extern int snprintf (char *__restrict __s, size_t __maxlen,
       __const char *__restrict __format, ...)
     throw () __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        __const char *__restrict __format, __gnuc_va_list __arg)
     throw () __attribute__ ((__format__ (__printf__, 3, 0)));






extern int vasprintf (char **__restrict __ptr, __const char *__restrict __f,
        __gnuc_va_list __arg)
     throw () __attribute__ ((__format__ (__printf__, 2, 0))) ;
extern int __asprintf (char **__restrict __ptr,
         __const char *__restrict __fmt, ...)
     throw () __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int asprintf (char **__restrict __ptr,
       __const char *__restrict __fmt, ...)
     throw () __attribute__ ((__format__ (__printf__, 2, 3))) ;
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
     __const char *__restrict __format, ...) throw ();
# 445 "/usr/include/stdio.h" 3 4








extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;





extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (__const char *__restrict __s,
      __const char *__restrict __format, __gnuc_va_list __arg)
     throw () __attribute__ ((__format__ (__scanf__, 2, 0)));
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

# 622 "/usr/include/stdio.h" 3 4
extern char *fgets_unlocked (char *__restrict __s, int __n,
        FILE *__restrict __stream) ;
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

# 699 "/usr/include/stdio.h" 3 4
extern int fputs_unlocked (__const char *__restrict __s,
      FILE *__restrict __stream);
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



extern int fseeko64 (FILE *__stream, __off64_t __off, int __whence);
extern __off64_t ftello64 (FILE *__stream) ;
extern int fgetpos64 (FILE *__restrict __stream, fpos64_t *__restrict __pos);
extern int fsetpos64 (FILE *__stream, __const fpos64_t *__pos);




extern void clearerr (FILE *__stream) throw ();

extern int feof (FILE *__stream) throw () ;

extern int ferror (FILE *__stream) throw () ;




extern void clearerr_unlocked (FILE *__stream) throw ();
extern int feof_unlocked (FILE *__stream) throw () ;
extern int ferror_unlocked (FILE *__stream) throw () ;








extern void perror (__const char *__s);






# 1 "/usr/include/bits/sys_errlist.h" 1 3 4
# 27 "/usr/include/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern __const char *__const sys_errlist[];


extern int _sys_nerr;
extern __const char *__const _sys_errlist[];
# 827 "/usr/include/stdio.h" 2 3 4




extern int fileno (FILE *__stream) throw () ;




extern int fileno_unlocked (FILE *__stream) throw () ;
# 846 "/usr/include/stdio.h" 3 4
extern FILE *popen (__const char *__command, __const char *__modes) ;





extern int pclose (FILE *__stream);





extern char *ctermid (char *__s) throw ();





extern char *cuserid (char *__s);




struct obstack;


extern int obstack_printf (struct obstack *__restrict __obstack,
      __const char *__restrict __format, ...)
     throw () __attribute__ ((__format__ (__printf__, 2, 3)));
extern int obstack_vprintf (struct obstack *__restrict __obstack,
       __const char *__restrict __format,
       __gnuc_va_list __args)
     throw () __attribute__ ((__format__ (__printf__, 2, 0)));







extern void flockfile (FILE *__stream) throw ();



extern int ftrylockfile (FILE *__stream) throw () ;


extern void funlockfile (FILE *__stream) throw ();
# 907 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/stdio.h" 1 3 4
# 36 "/usr/include/bits/stdio.h" 3 4
extern __inline __attribute__ ((__gnu_inline__)) int
vprintf (__const char *__restrict __fmt, __gnuc_va_list __arg)
{
  return vfprintf (stdout, __fmt, __arg);
}



extern __inline __attribute__ ((__gnu_inline__)) int
getchar (void)
{
  return _IO_getc (stdin);
}




extern __inline __attribute__ ((__gnu_inline__)) int
fgetc_unlocked (FILE *__fp)
{
  return (__builtin_expect (((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end), 0) ? __uflow (__fp) : *(unsigned char *) (__fp)->_IO_read_ptr++);
}





extern __inline __attribute__ ((__gnu_inline__)) int
getc_unlocked (FILE *__fp)
{
  return (__builtin_expect (((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end), 0) ? __uflow (__fp) : *(unsigned char *) (__fp)->_IO_read_ptr++);
}


extern __inline __attribute__ ((__gnu_inline__)) int
getchar_unlocked (void)
{
  return (__builtin_expect (((stdin)->_IO_read_ptr >= (stdin)->_IO_read_end), 0) ? __uflow (stdin) : *(unsigned char *) (stdin)->_IO_read_ptr++);
}




extern __inline __attribute__ ((__gnu_inline__)) int
putchar (int __c)
{
  return _IO_putc (__c, stdout);
}




extern __inline __attribute__ ((__gnu_inline__)) int
fputc_unlocked (int __c, FILE *__stream)
{
  return (__builtin_expect (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end), 0) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}





extern __inline __attribute__ ((__gnu_inline__)) int
putc_unlocked (int __c, FILE *__stream)
{
  return (__builtin_expect (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end), 0) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}


extern __inline __attribute__ ((__gnu_inline__)) int
putchar_unlocked (int __c)
{
  return (__builtin_expect (((stdout)->_IO_write_ptr >= (stdout)->_IO_write_end), 0) ? __overflow (stdout, (unsigned char) (__c)) : (unsigned char) (*(stdout)->_IO_write_ptr++ = (__c)));
}





extern __inline __attribute__ ((__gnu_inline__)) __ssize_t
getline (char **__lineptr, size_t *__n, FILE *__stream)
{
  return __getdelim (__lineptr, __n, '\n', __stream);
}





extern __inline __attribute__ ((__gnu_inline__)) int
feof_unlocked (FILE *__stream) throw ()
{
  return (((__stream)->_flags & 0x10) != 0);
}


extern __inline __attribute__ ((__gnu_inline__)) int
ferror_unlocked (FILE *__stream) throw ()
{
  return (((__stream)->_flags & 0x20) != 0);
}
# 908 "/usr/include/stdio.h" 2 3 4
# 916 "/usr/include/stdio.h" 3 4
}
# 43 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2
# 99 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
extern "C" {
# 183 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
}
# 196 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/safe-ctype.h" 1
# 57 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/safe-ctype.h"
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
# 110 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/safe-ctype.h"
extern const unsigned char _sch_toupper[256];
extern const unsigned char _sch_tolower[256];
# 122 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/safe-ctype.h"
# 1 "/usr/include/ctype.h" 1 3 4
# 30 "/usr/include/ctype.h" 3 4
extern "C" {
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
     throw () __attribute__ ((__const));
extern __const __int32_t **__ctype_tolower_loc (void)
     throw () __attribute__ ((__const));
extern __const __int32_t **__ctype_toupper_loc (void)
     throw () __attribute__ ((__const));
# 96 "/usr/include/ctype.h" 3 4






extern int isalnum (int) throw ();
extern int isalpha (int) throw ();
extern int iscntrl (int) throw ();
extern int isdigit (int) throw ();
extern int islower (int) throw ();
extern int isgraph (int) throw ();
extern int isprint (int) throw ();
extern int ispunct (int) throw ();
extern int isspace (int) throw ();
extern int isupper (int) throw ();
extern int isxdigit (int) throw ();



extern int tolower (int __c) throw ();


extern int toupper (int __c) throw ();








extern int isblank (int) throw ();






extern int isctype (int __c, int __mask) throw ();






extern int isascii (int __c) throw ();



extern int toascii (int __c) throw ();



extern int _toupper (int) throw ();
extern int _tolower (int) throw ();
# 247 "/usr/include/ctype.h" 3 4
extern int isalnum_l (int, __locale_t) throw ();
extern int isalpha_l (int, __locale_t) throw ();
extern int iscntrl_l (int, __locale_t) throw ();
extern int isdigit_l (int, __locale_t) throw ();
extern int islower_l (int, __locale_t) throw ();
extern int isgraph_l (int, __locale_t) throw ();
extern int isprint_l (int, __locale_t) throw ();
extern int ispunct_l (int, __locale_t) throw ();
extern int isspace_l (int, __locale_t) throw ();
extern int isupper_l (int, __locale_t) throw ();
extern int isxdigit_l (int, __locale_t) throw ();

extern int isblank_l (int, __locale_t) throw ();



extern int __tolower_l (int __c, __locale_t __l) throw ();
extern int tolower_l (int __c, __locale_t __l) throw ();


extern int __toupper_l (int __c, __locale_t __l) throw ();
extern int toupper_l (int __c, __locale_t __l) throw ();
# 323 "/usr/include/ctype.h" 3 4
}
# 123 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/safe-ctype.h" 2
# 197 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2



# 1 "/usr/include/errno.h" 1 3 4
# 32 "/usr/include/errno.h" 3 4
extern "C" {



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
extern int *__errno_location (void) throw () __attribute__ ((__const__));
# 37 "/usr/include/errno.h" 2 3 4
# 55 "/usr/include/errno.h" 3 4
extern char *program_invocation_name, *program_invocation_short_name;



}
# 69 "/usr/include/errno.h" 3 4
typedef int error_t;
# 201 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2






# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cstring" 1 3
# 41 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cstring" 3
       
# 42 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cstring" 3

# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/x86_64-unknown-linux-gnu/32/bits/c++config.h" 1 3
# 171 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/x86_64-unknown-linux-gnu/32/bits/c++config.h" 3
namespace std
{
  typedef unsigned int size_t;
  typedef int ptrdiff_t;




}
# 414 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/x86_64-unknown-linux-gnu/32/bits/c++config.h" 3
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/x86_64-unknown-linux-gnu/32/bits/os_defines.h" 1 3
# 415 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/x86_64-unknown-linux-gnu/32/bits/c++config.h" 2 3


# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/x86_64-unknown-linux-gnu/32/bits/cpu_defines.h" 1 3
# 418 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/x86_64-unknown-linux-gnu/32/bits/c++config.h" 2 3
# 44 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cstring" 2 3
# 1 "/usr/include/string.h" 1 3 4
# 28 "/usr/include/string.h" 3 4
extern "C" {




# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 1 3 4
# 34 "/usr/include/string.h" 2 3 4









extern void *memcpy (void *__restrict __dest,
       __const void *__restrict __src, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, __const void *__src, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));






extern void *memccpy (void *__restrict __dest, __const void *__restrict __src,
        int __c, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));





extern void *memset (void *__s, int __c, size_t __n) throw () __attribute__ ((__nonnull__ (1)));


extern int memcmp (__const void *__s1, __const void *__s2, size_t __n)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));



extern "C++"
{
extern void *memchr (void *__s, int __c, size_t __n)
      throw () __asm ("memchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern __const void *memchr (__const void *__s, int __c, size_t __n)
      throw () __asm ("memchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__, __artificial__)) void *
memchr (void *__s, int __c, size_t __n) throw ()
{
  return __builtin_memchr (__s, __c, __n);
}

extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__, __artificial__)) __const void *
memchr (__const void *__s, int __c, size_t __n) throw ()
{
  return __builtin_memchr (__s, __c, __n);
}

}










extern "C++" void *rawmemchr (void *__s, int __c)
     throw () __asm ("rawmemchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern "C++" __const void *rawmemchr (__const void *__s, int __c)
     throw () __asm ("rawmemchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));







extern "C++" void *memrchr (void *__s, int __c, size_t __n)
      throw () __asm ("memrchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern "C++" __const void *memrchr (__const void *__s, int __c, size_t __n)
      throw () __asm ("memrchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));









extern char *strcpy (char *__restrict __dest, __const char *__restrict __src)
     throw () __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        __const char *__restrict __src, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, __const char *__restrict __src)
     throw () __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, __const char *__restrict __src,
        size_t __n) throw () __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (__const char *__s1, __const char *__s2)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (__const char *__s1, __const char *__s2, size_t __n)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (__const char *__s1, __const char *__s2)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         __const char *__restrict __src, size_t __n)
     throw () __attribute__ ((__nonnull__ (2)));

# 164 "/usr/include/string.h" 3 4
extern int strcoll_l (__const char *__s1, __const char *__s2, __locale_t __l)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));

extern size_t strxfrm_l (char *__dest, __const char *__src, size_t __n,
    __locale_t __l) throw () __attribute__ ((__nonnull__ (2, 4)));




extern char *strdup (__const char *__s)
     throw () __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (__const char *__string, size_t __n)
     throw () __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 208 "/usr/include/string.h" 3 4



extern "C++"
{
extern char *strchr (char *__s, int __c)
     throw () __asm ("strchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern __const char *strchr (__const char *__s, int __c)
     throw () __asm ("strchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__, __artificial__)) char *
strchr (char *__s, int __c) throw ()
{
  return __builtin_strchr (__s, __c);
}

extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__, __artificial__)) __const char *
strchr (__const char *__s, int __c) throw ()
{
  return __builtin_strchr (__s, __c);
}

}






extern "C++"
{
extern char *strrchr (char *__s, int __c)
     throw () __asm ("strrchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern __const char *strrchr (__const char *__s, int __c)
     throw () __asm ("strrchr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__, __artificial__)) char *
strrchr (char *__s, int __c) throw ()
{
  return __builtin_strrchr (__s, __c);
}

extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__, __artificial__)) __const char *
strrchr (__const char *__s, int __c) throw ()
{
  return __builtin_strrchr (__s, __c);
}

}










extern "C++" char *strchrnul (char *__s, int __c)
     throw () __asm ("strchrnul") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern "C++" __const char *strchrnul (__const char *__s, int __c)
     throw () __asm ("strchrnul") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));









extern size_t strcspn (__const char *__s, __const char *__reject)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (__const char *__s, __const char *__accept)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern "C++"
{
extern char *strpbrk (char *__s, __const char *__accept)
     throw () __asm ("strpbrk") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern __const char *strpbrk (__const char *__s, __const char *__accept)
     throw () __asm ("strpbrk") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__, __artificial__)) char *
strpbrk (char *__s, __const char *__accept) throw ()
{
  return __builtin_strpbrk (__s, __accept);
}

extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__, __artificial__)) __const char *
strpbrk (__const char *__s, __const char *__accept) throw ()
{
  return __builtin_strpbrk (__s, __accept);
}

}






extern "C++"
{
extern char *strstr (char *__haystack, __const char *__needle)
     throw () __asm ("strstr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern __const char *strstr (__const char *__haystack,
        __const char *__needle)
     throw () __asm ("strstr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__, __artificial__)) char *
strstr (char *__haystack, __const char *__needle) throw ()
{
  return __builtin_strstr (__haystack, __needle);
}

extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__, __artificial__)) __const char *
strstr (__const char *__haystack, __const char *__needle) throw ()
{
  return __builtin_strstr (__haystack, __needle);
}

}







extern char *strtok (char *__restrict __s, __const char *__restrict __delim)
     throw () __attribute__ ((__nonnull__ (2)));




extern char *__strtok_r (char *__restrict __s,
    __const char *__restrict __delim,
    char **__restrict __save_ptr)
     throw () __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, __const char *__restrict __delim,
         char **__restrict __save_ptr)
     throw () __attribute__ ((__nonnull__ (2, 3)));





extern "C++" char *strcasestr (char *__haystack, __const char *__needle)
     throw () __asm ("strcasestr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern "C++" __const char *strcasestr (__const char *__haystack,
           __const char *__needle)
     throw () __asm ("strcasestr") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 380 "/usr/include/string.h" 3 4
extern void *memmem (__const void *__haystack, size_t __haystacklen,
       __const void *__needle, size_t __needlelen)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 3)));



extern void *__mempcpy (void *__restrict __dest,
   __const void *__restrict __src, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));
extern void *mempcpy (void *__restrict __dest,
        __const void *__restrict __src, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));





extern size_t strlen (__const char *__s)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern size_t strnlen (__const char *__string, size_t __maxlen)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern char *strerror (int __errnum) throw ();

# 436 "/usr/include/string.h" 3 4
extern char *strerror_r (int __errnum, char *__buf, size_t __buflen)
     throw () __attribute__ ((__nonnull__ (2)));





extern char *strerror_l (int __errnum, __locale_t __l) throw ();





extern void __bzero (void *__s, size_t __n) throw () __attribute__ ((__nonnull__ (1)));



extern void bcopy (__const void *__src, void *__dest, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) throw () __attribute__ ((__nonnull__ (1)));


extern int bcmp (__const void *__s1, __const void *__s2, size_t __n)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));



extern "C++"
{
extern char *index (char *__s, int __c)
     throw () __asm ("index") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern __const char *index (__const char *__s, int __c)
     throw () __asm ("index") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__, __artificial__)) char *
index (char *__s, int __c) throw ()
{
  return __builtin_index (__s, __c);
}

extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__, __artificial__)) __const char *
index (__const char *__s, int __c) throw ()
{
  return __builtin_index (__s, __c);
}

}







extern "C++"
{
extern char *rindex (char *__s, int __c)
     throw () __asm ("rindex") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern __const char *rindex (__const char *__s, int __c)
     throw () __asm ("rindex") __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__, __artificial__)) char *
rindex (char *__s, int __c) throw ()
{
  return __builtin_rindex (__s, __c);
}

extern __inline __attribute__ ((__always_inline__)) __attribute__ ((__gnu_inline__, __artificial__)) __const char *
rindex (__const char *__s, int __c) throw ()
{
  return __builtin_rindex (__s, __c);
}

}







extern int ffs (int __i) throw () __attribute__ ((__const__));




extern int ffsl (long int __l) throw () __attribute__ ((__const__));

__extension__ extern int ffsll (long long int __ll)
     throw () __attribute__ ((__const__));




extern int strcasecmp (__const char *__s1, __const char *__s2)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (__const char *__s1, __const char *__s2, size_t __n)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));





extern int strcasecmp_l (__const char *__s1, __const char *__s2,
    __locale_t __loc)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));

extern int strncasecmp_l (__const char *__s1, __const char *__s2,
     size_t __n, __locale_t __loc)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));





extern char *strsep (char **__restrict __stringp,
       __const char *__restrict __delim)
     throw () __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) throw ();


extern char *__stpcpy (char *__restrict __dest, __const char *__restrict __src)
     throw () __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, __const char *__restrict __src)
     throw () __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   __const char *__restrict __src, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        __const char *__restrict __src, size_t __n)
     throw () __attribute__ ((__nonnull__ (1, 2)));




extern int strverscmp (__const char *__s1, __const char *__s2)
     throw () __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern char *strfry (char *__string) throw () __attribute__ ((__nonnull__ (1)));


extern void *memfrob (void *__s, size_t __n) throw () __attribute__ ((__nonnull__ (1)));







extern "C++" char *basename (char *__filename)
     throw () __asm ("basename") __attribute__ ((__nonnull__ (1)));
extern "C++" __const char *basename (__const char *__filename)
     throw () __asm ("basename") __attribute__ ((__nonnull__ (1)));
# 644 "/usr/include/string.h" 3 4
}
# 45 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cstring" 2 3
# 73 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cstring" 3
namespace std __attribute__ ((__visibility__ ("default")))
{


  using ::memchr;
  using ::memcmp;
  using ::memcpy;
  using ::memmove;
  using ::memset;
  using ::strcat;
  using ::strcmp;
  using ::strcoll;
  using ::strcpy;
  using ::strcspn;
  using ::strerror;
  using ::strlen;
  using ::strncat;
  using ::strncmp;
  using ::strncpy;
  using ::strspn;
  using ::strtok;
  using ::strxfrm;
  using ::strchr;
  using ::strpbrk;
  using ::strrchr;
  using ::strstr;
# 122 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cstring" 3

}
# 208 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2
# 216 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
# 1 "/usr/include/strings.h" 1 3 4
# 217 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2
# 253 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
# 1 "/usr/include/unistd.h" 1 3 4
# 28 "/usr/include/unistd.h" 3 4
extern "C" {
# 203 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/bits/posix_opt.h" 1 3 4
# 204 "/usr/include/unistd.h" 2 3 4



# 1 "/usr/include/bits/environments.h" 1 3 4
# 23 "/usr/include/bits/environments.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 24 "/usr/include/bits/environments.h" 2 3 4
# 208 "/usr/include/unistd.h" 2 3 4
# 227 "/usr/include/unistd.h" 3 4
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 1 3 4
# 228 "/usr/include/unistd.h" 2 3 4
# 268 "/usr/include/unistd.h" 3 4
typedef __intptr_t intptr_t;






typedef __socklen_t socklen_t;
# 288 "/usr/include/unistd.h" 3 4
extern int access (__const char *__name, int __type) throw () __attribute__ ((__nonnull__ (1)));




extern int euidaccess (__const char *__name, int __type)
     throw () __attribute__ ((__nonnull__ (1)));


extern int eaccess (__const char *__name, int __type)
     throw () __attribute__ ((__nonnull__ (1)));






extern int faccessat (int __fd, __const char *__file, int __type, int __flag)
     throw () __attribute__ ((__nonnull__ (2))) ;
# 331 "/usr/include/unistd.h" 3 4
extern __off_t lseek (int __fd, __off_t __offset, int __whence) throw ();
# 342 "/usr/include/unistd.h" 3 4
extern __off64_t lseek64 (int __fd, __off64_t __offset, int __whence)
     throw ();






extern int close (int __fd);






extern ssize_t read (int __fd, void *__buf, size_t __nbytes) ;





extern ssize_t write (int __fd, __const void *__buf, size_t __n) ;
# 373 "/usr/include/unistd.h" 3 4
extern ssize_t pread (int __fd, void *__buf, size_t __nbytes,
        __off_t __offset) ;






extern ssize_t pwrite (int __fd, __const void *__buf, size_t __n,
         __off_t __offset) ;
# 401 "/usr/include/unistd.h" 3 4
extern ssize_t pread64 (int __fd, void *__buf, size_t __nbytes,
   __off64_t __offset) ;


extern ssize_t pwrite64 (int __fd, __const void *__buf, size_t __n,
    __off64_t __offset) ;







extern int pipe (int __pipedes[2]) throw () ;




extern int pipe2 (int __pipedes[2], int __flags) throw () ;
# 429 "/usr/include/unistd.h" 3 4
extern unsigned int alarm (unsigned int __seconds) throw ();
# 441 "/usr/include/unistd.h" 3 4
extern unsigned int sleep (unsigned int __seconds);






extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     throw ();






extern int usleep (__useconds_t __useconds);
# 465 "/usr/include/unistd.h" 3 4
extern int pause (void);



extern int chown (__const char *__file, __uid_t __owner, __gid_t __group)
     throw () __attribute__ ((__nonnull__ (1))) ;



extern int fchown (int __fd, __uid_t __owner, __gid_t __group) throw () ;




extern int lchown (__const char *__file, __uid_t __owner, __gid_t __group)
     throw () __attribute__ ((__nonnull__ (1))) ;






extern int fchownat (int __fd, __const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     throw () __attribute__ ((__nonnull__ (2))) ;



extern int chdir (__const char *__path) throw () __attribute__ ((__nonnull__ (1))) ;



extern int fchdir (int __fd) throw () ;
# 507 "/usr/include/unistd.h" 3 4
extern char *getcwd (char *__buf, size_t __size) throw () ;





extern char *get_current_dir_name (void) throw ();






extern char *getwd (char *__buf)
     throw () __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__)) ;




extern int dup (int __fd) throw () ;


extern int dup2 (int __fd, int __fd2) throw ();




extern int dup3 (int __fd, int __fd2, int __flags) throw ();



extern char **__environ;

extern char **environ;





extern int execve (__const char *__path, char *__const __argv[],
     char *__const __envp[]) throw () __attribute__ ((__nonnull__ (1)));




extern int fexecve (int __fd, char *__const __argv[], char *__const __envp[])
     throw ();




extern int execv (__const char *__path, char *__const __argv[])
     throw () __attribute__ ((__nonnull__ (1)));



extern int execle (__const char *__path, __const char *__arg, ...)
     throw () __attribute__ ((__nonnull__ (1)));



extern int execl (__const char *__path, __const char *__arg, ...)
     throw () __attribute__ ((__nonnull__ (1)));



extern int execvp (__const char *__file, char *__const __argv[])
     throw () __attribute__ ((__nonnull__ (1)));




extern int execlp (__const char *__file, __const char *__arg, ...)
     throw () __attribute__ ((__nonnull__ (1)));




extern int execvpe (__const char *__file, char *__const __argv[],
      char *__const __envp[])
     throw () __attribute__ ((__nonnull__ (1)));





extern int nice (int __inc) throw () ;




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
     throw () __attribute__ ((__nonnull__ (1)));


extern long int fpathconf (int __fd, int __name) throw ();


extern long int sysconf (int __name) throw ();



extern size_t confstr (int __name, char *__buf, size_t __len) throw ();




extern __pid_t getpid (void) throw ();


extern __pid_t getppid (void) throw ();




extern __pid_t getpgrp (void) throw ();
# 641 "/usr/include/unistd.h" 3 4
extern __pid_t __getpgid (__pid_t __pid) throw ();

extern __pid_t getpgid (__pid_t __pid) throw ();






extern int setpgid (__pid_t __pid, __pid_t __pgid) throw ();
# 667 "/usr/include/unistd.h" 3 4
extern int setpgrp (void) throw ();
# 684 "/usr/include/unistd.h" 3 4
extern __pid_t setsid (void) throw ();



extern __pid_t getsid (__pid_t __pid) throw ();



extern __uid_t getuid (void) throw ();


extern __uid_t geteuid (void) throw ();


extern __gid_t getgid (void) throw ();


extern __gid_t getegid (void) throw ();




extern int getgroups (int __size, __gid_t __list[]) throw () ;



extern int group_member (__gid_t __gid) throw ();






extern int setuid (__uid_t __uid) throw ();




extern int setreuid (__uid_t __ruid, __uid_t __euid) throw ();




extern int seteuid (__uid_t __uid) throw ();






extern int setgid (__gid_t __gid) throw ();




extern int setregid (__gid_t __rgid, __gid_t __egid) throw ();




extern int setegid (__gid_t __gid) throw ();





extern int getresuid (__uid_t *__ruid, __uid_t *__euid, __uid_t *__suid)
     throw ();



extern int getresgid (__gid_t *__rgid, __gid_t *__egid, __gid_t *__sgid)
     throw ();



extern int setresuid (__uid_t __ruid, __uid_t __euid, __uid_t __suid)
     throw ();



extern int setresgid (__gid_t __rgid, __gid_t __egid, __gid_t __sgid)
     throw ();






extern __pid_t fork (void) throw ();






extern __pid_t vfork (void) throw ();





extern char *ttyname (int __fd) throw ();



extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
     throw () __attribute__ ((__nonnull__ (2))) ;



extern int isatty (int __fd) throw ();





extern int ttyslot (void) throw ();




extern int link (__const char *__from, __const char *__to)
     throw () __attribute__ ((__nonnull__ (1, 2))) ;




extern int linkat (int __fromfd, __const char *__from, int __tofd,
     __const char *__to, int __flags)
     throw () __attribute__ ((__nonnull__ (2, 4))) ;




extern int symlink (__const char *__from, __const char *__to)
     throw () __attribute__ ((__nonnull__ (1, 2))) ;




extern ssize_t readlink (__const char *__restrict __path,
    char *__restrict __buf, size_t __len)
     throw () __attribute__ ((__nonnull__ (1, 2))) ;




extern int symlinkat (__const char *__from, int __tofd,
        __const char *__to) throw () __attribute__ ((__nonnull__ (1, 3))) ;


extern ssize_t readlinkat (int __fd, __const char *__restrict __path,
      char *__restrict __buf, size_t __len)
     throw () __attribute__ ((__nonnull__ (2, 3))) ;



extern int unlink (__const char *__name) throw () __attribute__ ((__nonnull__ (1)));



extern int unlinkat (int __fd, __const char *__name, int __flag)
     throw () __attribute__ ((__nonnull__ (2)));



extern int rmdir (__const char *__path) throw () __attribute__ ((__nonnull__ (1)));



extern __pid_t tcgetpgrp (int __fd) throw ();


extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) throw ();






extern char *getlogin (void);







extern int getlogin_r (char *__name, size_t __name_len) __attribute__ ((__nonnull__ (1)));




extern int setlogin (__const char *__name) throw () __attribute__ ((__nonnull__ (1)));
# 887 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/getopt.h" 1 3 4
# 50 "/usr/include/getopt.h" 3 4
extern "C" {
# 59 "/usr/include/getopt.h" 3 4
extern char *optarg;
# 73 "/usr/include/getopt.h" 3 4
extern int optind;




extern int opterr;



extern int optopt;
# 152 "/usr/include/getopt.h" 3 4
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       throw ();
# 187 "/usr/include/getopt.h" 3 4
}
# 888 "/usr/include/unistd.h" 2 3 4







extern int gethostname (char *__name, size_t __len) throw () __attribute__ ((__nonnull__ (1)));






extern int sethostname (__const char *__name, size_t __len)
     throw () __attribute__ ((__nonnull__ (1))) ;



extern int sethostid (long int __id) throw () ;





extern int getdomainname (char *__name, size_t __len)
     throw () __attribute__ ((__nonnull__ (1))) ;
extern int setdomainname (__const char *__name, size_t __len)
     throw () __attribute__ ((__nonnull__ (1))) ;





extern int vhangup (void) throw ();


extern int revoke (__const char *__file) throw () __attribute__ ((__nonnull__ (1))) ;







extern int profil (unsigned short int *__sample_buffer, size_t __size,
     size_t __offset, unsigned int __scale)
     throw () __attribute__ ((__nonnull__ (1)));





extern int acct (__const char *__name) throw ();



extern char *getusershell (void) throw ();
extern void endusershell (void) throw ();
extern void setusershell (void) throw ();





extern int daemon (int __nochdir, int __noclose) throw () ;






extern int chroot (__const char *__path) throw () __attribute__ ((__nonnull__ (1))) ;



extern char *getpass (__const char *__prompt) __attribute__ ((__nonnull__ (1)));
# 973 "/usr/include/unistd.h" 3 4
extern int fsync (int __fd);






extern long int gethostid (void);


extern void sync (void) throw ();




extern int getpagesize (void) throw () __attribute__ ((__const__));




extern int getdtablesize (void) throw ();




extern int truncate (__const char *__file, __off_t __length)
     throw () __attribute__ ((__nonnull__ (1))) ;
# 1010 "/usr/include/unistd.h" 3 4
extern int truncate64 (__const char *__file, __off64_t __length)
     throw () __attribute__ ((__nonnull__ (1))) ;
# 1020 "/usr/include/unistd.h" 3 4
extern int ftruncate (int __fd, __off_t __length) throw () ;
# 1030 "/usr/include/unistd.h" 3 4
extern int ftruncate64 (int __fd, __off64_t __length) throw () ;
# 1040 "/usr/include/unistd.h" 3 4
extern int brk (void *__addr) throw () ;





extern void *sbrk (intptr_t __delta) throw ();
# 1061 "/usr/include/unistd.h" 3 4
extern long int syscall (long int __sysno, ...) throw ();
# 1084 "/usr/include/unistd.h" 3 4
extern int lockf (int __fd, int __cmd, __off_t __len) ;
# 1094 "/usr/include/unistd.h" 3 4
extern int lockf64 (int __fd, int __cmd, __off64_t __len) ;
# 1115 "/usr/include/unistd.h" 3 4
extern int fdatasync (int __fildes);







extern char *crypt (__const char *__key, __const char *__salt)
     throw () __attribute__ ((__nonnull__ (1, 2)));



extern void encrypt (char *__block, int __edflag) throw () __attribute__ ((__nonnull__ (1)));






extern void swab (__const void *__restrict __from, void *__restrict __to,
    ssize_t __n) throw () __attribute__ ((__nonnull__ (1, 2)));







extern char *ctermid (char *__s) throw ();
# 1153 "/usr/include/unistd.h" 3 4
}
# 254 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2



# 1 "/usr/include/sys/param.h" 1 3 4
# 26 "/usr/include/sys/param.h" 3 4
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include-fixed/limits.h" 1 3 4
# 34 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include-fixed/limits.h" 3 4
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include-fixed/syslimits.h" 1 3 4






# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include-fixed/limits.h" 1 3 4
# 169 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include-fixed/limits.h" 3 4
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



# 1 "/usr/include/bits/xopen_lim.h" 1 3 4
# 34 "/usr/include/bits/xopen_lim.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 35 "/usr/include/bits/xopen_lim.h" 2 3 4
# 154 "/usr/include/limits.h" 2 3 4
# 170 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include-fixed/limits.h" 2 3 4
# 8 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include-fixed/syslimits.h" 2 3 4
# 35 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include-fixed/limits.h" 2 3 4
# 27 "/usr/include/sys/param.h" 2 3 4

# 1 "/usr/include/linux/param.h" 1 3 4



# 1 "/usr/include/asm/param.h" 1 3 4
# 1 "/usr/include/asm-generic/param.h" 1 3 4
# 1 "/usr/include/asm/param.h" 2 3 4
# 5 "/usr/include/linux/param.h" 2 3 4
# 29 "/usr/include/sys/param.h" 2 3 4
# 258 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2





# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include-fixed/limits.h" 1 3 4
# 264 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2



# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/hwint.h" 1
# 180 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/hwint.h"
static inline int
clz_hwi (unsigned long x)
{
  if (x == 0)
    return (8 * 8);

  return __builtin_clzl (x);





}

static inline int
ctz_hwi (unsigned long x)
{
  if (x == 0)
    return (8 * 8);

  return __builtin_ctzl (x);





}

static inline int
ffs_hwi (unsigned long x)
{

  return __builtin_ffsl (x);





}

static inline int
floor_log2 (unsigned long x)
{
  return (8 * 8) - 1 - clz_hwi (x);
}

static inline int
exact_log2 (unsigned long x)
{
  return x == (x & -x) && x ? ctz_hwi (x) : -1;
}







extern long abs_hwi (long);
extern unsigned long absu_hwi (long);
extern long gcd (long, long);
extern long pos_mul_hwi (long, long);
extern long mul_hwi (long, long);
extern long least_common_multiple (long, long);
# 268 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2
# 297 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
# 1 "/usr/include/sys/time.h" 1 3 4
# 27 "/usr/include/sys/time.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 28 "/usr/include/sys/time.h" 2 3 4

# 1 "/usr/include/bits/time.h" 1 3 4
# 30 "/usr/include/sys/time.h" 2 3 4
# 39 "/usr/include/sys/time.h" 3 4
extern "C" {
# 57 "/usr/include/sys/time.h" 3 4
struct timezone
  {
    int tz_minuteswest;
    int tz_dsttime;
  };

typedef struct timezone *__restrict __timezone_ptr_t;
# 73 "/usr/include/sys/time.h" 3 4
extern int gettimeofday (struct timeval *__restrict __tv,
    __timezone_ptr_t __tz) throw () __attribute__ ((__nonnull__ (1)));




extern int settimeofday (__const struct timeval *__tv,
    __const struct timezone *__tz)
     throw () __attribute__ ((__nonnull__ (1)));





extern int adjtime (__const struct timeval *__delta,
      struct timeval *__olddelta) throw ();




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
        struct itimerval *__value) throw ();




extern int setitimer (__itimer_which_t __which,
        __const struct itimerval *__restrict __new,
        struct itimerval *__restrict __old) throw ();




extern int utimes (__const char *__file, __const struct timeval __tvp[2])
     throw () __attribute__ ((__nonnull__ (1)));



extern int lutimes (__const char *__file, __const struct timeval __tvp[2])
     throw () __attribute__ ((__nonnull__ (1)));


extern int futimes (int __fd, __const struct timeval __tvp[2]) throw ();






extern int futimesat (int __fd, __const char *__file,
        __const struct timeval __tvp[2]) throw ();
# 191 "/usr/include/sys/time.h" 3 4
}
# 298 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2
# 1 "/usr/include/time.h" 1 3 4
# 30 "/usr/include/time.h" 3 4
extern "C" {







# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 1 3 4
# 39 "/usr/include/time.h" 2 3 4



# 1 "/usr/include/bits/time.h" 1 3 4
# 43 "/usr/include/time.h" 2 3 4
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



extern clock_t clock (void) throw ();


extern time_t time (time_t *__timer) throw ();


extern double difftime (time_t __time1, time_t __time0)
     throw () __attribute__ ((__const__));


extern time_t mktime (struct tm *__tp) throw ();





extern size_t strftime (char *__restrict __s, size_t __maxsize,
   __const char *__restrict __format,
   __const struct tm *__restrict __tp) throw ();





extern char *strptime (__const char *__restrict __s,
         __const char *__restrict __fmt, struct tm *__tp)
     throw ();







extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     __const char *__restrict __format,
     __const struct tm *__restrict __tp,
     __locale_t __loc) throw ();



extern char *strptime_l (__const char *__restrict __s,
    __const char *__restrict __fmt, struct tm *__tp,
    __locale_t __loc) throw ();






extern struct tm *gmtime (__const time_t *__timer) throw ();



extern struct tm *localtime (__const time_t *__timer) throw ();





extern struct tm *gmtime_r (__const time_t *__restrict __timer,
       struct tm *__restrict __tp) throw ();



extern struct tm *localtime_r (__const time_t *__restrict __timer,
          struct tm *__restrict __tp) throw ();





extern char *asctime (__const struct tm *__tp) throw ();


extern char *ctime (__const time_t *__timer) throw ();







extern char *asctime_r (__const struct tm *__restrict __tp,
   char *__restrict __buf) throw ();


extern char *ctime_r (__const time_t *__restrict __timer,
        char *__restrict __buf) throw ();




extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;




extern char *tzname[2];



extern void tzset (void) throw ();



extern int daylight;
extern long int timezone;





extern int stime (__const time_t *__when) throw ();
# 313 "/usr/include/time.h" 3 4
extern time_t timegm (struct tm *__tp) throw ();


extern time_t timelocal (struct tm *__tp) throw ();


extern int dysize (int __year) throw () __attribute__ ((__const__));
# 328 "/usr/include/time.h" 3 4
extern int nanosleep (__const struct timespec *__requested_time,
        struct timespec *__remaining);



extern int clock_getres (clockid_t __clock_id, struct timespec *__res) throw ();


extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) throw ();


extern int clock_settime (clockid_t __clock_id, __const struct timespec *__tp)
     throw ();






extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       __const struct timespec *__req,
       struct timespec *__rem);


extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) throw ();




extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,
    timer_t *__restrict __timerid) throw ();


extern int timer_delete (timer_t __timerid) throw ();


extern int timer_settime (timer_t __timerid, int __flags,
     __const struct itimerspec *__restrict __value,
     struct itimerspec *__restrict __ovalue) throw ();


extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     throw ();


extern int timer_getoverrun (timer_t __timerid) throw ();
# 390 "/usr/include/time.h" 3 4
extern int getdate_err;
# 399 "/usr/include/time.h" 3 4
extern struct tm *getdate (__const char *__string);
# 413 "/usr/include/time.h" 3 4
extern int getdate_r (__const char *__restrict __string,
        struct tm *__restrict __resbufp);


}
# 299 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2
# 310 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
# 1 "/usr/include/fcntl.h" 1 3 4
# 30 "/usr/include/fcntl.h" 3 4
extern "C" {



# 1 "/usr/include/bits/fcntl.h" 1 3 4
# 25 "/usr/include/bits/fcntl.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 26 "/usr/include/bits/fcntl.h" 2 3 4

# 1 "/usr/include/bits/uio.h" 1 3 4
# 44 "/usr/include/bits/uio.h" 3 4
struct iovec
  {
    void *iov_base;
    size_t iov_len;
  };
# 28 "/usr/include/bits/fcntl.h" 2 3 4
# 160 "/usr/include/bits/fcntl.h" 3 4
struct flock
  {
    short int l_type;
    short int l_whence;

    __off_t l_start;
    __off_t l_len;




    __pid_t l_pid;
  };


struct flock64
  {
    short int l_type;
    short int l_whence;
    __off64_t l_start;
    __off64_t l_len;
    __pid_t l_pid;
  };




enum __pid_type
  {
    F_OWNER_TID = 0,
    F_OWNER_PID,
    F_OWNER_GID
  };


struct f_owner_ex
  {
    enum __pid_type type;
    __pid_t pid;
  };
# 257 "/usr/include/bits/fcntl.h" 3 4
extern "C" {




extern ssize_t readahead (int __fd, __off64_t __offset, size_t __count)
    throw ();



extern int sync_file_range (int __fd, __off64_t __from, __off64_t __to,
       unsigned int __flags);



extern ssize_t vmsplice (int __fdout, const struct iovec *__iov,
    size_t __count, unsigned int __flags);


extern ssize_t splice (int __fdin, __off64_t *__offin, int __fdout,
         __off64_t *__offout, size_t __len,
         unsigned int __flags);


extern ssize_t tee (int __fdin, int __fdout, size_t __len,
      unsigned int __flags);



extern int fallocate (int __fd, int __mode, __off_t __offset, __off_t __len);
# 297 "/usr/include/bits/fcntl.h" 3 4
extern int fallocate64 (int __fd, int __mode, __off64_t __offset,
   __off64_t __len);



}
# 35 "/usr/include/fcntl.h" 2 3 4



# 1 "/usr/include/sys/stat.h" 1 3 4
# 105 "/usr/include/sys/stat.h" 3 4
extern "C" {

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



struct stat64
  {
    __dev_t st_dev;





    unsigned int __pad1;
    __ino_t __st_ino;
    __mode_t st_mode;
    __nlink_t st_nlink;

    __uid_t st_uid;
    __gid_t st_gid;





    __dev_t st_rdev;
    unsigned int __pad2;
    __off64_t st_size;

    __blksize_t st_blksize;
    __blkcnt64_t st_blocks;







    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
# 166 "/usr/include/bits/stat.h" 3 4
    __ino64_t st_ino;

  };
# 108 "/usr/include/sys/stat.h" 2 3 4
# 209 "/usr/include/sys/stat.h" 3 4
extern int stat (__const char *__restrict __file,
   struct stat *__restrict __buf) throw () __attribute__ ((__nonnull__ (1, 2)));



extern int fstat (int __fd, struct stat *__buf) throw () __attribute__ ((__nonnull__ (2)));
# 228 "/usr/include/sys/stat.h" 3 4
extern int stat64 (__const char *__restrict __file,
     struct stat64 *__restrict __buf) throw () __attribute__ ((__nonnull__ (1, 2)));
extern int fstat64 (int __fd, struct stat64 *__buf) throw () __attribute__ ((__nonnull__ (2)));







extern int fstatat (int __fd, __const char *__restrict __file,
      struct stat *__restrict __buf, int __flag)
     throw () __attribute__ ((__nonnull__ (2, 3)));
# 253 "/usr/include/sys/stat.h" 3 4
extern int fstatat64 (int __fd, __const char *__restrict __file,
        struct stat64 *__restrict __buf, int __flag)
     throw () __attribute__ ((__nonnull__ (2, 3)));







extern int lstat (__const char *__restrict __file,
    struct stat *__restrict __buf) throw () __attribute__ ((__nonnull__ (1, 2)));
# 276 "/usr/include/sys/stat.h" 3 4
extern int lstat64 (__const char *__restrict __file,
      struct stat64 *__restrict __buf)
     throw () __attribute__ ((__nonnull__ (1, 2)));





extern int chmod (__const char *__file, __mode_t __mode)
     throw () __attribute__ ((__nonnull__ (1)));





extern int lchmod (__const char *__file, __mode_t __mode)
     throw () __attribute__ ((__nonnull__ (1)));




extern int fchmod (int __fd, __mode_t __mode) throw ();





extern int fchmodat (int __fd, __const char *__file, __mode_t __mode,
       int __flag)
     throw () __attribute__ ((__nonnull__ (2))) ;






extern __mode_t umask (__mode_t __mask) throw ();




extern __mode_t getumask (void) throw ();



extern int mkdir (__const char *__path, __mode_t __mode)
     throw () __attribute__ ((__nonnull__ (1)));





extern int mkdirat (int __fd, __const char *__path, __mode_t __mode)
     throw () __attribute__ ((__nonnull__ (2)));






extern int mknod (__const char *__path, __mode_t __mode, __dev_t __dev)
     throw () __attribute__ ((__nonnull__ (1)));





extern int mknodat (int __fd, __const char *__path, __mode_t __mode,
      __dev_t __dev) throw () __attribute__ ((__nonnull__ (2)));





extern int mkfifo (__const char *__path, __mode_t __mode)
     throw () __attribute__ ((__nonnull__ (1)));





extern int mkfifoat (int __fd, __const char *__path, __mode_t __mode)
     throw () __attribute__ ((__nonnull__ (2)));





extern int utimensat (int __fd, __const char *__path,
        __const struct timespec __times[2],
        int __flags)
     throw () __attribute__ ((__nonnull__ (2)));




extern int futimens (int __fd, __const struct timespec __times[2]) throw ();
# 399 "/usr/include/sys/stat.h" 3 4
extern int __fxstat (int __ver, int __fildes, struct stat *__stat_buf)
     throw () __attribute__ ((__nonnull__ (3)));
extern int __xstat (int __ver, __const char *__filename,
      struct stat *__stat_buf) throw () __attribute__ ((__nonnull__ (2, 3)));
extern int __lxstat (int __ver, __const char *__filename,
       struct stat *__stat_buf) throw () __attribute__ ((__nonnull__ (2, 3)));
extern int __fxstatat (int __ver, int __fildes, __const char *__filename,
         struct stat *__stat_buf, int __flag)
     throw () __attribute__ ((__nonnull__ (3, 4)));
# 432 "/usr/include/sys/stat.h" 3 4
extern int __fxstat64 (int __ver, int __fildes, struct stat64 *__stat_buf)
     throw () __attribute__ ((__nonnull__ (3)));
extern int __xstat64 (int __ver, __const char *__filename,
        struct stat64 *__stat_buf) throw () __attribute__ ((__nonnull__ (2, 3)));
extern int __lxstat64 (int __ver, __const char *__filename,
         struct stat64 *__stat_buf) throw () __attribute__ ((__nonnull__ (2, 3)));
extern int __fxstatat64 (int __ver, int __fildes, __const char *__filename,
    struct stat64 *__stat_buf, int __flag)
     throw () __attribute__ ((__nonnull__ (3, 4)));

extern int __xmknod (int __ver, __const char *__path, __mode_t __mode,
       __dev_t *__dev) throw () __attribute__ ((__nonnull__ (2, 4)));

extern int __xmknodat (int __ver, int __fd, __const char *__path,
         __mode_t __mode, __dev_t *__dev)
     throw () __attribute__ ((__nonnull__ (3, 5)));




extern __inline __attribute__ ((__gnu_inline__)) int
stat (__const char *__path, struct stat *__statbuf) throw ()
{
  return __xstat (3, __path, __statbuf);
}


extern __inline __attribute__ ((__gnu_inline__)) int
lstat (__const char *__path, struct stat *__statbuf) throw ()
{
  return __lxstat (3, __path, __statbuf);
}


extern __inline __attribute__ ((__gnu_inline__)) int
fstat (int __fd, struct stat *__statbuf) throw ()
{
  return __fxstat (3, __fd, __statbuf);
}


extern __inline __attribute__ ((__gnu_inline__)) int
fstatat (int __fd, __const char *__filename, struct stat *__statbuf, int __flag) throw ()

{
  return __fxstatat (3, __fd, __filename, __statbuf, __flag);
}



extern __inline __attribute__ ((__gnu_inline__)) int
mknod (__const char *__path, __mode_t __mode, __dev_t __dev) throw ()
{
  return __xmknod (1, __path, __mode, &__dev);
}



extern __inline __attribute__ ((__gnu_inline__)) int
mknodat (int __fd, __const char *__path, __mode_t __mode, __dev_t __dev) throw ()

{
  return __xmknodat (1, __fd, __path, __mode, &__dev);
}





extern __inline __attribute__ ((__gnu_inline__)) int
stat64 (__const char *__path, struct stat64 *__statbuf) throw ()
{
  return __xstat64 (3, __path, __statbuf);
}


extern __inline __attribute__ ((__gnu_inline__)) int
lstat64 (__const char *__path, struct stat64 *__statbuf) throw ()
{
  return __lxstat64 (3, __path, __statbuf);
}


extern __inline __attribute__ ((__gnu_inline__)) int
fstat64 (int __fd, struct stat64 *__statbuf) throw ()
{
  return __fxstat64 (3, __fd, __statbuf);
}


extern __inline __attribute__ ((__gnu_inline__)) int
fstatat64 (int __fd, __const char *__filename, struct stat64 *__statbuf, int __flag) throw ()

{
  return __fxstatat64 (3, __fd, __filename, __statbuf, __flag);
}






}
# 39 "/usr/include/fcntl.h" 2 3 4
# 64 "/usr/include/fcntl.h" 3 4
extern int fcntl (int __fd, int __cmd, ...);
# 73 "/usr/include/fcntl.h" 3 4
extern int open (__const char *__file, int __oflag, ...) __attribute__ ((__nonnull__ (1)));
# 83 "/usr/include/fcntl.h" 3 4
extern int open64 (__const char *__file, int __oflag, ...) __attribute__ ((__nonnull__ (1)));
# 97 "/usr/include/fcntl.h" 3 4
extern int openat (int __fd, __const char *__file, int __oflag, ...)
     __attribute__ ((__nonnull__ (2)));
# 108 "/usr/include/fcntl.h" 3 4
extern int openat64 (int __fd, __const char *__file, int __oflag, ...)
     __attribute__ ((__nonnull__ (2)));
# 118 "/usr/include/fcntl.h" 3 4
extern int creat (__const char *__file, __mode_t __mode) __attribute__ ((__nonnull__ (1)));
# 128 "/usr/include/fcntl.h" 3 4
extern int creat64 (__const char *__file, __mode_t __mode) __attribute__ ((__nonnull__ (1)));
# 164 "/usr/include/fcntl.h" 3 4
extern int posix_fadvise (int __fd, __off_t __offset, __off_t __len,
     int __advise) throw ();
# 176 "/usr/include/fcntl.h" 3 4
extern int posix_fadvise64 (int __fd, __off64_t __offset, __off64_t __len,
       int __advise) throw ();
# 186 "/usr/include/fcntl.h" 3 4
extern int posix_fallocate (int __fd, __off_t __offset, __off_t __len);
# 197 "/usr/include/fcntl.h" 3 4
extern int posix_fallocate64 (int __fd, __off64_t __offset, __off64_t __len);
# 208 "/usr/include/fcntl.h" 3 4
}
# 311 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2
# 351 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
# 1 "/usr/include/sys/wait.h" 1 3 4
# 29 "/usr/include/sys/wait.h" 3 4
extern "C" {

# 1 "/usr/include/signal.h" 1 3 4
# 31 "/usr/include/signal.h" 3 4
extern "C" {

# 1 "/usr/include/bits/sigset.h" 1 3 4
# 104 "/usr/include/bits/sigset.h" 3 4
extern int __sigismember (__const __sigset_t *, int);
extern int __sigaddset (__sigset_t *, int);
extern int __sigdelset (__sigset_t *, int);
# 118 "/usr/include/bits/sigset.h" 3 4
extern __inline __attribute__ ((__gnu_inline__)) int __sigismember (__const __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return (__set->__val[__word] & __mask) ? 1 : 0; }
extern __inline __attribute__ ((__gnu_inline__)) int __sigaddset ( __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return ((__set->__val[__word] |= __mask), 0); }
extern __inline __attribute__ ((__gnu_inline__)) int __sigdelset ( __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return ((__set->__val[__word] &= ~__mask), 0); }
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
     throw ();

extern __sighandler_t sysv_signal (int __sig, __sighandler_t __handler)
     throw ();







extern __sighandler_t signal (int __sig, __sighandler_t __handler)
     throw ();
# 113 "/usr/include/signal.h" 3 4





extern __sighandler_t bsd_signal (int __sig, __sighandler_t __handler)
     throw ();






extern int kill (__pid_t __pid, int __sig) throw ();






extern int killpg (__pid_t __pgrp, int __sig) throw ();




extern int raise (int __sig) throw ();




extern __sighandler_t ssignal (int __sig, __sighandler_t __handler)
     throw ();
extern int gsignal (int __sig) throw ();




extern void psignal (int __sig, __const char *__s);




extern void psiginfo (__const siginfo_t *__pinfo, __const char *__s);
# 168 "/usr/include/signal.h" 3 4
extern int __sigpause (int __sig_or_mask, int __is_sig);
# 177 "/usr/include/signal.h" 3 4
extern int sigpause (int __sig) __asm__ ("__xpg_sigpause");
# 196 "/usr/include/signal.h" 3 4
extern int sigblock (int __mask) throw () __attribute__ ((__deprecated__));


extern int sigsetmask (int __mask) throw () __attribute__ ((__deprecated__));


extern int siggetmask (void) throw () __attribute__ ((__deprecated__));
# 211 "/usr/include/signal.h" 3 4
typedef __sighandler_t sighandler_t;




typedef __sighandler_t sig_t;





extern int sigemptyset (sigset_t *__set) throw () __attribute__ ((__nonnull__ (1)));


extern int sigfillset (sigset_t *__set) throw () __attribute__ ((__nonnull__ (1)));


extern int sigaddset (sigset_t *__set, int __signo) throw () __attribute__ ((__nonnull__ (1)));


extern int sigdelset (sigset_t *__set, int __signo) throw () __attribute__ ((__nonnull__ (1)));


extern int sigismember (__const sigset_t *__set, int __signo)
     throw () __attribute__ ((__nonnull__ (1)));



extern int sigisemptyset (__const sigset_t *__set) throw () __attribute__ ((__nonnull__ (1)));


extern int sigandset (sigset_t *__set, __const sigset_t *__left,
        __const sigset_t *__right) throw () __attribute__ ((__nonnull__ (1, 2, 3)));


extern int sigorset (sigset_t *__set, __const sigset_t *__left,
       __const sigset_t *__right) throw () __attribute__ ((__nonnull__ (1, 2, 3)));




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
   sigset_t *__restrict __oset) throw ();






extern int sigsuspend (__const sigset_t *__set) __attribute__ ((__nonnull__ (1)));


extern int sigaction (int __sig, __const struct sigaction *__restrict __act,
        struct sigaction *__restrict __oact) throw ();


extern int sigpending (sigset_t *__set) throw () __attribute__ ((__nonnull__ (1)));






extern int sigwait (__const sigset_t *__restrict __set, int *__restrict __sig)
     __attribute__ ((__nonnull__ (1, 2)));






extern int sigwaitinfo (__const sigset_t *__restrict __set,
   siginfo_t *__restrict __info) __attribute__ ((__nonnull__ (1)));






extern int sigtimedwait (__const sigset_t *__restrict __set,
    siginfo_t *__restrict __info,
    __const struct timespec *__restrict __timeout)
     __attribute__ ((__nonnull__ (1)));



extern int sigqueue (__pid_t __pid, int __sig, __const union sigval __val)
     throw ();
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
     struct sigvec *__ovec) throw ();



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


extern int sigreturn (struct sigcontext *__scp) throw ();






# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 1 3 4
# 350 "/usr/include/signal.h" 2 3 4




extern int siginterrupt (int __sig, int __interrupt) throw ();

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


# 1 "/usr/include/sys/ucontext.h" 1 3 4
# 23 "/usr/include/sys/ucontext.h" 3 4
# 1 "/usr/include/signal.h" 1 3 4
# 24 "/usr/include/sys/ucontext.h" 2 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 25 "/usr/include/sys/ucontext.h" 2 3 4
# 148 "/usr/include/sys/ucontext.h" 3 4
typedef int greg_t;





typedef greg_t gregset_t[19];



enum
{
  REG_GS = 0,

  REG_FS,

  REG_ES,

  REG_DS,

  REG_EDI,

  REG_ESI,

  REG_EBP,

  REG_ESP,

  REG_EBX,

  REG_EDX,

  REG_ECX,

  REG_EAX,

  REG_TRAPNO,

  REG_ERR,

  REG_EIP,

  REG_CS,

  REG_EFL,

  REG_UESP,

  REG_SS

};



struct _libc_fpreg
{
  unsigned short int significand[4];
  unsigned short int exponent;
};

struct _libc_fpstate
{
  unsigned long int cw;
  unsigned long int sw;
  unsigned long int tag;
  unsigned long int ipoff;
  unsigned long int cssel;
  unsigned long int dataoff;
  unsigned long int datasel;
  struct _libc_fpreg _st[8];
  unsigned long int status;
};


typedef struct _libc_fpstate *fpregset_t;


typedef struct
  {
    gregset_t gregs;


    fpregset_t fpregs;
    unsigned long int oldmask;
    unsigned long int cr2;
  } mcontext_t;


typedef struct ucontext
  {
    unsigned long int uc_flags;
    struct ucontext *uc_link;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
    __sigset_t uc_sigmask;
    struct _libc_fpstate __fpregs_mem;
  } ucontext_t;
# 360 "/usr/include/signal.h" 2 3 4





extern int sigstack (struct sigstack *__ss, struct sigstack *__oss)
     throw () __attribute__ ((__deprecated__));



extern int sigaltstack (__const struct sigaltstack *__restrict __ss,
   struct sigaltstack *__restrict __oss) throw ();







extern int sighold (int __sig) throw ();


extern int sigrelse (int __sig) throw ();


extern int sigignore (int __sig) throw ();


extern __sighandler_t sigset (int __sig, __sighandler_t __disp) throw ();






# 1 "/usr/include/bits/sigthread.h" 1 3 4
# 31 "/usr/include/bits/sigthread.h" 3 4
extern int pthread_sigmask (int __how,
       __const __sigset_t *__restrict __newmask,
       __sigset_t *__restrict __oldmask)throw ();


extern int pthread_kill (pthread_t __threadid, int __signo) throw ();



extern int pthread_sigqueue (pthread_t __threadid, int __signo,
        const union sigval __value) throw ();
# 396 "/usr/include/signal.h" 2 3 4






extern int __libc_current_sigrtmin (void) throw ();

extern int __libc_current_sigrtmax (void) throw ();



}
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




typedef __rlim64_t rlim64_t;


struct rlimit
  {

    rlim_t rlim_cur;

    rlim_t rlim_max;
  };


struct rlimit64
  {

    rlim64_t rlim_cur;

    rlim64_t rlim_max;
 };



enum __rusage_who
{

  RUSAGE_SELF = 0,



  RUSAGE_CHILDREN = -1



  ,

  RUSAGE_THREAD = 1




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






extern "C" {
# 43 "/usr/include/sys/resource.h" 3 4
typedef int __rlimit_resource_t;
typedef int __rusage_who_t;
typedef int __priority_which_t;





extern int getrlimit (__rlimit_resource_t __resource,
        struct rlimit *__rlimits) throw ();
# 62 "/usr/include/sys/resource.h" 3 4
extern int getrlimit64 (__rlimit_resource_t __resource,
   struct rlimit64 *__rlimits) throw ();






extern int setrlimit (__rlimit_resource_t __resource,
        __const struct rlimit *__rlimits) throw ();
# 82 "/usr/include/sys/resource.h" 3 4
extern int setrlimit64 (__rlimit_resource_t __resource,
   __const struct rlimit64 *__rlimits) throw ();




extern int getrusage (__rusage_who_t __who, struct rusage *__usage) throw ();





extern int getpriority (__priority_which_t __which, id_t __who) throw ();



extern int setpriority (__priority_which_t __which, id_t __who, int __prio)
     throw ();

}
# 33 "/usr/include/sys/wait.h" 2 3 4
# 102 "/usr/include/sys/wait.h" 3 4
typedef enum
{
  P_ALL,
  P_PID,
  P_PGID
} idtype_t;
# 116 "/usr/include/sys/wait.h" 3 4
extern __pid_t wait (void * __stat_loc);
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






extern __pid_t wait3 (void * __stat_loc, int __options,
        struct rusage * __usage) throw ();




extern __pid_t wait4 (__pid_t __pid, void * __stat_loc, int __options,
        struct rusage *__usage) throw ();



}
# 352 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2
# 382 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
# 1 "/usr/include/sys/mman.h" 1 3 4
# 26 "/usr/include/sys/mman.h" 3 4
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 1 3 4
# 27 "/usr/include/sys/mman.h" 2 3 4
# 42 "/usr/include/sys/mman.h" 3 4
# 1 "/usr/include/bits/mman.h" 1 3 4
# 43 "/usr/include/sys/mman.h" 2 3 4




extern "C" {
# 58 "/usr/include/sys/mman.h" 3 4
extern void *mmap (void *__addr, size_t __len, int __prot,
     int __flags, int __fd, __off_t __offset) throw ();
# 71 "/usr/include/sys/mman.h" 3 4
extern void *mmap64 (void *__addr, size_t __len, int __prot,
       int __flags, int __fd, __off64_t __offset) throw ();




extern int munmap (void *__addr, size_t __len) throw ();




extern int mprotect (void *__addr, size_t __len, int __prot) throw ();







extern int msync (void *__addr, size_t __len, int __flags);




extern int madvise (void *__addr, size_t __len, int __advice) throw ();



extern int posix_madvise (void *__addr, size_t __len, int __advice) throw ();




extern int mlock (__const void *__addr, size_t __len) throw ();


extern int munlock (__const void *__addr, size_t __len) throw ();




extern int mlockall (int __flags) throw ();



extern int munlockall (void) throw ();







extern int mincore (void *__start, size_t __len, unsigned char *__vec)
     throw ();
# 134 "/usr/include/sys/mman.h" 3 4
extern void *mremap (void *__addr, size_t __old_len, size_t __new_len,
       int __flags, ...) throw ();



extern int remap_file_pages (void *__start, size_t __size, int __prot,
        size_t __pgoff, int __flags) throw ();




extern int shm_open (__const char *__name, int __oflag, mode_t __mode);


extern int shm_unlink (__const char *__name);

}
# 383 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2
# 398 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
# 1 "/usr/include/sys/times.h" 1 3 4
# 32 "/usr/include/sys/times.h" 3 4
extern "C" {


struct tms
  {
    clock_t tms_utime;
    clock_t tms_stime;

    clock_t tms_cutime;
    clock_t tms_cstime;
  };






extern clock_t times (struct tms *__buffer) throw ();

}
# 399 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2
# 407 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
extern "C" {
# 431 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
extern int getopt (int, char * const *, const char *);
# 455 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
}



# 1 "/usr/include/malloc.h" 1 3 4
# 25 "/usr/include/malloc.h" 3 4
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 1 3 4
# 26 "/usr/include/malloc.h" 2 3 4
# 48 "/usr/include/malloc.h" 3 4
extern "C" {


extern void *malloc (size_t __size) throw () __attribute__ ((__malloc__)) ;


extern void *calloc (size_t __nmemb, size_t __size) throw ()
       __attribute__ ((__malloc__)) ;






extern void *realloc (void *__ptr, size_t __size) throw ()
       __attribute__ ((__warn_unused_result__));


extern void free (void *__ptr) throw ();


extern void cfree (void *__ptr) throw ();


extern void *memalign (size_t __alignment, size_t __size) throw ()
       __attribute__ ((__malloc__)) ;


extern void *valloc (size_t __size) throw ()
       __attribute__ ((__malloc__)) ;



extern void * pvalloc (size_t __size) throw ()
       __attribute__ ((__malloc__)) ;



extern void *(*__morecore) (ptrdiff_t __size);


extern void *__default_morecore (ptrdiff_t __size) throw ()
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


extern struct mallinfo mallinfo (void) throw ();
# 135 "/usr/include/malloc.h" 3 4
extern int mallopt (int __param, int __val) throw ();



extern int malloc_trim (size_t __pad) throw ();



extern size_t malloc_usable_size (void *__ptr) throw ();


extern void malloc_stats (void) throw ();


extern int malloc_info (int __options, FILE *__fp);


extern void *malloc_get_state (void) throw ();



extern int malloc_set_state (void *__ptr) throw ();




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


extern void __malloc_check_init (void) throw ();


}
# 460 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2



extern "C" {
# 479 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
}



# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stdint.h" 1 3 4


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
# 4 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stdint.h" 2 3 4
# 484 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2



# 1 "/usr/include/inttypes.h" 1 3 4
# 274 "/usr/include/inttypes.h" 3 4
extern "C" {
# 288 "/usr/include/inttypes.h" 3 4
typedef struct
  {
    long long int quot;
    long long int rem;
  } imaxdiv_t;





extern intmax_t imaxabs (intmax_t __n) throw () __attribute__ ((__const__));


extern imaxdiv_t imaxdiv (intmax_t __numer, intmax_t __denom)
      throw () __attribute__ ((__const__));


extern intmax_t strtoimax (__const char *__restrict __nptr,
      char **__restrict __endptr, int __base) throw ();


extern uintmax_t strtoumax (__const char *__restrict __nptr,
       char ** __restrict __endptr, int __base) throw ();


extern intmax_t wcstoimax (__const wchar_t *__restrict __nptr,
      wchar_t **__restrict __endptr, int __base)
     throw ();


extern uintmax_t wcstoumax (__const wchar_t *__restrict __nptr,
       wchar_t ** __restrict __endptr, int __base)
     throw ();
# 379 "/usr/include/inttypes.h" 3 4
__extension__
extern long long int __strtoll_internal (__const char *__restrict __nptr,
      char **__restrict __endptr,
      int __base, int __group)
  throw () __attribute__ ((__nonnull__ (1))) ;

extern __inline __attribute__ ((__gnu_inline__)) intmax_t
strtoimax (__const char *__restrict nptr, char **__restrict endptr, int base) throw ()

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
  throw () __attribute__ ((__nonnull__ (1))) ;

extern __inline __attribute__ ((__gnu_inline__)) uintmax_t
strtoumax (__const char *__restrict nptr, char **__restrict endptr, int base) throw ()

{
  return __strtoull_internal (nptr, endptr, base, 0);
}

__extension__
extern long long int __wcstoll_internal (__const wchar_t *
      __restrict __nptr,
      wchar_t **__restrict __endptr,
      int __base, int __group)
  throw () __attribute__ ((__nonnull__ (1))) ;

extern __inline __attribute__ ((__gnu_inline__)) intmax_t
wcstoimax (__const wchar_t *__restrict nptr, wchar_t **__restrict endptr, int base) throw ()

{
  return __wcstoll_internal (nptr, endptr, base, 0);
}


__extension__
extern unsigned long long int __wcstoull_internal (__const wchar_t *
         __restrict __nptr,
         wchar_t **
         __restrict __endptr,
         int __base,
         int __group)
  throw () __attribute__ ((__nonnull__ (1))) ;

extern __inline __attribute__ ((__gnu_inline__)) uintmax_t
wcstoumax (__const wchar_t *__restrict nptr, wchar_t **__restrict endptr, int base) throw ()

{
  return __wcstoull_internal (nptr, endptr, base, 0);
}




}
# 488 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2



extern "C" {
# 534 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
}
# 623 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/filenames.h" 1
# 30 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/filenames.h"
extern "C" {
# 81 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/filenames.h"
extern int filename_cmp (const char *s1, const char *s2);


extern int filename_ncmp (const char *s1, const char *s2,
     size_t n);


}
# 624 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2
# 635 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
# 1 "/usr/include/dlfcn.h" 1 3 4
# 25 "/usr/include/dlfcn.h" 3 4
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 1 3 4
# 26 "/usr/include/dlfcn.h" 2 3 4


# 1 "/usr/include/bits/dlfcn.h" 1 3 4
# 58 "/usr/include/bits/dlfcn.h" 3 4
extern "C" {


extern void _dl_mcount_wrapper_check (void *__selfpc) throw ();

}
# 29 "/usr/include/dlfcn.h" 2 3 4
# 45 "/usr/include/dlfcn.h" 3 4
typedef long int Lmid_t;







extern "C" {



extern void *dlopen (__const char *__file, int __mode) throw ();



extern int dlclose (void *__handle) throw () __attribute__ ((__nonnull__ (1)));



extern void *dlsym (void *__restrict __handle,
      __const char *__restrict __name) throw () __attribute__ ((__nonnull__ (2)));



extern void *dlmopen (Lmid_t __nsid, __const char *__file, int __mode) throw ();



extern void *dlvsym (void *__restrict __handle,
       __const char *__restrict __name,
       __const char *__restrict __version)
     throw () __attribute__ ((__nonnull__ (2, 3)));





extern char *dlerror (void) throw ();





typedef struct
{
  __const char *dli_fname;
  void *dli_fbase;
  __const char *dli_sname;
  void *dli_saddr;
} Dl_info;



extern int dladdr (__const void *__address, Dl_info *__info)
     throw () __attribute__ ((__nonnull__ (2)));


extern int dladdr1 (__const void *__address, Dl_info *__info,
      void **__extra_info, int __flags) throw () __attribute__ ((__nonnull__ (2)));




enum
  {

    RTLD_DL_SYMENT = 1,


    RTLD_DL_LINKMAP = 2
  };







extern int dlinfo (void *__restrict __handle,
     int __request, void *__restrict __arg)
     throw () __attribute__ ((__nonnull__ (1, 3)));


enum
  {

    RTLD_DI_LMID = 1,



    RTLD_DI_LINKMAP = 2,

    RTLD_DI_CONFIGADDR = 3,






    RTLD_DI_SERINFO = 4,
    RTLD_DI_SERINFOSIZE = 5,



    RTLD_DI_ORIGIN = 6,

    RTLD_DI_PROFILENAME = 7,
    RTLD_DI_PROFILEOUT = 8,




    RTLD_DI_TLS_MODID = 9,





    RTLD_DI_TLS_DATA = 10,

    RTLD_DI_MAX = 10
  };




typedef struct
{
  char *dls_name;
  unsigned int dls_flags;
} Dl_serpath;



typedef struct
{
  size_t dls_size;
  unsigned int dls_cnt;
  Dl_serpath dls_serpath[1];
} Dl_serinfo;



}
# 636 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2



# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h" 1
# 40 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h"
extern "C" {





# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 1 3 4
# 47 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h" 2
# 56 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h"
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
# 121 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h"
extern const char *lbasename (const char *);




extern const char *dos_lbasename (const char *);





extern const char *unix_lbasename (const char *);



extern char *lrealpath (const char *);





extern char *concat (const char *, ...) __attribute__ ((__malloc__)) __attribute__ ((__sentinel__));
# 151 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h"
extern char *reconcat (char *, const char *, ...) __attribute__ ((__malloc__)) __attribute__ ((__sentinel__));





extern unsigned long concat_length (const char *, ...) __attribute__ ((__sentinel__));






extern char *concat_copy (char *, const char *, ...) __attribute__ ((__sentinel__));






extern char *concat_copy2 (const char *, ...) __attribute__ ((__sentinel__));



extern char *libiberty_concat_ptr;
# 187 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h"
extern int fdmatch (int fd1, int fd2);
# 199 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h"
extern char * getpwd (void);
# 212 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h"
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
# 276 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h"
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
# 375 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h"
extern const unsigned char _hex_value[256];
extern void hex_init (void);
# 401 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h"
extern struct pex_obj *pex_init (int flags, const char *pname,
     const char *tempbase);
# 496 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h"
extern const char *pex_run (struct pex_obj *obj, int flags,
       const char *executable, char * const *argv,
       const char *outname, const char *errname,
       int *err);
# 511 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h"
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
# 586 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h"
extern const char *pex_one (int flags, const char *executable,
       char * const *argv, const char *pname,
       const char *outname, const char *errname,
       int *status, int *err);
# 605 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h"
extern int pexecute (const char *, char * const *, const char *,
                     const char *, char **, char **, int);



extern int pwait (int, int *, int);
# 642 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h"
extern void setproctitle (const char *name, ...);


extern void stack_limit_increase (unsigned long);
# 655 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h"
extern void *C_alloca (size_t) __attribute__ ((__malloc__));
# 682 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/libiberty.h"
}
# 640 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h" 2
# 668 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
extern void fancy_abort (const char *, int, const char *) __attribute__ ((__noreturn__));
# 758 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
        




        






        


        
# 814 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
        






        
# 884 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
        
# 896 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
        


        



        
# 914 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
        
# 930 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/system.h"
        
# 29 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/gcc-plugin.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/coretypes.h" 1
# 47 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/coretypes.h"
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
# 168 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/coretypes.h"
typedef int reg_class_t;
# 186 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/coretypes.h"
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
# 30 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/gcc-plugin.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/highlev-plugin-common.h" 1
# 31 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/gcc-plugin.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/hashtab.h" 1
# 37 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/hashtab.h"
extern "C" {
# 47 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/hashtab.h"
typedef unsigned int hashval_t;




typedef hashval_t (*htab_hash) (const void *);






typedef int (*htab_eq) (const void *, const void *);



typedef void (*htab_del) (void *);





typedef int (*htab_trav) (void **, void *);





typedef void *(*htab_alloc) (size_t, size_t);


typedef void (*htab_free) (void *);



typedef void *(*htab_alloc_with_arg) (void *, size_t, size_t);
typedef void (*htab_free_with_arg) (void *, void *);
# 100 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/hashtab.h"
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




}
# 32 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/gcc-plugin.h" 2


enum plugin_event
{

# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/plugin.def" 1
# 22 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/plugin.def"
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
# 38 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/gcc-plugin.h" 2

  PLUGIN_EVENT_FIRST_DYNAMIC
};




extern "C" {


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



extern bool plugin_default_version_check (struct plugin_gcc_version *,
       struct plugin_gcc_version *);
# 103 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/gcc-plugin.h"
typedef int (*plugin_init_func) (struct plugin_name_args *plugin_info,
                                 struct plugin_gcc_version *version);



extern int plugin_init (struct plugin_name_args *plugin_info,
                        struct plugin_gcc_version *version);






typedef void (*plugin_callback_func) (void *gcc_data, void *user_data);
# 129 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/gcc-plugin.h"
extern int get_event_last (void);

int get_named_event_id (const char *name, enum insert_option insert);






extern void register_callback (const char *plugin_name,
          int event,
                               plugin_callback_func callback,
                               void *user_data);

extern int unregister_callback (const char *plugin_name, int event);





extern const char* default_plugin_dir_name (void);


}






extern "C" {

extern int plugin_is_GPL_compatible;

}
# 24 "../../../src/plugin-utils.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h" 1
# 26 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/machmode.h" 1
# 25 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/machmode.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/insn-modes.h" 1






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
# 26 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/machmode.h" 2



extern const char * const mode_name[NUM_MACHINE_MODES];




# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/mode-classes.def" 1
# 35 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/machmode.h" 2

enum mode_class { MODE_RANDOM, MODE_CC, MODE_INT, MODE_PARTIAL_INT, MODE_FRACT, MODE_UFRACT, MODE_ACCUM, MODE_UACCUM, MODE_FLOAT, MODE_DECIMAL_FLOAT, MODE_COMPLEX_INT, MODE_COMPLEX_FLOAT, MODE_VECTOR_INT, MODE_VECTOR_FRACT, MODE_VECTOR_UFRACT, MODE_VECTOR_ACCUM, MODE_VECTOR_UACCUM, MODE_VECTOR_FLOAT, MAX_MODE_CLASS };






extern const unsigned char mode_class[NUM_MACHINE_MODES];
# 179 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/machmode.h"
extern unsigned char mode_size[NUM_MACHINE_MODES];




extern const unsigned short mode_precision[NUM_MACHINE_MODES];



extern const unsigned char mode_ibit[NUM_MACHINE_MODES];



extern const unsigned char mode_fbit[NUM_MACHINE_MODES];





extern const unsigned long mode_mask_array[NUM_MACHINE_MODES];





extern const unsigned char mode_inner[NUM_MACHINE_MODES];
# 216 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/machmode.h"
extern const unsigned char mode_nunits[NUM_MACHINE_MODES];




extern const unsigned char mode_wider[NUM_MACHINE_MODES];




extern const unsigned char mode_2xwider[NUM_MACHINE_MODES];






extern enum machine_mode mode_for_size (unsigned int, enum mode_class, int);



extern enum machine_mode smallest_mode_for_size (unsigned int,
       enum mode_class);





extern enum machine_mode int_mode_for_mode (enum machine_mode);




extern enum machine_mode mode_for_vector (enum machine_mode, unsigned);



extern enum machine_mode get_best_mode (int, int,
     unsigned long,
     unsigned long,
     unsigned int,
     enum machine_mode, int);



extern unsigned char mode_base_align[NUM_MACHINE_MODES];

extern unsigned get_mode_alignment (enum machine_mode);





extern const unsigned char class_narrowest_mode[MAX_MODE_CLASS];






extern enum machine_mode byte_mode;
extern enum machine_mode word_mode;
extern enum machine_mode ptr_mode;


extern void init_adjust_machine_modes (void);
# 27 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/input.h" 1
# 25 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/input.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/line-map.h" 1
# 37 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/line-map.h"
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
# 71 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/line-map.h"
struct line_map_ordinary {
  const char *to_file;
  linenum_type to_line;




  int included_from;





  unsigned char sysp;


  unsigned int column_bits : 8;
};





struct cpp_hashnode;
# 105 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/line-map.h"
struct line_map_macro {

  struct cpp_hashnode *


    macro;


  unsigned int n_tokens;
# 168 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/line-map.h"
  source_location * macro_locations;






  source_location expansion;
};
# 204 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/line-map.h"
struct line_map {
  source_location start_location;


  enum lc_reason reason : 8;

  union map_u {
    struct line_map_ordinary ordinary;
    struct line_map_macro macro;
  } d;
};
# 244 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/line-map.h"
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


  bool trace_includes;


  source_location highest_location;


  source_location highest_line;



  unsigned int max_column_hint;



  line_map_realloc reallocator;



  line_map_round_alloc_size_func round_alloc_size;
};
# 412 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/line-map.h"
extern void linemap_init (struct line_maps *);



extern void linemap_check_files_exited (struct line_maps *);







extern source_location linemap_line_start
(struct line_maps *set, linenum_type to_line, unsigned int max_column_hint);
# 440 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/line-map.h"
extern const struct line_map *linemap_add
  (struct line_maps *, enum lc_reason, unsigned int sysp,
   const char *to_file, linenum_type to_line);







extern const struct line_map *linemap_lookup
  (struct line_maps *, source_location);



bool linemap_tracks_macro_expansion_locs_p (struct line_maps *);



bool linemap_macro_expansion_map_p (const struct line_map *);


const char* linemap_map_get_macro_name (const struct line_map*);
# 473 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/line-map.h"
int linemap_location_in_system_header_p (struct line_maps *,
      source_location);




bool linemap_location_from_macro_expansion_p (struct line_maps *,
           source_location);
# 550 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/line-map.h"
extern source_location
linemap_position_for_column (struct line_maps *, unsigned int);



source_location linemap_position_for_line_and_column (struct line_map *,
            linenum_type,
            unsigned int);
# 577 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/line-map.h"
int linemap_compare_locations (struct line_maps *set,
          source_location pre,
          source_location post);







typedef struct
{

  const char *file;


  int line;

  int column;


  bool sysp;
} expanded_location;




enum location_resolution_kind
{
  LRK_MACRO_EXPANSION_POINT,
  LRK_SPELLING_LOCATION,
  LRK_MACRO_DEFINITION_LOCATION
};
# 659 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/line-map.h"
source_location linemap_resolve_location (struct line_maps *,
       source_location loc,
       enum location_resolution_kind lrk,
       const struct line_map **loc_map);
# 671 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/line-map.h"
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




void linemap_dump (FILE *, struct line_maps *, unsigned, bool);




void line_table_dump (FILE *, struct line_maps *, unsigned int, unsigned int);
# 26 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/input.h" 2

extern struct line_maps *line_table;
# 37 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/input.h"
extern char builtins_location_check[(((source_location) 1)
         < 2) ? 1 : -1];

extern expanded_location expand_location (source_location);



typedef source_location location_t;

extern location_t input_location;
# 58 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/input.h"
void dump_line_table_statistics (void);
# 28 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/statistics.h" 1
# 41 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/statistics.h"
struct function;


extern void statistics_early_init (void);
extern void statistics_init (void);
extern void statistics_fini (void);
extern void statistics_fini_pass (void);
extern void statistics_counter_event (struct function *, const char *, int);
extern void statistics_histogram_event (struct function *, const char *, int);
# 29 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/vec.h" 1
# 472 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/vec.h"
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
# 514 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/vec.h"
typedef struct vec_prefix
{
  unsigned num;
  unsigned alloc;
} vec_prefix;
# 1351 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/vec.h"
extern void *vec_stack_p_reserve (void *, int );
extern void *vec_stack_p_reserve_exact (void *, int );
extern void *vec_stack_p_reserve_exact_1 (int, void *);
extern void *vec_stack_o_reserve (void *, int, size_t, size_t );
extern void *vec_stack_o_reserve_exact (void *, int, size_t, size_t
      );
extern void vec_stack_free (void *);
# 30 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/vecir.h" 1
# 28 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/vecir.h"
static inline void VEC_tree_must_be_pointer_type (void) { (void)((tree)1 == (void *)1); } typedef struct VEC_tree_base { struct vec_prefix prefix; tree vec[1]; } VEC_tree_base; typedef struct VEC_tree_none { VEC_tree_base base; } VEC_tree_none; static inline unsigned VEC_tree_base_length (const VEC_tree_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline tree VEC_tree_base_last (const VEC_tree_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static inline tree VEC_tree_base_index (const VEC_tree_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static inline int VEC_tree_base_iterate (const VEC_tree_base *vec_, unsigned ix_, tree *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (tree) 0; return 0; } } static inline size_t VEC_tree_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_tree_base, vec) + alloc_ * sizeof(tree); } static inline void VEC_tree_base_embedded_init (VEC_tree_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_tree_base_space (VEC_tree_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_tree_base_splice (VEC_tree_base *dst_, VEC_tree_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (tree)); dst_->prefix.num += len_; } } static inline tree *VEC_tree_base_quick_push (VEC_tree_base *vec_, tree obj_ ) { tree *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static inline tree VEC_tree_base_pop (VEC_tree_base *vec_ ) { tree obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_tree_base_truncate (VEC_tree_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline tree VEC_tree_base_replace (VEC_tree_base *vec_, unsigned ix_, tree obj_ ) { tree old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static inline tree *VEC_tree_base_quick_insert (VEC_tree_base *vec_, unsigned ix_, tree obj_ ) { tree *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (tree)); *slot_ = obj_; return slot_; } static inline tree VEC_tree_base_ordered_remove (VEC_tree_base *vec_, unsigned ix_ ) { tree *slot_; tree obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (tree)); return obj_; } static inline tree VEC_tree_base_unordered_remove (VEC_tree_base *vec_, unsigned ix_ ) { tree *slot_; tree obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_tree_base_block_remove (VEC_tree_base *vec_, unsigned ix_, unsigned len_ ) { tree *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (tree)); } static inline tree *VEC_tree_base_address (VEC_tree_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_tree_base_lower_bound (VEC_tree_base *vec_, const tree obj_, bool (*lessthan_)(const tree, const tree) ) { unsigned int len_ = VEC_tree_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { tree middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_tree_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_tree_gc { VEC_tree_base base; } VEC_tree_gc; static inline VEC_tree_gc *VEC_tree_gc_alloc (int alloc_ ) { return (VEC_tree_gc *) vec_gc_p_reserve_exact (__null, alloc_ ); } static inline void VEC_tree_gc_free (VEC_tree_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = __null; } static inline VEC_tree_gc *VEC_tree_gc_copy (VEC_tree_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_tree_gc *new_vec_ = __null; if (len_) { new_vec_ = (VEC_tree_gc *)(vec_gc_p_reserve_exact (__null, len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (tree) * len_); } return new_vec_; } static inline int VEC_tree_gc_reserve (VEC_tree_gc **vec_, int alloc_ ) { int extend = !VEC_tree_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_tree_gc *) vec_gc_p_reserve (*vec_, alloc_ ); return extend; } static inline int VEC_tree_gc_reserve_exact (VEC_tree_gc **vec_, int alloc_ ) { int extend = !VEC_tree_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_tree_gc *) vec_gc_p_reserve_exact (*vec_, alloc_ ); return extend; } static inline void VEC_tree_gc_safe_grow (VEC_tree_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_tree_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_tree_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_tree_gc_safe_grow_cleared (VEC_tree_gc **vec_, int size_ ) { int oldsize = VEC_tree_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_tree_gc_safe_grow (vec_, size_ ); memset (&(VEC_tree_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (tree) * (size_ - oldsize)); } static inline void VEC_tree_gc_safe_splice (VEC_tree_gc **dst_, VEC_tree_base *src_ ) { if (src_) { VEC_tree_gc_reserve_exact (dst_, src_->prefix.num ); VEC_tree_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline tree *VEC_tree_gc_safe_push (VEC_tree_gc **vec_, tree obj_ ) { VEC_tree_gc_reserve (vec_, 1 ); return VEC_tree_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline tree *VEC_tree_gc_safe_insert (VEC_tree_gc **vec_, unsigned ix_, tree obj_ ) { VEC_tree_gc_reserve (vec_, 1 ); return VEC_tree_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
typedef struct VEC_tree_heap { VEC_tree_base base; } VEC_tree_heap; static inline VEC_tree_heap *VEC_tree_heap_alloc (int alloc_ ) { return (VEC_tree_heap *) vec_heap_p_reserve_exact (__null, alloc_ ); } static inline void VEC_tree_heap_free (VEC_tree_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = __null; } static inline VEC_tree_heap *VEC_tree_heap_copy (VEC_tree_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_tree_heap *new_vec_ = __null; if (len_) { new_vec_ = (VEC_tree_heap *)(vec_heap_p_reserve_exact (__null, len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (tree) * len_); } return new_vec_; } static inline int VEC_tree_heap_reserve (VEC_tree_heap **vec_, int alloc_ ) { int extend = !VEC_tree_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_tree_heap *) vec_heap_p_reserve (*vec_, alloc_ ); return extend; } static inline int VEC_tree_heap_reserve_exact (VEC_tree_heap **vec_, int alloc_ ) { int extend = !VEC_tree_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_tree_heap *) vec_heap_p_reserve_exact (*vec_, alloc_ ); return extend; } static inline void VEC_tree_heap_safe_grow (VEC_tree_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_tree_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_tree_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_tree_heap_safe_grow_cleared (VEC_tree_heap **vec_, int size_ ) { int oldsize = VEC_tree_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_tree_heap_safe_grow (vec_, size_ ); memset (&(VEC_tree_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (tree) * (size_ - oldsize)); } static inline void VEC_tree_heap_safe_splice (VEC_tree_heap **dst_, VEC_tree_base *src_ ) { if (src_) { VEC_tree_heap_reserve_exact (dst_, src_->prefix.num ); VEC_tree_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline tree *VEC_tree_heap_safe_push (VEC_tree_heap **vec_, tree obj_ ) { VEC_tree_heap_reserve (vec_, 1 ); return VEC_tree_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline tree *VEC_tree_heap_safe_insert (VEC_tree_heap **vec_, unsigned ix_, tree obj_ ) { VEC_tree_heap_reserve (vec_, 1 ); return VEC_tree_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;


static inline void VEC_gimple_must_be_pointer_type (void) { (void)((gimple)1 == (void *)1); } typedef struct VEC_gimple_base { struct vec_prefix prefix; gimple vec[1]; } VEC_gimple_base; typedef struct VEC_gimple_none { VEC_gimple_base base; } VEC_gimple_none; static inline unsigned VEC_gimple_base_length (const VEC_gimple_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline gimple VEC_gimple_base_last (const VEC_gimple_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static inline gimple VEC_gimple_base_index (const VEC_gimple_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static inline int VEC_gimple_base_iterate (const VEC_gimple_base *vec_, unsigned ix_, gimple *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (gimple) 0; return 0; } } static inline size_t VEC_gimple_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_gimple_base, vec) + alloc_ * sizeof(gimple); } static inline void VEC_gimple_base_embedded_init (VEC_gimple_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_gimple_base_space (VEC_gimple_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_gimple_base_splice (VEC_gimple_base *dst_, VEC_gimple_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (gimple)); dst_->prefix.num += len_; } } static inline gimple *VEC_gimple_base_quick_push (VEC_gimple_base *vec_, gimple obj_ ) { gimple *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static inline gimple VEC_gimple_base_pop (VEC_gimple_base *vec_ ) { gimple obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_gimple_base_truncate (VEC_gimple_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline gimple VEC_gimple_base_replace (VEC_gimple_base *vec_, unsigned ix_, gimple obj_ ) { gimple old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static inline gimple *VEC_gimple_base_quick_insert (VEC_gimple_base *vec_, unsigned ix_, gimple obj_ ) { gimple *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (gimple)); *slot_ = obj_; return slot_; } static inline gimple VEC_gimple_base_ordered_remove (VEC_gimple_base *vec_, unsigned ix_ ) { gimple *slot_; gimple obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (gimple)); return obj_; } static inline gimple VEC_gimple_base_unordered_remove (VEC_gimple_base *vec_, unsigned ix_ ) { gimple *slot_; gimple obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_gimple_base_block_remove (VEC_gimple_base *vec_, unsigned ix_, unsigned len_ ) { gimple *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (gimple)); } static inline gimple *VEC_gimple_base_address (VEC_gimple_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_gimple_base_lower_bound (VEC_gimple_base *vec_, const gimple obj_, bool (*lessthan_)(const gimple, const gimple) ) { unsigned int len_ = VEC_gimple_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { gimple middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_gimple_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_gimple_heap { VEC_gimple_base base; } VEC_gimple_heap; static inline VEC_gimple_heap *VEC_gimple_heap_alloc (int alloc_ ) { return (VEC_gimple_heap *) vec_heap_p_reserve_exact (__null, alloc_ ); } static inline void VEC_gimple_heap_free (VEC_gimple_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = __null; } static inline VEC_gimple_heap *VEC_gimple_heap_copy (VEC_gimple_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_gimple_heap *new_vec_ = __null; if (len_) { new_vec_ = (VEC_gimple_heap *)(vec_heap_p_reserve_exact (__null, len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (gimple) * len_); } return new_vec_; } static inline int VEC_gimple_heap_reserve (VEC_gimple_heap **vec_, int alloc_ ) { int extend = !VEC_gimple_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_heap *) vec_heap_p_reserve (*vec_, alloc_ ); return extend; } static inline int VEC_gimple_heap_reserve_exact (VEC_gimple_heap **vec_, int alloc_ ) { int extend = !VEC_gimple_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_heap *) vec_heap_p_reserve_exact (*vec_, alloc_ ); return extend; } static inline void VEC_gimple_heap_safe_grow (VEC_gimple_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_gimple_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_gimple_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_gimple_heap_safe_grow_cleared (VEC_gimple_heap **vec_, int size_ ) { int oldsize = VEC_gimple_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_gimple_heap_safe_grow (vec_, size_ ); memset (&(VEC_gimple_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (gimple) * (size_ - oldsize)); } static inline void VEC_gimple_heap_safe_splice (VEC_gimple_heap **dst_, VEC_gimple_base *src_ ) { if (src_) { VEC_gimple_heap_reserve_exact (dst_, src_->prefix.num ); VEC_gimple_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline gimple *VEC_gimple_heap_safe_push (VEC_gimple_heap **vec_, gimple obj_ ) { VEC_gimple_heap_reserve (vec_, 1 ); return VEC_gimple_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline gimple *VEC_gimple_heap_safe_insert (VEC_gimple_heap **vec_, unsigned ix_, gimple obj_ ) { VEC_gimple_heap_reserve (vec_, 1 ); return VEC_gimple_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
typedef struct VEC_gimple_gc { VEC_gimple_base base; } VEC_gimple_gc; static inline VEC_gimple_gc *VEC_gimple_gc_alloc (int alloc_ ) { return (VEC_gimple_gc *) vec_gc_p_reserve_exact (__null, alloc_ ); } static inline void VEC_gimple_gc_free (VEC_gimple_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = __null; } static inline VEC_gimple_gc *VEC_gimple_gc_copy (VEC_gimple_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_gimple_gc *new_vec_ = __null; if (len_) { new_vec_ = (VEC_gimple_gc *)(vec_gc_p_reserve_exact (__null, len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (gimple) * len_); } return new_vec_; } static inline int VEC_gimple_gc_reserve (VEC_gimple_gc **vec_, int alloc_ ) { int extend = !VEC_gimple_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_gc *) vec_gc_p_reserve (*vec_, alloc_ ); return extend; } static inline int VEC_gimple_gc_reserve_exact (VEC_gimple_gc **vec_, int alloc_ ) { int extend = !VEC_gimple_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_gc *) vec_gc_p_reserve_exact (*vec_, alloc_ ); return extend; } static inline void VEC_gimple_gc_safe_grow (VEC_gimple_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_gimple_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_gimple_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_gimple_gc_safe_grow_cleared (VEC_gimple_gc **vec_, int size_ ) { int oldsize = VEC_gimple_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_gimple_gc_safe_grow (vec_, size_ ); memset (&(VEC_gimple_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (gimple) * (size_ - oldsize)); } static inline void VEC_gimple_gc_safe_splice (VEC_gimple_gc **dst_, VEC_gimple_base *src_ ) { if (src_) { VEC_gimple_gc_reserve_exact (dst_, src_->prefix.num ); VEC_gimple_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline gimple *VEC_gimple_gc_safe_push (VEC_gimple_gc **vec_, gimple obj_ ) { VEC_gimple_gc_reserve (vec_, 1 ); return VEC_gimple_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline gimple *VEC_gimple_gc_safe_insert (VEC_gimple_gc **vec_, unsigned ix_, gimple obj_ ) { VEC_gimple_gc_reserve (vec_, 1 ); return VEC_gimple_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;


typedef gimple *gimple_p;
static inline void VEC_gimple_p_must_be_pointer_type (void) { (void)((gimple_p)1 == (void *)1); } typedef struct VEC_gimple_p_base { struct vec_prefix prefix; gimple_p vec[1]; } VEC_gimple_p_base; typedef struct VEC_gimple_p_none { VEC_gimple_p_base base; } VEC_gimple_p_none; static inline unsigned VEC_gimple_p_base_length (const VEC_gimple_p_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline gimple_p VEC_gimple_p_base_last (const VEC_gimple_p_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static inline gimple_p VEC_gimple_p_base_index (const VEC_gimple_p_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static inline int VEC_gimple_p_base_iterate (const VEC_gimple_p_base *vec_, unsigned ix_, gimple_p *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (gimple_p) 0; return 0; } } static inline size_t VEC_gimple_p_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_gimple_p_base, vec) + alloc_ * sizeof(gimple_p); } static inline void VEC_gimple_p_base_embedded_init (VEC_gimple_p_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_gimple_p_base_space (VEC_gimple_p_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_gimple_p_base_splice (VEC_gimple_p_base *dst_, VEC_gimple_p_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (gimple_p)); dst_->prefix.num += len_; } } static inline gimple_p *VEC_gimple_p_base_quick_push (VEC_gimple_p_base *vec_, gimple_p obj_ ) { gimple_p *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static inline gimple_p VEC_gimple_p_base_pop (VEC_gimple_p_base *vec_ ) { gimple_p obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_gimple_p_base_truncate (VEC_gimple_p_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline gimple_p VEC_gimple_p_base_replace (VEC_gimple_p_base *vec_, unsigned ix_, gimple_p obj_ ) { gimple_p old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static inline gimple_p *VEC_gimple_p_base_quick_insert (VEC_gimple_p_base *vec_, unsigned ix_, gimple_p obj_ ) { gimple_p *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (gimple_p)); *slot_ = obj_; return slot_; } static inline gimple_p VEC_gimple_p_base_ordered_remove (VEC_gimple_p_base *vec_, unsigned ix_ ) { gimple_p *slot_; gimple_p obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (gimple_p)); return obj_; } static inline gimple_p VEC_gimple_p_base_unordered_remove (VEC_gimple_p_base *vec_, unsigned ix_ ) { gimple_p *slot_; gimple_p obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_gimple_p_base_block_remove (VEC_gimple_p_base *vec_, unsigned ix_, unsigned len_ ) { gimple_p *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (gimple_p)); } static inline gimple_p *VEC_gimple_p_base_address (VEC_gimple_p_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_gimple_p_base_lower_bound (VEC_gimple_p_base *vec_, const gimple_p obj_, bool (*lessthan_)(const gimple_p, const gimple_p) ) { unsigned int len_ = VEC_gimple_p_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { gimple_p middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_gimple_p_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_gimple_p_heap { VEC_gimple_p_base base; } VEC_gimple_p_heap; static inline VEC_gimple_p_heap *VEC_gimple_p_heap_alloc (int alloc_ ) { return (VEC_gimple_p_heap *) vec_heap_p_reserve_exact (__null, alloc_ ); } static inline void VEC_gimple_p_heap_free (VEC_gimple_p_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = __null; } static inline VEC_gimple_p_heap *VEC_gimple_p_heap_copy (VEC_gimple_p_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_gimple_p_heap *new_vec_ = __null; if (len_) { new_vec_ = (VEC_gimple_p_heap *)(vec_heap_p_reserve_exact (__null, len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (gimple_p) * len_); } return new_vec_; } static inline int VEC_gimple_p_heap_reserve (VEC_gimple_p_heap **vec_, int alloc_ ) { int extend = !VEC_gimple_p_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_p_heap *) vec_heap_p_reserve (*vec_, alloc_ ); return extend; } static inline int VEC_gimple_p_heap_reserve_exact (VEC_gimple_p_heap **vec_, int alloc_ ) { int extend = !VEC_gimple_p_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_p_heap *) vec_heap_p_reserve_exact (*vec_, alloc_ ); return extend; } static inline void VEC_gimple_p_heap_safe_grow (VEC_gimple_p_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_gimple_p_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_gimple_p_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_gimple_p_heap_safe_grow_cleared (VEC_gimple_p_heap **vec_, int size_ ) { int oldsize = VEC_gimple_p_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_gimple_p_heap_safe_grow (vec_, size_ ); memset (&(VEC_gimple_p_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (gimple_p) * (size_ - oldsize)); } static inline void VEC_gimple_p_heap_safe_splice (VEC_gimple_p_heap **dst_, VEC_gimple_p_base *src_ ) { if (src_) { VEC_gimple_p_heap_reserve_exact (dst_, src_->prefix.num ); VEC_gimple_p_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline gimple_p *VEC_gimple_p_heap_safe_push (VEC_gimple_p_heap **vec_, gimple_p obj_ ) { VEC_gimple_p_heap_reserve (vec_, 1 ); return VEC_gimple_p_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline gimple_p *VEC_gimple_p_heap_safe_insert (VEC_gimple_p_heap **vec_, unsigned ix_, gimple_p obj_ ) { VEC_gimple_p_heap_reserve (vec_, 1 ); return VEC_gimple_p_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;


static inline void VEC_gimple_seq_must_be_pointer_type (void) { (void)((gimple_seq)1 == (void *)1); } typedef struct VEC_gimple_seq_base { struct vec_prefix prefix; gimple_seq vec[1]; } VEC_gimple_seq_base; typedef struct VEC_gimple_seq_none { VEC_gimple_seq_base base; } VEC_gimple_seq_none; static inline unsigned VEC_gimple_seq_base_length (const VEC_gimple_seq_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline gimple_seq VEC_gimple_seq_base_last (const VEC_gimple_seq_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static inline gimple_seq VEC_gimple_seq_base_index (const VEC_gimple_seq_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static inline int VEC_gimple_seq_base_iterate (const VEC_gimple_seq_base *vec_, unsigned ix_, gimple_seq *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (gimple_seq) 0; return 0; } } static inline size_t VEC_gimple_seq_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_gimple_seq_base, vec) + alloc_ * sizeof(gimple_seq); } static inline void VEC_gimple_seq_base_embedded_init (VEC_gimple_seq_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_gimple_seq_base_space (VEC_gimple_seq_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_gimple_seq_base_splice (VEC_gimple_seq_base *dst_, VEC_gimple_seq_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (gimple_seq)); dst_->prefix.num += len_; } } static inline gimple_seq *VEC_gimple_seq_base_quick_push (VEC_gimple_seq_base *vec_, gimple_seq obj_ ) { gimple_seq *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static inline gimple_seq VEC_gimple_seq_base_pop (VEC_gimple_seq_base *vec_ ) { gimple_seq obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_gimple_seq_base_truncate (VEC_gimple_seq_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline gimple_seq VEC_gimple_seq_base_replace (VEC_gimple_seq_base *vec_, unsigned ix_, gimple_seq obj_ ) { gimple_seq old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static inline gimple_seq *VEC_gimple_seq_base_quick_insert (VEC_gimple_seq_base *vec_, unsigned ix_, gimple_seq obj_ ) { gimple_seq *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (gimple_seq)); *slot_ = obj_; return slot_; } static inline gimple_seq VEC_gimple_seq_base_ordered_remove (VEC_gimple_seq_base *vec_, unsigned ix_ ) { gimple_seq *slot_; gimple_seq obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (gimple_seq)); return obj_; } static inline gimple_seq VEC_gimple_seq_base_unordered_remove (VEC_gimple_seq_base *vec_, unsigned ix_ ) { gimple_seq *slot_; gimple_seq obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_gimple_seq_base_block_remove (VEC_gimple_seq_base *vec_, unsigned ix_, unsigned len_ ) { gimple_seq *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (gimple_seq)); } static inline gimple_seq *VEC_gimple_seq_base_address (VEC_gimple_seq_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_gimple_seq_base_lower_bound (VEC_gimple_seq_base *vec_, const gimple_seq obj_, bool (*lessthan_)(const gimple_seq, const gimple_seq) ) { unsigned int len_ = VEC_gimple_seq_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { gimple_seq middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_gimple_seq_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_gimple_seq_gc { VEC_gimple_seq_base base; } VEC_gimple_seq_gc; static inline VEC_gimple_seq_gc *VEC_gimple_seq_gc_alloc (int alloc_ ) { return (VEC_gimple_seq_gc *) vec_gc_p_reserve_exact (__null, alloc_ ); } static inline void VEC_gimple_seq_gc_free (VEC_gimple_seq_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = __null; } static inline VEC_gimple_seq_gc *VEC_gimple_seq_gc_copy (VEC_gimple_seq_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_gimple_seq_gc *new_vec_ = __null; if (len_) { new_vec_ = (VEC_gimple_seq_gc *)(vec_gc_p_reserve_exact (__null, len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (gimple_seq) * len_); } return new_vec_; } static inline int VEC_gimple_seq_gc_reserve (VEC_gimple_seq_gc **vec_, int alloc_ ) { int extend = !VEC_gimple_seq_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_seq_gc *) vec_gc_p_reserve (*vec_, alloc_ ); return extend; } static inline int VEC_gimple_seq_gc_reserve_exact (VEC_gimple_seq_gc **vec_, int alloc_ ) { int extend = !VEC_gimple_seq_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_seq_gc *) vec_gc_p_reserve_exact (*vec_, alloc_ ); return extend; } static inline void VEC_gimple_seq_gc_safe_grow (VEC_gimple_seq_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_gimple_seq_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_gimple_seq_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_gimple_seq_gc_safe_grow_cleared (VEC_gimple_seq_gc **vec_, int size_ ) { int oldsize = VEC_gimple_seq_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_gimple_seq_gc_safe_grow (vec_, size_ ); memset (&(VEC_gimple_seq_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (gimple_seq) * (size_ - oldsize)); } static inline void VEC_gimple_seq_gc_safe_splice (VEC_gimple_seq_gc **dst_, VEC_gimple_seq_base *src_ ) { if (src_) { VEC_gimple_seq_gc_reserve_exact (dst_, src_->prefix.num ); VEC_gimple_seq_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline gimple_seq *VEC_gimple_seq_gc_safe_push (VEC_gimple_seq_gc **vec_, gimple_seq obj_ ) { VEC_gimple_seq_gc_reserve (vec_, 1 ); return VEC_gimple_seq_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline gimple_seq *VEC_gimple_seq_gc_safe_insert (VEC_gimple_seq_gc **vec_, unsigned ix_, gimple_seq obj_ ) { VEC_gimple_seq_gc_reserve (vec_, 1 ); return VEC_gimple_seq_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
typedef struct VEC_gimple_seq_heap { VEC_gimple_seq_base base; } VEC_gimple_seq_heap; static inline VEC_gimple_seq_heap *VEC_gimple_seq_heap_alloc (int alloc_ ) { return (VEC_gimple_seq_heap *) vec_heap_p_reserve_exact (__null, alloc_ ); } static inline void VEC_gimple_seq_heap_free (VEC_gimple_seq_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = __null; } static inline VEC_gimple_seq_heap *VEC_gimple_seq_heap_copy (VEC_gimple_seq_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_gimple_seq_heap *new_vec_ = __null; if (len_) { new_vec_ = (VEC_gimple_seq_heap *)(vec_heap_p_reserve_exact (__null, len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (gimple_seq) * len_); } return new_vec_; } static inline int VEC_gimple_seq_heap_reserve (VEC_gimple_seq_heap **vec_, int alloc_ ) { int extend = !VEC_gimple_seq_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_seq_heap *) vec_heap_p_reserve (*vec_, alloc_ ); return extend; } static inline int VEC_gimple_seq_heap_reserve_exact (VEC_gimple_seq_heap **vec_, int alloc_ ) { int extend = !VEC_gimple_seq_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_gimple_seq_heap *) vec_heap_p_reserve_exact (*vec_, alloc_ ); return extend; } static inline void VEC_gimple_seq_heap_safe_grow (VEC_gimple_seq_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_gimple_seq_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_gimple_seq_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_gimple_seq_heap_safe_grow_cleared (VEC_gimple_seq_heap **vec_, int size_ ) { int oldsize = VEC_gimple_seq_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_gimple_seq_heap_safe_grow (vec_, size_ ); memset (&(VEC_gimple_seq_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (gimple_seq) * (size_ - oldsize)); } static inline void VEC_gimple_seq_heap_safe_splice (VEC_gimple_seq_heap **dst_, VEC_gimple_seq_base *src_ ) { if (src_) { VEC_gimple_seq_heap_reserve_exact (dst_, src_->prefix.num ); VEC_gimple_seq_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline gimple_seq *VEC_gimple_seq_heap_safe_push (VEC_gimple_seq_heap **vec_, gimple_seq obj_ ) { VEC_gimple_seq_heap_reserve (vec_, 1 ); return VEC_gimple_seq_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline gimple_seq *VEC_gimple_seq_heap_safe_insert (VEC_gimple_seq_heap **vec_, unsigned ix_, gimple_seq obj_ ) { VEC_gimple_seq_heap_reserve (vec_, 1 ); return VEC_gimple_seq_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;


static inline void VEC_rtx_must_be_pointer_type (void) { (void)((rtx)1 == (void *)1); } typedef struct VEC_rtx_base { struct vec_prefix prefix; rtx vec[1]; } VEC_rtx_base; typedef struct VEC_rtx_none { VEC_rtx_base base; } VEC_rtx_none; static inline unsigned VEC_rtx_base_length (const VEC_rtx_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline rtx VEC_rtx_base_last (const VEC_rtx_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static inline rtx VEC_rtx_base_index (const VEC_rtx_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static inline int VEC_rtx_base_iterate (const VEC_rtx_base *vec_, unsigned ix_, rtx *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (rtx) 0; return 0; } } static inline size_t VEC_rtx_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_rtx_base, vec) + alloc_ * sizeof(rtx); } static inline void VEC_rtx_base_embedded_init (VEC_rtx_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_rtx_base_space (VEC_rtx_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_rtx_base_splice (VEC_rtx_base *dst_, VEC_rtx_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (rtx)); dst_->prefix.num += len_; } } static inline rtx *VEC_rtx_base_quick_push (VEC_rtx_base *vec_, rtx obj_ ) { rtx *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static inline rtx VEC_rtx_base_pop (VEC_rtx_base *vec_ ) { rtx obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_rtx_base_truncate (VEC_rtx_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline rtx VEC_rtx_base_replace (VEC_rtx_base *vec_, unsigned ix_, rtx obj_ ) { rtx old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static inline rtx *VEC_rtx_base_quick_insert (VEC_rtx_base *vec_, unsigned ix_, rtx obj_ ) { rtx *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (rtx)); *slot_ = obj_; return slot_; } static inline rtx VEC_rtx_base_ordered_remove (VEC_rtx_base *vec_, unsigned ix_ ) { rtx *slot_; rtx obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (rtx)); return obj_; } static inline rtx VEC_rtx_base_unordered_remove (VEC_rtx_base *vec_, unsigned ix_ ) { rtx *slot_; rtx obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_rtx_base_block_remove (VEC_rtx_base *vec_, unsigned ix_, unsigned len_ ) { rtx *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (rtx)); } static inline rtx *VEC_rtx_base_address (VEC_rtx_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_rtx_base_lower_bound (VEC_rtx_base *vec_, const rtx obj_, bool (*lessthan_)(const rtx, const rtx) ) { unsigned int len_ = VEC_rtx_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { rtx middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_rtx_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_rtx_heap { VEC_rtx_base base; } VEC_rtx_heap; static inline VEC_rtx_heap *VEC_rtx_heap_alloc (int alloc_ ) { return (VEC_rtx_heap *) vec_heap_p_reserve_exact (__null, alloc_ ); } static inline void VEC_rtx_heap_free (VEC_rtx_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = __null; } static inline VEC_rtx_heap *VEC_rtx_heap_copy (VEC_rtx_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_rtx_heap *new_vec_ = __null; if (len_) { new_vec_ = (VEC_rtx_heap *)(vec_heap_p_reserve_exact (__null, len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (rtx) * len_); } return new_vec_; } static inline int VEC_rtx_heap_reserve (VEC_rtx_heap **vec_, int alloc_ ) { int extend = !VEC_rtx_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_rtx_heap *) vec_heap_p_reserve (*vec_, alloc_ ); return extend; } static inline int VEC_rtx_heap_reserve_exact (VEC_rtx_heap **vec_, int alloc_ ) { int extend = !VEC_rtx_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_rtx_heap *) vec_heap_p_reserve_exact (*vec_, alloc_ ); return extend; } static inline void VEC_rtx_heap_safe_grow (VEC_rtx_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_rtx_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_rtx_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_rtx_heap_safe_grow_cleared (VEC_rtx_heap **vec_, int size_ ) { int oldsize = VEC_rtx_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_rtx_heap_safe_grow (vec_, size_ ); memset (&(VEC_rtx_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (rtx) * (size_ - oldsize)); } static inline void VEC_rtx_heap_safe_splice (VEC_rtx_heap **dst_, VEC_rtx_base *src_ ) { if (src_) { VEC_rtx_heap_reserve_exact (dst_, src_->prefix.num ); VEC_rtx_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline rtx *VEC_rtx_heap_safe_push (VEC_rtx_heap **vec_, rtx obj_ ) { VEC_rtx_heap_reserve (vec_, 1 ); return VEC_rtx_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline rtx *VEC_rtx_heap_safe_insert (VEC_rtx_heap **vec_, unsigned ix_, rtx obj_ ) { VEC_rtx_heap_reserve (vec_, 1 ); return VEC_rtx_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
typedef struct VEC_rtx_gc { VEC_rtx_base base; } VEC_rtx_gc; static inline VEC_rtx_gc *VEC_rtx_gc_alloc (int alloc_ ) { return (VEC_rtx_gc *) vec_gc_p_reserve_exact (__null, alloc_ ); } static inline void VEC_rtx_gc_free (VEC_rtx_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = __null; } static inline VEC_rtx_gc *VEC_rtx_gc_copy (VEC_rtx_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_rtx_gc *new_vec_ = __null; if (len_) { new_vec_ = (VEC_rtx_gc *)(vec_gc_p_reserve_exact (__null, len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (rtx) * len_); } return new_vec_; } static inline int VEC_rtx_gc_reserve (VEC_rtx_gc **vec_, int alloc_ ) { int extend = !VEC_rtx_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_rtx_gc *) vec_gc_p_reserve (*vec_, alloc_ ); return extend; } static inline int VEC_rtx_gc_reserve_exact (VEC_rtx_gc **vec_, int alloc_ ) { int extend = !VEC_rtx_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_rtx_gc *) vec_gc_p_reserve_exact (*vec_, alloc_ ); return extend; } static inline void VEC_rtx_gc_safe_grow (VEC_rtx_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_rtx_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_rtx_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_rtx_gc_safe_grow_cleared (VEC_rtx_gc **vec_, int size_ ) { int oldsize = VEC_rtx_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_rtx_gc_safe_grow (vec_, size_ ); memset (&(VEC_rtx_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (rtx) * (size_ - oldsize)); } static inline void VEC_rtx_gc_safe_splice (VEC_rtx_gc **dst_, VEC_rtx_base *src_ ) { if (src_) { VEC_rtx_gc_reserve_exact (dst_, src_->prefix.num ); VEC_rtx_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline rtx *VEC_rtx_gc_safe_push (VEC_rtx_gc **vec_, rtx obj_ ) { VEC_rtx_gc_reserve (vec_, 1 ); return VEC_rtx_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline rtx *VEC_rtx_gc_safe_insert (VEC_rtx_gc **vec_, unsigned ix_, rtx obj_ ) { VEC_rtx_gc_reserve (vec_, 1 ); return VEC_rtx_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
# 31 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/double-int.h" 1
# 24 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/double-int.h"
# 1 "/usr/include/gmp.h" 1 3 4
# 43 "/usr/include/gmp.h" 3 4
# 1 "./include/gmp-i386.h" 1 3 4
# 24 "./include/gmp-i386.h" 3 4
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/iosfwd" 1 3 4
# 38 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/iosfwd" 3 4
       
# 39 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/iosfwd" 3


# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/bits/stringfwd.h" 1 3
# 39 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/bits/stringfwd.h" 3
       
# 40 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/bits/stringfwd.h" 3



namespace std __attribute__ ((__visibility__ ("default")))
{


  template<typename _Alloc>
    class allocator;







  template<class _CharT>
    struct char_traits;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
           typename _Alloc = allocator<_CharT> >
    class basic_string;

  template<> struct char_traits<char>;

  typedef basic_string<char> string;


  template<> struct char_traits<wchar_t>;

  typedef basic_string<wchar_t> wstring;
# 85 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/bits/stringfwd.h" 3

}
# 42 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/iosfwd" 2 3
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/bits/postypes.h" 1 3
# 40 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/bits/postypes.h" 3
       
# 41 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/bits/postypes.h" 3

# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cwchar" 1 3
# 41 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cwchar" 3
       
# 42 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cwchar" 3




# 1 "/usr/include/wchar.h" 1 3 4
# 52 "/usr/include/wchar.h" 3 4
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 1 3 4
# 354 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 3 4
typedef unsigned int wint_t;
# 53 "/usr/include/wchar.h" 2 3 4
# 104 "/usr/include/wchar.h" 3 4


typedef __mbstate_t mbstate_t;



# 129 "/usr/include/wchar.h" 3 4
extern "C" {




struct tm;









extern wchar_t *wcscpy (wchar_t *__restrict __dest,
   __const wchar_t *__restrict __src) throw ();

extern wchar_t *wcsncpy (wchar_t *__restrict __dest,
    __const wchar_t *__restrict __src, size_t __n)
     throw ();


extern wchar_t *wcscat (wchar_t *__restrict __dest,
   __const wchar_t *__restrict __src) throw ();

extern wchar_t *wcsncat (wchar_t *__restrict __dest,
    __const wchar_t *__restrict __src, size_t __n)
     throw ();


extern int wcscmp (__const wchar_t *__s1, __const wchar_t *__s2)
     throw () __attribute__ ((__pure__));

extern int wcsncmp (__const wchar_t *__s1, __const wchar_t *__s2, size_t __n)
     throw () __attribute__ ((__pure__));




extern int wcscasecmp (__const wchar_t *__s1, __const wchar_t *__s2) throw ();


extern int wcsncasecmp (__const wchar_t *__s1, __const wchar_t *__s2,
   size_t __n) throw ();





extern int wcscasecmp_l (__const wchar_t *__s1, __const wchar_t *__s2,
    __locale_t __loc) throw ();

extern int wcsncasecmp_l (__const wchar_t *__s1, __const wchar_t *__s2,
     size_t __n, __locale_t __loc) throw ();





extern int wcscoll (__const wchar_t *__s1, __const wchar_t *__s2) throw ();



extern size_t wcsxfrm (wchar_t *__restrict __s1,
         __const wchar_t *__restrict __s2, size_t __n) throw ();








extern int wcscoll_l (__const wchar_t *__s1, __const wchar_t *__s2,
        __locale_t __loc) throw ();




extern size_t wcsxfrm_l (wchar_t *__s1, __const wchar_t *__s2,
    size_t __n, __locale_t __loc) throw ();


extern wchar_t *wcsdup (__const wchar_t *__s) throw () __attribute__ ((__malloc__));





extern "C++" wchar_t *wcschr (wchar_t *__wcs, wchar_t __wc)
     throw () __asm ("wcschr") __attribute__ ((__pure__));
extern "C++" __const wchar_t *wcschr (__const wchar_t *__wcs, wchar_t __wc)
     throw () __asm ("wcschr") __attribute__ ((__pure__));






extern "C++" wchar_t *wcsrchr (wchar_t *__wcs, wchar_t __wc)
     throw () __asm ("wcsrchr") __attribute__ ((__pure__));
extern "C++" __const wchar_t *wcsrchr (__const wchar_t *__wcs, wchar_t __wc)
     throw () __asm ("wcsrchr") __attribute__ ((__pure__));









extern wchar_t *wcschrnul (__const wchar_t *__s, wchar_t __wc)
     throw () __attribute__ ((__pure__));





extern size_t wcscspn (__const wchar_t *__wcs, __const wchar_t *__reject)
     throw () __attribute__ ((__pure__));


extern size_t wcsspn (__const wchar_t *__wcs, __const wchar_t *__accept)
     throw () __attribute__ ((__pure__));


extern "C++" wchar_t *wcspbrk (wchar_t *__wcs, __const wchar_t *__accept)
     throw () __asm ("wcspbrk") __attribute__ ((__pure__));
extern "C++" __const wchar_t *wcspbrk (__const wchar_t *__wcs,
           __const wchar_t *__accept)
     throw () __asm ("wcspbrk") __attribute__ ((__pure__));






extern "C++" wchar_t *wcsstr (wchar_t *__haystack, __const wchar_t *__needle)
     throw () __asm ("wcsstr") __attribute__ ((__pure__));
extern "C++" __const wchar_t *wcsstr (__const wchar_t *__haystack,
          __const wchar_t *__needle)
     throw () __asm ("wcsstr") __attribute__ ((__pure__));






extern wchar_t *wcstok (wchar_t *__restrict __s,
   __const wchar_t *__restrict __delim,
   wchar_t **__restrict __ptr) throw ();


extern size_t wcslen (__const wchar_t *__s) throw () __attribute__ ((__pure__));





extern "C++" wchar_t *wcswcs (wchar_t *__haystack, __const wchar_t *__needle)
     throw () __asm ("wcswcs") __attribute__ ((__pure__));
extern "C++" __const wchar_t *wcswcs (__const wchar_t *__haystack,
          __const wchar_t *__needle)
     throw () __asm ("wcswcs") __attribute__ ((__pure__));
# 303 "/usr/include/wchar.h" 3 4
extern size_t wcsnlen (__const wchar_t *__s, size_t __maxlen)
     throw () __attribute__ ((__pure__));






extern "C++" wchar_t *wmemchr (wchar_t *__s, wchar_t __c, size_t __n)
     throw () __asm ("wmemchr") __attribute__ ((__pure__));
extern "C++" __const wchar_t *wmemchr (__const wchar_t *__s, wchar_t __c,
           size_t __n)
     throw () __asm ("wmemchr") __attribute__ ((__pure__));






extern int wmemcmp (__const wchar_t *__restrict __s1,
      __const wchar_t *__restrict __s2, size_t __n)
     throw () __attribute__ ((__pure__));


extern wchar_t *wmemcpy (wchar_t *__restrict __s1,
    __const wchar_t *__restrict __s2, size_t __n) throw ();



extern wchar_t *wmemmove (wchar_t *__s1, __const wchar_t *__s2, size_t __n)
     throw ();


extern wchar_t *wmemset (wchar_t *__s, wchar_t __c, size_t __n) throw ();





extern wchar_t *wmempcpy (wchar_t *__restrict __s1,
     __const wchar_t *__restrict __s2, size_t __n)
     throw ();






extern wint_t btowc (int __c) throw ();



extern int wctob (wint_t __c) throw ();



extern int mbsinit (__const mbstate_t *__ps) throw () __attribute__ ((__pure__));



extern size_t mbrtowc (wchar_t *__restrict __pwc,
         __const char *__restrict __s, size_t __n,
         mbstate_t *__p) throw ();


extern size_t wcrtomb (char *__restrict __s, wchar_t __wc,
         mbstate_t *__restrict __ps) throw ();


extern size_t __mbrlen (__const char *__restrict __s, size_t __n,
   mbstate_t *__restrict __ps) throw ();
extern size_t mbrlen (__const char *__restrict __s, size_t __n,
        mbstate_t *__restrict __ps) throw ();








extern wint_t __btowc_alias (int __c) __asm ("btowc");
extern __inline __attribute__ ((__gnu_inline__)) wint_t
btowc (int __c) throw ()
{ return (__builtin_constant_p (__c) && __c >= '\0' && __c <= '\x7f'
   ? (wint_t) __c : __btowc_alias (__c)); }

extern int __wctob_alias (wint_t __c) __asm ("wctob");
extern __inline __attribute__ ((__gnu_inline__)) int
wctob (wint_t __wc) throw ()
{ return (__builtin_constant_p (__wc) && __wc >= L'\0' && __wc <= L'\x7f'
   ? (int) __wc : __wctob_alias (__wc)); }

extern __inline __attribute__ ((__gnu_inline__)) size_t
mbrlen (__const char *__restrict __s, size_t __n, mbstate_t *__restrict __ps) throw ()

{ return (__ps != __null
   ? mbrtowc (__null, __s, __n, __ps) : __mbrlen (__s, __n, __null)); }





extern size_t mbsrtowcs (wchar_t *__restrict __dst,
    __const char **__restrict __src, size_t __len,
    mbstate_t *__restrict __ps) throw ();



extern size_t wcsrtombs (char *__restrict __dst,
    __const wchar_t **__restrict __src, size_t __len,
    mbstate_t *__restrict __ps) throw ();






extern size_t mbsnrtowcs (wchar_t *__restrict __dst,
     __const char **__restrict __src, size_t __nmc,
     size_t __len, mbstate_t *__restrict __ps) throw ();



extern size_t wcsnrtombs (char *__restrict __dst,
     __const wchar_t **__restrict __src,
     size_t __nwc, size_t __len,
     mbstate_t *__restrict __ps) throw ();






extern int wcwidth (wchar_t __c) throw ();



extern int wcswidth (__const wchar_t *__s, size_t __n) throw ();






extern double wcstod (__const wchar_t *__restrict __nptr,
        wchar_t **__restrict __endptr) throw ();





extern float wcstof (__const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) throw ();
extern long double wcstold (__const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) throw ();







extern long int wcstol (__const wchar_t *__restrict __nptr,
   wchar_t **__restrict __endptr, int __base) throw ();



extern unsigned long int wcstoul (__const wchar_t *__restrict __nptr,
      wchar_t **__restrict __endptr, int __base)
     throw ();






__extension__
extern long long int wcstoll (__const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr, int __base)
     throw ();



__extension__
extern unsigned long long int wcstoull (__const wchar_t *__restrict __nptr,
     wchar_t **__restrict __endptr,
     int __base) throw ();






__extension__
extern long long int wcstoq (__const wchar_t *__restrict __nptr,
        wchar_t **__restrict __endptr, int __base)
     throw ();



__extension__
extern unsigned long long int wcstouq (__const wchar_t *__restrict __nptr,
           wchar_t **__restrict __endptr,
           int __base) throw ();
# 528 "/usr/include/wchar.h" 3 4
extern long int wcstol_l (__const wchar_t *__restrict __nptr,
     wchar_t **__restrict __endptr, int __base,
     __locale_t __loc) throw ();

extern unsigned long int wcstoul_l (__const wchar_t *__restrict __nptr,
        wchar_t **__restrict __endptr,
        int __base, __locale_t __loc) throw ();

__extension__
extern long long int wcstoll_l (__const wchar_t *__restrict __nptr,
    wchar_t **__restrict __endptr,
    int __base, __locale_t __loc) throw ();

__extension__
extern unsigned long long int wcstoull_l (__const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr,
       int __base, __locale_t __loc)
     throw ();

extern double wcstod_l (__const wchar_t *__restrict __nptr,
   wchar_t **__restrict __endptr, __locale_t __loc)
     throw ();

extern float wcstof_l (__const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr, __locale_t __loc)
     throw ();

extern long double wcstold_l (__const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr,
         __locale_t __loc) throw ();






extern wchar_t *wcpcpy (wchar_t *__dest, __const wchar_t *__src) throw ();



extern wchar_t *wcpncpy (wchar_t *__dest, __const wchar_t *__src, size_t __n)
     throw ();
# 578 "/usr/include/wchar.h" 3 4
extern __FILE *open_wmemstream (wchar_t **__bufloc, size_t *__sizeloc) throw ();






extern int fwide (__FILE *__fp, int __mode) throw ();






extern int fwprintf (__FILE *__restrict __stream,
       __const wchar_t *__restrict __format, ...)
                                                           ;




extern int wprintf (__const wchar_t *__restrict __format, ...)
                                                           ;

extern int swprintf (wchar_t *__restrict __s, size_t __n,
       __const wchar_t *__restrict __format, ...)
     throw () ;





extern int vfwprintf (__FILE *__restrict __s,
        __const wchar_t *__restrict __format,
        __gnuc_va_list __arg)
                                                           ;




extern int vwprintf (__const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
                                                           ;


extern int vswprintf (wchar_t *__restrict __s, size_t __n,
        __const wchar_t *__restrict __format,
        __gnuc_va_list __arg)
     throw () ;






extern int fwscanf (__FILE *__restrict __stream,
      __const wchar_t *__restrict __format, ...)
                                                          ;




extern int wscanf (__const wchar_t *__restrict __format, ...)
                                                          ;

extern int swscanf (__const wchar_t *__restrict __s,
      __const wchar_t *__restrict __format, ...)
     throw () ;
# 678 "/usr/include/wchar.h" 3 4









extern int vfwscanf (__FILE *__restrict __s,
       __const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
                                                          ;




extern int vwscanf (__const wchar_t *__restrict __format,
      __gnuc_va_list __arg)
                                                          ;

extern int vswscanf (__const wchar_t *__restrict __s,
       __const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
     throw () ;
# 734 "/usr/include/wchar.h" 3 4









extern wint_t fgetwc (__FILE *__stream);
extern wint_t getwc (__FILE *__stream);





extern wint_t getwchar (void);






extern wint_t fputwc (wchar_t __wc, __FILE *__stream);
extern wint_t putwc (wchar_t __wc, __FILE *__stream);





extern wint_t putwchar (wchar_t __wc);







extern wchar_t *fgetws (wchar_t *__restrict __ws, int __n,
   __FILE *__restrict __stream);





extern int fputws (__const wchar_t *__restrict __ws,
     __FILE *__restrict __stream);






extern wint_t ungetwc (wint_t __wc, __FILE *__stream);

# 799 "/usr/include/wchar.h" 3 4
extern wint_t getwc_unlocked (__FILE *__stream);
extern wint_t getwchar_unlocked (void);







extern wint_t fgetwc_unlocked (__FILE *__stream);







extern wint_t fputwc_unlocked (wchar_t __wc, __FILE *__stream);
# 825 "/usr/include/wchar.h" 3 4
extern wint_t putwc_unlocked (wchar_t __wc, __FILE *__stream);
extern wint_t putwchar_unlocked (wchar_t __wc);
# 835 "/usr/include/wchar.h" 3 4
extern wchar_t *fgetws_unlocked (wchar_t *__restrict __ws, int __n,
     __FILE *__restrict __stream);







extern int fputws_unlocked (__const wchar_t *__restrict __ws,
       __FILE *__restrict __stream);







extern size_t wcsftime (wchar_t *__restrict __s, size_t __maxsize,
   __const wchar_t *__restrict __format,
   __const struct tm *__restrict __tp) throw ();







extern size_t wcsftime_l (wchar_t *__restrict __s, size_t __maxsize,
     __const wchar_t *__restrict __format,
     __const struct tm *__restrict __tp,
     __locale_t __loc) throw ();
# 889 "/usr/include/wchar.h" 3 4
}
# 47 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cwchar" 2 3
# 64 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cwchar" 3
namespace std
{
  using ::mbstate_t;
}
# 137 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cwchar" 3
namespace std __attribute__ ((__visibility__ ("default")))
{


  using ::wint_t;

  using ::btowc;
  using ::fgetwc;
  using ::fgetws;
  using ::fputwc;
  using ::fputws;
  using ::fwide;
  using ::fwprintf;
  using ::fwscanf;
  using ::getwc;
  using ::getwchar;
  using ::mbrlen;
  using ::mbrtowc;
  using ::mbsinit;
  using ::mbsrtowcs;
  using ::putwc;
  using ::putwchar;

  using ::swprintf;

  using ::swscanf;
  using ::ungetwc;
  using ::vfwprintf;

  using ::vfwscanf;


  using ::vswprintf;


  using ::vswscanf;

  using ::vwprintf;

  using ::vwscanf;

  using ::wcrtomb;
  using ::wcscat;
  using ::wcscmp;
  using ::wcscoll;
  using ::wcscpy;
  using ::wcscspn;
  using ::wcsftime;
  using ::wcslen;
  using ::wcsncat;
  using ::wcsncmp;
  using ::wcsncpy;
  using ::wcsrtombs;
  using ::wcsspn;
  using ::wcstod;

  using ::wcstof;

  using ::wcstok;
  using ::wcstol;
  using ::wcstoul;
  using ::wcsxfrm;
  using ::wctob;
  using ::wmemcmp;
  using ::wmemcpy;
  using ::wmemmove;
  using ::wmemset;
  using ::wprintf;
  using ::wscanf;
  using ::wcschr;
  using ::wcspbrk;
  using ::wcsrchr;
  using ::wcsstr;
  using ::wmemchr;
# 234 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cwchar" 3

}







namespace __gnu_cxx
{





  using ::wcstold;
# 259 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cwchar" 3
  using ::wcstoll;
  using ::wcstoull;

}

namespace std
{
  using ::__gnu_cxx::wcstold;
  using ::__gnu_cxx::wcstoll;
  using ::__gnu_cxx::wcstoull;
}
# 43 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/bits/postypes.h" 2 3
# 70 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/bits/postypes.h" 3
namespace std __attribute__ ((__visibility__ ("default")))
{

# 92 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/bits/postypes.h" 3
  typedef long long streamoff;







  typedef ptrdiff_t streamsize;
# 113 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/bits/postypes.h" 3
  template<typename _StateT>
    class fpos
    {
    private:
      streamoff _M_off;
      _StateT _M_state;

    public:




      fpos()
      : _M_off(0), _M_state() { }
# 135 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/bits/postypes.h" 3
      fpos(streamoff __off)
      : _M_off(__off), _M_state() { }


      operator streamoff() const { return _M_off; }


      void
      state(_StateT __st)
      { _M_state = __st; }


      _StateT
      state() const
      { return _M_state; }





      fpos&
      operator+=(streamoff __off)
      {
 _M_off += __off;
 return *this;
      }





      fpos&
      operator-=(streamoff __off)
      {
 _M_off -= __off;
 return *this;
      }







      fpos
      operator+(streamoff __off) const
      {
 fpos __pos(*this);
 __pos += __off;
 return __pos;
      }







      fpos
      operator-(streamoff __off) const
      {
 fpos __pos(*this);
 __pos -= __off;
 return __pos;
      }






      streamoff
      operator-(const fpos& __other) const
      { return _M_off - __other._M_off; }
    };






  template<typename _StateT>
    inline bool
    operator==(const fpos<_StateT>& __lhs, const fpos<_StateT>& __rhs)
    { return streamoff(__lhs) == streamoff(__rhs); }

  template<typename _StateT>
    inline bool
    operator!=(const fpos<_StateT>& __lhs, const fpos<_StateT>& __rhs)
    { return streamoff(__lhs) != streamoff(__rhs); }





  typedef fpos<mbstate_t> streampos;

  typedef fpos<mbstate_t> wstreampos;
# 241 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/bits/postypes.h" 3

}
# 43 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/iosfwd" 2 3

namespace std __attribute__ ((__visibility__ ("default")))
{

# 76 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/iosfwd" 3
  class ios_base;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ios;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_streambuf;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_istream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ostream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_iostream;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
     typename _Alloc = allocator<_CharT> >
    class basic_stringbuf;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
    typename _Alloc = allocator<_CharT> >
    class basic_istringstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
    typename _Alloc = allocator<_CharT> >
    class basic_ostringstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
    typename _Alloc = allocator<_CharT> >
    class basic_stringstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_filebuf;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ifstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ofstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_fstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class istreambuf_iterator;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class ostreambuf_iterator;



  typedef basic_ios<char> ios;


  typedef basic_streambuf<char> streambuf;


  typedef basic_istream<char> istream;


  typedef basic_ostream<char> ostream;


  typedef basic_iostream<char> iostream;


  typedef basic_stringbuf<char> stringbuf;


  typedef basic_istringstream<char> istringstream;


  typedef basic_ostringstream<char> ostringstream;


  typedef basic_stringstream<char> stringstream;


  typedef basic_filebuf<char> filebuf;


  typedef basic_ifstream<char> ifstream;


  typedef basic_ofstream<char> ofstream;


  typedef basic_fstream<char> fstream;



  typedef basic_ios<wchar_t> wios;


  typedef basic_streambuf<wchar_t> wstreambuf;


  typedef basic_istream<wchar_t> wistream;


  typedef basic_ostream<wchar_t> wostream;


  typedef basic_iostream<wchar_t> wiostream;


  typedef basic_stringbuf<wchar_t> wstringbuf;


  typedef basic_istringstream<wchar_t> wistringstream;


  typedef basic_ostringstream<wchar_t> wostringstream;


  typedef basic_stringstream<wchar_t> wstringstream;


  typedef basic_filebuf<wchar_t> wfilebuf;


  typedef basic_ifstream<wchar_t> wifstream;


  typedef basic_ofstream<wchar_t> wofstream;


  typedef basic_fstream<wchar_t> wfstream;




}
# 25 "./include/gmp-i386.h" 2 3 4
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cstdio" 1 3 4
# 41 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cstdio" 3 4
       
# 42 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cstdio" 3
# 95 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cstdio" 3
namespace std
{
  using ::FILE;
  using ::fpos_t;

  using ::clearerr;
  using ::fclose;
  using ::feof;
  using ::ferror;
  using ::fflush;
  using ::fgetc;
  using ::fgetpos;
  using ::fgets;
  using ::fopen;
  using ::fprintf;
  using ::fputc;
  using ::fputs;
  using ::fread;
  using ::freopen;
  using ::fscanf;
  using ::fseek;
  using ::fsetpos;
  using ::ftell;
  using ::fwrite;
  using ::getc;
  using ::getchar;
  using ::gets;
  using ::perror;
  using ::printf;
  using ::putc;
  using ::putchar;
  using ::puts;
  using ::remove;
  using ::rename;
  using ::rewind;
  using ::scanf;
  using ::setbuf;
  using ::setvbuf;
  using ::sprintf;
  using ::sscanf;
  using ::tmpfile;
  using ::tmpnam;
  using ::ungetc;
  using ::vfprintf;
  using ::vprintf;
  using ::vsprintf;
}
# 151 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cstdio" 3
namespace __gnu_cxx
{
# 169 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cstdio" 3
  using ::snprintf;
  using ::vfscanf;
  using ::vscanf;
  using ::vsnprintf;
  using ::vsscanf;

}

namespace std
{
  using ::__gnu_cxx::snprintf;
  using ::__gnu_cxx::vfscanf;
  using ::__gnu_cxx::vscanf;
  using ::__gnu_cxx::vsnprintf;
  using ::__gnu_cxx::vsscanf;
}
# 26 "./include/gmp-i386.h" 2 3 4
# 51 "./include/gmp-i386.h" 3 4
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cstddef" 1 3 4
# 41 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cstddef" 3 4
       
# 42 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cstddef" 3


# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h" 1 3 4
# 44 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/../../../../include/c++/4.7.1/cstddef" 2 3
# 52 "./include/gmp-i386.h" 2 3 4
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
# 537 "./include/gmp-i386.h" 3 4
extern "C" {
using std::FILE;



 void __gmp_set_memory_functions (void *(*) (size_t), void *(*) (void *, size_t, size_t), void (*) (void *, size_t))

                                      throw ();


 void __gmp_get_memory_functions (void *(**) (size_t), void *(**) (void *, size_t, size_t), void (**) (void *, size_t))

                                                                   throw ();


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


 int __gmpz_cmp (mpz_srcptr, mpz_srcptr) throw () __attribute__ ((__pure__));


 int __gmpz_cmp_d (mpz_srcptr, double) __attribute__ ((__pure__));


 int __gmpz_cmp_si (mpz_srcptr, signed long int) throw () __attribute__ ((__pure__));


 int __gmpz_cmp_ui (mpz_srcptr, unsigned long int) throw () __attribute__ ((__pure__));


 int __gmpz_cmpabs (mpz_srcptr, mpz_srcptr) throw () __attribute__ ((__pure__));


 int __gmpz_cmpabs_d (mpz_srcptr, double) __attribute__ ((__pure__));


 int __gmpz_cmpabs_ui (mpz_srcptr, unsigned long int) throw () __attribute__ ((__pure__));


 void __gmpz_com (mpz_ptr, mpz_srcptr);


 void __gmpz_combit (mpz_ptr, unsigned long int);


 int __gmpz_congruent_p (mpz_srcptr, mpz_srcptr, mpz_srcptr) __attribute__ ((__pure__));


 int __gmpz_congruent_2exp_p (mpz_srcptr, mpz_srcptr, unsigned long) throw () __attribute__ ((__pure__));


 int __gmpz_congruent_ui_p (mpz_srcptr, unsigned long, unsigned long) __attribute__ ((__pure__));


 void __gmpz_divexact (mpz_ptr, mpz_srcptr, mpz_srcptr);


 void __gmpz_divexact_ui (mpz_ptr, mpz_srcptr, unsigned long);


 int __gmpz_divisible_p (mpz_srcptr, mpz_srcptr) __attribute__ ((__pure__));


 int __gmpz_divisible_ui_p (mpz_srcptr, unsigned long) __attribute__ ((__pure__));


 int __gmpz_divisible_2exp_p (mpz_srcptr, unsigned long) throw () __attribute__ ((__pure__));


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


 int __gmpz_fits_sint_p (mpz_srcptr) throw () __attribute__ ((__pure__));


 int __gmpz_fits_slong_p (mpz_srcptr) throw () __attribute__ ((__pure__));


 int __gmpz_fits_sshort_p (mpz_srcptr) throw () __attribute__ ((__pure__));



 int __gmpz_fits_uint_p (mpz_srcptr) throw () __attribute__ ((__pure__));




 int __gmpz_fits_ulong_p (mpz_srcptr) throw () __attribute__ ((__pure__));




 int __gmpz_fits_ushort_p (mpz_srcptr) throw () __attribute__ ((__pure__));



 void __gmpz_gcd (mpz_ptr, mpz_srcptr, mpz_srcptr);


 unsigned long int __gmpz_gcd_ui (mpz_ptr, mpz_srcptr, unsigned long int);


 void __gmpz_gcdext (mpz_ptr, mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr);


 double __gmpz_get_d (mpz_srcptr) __attribute__ ((__pure__));


 double __gmpz_get_d_2exp (signed long int *, mpz_srcptr);


 long int __gmpz_get_si (mpz_srcptr) throw () __attribute__ ((__pure__));


 char *__gmpz_get_str (char *, int, mpz_srcptr);



 unsigned long int __gmpz_get_ui (mpz_srcptr) throw () __attribute__ ((__pure__));




 mp_limb_t __gmpz_getlimbn (mpz_srcptr, mp_size_t) throw () __attribute__ ((__pure__));



 unsigned long int __gmpz_hamdist (mpz_srcptr, mpz_srcptr) throw () __attribute__ ((__pure__));


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




 unsigned long int __gmpz_popcount (mpz_srcptr) throw () __attribute__ ((__pure__));



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


 unsigned long int __gmpz_scan0 (mpz_srcptr, unsigned long int) throw () __attribute__ ((__pure__));


 unsigned long int __gmpz_scan1 (mpz_srcptr, unsigned long int) throw () __attribute__ ((__pure__));


 void __gmpz_set (mpz_ptr, mpz_srcptr);


 void __gmpz_set_d (mpz_ptr, double);


 void __gmpz_set_f (mpz_ptr, mpf_srcptr);



 void __gmpz_set_q (mpz_ptr, mpq_srcptr);



 void __gmpz_set_si (mpz_ptr, signed long int);


 int __gmpz_set_str (mpz_ptr, const char *, int);


 void __gmpz_set_ui (mpz_ptr, unsigned long int);


 void __gmpz_setbit (mpz_ptr, unsigned long int);



 size_t __gmpz_size (mpz_srcptr) throw () __attribute__ ((__pure__));



 size_t __gmpz_sizeinbase (mpz_srcptr, int) throw () __attribute__ ((__pure__));


 void __gmpz_sqrt (mpz_ptr, mpz_srcptr);


 void __gmpz_sqrtrem (mpz_ptr, mpz_ptr, mpz_srcptr);


 void __gmpz_sub (mpz_ptr, mpz_srcptr, mpz_srcptr);


 void __gmpz_sub_ui (mpz_ptr, mpz_srcptr, unsigned long int);


 void __gmpz_ui_sub (mpz_ptr, unsigned long int, mpz_srcptr);


 void __gmpz_submul (mpz_ptr, mpz_srcptr, mpz_srcptr);


 void __gmpz_submul_ui (mpz_ptr, mpz_srcptr, unsigned long int);


 void __gmpz_swap (mpz_ptr, mpz_ptr) throw ();


 unsigned long int __gmpz_tdiv_ui (mpz_srcptr, unsigned long int) __attribute__ ((__pure__));


 void __gmpz_tdiv_q (mpz_ptr, mpz_srcptr, mpz_srcptr);


 void __gmpz_tdiv_q_2exp (mpz_ptr, mpz_srcptr, unsigned long int);


 unsigned long int __gmpz_tdiv_q_ui (mpz_ptr, mpz_srcptr, unsigned long int);


 void __gmpz_tdiv_qr (mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr);


 unsigned long int __gmpz_tdiv_qr_ui (mpz_ptr, mpz_ptr, mpz_srcptr, unsigned long int);


 void __gmpz_tdiv_r (mpz_ptr, mpz_srcptr, mpz_srcptr);


 void __gmpz_tdiv_r_2exp (mpz_ptr, mpz_srcptr, unsigned long int);


 unsigned long int __gmpz_tdiv_r_ui (mpz_ptr, mpz_srcptr, unsigned long int);


 int __gmpz_tstbit (mpz_srcptr, unsigned long int) throw () __attribute__ ((__pure__));


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


 int __gmpq_equal (mpq_srcptr, mpq_srcptr) throw () __attribute__ ((__pure__));


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


 void __gmpq_swap (mpq_ptr, mpq_ptr) throw ();





 void __gmpf_abs (mpf_ptr, mpf_srcptr);


 void __gmpf_add (mpf_ptr, mpf_srcptr, mpf_srcptr);


 void __gmpf_add_ui (mpf_ptr, mpf_srcptr, unsigned long int);

 void __gmpf_ceil (mpf_ptr, mpf_srcptr);


 void __gmpf_clear (mpf_ptr);


 int __gmpf_cmp (mpf_srcptr, mpf_srcptr) throw () __attribute__ ((__pure__));


 int __gmpf_cmp_d (mpf_srcptr, double) __attribute__ ((__pure__));


 int __gmpf_cmp_si (mpf_srcptr, signed long int) throw () __attribute__ ((__pure__));


 int __gmpf_cmp_ui (mpf_srcptr, unsigned long int) throw () __attribute__ ((__pure__));


 void __gmpf_div (mpf_ptr, mpf_srcptr, mpf_srcptr);


 void __gmpf_div_2exp (mpf_ptr, mpf_srcptr, unsigned long int);


 void __gmpf_div_ui (mpf_ptr, mpf_srcptr, unsigned long int);


 void __gmpf_dump (mpf_srcptr);


 int __gmpf_eq (mpf_srcptr, mpf_srcptr, unsigned long int) __attribute__ ((__pure__));


 int __gmpf_fits_sint_p (mpf_srcptr) throw () __attribute__ ((__pure__));


 int __gmpf_fits_slong_p (mpf_srcptr) throw () __attribute__ ((__pure__));


 int __gmpf_fits_sshort_p (mpf_srcptr) throw () __attribute__ ((__pure__));


 int __gmpf_fits_uint_p (mpf_srcptr) throw () __attribute__ ((__pure__));


 int __gmpf_fits_ulong_p (mpf_srcptr) throw () __attribute__ ((__pure__));


 int __gmpf_fits_ushort_p (mpf_srcptr) throw () __attribute__ ((__pure__));


 void __gmpf_floor (mpf_ptr, mpf_srcptr);


 double __gmpf_get_d (mpf_srcptr) __attribute__ ((__pure__));


 double __gmpf_get_d_2exp (signed long int *, mpf_srcptr);


 unsigned long int __gmpf_get_default_prec (void) throw () __attribute__ ((__pure__));


 unsigned long int __gmpf_get_prec (mpf_srcptr) throw () __attribute__ ((__pure__));


 long __gmpf_get_si (mpf_srcptr) throw () __attribute__ ((__pure__));


 char *__gmpf_get_str (char *, mp_exp_t *, int, size_t, mpf_srcptr);


 unsigned long __gmpf_get_ui (mpf_srcptr) throw () __attribute__ ((__pure__));


 void __gmpf_init (mpf_ptr);


 void __gmpf_init2 (mpf_ptr, unsigned long int);


 void __gmpf_init_set (mpf_ptr, mpf_srcptr);


 void __gmpf_init_set_d (mpf_ptr, double);


 void __gmpf_init_set_si (mpf_ptr, signed long int);


 int __gmpf_init_set_str (mpf_ptr, const char *, int);


 void __gmpf_init_set_ui (mpf_ptr, unsigned long int);



 size_t __gmpf_inp_str (mpf_ptr, FILE *, int);



 int __gmpf_integer_p (mpf_srcptr) throw () __attribute__ ((__pure__));


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


 void __gmpf_set_default_prec (unsigned long int) throw ();


 void __gmpf_set_prec (mpf_ptr, unsigned long int);


 void __gmpf_set_prec_raw (mpf_ptr, unsigned long int) throw ();


 void __gmpf_set_q (mpf_ptr, mpq_srcptr);


 void __gmpf_set_si (mpf_ptr, signed long int);


 int __gmpf_set_str (mpf_ptr, const char *, int);


 void __gmpf_set_ui (mpf_ptr, unsigned long int);


 void __gmpf_set_z (mpf_ptr, mpz_srcptr);


 size_t __gmpf_size (mpf_srcptr) throw () __attribute__ ((__pure__));


 void __gmpf_sqrt (mpf_ptr, mpf_srcptr);


 void __gmpf_sqrt_ui (mpf_ptr, unsigned long int);


 void __gmpf_sub (mpf_ptr, mpf_srcptr, mpf_srcptr);


 void __gmpf_sub_ui (mpf_ptr, mpf_srcptr, unsigned long int);


 void __gmpf_swap (mpf_ptr, mpf_ptr) throw ();


 void __gmpf_trunc (mpf_ptr, mpf_srcptr);


 void __gmpf_ui_div (mpf_ptr, unsigned long int, mpf_srcptr);


 void __gmpf_ui_sub (mpf_ptr, unsigned long int, mpf_srcptr);


 void __gmpf_urandomb (mpf_t, gmp_randstate_t, unsigned long int);
# 1480 "./include/gmp-i386.h" 3 4
 mp_limb_t __gmpn_add (mp_ptr, mp_srcptr, mp_size_t, mp_srcptr,mp_size_t);




 mp_limb_t __gmpn_add_1 (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t) throw ();



 mp_limb_t __gmpn_add_n (mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);


 mp_limb_t __gmpn_addmul_1 (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);


 mp_limb_t __gmpn_bdivmod (mp_ptr, mp_ptr, mp_size_t, mp_srcptr, mp_size_t, unsigned long int);



 int __gmpn_cmp (mp_srcptr, mp_srcptr, mp_size_t) throw () __attribute__ ((__pure__));






 mp_limb_t __gmpn_divexact_by3c (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);





 mp_limb_t __gmpn_divrem (mp_ptr, mp_size_t, mp_ptr, mp_size_t, mp_srcptr, mp_size_t);


 mp_limb_t __gmpn_divrem_1 (mp_ptr, mp_size_t, mp_srcptr, mp_size_t, mp_limb_t);


 mp_limb_t __gmpn_divrem_2 (mp_ptr, mp_size_t, mp_ptr, mp_size_t, mp_srcptr);


 mp_size_t __gmpn_gcd (mp_ptr, mp_ptr, mp_size_t, mp_ptr, mp_size_t);


 mp_limb_t __gmpn_gcd_1 (mp_srcptr, mp_size_t, mp_limb_t) __attribute__ ((__pure__));


 mp_limb_t __gmpn_gcdext_1 (mp_limb_signed_t *, mp_limb_signed_t *, mp_limb_t, mp_limb_t);


 mp_size_t __gmpn_gcdext (mp_ptr, mp_ptr, mp_size_t *, mp_ptr, mp_size_t, mp_ptr, mp_size_t);


 size_t __gmpn_get_str (unsigned char *, int, mp_ptr, mp_size_t);


 unsigned long int __gmpn_hamdist (mp_srcptr, mp_srcptr, mp_size_t) throw () __attribute__ ((__pure__));


 mp_limb_t __gmpn_lshift (mp_ptr, mp_srcptr, mp_size_t, unsigned int);


 mp_limb_t __gmpn_mod_1 (mp_srcptr, mp_size_t, mp_limb_t) __attribute__ ((__pure__));


 mp_limb_t __gmpn_mul (mp_ptr, mp_srcptr, mp_size_t, mp_srcptr, mp_size_t);


 mp_limb_t __gmpn_mul_1 (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);


 void __gmpn_mul_n (mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);


 void __gmpn_sqr (mp_ptr, mp_srcptr, mp_size_t);



 mp_limb_t __gmpn_neg_n (mp_ptr, mp_srcptr, mp_size_t);



 int __gmpn_perfect_square_p (mp_srcptr, mp_size_t) __attribute__ ((__pure__));


 unsigned long int __gmpn_popcount (mp_srcptr, mp_size_t) throw () __attribute__ ((__pure__));


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




 mp_limb_t __gmpn_sub_1 (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t) throw ();



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
__gmpz_fits_uint_p (mpz_srcptr __gmp_z) throw ()
{
  mp_size_t __gmp_n = __gmp_z->_mp_size; mp_ptr __gmp_p = __gmp_z->_mp_d; return (__gmp_n == 0 || (__gmp_n == 1 && __gmp_p[0] <= (~ (unsigned) 0)));;
}




extern __inline__

int
__gmpz_fits_ulong_p (mpz_srcptr __gmp_z) throw ()
{
  mp_size_t __gmp_n = __gmp_z->_mp_size; mp_ptr __gmp_p = __gmp_z->_mp_d; return (__gmp_n == 0 || (__gmp_n == 1 && __gmp_p[0] <= (~ (unsigned long) 0)));;
}




extern __inline__

int
__gmpz_fits_ushort_p (mpz_srcptr __gmp_z) throw ()
{
  mp_size_t __gmp_n = __gmp_z->_mp_size; mp_ptr __gmp_p = __gmp_z->_mp_d; return (__gmp_n == 0 || (__gmp_n == 1 && __gmp_p[0] <= ((unsigned short) ~0)));;
}




extern __inline__

unsigned long
__gmpz_get_ui (mpz_srcptr __gmp_z) throw ()
{
  mp_ptr __gmp_p = __gmp_z->_mp_d;
  mp_size_t __gmp_n = __gmp_z->_mp_size;
  mp_limb_t __gmp_l = __gmp_p[0];






  return (__gmp_n != 0 ? __gmp_l : 0);
# 1712 "./include/gmp-i386.h" 3 4
}




extern __inline__

mp_limb_t
__gmpz_getlimbn (mpz_srcptr __gmp_z, mp_size_t __gmp_n) throw ()
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
__gmpz_popcount (mpz_srcptr __gmp_u) throw ()
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
__gmpz_size (mpz_srcptr __gmp_z) throw ()
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
  do { mp_size_t __gmp_i; mp_limb_t __gmp_x; __gmp_i = (__gmp_ysize); if (__gmp_i != 0) { if (__gmpn_add_n (__gmp_wp, __gmp_xp, __gmp_yp, __gmp_i)) { do { if (__gmp_i >= (__gmp_xsize)) { (__gmp_c) = 1; goto __gmp_done; } __gmp_x = (__gmp_xp)[__gmp_i]; } while ((((__gmp_wp)[__gmp_i++] = (__gmp_x + 1) & ((~ (static_cast<mp_limb_t> (0))) >> 0)) == 0)); } } if ((__gmp_wp) != (__gmp_xp)) do { mp_size_t __gmp_j; ; for (__gmp_j = (__gmp_i); __gmp_j < (__gmp_xsize); __gmp_j++) (__gmp_wp)[__gmp_j] = (__gmp_xp)[__gmp_j]; } while (0); (__gmp_c) = 0; __gmp_done: ; } while (0);
  return __gmp_c;
}




extern __inline__

mp_limb_t
__gmpn_add_1 (mp_ptr __gmp_dst, mp_srcptr __gmp_src, mp_size_t __gmp_size, mp_limb_t __gmp_n) throw ()
{
  mp_limb_t __gmp_c;
  do { mp_size_t __gmp_i; mp_limb_t __gmp_x, __gmp_r; __gmp_x = (__gmp_src)[0]; __gmp_r = __gmp_x + (__gmp_n); (__gmp_dst)[0] = __gmp_r; if (((__gmp_r) < ((__gmp_n)))) { (__gmp_c) = 1; for (__gmp_i = 1; __gmp_i < (__gmp_size);) { __gmp_x = (__gmp_src)[__gmp_i]; __gmp_r = __gmp_x + 1; (__gmp_dst)[__gmp_i] = __gmp_r; ++__gmp_i; if (!((__gmp_r) < (1))) { if ((__gmp_src) != (__gmp_dst)) do { mp_size_t __gmp_j; ; for (__gmp_j = (__gmp_i); __gmp_j < (__gmp_size); __gmp_j++) (__gmp_dst)[__gmp_j] = (__gmp_src)[__gmp_j]; } while (0); (__gmp_c) = 0; break; } } } else { if ((__gmp_src) != (__gmp_dst)) do { mp_size_t __gmp_j; ; for (__gmp_j = (1); __gmp_j < (__gmp_size); __gmp_j++) (__gmp_dst)[__gmp_j] = (__gmp_src)[__gmp_j]; } while (0); (__gmp_c) = 0; } } while (0);
  return __gmp_c;
}




extern __inline__

int
__gmpn_cmp (mp_srcptr __gmp_xp, mp_srcptr __gmp_yp, mp_size_t __gmp_size) throw ()
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
  do { mp_size_t __gmp_i; mp_limb_t __gmp_x; __gmp_i = (__gmp_ysize); if (__gmp_i != 0) { if (__gmpn_sub_n (__gmp_wp, __gmp_xp, __gmp_yp, __gmp_i)) { do { if (__gmp_i >= (__gmp_xsize)) { (__gmp_c) = 1; goto __gmp_done; } __gmp_x = (__gmp_xp)[__gmp_i]; } while ((((__gmp_wp)[__gmp_i++] = (__gmp_x - 1) & ((~ (static_cast<mp_limb_t> (0))) >> 0)), __gmp_x == 0)); } } if ((__gmp_wp) != (__gmp_xp)) do { mp_size_t __gmp_j; ; for (__gmp_j = (__gmp_i); __gmp_j < (__gmp_xsize); __gmp_j++) (__gmp_wp)[__gmp_j] = (__gmp_xp)[__gmp_j]; } while (0); (__gmp_c) = 0; __gmp_done: ; } while (0);
  return __gmp_c;
}




extern __inline__

mp_limb_t
__gmpn_sub_1 (mp_ptr __gmp_dst, mp_srcptr __gmp_src, mp_size_t __gmp_size, mp_limb_t __gmp_n) throw ()
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



}
# 2180 "./include/gmp-i386.h" 3 4
 std::ostream& operator<< (std::ostream &, mpz_srcptr);
 std::ostream& operator<< (std::ostream &, mpq_srcptr);
 std::ostream& operator<< (std::ostream &, mpf_srcptr);
 std::istream& operator>> (std::istream &, mpz_ptr);
 std::istream& operator>> (std::istream &, mpq_ptr);
 std::istream& operator>> (std::istream &, mpf_ptr);
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
# 25 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/double-int.h" 2
# 54 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/double-int.h"
typedef struct
{
  unsigned long low;
  long high;
} double_int;
# 67 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/double-int.h"
static inline double_int
shwi_to_double_int (long cst)
{
  double_int r;

  r.low = (unsigned long) cst;
  r.high = cst < 0 ? -1 : 0;

  return r;
}
# 89 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/double-int.h"
static inline double_int
uhwi_to_double_int (unsigned long cst)
{
  double_int r;

  r.low = cst;
  r.high = 0;

  return r;
}




static inline long
double_int_to_shwi (double_int cst)
{
  return (long) cst.low;
}




static inline unsigned long
double_int_to_uhwi (double_int cst)
{
  return cst.low;
}

bool double_int_fits_in_hwi_p (double_int, bool);
bool double_int_fits_in_shwi_p (double_int);



static inline bool
double_int_fits_in_uhwi_p (double_int cst)
{
  return cst.high == 0;
}






double_int double_int_mul (double_int, double_int);
double_int double_int_mul_with_sign (double_int, double_int, bool, int *);
double_int double_int_add (double_int, double_int);
double_int double_int_sub (double_int, double_int);
double_int double_int_neg (double_int);




double_int double_int_div (double_int, double_int, bool, unsigned);
double_int double_int_sdiv (double_int, double_int, unsigned);
double_int double_int_udiv (double_int, double_int, unsigned);
double_int double_int_mod (double_int, double_int, bool, unsigned);
double_int double_int_smod (double_int, double_int, unsigned);
double_int double_int_umod (double_int, double_int, unsigned);
double_int double_int_divmod (double_int, double_int, bool, unsigned, double_int *);
double_int double_int_sdivmod (double_int, double_int, unsigned, double_int *);
double_int double_int_udivmod (double_int, double_int, unsigned, double_int *);

double_int double_int_setbit (double_int, unsigned);
int double_int_ctz (double_int);





static inline double_int
double_int_not (double_int a)
{
  a.low = ~a.low;
  a.high = ~a.high;
  return a;
}



static inline double_int
double_int_ior (double_int a, double_int b)
{
  a.low |= b.low;
  a.high |= b.high;
  return a;
}



static inline double_int
double_int_and (double_int a, double_int b)
{
  a.low &= b.low;
  a.high &= b.high;
  return a;
}



static inline double_int
double_int_and_not (double_int a, double_int b)
{
  a.low &= ~b.low;
  a.high &= ~b.high;
  return a;
}



static inline double_int
double_int_xor (double_int a, double_int b)
{
  a.low ^= b.low;
  a.high ^= b.high;
  return a;
}



double_int double_int_lshift (double_int, long, unsigned int, bool);
double_int double_int_rshift (double_int, long, unsigned int, bool);
double_int double_int_lrotate (double_int, long, unsigned int);
double_int double_int_rrotate (double_int, long, unsigned int);




static inline bool
double_int_negative_p (double_int cst)
{
  return cst.high < 0;
}

int double_int_cmp (double_int, double_int, bool);
int double_int_scmp (double_int, double_int);
int double_int_ucmp (double_int, double_int);

double_int double_int_max (double_int, double_int, bool);
double_int double_int_smax (double_int, double_int);
double_int double_int_umax (double_int, double_int);

double_int double_int_min (double_int, double_int, bool);
double_int double_int_smin (double_int, double_int);
double_int double_int_umin (double_int, double_int);

void dump_double_int (FILE *, double_int, bool);



double_int double_int_ext (double_int, unsigned, bool);
double_int double_int_sext (double_int, unsigned);
double_int double_int_zext (double_int, unsigned);
double_int double_int_mask (unsigned);
# 253 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/double-int.h"
static inline bool
double_int_zero_p (double_int cst)
{
  return cst.low == 0 && cst.high == 0;
}



static inline bool
double_int_one_p (double_int cst)
{
  return cst.low == 1 && cst.high == 0;
}



static inline bool
double_int_minus_one_p (double_int cst)
{
  return (cst.low == (~((unsigned long) 0)) && cst.high == -1);
}



static inline bool
double_int_equal_p (double_int cst1, double_int cst2)
{
  return cst1.low == cst2.low && cst1.high == cst2.high;
}




extern int add_double_with_sign (unsigned long, long,
     unsigned long, long,
     unsigned long *, long *,
     bool);


extern int neg_double (unsigned long, long,
         unsigned long *, long *);
extern int mul_double_with_sign (unsigned long, long,
     unsigned long, long,
     unsigned long *, long *,
     bool);


extern void lshift_double (unsigned long, long,
      long, unsigned int,
      unsigned long *, long *, bool);
extern void rshift_double (unsigned long, long,
      long, unsigned int,
      unsigned long *, long *, bool);
extern int div_and_round_double (unsigned, int, unsigned long,
     long, unsigned long,
     long, unsigned long *,
     long *, unsigned long *,
     long *);





void mpz_set_double_int (mpz_t, double_int, bool);
double_int mpz_get_double_int (const_tree, mpz_t, bool);
# 32 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/real.h" 1
# 30 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/real.h"
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
# 77 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/real.h"
extern char test_real_width
  [sizeof(struct real_value) <= (((128 + (8 * 8)) + 32)/(8 * 8) + (((128 + (8 * 8)) + 32)%(8 * 8) ? 1 : 0))*sizeof(long) ? 1 : -1];
# 115 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/real.h"
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


  bool round_towards_zero;
  bool has_sign_dependent_rounding;


  bool has_nans;
  bool has_inf;
  bool has_denorm;
  bool has_signed_zero;
  bool qnan_msb_set;
  bool canonical_nan_lsbs_set;
};







extern const struct real_format *
  real_format_for_mode[MAX_MODE_FLOAT - MIN_MODE_FLOAT + 1
         + MAX_MODE_DECIMAL_FLOAT - MIN_MODE_DECIMAL_FLOAT + 1];
# 226 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/real.h"
extern bool real_arithmetic (struct real_value *, int, const struct real_value *,
        const struct real_value *);


extern bool real_compare (int, const struct real_value *, const struct real_value *);


extern bool real_isinf (const struct real_value *);


extern bool real_isnan (const struct real_value *);


extern bool real_isfinite (const struct real_value *);


extern bool real_isneg (const struct real_value *);


extern bool real_isnegzero (const struct real_value *);


extern bool real_identical (const struct real_value *, const struct real_value *);


extern void real_convert (struct real_value *, enum machine_mode,
     const struct real_value *);


extern bool exact_real_truncate (enum machine_mode, const struct real_value *);


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

extern bool real_nan (struct real_value *, const char *, int, enum machine_mode);

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
# 385 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/real.h"
extern struct real_value real_value_truncate (enum machine_mode,
         struct real_value);




extern struct real_value real_value_negate (const struct real_value *);
extern struct real_value real_value_abs (const struct real_value *);

extern int significand_size (enum machine_mode);

extern struct real_value real_from_string2 (const char *, enum machine_mode);
# 414 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/real.h"
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
# 453 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/real.h"
extern rtx const_double_from_real_value (struct real_value, enum machine_mode);


extern bool exact_real_inverse (enum machine_mode, struct real_value *);




bool real_can_shorten_arithmetic (enum machine_mode, enum machine_mode);


extern tree build_real (tree, struct real_value);


extern bool real_sqrt (struct real_value *, enum machine_mode,
         const struct real_value *);


extern bool real_powi (struct real_value *, enum machine_mode,
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


extern bool real_isinteger (const struct real_value *c, enum machine_mode mode);




extern void get_max_float (const struct real_format *, char *, size_t);
# 33 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/fixed-value.h" 1
# 27 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/fixed-value.h"
struct fixed_value
{
  double_int data;
  enum machine_mode mode;
};
# 40 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/fixed-value.h"
extern struct fixed_value fconst0[18];
extern struct fixed_value fconst1[8];
# 50 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/fixed-value.h"
extern rtx const_fixed_from_fixed_value (struct fixed_value, enum machine_mode);


extern void fixed_from_string (struct fixed_value *, const char *,
          enum machine_mode);


extern tree build_fixed (tree, struct fixed_value);


extern bool fixed_convert (struct fixed_value *, enum machine_mode,
      const struct fixed_value *, bool);


extern bool fixed_convert_from_int (struct fixed_value *, enum machine_mode,
        double_int, bool, bool);


extern bool fixed_convert_from_real (struct fixed_value *, enum machine_mode,
         const struct real_value *, bool);


extern void real_convert_from_fixed (struct real_value *, enum machine_mode,
         const struct fixed_value *);


extern bool fixed_identical (const struct fixed_value *, const struct fixed_value *);


extern unsigned int fixed_hash (const struct fixed_value *);







extern void fixed_to_decimal (char *str, const struct fixed_value *, size_t);


extern bool fixed_arithmetic (struct fixed_value *, int, const struct fixed_value *,
         const struct fixed_value *, bool);


extern bool fixed_compare (int, const struct fixed_value *,
      const struct fixed_value *);


extern bool fixed_isneg (const struct fixed_value *);
# 34 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/alias.h" 1
# 31 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/alias.h"
typedef int alias_set_type;

extern alias_set_type new_alias_set (void);
extern alias_set_type get_alias_set (tree);
extern alias_set_type get_deref_alias_set (tree);
extern alias_set_type get_varargs_alias_set (void);
extern alias_set_type get_frame_alias_set (void);
extern bool component_uses_parent_alias_set (const_tree);
extern bool alias_set_subset_of (alias_set_type, alias_set_type);
extern void record_alias_subset (alias_set_type, alias_set_type);
extern void record_component_aliases (tree);
extern int alias_sets_conflict_p (alias_set_type, alias_set_type);
extern int alias_sets_must_conflict_p (alias_set_type, alias_set_type);
extern int objects_must_conflict_p (tree, tree);
extern int nonoverlapping_memrefs_p (const_rtx, const_rtx, bool);
# 35 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/flags.h" 1
# 26 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/flags.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/flag-types.h" 1
# 25 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/flag-types.h"
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
# 53 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/flag-types.h"
enum debug_info_usage
{
  DINFO_USAGE_DFN,
  DINFO_USAGE_DIR_USE,
  DINFO_USAGE_IND_USE,
  DINFO_USAGE_NUM_ENUMS
};
# 86 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/flag-types.h"
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
# 27 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/flags.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/options.h" 1







# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386-opts.h" 1
# 31 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386-opts.h"
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


enum calling_abi
{
  SYSV_ABI = 0,
  MS_ABI = 1
};

enum fpmath_unit
{
  FPMATH_387 = 1,
  FPMATH_SSE = 2
};

enum tls_dialect
{
  TLS_DIALECT_GNU,
  TLS_DIALECT_GNU2,
  TLS_DIALECT_SUN
};

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

enum asm_dialect {
  ASM_ATT,
  ASM_INTEL
};

enum ix86_veclibabi {
  ix86_veclibabi_type_none,
  ix86_veclibabi_type_svml,
  ix86_veclibabi_type_acml
};
# 9 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/options.h" 2




struct gcc_options



{




  int x_recip_mask;





  long x_frame_larger_than_size;





  long x_ix86_isa_flags;





  long x_ix86_isa_flags_explicit;





  long x_larger_than_size;





  bool x_exit_after_options;





  bool x_flag_dump_all_passed;





  bool x_flag_opts_finished;





  bool x_flag_stack_usage_info;





  bool x_flag_warn_unused_result;





  bool x_in_lto_p;





  bool x_use_gnu_debug_info_extensions;





  bool x_warn_frame_larger_than;





  bool x_warn_larger_than;





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





  int x_recip_mask_explicit;





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





  enum calling_abi x_ix86_abi;





  int x_flag_android;





  const char *x_ix86_arch_string;





  enum asm_dialect x_ix86_asm_dialect;





  int x_linux_libc;





  int x_ix86_branch_cost;





  enum cmodel x_ix86_cmodel;





  int x_flag_dispatch_scheduler;





  int x_flag_fentry;





  int x_ix86_force_drap;





  enum fpmath_unit x_ix86_fpmath;





  int x_ix86_incoming_stack_boundary_arg;





  int x_ix86_section_threshold;





  int x_ix86_preferred_stack_boundary_arg;





  const char *x_ix86_recip_name;





  int x_ix86_regparm;





  int x_ix86_sse2avx;





  int x_ix86_force_align_arg_pointer;





  enum stringop_alg x_ix86_stringop_alg;





  enum tls_dialect x_ix86_tls_dialect;





  const char *x_ix86_tune_string;





  enum ix86_veclibabi x_ix86_veclibabi_type;





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



  int x_VAR_malign_functions_;



  int x_VAR_malign_jumps_;



  int x_VAR_malign_loops_;



  int x_VAR_mpc32;



  int x_VAR_mpc64;



  int x_VAR_mpc80;



  bool frontend_set_flag_associative_math;


  bool frontend_set_flag_cx_limited_range;


  bool frontend_set_flag_finite_math_only;


  bool frontend_set_flag_errno_math;


  bool frontend_set_flag_reciprocal_math;


  bool frontend_set_flag_rounding_math;


  bool frontend_set_flag_signaling_nans;


  bool frontend_set_flag_signed_zeros;


  bool frontend_set_flag_trapping_math;


  bool frontend_set_flag_unsafe_math_optimizations;


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
  long x_ix86_isa_flags_explicit;
  long x_ix86_isa_flags;
  enum fpmath_unit x_ix86_fpmath;
  int ix86_target_flags_explicit;
  int x_recip_mask_explicit;
  int x_recip_mask;
  int x_target_flags;
  unsigned char arch;
  unsigned char arch_specified;
  unsigned char branch_cost;
  unsigned char schedule;
  unsigned char tune;
  unsigned char tune_defaulted;
};



extern void cl_optimization_save (struct cl_optimization *, struct gcc_options *);


extern void cl_optimization_restore (struct gcc_options *, struct cl_optimization *);


extern void cl_optimization_print (FILE *, int, struct cl_optimization *);


extern void cl_target_option_save (struct cl_target_option *, struct gcc_options *);


extern void cl_target_option_restore (struct gcc_options *, struct cl_target_option *);


extern void cl_target_option_print (FILE *, int, struct cl_target_option *);
# 3819 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/options.h"
enum opt_code
{
  OPT____ = 0,
# 3853 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/options.h"
  OPT__help = 32,
  OPT__help_ = 33,
# 3886 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/options.h"
  OPT__output_pch_ = 65,

  OPT__param = 67,
# 3920 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/options.h"
  OPT__sysroot_ = 99,
  OPT__target_help = 100,
# 3931 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/options.h"
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
  OPT_m128bit_long_double = 983,
  OPT_m32 = 984,
  OPT_m3dnow = 985,
  OPT_m3dnowa = 986,
  OPT_m64 = 987,
  OPT_m80387 = 988,
  OPT_m8bit_idiv = 989,
  OPT_m96bit_long_double = 990,
  OPT_mabi_ = 991,
  OPT_mabm = 992,
  OPT_maccumulate_outgoing_args = 993,
  OPT_maes = 994,
  OPT_malign_double = 995,
  OPT_malign_functions_ = 996,
  OPT_malign_jumps_ = 997,
  OPT_malign_loops_ = 998,
  OPT_malign_stringops = 999,
  OPT_mandroid = 1000,
  OPT_march_ = 1001,
  OPT_masm_ = 1002,
  OPT_mavx = 1003,
  OPT_mavx2 = 1004,
  OPT_mavx256_split_unaligned_load = 1005,
  OPT_mavx256_split_unaligned_store = 1006,
  OPT_mbionic = 1007,
  OPT_mbmi = 1008,
  OPT_mbmi2 = 1009,
  OPT_mbranch_cost_ = 1010,
  OPT_mcld = 1011,
  OPT_mcmodel_ = 1012,

  OPT_mcrc32 = 1014,
  OPT_mcx16 = 1015,
  OPT_mdispatch_scheduler = 1016,
  OPT_mf16c = 1017,
  OPT_mfancy_math_387 = 1018,
  OPT_mfentry = 1019,
  OPT_mfma = 1020,
  OPT_mfma4 = 1021,
  OPT_mforce_drap = 1022,
  OPT_mfp_ret_in_387 = 1023,
  OPT_mfpmath_ = 1024,
  OPT_mfsgsbase = 1025,

  OPT_mglibc = 1027,
  OPT_mhard_float = 1028,
  OPT_mieee_fp = 1029,
  OPT_mincoming_stack_boundary_ = 1030,
  OPT_minline_all_stringops = 1031,
  OPT_minline_stringops_dynamically = 1032,

  OPT_mlarge_data_threshold_ = 1034,
  OPT_mlwp = 1035,
  OPT_mlzcnt = 1036,
  OPT_mmmx = 1037,
  OPT_mmovbe = 1038,
  OPT_mms_bitfields = 1039,
  OPT_mno_align_stringops = 1040,
  OPT_mno_fancy_math_387 = 1041,
  OPT_mno_push_args = 1042,
  OPT_mno_red_zone = 1043,
  OPT_mno_sse4 = 1044,
  OPT_momit_leaf_frame_pointer = 1045,
  OPT_mpc32 = 1046,
  OPT_mpc64 = 1047,
  OPT_mpc80 = 1048,
  OPT_mpclmul = 1049,
  OPT_mpopcnt = 1050,
  OPT_mprefer_avx128 = 1051,
  OPT_mpreferred_stack_boundary_ = 1052,
  OPT_mpush_args = 1053,
  OPT_mrdrnd = 1054,
  OPT_mrecip = 1055,
  OPT_mrecip_ = 1056,
  OPT_mred_zone = 1057,
  OPT_mregparm_ = 1058,
  OPT_mrtd = 1059,
  OPT_msahf = 1060,
  OPT_msoft_float = 1061,
  OPT_msse = 1062,
  OPT_msse2 = 1063,
  OPT_msse2avx = 1064,
  OPT_msse3 = 1065,
  OPT_msse4 = 1066,
  OPT_msse4_1 = 1067,
  OPT_msse4_2 = 1068,
  OPT_msse4a = 1069,

  OPT_msseregparm = 1071,
  OPT_mssse3 = 1072,
  OPT_mstack_arg_probe = 1073,
  OPT_mstackrealign = 1074,
  OPT_mstringop_strategy_ = 1075,
  OPT_mtbm = 1076,
  OPT_mtls_dialect_ = 1077,
  OPT_mtls_direct_seg_refs = 1078,
  OPT_mtune_ = 1079,
  OPT_muclibc = 1080,
  OPT_mveclibabi_ = 1081,
  OPT_mvect8_ret_in_mem = 1082,
  OPT_mvzeroupper = 1083,
  OPT_mx32 = 1084,
  OPT_mxop = 1085,
  OPT_n = 1086,
  OPT_no_canonical_prefixes = 1087,
  OPT_no_integrated_cpp = 1088,
  OPT_nocpp = 1089,
  OPT_nodefaultlibs = 1090,
  OPT_nostartfiles = 1091,
  OPT_nostdinc = 1092,
  OPT_nostdinc__ = 1093,
  OPT_nostdlib = 1094,
  OPT_o = 1095,
  OPT_p = 1096,
  OPT_pass_exit_codes = 1097,
  OPT_pedantic = 1098,
  OPT_pedantic_errors = 1099,
  OPT_pg = 1100,
  OPT_pie = 1101,
  OPT_pipe = 1102,
  OPT_posix = 1103,
  OPT_print_file_name_ = 1104,
  OPT_print_libgcc_file_name = 1105,
  OPT_print_multi_directory = 1106,
  OPT_print_multi_lib = 1107,
  OPT_print_multi_os_directory = 1108,
  OPT_print_objc_runtime_info = 1109,
  OPT_print_prog_name_ = 1110,
  OPT_print_search_dirs = 1111,
  OPT_print_sysroot = 1112,
  OPT_print_sysroot_headers_suffix = 1113,
  OPT_profile = 1114,
  OPT_pthread = 1115,
  OPT_quiet = 1116,
  OPT_r = 1117,
  OPT_rdynamic = 1118,
  OPT_remap = 1119,
  OPT_s = 1120,
  OPT_s_bc_abi = 1121,
  OPT_save_temps = 1122,
  OPT_save_temps_ = 1123,
  OPT_shared = 1124,
  OPT_shared_libgcc = 1125,

  OPT_specs_ = 1127,
  OPT_static = 1128,
  OPT_static_libgcc = 1129,
  OPT_static_libgcj = 1130,
  OPT_static_libgfortran = 1131,
  OPT_static_libgo = 1132,
  OPT_static_libstdc__ = 1133,


  OPT_std_c__11 = 1136,
  OPT_std_c__98 = 1137,
  OPT_std_c11 = 1138,


  OPT_std_c90 = 1141,
  OPT_std_c99 = 1142,

  OPT_std_f2003 = 1144,
  OPT_std_f2008 = 1145,
  OPT_std_f2008ts = 1146,
  OPT_std_f95 = 1147,
  OPT_std_gnu = 1148,


  OPT_std_gnu__11 = 1151,
  OPT_std_gnu__98 = 1152,
  OPT_std_gnu11 = 1153,


  OPT_std_gnu90 = 1156,
  OPT_std_gnu99 = 1157,


  OPT_std_iso9899_199409 = 1160,



  OPT_std_legacy = 1164,
  OPT_symbolic = 1165,
  OPT_t = 1166,
  OPT_time = 1167,
  OPT_time_ = 1168,
  OPT_tno_android_cc = 1169,
  OPT_tno_android_ld = 1170,
  OPT_traditional = 1171,
  OPT_traditional_cpp = 1172,
  OPT_trigraphs = 1173,
  OPT_u = 1174,
  OPT_undef = 1175,
  OPT_v = 1176,
  OPT_version = 1177,
  OPT_w = 1178,
  OPT_wrapper = 1179,
  OPT_x = 1180,
  OPT_z = 1181,
  N_OPTS,
  OPT_SPECIAL_unknown,
  OPT_SPECIAL_ignore,
  OPT_SPECIAL_program_name,
  OPT_SPECIAL_input_file
};
# 28 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/flags.h" 2




extern const char *const debug_type_names[];

extern void strip_off_ending (char *, int);
extern int base_of_path (const char *path, const char **base_out);


extern bool fast_math_flags_set_p (const struct gcc_options *);
extern bool fast_math_flags_struct_set_p (struct cl_optimization *);
# 48 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/flags.h"
extern void set_Wstrict_aliasing (struct gcc_options *opts, int onoff);





extern bool final_insns_dump_p;



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
# 105 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/flags.h"
extern int dump_for_graph;
# 36 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h" 2






enum tree_code {
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/all-tree.def" 1
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def" 1
# 42 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
ERROR_MARK,





IDENTIFIER_NODE,






TREE_LIST,


TREE_VEC,
# 79 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
BLOCK,
# 123 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
OFFSET_TYPE,
# 136 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
ENUMERAL_TYPE,



BOOLEAN_TYPE,
# 150 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
INTEGER_TYPE,



REAL_TYPE,
# 163 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
POINTER_TYPE,



REFERENCE_TYPE,


NULLPTR_TYPE,




FIXED_POINT_TYPE,
# 184 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
COMPLEX_TYPE,




VECTOR_TYPE,
# 205 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
ARRAY_TYPE,
# 215 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
RECORD_TYPE,





UNION_TYPE,





QUAL_UNION_TYPE,






VOID_TYPE,







FUNCTION_TYPE,






METHOD_TYPE,





LANG_TYPE,
# 268 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
INTEGER_CST,


REAL_CST,


FIXED_CST,



COMPLEX_CST,


VECTOR_CST,


STRING_CST,
# 344 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
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
# 374 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
IMPORTED_DECL,



TRANSLATION_UNIT_DECL,
# 391 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
COMPONENT_REF,
# 401 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
BIT_FIELD_REF,



REALPART_EXPR,
IMAGPART_EXPR,






ARRAY_REF,




ARRAY_RANGE_REF,


INDIRECT_REF,
# 430 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
OBJ_TYPE_REF,
# 446 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
CONSTRUCTOR,
# 456 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
COMPOUND_EXPR,


MODIFY_EXPR,




INIT_EXPR,







TARGET_EXPR,
# 486 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
COND_EXPR,
# 498 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
VEC_COND_EXPR,
# 512 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
VEC_PERM_EXPR,
# 535 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
BIND_EXPR,







CALL_EXPR,






WITH_CLEANUP_EXPR,
# 567 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
CLEANUP_POINT_EXPR,
# 619 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
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
# 689 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
LSHIFT_EXPR,
RSHIFT_EXPR,
LROTATE_EXPR,
RROTATE_EXPR,


BIT_IOR_EXPR,
BIT_XOR_EXPR,
BIT_AND_EXPR,
BIT_NOT_EXPR,
# 709 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
TRUTH_ANDIF_EXPR,
TRUTH_ORIF_EXPR,
TRUTH_AND_EXPR,
TRUTH_OR_EXPR,
TRUTH_XOR_EXPR,
TRUTH_NOT_EXPR,
# 725 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
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
# 782 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
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
# 877 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
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
# 939 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
ASSERT_EXPR,



TREE_BINFO,






WITH_SIZE_EXPR,
# 961 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
REALIGN_LOAD_EXPR,
# 977 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
TARGET_MEM_REF,
# 987 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
MEM_REF,







OMP_PARALLEL,





OMP_TASK,
# 1022 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
OMP_FOR,




OMP_SECTIONS,




OMP_SINGLE,



OMP_SECTION,



OMP_MASTER,



OMP_ORDERED,




OMP_CRITICAL,







OMP_ATOMIC,




OMP_ATOMIC_READ,
# 1072 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
OMP_ATOMIC_CAPTURE_OLD,
OMP_ATOMIC_CAPTURE_NEW,


OMP_CLAUSE,



TRANSACTION_EXPR,







REDUC_MAX_EXPR,
REDUC_MIN_EXPR,
REDUC_PLUS_EXPR,
# 1101 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
DOT_PROD_EXPR,
# 1110 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
WIDEN_SUM_EXPR,






WIDEN_MULT_EXPR,
# 1126 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
WIDEN_MULT_PLUS_EXPR,


WIDEN_MULT_MINUS_EXPR,
# 1142 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
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
# 1198 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.def"
VEC_WIDEN_LSHIFT_HI_EXPR,
VEC_WIDEN_LSHIFT_LO_EXPR,






PREDICT_EXPR,


OPTIMIZATION_NODE,


TARGET_OPTION_NODE,
# 2 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/all-tree.def" 2
LAST_AND_UNUSED_TREE_CODE,
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.def" 1
# 41 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.def"
C_MAYBE_CONST_EXPR,






EXCESS_PRECISION_EXPR,





USERDEF_LITERAL,
# 4 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/all-tree.def" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/ada/gcc-interface/ada-tree.def" 1
# 29 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/ada/gcc-interface/ada-tree.def"
UNCONSTRAINED_ARRAY_TYPE,





UNCONSTRAINED_ARRAY_REF,




NULL_EXPR,



PLUS_NOMOD_EXPR,



MINUS_NOMOD_EXPR,




ATTR_ADDR_EXPR,
# 62 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/ada/gcc-interface/ada-tree.def"
STMT_STMT,





LOOP_STMT,





EXIT_STMT,
# 5 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/all-tree.def" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.def" 1
# 43 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.def"
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
# 109 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.def"
BASELINK,
# 126 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.def"
TEMPLATE_DECL,
# 161 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.def"
TEMPLATE_PARM_INDEX,
# 170 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.def"
TEMPLATE_TEMPLATE_PARM,
# 179 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.def"
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
# 243 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.def"
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
# 267 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.def"
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
# 384 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.def"
TYPE_ARGUMENT_PACK,
# 393 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.def"
NONTYPE_ARGUMENT_PACK,
# 416 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.def"
TYPE_PACK_EXPANSION,






EXPR_PACK_EXPANSION,
# 435 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.def"
ARGUMENT_PACK_SELECT,




TRAIT_EXPR,
# 451 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.def"
LAMBDA_EXPR,
# 460 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.def"
DECLTYPE_TYPE,



UNDERLYING_TYPE,



BASES,
# 478 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.def"
TEMPLATE_INFO,
# 6 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/all-tree.def" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/java/java-tree.def" 1
# 23 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/java/java-tree.def"
URSHIFT_EXPR,



COMPARE_EXPR,


COMPARE_L_EXPR,

COMPARE_G_EXPR,
# 7 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/all-tree.def" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/objc/objc-tree.def" 1
# 25 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/objc/objc-tree.def"
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
# 71 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/objc/objc-tree.def"
PROPERTY_REF,
# 7 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/all-tree.def" 2
# 44 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h" 2
MAX_TREE_CODES
};




extern unsigned char tree_contains_struct[MAX_TREE_CODES][64];
# 121 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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
# 235 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern const unsigned char tree_code_length[];




extern const char *const tree_code_name[];
# 250 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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


typedef struct VEC_alias_pair_base { struct vec_prefix prefix; alias_pair vec[1]; } VEC_alias_pair_base; typedef struct VEC_alias_pair_none { VEC_alias_pair_base base; } VEC_alias_pair_none; static inline unsigned VEC_alias_pair_base_length (const VEC_alias_pair_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline alias_pair *VEC_alias_pair_base_last (VEC_alias_pair_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return &vec_->vec[vec_->prefix.num - 1]; } static inline alias_pair *VEC_alias_pair_base_index (VEC_alias_pair_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return &vec_->vec[ix_]; } static inline int VEC_alias_pair_base_iterate (VEC_alias_pair_base *vec_, unsigned ix_, alias_pair **ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = &vec_->vec[ix_]; return 1; } else { *ptr = 0; return 0; } } static inline size_t VEC_alias_pair_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_alias_pair_base, vec) + alloc_ * sizeof(alias_pair); } static inline void VEC_alias_pair_base_embedded_init (VEC_alias_pair_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_alias_pair_base_space (VEC_alias_pair_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_alias_pair_base_splice (VEC_alias_pair_base *dst_, VEC_alias_pair_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (alias_pair)); dst_->prefix.num += len_; } } static inline alias_pair *VEC_alias_pair_base_quick_push (VEC_alias_pair_base *vec_, const alias_pair *obj_ ) { alias_pair *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; if (obj_) *slot_ = *obj_; return slot_; } static inline void VEC_alias_pair_base_pop (VEC_alias_pair_base *vec_ ) { (void)(vec_->prefix.num); --vec_->prefix.num; } static inline void VEC_alias_pair_base_truncate (VEC_alias_pair_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline alias_pair *VEC_alias_pair_base_replace (VEC_alias_pair_base *vec_, unsigned ix_, const alias_pair *obj_ ) { alias_pair *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; if (obj_) *slot_ = *obj_; return slot_; } static inline alias_pair *VEC_alias_pair_base_quick_insert (VEC_alias_pair_base *vec_, unsigned ix_, const alias_pair *obj_ ) { alias_pair *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (alias_pair)); if (obj_) *slot_ = *obj_; return slot_; } static inline void VEC_alias_pair_base_ordered_remove (VEC_alias_pair_base *vec_, unsigned ix_ ) { alias_pair *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (alias_pair)); } static inline void VEC_alias_pair_base_unordered_remove (VEC_alias_pair_base *vec_, unsigned ix_ ) { (void)(ix_ < vec_->prefix.num); vec_->vec[ix_] = vec_->vec[--vec_->prefix.num]; } static inline void VEC_alias_pair_base_block_remove (VEC_alias_pair_base *vec_, unsigned ix_, unsigned len_ ) { alias_pair *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (alias_pair)); } static inline alias_pair *VEC_alias_pair_base_address (VEC_alias_pair_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_alias_pair_base_lower_bound (VEC_alias_pair_base *vec_, const alias_pair *obj_, bool (*lessthan_)(const alias_pair *, const alias_pair *) ) { unsigned int len_ = VEC_alias_pair_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { alias_pair *middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_alias_pair_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_alias_pair_gc { VEC_alias_pair_base base; } VEC_alias_pair_gc; static inline VEC_alias_pair_gc *VEC_alias_pair_gc_alloc (int alloc_ ) { return (VEC_alias_pair_gc *) vec_gc_o_reserve_exact (__null, alloc_, __builtin_offsetof (VEC_alias_pair_gc, base.vec), sizeof (alias_pair) ); } static inline VEC_alias_pair_gc *VEC_alias_pair_gc_copy (VEC_alias_pair_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_alias_pair_gc *new_vec_ = __null; if (len_) { new_vec_ = (VEC_alias_pair_gc *)(vec_gc_o_reserve_exact (__null, len_, __builtin_offsetof (VEC_alias_pair_gc, base.vec), sizeof (alias_pair) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (alias_pair) * len_); } return new_vec_; } static inline void VEC_alias_pair_gc_free (VEC_alias_pair_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = __null; } static inline int VEC_alias_pair_gc_reserve (VEC_alias_pair_gc **vec_, int alloc_ ) { int extend = !VEC_alias_pair_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_alias_pair_gc *) vec_gc_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_alias_pair_gc, base.vec), sizeof (alias_pair) ); return extend; } static inline int VEC_alias_pair_gc_reserve_exact (VEC_alias_pair_gc **vec_, int alloc_ ) { int extend = !VEC_alias_pair_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_alias_pair_gc *) vec_gc_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_alias_pair_gc, base.vec), sizeof (alias_pair) ); return extend; } static inline void VEC_alias_pair_gc_safe_grow (VEC_alias_pair_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_alias_pair_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_alias_pair_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_alias_pair_gc_safe_grow_cleared (VEC_alias_pair_gc **vec_, int size_ ) { int oldsize = VEC_alias_pair_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_alias_pair_gc_safe_grow (vec_, size_ ); memset (&(VEC_alias_pair_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (alias_pair) * (size_ - oldsize)); } static inline void VEC_alias_pair_gc_safe_splice (VEC_alias_pair_gc **dst_, VEC_alias_pair_base *src_ ) { if (src_) { VEC_alias_pair_gc_reserve_exact (dst_, src_->prefix.num ); VEC_alias_pair_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline alias_pair *VEC_alias_pair_gc_safe_push (VEC_alias_pair_gc **vec_, const alias_pair *obj_ ) { VEC_alias_pair_gc_reserve (vec_, 1 ); return VEC_alias_pair_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline alias_pair *VEC_alias_pair_gc_safe_insert (VEC_alias_pair_gc **vec_, unsigned ix_, const alias_pair *obj_ ) { VEC_alias_pair_gc_reserve (vec_, 1 ); return VEC_alias_pair_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;

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
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/builtins.def" 1
# 184 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/builtins.def"
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


# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/sync-builtins.def" 1
# 31 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/sync-builtins.def"
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
# 805 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/builtins.def" 2


# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/omp-builtins.def" 1
# 27 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/omp-builtins.def"
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
# 808 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/builtins.def" 2


# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/gtm-builtins.def" 1
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
# 63 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/gtm-builtins.def"
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
# 129 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/gtm-builtins.def"
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
# 810 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/builtins.def" 2
# 294 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h" 2



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
# 342 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern unsigned const char omp_clause_num_ops[];
extern const char * const omp_clause_code_name[];



enum omp_clause_code
{


  OMP_CLAUSE_ERROR = 0,


  OMP_CLAUSE_PRIVATE,


  OMP_CLAUSE_SHARED,


  OMP_CLAUSE_FIRSTPRIVATE,


  OMP_CLAUSE_LASTPRIVATE,
# 372 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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
# 433 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
struct tree_base {
  enum tree_code code : 16;

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
# 712 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
enum tree_node_structure_enum {
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/treestruct.def" 1
# 33 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/treestruct.def"
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
# 714 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h" 2
  LAST_TS_ENUM
};
# 1012 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree-check.h" 1
# 1013 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h" 2
# 1484 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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

# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/symtab.h" 1
# 22 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/symtab.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/obstack.h" 1
# 114 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/obstack.h"
extern "C" {
# 157 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/obstack.h"
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
# 542 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/obstack.h"
}
# 23 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/symtab.h" 2







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


  bool entries_owned;
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
       unsigned int nslots, unsigned int nelements, bool own);


extern void ht_dump_statistics (hash_table *);
# 1545 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h" 2
# 1562 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
struct tree_identifier {
  struct tree_common common;
  struct ht_identifier id;
};





struct tree_list {
  struct tree_common common;
  tree purpose;
  tree value;
};
# 1584 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
struct tree_vec {
  struct tree_common common;
  int length;
  tree a[1];
};
# 1643 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
typedef struct constructor_elt_d {
  tree index;
  tree value;
} constructor_elt;

typedef struct VEC_constructor_elt_base { struct vec_prefix prefix; constructor_elt vec[1]; } VEC_constructor_elt_base; typedef struct VEC_constructor_elt_none { VEC_constructor_elt_base base; } VEC_constructor_elt_none; static inline unsigned VEC_constructor_elt_base_length (const VEC_constructor_elt_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline constructor_elt *VEC_constructor_elt_base_last (VEC_constructor_elt_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return &vec_->vec[vec_->prefix.num - 1]; } static inline constructor_elt *VEC_constructor_elt_base_index (VEC_constructor_elt_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return &vec_->vec[ix_]; } static inline int VEC_constructor_elt_base_iterate (VEC_constructor_elt_base *vec_, unsigned ix_, constructor_elt **ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = &vec_->vec[ix_]; return 1; } else { *ptr = 0; return 0; } } static inline size_t VEC_constructor_elt_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_constructor_elt_base, vec) + alloc_ * sizeof(constructor_elt); } static inline void VEC_constructor_elt_base_embedded_init (VEC_constructor_elt_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_constructor_elt_base_space (VEC_constructor_elt_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_constructor_elt_base_splice (VEC_constructor_elt_base *dst_, VEC_constructor_elt_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (constructor_elt)); dst_->prefix.num += len_; } } static inline constructor_elt *VEC_constructor_elt_base_quick_push (VEC_constructor_elt_base *vec_, const constructor_elt *obj_ ) { constructor_elt *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; if (obj_) *slot_ = *obj_; return slot_; } static inline void VEC_constructor_elt_base_pop (VEC_constructor_elt_base *vec_ ) { (void)(vec_->prefix.num); --vec_->prefix.num; } static inline void VEC_constructor_elt_base_truncate (VEC_constructor_elt_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline constructor_elt *VEC_constructor_elt_base_replace (VEC_constructor_elt_base *vec_, unsigned ix_, const constructor_elt *obj_ ) { constructor_elt *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; if (obj_) *slot_ = *obj_; return slot_; } static inline constructor_elt *VEC_constructor_elt_base_quick_insert (VEC_constructor_elt_base *vec_, unsigned ix_, const constructor_elt *obj_ ) { constructor_elt *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (constructor_elt)); if (obj_) *slot_ = *obj_; return slot_; } static inline void VEC_constructor_elt_base_ordered_remove (VEC_constructor_elt_base *vec_, unsigned ix_ ) { constructor_elt *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (constructor_elt)); } static inline void VEC_constructor_elt_base_unordered_remove (VEC_constructor_elt_base *vec_, unsigned ix_ ) { (void)(ix_ < vec_->prefix.num); vec_->vec[ix_] = vec_->vec[--vec_->prefix.num]; } static inline void VEC_constructor_elt_base_block_remove (VEC_constructor_elt_base *vec_, unsigned ix_, unsigned len_ ) { constructor_elt *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (constructor_elt)); } static inline constructor_elt *VEC_constructor_elt_base_address (VEC_constructor_elt_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_constructor_elt_base_lower_bound (VEC_constructor_elt_base *vec_, const constructor_elt *obj_, bool (*lessthan_)(const constructor_elt *, const constructor_elt *) ) { unsigned int len_ = VEC_constructor_elt_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { constructor_elt *middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_constructor_elt_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_constructor_elt_gc { VEC_constructor_elt_base base; } VEC_constructor_elt_gc; static inline VEC_constructor_elt_gc *VEC_constructor_elt_gc_alloc (int alloc_ ) { return (VEC_constructor_elt_gc *) vec_gc_o_reserve_exact (__null, alloc_, __builtin_offsetof (VEC_constructor_elt_gc, base.vec), sizeof (constructor_elt) ); } static inline VEC_constructor_elt_gc *VEC_constructor_elt_gc_copy (VEC_constructor_elt_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_constructor_elt_gc *new_vec_ = __null; if (len_) { new_vec_ = (VEC_constructor_elt_gc *)(vec_gc_o_reserve_exact (__null, len_, __builtin_offsetof (VEC_constructor_elt_gc, base.vec), sizeof (constructor_elt) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (constructor_elt) * len_); } return new_vec_; } static inline void VEC_constructor_elt_gc_free (VEC_constructor_elt_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = __null; } static inline int VEC_constructor_elt_gc_reserve (VEC_constructor_elt_gc **vec_, int alloc_ ) { int extend = !VEC_constructor_elt_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_constructor_elt_gc *) vec_gc_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_constructor_elt_gc, base.vec), sizeof (constructor_elt) ); return extend; } static inline int VEC_constructor_elt_gc_reserve_exact (VEC_constructor_elt_gc **vec_, int alloc_ ) { int extend = !VEC_constructor_elt_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_constructor_elt_gc *) vec_gc_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_constructor_elt_gc, base.vec), sizeof (constructor_elt) ); return extend; } static inline void VEC_constructor_elt_gc_safe_grow (VEC_constructor_elt_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_constructor_elt_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_constructor_elt_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_constructor_elt_gc_safe_grow_cleared (VEC_constructor_elt_gc **vec_, int size_ ) { int oldsize = VEC_constructor_elt_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_constructor_elt_gc_safe_grow (vec_, size_ ); memset (&(VEC_constructor_elt_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (constructor_elt) * (size_ - oldsize)); } static inline void VEC_constructor_elt_gc_safe_splice (VEC_constructor_elt_gc **dst_, VEC_constructor_elt_base *src_ ) { if (src_) { VEC_constructor_elt_gc_reserve_exact (dst_, src_->prefix.num ); VEC_constructor_elt_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline constructor_elt *VEC_constructor_elt_gc_safe_push (VEC_constructor_elt_gc **vec_, const constructor_elt *obj_ ) { VEC_constructor_elt_gc_reserve (vec_, 1 ); return VEC_constructor_elt_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline constructor_elt *VEC_constructor_elt_gc_safe_insert (VEC_constructor_elt_gc **vec_, unsigned ix_, const constructor_elt *obj_ ) { VEC_constructor_elt_gc_reserve (vec_, 1 ); return VEC_constructor_elt_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;

struct tree_constructor {
  struct tree_typed typed;
  VEC_constructor_elt_gc *elts;
};
# 1696 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern void protected_set_expr_location (tree, location_t);
# 1928 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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
# 1999 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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
# 2058 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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
# 2127 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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
# 2169 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern enum machine_mode vector_type_mode (const_tree);
# 2279 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
enum cv_qualifier
  {
    TYPE_UNQUALIFIED = 0x0,
    TYPE_QUAL_CONST = 0x1,
    TYPE_QUAL_VOLATILE = 0x2,
    TYPE_QUAL_RESTRICT = 0x4
  };
# 2402 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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

  enum machine_mode mode : 8;

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
# 2496 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
struct tree_type_non_common {
  struct tree_type_with_lang_specific with_lang_specific;
  tree values;
  tree minval;
  tree maxval;
  tree binfo;
};
# 2607 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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
# 2651 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
struct function;
# 2706 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
struct tree_decl_minimal {
  struct tree_common common;
  location_t locus;
  unsigned int uid;
  tree name;
  tree context;
};
# 2874 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
struct tree_decl_common {
  struct tree_decl_minimal common;
  tree size;

  enum machine_mode mode : 8;

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
# 3001 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
struct tree_decl_with_rtl {
  struct tree_decl_common common;
  rtx rtl;
};
# 3074 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
struct tree_field_decl {
  struct tree_decl_common common;

  tree offset;
  tree bit_field_type;
  tree qualifier;
  tree bit_offset;
  tree fcontext;
};
# 3100 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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
# 3125 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
struct tree_parm_decl {
  struct tree_decl_with_rtl common;
  rtx incoming_rtl;
  struct var_ann_d *ann;
};
# 3264 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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
 enum symbol_visibility visibility : 2;
 unsigned visibility_specified : 1;

 enum tls_model tls_model : 3;


 unsigned init_priority_p : 1;

 unsigned shadowed_for_var_p : 1;

 unsigned implicit_section_name_p : 1;

};

extern tree decl_debug_expr_lookup (tree);
extern void decl_debug_expr_insert (tree, tree);
# 3309 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
typedef unsigned short priority_type;

extern priority_type decl_init_priority_lookup (tree);
extern priority_type decl_fini_priority_lookup (tree);
extern void decl_init_priority_insert (tree, priority_type);
extern void decl_fini_priority_insert (tree, priority_type);
# 3348 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
struct tree_var_decl {
  struct tree_decl_with_vis common;
  struct var_ann_d *ann;
};
# 3370 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
struct
 tree_decl_non_common {
  struct tree_decl_with_vis common;

  tree saved_tree;

  tree arguments;

  tree result;

  tree vindex;
};
# 3500 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern VEC_tree_gc **decl_debug_args_lookup (tree);
extern VEC_tree_gc **decl_debug_args_insert (tree);
# 3542 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
struct tree_function_decl {
  struct tree_decl_non_common common;

  struct function *f;


  tree personality;


  tree function_specific_target;
  tree function_specific_optimization;





  enum built_in_function function_code : 11;
  enum built_in_class built_in_class : 2;

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
# 3617 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
struct tree_type_decl {
  struct tree_decl_non_common common;

};
# 3633 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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






union
                                                         tree_node {
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
# 4068 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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
# 4127 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
enum ptrmemfunc_vbit_where_t
{
  ptrmemfunc_vbit_in_pfn,
  ptrmemfunc_vbit_in_delta
};
# 4141 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern tree decl_assembler_name (tree);
extern bool decl_assembler_name_equal (tree decl, const_tree asmname);
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
# 4203 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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





static inline tree
build1_stat_loc (location_t loc, enum tree_code code, tree type,
   tree arg1 )
{
  tree t = build1_stat (code, type, arg1 );
  if (((t) && ((tree_code_type[(int) (((enum tree_code) (t)->base.code))]) >= tcc_reference && (tree_code_type[(int) (((enum tree_code) (t)->base.code))]) <= tcc_expression)))
    ((t))->exp.locus = (loc);
  return t;
}


static inline tree
build2_stat_loc (location_t loc, enum tree_code code, tree type, tree arg0,
   tree arg1 )
{
  tree t = build2_stat (code, type, arg0, arg1 );
  if (((t) && ((tree_code_type[(int) (((enum tree_code) (t)->base.code))]) >= tcc_reference && (tree_code_type[(int) (((enum tree_code) (t)->base.code))]) <= tcc_expression)))
    ((t))->exp.locus = (loc);
  return t;
}


static inline tree
build3_stat_loc (location_t loc, enum tree_code code, tree type, tree arg0,
   tree arg1, tree arg2 )
{
  tree t = build3_stat (code, type, arg0, arg1, arg2 );
  if (((t) && ((tree_code_type[(int) (((enum tree_code) (t)->base.code))]) >= tcc_reference && (tree_code_type[(int) (((enum tree_code) (t)->base.code))]) <= tcc_expression)))
    ((t))->exp.locus = (loc);
  return t;
}



static inline tree
build4_stat_loc (location_t loc, enum tree_code code, tree type, tree arg0,
   tree arg1, tree arg2, tree arg3 )
{
  tree t = build4_stat (code, type, arg0, arg1, arg2, arg3 );
  if (((t) && ((tree_code_type[(int) (((enum tree_code) (t)->base.code))]) >= tcc_reference && (tree_code_type[(int) (((enum tree_code) (t)->base.code))]) <= tcc_expression)))
    ((t))->exp.locus = (loc);
  return t;
}



static inline tree
build5_stat_loc (location_t loc, enum tree_code code, tree type, tree arg0,
   tree arg1, tree arg2, tree arg3, tree arg4 )
{
  tree t = build5_stat (code, type, arg0, arg1, arg2, arg3,
   arg4 );
  if (((t) && ((tree_code_type[(int) (((enum tree_code) (t)->base.code))]) >= tcc_reference && (tree_code_type[(int) (((enum tree_code) (t)->base.code))]) <= tcc_expression)))
    ((t))->exp.locus = (loc);
  return t;
}



static inline tree
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





static inline double_int
tree_to_double_int (const_tree cst)
{
  return ((cst)->int_cst.int_cst);
}

extern tree double_int_to_tree (tree, double_int);
extern bool double_int_fits_to_tree_p (const_tree, double_int);
extern tree force_fit_type_double (tree, double_int, int, bool);



static inline tree
build_int_cstu (tree type, unsigned long cst)
{
  return double_int_to_tree (type, uhwi_to_double_int (cst));
}

extern tree build_int_cst (tree, long);
extern tree build_int_cst_type (tree, long);
extern tree build_int_cst_wide (tree, unsigned long, long);
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
extern tree build_pointer_type_for_mode (tree, enum machine_mode, bool);
extern tree build_pointer_type (tree);
extern tree build_reference_type_for_mode (tree, enum machine_mode, bool);
extern tree build_reference_type (tree);
extern tree build_vector_type_for_mode (tree, enum machine_mode);
extern tree build_vector_type (tree innertype, int nunits);
extern tree build_opaque_vector_type (tree innertype, int nunits);
extern tree build_type_no_quals (tree);
extern tree build_index_type (tree);
extern tree build_array_type (tree, tree);
extern tree build_nonshared_array_type (tree, tree);
extern tree build_array_type_nelts (tree, unsigned long);
extern tree build_function_type (tree, tree);
extern tree build_function_type_list (tree, ...);
extern tree build_function_decl_skip_args (tree, bitmap, bool);
extern tree build_varargs_function_type_list (tree, ...);
extern tree build_function_type_array (tree, int, tree *);
extern tree build_varargs_function_type_array (tree, int, tree *);





extern tree build_method_type_directly (tree, tree, tree);
extern tree build_method_type (tree, tree);
extern tree build_offset_type (tree, tree);
extern tree build_complex_type (tree);
extern tree array_type_nelts (const_tree);
extern bool in_array_bounds_p (tree);
extern bool range_in_array_bounds_p (tree);

extern tree value_member (tree, tree);
extern tree purpose_member (const_tree, tree);
extern bool vec_member (const_tree, VEC_tree_gc *);
extern tree chain_index (int, tree);

extern int attribute_list_equal (const_tree, const_tree);
extern int attribute_list_contained (const_tree, const_tree);
extern int tree_int_cst_equal (const_tree, const_tree);
extern int tree_int_cst_lt (const_tree, const_tree);
extern int tree_int_cst_compare (const_tree, const_tree);
extern int host_integerp (const_tree, int)

  __attribute__ ((__pure__))

  ;
extern long tree_low_cst (const_tree, int);

extern inline __attribute__ ((__gnu_inline__)) long
tree_low_cst (const_tree t, int pos)
{
  ((void)(!(host_integerp (t, pos)) ? fancy_abort ("/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h", 4431, __FUNCTION__), 0 : 0));
  return (((t)->int_cst.int_cst).low);
}

extern long size_low_cst (const_tree);
extern int tree_int_cst_sgn (const_tree);
extern int tree_int_cst_sign_bit (const_tree);
extern unsigned int tree_int_cst_min_precision (tree, bool);
extern bool tree_expr_nonnegative_p (tree);
extern bool tree_expr_nonnegative_warnv_p (tree, bool *);
extern bool may_negate_without_overflow_p (const_tree);
extern tree strip_array_types (tree);
extern tree excess_precision_type (tree);



extern tree make_fract_type (int, int, int);
extern tree make_accum_type (int, int, int);
# 4480 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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







  const bool decl_required;


  const bool type_required;




  const bool function_type_required;
# 4538 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
  tree (*const handler) (tree *node, tree name, tree args,
     int flags, bool *no_add_attrs);

  const bool affects_type_identity;
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
# 4586 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
static inline tree
lookup_attribute (const char *attr_name, tree list)
{
  ((void)(0 && (attr_name[0] != '_')));

  if (list == (tree) __null)
    return (tree) __null;
  else



    return private_lookup_attribute (attr_name, strlen (attr_name), list);
}



extern bool private_is_attribute_p (const char *, size_t, const_tree);






static inline bool
is_attribute_p (const char *attr_name, const_tree ident)
{
  ((void)(0 && (attr_name[0] != '_')));



  return private_is_attribute_p (attr_name, strlen (attr_name), ident);
}





extern tree remove_attribute (const char *, tree);



extern tree merge_attributes (tree, tree);
# 4641 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern bool check_qualified_type (const_tree, const_tree, int);





extern tree get_qualified_type (tree, int);




extern tree build_qualified_type (tree, int);



extern tree build_aligned_type (tree, unsigned int);
# 4670 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern tree build_distinct_type_copy (tree);
extern tree build_variant_type_copy (tree);




extern void finish_builtin_struct (tree, const char *,
        tree, tree);





extern void layout_type (tree);
# 4692 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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
# 4747 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
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
extern void finalize_size_functions (void);
# 4824 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern unsigned int maximum_field_alignment;





extern tree chainon (tree, tree);



extern tree tree_cons_stat (tree, tree, tree );




extern tree tree_last (tree);



extern tree nreverse (tree);




extern int list_length (const_tree);



extern int fields_length (const_tree);



extern tree first_field (const_tree);




extern bool initializer_zerop (const_tree);



extern VEC_tree_gc *ctor_to_vec (tree);

extern bool categorize_ctor_elements (const_tree, long *,
          long *, bool *);

extern bool complete_ctor_at_level_p (const_tree, long, const_tree);



extern int integer_zerop (const_tree);



extern int integer_onep (const_tree);




extern int integer_all_onesp (const_tree);




extern int integer_pow2p (const_tree);




extern int integer_nonzerop (const_tree);

extern bool cst_and_fits_in_hwi (const_tree);
extern tree num_ending_zeros (const_tree);




extern int fixed_zerop (const_tree);




extern tree staticp (tree);





extern tree save_expr (tree);




extern tree skip_simple_arithmetic (tree);



enum tree_node_structure_enum tree_node_structure (const_tree);




extern bool contains_placeholder_p (const_tree);
# 4938 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern bool type_contains_placeholder_p (tree);
# 4947 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern void find_placeholder_in_expr (tree, VEC_tree_heap **);
# 4965 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern tree substitute_in_expr (tree, tree, tree);
# 4976 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern tree substitute_placeholder_in_expr (tree, tree);
# 4991 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern tree variable_size (tree);





extern tree stabilize_reference (tree);





extern tree stabilize_reference_1 (tree);






extern tree get_unwidened (tree, tree);






extern tree get_narrower (tree, int *);



static inline bool
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
      return true;

    default:
      return false;
    }
}





extern tree get_inner_reference (tree, long *, long *,
     tree *, enum machine_mode *, int *, int *,
     bool);





extern bool contains_packed_reference (const_tree exp);




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



static inline void
function_args_iter_init (function_args_iterator *i, const_tree fntype)
{
  i->next = ((fntype)->type_non_common.values);
}




static inline tree *
function_args_iter_cond_ptr (function_args_iterator *i)
{
  return (i->next) ? &((i->next)->list.value) : __null;
}




static inline tree
function_args_iter_cond (function_args_iterator *i)
{
  return (i->next) ? ((i->next)->list.value) : (tree) __null;
}


static inline void
function_args_iter_next (function_args_iterator *i)
{
  ((void)(!(i->next != (tree) __null) ? fancy_abort ("/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h", 5139, __FUNCTION__), 0 : 0));
  i->next = ((i->next)->common.chain);
}



static inline bool
inlined_function_outer_scope_p (const_tree block)
{
 return ((block)->block.locus) != ((source_location) 0);
}
# 5170 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern unsigned crc32_string (unsigned, const char *);
extern unsigned crc32_byte (unsigned, char);
extern void clean_symbol_name (char *);
extern tree get_file_function_name (const char *);
extern tree get_callee_fndecl (const_tree);
extern int type_num_arguments (const_tree);
extern bool associative_tree_code (enum tree_code);
extern bool commutative_tree_code (enum tree_code);
extern bool commutative_ternary_tree_code (enum tree_code);
extern tree upper_bound_in_type (tree, tree);
extern tree lower_bound_in_type (tree, tree);
extern int operand_equal_for_phi_arg_p (const_tree, const_tree);
extern tree create_artificial_label (location_t);
extern const char *get_name (tree);
extern bool stdarg_p (const_tree);
extern bool prototype_p (tree);
extern bool is_typedef_decl (tree x);
extern bool typedef_variant_p (tree);
extern bool auto_var_in_fn_p (const_tree, const_tree);
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





static inline int
struct_ptr_eq (const void *a, const void *b)
{
  const void * const * x = (const void * const *) a;
  const void * const * y = (const void * const *) b;
  return *x == *y;
}

static inline hashval_t
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
extern bool fold_convertible_p (const_tree, const_tree);


extern tree fold_convert_loc (location_t, tree, tree);
extern tree fold_single_bit_test (location_t, enum tree_code, tree, tree, tree);
extern tree fold_ignored_result (tree);
extern tree fold_abs_const (tree, tree);
extern tree fold_indirect_ref_1 (location_t, tree, tree);
extern void fold_defer_overflow_warnings (void);
extern void fold_undefer_overflow_warnings (bool, const_gimple, int);
extern void fold_undefer_and_ignore_overflow_warnings (void);
extern bool fold_deferring_overflow_warnings_p (void);
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
extern tree build_invariant_address (tree, tree, long);
extern tree constant_boolean_node (bool, tree);
extern tree div_if_zero_remainder (enum tree_code, const_tree, const_tree);

extern bool tree_swap_operands_p (const_tree, const_tree, bool);
extern enum tree_code swap_tree_comparison (enum tree_code);

extern bool ptr_difference_const (tree, tree, long *);
extern enum tree_code invert_tree_comparison (enum tree_code, bool);

extern bool tree_expr_nonzero_p (tree);
extern bool tree_unary_nonzero_warnv_p (enum tree_code, tree, tree, bool *);
extern bool tree_binary_nonzero_warnv_p (enum tree_code, tree, tree, tree op1,
                                         bool *);
extern bool tree_single_nonzero_warnv_p (tree, bool *);
extern bool tree_unary_nonnegative_warnv_p (enum tree_code, tree, tree, bool *);
extern bool tree_binary_nonnegative_warnv_p (enum tree_code, tree, tree, tree,
                                             bool *);
extern bool tree_single_nonnegative_warnv_p (tree t, bool *strict_overflow_p);
extern bool tree_invalid_nonnegative_warnv_p (tree t, bool *strict_overflow_p);
extern bool tree_call_nonnegative_warnv_p (tree, tree, tree, tree, bool *);

extern bool tree_expr_nonzero_warnv_p (tree, bool *);

extern bool fold_real_zero_addition_p (const_tree, const_tree, int);
extern tree combine_comparisons (location_t, enum tree_code, enum tree_code,
     enum tree_code, tree, tree, tree);
extern void debug_fold_checksum (const_tree);


static inline bool
truth_value_p (enum tree_code code)
{
  return (tree_code_type[(int) (code)] == tcc_comparison
   || code == TRUTH_AND_EXPR || code == TRUTH_ANDIF_EXPR
   || code == TRUTH_OR_EXPR || code == TRUTH_ORIF_EXPR
   || code == TRUTH_XOR_EXPR || code == TRUTH_NOT_EXPR);
}



static inline bool
ptrofftype_p (tree type)
{
  return ((((enum tree_code) (type)->base.code) == ENUMERAL_TYPE || ((enum tree_code) (type)->base.code) == BOOLEAN_TYPE || ((enum tree_code) (type)->base.code) == INTEGER_TYPE)
   && ((type)->type_common.precision) == ((sizetype_tab[(int) SIZETYPE])->type_common.precision)
   && ((type)->base.unsigned_flag) == ((sizetype_tab[(int) SIZETYPE])->base.unsigned_flag));
}



static inline tree
convert_to_ptrofftype_loc (location_t loc, tree off)
{
  return fold_convert_loc (loc, sizetype_tab[(int) SIZETYPE], off);
}



static inline tree
fold_build_pointer_plus_loc (location_t loc, tree ptr, tree off)
{
  return fold_build2_stat_loc (loc, POINTER_PLUS_EXPR, ((ptr)->typed.type), ptr, fold_convert_loc (loc, sizetype_tab[(int) SIZETYPE], off) )
                                                ;
}




static inline tree
fold_build_pointer_plus_hwi_loc (location_t loc, tree ptr, long off)
{
  return fold_build2_stat_loc (loc, POINTER_PLUS_EXPR, ((ptr)->typed.type), ptr, size_int_kind (off, SIZETYPE) )
                         ;
}




extern bool avoid_folding_inline_builtin (tree);
extern tree fold_call_expr (location_t, tree, bool);
extern tree fold_builtin_fputs (location_t, tree, tree, bool, bool, tree);
extern tree fold_builtin_strcpy (location_t, tree, tree, tree, tree);
extern tree fold_builtin_strncpy (location_t, tree, tree, tree, tree, tree);
extern tree fold_builtin_memory_chk (location_t, tree, tree, tree, tree, tree, tree, bool,
         enum built_in_function);
extern tree fold_builtin_stxcpy_chk (location_t, tree, tree, tree, tree, tree, bool,
         enum built_in_function);
extern tree fold_builtin_stxncpy_chk (location_t, tree, tree, tree, tree, tree, bool,
          enum built_in_function);
extern tree fold_builtin_snprintf_chk (location_t, tree, tree, enum built_in_function);
extern bool fold_builtin_next_arg (tree, bool);
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
extern bool validate_arglist (const_tree, ...);
extern rtx builtin_memset_read_str (void *, long, enum machine_mode);
extern bool is_builtin_fn (tree);
extern unsigned int get_object_alignment_1 (tree, unsigned long *);
extern unsigned int get_object_alignment (tree);
extern unsigned int get_object_or_type_alignment (tree);
extern unsigned int get_pointer_alignment_1 (tree, unsigned long *);
extern unsigned int get_pointer_alignment (tree);
extern tree fold_call_stmt (gimple, bool);
extern tree gimple_fold_builtin_snprintf_chk (gimple, tree, enum built_in_function);
extern tree make_range (tree, int *, tree *, tree *, bool *);
extern tree make_range_step (location_t, enum tree_code, tree, tree, tree,
        tree *, tree *, int *, bool *);
extern tree build_range_check (location_t, tree, tree, int, tree, tree);
extern bool merge_ranges (int *, tree *, tree *, int, tree, tree, int,
     tree, tree);
extern void set_builtin_user_assembler_name (tree decl, const char *asmspec);
extern bool is_simple_builtin (tree);
extern bool is_inexpensive_builtin (tree);


extern tree strip_float_extensions (tree);


extern int really_constant_p (const_tree);
extern bool decl_address_invariant_p (const_tree);
extern bool decl_address_ip_invariant_p (const_tree);
extern bool int_fits_type_p (const_tree, const_tree);

extern void get_type_static_bounds (const_tree, mpz_t, mpz_t);

extern bool variably_modified_type_p (tree, tree);
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
extern bool needs_to_live_in_memory (const_tree);
extern tree reconstruct_complex_type (tree, tree);

extern int real_onep (const_tree);
extern int real_twop (const_tree);
extern int real_minus_onep (const_tree);
extern void init_ttree (void);
extern void build_common_tree_nodes (bool, bool);
extern void build_common_builtin_nodes (void);
extern tree build_nonstandard_integer_type (unsigned long, int);
extern tree build_range_type (tree, tree, tree);
extern tree build_nonshared_range_type (tree, tree, tree);
extern bool subrange_type_for_debug_p (const_tree, tree *, tree *);
extern long int_cst_value (const_tree);
extern long widest_int_cst_value (const_tree);

extern tree *tree_block (tree);
extern location_t *block_nonartificial_location (tree);
extern location_t tree_nonartificial_location (tree);

extern tree block_ultimate_origin (const_tree);

extern tree get_binfo_at_offset (tree, long, tree);


extern tree build_addr (tree, tree);


extern void expand_main_function (void);
extern void expand_function_end (void);
extern void expand_function_start (tree);
extern void stack_protect_prologue (void);
extern void stack_protect_epilogue (void);
extern void init_dummy_function_start (void);
extern void expand_dummy_function_end (void);
extern unsigned int init_function_for_compilation (void);
extern void allocate_struct_function (tree, bool);
extern void push_struct_function (tree fndecl);
extern void init_function_start (tree);
extern bool use_register_for_decl (const_tree);
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



extern bool debug_find_tree (tree, tree);


extern tree unsave_expr_now (tree);
extern tree build_duplicate_type (tree);
# 5612 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern int flags_from_decl_or_type (const_tree);
extern int call_expr_flags (const_tree);
# 5639 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern int setjmp_call_p (const_tree);
extern bool gimple_alloca_call_p (const_gimple);
extern bool alloca_call_p (const_tree);
extern bool must_pass_in_stack_var_size (enum machine_mode, const_tree);
extern bool must_pass_in_stack_var_size_or_pad (enum machine_mode, const_tree);



extern const struct attribute_spec *lookup_attribute_spec (const_tree);

extern void init_attributes (void);
# 5659 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern tree decl_attributes (tree *, tree, int);

extern void apply_tm_attr (tree, tree);


extern void set_decl_abstract_flags (tree, int);
extern void set_decl_origin_self (tree);


extern void set_min_and_max_values_for_integral_type (tree, int, bool);
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
extern bool decl_replaceable_p (tree);
extern bool decl_binds_to_current_def_p (tree);





typedef struct pointer_set_t symbol_alias_set_t;

extern void symbol_alias_set_destroy (symbol_alias_set_t *);
extern int symbol_alias_set_contains (const symbol_alias_set_t *, tree);
extern symbol_alias_set_t * propagate_aliases_backward (bool (*)
        (tree, tree, void *),
       void *);


extern void expand_computed_goto (tree);
extern bool parse_output_constraint (const char **, int, int, int,
         bool *, bool *, bool *);
extern bool parse_input_constraint (const char **, int, int, int, int,
        const char * const *, bool *, bool *);
extern void expand_asm_stmt (gimple);
extern tree resolve_asm_operand_names (tree, tree, tree, tree);
extern bool expand_switch_using_bit_tests_p (tree, tree, unsigned int,
          unsigned int);
extern void expand_case (gimple);
extern void expand_decl (tree);
# 5725 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
struct pointer_set_t;



typedef tree (*walk_tree_fn) (tree *, int *, void *);



typedef tree (*walk_tree_lh) (tree *, int *, tree (*) (tree *, int *, void *),
         void *, struct pointer_set_t*);

extern tree walk_tree_1 (tree*, walk_tree_fn, void*, struct pointer_set_t*,
    walk_tree_lh);
extern tree walk_tree_without_duplicates_1 (tree*, walk_tree_fn, void*,
         walk_tree_lh);
# 5748 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
extern void set_decl_rtl (tree, rtx);
extern void set_decl_incoming_rtl (tree, rtx, bool);



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




extern bool in_gimple_form;


extern tree get_base_address (tree t);
extern void mark_addressable (tree);



struct tree_map_base {
  tree from;
};

extern int tree_map_base_eq (const void *, const void *);
extern unsigned int tree_map_base_hash (const void *);
extern int tree_map_base_marked_p (const void *);
extern bool list_equal_p (const_tree, const_tree);



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


extern bool ssa_name_nonnegative_p (const_tree);


extern void init_object_sizes (void);
extern void fini_object_sizes (void);
extern unsigned long compute_builtin_object_size (tree, int);


extern unsigned long highest_pow2_factor (const_tree);
extern tree build_personality_function (const char *);


extern tree build_tm_abort_call (location_t, bool);
extern bool is_tm_safe (const_tree);
extern bool is_tm_pure (const_tree);
extern bool is_tm_may_cancel_outer (tree);
extern bool is_tm_ending_fndecl (tree);
extern void record_tm_replacement (tree, tree);
extern void tm_malloc_replacement (tree);

static inline bool
is_tm_safe_or_pure (const_tree x)
{
  return is_tm_safe (x) || is_tm_pure (x);
}



void init_inline_once (void);




static inline int
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



static inline void
init_call_expr_arg_iterator (tree exp, call_expr_arg_iterator *iter)
{
  iter->t = exp;
  iter->n = (((int)((((exp)->exp.operands[0])->int_cst.int_cst).low)) - 3);
  iter->i = 0;
}

static inline void
init_const_call_expr_arg_iterator (const_tree exp, const_call_expr_arg_iterator *iter)
{
  iter->t = exp;
  iter->n = (((int)((((exp)->exp.operands[0])->int_cst.int_cst).low)) - 3);
  iter->i = 0;
}



static inline tree
next_call_expr_arg (call_expr_arg_iterator *iter)
{
  tree result;
  if (iter->i >= iter->n)
    return (tree) __null;
  result = (((iter->t))->exp.operands[(iter->i) + 3]);
  iter->i++;
  return result;
}

static inline const_tree
next_const_call_expr_arg (const_call_expr_arg_iterator *iter)
{
  const_tree result;
  if (iter->i >= iter->n)
    return (tree) __null;
  result = (((iter->t))->exp.operands[(iter->i) + 3]);
  iter->i++;
  return result;
}





static inline tree
first_call_expr_arg (tree exp, call_expr_arg_iterator *iter)
{
  init_call_expr_arg_iterator (exp, iter);
  return next_call_expr_arg (iter);
}

static inline const_tree
first_const_call_expr_arg (const_tree exp, const_call_expr_arg_iterator *iter)
{
  init_const_call_expr_arg_iterator (exp, iter);
  return next_const_call_expr_arg (iter);
}



static inline bool
more_call_expr_args_p (const call_expr_arg_iterator *iter)
{
  return (iter->i < iter->n);
}

static inline bool
more_const_call_expr_args_p (const const_call_expr_arg_iterator *iter)
{
  return (iter->i < iter->n);
}
# 6008 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
static inline bool
is_lang_specific (tree t)
{
  return ((enum tree_code) (t)->base.code) == LANG_TYPE || ((enum tree_code) (t)->base.code) >= ((int) LAST_AND_UNUSED_TREE_CODE);
}


extern bool block_may_fallthru (const_tree);
# 6024 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h"
typedef struct builtin_info_type_d {
  tree decl[(int)END_BUILTINS];
  bool implicit_p[(int)END_BUILTINS];
} builtin_info_type;

extern builtin_info_type builtin_info;






static inline tree
builtin_decl_explicit (enum built_in_function fncode)
{
  ((void)(0 && ((((unsigned long) ((int)fncode) - (unsigned long) (((int)BUILT_IN_NONE) + 1) <= (unsigned long) (((int) END_BUILTINS) - 1) - (unsigned long) (((int)BUILT_IN_NONE) + 1))))));

  return builtin_info.decl[(size_t)fncode];
}


static inline tree
builtin_decl_implicit (enum built_in_function fncode)
{
  size_t uns_fncode = (size_t)fncode;
  ((void)(0 && ((((unsigned long) ((int)fncode) - (unsigned long) (((int)BUILT_IN_NONE) + 1) <= (unsigned long) (((int) END_BUILTINS) - 1) - (unsigned long) (((int)BUILT_IN_NONE) + 1))))));

  if (!builtin_info.implicit_p[uns_fncode])
    return (tree) __null;

  return builtin_info.decl[uns_fncode];
}




static inline void
set_builtin_decl (enum built_in_function fncode, tree decl, bool implicit_p)
{
  size_t ufncode = (size_t)fncode;

  ((void)(0 && ((((unsigned long) ((int)fncode) - (unsigned long) (((int)BUILT_IN_NONE) + 1) <= (unsigned long) (((int) END_BUILTINS) - 1) - (unsigned long) (((int)BUILT_IN_NONE) + 1))) && (decl != (tree) __null || !implicit_p))))
                                               ;

  builtin_info.decl[ufncode] = decl;
  builtin_info.implicit_p[ufncode] = implicit_p;
}



static inline void
set_builtin_decl_implicit_p (enum built_in_function fncode, bool implicit_p)
{
  size_t uns_fncode = (size_t)fncode;

  ((void)(0 && ((((unsigned long) ((int)fncode) - (unsigned long) (((int)BUILT_IN_NONE) + 1) <= (unsigned long) (((int) END_BUILTINS) - 1) - (unsigned long) (((int)BUILT_IN_NONE) + 1))) && builtin_info.decl[uns_fncode] != (tree) __null)))
                                                       ;

  builtin_info.implicit_p[uns_fncode] = implicit_p;
}




static inline bool
builtin_decl_explicit_p (enum built_in_function fncode)
{
  ((void)(0 && ((((unsigned long) ((int)fncode) - (unsigned long) (((int)BUILT_IN_NONE) + 1) <= (unsigned long) (((int) END_BUILTINS) - 1) - (unsigned long) (((int)BUILT_IN_NONE) + 1))))));
  return (builtin_info.decl[(size_t)fncode] != (tree) __null);
}



static inline bool
builtin_decl_implicit_p (enum built_in_function fncode)
{
  size_t uns_fncode = (size_t)fncode;

  ((void)(0 && ((((unsigned long) ((int)fncode) - (unsigned long) (((int)BUILT_IN_NONE) + 1) <= (unsigned long) (((int) END_BUILTINS) - 1) - (unsigned long) (((int)BUILT_IN_NONE) + 1))))));
  return (builtin_info.decl[uns_fncode] != (tree) __null
   && builtin_info.implicit_p[uns_fncode]);
}
# 25 "../../../src/plugin-utils.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 1
# 20 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/insn-constants.h" 1
# 78 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/insn-constants.h"
enum unspec {
  UNSPEC_GOT = 0,
  UNSPEC_GOTOFF = 1,
  UNSPEC_GOTPCREL = 2,
  UNSPEC_GOTTPOFF = 3,
  UNSPEC_TPOFF = 4,
  UNSPEC_NTPOFF = 5,
  UNSPEC_DTPOFF = 6,
  UNSPEC_GOTNTPOFF = 7,
  UNSPEC_INDNTPOFF = 8,
  UNSPEC_PLTOFF = 9,
  UNSPEC_MACHOPIC_OFFSET = 10,
  UNSPEC_PCREL = 11,
  UNSPEC_STACK_ALLOC = 12,
  UNSPEC_SET_GOT = 13,
  UNSPEC_REG_SAVE = 14,
  UNSPEC_DEF_CFA = 15,
  UNSPEC_SET_RIP = 16,
  UNSPEC_SET_GOT_OFFSET = 17,
  UNSPEC_MEMORY_BLOCKAGE = 18,
  UNSPEC_STACK_CHECK = 19,
  UNSPEC_TP = 20,
  UNSPEC_TLS_GD = 21,
  UNSPEC_TLS_LD_BASE = 22,
  UNSPEC_TLSDESC = 23,
  UNSPEC_TLS_IE_SUN = 24,
  UNSPEC_SCAS = 25,
  UNSPEC_FNSTSW = 26,
  UNSPEC_SAHF = 27,
  UNSPEC_PARITY = 28,
  UNSPEC_FSTCW = 29,
  UNSPEC_ADD_CARRY = 30,
  UNSPEC_FLDCW = 31,
  UNSPEC_REP = 32,
  UNSPEC_LD_MPIC = 33,
  UNSPEC_TRUNC_NOOP = 34,
  UNSPEC_DIV_ALREADY_SPLIT = 35,
  UNSPEC_MS_TO_SYSV_CALL = 36,
  UNSPEC_CALL_NEEDS_VZEROUPPER = 37,
  UNSPEC_PAUSE = 38,
  UNSPEC_FIX_NOTRUNC = 39,
  UNSPEC_MASKMOV = 40,
  UNSPEC_MOVMSK = 41,
  UNSPEC_RCP = 42,
  UNSPEC_RSQRT = 43,
  UNSPEC_PSADBW = 44,
  UNSPEC_COPYSIGN = 45,
  UNSPEC_IEEE_MIN = 46,
  UNSPEC_IEEE_MAX = 47,
  UNSPEC_SIN = 48,
  UNSPEC_COS = 49,
  UNSPEC_FPATAN = 50,
  UNSPEC_FYL2X = 51,
  UNSPEC_FYL2XP1 = 52,
  UNSPEC_FRNDINT = 53,
  UNSPEC_FIST = 54,
  UNSPEC_F2XM1 = 55,
  UNSPEC_TAN = 56,
  UNSPEC_FXAM = 57,
  UNSPEC_FRNDINT_FLOOR = 58,
  UNSPEC_FRNDINT_CEIL = 59,
  UNSPEC_FRNDINT_TRUNC = 60,
  UNSPEC_FRNDINT_MASK_PM = 61,
  UNSPEC_FIST_FLOOR = 62,
  UNSPEC_FIST_CEIL = 63,
  UNSPEC_SINCOS_COS = 64,
  UNSPEC_SINCOS_SIN = 65,
  UNSPEC_XTRACT_FRACT = 66,
  UNSPEC_XTRACT_EXP = 67,
  UNSPEC_FSCALE_FRACT = 68,
  UNSPEC_FSCALE_EXP = 69,
  UNSPEC_FPREM_F = 70,
  UNSPEC_FPREM_U = 71,
  UNSPEC_FPREM1_F = 72,
  UNSPEC_FPREM1_U = 73,
  UNSPEC_C2_FLAG = 74,
  UNSPEC_FXAM_MEM = 75,
  UNSPEC_SP_SET = 76,
  UNSPEC_SP_TEST = 77,
  UNSPEC_SP_TLS_SET = 78,
  UNSPEC_SP_TLS_TEST = 79,
  UNSPEC_ROUND = 80,
  UNSPEC_CRC32 = 81,
  UNSPEC_BEXTR = 82,
  UNSPEC_PDEP = 83,
  UNSPEC_PEXT = 84,
  UNSPEC_MOVNTQ = 85,
  UNSPEC_PFRCP = 86,
  UNSPEC_PFRCPIT1 = 87,
  UNSPEC_PFRCPIT2 = 88,
  UNSPEC_PFRSQRT = 89,
  UNSPEC_PFRSQIT1 = 90,
  UNSPEC_MOVNT = 91,
  UNSPEC_MOVU = 92,
  UNSPEC_LDDQU = 93,
  UNSPEC_PSHUFB = 94,
  UNSPEC_PSIGN = 95,
  UNSPEC_PALIGNR = 96,
  UNSPEC_EXTRQI = 97,
  UNSPEC_EXTRQ = 98,
  UNSPEC_INSERTQI = 99,
  UNSPEC_INSERTQ = 100,
  UNSPEC_BLENDV = 101,
  UNSPEC_INSERTPS = 102,
  UNSPEC_DP = 103,
  UNSPEC_MOVNTDQA = 104,
  UNSPEC_MPSADBW = 105,
  UNSPEC_PHMINPOSUW = 106,
  UNSPEC_PTEST = 107,
  UNSPEC_PCMPESTR = 108,
  UNSPEC_PCMPISTR = 109,
  UNSPEC_FMADDSUB = 110,
  UNSPEC_XOP_UNSIGNED_CMP = 111,
  UNSPEC_XOP_TRUEFALSE = 112,
  UNSPEC_XOP_PERMUTE = 113,
  UNSPEC_FRCZ = 114,
  UNSPEC_AESENC = 115,
  UNSPEC_AESENCLAST = 116,
  UNSPEC_AESDEC = 117,
  UNSPEC_AESDECLAST = 118,
  UNSPEC_AESIMC = 119,
  UNSPEC_AESKEYGENASSIST = 120,
  UNSPEC_PCLMUL = 121,
  UNSPEC_PCMP = 122,
  UNSPEC_VPERMIL = 123,
  UNSPEC_VPERMIL2 = 124,
  UNSPEC_VPERMIL2F128 = 125,
  UNSPEC_CAST = 126,
  UNSPEC_VTESTP = 127,
  UNSPEC_VCVTPH2PS = 128,
  UNSPEC_VCVTPS2PH = 129,
  UNSPEC_VPERMSI = 130,
  UNSPEC_VPERMDF = 131,
  UNSPEC_VPERMSF = 132,
  UNSPEC_VPERMTI = 133,
  UNSPEC_GATHER = 134,
  UNSPEC_VSIBADDR = 135,
  UNSPEC_LFENCE = 136,
  UNSPEC_SFENCE = 137,
  UNSPEC_MFENCE = 138,
  UNSPEC_MOVA = 139,
  UNSPEC_LDA = 140,
  UNSPEC_STA = 141
};

extern const char *const unspec_strings[];

enum unspecv {
  UNSPECV_BLOCKAGE = 0,
  UNSPECV_STACK_PROBE = 1,
  UNSPECV_PROBE_STACK_RANGE = 2,
  UNSPECV_ALIGN = 3,
  UNSPECV_PROLOGUE_USE = 4,
  UNSPECV_SPLIT_STACK_RETURN = 5,
  UNSPECV_CLD = 6,
  UNSPECV_NOPS = 7,
  UNSPECV_RDTSC = 8,
  UNSPECV_RDTSCP = 9,
  UNSPECV_RDPMC = 10,
  UNSPECV_LLWP_INTRINSIC = 11,
  UNSPECV_SLWP_INTRINSIC = 12,
  UNSPECV_LWPVAL_INTRINSIC = 13,
  UNSPECV_LWPINS_INTRINSIC = 14,
  UNSPECV_RDFSBASE = 15,
  UNSPECV_RDGSBASE = 16,
  UNSPECV_WRFSBASE = 17,
  UNSPECV_WRGSBASE = 18,
  UNSPECV_RDRAND = 19,
  UNSPECV_EMMS = 20,
  UNSPECV_FEMMS = 21,
  UNSPECV_LDMXCSR = 22,
  UNSPECV_STMXCSR = 23,
  UNSPECV_CLFLUSH = 24,
  UNSPECV_MONITOR = 25,
  UNSPECV_MWAIT = 26,
  UNSPECV_VZEROALL = 27,
  UNSPECV_VZEROUPPER = 28,
  UNSPECV_CMPXCHG_1 = 29,
  UNSPECV_CMPXCHG_2 = 30,
  UNSPECV_CMPXCHG_3 = 31,
  UNSPECV_CMPXCHG_4 = 32,
  UNSPECV_XCHG = 33,
  UNSPECV_LOCK = 34
};

extern const char *const unspecv_strings[];
# 21 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/vxworks-dummy.h" 1
# 22 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/biarch64.h" 1
# 23 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h" 1
# 85 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/vxworks-dummy.h" 1
# 86 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h" 2

# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386-opts.h" 1
# 88 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h" 2
# 100 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h"
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
# 253 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h"
enum ix86_tune_indices {
  X86_TUNE_USE_LEAVE,
  X86_TUNE_PUSH_MEMORY,
  X86_TUNE_ZERO_EXTEND_WITH_AND,
  X86_TUNE_UNROLL_STRLEN,
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
  X86_TUNE_SINGLE_POP,
  X86_TUNE_DOUBLE_POP,
  X86_TUNE_SINGLE_PUSH,
  X86_TUNE_DOUBLE_PUSH,
  X86_TUNE_INTEGER_DFMODE_MOVES,
  X86_TUNE_PARTIAL_REG_DEPENDENCY,
  X86_TUNE_SSE_PARTIAL_REG_DEPENDENCY,
  X86_TUNE_SSE_UNALIGNED_LOAD_OPTIMAL,
  X86_TUNE_SSE_UNALIGNED_STORE_OPTIMAL,
  X86_TUNE_SSE_PACKED_SINGLE_INSN_OPTIMAL,
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
  X86_TUNE_PAD_SHORT_FUNCTION,
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
  X86_TUNE_VECTORIZE_DOUBLE,
  X86_TUNE_SOFTWARE_PREFETCHING_BENEFICIAL,
  X86_TUNE_AVX128_OPTIMAL,
  X86_TUNE_REASSOC_INT_TO_PARALLEL,
  X86_TUNE_REASSOC_FP_TO_PARALLEL,

  X86_TUNE_LAST
};

extern unsigned char ix86_tune_features[X86_TUNE_LAST];
# 427 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h"
enum ix86_arch_indices {
  X86_ARCH_CMOV,
  X86_ARCH_CMPXCHG,
  X86_ARCH_CMPXCHG8B,
  X86_ARCH_XADD,
  X86_ARCH_BSWAP,

  X86_ARCH_LAST
};

extern unsigned char ix86_arch_features[X86_ARCH_LAST];
# 452 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h"
extern int x86_prefetch_sse;
# 476 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h"
extern tree x86_mfence;
# 527 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h"
extern const char *host_detect_local_cpu (int argc, const char **argv);
# 576 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h"
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
  TARGET_CPU_DEFAULT_corei7,
  TARGET_CPU_DEFAULT_atom,

  TARGET_CPU_DEFAULT_geode,
  TARGET_CPU_DEFAULT_k6,
  TARGET_CPU_DEFAULT_k6_2,
  TARGET_CPU_DEFAULT_k6_3,
  TARGET_CPU_DEFAULT_athlon,
  TARGET_CPU_DEFAULT_athlon_sse,
  TARGET_CPU_DEFAULT_k8,
  TARGET_CPU_DEFAULT_amdfam10,
  TARGET_CPU_DEFAULT_bdver1,
  TARGET_CPU_DEFAULT_bdver2,
  TARGET_CPU_DEFAULT_btver1,

  TARGET_CPU_DEFAULT_max
};
# 1179 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h"
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
# 1469 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h"
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
  int caller;
  int float_in_sse;


  enum calling_abi call_abi;

} CUMULATIVE_ARGS;
# 1899 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h"
extern int const dbx_register_map[53];
extern int const dbx64_register_map[53];
extern int const svr4_dbx_register_map[53];
# 2030 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h"
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
  PROCESSOR_CORE2_32,
  PROCESSOR_CORE2_64,
  PROCESSOR_COREI7_32,
  PROCESSOR_COREI7_64,
  PROCESSOR_GENERIC32,
  PROCESSOR_GENERIC64,
  PROCESSOR_AMDFAM10,
  PROCESSOR_BDVER1,
  PROCESSOR_BDVER2,
  PROCESSOR_BTVER1,
  PROCESSOR_ATOM,
  PROCESSOR_max
};

extern enum processor_type ix86_tune;
extern enum processor_type ix86_arch;






extern unsigned int ix86_preferred_stack_boundary;
extern unsigned int ix86_incoming_stack_boundary;


extern enum reg_class const regclass_map[53];

enum ix86_fpcmp_strategy {
  IX86_FPCMP_SAHF,
  IX86_FPCMP_COMI,
  IX86_FPCMP_ARITH
};
# 2091 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h"
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
# 2167 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h"
struct machine_frame_state
{



  rtx cfa_reg;
  long cfa_offset;





  long sp_offset;
  long fp_offset;





  int red_zone_offset;





  unsigned int sp_valid : 1;
  unsigned int fp_valid : 1;
  unsigned int drap_valid : 1;




  unsigned int realigned : 1;
};


struct seh_frame_state;

struct machine_function {
  struct stack_local_entry *stack_locals;
  const char *some_ld_name;
  int varargs_gpr_size;
  int varargs_fpr_size;
  int optimize_mode_switching[MAX_386_ENTITIES];



  int use_fast_prologue_epilogue_nregs;






  rtx split_stack_varargs_pointer;



  enum calling_abi call_abi : 8;


  unsigned int accesses_prev_frame : 1;


  unsigned int needs_cld : 1;



  unsigned int use_fast_prologue_epilogue : 1;
# 2246 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h"
  unsigned int tls_descriptor_call_expanded_p : 1;



  unsigned int static_chain_on_stack : 1;


  unsigned int caller_pass_avx256_p : 1;


  unsigned int caller_return_avx256_p : 1;


  unsigned int callee_pass_avx256_p : 1;


  unsigned int callee_return_avx256_p : 1;


  unsigned int rescan_vzeroupper_p : 1;



  struct machine_frame_state fs;


  struct seh_frame_state * seh;
};
# 2311 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/i386.h"
extern void debug_ready_dispatch (void);
extern void debug_dispatch_window (int);
# 24 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/linux-android.h" 1
# 25 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/unix.h" 1
# 26 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/att.h" 1
# 27 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/dbxelf.h" 1
# 28 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/elfos.h" 1
# 29 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/gnu-user.h" 1
# 30 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/glibc-stdint.h" 1
# 31 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/x86-64.h" 1
# 32 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/gnu-user64.h" 1
# 33 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/linux.h" 1
# 34 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/i386/linux64.h" 1
# 35 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/config/initfini-array.h" 1
# 36 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2


# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/insn-flags.h" 1
# 2780 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/insn-flags.h"
extern rtx gen_x86_fnstsw_1 (rtx);
extern rtx gen_x86_sahf_1 (rtx);
extern rtx gen_swapxf (rtx, rtx);
extern rtx gen_zero_extendsidi2_1 (rtx, rtx);
extern rtx gen_zero_extendqidi2 (rtx, rtx);
extern rtx gen_zero_extendhidi2 (rtx, rtx);
extern rtx gen_zero_extendhisi2_and (rtx, rtx);
extern rtx gen_extendsidi2_1 (rtx, rtx);
extern rtx gen_extendqidi2 (rtx, rtx);
extern rtx gen_extendhidi2 (rtx, rtx);
extern rtx gen_extendhisi2 (rtx, rtx);
extern rtx gen_extendqisi2 (rtx, rtx);
extern rtx gen_extendqihi2 (rtx, rtx);
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
extern rtx gen_addsi_1_zext (rtx, rtx, rtx);
extern rtx gen_addqi_ext_1 (rtx, rtx, rtx);
extern rtx gen_divmodsi4_1 (rtx, rtx, rtx, rtx);
extern rtx gen_divmoddi4_1 (rtx, rtx, rtx, rtx);
extern rtx gen_divmodhiqi3 (rtx, rtx, rtx);
extern rtx gen_udivmodsi4_1 (rtx, rtx, rtx, rtx);
extern rtx gen_udivmoddi4_1 (rtx, rtx, rtx, rtx);
extern rtx gen_udivmodhiqi3 (rtx, rtx, rtx);
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
extern rtx gen_x86_shrd (rtx, rtx, rtx);
extern rtx gen_ashrdi3_cvt (rtx, rtx, rtx);
extern rtx gen_ashrsi3_cvt (rtx, rtx, rtx);
extern rtx gen_ix86_rotldi3_doubleword (rtx, rtx, rtx);
extern rtx gen_ix86_rotlti3_doubleword (rtx, rtx, rtx);
extern rtx gen_ix86_rotrdi3_doubleword (rtx, rtx, rtx);
extern rtx gen_ix86_rotrti3_doubleword (rtx, rtx, rtx);
extern rtx gen_setcc_sf_sse (rtx, rtx, rtx, rtx);
extern rtx gen_setcc_df_sse (rtx, rtx, rtx, rtx);
extern rtx gen_jump (rtx);
extern rtx gen_blockage (void);
extern rtx gen_prologue_use (rtx);
extern rtx gen_simple_return_internal (void);
extern rtx gen_simple_return_internal_long (void);
extern rtx gen_simple_return_pop_internal (rtx);
extern rtx gen_simple_return_indirect_internal (rtx);
extern rtx gen_nop (void);
extern rtx gen_nops (rtx);
extern rtx gen_pad (rtx);
extern rtx gen_set_got (rtx);
extern rtx gen_set_got_labelled (rtx, rtx);
extern rtx gen_set_got_rex64 (rtx);
extern rtx gen_set_rip_rex64 (rtx, rtx);
extern rtx gen_set_got_offset_rex64 (rtx, rtx);
extern rtx gen_eh_return_internal (void);
extern rtx gen_leave (void);
extern rtx gen_leave_rex64 (void);
extern rtx gen_split_stack_return (rtx);
extern rtx gen_ffssi2_no_cmove (rtx, rtx);
extern rtx gen_ctzhi2 (rtx, rtx);
extern rtx gen_ctzsi2 (rtx, rtx);
extern rtx gen_ctzdi2 (rtx, rtx);
extern rtx gen_clzhi2_lzcnt (rtx, rtx);
extern rtx gen_clzsi2_lzcnt (rtx, rtx);
extern rtx gen_clzdi2_lzcnt (rtx, rtx);
extern rtx gen_bmi_bextr_si (rtx, rtx, rtx);
extern rtx gen_bmi_bextr_di (rtx, rtx, rtx);
extern rtx gen_bmi2_bzhi_si3 (rtx, rtx, rtx);
extern rtx gen_bmi2_bzhi_di3 (rtx, rtx, rtx);
extern rtx gen_bmi2_pdep_si3 (rtx, rtx, rtx);
extern rtx gen_bmi2_pdep_di3 (rtx, rtx, rtx);
extern rtx gen_bmi2_pext_si3 (rtx, rtx, rtx);
extern rtx gen_bmi2_pext_di3 (rtx, rtx, rtx);
extern rtx gen_tbm_bextri_si (rtx, rtx, rtx, rtx);
extern rtx gen_tbm_bextri_di (rtx, rtx, rtx, rtx);
extern rtx gen_bsr_rex64 (rtx, rtx);
extern rtx gen_bsr (rtx, rtx);
extern rtx gen_popcounthi2 (rtx, rtx);
extern rtx gen_popcountsi2 (rtx, rtx);
extern rtx gen_popcountdi2 (rtx, rtx);
extern rtx gen_bswaphi_lowpart (rtx);
extern rtx gen_paritydi2_cmp (rtx, rtx, rtx, rtx);
extern rtx gen_paritysi2_cmp (rtx, rtx, rtx);
static inline rtx gen_tls_initial_exec_64_sun (rtx, rtx);
static inline rtx
gen_tls_initial_exec_64_sun(rtx a __attribute__ ((__unused__)), rtx b __attribute__ ((__unused__)))
{
  return 0;
}
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
extern rtx gen_movmsk_df (rtx, rtx);
extern rtx gen_cld (void);
extern rtx gen_smaxsf3 (rtx, rtx, rtx);
extern rtx gen_sminsf3 (rtx, rtx, rtx);
extern rtx gen_smaxdf3 (rtx, rtx, rtx);
extern rtx gen_smindf3 (rtx, rtx, rtx);
extern rtx gen_pro_epilogue_adjust_stack_si_add (rtx, rtx, rtx);
extern rtx gen_pro_epilogue_adjust_stack_di_add (rtx, rtx, rtx);
extern rtx gen_pro_epilogue_adjust_stack_si_sub (rtx, rtx, rtx);
extern rtx gen_pro_epilogue_adjust_stack_di_sub (rtx, rtx, rtx);
extern rtx gen_allocate_stack_worker_probe_si (rtx, rtx);
extern rtx gen_allocate_stack_worker_probe_di (rtx, rtx);
extern rtx gen_adjust_stack_and_probesi (rtx, rtx, rtx);
extern rtx gen_adjust_stack_and_probedi (rtx, rtx, rtx);
extern rtx gen_probe_stack_rangesi (rtx, rtx, rtx);
extern rtx gen_probe_stack_rangedi (rtx, rtx, rtx);
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
extern rtx gen_rdfsbasesi (rtx);
extern rtx gen_rdfsbasedi (rtx);
extern rtx gen_rdgsbasesi (rtx);
extern rtx gen_rdgsbasedi (rtx);
extern rtx gen_wrfsbasesi (rtx);
extern rtx gen_wrfsbasedi (rtx);
extern rtx gen_wrgsbasesi (rtx);
extern rtx gen_wrgsbasedi (rtx);
extern rtx gen_rdrandhi_1 (rtx);
extern rtx gen_rdrandsi_1 (rtx);
extern rtx gen_rdranddi_1 (rtx);
extern rtx gen_sse_movntq (rtx, rtx);
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
extern rtx gen_mmx_ashlv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_lshrv4hi3 (rtx, rtx, rtx);
extern rtx gen_mmx_ashlv2si3 (rtx, rtx, rtx);
extern rtx gen_mmx_lshrv2si3 (rtx, rtx, rtx);
extern rtx gen_mmx_ashlv1di3 (rtx, rtx, rtx);
extern rtx gen_mmx_lshrv1di3 (rtx, rtx, rtx);
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
extern rtx gen_sse2_movq128 (rtx, rtx);
extern rtx gen_movdi_to_sse (rtx, rtx);
extern rtx gen_avx_movups256 (rtx, rtx);
extern rtx gen_sse_movups (rtx, rtx);
extern rtx gen_avx_movupd256 (rtx, rtx);
extern rtx gen_sse2_movupd (rtx, rtx);
extern rtx gen_avx_movdqu256 (rtx, rtx);
extern rtx gen_sse2_movdqu (rtx, rtx);
extern rtx gen_avx_lddqu256 (rtx, rtx);
extern rtx gen_sse3_lddqu (rtx, rtx);
extern rtx gen_sse2_movntisi (rtx, rtx);
extern rtx gen_sse2_movntidi (rtx, rtx);
extern rtx gen_avx_movntv8sf (rtx, rtx);
extern rtx gen_sse_movntv4sf (rtx, rtx);
extern rtx gen_avx_movntv4df (rtx, rtx);
extern rtx gen_sse2_movntv2df (rtx, rtx);
extern rtx gen_avx_movntv4di (rtx, rtx);
extern rtx gen_sse2_movntv2di (rtx, rtx);
extern rtx gen_sse_vmaddv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse_vmsubv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse2_vmaddv2df3 (rtx, rtx, rtx);
extern rtx gen_sse2_vmsubv2df3 (rtx, rtx, rtx);
extern rtx gen_sse_vmmulv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse2_vmmulv2df3 (rtx, rtx, rtx);
extern rtx gen_avx_divv8sf3 (rtx, rtx, rtx);
extern rtx gen_sse_divv4sf3 (rtx, rtx, rtx);
extern rtx gen_avx_divv4df3 (rtx, rtx, rtx);
extern rtx gen_sse2_divv2df3 (rtx, rtx, rtx);
extern rtx gen_sse_vmdivv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse2_vmdivv2df3 (rtx, rtx, rtx);
extern rtx gen_avx_rcpv8sf2 (rtx, rtx);
extern rtx gen_sse_rcpv4sf2 (rtx, rtx);
extern rtx gen_sse_vmrcpv4sf2 (rtx, rtx, rtx);
extern rtx gen_avx_sqrtv8sf2 (rtx, rtx);
extern rtx gen_sse_sqrtv4sf2 (rtx, rtx);
extern rtx gen_avx_sqrtv4df2 (rtx, rtx);
extern rtx gen_sse2_sqrtv2df2 (rtx, rtx);
extern rtx gen_sse_vmsqrtv4sf2 (rtx, rtx, rtx);
extern rtx gen_sse2_vmsqrtv2df2 (rtx, rtx, rtx);
extern rtx gen_avx_rsqrtv8sf2 (rtx, rtx);
extern rtx gen_sse_rsqrtv4sf2 (rtx, rtx);
extern rtx gen_sse_vmrsqrtv4sf2 (rtx, rtx, rtx);
extern rtx gen_sse_vmsmaxv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse_vmsminv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse2_vmsmaxv2df3 (rtx, rtx, rtx);
extern rtx gen_sse2_vmsminv2df3 (rtx, rtx, rtx);
extern rtx gen_avx_addsubv4df3 (rtx, rtx, rtx);
extern rtx gen_sse3_addsubv2df3 (rtx, rtx, rtx);
extern rtx gen_avx_addsubv8sf3 (rtx, rtx, rtx);
extern rtx gen_sse3_addsubv4sf3 (rtx, rtx, rtx);
extern rtx gen_avx_haddv4df3 (rtx, rtx, rtx);
extern rtx gen_avx_hsubv4df3 (rtx, rtx, rtx);
extern rtx gen_sse3_haddv2df3 (rtx, rtx, rtx);
extern rtx gen_sse3_hsubv2df3 (rtx, rtx, rtx);
extern rtx gen_avx_haddv8sf3 (rtx, rtx, rtx);
extern rtx gen_avx_hsubv8sf3 (rtx, rtx, rtx);
extern rtx gen_sse3_haddv4sf3 (rtx, rtx, rtx);
extern rtx gen_sse3_hsubv4sf3 (rtx, rtx, rtx);
extern rtx gen_avx_cmpv8sf3 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_cmpv4sf3 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_cmpv4df3 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_cmpv2df3 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_vmcmpv4sf3 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_vmcmpv2df3 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_maskcmpv8sf3 (rtx, rtx, rtx, rtx);
extern rtx gen_sse_maskcmpv4sf3 (rtx, rtx, rtx, rtx);
extern rtx gen_avx_maskcmpv4df3 (rtx, rtx, rtx, rtx);
extern rtx gen_sse2_maskcmpv2df3 (rtx, rtx, rtx, rtx);
extern rtx gen_sse_vmmaskcmpv4sf3 (rtx, rtx, rtx, rtx);
extern rtx gen_sse2_vmmaskcmpv2df3 (rtx, rtx, rtx, rtx);
extern rtx gen_sse_comi (rtx, rtx);
extern rtx gen_sse2_comi (rtx, rtx);
extern rtx gen_sse_ucomi (rtx, rtx);
extern rtx gen_sse2_ucomi (rtx, rtx);
extern rtx gen_avx_andnotv8sf3 (rtx, rtx, rtx);
extern rtx gen_sse_andnotv4sf3 (rtx, rtx, rtx);
extern rtx gen_avx_andnotv4df3 (rtx, rtx, rtx);
extern rtx gen_sse2_andnotv2df3 (rtx, rtx, rtx);
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
extern rtx gen_floatv8siv8sf2 (rtx, rtx);
extern rtx gen_floatv4siv4sf2 (rtx, rtx);
extern rtx gen_avx_cvtps2dq256 (rtx, rtx);
extern rtx gen_sse2_cvtps2dq (rtx, rtx);
extern rtx gen_fix_truncv8sfv8si2 (rtx, rtx);
extern rtx gen_fix_truncv4sfv4si2 (rtx, rtx);
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
extern rtx gen_floatv4siv4df2 (rtx, rtx);
extern rtx gen_avx_cvtdq2pd256_2 (rtx, rtx);
extern rtx gen_sse2_cvtdq2pd (rtx, rtx);
extern rtx gen_avx_cvtpd2dq256 (rtx, rtx);
extern rtx gen_fix_truncv4dfv4si2 (rtx, rtx);
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
extern rtx gen_sse_shufps_v4si (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse_shufps_v4sf (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse_storehps (rtx, rtx);
extern rtx gen_sse_loadhps (rtx, rtx, rtx);
extern rtx gen_sse_storelps (rtx, rtx);
extern rtx gen_sse_loadlps (rtx, rtx, rtx);
extern rtx gen_sse_movss (rtx, rtx, rtx);
extern rtx gen_avx2_vec_dupv8sf (rtx, rtx);
extern rtx gen_avx2_vec_dupv4sf (rtx, rtx);
extern rtx gen_vec_dupv4sf (rtx, rtx);
extern rtx gen_vec_setv4si_0 (rtx, rtx, rtx);
extern rtx gen_vec_setv4sf_0 (rtx, rtx, rtx);
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
extern rtx gen_avx2_interleave_highv4di (rtx, rtx, rtx);
extern rtx gen_vec_interleave_highv2di (rtx, rtx, rtx);
extern rtx gen_avx2_interleave_lowv4di (rtx, rtx, rtx);
extern rtx gen_vec_interleave_lowv2di (rtx, rtx, rtx);
extern rtx gen_sse2_shufpd_v2di (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse2_shufpd_v2df (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse2_storehpd (rtx, rtx);
extern rtx gen_sse2_storelpd (rtx, rtx);
extern rtx gen_sse2_loadhpd (rtx, rtx, rtx);
extern rtx gen_sse2_loadlpd (rtx, rtx, rtx);
extern rtx gen_sse2_movsd (rtx, rtx, rtx);
extern rtx gen_vec_dupv2df (rtx, rtx);
extern rtx gen_mulv32qi3 (rtx, rtx, rtx);
extern rtx gen_mulv16qi3 (rtx, rtx, rtx);
extern rtx gen_mulv4di3 (rtx, rtx, rtx);
extern rtx gen_mulv2di3 (rtx, rtx, rtx);
extern rtx gen_ashrv16hi3 (rtx, rtx, rtx);
extern rtx gen_ashrv8hi3 (rtx, rtx, rtx);
extern rtx gen_ashrv8si3 (rtx, rtx, rtx);
extern rtx gen_ashrv4si3 (rtx, rtx, rtx);
extern rtx gen_ashlv16hi3 (rtx, rtx, rtx);
extern rtx gen_lshrv16hi3 (rtx, rtx, rtx);
extern rtx gen_ashlv8hi3 (rtx, rtx, rtx);
extern rtx gen_lshrv8hi3 (rtx, rtx, rtx);
extern rtx gen_ashlv8si3 (rtx, rtx, rtx);
extern rtx gen_lshrv8si3 (rtx, rtx, rtx);
extern rtx gen_ashlv4si3 (rtx, rtx, rtx);
extern rtx gen_lshrv4si3 (rtx, rtx, rtx);
extern rtx gen_ashlv4di3 (rtx, rtx, rtx);
extern rtx gen_lshrv4di3 (rtx, rtx, rtx);
extern rtx gen_ashlv2di3 (rtx, rtx, rtx);
extern rtx gen_lshrv2di3 (rtx, rtx, rtx);
extern rtx gen_avx2_ashlv2ti3 (rtx, rtx, rtx);
extern rtx gen_sse2_ashlv1ti3 (rtx, rtx, rtx);
extern rtx gen_avx2_lshrv2ti3 (rtx, rtx, rtx);
extern rtx gen_sse2_lshrv1ti3 (rtx, rtx, rtx);
extern rtx gen_sse4_2_gtv2di3 (rtx, rtx, rtx);
extern rtx gen_avx2_gtv32qi3 (rtx, rtx, rtx);
extern rtx gen_avx2_gtv16hi3 (rtx, rtx, rtx);
extern rtx gen_avx2_gtv8si3 (rtx, rtx, rtx);
extern rtx gen_avx2_gtv4di3 (rtx, rtx, rtx);
extern rtx gen_sse2_gtv16qi3 (rtx, rtx, rtx);
extern rtx gen_sse2_gtv8hi3 (rtx, rtx, rtx);
extern rtx gen_sse2_gtv4si3 (rtx, rtx, rtx);
extern rtx gen_avx2_packsswb (rtx, rtx, rtx);
extern rtx gen_sse2_packsswb (rtx, rtx, rtx);
extern rtx gen_avx2_packssdw (rtx, rtx, rtx);
extern rtx gen_sse2_packssdw (rtx, rtx, rtx);
extern rtx gen_avx2_packuswb (rtx, rtx, rtx);
extern rtx gen_sse2_packuswb (rtx, rtx, rtx);
extern rtx gen_avx2_interleave_highv32qi (rtx, rtx, rtx);
extern rtx gen_vec_interleave_highv16qi (rtx, rtx, rtx);
extern rtx gen_avx2_interleave_lowv32qi (rtx, rtx, rtx);
extern rtx gen_vec_interleave_lowv16qi (rtx, rtx, rtx);
extern rtx gen_avx2_interleave_highv16hi (rtx, rtx, rtx);
extern rtx gen_vec_interleave_highv8hi (rtx, rtx, rtx);
extern rtx gen_avx2_interleave_lowv16hi (rtx, rtx, rtx);
extern rtx gen_vec_interleave_lowv8hi (rtx, rtx, rtx);
extern rtx gen_avx2_interleave_highv8si (rtx, rtx, rtx);
extern rtx gen_vec_interleave_highv4si (rtx, rtx, rtx);
extern rtx gen_avx2_interleave_lowv8si (rtx, rtx, rtx);
extern rtx gen_vec_interleave_lowv4si (rtx, rtx, rtx);
extern rtx gen_sse4_1_pinsrb (rtx, rtx, rtx, rtx);
extern rtx gen_sse2_pinsrw (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_pinsrd (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_pinsrq (rtx, rtx, rtx, rtx);
extern rtx gen_avx2_pshufd_1 (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse2_pshufd_1 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_pshuflw_1 (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse2_pshuflw_1 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_pshufhw_1 (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse2_pshufhw_1 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse2_loadld (rtx, rtx, rtx);
extern rtx gen_sse2_stored (rtx, rtx);
extern rtx gen_vec_concatv2di (rtx, rtx, rtx);
extern rtx gen_avx2_psadbw (rtx, rtx, rtx);
extern rtx gen_sse2_psadbw (rtx, rtx, rtx);
extern rtx gen_avx_movmskps256 (rtx, rtx);
extern rtx gen_sse_movmskps (rtx, rtx);
extern rtx gen_avx_movmskpd256 (rtx, rtx);
extern rtx gen_sse2_movmskpd (rtx, rtx);
extern rtx gen_avx2_pmovmskb (rtx, rtx);
extern rtx gen_sse2_pmovmskb (rtx, rtx);
extern rtx gen_sse_ldmxcsr (rtx);
extern rtx gen_sse_stmxcsr (rtx);
extern rtx gen_sse2_clflush (rtx);
extern rtx gen_sse3_mwait (rtx, rtx);
extern rtx gen_sse3_monitor (rtx, rtx, rtx);
extern rtx gen_sse3_monitor64 (rtx, rtx, rtx);
extern rtx gen_avx2_phaddwv16hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phaddwv8hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phaddwv4hi3 (rtx, rtx, rtx);
extern rtx gen_avx2_phadddv8si3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phadddv4si3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phadddv2si3 (rtx, rtx, rtx);
extern rtx gen_avx2_phaddswv16hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phaddswv8hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phaddswv4hi3 (rtx, rtx, rtx);
extern rtx gen_avx2_phsubwv16hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phsubwv8hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phsubwv4hi3 (rtx, rtx, rtx);
extern rtx gen_avx2_phsubdv8si3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phsubdv4si3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phsubdv2si3 (rtx, rtx, rtx);
extern rtx gen_avx2_phsubswv16hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phsubswv8hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_phsubswv4hi3 (rtx, rtx, rtx);
extern rtx gen_avx2_pmaddubsw256 (rtx, rtx, rtx);
extern rtx gen_ssse3_pmaddubsw128 (rtx, rtx, rtx);
extern rtx gen_ssse3_pmaddubsw (rtx, rtx, rtx);
extern rtx gen_avx2_pshufbv32qi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_pshufbv16qi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_pshufbv8qi3 (rtx, rtx, rtx);
extern rtx gen_avx2_psignv32qi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_psignv16qi3 (rtx, rtx, rtx);
extern rtx gen_avx2_psignv16hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_psignv8hi3 (rtx, rtx, rtx);
extern rtx gen_avx2_psignv8si3 (rtx, rtx, rtx);
extern rtx gen_ssse3_psignv4si3 (rtx, rtx, rtx);
extern rtx gen_ssse3_psignv8qi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_psignv4hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_psignv2si3 (rtx, rtx, rtx);
extern rtx gen_avx2_palignrv2ti (rtx, rtx, rtx, rtx);
extern rtx gen_ssse3_palignrti (rtx, rtx, rtx, rtx);
extern rtx gen_ssse3_palignrdi (rtx, rtx, rtx, rtx);
extern rtx gen_absv32qi2 (rtx, rtx);
extern rtx gen_absv16qi2 (rtx, rtx);
extern rtx gen_absv16hi2 (rtx, rtx);
extern rtx gen_absv8hi2 (rtx, rtx);
extern rtx gen_absv8si2 (rtx, rtx);
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
extern rtx gen_avx_blendps256 (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_blendps (rtx, rtx, rtx, rtx);
extern rtx gen_avx_blendpd256 (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_blendpd (rtx, rtx, rtx, rtx);
extern rtx gen_avx_blendvps256 (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_blendvps (rtx, rtx, rtx, rtx);
extern rtx gen_avx_blendvpd256 (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_blendvpd (rtx, rtx, rtx, rtx);
extern rtx gen_avx_dpps256 (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_dpps (rtx, rtx, rtx, rtx);
extern rtx gen_avx_dppd256 (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_dppd (rtx, rtx, rtx, rtx);
extern rtx gen_avx2_movntdqa (rtx, rtx);
extern rtx gen_sse4_1_movntdqa (rtx, rtx);
extern rtx gen_avx2_mpsadbw (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_mpsadbw (rtx, rtx, rtx, rtx);
extern rtx gen_avx2_packusdw (rtx, rtx, rtx);
extern rtx gen_sse4_1_packusdw (rtx, rtx, rtx);
extern rtx gen_avx2_pblendvb (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_pblendvb (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_pblendw (rtx, rtx, rtx, rtx);
extern rtx gen_avx2_pblenddv8si (rtx, rtx, rtx, rtx);
extern rtx gen_avx2_pblenddv4si (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_phminposuw (rtx, rtx);
extern rtx gen_avx2_sign_extendv16qiv16hi2 (rtx, rtx);
extern rtx gen_avx2_zero_extendv16qiv16hi2 (rtx, rtx);
extern rtx gen_sse4_1_sign_extendv8qiv8hi2 (rtx, rtx);
extern rtx gen_sse4_1_zero_extendv8qiv8hi2 (rtx, rtx);
extern rtx gen_avx2_sign_extendv8qiv8si2 (rtx, rtx);
extern rtx gen_avx2_zero_extendv8qiv8si2 (rtx, rtx);
extern rtx gen_sse4_1_sign_extendv4qiv4si2 (rtx, rtx);
extern rtx gen_sse4_1_zero_extendv4qiv4si2 (rtx, rtx);
extern rtx gen_avx2_sign_extendv8hiv8si2 (rtx, rtx);
extern rtx gen_avx2_zero_extendv8hiv8si2 (rtx, rtx);
extern rtx gen_sse4_1_sign_extendv4hiv4si2 (rtx, rtx);
extern rtx gen_sse4_1_zero_extendv4hiv4si2 (rtx, rtx);
extern rtx gen_avx2_sign_extendv4qiv4di2 (rtx, rtx);
extern rtx gen_avx2_zero_extendv4qiv4di2 (rtx, rtx);
extern rtx gen_sse4_1_sign_extendv2qiv2di2 (rtx, rtx);
extern rtx gen_sse4_1_zero_extendv2qiv2di2 (rtx, rtx);
extern rtx gen_avx2_sign_extendv4hiv4di2 (rtx, rtx);
extern rtx gen_avx2_zero_extendv4hiv4di2 (rtx, rtx);
extern rtx gen_sse4_1_sign_extendv2hiv2di2 (rtx, rtx);
extern rtx gen_sse4_1_zero_extendv2hiv2di2 (rtx, rtx);
extern rtx gen_avx2_sign_extendv4siv4di2 (rtx, rtx);
extern rtx gen_avx2_zero_extendv4siv4di2 (rtx, rtx);
extern rtx gen_sse4_1_sign_extendv2siv2di2 (rtx, rtx);
extern rtx gen_sse4_1_zero_extendv2siv2di2 (rtx, rtx);
extern rtx gen_avx_vtestps256 (rtx, rtx);
extern rtx gen_avx_vtestps (rtx, rtx);
extern rtx gen_avx_vtestpd256 (rtx, rtx);
extern rtx gen_avx_vtestpd (rtx, rtx);
extern rtx gen_avx_ptest256 (rtx, rtx);
extern rtx gen_sse4_1_ptest (rtx, rtx);
extern rtx gen_avx_roundps256 (rtx, rtx, rtx);
extern rtx gen_sse4_1_roundps (rtx, rtx, rtx);
extern rtx gen_avx_roundpd256 (rtx, rtx, rtx);
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
extern rtx gen_xop_pcmov_v32qi256 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v16qi (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v16hi256 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v8hi (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v8si256 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v4si (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v4di256 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v2di (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v8sf256 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v4sf (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v4df256 (rtx, rtx, rtx, rtx);
extern rtx gen_xop_pcmov_v2df (rtx, rtx, rtx, rtx);
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
extern rtx gen_xop_shav16qi3 (rtx, rtx, rtx);
extern rtx gen_xop_shav8hi3 (rtx, rtx, rtx);
extern rtx gen_xop_shav4si3 (rtx, rtx, rtx);
extern rtx gen_xop_shav2di3 (rtx, rtx, rtx);
extern rtx gen_xop_shlv16qi3 (rtx, rtx, rtx);
extern rtx gen_xop_shlv8hi3 (rtx, rtx, rtx);
extern rtx gen_xop_shlv4si3 (rtx, rtx, rtx);
extern rtx gen_xop_shlv2di3 (rtx, rtx, rtx);
extern rtx gen_xop_frczsf2 (rtx, rtx);
extern rtx gen_xop_frczdf2 (rtx, rtx);
extern rtx gen_xop_frczv4sf2 (rtx, rtx);
extern rtx gen_xop_frczv2df2 (rtx, rtx);
extern rtx gen_xop_frczv8sf2 (rtx, rtx);
extern rtx gen_xop_frczv4df2 (rtx, rtx);
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
extern rtx gen_xop_vpermil2v8sf3 (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_xop_vpermil2v4sf3 (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_xop_vpermil2v4df3 (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_xop_vpermil2v2df3 (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_aesenc (rtx, rtx, rtx);
extern rtx gen_aesenclast (rtx, rtx, rtx);
extern rtx gen_aesdec (rtx, rtx, rtx);
extern rtx gen_aesdeclast (rtx, rtx, rtx);
extern rtx gen_aesimc (rtx, rtx);
extern rtx gen_aeskeygenassist (rtx, rtx, rtx);
extern rtx gen_pclmulqdq (rtx, rtx, rtx, rtx);
extern rtx gen_avx_vzeroupper (rtx);
extern rtx gen_avx2_pbroadcastv32qi (rtx, rtx);
extern rtx gen_avx2_pbroadcastv16qi (rtx, rtx);
extern rtx gen_avx2_pbroadcastv16hi (rtx, rtx);
extern rtx gen_avx2_pbroadcastv8hi (rtx, rtx);
extern rtx gen_avx2_pbroadcastv8si (rtx, rtx);
extern rtx gen_avx2_pbroadcastv4si (rtx, rtx);
extern rtx gen_avx2_pbroadcastv4di (rtx, rtx);
extern rtx gen_avx2_pbroadcastv2di (rtx, rtx);
extern rtx gen_avx2_permvarv8si (rtx, rtx, rtx);
extern rtx gen_avx2_permv4df (rtx, rtx, rtx);
extern rtx gen_avx2_permvarv8sf (rtx, rtx, rtx);
extern rtx gen_avx2_permv4di_1 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_permv2ti (rtx, rtx, rtx, rtx);
extern rtx gen_avx2_vec_dupv4df (rtx, rtx);
extern rtx gen_vec_dupv8si (rtx, rtx);
extern rtx gen_vec_dupv8sf (rtx, rtx);
extern rtx gen_vec_dupv4di (rtx, rtx);
extern rtx gen_vec_dupv4df (rtx, rtx);
extern rtx gen_avx2_vbroadcasti128_v32qi (rtx, rtx);
extern rtx gen_avx2_vbroadcasti128_v16hi (rtx, rtx);
extern rtx gen_avx2_vbroadcasti128_v8si (rtx, rtx);
extern rtx gen_avx2_vbroadcasti128_v4di (rtx, rtx);
extern rtx gen_avx_vbroadcastf128_v32qi (rtx, rtx);
extern rtx gen_avx_vbroadcastf128_v16hi (rtx, rtx);
extern rtx gen_avx_vbroadcastf128_v8si (rtx, rtx);
extern rtx gen_avx_vbroadcastf128_v4di (rtx, rtx);
extern rtx gen_avx_vbroadcastf128_v8sf (rtx, rtx);
extern rtx gen_avx_vbroadcastf128_v4df (rtx, rtx);
extern rtx gen_avx_vpermilvarv8sf3 (rtx, rtx, rtx);
extern rtx gen_avx_vpermilvarv4sf3 (rtx, rtx, rtx);
extern rtx gen_avx_vpermilvarv4df3 (rtx, rtx, rtx);
extern rtx gen_avx_vpermilvarv2df3 (rtx, rtx, rtx);
extern rtx gen_avx2_vec_set_lo_v4di (rtx, rtx, rtx);
extern rtx gen_avx2_vec_set_hi_v4di (rtx, rtx, rtx);
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
extern rtx gen_avx2_maskloadd (rtx, rtx, rtx);
extern rtx gen_avx2_maskloadq (rtx, rtx, rtx);
extern rtx gen_avx2_maskloadd256 (rtx, rtx, rtx);
extern rtx gen_avx2_maskloadq256 (rtx, rtx, rtx);
extern rtx gen_avx_maskstoreps (rtx, rtx, rtx);
extern rtx gen_avx_maskstorepd (rtx, rtx, rtx);
extern rtx gen_avx_maskstoreps256 (rtx, rtx, rtx);
extern rtx gen_avx_maskstorepd256 (rtx, rtx, rtx);
extern rtx gen_avx2_maskstored (rtx, rtx, rtx);
extern rtx gen_avx2_maskstoreq (rtx, rtx, rtx);
extern rtx gen_avx2_maskstored256 (rtx, rtx, rtx);
extern rtx gen_avx2_maskstoreq256 (rtx, rtx, rtx);
extern rtx gen_avx_si256_si (rtx, rtx);
extern rtx gen_avx_ps256_ps (rtx, rtx);
extern rtx gen_avx_pd256_pd (rtx, rtx);
extern rtx gen_avx2_ashrvv8si (rtx, rtx, rtx);
extern rtx gen_avx2_ashrvv4si (rtx, rtx, rtx);
extern rtx gen_avx2_ashlvv8si (rtx, rtx, rtx);
extern rtx gen_avx2_lshrvv8si (rtx, rtx, rtx);
extern rtx gen_avx2_ashlvv4si (rtx, rtx, rtx);
extern rtx gen_avx2_lshrvv4si (rtx, rtx, rtx);
extern rtx gen_avx2_ashlvv4di (rtx, rtx, rtx);
extern rtx gen_avx2_lshrvv4di (rtx, rtx, rtx);
extern rtx gen_avx2_ashlvv2di (rtx, rtx, rtx);
extern rtx gen_avx2_lshrvv2di (rtx, rtx, rtx);
extern rtx gen_avx_vec_concatv32qi (rtx, rtx, rtx);
extern rtx gen_avx_vec_concatv16hi (rtx, rtx, rtx);
extern rtx gen_avx_vec_concatv8si (rtx, rtx, rtx);
extern rtx gen_avx_vec_concatv4di (rtx, rtx, rtx);
extern rtx gen_avx_vec_concatv8sf (rtx, rtx, rtx);
extern rtx gen_avx_vec_concatv4df (rtx, rtx, rtx);
extern rtx gen_vcvtph2ps (rtx, rtx);
extern rtx gen_vcvtph2ps256 (rtx, rtx);
extern rtx gen_vcvtps2ph256 (rtx, rtx, rtx);
extern rtx gen_mfence_sse2 (rtx);
extern rtx gen_mfence_nosse (rtx);
extern rtx gen_atomic_loaddi_fpu (rtx, rtx, rtx);
extern rtx gen_atomic_storedi_fpu (rtx, rtx, rtx);
extern rtx gen_loaddi_via_fpu (rtx, rtx);
extern rtx gen_storedi_via_fpu (rtx, rtx);
extern rtx gen_atomic_compare_and_swap_singleqi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_compare_and_swap_singlehi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_compare_and_swap_singlesi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_compare_and_swap_singledi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_compare_and_swap_doubledi (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_atomic_compare_and_swap_doubleti (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_addqi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_addhi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_addsi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_fetch_adddi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_exchangeqi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_exchangehi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_exchangesi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_exchangedi (rtx, rtx, rtx, rtx);
extern rtx gen_atomic_addqi (rtx, rtx, rtx);
extern rtx gen_atomic_addhi (rtx, rtx, rtx);
extern rtx gen_atomic_addsi (rtx, rtx, rtx);
extern rtx gen_atomic_adddi (rtx, rtx, rtx);
extern rtx gen_atomic_subqi (rtx, rtx, rtx);
extern rtx gen_atomic_subhi (rtx, rtx, rtx);
extern rtx gen_atomic_subsi (rtx, rtx, rtx);
extern rtx gen_atomic_subdi (rtx, rtx, rtx);
extern rtx gen_atomic_andqi (rtx, rtx, rtx);
extern rtx gen_atomic_orqi (rtx, rtx, rtx);
extern rtx gen_atomic_xorqi (rtx, rtx, rtx);
extern rtx gen_atomic_andhi (rtx, rtx, rtx);
extern rtx gen_atomic_orhi (rtx, rtx, rtx);
extern rtx gen_atomic_xorhi (rtx, rtx, rtx);
extern rtx gen_atomic_andsi (rtx, rtx, rtx);
extern rtx gen_atomic_orsi (rtx, rtx, rtx);
extern rtx gen_atomic_xorsi (rtx, rtx, rtx);
extern rtx gen_atomic_anddi (rtx, rtx, rtx);
extern rtx gen_atomic_ordi (rtx, rtx, rtx);
extern rtx gen_atomic_xordi (rtx, rtx, rtx);
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
extern rtx gen_movoi (rtx, rtx);
extern rtx gen_movti (rtx, rtx);
extern rtx gen_movcdi (rtx, rtx);
extern rtx gen_movqi (rtx, rtx);
extern rtx gen_movhi (rtx, rtx);
extern rtx gen_movsi (rtx, rtx);
extern rtx gen_movdi (rtx, rtx);
extern rtx gen_reload_noff_store (rtx, rtx, rtx);
extern rtx gen_reload_noff_load (rtx, rtx, rtx);
extern rtx gen_movstrictqi (rtx, rtx);
extern rtx gen_movstricthi (rtx, rtx);
extern rtx gen_movsi_insv_1 (rtx, rtx);
extern rtx gen_movdi_insv_1 (rtx, rtx);
extern rtx gen_movtf (rtx, rtx);
extern rtx gen_movsf (rtx, rtx);
extern rtx gen_movdf (rtx, rtx);
extern rtx gen_movxf (rtx, rtx);
extern rtx gen_zero_extendsidi2 (rtx, rtx);
extern rtx gen_zero_extendhisi2 (rtx, rtx);
extern rtx gen_zero_extendqihi2 (rtx, rtx);
extern rtx gen_zero_extendqisi2 (rtx, rtx);
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
extern rtx gen_floatsidf2 (rtx, rtx);
extern rtx gen_floatsixf2 (rtx, rtx);
extern rtx gen_floatdisf2 (rtx, rtx);
extern rtx gen_floatdidf2 (rtx, rtx);
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
extern rtx gen_divmodqi4 (rtx, rtx, rtx, rtx);
extern rtx gen_udivmodhi4 (rtx, rtx, rtx, rtx);
extern rtx gen_udivmodsi4 (rtx, rtx, rtx, rtx);
extern rtx gen_udivmoddi4 (rtx, rtx, rtx, rtx);
extern rtx gen_udivmodqi4 (rtx, rtx, rtx, rtx);
extern rtx gen_testsi_ccno_1 (rtx, rtx);
extern rtx gen_testqi_ccz_1 (rtx, rtx);
extern rtx gen_testdi_ccno_1 (rtx, rtx);
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
extern rtx gen_ashlqi3 (rtx, rtx, rtx);
extern rtx gen_ashlhi3 (rtx, rtx, rtx);
extern rtx gen_ashlsi3 (rtx, rtx, rtx);
extern rtx gen_ashldi3 (rtx, rtx, rtx);
extern rtx gen_ashlti3 (rtx, rtx, rtx);
extern rtx gen_x86_shiftsi_adj_1 (rtx, rtx, rtx, rtx);
extern rtx gen_x86_shiftdi_adj_1 (rtx, rtx, rtx, rtx);
extern rtx gen_x86_shiftsi_adj_2 (rtx, rtx, rtx);
extern rtx gen_x86_shiftdi_adj_2 (rtx, rtx, rtx);
extern rtx gen_lshrqi3 (rtx, rtx, rtx);
extern rtx gen_ashrqi3 (rtx, rtx, rtx);
extern rtx gen_lshrhi3 (rtx, rtx, rtx);
extern rtx gen_ashrhi3 (rtx, rtx, rtx);
extern rtx gen_lshrsi3 (rtx, rtx, rtx);
extern rtx gen_ashrsi3 (rtx, rtx, rtx);
extern rtx gen_lshrdi3 (rtx, rtx, rtx);
extern rtx gen_ashrdi3 (rtx, rtx, rtx);
extern rtx gen_lshrti3 (rtx, rtx, rtx);
extern rtx gen_ashrti3 (rtx, rtx, rtx);
extern rtx gen_x86_shiftsi_adj_3 (rtx, rtx, rtx);
extern rtx gen_x86_shiftdi_adj_3 (rtx, rtx, rtx);
extern rtx gen_rotlti3 (rtx, rtx, rtx);
extern rtx gen_rotrti3 (rtx, rtx, rtx);
extern rtx gen_rotldi3 (rtx, rtx, rtx);
extern rtx gen_rotrdi3 (rtx, rtx, rtx);
extern rtx gen_rotlqi3 (rtx, rtx, rtx);
extern rtx gen_rotrqi3 (rtx, rtx, rtx);
extern rtx gen_rotlhi3 (rtx, rtx, rtx);
extern rtx gen_rotrhi3 (rtx, rtx, rtx);
extern rtx gen_rotlsi3 (rtx, rtx, rtx);
extern rtx gen_rotrsi3 (rtx, rtx, rtx);
extern rtx gen_extv (rtx, rtx, rtx, rtx);
extern rtx gen_extzv (rtx, rtx, rtx, rtx);
extern rtx gen_insv (rtx, rtx, rtx, rtx);
extern rtx gen_indirect_jump (rtx);
extern rtx gen_tablejump (rtx, rtx);

extern rtx gen_call (rtx, rtx, rtx);

extern rtx gen_sibcall (rtx, rtx, rtx);

extern rtx gen_call_pop (rtx, rtx, rtx, rtx);

extern rtx gen_call_value (rtx, rtx, rtx, rtx);

extern rtx gen_sibcall_value (rtx, rtx, rtx, rtx);

extern rtx gen_call_value_pop (rtx, rtx, rtx, rtx, rtx);
extern rtx gen_untyped_call (rtx, rtx, rtx);
extern rtx gen_memory_blockage (void);
extern rtx gen_return (void);
extern rtx gen_simple_return (void);
extern rtx gen_prologue (void);
extern rtx gen_epilogue (void);
extern rtx gen_sibcall_epilogue (void);
extern rtx gen_eh_return (rtx);
extern rtx gen_split_stack_prologue (void);
extern rtx gen_split_stack_space_check (rtx, rtx);
extern rtx gen_ffssi2 (rtx, rtx);
extern rtx gen_ffsdi2 (rtx, rtx);
extern rtx gen_clzhi2 (rtx, rtx);
extern rtx gen_clzsi2 (rtx, rtx);
extern rtx gen_clzdi2 (rtx, rtx);
extern rtx gen_bswapsi2 (rtx, rtx);
extern rtx gen_bswapdi2 (rtx, rtx);
extern rtx gen_paritydi2 (rtx, rtx);
extern rtx gen_paritysi2 (rtx, rtx);
extern rtx gen_tls_global_dynamic_32 (rtx, rtx, rtx, rtx);
extern rtx gen_tls_global_dynamic_64 (rtx, rtx, rtx);
extern rtx gen_tls_local_dynamic_base_32 (rtx, rtx, rtx);
extern rtx gen_tls_local_dynamic_base_64 (rtx, rtx);
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
extern rtx gen_roundxf2 (rtx, rtx);
extern rtx gen_lrintxfhi2 (rtx, rtx);
extern rtx gen_lrintxfsi2 (rtx, rtx);
extern rtx gen_lrintxfdi2 (rtx, rtx);
extern rtx gen_lrintsfsi2 (rtx, rtx);
extern rtx gen_lrintdfsi2 (rtx, rtx);
extern rtx gen_lrintsfdi2 (rtx, rtx);
extern rtx gen_lrintdfdi2 (rtx, rtx);
extern rtx gen_lroundsfhi2 (rtx, rtx);
extern rtx gen_lrounddfhi2 (rtx, rtx);
extern rtx gen_lroundxfhi2 (rtx, rtx);
extern rtx gen_lroundsfsi2 (rtx, rtx);
extern rtx gen_lrounddfsi2 (rtx, rtx);
extern rtx gen_lroundxfsi2 (rtx, rtx);
extern rtx gen_lroundsfdi2 (rtx, rtx);
extern rtx gen_lrounddfdi2 (rtx, rtx);
extern rtx gen_lroundxfdi2 (rtx, rtx);
extern rtx gen_floorxf2 (rtx, rtx);
extern rtx gen_floorsf2 (rtx, rtx);
extern rtx gen_floordf2 (rtx, rtx);
extern rtx gen_lfloorxfhi2 (rtx, rtx);
extern rtx gen_lfloorxfsi2 (rtx, rtx);
extern rtx gen_lfloorxfdi2 (rtx, rtx);
extern rtx gen_lfloorsfsi2 (rtx, rtx);
extern rtx gen_lfloorsfdi2 (rtx, rtx);
extern rtx gen_lfloordfsi2 (rtx, rtx);
extern rtx gen_lfloordfdi2 (rtx, rtx);
extern rtx gen_ceilxf2 (rtx, rtx);
extern rtx gen_ceilsf2 (rtx, rtx);
extern rtx gen_ceildf2 (rtx, rtx);
extern rtx gen_lceilxfhi2 (rtx, rtx);
extern rtx gen_lceilxfsi2 (rtx, rtx);
extern rtx gen_lceilxfdi2 (rtx, rtx);
extern rtx gen_lceilsfsi2 (rtx, rtx);
extern rtx gen_lceilsfdi2 (rtx, rtx);
extern rtx gen_lceildfsi2 (rtx, rtx);
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
extern rtx gen_signbitxf2 (rtx, rtx);
extern rtx gen_signbitdf2 (rtx, rtx);
extern rtx gen_signbitsf2 (rtx, rtx);
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
extern rtx gen_pause (void);
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
extern rtx gen_movv16qi (rtx, rtx);
extern rtx gen_movv16hi (rtx, rtx);
extern rtx gen_movv8hi (rtx, rtx);
extern rtx gen_movv8si (rtx, rtx);
extern rtx gen_movv4si (rtx, rtx);
extern rtx gen_movv4di (rtx, rtx);
extern rtx gen_movv2di (rtx, rtx);
extern rtx gen_movv2ti (rtx, rtx);
extern rtx gen_movv1ti (rtx, rtx);
extern rtx gen_movv8sf (rtx, rtx);
extern rtx gen_movv4sf (rtx, rtx);
extern rtx gen_movv4df (rtx, rtx);
extern rtx gen_movv2df (rtx, rtx);
extern rtx gen_pushv32qi1 (rtx);
extern rtx gen_pushv16qi1 (rtx);
extern rtx gen_pushv16hi1 (rtx);
extern rtx gen_pushv8hi1 (rtx);
extern rtx gen_pushv8si1 (rtx);
extern rtx gen_pushv4si1 (rtx);
extern rtx gen_pushv4di1 (rtx);
extern rtx gen_pushv2di1 (rtx);
extern rtx gen_pushv2ti1 (rtx);
extern rtx gen_pushv1ti1 (rtx);
extern rtx gen_pushv8sf1 (rtx);
extern rtx gen_pushv4sf1 (rtx);
extern rtx gen_pushv4df1 (rtx);
extern rtx gen_pushv2df1 (rtx);
extern rtx gen_movmisalignv32qi (rtx, rtx);
extern rtx gen_movmisalignv16qi (rtx, rtx);
extern rtx gen_movmisalignv16hi (rtx, rtx);
extern rtx gen_movmisalignv8hi (rtx, rtx);
extern rtx gen_movmisalignv8si (rtx, rtx);
extern rtx gen_movmisalignv4si (rtx, rtx);
extern rtx gen_movmisalignv4di (rtx, rtx);
extern rtx gen_movmisalignv2di (rtx, rtx);
extern rtx gen_movmisalignv2ti (rtx, rtx);
extern rtx gen_movmisalignv1ti (rtx, rtx);
extern rtx gen_movmisalignv8sf (rtx, rtx);
extern rtx gen_movmisalignv4sf (rtx, rtx);
extern rtx gen_movmisalignv4df (rtx, rtx);
extern rtx gen_movmisalignv2df (rtx, rtx);
extern rtx gen_storentdi (rtx, rtx);
extern rtx gen_storentsi (rtx, rtx);
extern rtx gen_storentsf (rtx, rtx);
extern rtx gen_storentdf (rtx, rtx);
extern rtx gen_storentv4di (rtx, rtx);
extern rtx gen_storentv2di (rtx, rtx);
extern rtx gen_storentv8sf (rtx, rtx);
extern rtx gen_storentv4sf (rtx, rtx);
extern rtx gen_storentv4df (rtx, rtx);
extern rtx gen_storentv2df (rtx, rtx);
extern rtx gen_absv8sf2 (rtx, rtx);
extern rtx gen_negv8sf2 (rtx, rtx);
extern rtx gen_absv4sf2 (rtx, rtx);
extern rtx gen_negv4sf2 (rtx, rtx);
extern rtx gen_absv4df2 (rtx, rtx);
extern rtx gen_negv4df2 (rtx, rtx);
extern rtx gen_absv2df2 (rtx, rtx);
extern rtx gen_negv2df2 (rtx, rtx);
extern rtx gen_addv8sf3 (rtx, rtx, rtx);
extern rtx gen_subv8sf3 (rtx, rtx, rtx);
extern rtx gen_addv4sf3 (rtx, rtx, rtx);
extern rtx gen_subv4sf3 (rtx, rtx, rtx);
extern rtx gen_addv4df3 (rtx, rtx, rtx);
extern rtx gen_subv4df3 (rtx, rtx, rtx);
extern rtx gen_addv2df3 (rtx, rtx, rtx);
extern rtx gen_subv2df3 (rtx, rtx, rtx);
extern rtx gen_mulv8sf3 (rtx, rtx, rtx);
extern rtx gen_mulv4sf3 (rtx, rtx, rtx);
extern rtx gen_mulv4df3 (rtx, rtx, rtx);
extern rtx gen_mulv2df3 (rtx, rtx, rtx);
extern rtx gen_divv4df3 (rtx, rtx, rtx);
extern rtx gen_divv2df3 (rtx, rtx, rtx);
extern rtx gen_divv8sf3 (rtx, rtx, rtx);
extern rtx gen_divv4sf3 (rtx, rtx, rtx);
extern rtx gen_sqrtv4df2 (rtx, rtx);
extern rtx gen_sqrtv2df2 (rtx, rtx);
extern rtx gen_sqrtv8sf2 (rtx, rtx);
extern rtx gen_sqrtv4sf2 (rtx, rtx);
extern rtx gen_rsqrtv8sf2 (rtx, rtx);
extern rtx gen_rsqrtv4sf2 (rtx, rtx);
extern rtx gen_smaxv8sf3 (rtx, rtx, rtx);
extern rtx gen_sminv8sf3 (rtx, rtx, rtx);
extern rtx gen_smaxv4sf3 (rtx, rtx, rtx);
extern rtx gen_sminv4sf3 (rtx, rtx, rtx);
extern rtx gen_smaxv4df3 (rtx, rtx, rtx);
extern rtx gen_sminv4df3 (rtx, rtx, rtx);
extern rtx gen_smaxv2df3 (rtx, rtx, rtx);
extern rtx gen_sminv2df3 (rtx, rtx, rtx);
extern rtx gen_reduc_splus_v4df (rtx, rtx);
extern rtx gen_reduc_splus_v2df (rtx, rtx);
extern rtx gen_reduc_splus_v8sf (rtx, rtx);
extern rtx gen_reduc_splus_v4sf (rtx, rtx);
extern rtx gen_reduc_smax_v32qi (rtx, rtx);
extern rtx gen_reduc_smin_v32qi (rtx, rtx);
extern rtx gen_reduc_smax_v16hi (rtx, rtx);
extern rtx gen_reduc_smin_v16hi (rtx, rtx);
extern rtx gen_reduc_smax_v8si (rtx, rtx);
extern rtx gen_reduc_smin_v8si (rtx, rtx);
extern rtx gen_reduc_smax_v4di (rtx, rtx);
extern rtx gen_reduc_smin_v4di (rtx, rtx);
extern rtx gen_reduc_smax_v8sf (rtx, rtx);
extern rtx gen_reduc_smin_v8sf (rtx, rtx);
extern rtx gen_reduc_smax_v4df (rtx, rtx);
extern rtx gen_reduc_smin_v4df (rtx, rtx);
extern rtx gen_reduc_smax_v4sf (rtx, rtx);
extern rtx gen_reduc_smin_v4sf (rtx, rtx);
extern rtx gen_reduc_umax_v32qi (rtx, rtx);
extern rtx gen_reduc_umin_v32qi (rtx, rtx);
extern rtx gen_reduc_umax_v16hi (rtx, rtx);
extern rtx gen_reduc_umin_v16hi (rtx, rtx);
extern rtx gen_reduc_umax_v8si (rtx, rtx);
extern rtx gen_reduc_umin_v8si (rtx, rtx);
extern rtx gen_reduc_umax_v4di (rtx, rtx);
extern rtx gen_reduc_umin_v4di (rtx, rtx);
extern rtx gen_reduc_umin_v8hi (rtx, rtx);
extern rtx gen_vcondv32qiv8sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv16hiv8sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8siv8sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4div8sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8sfv8sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4dfv8sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv32qiv4df (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv16hiv4df (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8siv4df (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4div4df (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8sfv4df (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4dfv4df (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv16qiv4sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8hiv4sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4siv4sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv2div4sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4sfv4sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv2dfv4sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv16qiv2df (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8hiv2df (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4siv2df (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv2div2df (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4sfv2df (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv2dfv2df (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_andv8sf3 (rtx, rtx, rtx);
extern rtx gen_iorv8sf3 (rtx, rtx, rtx);
extern rtx gen_xorv8sf3 (rtx, rtx, rtx);
extern rtx gen_andv4sf3 (rtx, rtx, rtx);
extern rtx gen_iorv4sf3 (rtx, rtx, rtx);
extern rtx gen_xorv4sf3 (rtx, rtx, rtx);
extern rtx gen_andv4df3 (rtx, rtx, rtx);
extern rtx gen_iorv4df3 (rtx, rtx, rtx);
extern rtx gen_xorv4df3 (rtx, rtx, rtx);
extern rtx gen_andv2df3 (rtx, rtx, rtx);
extern rtx gen_iorv2df3 (rtx, rtx, rtx);
extern rtx gen_xorv2df3 (rtx, rtx, rtx);
extern rtx gen_copysignv8sf3 (rtx, rtx, rtx);
extern rtx gen_copysignv4sf3 (rtx, rtx, rtx);
extern rtx gen_copysignv4df3 (rtx, rtx, rtx);
extern rtx gen_copysignv2df3 (rtx, rtx, rtx);
extern rtx gen_fmasf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fmadf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fmav4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fmav2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fmav8sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fmav4df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fmssf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fmsdf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fmsv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fmsv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fmsv8sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fmsv4df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fnmasf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fnmadf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fnmav4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fnmav2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fnmav8sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fnmav4df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fnmssf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fnmsdf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fnmsv4sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fnmsv2df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fnmsv8sf4 (rtx, rtx, rtx, rtx);
extern rtx gen_fnmsv4df4 (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmadd_sf (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmadd_df (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmadd_v4sf (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmadd_v2df (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmadd_v8sf (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_fmadd_v4df (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_vmfmadd_v4sf (rtx, rtx, rtx, rtx);
extern rtx gen_fma4i_vmfmadd_v2df (rtx, rtx, rtx, rtx);
extern rtx gen_fmai_vmfmadd_v4sf (rtx, rtx, rtx, rtx);
extern rtx gen_fmai_vmfmadd_v2df (rtx, rtx, rtx, rtx);
extern rtx gen_fmaddsub_v8sf (rtx, rtx, rtx, rtx);
extern rtx gen_fmaddsub_v4sf (rtx, rtx, rtx, rtx);
extern rtx gen_fmaddsub_v4df (rtx, rtx, rtx, rtx);
extern rtx gen_fmaddsub_v2df (rtx, rtx, rtx, rtx);
extern rtx gen_floatunsv8siv8sf2 (rtx, rtx);
extern rtx gen_floatunsv4siv4sf2 (rtx, rtx);
extern rtx gen_fixuns_truncv8sfv8si2 (rtx, rtx);
extern rtx gen_fixuns_truncv4sfv4si2 (rtx, rtx);
extern rtx gen_avx_cvtpd2dq256_2 (rtx, rtx);
extern rtx gen_sse2_cvtpd2dq (rtx, rtx);
extern rtx gen_avx_cvttpd2dq256_2 (rtx, rtx);
extern rtx gen_sse2_cvttpd2dq (rtx, rtx);
extern rtx gen_sse2_cvtpd2ps (rtx, rtx);
extern rtx gen_vec_unpacks_hi_v4sf (rtx, rtx);
extern rtx gen_vec_unpacks_hi_v8sf (rtx, rtx);
extern rtx gen_vec_unpacks_lo_v4sf (rtx, rtx);
extern rtx gen_vec_unpacks_lo_v8sf (rtx, rtx);
extern rtx gen_vec_unpacks_float_hi_v16hi (rtx, rtx);
extern rtx gen_vec_unpacks_float_hi_v8hi (rtx, rtx);
extern rtx gen_vec_unpacks_float_lo_v16hi (rtx, rtx);
extern rtx gen_vec_unpacks_float_lo_v8hi (rtx, rtx);
extern rtx gen_vec_unpacku_float_hi_v16hi (rtx, rtx);
extern rtx gen_vec_unpacku_float_hi_v8hi (rtx, rtx);
extern rtx gen_vec_unpacku_float_lo_v16hi (rtx, rtx);
extern rtx gen_vec_unpacku_float_lo_v8hi (rtx, rtx);
extern rtx gen_vec_unpacks_float_hi_v4si (rtx, rtx);
extern rtx gen_vec_unpacks_float_lo_v4si (rtx, rtx);
extern rtx gen_vec_unpacks_float_hi_v8si (rtx, rtx);
extern rtx gen_vec_unpacks_float_lo_v8si (rtx, rtx);
extern rtx gen_vec_unpacku_float_hi_v4si (rtx, rtx);
extern rtx gen_vec_unpacku_float_lo_v4si (rtx, rtx);
extern rtx gen_vec_unpacku_float_hi_v8si (rtx, rtx);
extern rtx gen_vec_unpacku_float_lo_v8si (rtx, rtx);
extern rtx gen_vec_pack_trunc_v4df (rtx, rtx, rtx);
extern rtx gen_vec_pack_trunc_v2df (rtx, rtx, rtx);
extern rtx gen_vec_pack_sfix_trunc_v4df (rtx, rtx, rtx);
extern rtx gen_vec_pack_sfix_trunc_v2df (rtx, rtx, rtx);
extern rtx gen_vec_pack_ufix_trunc_v4df (rtx, rtx, rtx);
extern rtx gen_vec_pack_ufix_trunc_v2df (rtx, rtx, rtx);
extern rtx gen_vec_pack_sfix_v4df (rtx, rtx, rtx);
extern rtx gen_vec_pack_sfix_v2df (rtx, rtx, rtx);
extern rtx gen_sse_movhlps_exp (rtx, rtx, rtx);
extern rtx gen_sse_movlhps_exp (rtx, rtx, rtx);
extern rtx gen_vec_interleave_highv8sf (rtx, rtx, rtx);
extern rtx gen_vec_interleave_lowv8sf (rtx, rtx, rtx);
extern rtx gen_avx_shufps256 (rtx, rtx, rtx, rtx);
extern rtx gen_sse_shufps (rtx, rtx, rtx, rtx);
extern rtx gen_sse_loadhps_exp (rtx, rtx, rtx);
extern rtx gen_sse_loadlps_exp (rtx, rtx, rtx);
extern rtx gen_vec_initv16qi (rtx, rtx);
extern rtx gen_vec_initv8hi (rtx, rtx);
extern rtx gen_vec_initv4si (rtx, rtx);
extern rtx gen_vec_initv2di (rtx, rtx);
extern rtx gen_vec_initv4sf (rtx, rtx);
extern rtx gen_vec_initv2df (rtx, rtx);
extern rtx gen_vec_setv32qi (rtx, rtx, rtx);
extern rtx gen_vec_setv16qi (rtx, rtx, rtx);
extern rtx gen_vec_setv16hi (rtx, rtx, rtx);
extern rtx gen_vec_setv8hi (rtx, rtx, rtx);
extern rtx gen_vec_setv8si (rtx, rtx, rtx);
extern rtx gen_vec_setv4si (rtx, rtx, rtx);
extern rtx gen_vec_setv4di (rtx, rtx, rtx);
extern rtx gen_vec_setv2di (rtx, rtx, rtx);
extern rtx gen_vec_setv8sf (rtx, rtx, rtx);
extern rtx gen_vec_setv4sf (rtx, rtx, rtx);
extern rtx gen_vec_setv4df (rtx, rtx, rtx);
extern rtx gen_vec_setv2df (rtx, rtx, rtx);
extern rtx gen_avx_vextractf128v32qi (rtx, rtx, rtx);
extern rtx gen_avx_vextractf128v16hi (rtx, rtx, rtx);
extern rtx gen_avx_vextractf128v8si (rtx, rtx, rtx);
extern rtx gen_avx_vextractf128v4di (rtx, rtx, rtx);
extern rtx gen_avx_vextractf128v8sf (rtx, rtx, rtx);
extern rtx gen_avx_vextractf128v4df (rtx, rtx, rtx);
extern rtx gen_vec_extractv32qi (rtx, rtx, rtx);
extern rtx gen_vec_extractv16qi (rtx, rtx, rtx);
extern rtx gen_vec_extractv16hi (rtx, rtx, rtx);
extern rtx gen_vec_extractv8hi (rtx, rtx, rtx);
extern rtx gen_vec_extractv8si (rtx, rtx, rtx);
extern rtx gen_vec_extractv4si (rtx, rtx, rtx);
extern rtx gen_vec_extractv4di (rtx, rtx, rtx);
extern rtx gen_vec_extractv2di (rtx, rtx, rtx);
extern rtx gen_vec_extractv8sf (rtx, rtx, rtx);
extern rtx gen_vec_extractv4sf (rtx, rtx, rtx);
extern rtx gen_vec_extractv4df (rtx, rtx, rtx);
extern rtx gen_vec_extractv2df (rtx, rtx, rtx);
extern rtx gen_vec_interleave_highv4df (rtx, rtx, rtx);
extern rtx gen_vec_interleave_highv2df (rtx, rtx, rtx);
extern rtx gen_avx_movddup256 (rtx, rtx);
extern rtx gen_avx_unpcklpd256 (rtx, rtx, rtx);
extern rtx gen_vec_interleave_lowv4df (rtx, rtx, rtx);
extern rtx gen_vec_interleave_lowv2df (rtx, rtx, rtx);
extern rtx gen_avx_shufpd256 (rtx, rtx, rtx, rtx);
extern rtx gen_sse2_shufpd (rtx, rtx, rtx, rtx);
extern rtx gen_sse2_loadhpd_exp (rtx, rtx, rtx);
extern rtx gen_sse2_loadlpd_exp (rtx, rtx, rtx);
extern rtx gen_negv32qi2 (rtx, rtx);
extern rtx gen_negv16qi2 (rtx, rtx);
extern rtx gen_negv16hi2 (rtx, rtx);
extern rtx gen_negv8hi2 (rtx, rtx);
extern rtx gen_negv8si2 (rtx, rtx);
extern rtx gen_negv4si2 (rtx, rtx);
extern rtx gen_negv4di2 (rtx, rtx);
extern rtx gen_negv2di2 (rtx, rtx);
extern rtx gen_addv32qi3 (rtx, rtx, rtx);
extern rtx gen_subv32qi3 (rtx, rtx, rtx);
extern rtx gen_addv16qi3 (rtx, rtx, rtx);
extern rtx gen_subv16qi3 (rtx, rtx, rtx);
extern rtx gen_addv16hi3 (rtx, rtx, rtx);
extern rtx gen_subv16hi3 (rtx, rtx, rtx);
extern rtx gen_addv8hi3 (rtx, rtx, rtx);
extern rtx gen_subv8hi3 (rtx, rtx, rtx);
extern rtx gen_addv8si3 (rtx, rtx, rtx);
extern rtx gen_subv8si3 (rtx, rtx, rtx);
extern rtx gen_addv4si3 (rtx, rtx, rtx);
extern rtx gen_subv4si3 (rtx, rtx, rtx);
extern rtx gen_addv4di3 (rtx, rtx, rtx);
extern rtx gen_subv4di3 (rtx, rtx, rtx);
extern rtx gen_addv2di3 (rtx, rtx, rtx);
extern rtx gen_subv2di3 (rtx, rtx, rtx);
extern rtx gen_avx2_ssaddv32qi3 (rtx, rtx, rtx);
extern rtx gen_avx2_usaddv32qi3 (rtx, rtx, rtx);
extern rtx gen_avx2_sssubv32qi3 (rtx, rtx, rtx);
extern rtx gen_avx2_ussubv32qi3 (rtx, rtx, rtx);
extern rtx gen_sse2_ssaddv16qi3 (rtx, rtx, rtx);
extern rtx gen_sse2_usaddv16qi3 (rtx, rtx, rtx);
extern rtx gen_sse2_sssubv16qi3 (rtx, rtx, rtx);
extern rtx gen_sse2_ussubv16qi3 (rtx, rtx, rtx);
extern rtx gen_avx2_ssaddv16hi3 (rtx, rtx, rtx);
extern rtx gen_avx2_usaddv16hi3 (rtx, rtx, rtx);
extern rtx gen_avx2_sssubv16hi3 (rtx, rtx, rtx);
extern rtx gen_avx2_ussubv16hi3 (rtx, rtx, rtx);
extern rtx gen_sse2_ssaddv8hi3 (rtx, rtx, rtx);
extern rtx gen_sse2_usaddv8hi3 (rtx, rtx, rtx);
extern rtx gen_sse2_sssubv8hi3 (rtx, rtx, rtx);
extern rtx gen_sse2_ussubv8hi3 (rtx, rtx, rtx);
extern rtx gen_mulv16hi3 (rtx, rtx, rtx);
extern rtx gen_mulv8hi3 (rtx, rtx, rtx);
extern rtx gen_smulv16hi3_highpart (rtx, rtx, rtx);
extern rtx gen_umulv16hi3_highpart (rtx, rtx, rtx);
extern rtx gen_smulv8hi3_highpart (rtx, rtx, rtx);
extern rtx gen_umulv8hi3_highpart (rtx, rtx, rtx);
extern rtx gen_avx2_umulv4siv4di3 (rtx, rtx, rtx);
extern rtx gen_sse2_umulv2siv2di3 (rtx, rtx, rtx);
extern rtx gen_avx2_mulv4siv4di3 (rtx, rtx, rtx);
extern rtx gen_sse4_1_mulv2siv2di3 (rtx, rtx, rtx);
extern rtx gen_avx2_pmaddwd (rtx, rtx, rtx);
extern rtx gen_sse2_pmaddwd (rtx, rtx, rtx);
extern rtx gen_mulv8si3 (rtx, rtx, rtx);
extern rtx gen_mulv4si3 (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_hi_v16hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_hi_v16hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_hi_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_hi_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_lo_v16hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_lo_v16hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_lo_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_lo_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_hi_v8si (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_hi_v8si (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_lo_v8si (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_lo_v8si (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_hi_v4si (rtx, rtx, rtx);
extern rtx gen_vec_widen_smult_lo_v4si (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_hi_v4si (rtx, rtx, rtx);
extern rtx gen_vec_widen_umult_lo_v4si (rtx, rtx, rtx);
extern rtx gen_sdot_prodv16hi (rtx, rtx, rtx, rtx);
extern rtx gen_sdot_prodv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_sdot_prodv4si (rtx, rtx, rtx, rtx);
extern rtx gen_udot_prodv4si (rtx, rtx, rtx, rtx);
extern rtx gen_sdot_prodv8si (rtx, rtx, rtx, rtx);
extern rtx gen_udot_prodv8si (rtx, rtx, rtx, rtx);
extern rtx gen_vec_shl_v16qi (rtx, rtx, rtx);
extern rtx gen_vec_shl_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_shl_v4si (rtx, rtx, rtx);
extern rtx gen_vec_shl_v2di (rtx, rtx, rtx);
extern rtx gen_vec_shr_v16qi (rtx, rtx, rtx);
extern rtx gen_vec_shr_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_shr_v4si (rtx, rtx, rtx);
extern rtx gen_vec_shr_v2di (rtx, rtx, rtx);
extern rtx gen_smaxv32qi3 (rtx, rtx, rtx);
extern rtx gen_sminv32qi3 (rtx, rtx, rtx);
extern rtx gen_umaxv32qi3 (rtx, rtx, rtx);
extern rtx gen_uminv32qi3 (rtx, rtx, rtx);
extern rtx gen_smaxv16hi3 (rtx, rtx, rtx);
extern rtx gen_sminv16hi3 (rtx, rtx, rtx);
extern rtx gen_umaxv16hi3 (rtx, rtx, rtx);
extern rtx gen_uminv16hi3 (rtx, rtx, rtx);
extern rtx gen_smaxv8si3 (rtx, rtx, rtx);
extern rtx gen_sminv8si3 (rtx, rtx, rtx);
extern rtx gen_umaxv8si3 (rtx, rtx, rtx);
extern rtx gen_uminv8si3 (rtx, rtx, rtx);
extern rtx gen_smaxv4di3 (rtx, rtx, rtx);
extern rtx gen_sminv4di3 (rtx, rtx, rtx);
extern rtx gen_umaxv4di3 (rtx, rtx, rtx);
extern rtx gen_uminv4di3 (rtx, rtx, rtx);
extern rtx gen_smaxv2di3 (rtx, rtx, rtx);
extern rtx gen_sminv2di3 (rtx, rtx, rtx);
extern rtx gen_umaxv2di3 (rtx, rtx, rtx);
extern rtx gen_uminv2di3 (rtx, rtx, rtx);
extern rtx gen_smaxv16qi3 (rtx, rtx, rtx);
extern rtx gen_sminv16qi3 (rtx, rtx, rtx);
extern rtx gen_smaxv8hi3 (rtx, rtx, rtx);
extern rtx gen_sminv8hi3 (rtx, rtx, rtx);
extern rtx gen_smaxv4si3 (rtx, rtx, rtx);
extern rtx gen_sminv4si3 (rtx, rtx, rtx);
extern rtx gen_umaxv16qi3 (rtx, rtx, rtx);
extern rtx gen_uminv16qi3 (rtx, rtx, rtx);
extern rtx gen_umaxv8hi3 (rtx, rtx, rtx);
extern rtx gen_uminv8hi3 (rtx, rtx, rtx);
extern rtx gen_umaxv4si3 (rtx, rtx, rtx);
extern rtx gen_uminv4si3 (rtx, rtx, rtx);
extern rtx gen_avx2_eqv32qi3 (rtx, rtx, rtx);
extern rtx gen_avx2_eqv16hi3 (rtx, rtx, rtx);
extern rtx gen_avx2_eqv8si3 (rtx, rtx, rtx);
extern rtx gen_avx2_eqv4di3 (rtx, rtx, rtx);
extern rtx gen_sse2_eqv16qi3 (rtx, rtx, rtx);
extern rtx gen_sse2_eqv8hi3 (rtx, rtx, rtx);
extern rtx gen_sse2_eqv4si3 (rtx, rtx, rtx);
extern rtx gen_sse4_1_eqv2di3 (rtx, rtx, rtx);
extern rtx gen_vcondv32qiv32qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv16hiv32qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8siv32qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4div32qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8sfv32qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4dfv32qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv32qiv16hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv16hiv16hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8siv16hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4div16hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8sfv16hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4dfv16hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv32qiv8si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv16hiv8si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8siv8si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4div8si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8sfv8si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4dfv8si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv32qiv4di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv16hiv4di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8siv4di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4div4di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8sfv4di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4dfv4di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv16qiv16qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8hiv16qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4siv16qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv2div16qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4sfv16qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv2dfv16qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv16qiv8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8hiv8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4siv8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv2div8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4sfv8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv2dfv8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv16qiv4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv8hiv4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4siv4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv2div4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv4sfv4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv2dfv4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv2div2di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vcondv2dfv2di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv32qiv32qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv16hiv32qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv8siv32qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv4div32qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv8sfv32qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv4dfv32qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv32qiv16hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv16hiv16hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv8siv16hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv4div16hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv8sfv16hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv4dfv16hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv32qiv8si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv16hiv8si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv8siv8si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv4div8si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv8sfv8si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv4dfv8si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv32qiv4di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv16hiv4di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv8siv4di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv4div4di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv8sfv4di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv4dfv4di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv16qiv16qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv8hiv16qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv4siv16qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv2div16qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv4sfv16qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv2dfv16qi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv16qiv8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv8hiv8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv4siv8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv2div8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv4sfv8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv2dfv8hi (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv16qiv4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv8hiv4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv4siv4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv2div4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv4sfv4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv2dfv4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv2div2di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vconduv2dfv2di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_vec_permv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_vec_permv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_vec_permv4si (rtx, rtx, rtx, rtx);
extern rtx gen_vec_permv2di (rtx, rtx, rtx, rtx);
extern rtx gen_vec_permv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_vec_permv2df (rtx, rtx, rtx, rtx);
extern rtx gen_vec_permv32qi (rtx, rtx, rtx, rtx);
extern rtx gen_vec_permv16hi (rtx, rtx, rtx, rtx);
extern rtx gen_vec_permv8si (rtx, rtx, rtx, rtx);
extern rtx gen_vec_permv4di (rtx, rtx, rtx, rtx);
extern rtx gen_vec_permv8sf (rtx, rtx, rtx, rtx);
extern rtx gen_vec_permv4df (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv4sf (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv4si (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv2df (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv2di (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv16qi (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv8hi (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv8sf (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv4df (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv8si (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv4di (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv32qi (rtx, rtx, rtx, rtx);
extern rtx gen_vec_perm_constv16hi (rtx, rtx, rtx, rtx);
extern rtx gen_one_cmplv32qi2 (rtx, rtx);
extern rtx gen_one_cmplv16qi2 (rtx, rtx);
extern rtx gen_one_cmplv16hi2 (rtx, rtx);
extern rtx gen_one_cmplv8hi2 (rtx, rtx);
extern rtx gen_one_cmplv8si2 (rtx, rtx);
extern rtx gen_one_cmplv4si2 (rtx, rtx);
extern rtx gen_one_cmplv4di2 (rtx, rtx);
extern rtx gen_one_cmplv2di2 (rtx, rtx);
extern rtx gen_avx2_andnotv32qi3 (rtx, rtx, rtx);
extern rtx gen_sse2_andnotv16qi3 (rtx, rtx, rtx);
extern rtx gen_avx2_andnotv16hi3 (rtx, rtx, rtx);
extern rtx gen_sse2_andnotv8hi3 (rtx, rtx, rtx);
extern rtx gen_avx2_andnotv8si3 (rtx, rtx, rtx);
extern rtx gen_sse2_andnotv4si3 (rtx, rtx, rtx);
extern rtx gen_avx2_andnotv4di3 (rtx, rtx, rtx);
extern rtx gen_sse2_andnotv2di3 (rtx, rtx, rtx);
extern rtx gen_andv32qi3 (rtx, rtx, rtx);
extern rtx gen_iorv32qi3 (rtx, rtx, rtx);
extern rtx gen_xorv32qi3 (rtx, rtx, rtx);
extern rtx gen_andv16qi3 (rtx, rtx, rtx);
extern rtx gen_iorv16qi3 (rtx, rtx, rtx);
extern rtx gen_xorv16qi3 (rtx, rtx, rtx);
extern rtx gen_andv16hi3 (rtx, rtx, rtx);
extern rtx gen_iorv16hi3 (rtx, rtx, rtx);
extern rtx gen_xorv16hi3 (rtx, rtx, rtx);
extern rtx gen_andv8hi3 (rtx, rtx, rtx);
extern rtx gen_iorv8hi3 (rtx, rtx, rtx);
extern rtx gen_xorv8hi3 (rtx, rtx, rtx);
extern rtx gen_andv8si3 (rtx, rtx, rtx);
extern rtx gen_iorv8si3 (rtx, rtx, rtx);
extern rtx gen_xorv8si3 (rtx, rtx, rtx);
extern rtx gen_andv4si3 (rtx, rtx, rtx);
extern rtx gen_iorv4si3 (rtx, rtx, rtx);
extern rtx gen_xorv4si3 (rtx, rtx, rtx);
extern rtx gen_andv4di3 (rtx, rtx, rtx);
extern rtx gen_iorv4di3 (rtx, rtx, rtx);
extern rtx gen_xorv4di3 (rtx, rtx, rtx);
extern rtx gen_andv2di3 (rtx, rtx, rtx);
extern rtx gen_iorv2di3 (rtx, rtx, rtx);
extern rtx gen_xorv2di3 (rtx, rtx, rtx);
extern rtx gen_andtf3 (rtx, rtx, rtx);
extern rtx gen_iortf3 (rtx, rtx, rtx);
extern rtx gen_xortf3 (rtx, rtx, rtx);
extern rtx gen_vec_pack_trunc_v16hi (rtx, rtx, rtx);
extern rtx gen_vec_pack_trunc_v8hi (rtx, rtx, rtx);
extern rtx gen_vec_pack_trunc_v8si (rtx, rtx, rtx);
extern rtx gen_vec_pack_trunc_v4si (rtx, rtx, rtx);
extern rtx gen_vec_pack_trunc_v4di (rtx, rtx, rtx);
extern rtx gen_vec_pack_trunc_v2di (rtx, rtx, rtx);
extern rtx gen_vec_interleave_highv32qi (rtx, rtx, rtx);
extern rtx gen_vec_interleave_highv16hi (rtx, rtx, rtx);
extern rtx gen_vec_interleave_highv8si (rtx, rtx, rtx);
extern rtx gen_vec_interleave_highv4di (rtx, rtx, rtx);
extern rtx gen_vec_interleave_lowv32qi (rtx, rtx, rtx);
extern rtx gen_vec_interleave_lowv16hi (rtx, rtx, rtx);
extern rtx gen_vec_interleave_lowv8si (rtx, rtx, rtx);
extern rtx gen_vec_interleave_lowv4di (rtx, rtx, rtx);
extern rtx gen_avx2_pshufdv3 (rtx, rtx, rtx);
extern rtx gen_sse2_pshufd (rtx, rtx, rtx);
extern rtx gen_avx2_pshuflwv3 (rtx, rtx, rtx);
extern rtx gen_sse2_pshuflw (rtx, rtx, rtx);
extern rtx gen_avx2_pshufhwv3 (rtx, rtx, rtx);
extern rtx gen_sse2_pshufhw (rtx, rtx, rtx);
extern rtx gen_sse2_loadd (rtx, rtx);
extern rtx gen_sse_storeq (rtx, rtx);
extern rtx gen_vec_unpacks_lo_v32qi (rtx, rtx);
extern rtx gen_vec_unpacks_lo_v16qi (rtx, rtx);
extern rtx gen_vec_unpacks_lo_v16hi (rtx, rtx);
extern rtx gen_vec_unpacks_lo_v8hi (rtx, rtx);
extern rtx gen_vec_unpacks_lo_v8si (rtx, rtx);
extern rtx gen_vec_unpacks_lo_v4si (rtx, rtx);
extern rtx gen_vec_unpacks_hi_v32qi (rtx, rtx);
extern rtx gen_vec_unpacks_hi_v16qi (rtx, rtx);
extern rtx gen_vec_unpacks_hi_v16hi (rtx, rtx);
extern rtx gen_vec_unpacks_hi_v8hi (rtx, rtx);
extern rtx gen_vec_unpacks_hi_v8si (rtx, rtx);
extern rtx gen_vec_unpacks_hi_v4si (rtx, rtx);
extern rtx gen_vec_unpacku_lo_v32qi (rtx, rtx);
extern rtx gen_vec_unpacku_lo_v16qi (rtx, rtx);
extern rtx gen_vec_unpacku_lo_v16hi (rtx, rtx);
extern rtx gen_vec_unpacku_lo_v8hi (rtx, rtx);
extern rtx gen_vec_unpacku_lo_v8si (rtx, rtx);
extern rtx gen_vec_unpacku_lo_v4si (rtx, rtx);
extern rtx gen_vec_unpacku_hi_v32qi (rtx, rtx);
extern rtx gen_vec_unpacku_hi_v16qi (rtx, rtx);
extern rtx gen_vec_unpacku_hi_v16hi (rtx, rtx);
extern rtx gen_vec_unpacku_hi_v8hi (rtx, rtx);
extern rtx gen_vec_unpacku_hi_v8si (rtx, rtx);
extern rtx gen_vec_unpacku_hi_v4si (rtx, rtx);
extern rtx gen_avx2_uavgv32qi3 (rtx, rtx, rtx);
extern rtx gen_sse2_uavgv16qi3 (rtx, rtx, rtx);
extern rtx gen_avx2_uavgv16hi3 (rtx, rtx, rtx);
extern rtx gen_sse2_uavgv8hi3 (rtx, rtx, rtx);
extern rtx gen_sse2_maskmovdqu (rtx, rtx, rtx);
extern rtx gen_avx2_umulhrswv16hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_pmulhrswv8hi3 (rtx, rtx, rtx);
extern rtx gen_ssse3_pmulhrswv4hi3 (rtx, rtx, rtx);
extern rtx gen_avx2_pblendw (rtx, rtx, rtx, rtx);
extern rtx gen_avx_roundps_sfix256 (rtx, rtx, rtx);
extern rtx gen_sse4_1_roundps_sfix (rtx, rtx, rtx);
extern rtx gen_avx_roundpd_vec_pack_sfix256 (rtx, rtx, rtx, rtx);
extern rtx gen_sse4_1_roundpd_vec_pack_sfix (rtx, rtx, rtx, rtx);
extern rtx gen_roundv8sf2 (rtx, rtx);
extern rtx gen_roundv4sf2 (rtx, rtx);
extern rtx gen_roundv4df2 (rtx, rtx);
extern rtx gen_roundv2df2 (rtx, rtx);
extern rtx gen_roundv8sf2_sfix (rtx, rtx);
extern rtx gen_roundv4sf2_sfix (rtx, rtx);
extern rtx gen_roundv4df2_vec_pack_sfix (rtx, rtx, rtx);
extern rtx gen_roundv2df2_vec_pack_sfix (rtx, rtx, rtx);
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
extern rtx gen_vlshrv2di3 (rtx, rtx, rtx);
extern rtx gen_vlshrv8si3 (rtx, rtx, rtx);
extern rtx gen_vlshrv4di3 (rtx, rtx, rtx);
extern rtx gen_vashrv16qi3 (rtx, rtx, rtx);
extern rtx gen_vashrv8hi3 (rtx, rtx, rtx);
extern rtx gen_vashrv2di3 (rtx, rtx, rtx);
extern rtx gen_vashrv4si3 (rtx, rtx, rtx);
extern rtx gen_vashrv8si3 (rtx, rtx, rtx);
extern rtx gen_vashlv16qi3 (rtx, rtx, rtx);
extern rtx gen_vashlv8hi3 (rtx, rtx, rtx);
extern rtx gen_vashlv4si3 (rtx, rtx, rtx);
extern rtx gen_vashlv2di3 (rtx, rtx, rtx);
extern rtx gen_vashlv8si3 (rtx, rtx, rtx);
extern rtx gen_vashlv4di3 (rtx, rtx, rtx);
extern rtx gen_ashlv16qi3 (rtx, rtx, rtx);
extern rtx gen_lshrv16qi3 (rtx, rtx, rtx);
extern rtx gen_ashrv16qi3 (rtx, rtx, rtx);
extern rtx gen_ashrv2di3 (rtx, rtx, rtx);
extern rtx gen_xop_vmfrczv4sf2 (rtx, rtx);
extern rtx gen_xop_vmfrczv2df2 (rtx, rtx);
extern rtx gen_avx_vzeroall (void);
extern rtx gen_avx2_permv4di (rtx, rtx, rtx);
extern rtx gen_avx_vpermilv4df (rtx, rtx, rtx);
extern rtx gen_avx_vpermilv2df (rtx, rtx, rtx);
extern rtx gen_avx_vpermilv8sf (rtx, rtx, rtx);
extern rtx gen_avx_vpermilv4sf (rtx, rtx, rtx);
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
extern rtx gen_avx2_extracti128 (rtx, rtx, rtx);
extern rtx gen_avx2_inserti128 (rtx, rtx, rtx, rtx);
extern rtx gen_vcvtps2ph (rtx, rtx, rtx);
extern rtx gen_avx2_gathersiv2di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_gathersiv2df (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_gathersiv4di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_gathersiv4df (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_gathersiv4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_gathersiv4sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_gathersiv8si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_gathersiv8sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_gatherdiv2di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_gatherdiv2df (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_gatherdiv4di (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_gatherdiv4df (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_gatherdiv4si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_gatherdiv4sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_gatherdiv8si (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_avx2_gatherdiv8sf (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_sse2_lfence (void);
extern rtx gen_sse_sfence (void);
extern rtx gen_sse2_mfence (void);
extern rtx gen_mem_thread_fence (rtx);
extern rtx gen_atomic_loadqi (rtx, rtx, rtx);
extern rtx gen_atomic_loadhi (rtx, rtx, rtx);
extern rtx gen_atomic_loadsi (rtx, rtx, rtx);
extern rtx gen_atomic_loaddi (rtx, rtx, rtx);
extern rtx gen_atomic_storeqi (rtx, rtx, rtx);
extern rtx gen_atomic_storehi (rtx, rtx, rtx);
extern rtx gen_atomic_storesi (rtx, rtx, rtx);
extern rtx gen_atomic_storedi (rtx, rtx, rtx);
extern rtx gen_atomic_compare_and_swapqi (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_atomic_compare_and_swaphi (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_atomic_compare_and_swapsi (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_atomic_compare_and_swapdi (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx gen_atomic_compare_and_swapti (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
# 39 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2

# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/defaults.h" 1
# 1007 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/defaults.h"
       
# 41 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 2
# 26 "../../../src/plugin-utils.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/langhooks.h" 1
# 26 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/langhooks.h"
struct diagnostic_info;

struct gimplify_omp_ctx;

struct array_descr_info;


typedef void (*lang_print_tree_hook) (FILE *, tree, int indent);

enum classify_record
  { RECORD_IS_STRUCT, RECORD_IS_CLASS, RECORD_IS_INTERFACE };




struct lang_hooks_for_tree_inlining
{
  bool (*var_mod_type_p) (tree, tree);
};

struct lang_hooks_for_callgraph
{


  tree (*analyze_expr) (tree *, int *);
};



struct lang_hooks_for_tree_dump
{


  bool (*dump_tree) (void *, tree);


  int (*type_quals) (const_tree);
};



struct lang_hooks_for_types
{


  tree (*make_type) (enum tree_code);




  enum classify_record (*classify_record) (tree);



  tree (*type_for_mode) (enum machine_mode, int);



  tree (*type_for_size) (unsigned, int);



  bool (*generic_p) (const_tree);


  tree (*get_argument_pack_elems) (const_tree);





  tree (*type_promotes_to) (tree);
# 106 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/langhooks.h"
  void (*register_builtin_type) (tree, const char *);





  void (*incomplete_type_error) (const_tree value, const_tree type);



  tree (*max_size) (const_tree);



  void (*omp_firstprivatize_type_sizes) (struct gimplify_omp_ctx *, tree);





  bool (*type_hash_eq) (const_tree, const_tree);



  bool (*get_array_descr_info) (const_tree, struct array_descr_info *);


  void (*get_subrange_bounds) (const_tree, tree *, tree *);




  tree (*descriptive_type) (const_tree);





  tree (*reconstruct_complex_type) (tree, tree);
};



struct lang_hooks_for_decls
{



  bool (*global_bindings_p) (void);





  tree (*pushdecl) (tree);


  tree (*getdecls) (void);


  bool (*function_decl_explicit_p) (tree);



  bool (*generic_generic_parameter_decl_p) (const_tree);



  bool (*function_parm_expanded_from_pack_p) (tree, tree);


  tree (*get_generic_function_decl) (const_tree);



  bool (*warn_unused_global) (const_tree);



  void (*final_write_globals) (void);


  bool (*ok_for_sibcall) (const_tree);



  bool (*omp_privatize_by_reference) (const_tree);



  enum omp_clause_default_kind (*omp_predetermined_sharing) (tree);



  tree (*omp_report_decl) (tree);





  bool (*omp_disregard_value_expr) (tree, bool);



  bool (*omp_private_debug_clause) (tree, bool);



  bool (*omp_private_outer_ref) (tree);




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




  bool (*complain_wrong_lang_p) (const struct cl_option *option);
# 304 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/langhooks.h"
  bool (*handle_option) (size_t code, const char *arg, int value, int kind,
    location_t loc,
    const struct cl_option_handlers *handlers);
# 316 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/langhooks.h"
  bool (*post_options) (const char **);




  bool (*init) (void);


  void (*finish) (void);


  void (*parse_file) (void);


  bool (*missing_noreturn_ok_p) (tree);



  alias_set_type (*get_alias_set) (tree);



  void (*finish_incomplete_decl) (tree);



  void (*dup_lang_specific_decl) (tree);






  void (*set_decl_assembler_name) (tree);



  void (*print_statistics) (void);



  lang_print_tree_hook print_xnode;



  lang_print_tree_hook print_decl;
  lang_print_tree_hook print_type;
  lang_print_tree_hook print_identifier;
# 374 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/langhooks.h"
  const char *(*decl_printable_name) (tree decl, int verbosity);




  const char *(*dwarf_name) (tree, int verbosity);




  int (*types_compatible_p) (tree x, tree y);


  void (*print_error_function) (diagnostic_context *, const char *,
    struct diagnostic_info *);
# 397 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/langhooks.h"
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


  bool (*function_parameter_pack_p) (const_tree);



  int (*gimplify_expr) (tree *, gimple_seq *, gimple_seq *);


  tree (*builtin_function) (tree decl);







  tree (*builtin_function_ext_scope) (tree decl);


  void (*init_ts) (void);




  tree (*expr_to_decl) (tree expr, bool *tc, bool *se);


  tree (*eh_personality) (void);


  tree (*eh_runtime_type) (tree);







  tree (*eh_protect_cleanup_actions) (void);



  bool eh_use_cxa_end_cleanup;



  bool deep_unsharing;



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




# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h" 1
# 26 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/ggc.h" 1
# 30 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/ggc.h"
extern const char empty_string[];





typedef void (*gt_pointer_operator) (void *, void *);

# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/gtype-desc.h" 1
# 23 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/gtype-desc.h"
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
 gt_ggc_e_17stack_local_entry,
 gt_ggc_e_19machine_frame_state,
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
# 6588 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/gtype-desc.h"
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



extern void gt_ggc_mx_stack_local_entry (void *);



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
# 7440 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/gtype-desc.h"
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



extern void gt_pch_nx_stack_local_entry (void *);



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
extern void gt_pch_p_17stack_local_entry
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
# 39 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/ggc.h" 2




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
# 112 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/ggc.h"
extern int ggc_set_mark (const void *);




extern int ggc_marked_p (const void *);


extern void gt_pch_n_S (const void *);
extern void gt_ggc_m_S (const void *);



struct alloc_zone;


extern void init_stringpool (void);


extern void init_ggc (void);





extern bool ggc_protect_identifiers;


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

extern void dump_ggc_loc_statistics (bool);
# 179 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/ggc.h"
static inline void *
ggc_internal_vec_alloc_stat (size_t s, size_t c )
{
    return ggc_internal_alloc_stat (c * s );
}

static inline void *
ggc_internal_cleared_vec_alloc_stat (size_t s, size_t c )
{
    return ggc_internal_cleared_alloc_stat (c * s );
}




static inline void *
ggc_alloc_atomic_stat (size_t s )
{
    return ggc_internal_alloc_stat (s );
}






extern void * ggc_cleared_alloc_htab_ignore_args (size_t, size_t);

extern void * ggc_cleared_alloc_ptr_array_two_args (size_t, size_t);
# 219 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/ggc.h"
extern void *ggc_splay_alloc (enum gt_types_enum, int, void *);

extern void ggc_splay_dont_free (void *, void *);




extern const char *ggc_alloc_string_stat (const char *contents, int length
                                          );
# 236 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/ggc.h"
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
# 307 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/ggc.h"
static inline void *
ggc_internal_zone_alloc_stat (struct alloc_zone * z __attribute__ ((__unused__)),
                              size_t s )
{
    return ggc_internal_alloc_stat (s );
}

static inline void *
ggc_internal_zone_cleared_alloc_stat (struct alloc_zone * z __attribute__ ((__unused__)),
                                      size_t s )
{
    return ggc_internal_cleared_alloc_stat (s );
}

static inline void *
ggc_internal_zone_vec_alloc_stat (struct alloc_zone * z __attribute__ ((__unused__)),
                                  size_t s, size_t n )
{
    return ggc_internal_vec_alloc_stat (s, n );
}





static inline struct rtx_def *
ggc_alloc_zone_rtx_def_stat (struct alloc_zone * z, size_t s )
{
  return (struct rtx_def *) ggc_internal_zone_alloc_stat (z, s );
}

static inline union tree_node *
ggc_alloc_zone_tree_node_stat (struct alloc_zone * z, size_t s )
{
  return (union tree_node *) ggc_internal_zone_alloc_stat (z, s );
}

static inline union tree_node *
ggc_alloc_zone_cleared_tree_node_stat (struct alloc_zone * z, size_t s
                                       )
{
  return (union tree_node *)
    ggc_internal_zone_cleared_alloc_stat (z, s );
}

static inline union gimple_statement_d *
ggc_alloc_cleared_gimple_statement_d_stat (size_t s )
{
  return (union gimple_statement_d *)
    ggc_internal_cleared_alloc_stat (s );
}
# 27 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/function.h" 1
# 25 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/function.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tree.h" 1
# 26 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/function.h" 2

# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/vecprim.h" 1
# 23 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/vecprim.h"
static inline void VEC_char_must_be_integral_type (void) { (void)~(char)0; } typedef struct VEC_char_base { struct vec_prefix prefix; char vec[1]; } VEC_char_base; typedef struct VEC_char_none { VEC_char_base base; } VEC_char_none; static inline unsigned VEC_char_base_length (const VEC_char_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline char VEC_char_base_last (const VEC_char_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static inline char VEC_char_base_index (const VEC_char_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static inline int VEC_char_base_iterate (const VEC_char_base *vec_, unsigned ix_, char *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (char) 0; return 0; } } static inline size_t VEC_char_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_char_base, vec) + alloc_ * sizeof(char); } static inline void VEC_char_base_embedded_init (VEC_char_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_char_base_space (VEC_char_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_char_base_splice (VEC_char_base *dst_, VEC_char_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (char)); dst_->prefix.num += len_; } } static inline char *VEC_char_base_quick_push (VEC_char_base *vec_, char obj_ ) { char *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static inline char VEC_char_base_pop (VEC_char_base *vec_ ) { char obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_char_base_truncate (VEC_char_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline char VEC_char_base_replace (VEC_char_base *vec_, unsigned ix_, char obj_ ) { char old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static inline char *VEC_char_base_quick_insert (VEC_char_base *vec_, unsigned ix_, char obj_ ) { char *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (char)); *slot_ = obj_; return slot_; } static inline char VEC_char_base_ordered_remove (VEC_char_base *vec_, unsigned ix_ ) { char *slot_; char obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (char)); return obj_; } static inline char VEC_char_base_unordered_remove (VEC_char_base *vec_, unsigned ix_ ) { char *slot_; char obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_char_base_block_remove (VEC_char_base *vec_, unsigned ix_, unsigned len_ ) { char *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (char)); } static inline char *VEC_char_base_address (VEC_char_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_char_base_lower_bound (VEC_char_base *vec_, const char obj_, bool (*lessthan_)(const char, const char) ) { unsigned int len_ = VEC_char_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { char middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_char_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_char_heap { VEC_char_base base; } VEC_char_heap; static inline VEC_char_heap *VEC_char_heap_alloc (int alloc_ ) { return (VEC_char_heap *) vec_heap_o_reserve_exact (__null, alloc_, __builtin_offsetof (VEC_char_heap, base.vec), sizeof (char) ); } static inline VEC_char_heap *VEC_char_heap_copy (VEC_char_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_char_heap *new_vec_ = __null; if (len_) { new_vec_ = (VEC_char_heap *)(vec_heap_o_reserve_exact (__null, len_, __builtin_offsetof (VEC_char_heap, base.vec), sizeof (char) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (char) * len_); } return new_vec_; } static inline void VEC_char_heap_free (VEC_char_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = __null; } static inline int VEC_char_heap_reserve (VEC_char_heap **vec_, int alloc_ ) { int extend = !VEC_char_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_char_heap *) vec_heap_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_char_heap, base.vec), sizeof (char) ); return extend; } static inline int VEC_char_heap_reserve_exact (VEC_char_heap **vec_, int alloc_ ) { int extend = !VEC_char_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_char_heap *) vec_heap_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_char_heap, base.vec), sizeof (char) ); return extend; } static inline void VEC_char_heap_safe_grow (VEC_char_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_char_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_char_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_char_heap_safe_grow_cleared (VEC_char_heap **vec_, int size_ ) { int oldsize = VEC_char_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_char_heap_safe_grow (vec_, size_ ); memset (&(VEC_char_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (char) * (size_ - oldsize)); } static inline void VEC_char_heap_safe_splice (VEC_char_heap **dst_, VEC_char_base *src_ ) { if (src_) { VEC_char_heap_reserve_exact (dst_, src_->prefix.num ); VEC_char_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline char *VEC_char_heap_safe_push (VEC_char_heap **vec_, const char obj_ ) { VEC_char_heap_reserve (vec_, 1 ); return VEC_char_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline char *VEC_char_heap_safe_insert (VEC_char_heap **vec_, unsigned ix_, const char obj_ ) { VEC_char_heap_reserve (vec_, 1 ); return VEC_char_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;

typedef unsigned char uchar;
static inline void VEC_uchar_must_be_integral_type (void) { (void)~(uchar)0; } typedef struct VEC_uchar_base { struct vec_prefix prefix; uchar vec[1]; } VEC_uchar_base; typedef struct VEC_uchar_none { VEC_uchar_base base; } VEC_uchar_none; static inline unsigned VEC_uchar_base_length (const VEC_uchar_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline uchar VEC_uchar_base_last (const VEC_uchar_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static inline uchar VEC_uchar_base_index (const VEC_uchar_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static inline int VEC_uchar_base_iterate (const VEC_uchar_base *vec_, unsigned ix_, uchar *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (uchar) 0; return 0; } } static inline size_t VEC_uchar_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_uchar_base, vec) + alloc_ * sizeof(uchar); } static inline void VEC_uchar_base_embedded_init (VEC_uchar_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_uchar_base_space (VEC_uchar_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_uchar_base_splice (VEC_uchar_base *dst_, VEC_uchar_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (uchar)); dst_->prefix.num += len_; } } static inline uchar *VEC_uchar_base_quick_push (VEC_uchar_base *vec_, uchar obj_ ) { uchar *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static inline uchar VEC_uchar_base_pop (VEC_uchar_base *vec_ ) { uchar obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_uchar_base_truncate (VEC_uchar_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline uchar VEC_uchar_base_replace (VEC_uchar_base *vec_, unsigned ix_, uchar obj_ ) { uchar old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static inline uchar *VEC_uchar_base_quick_insert (VEC_uchar_base *vec_, unsigned ix_, uchar obj_ ) { uchar *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (uchar)); *slot_ = obj_; return slot_; } static inline uchar VEC_uchar_base_ordered_remove (VEC_uchar_base *vec_, unsigned ix_ ) { uchar *slot_; uchar obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (uchar)); return obj_; } static inline uchar VEC_uchar_base_unordered_remove (VEC_uchar_base *vec_, unsigned ix_ ) { uchar *slot_; uchar obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_uchar_base_block_remove (VEC_uchar_base *vec_, unsigned ix_, unsigned len_ ) { uchar *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (uchar)); } static inline uchar *VEC_uchar_base_address (VEC_uchar_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_uchar_base_lower_bound (VEC_uchar_base *vec_, const uchar obj_, bool (*lessthan_)(const uchar, const uchar) ) { unsigned int len_ = VEC_uchar_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { uchar middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_uchar_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_uchar_heap { VEC_uchar_base base; } VEC_uchar_heap; static inline VEC_uchar_heap *VEC_uchar_heap_alloc (int alloc_ ) { return (VEC_uchar_heap *) vec_heap_o_reserve_exact (__null, alloc_, __builtin_offsetof (VEC_uchar_heap, base.vec), sizeof (uchar) ); } static inline VEC_uchar_heap *VEC_uchar_heap_copy (VEC_uchar_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_uchar_heap *new_vec_ = __null; if (len_) { new_vec_ = (VEC_uchar_heap *)(vec_heap_o_reserve_exact (__null, len_, __builtin_offsetof (VEC_uchar_heap, base.vec), sizeof (uchar) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (uchar) * len_); } return new_vec_; } static inline void VEC_uchar_heap_free (VEC_uchar_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = __null; } static inline int VEC_uchar_heap_reserve (VEC_uchar_heap **vec_, int alloc_ ) { int extend = !VEC_uchar_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_uchar_heap *) vec_heap_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_uchar_heap, base.vec), sizeof (uchar) ); return extend; } static inline int VEC_uchar_heap_reserve_exact (VEC_uchar_heap **vec_, int alloc_ ) { int extend = !VEC_uchar_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_uchar_heap *) vec_heap_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_uchar_heap, base.vec), sizeof (uchar) ); return extend; } static inline void VEC_uchar_heap_safe_grow (VEC_uchar_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_uchar_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_uchar_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_uchar_heap_safe_grow_cleared (VEC_uchar_heap **vec_, int size_ ) { int oldsize = VEC_uchar_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_uchar_heap_safe_grow (vec_, size_ ); memset (&(VEC_uchar_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (uchar) * (size_ - oldsize)); } static inline void VEC_uchar_heap_safe_splice (VEC_uchar_heap **dst_, VEC_uchar_base *src_ ) { if (src_) { VEC_uchar_heap_reserve_exact (dst_, src_->prefix.num ); VEC_uchar_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline uchar *VEC_uchar_heap_safe_push (VEC_uchar_heap **vec_, const uchar obj_ ) { VEC_uchar_heap_reserve (vec_, 1 ); return VEC_uchar_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline uchar *VEC_uchar_heap_safe_insert (VEC_uchar_heap **vec_, unsigned ix_, const uchar obj_ ) { VEC_uchar_heap_reserve (vec_, 1 ); return VEC_uchar_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
typedef struct VEC_uchar_gc { VEC_uchar_base base; } VEC_uchar_gc; static inline VEC_uchar_gc *VEC_uchar_gc_alloc (int alloc_ ) { return (VEC_uchar_gc *) vec_gc_o_reserve_exact (__null, alloc_, __builtin_offsetof (VEC_uchar_gc, base.vec), sizeof (uchar) ); } static inline VEC_uchar_gc *VEC_uchar_gc_copy (VEC_uchar_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_uchar_gc *new_vec_ = __null; if (len_) { new_vec_ = (VEC_uchar_gc *)(vec_gc_o_reserve_exact (__null, len_, __builtin_offsetof (VEC_uchar_gc, base.vec), sizeof (uchar) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (uchar) * len_); } return new_vec_; } static inline void VEC_uchar_gc_free (VEC_uchar_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = __null; } static inline int VEC_uchar_gc_reserve (VEC_uchar_gc **vec_, int alloc_ ) { int extend = !VEC_uchar_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_uchar_gc *) vec_gc_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_uchar_gc, base.vec), sizeof (uchar) ); return extend; } static inline int VEC_uchar_gc_reserve_exact (VEC_uchar_gc **vec_, int alloc_ ) { int extend = !VEC_uchar_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_uchar_gc *) vec_gc_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_uchar_gc, base.vec), sizeof (uchar) ); return extend; } static inline void VEC_uchar_gc_safe_grow (VEC_uchar_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_uchar_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_uchar_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_uchar_gc_safe_grow_cleared (VEC_uchar_gc **vec_, int size_ ) { int oldsize = VEC_uchar_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_uchar_gc_safe_grow (vec_, size_ ); memset (&(VEC_uchar_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (uchar) * (size_ - oldsize)); } static inline void VEC_uchar_gc_safe_splice (VEC_uchar_gc **dst_, VEC_uchar_base *src_ ) { if (src_) { VEC_uchar_gc_reserve_exact (dst_, src_->prefix.num ); VEC_uchar_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline uchar *VEC_uchar_gc_safe_push (VEC_uchar_gc **vec_, const uchar obj_ ) { VEC_uchar_gc_reserve (vec_, 1 ); return VEC_uchar_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline uchar *VEC_uchar_gc_safe_insert (VEC_uchar_gc **vec_, unsigned ix_, const uchar obj_ ) { VEC_uchar_gc_reserve (vec_, 1 ); return VEC_uchar_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;

static inline void VEC_int_must_be_integral_type (void) { (void)~(int)0; } typedef struct VEC_int_base { struct vec_prefix prefix; int vec[1]; } VEC_int_base; typedef struct VEC_int_none { VEC_int_base base; } VEC_int_none; static inline unsigned VEC_int_base_length (const VEC_int_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline int VEC_int_base_last (const VEC_int_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static inline int VEC_int_base_index (const VEC_int_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static inline int VEC_int_base_iterate (const VEC_int_base *vec_, unsigned ix_, int *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (int) 0; return 0; } } static inline size_t VEC_int_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_int_base, vec) + alloc_ * sizeof(int); } static inline void VEC_int_base_embedded_init (VEC_int_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_int_base_space (VEC_int_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_int_base_splice (VEC_int_base *dst_, VEC_int_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (int)); dst_->prefix.num += len_; } } static inline int *VEC_int_base_quick_push (VEC_int_base *vec_, int obj_ ) { int *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static inline int VEC_int_base_pop (VEC_int_base *vec_ ) { int obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_int_base_truncate (VEC_int_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline int VEC_int_base_replace (VEC_int_base *vec_, unsigned ix_, int obj_ ) { int old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static inline int *VEC_int_base_quick_insert (VEC_int_base *vec_, unsigned ix_, int obj_ ) { int *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (int)); *slot_ = obj_; return slot_; } static inline int VEC_int_base_ordered_remove (VEC_int_base *vec_, unsigned ix_ ) { int *slot_; int obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (int)); return obj_; } static inline int VEC_int_base_unordered_remove (VEC_int_base *vec_, unsigned ix_ ) { int *slot_; int obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_int_base_block_remove (VEC_int_base *vec_, unsigned ix_, unsigned len_ ) { int *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (int)); } static inline int *VEC_int_base_address (VEC_int_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_int_base_lower_bound (VEC_int_base *vec_, const int obj_, bool (*lessthan_)(const int, const int) ) { unsigned int len_ = VEC_int_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { int middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_int_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_int_heap { VEC_int_base base; } VEC_int_heap; static inline VEC_int_heap *VEC_int_heap_alloc (int alloc_ ) { return (VEC_int_heap *) vec_heap_o_reserve_exact (__null, alloc_, __builtin_offsetof (VEC_int_heap, base.vec), sizeof (int) ); } static inline VEC_int_heap *VEC_int_heap_copy (VEC_int_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_int_heap *new_vec_ = __null; if (len_) { new_vec_ = (VEC_int_heap *)(vec_heap_o_reserve_exact (__null, len_, __builtin_offsetof (VEC_int_heap, base.vec), sizeof (int) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (int) * len_); } return new_vec_; } static inline void VEC_int_heap_free (VEC_int_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = __null; } static inline int VEC_int_heap_reserve (VEC_int_heap **vec_, int alloc_ ) { int extend = !VEC_int_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_int_heap *) vec_heap_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_int_heap, base.vec), sizeof (int) ); return extend; } static inline int VEC_int_heap_reserve_exact (VEC_int_heap **vec_, int alloc_ ) { int extend = !VEC_int_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_int_heap *) vec_heap_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_int_heap, base.vec), sizeof (int) ); return extend; } static inline void VEC_int_heap_safe_grow (VEC_int_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_int_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_int_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_int_heap_safe_grow_cleared (VEC_int_heap **vec_, int size_ ) { int oldsize = VEC_int_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_int_heap_safe_grow (vec_, size_ ); memset (&(VEC_int_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (int) * (size_ - oldsize)); } static inline void VEC_int_heap_safe_splice (VEC_int_heap **dst_, VEC_int_base *src_ ) { if (src_) { VEC_int_heap_reserve_exact (dst_, src_->prefix.num ); VEC_int_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline int *VEC_int_heap_safe_push (VEC_int_heap **vec_, const int obj_ ) { VEC_int_heap_reserve (vec_, 1 ); return VEC_int_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline int *VEC_int_heap_safe_insert (VEC_int_heap **vec_, unsigned ix_, const int obj_ ) { VEC_int_heap_reserve (vec_, 1 ); return VEC_int_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;

static inline void VEC_unsigned_must_be_integral_type (void) { (void)~(unsigned)0; } typedef struct VEC_unsigned_base { struct vec_prefix prefix; unsigned vec[1]; } VEC_unsigned_base; typedef struct VEC_unsigned_none { VEC_unsigned_base base; } VEC_unsigned_none; static inline unsigned VEC_unsigned_base_length (const VEC_unsigned_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline unsigned VEC_unsigned_base_last (const VEC_unsigned_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static inline unsigned VEC_unsigned_base_index (const VEC_unsigned_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static inline int VEC_unsigned_base_iterate (const VEC_unsigned_base *vec_, unsigned ix_, unsigned *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (unsigned) 0; return 0; } } static inline size_t VEC_unsigned_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_unsigned_base, vec) + alloc_ * sizeof(unsigned); } static inline void VEC_unsigned_base_embedded_init (VEC_unsigned_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_unsigned_base_space (VEC_unsigned_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_unsigned_base_splice (VEC_unsigned_base *dst_, VEC_unsigned_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (unsigned)); dst_->prefix.num += len_; } } static inline unsigned *VEC_unsigned_base_quick_push (VEC_unsigned_base *vec_, unsigned obj_ ) { unsigned *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static inline unsigned VEC_unsigned_base_pop (VEC_unsigned_base *vec_ ) { unsigned obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_unsigned_base_truncate (VEC_unsigned_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline unsigned VEC_unsigned_base_replace (VEC_unsigned_base *vec_, unsigned ix_, unsigned obj_ ) { unsigned old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static inline unsigned *VEC_unsigned_base_quick_insert (VEC_unsigned_base *vec_, unsigned ix_, unsigned obj_ ) { unsigned *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (unsigned)); *slot_ = obj_; return slot_; } static inline unsigned VEC_unsigned_base_ordered_remove (VEC_unsigned_base *vec_, unsigned ix_ ) { unsigned *slot_; unsigned obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (unsigned)); return obj_; } static inline unsigned VEC_unsigned_base_unordered_remove (VEC_unsigned_base *vec_, unsigned ix_ ) { unsigned *slot_; unsigned obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_unsigned_base_block_remove (VEC_unsigned_base *vec_, unsigned ix_, unsigned len_ ) { unsigned *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (unsigned)); } static inline unsigned *VEC_unsigned_base_address (VEC_unsigned_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_unsigned_base_lower_bound (VEC_unsigned_base *vec_, const unsigned obj_, bool (*lessthan_)(const unsigned, const unsigned) ) { unsigned int len_ = VEC_unsigned_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { unsigned middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_unsigned_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_unsigned_heap { VEC_unsigned_base base; } VEC_unsigned_heap; static inline VEC_unsigned_heap *VEC_unsigned_heap_alloc (int alloc_ ) { return (VEC_unsigned_heap *) vec_heap_o_reserve_exact (__null, alloc_, __builtin_offsetof (VEC_unsigned_heap, base.vec), sizeof (unsigned) ); } static inline VEC_unsigned_heap *VEC_unsigned_heap_copy (VEC_unsigned_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_unsigned_heap *new_vec_ = __null; if (len_) { new_vec_ = (VEC_unsigned_heap *)(vec_heap_o_reserve_exact (__null, len_, __builtin_offsetof (VEC_unsigned_heap, base.vec), sizeof (unsigned) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (unsigned) * len_); } return new_vec_; } static inline void VEC_unsigned_heap_free (VEC_unsigned_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = __null; } static inline int VEC_unsigned_heap_reserve (VEC_unsigned_heap **vec_, int alloc_ ) { int extend = !VEC_unsigned_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_unsigned_heap *) vec_heap_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_unsigned_heap, base.vec), sizeof (unsigned) ); return extend; } static inline int VEC_unsigned_heap_reserve_exact (VEC_unsigned_heap **vec_, int alloc_ ) { int extend = !VEC_unsigned_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_unsigned_heap *) vec_heap_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_unsigned_heap, base.vec), sizeof (unsigned) ); return extend; } static inline void VEC_unsigned_heap_safe_grow (VEC_unsigned_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_unsigned_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_unsigned_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_unsigned_heap_safe_grow_cleared (VEC_unsigned_heap **vec_, int size_ ) { int oldsize = VEC_unsigned_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_unsigned_heap_safe_grow (vec_, size_ ); memset (&(VEC_unsigned_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (unsigned) * (size_ - oldsize)); } static inline void VEC_unsigned_heap_safe_splice (VEC_unsigned_heap **dst_, VEC_unsigned_base *src_ ) { if (src_) { VEC_unsigned_heap_reserve_exact (dst_, src_->prefix.num ); VEC_unsigned_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline unsigned *VEC_unsigned_heap_safe_push (VEC_unsigned_heap **vec_, const unsigned obj_ ) { VEC_unsigned_heap_reserve (vec_, 1 ); return VEC_unsigned_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline unsigned *VEC_unsigned_heap_safe_insert (VEC_unsigned_heap **vec_, unsigned ix_, const unsigned obj_ ) { VEC_unsigned_heap_reserve (vec_, 1 ); return VEC_unsigned_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
# 28 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/function.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/tm.h" 1
# 29 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/function.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/hard-reg-set.h" 1
# 42 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/hard-reg-set.h"
typedef unsigned long HARD_REG_ELT_TYPE;
# 60 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/hard-reg-set.h"
struct hard_reg_set_container
{
  HARD_REG_ELT_TYPE set;
};
# 122 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/hard-reg-set.h"
static inline bool
hard_reg_set_subset_p (const HARD_REG_ELT_TYPE x, const HARD_REG_ELT_TYPE y)
{
  return (x & ~y) == ((HARD_REG_ELT_TYPE) (0));
}

static inline bool
hard_reg_set_equal_p (const HARD_REG_ELT_TYPE x, const HARD_REG_ELT_TYPE y)
{
  return x == y;
}

static inline bool
hard_reg_set_intersect_p (const HARD_REG_ELT_TYPE x, const HARD_REG_ELT_TYPE y)
{
  return (x & y) != ((HARD_REG_ELT_TYPE) (0));
}

static inline bool
hard_reg_set_empty_p (const HARD_REG_ELT_TYPE x)
{
  return x == ((HARD_REG_ELT_TYPE) (0));
}
# 492 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/hard-reg-set.h"
typedef struct
{

  HARD_REG_ELT_TYPE *pelt;


  unsigned short length;


  unsigned short word_no;




  HARD_REG_ELT_TYPE bits;
} hard_reg_set_iterator;





static inline void
hard_reg_set_iter_init (hard_reg_set_iterator *iter, HARD_REG_ELT_TYPE set,
                        unsigned min, unsigned *regno)
{




  iter->pelt = &set;
  iter->length = 1;

  iter->word_no = min / ((unsigned) (8 * 8));
  if (iter->word_no < iter->length)
    {
      iter->bits = iter->pelt[iter->word_no];
      iter->bits >>= min % ((unsigned) (8 * 8));


      min += !iter->bits;
    }
  *regno = min;
}

static inline bool
hard_reg_set_iter_set (hard_reg_set_iterator *iter, unsigned *regno)
{
  while (1)
    {

      if (iter->word_no >= iter->length)
        return false;

      if (iter->bits)
        {

          while (!(iter->bits & 1))
            {
              iter->bits >>= 1;
              *regno += 1;
            }
          return (*regno < 53);
        }


      *regno = (*regno + ((unsigned) (8 * 8)) - 1);
      *regno -= *regno % ((unsigned) (8 * 8));


      while (++iter->word_no < iter->length)
        {
          iter->bits = iter->pelt[iter->word_no];
          if (iter->bits)
            break;
          *regno += ((unsigned) (8 * 8));
        }
    }
}

static inline void
hard_reg_set_iter_next (hard_reg_set_iterator *iter, unsigned *regno)
{
  iter->bits >>= 1;
  *regno += 1;
}
# 591 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/hard-reg-set.h"
extern char global_regs[53];

struct target_hard_regs {

  HARD_REG_ELT_TYPE x_accessible_reg_set;



  HARD_REG_ELT_TYPE x_operand_reg_set;





  char x_fixed_regs[53];


  HARD_REG_ELT_TYPE x_fixed_reg_set;





  char x_call_used_regs[53];

  char x_call_really_used_regs[53];


  HARD_REG_ELT_TYPE x_call_used_reg_set;





  HARD_REG_ELT_TYPE x_call_fixed_reg_set;







  HARD_REG_ELT_TYPE x_regs_invalidated_by_call;



  HARD_REG_ELT_TYPE x_no_caller_save_reg_set;


  int x_reg_alloc_order[53];


  int x_inv_reg_alloc_order[53];


  HARD_REG_ELT_TYPE x_reg_class_contents[((int) LIM_REG_CLASSES)];



  bool x_class_only_fixed_regs[((int) LIM_REG_CLASSES)];


  unsigned int x_reg_class_size[((int) LIM_REG_CLASSES)];


  enum reg_class x_reg_class_subclasses[((int) LIM_REG_CLASSES)][((int) LIM_REG_CLASSES)];



  enum reg_class x_reg_class_subunion[((int) LIM_REG_CLASSES)][((int) LIM_REG_CLASSES)];



  enum reg_class x_reg_class_superunion[((int) LIM_REG_CLASSES)][((int) LIM_REG_CLASSES)];


  const char *x_reg_names[53];
};

extern struct target_hard_regs default_target_hard_regs;
# 718 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/hard-reg-set.h"
extern const char * reg_class_names[];
# 30 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/function.h" 2






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
# 98 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/function.h"
extern rtx * regno_reg_rtx;







struct expr_status {


  int x_pending_stack_adjust;
# 126 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/function.h"
  int x_inhibit_defer_pop;





  int x_stack_pointer_delta;




  rtx x_saveregs_value;


  rtx x_apply_args_value;


  rtx x_forced_labels;
};

typedef struct call_site_record_d *call_site_record;
static inline void VEC_call_site_record_must_be_pointer_type (void) { (void)((call_site_record)1 == (void *)1); } typedef struct VEC_call_site_record_base { struct vec_prefix prefix; call_site_record vec[1]; } VEC_call_site_record_base; typedef struct VEC_call_site_record_none { VEC_call_site_record_base base; } VEC_call_site_record_none; static inline unsigned VEC_call_site_record_base_length (const VEC_call_site_record_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline call_site_record VEC_call_site_record_base_last (const VEC_call_site_record_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static inline call_site_record VEC_call_site_record_base_index (const VEC_call_site_record_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static inline int VEC_call_site_record_base_iterate (const VEC_call_site_record_base *vec_, unsigned ix_, call_site_record *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (call_site_record) 0; return 0; } } static inline size_t VEC_call_site_record_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_call_site_record_base, vec) + alloc_ * sizeof(call_site_record); } static inline void VEC_call_site_record_base_embedded_init (VEC_call_site_record_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_call_site_record_base_space (VEC_call_site_record_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_call_site_record_base_splice (VEC_call_site_record_base *dst_, VEC_call_site_record_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (call_site_record)); dst_->prefix.num += len_; } } static inline call_site_record *VEC_call_site_record_base_quick_push (VEC_call_site_record_base *vec_, call_site_record obj_ ) { call_site_record *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static inline call_site_record VEC_call_site_record_base_pop (VEC_call_site_record_base *vec_ ) { call_site_record obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_call_site_record_base_truncate (VEC_call_site_record_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline call_site_record VEC_call_site_record_base_replace (VEC_call_site_record_base *vec_, unsigned ix_, call_site_record obj_ ) { call_site_record old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static inline call_site_record *VEC_call_site_record_base_quick_insert (VEC_call_site_record_base *vec_, unsigned ix_, call_site_record obj_ ) { call_site_record *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (call_site_record)); *slot_ = obj_; return slot_; } static inline call_site_record VEC_call_site_record_base_ordered_remove (VEC_call_site_record_base *vec_, unsigned ix_ ) { call_site_record *slot_; call_site_record obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (call_site_record)); return obj_; } static inline call_site_record VEC_call_site_record_base_unordered_remove (VEC_call_site_record_base *vec_, unsigned ix_ ) { call_site_record *slot_; call_site_record obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_call_site_record_base_block_remove (VEC_call_site_record_base *vec_, unsigned ix_, unsigned len_ ) { call_site_record *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (call_site_record)); } static inline call_site_record *VEC_call_site_record_base_address (VEC_call_site_record_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_call_site_record_base_lower_bound (VEC_call_site_record_base *vec_, const call_site_record obj_, bool (*lessthan_)(const call_site_record, const call_site_record) ) { unsigned int len_ = VEC_call_site_record_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { call_site_record middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_call_site_record_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_call_site_record_gc { VEC_call_site_record_base base; } VEC_call_site_record_gc; static inline VEC_call_site_record_gc *VEC_call_site_record_gc_alloc (int alloc_ ) { return (VEC_call_site_record_gc *) vec_gc_p_reserve_exact (__null, alloc_ ); } static inline void VEC_call_site_record_gc_free (VEC_call_site_record_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = __null; } static inline VEC_call_site_record_gc *VEC_call_site_record_gc_copy (VEC_call_site_record_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_call_site_record_gc *new_vec_ = __null; if (len_) { new_vec_ = (VEC_call_site_record_gc *)(vec_gc_p_reserve_exact (__null, len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (call_site_record) * len_); } return new_vec_; } static inline int VEC_call_site_record_gc_reserve (VEC_call_site_record_gc **vec_, int alloc_ ) { int extend = !VEC_call_site_record_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_call_site_record_gc *) vec_gc_p_reserve (*vec_, alloc_ ); return extend; } static inline int VEC_call_site_record_gc_reserve_exact (VEC_call_site_record_gc **vec_, int alloc_ ) { int extend = !VEC_call_site_record_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_call_site_record_gc *) vec_gc_p_reserve_exact (*vec_, alloc_ ); return extend; } static inline void VEC_call_site_record_gc_safe_grow (VEC_call_site_record_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_call_site_record_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_call_site_record_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_call_site_record_gc_safe_grow_cleared (VEC_call_site_record_gc **vec_, int size_ ) { int oldsize = VEC_call_site_record_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_call_site_record_gc_safe_grow (vec_, size_ ); memset (&(VEC_call_site_record_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (call_site_record) * (size_ - oldsize)); } static inline void VEC_call_site_record_gc_safe_splice (VEC_call_site_record_gc **dst_, VEC_call_site_record_base *src_ ) { if (src_) { VEC_call_site_record_gc_reserve_exact (dst_, src_->prefix.num ); VEC_call_site_record_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline call_site_record *VEC_call_site_record_gc_safe_push (VEC_call_site_record_gc **vec_, call_site_record obj_ ) { VEC_call_site_record_gc_reserve (vec_, 1 ); return VEC_call_site_record_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline call_site_record *VEC_call_site_record_gc_safe_insert (VEC_call_site_record_gc **vec_, unsigned ix_, call_site_record obj_ ) { VEC_call_site_record_gc_reserve (vec_, 1 ); return VEC_call_site_record_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;


struct rtl_eh {
  rtx ehr_stackadj;
  rtx ehr_handler;
  rtx ehr_label;

  rtx sjlj_fc;
  rtx sjlj_exit_after;

  VEC_uchar_gc *action_record_data;

  VEC_call_site_record_gc *call_site_record[2];
};
# 171 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/function.h"
struct gimple_df;
struct temp_slot;
typedef struct temp_slot *temp_slot_p;
struct call_site_record_d;
struct dw_fde_struct;

static inline void VEC_temp_slot_p_must_be_pointer_type (void) { (void)((temp_slot_p)1 == (void *)1); } typedef struct VEC_temp_slot_p_base { struct vec_prefix prefix; temp_slot_p vec[1]; } VEC_temp_slot_p_base; typedef struct VEC_temp_slot_p_none { VEC_temp_slot_p_base base; } VEC_temp_slot_p_none; static inline unsigned VEC_temp_slot_p_base_length (const VEC_temp_slot_p_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline temp_slot_p VEC_temp_slot_p_base_last (const VEC_temp_slot_p_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static inline temp_slot_p VEC_temp_slot_p_base_index (const VEC_temp_slot_p_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static inline int VEC_temp_slot_p_base_iterate (const VEC_temp_slot_p_base *vec_, unsigned ix_, temp_slot_p *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (temp_slot_p) 0; return 0; } } static inline size_t VEC_temp_slot_p_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_temp_slot_p_base, vec) + alloc_ * sizeof(temp_slot_p); } static inline void VEC_temp_slot_p_base_embedded_init (VEC_temp_slot_p_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_temp_slot_p_base_space (VEC_temp_slot_p_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_temp_slot_p_base_splice (VEC_temp_slot_p_base *dst_, VEC_temp_slot_p_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (temp_slot_p)); dst_->prefix.num += len_; } } static inline temp_slot_p *VEC_temp_slot_p_base_quick_push (VEC_temp_slot_p_base *vec_, temp_slot_p obj_ ) { temp_slot_p *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static inline temp_slot_p VEC_temp_slot_p_base_pop (VEC_temp_slot_p_base *vec_ ) { temp_slot_p obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_temp_slot_p_base_truncate (VEC_temp_slot_p_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline temp_slot_p VEC_temp_slot_p_base_replace (VEC_temp_slot_p_base *vec_, unsigned ix_, temp_slot_p obj_ ) { temp_slot_p old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static inline temp_slot_p *VEC_temp_slot_p_base_quick_insert (VEC_temp_slot_p_base *vec_, unsigned ix_, temp_slot_p obj_ ) { temp_slot_p *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (temp_slot_p)); *slot_ = obj_; return slot_; } static inline temp_slot_p VEC_temp_slot_p_base_ordered_remove (VEC_temp_slot_p_base *vec_, unsigned ix_ ) { temp_slot_p *slot_; temp_slot_p obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (temp_slot_p)); return obj_; } static inline temp_slot_p VEC_temp_slot_p_base_unordered_remove (VEC_temp_slot_p_base *vec_, unsigned ix_ ) { temp_slot_p *slot_; temp_slot_p obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_temp_slot_p_base_block_remove (VEC_temp_slot_p_base *vec_, unsigned ix_, unsigned len_ ) { temp_slot_p *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (temp_slot_p)); } static inline temp_slot_p *VEC_temp_slot_p_base_address (VEC_temp_slot_p_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_temp_slot_p_base_lower_bound (VEC_temp_slot_p_base *vec_, const temp_slot_p obj_, bool (*lessthan_)(const temp_slot_p, const temp_slot_p) ) { unsigned int len_ = VEC_temp_slot_p_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { temp_slot_p middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_temp_slot_p_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_temp_slot_p_gc { VEC_temp_slot_p_base base; } VEC_temp_slot_p_gc; static inline VEC_temp_slot_p_gc *VEC_temp_slot_p_gc_alloc (int alloc_ ) { return (VEC_temp_slot_p_gc *) vec_gc_p_reserve_exact (__null, alloc_ ); } static inline void VEC_temp_slot_p_gc_free (VEC_temp_slot_p_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = __null; } static inline VEC_temp_slot_p_gc *VEC_temp_slot_p_gc_copy (VEC_temp_slot_p_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_temp_slot_p_gc *new_vec_ = __null; if (len_) { new_vec_ = (VEC_temp_slot_p_gc *)(vec_gc_p_reserve_exact (__null, len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (temp_slot_p) * len_); } return new_vec_; } static inline int VEC_temp_slot_p_gc_reserve (VEC_temp_slot_p_gc **vec_, int alloc_ ) { int extend = !VEC_temp_slot_p_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_temp_slot_p_gc *) vec_gc_p_reserve (*vec_, alloc_ ); return extend; } static inline int VEC_temp_slot_p_gc_reserve_exact (VEC_temp_slot_p_gc **vec_, int alloc_ ) { int extend = !VEC_temp_slot_p_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_temp_slot_p_gc *) vec_gc_p_reserve_exact (*vec_, alloc_ ); return extend; } static inline void VEC_temp_slot_p_gc_safe_grow (VEC_temp_slot_p_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_temp_slot_p_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_temp_slot_p_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_temp_slot_p_gc_safe_grow_cleared (VEC_temp_slot_p_gc **vec_, int size_ ) { int oldsize = VEC_temp_slot_p_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_temp_slot_p_gc_safe_grow (vec_, size_ ); memset (&(VEC_temp_slot_p_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (temp_slot_p) * (size_ - oldsize)); } static inline void VEC_temp_slot_p_gc_safe_splice (VEC_temp_slot_p_gc **dst_, VEC_temp_slot_p_base *src_ ) { if (src_) { VEC_temp_slot_p_gc_reserve_exact (dst_, src_->prefix.num ); VEC_temp_slot_p_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline temp_slot_p *VEC_temp_slot_p_gc_safe_push (VEC_temp_slot_p_gc **vec_, temp_slot_p obj_ ) { VEC_temp_slot_p_gc_reserve (vec_, 1 ); return VEC_temp_slot_p_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline temp_slot_p *VEC_temp_slot_p_gc_safe_insert (VEC_temp_slot_p_gc **vec_, unsigned ix_, temp_slot_p obj_ ) { VEC_temp_slot_p_gc_reserve (vec_, 1 ); return VEC_temp_slot_p_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
struct ipa_opt_pass_d;
typedef struct ipa_opt_pass_d *ipa_opt_pass;

static inline void VEC_ipa_opt_pass_must_be_pointer_type (void) { (void)((ipa_opt_pass)1 == (void *)1); } typedef struct VEC_ipa_opt_pass_base { struct vec_prefix prefix; ipa_opt_pass vec[1]; } VEC_ipa_opt_pass_base; typedef struct VEC_ipa_opt_pass_none { VEC_ipa_opt_pass_base base; } VEC_ipa_opt_pass_none; static inline unsigned VEC_ipa_opt_pass_base_length (const VEC_ipa_opt_pass_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline ipa_opt_pass VEC_ipa_opt_pass_base_last (const VEC_ipa_opt_pass_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return vec_->vec[vec_->prefix.num - 1]; } static inline ipa_opt_pass VEC_ipa_opt_pass_base_index (const VEC_ipa_opt_pass_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return vec_->vec[ix_]; } static inline int VEC_ipa_opt_pass_base_iterate (const VEC_ipa_opt_pass_base *vec_, unsigned ix_, ipa_opt_pass *ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = vec_->vec[ix_]; return 1; } else { *ptr = (ipa_opt_pass) 0; return 0; } } static inline size_t VEC_ipa_opt_pass_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_ipa_opt_pass_base, vec) + alloc_ * sizeof(ipa_opt_pass); } static inline void VEC_ipa_opt_pass_base_embedded_init (VEC_ipa_opt_pass_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_ipa_opt_pass_base_space (VEC_ipa_opt_pass_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_ipa_opt_pass_base_splice (VEC_ipa_opt_pass_base *dst_, VEC_ipa_opt_pass_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (ipa_opt_pass)); dst_->prefix.num += len_; } } static inline ipa_opt_pass *VEC_ipa_opt_pass_base_quick_push (VEC_ipa_opt_pass_base *vec_, ipa_opt_pass obj_ ) { ipa_opt_pass *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; *slot_ = obj_; return slot_; } static inline ipa_opt_pass VEC_ipa_opt_pass_base_pop (VEC_ipa_opt_pass_base *vec_ ) { ipa_opt_pass obj_; (void)(vec_->prefix.num); obj_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_ipa_opt_pass_base_truncate (VEC_ipa_opt_pass_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline ipa_opt_pass VEC_ipa_opt_pass_base_replace (VEC_ipa_opt_pass_base *vec_, unsigned ix_, ipa_opt_pass obj_ ) { ipa_opt_pass old_obj_; (void)(ix_ < vec_->prefix.num); old_obj_ = vec_->vec[ix_]; vec_->vec[ix_] = obj_; return old_obj_; } static inline ipa_opt_pass *VEC_ipa_opt_pass_base_quick_insert (VEC_ipa_opt_pass_base *vec_, unsigned ix_, ipa_opt_pass obj_ ) { ipa_opt_pass *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (ipa_opt_pass)); *slot_ = obj_; return slot_; } static inline ipa_opt_pass VEC_ipa_opt_pass_base_ordered_remove (VEC_ipa_opt_pass_base *vec_, unsigned ix_ ) { ipa_opt_pass *slot_; ipa_opt_pass obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (ipa_opt_pass)); return obj_; } static inline ipa_opt_pass VEC_ipa_opt_pass_base_unordered_remove (VEC_ipa_opt_pass_base *vec_, unsigned ix_ ) { ipa_opt_pass *slot_; ipa_opt_pass obj_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; obj_ = *slot_; *slot_ = vec_->vec[--vec_->prefix.num]; return obj_; } static inline void VEC_ipa_opt_pass_base_block_remove (VEC_ipa_opt_pass_base *vec_, unsigned ix_, unsigned len_ ) { ipa_opt_pass *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (ipa_opt_pass)); } static inline ipa_opt_pass *VEC_ipa_opt_pass_base_address (VEC_ipa_opt_pass_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_ipa_opt_pass_base_lower_bound (VEC_ipa_opt_pass_base *vec_, const ipa_opt_pass obj_, bool (*lessthan_)(const ipa_opt_pass, const ipa_opt_pass) ) { unsigned int len_ = VEC_ipa_opt_pass_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { ipa_opt_pass middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_ipa_opt_pass_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_ipa_opt_pass_heap { VEC_ipa_opt_pass_base base; } VEC_ipa_opt_pass_heap; static inline VEC_ipa_opt_pass_heap *VEC_ipa_opt_pass_heap_alloc (int alloc_ ) { return (VEC_ipa_opt_pass_heap *) vec_heap_p_reserve_exact (__null, alloc_ ); } static inline void VEC_ipa_opt_pass_heap_free (VEC_ipa_opt_pass_heap **vec_) { if (*vec_) (free) (*vec_); *vec_ = __null; } static inline VEC_ipa_opt_pass_heap *VEC_ipa_opt_pass_heap_copy (VEC_ipa_opt_pass_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_ipa_opt_pass_heap *new_vec_ = __null; if (len_) { new_vec_ = (VEC_ipa_opt_pass_heap *)(vec_heap_p_reserve_exact (__null, len_ )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (ipa_opt_pass) * len_); } return new_vec_; } static inline int VEC_ipa_opt_pass_heap_reserve (VEC_ipa_opt_pass_heap **vec_, int alloc_ ) { int extend = !VEC_ipa_opt_pass_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_ipa_opt_pass_heap *) vec_heap_p_reserve (*vec_, alloc_ ); return extend; } static inline int VEC_ipa_opt_pass_heap_reserve_exact (VEC_ipa_opt_pass_heap **vec_, int alloc_ ) { int extend = !VEC_ipa_opt_pass_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_ipa_opt_pass_heap *) vec_heap_p_reserve_exact (*vec_, alloc_ ); return extend; } static inline void VEC_ipa_opt_pass_heap_safe_grow (VEC_ipa_opt_pass_heap **vec_, int size_ ) { (void)(size_ >= 0 && VEC_ipa_opt_pass_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_ipa_opt_pass_heap_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_ipa_opt_pass_heap_safe_grow_cleared (VEC_ipa_opt_pass_heap **vec_, int size_ ) { int oldsize = VEC_ipa_opt_pass_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_ipa_opt_pass_heap_safe_grow (vec_, size_ ); memset (&(VEC_ipa_opt_pass_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (ipa_opt_pass) * (size_ - oldsize)); } static inline void VEC_ipa_opt_pass_heap_safe_splice (VEC_ipa_opt_pass_heap **dst_, VEC_ipa_opt_pass_base *src_ ) { if (src_) { VEC_ipa_opt_pass_heap_reserve_exact (dst_, src_->prefix.num ); VEC_ipa_opt_pass_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline ipa_opt_pass *VEC_ipa_opt_pass_heap_safe_push (VEC_ipa_opt_pass_heap **vec_, ipa_opt_pass obj_ ) { VEC_ipa_opt_pass_heap_reserve (vec_, 1 ); return VEC_ipa_opt_pass_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline ipa_opt_pass *VEC_ipa_opt_pass_heap_safe_insert (VEC_ipa_opt_pass_heap **vec_, unsigned ix_, ipa_opt_pass obj_ ) { VEC_ipa_opt_pass_heap_reserve (vec_, 1 ); return VEC_ipa_opt_pass_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;

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

  long start;
  long length;
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




  long x_frame_offset;


  rtx x_parm_birth_insn;


  VEC_temp_slot_p_gc *x_used_temp_slots;


  struct temp_slot *x_avail_temp_slots;


  int x_temp_slot_level;



  unsigned int stack_alignment_needed;



  unsigned int preferred_stack_boundary;


  unsigned int parm_stack_boundary;


  unsigned int max_used_stack_slot_alignment;
# 346 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/function.h"
  unsigned int stack_alignment_estimated;





  rtx epilogue_delay_list;



  bool accesses_prior_frames;


  bool calls_eh_return;



  bool saves_all_registers;



  bool has_nonlocal_goto;


  bool has_asm_statement;






  bool all_throwers_are_sibcalls;



  bool limit_stack;


  bool profile;


  bool uses_const_pool;


  bool uses_pic_offset_table;


  bool uses_eh_lsda;


  bool tail_call_emit;


  bool arg_pointer_save_area_init;



  bool frame_pointer_needed;


  bool maybe_hot_insn_p;






  bool stack_realign_needed;




  bool stack_realign_tried;



  bool need_drap;




  bool stack_realign_processed;



  bool stack_realign_finalized;


  bool dbr_scheduled_p;




  bool nothrow;


  bool shrink_wrapped;





  HARD_REG_ELT_TYPE asm_clobbers;
};
# 466 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/function.h"
extern struct rtl_data x_rtl;






struct stack_usage
{

  long static_stack_size;



  long dynamic_stack_size;



  int pushed_stack_size;



  unsigned int has_unbounded_dynamic_stack_size : 1;
};
# 503 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/function.h"
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



static inline void
add_local_decl (struct function *fun, tree d)
{
  (VEC_tree_gc_safe_push(&(fun->local_decls),d ));
}
# 657 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/function.h"
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
# 708 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/function.h"
extern void reorder_blocks (void);


extern void number_blocks (tree);

extern void clear_block_marks (tree);
extern tree blocks_nreverse (tree);
extern tree block_chainon (tree, tree);




extern long get_frame_size (void);




extern bool frame_offset_overflow (long, tree);



extern struct machine_function * (*init_machine_status) (void);


extern void free_after_parsing (struct function *);
extern void free_after_compilation (struct function *);

extern void init_varasm_status (void);






extern rtx get_arg_pointer_save_area (void);


extern const char *current_function_name (void);

extern void do_warn_unused_parameter (tree);

extern bool pass_by_reference (CUMULATIVE_ARGS *, enum machine_mode,
          tree, bool);
extern bool reference_callee_copied (CUMULATIVE_ARGS *, enum machine_mode,
         tree, bool);

extern void used_types_insert (tree);

extern int get_next_funcdef_no (void);
extern int get_last_funcdef_no (void);


extern bool requires_stack_frame_p (rtx, HARD_REG_ELT_TYPE, HARD_REG_ELT_TYPE);



extern bool optimize_function_for_size_p (struct function *);
extern bool optimize_function_for_speed_p (struct function *);
# 28 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/hashtab.h" 1
# 29 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/vec.h" 1
# 30 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h" 2
# 43 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h" 1
# 25 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/splay-tree.h" 1
# 35 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/splay-tree.h"
extern "C" {





  typedef unsigned long int libi_uhostptr_t;
  typedef long int libi_shostptr_t;
# 62 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/splay-tree.h"
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


}
# 26 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cpplib.h" 1
# 31 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cpplib.h"
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
# 153 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cpplib.h"
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
# 195 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cpplib.h"
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
  enum cpp_ttype type : 8;
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
# 269 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cpplib.h"
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


  bool warn_invalid_pch;


  bool restore_pch_deps;


  struct
  {

    enum cpp_deps_style style;


    bool missing_files;



    bool phony_targets;


    bool ignore_main_file;



    bool need_preprocessor_output;
  } deps;





  size_t precision, char_precision, int_precision, wchar_precision;


  bool unsigned_char, unsigned_wchar;



  bool bytes_big_endian;


  unsigned char stdc_0_in_system_headers;


  bool directives_only;
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



  bool (*error) (cpp_reader *, int, int, source_location, unsigned int,
   const char *, va_list *)
       __attribute__ ((__format__ (__printf__, 6, 0))) __attribute__ ((__nonnull__ (6)));



  void (*used_define) (cpp_reader *, source_location, cpp_hashnode *);
  void (*used_undef) (cpp_reader *, source_location, cpp_hashnode *);


  void (*before_define) (cpp_reader *);


  void (*used) (cpp_reader *, source_location, cpp_hashnode *);


  bool (*user_builtin_macro) (cpp_reader *, cpp_hashnode *);
};
# 553 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cpplib.h"
struct cpp_dir
{

  struct cpp_dir *next;


  char *name;
  unsigned int len;



  unsigned char sysp;


  bool user_supplied_p;



  char *canonical_name;



  const char **name_map;





  char *(*construct) (const char *header, cpp_dir *dir);



  ino_t ino;
  dev_t dev;
};
# 614 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cpplib.h"
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
# 646 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cpplib.h"
enum {
  NTV_MACRO,
  NTV_ANSWER,
  NTV_BUILTIN,
  NTV_ARGUMENT,
  NTV_NONE
};
# 665 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cpplib.h"
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
  enum node_type type : 6;
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
           unsigned char *, bool);
extern void cpp_register_pragma (cpp_reader *, const char *, const char *,
     void (*) (cpp_reader *), bool);
extern void cpp_register_deferred_pragma (cpp_reader *, const char *,
       const char *, unsigned, bool, bool);
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

extern bool cpp_interpret_string (cpp_reader *,
      const cpp_string *, size_t,
      cpp_string *, enum cpp_ttype);
extern bool cpp_interpret_string_notranslate (cpp_reader *,
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



typedef unsigned long cpp_num_part;
typedef struct cpp_num cpp_num;
struct cpp_num
{
  cpp_num_part high;
  cpp_num_part low;
  bool unsignedp;
  bool overflow;
};
# 849 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cpplib.h"
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


extern bool cpp_error (cpp_reader *, int, const char *msgid, ...)
  __attribute__ ((__format__ (__printf__, 3, 4))) __attribute__ ((__nonnull__ (3)));
extern bool cpp_warning (cpp_reader *, int, const char *msgid, ...)
  __attribute__ ((__format__ (__printf__, 3, 4))) __attribute__ ((__nonnull__ (3)));
extern bool cpp_pedwarning (cpp_reader *, int, const char *msgid, ...)
  __attribute__ ((__format__ (__printf__, 3, 4))) __attribute__ ((__nonnull__ (3)));
extern bool cpp_warning_syshdr (cpp_reader *, int, const char *msgid, ...)
  __attribute__ ((__format__ (__printf__, 3, 4))) __attribute__ ((__nonnull__ (3)));



extern bool cpp_errno (cpp_reader *, int, const char *msgid);




extern bool cpp_error_with_line (cpp_reader *, int, source_location,
                                 unsigned, const char *msgid, ...)
  __attribute__ ((__format__ (__printf__, 5, 6))) __attribute__ ((__nonnull__ (5)));
extern bool cpp_warning_with_line (cpp_reader *, int, source_location,
                                   unsigned, const char *msgid, ...)
  __attribute__ ((__format__ (__printf__, 5, 6))) __attribute__ ((__nonnull__ (5)));
extern bool cpp_pedwarning_with_line (cpp_reader *, int, source_location,
                                      unsigned, const char *msgid, ...)
  __attribute__ ((__format__ (__printf__, 5, 6))) __attribute__ ((__nonnull__ (5)));
extern bool cpp_warning_with_line_syshdr (cpp_reader *, int, source_location,
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


extern bool cpp_included (cpp_reader *, const char *);
extern bool cpp_included_before (cpp_reader *, const char *, source_location);
extern void cpp_make_system_header (cpp_reader *, int, int);
extern bool cpp_push_include (cpp_reader *, const char *);
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
extern bool cpp_userdef_string_p
  (enum cpp_ttype type);
extern bool cpp_userdef_char_p
  (enum cpp_ttype type);
extern const char * cpp_get_userdef_suffix
  (const cpp_token *);
# 27 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h" 2
# 43 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/diagnostic-core.h" 1
# 28 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/diagnostic-core.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/bversion.h" 1
# 29 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/diagnostic-core.h" 2


typedef enum
{

# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/diagnostic.def" 1
# 25 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/diagnostic.def"
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
# 35 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/diagnostic-core.h" 2

  DK_LAST_DIAGNOSTIC_KIND,


  DK_POP
} diagnostic_t;

extern const char *progname;

extern const char *trim_filename (const char *);
# 59 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/diagnostic-core.h"
extern void internal_error (const char *, ...) __attribute__ ((__format__ (__gcc_cxxdiag__, 1, 2))) __attribute__ ((__nonnull__ (1)))
     __attribute__ ((__noreturn__));

extern bool warning (int, const char *, ...) __attribute__ ((__format__ (__gcc_cxxdiag__, 2, 3))) __attribute__ ((__nonnull__ (2)));
extern bool warning_at (location_t, int, const char *, ...)
    __attribute__ ((__format__ (__gcc_cxxdiag__, 3, 4))) __attribute__ ((__nonnull__ (3)));
extern void error (const char *, ...) __attribute__ ((__format__ (__gcc_cxxdiag__, 1, 2))) __attribute__ ((__nonnull__ (1)));
extern void error_n (location_t, int, const char *, const char *, ...)
    __attribute__ ((__format__ (__gcc_cxxdiag__, 3, 5))) __attribute__ ((__nonnull__ (3))) __attribute__ ((__format__ (__gcc_cxxdiag__, 4, 5))) __attribute__ ((__nonnull__ (4)));
extern void error_at (location_t, const char *, ...) __attribute__ ((__format__ (__gcc_cxxdiag__, 2, 3))) __attribute__ ((__nonnull__ (2)));
extern void fatal_error (const char *, ...) __attribute__ ((__format__ (__gcc_cxxdiag__, 1, 2))) __attribute__ ((__nonnull__ (1)))
     __attribute__ ((__noreturn__));

extern bool pedwarn (location_t, int, const char *, ...)
     __attribute__ ((__format__ (__gcc_cxxdiag__, 3, 4))) __attribute__ ((__nonnull__ (3)));
extern bool permerror (location_t, const char *, ...) __attribute__ ((__format__ (__gcc_cxxdiag__, 2, 3))) __attribute__ ((__nonnull__ (2)));
extern void sorry (const char *, ...) __attribute__ ((__format__ (__gcc_cxxdiag__, 1, 2))) __attribute__ ((__nonnull__ (1)));
extern void inform (location_t, const char *, ...) __attribute__ ((__format__ (__gcc_cxxdiag__, 2, 3))) __attribute__ ((__nonnull__ (2)));
extern void inform_n (location_t, int, const char *, const char *, ...)
    __attribute__ ((__format__ (__gcc_cxxdiag__, 3, 5))) __attribute__ ((__nonnull__ (3))) __attribute__ ((__format__ (__gcc_cxxdiag__, 4, 5))) __attribute__ ((__nonnull__ (4)));
extern void verbatim (const char *, ...) __attribute__ ((__format__ (__gcc_cxxdiag__, 1, 2))) __attribute__ ((__nonnull__ (1)));
extern bool emit_diagnostic (diagnostic_t, location_t, int,
        const char *, ...) __attribute__ ((__format__ (__gcc_cxxdiag__, 4, 5))) __attribute__ ((__nonnull__ (4)));
extern bool seen_error (void);




extern void fnotice (FILE *, const char *, ...)
     __attribute__ ((__format__ (__printf__, 2, 3))) __attribute__ ((__nonnull__ (2)));
# 44 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h" 2
# 63 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h"
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
# 231 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h"
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
# 316 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h"
struct c_common_identifier {
  struct tree_common common;
  struct cpp_hashnode node;
};



struct c_common_resword
{
  const char *const word;
  enum rid const rid : 16;
  const unsigned int disable : 16;
};
# 370 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h"
extern const struct c_common_resword c_common_reswords[];


extern const unsigned int num_c_common_reswords;
# 440 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h"
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
# 498 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h"
  int stmts_are_full_exprs_p;
};

typedef struct stmt_tree_s *stmt_tree;




struct c_language_function {


  struct stmt_tree_s x_stmt_tree;



  VEC_tree_gc *local_typedefs;
};
# 532 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h"
extern void (*lang_post_pch_load) (void);

extern void push_file_scope (void);
extern void pop_file_scope (void);
extern stmt_tree current_stmt_tree (void);
extern tree push_stmt_list (void);
extern tree pop_stmt_list (tree);
extern tree add_stmt (tree);
extern void push_cleanup (tree, tree, bool);
extern tree pushdecl_top_level (tree);
extern tree pushdecl (tree);
extern tree build_modify_expr (location_t, tree, tree, enum tree_code,
          location_t, tree, tree);
extern tree build_indirect_ref (location_t, tree, ref_operator);

extern int c_expand_decl (tree);

extern int field_decl_cmp (const void *, const void *);
extern void resort_sorted_fields (void *, void *, gt_pointer_operator,
      void *);
extern bool has_c_linkage (const_tree decl);





extern char flag_no_line_commands;




extern char flag_no_output;




extern char flag_dump_macros;



extern char flag_dump_includes;



extern bool flag_pch_preprocess;




extern const char *pch_file;




extern int flag_iso;



extern int warn_unknown_pragmas;




extern int warn_format;
# 604 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h"
extern int flag_cond_mismatch;



extern int flag_isoc94;



extern int flag_isoc99;



extern int flag_isoc11;



extern int flag_hosted;
# 629 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h"
extern int print_struct_values;



extern const char *constant_string_class_name;
# 642 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h"
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




extern bool done_lexing;
# 693 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h"
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


extern bool in_late_binary_op;
extern const char *c_addr_space_name (addr_space_t as);
extern tree identifier_global_value (tree);
extern tree c_linkage_bindings (tree);
extern void record_builtin_type (enum rid, const char *, tree);
extern tree build_void_list_node (void);
extern void start_fname_decls (void);
extern void finish_fname_decls (void);
extern const char *fname_as_string (int);
extern tree fname_decl (location_t, unsigned, tree);

extern int check_user_alignment (const_tree, bool);
extern void check_function_arguments (const_tree, int, tree *);
extern void check_function_arguments_recurse (void (*)
           (void *, tree,
            unsigned long),
           void *, tree,
           unsigned long);
extern bool check_builtin_function_arguments (tree, int, tree *);
extern void check_function_format (tree, int, tree *);
extern void set_Wformat (int);
extern tree handle_format_attribute (tree *, tree, tree, int, bool *);
extern tree handle_format_arg_attribute (tree *, tree, tree, int, bool *);
extern bool attribute_takes_identifier_p (const_tree);
extern bool c_common_handle_option (size_t, const char *, int, int, location_t,
        const struct cl_option_handlers *);
extern bool default_handle_c_option (size_t, const char *, int);
extern tree c_common_type_for_mode (enum machine_mode, int);
extern tree c_common_type_for_size (unsigned int, int);
extern tree c_common_fixed_point_type_for_size (unsigned int, unsigned int,
      int, int);
extern tree c_common_unsigned_type (tree);
extern tree c_common_signed_type (tree);
extern tree c_common_signed_or_unsigned_type (int, tree);
extern void c_common_init_ts (void);
extern tree c_build_bitfield_integer_type (unsigned long, int);
extern bool unsafe_conversion_p (tree, tree, bool);
extern bool decl_with_nonnull_addr_p (const_tree);
extern tree c_fully_fold (tree, bool, bool *);
extern tree decl_constant_value_for_optimization (tree);
extern tree c_wrap_maybe_const (tree, bool);
extern tree c_save_expr (tree);
extern tree c_common_truthvalue_conversion (location_t, tree);
extern void c_apply_type_quals_to_decl (int, tree);
extern tree c_sizeof_or_alignof_type (location_t, tree, bool, int);
extern tree c_alignof_expr (location_t, tree);


extern void binary_op_error (location_t, enum tree_code, tree, tree);
extern tree fix_string_type (tree);
extern void constant_expression_warning (tree);
extern void constant_expression_error (tree);
extern bool strict_aliasing_warning (tree, tree, tree);
extern void warnings_for_convert_and_check (tree, tree, tree);
extern tree convert_and_check (tree, tree);
extern void overflow_warning (location_t, tree);
extern void warn_logical_operator (location_t, enum tree_code, tree,
       enum tree_code, tree, enum tree_code, tree);
extern void check_main_parameter_types (tree decl);
extern bool c_determine_visibility (tree);
extern bool same_scalar_type_ignoring_signedness (tree, tree);
extern void mark_valid_location_for_stdc_pragma (bool);
extern bool valid_location_for_stdc_pragma_p (void);
extern void set_float_const_decimal64 (void);
extern void clear_float_const_decimal64 (void);
extern bool float_const_decimal64_p (void);

extern bool keyword_begins_type_specifier (enum rid);
extern bool keyword_is_storage_class_specifier (enum rid);
extern bool keyword_is_type_qualifier (enum rid);
extern bool keyword_is_decl_specifier (enum rid);





extern tree shorten_binary_op (tree result_type, tree op0, tree op1, bool bitwise);




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
extern bool c_common_complain_wrong_lang_p (const struct cl_option *);
extern void c_common_init_options_struct (struct gcc_options *);
extern void c_common_init_options (unsigned int, struct cl_decoded_option *);
extern bool c_common_post_options (const char **);
extern bool c_common_init (void);
extern void c_common_finish (void);
extern void c_common_parse_file (void);
extern alias_set_type c_common_get_alias_set (tree);
extern void c_register_builtin_type (tree, const char*);
extern bool c_promoting_integer_type_p (const_tree);
extern int self_promoting_args_p (const_tree);
extern tree strip_pointer_operator (tree);
extern tree strip_pointer_or_array_types (tree);
extern long c_common_to_target_charset (long);


extern void c_parse_file (void);

extern void warn_for_omitted_condop (location_t, tree);
# 872 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h"
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
extern bool lvalue_p (const_tree);

extern bool vector_targets_convertible_p (const_tree t1, const_tree t2);
extern bool vector_types_convertible_p (const_tree t1, const_tree t2, bool emit_lax_note);

extern rtx c_expand_expr (tree, rtx, enum machine_mode, int, rtx *);

extern void init_c_lex (void);

extern void c_cpp_builtins (cpp_reader *);
extern void c_cpp_builtins_optimize_pragma (cpp_reader *, tree, tree);
extern bool c_cpp_error (cpp_reader *, int, int, location_t, unsigned int,
    const char *, va_list *)
     __attribute__ ((__format__ (__gcc_cxxdiag__, 6, 0))) __attribute__ ((__nonnull__ (6)));

extern bool parse_optimize_options (tree, bool);



extern int pending_lang_change;



struct c_fileinfo
{
  int time;







  short interface_only;
  short interface_unknown;
};

struct c_fileinfo *get_fileinfo (const char *);
extern void dump_time_statistics (void);

extern bool c_dump_tree (void *, tree);

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

extern int complete_array_type (tree *, tree, bool);

extern tree builtin_type_for_size (int, bool);

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
extern bool check_missing_format_attribute (tree, tree);


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


extern bool c_omp_sharing_predetermined (tree);
extern tree c_omp_remap_decl (tree, bool);
extern void record_types_used_by_current_var_decl (tree);


static inline tree
c_tree_chain_next (tree t)
{



  if ((tree_contains_struct[(((enum tree_code) (t)->base.code))][(TS_TYPE_COMMON)]))
    return ((t)->type_common.next_variant);

  if ((tree_contains_struct[(((enum tree_code) (t)->base.code))][(TS_COMMON)]))
    return ((t)->common.chain);
  return __null;
}






extern int parse_tm_stmt_attr (tree, int);
# 1092 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h"
extern int tm_attr_to_mask (tree);
extern tree tm_mask_to_attr (int);
extern tree find_tm_attribute (tree);



struct tree_userdef_literal {
  struct tree_base base;
  tree suffix_id;
  tree value;
  tree num_string;
};
# 1117 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-common.h"
extern tree build_userdef_literal (tree suffix_id, tree value, tree num_string);
# 44 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/diagnostic.h" 1
# 25 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/diagnostic.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/pretty-print.h" 1
# 33 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/pretty-print.h"
typedef struct
{
  const char *format_spec;
  va_list *args_ptr;
  int err_no;
  location_t *locus;
  void **x_data;
} text_info;






typedef enum
{
  DIAGNOSTICS_SHOW_PREFIX_ONCE = 0x0,
  DIAGNOSTICS_SHOW_PREFIX_NEVER = 0x1,
  DIAGNOSTICS_SHOW_PREFIX_EVERY_LINE = 0x2
} diagnostic_prefixing_rule_t;






struct chunk_info
{

  struct chunk_info *prev;







  const char *args[30 * 2];
};



typedef struct
{

  struct obstack formatted_obstack;



  struct obstack chunk_obstack;



  struct obstack *obstack;


  struct chunk_info *cur_chunk_array;


  FILE *stream;


  int line_length;



  char digit_buffer[128];
} output_buffer;


typedef unsigned int pp_flags;

typedef enum
{
  pp_none, pp_before, pp_after
} pp_padding;



typedef struct
{

  diagnostic_prefixing_rule_t rule;



  int line_cutoff;
} pp_wrapping_mode_t;
# 135 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/pretty-print.h"
typedef struct pretty_print_info pretty_printer;
typedef bool (*printer_fn) (pretty_printer *, text_info *, const char *,
       int, bool, bool, bool);
# 159 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/pretty-print.h"
struct pretty_print_info
{

  output_buffer *buffer;


  const char *prefix;


  pp_padding padding;



  int maximum_length;


  int indent_skip;


  pp_wrapping_mode_t wrapping;
# 188 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/pretty-print.h"
  printer_fn format_decoder;


  bool emitted_prefix;


  bool need_newline;



  bool translate_identifiers;
};
# 297 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/pretty-print.h"
extern void pp_construct (pretty_printer *, const char *, int);
extern void pp_base_set_line_maximum_length (pretty_printer *, int);
extern void pp_base_set_prefix (pretty_printer *, const char *);
extern void pp_base_destroy_prefix (pretty_printer *);
extern int pp_base_remaining_character_count_for_line (pretty_printer *);
extern void pp_base_clear_output_area (pretty_printer *);
extern const char *pp_base_formatted_text (pretty_printer *);
extern const char *pp_base_last_position_in_text (const pretty_printer *);
extern void pp_base_emit_prefix (pretty_printer *);
extern void pp_base_append_text (pretty_printer *, const char *, const char *);
# 323 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/pretty-print.h"
extern void pp_printf (pretty_printer *, const char *, ...)
     __attribute__ ((__format__ (__gcc_cxxdiag__, 2 ,3))) __attribute__ ((__nonnull__ (2)));

extern void pp_verbatim (pretty_printer *, const char *, ...)
     __attribute__ ((__format__ (__gcc_cxxdiag__, 2 ,3))) __attribute__ ((__nonnull__ (2)));
extern void pp_base_flush (pretty_printer *);
extern void pp_base_format (pretty_printer *, text_info *);
extern void pp_base_output_formatted_text (pretty_printer *);
extern void pp_base_format_verbatim (pretty_printer *, text_info *);

extern void pp_base_indent (pretty_printer *);
extern void pp_base_newline (pretty_printer *);
extern void pp_base_character (pretty_printer *, int);
extern void pp_base_string (pretty_printer *, const char *);
extern void pp_write_text_to_stream (pretty_printer *pp);
extern void pp_base_maybe_space (pretty_printer *);


static inline pp_wrapping_mode_t
pp_set_verbatim_wrapping_ (pretty_printer *pp)
{
  pp_wrapping_mode_t oldmode = (pp)->wrapping;
  (pp)->wrapping.line_cutoff = 0;
  (pp)->wrapping.rule = DIAGNOSTICS_SHOW_PREFIX_NEVER;
  return oldmode;
}


extern const char *identifier_to_locale (const char *);
extern void *(*identifier_to_locale_alloc) (size_t);
extern void (*identifier_to_locale_free) (void *);
# 26 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/diagnostic.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/diagnostic-core.h" 1
# 27 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/diagnostic.h" 2




typedef struct diagnostic_info
{
  text_info message;
  location_t location;
  unsigned int override_column;

  void *x_data;

  diagnostic_t kind;

  int option_index;
} diagnostic_info;




typedef struct diagnostic_classification_change_t
{
  location_t location;
  int option;
  diagnostic_t kind;
} diagnostic_classification_change_t;


typedef void (*diagnostic_starter_fn) (diagnostic_context *,
           diagnostic_info *);
typedef diagnostic_starter_fn diagnostic_finalizer_fn;



struct diagnostic_context
{

  pretty_printer *printer;


  int diagnostic_count[DK_LAST_DIAGNOSTIC_KIND];



  bool some_warnings_are_errors;


  bool warning_as_error_requested;



  int n_opts;







  diagnostic_t *classify_diagnostic;






  diagnostic_classification_change_t *classification_history;


  int n_classification_history;


  int *push_list;
  int n_push;



  bool show_option_requested;


  bool abort_on_error;


  bool show_column;


  bool pedantic_errors;


  bool permissive;



  int opt_permissive;


  bool fatal_errors;


  bool dc_inhibit_warnings;


  bool dc_warn_system_headers;


  unsigned int max_errors;
# 141 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/diagnostic.h"
  diagnostic_starter_fn begin_diagnostic;


  diagnostic_finalizer_fn end_diagnostic;


  void (*internal_error) (diagnostic_context *, const char *, va_list *);



  int (*option_enabled) (int, void *);



  void *option_state;







  char *(*option_name) (diagnostic_context *, int, diagnostic_t, diagnostic_t);


  void *x_data;



  const struct line_map *last_module;

  int lock;

  bool inhibit_notes_p;
};

static inline void
diagnostic_inhibit_notes (diagnostic_context * context)
{
  context->inhibit_notes_p = true;
}
# 224 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/diagnostic.h"
extern diagnostic_context *global_dc;
# 254 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/diagnostic.h"
extern void diagnostic_initialize (diagnostic_context *, int);
extern void diagnostic_finish (diagnostic_context *);
extern void diagnostic_report_current_module (diagnostic_context *, location_t);


extern diagnostic_t diagnostic_classify_diagnostic (diagnostic_context *,
          int ,
          diagnostic_t ,
          location_t);
extern void diagnostic_push_diagnostics (diagnostic_context *, location_t);
extern void diagnostic_pop_diagnostics (diagnostic_context *, location_t);
extern bool diagnostic_report_diagnostic (diagnostic_context *,
       diagnostic_info *);

extern void diagnostic_set_info (diagnostic_info *, const char *, va_list *,
     location_t, diagnostic_t) __attribute__ ((__format__ (__gcc_cxxdiag__, 2, 0))) __attribute__ ((__nonnull__ (2)));
extern void diagnostic_set_info_translated (diagnostic_info *, const char *,
         va_list *, location_t,
         diagnostic_t)
     __attribute__ ((__format__ (__gcc_cxxdiag__, 2, 0))) __attribute__ ((__nonnull__ (2)));

extern char *diagnostic_build_prefix (diagnostic_context *, diagnostic_info *);
void default_diagnostic_starter (diagnostic_context *, diagnostic_info *);
void default_diagnostic_finalizer (diagnostic_context *, diagnostic_info *);


extern char *file_name_as_prefix (const char *);
# 45 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h" 2

# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/name-lookup.h" 1
# 29 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/name-lookup.h"
typedef struct binding_table_s *binding_table;
typedef struct binding_entry_s *binding_entry;


typedef void (*bt_foreach_proc) (binding_entry, void *);

struct binding_entry_s {
  binding_entry chain;
  tree name;
  tree type;
};
# 48 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/name-lookup.h"
extern void binding_table_foreach (binding_table, bt_foreach_proc, void *);
extern binding_entry binding_table_find (binding_table, tree);



typedef struct cxx_binding cxx_binding;


typedef struct cp_binding_level cp_binding_level;
# 66 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/name-lookup.h"
struct cxx_binding {

  cxx_binding *previous;

  tree value;

  tree type;

  cp_binding_level *scope;
  unsigned value_is_inherited : 1;
  unsigned is_local : 1;
};



typedef struct cxx_saved_binding {

  tree identifier;

  cxx_binding *binding;
  tree real_type_value;
} cxx_saved_binding;

typedef struct VEC_cxx_saved_binding_base { struct vec_prefix prefix; cxx_saved_binding vec[1]; } VEC_cxx_saved_binding_base; typedef struct VEC_cxx_saved_binding_none { VEC_cxx_saved_binding_base base; } VEC_cxx_saved_binding_none; static inline unsigned VEC_cxx_saved_binding_base_length (const VEC_cxx_saved_binding_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline cxx_saved_binding *VEC_cxx_saved_binding_base_last (VEC_cxx_saved_binding_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return &vec_->vec[vec_->prefix.num - 1]; } static inline cxx_saved_binding *VEC_cxx_saved_binding_base_index (VEC_cxx_saved_binding_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return &vec_->vec[ix_]; } static inline int VEC_cxx_saved_binding_base_iterate (VEC_cxx_saved_binding_base *vec_, unsigned ix_, cxx_saved_binding **ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = &vec_->vec[ix_]; return 1; } else { *ptr = 0; return 0; } } static inline size_t VEC_cxx_saved_binding_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_cxx_saved_binding_base, vec) + alloc_ * sizeof(cxx_saved_binding); } static inline void VEC_cxx_saved_binding_base_embedded_init (VEC_cxx_saved_binding_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_cxx_saved_binding_base_space (VEC_cxx_saved_binding_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_cxx_saved_binding_base_splice (VEC_cxx_saved_binding_base *dst_, VEC_cxx_saved_binding_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (cxx_saved_binding)); dst_->prefix.num += len_; } } static inline cxx_saved_binding *VEC_cxx_saved_binding_base_quick_push (VEC_cxx_saved_binding_base *vec_, const cxx_saved_binding *obj_ ) { cxx_saved_binding *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; if (obj_) *slot_ = *obj_; return slot_; } static inline void VEC_cxx_saved_binding_base_pop (VEC_cxx_saved_binding_base *vec_ ) { (void)(vec_->prefix.num); --vec_->prefix.num; } static inline void VEC_cxx_saved_binding_base_truncate (VEC_cxx_saved_binding_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline cxx_saved_binding *VEC_cxx_saved_binding_base_replace (VEC_cxx_saved_binding_base *vec_, unsigned ix_, const cxx_saved_binding *obj_ ) { cxx_saved_binding *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; if (obj_) *slot_ = *obj_; return slot_; } static inline cxx_saved_binding *VEC_cxx_saved_binding_base_quick_insert (VEC_cxx_saved_binding_base *vec_, unsigned ix_, const cxx_saved_binding *obj_ ) { cxx_saved_binding *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (cxx_saved_binding)); if (obj_) *slot_ = *obj_; return slot_; } static inline void VEC_cxx_saved_binding_base_ordered_remove (VEC_cxx_saved_binding_base *vec_, unsigned ix_ ) { cxx_saved_binding *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (cxx_saved_binding)); } static inline void VEC_cxx_saved_binding_base_unordered_remove (VEC_cxx_saved_binding_base *vec_, unsigned ix_ ) { (void)(ix_ < vec_->prefix.num); vec_->vec[ix_] = vec_->vec[--vec_->prefix.num]; } static inline void VEC_cxx_saved_binding_base_block_remove (VEC_cxx_saved_binding_base *vec_, unsigned ix_, unsigned len_ ) { cxx_saved_binding *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (cxx_saved_binding)); } static inline cxx_saved_binding *VEC_cxx_saved_binding_base_address (VEC_cxx_saved_binding_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_cxx_saved_binding_base_lower_bound (VEC_cxx_saved_binding_base *vec_, const cxx_saved_binding *obj_, bool (*lessthan_)(const cxx_saved_binding *, const cxx_saved_binding *) ) { unsigned int len_ = VEC_cxx_saved_binding_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { cxx_saved_binding *middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_cxx_saved_binding_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_cxx_saved_binding_gc { VEC_cxx_saved_binding_base base; } VEC_cxx_saved_binding_gc; static inline VEC_cxx_saved_binding_gc *VEC_cxx_saved_binding_gc_alloc (int alloc_ ) { return (VEC_cxx_saved_binding_gc *) vec_gc_o_reserve_exact (__null, alloc_, __builtin_offsetof (VEC_cxx_saved_binding_gc, base.vec), sizeof (cxx_saved_binding) ); } static inline VEC_cxx_saved_binding_gc *VEC_cxx_saved_binding_gc_copy (VEC_cxx_saved_binding_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_cxx_saved_binding_gc *new_vec_ = __null; if (len_) { new_vec_ = (VEC_cxx_saved_binding_gc *)(vec_gc_o_reserve_exact (__null, len_, __builtin_offsetof (VEC_cxx_saved_binding_gc, base.vec), sizeof (cxx_saved_binding) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (cxx_saved_binding) * len_); } return new_vec_; } static inline void VEC_cxx_saved_binding_gc_free (VEC_cxx_saved_binding_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = __null; } static inline int VEC_cxx_saved_binding_gc_reserve (VEC_cxx_saved_binding_gc **vec_, int alloc_ ) { int extend = !VEC_cxx_saved_binding_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_cxx_saved_binding_gc *) vec_gc_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_cxx_saved_binding_gc, base.vec), sizeof (cxx_saved_binding) ); return extend; } static inline int VEC_cxx_saved_binding_gc_reserve_exact (VEC_cxx_saved_binding_gc **vec_, int alloc_ ) { int extend = !VEC_cxx_saved_binding_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_cxx_saved_binding_gc *) vec_gc_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_cxx_saved_binding_gc, base.vec), sizeof (cxx_saved_binding) ); return extend; } static inline void VEC_cxx_saved_binding_gc_safe_grow (VEC_cxx_saved_binding_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_cxx_saved_binding_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_cxx_saved_binding_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_cxx_saved_binding_gc_safe_grow_cleared (VEC_cxx_saved_binding_gc **vec_, int size_ ) { int oldsize = VEC_cxx_saved_binding_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_cxx_saved_binding_gc_safe_grow (vec_, size_ ); memset (&(VEC_cxx_saved_binding_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (cxx_saved_binding) * (size_ - oldsize)); } static inline void VEC_cxx_saved_binding_gc_safe_splice (VEC_cxx_saved_binding_gc **dst_, VEC_cxx_saved_binding_base *src_ ) { if (src_) { VEC_cxx_saved_binding_gc_reserve_exact (dst_, src_->prefix.num ); VEC_cxx_saved_binding_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline cxx_saved_binding *VEC_cxx_saved_binding_gc_safe_push (VEC_cxx_saved_binding_gc **vec_, const cxx_saved_binding *obj_ ) { VEC_cxx_saved_binding_gc_reserve (vec_, 1 ); return VEC_cxx_saved_binding_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline cxx_saved_binding *VEC_cxx_saved_binding_gc_safe_insert (VEC_cxx_saved_binding_gc **vec_, unsigned ix_, const cxx_saved_binding *obj_ ) { VEC_cxx_saved_binding_gc_reserve (vec_, 1 ); return VEC_cxx_saved_binding_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;

extern tree identifier_type_value (tree);
extern void set_identifier_type_value (tree, tree);
extern void pop_binding (tree, tree);
extern tree constructor_name (tree);
extern bool constructor_name_p (tree, tree);


typedef enum scope_kind {
  sk_block = 0,




  sk_cleanup,


  sk_try,
  sk_catch,
  sk_for,

  sk_cond,

  sk_function_parms,
  sk_class,
  sk_scoped_enum,

  sk_namespace,

  sk_template_parms,
  sk_template_spec,



  sk_omp
} scope_kind;


typedef enum tag_scope {
  ts_current = 0,




  ts_global = 1,


  ts_within_enclosing_non_class = 2



} tag_scope;

typedef struct cp_class_binding {
  cxx_binding *base;

  tree identifier;
} cp_class_binding;

typedef struct VEC_cp_class_binding_base { struct vec_prefix prefix; cp_class_binding vec[1]; } VEC_cp_class_binding_base; typedef struct VEC_cp_class_binding_none { VEC_cp_class_binding_base base; } VEC_cp_class_binding_none; static inline unsigned VEC_cp_class_binding_base_length (const VEC_cp_class_binding_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline cp_class_binding *VEC_cp_class_binding_base_last (VEC_cp_class_binding_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return &vec_->vec[vec_->prefix.num - 1]; } static inline cp_class_binding *VEC_cp_class_binding_base_index (VEC_cp_class_binding_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return &vec_->vec[ix_]; } static inline int VEC_cp_class_binding_base_iterate (VEC_cp_class_binding_base *vec_, unsigned ix_, cp_class_binding **ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = &vec_->vec[ix_]; return 1; } else { *ptr = 0; return 0; } } static inline size_t VEC_cp_class_binding_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_cp_class_binding_base, vec) + alloc_ * sizeof(cp_class_binding); } static inline void VEC_cp_class_binding_base_embedded_init (VEC_cp_class_binding_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_cp_class_binding_base_space (VEC_cp_class_binding_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_cp_class_binding_base_splice (VEC_cp_class_binding_base *dst_, VEC_cp_class_binding_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (cp_class_binding)); dst_->prefix.num += len_; } } static inline cp_class_binding *VEC_cp_class_binding_base_quick_push (VEC_cp_class_binding_base *vec_, const cp_class_binding *obj_ ) { cp_class_binding *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; if (obj_) *slot_ = *obj_; return slot_; } static inline void VEC_cp_class_binding_base_pop (VEC_cp_class_binding_base *vec_ ) { (void)(vec_->prefix.num); --vec_->prefix.num; } static inline void VEC_cp_class_binding_base_truncate (VEC_cp_class_binding_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline cp_class_binding *VEC_cp_class_binding_base_replace (VEC_cp_class_binding_base *vec_, unsigned ix_, const cp_class_binding *obj_ ) { cp_class_binding *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; if (obj_) *slot_ = *obj_; return slot_; } static inline cp_class_binding *VEC_cp_class_binding_base_quick_insert (VEC_cp_class_binding_base *vec_, unsigned ix_, const cp_class_binding *obj_ ) { cp_class_binding *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (cp_class_binding)); if (obj_) *slot_ = *obj_; return slot_; } static inline void VEC_cp_class_binding_base_ordered_remove (VEC_cp_class_binding_base *vec_, unsigned ix_ ) { cp_class_binding *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (cp_class_binding)); } static inline void VEC_cp_class_binding_base_unordered_remove (VEC_cp_class_binding_base *vec_, unsigned ix_ ) { (void)(ix_ < vec_->prefix.num); vec_->vec[ix_] = vec_->vec[--vec_->prefix.num]; } static inline void VEC_cp_class_binding_base_block_remove (VEC_cp_class_binding_base *vec_, unsigned ix_, unsigned len_ ) { cp_class_binding *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (cp_class_binding)); } static inline cp_class_binding *VEC_cp_class_binding_base_address (VEC_cp_class_binding_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_cp_class_binding_base_lower_bound (VEC_cp_class_binding_base *vec_, const cp_class_binding *obj_, bool (*lessthan_)(const cp_class_binding *, const cp_class_binding *) ) { unsigned int len_ = VEC_cp_class_binding_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { cp_class_binding *middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_cp_class_binding_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_cp_class_binding_gc { VEC_cp_class_binding_base base; } VEC_cp_class_binding_gc; static inline VEC_cp_class_binding_gc *VEC_cp_class_binding_gc_alloc (int alloc_ ) { return (VEC_cp_class_binding_gc *) vec_gc_o_reserve_exact (__null, alloc_, __builtin_offsetof (VEC_cp_class_binding_gc, base.vec), sizeof (cp_class_binding) ); } static inline VEC_cp_class_binding_gc *VEC_cp_class_binding_gc_copy (VEC_cp_class_binding_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_cp_class_binding_gc *new_vec_ = __null; if (len_) { new_vec_ = (VEC_cp_class_binding_gc *)(vec_gc_o_reserve_exact (__null, len_, __builtin_offsetof (VEC_cp_class_binding_gc, base.vec), sizeof (cp_class_binding) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (cp_class_binding) * len_); } return new_vec_; } static inline void VEC_cp_class_binding_gc_free (VEC_cp_class_binding_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = __null; } static inline int VEC_cp_class_binding_gc_reserve (VEC_cp_class_binding_gc **vec_, int alloc_ ) { int extend = !VEC_cp_class_binding_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_cp_class_binding_gc *) vec_gc_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_cp_class_binding_gc, base.vec), sizeof (cp_class_binding) ); return extend; } static inline int VEC_cp_class_binding_gc_reserve_exact (VEC_cp_class_binding_gc **vec_, int alloc_ ) { int extend = !VEC_cp_class_binding_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_cp_class_binding_gc *) vec_gc_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_cp_class_binding_gc, base.vec), sizeof (cp_class_binding) ); return extend; } static inline void VEC_cp_class_binding_gc_safe_grow (VEC_cp_class_binding_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_cp_class_binding_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_cp_class_binding_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_cp_class_binding_gc_safe_grow_cleared (VEC_cp_class_binding_gc **vec_, int size_ ) { int oldsize = VEC_cp_class_binding_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_cp_class_binding_gc_safe_grow (vec_, size_ ); memset (&(VEC_cp_class_binding_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (cp_class_binding) * (size_ - oldsize)); } static inline void VEC_cp_class_binding_gc_safe_splice (VEC_cp_class_binding_gc **dst_, VEC_cp_class_binding_base *src_ ) { if (src_) { VEC_cp_class_binding_gc_reserve_exact (dst_, src_->prefix.num ); VEC_cp_class_binding_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline cp_class_binding *VEC_cp_class_binding_gc_safe_push (VEC_cp_class_binding_gc **vec_, const cp_class_binding *obj_ ) { VEC_cp_class_binding_gc_reserve (vec_, 1 ); return VEC_cp_class_binding_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline cp_class_binding *VEC_cp_class_binding_gc_safe_insert (VEC_cp_class_binding_gc **vec_, unsigned ix_, const cp_class_binding *obj_ ) { VEC_cp_class_binding_gc_reserve (vec_, 1 ); return VEC_cp_class_binding_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;

typedef struct cp_label_binding {

  tree label;

  tree prev_value;
} cp_label_binding;

typedef struct VEC_cp_label_binding_base { struct vec_prefix prefix; cp_label_binding vec[1]; } VEC_cp_label_binding_base; typedef struct VEC_cp_label_binding_none { VEC_cp_label_binding_base base; } VEC_cp_label_binding_none; static inline unsigned VEC_cp_label_binding_base_length (const VEC_cp_label_binding_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline cp_label_binding *VEC_cp_label_binding_base_last (VEC_cp_label_binding_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return &vec_->vec[vec_->prefix.num - 1]; } static inline cp_label_binding *VEC_cp_label_binding_base_index (VEC_cp_label_binding_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return &vec_->vec[ix_]; } static inline int VEC_cp_label_binding_base_iterate (VEC_cp_label_binding_base *vec_, unsigned ix_, cp_label_binding **ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = &vec_->vec[ix_]; return 1; } else { *ptr = 0; return 0; } } static inline size_t VEC_cp_label_binding_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_cp_label_binding_base, vec) + alloc_ * sizeof(cp_label_binding); } static inline void VEC_cp_label_binding_base_embedded_init (VEC_cp_label_binding_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_cp_label_binding_base_space (VEC_cp_label_binding_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_cp_label_binding_base_splice (VEC_cp_label_binding_base *dst_, VEC_cp_label_binding_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (cp_label_binding)); dst_->prefix.num += len_; } } static inline cp_label_binding *VEC_cp_label_binding_base_quick_push (VEC_cp_label_binding_base *vec_, const cp_label_binding *obj_ ) { cp_label_binding *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; if (obj_) *slot_ = *obj_; return slot_; } static inline void VEC_cp_label_binding_base_pop (VEC_cp_label_binding_base *vec_ ) { (void)(vec_->prefix.num); --vec_->prefix.num; } static inline void VEC_cp_label_binding_base_truncate (VEC_cp_label_binding_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline cp_label_binding *VEC_cp_label_binding_base_replace (VEC_cp_label_binding_base *vec_, unsigned ix_, const cp_label_binding *obj_ ) { cp_label_binding *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; if (obj_) *slot_ = *obj_; return slot_; } static inline cp_label_binding *VEC_cp_label_binding_base_quick_insert (VEC_cp_label_binding_base *vec_, unsigned ix_, const cp_label_binding *obj_ ) { cp_label_binding *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (cp_label_binding)); if (obj_) *slot_ = *obj_; return slot_; } static inline void VEC_cp_label_binding_base_ordered_remove (VEC_cp_label_binding_base *vec_, unsigned ix_ ) { cp_label_binding *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (cp_label_binding)); } static inline void VEC_cp_label_binding_base_unordered_remove (VEC_cp_label_binding_base *vec_, unsigned ix_ ) { (void)(ix_ < vec_->prefix.num); vec_->vec[ix_] = vec_->vec[--vec_->prefix.num]; } static inline void VEC_cp_label_binding_base_block_remove (VEC_cp_label_binding_base *vec_, unsigned ix_, unsigned len_ ) { cp_label_binding *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (cp_label_binding)); } static inline cp_label_binding *VEC_cp_label_binding_base_address (VEC_cp_label_binding_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_cp_label_binding_base_lower_bound (VEC_cp_label_binding_base *vec_, const cp_label_binding *obj_, bool (*lessthan_)(const cp_label_binding *, const cp_label_binding *) ) { unsigned int len_ = VEC_cp_label_binding_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { cp_label_binding *middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_cp_label_binding_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_cp_label_binding_gc { VEC_cp_label_binding_base base; } VEC_cp_label_binding_gc; static inline VEC_cp_label_binding_gc *VEC_cp_label_binding_gc_alloc (int alloc_ ) { return (VEC_cp_label_binding_gc *) vec_gc_o_reserve_exact (__null, alloc_, __builtin_offsetof (VEC_cp_label_binding_gc, base.vec), sizeof (cp_label_binding) ); } static inline VEC_cp_label_binding_gc *VEC_cp_label_binding_gc_copy (VEC_cp_label_binding_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_cp_label_binding_gc *new_vec_ = __null; if (len_) { new_vec_ = (VEC_cp_label_binding_gc *)(vec_gc_o_reserve_exact (__null, len_, __builtin_offsetof (VEC_cp_label_binding_gc, base.vec), sizeof (cp_label_binding) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (cp_label_binding) * len_); } return new_vec_; } static inline void VEC_cp_label_binding_gc_free (VEC_cp_label_binding_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = __null; } static inline int VEC_cp_label_binding_gc_reserve (VEC_cp_label_binding_gc **vec_, int alloc_ ) { int extend = !VEC_cp_label_binding_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_cp_label_binding_gc *) vec_gc_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_cp_label_binding_gc, base.vec), sizeof (cp_label_binding) ); return extend; } static inline int VEC_cp_label_binding_gc_reserve_exact (VEC_cp_label_binding_gc **vec_, int alloc_ ) { int extend = !VEC_cp_label_binding_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_cp_label_binding_gc *) vec_gc_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_cp_label_binding_gc, base.vec), sizeof (cp_label_binding) ); return extend; } static inline void VEC_cp_label_binding_gc_safe_grow (VEC_cp_label_binding_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_cp_label_binding_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_cp_label_binding_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_cp_label_binding_gc_safe_grow_cleared (VEC_cp_label_binding_gc **vec_, int size_ ) { int oldsize = VEC_cp_label_binding_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_cp_label_binding_gc_safe_grow (vec_, size_ ); memset (&(VEC_cp_label_binding_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (cp_label_binding) * (size_ - oldsize)); } static inline void VEC_cp_label_binding_gc_safe_splice (VEC_cp_label_binding_gc **dst_, VEC_cp_label_binding_base *src_ ) { if (src_) { VEC_cp_label_binding_gc_reserve_exact (dst_, src_->prefix.num ); VEC_cp_label_binding_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline cp_label_binding *VEC_cp_label_binding_gc_safe_push (VEC_cp_label_binding_gc **vec_, const cp_label_binding *obj_ ) { VEC_cp_label_binding_gc_reserve (vec_, 1 ); return VEC_cp_label_binding_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline cp_label_binding *VEC_cp_label_binding_gc_safe_insert (VEC_cp_label_binding_gc **vec_, unsigned ix_, const cp_label_binding *obj_ ) { VEC_cp_label_binding_gc_reserve (vec_, 1 ); return VEC_cp_label_binding_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;
# 187 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/name-lookup.h"
struct cp_binding_level {




  tree names;


  tree namespaces;


  VEC_tree_gc *static_decls;


  tree usings;



  tree using_directives;



  VEC_cp_class_binding_gc *class_shadowed;






  tree type_shadowed;



  VEC_cp_label_binding_gc *shadowed_labels;




  tree blocks;



  tree this_entity;


  cp_binding_level *level_chain;




  VEC_tree_gc *dead_vars_from_for;



  tree statement_list;


  int binding_depth;




  enum scope_kind kind : 4;



  unsigned int explicit_spec_p : 1;


  unsigned keep : 1;



  unsigned more_cleanups_ok : 1;
  unsigned have_cleanups : 1;


};
# 278 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/name-lookup.h"
extern tree global_namespace;
extern tree global_scope_name;




extern tree global_type_node;





extern cp_binding_level *leave_scope (void);
extern bool kept_level_p (void);
extern bool global_bindings_p (void);
extern bool toplevel_bindings_p (void);
extern bool namespace_bindings_p (void);
extern bool local_bindings_p (void);
extern bool template_parm_scope_p (void);
extern scope_kind innermost_scope_kind (void);
extern cp_binding_level *begin_scope (scope_kind, tree);
extern void print_binding_stack (void);
extern void push_to_top_level (void);
extern void pop_from_top_level (void);
extern void pop_everything (void);
extern void keep_next_level (bool);
extern bool is_ancestor (tree, tree);
extern tree push_scope (tree);
extern void pop_scope (tree);
extern tree push_inner_scope (tree);
extern void pop_inner_scope (tree, tree);
extern void push_binding_level (cp_binding_level *);

extern void push_namespace (tree);
extern void pop_namespace (void);
extern void push_nested_namespace (tree);
extern void pop_nested_namespace (tree);
extern bool handle_namespace_attrs (tree, tree);
extern void pushlevel_class (void);
extern void poplevel_class (void);
extern tree pushdecl_with_scope (tree, cp_binding_level *, bool);
extern tree lookup_name_prefer_type (tree, int);
extern tree lookup_name_real (tree, int, int, bool, int, int);
extern tree lookup_type_scope (tree, tag_scope);
extern tree namespace_binding (tree, tree);
extern void set_namespace_binding (tree, tree, tree);
extern bool hidden_name_p (tree);
extern tree remove_hidden_names (tree);
extern tree lookup_qualified_name (tree, tree, bool, bool);
extern tree lookup_name_nonclass (tree);
extern tree lookup_name_innermost_nonclass_level (tree);
extern bool is_local_extern (tree);
extern tree lookup_function_nonclass (tree, VEC_tree_gc *, bool);
extern void push_local_binding (tree, tree, int);
extern bool pushdecl_class_level (tree);
extern tree pushdecl_namespace_level (tree, bool);
extern bool push_class_level_binding (tree, tree);
extern tree getdecls (void);
extern int function_parm_depth (void);
extern tree cp_namespace_decls (tree);
extern void set_decl_namespace (tree, tree, bool);
extern void push_decl_namespace (tree);
extern void pop_decl_namespace (void);
extern void do_namespace_alias (tree, tree);
extern void do_toplevel_using_decl (tree, tree, tree);
extern void do_local_using_decl (tree, tree, tree);
extern tree do_class_using_decl (tree, tree);
extern void do_using_directive (tree);
extern tree lookup_arg_dependent (tree, tree, VEC_tree_gc *, bool);
extern bool is_associated_namespace (tree, tree);
extern void parse_using_directive (tree, tree);
extern tree innermost_non_namespace_value (tree);
extern cxx_binding *outer_binding (tree, cxx_binding *, bool);
extern void cp_emit_debug_info_for_using (tree, tree);




static inline bool
get_global_value_if_present (tree id, tree *decl)
{
  tree global_value = namespace_binding (id, global_namespace);
  if (global_value)
    *decl = global_value;
  return global_value != __null;
}



static inline bool
is_typename_at_global_scope (tree id)
{
  tree global_value = namespace_binding (id, global_namespace);

  return global_value && ((enum tree_code) (global_value)->base.code) == TYPE_DECL;
}
# 47 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h" 2
# 229 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
struct lang_identifier {
  struct c_common_identifier c_common;
  cxx_binding *namespace_bindings;
  cxx_binding *bindings;
  tree class_template_info;
  tree label_value;
};
# 246 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
struct template_parm_index_s {
  struct tree_common common;
  int index;
  int level;
  int orig_level;
  int num_siblings;
  tree decl;
};
typedef struct template_parm_index_s template_parm_index;

struct ptrmem_cst {
  struct tree_common common;
  tree member;
};
typedef struct ptrmem_cst * ptrmem_cst_t;
# 331 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
struct tree_overload {
  struct tree_common common;
  tree function;
};
# 362 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
struct tree_baselink {
  struct tree_common common;
  tree binfo;
  tree functions;
  tree access_binfo;
};



typedef enum cp_id_kind
{

  CP_ID_KIND_NONE,

  CP_ID_KIND_UNQUALIFIED,

  CP_ID_KIND_UNQUALIFIED_DEPENDENT,

  CP_ID_KIND_TEMPLATE_ID,

  CP_ID_KIND_QUALIFIED
} cp_id_kind;




typedef enum cpp0x_warn_str
{

  CPP0X_INITIALIZER_LISTS,

  CPP0X_EXPLICIT_CONVERSION,

  CPP0X_VARIADIC_TEMPLATES,

  CPP0X_LAMBDA_EXPR,

  CPP0X_AUTO,

  CPP0X_SCOPED_ENUMS,

  CPP0X_DEFAULTED_DELETED,

  CPP0X_INLINE_NAMESPACES,

  CPP0X_OVERRIDE_CONTROLS,

  CPP0X_NSDMI,

  CPP0X_USER_DEFINED_LITERALS,

  CPP0X_DELEGATING_CTORS
} cpp0x_warn_str;



typedef enum composite_pointer_operation
{

  CPO_COMPARISON,

  CPO_CONVERSION,

  CPO_CONDITIONAL_EXPR
} composite_pointer_operation;


typedef enum expr_list_kind {
  ELK_INIT,
  ELK_MEM_INIT,
  ELK_FUNC_CAST
} expr_list_kind;


typedef enum impl_conv_rhs {
  ICR_DEFAULT_ARGUMENT,
  ICR_CONVERTING,
  ICR_INIT,
  ICR_ARGPASS,
  ICR_RETURN,
  ICR_ASSIGN
} impl_conv_rhs;


typedef enum impl_conv_void {
  ICV_CAST,
  ICV_SECOND_OF_COND,
  ICV_THIRD_OF_COND,
  ICV_RIGHT_OF_COMMA,
  ICV_LEFT_OF_COMMA,
  ICV_STATEMENT,
  ICV_THIRD_IN_FOR
} impl_conv_void;
# 522 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
struct tree_default_arg {
  struct tree_common common;
  struct cp_token_cache *tokens;
  VEC_tree_gc *instantiations;
};
# 538 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
struct tree_deferred_noexcept {
  struct tree_base base;
  tree pattern;
  tree args;
};
# 560 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
struct tree_static_assert {
  struct tree_common common;
  tree condition;
  tree message;
  location_t location;
};

struct tree_argument_pack_select {
  struct tree_common common;
  tree argument_pack;
  int index;
};



typedef enum cp_trait_kind
{
  CPTK_BASES,
  CPTK_DIRECT_BASES,
  CPTK_HAS_NOTHROW_ASSIGN,
  CPTK_HAS_NOTHROW_CONSTRUCTOR,
  CPTK_HAS_NOTHROW_COPY,
  CPTK_HAS_TRIVIAL_ASSIGN,
  CPTK_HAS_TRIVIAL_CONSTRUCTOR,
  CPTK_HAS_TRIVIAL_COPY,
  CPTK_HAS_TRIVIAL_DESTRUCTOR,
  CPTK_HAS_VIRTUAL_DESTRUCTOR,
  CPTK_IS_ABSTRACT,
  CPTK_IS_BASE_OF,
  CPTK_IS_CLASS,
  CPTK_IS_CONVERTIBLE_TO,
  CPTK_IS_EMPTY,
  CPTK_IS_ENUM,
  CPTK_IS_FINAL,
  CPTK_IS_LITERAL_TYPE,
  CPTK_IS_POD,
  CPTK_IS_POLYMORPHIC,
  CPTK_IS_STD_LAYOUT,
  CPTK_IS_TRIVIAL,
  CPTK_IS_UNION,
  CPTK_UNDERLYING_TYPE
} cp_trait_kind;
# 614 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
struct tree_trait_expr {
  struct tree_common common;
  tree type1;
  tree type2;
  enum cp_trait_kind kind;
};
# 630 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
enum cp_lambda_default_capture_mode_type {
  CPLD_NONE,
  CPLD_COPY,
  CPLD_REFERENCE
};
# 696 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
struct tree_lambda_expr
{
  struct tree_typed typed;
  tree capture_list;
  tree this_capture;
  tree return_type;
  tree extra_scope;
  tree closure;
  VEC_tree_gc* pending_proxies;
  location_t locus;
  enum cp_lambda_default_capture_mode_type default_capture_mode;
  int discriminator;
};
# 724 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
struct qualified_typedef_usage_s {
  tree typedef_decl;
  tree context;
  location_t locus;
};
typedef struct qualified_typedef_usage_s qualified_typedef_usage_t;
typedef struct VEC_qualified_typedef_usage_t_base { struct vec_prefix prefix; qualified_typedef_usage_t vec[1]; } VEC_qualified_typedef_usage_t_base; typedef struct VEC_qualified_typedef_usage_t_none { VEC_qualified_typedef_usage_t_base base; } VEC_qualified_typedef_usage_t_none; static inline unsigned VEC_qualified_typedef_usage_t_base_length (const VEC_qualified_typedef_usage_t_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline qualified_typedef_usage_t *VEC_qualified_typedef_usage_t_base_last (VEC_qualified_typedef_usage_t_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return &vec_->vec[vec_->prefix.num - 1]; } static inline qualified_typedef_usage_t *VEC_qualified_typedef_usage_t_base_index (VEC_qualified_typedef_usage_t_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return &vec_->vec[ix_]; } static inline int VEC_qualified_typedef_usage_t_base_iterate (VEC_qualified_typedef_usage_t_base *vec_, unsigned ix_, qualified_typedef_usage_t **ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = &vec_->vec[ix_]; return 1; } else { *ptr = 0; return 0; } } static inline size_t VEC_qualified_typedef_usage_t_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_qualified_typedef_usage_t_base, vec) + alloc_ * sizeof(qualified_typedef_usage_t); } static inline void VEC_qualified_typedef_usage_t_base_embedded_init (VEC_qualified_typedef_usage_t_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_qualified_typedef_usage_t_base_space (VEC_qualified_typedef_usage_t_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_qualified_typedef_usage_t_base_splice (VEC_qualified_typedef_usage_t_base *dst_, VEC_qualified_typedef_usage_t_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (qualified_typedef_usage_t)); dst_->prefix.num += len_; } } static inline qualified_typedef_usage_t *VEC_qualified_typedef_usage_t_base_quick_push (VEC_qualified_typedef_usage_t_base *vec_, const qualified_typedef_usage_t *obj_ ) { qualified_typedef_usage_t *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; if (obj_) *slot_ = *obj_; return slot_; } static inline void VEC_qualified_typedef_usage_t_base_pop (VEC_qualified_typedef_usage_t_base *vec_ ) { (void)(vec_->prefix.num); --vec_->prefix.num; } static inline void VEC_qualified_typedef_usage_t_base_truncate (VEC_qualified_typedef_usage_t_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline qualified_typedef_usage_t *VEC_qualified_typedef_usage_t_base_replace (VEC_qualified_typedef_usage_t_base *vec_, unsigned ix_, const qualified_typedef_usage_t *obj_ ) { qualified_typedef_usage_t *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; if (obj_) *slot_ = *obj_; return slot_; } static inline qualified_typedef_usage_t *VEC_qualified_typedef_usage_t_base_quick_insert (VEC_qualified_typedef_usage_t_base *vec_, unsigned ix_, const qualified_typedef_usage_t *obj_ ) { qualified_typedef_usage_t *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (qualified_typedef_usage_t)); if (obj_) *slot_ = *obj_; return slot_; } static inline void VEC_qualified_typedef_usage_t_base_ordered_remove (VEC_qualified_typedef_usage_t_base *vec_, unsigned ix_ ) { qualified_typedef_usage_t *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (qualified_typedef_usage_t)); } static inline void VEC_qualified_typedef_usage_t_base_unordered_remove (VEC_qualified_typedef_usage_t_base *vec_, unsigned ix_ ) { (void)(ix_ < vec_->prefix.num); vec_->vec[ix_] = vec_->vec[--vec_->prefix.num]; } static inline void VEC_qualified_typedef_usage_t_base_block_remove (VEC_qualified_typedef_usage_t_base *vec_, unsigned ix_, unsigned len_ ) { qualified_typedef_usage_t *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (qualified_typedef_usage_t)); } static inline qualified_typedef_usage_t *VEC_qualified_typedef_usage_t_base_address (VEC_qualified_typedef_usage_t_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_qualified_typedef_usage_t_base_lower_bound (VEC_qualified_typedef_usage_t_base *vec_, const qualified_typedef_usage_t *obj_, bool (*lessthan_)(const qualified_typedef_usage_t *, const qualified_typedef_usage_t *) ) { unsigned int len_ = VEC_qualified_typedef_usage_t_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { qualified_typedef_usage_t *middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_qualified_typedef_usage_t_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_qualified_typedef_usage_t_gc { VEC_qualified_typedef_usage_t_base base; } VEC_qualified_typedef_usage_t_gc; static inline VEC_qualified_typedef_usage_t_gc *VEC_qualified_typedef_usage_t_gc_alloc (int alloc_ ) { return (VEC_qualified_typedef_usage_t_gc *) vec_gc_o_reserve_exact (__null, alloc_, __builtin_offsetof (VEC_qualified_typedef_usage_t_gc, base.vec), sizeof (qualified_typedef_usage_t) ); } static inline VEC_qualified_typedef_usage_t_gc *VEC_qualified_typedef_usage_t_gc_copy (VEC_qualified_typedef_usage_t_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_qualified_typedef_usage_t_gc *new_vec_ = __null; if (len_) { new_vec_ = (VEC_qualified_typedef_usage_t_gc *)(vec_gc_o_reserve_exact (__null, len_, __builtin_offsetof (VEC_qualified_typedef_usage_t_gc, base.vec), sizeof (qualified_typedef_usage_t) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (qualified_typedef_usage_t) * len_); } return new_vec_; } static inline void VEC_qualified_typedef_usage_t_gc_free (VEC_qualified_typedef_usage_t_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = __null; } static inline int VEC_qualified_typedef_usage_t_gc_reserve (VEC_qualified_typedef_usage_t_gc **vec_, int alloc_ ) { int extend = !VEC_qualified_typedef_usage_t_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_qualified_typedef_usage_t_gc *) vec_gc_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_qualified_typedef_usage_t_gc, base.vec), sizeof (qualified_typedef_usage_t) ); return extend; } static inline int VEC_qualified_typedef_usage_t_gc_reserve_exact (VEC_qualified_typedef_usage_t_gc **vec_, int alloc_ ) { int extend = !VEC_qualified_typedef_usage_t_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_qualified_typedef_usage_t_gc *) vec_gc_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_qualified_typedef_usage_t_gc, base.vec), sizeof (qualified_typedef_usage_t) ); return extend; } static inline void VEC_qualified_typedef_usage_t_gc_safe_grow (VEC_qualified_typedef_usage_t_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_qualified_typedef_usage_t_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_qualified_typedef_usage_t_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_qualified_typedef_usage_t_gc_safe_grow_cleared (VEC_qualified_typedef_usage_t_gc **vec_, int size_ ) { int oldsize = VEC_qualified_typedef_usage_t_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_qualified_typedef_usage_t_gc_safe_grow (vec_, size_ ); memset (&(VEC_qualified_typedef_usage_t_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (qualified_typedef_usage_t) * (size_ - oldsize)); } static inline void VEC_qualified_typedef_usage_t_gc_safe_splice (VEC_qualified_typedef_usage_t_gc **dst_, VEC_qualified_typedef_usage_t_base *src_ ) { if (src_) { VEC_qualified_typedef_usage_t_gc_reserve_exact (dst_, src_->prefix.num ); VEC_qualified_typedef_usage_t_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline qualified_typedef_usage_t *VEC_qualified_typedef_usage_t_gc_safe_push (VEC_qualified_typedef_usage_t_gc **vec_, const qualified_typedef_usage_t *obj_ ) { VEC_qualified_typedef_usage_t_gc_reserve (vec_, 1 ); return VEC_qualified_typedef_usage_t_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline qualified_typedef_usage_t *VEC_qualified_typedef_usage_t_gc_safe_insert (VEC_qualified_typedef_usage_t_gc **vec_, unsigned ix_, const qualified_typedef_usage_t *obj_ ) { VEC_qualified_typedef_usage_t_gc_reserve (vec_, 1 ); return VEC_qualified_typedef_usage_t_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;

struct tree_template_info {
  struct tree_common common;
  VEC_qualified_typedef_usage_t_gc *typedefs_needing_access_checking;
};

enum cp_tree_node_structure_enum {
  TS_CP_GENERIC,
  TS_CP_IDENTIFIER,
  TS_CP_TPI,
  TS_CP_PTRMEM,
  TS_CP_BINDING,
  TS_CP_OVERLOAD,
  TS_CP_BASELINK,
  TS_CP_WRAPPER,
  TS_CP_DEFAULT_ARG,
  TS_CP_DEFERRED_NOEXCEPT,
  TS_CP_STATIC_ASSERT,
  TS_CP_ARGUMENT_PACK_SELECT,
  TS_CP_TRAIT_EXPR,
  TS_CP_LAMBDA_EXPR,
  TS_CP_TEMPLATE_INFO,
  TS_CP_USERDEF_LITERAL,
  LAST_TS_CP_ENUM
};


union
                                                                                 lang_tree_node {
  union tree_node
                                        generic;
  struct template_parm_index_s tpi;
  struct ptrmem_cst ptrmem;
  struct tree_overload overload;
  struct tree_baselink baselink;
  struct tree_default_arg default_arg;
  struct tree_deferred_noexcept deferred_noexcept;
  struct lang_identifier identifier;
  struct tree_static_assert
    static_assertion;
  struct tree_argument_pack_select
    argument_pack_select;
  struct tree_trait_expr
    trait_expression;
  struct tree_lambda_expr
    lambda_expression;
  struct tree_template_info
    template_info;
  struct tree_userdef_literal
    userdef_literal;
};


enum cp_tree_index
{
    CPTI_JAVA_BYTE_TYPE,
    CPTI_JAVA_SHORT_TYPE,
    CPTI_JAVA_INT_TYPE,
    CPTI_JAVA_LONG_TYPE,
    CPTI_JAVA_FLOAT_TYPE,
    CPTI_JAVA_DOUBLE_TYPE,
    CPTI_JAVA_CHAR_TYPE,
    CPTI_JAVA_BOOLEAN_TYPE,

    CPTI_WCHAR_DECL,
    CPTI_VTABLE_ENTRY_TYPE,
    CPTI_DELTA_TYPE,
    CPTI_VTABLE_INDEX_TYPE,
    CPTI_CLEANUP_TYPE,
    CPTI_VTT_PARM_TYPE,

    CPTI_CLASS_TYPE,
    CPTI_UNKNOWN_TYPE,
    CPTI_INIT_LIST_TYPE,
    CPTI_DEPENDENT_LAMBDA_RETURN_TYPE,
    CPTI_VTBL_TYPE,
    CPTI_VTBL_PTR_TYPE,
    CPTI_STD,
    CPTI_ABI,
    CPTI_CONST_TYPE_INFO_TYPE,
    CPTI_TYPE_INFO_PTR_TYPE,
    CPTI_ABORT_FNDECL,
    CPTI_GLOBAL_DELETE_FNDECL,
    CPTI_AGGR_TAG,

    CPTI_CTOR_IDENTIFIER,
    CPTI_COMPLETE_CTOR_IDENTIFIER,
    CPTI_BASE_CTOR_IDENTIFIER,
    CPTI_DTOR_IDENTIFIER,
    CPTI_COMPLETE_DTOR_IDENTIFIER,
    CPTI_BASE_DTOR_IDENTIFIER,
    CPTI_DELETING_DTOR_IDENTIFIER,
    CPTI_DELTA_IDENTIFIER,
    CPTI_IN_CHARGE_IDENTIFIER,
    CPTI_VTT_PARM_IDENTIFIER,
    CPTI_NELTS_IDENTIFIER,
    CPTI_THIS_IDENTIFIER,
    CPTI_PFN_IDENTIFIER,
    CPTI_VPTR_IDENTIFIER,
    CPTI_STD_IDENTIFIER,

    CPTI_LANG_NAME_C,
    CPTI_LANG_NAME_CPLUSPLUS,
    CPTI_LANG_NAME_JAVA,

    CPTI_EMPTY_EXCEPT_SPEC,
    CPTI_NOEXCEPT_TRUE_SPEC,
    CPTI_NOEXCEPT_FALSE_SPEC,
    CPTI_JCLASS,
    CPTI_TERMINATE,
    CPTI_CALL_UNEXPECTED,
    CPTI_ATEXIT_FN_PTR_TYPE,
    CPTI_ATEXIT,
    CPTI_DSO_HANDLE,
    CPTI_DCAST,

    CPTI_KEYED_CLASSES,

    CPTI_NULLPTR,
    CPTI_NULLPTR_TYPE,

    CPTI_MAX
};

extern tree cp_global_trees[CPTI_MAX];
# 974 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
struct saved_scope {
  VEC_cxx_saved_binding_gc *old_bindings;
  tree old_namespace;
  VEC_tree_gc *decl_ns_list;
  tree class_name;
  tree class_type;
  tree access_specifier;
  tree function_decl;
  VEC_tree_gc *lang_base;
  tree lang_name;
  tree template_parms;
  cp_binding_level *x_previous_class_level;
  tree x_saved_tree;


  tree x_current_class_ptr;
  tree x_current_class_ref;

  int x_processing_template_decl;
  int x_processing_specialization;
  unsigned int x_processing_explicit_instantiation : 1;
  unsigned int need_pop_function_context : 1;

  int unevaluated_operand;
  int inhibit_evaluation_warnings;

  struct stmt_tree_s x_stmt_tree;

  cp_binding_level *class_bindings;
  cp_binding_level *bindings;

  struct saved_scope *prev;
};
# 1056 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
extern struct saved_scope *scope_chain;

struct cxx_int_tree_map {
  unsigned int uid;
  tree to;
};

extern unsigned int cxx_int_tree_map_hash (const void *);
extern int cxx_int_tree_map_eq (const void *, const void *);



struct language_function {
  struct c_language_function base;

  tree x_cdtor_label;
  tree x_current_class_ptr;
  tree x_current_class_ref;
  tree x_eh_spec_block;
  tree x_in_charge_parm;
  tree x_vtt_parm;
  tree x_return_value;

  unsigned int returns_value : 1;
  unsigned int returns_null : 1;
  unsigned int returns_abnormally : 1;
  unsigned int x_in_function_try_handler : 1;
  unsigned int x_in_base_initializer : 1;


  unsigned int can_throw : 1;

  htab_t x_named_labels;
  cp_binding_level *bindings;
  VEC_tree_gc *x_local_names;
  htab_t extern_decl_map;
};
# 1174 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
extern bool statement_code_p[MAX_TREE_CODES];



enum languages { lang_c, lang_cplusplus, lang_java };
# 1289 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
typedef struct tree_pair_s {
  tree purpose;
  tree value;
} tree_pair_s;
typedef tree_pair_s *tree_pair_p;
typedef struct VEC_tree_pair_s_base { struct vec_prefix prefix; tree_pair_s vec[1]; } VEC_tree_pair_s_base; typedef struct VEC_tree_pair_s_none { VEC_tree_pair_s_base base; } VEC_tree_pair_s_none; static inline unsigned VEC_tree_pair_s_base_length (const VEC_tree_pair_s_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline tree_pair_s *VEC_tree_pair_s_base_last (VEC_tree_pair_s_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return &vec_->vec[vec_->prefix.num - 1]; } static inline tree_pair_s *VEC_tree_pair_s_base_index (VEC_tree_pair_s_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return &vec_->vec[ix_]; } static inline int VEC_tree_pair_s_base_iterate (VEC_tree_pair_s_base *vec_, unsigned ix_, tree_pair_s **ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = &vec_->vec[ix_]; return 1; } else { *ptr = 0; return 0; } } static inline size_t VEC_tree_pair_s_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_tree_pair_s_base, vec) + alloc_ * sizeof(tree_pair_s); } static inline void VEC_tree_pair_s_base_embedded_init (VEC_tree_pair_s_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_tree_pair_s_base_space (VEC_tree_pair_s_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_tree_pair_s_base_splice (VEC_tree_pair_s_base *dst_, VEC_tree_pair_s_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (tree_pair_s)); dst_->prefix.num += len_; } } static inline tree_pair_s *VEC_tree_pair_s_base_quick_push (VEC_tree_pair_s_base *vec_, const tree_pair_s *obj_ ) { tree_pair_s *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; if (obj_) *slot_ = *obj_; return slot_; } static inline void VEC_tree_pair_s_base_pop (VEC_tree_pair_s_base *vec_ ) { (void)(vec_->prefix.num); --vec_->prefix.num; } static inline void VEC_tree_pair_s_base_truncate (VEC_tree_pair_s_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline tree_pair_s *VEC_tree_pair_s_base_replace (VEC_tree_pair_s_base *vec_, unsigned ix_, const tree_pair_s *obj_ ) { tree_pair_s *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; if (obj_) *slot_ = *obj_; return slot_; } static inline tree_pair_s *VEC_tree_pair_s_base_quick_insert (VEC_tree_pair_s_base *vec_, unsigned ix_, const tree_pair_s *obj_ ) { tree_pair_s *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (tree_pair_s)); if (obj_) *slot_ = *obj_; return slot_; } static inline void VEC_tree_pair_s_base_ordered_remove (VEC_tree_pair_s_base *vec_, unsigned ix_ ) { tree_pair_s *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (tree_pair_s)); } static inline void VEC_tree_pair_s_base_unordered_remove (VEC_tree_pair_s_base *vec_, unsigned ix_ ) { (void)(ix_ < vec_->prefix.num); vec_->vec[ix_] = vec_->vec[--vec_->prefix.num]; } static inline void VEC_tree_pair_s_base_block_remove (VEC_tree_pair_s_base *vec_, unsigned ix_, unsigned len_ ) { tree_pair_s *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (tree_pair_s)); } static inline tree_pair_s *VEC_tree_pair_s_base_address (VEC_tree_pair_s_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_tree_pair_s_base_lower_bound (VEC_tree_pair_s_base *vec_, const tree_pair_s *obj_, bool (*lessthan_)(const tree_pair_s *, const tree_pair_s *) ) { unsigned int len_ = VEC_tree_pair_s_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { tree_pair_s *middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_tree_pair_s_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_tree_pair_s_gc { VEC_tree_pair_s_base base; } VEC_tree_pair_s_gc; static inline VEC_tree_pair_s_gc *VEC_tree_pair_s_gc_alloc (int alloc_ ) { return (VEC_tree_pair_s_gc *) vec_gc_o_reserve_exact (__null, alloc_, __builtin_offsetof (VEC_tree_pair_s_gc, base.vec), sizeof (tree_pair_s) ); } static inline VEC_tree_pair_s_gc *VEC_tree_pair_s_gc_copy (VEC_tree_pair_s_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_tree_pair_s_gc *new_vec_ = __null; if (len_) { new_vec_ = (VEC_tree_pair_s_gc *)(vec_gc_o_reserve_exact (__null, len_, __builtin_offsetof (VEC_tree_pair_s_gc, base.vec), sizeof (tree_pair_s) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (tree_pair_s) * len_); } return new_vec_; } static inline void VEC_tree_pair_s_gc_free (VEC_tree_pair_s_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = __null; } static inline int VEC_tree_pair_s_gc_reserve (VEC_tree_pair_s_gc **vec_, int alloc_ ) { int extend = !VEC_tree_pair_s_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_tree_pair_s_gc *) vec_gc_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_tree_pair_s_gc, base.vec), sizeof (tree_pair_s) ); return extend; } static inline int VEC_tree_pair_s_gc_reserve_exact (VEC_tree_pair_s_gc **vec_, int alloc_ ) { int extend = !VEC_tree_pair_s_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_tree_pair_s_gc *) vec_gc_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_tree_pair_s_gc, base.vec), sizeof (tree_pair_s) ); return extend; } static inline void VEC_tree_pair_s_gc_safe_grow (VEC_tree_pair_s_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_tree_pair_s_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_tree_pair_s_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_tree_pair_s_gc_safe_grow_cleared (VEC_tree_pair_s_gc **vec_, int size_ ) { int oldsize = VEC_tree_pair_s_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_tree_pair_s_gc_safe_grow (vec_, size_ ); memset (&(VEC_tree_pair_s_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (tree_pair_s) * (size_ - oldsize)); } static inline void VEC_tree_pair_s_gc_safe_splice (VEC_tree_pair_s_gc **dst_, VEC_tree_pair_s_base *src_ ) { if (src_) { VEC_tree_pair_s_gc_reserve_exact (dst_, src_->prefix.num ); VEC_tree_pair_s_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline tree_pair_s *VEC_tree_pair_s_gc_safe_push (VEC_tree_pair_s_gc **vec_, const tree_pair_s *obj_ ) { VEC_tree_pair_s_gc_reserve (vec_, 1 ); return VEC_tree_pair_s_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline tree_pair_s *VEC_tree_pair_s_gc_safe_insert (VEC_tree_pair_s_gc **vec_, unsigned ix_, const tree_pair_s *obj_ ) { VEC_tree_pair_s_gc_reserve (vec_, 1 ); return VEC_tree_pair_s_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;




struct lang_type_header {
  unsigned int is_lang_type_class : 1;

  unsigned int has_type_conversion : 1;
  unsigned int has_copy_ctor : 1;
  unsigned int has_default_ctor : 1;
  unsigned int const_needs_init : 1;
  unsigned int ref_needs_init : 1;
  unsigned int has_const_copy_assign : 1;

  unsigned int spare : 1;
};
# 1326 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
struct lang_type_class {
  struct lang_type_header h;

  unsigned char align;

  unsigned has_mutable : 1;
  unsigned com_interface : 1;
  unsigned non_pod_class : 1;
  unsigned nearly_empty_p : 1;
  unsigned user_align : 1;
  unsigned has_copy_assign : 1;
  unsigned has_new : 1;
  unsigned has_array_new : 1;

  unsigned gets_delete : 2;
  unsigned interface_only : 1;
  unsigned interface_unknown : 1;
  unsigned contains_empty_class_p : 1;
  unsigned anon_aggr : 1;
  unsigned non_zero_init : 1;
  unsigned empty_p : 1;

  unsigned vec_new_uses_cookie : 1;
  unsigned declared_class : 1;
  unsigned diamond_shaped : 1;
  unsigned repeated_base : 1;
  unsigned being_defined : 1;
  unsigned java_interface : 1;
  unsigned debug_requested : 1;
  unsigned fields_readonly : 1;

  unsigned use_template : 2;
  unsigned ptrmemfunc_flag : 1;
  unsigned was_anonymous : 1;
  unsigned lazy_default_ctor : 1;
  unsigned lazy_copy_ctor : 1;
  unsigned lazy_copy_assign : 1;
  unsigned lazy_destructor : 1;

  unsigned has_const_copy_ctor : 1;
  unsigned has_complex_copy_ctor : 1;
  unsigned has_complex_copy_assign : 1;
  unsigned non_aggregate : 1;
  unsigned has_complex_dflt : 1;
  unsigned has_list_ctor : 1;
  unsigned non_std_layout : 1;
  unsigned is_literal : 1;

  unsigned lazy_move_ctor : 1;
  unsigned lazy_move_assign : 1;
  unsigned has_complex_move_ctor : 1;
  unsigned has_complex_move_assign : 1;
  unsigned has_constexpr_ctor : 1;
  unsigned is_final : 1;
# 1388 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
  unsigned dummy : 2;

  tree primary_base;
  VEC_tree_pair_s_gc *vcall_indices;
  tree vtables;
  tree typeinfo_var;
  VEC_tree_gc *vbases;
  binding_table nested_udts;
  tree as_base;
  VEC_tree_gc *pure_virtuals;
  tree friend_classes;
  VEC_tree_gc * methods;
  tree key_method;
  tree decl_list;
  tree template_info;
  tree befriending_classes;



  tree objc_info;


  struct sorted_fields_type *
    sorted_fields;

  tree lambda_expr;
};

struct lang_type_ptrmem {
  struct lang_type_header h;
  tree record;
};

struct lang_type {
  union lang_type_u
  {
    struct lang_type_header h;
    struct lang_type_class c;
    struct lang_type_ptrmem ptrmem;
  } u;
};
# 1866 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
struct lang_decl_base {
  unsigned selector : 16;
  enum languages language : 4;
  unsigned use_template : 2;
  unsigned not_really_extern : 1;
  unsigned initialized_in_class : 1;
  unsigned repo_available_p : 1;
  unsigned threadprivate_or_deleted_p : 1;
  unsigned anticipated_p : 1;
  unsigned friend_attr : 1;
  unsigned template_conv_p : 1;
  unsigned odr_used : 1;
  unsigned u2sel : 1;

};
# 1894 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
struct lang_decl_min {
  struct lang_decl_base base;






  tree template_info;

  union lang_decl_u2 {



    tree access;


    int discriminator;
  } u2;
};



struct lang_decl_fn {
  struct lang_decl_min min;



  enum tree_code operator_code : 16;

  unsigned global_ctor_p : 1;
  unsigned global_dtor_p : 1;
  unsigned constructor_attr : 1;
  unsigned destructor_attr : 1;
  unsigned assignment_operator_p : 1;
  unsigned static_function : 1;
  unsigned pure_virtual : 1;
  unsigned defaulted_p : 1;

  unsigned has_in_charge_parm_p : 1;
  unsigned has_vtt_parm_p : 1;
  unsigned pending_inline_p : 1;
  unsigned nonconverting : 1;
  unsigned thunk_p : 1;
  unsigned this_thunk_p : 1;
  unsigned hidden_friend_p : 1;





  tree befriending_classes;







  tree context;

  union lang_decl_u5
  {


    tree cloned_function;



    long fixed_offset;
  } u5;

  union lang_decl_u3
  {
    struct cp_token_cache * pending_inline_info;
    struct language_function *
      saved_language_function;
  } u;

};



struct lang_decl_ns {
  struct lang_decl_base base;
  cp_binding_level *level;
};



struct lang_decl_parm {
  struct lang_decl_base base;
  int level;
  int index;
};





struct lang_decl {
  union lang_decl_u {
    struct lang_decl_base base;
    struct lang_decl_min min;
    struct lang_decl_fn fn;
    struct lang_decl_ns ns;
    struct lang_decl_parm parm;
  } u;
};
# 2517 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
extern tree decl_shadowed_for_var_lookup (tree);
extern void decl_shadowed_for_var_insert (tree, tree);
# 2962 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
typedef struct aggr_init_expr_arg_iterator_d {
  tree t;
  int n;
  int i;
} aggr_init_expr_arg_iterator;



static inline void
init_aggr_init_expr_arg_iterator (tree exp,
           aggr_init_expr_arg_iterator *iter)
{
  iter->t = exp;
  iter->n = (((int)((((exp)->exp.operands[0])->int_cst.int_cst).low)) - 3);
  iter->i = 0;
}



static inline tree
next_aggr_init_expr_arg (aggr_init_expr_arg_iterator *iter)
{
  tree result;
  if (iter->i >= iter->n)
    return (tree) __null;
  result = (((iter->t))->exp.operands[(iter->i) + 3]);
  iter->i++;
  return result;
}





static inline tree
first_aggr_init_expr_arg (tree exp, aggr_init_expr_arg_iterator *iter)
{
  init_aggr_init_expr_arg_iterator (exp, iter);
  return next_aggr_init_expr_arg (iter);
}



static inline bool
more_aggr_init_expr_args_p (const aggr_init_expr_arg_iterator *iter)
{
  return (iter->i < iter->n);
}
# 4026 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
enum tag_types {
  none_type = 0,
  record_type,
  class_type,
  union_type,
  enum_type,
  typename_type
};


enum cp_lvalue_kind_flags {
  clk_none = 0,
  clk_ordinary = 1,
  clk_rvalueref = 2,
  clk_class = 4,
  clk_bitfield = 8,
  clk_packed = 16
};



typedef int cp_lvalue_kind;


typedef enum tmpl_spec_kind {
  tsk_none,
  tsk_invalid_member_spec,



  tsk_invalid_expl_inst,

  tsk_excessive_parms,

  tsk_insufficient_parms,

  tsk_template,
  tsk_expl_spec,
  tsk_expl_inst
} tmpl_spec_kind;





typedef enum access_kind {
  ak_none = 0,
  ak_public = 1,
  ak_protected = 2,
  ak_private = 3
} access_kind;



typedef enum special_function_kind {
  sfk_none = 0,


  sfk_constructor,
  sfk_copy_constructor,
  sfk_move_constructor,
  sfk_copy_assignment,
  sfk_move_assignment,
  sfk_destructor,
  sfk_complete_destructor,
  sfk_base_destructor,
  sfk_deleting_destructor,


  sfk_conversion
} special_function_kind;
# 4115 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
typedef enum linkage_kind {
  lk_none,
  lk_internal,
  lk_external
} linkage_kind;

typedef enum duration_kind {
  dk_static,
  dk_thread,
  dk_auto,
  dk_dynamic
} duration_kind;


enum tsubst_flags {
  tf_none = 0,
  tf_error = 1 << 0,
  tf_warning = 1 << 1,
  tf_ignore_bad_quals = 1 << 2,
  tf_keep_type_decl = 1 << 3,

  tf_ptrmem_ok = 1 << 4,

  tf_user = 1 << 5,

  tf_conv = 1 << 6,



  tf_no_access_control = 1 << 7,


  tf_warning_or_error = tf_warning | tf_error
};



typedef int tsubst_flags_t;


enum base_access_flags {
  ba_any = 0,

  ba_unique = 1 << 0,
  ba_check_bit = 1 << 1,
  ba_check = ba_unique | ba_check_bit,
  ba_ignore_scope = 1 << 2,
  ba_quiet = 1 << 3
};



typedef int base_access;


typedef enum deferring_kind {
  dk_no_deferred = 0,
  dk_deferred = 1,
  dk_no_check = 2
} deferring_kind;



typedef enum base_kind {
  bk_inaccessible = -3,
  bk_ambig = -2,
  bk_not_base = -1,
  bk_same_type = 0,
  bk_proper_base = 1,
  bk_via_virtual = 2


} base_kind;







extern tree integer_two_node;




extern int function_depth;







extern int cp_unevaluated_operand;
extern tree cp_convert_range_for (tree, tree, tree);







typedef enum unification_kind_t {
  DEDUCE_CALL,
  DEDUCE_CONV,
  DEDUCE_EXACT
} unification_kind_t;



extern int current_class_depth;



extern VEC_tree_gc *local_classes;
# 4340 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
extern int at_eof;





extern tree static_aggregates;

enum overload_flags { NO_SPECIAL = 0, DTOR_FLAG, TYPENAME_FLAG };
# 4583 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h"
extern void init_reswords (void);

typedef struct operator_name_info_t {

  tree identifier;

  const char *name;

  const char *mangled_name;

  int arity;
} operator_name_info_t;


extern operator_name_info_t operator_name_info
  [(int) MAX_TREE_CODES];

extern operator_name_info_t assignment_operator_name_info
  [(int) MAX_TREE_CODES];




typedef int cp_cv_quals;





enum virt_specifier
  {
    VIRT_SPEC_UNSPECIFIED = 0x0,
    VIRT_SPEC_FINAL = 0x1,
    VIRT_SPEC_OVERRIDE = 0x2
  };




typedef int cp_virt_specifiers;



typedef enum cp_storage_class {


  sc_none = 0,
  sc_auto,
  sc_register,
  sc_static,
  sc_extern,
  sc_mutable
} cp_storage_class;



typedef enum cp_decl_spec {
  ds_first,
  ds_signed = ds_first,
  ds_unsigned,
  ds_short,
  ds_long,
  ds_const,
  ds_volatile,
  ds_restrict,
  ds_inline,
  ds_virtual,
  ds_explicit,
  ds_friend,
  ds_typedef,
  ds_alias,
  ds_constexpr,
  ds_complex,
  ds_thread,
  ds_last
} cp_decl_spec;



typedef struct cp_decl_specifier_seq {

  unsigned specs[(int) ds_last];


  location_t type_location;




  tree type;

  tree attributes;


  tree redefined_builtin_type;


  cp_storage_class storage_class;

  unsigned int type_definition_p : 1;


  unsigned int multiple_types_p : 1;



  unsigned int conflicting_specifiers_p : 1;

  unsigned int any_specifiers_p : 1;

  unsigned int any_type_specifiers_p : 1;

  unsigned int explicit_int_p : 1;

  unsigned int explicit_int128_p : 1;

  unsigned int explicit_char_p : 1;
} cp_decl_specifier_seq;



typedef enum cp_declarator_kind {
  cdk_id,
  cdk_function,
  cdk_array,
  cdk_pointer,
  cdk_reference,
  cdk_ptrmem,
  cdk_error
} cp_declarator_kind;



typedef struct cp_declarator cp_declarator;

typedef struct cp_parameter_declarator cp_parameter_declarator;


struct cp_parameter_declarator {

  cp_parameter_declarator *next;

  cp_decl_specifier_seq decl_specifiers;

  cp_declarator *declarator;

  tree default_argument;


  bool ellipsis_p;
};


struct cp_declarator {

  enum cp_declarator_kind kind : 4;


  unsigned int parameter_pack_p : 1;
  location_t id_loc;

  tree attributes;


  cp_declarator *declarator;
  union {

    struct {


      tree qualifying_scope;


      tree unqualified_name;


      special_function_kind sfk;
    } id;

    struct {

      tree parameters;

      cp_cv_quals qualifiers;

      cp_virt_specifiers virt_specifiers;

      tree exception_specification;

      tree late_return_type;
    } function;

    struct {

      tree bounds;
    } array;

    struct {

      cp_cv_quals qualifiers;

      tree class_type;
    } pointer;

    struct {


      cp_cv_quals qualifiers;

      bool rvalue_ref;
    } reference;
  } u;
};


struct tinst_level {

  struct tinst_level *next;




  tree decl;


  location_t locus;


  int errors;


  bool in_system_header_p;
};



static inline tree
type_of_this_parm (const_tree fntype)
{
  function_args_iterator iter;
  ((void)(!(((enum tree_code) (fntype)->base.code) == METHOD_TYPE) ? fancy_abort ("/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/cp/cp-tree.h", 4823, __FUNCTION__), 0 : 0));
  function_args_iter_init (&iter, fntype);
  return function_args_iter_cond (&iter);
}



static inline tree
class_of_this_parm (const_tree fntype)
{
  return ((type_of_this_parm (fntype))->typed.type);
}



extern cp_parameter_declarator *no_parameters;


extern bool pragma_java_exceptions;


extern bool check_dtor_name (tree, tree);

extern tree build_conditional_expr (tree, tree, tree,
                                                 tsubst_flags_t);
extern tree build_addr_func (tree);
extern void set_flags_from_callee (tree);
extern tree build_call_a (tree, int, tree*);
extern tree build_call_n (tree, int, ...);
extern bool null_ptr_cst_p (tree);
extern bool null_member_pointer_value_p (tree);
extern bool sufficient_parms_p (const_tree);
extern tree type_decays_to (tree);
extern tree build_user_type_conversion (tree, tree, int);
extern tree build_new_function_call (tree, VEC_tree_gc **, bool,
       tsubst_flags_t);
extern tree build_operator_new_call (tree, VEC_tree_gc **, tree *,
       tree *, tree *);
extern tree build_new_method_call (tree, tree, VEC_tree_gc **,
       tree, int, tree *,
       tsubst_flags_t);
extern tree build_special_member_call (tree, tree, VEC_tree_gc **,
       tree, int, tsubst_flags_t);
extern tree build_new_op (enum tree_code, int, tree,
       tree, tree, tree *,
       tsubst_flags_t);
extern tree build_op_call (tree, VEC_tree_gc **,
       tsubst_flags_t);
extern tree build_op_delete_call (enum tree_code, tree, tree, bool, tree, tree);
extern bool can_convert (tree, tree);
extern bool can_convert_arg (tree, tree, tree, int);
extern bool can_convert_arg_bad (tree, tree, tree, int);
extern bool enforce_access (tree, tree, tree);
extern void push_defarg_context (tree);
extern void pop_defarg_context (void);
extern tree convert_default_arg (tree, tree, tree, int);
extern tree convert_arg_to_ellipsis (tree);
extern tree build_x_va_arg (tree, tree);
extern tree cxx_type_promotes_to (tree);
extern tree type_passed_as (tree);
extern tree convert_for_arg_passing (tree, tree);
extern bool is_properly_derived_from (tree, tree);
extern tree initialize_reference (tree, tree, int,
       tsubst_flags_t);
extern tree extend_ref_init_temps (tree, tree, VEC_tree_gc**);
extern tree make_temporary_var_for_ref_to_temp (tree, tree);
extern tree strip_top_quals (tree);
extern bool reference_related_p (tree, tree);
extern tree perform_implicit_conversion (tree, tree, tsubst_flags_t);
extern tree perform_implicit_conversion_flags (tree, tree, tsubst_flags_t, int);
extern tree build_integral_nontype_arg_conv (tree, tree, tsubst_flags_t);
extern tree perform_direct_initialization_if_possible (tree, tree, bool,
                                                       tsubst_flags_t);
extern tree in_charge_arg_for_name (tree);
extern tree build_cxx_call (tree, int, tree *);
extern bool is_std_init_list (tree);
extern bool is_list_ctor (tree);





extern tree build_vfield_ref (tree, tree);
extern tree build_base_path (enum tree_code, tree,
       tree, int, tsubst_flags_t);
extern tree convert_to_base (tree, tree, bool, bool,
       tsubst_flags_t);
extern tree convert_to_base_statically (tree, tree);
extern tree build_vtbl_ref (tree, tree);
extern tree build_vfn_ref (tree, tree);
extern tree get_vtable_decl (tree, int);
extern void resort_type_method_vec (void *, void *,
       gt_pointer_operator, void *);
extern bool add_method (tree, tree, tree);
extern bool currently_open_class (tree);
extern tree currently_open_derived_class (tree);
extern tree current_nonlambda_class_type (void);
extern tree finish_struct (tree, tree);
extern void finish_struct_1 (tree);
extern int resolves_to_fixed_type_p (tree, int *);
extern void init_class_processing (void);
extern int is_empty_class (tree);
extern bool is_really_empty_class (tree);
extern void pushclass (tree);
extern void popclass (void);
extern void push_nested_class (tree);
extern void pop_nested_class (void);
extern int current_lang_depth (void);
extern void push_lang_context (tree);
extern void pop_lang_context (void);
extern tree instantiate_type (tree, tree, tsubst_flags_t);
extern void print_class_statistics (void);
extern void build_self_reference (void);
extern int same_signature_p (const_tree, const_tree);
extern void maybe_add_class_template_decl_list (tree, tree, int);
extern void unreverse_member_declarations (tree);
extern void invalidate_class_lookup_cache (void);
extern void maybe_note_name_used_in_class (tree, tree);
extern void note_name_declared_in_class (tree, tree);
extern tree get_vtbl_decl_for_binfo (tree);
extern void debug_class (tree);
extern void debug_thunks (tree);
extern void set_linkage_according_to_type (tree, tree);
extern void determine_key_method (tree);
extern void check_for_override (tree, tree);
extern void push_class_stack (void);
extern void pop_class_stack (void);
extern bool type_has_user_nondefault_constructor (tree);
extern tree in_class_defaulted_default_constructor (tree);
extern bool user_provided_p (tree);
extern bool type_has_user_provided_constructor (tree);
extern bool type_has_user_provided_default_constructor (tree);
extern tree default_init_uninitialized_part (tree);
extern bool trivial_default_constructor_is_constexpr (tree);
extern bool type_has_constexpr_default_constructor (tree);
extern bool type_has_virtual_destructor (tree);
extern bool type_has_move_constructor (tree);
extern bool type_has_move_assign (tree);
extern bool type_has_user_declared_move_constructor (tree);
extern bool type_has_user_declared_move_assign(tree);
extern bool type_build_ctor_call (tree);
extern void explain_non_literal_class (tree);
extern void defaulted_late_check (tree);
extern bool defaultable_fn_check (tree);
extern void fixup_type_variants (tree);
extern void fixup_attribute_variants (tree);
extern tree* decl_cloned_function_p (const_tree, bool);
extern void clone_function_decl (tree, int);
extern void adjust_clone_args (tree);


extern tree convert_to_reference (tree, tree, int, int, tree);
extern tree convert_from_reference (tree);
extern tree force_rvalue (tree, tsubst_flags_t);
extern tree ocp_convert (tree, tree, int, int);
extern tree cp_convert (tree, tree);
extern tree cp_convert_and_check (tree, tree);
extern tree cp_fold_convert (tree, tree);
extern tree convert_to_void (tree, impl_conv_void,
                                    tsubst_flags_t);
extern tree convert_force (tree, tree, int);
extern tree build_expr_type_conversion (int, tree, bool);
extern tree type_promotes_to (tree);
extern tree perform_qualification_conversions (tree, tree);


extern tree pushdecl (tree);
extern tree pushdecl_maybe_friend (tree, bool);
extern void maybe_push_cleanup_level (tree);
extern tree pushtag (tree, tree, tag_scope);
extern tree make_anon_name (void);
extern tree pushdecl_top_level_maybe_friend (tree, bool);
extern tree pushdecl_top_level_and_finish (tree, tree);
extern tree check_for_out_of_scope_variable (tree);
extern void print_other_binding_stack (cp_binding_level *);
extern tree maybe_push_decl (tree);
extern tree current_decl_namespace (void);


extern tree poplevel (int, int, int);
extern void cxx_init_decl_processing (void);
enum cp_tree_node_structure_enum cp_tree_node_structure
      (union lang_tree_node *);
extern void finish_scope (void);
extern void push_switch (tree);
extern void pop_switch (void);
extern tree make_lambda_name (void);
extern int decls_match (tree, tree);
extern tree duplicate_decls (tree, tree, bool);
extern tree declare_local_label (tree);
extern tree define_label (location_t, tree);
extern void check_goto (tree);
extern bool check_omp_return (void);
extern tree make_typename_type (tree, tree, enum tag_types, tsubst_flags_t);
extern tree make_unbound_class_template (tree, tree, tree, tsubst_flags_t);
extern tree build_library_fn_ptr (const char *, tree);
extern tree build_cp_library_fn_ptr (const char *, tree);
extern tree push_library_fn (tree, tree, tree);
extern tree push_void_library_fn (tree, tree);
extern tree push_throw_library_fn (tree, tree);
extern tree check_tag_decl (cp_decl_specifier_seq *);
extern tree shadow_tag (cp_decl_specifier_seq *);
extern tree groktypename (cp_decl_specifier_seq *, const cp_declarator *, bool);
extern tree start_decl (const cp_declarator *, cp_decl_specifier_seq *, int, tree, tree, tree *);
extern void start_decl_1 (tree, bool);
extern bool check_array_initializer (tree, tree, tree);
extern void cp_finish_decl (tree, tree, bool, tree, int);
extern int cp_complete_array_type (tree *, tree, bool);
extern int cp_complete_array_type_or_error (tree *, tree, bool, tsubst_flags_t);
extern tree build_ptrmemfunc_type (tree);
extern tree build_ptrmem_type (tree, tree);

extern tree build_this_parm (tree, cp_cv_quals);
extern int copy_fn_p (const_tree);
extern bool move_fn_p (const_tree);
extern tree get_scope_of_declarator (const cp_declarator *);
extern void grok_special_member_properties (tree);
extern int grok_ctor_properties (const_tree, const_tree);
extern bool grok_op_properties (tree, bool);
extern tree xref_tag (enum tag_types, tree, tag_scope, bool);
extern tree xref_tag_from_type (tree, tree, tag_scope);
extern bool xref_basetypes (tree, tree);
extern tree start_enum (tree, tree, tree, bool, bool *);
extern void finish_enum_value_list (tree);
extern void finish_enum (tree);
extern void build_enumerator (tree, tree, tree, location_t);
extern tree lookup_enumerator (tree, tree);
extern void start_preparsed_function (tree, tree, int);
extern int start_function (cp_decl_specifier_seq *, const cp_declarator *, tree);
extern tree begin_function_body (void);
extern void finish_function_body (tree);
extern tree outer_curly_brace_block (tree);
extern tree finish_function (int);
extern tree grokmethod (cp_decl_specifier_seq *, const cp_declarator *, tree);
extern void maybe_register_incomplete_var (tree);
extern void maybe_commonize_var (tree);
extern void complete_vars (tree);
extern void finish_stmt (void);
extern tree static_fn_type (tree);
extern void revert_static_member_fn (tree);
extern void fixup_anonymous_aggr (tree);
extern tree compute_array_index_type (tree, tree, tsubst_flags_t);
extern tree check_default_argument (tree, tree);
typedef int (*walk_namespaces_fn) (tree, void *);
extern int walk_namespaces (walk_namespaces_fn,
       void *);
extern int wrapup_globals_for_namespace (tree, void *);
extern tree create_implicit_typedef (tree, tree);
extern int local_variable_p (const_tree);
extern tree register_dtor_fn (tree);
extern tmpl_spec_kind current_tmpl_spec_kind (int);
extern tree cp_fname_init (const char *, tree *);
extern tree cxx_builtin_function (tree decl);
extern tree cxx_builtin_function_ext_scope (tree decl);
extern tree check_elaborated_type_specifier (enum tag_types, tree, bool);
extern void warn_extern_redeclared_static (tree, tree);
extern tree cxx_comdat_group (tree);
extern bool cp_missing_noreturn_ok_p (tree);
extern void initialize_artificial_var (tree, VEC_constructor_elt_gc *);
extern tree check_var_type (tree, tree);
extern tree reshape_init (tree, tree, tsubst_flags_t);
extern tree next_initializable_field (tree);

extern bool defer_mark_used_calls;
extern VEC_tree_gc *deferred_mark_used_calls;
extern tree finish_case_label (location_t, tree, tree);
extern tree cxx_maybe_build_cleanup (tree, tsubst_flags_t);


extern bool check_java_method (tree);
extern tree build_memfn_type (tree, tree, cp_cv_quals);
extern tree change_return_type (tree, tree);
extern void maybe_retrofit_in_chrg (tree);
extern void maybe_make_one_only (tree);
extern bool vague_linkage_p (tree);
extern void grokclassfn (tree, tree,
       enum overload_flags);
extern tree grok_array_decl (tree, tree);
extern tree delete_sanity (tree, tree, bool, int, tsubst_flags_t);
extern tree check_classfn (tree, tree, tree);
extern void check_member_template (tree);
extern tree grokfield (const cp_declarator *, cp_decl_specifier_seq *,
         tree, bool, tree, tree);
extern tree grokbitfield (const cp_declarator *, cp_decl_specifier_seq *,
     tree, tree);
extern tree cp_reconstruct_complex_type (tree, tree);
extern void cplus_decl_attributes (tree *, tree, int);
extern void finish_anon_union (tree);
extern void cp_write_global_declarations (void);
extern tree coerce_new_type (tree);
extern tree coerce_delete_type (tree);
extern void comdat_linkage (tree);
extern void determine_visibility (tree);
extern void constrain_class_visibility (tree);
extern void import_export_decl (tree);
extern tree build_cleanup (tree);
extern tree build_offset_ref_call_from_tree (tree, VEC_tree_gc **);
extern bool decl_constant_var_p (tree);
extern bool decl_maybe_constant_var_p (tree);
extern void check_default_args (tree);
extern bool mark_used (tree);
extern void finish_static_data_member_decl (tree, tree, bool, tree, int);
extern tree cp_build_parm_decl (tree, tree);
extern tree get_guard (tree);
extern tree get_guard_cond (tree);
extern tree set_guard (tree);
extern tree cxx_callgraph_analyze_expr (tree *, int *);
extern void mark_needed (tree);
extern bool decl_needed_p (tree);
extern void note_vague_linkage_fn (tree);
extern tree build_artificial_parm (tree, tree);
extern bool possibly_inlined_p (tree);
extern int parm_index (tree);


extern void init_error (void);
extern const char *type_as_string (tree, int);
extern const char *type_as_string_translate (tree, int);
extern const char *decl_as_string (tree, int);
extern const char *decl_as_string_translate (tree, int);
extern const char *expr_as_string (tree, int);
extern const char *lang_decl_name (tree, int, bool);
extern const char *language_to_string (enum languages);
extern const char *class_key_or_enum_as_string (tree);
extern void print_instantiation_context (void);
extern void maybe_warn_variadic_templates (void);
extern void maybe_warn_cpp0x (cpp0x_warn_str str);
extern bool pedwarn_cxx98 (location_t, int, const char *, ...) __attribute__ ((__format__ (__gcc_cxxdiag__, 3, 4))) __attribute__ ((__nonnull__ (3)));
extern location_t location_of (tree);
extern void qualified_name_lookup_error (tree, tree, tree,
       location_t);


extern void init_exception_processing (void);
extern tree expand_start_catch_block (tree);
extern void expand_end_catch_block (void);
extern tree build_exc_ptr (void);
extern tree build_throw (tree);
extern int nothrow_libfn_p (const_tree);
extern void check_handlers (tree);
extern tree finish_noexcept_expr (tree, tsubst_flags_t);
extern bool expr_noexcept_p (tree, tsubst_flags_t);
extern void perform_deferred_noexcept_checks (void);
extern bool nothrow_spec_p (const_tree);
extern bool type_noexcept_p (const_tree);
extern bool type_throw_all_p (const_tree);
extern tree build_noexcept_spec (tree, int);
extern void choose_personality_routine (enum languages);
extern tree build_must_not_throw_expr (tree,tree);
extern tree eh_type_info (tree);
extern tree begin_eh_spec_block (void);
extern void finish_eh_spec_block (tree, tree);
extern tree build_eh_type_type (tree);
extern tree cp_protect_cleanup_actions (void);


extern tree cplus_expand_constant (tree);
extern tree mark_rvalue_use (tree);
extern tree mark_lvalue_use (tree);
extern tree mark_type_use (tree);
extern void mark_exp_read (tree);


extern int is_friend (tree, tree);
extern void make_friend_class (tree, tree, bool);
extern void add_friend (tree, tree, bool);
extern tree do_friend (tree, tree, tree, tree, enum overload_flags, bool);


extern tree expand_member_init (tree);
extern void emit_mem_initializers (tree);
extern tree build_aggr_init (tree, tree, int,
                                                 tsubst_flags_t);
extern int is_class_type (tree, int);
extern tree get_type_value (tree);
extern tree build_zero_init (tree, tree, bool);
extern tree build_value_init (tree, tsubst_flags_t);
extern tree build_value_init_noctor (tree, tsubst_flags_t);
extern tree build_offset_ref (tree, tree, bool);
extern tree build_new (VEC_tree_gc **, tree, tree,
       VEC_tree_gc **, int,
                                                 tsubst_flags_t);
extern tree get_temp_regvar (tree, tree);
extern tree build_vec_init (tree, tree, tree, bool, int,
                                                 tsubst_flags_t);
extern tree build_delete (tree, tree,
       special_function_kind,
       int, int, tsubst_flags_t);
extern void push_base_cleanups (void);
extern tree build_vec_delete (tree, tree,
       special_function_kind, int,
       tsubst_flags_t);
extern tree create_temporary_var (tree);
extern void initialize_vtbl_ptrs (tree);
extern tree build_java_class_ref (tree);
extern tree integral_constant_value (tree);
extern tree decl_constant_value_safe (tree);
extern int diagnose_uninitialized_cst_or_ref_member (tree, bool, bool);


extern void cxx_dup_lang_specific_decl (tree);
extern void yyungetc (int, int);

extern tree unqualified_name_lookup_error (tree);
extern tree unqualified_fn_lookup_error (tree);
extern tree build_lang_decl (enum tree_code, tree, tree);
extern tree build_lang_decl_loc (location_t, enum tree_code, tree, tree);
extern void retrofit_lang_decl (tree);
extern tree copy_decl (tree);
extern tree copy_type (tree);
extern tree cxx_make_type (enum tree_code);
extern tree make_class_type (enum tree_code);
extern bool cxx_init (void);
extern void cxx_finish (void);
extern bool in_main_input_context (void);


extern void init_method (void);
extern tree make_thunk (tree, bool, tree, tree);
extern void finish_thunk (tree);
extern void use_thunk (tree, bool);
extern bool trivial_fn_p (tree);
extern bool maybe_explain_implicit_delete (tree);
extern void explain_implicit_non_constexpr (tree);
extern void synthesize_method (tree);
extern tree lazily_declare_fn (special_function_kind,
       tree);
extern tree skip_artificial_parms_for (const_tree, tree);
extern int num_artificial_parms_for (const_tree);
extern tree make_alias_for (tree, tree);
extern tree get_copy_ctor (tree, tsubst_flags_t);
extern tree get_copy_assign (tree);
extern tree get_default_ctor (tree);
extern tree get_dtor (tree, tsubst_flags_t);
extern tree locate_ctor (tree);


extern bool maybe_clone_body (tree);


extern bool check_template_shadow (tree);
extern tree get_innermost_template_args (tree, int);
extern void maybe_begin_member_template_processing (tree);
extern void maybe_end_member_template_processing (void);
extern tree finish_member_template_decl (tree);
extern void begin_template_parm_list (void);
extern bool begin_specialization (void);
extern void reset_specialization (void);
extern void end_specialization (void);
extern void begin_explicit_instantiation (void);
extern void end_explicit_instantiation (void);
extern tree check_explicit_specialization (tree, tree, int, int);
extern tree make_auto (void);
extern tree do_auto_deduction (tree, tree, tree);
extern tree type_uses_auto (tree);
extern void append_type_to_template_for_access_check (tree, tree, tree,
            location_t);
extern tree splice_late_return_type (tree, tree);
extern bool is_auto (const_tree);
extern tree process_template_parm (tree, location_t, tree,
       bool, bool, unsigned);
extern tree end_template_parm_list (tree);
void fixup_template_parms (void);
extern void end_template_decl (void);
extern tree maybe_update_decl_type (tree, tree);
extern bool check_default_tmpl_args (tree, tree, int, int, int);
extern tree push_template_decl (tree);
extern tree push_template_decl_real (tree, bool);
extern bool redeclare_class_template (tree, tree);
extern tree lookup_template_class (tree, tree, tree, tree,
       int, tsubst_flags_t);
extern tree lookup_template_function (tree, tree);
extern int uses_template_parms (tree);
extern int uses_template_parms_level (tree, int);
extern tree instantiate_class_template (tree);
extern tree instantiate_template (tree, tree, tsubst_flags_t);
extern int fn_type_unification (tree, tree, tree,
       const tree *, unsigned int,
       tree, unification_kind_t, int,
       bool);
extern void mark_decl_instantiated (tree, int);
extern int more_specialized_fn (tree, tree, int);
extern void do_decl_instantiation (tree, tree);
extern void do_type_instantiation (tree, tree, tsubst_flags_t);
extern bool always_instantiate_p (tree);
extern void maybe_instantiate_noexcept (tree);
extern tree instantiate_decl (tree, int, bool);
extern int comp_template_parms (const_tree, const_tree);
extern bool uses_parameter_packs (tree);
extern bool template_parameter_pack_p (const_tree);
extern bool function_parameter_pack_p (const_tree);
extern bool function_parameter_expanded_from_pack_p (tree, tree);
extern tree make_pack_expansion (tree);
extern bool check_for_bare_parameter_packs (tree);
extern tree build_template_info (tree, tree);
extern tree get_template_info (const_tree);
extern VEC_qualified_typedef_usage_t_gc* get_types_needing_access_check (tree);
extern int template_class_depth (tree);
extern int is_specialization_of (tree, tree);
extern bool is_specialization_of_friend (tree, tree);
extern tree get_pattern_parm (tree, tree);
extern int comp_template_args (tree, tree);
extern tree maybe_process_partial_specialization (tree);
extern tree most_specialized_instantiation (tree);
extern void print_candidates (tree);
extern void instantiate_pending_templates (int);
extern tree tsubst_default_argument (tree, tree, tree);
extern tree tsubst (tree, tree, tsubst_flags_t, tree);
extern tree tsubst_copy_and_build (tree, tree, tsubst_flags_t,
       tree, bool, bool);
extern tree most_general_template (tree);
extern tree get_mostly_instantiated_function_type (tree);
extern int problematic_instantiation_changed (void);
extern void record_last_problematic_instantiation (void);
extern struct tinst_level *current_instantiation(void);
extern tree maybe_get_template_decl_from_type_decl (tree);
extern int processing_template_parmlist;
extern bool dependent_type_p (tree);
extern bool dependent_scope_p (tree);
extern bool any_dependent_template_arguments_p (const_tree);
extern bool dependent_template_p (tree);
extern bool dependent_template_id_p (tree, tree);
extern bool type_dependent_expression_p (tree);
extern bool any_type_dependent_arguments_p (const VEC_tree_gc *);
extern bool any_type_dependent_elements_p (const_tree);
extern bool type_dependent_expression_p_push (tree);
extern bool value_dependent_expression_p (tree);
extern bool any_value_dependent_elements_p (const_tree);
extern bool dependent_omp_for_p (tree, tree, tree, tree);
extern tree resolve_typename_type (tree, bool);
extern tree template_for_substitution (tree);
extern tree build_non_dependent_expr (tree);
extern void make_args_non_dependent (VEC_tree_gc *);
extern bool reregister_specialization (tree, tree, tree);
extern tree fold_non_dependent_expr (tree);
extern bool alias_type_or_template_p (tree);
extern bool alias_template_specialization_p (tree);
extern bool explicit_class_specialization_p (tree);
extern int push_tinst_level (tree);
extern void pop_tinst_level (void);
extern struct tinst_level *outermost_tinst_level(void);
extern bool parameter_of_template_p (tree, tree);
extern void init_template_processing (void);
extern void print_template_statistics (void);
bool template_template_parameter_p (const_tree);
extern bool primary_template_instantiation_p (const_tree);
extern tree get_primary_template_innermost_parameters (const_tree);
extern tree get_template_parms_at_level (tree, int);
extern tree get_template_innermost_arguments (const_tree);
extern tree get_template_argument_pack_elems (const_tree);
extern tree get_function_template_decl (const_tree);
extern tree resolve_nondeduced_context (tree);
extern hashval_t iterative_hash_template_arg (tree arg, hashval_t val);


extern void init_repo (void);
extern int repo_emit_p (tree);
extern bool repo_export_class_p (const_tree);
extern void finish_repo (void);



extern VEC_tree_gc *unemitted_tinfo_decls;

extern void init_rtti_processing (void);
extern tree build_typeid (tree);
extern tree get_tinfo_decl (tree);
extern tree get_typeid (tree);
extern tree build_headof (tree);
extern tree build_dynamic_cast (tree, tree, tsubst_flags_t);
extern void emit_support_tinfos (void);
extern bool emit_tinfo_decl (tree);


extern bool accessible_base_p (tree, tree, bool);
extern tree lookup_base (tree, tree, base_access,
       base_kind *);
extern tree dcast_base_hint (tree, tree);
extern int accessible_p (tree, tree, bool);
extern tree lookup_field_1 (tree, tree, bool);
extern tree lookup_field (tree, tree, int, bool);
extern int lookup_fnfields_1 (tree, tree);
extern tree lookup_fnfields_slot (tree, tree);
extern tree lookup_fnfields_slot_nolazy (tree, tree);
extern int class_method_index_for_fn (tree, tree);
extern tree lookup_fnfields (tree, tree, int);
extern tree lookup_member (tree, tree, int, bool,
       tsubst_flags_t);
extern int look_for_overrides (tree, tree);
extern void get_pure_virtuals (tree);
extern void maybe_suppress_debug_info (tree);
extern void note_debug_info_needed (tree);
extern void print_search_statistics (void);
extern void reinit_search_statistics (void);
extern tree current_scope (void);
extern int at_function_scope_p (void);
extern bool at_class_scope_p (void);
extern bool at_namespace_scope_p (void);
extern tree context_for_name_lookup (tree);
extern tree lookup_conversions (tree);
extern tree binfo_from_vbase (tree);
extern tree binfo_for_vbase (tree, tree);
extern tree look_for_overrides_here (tree, tree);

extern tree dfs_walk_all (tree, tree (*) (tree, void *),
     tree (*) (tree, void *), void *);
extern tree dfs_walk_once (tree, tree (*) (tree, void *),
      tree (*) (tree, void *), void *);
extern tree binfo_via_virtual (tree, tree);
extern tree build_baselink (tree, tree, tree, tree);
extern tree adjust_result_of_qualified_name_lookup
      (tree, tree, tree);
extern tree copied_binfo (tree, tree);
extern tree original_binfo (tree, tree);
extern int shared_member_p (tree);




typedef struct deferred_access_check {

  tree binfo;

  tree decl;

  tree diag_decl;
} deferred_access_check;
typedef struct VEC_deferred_access_check_base { struct vec_prefix prefix; deferred_access_check vec[1]; } VEC_deferred_access_check_base; typedef struct VEC_deferred_access_check_none { VEC_deferred_access_check_base base; } VEC_deferred_access_check_none; static inline unsigned VEC_deferred_access_check_base_length (const VEC_deferred_access_check_base *vec_) { return vec_ ? vec_->prefix.num : 0; } static inline deferred_access_check *VEC_deferred_access_check_base_last (VEC_deferred_access_check_base *vec_ ) { (void)(vec_ && vec_->prefix.num); return &vec_->vec[vec_->prefix.num - 1]; } static inline deferred_access_check *VEC_deferred_access_check_base_index (VEC_deferred_access_check_base *vec_, unsigned ix_ ) { (void)(vec_ && ix_ < vec_->prefix.num); return &vec_->vec[ix_]; } static inline int VEC_deferred_access_check_base_iterate (VEC_deferred_access_check_base *vec_, unsigned ix_, deferred_access_check **ptr) { if (vec_ && ix_ < vec_->prefix.num) { *ptr = &vec_->vec[ix_]; return 1; } else { *ptr = 0; return 0; } } static inline size_t VEC_deferred_access_check_base_embedded_size (int alloc_) { return __builtin_offsetof (VEC_deferred_access_check_base, vec) + alloc_ * sizeof(deferred_access_check); } static inline void VEC_deferred_access_check_base_embedded_init (VEC_deferred_access_check_base *vec_, int alloc_) { vec_->prefix.num = 0; vec_->prefix.alloc = alloc_; } static inline int VEC_deferred_access_check_base_space (VEC_deferred_access_check_base *vec_, int alloc_ ) { (void)(alloc_ >= 0); return vec_ ? vec_->prefix.alloc - vec_->prefix.num >= (unsigned)alloc_ : !alloc_; } static inline void VEC_deferred_access_check_base_splice (VEC_deferred_access_check_base *dst_, VEC_deferred_access_check_base *src_ ) { if (src_) { unsigned len_ = src_->prefix.num; (void)(dst_->prefix.num + len_ <= dst_->prefix.alloc); memcpy (&dst_->vec[dst_->prefix.num], &src_->vec[0], len_ * sizeof (deferred_access_check)); dst_->prefix.num += len_; } } static inline deferred_access_check *VEC_deferred_access_check_base_quick_push (VEC_deferred_access_check_base *vec_, const deferred_access_check *obj_ ) { deferred_access_check *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); slot_ = &vec_->vec[vec_->prefix.num++]; if (obj_) *slot_ = *obj_; return slot_; } static inline void VEC_deferred_access_check_base_pop (VEC_deferred_access_check_base *vec_ ) { (void)(vec_->prefix.num); --vec_->prefix.num; } static inline void VEC_deferred_access_check_base_truncate (VEC_deferred_access_check_base *vec_, unsigned size_ ) { (void)(vec_ ? vec_->prefix.num >= size_ : !size_); if (vec_) vec_->prefix.num = size_; } static inline deferred_access_check *VEC_deferred_access_check_base_replace (VEC_deferred_access_check_base *vec_, unsigned ix_, const deferred_access_check *obj_ ) { deferred_access_check *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; if (obj_) *slot_ = *obj_; return slot_; } static inline deferred_access_check *VEC_deferred_access_check_base_quick_insert (VEC_deferred_access_check_base *vec_, unsigned ix_, const deferred_access_check *obj_ ) { deferred_access_check *slot_; (void)(vec_->prefix.num < vec_->prefix.alloc); (void)(ix_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_ + 1, slot_, (vec_->prefix.num++ - ix_) * sizeof (deferred_access_check)); if (obj_) *slot_ = *obj_; return slot_; } static inline void VEC_deferred_access_check_base_ordered_remove (VEC_deferred_access_check_base *vec_, unsigned ix_ ) { deferred_access_check *slot_; (void)(ix_ < vec_->prefix.num); slot_ = &vec_->vec[ix_]; memmove (slot_, slot_ + 1, (--vec_->prefix.num - ix_) * sizeof (deferred_access_check)); } static inline void VEC_deferred_access_check_base_unordered_remove (VEC_deferred_access_check_base *vec_, unsigned ix_ ) { (void)(ix_ < vec_->prefix.num); vec_->vec[ix_] = vec_->vec[--vec_->prefix.num]; } static inline void VEC_deferred_access_check_base_block_remove (VEC_deferred_access_check_base *vec_, unsigned ix_, unsigned len_ ) { deferred_access_check *slot_; (void)(ix_ + len_ <= vec_->prefix.num); slot_ = &vec_->vec[ix_]; vec_->prefix.num -= len_; memmove (slot_, slot_ + len_, (vec_->prefix.num - ix_) * sizeof (deferred_access_check)); } static inline deferred_access_check *VEC_deferred_access_check_base_address (VEC_deferred_access_check_base *vec_) { return vec_ ? vec_->vec : 0; } static inline unsigned VEC_deferred_access_check_base_lower_bound (VEC_deferred_access_check_base *vec_, const deferred_access_check *obj_, bool (*lessthan_)(const deferred_access_check *, const deferred_access_check *) ) { unsigned int len_ = VEC_deferred_access_check_base_length (vec_); unsigned int half_, middle_; unsigned int first_ = 0; while (len_ > 0) { deferred_access_check *middle_elem_; half_ = len_ >> 1; middle_ = first_; middle_ += half_; middle_elem_ = VEC_deferred_access_check_base_index (vec_, middle_ ); if (lessthan_ (middle_elem_, obj_)) { first_ = middle_; ++first_; len_ = len_ - half_ - 1; } else len_ = half_; } return first_; } struct vec_swallow_trailing_semi;
typedef struct VEC_deferred_access_check_gc { VEC_deferred_access_check_base base; } VEC_deferred_access_check_gc; static inline VEC_deferred_access_check_gc *VEC_deferred_access_check_gc_alloc (int alloc_ ) { return (VEC_deferred_access_check_gc *) vec_gc_o_reserve_exact (__null, alloc_, __builtin_offsetof (VEC_deferred_access_check_gc, base.vec), sizeof (deferred_access_check) ); } static inline VEC_deferred_access_check_gc *VEC_deferred_access_check_gc_copy (VEC_deferred_access_check_base *vec_ ) { size_t len_ = vec_ ? vec_->prefix.num : 0; VEC_deferred_access_check_gc *new_vec_ = __null; if (len_) { new_vec_ = (VEC_deferred_access_check_gc *)(vec_gc_o_reserve_exact (__null, len_, __builtin_offsetof (VEC_deferred_access_check_gc, base.vec), sizeof (deferred_access_check) )); new_vec_->base.prefix.num = len_; memcpy (new_vec_->base.vec, vec_->vec, sizeof (deferred_access_check) * len_); } return new_vec_; } static inline void VEC_deferred_access_check_gc_free (VEC_deferred_access_check_gc **vec_) { if (*vec_) ggc_free (*vec_); *vec_ = __null; } static inline int VEC_deferred_access_check_gc_reserve (VEC_deferred_access_check_gc **vec_, int alloc_ ) { int extend = !VEC_deferred_access_check_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_deferred_access_check_gc *) vec_gc_o_reserve (*vec_, alloc_, __builtin_offsetof (VEC_deferred_access_check_gc, base.vec), sizeof (deferred_access_check) ); return extend; } static inline int VEC_deferred_access_check_gc_reserve_exact (VEC_deferred_access_check_gc **vec_, int alloc_ ) { int extend = !VEC_deferred_access_check_base_space (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), alloc_ ); if (extend) *vec_ = (VEC_deferred_access_check_gc *) vec_gc_o_reserve_exact (*vec_, alloc_, __builtin_offsetof (VEC_deferred_access_check_gc, base.vec), sizeof (deferred_access_check) ); return extend; } static inline void VEC_deferred_access_check_gc_safe_grow (VEC_deferred_access_check_gc **vec_, int size_ ) { (void)(size_ >= 0 && VEC_deferred_access_check_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0) <= (unsigned)size_); VEC_deferred_access_check_gc_reserve_exact (vec_, size_ - (int)(*vec_ ? ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num : 0) ); ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0)->prefix.num = size_; } static inline void VEC_deferred_access_check_gc_safe_grow_cleared (VEC_deferred_access_check_gc **vec_, int size_ ) { int oldsize = VEC_deferred_access_check_base_length ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0); VEC_deferred_access_check_gc_safe_grow (vec_, size_ ); memset (&(VEC_deferred_access_check_base_address ((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0))[oldsize], 0, sizeof (deferred_access_check) * (size_ - oldsize)); } static inline void VEC_deferred_access_check_gc_safe_splice (VEC_deferred_access_check_gc **dst_, VEC_deferred_access_check_base *src_ ) { if (src_) { VEC_deferred_access_check_gc_reserve_exact (dst_, src_->prefix.num ); VEC_deferred_access_check_base_splice (((__builtin_offsetof (__typeof (**dst_), base) == 0 || (*dst_)) ? &(*dst_)->base : 0), src_ ); } } static inline deferred_access_check *VEC_deferred_access_check_gc_safe_push (VEC_deferred_access_check_gc **vec_, const deferred_access_check *obj_ ) { VEC_deferred_access_check_gc_reserve (vec_, 1 ); return VEC_deferred_access_check_base_quick_push (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), obj_ ); } static inline deferred_access_check *VEC_deferred_access_check_gc_safe_insert (VEC_deferred_access_check_gc **vec_, unsigned ix_, const deferred_access_check *obj_ ) { VEC_deferred_access_check_gc_reserve (vec_, 1 ); return VEC_deferred_access_check_base_quick_insert (((__builtin_offsetof (__typeof (**vec_), base) == 0 || (*vec_)) ? &(*vec_)->base : 0), ix_, obj_ ); } struct vec_swallow_trailing_semi;


extern void push_deferring_access_checks (deferring_kind);
extern void resume_deferring_access_checks (void);
extern void stop_deferring_access_checks (void);
extern void pop_deferring_access_checks (void);
extern VEC_deferred_access_check_gc* get_deferred_access_checks (void);
extern void pop_to_parent_deferring_access_checks (void);
extern void perform_access_checks (VEC_deferred_access_check_gc*);
extern void perform_deferred_access_checks (void);
extern void perform_or_defer_access_check (tree, tree, tree);
extern bool speculative_access_check (tree, tree, tree, bool);
extern int stmts_are_full_exprs_p (void);
extern void init_cp_semantics (void);
extern tree do_poplevel (tree);
extern void add_decl_expr (tree);
extern tree maybe_cleanup_point_expr_void (tree);
extern tree finish_expr_stmt (tree);
extern tree begin_if_stmt (void);
extern void finish_if_stmt_cond (tree, tree);
extern tree finish_then_clause (tree);
extern void begin_else_clause (tree);
extern void finish_else_clause (tree);
extern void finish_if_stmt (tree);
extern tree begin_while_stmt (void);
extern void finish_while_stmt_cond (tree, tree);
extern void finish_while_stmt (tree);
extern tree begin_do_stmt (void);
extern void finish_do_body (tree);
extern void finish_do_stmt (tree, tree);
extern tree finish_return_stmt (tree);
extern tree begin_for_scope (tree *);
extern tree begin_for_stmt (tree, tree);
extern void finish_for_init_stmt (tree);
extern void finish_for_cond (tree, tree);
extern void finish_for_expr (tree, tree);
extern void finish_for_stmt (tree);
extern tree begin_range_for_stmt (tree, tree);
extern void finish_range_for_decl (tree, tree, tree);
extern void finish_range_for_stmt (tree);
extern tree finish_break_stmt (void);
extern tree finish_continue_stmt (void);
extern tree begin_switch_stmt (void);
extern void finish_switch_cond (tree, tree);
extern void finish_switch_stmt (tree);
extern tree finish_goto_stmt (tree);
extern tree begin_try_block (void);
extern void finish_try_block (tree);
extern void finish_handler_sequence (tree);
extern tree begin_function_try_block (tree *);
extern void finish_function_try_block (tree);
extern void finish_function_handler_sequence (tree, tree);
extern void finish_cleanup_try_block (tree);
extern tree begin_handler (void);
extern void finish_handler_parms (tree, tree);
extern void finish_handler (tree);
extern void finish_cleanup (tree, tree);
extern bool literal_type_p (tree);
extern tree register_constexpr_fundef (tree, tree);
extern bool check_constexpr_ctor_body (tree, tree);
extern tree ensure_literal_type_for_constexpr_object (tree);
extern bool potential_constant_expression (tree);
extern bool potential_rvalue_constant_expression (tree);
extern bool require_potential_constant_expression (tree);
extern bool require_potential_rvalue_constant_expression (tree);
extern tree cxx_constant_value (tree);
extern tree maybe_constant_value (tree);
extern tree maybe_constant_init (tree);
extern bool is_sub_constant_expr (tree);
extern bool reduced_constant_expression_p (tree);
extern void explain_invalid_constexpr_fn (tree);
extern VEC_tree_heap* cx_error_context (void);

enum {
  BCS_NO_SCOPE = 1,
  BCS_TRY_BLOCK = 2,
  BCS_FN_BODY = 4
};
extern tree begin_compound_stmt (unsigned int);

extern void finish_compound_stmt (tree);
extern tree finish_asm_stmt (int, tree, tree, tree, tree,
       tree);
extern tree finish_label_stmt (tree);
extern void finish_label_decl (tree);
extern tree finish_parenthesized_expr (tree);
extern tree finish_non_static_data_member (tree, tree, tree);
extern tree begin_stmt_expr (void);
extern tree finish_stmt_expr_expr (tree, tree);
extern tree finish_stmt_expr (tree, bool);
extern tree stmt_expr_value_expr (tree);
bool empty_expr_stmt_p (tree);
extern tree perform_koenig_lookup (tree, VEC_tree_gc *, bool,
       tsubst_flags_t);
extern tree finish_call_expr (tree, VEC_tree_gc **, bool,
       bool, tsubst_flags_t);
extern tree finish_increment_expr (tree, enum tree_code);
extern tree finish_this_expr (void);
extern tree finish_pseudo_destructor_expr (tree, tree, tree);
extern tree finish_unary_op_expr (enum tree_code, tree);
extern tree finish_compound_literal (tree, tree, tsubst_flags_t);
extern tree finish_fname (tree);
extern void finish_translation_unit (void);
extern tree finish_template_type_parm (tree, tree);
extern tree finish_template_template_parm (tree, tree);
extern tree begin_class_definition (tree);
extern void finish_template_decl (tree);
extern tree finish_template_type (tree, tree, int);
extern tree finish_base_specifier (tree, tree, bool);
extern void finish_member_declaration (tree);
extern tree finish_id_expression (tree, tree, tree,
       cp_id_kind *,
       bool, bool, bool *,
       bool, bool, bool, bool,
       const char **,
                                                 location_t);
extern tree finish_typeof (tree);
extern tree finish_underlying_type (tree);
extern tree calculate_bases (tree);
extern tree finish_bases (tree, bool);
extern tree calculate_direct_bases (tree);
extern tree finish_offsetof (tree);
extern void finish_decl_cleanup (tree, tree);
extern void finish_eh_cleanup (tree);
extern void emit_associated_thunks (tree);
extern void finish_mem_initializers (tree);
extern tree check_template_template_default_arg (tree);
extern bool expand_or_defer_fn_1 (tree);
extern void expand_or_defer_fn (tree);
extern void add_typedef_to_current_template_for_access_check (tree, tree,
             location_t);
extern void check_accessibility_of_qualified_id (tree, tree, tree);
extern tree finish_qualified_id_expr (tree, tree, bool, bool,
       bool, bool);
extern void simplify_aggr_init_expr (tree *);
extern void finalize_nrv (tree *, tree, tree);
extern void note_decl_for_pch (tree);
extern tree finish_omp_clauses (tree);
extern void finish_omp_threadprivate (tree);
extern tree begin_omp_structured_block (void);
extern tree finish_omp_structured_block (tree);
extern tree begin_omp_parallel (void);
extern tree finish_omp_parallel (tree, tree);
extern tree begin_omp_task (void);
extern tree finish_omp_task (tree, tree);
extern tree finish_omp_for (location_t, tree, tree,
       tree, tree, tree, tree, tree);
extern void finish_omp_atomic (enum tree_code, enum tree_code,
       tree, tree, tree, tree, tree);
extern void finish_omp_barrier (void);
extern void finish_omp_flush (void);
extern void finish_omp_taskwait (void);
extern tree begin_transaction_stmt (location_t, tree *, int);
extern void finish_transaction_stmt (tree, tree, int, tree);
extern tree build_transaction_expr (location_t, tree, int, tree);
extern void finish_omp_taskyield (void);
extern bool cxx_omp_create_clause_info (tree, tree, bool, bool, bool);
extern tree baselink_for_fns (tree);
extern void finish_static_assert (tree, tree, location_t,
                                                 bool);
extern tree finish_decltype_type (tree, bool, tsubst_flags_t);
extern tree finish_trait_expr (enum cp_trait_kind, tree, tree);
extern tree build_lambda_expr (void);
extern tree build_lambda_object (tree);
extern tree begin_lambda_type (tree);
extern tree lambda_capture_field_type (tree);
extern tree lambda_return_type (tree);
extern tree lambda_proxy_type (tree);
extern tree lambda_function (tree);
extern void apply_lambda_return_type (tree, tree);
extern tree add_capture (tree, tree, tree, bool, bool);
extern tree add_default_capture (tree, tree, tree);
extern tree build_capture_proxy (tree);
extern void insert_capture_proxy (tree);
extern void insert_pending_capture_proxies (void);
extern bool is_capture_proxy (tree);
extern bool is_normal_capture_proxy (tree);
extern void register_capture_members (tree);
extern tree lambda_expr_this_capture (tree);
extern tree nonlambda_method_basetype (void);
extern void maybe_add_lambda_conv_op (tree);
extern bool is_lambda_ignored_entity (tree);


extern int cp_tree_operand_length (const_tree);
void cp_free_lang_data (tree t);
extern tree force_target_expr (tree, tree, tsubst_flags_t);
extern tree build_target_expr_with_type (tree, tree, tsubst_flags_t);
extern void lang_check_failed (const char *, int,
       const char *) __attribute__ ((__noreturn__));
extern tree stabilize_expr (tree, tree *);
extern void stabilize_call (tree, tree *);
extern void stabilize_aggr_init (tree, tree *);
extern bool stabilize_init (tree, tree *);
extern tree add_stmt_to_compound (tree, tree);
extern void init_tree (void);
extern bool pod_type_p (const_tree);
extern bool layout_pod_type_p (const_tree);
extern bool std_layout_type_p (const_tree);
extern bool trivial_type_p (const_tree);
extern bool trivially_copyable_p (const_tree);
extern bool type_has_nontrivial_default_init (const_tree);
extern bool type_has_nontrivial_copy_init (const_tree);
extern bool class_tmpl_impl_spec_p (const_tree);
extern int zero_init_p (const_tree);
extern tree strip_typedefs (tree);
extern tree copy_binfo (tree, tree, tree,
       tree *, int);
extern int member_p (const_tree);
extern cp_lvalue_kind real_lvalue_p (const_tree);
extern cp_lvalue_kind lvalue_kind (const_tree);
extern bool lvalue_or_rvalue_with_address_p (const_tree);
extern bool builtin_valid_in_constant_expr_p (const_tree);
extern tree build_min (enum tree_code, tree, ...);
extern tree build_min_nt (enum tree_code, ...);
extern tree build_min_non_dep (enum tree_code, tree, ...);
extern tree build_min_non_dep_call_vec (tree, tree, VEC_tree_gc *);
extern tree build_cplus_new (tree, tree, tsubst_flags_t);
extern tree build_aggr_init_expr (tree, tree, tsubst_flags_t);
extern tree get_target_expr (tree);
extern tree get_target_expr_sfinae (tree, tsubst_flags_t);
extern tree build_cplus_array_type (tree, tree);
extern tree build_array_of_n_type (tree, int);
extern tree build_array_copy (tree);
extern tree build_vec_init_expr (tree, tree, tsubst_flags_t);
extern void diagnose_non_constexpr_vec_init (tree);
extern tree hash_tree_cons (tree, tree, tree);
extern tree hash_tree_chain (tree, tree);
extern tree build_qualified_name (tree, tree, tree, bool);
extern int is_overloaded_fn (tree);
extern tree dependent_name (tree);
extern tree get_fns (tree);
extern tree get_first_fn (tree);
extern tree ovl_cons (tree, tree);
extern tree build_overload (tree, tree);
extern tree ovl_scope (tree);
extern bool non_static_member_function_p (tree);
extern const char *cxx_printable_name (tree, int);
extern const char *cxx_printable_name_translate (tree, int);
extern tree build_exception_variant (tree, tree);
extern tree bind_template_template_parm (tree, tree);
extern tree array_type_nelts_total (tree);
extern tree array_type_nelts_top (tree);
extern tree break_out_target_exprs (tree);
extern tree get_type_decl (tree);
extern tree decl_namespace_context (tree);
extern bool decl_anon_ns_mem_p (const_tree);
extern tree lvalue_type (tree);
extern tree error_type (tree);
extern int varargs_function_p (const_tree);
extern bool really_overloaded_fn (tree);
extern bool cp_tree_equal (tree, tree);
extern tree no_linkage_check (tree, bool);
extern void debug_binfo (tree);
extern tree build_dummy_object (tree);
extern tree maybe_dummy_object (tree, tree *);
extern int is_dummy_object (const_tree);
extern const struct attribute_spec cxx_attribute_table[];
extern tree make_ptrmem_cst (tree, tree);
extern tree cp_build_type_attribute_variant (tree, tree);
extern tree cp_build_reference_type (tree, bool);
extern tree move (tree);
extern tree cp_build_qualified_type_real (tree, int, tsubst_flags_t);


extern bool cv_qualified_p (const_tree);
extern tree cv_unqualified (tree);
extern special_function_kind special_function_p (const_tree);
extern int count_trees (tree);
extern int char_type_p (tree);
extern void verify_stmt_tree (tree);
extern linkage_kind decl_linkage (tree);
extern duration_kind decl_storage_duration (tree);
extern tree cp_walk_subtrees (tree*, int*, walk_tree_fn,
         void*, struct pointer_set_t*);




extern tree fold_if_not_in_template (tree);
extern tree rvalue (tree);
extern tree convert_bitfield_to_declared_type (tree);
extern tree cp_save_expr (tree);
extern bool cast_valid_in_integral_constant_expression_p (tree);
extern bool cxx_type_hash_eq (const_tree, const_tree);

extern void cxx_print_statistics (void);


extern void cxx_print_xnode (FILE *, tree, int);
extern void cxx_print_decl (FILE *, tree, int);
extern void cxx_print_type (FILE *, tree, int);
extern void cxx_print_identifier (FILE *, tree, int);
extern void cxx_print_error_function (diagnostic_context *,
       const char *,
       struct diagnostic_info *);


extern bool cxx_mark_addressable (tree);
extern int string_conv_p (const_tree, const_tree, int);
extern tree cp_truthvalue_conversion (tree);
extern tree condition_conversion (tree);
extern tree require_complete_type (tree);
extern tree require_complete_type_sfinae (tree, tsubst_flags_t);
extern tree complete_type (tree);
extern tree complete_type_or_else (tree, tree);
extern tree complete_type_or_maybe_complain (tree, tree, tsubst_flags_t);
extern int type_unknown_p (const_tree);
enum { ce_derived, ce_normal, ce_exact };
extern bool comp_except_specs (const_tree, const_tree, int);
extern bool comptypes (tree, tree, int);
extern bool same_type_ignoring_top_level_qualifiers_p (tree, tree);
extern bool compparms (const_tree, const_tree);
extern int comp_cv_qualification (const_tree, const_tree);
extern int comp_cv_qual_signature (tree, tree);
extern tree cxx_sizeof_or_alignof_expr (tree, enum tree_code, bool);
extern tree cxx_sizeof_or_alignof_type (tree, enum tree_code, bool);
extern tree cxx_sizeof_nowarn (tree);
extern tree is_bitfield_expr_with_lowered_type (const_tree);
extern tree unlowered_expr_type (const_tree);
extern tree decay_conversion (tree);
extern tree build_class_member_access_expr (tree, tree, tree, bool,
       tsubst_flags_t);
extern tree finish_class_member_access_expr (tree, tree, bool,
       tsubst_flags_t);
extern tree build_x_indirect_ref (tree, ref_operator,
                                                 tsubst_flags_t);
extern tree cp_build_indirect_ref (tree, ref_operator,
                                                 tsubst_flags_t);
extern tree build_array_ref (location_t, tree, tree);
extern tree cp_build_array_ref (location_t, tree, tree,
       tsubst_flags_t);
extern tree get_member_function_from_ptrfunc (tree *, tree);
extern tree cp_build_function_call (tree, tree, tsubst_flags_t);
extern tree cp_build_function_call_nary (tree, tsubst_flags_t, ...)
      __attribute__ ((__sentinel__));
extern tree cp_build_function_call_vec (tree, VEC_tree_gc **,
       tsubst_flags_t);
extern tree build_x_binary_op (enum tree_code, tree,
       enum tree_code, tree,
       enum tree_code, tree *,
       tsubst_flags_t);
extern tree build_x_array_ref (tree, tree, tsubst_flags_t);
extern tree build_x_unary_op (enum tree_code, tree,
                                                 tsubst_flags_t);
extern tree cp_build_addr_expr (tree, tsubst_flags_t);
extern tree cp_build_addr_expr_strict (tree, tsubst_flags_t);
extern tree cp_build_unary_op (enum tree_code, tree, int,
                                                 tsubst_flags_t);
extern tree unary_complex_lvalue (enum tree_code, tree);
extern tree build_x_conditional_expr (tree, tree, tree,
                                                 tsubst_flags_t);
extern tree build_x_compound_expr_from_list (tree, expr_list_kind,
       tsubst_flags_t);
extern tree build_x_compound_expr_from_vec (VEC_tree_gc *, const char *);
extern tree build_x_compound_expr (tree, tree, tsubst_flags_t);
extern tree build_compound_expr (location_t, tree, tree);
extern tree cp_build_compound_expr (tree, tree, tsubst_flags_t);
extern tree build_static_cast (tree, tree, tsubst_flags_t);
extern tree build_reinterpret_cast (tree, tree, tsubst_flags_t);
extern tree build_const_cast (tree, tree, tsubst_flags_t);
extern tree build_c_cast (location_t, tree, tree);
extern tree cp_build_c_cast (tree, tree, tsubst_flags_t);
extern tree build_x_modify_expr (tree, enum tree_code, tree,
       tsubst_flags_t);
extern tree cp_build_modify_expr (tree, enum tree_code, tree,
       tsubst_flags_t);
extern tree convert_for_initialization (tree, tree, tree, int,
       impl_conv_rhs, tree, int,
                                                 tsubst_flags_t);
extern int comp_ptr_ttypes (tree, tree);
extern bool comp_ptr_ttypes_const (tree, tree);
extern bool error_type_p (const_tree);
extern int ptr_reasonably_similar (const_tree, const_tree);
extern tree build_ptrmemfunc (tree, tree, int, bool,
       tsubst_flags_t);
extern int cp_type_quals (const_tree);
extern int type_memfn_quals (const_tree);
extern tree apply_memfn_quals (tree, cp_cv_quals);
extern bool cp_has_mutable_p (const_tree);
extern bool at_least_as_qualified_p (const_tree, const_tree);
extern void cp_apply_type_quals_to_decl (int, tree);
extern tree build_ptrmemfunc1 (tree, tree, tree);
extern void expand_ptrmemfunc_cst (tree, tree *, tree *);
extern tree type_after_usual_arithmetic_conversions (tree, tree);
extern tree common_pointer_type (tree, tree);
extern tree composite_pointer_type (tree, tree, tree, tree,
       composite_pointer_operation,
       tsubst_flags_t);
extern tree merge_types (tree, tree);
extern tree strip_array_domain (tree);
extern tree check_return_expr (tree, bool *);
extern tree cp_build_binary_op (location_t,
       enum tree_code, tree, tree,
       tsubst_flags_t);

extern tree build_ptrmemfunc_access_expr (tree, tree);
extern tree build_address (tree);
extern tree build_typed_address (tree, tree);
extern tree build_nop (tree, tree);
extern tree non_reference (tree);
extern tree lookup_anon_field (tree, tree);
extern bool invalid_nonstatic_memfn_p (const_tree, tsubst_flags_t);
extern tree convert_member_func_to_ptr (tree, tree);
extern tree convert_ptrmem (tree, tree, bool, bool,
       tsubst_flags_t);
extern int lvalue_or_else (tree, enum lvalue_use,
                                                 tsubst_flags_t);
extern void check_template_keyword (tree);
extern bool check_raw_literal_operator (const_tree decl);
extern bool check_literal_operator_args (const_tree, bool *, bool *);


extern void require_complete_eh_spec_types (tree, tree);
extern void cxx_incomplete_type_diagnostic (const_tree, const_tree, diagnostic_t);

extern void cxx_incomplete_type_error (const_tree, const_tree);


extern tree error_not_base_type (tree, tree);
extern tree binfo_or_else (tree, tree);
extern void cxx_readonly_error (tree, enum lvalue_use);
extern void complete_type_check_abstract (tree);
extern int abstract_virtuals_error (tree, tree);
extern int abstract_virtuals_error_sfinae (tree, tree, tsubst_flags_t);

extern tree store_init_value (tree, tree, VEC_tree_gc**, int);
extern void check_narrowing (tree, tree);
extern tree digest_init (tree, tree, tsubst_flags_t);
extern tree digest_init_flags (tree, tree, int);
extern tree build_scoped_ref (tree, tree, tree *);
extern tree build_x_arrow (tree);
extern tree build_m_component_ref (tree, tree);
extern tree build_functional_cast (tree, tree, tsubst_flags_t);
extern tree add_exception_specifier (tree, tree, int);
extern tree merge_exception_specifiers (tree, tree, tree);


extern void init_mangle (void);
extern void mangle_decl (tree);
extern const char *mangle_type_string (tree);
extern tree mangle_typeinfo_for_type (tree);
extern tree mangle_typeinfo_string_for_type (tree);
extern tree mangle_vtbl_for_type (tree);
extern tree mangle_vtt_for_type (tree);
extern tree mangle_ctor_vtbl_for_type (tree, tree);
extern tree mangle_thunk (tree, int, tree, tree);
extern tree mangle_conv_op_name_for_type (tree);
extern tree mangle_guard_variable (tree);
extern tree mangle_ref_init_variable (tree);


extern bool cp_dump_tree (void *, tree);



extern alias_set_type cxx_get_alias_set (tree);
extern bool cxx_warn_unused_global_decl (const_tree);
extern size_t cp_tree_size (enum tree_code);
extern bool cp_var_mod_type_p (tree, tree);
extern void cxx_initialize_diagnostics (diagnostic_context *);
extern int cxx_types_compatible_p (tree, tree);
extern void init_shadowed_var_for_decl (void);


extern int cp_gimplify_expr (tree *, gimple_seq *,
       gimple_seq *);
extern void cp_genericize (tree);
extern bool cxx_omp_const_qual_no_mutable (tree);
extern enum omp_clause_default_kind cxx_omp_predetermined_sharing (tree);
extern tree cxx_omp_clause_default_ctor (tree, tree, tree);
extern tree cxx_omp_clause_copy_ctor (tree, tree, tree);
extern tree cxx_omp_clause_assign_op (tree, tree, tree);
extern tree cxx_omp_clause_dtor (tree, tree);
extern void cxx_omp_finish_clause (tree);
extern bool cxx_omp_privatize_by_reference (const_tree);


extern void suggest_alternatives_for (location_t, tree);
extern tree strip_using_decl (tree);
# 32 "../../../src/plugin-utils.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-pragma.h" 1
# 28 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-pragma.h"
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
extern bool pop_visibility (int);

extern void init_pragma (void);


typedef void (*pragma_handler_1arg)(struct cpp_reader *);


typedef void (*pragma_handler_2arg)(struct cpp_reader *, void *);


union gen_pragma_handler {
  pragma_handler_1arg handler_1arg;
  pragma_handler_2arg handler_2arg;
};

struct internal_pragma_handler_d {
  union gen_pragma_handler handler;


  bool extra_data;

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
# 144 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/c-family/c-pragma.h"
extern enum cpp_ttype c_lex_with_flags (tree *, location_t *, unsigned char *,
     int);

extern void c_pp_lookup_pragma (unsigned int, const char **, const char **);

extern tree pragma_extern_prefix;
# 33 "../../../src/plugin-utils.h" 2
# 42 "../../../src/plugin-utils.h"
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h" 1
# 47 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
enum rtx_code {


# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def" 1
# 82 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
UNKNOWN ,






VALUE ,



DEBUG_EXPR ,






EXPR_LIST ,



INSN_LIST ,





SEQUENCE ,


ADDRESS ,
# 126 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
DEBUG_INSN ,


INSN ,



JUMP_INSN ,






CALL_INSN ,


BARRIER ,







CODE_LABEL ,






NOTE ,
# 171 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
COND_EXEC ,


PARALLEL ,







ASM_INPUT ,
# 196 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
ASM_OPERANDS ,
# 214 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
UNSPEC ,


UNSPEC_VOLATILE ,



ADDR_VEC ,
# 246 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
ADDR_DIFF_VEC ,
# 257 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
PREFETCH ,
# 269 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
SET ,
# 278 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
USE ,
# 287 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
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
# 356 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
REG ,






SCRATCH ,



SUBREG ,
# 380 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
STRICT_LOW_PART ,





CONCAT ,





CONCATN ,




MEM ,



LABEL_REF ,






SYMBOL_REF ,






CC0 ,
# 427 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
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
# 484 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
SMIN ,
SMAX ,
UMIN ,
UMAX ,
# 496 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
PRE_DEC ,
PRE_INC ,
POST_DEC ,
POST_INC ,
# 513 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
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
# 585 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
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
# 648 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.def"
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
# 51 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h" 2


  LAST_AND_UNUSED_RTX_CODE};
# 62 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
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
# 100 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
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



  long offset;



  long size;


  alias_set_type alias;




  unsigned int align;


  unsigned char addrspace;


  bool offset_known_p;


  bool size_known_p;
} mem_attrs;
# 180 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
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



  long offset;
};



struct object_block {

  section *sect;


  unsigned int alignment;


  long size;
# 241 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
  VEC_rtx_gc *objects;
# 251 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
  VEC_rtx_gc *anchors;
};



struct
                                                    rtx_def {

  enum rtx_code code: 16;


  enum machine_mode mode : 8;







  unsigned int jump : 1;




  unsigned int call : 1;
# 285 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
  unsigned int unchanging : 1;
# 298 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
  unsigned int volatil : 1;
# 312 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
  unsigned int in_struct : 1;
# 321 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
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
# 384 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
struct rtvec_def {
  int num_elem;
  rtx elem[1];
};
# 874 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
enum reg_note
{

# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/reg-notes.def" 1
# 33 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/reg-notes.def"
REG_DEP_TRUE,




REG_DEAD,


REG_INC,
# 52 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/reg-notes.def"
REG_EQUIV,




REG_EQUAL,






REG_NONNEG,


REG_UNUSED,
# 76 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/reg-notes.def"
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
# 126 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/reg-notes.def"
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
# 878 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h" 2

  REG_NOTE_MAX
};
# 889 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
extern const char * const reg_note_name[];
# 992 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
enum insn_note
{

# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/insn-notes.def" 1
# 35 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/insn-notes.def"
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
# 996 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h" 2


  NOTE_INSN_MAX
};



extern const char * const note_insn_name[NOTE_INSN_MAX];
# 1018 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
enum label_kind
{
  LABEL_NORMAL = 0,
  LABEL_STATIC_ENTRY,
  LABEL_GLOBAL_ENTRY,
  LABEL_WEAK_ENTRY
};
# 1087 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
static inline unsigned int
rhs_regno (const_rtx x)
{
  return (((x)->u.fld[0]).rt_uint);
}
# 1162 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
struct full_rtx_costs
{
  int speed;
  int size;
};


static inline void
init_costs_to_max (struct full_rtx_costs *c)
{
  c->speed = 2147483647;
  c->size = 2147483647;
}


static inline void
init_costs_to_zero (struct full_rtx_costs *c)
{
  c->speed = 0;
  c->size = 0;
}



static inline bool
costs_lt_p (struct full_rtx_costs *a, struct full_rtx_costs *b,
     bool speed)
{
  if (speed)
    return (a->speed < b->speed
     || (a->speed == b->speed && a->size < b->size));
  else
    return (a->size < b->size
     || (a->size == b->size && a->speed < b->speed));
}



static inline void
costs_add_n_insns (struct full_rtx_costs *c, int n)
{
  c->speed += ((n) * 4);
  c->size += ((n) * 4);
}

extern void init_rtlanal (void);
extern int rtx_cost (rtx, enum rtx_code, int, bool);
extern int address_cost (rtx, enum machine_mode, addr_space_t, bool);
extern void get_full_rtx_cost (rtx, enum rtx_code, int,
          struct full_rtx_costs *);
extern unsigned int subreg_lsb (const_rtx);
extern unsigned int subreg_lsb_1 (enum machine_mode, enum machine_mode,
      unsigned int);
extern unsigned int subreg_regno_offset (unsigned int, enum machine_mode,
      unsigned int, enum machine_mode);
extern bool subreg_offset_representable_p (unsigned int, enum machine_mode,
        unsigned int, enum machine_mode);
extern unsigned int subreg_regno (const_rtx);
extern int simplify_subreg_regno (unsigned int, enum machine_mode,
      unsigned int, enum machine_mode);
extern unsigned int subreg_nregs (const_rtx);
extern unsigned int subreg_nregs_with_regno (unsigned int, const_rtx);
extern unsigned long nonzero_bits (const_rtx, enum machine_mode);
extern unsigned int num_sign_bit_copies (const_rtx, enum machine_mode);
extern bool constant_pool_constant_p (rtx);
extern bool truncated_to_mode (enum machine_mode, const_rtx);
extern int low_bitmask_len (enum machine_mode, unsigned long);





static inline int
set_rtx_cost (rtx x, bool speed_p)
{
  return rtx_cost (x, INSN, 4, speed_p);
}



static inline void
get_full_set_rtx_cost (rtx x, struct full_rtx_costs *c)
{
  get_full_rtx_cost (x, INSN, 4, c);
}





static inline int
set_src_cost (rtx x, bool speed_p)
{
  return rtx_cost (x, SET, 1, speed_p);
}



static inline void
get_full_set_src_cost (rtx x, struct full_rtx_costs *c)
{
  get_full_rtx_cost (x, SET, 1, c);
}
# 1634 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
extern int generating_concat_p;


extern int currently_expanding_to_rtl;




extern int ceil_log2 (unsigned long);


extern long trunc_int_for_mode (long, enum machine_mode);
extern rtx plus_constant (rtx, long);


extern rtx rtx_alloc_stat (enum rtx_code );


extern rtvec rtvec_alloc (int);
extern rtvec shallow_copy_rtvec (rtvec);
extern bool shared_const_p (const_rtx);
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
extern bool paradoxical_subreg_p (const_rtx);
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
extern rtx immed_double_const (long, long,
          enum machine_mode);



extern rtx lowpart_subreg (enum machine_mode, rtx, enum machine_mode);


extern rtx force_const_mem (enum machine_mode, rtx);



struct function;
extern rtx get_pool_constant (rtx);
extern rtx get_pool_constant_mark (rtx, bool *);
extern enum machine_mode get_pool_mode (const_rtx);
extern rtx simplify_subtraction (rtx);
extern void decide_function_section (tree);


extern rtx assign_stack_local (enum machine_mode, long, int);


extern rtx assign_stack_local_1 (enum machine_mode, long, int, int);
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
extern rtx next_label (rtx);
extern rtx skip_consecutive_labels (rtx);
extern rtx next_cc0_user (rtx);
extern rtx prev_cc0_setter (rtx);


extern int insn_line (const_rtx);
extern const char * insn_file (const_rtx);
extern location_t locator_location (int);
extern int locator_line (int);
extern const char * locator_file (int);
extern bool locator_eq (int, int);
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
extern bool mode_signbit_p (enum machine_mode, const_rtx);
extern bool val_signbit_p (enum machine_mode, unsigned long);
extern bool val_signbit_known_set_p (enum machine_mode,
         unsigned long);
extern bool val_signbit_known_clear_p (enum machine_mode,
           unsigned long);


extern enum machine_mode choose_hard_reg_mode (unsigned int, unsigned int,
            bool);


extern rtx set_unique_reg_note (rtx, enum reg_note, rtx);
extern rtx set_dst_reg_note (rtx, enum reg_note, rtx, rtx);
extern void set_insn_deleted (rtx);
# 1895 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
typedef struct replace_label_data
{
  rtx r1;
  rtx r2;
  bool update_label_nuses;
} replace_label_data;

extern int rtx_addr_can_trap_p (const_rtx);
extern bool nonzero_address_p (const_rtx);
extern int rtx_unstable_p (const_rtx);
extern bool rtx_varies_p (const_rtx, bool);
extern bool rtx_addr_varies_p (const_rtx, bool);
extern long get_integer_term (const_rtx);
extern rtx get_related_value (const_rtx);
extern bool offset_within_block_p (const_rtx, long);
extern void split_const (rtx, rtx *, rtx *);
extern int reg_mentioned_p (const_rtx, const_rtx);
extern int count_occurrences (const_rtx, const_rtx, int);
extern int reg_referenced_p (const_rtx, const_rtx);
extern int reg_used_between_p (const_rtx, const_rtx, const_rtx);
extern int reg_set_between_p (const_rtx, const_rtx, const_rtx);
extern int commutative_operand_precedence (rtx);
extern bool swap_commutative_operands_p (rtx, rtx);
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

extern void find_all_hard_reg_sets (const_rtx, HARD_REG_ELT_TYPE *);

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
extern bool can_throw_internal (const_rtx);
extern bool can_throw_external (const_rtx);
extern bool insn_could_throw_p (const_rtx);
extern bool insn_nothrow_p (const_rtx);
extern bool can_nonlocal_goto (const_rtx);
extern void copy_reg_eh_region_note_forward (rtx, rtx, rtx);
extern void copy_reg_eh_region_note_backward(rtx, rtx, rtx);
extern int inequality_comparisons_p (const_rtx);
extern rtx replace_rtx (rtx, rtx, rtx);
extern int replace_label (rtx *, void *);
extern int rtx_referenced_p (rtx, rtx);
extern bool tablejump_p (const_rtx, rtx *, rtx *);
extern int computed_jump_p (const_rtx);

typedef int (*rtx_function) (rtx *, void *);
extern int for_each_rtx (rtx *, rtx_function, void *);
# 1980 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
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
                             bool, hash_rtx_callback_function);

extern rtx regno_use_in (unsigned int, rtx);
extern int auto_inc_p (const_rtx);
extern int in_expr_list_p (const_rtx, const_rtx);
extern void remove_node_from_expr_list (const_rtx, rtx *);
extern int loc_mentioned_in_p (rtx *, const_rtx);
extern rtx find_first_parameter_load (rtx, rtx);
extern bool keep_with_call_p (const_rtx);
extern bool label_is_jump_target_p (const_rtx, const_rtx);
extern int insn_rtx_cost (rtx, bool);



extern rtx canonicalize_condition (rtx, rtx, int, rtx *, rtx, int, int);



extern rtx get_condition (rtx, rtx *, int, int);


struct subreg_info
{

  int offset;

  int nregs;


  bool representable_p;
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

extern bool resize_reg_info (void);

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
# 2113 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
enum global_rtl_index
{
  GR_PC,
  GR_CC0,
  GR_RETURN,
  GR_SIMPLE_RETURN,
  GR_STACK_POINTER,
  GR_FRAME_POINTER,
# 2130 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
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
# 2166 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
  rtx x_global_rtl[GR_MAX];


  rtx x_pic_offset_table_rtx;




  rtx x_return_address_pointer_rtx;





  rtx x_initial_regno_reg_rtx[53];


  rtx x_top_of_stack[MAX_MACHINE_MODE];



  rtx x_static_reg_base_value[53];


  struct mem_attrs *x_mode_mem_attrs[(int) MAX_MACHINE_MODE];
};

extern struct target_rtl default_target_rtl;
# 2227 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
static inline struct mem_attrs *
get_mem_attrs (const_rtx x)
{
  struct mem_attrs *attrs;

  attrs = (((x)->u.fld[1]).rt_mem);
  if (!attrs)
    attrs = ((&default_target_rtl)->x_mode_mem_attrs)[(int) ((enum machine_mode) (x)->mode)];
  return attrs;
}





# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/genrtl.h" 1







static inline rtx
gen_rtx_fmt_0_stat (enum rtx_code code, enum machine_mode mode )
{
  rtx rt;
  rt = rtx_alloc_stat (code );

  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtx) = (rtx) 0;

  return rt;
}




static inline rtx
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




static inline rtx
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




static inline rtx
gen_rtx_fmt_E_stat (enum rtx_code code, enum machine_mode mode,
 rtvec arg0 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );

  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtvec) = arg0;

  return rt;
}




static inline rtx
gen_rtx_fmt_e_stat (enum rtx_code code, enum machine_mode mode,
 rtx arg0 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );

  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtx) = arg0;

  return rt;
}




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
gen_rtx_fmt__stat (enum rtx_code code, enum machine_mode mode )
{
  rtx rt;
  rt = rtx_alloc_stat (code );

  ((rt)->mode = (mode));

  return rt;
}




static inline rtx
gen_rtx_fmt_w_stat (enum rtx_code code, enum machine_mode mode,
 long arg0 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );

  ((rt)->mode = (mode));
  ((rt)->u.hwint[0]) = arg0;

  return rt;
}




static inline rtx
gen_rtx_fmt_www_stat (enum rtx_code code, enum machine_mode mode,
 long arg0,
 long arg1,
 long arg2 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );

  ((rt)->mode = (mode));
  ((rt)->u.hwint[0]) = arg0;
  ((rt)->u.hwint[1]) = arg1;
  ((rt)->u.hwint[2]) = arg2;

  return rt;
}




static inline rtx
gen_rtx_fmt_s_stat (enum rtx_code code, enum machine_mode mode,
 const char *arg0 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );

  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_str) = arg0;

  return rt;
}




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
gen_rtx_fmt_u_stat (enum rtx_code code, enum machine_mode mode,
 rtx arg0 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );

  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_rtx) = arg0;

  return rt;
}




static inline rtx
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




static inline rtx
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




static inline rtx
gen_rtx_fmt_t_stat (enum rtx_code code, enum machine_mode mode,
 union tree_node *arg0 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );

  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_tree) = arg0;

  return rt;
}




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
gen_rtx_fmt_i_stat (enum rtx_code code, enum machine_mode mode,
 int arg0 )
{
  rtx rt;
  rt = rtx_alloc_stat (code );

  ((rt)->mode = (mode));
  (((rt)->u.fld[0]).rt_int) = arg0;

  return rt;
}




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
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




static inline rtx
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
# 2243 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h" 2
# 2254 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
extern rtx gen_rtx_CONST_INT (enum machine_mode, long);
extern rtx gen_rtx_CONST_VECTOR (enum machine_mode, rtvec);
extern rtx gen_raw_REG (enum machine_mode, int);
extern rtx gen_rtx_REG (enum machine_mode, unsigned);
extern rtx gen_rtx_SUBREG (enum machine_mode, rtx, int);
extern rtx gen_rtx_MEM (enum machine_mode, rtx);
# 2338 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
extern rtx output_constant_def (tree, int);
extern rtx lookup_constant_def (tree);




extern int reload_completed;


extern int epilogue_completed;




extern int reload_in_progress;
# 2362 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
extern int regstack_completed;
# 2371 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/rtl.h"
extern int cse_not_expected;





extern int rtx_to_tree_code (enum rtx_code);


extern int delete_trivially_dead_insns (rtx, int);
extern int cse_main (rtx, int);
extern int exp_equiv_p (const_rtx, const_rtx, int, bool);
extern unsigned hash_rtx (const_rtx x, enum machine_mode, int *, int *, bool);


extern bool check_for_inc_dec (rtx insn);


extern int comparison_dominates_p (enum rtx_code, enum rtx_code);
extern bool jump_to_label_p (rtx);
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
extern void delete_insn_chain (rtx, rtx, bool);
extern rtx unlink_insn_chain (rtx, rtx);
extern rtx delete_insn_and_edges (rtx);
extern rtx gen_lowpart_SUBREG (enum machine_mode, rtx);
extern rtx gen_const_mem (enum machine_mode, rtx);
extern rtx gen_frame_mem (enum machine_mode, rtx);
extern rtx gen_tmp_stack_mem (enum machine_mode, rtx);
extern bool validate_subreg (enum machine_mode, enum machine_mode,
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


extern rtx move_by_pieces (rtx, rtx, unsigned long,
      unsigned int, int);
extern long find_args_size_adjust (rtx);
extern int fixup_args_size_notes (rtx, rtx, int);


extern void print_rtl_with_bb (FILE *, const_rtx);


extern void dump_reg_info (FILE *);
extern void dump_flow_info (FILE *, int);


extern void init_expmed (void);
extern void expand_inc (rtx, rtx);
extern void expand_dec (rtx, rtx);


extern bool can_copy_p (enum machine_mode);
extern bool can_assign_to_reg_without_clobbers_p (rtx);
extern rtx fis_get_condition (rtx);



extern HARD_REG_ELT_TYPE eliminable_regset;

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
extern bool invalid_mode_change_p (unsigned int, enum reg_class);


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


extern bool read_rtx (const char *, rtx *);


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
extern bool memory_modified_in_insn_p (const_rtx, const_rtx);
extern rtx find_base_term (rtx);
extern rtx gen_hard_reg_clobber (enum machine_mode, unsigned int);
extern rtx get_reg_known_value (unsigned int);
extern bool get_reg_known_equiv_p (unsigned int);
extern rtx get_reg_base_value (unsigned int);


extern int stack_regs_mentioned (const_rtx insn);



extern rtx stack_limit_rtx;


extern void invert_br_probabilities (rtx);
extern bool expensive_function_p (int);


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
  bool (*reg_truncated_to_mode) (enum machine_mode, const_rtx);


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
extern bool optimize_insn_for_size_p (void);
extern bool optimize_insn_for_speed_p (void);


extern void _fatal_insn_not_found (const_rtx, const char *, int, const char *)
     __attribute__ ((__noreturn__));
extern void _fatal_insn (const char *, const_rtx, const char *, int, const char *)
     __attribute__ ((__noreturn__));
# 43 "../../../src/plugin-utils.h" 2
# 1 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/emit-rtl.h" 1
# 24 "/work1/ferranti/build-gcc/gcc-4.7.1/install/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/plugin/include/emit-rtl.h"
extern void set_mem_alias_set (rtx, alias_set_type);


extern void set_mem_align (rtx, unsigned int);


extern void set_mem_addr_space (rtx, addr_space_t);


extern void set_mem_expr (rtx, tree);


extern void set_mem_offset (rtx, long);


extern void clear_mem_offset (rtx);


extern void set_mem_size (rtx, long);


extern void clear_mem_size (rtx);


extern void set_mem_attrs_for_spill (rtx);
extern tree get_spill_slot_decl (bool);





extern rtx replace_equiv_address (rtx, rtx);


extern rtx replace_equiv_address_nv (rtx, rtx);

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



static inline rtx
get_insns (void)
{
  return (&x_rtl)->emit.x_first_insn;
}



static inline void
set_first_insn (rtx insn)
{
  ((void)(0 && (!insn || !(((insn)->u.fld[1]).rt_rtx))));
  (&x_rtl)->emit.x_first_insn = insn;
}



static inline rtx
get_last_insn (void)
{
  return (&x_rtl)->emit.x_last_insn;
}



static inline void
set_last_insn (rtx insn)
{
  ((void)(0 && (!insn || !(((insn)->u.fld[2]).rt_rtx))));
  (&x_rtl)->emit.x_last_insn = insn;
}



static inline int
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


bool is_targetable_decl(tree decl);



bool is_targetable_type(tree type);
# 325 "../../../src/plugin-utils.h"
bool comparison_set_rtx_1(rtx match_input,rtx *cc_op,rtx *op1,rtx *op2);
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






bool is_targetable_decl(tree decl){





  return ((decl)->decl_minimal.name)!=(tree) __null&&!((decl)->base.nameless_flag)&&((! (((decl)->decl_minimal.context)) || ((enum tree_code) (((decl)->decl_minimal.context))->base.code) == TRANSLATION_UNIT_DECL)||is_gpp());

}

bool is_targetable_type(tree type){
 return ((type)->type_common.name)!=(tree) __null&&!((type)->base.nameless_flag)&&(! (((type)->type_common.context)) || ((enum tree_code) (((type)->type_common.context))->base.code) == TRANSLATION_UNIT_DECL);
}


bool comparison_set_rtx_1(rtx match_input,rtx *cc_op,rtx *op1,rtx *op2){
 if(((enum rtx_code) (match_input)->code)==SET){
  rtx compare=(((match_input)->u.fld[1]).rt_rtx);
  *cc_op=(((match_input)->u.fld[0]).rt_rtx);

  if(((enum mode_class) mode_class[((enum machine_mode) (*cc_op)->mode)])==MODE_CC&&((enum rtx_code) (compare)->code)==COMPARE){




   *op1=(((compare)->u.fld[0]).rt_rtx);
   *op2=(((compare)->u.fld[1]).rt_rtx);

   return true;
  }
 }

 return false;
}
