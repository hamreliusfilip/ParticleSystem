#include <particlesystem/particlesystem.h>

void ParticleSystem::createParticles(Emitter* E, float dt) {
    
    Particle particle;
    particle.position = {E->position.x, E->position.y};
    
    E->addParticle(particles, particle,dt);
}

void ParticleSystem::update(std::vector<Effect> effects, float dt) {
    
    for (size_t i = 0; i < particles.size(); i++) {
        
        particles[i].lifetime -= dt;
        
        if (particles[i].lifetime <= 0) {
            particles.erase(particles.begin() + int(i));
            
        } else {
            for (size_t j = 0; j < effects.size(); j++) {
                
                float dx = effects[j].position.x - (particles[i].position.x);
                float dy = effects[j].position.y - (particles[i].position.y);
                
                particles[i].velocity.x += effects[j].strength * dx;
                particles[i].velocity.y += effects[j].strength * dy;
                
            } particles[i].position += particles[i].velocity * dt;
        }
    }
}
