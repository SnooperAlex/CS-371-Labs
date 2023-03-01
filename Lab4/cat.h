#ifndef CAT
#define CAT

#include <string>

class Cat {
  private: 
    unsigned int lives; 
    std::string name;  
    Cat(std::string x){
        lives = 9;
        name = x;
    }

    Cat(std::string x, unsigned int i){
        lives = i;
        name = x; 
    }
    ~Cat(){
        delete[] name;
    };

    std::string Cat::get_name() const {
        return name;
    }

    unsigned int Cat::get_lives() const {
        return lives;
    }
};



#endif
