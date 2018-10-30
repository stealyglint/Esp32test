#include <Arduino.h>

uint64_t chipid;
uint8_t coreNum;
esp_chip_info_t chipInfo;
int a=0;
void setup() {
	Serial.begin(115200);

}

void loop() {

	chipid=ESP.getEfuseMac();//The chip ID is essentially its MAC address(length: 6 bytes).

	Serial.printf("ESP32 Chip ID = %04X",(uint16_t)(chipid>>32));//print High 2 bytes
	Serial.printf("%08X\n",(uint32_t)chipid);//print Low 4bytes.
  Serial.printf("Hello World!\n");
  Serial.printf("%i\n",a);
	esp_chip_info(&chipInfo);
	Serial.printf("Num of Cores: %d,\n WiFi%s%s\n", chipInfo.cores,
								(chipInfo.features & CHIP_FEATURE_BT) ? "/BT" : "",
							(chipInfo.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
  a = a + 1;
	delay(2000);

}
