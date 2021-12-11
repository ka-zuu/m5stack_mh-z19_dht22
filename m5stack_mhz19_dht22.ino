
#include <M5Stack.h>
#include <DHT.h>
#include <MHZ19_uart.h>

#define DHTPIN 5
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

const int rx_pin = 16; //Serial rx pin no
const int tx_pin = 17; //Serial tx pin no

MHZ19_uart mhz19;

void setup()
{
  dacWrite(25, 0); // スピーカーのノイズ対策

  M5.begin();
  dht.begin();
  mhz19.begin(rx_pin, tx_pin);
  mhz19.setAutoCalibration(false);

  M5.Lcd.setTextSize(5);

  delay(10 * 1000); //
}

void loop() {

  delay(3000);

  // 値の取得
  float temperature = dht.readTemperature(); // 温度を取得
  float humidity = dht.readHumidity(); // 湿度を取得

  int co2ppm = mhz19.getCO2PPM();

  // 画面描画
  M5.Lcd.setCursor(20,20);
  M5.Lcd.printf("%2.0f C",temperature);
  M5.Lcd.setCursor(20,70);
  M5.Lcd.printf("%2.0f",humidity);
  M5.Lcd.println(" %");

  M5.Lcd.setCursor(20,120);
  M5.Lcd.print(co2ppm);
  M5.Lcd.println(" ppm  ");
}