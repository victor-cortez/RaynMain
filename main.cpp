//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Map.h"
#include "TWODRenderer.h"
#include "Maps/Map1.h"
#include "Player.h"
#include "InputManager.h"

using namespace std;
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
//Screen dimension constants
const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 240;
const int BLOCK_SIZE = 10;
const int FRAMERATE = 60;
const int SPEED = 40;
const bool ISFULLSCREEN = false;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gXOut = NULL;


//The window renderer
SDL_Renderer* gRenderer = NULL;

TWODRenderer my2DRenderer;
Player* myPlayer = new Player();
Map* myMap1 = new Map1();
InputManager myInputManager;
void close()
{
    //Deallocate surface
    SDL_FreeSurface( gXOut );
    gXOut = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    TTF_Quit();
    //Quit SDL subsystems
    SDL_Quit();
}

bool init()
{
    //Initialization flag
    bool success = true;
    TTF_Init();
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

            }
        }
    }
    if (ISFULLSCREEN){
        SDL_SetWindowFullscreen(gWindow, SDL_WINDOW_FULLSCREEN);
    } else {
        SDL_SetWindowFullscreen(gWindow, 0);
    }

    my2DRenderer.initialize(SCREEN_HEIGHT,SCREEN_WIDTH,gRenderer);
    myPlayer->initialize(SCREEN_HEIGHT,SCREEN_WIDTH,gRenderer);
    myInputManager.addPlayer(myPlayer);
    return success;
}

int main( int argc, char* args[] )
{

    //struct timeval stop, start;
    float startTime;
    float endTime;

    //do stuff

    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( false)
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //Define parts
            int deltatime = 0;
            //While application is running
            while( !quit )
            {
                //mingw_gettimeofday(&start, NULL); //start time
                startTime = (float) clock();
                //Handle events on queue
                while( SDL_PollEvent( &e ) ){
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    myInputManager.processInput(e);
                }
                myInputManager.update(deltatime);


                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );
                //Render our stuff
                my2DRenderer.renderMap(myMap1);
                myPlayer->renderPlayer();
                //Update screen
                SDL_RenderPresent( gRenderer );

                //Management to cap the framerate and keep it constant at the specified framerate
                SDL_Delay((int) MAX((1000/FRAMERATE)-deltatime,0) );
                //mingw_gettimeofday(&stop, NULL);
                endTime = (float)  clock();
                //deltatime = (int) stop.tv_usec - start.tv_usec;
                deltatime = 1000*((endTime-startTime))/CLOCKS_PER_SEC; //Working with milliseconds here
                //cout<<deltatime<<" " << CLOCKS_PER_SEC<<endl;
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}