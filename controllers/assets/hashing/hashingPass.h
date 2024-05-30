#include<iostream>
#include <time.h>
#include <stdlib.h>

#ifndef PASSWORD_HASHING_H
#define PASSWORD_HASHING_H

class Password
{
private:
    int passwordLength = 0;
    std::string password;
    char simsID[11] = "0123456789";
    char hashData[32] = {
                '@','#','&','_','-',
                '(',')','=','%','*',
                ':','/','!','?','+',
                '"','\'','$','~','[',
                ']','{','}','<','>',
                '^','`',';','|'
    }; 
    char passSims[90] = {
        '1','2','3','4','5',
        '6','7','8','9','0',
        '@','#','&','_','-',
        '(',')','=','%','*',
        ':','/','!','?','+',
        '"','\'','~','[',
        ']','{','}','<','>',
        '^','`',';','|','a',
        'b','c','d','e','f',
        'g','h','i','j','k',
        'l','m','n','o','p',
        'q','r','s','t','u',
        'v','w','x','y','z',
        'A','B','C','D','E',
        'F','G','H','I','J',
        'K','L','M','N','O',
        'P','Q','R','S','T',
        'U','V','W','X','Y',
        'Z'};
public:
    Password(){}
    Password( std::string hashingpass ){}
    std::string __hashPassword( std::string password );
    std::string __unhashPassword( const std::string &__hashPassword );
    void setPasswordLength( int length ){passwordLength = length;}
    std::string generatePassword();
    void oPasswordSims()
    {
        for( auto &elem: passSims )
            std::cout << elem;
    }
};

#endif //PASSWORD_HASHING_H
