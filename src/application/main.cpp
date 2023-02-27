#include <tracy/Tracy.hpp>
#include <rendering/window.h>

#include <particlesystem/particlesystem.h>
#include "particle.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fmt/format.h>

using vec4 = Color;
constexpr float Pi = 3.141592654f;

int main(int, char**) try {
    rendering::Window window("Particle System v0.0.1 pre-release alpha", 850, 850);
    
    ParticleSystem particleSystem;
    
    std::vector<Emitter*> emitters;
    std::vector<Effect*> effects;
    
    float prevTime = 0.0;
    bool running = true;
    
    while (running) {
        
        window.beginFrame();
        
        float t = float(window.time());
        float dt = t - prevTime;
        prevTime = t;
        
        window.clear({0, 0, 0, 1});
        
        // ------------------------------ GUI ------------------------------------
        {
            window.beginGuiWindow("Particle System");
            
            if (window.button("Close application")) {
                running = false;
            }
            
            // ------------ EMITTERS ------------
            
            // Directional
            float angle;
            window.sliderFloat("Select angle, 0-2*pi", angle, 0.0, float(2*Pi));
            
            if (window.button("New directional emitter")) {
                Directional* newEmitter = new Directional(angle); // Angle attribute
                newEmitter->position = {0.5,-0.5};
                emitters.push_back(newEmitter);
            }
            
            // Uniform
            if (window.button("New uniform emitter")) {
                Uniform* newEmitter = new Uniform;
                newEmitter->position = {-0.5,0.5};
                emitters.push_back(newEmitter);
            }
            
            // Explosion
            int value;
            window.sliderInt("Select amount of particles", value, 1, 100);
            
            if (window.button("New explosion emitter")) {
                Explosion* newEmitter = new Explosion(value);
                newEmitter->position = {0,0};
                emitters.push_back(newEmitter);
            }
            
            // ------------ EFFECTS ------------
            
            // Gravity effect
            float gravity;
            window.sliderFloat("Select gravity", gravity, 0.0, 100);
            
            if (window.button("New Gravity well effect")) {
                GravityWell* newEffect = new GravityWell(gravity);
                newEffect->position = {0,0};
                effects.push_back(newEffect);
            }
            
            // Wind effect
            float power;
            window.sliderFloat("Select power of wind", power, 0.0, 10);
            
            if (window.button("New Wind effect")) {
                Wind* newEffect = new Wind(power);
                newEffect->position = {0,0};
                effects.push_back(newEffect);
            }
            
            window.endGuiWindow();
        }
        
        // ------------------------------ GUI END -----------------------------------
        
        // ------------------------------ RENDER ------------------------------------
        
        for (size_t i = 0; i < emitters.size(); i++){
            for(size_t j = 0; j < effects.size(); j++){
                effects[j]->affectParticle(particleSystem.particles);
            }emitters[i]->addParticle(particleSystem.particles,dt);
        }
        
        particleSystem.update(dt);
        
        for (size_t i = 0; i < particleSystem.particles.size(); i++){
            window.drawPoint(particleSystem.particles[i].position,
                             particleSystem.particles[i].radius,
                             particleSystem.particles[i].color);
        }
        
        // -------------------------------------------------------------------------
        
        window.endFrame();
        running = running && !window.shouldClose();
    }
    return EXIT_SUCCESS;
}
catch (const std::exception& e) {
    fmt::print("{}", e.what());
    return EXIT_FAILURE;
}
