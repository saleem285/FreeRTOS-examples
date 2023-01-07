const int button = 27;
int buttonstatus;
#define STACK_SIZE 2048


void printButtonClicked(void* params){
  while(true){
    if(buttonstatus == HIGH)
      Serial.println("Pressed");
    while(buttonstatus == HIGH)
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
  pinMode(button, INPUT_PULLDOWN);
  
  xTaskCreate(printButtonClicked, "printButtonClicked", STACK_SIZE, nullptr, 0, nullptr);
  xTaskCreate(checkButton, "checkButton", STACK_SIZE, nullptr, 0, nullptr);
}



// the loop function runs over and over again forever
void loop() {
  delay(1000);
}
