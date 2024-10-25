/*output:19a: fifo file created using mknod command
prw-rw-r-- 1 soumya soumya     0 Sep 20 15:56 fifo_file19
*/

/*output:19b: file created using mkfifo comamnd
prw-rw-r-- 1 soumya soumya     0 Sep 20 15:58 file_mkfifo19
*/


/* output:19c: Mknod uses more system calls.
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ strace -o mknod_trace.txt mknod fifo2 p

soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cat mknod_trace.txt
execve("/usr/bin/mknod", ["mknod", "fifo2", "p"], 0x7ffc926129f0  45 vars ) = 0
brk(NULL)                               = 0x55b51d348000
arch_prctl(0x3001 /* ARCH_???/, 0x7fff6b99a750) = -1 EINVAL (Invalid argument)
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f9c1ec2d000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=64183, ...}, AT_EMPTY_PATH) = 0
mmap(NULL, 64183, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f9c1ec1d000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libselinux.so.1", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=174472, ...}, AT_EMPTY_PATH) = 0
mmap(NULL, 181928, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f9c1ebf0000
mmap(0x7f9c1ebf6000, 114688, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6000) = 0x7f9c1ebf6000
mmap(0x7f9c1ec12000, 28672, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x22000) = 0x7f9c1ec12000
mmap(0x7f9c1ec19000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x29000) = 0x7f9c1ec19000
mmap(0x7f9c1ec1b000, 5800, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f9c1ec1b000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0P<\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=2072888, ...}, AT_EMPTY_PATH) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2117488, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f9c1e800000
mmap(0x7f9c1e822000, 1540096, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x22000) = 0x7f9c1e822000
mmap(0x7f9c1e99a000, 360448, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x19a000) = 0x7f9c1e99a000
mmap(0x7f9c1e9f2000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1f1000) = 0x7f9c1e9f2000
mmap(0x7f9c1e9f8000, 53104, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f9c1e9f8000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libpcre2-8.so.0", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=625344, ...}, AT_EMPTY_PATH) = 0
mmap(NULL, 627472, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f9c1eb56000
mmap(0x7f9c1eb58000, 438272, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x2000) = 0x7f9c1eb58000
mmap(0x7f9c1ebc3000, 176128, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6d000) = 0x7f9c1ebc3000
mmap(0x7f9c1ebee000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x97000) = 0x7f9c1ebee000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f9c1eb53000
arch_prctl(ARCH_SET_FS, 0x7f9c1eb53800) = 0
set_tid_address(0x7f9c1eb53ad0)         = 5849
set_robust_list(0x7f9c1eb53ae0, 24)     = 0
rseq(0x7f9c1eb54120, 0x20, 0, 0x53053053) = 0
mprotect(0x7f9c1e9f2000, 16384, PROT_READ) = 0
mprotect(0x7f9c1ebee000, 4096, PROT_READ) = 0
mprotect(0x7f9c1ec19000, 4096, PROT_READ) = 0
mprotect(0x55b51b814000, 4096, PROT_READ) = 0
mprotect(0x7f9c1ec62000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x7f9c1ec1d000, 64183)           = 0
statfs("/sys/fs/selinux", 0x7fff6b99a720) = -1 ENOENT (No such file or directory)
statfs("/selinux", 0x7fff6b99a720)      = -1 ENOENT (No such file or directory)
getrandom("\xd0\xd8\x4f\x10\x7a\xa5\x51\x56", 8, GRND_NONBLOCK) = 8
brk(NULL)                               = 0x55b51d348000
brk(0x55b51d369000)                     = 0x55b51d369000
openat(AT_FDCWD, "/proc/filesystems", O_RDONLY|O_CLOEXEC) = 3
newfstatat(3, "", {st_mode=S_IFREG|0444, st_size=0, ...}, AT_EMPTY_PATH) = 0
read(3, "nodev\tsysfs\nnodev\ttmpfs\nnodev\tbd"..., 1024) = 393
read(3, "", 1024)                       = 0
close(3)                                = 0
access("/etc/selinux/config", F_OK)     = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=5716304, ...}, AT_EMPTY_PATH) = 0
mmap(NULL, 5716304, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f9c1e200000
close(3)                                = 0
mknodat(AT_FDCWD, "fifo2", S_IFIFO|0666) = -1 EEXIST (File exists)
write(2, "mknod: ", 7)                  = 7
write(2, "fifo2", 5)                    = 5
openat(AT_FDCWD, "/usr/share/locale/locale.alias", O_RDONLY|O_CLOEXEC) = 3
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=2996, ...}, AT_EMPTY_PATH) = 0
read(3, "# Locale name alias data base.\n#"..., 4096) = 2996
read(3, "", 4096)                       = 0
close(3)                                = 0
openat(AT_FDCWD, "/usr/share/locale/en_US.UTF-8/LC_MESSAGES/libc.mo", O_RDONLY) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/share/locale/en_US.utf8/LC_MESSAGES/libc.mo", O_RDONLY) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/share/locale/en_US/LC_MESSAGES/libc.mo", O_RDONLY) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/share/locale/en.UTF-8/LC_MESSAGES/libc.mo", O_RDONLY) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/share/locale/en.utf8/LC_MESSAGES/libc.mo", O_RDONLY) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/share/locale/en/LC_MESSAGES/libc.mo", O_RDONLY) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/share/locale-langpack/en_US.UTF-8/LC_MESSAGES/libc.mo", O_RDONLY) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/share/locale-langpack/en_US.utf8/LC_MESSAGES/libc.mo", O_RDONLY) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/share/locale-langpack/en_US/LC_MESSAGES/libc.mo", O_RDONLY) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/share/locale-langpack/en.UTF-8/LC_MESSAGES/libc.mo", O_RDONLY) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/share/locale-langpack/en.utf8/LC_MESSAGES/libc.mo", O_RDONLY) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/share/locale-langpack/en/LC_MESSAGES/libc.mo", O_RDONLY) = -1 ENOENT (No such file or directory)
write(2, ": File exists", 13)           = 13
write(2, "\n", 1)                       = 1
close(1)                                = 0
close(2)                                = 0
exit_group(1)                           = ?
+++ exited with 1 +++

*/

