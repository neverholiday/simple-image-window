#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>


// window width and height
#define WindowWidth 800
#define WindowHeight 600


int main ()
{

	// set window names
	const char *windowName = "Simple image window";

	// use for opengl
	uint32_t windowFlags = SDL_WINDOW_OPENGL;
  	SDL_Window *window = SDL_CreateWindow( windowName, 
												0, 0, 
												WindowWidth, 
												WindowHeight, 
												windowFlags );
	
	// create context
	SDL_GLContext context = SDL_GL_CreateContext( window );

	// make current 
	SDL_GL_MakeCurrent( window, context );

	int32_t isRunning = 1;
	int32_t FullScreen = 0;

	// main loop of application
	while ( isRunning ) {
		
		// poll event
		SDL_Event event;

		while ( SDL_PollEvent( &event ) ) {
		
			if ( event.type == SDL_KEYDOWN ) {
				
				switch ( event.key.keysym.sym ) {
					case SDLK_ESCAPE:
						isRunning = 0;
						break;
					default:
						break; 
				}
			}
			else if ( event.type == SDL_QUIT ) {
				isRunning = 0;
			}
		}

		glViewport( 0, 0, WindowWidth, WindowHeight );
		glClearColor( 0.1f, 0.1f, 0.1f, 1.0f );
		glClear( GL_COLOR_BUFFER_BIT );

		SDL_GL_SwapWindow( window );
	}

  return 0;

}
