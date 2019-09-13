int ledPins[] = {
  2, 3, 4, 5, 6, 7,8
};       // an array of pin numbers to which LEDs are attached
int pinCount = 7;           // the number of pins (i.e. the length of the array)
int timer = 250;           // The higher the number, the slower the timing.
int a=10;
int b=11;
int c=12;
int value=0;
int tanque;
float adc, level ;
float out;
//inp
float u,inp_z;
//out
float y,sen_out;
//temp
float u_ant,y_ant,zzz,u_temp,y_temp,y2_temp;
bool reset;
void setup()
{ 
  inp_z=0;
  u=0;
  reset=false;
  y=0;
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  analogWriteResolution(12);
  Serial.begin(9600);
}
   
    ///// FUNCTIONS
    
    void Proces (){
      u_temp= u_ant*0.0198;
      y_temp=y_ant*0.9802;
      zzz=u_temp+y_temp;
      y2_temp=zzz+inp_z;
      y=y2_temp;
      y_ant=y2_temp;
      u_ant=u;
      if(reset == true){
      y_ant=0;
      }
      
      u=level;
      sen_out = map(y,0,100,0,4094);
      //Serial.print("=============Output_sens: ");
      //Serial.println(sen_out);
      out = sen_out;

    }
    void Write()
    {
      //Serial.print("======= New Output : ");
      //Serial.println(out);
      analogWrite(DAC0,out);
    }
    
    void Output()
    {
  
      for (int thisPin = 0; thisPin < pinCount; thisPin++) {
        // turn the pin on:
        digitalWrite(ledPins[thisPin], HIGH);
        delay(timer);
        // turn the pin off:
        digitalWrite(ledPins[thisPin], LOW);
      }
        digitalWrite(c, HIGH);
        delay(timer);
        digitalWrite(c, LOW);
        digitalWrite(a, HIGH);
        delay(timer);
        digitalWrite(a, LOW);
        digitalWrite(b, HIGH);
        delay(timer);
        digitalWrite(b, LOW);

        delay(timer);
        digitalWrite(b, HIGH);
        delay(timer);
        digitalWrite(b, LOW);
        digitalWrite(a, HIGH);
        delay(timer);
        digitalWrite(a, LOW);
        digitalWrite(c, HIGH);
        delay(timer);
        digitalWrite(c, LOW);
      for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
        // turn the pin on:
        digitalWrite(ledPins[thisPin], HIGH);
        delay(timer);
        // turn the pin off:
        digitalWrite(ledPins[thisPin], LOW);
      }

    }

    void Read()
    {
      adc = analogRead(A7);
//      Serial.print("ADC: ");
//      Serial.println(adc);
      out = sen_out;
//      Serial.println(out);
      delay(50);
      //level = map(adc,0,1023,0,100);
      //codig------------------------
      level = map(adc,0,1023,0,100);
      //tanque = map (level,0,100,0,10);
      tanque = map (out,0,4012,0,10);
      //Serial.print("Escalamiento ADC: ");
      //Serial.println(level);
      //Serial.print("Level tanque: ");
      //Serial.println(tanque);
      Led();
      delay(50);
    }

    void Led(){
      //Serial.print("Tanque: ");
      //Serial.println(tanque);
      switch (tanque) {
        case 0:
//          Serial.println("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA: ");
           digitalWrite(c, LOW);
           digitalWrite(a, LOW);
           digitalWrite(b, LOW);
           digitalWrite(2,LOW);
           delay(50);
          for (int thisPin = pinCount - 1; thisPin > 0; thisPin--) {
            // turn the pin off:
            digitalWrite(ledPins[thisPin], LOW);
          }
          break;
        case 1:
//          Serial.println("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA: ");
          digitalWrite(c, LOW);
          digitalWrite(a, LOW);
          digitalWrite(b, LOW);
          for (int thisPin = pinCount - 1; thisPin >= 1; thisPin--) {
            // turn the pin off:
            digitalWrite(ledPins[thisPin], LOW);
          }
          delay(50);
            for (int thisPin = 0; thisPin < 1; thisPin++) {
          // turn the pin on:
          digitalWrite(ledPins[thisPin], HIGH);
          }
          break;
        case 2:
//          Serial.println("....................: ");
           for (int thisPin = 0; thisPin < 2; thisPin++) {
          // turn the pin on:
          digitalWrite(ledPins[thisPin], HIGH);
          }
          for (int thisPin = pinCount - 1; thisPin >= 2; thisPin--) {
            // turn the pin off:
            digitalWrite(ledPins[thisPin], LOW);
          }
           delay(50);
           digitalWrite(c, LOW);
           digitalWrite(a, LOW);
           digitalWrite(b, LOW);
          break;
        case 3:
//          Serial.println("....................: ");
          for (int thisPin = 0; thisPin < 3; thisPin++) {
          // turn the pin on:
          digitalWrite(ledPins[thisPin], HIGH);
          }
          for (int thisPin = pinCount - 1; thisPin >= 3; thisPin--) {
            // turn the pin off:
            digitalWrite(ledPins[thisPin], LOW);
          }
           delay(50);
           digitalWrite(c, LOW);
           digitalWrite(a, LOW);
           digitalWrite(b, LOW);
          break;
        case 4:
//          Serial.println("....................: ");
          for (int thisPin = 0; thisPin < 4; thisPin++) {
          // turn the pin on:
          digitalWrite(ledPins[thisPin], HIGH);
          }
          for (int thisPin = pinCount - 1; thisPin >= 4; thisPin--) {
            // turn the pin off:
            digitalWrite(ledPins[thisPin], LOW);
          }
           delay(50);
           digitalWrite(c, LOW);
           digitalWrite(a, LOW);
           digitalWrite(b, LOW);
          break;
        case 5:
//          Serial.println("....................: ");
          for (int thisPin = 0; thisPin < 5; thisPin++) {
          // turn the pin on:
          digitalWrite(ledPins[thisPin], HIGH);
          }
          for (int thisPin = pinCount - 1; thisPin >= 5; thisPin--) {
            // turn the pin off:
            digitalWrite(ledPins[thisPin], LOW);
           
          }
           digitalWrite(c, LOW);
           digitalWrite(a, LOW);
           digitalWrite(b, LOW);
          break;
        case 6:
//          Serial.println("....................: ");
          for (int thisPin = 0; thisPin < 6; thisPin++) {
          // turn the pin on:
          digitalWrite(ledPins[thisPin], HIGH);
          }
          for (int thisPin = pinCount - 1; thisPin >= 6; thisPin--) {
            // turn the pin off:
            digitalWrite(ledPins[thisPin], LOW);
          }
            digitalWrite(c, LOW);
            digitalWrite(a, LOW);
            digitalWrite(b, LOW);
          break;
        case 7:
//          Serial.println("__________________________: ");
          for (int thisPin = 0; thisPin < 7; thisPin++) {
          // turn the pin on:
          digitalWrite(ledPins[thisPin], HIGH);
          }
          for (int thisPin = pinCount - 1; thisPin >= 7; thisPin--) {
            // turn the pin off:
            digitalWrite(ledPins[thisPin], LOW);
          }
            digitalWrite(c, LOW);
            digitalWrite(a, LOW);
            digitalWrite(b, LOW);
          break;
        case 8:
          for (int thisPin = 0; thisPin < 7; thisPin++) {
            // turn the pin on:
            digitalWrite(ledPins[thisPin], HIGH);
          }
            digitalWrite(c, HIGH);
            digitalWrite(b, LOW);
            digitalWrite(a, LOW);
          break;
        case 9:
          Serial.println("....................: ");
          for (int thisPin = 0; thisPin < 7; thisPin++) {
            // turn the pin on:
            digitalWrite(ledPins[thisPin], HIGH);
          }
            digitalWrite(c, HIGH);
            digitalWrite(a, HIGH);
            digitalWrite(b, LOW);
          break;
        case 10:
 //         Serial.println("....................: ");
          for (int thisPin = 0; thisPin < pinCount; thisPin++) {
            // turn the pin on:
            digitalWrite(ledPins[thisPin], HIGH);
          }
            digitalWrite(a, HIGH);
            digitalWrite(b, HIGH);
            digitalWrite(c, HIGH);
          break;
        default:
          // if nothing else matches, do the default
          // default is optional
          break;
      }
    }
    
void loop() {
  Proces();
  Read();
  Led();
  Write();
  delay(50);
}





