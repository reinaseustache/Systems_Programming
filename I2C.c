#include"I2C.h"

extern int i2cInit(int address, int buss){
	Address *theAddress;
	
	theAddress = (Address*)malloc(sizeof(Address));
	
	theAddress->address = address;
	theAddress->bussNumber = buss;
	
	//i2c initialization should also go here.
	
	if (!bcm2835_init())
    	{
     		printf("bcm2835_init failed. Are you running as root??\n");
      		return 1;
    	}//if bcm_init
	
	if (!bcm2835_i2c_begin())
    	{
		printf("bcm2835_i2c_begin failed. Are you running as root??\n");
		return 1;
	}//if i2c_begin

	bcm2835_i2c_setSlaveAddress(address); //set HAT address to 0x41
	return 0;
}

extern int getPiRevision(){
	int fd;
	char buff[BUFFERSIZE];
	int size; // to store number of bytes read 

	fd = open("/proc/cpuinfo", O_RDONLY);

	if (fd < 0){ // could not open the file success fully
		strcpy(buff, "ERROR: Cannot open file\n");
		size = strlen(buff);
		size = size + 1;

		write(STDERR_FILENO, buff, size);

		return -1;
	} else { // opened the file successfully
		char val[10] = "\0";

		while((size = read(fd, buff, 1)) > 0) { // read 1 byte at a time 
			buff[1] = '\0';

			if (buff[0] == 'R'){ 
				if((size = read(fd, buff, 7)) > 0){ // read rest to see if its "Revision"
					if(strcmp(buff, "evision\0") == 0){ // matches "Revision"
						while((size = read(fd, buff, 1)) > 0){  // read rest of line
							buff[1] = '\0';
							if(buff[0] == '\n') // reached of the line
								break;
							if((isspace(buff[0]) == 0) && (buff[0] != ':')){ // discard any spaces and colon
								strcat(val, buff); // store revision in val
							}
						} // while
						break;
					} // if
				} // if
			} // if	
		} // while

		if ((strcmp(val, "0000") == 0) || (strcmp(val, "0002") == 0) || (strcmp(val, "0003") == 0))
			return 1;
		else
			return 2;
	}

	close(fd);
	return 0;
}

extern int getPiI2CBusNumber(){
	if(getPiRevision() > 1)
		return 1;
	else
		return 0;
}

extern void write8(unsigned char reg, unsigned char value){
	unsigned char buff[2];
	uint32_t len;

	buff[0] = reg; // register
	buff[1] = value; // value to write to register
	len = 2;

	bcm2835_i2c_write(buff, len);
}

extern unsigned int readU8(unsigned char reg){
	unsigned char buff[1];
	uint32_t len;

	buff[0] = reg; // register
	len = 1;

	return bcm2835_i2c_read(buff, len); // reason code
}
