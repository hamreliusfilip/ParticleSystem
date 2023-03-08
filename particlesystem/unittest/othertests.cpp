#include <catch2/catch_all.hpp>
#include <particlesystem/particlesystem.h>
#include "particle.hpp"
#include "emitter.hpp"

//TEST_CASE("Particles have finite lifetime", "[particles]") {
//
//    ParticleSystem ps;
//
//    Particle tempParticle;
//    tempParticle.lifetime = 1;
//
//    ps.particles.push_back(tempParticle);
//
//    float dt = float(0.1);
//
//    for (int i = 0; i < 10; i++) {
//        ps.update(dt);
//    }
//
//    for (auto& p : ps.particles) {
//        REQUIRE(p.lifetime < 0);
//    }
//}

TEST_CASE("Check Emitter", "[Emitter]"){
    
    GIVEN("ParticleSystem"){
        
        ParticleSystem ps;
        
        REQUIRE()
    
    }
    
        
    
        TestEmitter* testEmm = new TestEmitter;

        ps.emitters.push_back(testEmm);

        
    
        WHEN(<#desc#>)
    
        THEN(<#desc#>)
    
        SCENARIO(<#...#>)
    }

