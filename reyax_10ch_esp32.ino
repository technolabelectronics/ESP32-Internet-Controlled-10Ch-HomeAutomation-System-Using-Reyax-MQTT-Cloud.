
#include <WiFi.h>
#include <PubSubClient.h>

const int Relay1 = 26;
const int Relay2 = 27;
const int Relay3 = 14;
const int Relay4 = 12;
const int Relay5 = 13;
const int Relay6 = 21;
const int Relay7 = 2;
const int Relay8 = 4;
const int Relay9 = 18;
const int Relay10 = 19;





// Update these with values suitable for your network.
//WIFI SETUP
const char* ssid = "XXXXXXXXXXX"; //WiFI Name
const char* password = "XXXXXXXXXX"; //WiFi Password
const char* mqtt_server = "iot.reyax.com";

//MQTT SETUP
const char* username = "XXXXXXXXXX"; //Reyax Useename
const char* pass = "XXXXXXXX"; //Reyax Password
const char* topic = "api/request";
const char* clientID = "ESP8266Client-"; // client id
//String msgStr = "";      // MQTT message buffer

#define sub1 "switch1"
#define sub2 "switch2"
#define sub3 "switch3"
#define sub4 "switch4"
#define sub5 "switch5"
#define sub6 "switch6"
#define sub7 "switch7"
#define sub8 "switch8"
#define sub9 "switch9"
#define sub10 "switch10"




WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE  (300)
char msg[MSG_BUFFER_SIZE];
int value = 0;

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    
    delay(500);
    Serial.print(".");
    
  }
  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
 
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect(clientID, username, pass)) {
      Serial.println("MQTT connected");
      client.subscribe(sub1);
      client.subscribe(sub2);
      client.subscribe(sub3);
      client.subscribe(sub4);
      client.subscribe(sub5);
      client.subscribe(sub6);
      client.subscribe(sub7);
      client.subscribe(sub8);
      client.subscribe(sub9);
      client.subscribe(sub10);
         
      //Serial.println(sub1);
      
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in few seconds");
      delay(500);
      


   }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  
  Serial.println(topic);
  Serial.print("Message:");
  for (int i = 0; i< length; i++) {
  Serial.print((char)payload[i]);
  }
  Serial.println();  
  Serial.print("Message size :");
  Serial.println(length);
  Serial.println();
  Serial.println("-----------------------");
 
  
  if (strstr(topic, sub1))
  {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '0') {
      digitalWrite(Relay1, LOW);   // Turn the LED on (Note that LOW is the voltage level
      Serial.print("Relay1 LOW");
    } else {
      digitalWrite(Relay1, HIGH);  // Turn the LED off by making the voltage HIGH
      Serial.print("Relay1 HIGH");
    }
  }

  else if ( strstr(topic, sub2))
  {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '0') {
      digitalWrite(Relay2, LOW);   // Turn the LED on (Note that LOW is the voltage level
      
    } else {
      digitalWrite(Relay2, HIGH);  // Turn the LED off by making the voltage HIGH
      
    }
  }
  else if ( strstr(topic, sub3))
  {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '0') {
      digitalWrite(Relay3, LOW);   // Turn the LED on (Note that LOW is the voltage level
      
    } else {
      digitalWrite(Relay3, HIGH);  // Turn the LED off by making the voltage HIGH
      
    }
  }
  else if ( strstr(topic, sub4))
  {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '0') {
      digitalWrite(Relay4, LOW);   // Turn the LED on (Note that LOW is the voltage level
      
    } else {
      digitalWrite(Relay4, HIGH);  // Turn the LED off by making the voltage HIGH
     
    }
  }
  else if ( strstr(topic, sub5))
  {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '0') {
      digitalWrite(Relay5, LOW);   // Turn the LED on (Note that LOW is the voltage level
      
    } else {
      digitalWrite(Relay5, HIGH);  // Turn the LED off by making the voltage HIGH
      
    }
  }else if ( strstr(topic, sub6))
  {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '0') {
      digitalWrite(Relay6, LOW);   // Turn the LED on (Note that LOW is the voltage level
      
    } else {
      digitalWrite(Relay6, HIGH);  // Turn the LED off by making the voltage HIGH
      
    }
  }else if ( strstr(topic, sub3))
  {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '0') {
      digitalWrite(Relay7, LOW);   // Turn the LED on (Note that LOW is the voltage level
      
    } else {
      digitalWrite(Relay7, HIGH);  // Turn the LED off by making the voltage HIGH
      
    }
  }else if ( strstr(topic, sub8))
  {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '0') {
      digitalWrite(Relay8, LOW);   // Turn the LED on (Note that LOW is the voltage level
      
    } else {
      digitalWrite(Relay8, HIGH);  // Turn the LED off by making the voltage HIGH
      
    }
  }else if ( strstr(topic, sub9))
  {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '0') {
      digitalWrite(Relay9, LOW);   // Turn the LED on (Note that LOW is the voltage level
      
    } else {
      digitalWrite(Relay9, HIGH);  // Turn the LED off by making the voltage HIGH
      
    }
  }
  else if ( strstr(topic, sub10))
  {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '0') {
      digitalWrite(Relay10, LOW);   // Turn the LED on (Note that LOW is the voltage level
      
    } else {
      digitalWrite(Relay10, HIGH);  // Turn the LED off by making the voltage HIGH
      
    }
  }
  else
  {
    Serial.println("unsubscribed topic");
  }
}



void setup() {
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  pinMode(Relay5, OUTPUT);
  pinMode(Relay6, OUTPUT);
  pinMode(Relay7, OUTPUT);
  pinMode(Relay8, OUTPUT);
  pinMode(Relay9, OUTPUT);
  pinMode(Relay10, OUTPUT);
  
   Serial.begin(115200);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
    
    }
    
   
  client.loop();
  delay(50);

 
}
