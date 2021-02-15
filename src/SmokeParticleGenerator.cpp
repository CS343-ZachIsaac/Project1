#include "SmokeParticleGenerator.h"

void SmokeParticleGenerator::respawn(SmokeParticle& particle) const {

	particle.setLife(2);
	particle.setFade(false);
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
	Max = .2;
	Min = .10;
	//--------------
	random = ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
	float rot = random;
	//set the new rotation
	particle.setRotation(rot);


	//Random Scale
	//--------------
	Max = 0.6;
	Min = 0.2;
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

	//--------------
	Max = 0.95;
	Min = 0.6;
	//--------------
	glm::vec4 color;
	random = ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
	color.r = random;

	Max = 0.5;
	Min = 0.15;
	random = ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
	color.g = random;
	color.b = 0.0;
	color.a = 0.8;
	//set the new scale
	particle.setColor(glm::vec4(color));

}