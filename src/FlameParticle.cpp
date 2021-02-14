#include "FlameParticle.h"

void FlameParticle::update(float dt)
{
	//Calls the parent update function;
	BasicParticle::update(dt);
	//add custom implementation here

	//scale
	setScale(getScale() + glm::vec3(0.00015, 0.00015, 0.0));
	//rotation

	//color
	setColor(getColor() - glm::vec4(0.0, 0.0, 0.0, 0.00015));
	//change alpha to move in and out
	if (getColor().a >= 1 && !Fade) {
		Fade = true;
	}
	else if (getColor().a <= 0 && Fade)
	{
		Fade = false;
	}
	if (!Fade)
	{
		setColor(getColor() + glm::vec4(0.0, 0.0, 0.0, 0.02));
	}
	else if (Fade)
	{
		setColor(getColor() - glm::vec4(0.0, 0.0, 0.0, 0.02));
	}
}

bool FlameParticle::setFade(bool value)
{
	return Fade;
}

