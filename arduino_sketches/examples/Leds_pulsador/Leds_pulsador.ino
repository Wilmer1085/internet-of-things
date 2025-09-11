const int boton = 10;       // Pulsador con INPUT_PULLUP
int estadoBoton;           // Lectura actual
int ultimoEstadoBoton = HIGH; 
unsigned long ultimoTiempo = 0;
unsigned long rebote = 50; // Tiempo para evitar rebote

int opcionPulsador = 0;    // Esta variable va a simular el menú (1,2,3...)

int const LED_GREEN = 13;
int const LED2_YELLOW = 12;
int const LED3_RED = 11;
char opt;

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
  Serial.println("[9] Interminence.");
  Serial.println("Press any koption ");

}



void setup() {
  
   pinMode(LED_GREEN, OUTPUT);
  pinMode(LED2_YELLOW, OUTPUT);
  pinMode(LED3_RED, OUTPUT);
  pinMode(boton, INPUT_PULLUP);   // <<--- NUEVO

  Serial.begin(9600);
  Serial.println("[Welcome");
  Serial.println("Press any key to show menu: ");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
   if (Serial.available() > 0) {
    menu();
    opt = Serial.read();

    if (opt == '1') { digitalWrite(LED3_RED, HIGH); }
    else if (opt == '2') { digitalWrite(LED3_RED, LOW); }
    else if (opt == '3') { digitalWrite(LED2_YELLOW, HIGH); }
    else if (opt == '4') { digitalWrite(LED2_YELLOW, LOW); }
    else if (opt == '5') { digitalWrite(LED_GREEN, HIGH); }
    else if (opt == '6') { digitalWrite(LED_GREEN, LOW); }
    else if (opt == '7') {
      digitalWrite(LED3_RED, HIGH);
      digitalWrite(LED2_YELLOW, HIGH);
      digitalWrite(LED_GREEN, HIGH);
    }
   if (opt == '8') {
      digitalWrite(LED3_RED, LOW);
      digitalWrite(LED2_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
    }
    else if (opt == '9') {
      if (millis() % 500 < 250) {
        digitalWrite(LED3_RED, HIGH);
        digitalWrite(LED2_YELLOW, HIGH);
        digitalWrite(LED_GREEN, HIGH);
      } else {
        digitalWrite(LED3_RED, LOW);
        digitalWrite(LED2_YELLOW, LOW);
        digitalWrite(LED_GREEN, LOW);
      }
    }
  }

  // ------- PULSADOR --------
  estadoBoton = digitalRead(boton);

  if (estadoBoton != ultimoEstadoBoton) {
    if (estadoBoton == LOW && (millis() - ultimoTiempo) > rebote) {
      opcionPulsador++;
      if (opcionPulsador > 9) opcionPulsador = 1;  // vuelve a la primera opción
      Serial.print("Opción desde botón: ");
      Serial.println(opcionPulsador);
    }
    ultimoTiempo = millis();
  }
  ultimoEstadoBoton = estadoBoton;

  // Ejecuta la acción según la opción seleccionada por el botón
  switch (opcionPulsador) {
    case 1: digitalWrite(LED3_RED, HIGH); break;
    case 2: digitalWrite(LED3_RED, LOW); break;
    case 3: digitalWrite(LED2_YELLOW, HIGH); break;
    case 4: digitalWrite(LED2_YELLOW, LOW); break;
    case 5: digitalWrite(LED_GREEN, HIGH); break;
    case 6: digitalWrite(LED_GREEN, LOW); break;
    case 7:
      digitalWrite(LED3_RED, HIGH);
      digitalWrite(LED2_YELLOW, HIGH);
      digitalWrite(LED_GREEN, HIGH);
      break;
    case 8:
      digitalWrite(LED3_RED, LOW);
      digitalWrite(LED2_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
      break;
    case 9:
      if (millis() % 500 < 250) {
        digitalWrite(LED3_RED, HIGH);
        digitalWrite(LED2_YELLOW, HIGH);
        digitalWrite(LED_GREEN, HIGH);
      } else {
        digitalWrite(LED3_RED, LOW);
        digitalWrite(LED2_YELLOW, LOW);
        digitalWrite(LED_GREEN, LOW);
      }
      break;
  }

  }
