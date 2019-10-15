#include "I2Ctools.h"
#define line "----------------------------------------------------\n"
i2cScanner I2Cscan;

void setup() {
  Serial.begin(115200);
  Serial.print(line);
  Serial.print("  I²C Scanner by C. Andrzejak\n");
  Serial.print(line);
  I2Cscan.print_I2C_List(Serial);
  Serial.println(line);
}
void loop() {  
}
