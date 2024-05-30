#include <iostream>
#include <fstream>
#include <string>

#ifndef FILEWORK_H
#define FILEWORK_H

class Filework
{
private:
    std::string defaultPath = "../controllers/assets/user_data/user_data_tmp";
public:
    void setDefPath(std::string fileName);
    void setTmpData(std::string &data);
    std::string getTmpData();
};

#endif //FILEWORK_H
