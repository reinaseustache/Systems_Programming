#include<stdio.h>
#include<regex.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
#include<bcm2835.h>

#ifndef I2C
#define I2C

#define BUFFERSIZE 4096

// structure to hold address and bus
typedef struct bussAddress{
	int address;
	int bussNumber;
}Address;

// Gets the version number of the Raspberry Pi board by searching through /proc/cpuinfo
// byte by byte until it finds a line like 'Revision: 0002'.
// It returns 1 if the revision ends with 0000, 0002 or 0003, 2 if the revision ends with
// any other 4 chars and 0 if it couldn't find the revision.
int getPiRevision();

// Gets the I2C bus number by calling getPiRevision and examining it return value
// If getPiRevision returns a value greater that 1 then this function returns
// 1 otherwise it returns 0.
int getPiI2CBusNumber();

// Initializes the I2C bus by dynamically allocating an Address struct and setting 
// the address and bus number, it also initializes the bcm2835 library and i2c the 
// sets the slave address on the hat. It returns if it was successful and 1 otherwise
int i2cInit(int address, int buss);

// Writes an 8-bit value to the specified register/address by passing the 
// bcm2835_i2c_write function an unsigned array containing the register in the first and the 
// value in the second position and the length of this array
void write8(unsigned char reg, unsigned char value);

// Reads an unsigned byte from the I2C device by passing the bcm2835_i2c_read function a buffer
// containing the register to read from in the first position and the length of the buffer
// It returns the a reason code for suuccess or error
unsigned int readU8(unsigned char reg);

#endif