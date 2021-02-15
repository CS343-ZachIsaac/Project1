#include "SmokeParticle.h"

void SmokeParticle::update(float dt)
{
	BasicParticle::update(dt);

	//scale
	setScale(getScale() - glm::vec3(0.0001, 0.0001, 0.0));
	//rotation

	//color
	//change alpha to move in and out
	if (getColor().a >= .2 && !Fade) {
		Fade = true;
	}
	if (!Fade)
	{
		setColor(getColor() + glm::vec4(0.0, 0.0, 0.0, 0.02));
	}
	if (Fade && getLife() <= 1)
	{
		setColor(getColor() + glm::vec4(0.0, 0.0, 0.0, -0.02));
	}
	setPosition(getPosition() + (getVelocity() * dt));
}

void SmokeParticle::setFade(bool value)
{
	Fade = value;
}


