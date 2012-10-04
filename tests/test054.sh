#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS ACF plugin with perf"

# Check if there is an ACF plugin for the host compiler version
acf_plugin="acf_plugin.so"
acf_plugin_path=""

config_query() {
    $ROOT/bin/atos lib config -u -t -q $*
}

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"


# Check if acf plugin is available for host compiler
if [ ! -f "`config_query '$.compilers[*].plugin_acf'`" ]; then
    skip "acf plugins not available for compiler"
fi

# Check if host compiler has plugin support
if [ "`config_query '$.compilers[*].plugins_enabled'`" != "1" ]; then
    skip "plugins not supported by compiler"
fi

$ROOT/bin/atos-opt -r -a "-Os"

$ROOT/bin/atos-opt -r -a "-O2"

$ROOT/bin/atos-opt -r -a "-O3"

nb_frontier=`$ROOT/bin/atos lib speedups -C atos-configurations -f | wc -l`

perf_out_script=perf-profile.sh
echo "#!/usr/bin/env bash" > $perf_out_script

echo "cat > oprof.out <<EOF
# Samples: 17738
#
# Overhead  Samples           Command                Shared Object  Symbol
# ........ ..........  ..............  ...........................  ......
#
    63.29%      11227              dd  [kernel]                     0xffffffff8152c640 k [k] sha_transform
    11.59%       2055              dd  [kernel]                     0xffffffff81329dc0 k [k] mix_pool_bytes_extract
     4.75%        843          sha1-c  /lib/libc-2.11.1.so          0x000000000006bc0f u [.] _IO_getc
     4.18%        741          sha1-c  /lib/libc-2.11.1.so          0x000000000006b52d u [.] _IO_feof
     3.31%        587              dd  [kernel]                     0xffffffff8132a439 k [k] extract_buf
     2.80%        496          sha1-c  ./sha1-c                     0x00000000000010c1 d [.] SHA1ProcessMessageBlock
     2.67%        474          sha1-c  ./sha1-c                     0x000000000000087f d [.] SHA1Input
     1.68%        298              dd  [kernel]                     0xffffffff812be0fd k [k] copy_user_generic_string
     1.30%        231          sha1-c  ./sha1-c                     0x0000000000000736 d [.] main
     0.69%        123              dd  [kernel]                     0xffffffff810387be k [k] __ticket_spin_lock
     0.51%         91          sha1-c  ./sha1-c                     0x0000000000000618 d [.] feof@plt
     0.42%         74              dd  [kernel]                     0xffffffff815427e0 k [k] _spin_unlock_irqrestore
     0.39%         70              dd  [kernel]                     0xffffffff8132aa6e k [k] extract_entropy_user
     0.36%         64              dd  [kernel]                     0xffffffff815426c1 k [k] _spin_lock_irqsave
     0.25%         44          sha1-c  ./sha1-c                     0x00000000000005f8 d [.] fgetc@plt
     0.17%         30              dd  [kernel]                     0xffffffff8152c52f k [k] sha_init
     0.15%         26          sha1-c  [kernel]                     0xffffffff812be0d0 k [k] copy_user_generic_string
     0.08%         15              dd  [kernel]                     0xffffffff810387f0 k [k] __ticket_spin_unlock
     0.06%         11              dd  [kernel]                     0xffffffff81038849 k [k] default_spin_lock_flags
     0.05%          9              dd  [kernel]                     0xffffffff812bdfa0 k [k] copy_to_user
     0.05%          8          sha1-c  [kernel]                     0xffffffff81058fd5 k [k] update_curr
     0.03%          5          sha1-c  [kernel]                     0xffffffff8114d0ea k [k] pipe_read
     0.02%          4          sha1-c  [kernel]                     0xffffffff810387be k [k] __ticket_spin_lock
     0.02%          4          sha1-c  [kernel]                     0xffffffff81145749 k [k] fget_light
     0.02%          4          sha1-c  /lib/libc-2.11.1.so          0x000000000007334e u [.] _IO_new_file_underflow
     0.02%          4          sha1-c  /lib/libc-2.11.1.so          0x00000000000760a1 u [.] __GI___uflow
     0.02%          4              dd  [kernel]                     0xffffffff8104b6e5 k [k] wake_affine
     0.02%          4              dd  [kernel]                     0xffffffff8105cba6 k [k] try_to_wake_up
     0.02%          4            bash  [kernel]                     0xffffffff8115938b k [k] __d_lookup
     0.02%          3          sha1-c  [kernel]                     0xffffffff81055638 k [k] find_busiest_group
     0.02%          3          sha1-c  [kernel]                     0xffffffff8105e201 k [k] pick_next_task_rt
     0.02%          3          sha1-c  [kernel]                     0xffffffff81084ee7 k [k] finish_wait
     0.02%          3          sha1-c  [kernel]                     0xffffffff8108aec1 k [k] cpu_clock
     0.02%          3          sha1-c  [kernel]                     0xffffffff8114c3b0 k [k] anon_pipe_buf_release
     0.02%          3          sha1-c  [kernel]                     0xffffffff8115b221 k [k] touch_atime
     0.02%          3          sha1-c  [kernel]                     0xffffffff8153fe1b k [k] schedule
     0.02%          3          sha1-c  [kernel]                     0xffffffff81541181 k [k] mutex_lock
     0.02%          3            bash  [kernel]                     0xffffffff812bdeb5 k [k] copy_page_c
     0.02%          3            bash  [kernel]                     0xffffffff81542c50 k [k] page_fault
     0.01%          2          sha1-c  [kernel]                     0xffffffff810121b7 k [k] ret_from_sys_call
     0.01%          2          sha1-c  [kernel]                     0xffffffff810199a4 k [k] native_read_tsc
     0.01%          2          sha1-c  [kernel]                     0xffffffff8104a5c0 k [k] dequeue_task
     0.01%          2          sha1-c  [kernel]                     0xffffffff810530b1 k [k] hrtick_start_fair
     0.01%          2          sha1-c  [kernel]                     0xffffffff810627a9 k [k] pick_next_task_fair
     0.01%          2          sha1-c  [kernel]                     0xffffffff81084f91 k [k] prepare_to_wait
     0.01%          2          sha1-c  [kernel]                     0xffffffff81144160 k [k] do_sync_read
     0.01%          2          sha1-c  [kernel]                     0xffffffff811449c3 k [k] vfs_read
     0.01%          2          sha1-c  [kernel]                     0xffffffff8114be61 k [k] generic_pipe_buf_confirm
     0.01%          2  perf_2.6.32-34  [kernel]                     0xffffffff810f8b28 k [k] __rmqueue
     0.01%          2              dd  [kernel]                     0xffffffff8111238f k [k] zap_pte_range
     0.01%          2              dd  [kernel]                     0xffffffff81144ab5 k [k] vfs_read
     0.01%          2              dd  [kernel]                     0xffffffff8114cb8a k [k] pipe_write
     0.01%          2              dd  [kernel]                     0xffffffff8115b1c3 k [k] file_update_time
     0.01%          2              dd  [kernel]                     0xffffffff815411a4 k [k] mutex_lock
     0.01%          2              dd  [kernel]                     0xffffffff81542c50 k [k] page_fault
     0.01%          2              dd  [kernel]                     0xffffffffa0000031 k [k] tg3_read32	[tg3]
     0.01%          2            bash  /lib/ld-2.11.1.so            0x0000000000009d0d u [.] do_lookup_x
     0.01%          1          sha1-c  [kernel]                     0xffffffff81012120 k [k] system_call
     0.01%          1          sha1-c  [kernel]                     0xffffffff81012b00 k [k] common_interrupt
     0.01%          1          sha1-c  [kernel]                     0xffffffff81018e7c k [k] sched_clock
     0.01%          1          sha1-c  [kernel]                     0xffffffff81037caa k [k] native_write_msr_safe
     0.01%          1          sha1-c  [kernel]                     0xffffffff8104a723 k [k] deactivate_task
     0.01%          1          sha1-c  [kernel]                     0xffffffff8104ae30 k [k] __wake_up_common
     0.01%          1          sha1-c  [kernel]                     0xffffffff8104bbe0 k [k] pick_next_task_idle
     0.01%          1          sha1-c  [kernel]                     0xffffffff810528f0 k [k] __wake_up_sync
     0.01%          1          sha1-c  [kernel]                     0xffffffff81059412 k [k] put_prev_task_fair
     0.01%          1          sha1-c  [kernel]                     0xffffffff8105a11f k [k] select_task_rq_fair
     0.01%          1          sha1-c  [kernel]                     0xffffffff810611cc k [k] dequeue_entity
     0.01%          1          sha1-c  [kernel]                     0xffffffff8106bdcc k [k] current_fs_time
     0.01%          1          sha1-c  [kernel]                     0xffffffff81086baa k [k] run_posix_cpu_timers
     0.01%          1          sha1-c  [kernel]                     0xffffffff8108ae78 k [k] sched_clock_cpu
     0.01%          1          sha1-c  [kernel]                     0xffffffff8108f372 k [k] current_kernel_time
     0.01%          1          sha1-c  [kernel]                     0xffffffff810c4700 k [k] __touch_softlockup_watchdog
     0.01%          1          sha1-c  [kernel]                     0xffffffff810c9c3a k [k] __call_rcu
     0.01%          1          sha1-c  [kernel]                     0xffffffff810fa4ce k [k] get_page_from_freelist
     0.01%          1          sha1-c  [kernel]                     0xffffffff810fbf78 k [k] free_pcppages_bulk
     0.01%          1          sha1-c  [kernel]                     0xffffffff8110df2a k [k] dec_zone_page_state
     0.01%          1          sha1-c  [kernel]                     0xffffffff81116b67 k [k] get_user_pages
     0.01%          1          sha1-c  [kernel]                     0xffffffff81118430 k [k] find_vma
     0.01%          1          sha1-c  [kernel]                     0xffffffff8111a954 k [k] do_munmap
     0.01%          1          sha1-c  [kernel]                     0xffffffff81144bb0 k [k] sys_read
     0.01%          1          sha1-c  [kernel]                     0xffffffff81145708 k [k] file_free_rcu
     0.01%          1          sha1-c  [kernel]                     0xffffffff8114c04d k [k] pipe_lock
     0.01%          1          sha1-c  [kernel]                     0xffffffff8117937c k [k] fsnotify
     0.01%          1          sha1-c  [kernel]                     0xffffffff81253b80 k [k] security_file_permission
     0.01%          1          sha1-c  [kernel]                     0xffffffff81286673 k [k] apparmor_file_permission
     0.01%          1          sha1-c  [kernel]                     0xffffffff812b47a1 k [k] cpumask_any_but
     0.01%          1          sha1-c  [kernel]                     0xffffffff812b4bfc k [k] find_next_bit
     0.01%          1          sha1-c  [kernel]                     0xffffffff81540281 k [k] thread_return
     0.01%          1          sha1-c  [kernel]                     0xffffffff81540610 k [k] _cond_resched
     0.01%          1          sha1-c  [kernel]                     0xffffffff81540ec4 k [k] mutex_unlock
     0.01%          1          sha1-c  [kernel]                     0xffffffff81542c50 k [k] page_fault
     0.01%          1          sha1-c  /lib/libc-2.11.1.so          0x00000000000d84a0 u [.] __GI___libc_read
     0.01%          1          sha1-c  /lib/ld-2.11.1.so            0x0000000000007d47 u [.] _dl_init_paths
     0.01%          1          sha1-c  /lib/ld-2.11.1.so            0x0000000000009d6b u [.] do_lookup_x
     0.01%          1  perf_2.6.32-34  [kernel]                     0xffffffff810387be k [k] __ticket_spin_lock
     0.01%          1  perf_2.6.32-34  [kernel]                     0xffffffff8106bdbf k [k] current_fs_time
     0.01%          1  perf_2.6.32-34  [kernel]                     0xffffffff810f147d k [k] perf_ctx_adjust_freq
     0.01%          1  perf_2.6.32-34  [kernel]                     0xffffffff810f3b8c k [k] iov_iter_fault_in_readable
     0.01%          1  perf_2.6.32-34  [kernel]                     0xffffffff8110df86 k [k] __inc_zone_state
     0.01%          1  perf_2.6.32-34  [kernel]                     0xffffffff81140267 k [k] lookup_page_cgroup
     0.01%          1  perf_2.6.32-34  [kernel]                     0xffffffff811dcded k [k] ext4_do_update_inode
     0.01%          1  perf_2.6.32-34  [kernel]                     0xffffffff812bd828 k [k] vsnprintf
     0.01%          1  perf_2.6.32-34  [kernel]                     0xffffffff812bde67 k [k] clear_page_c
     0.01%          1  perf_2.6.32-34  [kernel]                     0xffffffff812be0fd k [k] copy_user_generic_string
     0.01%          1  perf_2.6.32-34  [kernel]                     0xffffffff815427a9 k [k] _spin_lock
     0.01%          1  perf_2.6.32-34  /lib/libc-2.11.1.so          0x0000000000044e2a u [.] _itoa_word
     0.01%          1  perf_2.6.32-34  /lib/libc-2.11.1.so          0x0000000000074ce0 u [.] _IO_link_in_internal
     0.01%          1  perf_2.6.32-34  /lib/libc-2.11.1.so          0x0000000000085252 u [.] __memchr
     0.01%          1              dd  [kernel]                     0xffffffff81012120 k [k] system_call
     0.01%          1              dd  [kernel]                     0xffffffff810121b2 k [k] system_call_fastpath
     0.01%          1              dd  [kernel]                     0xffffffff81037caa k [k] native_write_msr_safe
     0.01%          1              dd  [kernel]                     0xffffffff8104a2c4 k [k] task_waking_fair
     0.01%          1              dd  [kernel]                     0xffffffff8104aeaf k [k] __wake_up_common
     0.01%          1              dd  [kernel]                     0xffffffff8106dc8a k [k] __do_softirq
     0.01%          1              dd  [kernel]                     0xffffffff8108ae86 k [k] sched_clock_cpu
     0.01%          1              dd  [kernel]                     0xffffffff810c9a14 k [k] check_for_new_grace_period
     0.01%          1              dd  [kernel]                     0xffffffff810c9c15 k [k] __call_rcu
     0.01%          1              dd  [kernel]                     0xffffffff810f9661 k [k] zone_watermark_ok
     0.01%          1              dd  [kernel]                     0xffffffff81118426 k [k] find_vma
     0.01%          1              dd  [kernel]                     0xffffffff81118795 k [k] remove_vma
     0.01%          1              dd  [kernel]                     0xffffffff8113d1bb k [k] __mem_cgroup_commit_charge
     0.01%          1              dd  [kernel]                     0xffffffff8114432e k [k] vfs_write
     0.01%          1              dd  [kernel]                     0xffffffff81144bb0 k [k] sys_read
     0.01%          1              dd  [kernel]                     0xffffffff8114575e k [k] fget_light
     0.01%          1              dd  [kernel]                     0xffffffff81149ad4 k [k] set_binfmt
     0.01%          1              dd  [kernel]                     0xffffffff8114c5e0 k [k] pipe_iov_copy_from_user
     0.01%          1              dd  [kernel]                     0xffffffff81150bc8 k [k] __link_path_walk
     0.01%          1              dd  [kernel]                     0xffffffff811541a9 k [k] sys_dup3
     0.01%          1              dd  [kernel]                     0xffffffff81159447 k [k] __d_lookup
     0.01%          1              dd  [kernel]                     0xffffffff8154062e k [k] _cond_resched
     0.01%          1              dd  /lib/libc-2.11.1.so          0x000000000001e9ae u [.] _init
     0.01%          1              dd  /lib/libc-2.11.1.so          0x0000000000030ac0 u [.] alias_compare
     0.01%          1              dd  /lib/libc-2.11.1.so          0x000000000004ceca u [.] ___printf_fp
     0.01%          1              dd  /lib/libc-2.11.1.so          0x0000000000086ab2 u [.] __stpcpy_sse2
     0.01%          1              dd  /lib/libc-2.11.1.so          0x00000000001248ef u [.] __GI__dl_addr
     0.01%          1              dd  /lib/ld-2.11.1.so            0x0000000000009aa1 u [.] check_match.12168
     0.01%          1              dd  /lib/ld-2.11.1.so            0x0000000000009ca4 u [.] do_lookup_x
     0.01%          1              dd  /lib/ld-2.11.1.so            0x0000000000018240 u [.] strcmp
     0.01%          1              dd  /lib/ld-2.11.1.so            0x0000000000018cc7 u [.] memset
     0.01%          1              dd                 7fb163670830  0x00007fb163670830 ! [.] 0x007fb163670830
     0.01%          1            bash  [kernel]                     0xffffffff810f49cc k [k] find_get_page
     0.01%          1            bash  [kernel]                     0xffffffff810f63d1 k [k] filemap_fault
     0.01%          1            bash  [kernel]                     0xffffffff810fc49e k [k] free_hot_cold_page
     0.01%          1            bash  [kernel]                     0xffffffff81112300 k [k] zap_pte_range
     0.01%          1            bash  [kernel]                     0xffffffff81112ea4 k [k] __do_fault
     0.01%          1            bash  [kernel]                     0xffffffff811182d1 k [k] vm_stat_account
     0.01%          1            bash  [kernel]                     0xffffffff8111a973 k [k] do_munmap
     0.01%          1            bash  [kernel]                     0xffffffff8111b631 k [k] do_mmap_pgoff
     0.01%          1            bash  [kernel]                     0xffffffff8111bb09 k [k] change_pte_range
     0.01%          1            bash  [kernel]                     0xffffffff8111c7e1 k [k] move_page_tables
     0.01%          1            bash  [kernel]                     0xffffffff8111e8a5 k [k] page_add_file_rmap
     0.01%          1            bash  [kernel]                     0xffffffff81136920 k [k] __slab_alloc
     0.01%          1            bash  [kernel]                     0xffffffff8113e2e4 k [k] __mem_cgroup_uncharge_common
     0.01%          1            bash  [kernel]                     0xffffffff811423a7 k [k] __dentry_open
     0.01%          1            bash  [kernel]                     0xffffffff8114d640 k [k] create_write_pipe
     0.01%          1            bash  [kernel]                     0xffffffff81150580 k [k] __link_path_walk
     0.01%          1            bash  [kernel]                     0xffffffff811d8a11 k [k] ext4_file_mmap
     0.01%          1            bash  [kernel]                     0xffffffff811def30 k [k] ext4_dirty_inode
     0.01%          1            bash  [kernel]                     0xffffffff8125501e k [k] security_vm_enough_memory
     0.01%          1            bash  [kernel]                     0xffffffff812bde67 k [k] clear_page_c
     0.01%          1            bash  [kernel]                     0xffffffff812bed79 k [k] strncpy_from_user
     0.01%          1            bash  /usr/lib/gconv/ISO8859-1.so  0x0000000000000600 u [.] gconv
     0.01%          1            bash  /lib/libc-2.11.1.so          0x000000000002aa8f u [.] _nl_intern_locale_data
     0.01%          1            bash  /lib/libc-2.11.1.so          0x000000000007ae67 u [.] _int_malloc
     0.01%          1            bash  /lib/libc-2.11.1.so          0x000000000007d98d u [.] _int_realloc
     0.01%          1            bash  /lib/libc-2.11.1.so          0x0000000000082ac0 u [.] __GI_strcpy
     0.01%          1            bash  /lib/ld-2.11.1.so            0x0000000000003d6b u [.] dl_main
     0.01%          1            bash  /lib/ld-2.11.1.so            0x0000000000006a26 u [.] _dl_map_object_from_fd
     0.01%          1            bash  /lib/ld-2.11.1.so            0x0000000000017ee0 u [.] __sigsetjmp
     0.01%          1            bash  /lib/ld-2.11.1.so            0x0000000000018240 u [.] strcmp
     0.01%          1            bash  /bin/bash                    0x0000000000031be6 d [.] coproc_pidchk
     0.01%          1            bash  /bin/bash                    0x00000000000334d0 d [.] execute_command_internal
     0.01%          1            bash  /bin/bash                    0x000000000003ae50 d [.] bind_variable
     0.01%          1            bash  /bin/bash                    0x0000000000056c18 d [.] buffered_getchar
     0.01%          1            bash  /bin/bash                    0x0000000000057f35 d [.] unquoted_glob_pattern_p
     0.01%          1            bash  /bin/bash                    0x000000000008c191 d [.] mbschr
     0.01%          1            bash  /bin/bash                    0x00000000000a9fe7 d [.] 0x000000000a9fe7
     0.01%          1            bash                 7fcc37eeed09  0x00007fcc37eeed09 ! [.] 0x007fcc37eeed09
