#ifndef emitter_hpp
#define emitter_hpp

#include "rendering/window.h"

#include "particle.hpp"

#include "glm/vec2.hpp"
#include "glm/vec4.hpp"
#include <stdio.h>
#include <math.h>
#include <vector>

class Emitter{
public:
    
    glm::vec2 position = {0,0};
    glm::vec2 velocity = {0,0};
    //    double time, delay;
    
    //    bool tick(double dt) {
    //        time += dt;
    //        if(time > delay) {
    //            time = 0;
    //            return true;
    //        }
    //        return false;
    //    }
    
    virtual void addParticle(std::vector<Particle> &particles,Particle particle, float dt) = 0;
};

class Directional : public Emitter {
    
public:
    //    Directional(double angle, double delay) : Emitter(), angle(angle) {
    //    }
    void addParticle(std::vector<Particle> &particles, Particle particle, float dt) override {
        
        if (fmod(dt, 0.1) < 0.01) {
            particle.velocity.y = float(cos((rand() / (float)(RAND_MAX)*2.5) + 0.1) / 10); // Åt höger
            particle.velocity.x = 0.5f;
            particle.radius = 2;
            
            particles.push_back(particle);
        }
    }
    //    double angle;
};

class Uniform : public Emitter {
    
public:
    void addParticle(std::vector<Particle> &particles,Particle particle, float dt) override {
        
        if (fmod(dt, 0.1) < 0.01) {
            particle.velocity.y = (rand() / (float)(RAND_MAX)) * 2.0f - 1.0f;
            particle.velocity.x = (rand() / (float)(RAND_MAX)) * 2.0f - 1.0f;
            
            particle.radius = 2;
            
            particles.push_back(particle);
        }
    }
};

class Explosion : public Emitter {
    
public:
    
    void addParticle(std::vector<Particle> &particles, Particle particle, float dt) override {
        
        int amount = 100;
        
        if (fmod(dt, 0.1) < 0.01) {
            for (int i = 0; i < amount; i++) {
                
                particle.velocity.y = (rand() / (float)(RAND_MAX)) * 2.0f - 1.0f;
                particle.velocity.x = (rand() / (float)(RAND_MAX)) * 2.0f - 1.0f;
                
                particle.radius = 2;
                
                particles.push_back(particle);
            }
        }
    }
};

#endif
