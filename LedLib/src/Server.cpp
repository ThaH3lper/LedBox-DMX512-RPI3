#include "Server.h"

Server::Server() {
    mSelector = Selector();

    mSMServerStatus = SharedMemory();
    mSMServerStatus.create(global::SMK_SERVER_STATUS);

    mSMData = SharedMemory();
    mSMData.create(global::SMK_DATA);
}

void Server::start() {
    mSMData.fillMemory(1, global::DATA_SIZE);

    mDmxController = DmxController();
    mDmxController.clear();
    if (!mDmxController.setup()) {
        exit(0);
    }
    
    for (int i = 0; i < 10; ++i) {
        mBehaviors[i] = new BaseBehavior();
    }
    mBehaviors[1] = new BootBehavior(0, 127, 0, 0);
    mBehaviors[2] = new BootBehavior(0, 127, 0, 350);
    mBehaviors[3] = new BootBehavior(0, 127, 0, 700);
    mBehaviors[0] = new BootBehavior(0, 127, 0, 1050);
    
    /*
     * Set mS(hared)M(emory)ServerStatus to 0 
     * to keep server looping.
     * Set 1 to exit the loop.
     */
    unsigned char array[1] = {0};
    mSMServerStatus.writeMemory(array, 1);

    unsigned char currentArray[global::DATA_SIZE];
    memcpy(currentArray, mSMData.readMemory(), global::DATA_SIZE);
    long double currentTime = time(0);

    //Server Loop
    while(*mSMServerStatus.readMemory() == 0) {

        //Check if mSMData has changed from clients.
        unsigned char * data = mSMData.readMemory();
        if (memcmp(data, currentArray, global::DATA_SIZE) != 0) {
            printf(GREEN "CHANGED!\n" RESET);
            memcpy(currentArray, data, global::DATA_SIZE);
            //mDmxController.printData();
            mSelector.select(data, mBehaviors);
        }

        //Calculate delta value for update
        long double currentTime = getCurrentTimeMS();
        //printf(GREEN "%Lf\n" RESET, currentTime);

        int interval = update(currentTime);
        //printf("update: %x\n", interval);

        delay_ms(interval);
    }
    printf("Exited\n");
}

void Server::stop() {
    unsigned char array[1] = {1};
    mSMServerStatus.writeMemory(array, 1);
    printf("Will exit on next update...\n");
}

double Server::update(long double currentTime) {
    double lowest = DEFAULT_INTERVAL;

    unsigned char * test = mDmxController.getData();
    memcpy(test, mDmxController.getData(), 512);

    for (int i = 0; i < 10; ++i)
    {
        mBehaviors[i]->update(currentTime);

        /*if(i == 0) {
            printf(RED "setChannel(%i, %i, %i, %i)\n", i, mBehaviors[i]->getGreen(), mBehaviors[i]->getRed(), mBehaviors[i]->getBlue());
        }*/

        mDmxController.setChannel(i, mBehaviors[i]->getGreen(),
            mBehaviors[i]->getRed(), mBehaviors[i]->getBlue());

        if(mBehaviors[i]->getUpdateInterval() < lowest) {
            lowest = mBehaviors[i]->getUpdateInterval();
        }
    }

    if (memcmp(test, mDmxController.getData(), 512) != 0) {
            printf(RED "C.h.a.n.g.e.d!\n" RESET);
        }



    mDmxController.sendData();
    return lowest;
}