#
# (For a higher level overview, try: perf report --sort comm,dso)
#

EOF
" >> $perf_out_script

chmod +x $perf_out_script

$ROOT/bin/atos-explore-acf -p ./$perf_out_script -x 70 -Y "-Os noinline cold"

[ -d atos-configurations ]

# REF + Os + O2 + O3
nb_played=`$ROOT/bin/atos lib query | wc -l`

# 2 hot functions for default treshold hot=70, cold=30
# -> only 3 new runs without list of flags to explore (base, ref, best)
[ "`expr $nb_played`" == "7" ]

echo "-O2 -finline-functions" > flags.txt
echo "-O3 -funroll-loops"     >> flags.txt

$ROOT/bin/atos-explore-acf -p ./$perf_out_script -x 70 -Y "-Os noinline cold" -F flags.txt

nb_played=`$ROOT/bin/atos lib query | wc -l`

# 7 +  (base, ref, best) + (2 flag_list * 1hot_functions)
[ "`expr $nb_played`" == "12" ]

# try with perf ref point
$ROOT/bin/atos-explore-acf -p ./$perf_out_script -x 70 OPT-O2

$ROOT/bin/atos-opt -r -a "-O2" -f

$ROOT/bin/atos-explore-acf -p ./$perf_out_script -x 70 OPT-fprofile-use-O2-O2

$ROOT/bin/atos-opt -r -a "-O2" -f -l

$ROOT/bin/atos-explore-acf -p ./$perf_out_script -x 70 OPT-fprofile-use-O2-O2-flto
