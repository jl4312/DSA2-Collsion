/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2015/09
----------------------------------------------*/
#ifndef __APPLICATION_H_
#define __APPLICATION_H_

#include "RE\ReEngAppClass.h"
#include <SFML\Graphics.hpp>
#include <vector>
#include  "BoundingSphere.h"
#include <stdio.h>
#include <iostream>
//#include <chrono>

using namespace ReEng; //Using ReEng namespace to use all the classes in the dll

class AppClass : public ReEngAppClass
{
public:
	typedef ReEngAppClass super;
	
	vector3 m_v3Torus;
	vector3 m_v3Cone;
	
	PrimitiveClass* m_pTorus;
	PrimitiveClass* m_pCone;

	BoundingSphere* b_Torus;
	BoundingSphere* b_Cone;

	quaternion b_ArcBall;

	
	/* Constructor */
	AppClass(HINSTANCE hInstance, LPWSTR lpCmdLine, int nCmdShow) : super(hInstance, lpCmdLine, nCmdShow) {}

	/*
	InitWindow
	Initialize ReEng variables necessary to create the window
	*/
	virtual void InitWindow(String a_sWindowName);

	/*
	InitVariables
	Initializes user specific variables, this is executed right after InitApplicationVariables,
	the purpose of this member function is to initialize member variables specific for this lesson
	*/
	virtual void InitVariables(void);

	/*
	Update
	Updates the scene
	*/
	virtual void Update(void);

	/*
	Display
	Displays the scene
	*/
	virtual void Display(void);

	/*
	ProcessKeyboard
	Manage the response of key presses
	*/
	virtual void ProcessKeyboard(void);

	/*
	ProcessMouse
	Manage the response of key presses and mouse position
	*/
	virtual void ProcessMouse(void);

	/*
	Release
	Releases the application
	IF INHERITED AND OVERRIDEN MAKE SURE TO RELEASE BASE POINTERS (OR CALL BASED CLASS RELEASE)
	*/
	virtual void Release(void);
};
#endif //__APPLICATION_H_