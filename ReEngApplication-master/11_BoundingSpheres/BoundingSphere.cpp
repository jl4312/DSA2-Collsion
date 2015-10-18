#include "BoundingSphere.h"

BoundingSphere::BoundingSphere(std::vector<vector3> list)
{
	vertexList = list;
	calcRadius();
}


bool BoundingSphere::IsColliding(BoundingSphere* pOther)
{
	if (pOther->radius + this->radius <= this->radius)
	{
		return true;
	}
	return false;
}

void BoundingSphere::UpdatePosition(vector3 v3Input)
{
	this->position = vector3(vector4(position, 0.0f) * glm::translate(matrix4(IDENTITY), v3Input));
}

void BoundingSphere::calcRadius()
{
	vector3 max = vertexList[0];
	vector3 min = vertexList[0];
	for (uint i = 0; i < vertexList.size(); i++)
	{
		if (max.x < vertexList[i].x)
		{
			max.x = vertexList[i].x;
		}
		else if (min.x > vertexList[i].x)
		{
			min.x = vertexList[i].x;
		}

		if (max.y < vertexList[i].y)
		{
			max.y = vertexList[i].y;
		}
		else if (min.y > vertexList[i].y)
		{
			min.y = vertexList[i].y;
		}

		if (max.z < vertexList[i].z)
		{
			max.z = vertexList[i].z;
		}
		else if (min.z > vertexList[i].z)
		{
			min.z = vertexList[i].z;
		}

		center = (max + min) / 2.0f;

		radius = 0;

		float fDistance;
		for (uint i = 0; i < vertexList.size(); i++){
			fDistance = glm::distance(center, vertexList[i]);
			if (radius < fDistance){
				radius = fDistance;
			}
		}
	}
}

vector3 BoundingSphere::getPosition(){
	return this->position;
}

vector3 BoundingSphere::getCenter(){
	return this->center;
}

float BoundingSphere::getRadius(){
	return this->radius;
}