/*Output shows that mkfifo uses lesser system calls.
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ cat mkfifo_trace.txt
execve("/usr/bin/mkfifo", ["mkfifo", "fifo3"], 0x7ffde4bf1a48 / 44 vars /) = 0
brk(NULL)                               = 0x55ea0a075000
arch_prctl(0x3001 /* ARCH_??? *, 0x7ffeeecfddb0) = -1 EINVAL (Invalid argument)
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f71b2e76000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=64183, ...}, AT_EMPTY_PATH) = 0
mmap(NULL, 64183, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f71b2e66000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libselinux.so.1", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=174472, ...}, AT_EMPTY_PATH) = 0
mmap(NULL, 181928, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f71b2e39000
mmap(0x7f71b2e3f000, 114688, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6000) = 0x7f71b2e3f000
mmap(0x7f71b2e5b000, 28672, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x22000) = 0x7f71b2e5b000
mmap(0x7f71b2e62000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x29000) = 0x7f71b2e62000
mmap(0x7f71b2e64000, 5800, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f71b2e64000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0P<\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=2072888, ...}, AT_EMPTY_PATH) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2117488, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f71b2c00000
mmap(0x7f71b2c22000, 1540096, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x22000) = 0x7f71b2c22000
mmap(0x7f71b2d9a000, 360448, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x19a000) = 0x7f71b2d9a000
mmap(0x7f71b2df2000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1f1000) = 0x7f71b2df2000
mmap(0x7f71b2df8000, 53104, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f71b2df8000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libpcre2-8.so.0", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=625344, ...}, AT_EMPTY_PATH) = 0
mmap(NULL, 627472, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f71b2b66000
mmap(0x7f71b2b68000, 438272, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x2000) = 0x7f71b2b68000
mmap(0x7f71b2bd3000, 176128, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6d000) = 0x7f71b2bd3000
mmap(0x7f71b2bfe000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x97000) = 0x7f71b2bfe000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f71b2e36000
arch_prctl(ARCH_SET_FS, 0x7f71b2e36800) = 0
set_tid_address(0x7f71b2e36ad0)         = 5827
set_robust_list(0x7f71b2e36ae0, 24)     = 0
rseq(0x7f71b2e37120, 0x20, 0, 0x53053053) = 0
mprotect(0x7f71b2df2000, 16384, PROT_READ) = 0
mprotect(0x7f71b2bfe000, 4096, PROT_READ) = 0
mprotect(0x7f71b2e62000, 4096, PROT_READ) = 0
mprotect(0x55ea08160000, 4096, PROT_READ) = 0
mprotect(0x7f71b2eab000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x7f71b2e66000, 64183)           = 0
statfs("/sys/fs/selinux", 0x7ffeeecfdd80) = -1 ENOENT (No such file or directory)
statfs("/selinux", 0x7ffeeecfdd80)      = -1 ENOENT (No such file or directory)
getrandom("\xec\x2c\x8b\x0d\x6a\xa5\x3b\xbb", 8, GRND_NONBLOCK) = 8
brk(NULL)                               = 0x55ea0a075000
brk(0x55ea0a096000)                     = 0x55ea0a096000
openat(AT_FDCWD, "/proc/filesystems", O_RDONLY|O_CLOEXEC) = 3
newfstatat(3, "", {st_mode=S_IFREG|0444, st_size=0, ...}, AT_EMPTY_PATH) = 0
read(3, "nodev\tsysfs\nnodev\ttmpfs\nnodev\tbd"..., 1024) = 393
read(3, "", 1024)                       = 0
close(3)                                = 0
access("/etc/selinux/config", F_OK)     = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=5716304, ...}, AT_EMPTY_PATH) = 0
mmap(NULL, 5716304, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f71b2400000
close(3)                                = 0
mknodat(AT_FDCWD, "fifo3", S_IFIFO|0666) = 0
close(1)                                = 0
close(2)                                = 0
exit_group(0)                           = ?
+++ exited with 0 +++
soumya@soumya-HP-Pavilion-Laptop-15-cc1xx:~/repo1/hl2$ 

*/

