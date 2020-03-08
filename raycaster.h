#ifndef RAYCASTER_H
#define RAYCASTER_H

#include "config.h"
#include "linalg.h"


#define RAY_EPS   (WALL_SIZE / 3.0f)


typedef struct {
    Vector3f vRay;
    Vector3f hRay;
} RayTuple;


extern Vector3f viewplaneDir;
extern float distFromViewplane;
extern Matrix3f counterClockwiseRotation;
extern Matrix3f clockwiseRotation;
extern RayTuple rays[VIEWPLANE_LENGTH];



/**
 * Initialize rays as a set of normalized vectors,
 */
void initializeRayDirections();

/**
 * Set the length of rays in an array such that
 * they each extend from the player to their first
 * intersection in the world.
 */
void extendRaysToFirstHit(RayTuple* rays);

/**
 * Find the stepping vector of a ray which will bring it
 * from one vertical world intersection to the next.
 */
Vector3f findVerticalRayStepVector(Vector3f* ray);

/**
 * Find the stepping vector of a ray which will bring it
 * from one horizontal world intersection to the next.
 */
Vector3f findHorizontalRayStepVector(Vector3f* ray);

/**
 * Cast a list of prepared rays into the world.
 */
void raycast(RayTuple* rays);

/**
 * Get the tile coordinate (x, y) for the vertical intersection
 * point of a ray and the world.
 */
Vector3f getTileCoordinateForVerticalRay(Vector3f* ray);

/**
 * Get the tile coordinate (x, y) for the horizontal intersection
 * point of a ray and the world.
 */
Vector3f getTileCoordinateForHorizontalRay(Vector3f* ray);

/**
 * Update the raycaster (setup and perform raycasting) for
 * the current frame.
 */
void updateRaycaster();

/**
 * Initialize the raycaster.
 */
void initRaycaster();


#endif /* RAYCASTER_H */
