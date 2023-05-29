/*
  ESP-NOW Demo - Receive
  esp-now-control-rcv.ino
  
  modified by Dan Peirce B.Sc.  2023
  Conrtols RGB LED on ESP32-S2-DevKitC-1 using ESP-Now

  Modified from
  ESP-NOW Demo - Receive
  esp-now-demo-rcv.ino
  Reads data from Initiator
  
  DroneBot Workshop 2022
  https://dronebotworkshop.com
*/

// Include Libraries
#include <esp_now.h>
#include <WiFi.h>

void command_tree(char command);

// Define a data structure
typedef struct struct_message {
  char a[11];
  bool d;
} struct_message;

// Create a structured object
struct_message myData;


// Callback function executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Data received: ");
  Serial.println(len);
  Serial.print("Character Value: ");
  Serial.println(myData.a);
  Serial.print("Boolean Value: ");
  Serial.println(myData.d);
  Serial.println();
  command_tree(myData.a[0]);
}

void setup() {
  // Set up Serial Monitor
  Serial.begin(115200);
  
  // Set ESP32 as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Initilize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Register callback function
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {

}

void command_tree(char command) {
  // char command = Serial.read(); // read  character
  static char dim_factor = 1;
  static unsigned char rpix, gpix, bpix;

  if (command == 'r' ) {
    rpix= RGB_BRIGHTNESS;
    gpix = 0;
    bpix = 0;
    Serial.println(F("Turn LED Red\n"));
  } else if (command == 'o') {
    rpix= 0;
    gpix = 0;
    bpix = 0;
    Serial.println(F("Turn LED OFF\n"));
  } else if (command == 'g') {
    rpix= 0;
    gpix = RGB_BRIGHTNESS;
    bpix = 0;
    Serial.println(F("Turn LED Green\n"));
  } else if (command == 'b') {
    rpix= 0;
    gpix = 0;
    bpix = RGB_BRIGHTNESS;
    Serial.println(F("Turn LED Blue\n"));
  } else if (command == 'w') {
    rpix= RGB_BRIGHTNESS;
    gpix = RGB_BRIGHTNESS;
    bpix = RGB_BRIGHTNESS;
    Serial.println(F("Turn LED White\n"));
  } else if (command == 'y') {
    rpix= RGB_BRIGHTNESS;
    gpix = RGB_BRIGHTNESS;
    bpix = 0;
    Serial.println(F("Turn LED Yellow\n"));
  } else if (command == 'p') {
    rpix= RGB_BRIGHTNESS;
    gpix = 0;
    bpix = RGB_BRIGHTNESS;
    Serial.println(F("Turn LED Purple\n"));
  } else if (command == '1') {
    dim_factor = 1;
    Serial.println(F("LED 100%\n"));

  } else if (command == '5') {
    dim_factor = 2;
    Serial.println(F("LED 50%\n"));
  } 
  else if (command == '2') {
    dim_factor = 5;
    Serial.println(F("LED 20%\n"));
  } else  {
    Serial.println(F("Unknown! Use r,g,b,w,o,y,p,1,5,2"));
  } 

  neopixelWrite(RGB_BUILTIN,rpix/dim_factor,gpix/dim_factor,bpix/dim_factor); 
}