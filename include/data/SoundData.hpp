#include <iostream>

class SoundData
{
private:
    std::string path;
    std:: string command;
public:
    std:: string getpath();
    std:: string getcommand();
    void setdata(std :: string path, std:: string command);
    SoundData();
};
