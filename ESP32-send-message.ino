#include <WiFi.h>                                                                                                                //Author : Febin T Rajeev
#include <ThingESP.h>

#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif

uint8_t temprature_sens_read();

int a = ((temprature_sens_read() - 32) / 1.8);
String tem = String(a, DEC);
String cell = "°C";
String result = tem + cell;
int b = 4+4;
String l=String(b, DEC);;

ThingESP32 thing("username", "project_name", "credentials");

int LED = 2;

unsigned long previousMillis = 0;
const long INTERVAL = 6000;

void setup()
{
    Serial.begin(115200);

    pinMode(LED, OUTPUT);

    thing.SetWiFi("wifi_ssid", "wifi_password");

    thing.initDevice();   
    
    
}

String HandleResponse(String query)
{

    if (query == "led on")
    {
        digitalWrite(LED, 1);
        return "Done: LED Turned ON";
    }

    else if (query == "led off")
    {
        digitalWrite(LED, 0);
        return "Done: LED Turned OFF";
    }
    else if (query == "owner")
    {
        return "FEBIN T RAJEEV";
        
    }
    else if (query == "morse code")
    {
        return "A : ._\NB : _...\NC : _._.\ND : _..\NE : .\N";
        
    }
     else if (query == "good morning")
    {
        return "good morning";
        
    }
    else if (query == "symbols")
    {
     
        return "♕ ➼ ★ ☆ ✡ ✦ ✧ ✩ ✪ ✫ ✬ ✭ ✮ ✯ ✰ ⁂ ⁎ ⁑ ✢ ✣ ✤ ✥ ✱ ✲ ✳ ✴ ✵ ✶ ✷ ✸ ✹ ✺ ✻ ✼ ✽ ✾ ✿ ❀ ❁ ❂ ❃ ❇ ❈ ❉ ❊ ❋ ❄ ❆ ❅ ⋆ ≛ ᕯ ✲ ࿏ ꙰ ۞";
        
    }else if (query == "pi")
    {
     
        return "3.14";
        
    }
    else if (query == "youtube")
    {
     
        return "https://www.youtube.com/";
        
    }    
    else if (query == "4 4")
    {
     
        return l;
        
    }
    
    else if (query == "help")
    { 
     
       
        return"__COMMANDS__\n● led on\n● led off\n● led status\n●symbols\n●temp\n● owner\n";
    }
   else if (query == "blink")
  {
 digitalWrite(LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);     
  digitalWrite(LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                  // wait for a second
}
 

       
        
    
    else if (query == "temp")
    {
         return result;
        
    } 
    
    else if (query == "led status")
        return digitalRead(LED) ? "LED is ON" : "LED is OFF";

    else
        return "Your query was invalid..";
}

void loop()
{

    // if (millis() - previousMillis >= INTERVAL)
    // {
    //     previousMillis = millis();
    //     String msg = digitalRead(LED) ? "LED is ON" : "LED is OFF";
    //     thing.sendMsg("PHONE_NUMBER", msg);
    // }

    thing.Handle();
}
