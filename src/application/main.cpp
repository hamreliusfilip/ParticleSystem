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

float rnd() { return rand() / static_cast<float>(RAND_MAX); }

float srnd() { return rnd() * 2.0f - 1.0f; }

int main(int, char**) try {
    rendering::Window window("Particle System v0.0.1 pre-release alpha", 850, 850);
    
    ParticleSystem particleSystem;
    
    Color color = {1, 1, 1, 1};
    
    std::vector<Emitter*> emitters;
    std::vector<Effect> effects;
    
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
            window.sliderInt("Select amount of particles", value, 1, 1000);
            
            if (window.button("New explosion emitter")) {
                Explosion* newEmitter = new Explosion(value); // Amount attribute
                newEmitter->position = {0,0};
                emitters.push_back(newEmitter);
            }
            
            // ------------ EFFECTS ------------
            
             if (window.button("New Gravity well effect")) {
                GravityWell GravityEff;
                effects.push_back(GravityEff);
            }
            
            if (window.button("New wind effect")) {
                Wind WindEff;
                effects.push_back(WindEff);
            }
            window.endGuiWindow();
        }
        
        // ------------------------------ GUI END -----------------------------------
        
        // ------------------------------ RENDER ------------------------------------
        
        // Create particles for each emitter
        for (size_t i = 0; i < emitters.size(); i++){
            particleSystem.createParticles(emitters[i], dt);
        }

        // Update particles
        particleSystem.update(effects, dt);
        
        // Render particles
        for (size_t i = 0; i < particleSystem.particles.size(); i++){
            Particle tempP = particleSystem.particles[i];
            window.drawPoint(tempP.position, tempP.radius, color); 
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
