#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofDisableArbTex();
	//Use this line for texture load check -- assert(img.getWidth() != 0 && img.getHeight() != 0);
	buildMesh(FlameMesh, 1.0, 1.0, glm::vec3(0.0, 0.0, 0.0));
	buildMesh(SmokeMesh, 1.0, 1.0, glm::vec3(0.0, 0.0, 0.0));

	//------------
	Flame1.load("textures/flame_05.png");
	assert(Flame1.getWidth() != 0 && Flame1.getHeight() != 0);
	Flame2.load("textures/flame_06.png");
	assert(Flame2.getWidth() != 0 && Flame2.getHeight() != 0);

	//----------
	Smoke1.load("textures/smoke_04.png");
	assert(Smoke1.getWidth() != 0 && Smoke1.getHeight() != 0);
	Smoke2.load("textures/smoke_05.png");
	assert(Smoke2.getWidth() != 0 && Smoke2.getHeight() != 0);
	ReloadShaders();
}

//--------------------------------------------------------------

void ofApp::ReloadShaders()
{
	ParticleShader.load("particleVertex.vert", "particleFragment.frag");
	needsReload = false;
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (needsReload)
	{
		ReloadShaders();
	}
	particleSystem.update(ofGetLastFrameTime());
	smokeParticleSystem.update(ofGetLastFrameTime());
}

//--------------------------------------------------------------
void ofApp::draw() {
	using namespace glm;
	//Shader begin
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ParticleShader.begin();
	for (FlameParticle f : particleSystem)
	{
		//Get Particle translation(velocity), rotation, scale and build a 4D matrix for transformation
		mat4 transformationMatrix = buildMatrix(/*particle position*/f.getPosition(), /*particle rotation*/f.getRotation(), /*particle scale*/f.getScale());
		//Pass the 4D matrix into the shader for the transformation to be applied
		ParticleShader.setUniformMatrix4f("transformation", /*transformation matrix*/ transformationMatrix);

		//Get Any brightnes, color, and other variables and pass to fragment shader
		switch (f.getSprite())
		{
		case 0:
			ParticleShader.setUniformTexture("Tex", Flame1, 0);
			break;
		case 1:
			ParticleShader.setUniformTexture("Tex", Flame2, 0);
			break;
		}
		
		
		ParticleShader.setUniform4f("particleColor", f.getColor());
		//draw the quad
		FlameMesh.draw();

	}
	//shader endl
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ALPHA);
	for (SmokeParticle s : smokeParticleSystem)
	{
		//Get Particle translation(velocity), rotation, scale and build a 4D matrix for transformation
		mat4 transformationMatrix = buildMatrix(/*particle position*/s.getPosition(), /*particle rotation*/s.getRotation(), /*particle scale*/s.getScale());
		//Pass the 4D matrix into the shader for the transformation to be applied
		ParticleShader.setUniformMatrix4f("transformation", /*transformation matrix*/ transformationMatrix);

		//Get Any brightnes, color, and other variables and pass to fragment shader
		switch (s.getSprite())
		{
		case 0:
			ParticleShader.setUniformTexture("Tex", Smoke1, 0);
			break;
		case 1:
			ParticleShader.setUniformTexture("Tex", Smoke2, 0);
			break;
		}


		ParticleShader.setUniform4f("particleColor", s.getColor());
		//draw the quad
		SmokeMesh.draw();

	}
	ParticleShader.end();
}
//--------------------------------------------------------------
void ofApp::buildMesh(ofMesh& mesh, float w, float h, glm::vec3 pos)
{
	float verts[] = { -w + pos.x, -h + pos.y,  pos.z,
			-w + pos.x,  h + pos.y,  pos.z,
			w + pos.x,  h + pos.y,  pos.z,
			w + pos.x, -h + pos.y,  pos.z };
	float uvs[] = { 0,0, 0,1, 1,1, 1,0 };
	for (int i = 0; i < 4; ++i) {
		int idx = i * 3;
		int uvIdx = i * 2;
		mesh.addVertex(glm::vec3(verts[idx], verts[idx + 1], verts[idx + 2]));
		mesh.addTexCoord(glm::vec2(uvs[uvIdx], uvs[uvIdx + 1]));
	}
	ofIndexType indices[6] = { 0,1,2,2,3,0 };
	mesh.addIndices(indices, 6);
}

//--------------------------------------------------------------

glm::mat4 ofApp::buildMatrix(const glm::vec3& trans, const float& rot, const glm::vec3& _scale)
{
	using namespace glm;
	mat4 translation = translate(trans);
	mat4 rotation = rotate(rot, vec3(0.0, 0.0, 1.0));
	mat4 scaling = scale(_scale);
	return scaling*rotation*translation;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (key == '`')
	{
		needsReload = true;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
