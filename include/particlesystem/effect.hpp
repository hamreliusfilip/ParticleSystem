#ifndef effect_hpp
#define effect_hpp

#include "rendering/window.h"
#include "glm/vec2.hpp"
#include "glm/vec4.hpp"
#include "particle.hpp"
#include <stdio.h>

class Effect {
public:
    float strength = 0;
    glm::vec2 position = { 0, 0 };
};

class GravityWell : public Effect{
public:
    GravityWell() : Effect(){
        strength = 10;
        position = {0,0};
    }
};

class Wind : public Effect{
public:
    Wind() : Effect(){
        strength = 10;
        position = {0,0};
    }
};
#endif
