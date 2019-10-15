// i2cScanner
#ifndef I2Ctools_h
#define I2Ctools_h
#include "Arduino.h"
class i2cScanner {
	public:
		i2cScanner(int a = 0);
		bool test_I2C_Addr(uint8_t addr);
		void print_I2C_List(Stream& MySerial);
};
#endif
