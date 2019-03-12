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
