#pragma once
#include "Window.h"
#include "Timer.h"
#include "Camera.h"


#include "Model.h"
#include "SceneObjectTest.h"

#include "SceneObject.h"
#include "Structures.h"
#include "ShadowMap.h"
#include "CubeMap.h"
#include <string>
#include <iostream>
#include <DirectXMath.h>

#include "flags.h"

class Scene {
public:
	Scene();
	~Scene();
	int Start();
private:
	bool DoFrame();
	bool SetUpDirLight();
	bool SetUpCamBuf();
	void UpdateCam();

	void checkInput();

	float speedfactor = 1.0f;
	float timerCount = 0.0f;
	Window window;
	Timer timer;
	Camera cam;
	CubeMap cMap;
	SceneObjectTest object;
	SceneObjectTest floor;
	SceneObjectTest test;
	//SceneObjectTest skybox;
	DirectionalLight dLight;
	ShadowMap shadow;
	ID3D11Buffer* lightBuf;
	ID3D11Buffer* camBuf;


	

	DirectX::XMMATRIX proj;

};