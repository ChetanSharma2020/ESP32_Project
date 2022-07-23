
/************************************************************
  Update the Preferences –> Aditional boards Manager URLs: 
  https://dl.espressif.com/dl/package_esp32_index.json , http://arduino.esp8266.com/stable/package_esp8266com_index.json
  

Note: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32
                OR you can add manually 
Tool-->Board-->Board Manager-- > search (esp32 espressif) and install the Board

Install Blynk Library :- 

How to install Blynk library  :- https://docs.blynk.io/en/blynk.edgent-firmware-api/installation/what-do-i-need-to-blynk 
                               OR you can add manually 
Sketch-->Include Library-->Manage library-- > Search for Blynk library


************************************************************/



#include <WiFi.h> // Uncomment this if you are using ESP32
//Web Server App Control Home Automation
//#include <ESP8266WiFi.h> //Uncomment this if you are using NodeMCU
WiFiClient client;
WiFiServer server(80);

/* WIFI settings */
const char* ssid = "simalesh Sharma 1";   //WIFI SSID
const char* password = "che@1234";    //WIFI PASSWORD

void connectWiFi()
{
  Serial.println("Connecting to WIFI");
  WiFi.begin(ssid, password);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(3000);
    Serial.print("..");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("ESP32 Local IP is : ");
  Serial.println((WiFi.localIP()));
}

/* data received from application */
String  data =""; 

#define switch1 32
#define switch2 35
#define switch3 34
#define switch4 39



int Relay1 = 15;    
int Relay2 = 2;    
int Relay3 = 4;     
int Relay4 = 22;
  

int switch_ON_Flag1_previous_I = 0;
int switch_ON_Flag2_previous_I = 0;
int switch_ON_Flag3_previous_I = 0;
int switch_ON_Flag4_previous_I = 0;



void setup()
{
  /* initialize motor control pins as output */
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT); 
  pinMode(Relay3, OUTPUT);  
  pinMode(Relay4, OUTPUT);

  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
  pinMode(switch4, INPUT);
 
 
 

  digitalWrite(Relay1,LOW);
  digitalWrite(Relay2,LOW);
  digitalWrite(Relay3,LOW);
  digitalWrite(Relay4,LOW);
 
  
  /* start server communication */
  Serial.begin(115200);
  connectWiFi();
  server.begin();
}

void loop()
{
        //////////////////////////////////////////////////////////////////
 if (digitalRead(switch1) == LOW)
  {
    if (switch_ON_Flag1_previous_I == 0 )
    {
      digitalWrite(Relay1, LOW);
      Serial.println("Relay1- ON");
      
      switch_ON_Flag1_previous_I = 1;
    }
    

  }
  if (digitalRead(switch1) == HIGH )
  {
    if (switch_ON_Flag1_previous_I == 1)
    {
      digitalWrite(Relay1, HIGH);
      Serial.println("Relay1 OFF");
     
      switch_ON_Flag1_previous_I = 0;
    }
   
  }
 if (digitalRead(switch2) == LOW)
  {
    if (switch_ON_Flag2_previous_I == 0 )
    {
      digitalWrite(Relay2, LOW);
      Serial.println("Relay1- ON");
      
      switch_ON_Flag2_previous_I = 1;
    }
    

  }
  if (digitalRead(switch2) == HIGH )
  {
    if (switch_ON_Flag2_previous_I == 1)
    {
      digitalWrite(Relay2, HIGH);
      Serial.println("Relay1 OFF");
     
      switch_ON_Flag2_previous_I = 0;
    }
   
  }
   if (digitalRead(switch3) == LOW)
  {
    if (switch_ON_Flag3_previous_I == 0 )
    {
      digitalWrite(Relay3, LOW);
      Serial.println("Relay1- ON");
      
      switch_ON_Flag3_previous_I = 1;
    }
    

  }
  if (digitalRead(switch3) == HIGH )
  {
    if (switch_ON_Flag3_previous_I == 1)
    {
      digitalWrite(Relay3, HIGH);
      Serial.println("Relay1 OFF");
     
      switch_ON_Flag3_previous_I = 0;
    }
   
  }
 if (digitalRead(switch4) == LOW)
  {
    if (switch_ON_Flag4_previous_I == 0 )
    {
      digitalWrite(Relay4, LOW);
      Serial.println("Relay1- ON");
      
      switch_ON_Flag4_previous_I = 1;
    }
    

  }
  if (digitalRead(switch4) == HIGH )
  {
    if (switch_ON_Flag4_previous_I == 1)
    {
      digitalWrite(Relay4, HIGH);
      Serial.println("Relay1 OFF");
     
      switch_ON_Flag4_previous_I = 0;
    }
   
  }
    /* If the server available, run the "checkClient" function */  
    client = server.available();
    if (!client) return; 
    data = checkClient ();
    Serial.println(data);
/************************ Run function according to incoming data from application *************************/

    
    if (data == "Relay1on")
    { 
      digitalWrite(Relay1,LOW);
      }
    
    else if (data == "Relay1off")
    {
      digitalWrite(Relay1,HIGH);
      }

    else if (data == "Relay2on")
    {
      digitalWrite(Relay2,LOW);
      }
      
    else if (data == "Relay2off")
    {
      digitalWrite(Relay2,HIGH);
      }
      
    else if (data == "Relay3on")
    {
      digitalWrite(Relay3,LOW);
      }
      
    else if (data == "Relay3off")
    {
      digitalWrite(Relay3,HIGH);
      }
      
    else if (data == "Relay4on")
    {
      digitalWrite(Relay4,LOW);
      }
      
    else if (data == "Relay4off")
    {
      digitalWrite(Relay4,HIGH);
      }
  
      
} 


/********************************** RECEIVE DATA FROM the APP ******************************************/
String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}
