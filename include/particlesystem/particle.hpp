#ifndef particle_hpp
#define particle_hpp

#include "rendering/window.h"
#include "glm/vec2.hpp"
#include "glm/vec4.hpp"

#include <stdio.h>

class Particle {
public:
    glm::vec2 position = {0, 0};
    glm::vec2 velocity = {0, 0};
    glm::vec2 acceleration = {0, 0};
    float lifetime = 1;
    float radius = 0;
    float mass = 0;

};

#endif
