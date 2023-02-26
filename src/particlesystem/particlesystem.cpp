#include <particlesystem/particlesystem.h>

void ParticleSystem::createParticles(Emitter* E, float dt) {
    
    Particle particle;
    particle.position = {E->position.x, E->position.y};
    particle.lifetime = 30;
    
    E->addParticle(particles, particle,dt);
}

void ParticleSystem::useEffect(Effect* Eff, std::vector<Particle> &particles) {
    
    for (size_t i = 0; i < particles.size(); i++) {
        Eff->affectParticle(Eff, particles);
    }
}

void ParticleSystem::update(float dt){
    
    for (size_t i = 0; i < particles.size(); i++) {
        particles[i].lifetime -= dt;
        particles[i].position += particles[i].velocity * dt;
        if (particles[i].lifetime <= 0) {particles.erase(particles.begin() + int(i));}
    }
    
}
