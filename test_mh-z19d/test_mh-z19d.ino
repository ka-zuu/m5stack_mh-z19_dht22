/*----------------------------------------------------------
    MH-Z19 CO2 sensor  SAMPLE
  ----------------------------------------------------------*/

#include <MHZ19_uart.h>
#include <M5Stack.h>

const int rx_pin = 16; //Serial rx pin no
const int tx_pin = 17; //Serial tx pin no

MHZ19_uart mhz19;

/*----------------------------------------------------------
    MH-Z19 CO2 sensor  setup
  ----------------------------------------------------------*/
void setup()
{
    dacWrite(25, 0); // スピーカーのノイズ対策
    M5.begin();
  Serial.begin(9600);
  mhz19.begin(rx_pin, tx_pin);
  mhz19.setAutoCalibration(false);

    M5.Lcd.setTextSize(7);

  Serial.println("MH-Z19 is warming up now.");
  delay(10 * 1000); //
}

/*----------------------------------------------------------
    MH-Z19 CO2 sensor  loop
  ----------------------------------------------------------*/
void loop()
{
  int co2ppm = mhz19.getCO2PPM();
  int temp = mhz19.getTemperature();

  Serial.print("co2: ");
  Serial.println(co2ppm);
  Serial.print("temp: ");
  Serial.println(temp);

M5.Lcd.setCursor(30,30);
  M5.Lcd.println(co2ppm);
  M5.Lcd.setCursor(30,120);
  M5.Lcd.println(temp);

  delay(5000);
}