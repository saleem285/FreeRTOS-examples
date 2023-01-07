const int ledpin = 33;
const int button = 27;
int brightness = 0;
int buttonstatus;
#define STACK_SIZE 2048


void lightLed(void* params){
  int fadeAmount = 5;
  while(true){
  analogWrite(ledpin, brightness);

  // change the brightness for next time through the loop:
  if(buttonstatus == HIGH){
    brightness = brightness + fadeAmount;
  }
  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(20);
  }
}

void checkButton(void* params){
  while(true){
    buttonstatus = digitalRead(button);
    delay(5);
  }
}

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(button, INPUT_PULLDOWN);
  xTaskCreate(lightLed, "lightLed", STACK_SIZE, nullptr, 5, nullptr);
  xTaskCreate(checkButton, "checkButton", STACK_SIZE, nullptr, 5, nullptr);
}



// the loop function runs over and over again forever
void loop() {
  Serial.println("I am multi-tasking :)");
  delay(1000);
}
