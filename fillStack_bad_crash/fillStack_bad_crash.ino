#define STACK_SIZE 1024

void taskEntryPoint(void* params){
  fillStack();
  Serial.println("finished");
  vTaskDelete(nullptr);
}

void fillStack(){
  int arr[50];
  for(int i = 0; i < 50; i++){
    arr[i] = rand();
  }
  for(int i = 0; i < 50; i++){
    delay(10);
    Serial.println(arr[i]);
  }
  
}

void setup() {
  Serial.begin(9600);
  xTaskCreate(taskEntryPoint, "fillStack", STACK_SIZE, nullptr, 5, nullptr);
}



// the loop function runs over and over again forever
void loop() {
  Serial.println("I am multi-tasking :)");
  delay(1000);
}
