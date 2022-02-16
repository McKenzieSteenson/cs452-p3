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
	for(i=0; i <29; i++) {
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

void *buddy_malloc(size_t size)
{
	// p -> (char *)p+headerSize
	return NULL;
}

void buddy_free(void *ptr) 
{
	// p -> (char *)p-headerSize

}

/* Prints out all the lists of available blocks in the Buddy system. */
void printBuddyLists(void)
{
	
	// List 5: head = 0x602138 --> [tag=1,kval=5,addr=0x199e020] --> head = 0x602138
// List {list number}: head = {addres of head} --> [tag={block_header.tag}, kval={block_header.kval}, addr={&addressOfBlock} --> head = {address of head}]
	int i;
	for (i = 0; i < 29; i++) {
		if (avail[i].tag == 1) {
			printf("List %d: head = %p --> [tag= %d, kval %d, addr={}] --> head = %p \n", avail[i].kval, &avail[i], avail[i].tag, avail[i].kval, &avail[i]);
		} else {
			printf("List %d: head = %p --> head = %p \n", avail[i].kval, &avail[i], &avail[i]);
		}
	}	

}



/* vim: set ts=4: */
