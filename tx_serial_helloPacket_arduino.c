/*

* Serial data test - Way PC to Arduino by USB
----------------------------------------------------------

* Created 28 December 2017.

* Copyleft (c) 2017, Andres Casasola Domínguez.
----------------------------------------------------------

* Last update: March 2018.

*/

#define BAUDRATE 9600

int val=0;
char data[20];

void setup(){
	Serial.begin(BAUDRATE);
  	pinMode(13, OUTPUT);
        Serial.println("Starting...");
        delay(500);
}

void loop(){

  //	Defining hello packet
  data[0]='h';
  data[1]='e';
  data[2]='l';
  data[3]='l';
  data[4]='o';
  data[5]='!';
  data[6]=':';	//	When receiver program in arduino reads ':' it understand the msg has finished
  data[7]='\0';	//	End of char chain
  Serial.print(data);
  delay(5000);
  
}
