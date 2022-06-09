/*
 *  simulation.h
 *
 *  Created on: Jun 8, 2022
 *      Author: Dylan
 */

#ifndef _INC_SIMULATION_H
#define _INC_SIMULATION_H

/* ---------------------------------------------------------------------------------------- */

#define SDL_ERRMSG_SIZE (150)

#define WINDOW_WIDTH 1152
#define WINDOW_HEIGHT 648
#define SIMULATION_FPS 60


/* ---------------------------------------------------------------------------------------- */

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include "simobject.h"
#include "userinteractions.h"
#include "common.h"

/* ---------------------------------------------------------------------------------------- */



/* ---------------------------------------------------------------------------------------- */

// manages the simulation as a whole
typedef struct simulation_t
{
    
    bool                running;                              // simulation on/off
    uint8_t             FPS;                                  // how many times the simulation is updated per second
    
    void                (*destroyObject)(simobject_t *);      // function for removing simulation objects
    simobject_t*        (*createObject)(simobject_t);         // function for adding simulation objects

    SDL_Renderer        *renderer;                            // SDL renderer the simulation is using
    SDL_Window          *window;                              // SDL window the simulation is using

    simobject_t         *simobjects;                          // array of objects in the simulation
    userinteractions_t  userinteractions;                     // structure of possible user interactions

} simulation_t;

/* ---------------------------------------------------------------------------------------- */

void simulation_init(simulation_t *sim);
void simulation_start(simulation_t *sim);
void simulation_kill(simulation_t *sim);

#endif