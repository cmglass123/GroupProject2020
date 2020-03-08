#ifndef RENDERER_H
#define RENDERER_H

#include "gfx.h"
#include "linalg.h"


#define XY_TO_SCREEN_INDEX(X, Y)   (((Y) * WINDOW_WIDTH) + (X))
#define XY_TO_TEXTURE_INDEX(X, Y)   (((Y) * TEXTURE_SIZE) + (X))
#define DARKEN_COLOR(C)     ((((C) >> 1) & 0x7F7F7F7F) | 0xFF000000)


typedef enum {HORIZONTAL_RAY, VERTICAL_RAY} RayType;



/**
 * Calculate the draw height of a pixel column for a given
 * ray length.
 */
float calculateDrawHeight(float rayLength);

/**
 * Draw a textured pixel column on the screen.

 */
void drawTexturedStrip(int x, float wallYStart, float length, int textureX, Uint32* texture, char darken);

/**
 * Draw an un-textured pixel column on the screen.
 */
void drawUntexturedStrip(int x, float wallYStart, float length, Uint32 ABGRColor, char darken);

/**
 * Find the texture column number to use for a given ray.

 */
int getTextureColumnNumberForRay(Vector3f* ray, RayType rtype);

/**
 * Get the barrel-distortion corrected ray length for a given ray.
 */
float getUndistortedRayLength(Vector3f* ray);

/**
 * Render the scene.
 * This assumes that rays have already been cast.
 */
void renderProjectedScene();

#endif /* RENDERER_H */
