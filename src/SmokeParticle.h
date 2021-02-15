#pragma once
#include "BasicParticle.h"

class SmokeParticle : public BasicParticle
{
public:
	// Updates the particle for a specified time increment (dt).
	void update(float dt) override;
	bool setFade(bool value);
private:
	bool Fade{ false };
};