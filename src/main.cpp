#define SDL_MAIN_HANDLED

#include "init/windowkernel.cpp"

int main(int argv, char** args){
    WinKernel win(500,500);
    win.launch();
    return 0;
}