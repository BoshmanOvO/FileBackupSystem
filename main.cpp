#include <iostream>
#include <string>
#include "FileBackups/MainBackup.cpp"
#include "FileBackups/FileBackup.cpp"
#include "FileBackups/BlockInfo.cpp"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    MainBackup mb;
    mb.fullBackup(1000, "file1", "Dehradun is a good town");
    mb.readFile(1000, "file1");

    const BlockInfo bf1 = {1, " is a ni", 0};
    mb.incrementalBackup(1030, "file1", &bf1);
    mb.readFile(1000, "file1");
    mb.readFile(1015, "file1");
    mb.readFile(1030, "file1");


    BlockInfo bf2 = {2, "ce town", 0};
    mb.incrementalBackup(1100, "file1", &bf2);
    mb.readFile(1100, "file1");


    BlockInfo bf3 = {2, "ce town", 1};
    mb.incrementalBackup(1115, "file1", &bf3);
    mb.readFile(1115, "file1");


    mb.fullBackup(1130, "file1", "blah blah blah");
    mb.readFile(1132, "file1");
    cout << endl;
    return 0;
}