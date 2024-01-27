#include <Arduino.h>
#include <string>

#define LED_PIN 39

int power = 255;

std::string buffer = "";

bool light_on = false;
// Количество нажатий на кнопку для включения светодиода
int button_push_number = 3;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0){
    buffer = "";
    while (Serial.available() > 0){
      buffer += std::string(1, char(Serial.read()));
      delay(500);
    }

    power = std::stoi(buffer);

    Serial.print("Recived power = ");
    Serial.println(power);

  }

  if(digitalRead(18) == HIGH)
  {
    // считаем количество нажатий кнопки
    button_push_number--;
    // Задержка для предотвращения дребезга контактов кнопки
    delay(200);
  }
 
  if (button_push_number == 0)
  {
    light_on = true;
    // устанавливаем счетчик нажания кнопки в исходное значение
    button_push_number = 3;
  }

  if(light_on == true)
  {
    light_on = false;
    analogWrite(LED_PIN, power);
    delay(1000);
  }
  else{
    analogWrite(LED_PIN, 0);
  }
}
