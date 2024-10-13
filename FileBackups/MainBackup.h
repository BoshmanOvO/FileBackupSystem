#ifndef MAINBACKUP_H
#define MAINBACKUP_H

#include<iostream>
#include <map>
#include <ctime>
#include <string>
#include <vector>
#include "FileBackup.h"
using namespace std;

class MainBackup {
    map<string, FileBackup *> globalBackup; // file and its backup
public:
    void fullBackup(const time_t timestamp, const string& filename, const string& content);
    void incrementalBackup(time_t timestamp, const string& filename, const BlockInfo *blockInfo);
    void readFile(time_t timestamp, const string& filename);
    map<string, FileBackup *> getGlobalBackup() const {
        return globalBackup;
    }
};

#endif //MAINBACKUP_H