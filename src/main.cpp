#define SDL_MAIN_HANDLED

#include "init/windowkernel.cpp"

int main(int argv, char** args){
    std::cout << "Erreur d'initialisation de GLEW : " << std::endl;
    WinKernel win(500,500);

    return 0;
}