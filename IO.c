#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include <termios.h>

/**
 * @author The C Byteble (https://www/youtube.com/@TheCByteble)
 * @brief Custom function to get unser input without displaying on terminal.
 * 
*/
int GetUserInput() {
    struct termios initialConf  = {0};
    struct termios newConf      = {0};
    int input  = '0';

    // stdin file descriptor
    const int stdinFileno = fileno(stdin);

    // Get the current configuration
    tcgetattr(stdinFileno, &initialConf);
    newConf = initialConf;
    newConf.c_lflag &= ~(ICANON | ECHO);

    // Set the new configuration
    tcsetattr(stdinFileno, TCSANOW, &newConf);
    input = getchar();

    // Restore the initial configuration
    tcsetattr(stdinFileno, TCSANOW, &initialConf);

    return input;
}