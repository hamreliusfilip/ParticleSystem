#ifndef effect_hpp
#define effect_hpp

#include "rendering/window.h"

#include "particle.hpp"

#include "glm/vec2.hpp"
#include "glm/vec4.hpp"

#include <stdio.h>
#include <vector>

class Effect {
public:
    glm::vec2 position = { 0, 0 };
    
    virtual void affectParticle(Effect* Eff, std::vector<Particle> &particles) = 0;
};

class GravityWell : public Effect{
    
public:
    GravityWell(float gravity) : Effect(), gravity(gravity){
    }
    
    void affectParticle(Effect* Eff, std::vector<Particle> &particles) override{
        
        float dx;
        float dy;
        
        for(size_t i = 0; i < particles.size(); i++){
            
            dx = Eff->position.x - particles[i].position.x;
            dy = Eff->position.y - particles[i].position.y;
            
            particles[i].velocity.x += gravity * dx;
            particles[i].velocity.y += gravity * dy;
        }
    }
    
    float gravity;
};

class Wind : public Effect{
    
public:
    Wind(float power) : Effect(), power(power){
    }
    
    void affectParticle(Effect* Eff, std::vector<Particle> &particles) override{
        
        float dx;
        float dy;
        
        for(size_t i = 0; i < particles.size(); i++){
            
            dx = Eff->position.x - particles[i].position.x;
            dy = Eff->position.y - particles[i].position.y;
            
            particles[i].velocity.x += power * dx;
            particles[i].velocity.y += power * dy;
    
        }
    }
    float power;
};


#endif
