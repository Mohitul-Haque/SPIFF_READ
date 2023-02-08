#include<FS.h>


//enter your file name
const char* CONFIG_FILE = "/config.json";


void setup() {
    Serial.begin(115200);

    delay(1000);

       
  
    if(!SPIFFS.begin()){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
      }
      
      File file = SPIFFS.open(CONFIG_FILE, "r");
      if(!file){
        Serial.println("Failed to open file for reading");
        return;
      }
      
      Serial.println();
      
      Serial.println("File Content:");
      while(file.available()){
        Serial.write(file.read());
      }
      
      file.close();    
}


void loop() {  // put your main code here, to run repeatedly:

}
