#ifndef _COMMON_H
#define _COMMON_H

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"


#define ANSI_COLOR_RED_BOLD      "\e[1;31m"
#define ANSI_COLOR_GREEN_BOLD    "\e[1;32m"
#define ANSI_COLOR_YELLOW_BOLD   "\e[1;33m"
#define ANSI_COLOR_BLUE_BOLD     "\e[1;34m"
#define ANSI_COLOR_MAGENTA_BOLD  "\e[1;35m"
#define ANSI_COLOR_CYAN_BOLD     "\e[1;36m"
#define ANSI_COLOR_RESET_BOLD    "\e[0m"


// print a simple message
void message(const char *s)
{
    std::cout << ANSI_COLOR_CYAN << s << ANSI_COLOR_RESET << std::endl;
}

#endif