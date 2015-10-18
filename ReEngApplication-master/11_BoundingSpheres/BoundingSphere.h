#ifndef _BOUNDINGSPHERES_H_
#define _BOUNDINGSPHERES_H_

#include "RE\ReEngAppClass.h"
#include <vector>
#include <SFML\Graphics.hpp>

using namespace ReEng;


class BoundingSphere
{
	std::vector<vector3> vertexList;
	vector3 position;
	float radius;
	vector3 center;

public:

	BoundingSphere(std::vector<vector3> list);

	bool IsColliding(BoundingSphere* pOther);

	void UpdatePosition(vector3 v3Input);

	void calcRadius();

	vector3 getPosition();
	vector3 getCenter();
	float getRadius();

	
private:

};

#endif //BOUDNINGSPHERE