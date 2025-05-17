#include <M5StickCPlus2.h>

#define TRIG_PIN 26
#define ECHO_PIN 32

bool isPaused = false;
bool isRunning = true;
unsigned long lastButtonPress = 0;

float measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distanceCm = duration * 0.034 / 2; // Speed sound (340 m/s)
  return distanceCm;
}

void displayDistance(float distanceCm) {
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextColor(TFT_WHITE);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(10, 20);

  float distance = distanceCm;
  String unit = "";
  String label = "Target: ";

  if (distanceCm < 2.0) {
    M5.Lcd.print(label);
    M5.Lcd.print("TC"); // Out fo Range (Out Range. OR)
    return;
  } else if (distanceCm > 400.0) {
    M5.Lcd.print(label);
    M5.Lcd.print("OR"); // Too Close (TC)
    return;
  } else if (distanceCm <= 10.0) {
    distance = distanceCm;
    unit = "см";
  } else if (distanceCm <= 100.0) {
    distance = distanceCm / 10;
    unit = "дм";
  } else {
    distance = distanceCm / 100;
    unit = "м";
  }

  M5.Lcd.print(label);
  M5.Lcd.print(distance, 1);
  M5.Lcd.print(" (");
  M5.Lcd.print(unit);
  M5.Lcd.print(")");

  if (isPaused) {
    M5.Lcd.setTextColor(TFT_RED);
    M5.Lcd.setCursor(10, 50);
    M5.Lcd.print("Paused");
  }
}

void setup() {
  M5.begin();
  M5.Lcd.setRotation(1);
  M5.Lcd.fillScreen(TFT_BLACK);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  esp_sleep_enable_ext0_wakeup(GPIO_NUM_39, 1);
}

void loop() {
  M5.update();

  if (M5.BtnPWR.wasPressed()) {
    isRunning = true;
    isPaused = false;
  }
  if (M5.BtnPWR.isPressed()) {
    if (millis() - lastButtonPress >= 2000) {
      esp_deep_sleep_start();
    }
  } else {
    lastButtonPress = millis();
  }

  if (M5.BtnA.wasPressed()) {
    isPaused = true;
  }
  if (M5.BtnB.wasPressed()) {
    isPaused = false;
  }

  if (!isRunning) return;

  if (!isPaused) {
    float distanceCm = measureDistance();
    displayDistance(distanceCm);
  }

  delay(100);
}