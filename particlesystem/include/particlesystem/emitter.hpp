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
    double time;
    double delay;
    
    bool tick(double dt) {
        time += dt;
        if(time > delay) {
            time = 0;
            return true;
        }return false;
    }
    
    virtual void addParticle(std::vector<Particle> &particles, float dt) = 0;
};

class Directional : public Emitter {
    
public:
       Directional(float angle) : Emitter(), angle(angle) {
      }
    
    void addParticle(std::vector<Particle> &particles, float dt) override {
        
        delay = 0.001;
        
        Particle particle;
        particle.position = {0.5,-0.5};
        particle.lifetime = 5;
        
        if(tick(dt)){
            
            particle.color = {
                rand() / (float)(RAND_MAX),
                rand() / (float)(RAND_MAX),
                rand() / (float)(RAND_MAX),
                1
                
            };
            
            particle.velocity.y = float(sin(angle));
            particle.velocity.x = float(cos(angle));
            
            particle.radius = float(4);
            
            particles.push_back(particle);
        }
    }
    float angle;
};

class Uniform : public Emitter {
    
public:
    void addParticle(std::vector<Particle> &particles, float dt) override {
        
        delay = 0.001;
        
        Particle particle;
        particle.position = {-0.5,0.5};
        particle.lifetime = 5;
        
        if(tick(dt)){
            
            particle.color = {
                rand() / (float)(RAND_MAX),
                rand() / (float)(RAND_MAX),
                rand() / (float)(RAND_MAX),
                1
                
            };
            
            particle.velocity.y = float(sin(rand()));
            particle.velocity.x = float(cos(rand()));
            
            particle.radius = float(4);
            
            particles.push_back(particle);
        }
    }
};

class Explosion : public Emitter {
    
public:
    Explosion(int amount) : Emitter(), amount(amount) {
   }
    
    void addParticle(std::vector<Particle> &particles, float dt) override {
        
        delay = 0.01;
        
        Particle particle;
        particle.position = {0,0};
        particle.lifetime = 5;
        
        particle.color = {
            rand() / (float)(RAND_MAX),
            rand() / (float)(RAND_MAX),
            rand() / (float)(RAND_MAX),
            1
            
        };
        
        if(tick(dt)){
            for (int i = 0; i < amount; i++) {
                
                particle.velocity.y = float(cos(rand()));
                particle.velocity.x = float(sin(rand()));
                
                particle.radius = float(4);
                
                particles.push_back(particle);
            }
        }
    }int amount;
};

#endif
