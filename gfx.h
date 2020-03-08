
#ifndef GFX_H
#define GFX_H

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif




/**
 * Macro to convert from RGB color components to an ABGR integer
 */
#define RGBtoABGR(R,G,B)   (0xFF000000 | ((B) << 16) | ((G) << 8) | (R))



/* Get a string describing the last error encountered by this library */
const char* gfxGetError();






 //Initialize the graphics environment

int initGFX(char* title, unsigned int width, unsigned int height);

/**
 * Create a texture buffer
 * Returns: A pointer to the texture pixel buffer
 */
void* createTexture(unsigned int width, unsigned int height);

/**
 * Free a texture buffer from memory
 *
 * texture: A pointer to the texture to be destroyed
 */
int destroyTexture(void* texture);

/**
 * Draw a texture to the window's entire rendering area.
 *
 * texture: A pointer to the texture to be drawm
 *
 * Returns: 1 if the operation was successful, 0 otherwise.
 */
void displayFullscreenTexture(void* texture);

/**
 * Terminate the graphics environment and free all allocated resources
 */
void destroyGFX();


/**
 * Set the current drawing color for primitives
 */
void setDrawColor(int r, int g, int b, int a);

/**
 * Draw a line between two points on the screen
 */
void drawLine(int x1, int y1, int x2, int y2);

/**
 * Draw a filled rectangle to the screen
 */
void fillRect(int x, int y, int w, int h);

/**
 * Draw the outline of a rectangle to the screen
 */
void drawRect(int x, int y, int w, int h);

/**
 * Refresh the primitive objects on the screen
 */
void presentRenderer();

/**
 * Clear the primitive objects on the screen
 */
void clearRenderer();



/**
 * Generate an xor square texture
 * size:      The size of the square texture in pixels
 * redmask:   The bitwise mask used on the red channel when picking colors to use
 * greenmask: The bitwise mask used on the green channel when picking colors to use
 * bluemask:  The bitwise mask used on the blue channel when picking colors to use
 */
Uint32* generateXorTexture(int size, int redmask, int greenmask, int bluemask);

/**
 * Generate a red xor square texture
 */
Uint32* generateRedXorTexture(int size);

/**
 * Generate a green xor square texture
 */
Uint32* generateGreenXorTexture(int size);

/**
 * Generate a blue xor square texture
 */
Uint32* generateBlueXorTexture(int size);

/**
 * Generate a gray xor square texture
 */
Uint32* generateGrayXorTexture(int size);


#endif /* GFX_H */
