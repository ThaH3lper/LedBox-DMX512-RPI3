#include "SharedMemory.h"

bool SharedMemory::create(key_t key) {

    // Create the shared segment.
    int shmid;
    if ((shmid = shmget((key_t) key, 27, IPC_CREAT | 0666)) < 0) {
        printf("Error: create(), failed to create/load shared segment\n");
        return false;
    }

    // Attach the segment to our data space.
    if ((mSharedAdress = ((unsigned char *) shmat(shmid, NULL, 0))) == (unsigned char *) -1) {
        printf("Error: load(), failed to load shared segment\n");
        return false;
    }
}

void SharedMemory::writeMemory(unsigned char * array, unsigned int amount) {
    unsigned char * tempArray = mSharedAdress;
    for(int i = 0; i < amount; i++) {
        *tempArray = *array;
        tempArray++;
        array++;
    }
}

void SharedMemory::fillMemory(unsigned char value, unsigned int amount) {
    unsigned char * tempArray = mSharedAdress;
    for(int i = 0; i < amount; i++) {
        *tempArray = value;
        tempArray++;
    }
}

unsigned char * SharedMemory::readMemory() {
    return mSharedAdress;
}
