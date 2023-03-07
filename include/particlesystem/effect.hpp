#ifndef effect_hpp
#define effect_hpp

#include "rendering/window.h"

#include "particle.hpp"

#include "glm/vec2.hpp"
#include "glm/vec4.hpp"

#include <stdio.h>
#include <vector>
#include <cmath>

class Effect {
public:
    glm::vec2 position = { 0, 0 };
    
    virtual void affectParticle(std::vector<Particle> &particles) = 0;
};

class GravityWell : public Effect{
    
public:
    GravityWell(float gravity) : Effect(), gravity(gravity){
    }
    
    void affectParticle(std::vector<Particle> &particles) override{
              
        float differanceX, differanceY;
        
        for(size_t i = 0; i < particles.size(); i++){

            differanceX = position.x - particles[i].position.x;
            differanceY = position.y - particles[i].position.y;
            
            if(differanceX < 1 & differanceY < 1){
                particles[i].velocity.x += gravity * float(0.001) * differanceX;
                particles[i].velocity.y += gravity * float(0.001) * differanceY;
            }
        }
    }float gravity;
};

class Wind : public Effect{
public:
    Wind(float power) : Effect(), power(power){
    }
    
    void affectParticle(std::vector<Particle> &particles) override{
        
        float differanceX, differanceY;
        
        for(size_t i = 0; i < particles.size(); i++){
            
            differanceX = position.x - particles[i].position.x;
            differanceY = position.y - particles[i].position.y;
            
            if(differanceX < 0.5 & differanceY < 0.5){
                particles[i].velocity.x += float(0.001) * power;
                particles[i].velocity.y += float(0.001) * power;
            }
        }
    }float power;
};
#endif
