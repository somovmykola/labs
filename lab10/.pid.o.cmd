cmd_/nfs/u50/somovm/lab10/pid.o := gcc -Wp,-MD,/nfs/u50/somovm/lab10/.pid.o.d  -nostdinc -isystem /usr/lib/gcc/x86_64-redhat-linux/4.1.2/include -D__KERNEL__ -Iinclude  -include include/linux/autoconf.h -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Os  -mtune=generic -m64 -mno-red-zone -mcmodel=kernel -pipe -Wno-sign-compare -fno-asynchronous-unwind-tables -funit-at-a-time -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -maccumulate-outgoing-args -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -fomit-frame-pointer -g  -fno-stack-protector -Wdeclaration-after-statement -Wno-pointer-sign -I/usr/realtime/include -I/usr/include/  -DMODULE -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(pid)"  -D"KBUILD_MODNAME=KBUILD_STR(pid)" -c -o /nfs/u50/somovm/lab10/pid.o /nfs/u50/somovm/lab10/pid.c

deps_/nfs/u50/somovm/lab10/pid.o := \
  /nfs/u50/somovm/lab10/pid.c \
  include/linux/module.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/unused/symbols.h) \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/sysfs.h) \
  include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  include/linux/stddef.h \
  include/linux/compiler.h \
    $(wildcard include/config/enable/must/check.h) \
  include/linux/compiler-gcc4.h \
    $(wildcard include/config/forced/inlining.h) \
  include/linux/compiler-gcc.h \
  include/linux/poison.h \
  include/linux/prefetch.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbd.h) \
    $(wildcard include/config/lsf.h) \
    $(wildcard include/config/resources/64bit.h) \
  include/linux/posix_types.h \
  include/asm/posix_types.h \
  include/asm/types.h \
  include/asm/processor.h \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/x86/vsmp.h) \
  include/asm/segment.h \
  include/asm/cache.h \
    $(wildcard include/config/x86/l1/cache/shift.h) \
  include/asm/page.h \
    $(wildcard include/config/physical/start.h) \
    $(wildcard include/config/flatmem.h) \
  include/linux/const.h \
  include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  include/asm-generic/bug.h \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem.h) \
    $(wildcard include/config/out/of/line/pfn/to/page.h) \
  include/asm-generic/page.h \
  include/asm/sigcontext.h \
  include/asm/cpufeature.h \
  include/asm-i386/cpufeature.h \
  include/linux/bitops.h \
  include/asm/bitops.h \
  include/asm/alternative.h \
    $(wildcard include/config/paravirt.h) \
  include/asm-generic/bitops/sched.h \
  include/asm-generic/bitops/hweight.h \
  include/asm-generic/bitops/ext2-non-atomic.h \
  include/asm-generic/bitops/le.h \
  include/asm/byteorder.h \
  include/linux/byteorder/little_endian.h \
  include/linux/byteorder/swab.h \
  include/linux/byteorder/generic.h \
  include/asm-generic/bitops/minix.h \
  include/asm/required-features.h \
    $(wildcard include/config/x86/use/3dnow.h) \
  include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  include/asm/msr.h \
  include/asm/msr-index.h \
  include/asm-i386/msr-index.h \
  include/linux/errno.h \
  include/asm/errno.h \
  include/asm-generic/errno.h \
  include/asm-generic/errno-base.h \
  include/asm/current.h \
  include/asm/pda.h \
    $(wildcard include/config/cc/stackprotector.h) \
  include/linux/cache.h \
  include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/spinlock/sleep.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/numa.h) \
  /usr/lib/gcc/x86_64-redhat-linux/4.1.2/include/stdarg.h \
  include/linux/linkage.h \
  include/asm/linkage.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/ipipe_base.h \
    $(wildcard include/config/ipipe.h) \
    $(wildcard include/config/ipipe/debug/context.h) \
    $(wildcard include/config/generic/clockevents.h) \
  include/asm/ipipe_base.h \
  include/asm/system.h \
    $(wildcard include/config/unordered/io.h) \
  include/asm/cmpxchg.h \
  include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
    $(wildcard include/config/x86.h) \
  include/asm/irqflags.h \
    $(wildcard include/config/ipipe/trace/irqsoff.h) \
  include/asm/processor-flags.h \
  include/asm-i386/processor-flags.h \
  include/linux/ipipe_trace.h \
    $(wildcard include/config/ipipe/trace.h) \
    $(wildcard include/config/ipipe/trace/panic.h) \
  include/asm/mmsegment.h \
  include/asm/percpu.h \
  include/linux/personality.h \
  include/linux/cpumask.h \
    $(wildcard include/config/hotplug/cpu.h) \
  include/linux/bitmap.h \
  include/linux/string.h \
  include/asm/string.h \
  include/linux/stat.h \
  include/asm/stat.h \
  include/linux/time.h \
  include/linux/seqlock.h \
  include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
  include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  include/linux/thread_info.h \
  include/asm/thread_info.h \
    $(wildcard include/config/debug/stack/usage.h) \
  include/linux/stringify.h \
  include/linux/bottom_half.h \
  include/linux/spinlock_types.h \
  include/asm/spinlock_types.h \
  include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
    $(wildcard include/config/generic/hardirqs.h) \
    $(wildcard include/config/prove/locking.h) \
  include/asm/spinlock.h \
  include/asm/atomic.h \
  include/asm-generic/atomic.h \
  include/asm/rwlock.h \
  include/linux/spinlock_api_smp.h \
  include/linux/kmod.h \
    $(wildcard include/config/kmod.h) \
  include/linux/elf.h \
  include/linux/auxvec.h \
  include/asm/auxvec.h \
  include/linux/elf-em.h \
  include/asm/elf.h \
  include/asm/ptrace.h \
  include/asm/ptrace-abi.h \
  include/asm/user.h \
  include/linux/kobject.h \
    $(wildcard include/config/hotplug.h) \
  include/linux/sysfs.h \
  include/linux/kref.h \
  include/linux/wait.h \
  include/linux/moduleparam.h \
  include/linux/init.h \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/acpi/hotplug/memory.h) \
  include/asm/local.h \
  include/linux/percpu.h \
  include/linux/slab.h \
    $(wildcard include/config/slab/debug.h) \
    $(wildcard include/config/slub.h) \
    $(wildcard include/config/slob.h) \
    $(wildcard include/config/debug/slab.h) \
  include/linux/gfp.h \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/highmem.h) \
  include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/arch/populates/node/map.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/nodes/span/other/nodes.h) \
    $(wildcard include/config/holes/in/zone.h) \
  include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  include/linux/nodemask.h \
  include/linux/memory_hotplug.h \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
  include/linux/notifier.h \
  include/linux/mutex.h \
    $(wildcard include/config/debug/mutexes.h) \
  include/linux/rwsem.h \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  include/linux/rwsem-spinlock.h \
  include/linux/srcu.h \
  include/linux/topology.h \
    $(wildcard include/config/sched/smt.h) \
    $(wildcard include/config/sched/mc.h) \
  include/linux/smp.h \
  include/asm/smp.h \
  include/asm/mpspec.h \
    $(wildcard include/config/acpi.h) \
  include/asm/apic.h \
    $(wildcard include/config/x86/good/apic.h) \
  include/linux/pm.h \
    $(wildcard include/config/suspend.h) \
    $(wildcard include/config/pm/sleep.h) \
  include/linux/delay.h \
  include/asm/delay.h \
  include/asm/fixmap.h \
  include/asm/apicdef.h \
  include/asm/vsyscall.h \
    $(wildcard include/config/generic/time.h) \
  include/asm/io_apic.h \
  include/asm/topology.h \
    $(wildcard include/config/acpi/numa.h) \
  include/asm-generic/topology.h \
  include/asm/mmzone.h \
    $(wildcard include/config/numa/emu.h) \
  include/asm/sparsemem.h \
  include/linux/slab_def.h \
  include/linux/kmalloc_sizes.h \
  include/asm/module.h \
  include/linux/version.h \
  include/asm/io.h \
  include/linux/vmalloc.h \
  include/asm-generic/iomap.h \
  /usr/realtime/include/rtai.h \
  /usr/realtime/include/rtai_sanity.h \
  /usr/realtime/include/asm/rtai.h \
  /usr/realtime/include/rtai_config.h \
    $(wildcard include/config/kbuild.h) \
    $(wildcard include/config/rtai.h) \
    $(wildcard include/config/rtai/16550a/any.h) \
    $(wildcard include/config/rtai/16550a/mmio.h) \
    $(wildcard include/config/rtai/16550a/pio.h) \
    $(wildcard include/config/rtai/adeos.h) \
    $(wildcard include/config/rtai/align/linux/priority.h) \
    $(wildcard include/config/rtai/allow/rr.h) \
    $(wildcard include/config/rtai/bits.h) \
    $(wildcard include/config/rtai/bits/builtin.h) \
    $(wildcard include/config/rtai/build/string.h) \
    $(wildcard include/config/rtai/busy/time/align.h) \
    $(wildcard include/config/rtai/cal/freqs/fact.h) \
    $(wildcard include/config/rtai/clock/realtime.h) \
    $(wildcard include/config/rtai/compiler.h) \
    $(wildcard include/config/rtai/cpus.h) \
    $(wildcard include/config/rtai/debug/rtdm.h) \
    $(wildcard include/config/rtai/diag/tsc/sync.h) \
    $(wildcard include/config/rtai/dont/dispatch/core/irqs.h) \
    $(wildcard include/config/rtai/drivers/16550a.h) \
    $(wildcard include/config/rtai/drivers/serial.h) \
    $(wildcard include/config/rtai/fifos.h) \
    $(wildcard include/config/rtai/fifos/builtin.h) \
    $(wildcard include/config/rtai/fifos/template.h) \
    $(wildcard include/config/rtai/fpu/support.h) \
    $(wildcard include/config/rtai/full/prinher.h) \
    $(wildcard include/config/rtai/hal/preempt.h) \
    $(wildcard include/config/rtai/host/string.h) \
    $(wildcard include/config/rtai/immediate/linux/syscall.h) \
    $(wildcard include/config/rtai/internal/leds/support.h) \
    $(wildcard include/config/rtai/internal/lxrt/inline.h) \
    $(wildcard include/config/rtai/internal/lxrt/support.h) \
    $(wildcard include/config/rtai/ipipe.h) \
    $(wildcard include/config/rtai/kstack/heapsz.h) \
    $(wildcard include/config/rtai/leds.h) \
    $(wildcard include/config/rtai/leds/builtin.h) \
    $(wildcard include/config/rtai/long/timed/list.h) \
    $(wildcard include/config/rtai/lxrt/inline.h) \
    $(wildcard include/config/rtai/lxrt/use/linux/syscall.h) \
    $(wildcard include/config/rtai/maintainer.h) \
    $(wildcard include/config/rtai/maintainer/pgm.h) \
    $(wildcard include/config/rtai/maintainer/pma.h) \
    $(wildcard include/config/rtai/malloc.h) \
    $(wildcard include/config/rtai/malloc/builtin.h) \
    $(wildcard include/config/rtai/malloc/heapsz.h) \
    $(wildcard include/config/rtai/malloc/vmalloc.h) \
    $(wildcard include/config/rtai/master/tsc/cpu.h) \
    $(wildcard include/config/rtai/math.h) \
    $(wildcard include/config/rtai/math/builtin.h) \
    $(wildcard include/config/rtai/math/c99.h) \
    $(wildcard include/config/rtai/mbx.h) \
    $(wildcard include/config/rtai/mbx/builtin.h) \
    $(wildcard include/config/rtai/monitor/exectime.h) \
    $(wildcard include/config/rtai/mount/on/load.h) \
    $(wildcard include/config/rtai/mq.h) \
    $(wildcard include/config/rtai/mq/builtin.h) \
    $(wildcard include/config/rtai/msg.h) \
    $(wildcard include/config/rtai/msg/builtin.h) \
    $(wildcard include/config/rtai/netrpc.h) \
    $(wildcard include/config/rtai/netrpc/builtin.h) \
    $(wildcard include/config/rtai/netrpc/rtnet.h) \
    $(wildcard include/config/rtai/one/shot.h) \
    $(wildcard include/config/rtai/revision/level.h) \
    $(wildcard include/config/rtai/rtc/freq.h) \
    $(wildcard include/config/rtai/rtdm.h) \
    $(wildcard include/config/rtai/rtdm/fd/max.h) \
    $(wildcard include/config/rtai/rtdm/select.h) \
    $(wildcard include/config/rtai/rtdm/shirq.h) \
    $(wildcard include/config/rtai/rt/poll.h) \
    $(wildcard include/config/rtai/rt/poll/on/stack.h) \
    $(wildcard include/config/rtai/sched/8254/latency.h) \
    $(wildcard include/config/rtai/sched/apic/latency.h) \
    $(wildcard include/config/rtai/sched/isr/lock.h) \
    $(wildcard include/config/rtai/sched/lxrt/numslots.h) \
    $(wildcard include/config/rtai/sem.h) \
    $(wildcard include/config/rtai/sem/builtin.h) \
    $(wildcard include/config/rtai/shm.h) \
    $(wildcard include/config/rtai/shm/builtin.h) \
    $(wildcard include/config/rtai/tasklets.h) \
    $(wildcard include/config/rtai/tasklets/builtin.h) \
    $(wildcard include/config/rtai/task/switch/signal.h) \
    $(wildcard include/config/rtai/tbx.h) \
    $(wildcard include/config/rtai/tbx/builtin.h) \
    $(wildcard include/config/rtai/trace.h) \
    $(wildcard include/config/rtai/tune/tsc/sync.h) \
    $(wildcard include/config/rtai/use/newerr.h) \
    $(wildcard include/config/rtai/use/tlsf.h) \
    $(wildcard include/config/rtai/usi.h) \
    $(wildcard include/config/rtai/usi/builtin.h) \
    $(wildcard include/config/rtai/version/major.h) \
    $(wildcard include/config/rtai/version/minor.h) \
    $(wildcard include/config/rtai/wd.h) \
  /usr/realtime/include/asm/rtai_hal.h \
    $(wildcard include/config/x86/local/apic.h) \
    $(wildcard include/config/x86/io/apic.h) \
  /usr/realtime/include/rtai_hal_names.h \
    $(wildcard include/config/ppc.h) \
    $(wildcard include/config/adeos/nothreads.h) \
  /usr/realtime/include/asm/rtai_vectors.h \
  include/linux/interrupt.h \
    $(wildcard include/config/high/res/timers.h) \
    $(wildcard include/config/generic/irq/probe.h) \
    $(wildcard include/config/proc/fs.h) \
  include/linux/irqreturn.h \
  include/linux/hardirq.h \
    $(wildcard include/config/preempt/bkl.h) \
    $(wildcard include/config/virt/cpu/accounting.h) \
  include/linux/smp_lock.h \
    $(wildcard include/config/lock/kernel.h) \
  include/linux/sched.h \
    $(wildcard include/config/sched/debug.h) \
    $(wildcard include/config/no/hz.h) \
    $(wildcard include/config/detect/softlockup.h) \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/keys.h) \
    $(wildcard include/config/bsd/process/acct.h) \
    $(wildcard include/config/taskstats.h) \
    $(wildcard include/config/audit.h) \
    $(wildcard include/config/inotify/user.h) \
    $(wildcard include/config/schedstats.h) \
    $(wildcard include/config/task/delay/acct.h) \
    $(wildcard include/config/fair/group/sched.h) \
    $(wildcard include/config/blk/dev/io/trace.h) \
    $(wildcard include/config/sysvipc.h) \
    $(wildcard include/config/rt/mutexes.h) \
    $(wildcard include/config/task/xacct.h) \
    $(wildcard include/config/cpusets.h) \
    $(wildcard include/config/compat.h) \
    $(wildcard include/config/fault/injection.h) \
  include/asm/param.h \
    $(wildcard include/config/hz.h) \
  include/linux/capability.h \
  include/linux/timex.h \
  include/asm/timex.h \
  include/asm/8253pit.h \
  include/asm/tsc.h \
  include/asm-i386/tsc.h \
    $(wildcard include/config/x86/tsc.h) \
    $(wildcard include/config/x86/generic.h) \
  include/linux/jiffies.h \
  include/linux/calc64.h \
  include/asm/div64.h \
  include/asm-generic/div64.h \
  include/linux/rbtree.h \
  include/linux/ipipe.h \
    $(wildcard include/config/debug/kernel.h) \
  include/linux/ipipe_compat.h \
    $(wildcard include/config/ipipe/compat.h) \
  include/asm/ipipe.h \
  include/asm/irq.h \
  include/linux/ipipe_percpu.h \
    $(wildcard include/config/ipipe/domains.h) \
  include/asm/semaphore.h \
  include/asm/mmu.h \
  include/asm/cputime.h \
  include/asm-generic/cputime.h \
  include/linux/sem.h \
  include/linux/ipc.h \
  include/asm/ipcbuf.h \
  include/asm/sembuf.h \
  include/linux/signal.h \
  include/asm/signal.h \
  include/asm-generic/signal.h \
  include/asm/siginfo.h \
  include/asm-generic/siginfo.h \
  include/linux/securebits.h \
  include/linux/fs_struct.h \
  include/linux/completion.h \
  include/linux/pid.h \
  include/linux/rcupdate.h \
  include/linux/seccomp.h \
    $(wildcard include/config/seccomp.h) \
  include/linux/futex.h \
    $(wildcard include/config/futex.h) \
  include/linux/rtmutex.h \
    $(wildcard include/config/debug/rt/mutexes.h) \
  include/linux/plist.h \
    $(wildcard include/config/debug/pi/list.h) \
  include/linux/param.h \
  include/linux/resource.h \
  include/asm/resource.h \
  include/asm-generic/resource.h \
  include/linux/timer.h \
    $(wildcard include/config/timer/stats.h) \
  include/linux/ktime.h \
    $(wildcard include/config/ktime/scalar.h) \
  include/linux/hrtimer.h \
  include/linux/task_io_accounting.h \
    $(wildcard include/config/task/io/accounting.h) \
  include/linux/aio.h \
  include/linux/workqueue.h \
  include/linux/aio_abi.h \
  include/linux/uio.h \
  include/asm/hardirq.h \
  include/linux/irq.h \
    $(wildcard include/config/s390.h) \
    $(wildcard include/config/irq/per/cpu.h) \
    $(wildcard include/config/irq/release/method.h) \
    $(wildcard include/config/generic/pending/irq.h) \
    $(wildcard include/config/irqbalance.h) \
    $(wildcard include/config/auto/irq/affinity.h) \
    $(wildcard include/config/generic/hardirqs/no//do/irq.h) \
  include/asm/irq_regs.h \
  include/asm-generic/irq_regs.h \
  include/asm/hw_irq.h \
  include/linux/profile.h \
    $(wildcard include/config/profiling.h) \
  /usr/realtime/include/rtai_types.h \
  /usr/realtime/include/rtai_wrappers.h \
    $(wildcard include/config/mmu.h) \
  include/linux/device.h \
    $(wildcard include/config/debug/devres.h) \
  include/linux/ioport.h \
  include/linux/klist.h \
  include/asm/device.h \
  include/asm/desc.h \
  include/asm/ldt.h \
  include/asm/desc_defs.h \
  /usr/realtime/include/asm/rtai_atomic.h \
  /usr/realtime/include/asm/rtai_fpu.h \
  /usr/realtime/include/rtai_trace.h \
    $(wildcard include/config/arm.h) \
  /usr/realtime/include/asm/rtai_oldnames.h \
  /usr/realtime/include/asm/rtai_emulate_tsc.h \
  /usr/realtime/include/rtai_sched.h \
  /usr/realtime/include/rtai_comedi.h \
  /usr/realtime/include/rtai_sem.h \
  /usr/realtime/include/rtai_nam2num.h \
  /usr/realtime/include/linux/comedilib.h \
  /usr/realtime/include/linux/comedi.h \
    $(wildcard include/config/dio/input.h) \
    $(wildcard include/config/dio/output.h) \
    $(wildcard include/config/dio/opendrain.h) \
    $(wildcard include/config/analog/trig.h) \
    $(wildcard include/config/waveform.h) \
    $(wildcard include/config/trig.h) \
    $(wildcard include/config/counter.h) \
    $(wildcard include/config/alt/source.h) \
    $(wildcard include/config/digital/trig.h) \
    $(wildcard include/config/block/size.h) \
    $(wildcard include/config/timer/1.h) \
    $(wildcard include/config/filter.h) \
    $(wildcard include/config/change/notify.h) \
    $(wildcard include/config/serial/clock.h) \
    $(wildcard include/config/bidirectional/data.h) \
    $(wildcard include/config/dio/query.h) \
    $(wildcard include/config/pwm/output.h) \
    $(wildcard include/config/get/pwm/output.h) \
    $(wildcard include/config/disarm.h) \
    $(wildcard include/config/get/counter/status.h) \
    $(wildcard include/config/reset.h) \
    $(wildcard include/config/gpct/single/pulse/generator.h) \
    $(wildcard include/config/gpct/pulse/train/generator.h) \
    $(wildcard include/config/gpct/quadrature/encoder.h) \
    $(wildcard include/config/set/gate/src.h) \
    $(wildcard include/config/get/gate/src.h) \
    $(wildcard include/config/set/clock/src.h) \
    $(wildcard include/config/get/clock/src.h) \
    $(wildcard include/config/set/other/src.h) \
    $(wildcard include/config/get/other/src.h) \
    $(wildcard include/config/get/hardware/buffer/size.h) \
    $(wildcard include/config/set/counter/mode.h) \
    $(wildcard include/config/8254/set/mode.h) \
    $(wildcard include/config/8254/read/status.h) \
    $(wildcard include/config/set/routing.h) \
    $(wildcard include/config/get/routing.h) \
    $(wildcard include/config/pwm/set/period.h) \
    $(wildcard include/config/pwm/get/period.h) \
    $(wildcard include/config/get/pwm/status.h) \
    $(wildcard include/config/pwm/set/h/bridge.h) \
    $(wildcard include/config/pwm/get/h/bridge.h) \

/nfs/u50/somovm/lab10/pid.o: $(deps_/nfs/u50/somovm/lab10/pid.o)

$(deps_/nfs/u50/somovm/lab10/pid.o):
