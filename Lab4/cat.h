#ifndef CAT
#define CAT

#include <string>

class Cat {
    private: 
        unsigned int lives; 
        std::string name;  
    public:
        Cat();
        
        Cat(std::string name);

        Cat(std::string name, unsigned int lives);

        ~Cat();

        std::string get_name() const {
            return name;
        };

        unsigned int get_lives() const {
            return lives;
        };

        void set_name(const std::string& name);

        void set_lives(const unsigned int& lives);

};

#endif
