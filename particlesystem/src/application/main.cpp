#include <tracy/Tracy.hpp>
#include <rendering/window.h>

#include <particlesystem/particlesystem.h>
#include "particle.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fmt/format.h>

constexpr float Pi = 3.141592654f;

int main(int, char**) try {
    rendering::Window window("Particle System v0.0.1 pre-release alpha", 850, 850);
    
    ParticleSystem particleSystem;
    
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
                particleSystem.emitters.push_back(new Directional(angle));
            }
            
            // Uniform
            if (window.button("New uniform emitter")) {
                particleSystem.emitters.push_back(new Uniform);
            }
            
            // Explosion
            int value;
            window.sliderInt("Select amount of particles", value, 1, 100);
            
            if (window.button("New explosion emitter")) {
                particleSystem.emitters.push_back(new Explosion(value));
            }
            
             // Test emitter for catch2 test
             // if (window.button("New test emitter")) {
             //   particleSystem.emitters.push_back(new TestEmitter);
             //}
            
            // ------------ EFFECTS ------------
            
            // Gravity effect
            float gravity;
            window.sliderFloat("Select gravity", gravity, 0.0, 30);
            
            if (window.button("New Gravity well effect")) {
                particleSystem.effects.push_back(new GravityWell(gravity));
            }
            
            // Wind effect
            float power;
            window.sliderFloat("Select power of wind", power, 0.0, 10);
            
            if (window.button("New Wind effect")) {
                particleSystem.effects.push_back(new Wind(power));
            }
            
            window.endGuiWindow();
        }
        
        // ------------------------------ GUI END -----------------------------------
        
        // ------------------------------ RENDER ------------------------------------
        
        
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
