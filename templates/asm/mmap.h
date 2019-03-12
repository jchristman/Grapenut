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
