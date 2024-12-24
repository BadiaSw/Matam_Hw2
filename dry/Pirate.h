
#pragma once

#include <iostream>

using std::string;

class Pirate {
private:
    string name;
    int bounty;

public:
    Pirate();
    Pirate(const string& name,const int);

    ~Pirate() = default;

    void setName(const string& name);

    string getName();

    void setBounty(const int bounty);

    int getBounty();

    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);
};
