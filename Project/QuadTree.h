#pragma once
#include <vector>
#include <d3d11.h>
#include <DirectXMath.h>
#include <DirectXCollision.h>

#include "SceneObjectTest.h"

enum class Node{ROOT, INNER, LEAF};

const int MAXDEPTH = 2;

class QuadTree {
public:
	QuadTree(std::vector<SceneObjectTest*> &objects, int depth, float size, DirectX::XMFLOAT3 pos);
	~QuadTree();
private:
	std::vector<SceneObjectTest*> objects;
	DirectX::BoundingBox box;
	QuadTree* nodes[4];
	Node type;
	int depth;
};