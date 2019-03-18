#define SYS_SOCKET      1    /* sys_socket(2)      */
#define SYS_BIND        2    /* sys_bind(2)        */
#define SYS_CONNECT     3    /* sys_connect(2)     */
#define SYS_LISTEN      4    /* sys_listen(2)      */
#define SYS_ACCEPT      5    /* sys_accept(2)      */
#define SYS_GETSOCKNAME 6    /* sys_getsockname(2) */
#define SYS_GETPEERNAME 7    /* sys_getpeername(2) */
#define SYS_SOCKETPAIR  8    /* sys_socketpair(2)  */
#define SYS_SEND        9    /* sys_send(2)        */
#define SYS_RECV        10   /* sys_recv(2)        */
#define SYS_SENDTO      11   /* sys_sendto(2)      */
#define SYS_RECVFROM    12   /* sys_recvfrom(2)    */
#define SYS_SHUTDOWN    13   /* sys_shutdown(2)    */
#define SYS_SETSOCKOPT  14   /* sys_setsockopt(2)  */
#define SYS_GETSOCKOPT  15   /* sys_getsockopt(2)  */
#define SYS_SENDMSG     16   /* sys_sendmsg(2)     */
#define SYS_RECVMSG     17   /* sys_recvmsg(2)     */
#define SYS_ACCEPT4     18   /* sys_accept4(2)     */

#define SOCK_STREAM	1  /* stream (connection) socket	*/
#define SOCK_DGRAM	2  /* datagram (conn.less) socket	*/
#define AF_INET		2  /* Internet IP Protocol 	*/
#define AF_INET6	10 /* IP version 6			*/

struct sockaddr
{
	unsigned short	sa_family;	/* address family, AF_xxx	*/
	char		sa_data[14];	/* 14 bytes of protocol address	*/
};

struct in_addr {
    unsigned long s_addr;  // load with inet_aton()
};

struct sockaddr_in {
    short            sin_family;   // e.g. AF_INET
    unsigned short   sin_port;     // e.g. htons(3490)
    struct in_addr   sin_addr;     // see struct in_addr, below
    char             sin_zero[8];  // zero this if you want to
};

#define htons(x) ((x >> 8) & 0xFF) | ((x & 0xFF) << 8)

extern int socket(int domain, int type, int protocol);
#define STDIN 0
#define STDOUT 1
#define STDERR 2

// File flags
#define O_RDONLY    0000
#define O_WRONLY    0001
#define O_RDWR      0002
#define O_CREAT     0100

#define NULL 0
extern int close(unsigned int fd);
extern void *memcpy(void *dest, void *src, int n);
/*
 * Protections are chosen from these bits, or-ed together
 */
#define	PROT_READ	0x04	/* pages can be read */
#define	PROT_WRITE	0x02	/* pages can be written */
#define	PROT_EXEC	0x01	/* pages can be executed */

/*
 * Flags contain mapping type, sharing type and options.
 * Mapping type; choose one
 */
#define	MAP_FILE	0x0001	/* mapped from a file or device */
#define	MAP_ANON	0x0002	/* allocated from memory, swap space */
#define	MAP_TYPE	0x000f	/* mask for type field */

/*
 * Sharing types; choose one
 */
#define	MAP_COPY	0x0020	/* "copy" region at mmap time */
#define	MAP_SHARED	0x0010	/* share changes */
#define	MAP_PRIVATE	0x0000	/* changes are private */

/*
 * Other flags
 */
#define	MAP_FIXED	0x0100	/* map addr must be exactly as requested */
#define	MAP_NOEXTEND	0x0200	/* for MAP_FILE, don't change file size */
#define	MAP_HASSEMPHORE	0x0400	/* region may contain semaphores */
#define	MAP_INHERIT	0x0800	/* region is retained after exec */

//struct mmap_arg_struct {
//	unsigned long addr;
//	unsigned long len;
//	unsigned long prot;
//	unsigned long flags;
//	unsigned long fd;
//	unsigned long offset;
//};

extern void *mmap(void *addr, int length, int prot, int flags,
                  int fd, int offset);
//extern void *mmap(struct mmap_arg_struct args);
extern int connect(int sockfd, struct sockaddr *addr, short addrlen);
extern void exit(int errno);
extern int read(int fd, char* buf, int count);
extern int open(char* filename, int flags, int mode);
extern int execve(char* filename, char* argv[], char* envp[]);
extern int write(int fd, char* buf, int count);
