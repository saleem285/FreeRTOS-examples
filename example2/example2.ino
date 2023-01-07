const int ledpin = 33;
const int button = 27;
int buttonstatus;
#define STACK_SIZE 2048


void lightLed(void* params){
  while(true){
    if(buttonstatus == HIGH){
      digitalWrite(ledpin, HIGH);
    }
    else{
      digitalWrite(ledpin, LOW);
    }
    delay(50);
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
