// Reina Eustache
// Project 2
// Due 03/09/2020 11:59 pm
// project2.c
// This file reads the contents of the /etc/password file and outputs
// <username>:<shell> to the screen without the use of stdio.h and 
// stdlib.h. Main returns an error if the file cannot be opened for 
// reading.

#include "project2.h"

int main() {
    int fd; // file descriptor for /etc/passwd
    char buff[BUFFERSIZE]; // array of size 32 to store characters for input/output
    int size; // stores size of characters in buff array

    int countColon = 0; // counts the number of colons encountered

    fd = open("/etc/passwd", O_RDONLY); // opens /etc/passwd for reading only

    if(fd < 0) { // file was not sucessfully opened 
        strcpy(buff, "ERROR: Cannot open file\n");
        size = strlen(buff);
        size =  size + 1;

        write(STDERR_FILENO, buff, size);

        return -1;
    }
    else { // file sucessfully opened for reading

        while ((size = read(fd, buff, 1)) > 0) { // reads to end of file one character at a time
            buff[1] = '\0';

            if(buff[0] == ':') // found a colon
                countColon++;

            if(countColon == 0) // still in the <username> column since first colon not yet reached
                write(STDOUT_FILENO, buff, size);

            if(countColon == 6) // reached <shell> column and can output the rest
                write(STDOUT_FILENO, buff, size);

            if(buff[0] == '\n') // end of line, can reset count for new line
                countColon = 0;
        }
    }

    close(fd); // close file descriptor for /etc/passwd

    return 0;
}