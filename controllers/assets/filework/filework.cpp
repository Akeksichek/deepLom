#include "filework.h"

void Filework::setTmpData(std::string &data)
{
    std::fstream out;
    out.open(defaultPath, std::fstream::out);
    if ( !out.is_open() ){
        
        std::cout << "Не удалось подключиться к файлу\n";
        std::cout << defaultPath << std::endl;
        return;
    }
    out << data;
    out.close(); 
    std::cout << defaultPath << " was created" << std::endl;
}

std::string Filework::getTmpData()
{
    std::string data;
    std::string res;
    std::ifstream in(defaultPath);
    if (in.is_open())
    {
        while (std::getline(in, data))
            res += data + "|";
    }
    in.close();

    return res;
}

void Filework::setDefPath(std::string fileName)
{
    defaultPath += fileName; 
}