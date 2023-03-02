#include <iostream>
#include "cat.h"

int main(int argc, char* argv[]) {
    int num_cats = argc / 2;
    Cat* cats = new Cat[num_cats];
     

    for (int i = 0; i < num_cats; i++) {
        std::string name = argv[i*2 + 1];
        int lives = (int)argv[i*2 + 2];
        cats[i] =Cat(name, lives);
        cats[i].set_name(name); 
        if (i == num_cats-1 && (argc-1) % 2 != 0){
            cats[i].set_lives(9);
        }
        else{
            cats[i].set_lives(lives);
        }
    }

    
    for (int i = 0; i < num_cats; i++) {
         std::cout << cats[i].get_name() << " has "
              << cats[i].get_lives() << " lives." << std::endl;
    }

    delete[] cats;

    return 0;
}