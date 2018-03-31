/*

* Arduino mousecontroller (Development part)
----------------------------------------------------------

* This example/application reads a hello packet from the

* usb port, in this case with an arduino.

* Arduino board. Works on any UNIX/LINUX systems
----------------------------------------------------------

* Created 28 December 2017

* Copyleft (c) 2017, Andres Casasola Dominguez
----------------------------------------------------------

* Last update: December 2017

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

void process_received_data(char *buf);

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
	char serialport[256];
	int baudrate=B115200;		//default
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
		
		//	Start reading
		n = serialport_read_until(fd, buf, ':', 20, 50);	//(-2 means timeout, -1 means could not open, 0 means data received ok)
		process_received_data(buf);
		printf("read [%d]: [%s]\n", n, buf);	//	Debug
		
		sleep(5);
			
	}
	
	close(fd);
	exit(EXIT_SUCCESS);  
}

void process_received_data(char *buf){
	for(int i=0; i<20;i++){
		if(buf[i]==':'){
			buf[i]='\0';
			buf[i+1]='\0';
		}
	}
}

