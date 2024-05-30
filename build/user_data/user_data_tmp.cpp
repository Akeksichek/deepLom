#include <iostream>
#include <string>


#ifndef USERDATA_H
#define USERDATA_H

struct user_data{
    std::string login;
    std::string email;
    std::string role;
    std::string get_userData()
    {
        return "\nlogin: " + login +
        "\nemail: " + email +
        "\nrole: " + role;
    }
};

#endif //USERDATA_H