# internet-of-things
# Internet of Things (IoT) — Proyecto Wilmer1085

Este repositorio contiene los códigos y recursos para un proyecto de Internet de las Cosas donde se monitorea temperatura y se controla un motor en función del valor medido.

---

## 🛠️ Contenido del repositorio

- `arduino_sketches/` — incluye los ejemplos / sketches para Arduino (o microcontrolador)  
- `requirements.txt` — dependencias para posibles componentes en Python (por ejemplo, para scripts de servidor)  
- `.gitignore`  
- `LICENSE` — licencia del proyecto (GPL‑3.0)  
- `README.md` — este archivo  

---

## 🎯 Objetivo del proyecto

Este proyecto busca:

- Leer la temperatura con un sensor (por ejemplo LM35, DHT11, DS18B20 u otro).
- En función del valor de temperatura:
  1. Si temperatura ≤ 10 °C → la pantalla LCD parpadea mostrando un mensaje, y el motor permanece apagado.
  2. Si 10 °C < temperatura ≤ 25 °C → la pantalla LCD se apaga, el motor permanece apagado.
  3. Si temperatura > 26 °C → la pantalla LCD muestra “Temp alta” y el motor se enciende (usando pin digital 10).

---

## 📦 Requisitos

Dependiendo de tu implementación, puedes necesitar:

- Arduino IDE (o entorno compatible)  
- Librería **LiquidCrystal** (u otra librería de pantalla LCD para tu hardware)  
- Sensor de temperatura (LM35, DHT11, DS18B20, etc.)  
- Cableado apropiado entre microcontrolador, sensor, motor y pantalla  
- Fuente de poder adecuada para el motor (y circuito de control como transistor/relevador si es necesario)  

Si usas algún script o servicio externo (por ejemplo, en Python), revisa `requirements.txt` para las dependencias.

---

## 💡 Uso / Instrucciones

1. Clona el repositorio:

   ```bash
   git clone https://github.com/Wilmer1085/internet-of-things.git
