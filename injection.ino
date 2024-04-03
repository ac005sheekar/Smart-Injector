//Programmed By: Sheekar Banerjee


void setup() {
    Serial.begin(9600);
    rtc.begin();
    while (!Serial) ; 
    Serial.println("start");
    wifi.init(SSID, PASSWORD);
    scale.set_scale(calibration_factor); 
    scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
    s1 = rtc.getserverTime();
    s2 = rtc.getserverTime();
    t = rtc.getTime();
    if (! rtcDS.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
    }
    if (rtcDS.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtcDS.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtcDS.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    }
    menuOption = menu();
}
void loop() {
     wifi.httpGet(host, hostPort);
     char* wifiBuf = wifi.getBuffer();
     for(int i=0; i< MAX_BUFFER_SIZE ; i++)
     Serial.print(wifiBuf[i]);
     char *wifiDateIdx = strstr (wifiBuf, "Date");
     for (int i = 0; wifiDateIdx[i] != '\n' ; i++)
     Serial.print(wifiDateIdx[i]);
    float scaleUnits1 = scale.get_units(); //scale.get_units() returns a float
    Serial.print(scaleUnits1);
    Serial.println(" Kg");
    if(scaleUnits1<0.000002)
    Serial.println("Send Notification to Refill Injection 1 container");
    float scaleUnits2 = scale.get_units(); //scale.get_units() returns a float
    Serial.print(scaleUnits2);
    Serial.println(" Kg");
    if(scaleUnits2<0.000002)
    Serial.println("Send Notification to Refill Injection 2 container");
 Here we can affiliate the  RTC - Real Time Clock - Test Code Fragment bellow:
     if(t.hour == s1.hour && t.min == s1.min && t.sec == s1.sec){
      relayModule1_1.on();
      waterpump_1.on();
      delay(20000);             
      relayModule1_1.off();
      waterpump_1.off();      
      delay(500);
      Serial.println("INJECTION1 has worked");
    }
   
    else if(t.hour == s2.hour && t.min == s2.min && t.sec == s2.sec){
      relayModule1_2.on();
      waterpump_2.on();
      delay(20000);             
      relayModule1_2.off(); pump_2.off();      
      delay(500);
      Serial.println("INJECTION1 has worked");
    }}
