#pragma once
#include "Particle.h"
#include "SmokeParticle.h"


class SmokeParticleGenerator : public ParticleGenerator<SmokeParticle>
{
    // Called when a new particle needs to be generated. When the function returns, the particle 
    // referenced by the parameter should be reinitialied as a new, random particle.
    void respawn(SmokeParticle& particle) const override;
};