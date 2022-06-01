#pragma once
#include "Window.h"
#include "Timer.h"
#include "Camera.h"

#include <math.h>


#include "Model.h"
#include "SceneObjectTest.h"
#include "QuadTree.h"

#include "SceneObject.h"
#include "Structures.h"
#include "ShadowMap.h"
#include "CubeMap.h"
#include <string>
#include <iostream>
#include <DirectXMath.h>

#include "flags.h"

#define NUM_SOLDIERS 1

class Scene {
public:
	Scene();
	~Scene();
	int Start();
private:
	bool DoFrame();
	bool SetUpDirLight();
	bool SetUpSpotLighs();
	bool SetUpBufs();
	void UpdateBufs();
	bool UpdateObjcects(float t);

	void checkInput();
	void cubeMapSetCam(int num);

	void SetLights();
	void SetUpSkybox();

	void ImGuiWindows();

	void EnableTesselation();
	void DisableTesselation();
	void HandleCulling();

	void SetUpGameObjects();

	void UpdateCamera();
	void UpdateProjection();

	void UpdateMouseDelta();

	TextureHandler* texHandl = new TextureHandler();
	float speedfactor = 0.0f;
	float timerCount = 0.0f;
	float dt;
	TimeData theTimedata;
	Window window;
	Timer timer;
	Camera cam;
	CubeMap cMap;
	SceneObjectTest particle;
	SceneObjectTest cube;
	
	SceneObjectTest soldiers[NUM_SOLDIERS];
	SceneObjectTest ground, ground1, ground2, ground3;
	std::vector<SceneObjectTest*> grounds;
	std::vector<SceneObjectTest*>gameObjects;
	DirectionalLight dLight;
	SpotLight sLights[3];
	ShadowMap shadow;
	ShadowShaderBuffer shadowBufferData[NUM_LIGHTS];
	ID3D11Buffer* shadowMapBufs[NUM_LIGHTS];

	ID3D11Buffer* lightBuf;
	ID3D11Buffer* lightBufSpots;
	ID3D11Buffer* camBuf;
	ID3D11Buffer* camBuf2;
	ID3D11Buffer* camBufTime;

	//SceneObjectTest skybox[6];

	QuadTree* qtree;
	std::vector<QuadTree*> intersectingNodes;
	std::vector<SceneObjectTest*>objectsToDraw;

	DirectX::XMMATRIX proj;

	//Settings
	bool tesselation;
	bool tesselationTemp;
	bool quadTreeOn;
	bool frustumCheckOn;

	bool updateCulling;

	float nearZ;
	float farZ;
	float fov;

	float mouseDX, mouseDY, mouseXtemp, mouseYtemp;
	

};