
/*
Header file of the display functions and defines
define the size of the phonebook width
define an enum for the kind of display that will be used (function with switch for each enum)
function display that takes a string and a paramater to print the line according to the format needeed 
function that display the home page of the app
*/

#pragma once
#define SIZE 150

enum {
    CENTER,
    RIGHT,
    LEFT,
    SEP,
    INPUT,
    ERROR,
    HEADER,
};

// Foreground
#define REDD "\x1B[31m"
#define GREN "\x1B[32m"
#define YLLW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MGNT "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHIT "\x1B[37m"

// Background
#define B_RED "\x1B[41m"
#define B_GRN "\x1B[42m"
#define B_YLW "\x1B[43m"
#define B_BLU "\x1B[44m"
#define B_MAG "\x1B[45m"
#define B_CYN "\x1B[46m"
#define B_WHI "\x1B[47m"

// Style
#define RSET "\x1B[0m"
#define BOLD "\x1B[1m"
#define ITAL "\x1B[3m"
#define UNDL "\x1B[4m"

// Other
#define CLEAR "\033[2J\033[H"
void display_line(std::string str, int mode);
void app_start(void);