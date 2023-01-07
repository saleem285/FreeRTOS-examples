#include <mutex>

const int button = 27;
int buttonstatus;
std::mutex mutex1;
#define STACK_SIZE 2048


void printButtonClicked(void* params){
  while(true){
    mutex1.lock();
    int status = buttonstatus;
    mutex1.unlock();
    if(status == HIGH)
      Serial.println("Pressed");
    while(status == HIGH){
      mutex1.lock();
      status = buttonstatus;
      mutex1.unlock();
      delay(20);
    }
  }
}

void checkButton(void* params){
  while(true){
    mutex1.lock();
    buttonstatus = digitalRead(button);
    mutex1.unlock();
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
