cmd_/opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel/gc_hal_kernel_linux.o := aarch64-linux-android-gcc -Wp,-MD,/opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel/.gc_hal_kernel_linux.o.d  -nostdinc -isystem /opt3/marvell/lp5.1-beta1-sp2/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/../lib/gcc/aarch64-linux-android/4.9.x-google/include -I/opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include -Iarch/arm64/include/generated  -I/opt3/marvell/lp5.1-beta1-sp2/kernel/include -Iinclude -I/opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/uapi -Iarch/arm64/include/generated/uapi -I/opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi -Iinclude/generated/uapi -include /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/kconfig.h   -I/opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver -D__KERNEL__ -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -O2 -mgeneral-regs-only -fno-pic -Wframe-larger-than=2048 -fno-stack-protector -Wno-unused-but-set-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO -Werror -fno-pic -DGPU_DRV_SRC_ROOT=/opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver -DUSE_GPU_FREQ=1  -I/opt3/marvell/lp5.1-beta1-sp2/kernel/drivers/staging/android -Idrivers/staging/android -DLINUX -DDRIVER -DDBG=0 -DNO_DMA_COHERENT -DUSE_PLATFORM_DRIVER=1 -DVIVANTE_PROFILER=0 -DVIVANTE_PROFILER_CONTEXT=0 -DANDROID=1 -DENABLE_GPU_CLOCK_BY_DRIVER=1 -DUSE_NEW_LINUX_SIGNAL=0 -DgcdPAGED_MEMORY_CACHEABLE=0 -DgcdNONPAGED_MEMORY_CACHEABLE=0 -DgcdNONPAGED_MEMORY_BUFFERABLE=1 -DgcdCACHE_FUNCTION_UNIMPLEMENTED=0 -DgcdSMP=1 -DgcdENABLE_3D=1 -DgcdENABLE_2D=1 -DgcdENABLE_VG=0 -DgcdENABLE_OUTER_CACHE_PATCH=1 -DgcdFPGA_BUILD=0   -I/opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/inc   -I/opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/kernel   -I/opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/kernel/arch   -I/opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/arch/XAQ2/cmodel/inc   -I/opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/kernel/inc   -I/opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel   -I/opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel/allocator/default/  -DMODULE  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(gc_hal_kernel_linux)"  -D"KBUILD_MODNAME=KBUILD_STR(galcore)" -c -o /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel/gc_hal_kernel_linux.o /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel/gc_hal_kernel_linux.c

source_/opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel/gc_hal_kernel_linux.o := /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel/gc_hal_kernel_linux.c

