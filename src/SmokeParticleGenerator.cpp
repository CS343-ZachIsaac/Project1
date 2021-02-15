#include "SmokeParticleGenerator.h"

void SmokeParticleGenerator::respawn(SmokeParticle& particle) const {

	particle.setLife(2);
	particle.setFade(false);
	//randomize particle parameters

	//Set the sprite
	int randSprite = rand() % 2;
	particle.setSprite(randSprite);


	//Random Position
	glm::vec3 pos;
	//--------------
	float Max = 1; //Max position
	float Min = 0; // Min position
	//--------------
	float random = ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
	//set Position scale and rotation
	pos.x = random; // Results in a random floating-point number between // 0.0 and 1.0, with precision to the 100thsplace.;
	
	Max = 3.1;
	Min = 2.5;
	random = ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
	pos.y = random;
	pos.z = 0.0;
	//Set the new position
	particle.setPosition(pos);


	//Random rotation
	//--------------
	Max = 0.8;
	Min = 0.1;
	//--------------
	random = ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
	float rot = random;
	//set the new rotation
	particle.setRotation(rot);


	//Random Scale
	//--------------
	Max = 0.1;
	Min = 0.05;
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
	Max = 0.1;
	Min = 0.0;
	//--------------
	glm::vec4 color;
	random = ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
	color.r = random;

	Max = 0.05;
	Min = 0.0;
	random = ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
	color.g = random;
	random = ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
	color.b = random;
	color.a = 0.0;
	//set the new scale
	particle.setColor(glm::vec4(color));

	particle.setVelocity(glm::vec3(.5, 1.5, 0.0));
}