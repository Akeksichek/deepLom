#include "hashingPass.h"

std::string Password::__hashPassword( std::string password )
{
    std::string hash;
    int secret, _secret_;
    for( auto &s: password )
    {
        secret = rand() % 8 + 1;
        hash += simsID[secret];hash += '$';
        for( int ps = 0; ps < sizeof(passSims); ps++ )
        {
            int psd = 0;
            if( s == passSims[ps] )
            {
                    _secret_ = rand() % 90;
                    if(ps+secret>=sizeof(passSims))
                    {
                        psd = ((ps + secret)-sizeof(passSims));
                        hash+=passSims[psd];
                    }
                    else{
                        hash += passSims[(ps + secret)];
                    }
            }
        }
    }
    
    return hash;
}

std::string Password::__unhashPassword( const std::string &__hashPassword )
{
    std::string pass;
    int secret, secret_sim;
    char sim;
    for(int i = 0; i <= __hashPassword.size(); i++)
    {
        if( __hashPassword[i] == '$' )
        {
            for(int j = 0; j < sizeof(simsID); j++)
            {
                if( simsID[j] == __hashPassword[i - 1] )
                {
                    secret = j;
                }
            }
            for(int j = 0; j < sizeof(passSims); j++)
            {
                if( __hashPassword[i + 1] == passSims[j] )
                {
                    sim = passSims[j - secret];
                    if( j - secret < 0 )
                    {
                        sim = passSims[ sizeof(passSims) + ( j - secret ) ];
                    }
                    break;
                }
            }
            pass += sim;
        }
    }

    return pass;
}

std::string Password::generatePassword()
{
    std::string password;
    for( int i = 0; i < passwordLength; i++ )
        password += passSims[rand() % 70];
    this->password = password;    
    return password;
}
