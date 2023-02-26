#ifndef effect_hpp
#define effect_hpp

#include "rendering/window.h"
#include "particlesystem.h"
#include <vector>
#include "glm/vec2.hpp"
#include "glm/vec4.hpp"
#include "particle.hpp"
#include <stdio.h>

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
