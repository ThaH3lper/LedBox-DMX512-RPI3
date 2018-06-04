#ifndef LED_H
#define LED_H

#include "Server.h"
#include <unistd.h> //Sleep
#include "global.h"
#include <stdlib.h>
#include <string>

/*
 * 	Led start
 * 	Led stop
 * 
 * 	Led all [ID] [Params 0..10]
 * 
 * 	Led channel [Channel] [ID] [Params 0..10]
 *
 *
 *--------------------------------------------
 * 	Fade to simple:
 * 		ID: 1
 * 		PARAMS [RED] [GREEN] [BLUE]
 *
 *--------------------------------------------
 * 	Sin curver:
 * 		ID: 2
 * 		PARAMS [RED_MIN] [RED_MAX] [GREEN_MIN] [GREEN_MAX] [BLUE_MIN] [BLUE_MAX] [SPEED] [OFFSET]
 */

int main (int argc, char *argv[])
{
	if(argc >= 2) {
		std::string command = argv[1];

		if(command == "start") {
		    printf(GREEN "[Starting Server]" RESET "\n");
			Server server = Server();
			server.start();

		} else if (command == "stop") {
			Server server = Server();
			server.stop();

		} else if (command == "all" && argc >= 3) {
			SharedMemory sm = SharedMemory();
			sm.create(global::SMK_DATA);
			unsigned char temp[global::DATA_SIZE];

			char* pos;
			for (int channelStart = 0; channelStart < global::DATA_SIZE; channelStart += global::MAX_CHANNEL_DATA)
			{
				temp[channelStart] = (unsigned char) std::strtol(argv[2],&pos,10);
				for (int argIndex = 3; argIndex < argc; argIndex++) {
					printf("%x %x\n", argIndex, argc);
					temp[channelStart + argIndex - 2] = (unsigned char) std::strtol(argv[argIndex],&pos,10);
				}
			}
			sm.writeMemory(temp, global::DATA_SIZE);

		} else if (command == "channel" && argc >= 4) {
			SharedMemory sm = SharedMemory();
			sm.create(global::SMK_DATA);
			unsigned char temp[global::DATA_SIZE];

			char* pos;
			int channelStart = (int) std::strtol(argv[2],&pos,10);
			temp[channelStart * global::MAX_CHANNEL_DATA] = (unsigned char) std::strtol(argv[3],&pos,10);
			for (int argIndex = 4; argIndex < argc; argIndex++) {
				printf("%x %x\n", argIndex, argc);
				temp[channelStart * global::MAX_CHANNEL_DATA + argIndex - 3] = (unsigned char) std::strtol(argv[argIndex],&pos,10);
			}
			sm.writeMemory(temp, global::DATA_SIZE);
		}
	} else {
			printf(GREEN "[LedLight]" RESET "\n");
			printf(YELLOW "Created by Patrik Nilsson" RESET "\n");
			printf(GRAY "./Led start | Start the server" RESET "\n");
			printf(GRAY "./Led stop  | Stop the server" RESET "\n");
			printf(GRAY "./Led all [PROGRAM] | Set program for all channels" RESET "\n");
			printf(GRAY "./Led channel [PROGRAM] | Set program for single channel" RESET "\n");
			printf(GRAY "-------- Programs ----------" RESET "\n");
			printf(GRAY "1 [R] [G] [B] | Simple fade to color" RESET "\n");
			printf(GRAY "2 [minR] [maxR] [minG] [maxG] [minB] [maxB] [speed] [offset] | Set sin curver" RESET "\n");
		}
	return 0;
}
#endif