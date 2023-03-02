#include <stdio.h>
#include <iostream>
#include "cat.h"

Cat::Cat(): name("Tom"), lives(9){
    std::cout << "Default constructor called..." << std::endl;
};

Cat::Cat(std::string name) : name(name), lives(9){
    std::cout << "Constructor called with name..." << std::endl;
};

Cat::Cat(std::string name, unsigned int lives) : name(name), lives(lives){
    std::cout << "Constructor called with name and lives..." << std::endl;
};

Cat::~Cat(){
        std::cout << "Destructor called..." << std::endl;
    };

void Cat::set_name(const std::string& name){
    this->name = name;
    std::cout << "set_name called..." << std::endl;
};

void Cat::set_lives(const unsigned int& lives){
    if (lives == 0 && this->lives > 0){
        set_name("The Cat formerly known as " + name);
        this->lives = lives;
    }
    else if(lives <= this->lives){
        this->lives = lives;
    }
    std::cout << "set_lives called..." << std::endl;
};