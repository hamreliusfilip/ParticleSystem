#include <catch2/catch_all.hpp>
#include <particlesystem/particlesystem.h>
#include "particle.hpp"
#include "emitter.hpp"

TEST_CASE("Particles have finite lifetime", "[particles]") {

    ParticleSystem ps;

    Particle tempParticle;
    tempParticle.lifetime = 1;

    ps.particles.push_back(tempParticle);

    float dt = float(0.1);

    for (int i = 0; i < 10; i++) {
        ps.update(dt);
    }

    for (auto& p : ps.particles) {
        REQUIRE(p.lifetime < 0);
    }
}



SCENARIO("Directional emitter adds particles correctly", "[emitter]") {
    GIVEN("A test emitter with specific velocity, color, radius and lifetime.") {
        TestEmitter emitter;
        
        WHEN("addParticle is called 10 times") {
            std::vector<Particle> particles;
            for (int i = 0; i < 10; i++) {
                emitter.addParticle(particles, float(0.1));
            }
            
            THEN("10 particles are added with expected properties") {
                REQUIRE(particles.size() == 10);
                
                for (const auto& particle : particles) {
                    REQUIRE(particle.color.r == 1);
                    REQUIRE(particle.color.g == 1);
                    REQUIRE(particle.color.b == 1);
                    
                    REQUIRE(particle.velocity.y == Catch::Approx(5.5));
                    REQUIRE(particle.velocity.x == Catch::Approx(5.5));
                    
                    REQUIRE(particle.radius == Catch::Approx(4));
                    
                    REQUIRE(particle.lifetime == Catch::Approx(5));
                }
            }
        }
    }
}
