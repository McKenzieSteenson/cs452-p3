/**
 * Implementation of a memory allocator based on the Buddy System.
 */
 
#include "buddy.h"

/* Initialize the buddy system to the default size */
int buddy_init(void) { 
	// Initialize the lists
	int i;
	base = sbrk(DEFAULT_MAX_MEM_SIZE);

	// have a check that sbrk was successful, check return value of sbrk, and return false if it fails
	// Check that there is room
	
	if (base == -1) {
		return FALSE;
	}
	// for i 0->28
	for(i=0; i <=29; i++) {
		// next <- &avail[i] //// &avail[i] is the address of avail[i]
		avail[i].next = &avail[i];
		// prev <- &avail[i]
		avail[i].prev = &avail[i];
		// kval <- i
		avail[i].kval = i;
		// tag <- -1
		avail[i].tag = -1;
	}
	return TRUE;
}

/* allocates size bytes andreturns a pointer to the 
* allocated memory. If the memory cannot be allocated
* then buddy_malloc function should return null
*/
void *buddy_malloc(size_t size)
{
	int lgsize = 0;
	int i;
	int j;
	struct block_header * left;
	struct block_header * right; 
 
	
	// p -> (char *)p+headerSize

	// (struct block_header *) ((char *) p1 + sizeof())

	// to assign an int to a specific place in memory
		// type *ptr = (type *)[some place in memory or a void pointer]

	// XOR equation
		// x = y XOR (1ULL<<k)

	// stores ceiling log base 2 of size in lgsize
	size = size-1;
	while (size > 0) {
		size = size>>1;
		lgsize++;
	}

	j = 0;
	for (i = lgsize; i <= 29; i++) {
		left = (struct block_header *) ((char *) base + (((char *)size - (char *)base) ^1ULL<<avail[i].kval));

		if (avail != NULL) {

			break;
		
			while(j > lgsize) {
				// split
				// right side shift
					// right = (struct block_header *) ((unsigned long long int) left ^(1ULL<<(i-1)));
				right = (struct block_header *) ((unsigned long long int) left ^(1ULL<<(i-1)));
				return left = left + 1;
			}
		
		}
	}
	return NULL;
}

/* frees the memory space pointed to by ptr
* if ptr is NULL, return
*/
void buddy_free(void *ptr) 
{
	struct block_header * p;

	ptr = buddy_malloc(sizeof(ptr));

	p = (struct block_header *) ((char *) ptr - sizeof(ptr));
	// p -> (char *)p-headerSize

	//// (struct block_header *) ((char *) p1 - sizeof())

}

/* Prints out all the lists of available blocks in the Buddy system. */
void printBuddyLists(void)
{
	
	// List 5: head = 0x602138 --> [tag=1,kval=5,addr=0x199e020] --> head = 0x602138
// List {list number}: head = {addres of head} --> [tag={block_header.tag}, kval={block_header.kval}, addr={&addressOfBlock} --> head = {address of head}]
	int i;
	for (i = 0; i <= 29; i++) {
		if (avail[i].tag == 1) {
			printf("List %d: head = %p --> [tag= %d, kval %d, addr={}] --> head = %p \n", avail[i].kval, &avail[i], avail[i].tag, avail[i].kval, &avail[i]);
		} else {
			printf("List %d: head = %p --> head = %p \n", avail[i].kval, &avail[i], &avail[i]);
		}
	}	

}



/* vim: set ts=4: */
