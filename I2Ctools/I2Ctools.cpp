#include "Arduino.h"
#include "Wire.h"

#include "I2Ctools.h"

i2cScanner::i2cScanner(int a) {
	Wire.begin();
}

bool i2cScanner:: test_I2C_Addr(uint8_t addr) {  
	Wire.beginTransmission(addr);
	if (Wire.endTransmission() == 0)
		return true;
	else
		return false;
}

void i2cScanner:: print_I2C_List(Stream& MySerial) {  
	MySerial.print(" - ");
	for (int counter1 = 0; counter1 < 16; counter1++) {
		MySerial.print("  ");
		MySerial.print(counter1, HEX);  
	}
	for (int counter1 = 0; counter1 < 8; counter1++) {
		MySerial.print("\n ");
		MySerial.print(counter1);
		MySerial.print("_");
		for (int counter2 = 0; counter2 < 16; counter2++) {
			uint8_t addr = (counter1 * 16) +  counter2;
			if (test_I2C_Addr(addr)) {
				MySerial.print(" ");
				if (addr < 16) {
					MySerial.print(" ");
				}
				MySerial.print(addr, HEX);
			} else {
				MySerial.print(" --");
			}      
		}
	}  
	MySerial.println("");
}
