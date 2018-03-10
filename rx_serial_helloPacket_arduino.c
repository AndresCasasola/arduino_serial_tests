/*

* Serial data test - Way PC to Arduino by USB
----------------------------------------------------------

* Created 28 December 2017

* Copyleft (c) 2017, Andres Casasola Dominguez
----------------------------------------------------------

* Last update: December 2017

* By Andres Casasola Dominguez

*/

#define BAUDRATE 9600

int val=0;
char data[20];

void setup(){
	Serial.begin(BAUDRATE);
  	pinMode(13, OUTPUT);
        Serial.println("Starting...");
}

void loop(){

	if(Serial.available()){
		int dataCounter=0;
		while((val=Serial.read()) != ':'){
			if(val!=-1){
				data[dataCounter]=val;
				dataCounter++;
			}
		}
		process_received_data();
	}
}

void process_received_data(){
	if(data[0]=='h' && data[1]=='e' && data[2]=='l' && data[3]=='l' && data[4]=='o'&& data[5]=='!'){
		Serial.println(data);
		digitalWrite(13,HIGH);
	}else{
		Serial.println("No hello packet received yet\n");
		digitalWrite(13,LOW);
	}
}
