/*

* Arduino mousecontroller (Development part)
----------------------------------------------------------

* This example/application send a hello packet of char, size 20

* Works on UNIX/LINUX systems
----------------------------------------------------------

* Created 28 December 2017

* Copyleft (c) 2017, Andres Casasola Dominguez
----------------------------------------------------------

* Last update: December 2017

* By Andrés Casasola Dominguez

*/

#include <stdio.h>    /* Standard input/output definitions */
#include <stdlib.h> 
#include <stdint.h>   /* Standard types */
#include <string.h>   /* String function definitions */
#include <unistd.h>   /* UNIX standard function definitions */
#include <fcntl.h>    /* File control definitions */
#include <errno.h>    /* Error number definitions */
#include <termios.h>  /* POSIX terminal control definitions */
#include <sys/ioctl.h>
#include <getopt.h>

#include "arduino-serial-lib.h"		// Libraries for serial communication -> Thanks to todbot, GitHub: https://github.com/todbot
#include "arduino-serial-lib.c"

/*
int serialport_init(const char* serialport, int baud);
int serialport_close(int fd);
int serialport_writebyte( int fd, uint8_t b);
int serialport_write(int fd, const char* str);
int serialport_read_until(int fd, char* buf, char until, int buf_max,int timeout);
int serialport_flush(int fd);
*/

int main(int argc, char*argv[]){

	int fd=0;
	int baudrate=B115200;		//	Default
	char buf[20], dat[20], use[1];
	int rc, n;

	baudrate=9600;	//	On arduino

	fd=serialport_init("/dev/ttyACM0", baudrate);	//	/dev/ttyUSB0 or /dev/ttyACM0 are commons
	if(fd==-1){
		printf("error while opening file descriptor\n");
		exit(2);
	}
	usleep(3000*1000);	//	3 seconds
	
	while(1){	
		//	Defining hello packet
		dat[0]='h';
		dat[1]='e';
		dat[2]='l';
		dat[3]='l';
		dat[4]='o';
		dat[5]='!';
		dat[6]=':';		//	When receiver program in arduino reads ':' it understand the msg has finished
		dat[7]='\0';	//	End of char array
		
		//	Sending hello packet
		rc = serialport_write(fd, dat);	//	0 is no error / -1 is error
        if(rc==-1){
        	printf("error while sending hello packet\n");
        	exit(2);
		}
		
		printf("wrote [%d]\n", rc);	//	Debug	(0 means no error, 1 means error while sending/writing)
		
		sleep(5);
	}
	
	close(fd);
	exit(EXIT_SUCCESS);  
}



