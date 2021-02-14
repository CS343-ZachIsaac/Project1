#include "FlameParticleGenerator.h"

void FlameParticleGenerator::respawn(FlameParticle& particle) const
{
	particle.setLife(120.0f);

	//randomize particle parameters

	//Set the sprite
	int randSprite = rand() % 1;
	particle.setSprite(randSprite);


	//Random Position
	glm::vec3 pos;
	//--------------
	float Max = 1; //Max position
	float Min = -1; // Min position
	//--------------
	float random = ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
	//set Position scale and rotation
	pos.x = random; // Results in a random floating-point number between // 0.0 and 1.0, with precision to the 100thsplace.;
	random = ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
	pos.y = random;
	pos.z = 0.0;
	//Set the new position
	particle.setPosition(pos);


	//Random rotation
	//--------------
	Max = .10;
	Min = .15;
	//--------------
	random = ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
	float rot = random;
	//set the new rotation
	particle.setRotation(rot);


	//Random Scale
	//--------------
	Max = .2;
	Min = .6;
	//--------------
	glm::vec3 _scale;
	random = ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
	_scale.x = random;
	random = ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
	_scale.y = random;
	_scale.z = 1.0;
	//set the new scale
	particle.setScale(_scale);
	//set color random


}


