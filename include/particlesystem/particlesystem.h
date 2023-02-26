#ifndef __PARTICLESYSTEM_H__
#define __PARTICLESYSTEM_H__

#include <vector>
#include <math.h>

#include "emitter.hpp"
#include "effect.hpp"
#include "particle.hpp"

#include <tracy/Tracy.hpp>
#include <rendering/window.h>
#include "glm/vec2.hpp"
#include "glm/vec4.hpp"

using Color = glm::vec4;

class ParticleSystem {
    
public:
    
    std::vector<Particle> particles;
    
    void createParticles(Emitter* E, float dt);
    
    void useEffect(Effect* Eff, std::vector<Particle> &particles);
    
    void update(float dt); 
};

#endif
