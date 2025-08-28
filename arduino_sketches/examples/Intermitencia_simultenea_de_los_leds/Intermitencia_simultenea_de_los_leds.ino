int const LED_GREEN = 13;
int const LED2_YELLOW = 12;
int const LED3_RED = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED2_YELLOW, OUTPUT);
  pinMode(LED3_RED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED2_YELLOW, HIGH);
  digitalWrite(LED3_RED, HIGH);
  delay(1000); //mlseconds
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED2_YELLOW, LOW);
   digitalWrite(LED3_RED, LOW);
   delay(1000); //mlseconds
 

  }
