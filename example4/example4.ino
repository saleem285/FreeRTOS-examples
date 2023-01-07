int ledpin = 33;
int ledpin2 = 26;
int button = 27;
int button2 = 32;
int buttonstatus;
int buttonstatus2;
#define STACK_SIZE 2048


void lightLed(void* params){
  int brightness = 0;
  int fadeAmount = 5;
  while(true){
  analogWrite(*(int*)params, brightness);

  // change the brightness for next time through the loop:
  if(buttonstatus == HIGH && *(int*)params == ledpin){
    brightness = brightness + fadeAmount;
  }
  if(buttonstatus2 == HIGH && *(int*)params == ledpin2){
    brightness = brightness + fadeAmount;
  }
  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
  }
}

void checkButton(void* params){
  while(true){
    buttonstatus = digitalRead(button);
    buttonstatus2 = digitalRead(button2);
    delay(5);
  }
}

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(button, INPUT_PULLDOWN);
  pinMode(button2, INPUT_PULLDOWN);
  xTaskCreate(checkButton, "checkButtons", STACK_SIZE, nullptr, 5, nullptr);
  xTaskCreate(lightLed, "lightLed", STACK_SIZE, &ledpin, 5, nullptr);
  xTaskCreate(lightLed, "lightLed", STACK_SIZE, &ledpin2, 5, nullptr);
}



// the loop function runs over and over again forever
void loop() {
  Serial.println("I am multi-tasking :)");
  delay(1000);
}
