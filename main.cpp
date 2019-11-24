#include "dependences.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    ///First, read command-line arguments before to do some function

    ///If there are no commands to parse...
    if(argc < 2){
        cout << "Error: There's no commands to parse." << endl;
        cout << "Enter -help to get info about supported commands!!" << endl;
        return -1;
    }

    ///If there are some to do... Parse commands
    ///The supported commands are:
    ///     -help : Show help.txt
    ///     -reassembling <output> <parts..>
    ///     -divide

    ///Help command loads help.txt file.
    if(strcmp("-help", argv[1]) == 0){
        if(help() != 0)
            return -1;
    }

    ///Divides command
    if(strcmp("-divide", argv[1]) == 0){
        if(argc != 4)
            return -1;

        int parts = atoi(argv[3]);

        if(divide(argv[2], parts) != 0)
            return -1;
    }

    if(strcmp("-reassembling", argv[1]) == 0){
        resassembling(argc, argv);
    }

    return 0;
}
