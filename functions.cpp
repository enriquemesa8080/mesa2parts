#include "dependences.hpp"

using namespace std;

int help()
{
    unsigned long file_size = 0;
    char *file_content;

    ///Open help file and if it doesn't exist display error message
    ifstream help_file;

    help_file.open("help.txt", ios::binary);

    if(!help_file.is_open()){
        cout << "Error: Help file doesn't exists!!" << endl;
        return -1;
    }

    ///Get the file size
    help_file.seekg(0, help_file.end);
    file_size = help_file.tellg();
    help_file.seekg(0, help_file.beg);

    ///Resize array size
    file_content = new char[file_size];

    ///Loads file content inside a char array.
    help_file.read( (char *) file_content, file_size);

    ///Free resources
    help_file.close();
    delete [] file_content;

    ///Display file on screen
    cout.write((char *)file_content, file_size);

    return 0;
}

///Divides a file in many parts
int divide(char file[], unsigned long parts){

    unsigned long file_size = 0;
    unsigned long size_by_package = 0;
    unsigned long remainder = 0;
    int counter = 0;
    char file_name[sizeof(file) + 10];
    char number[10]; ///Max 10 digits

    char *file_content;
    char *package;

    cout << "Divide: " << file << endl;
    cout << "Parts: " << parts << endl;

    ///The file is loaded in memory and closed

    ///Open help file and if it doesn't exist display error message
    ifstream file_to_break;
    ofstream file_part;

    file_to_break.open(file, ios::binary);

    if(!file_to_break.is_open()){
        cout << "Error: File to open doesn't exists!!" << endl;
        return -1;
    }

    ///Get the file size
    file_to_break.seekg(0, file_to_break.end);
    file_size = (unsigned long) file_to_break.tellg();
    file_to_break.seekg(0, file_to_break.beg);

    ///Resize array size
    file_content = new char[file_size];

    ///Loads file content inside a char array.
    file_to_break.read( (char *) file_content, file_size);

    ///Free resources of file opened
    file_to_break.close();

    ///Divides file size number between amount of parts
    size_by_package = file_size / parts;
    remainder = file_size % parts;

    ///Diplay some debugging options
    cout << "Size by package" << size_by_package << endl;
    cout << "File size" << file_size << endl;
    cout << "Remainder" << remainder << endl;

    ///The remainder will be write in a package

    int last_pos = 0;

    /*if(remainder > 0)
        parts++;
    */

    ///Writes the content of the file
    ///And the remainder will be write in package apart

    ///First write all packages with the same size
    while(counter != parts){

        ///It converts integer to string, and store it inside of number variable
        itoa(counter, number, 10);

        ///It copy the original name to file_name
        strcpy(file_name, file);

        ///And concatenate the string content with a number
        strcat(file_name, number);

        file_part.open(file_name, ios::binary);

        if(!file_part.is_open())
            return -1;

        package = new char[size_by_package];

        for(int i = 0; i < size_by_package; i++){
            package[i] = file_content[i+last_pos];
        }

        file_part.write((char *) package, size_by_package);

        cout << file_name << endl;
        counter++;

        last_pos = last_pos + size_by_package;

        delete [] package;

        file_part.close();
    }

    ///If there's a remainder...
    if(remainder > 0){

        counter++;

        ///It converts integer to string, and store it inside of number variable
        itoa(counter, number, 10);
        ///It copy the original name to file_name
        strcpy(file_name, file);

        ///And concatenate the string content with a number
        strcat(file_name, number);

        file_part.open(file_name, ios::binary);

        if(!file_part.is_open())
            return -1;

        package = new char[remainder];

        for(int i = 0; i < remainder; i++){
            package[i] = file_content[i+last_pos];
        }

        file_part.write((char *) package, remainder);

        cout << file_name << endl;

        delete [] package;

        file_part.close();
    }

    return 0;

}

int reassembling(int argc, char *argv[]){

}
