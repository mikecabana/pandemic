#include <iostream>
#include <string>

class Roles{
    public:
        Roles(std::string name, int id);
        void output();
    private:
        std::string name;
        int id;
};