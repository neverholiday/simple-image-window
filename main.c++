#include <iostream>

#include <stdio.h>
#include <stdint.h>

#include <glad/glad.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>


// window width and height
#define WindowWidth 800
#define WindowHeight 600


int main ()
{

	// set window names
	const char *windowName = "Simple image window";

    std::cout << "initialize window." << std::endl;

    // set to core profile
     if (SDL_Init( SDL_INIT_VIDEO) <  0 )
        std::cout << "Couldn't initialize SDL" << std::endl;

    SDL_GL_LoadLibrary(NULL);
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 2 );


	// use for opengl
  	SDL_Window *window = SDL_CreateWindow( windowName, 
												0, 0, 
												WindowWidth, 
												WindowHeight, 
												0 );
	
    std::cout << "initialize OpenGL context." << std::endl;
	
    // create context
	SDL_GLContext context = SDL_GL_CreateContext( window );

	// make current 
	SDL_GL_MakeCurrent( window, context );

    // Check OpenGL properties
    printf("START OpenGL loaded\n");
    if ( !gladLoadGLLoader( SDL_GL_GetProcAddress ) );
        std::cout << "GLAD load failed" << std::endl;
        return 1;

    printf("END OpenGL loaded\n");
    printf("Vendor:   %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version:  %s\n", glGetString(GL_VERSION));

    return 0;

    // define is running
	int32_t isRunning = 1;
    
    std::cout << "initialize OpenGL stuff." << std::endl;

    //
    //  OPENGL
    //
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };


    // // gen vbo buffers
    // unsigned int vbo;
    // glGenBuffers( 1, &vbo ); 

    std::cout << "Start loop." << std::endl;
	// main loop of application
	while ( isRunning ) {
		
		// poll event
		SDL_Event event;
		while ( SDL_PollEvent( &event ) ) {
		
            // check escape key
			if ( event.type == SDL_KEYDOWN ) {
				
				switch ( event.key.keysym.sym ) {
					case SDLK_ESCAPE:
						isRunning = 0;
						break;
					default:
						break; 
				}
			}
            // quit program
			else if ( event.type == SDL_QUIT ) {
				isRunning = 0;
			}
		}

		// glViewport( 0, 0, WindowWidth, WindowHeight );
		glClearColor( 0.1f, 0.1f, 0.1f, 1.0f );
		// glClear( GL_COLOR_BUFFER_BIT );

		// SDL_GL_SwapWindow( window );
	}

  return 0;

}