deps_/opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel/gc_hal_kernel_linux.o := \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel/gc_hal_kernel_linux.h \
    $(wildcard include/config/dove/gpu.h) \
    $(wildcard include/config/enable/gpufreq.h) \
    $(wildcard include/config/iommu/support.h) \
  include/generated/uapi/linux/version.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/init.h \
    $(wildcard include/config/broken/rodata.h) \
    $(wildcard include/config/modules.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
    $(wildcard include/config/kprobes.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/compiler-gcc4.h \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/types.h \
  arch/arm64/include/generated/asm/types.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/asm-generic/types.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/int-ll64.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/asm-generic/int-ll64.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/uapi/asm/bitsperlong.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/bitsperlong.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/asm-generic/bitsperlong.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/posix_types.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/stddef.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/stddef.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/uapi/asm/posix_types.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/asm-generic/posix_types.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/module.h \
    $(wildcard include/config/sysfs.h) \
    $(wildcard include/config/unused/symbols.h) \
    $(wildcard include/config/module/sig.h) \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/tracepoints.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/constructors.h) \
    $(wildcard include/config/debug/set/module/ronx.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/const.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/stat.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/stat.h \
    $(wildcard include/config/compat.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/uapi/asm/stat.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/asm-generic/stat.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/compat.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/sched.h \
    $(wildcard include/config/runtime/compcache.h) \
    $(wildcard include/config/sched/debug.h) \
    $(wildcard include/config/prove/rcu.h) \
    $(wildcard include/config/no/hz/common.h) \
    $(wildcard include/config/lockup/detector.h) \
    $(wildcard include/config/hardlockup/detector/other/cpu.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/core/dump/default/elf/headers.h) \
    $(wildcard include/config/sched/autogroup.h) \
    $(wildcard include/config/virt/cpu/accounting/native.h) \
    $(wildcard include/config/bsd/process/acct.h) \
    $(wildcard include/config/taskstats.h) \
    $(wildcard include/config/audit.h) \
    $(wildcard include/config/cgroups.h) \
    $(wildcard include/config/inotify/user.h) \
    $(wildcard include/config/fanotify.h) \
    $(wildcard include/config/epoll.h) \
    $(wildcard include/config/posix/mqueue.h) \
    $(wildcard include/config/keys.h) \
    $(wildcard include/config/perf/events.h) \
    $(wildcard include/config/schedstats.h) \
    $(wildcard include/config/task/delay/acct.h) \
    $(wildcard include/config/fair/group/sched.h) \
    $(wildcard include/config/rt/group/sched.h) \
    $(wildcard include/config/cgroup/sched.h) \
    $(wildcard include/config/preempt/notifiers.h) \
    $(wildcard include/config/blk/dev/io/trace.h) \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/tree/preempt/rcu.h) \
    $(wildcard include/config/rcu/boost.h) \
    $(wildcard include/config/compat/brk.h) \
    $(wildcard include/config/cc/stackprotector.h) \
    $(wildcard include/config/virt/cpu/accounting/gen.h) \
    $(wildcard include/config/sysvipc.h) \
    $(wildcard include/config/detect/hung/task.h) \
    $(wildcard include/config/auditsyscall.h) \
    $(wildcard include/config/rt/mutexes.h) \
    $(wildcard include/config/debug/mutexes.h) \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/block.h) \
    $(wildcard include/config/task/xacct.h) \
    $(wildcard include/config/cpusets.h) \
    $(wildcard include/config/futex.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/numa/balancing.h) \
    $(wildcard include/config/fault/injection.h) \
    $(wildcard include/config/latencytop.h) \
    $(wildcard include/config/function/graph/tracer.h) \
    $(wildcard include/config/memcg.h) \
    $(wildcard include/config/have/hw/breakpoint.h) \
    $(wildcard include/config/uprobes.h) \
    $(wildcard include/config/bcache.h) \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/have/unstable/sched/clock.h) \
    $(wildcard include/config/irq/time/accounting.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/no/hz/full.h) \
    $(wildcard include/config/proc/fs.h) \
    $(wildcard include/config/stack/growsup.h) \
    $(wildcard include/config/debug/stack/usage.h) \
    $(wildcard include/config/preempt/count.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/mm/owner.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/sched.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/uapi/asm/param.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/param.h \
    $(wildcard include/config/hz.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/asm-generic/param.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/capability.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/capability.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/ring/buffer.h) \
  /opt3/marvell/lp5.1-beta1-sp2/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/lib/gcc/aarch64-linux-android/4.9.x-google/include/stdarg.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/linkage.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/stringify.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/export.h \
    $(wildcard include/config/have/underscore/symbol/prefix.h) \
    $(wildcard include/config/modversions.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/linkage.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/bitops.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/bitops.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/barrier.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/bitops/builtin-__ffs.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/bitops/builtin-ffs.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/bitops/builtin-__fls.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/bitops/builtin-fls.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/bitops/ffz.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/bitops/fls64.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/bitops/find.h \
    $(wildcard include/config/generic/find/first/bit.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/bitops/sched.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/bitops/hweight.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/bitops/arch_hweight.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/bitops/const_hweight.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/bitops/lock.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/bitops/non-atomic.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/bitops/le.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/uapi/asm/byteorder.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/byteorder/little_endian.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/byteorder/little_endian.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/swab.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/swab.h \
  arch/arm64/include/generated/asm/swab.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/asm-generic/swab.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/byteorder/generic.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/typecheck.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/printk.h \
    $(wildcard include/config/early/printk.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/kern_levels.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/dynamic_debug.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/kernel.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/sysinfo.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/timex.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/timex.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/cache.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/cachetype.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/cputype.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/seqlock.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/context/tracking.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/thread_info.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/bug.h \
  arch/arm64/include/generated/asm/bug.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/thread_info.h \
    $(wildcard include/config/arm64/64k/pages.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/irqflags.h \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/irqflags.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/ptrace.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/uapi/asm/ptrace.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/hwcap.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/uapi/asm/hwcap.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/bottom_half.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/spinlock_types.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/spinlock_types.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/lockdep.h \
    $(wildcard include/config/lock/stat.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/rwlock_types.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/spinlock.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/processor.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/string.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/string.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/fpsimd.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/hw_breakpoint.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/rwlock.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/spinlock_api_smp.h \
    $(wildcard include/config/inline/spin/lock.h) \
    $(wildcard include/config/inline/spin/lock/bh.h) \
    $(wildcard include/config/inline/spin/lock/irq.h) \
    $(wildcard include/config/inline/spin/lock/irqsave.h) \
    $(wildcard include/config/inline/spin/trylock.h) \
    $(wildcard include/config/inline/spin/trylock/bh.h) \
    $(wildcard include/config/uninline/spin/unlock.h) \
    $(wildcard include/config/inline/spin/unlock/bh.h) \
    $(wildcard include/config/inline/spin/unlock/irq.h) \
    $(wildcard include/config/inline/spin/unlock/irqrestore.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/rwlock_api_smp.h \
    $(wildcard include/config/inline/read/lock.h) \
    $(wildcard include/config/inline/write/lock.h) \
    $(wildcard include/config/inline/read/lock/bh.h) \
    $(wildcard include/config/inline/write/lock/bh.h) \
    $(wildcard include/config/inline/read/lock/irq.h) \
    $(wildcard include/config/inline/write/lock/irq.h) \
    $(wildcard include/config/inline/read/lock/irqsave.h) \
    $(wildcard include/config/inline/write/lock/irqsave.h) \
    $(wildcard include/config/inline/read/trylock.h) \
    $(wildcard include/config/inline/write/trylock.h) \
    $(wildcard include/config/inline/read/unlock.h) \
    $(wildcard include/config/inline/write/unlock.h) \
    $(wildcard include/config/inline/read/unlock/bh.h) \
    $(wildcard include/config/inline/write/unlock/bh.h) \
    $(wildcard include/config/inline/read/unlock/irq.h) \
    $(wildcard include/config/inline/write/unlock/irq.h) \
    $(wildcard include/config/inline/read/unlock/irqrestore.h) \
    $(wildcard include/config/inline/write/unlock/irqrestore.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/atomic.h \
    $(wildcard include/config/arch/has/atomic/or.h) \
    $(wildcard include/config/generic/atomic64.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/atomic.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/cmpxchg.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/atomic-long.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/math64.h \
  arch/arm64/include/generated/asm/div64.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/div64.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/time.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/param.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/timex.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/arch_timer.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/clocksource/arm_arch_timer.h \
    $(wildcard include/config/arm/arch/timer.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/clocksource.h \
    $(wildcard include/config/arch/clocksource/data.h) \
    $(wildcard include/config/clocksource/watchdog.h) \
    $(wildcard include/config/clksrc/of.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/timer.h \
    $(wildcard include/config/timer/stats.h) \
    $(wildcard include/config/debug/objects/timers.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/ktime.h \
    $(wildcard include/config/ktime/scalar.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/jiffies.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/debug/objects/free.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/io.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/blk_types.h \
    $(wildcard include/config/blk/cgroup.h) \
    $(wildcard include/config/blk/dev/integrity.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/pgtable.h \
    $(wildcard include/config/transparent/hugepage.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/proc-fns.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/page.h \
    $(wildcard include/config/have/arch/pfn/valid.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/pgtable-3level-types.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/pgtable-nopud.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/memory.h \
  arch/arm64/include/generated/asm/sizes.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/sizes.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/sizes.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/memory_model.h \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/getorder.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/pgtable-hwdef.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/pgtable-3level-hwdef.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/pgtable.h \
    $(wildcard include/config/arch/uses/numa/prot/none.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/mm_types.h \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/stacktrace.h) \
    $(wildcard include/config/have/cmpxchg/double.h) \
    $(wildcard include/config/have/aligned/struct/page.h) \
    $(wildcard include/config/want/page/debug/flags.h) \
    $(wildcard include/config/kmemcheck.h) \
    $(wildcard include/config/aio.h) \
    $(wildcard include/config/mmu/notifier.h) \
    $(wildcard include/config/compaction.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/auxvec.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/auxvec.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/uapi/asm/auxvec.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/rbtree.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/rwsem.h \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/rwsem-spinlock.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/completion.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/wait.h \
  arch/arm64/include/generated/asm/current.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/current.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/wait.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/cpumask.h \
    $(wildcard include/config/debug/per/cpu/maps.h) \
    $(wildcard include/config/disable/obsolete/cpumask/functions.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/bitmap.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/page-debug-flags.h \
    $(wildcard include/config/page/poisoning.h) \
    $(wildcard include/config/page/guard.h) \
    $(wildcard include/config/page/debug/something/else.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/uprobes.h \
    $(wildcard include/config/arch/supports/uprobes.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/errno.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/errno.h \
  arch/arm64/include/generated/asm/errno.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/asm-generic/errno.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/asm-generic/errno-base.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/page-flags-layout.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  include/generated/bounds.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/sparsemem.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/mmu.h \
  arch/arm64/include/generated/asm/early_ioremap.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/early_ioremap.h \
    $(wildcard include/config/generic/early/ioremap.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/xen/xen.h \
    $(wildcard include/config/xen.h) \
    $(wildcard include/config/xen/dom0.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/iomap.h \
    $(wildcard include/config/has/ioport.h) \
    $(wildcard include/config/pci.h) \
    $(wildcard include/config/generic/iomap.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/pci_iomap.h \
    $(wildcard include/config/no/generic/pci/ioport/map.h) \
    $(wildcard include/config/generic/pci/iomap.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/timex.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/nodemask.h \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/movable/node.h) \
  arch/arm64/include/generated/asm/cputime.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/cputime.h \
    $(wildcard include/config/virt/cpu/accounting.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/cputime_jiffies.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/smp.h \
    $(wildcard include/config/use/generic/smp/helpers.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/smp.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/sem.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/rcupdate.h \
    $(wildcard include/config/rcu/torture/test.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/rcu/trace.h) \
    $(wildcard include/config/rcu/user/qs.h) \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/tiny/preempt/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/rcu/nocb/cpu.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/rcutree.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/sem.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/ipc.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/uidgid.h \
    $(wildcard include/config/uidgid/strict/type/checks.h) \
    $(wildcard include/config/user/ns.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/highuid.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/ipc.h \
  arch/arm64/include/generated/asm/ipcbuf.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/asm-generic/ipcbuf.h \
  arch/arm64/include/generated/asm/sembuf.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/asm-generic/sembuf.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/signal.h \
    $(wildcard include/config/old/sigaction.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/signal.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/uapi/asm/signal.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/signal.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/asm-generic/signal.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/asm-generic/signal-defs.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/uapi/asm/sigcontext.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/uapi/asm/siginfo.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/siginfo.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/asm-generic/siginfo.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/pid.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/pfn.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/percpu.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/percpu.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/topology.h \
    $(wildcard include/config/sched/smt.h) \
    $(wildcard include/config/sched/mc.h) \
    $(wildcard include/config/sched/book.h) \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/cma.h) \
    $(wildcard include/config/memory/isolation.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/have/memblock/node/map.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/no/bootmem.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/nodes/span/other/nodes.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/memory_hotplug.h \
    $(wildcard include/config/memory/hotremove.h) \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
    $(wildcard include/config/have/bootmem/info/node.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/notifier.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/mutex.h \
    $(wildcard include/config/mutex/spin/on/owner.h) \
    $(wildcard include/config/have/arch/mutex/cpu/relax.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/srcu.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/topology.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/topology.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/proportions.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/percpu_counter.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/seccomp.h \
    $(wildcard include/config/seccomp.h) \
    $(wildcard include/config/seccomp/filter.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/seccomp.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/rculist.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/rtmutex.h \
    $(wildcard include/config/debug/rt/mutexes.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/plist.h \
    $(wildcard include/config/debug/pi/list.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/resource.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/resource.h \
  arch/arm64/include/generated/asm/resource.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/resource.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/asm-generic/resource.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/hrtimer.h \
    $(wildcard include/config/high/res/timers.h) \
    $(wildcard include/config/timerfd.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/timerqueue.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/task_io_accounting.h \
    $(wildcard include/config/task/io/accounting.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/latencytop.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/cred.h \
    $(wildcard include/config/debug/credentials.h) \
    $(wildcard include/config/security.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/key.h \
    $(wildcard include/config/sysctl.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/sysctl.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/sysctl.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/selinux.h \
    $(wildcard include/config/security/selinux.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/llist.h \
    $(wildcard include/config/arch/have/nmi/safe/cmpxchg.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/gfp.h \
    $(wildcard include/config/pm/sleep.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/mmdebug.h \
    $(wildcard include/config/debug/vm.h) \
    $(wildcard include/config/debug/virtual.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/ptrace.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/err.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/ptrace.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/stat.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/kmod.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/elf.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/elf.h \
  arch/arm64/include/generated/asm/user.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/user.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/elf.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/elf-em.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/kobject.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/sysfs.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/kobject_ns.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/kref.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/ppc64.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/tracepoint.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/static_key.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/jump_label.h \
    $(wildcard include/config/jump/label.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/module.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/module.h \
    $(wildcard include/config/have/mod/arch/specific.h) \
    $(wildcard include/config/modules/use/elf/rel.h) \
    $(wildcard include/config/modules/use/elf/rela.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/fs.h \
    $(wildcard include/config/fs/posix/acl.h) \
    $(wildcard include/config/quota.h) \
    $(wildcard include/config/fsnotify.h) \
    $(wildcard include/config/ima.h) \
    $(wildcard include/config/debug/writecount.h) \
    $(wildcard include/config/file/locking.h) \
    $(wildcard include/config/fs/xip.h) \
    $(wildcard include/config/migration.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/kdev_t.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/kdev_t.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/dcache.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/rculist_bl.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/list_bl.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/bit_spinlock.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/path.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/radix-tree.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/semaphore.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/fiemap.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/shrinker.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/migrate_mode.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/percpu-rwsem.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/fs.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/limits.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/ioctl.h \
  arch/arm64/include/generated/asm/ioctl.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/ioctl.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/asm-generic/ioctl.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/quota.h \
    $(wildcard include/config/quota/netlink/interface.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/dqblk_xfs.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/dqblk_v1.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/dqblk_v2.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/dqblk_qtree.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/projid.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/quota.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/nfs_fs_i.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/fcntl.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/fcntl.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/uapi/asm/fcntl.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/asm-generic/fcntl.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/mm.h \
    $(wildcard include/config/x86.h) \
    $(wildcard include/config/ppc.h) \
    $(wildcard include/config/parisc.h) \
    $(wildcard include/config/metag.h) \
    $(wildcard include/config/ksm.h) \
    $(wildcard include/config/debug/vm/rb.h) \
    $(wildcard include/config/debug/pagealloc.h) \
    $(wildcard include/config/hibernation.h) \
    $(wildcard include/config/hugetlbfs.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/debug_locks.h \
    $(wildcard include/config/debug/locking/api/selftests.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/range.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/page-flags.h \
    $(wildcard include/config/pageflags/extended.h) \
    $(wildcard include/config/arch/uses/pg/uncached.h) \
    $(wildcard include/config/memory/failure.h) \
    $(wildcard include/config/swap.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/huge_mm.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/vmstat.h \
    $(wildcard include/config/vm/event/counters.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/vm_event_item.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/interrupt.h \
    $(wildcard include/config/generic/hardirqs.h) \
    $(wildcard include/config/irq/forced/threading.h) \
    $(wildcard include/config/generic/irq/probe.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/irqreturn.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/irqnr.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/irqnr.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/hardirq.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/ftrace_irq.h \
    $(wildcard include/config/ftrace/nmi/enter.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/vtime.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/hardirq.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/irq.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/irq.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/irq_cpustat.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/vmalloc.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/dma-mapping.h \
    $(wildcard include/config/has/dma.h) \
    $(wildcard include/config/arch/has/dma/set/coherent/mask.h) \
    $(wildcard include/config/have/dma/attrs.h) \
    $(wildcard include/config/need/dma/map/state.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/device.h \
    $(wildcard include/config/debug/devres.h) \
    $(wildcard include/config/acpi.h) \
    $(wildcard include/config/pinctrl.h) \
    $(wildcard include/config/devtmpfs.h) \
    $(wildcard include/config/sysfs/deprecated.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/ioport.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/klist.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/pinctrl/devinfo.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/pinctrl/consumer.h \
    $(wildcard include/config/pinconf.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/seq_file.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/pinctrl/pinctrl-state.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/pm.h \
    $(wildcard include/config/vt/console/sleep.h) \
    $(wildcard include/config/pm.h) \
    $(wildcard include/config/pm/runtime.h) \
    $(wildcard include/config/pm/clk.h) \
    $(wildcard include/config/pm/generic/domains.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/ratelimit.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/device.h \
    $(wildcard include/config/iommu/api.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/pm_wakeup.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/dma-attrs.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/dma-direction.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/scatterlist.h \
    $(wildcard include/config/debug/sg.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/scatterlist.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/scatterlist.h \
    $(wildcard include/config/need/sg/dma/length.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/dma-mapping.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/dma-coherent.h \
    $(wildcard include/config/have/generic/dma/coherent.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/xen/hypervisor.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/../../arm/include/asm/xen/hypervisor.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/asm-generic/dma-mapping-common.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/kmemcheck.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/dma-debug.h \
    $(wildcard include/config/dma/api/debug.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/kthread.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/idr.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/uaccess.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/compiler.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/clk.h \
    $(wildcard include/config/common/clk.h) \
    $(wildcard include/config/have/clk/prepare.h) \
    $(wildcard include/config/have/clk.h) \
    $(wildcard include/config/of.h) \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/inc/gc_hal.h \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/inc/gc_hal_rename.h \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/inc/gc_hal_types.h \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/inc/gc_hal_version.h \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/inc/gc_hal_options.h \
    $(wildcard include/config/sync.h) \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/inc/gc_hal_options_mrvl.h \
    $(wildcard include/config/mach/ttd2/fpga.h) \
    $(wildcard include/config/mach/eden/fpga.h) \
    $(wildcard include/config/mach/pxa1928/fpga.h) \
    $(wildcard include/config/cpu/pxa1986.h) \
    $(wildcard include/config/arm64.h) \
    $(wildcard include/config/gpu/reserve/mem.h) \
    $(wildcard include/config/enable/gc/trace.h) \
    $(wildcard include/config/power/validation.h) \
    $(wildcard include/config/shader/clk/control.h) \
    $(wildcard include/config/enable/qos/support.h) \
    $(wildcard include/config/cpu/pxa1928.h) \
    $(wildcard include/config/enable/gputex.h) \
    $(wildcard include/config/proc.h) \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/inc/gc_hal_enum.h \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/inc/gc_hal_base.h \
    $(wildcard include/config/format/info.h) \
    $(wildcard include/config/.h) \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/inc/gc_hal_dump.h \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/inc/gc_hal_profiler.h \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/inc/gc_hal_driver.h \
    $(wildcard include/config/power/management.h) \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/inc/gc_hal_statistics.h \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/inc/gc_hal_driver.h \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/kernel/gc_hal_kernel.h \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/kernel/gc_hal_kernel_features.h \
    $(wildcard include/config/mmp/pm/domain.h) \
    $(wildcard include/config/power/clock/separated.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/cputype.h \
    $(wildcard include/config/cpu/pxa168.h) \
    $(wildcard include/config/cpu/pxa910.h) \
    $(wildcard include/config/cpu/mmp2.h) \
    $(wildcard include/config/cpu/pxa988.h) \
    $(wildcard include/config/arm.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/regs-addr.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/io.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/of.h \
    $(wildcard include/config/sparc.h) \
    $(wildcard include/config/of/dynamic.h) \
    $(wildcard include/config/attach/node.h) \
    $(wildcard include/config/detach/node.h) \
    $(wildcard include/config/add/property.h) \
    $(wildcard include/config/remove/property.h) \
    $(wildcard include/config/update/property.h) \
    $(wildcard include/config/proc/devicetree.h) \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/mod_devicetable.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/linux/uuid.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/include/uapi/linux/uuid.h \
  /opt3/marvell/lp5.1-beta1-sp2/kernel/arch/arm64/include/asm/prom.h \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/kernel/arch/gc_hal_kernel_hardware.h \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel/gc_hal_kernel_mutex.h \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel/gc_hal_kernel_platform.h \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel/gc_hal_kernel_device.h \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel/gc_hal_kernel_debugfs.h \
  /opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel/gc_hal_kernel_os.h \

/opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel/gc_hal_kernel_linux.o: $(deps_/opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel/gc_hal_kernel_linux.o)

$(deps_/opt3/marvell/lp5.1-beta1-sp2/vendor/marvell/generic/graphics/driver/hal/os/linux/kernel/gc_hal_kernel_linux.o):
