// SPDX-License-Identifier: LGPL-2.1-or-later OR BSD-3-Clause

#include <sys/types.h>

#define LD_SO_DAEMON_SOCKET_NICE "ld-so-daemon"
#define LD_SO_DAEMON_SOCKET "\0"LD_SO_DAEMON_SOCKET_NICE

struct mmap_args {
	void *addr;
	size_t length;
	int prot;
	int flags;
	int fd;
	off_t offset;
};

struct packet {
	char code;
	union {
		struct mmap_args mmap;
		struct munmap_args {
			void *addr;
			size_t length;
		} munmap;
		struct seccomp_args {
			unsigned short len;
			void *filter;
			unsigned int flags;
		} seccomp;
		struct stack_args {
			void *dst, *src;
			size_t length;
			unsigned long delta;
		} stack;
		unsigned long longval;
	};
};
