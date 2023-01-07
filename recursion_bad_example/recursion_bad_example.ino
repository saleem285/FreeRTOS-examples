#define STACK_SIZE 1024

void taskEntryPoint(void* params){
  recursive(0);
}

void recursive(int iteration){
  if(iteration == 500){
    return;
  }
  int arr[10];
  for(int i=0; i < 10; i++){
    arr[i] = iteration;
  }
  Serial.print("depth: ");
  Serial.println(iteration);
  recursive(iteration+1);
}

void setup() {
  Serial.begin(9600);
  xTaskCreate(taskEntryPoint, "recursive", STACK_SIZE, nullptr, 5, nullptr);
}



// the loop function runs over and over again forever
void loop() {
  Serial.println("I am multi-tasking :)");
  delay(1000);
}
