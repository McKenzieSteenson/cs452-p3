/**
 * Implementation of a memory allocator based on the Buddy System.
 */
 
#include "buddy.h"

/* Initialize the buddy system to the default size */
int buddy_init(void) { 
	// Initialize the lists
	base = sbrk(DEFAULT_MAX_MEM_SIZE);

	// Check that there is room
	if (base == -1) {
		return FALSE;
	}
	// for i 0->28
	for(int i=0; i <29; i++) {
		// next <- &avail[i] //// &avail[i] is the address of avail[i]
		avail[i].next <- &avail[i];
		// prev <- &avail[i]
		avail[i].prev <- &avail[i];
		// kval <- i
		avail[i].kval <- i;
		// tag <- -1
		avail[i].tag <- -1;
	}
	return TRUE;
}

void *buddy_malloc(size_t size)
{
	return NULL;
}

void buddy_free(void *ptr) 
{

}

/* Prints out all the lists of available blocks in the Buddy system. */
void printBuddyLists(void)
{
	// List 5: head = 0x602138 --> [tag=1,kval=5,addr=0x199e020] --> head = 0x602138
// List {list number}: head = {addres of head} --> [tag={block_header.tag}, kval={block_header.kval}, addr={&addressOfBlock} --> head = {address of head}]
	for (int i = 0; i < 29; i++) {}
		printf(&avail[i]);
	}	

}



/* vim: set ts=4: */
