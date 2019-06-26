#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <GL/glew.h>

class WinKernel{
    
    public:
    WinKernel(int width, int height) : status(1){
        _win = initWindow(); // Default load
        if(_win != NULL){
            if(!initGLRenderer()){
                status = 0;
            }
        }else
        {
            status = 0;
        }
        
    }
    ~WinKernel(){
        SDL_GL_DeleteContext(_gl_context);
        SDL_DestroyWindow(_win);
        SDL_Quit();
    }
    int launch(){
        bool isRunning = true;
        float i = 0.0f;
        SDL_Event event;
        if(status){
            while(isRunning) {
                // Gestion des évènements

                SDL_WaitEvent(&event);
                    
                if(event.window.event == SDL_WINDOWEVENT_CLOSE){
                    isRunning = false;
                }
                glClear(GL_COLOR_BUFFER_BIT);
                glClearColor(1.0f,i,0.0f,1.0f);
                SDL_GL_SwapWindow(_win);
                i+=0.01f;
                
            }
            
        }
    }
    private:

    int errMemoryUnalloc(int sizeByte){
        //On affiche un message d'erreur informant d'une erreur d'allocation dynamique
        fprintf(stderr, "! Allocation Bound Error :/ -> Cannot allocate %d bytes", sizeByte);
        return 0;
    }
    SDL_Window* initWindow(){
        //Vérifie l'initialisation du module vidéo (et audio) de SDL.
        //Le cas échant fermera l'application
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0 )
        {
            std::cerr << "Window Initialisation Error :/ ->" << SDL_GetError() << std::endl;
            status = 0;
            return NULL;
        }

        //Crée la fenêtre SDL en taille maximisé et renvoie son pointeur
        SDL_Window* windowP = SDL_CreateWindow("Piwel Game Creator indev",SDL_WINDOWPOS_UNDEFINED,
                                                                SDL_WINDOWPOS_UNDEFINED,
                                                                640,
                                                                480,
                                                                SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

        //Si le pointeur est NULL, on affiche un message d'erreur
        if(windowP == NULL){
            fprintf(stderr,"Window Creation Error :/ -> %s\n",SDL_GetError());
        }

        //On renvoie le pointeur de la fênetre
        return windowP;
    }
    int initGLRenderer(){
        
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    
        _gl_context = SDL_GL_CreateContext(_win);
        
        GLenum initialisationGLEW( glewInit() );
        if(initialisationGLEW != GLEW_OK)
        {
            std::cout << "Erreur d'initialisation de GLEW : " << glewGetErrorString(initialisationGLEW) << std::endl;
            return 0;
        }
        return 1;
    }
    SDL_Window* _win;
    SDL_GLContext _gl_context;
    int status;
};