int const LED_GREEN = 13;
int const LED2_YELLOW = 12;
int const LED3_RED = 11;
char opt;

// --- Variable para intermitencia ---
bool intermitenciaActiva = false;

void menu(){
  Serial.println(" Main menu ");
  Serial.println("[1] Turn on led red.");
  Serial.println("[2] Turn off led red.");
  Serial.println("[3] Turn on led Yellow.");
  Serial.println("[4] Turn off led Yellow.");
  Serial.println("[5] Turn on led green.");
  Serial.println("[6] Turn off led green.");
  Serial.println("[7] Turn on all.");
  Serial.println("[8] Turn off all.");
  Serial.println("[9] Intermitence.");
  Serial.println("Press any option: ");
}

void setup() {
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED2_YELLOW, OUTPUT);
  pinMode(LED3_RED, OUTPUT);

  Serial.begin(9600);
  Serial.println("[Welcome]");
  Serial.println("Press any key to show menu: ");
}

void loop() {
  // ------- MENÚ POR SERIAL --------
  if (Serial.available() > 0) {
    menu();
    opt = Serial.read();

    if (opt == '1') {
      intermitenciaActiva = false;   // detener intermitencia
      digitalWrite(LED3_RED, HIGH);
    }
    if (opt == '2') {
      intermitenciaActiva = false;
      digitalWrite(LED3_RED, LOW);
    }
    if (opt == '3') {
      intermitenciaActiva = false;
      digitalWrite(LED2_YELLOW, HIGH);
    }
    if (opt == '4') {
      intermitenciaActiva = false;
      digitalWrite(LED2_YELLOW, LOW);
    }
    if (opt == '5') {
      intermitenciaActiva = false;
      digitalWrite(LED_GREEN, HIGH);
    }
    if (opt == '6') {
      intermitenciaActiva = false;
      digitalWrite(LED_GREEN, LOW);
    }
    if (opt == '7') {
      intermitenciaActiva = false;
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED2_YELLOW, HIGH);
      digitalWrite(LED3_RED, HIGH);
    }
    if (opt == '8') {
      intermitenciaActiva = false;
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED2_YELLOW, LOW);
      digitalWrite(LED3_RED, LOW);
    }
    if (opt == '9') {
      intermitenciaActiva = true;   // activar intermitencia infinita
    }
  }

  // ------- INTERMITENCIA INFINITA --------
  if (intermitenciaActiva) {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED2_YELLOW, HIGH);
    digitalWrite(LED3_RED, HIGH);
    delay(500);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED2_YELLOW, LOW);
    digitalWrite(LED3_RED, LOW);
    delay(500);
  }
}
