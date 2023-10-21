#define WIFI_SSID   "BOR1"
#define WIFI_PASS   "bor12345"
#define BOT_TOKEN   "5810771612:AAG0eIx9Yxx7SAxHPuG4Ig2cJSVHTHz4JtE"
#define CHAT_ID     "384474143"

#include <ESP8266WiFi.h>
#include <FastBot.h>

FastBot bot(BOT_TOKEN);


void setup() {

  // WiFi connection
  connectWiFi();

  // message manager
  bot.attach(newMsg);

  // set pin mode
  pinMode(LED_BUILTIN, OUTPUT);
}


void newMsg(FB_msg& msg) {
  // conditions for message
  if (msg.text == "/led_on") digitalWrite(LED_BUILTIN, LOW);
  else if (msg.text == "/led_off") digitalWrite(LED_BUILTIN, HIGH);
  else bot.sendMessage("Unknown command!", msg.chatID);
}


void loop() {
  bot.tick();
}


void connectWiFi() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected");
  Serial.println(WiFi.localIP());
}
