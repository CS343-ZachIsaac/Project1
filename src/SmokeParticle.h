#pragma once
#include "BasicParticle.h"

class SmokeParticle : public BasicParticle
{
public:
	// Updates the particle for a specified time increment (dt).
	void update(float dt) override;
	void setFade(bool value);
private:
	bool Fade{ false };
};