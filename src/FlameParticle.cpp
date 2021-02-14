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
}

