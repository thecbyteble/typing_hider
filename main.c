#include "IO.h"
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


#define MAX_INPUT_LEN 100

int main(int argc, char* argv[])
{
    int userInput = '0';
    char buff[MAX_INPUT_LEN] = {'\0'};
    uint8_t index = 0;
    

    fprintf(stdout, "Type something: (MAX: %ld caracters):", MAX_INPUT_LEN);
    while(index < MAX_INPUT_LEN)
    {
        userInput = GetUserInput();
        if(iscntrl(userInput))
        {
            break;
        }
        fprintf(stdout, "*");
    
        buff[index++] = userInput;
    }

    fprintf(stdout, "\n%s (%d caracters)\n", buff, strlen(buff));

    return 0;
}