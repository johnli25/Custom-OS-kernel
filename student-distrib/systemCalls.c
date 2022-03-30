#include "systemCalls.h"
#include "filesys.h"

int32_t execute (const uint8_t* command){
    //command is a string, have to parge (ex: shell)

    //parse through the string - past 391OS> get after white space 
    int index = 0;
    while(command[index] == ' '){
        index++;
    }

    uint8_t buffer[128];
    int bufIndex = 0;
     while(command[index] != ' ' && command[index] != '\n'){
        buffer[bufIndex] = command[index];
        index++;
        bufIndex++;
    }

    //buffer is the command without all white space ^

    dentry_t myDentry;
    int check = read_dentry_name(buffer, &myDentry);
    if(check == -1){
        return -1; //FAILED TEST
    }

    if (myDentry.file_type != 2){ //checks if valid type (executable)
        return -1; //FAILED TEST 
    }

    uint8_t ELFBUFFER[10];
    read_data(myDentry.inode, 0, ELFBUFFER,  4); //why 4 and not 3?

    uint8_t * ELFSTRING = " ELF"; //added a space
    int32_t equalCheck = strncmp(ELFBUFFER, ELFSTRING, 4);

    if(equalCheck != 0){ //checks if it is an ELF
        return -1; //FAILED TEST
    }

    

   
}