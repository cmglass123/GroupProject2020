#ifndef PLAYER_H
#define PLAYER_H

#include "linalg.h"


extern Vector3f playerPos;
extern Vector3f playerDir;


extern char movingForward;
extern char movingBack;
extern char turningLeft;
extern char turningRight;
extern char playerIsRunning;



/**
 * Initialize the player.
 */
void initPlayer();

/**
 * Update the player for the current frame.
 */
void updatePlayer();

/**
 * Move the player by a given movement vector.
 */
void movePlayer(float dx, float dy);

/**
 * Check if a given movement vector intersects with the world
 * and should be clipped.
 */
int clipMovement(float dx, float dy);

#endif /* PLAYER_H */
