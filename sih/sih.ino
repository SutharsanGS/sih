
#include "CTBot.h"

CTBot myBot;
CTBotReplyKeyboard myKbd;   // reply keyboard object helper
bool isKeyboardActive;      // store if the reply keyboard is shown

String ssid = "Mia3";     // REPLACE mySSID WITH YOUR WIFI SSID
String pass = "Sudharsan"; // REPLACE myPassword YOUR WIFI PASSWORD, IF ANY
String token = "5127463547:AAFC0QiSUvFWBN25mltXz9LZHqOH7wJb1r0";   // REPLACE myToken WITH YOUR TELEGRAM BOT TOKEN

void setup() {
	// initialize the Serial
	Serial.begin(115200);
	Serial.println("Starting TelegramBot...");
  pinMode(D4,OUTPUT);

	// connect the ESP8266 to the desired access point
	myBot.wifiConnect(ssid, pass);

	// set the telegram bot token
	myBot.setTelegramToken(token);

	// check if all things are ok
	if (myBot.testConnection())
		Serial.println("\ntestConnection OK");
	else
		Serial.println("\ntestConnection NOK");

	
}

void loop() {
	// a variable to store telegram message data
	TBMessage msg;

	// if there is an incoming message...
	if (myBot.getNewMessage(msg)) {
		// check what kind of message I received
		if (msg.messageType == CTBotMessageText) {
			// received a text message
			if (msg.text.equalsIgnoreCase("Turn on")) {
				myBot.sendMessage(msg.sender.id, "Turning on the pump...");
        digitalWrite(D4,HIGH);  
        delay(5000);
        myBot.sendMessage(msg.sender.id, "Water pressure is    ");
        delay(3000);
        myBot.sendMessage(msg.sender.id, "Time required to irrigate is    ");
			}if (msg.text.equalsIgnoreCase("Turn of")) {
       myBot.sendMessage(msg.sender.id, "Turning on the pump...");
        digitalWrite(D4,LOW);  
      }
			
			
		}  
	}
	// wait 500 milliseconds
	delay(500);
}
