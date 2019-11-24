///This file contains libraries for all modules.

///This software divides a file in many parts. And reassemble all in one!!
///Achievements:
///     -The software can parse the option -help
///To do:
///     -Parse the -reassemble and -divide commands.
///     -Algorithms for these commands.

#include <iostream>
#include <fstream>

#define debug_display(x) cout << "Good at this point" << x << endl;

#include <stdlib.h>
#include <string.h>

int help();
int divide(char file[], unsigned long parts);
int reassembling(int argc, char *argv[]);
