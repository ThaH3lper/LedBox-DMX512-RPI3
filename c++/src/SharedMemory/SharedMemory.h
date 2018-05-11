#ifndef SHAREDMEMORY_H
#define SHAREDMEMORY_H	
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

class SharedMemory {

private:
    unsigned char * mSharedAdress;

public:
	/*
	 * Info: 	Creates/Loads a shared adress to store char array.
	 * 		 	Uses SHARED_ADRESS_KEY as a key to identify the 
	 * 		 	memory segment. Should only be used by the server.
	 *
	 * Returns: if shared memory was successfully
	 * 			created/loaded or not.
	 */
	bool create(key_t mKey);

	/*
	 * Info: 	Write array to the shared memory.
	 *
	 * Params: 	- Array of unasigned char (0-255)
	 * 			- Amount of unasigned chars that should be written.
	 */
	void writeMemory(unsigned char * array, unsigned int amount);

	/*
	 * Info: 	Write the value of the shared memory.
	 *
	 * Params: 	- unasigned char (0-255) that should be filled in the memory.
	 *			- Amount of unasigned chars that should be written.
	 */
	void fillMemory(unsigned char value, unsigned int amount);

	/*
	 * Info: 	Read the value of the shared memory.
	 *
	 * Returns: Array of unasigned char (0-255)
	 */
	unsigned char * readMemory();
};

#endif