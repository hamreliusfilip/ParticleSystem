#ifndef effect_hpp
#define effect_hpp

#include "rendering/window.h"
#include "glm/vec2.hpp"
#include "glm/vec4.hpp"
#include "particle.hpp"
#include <stdio.h>

class Effect {
public:
    glm::vec2 position = { 0, 0 };
    
    virtual void affectParticle(Particle particle) = 0;
};

class GravityWell : public Effect{
    
public:
    GravityWell(float gravity) : Effect(), gravity(gravity){
    }
    
    void affectParticle(Particle particle) override{
       
    }
   
    float gravity;
};

class Wind : public Effect{
    
public:
    Wind(float power) : Effect(), power(power){
    }
    
    void affectParticle(Particle particle) override{
        
        float dx = position.x - particle.position.x;
        float dy = position.y - particle.position.y;
        
        particle.velocity.x += power * dx;
        particle.velocity.y += power * dy;
    }
   
    float power;
};
#endif

