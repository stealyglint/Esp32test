#include <Arduino.h>

uint64_t chipid;
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
  a = a + 1;
	delay(3000);

}
