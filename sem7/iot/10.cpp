void setup() {
  Serial.begin(9600);  // Initialize UART
  Serial.println("UART Communication Started!");
}

void loop() {
  Serial.println("Hello from UART!");
  delay(1000);  // Send message every 1 second
}
