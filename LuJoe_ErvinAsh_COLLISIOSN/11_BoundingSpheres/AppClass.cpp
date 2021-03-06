#include "AppClass.h"
void AppClass::InitWindow(String a_sWindowName)
{
	super::InitWindow("Bounding Spheres"); // Window Name

	// Set the clear color based on Microsoft's CornflowerBlue (default in XNA)
	//if this line is in Init Application it will depend on the .cfg file, if it
	//is on the InitVariables it will always force it regardless of the .cfg
	m_v4ClearColor = vector4(0.4f, 0.6f, 0.9f, 0.0f);
}
void AppClass::InitVariables(void)
{
	m_v3Torus = vector3(3.5f, 0.0f, 0.0f);
	m_v3Cone = vector3(0.0f, 0.0f, 0.0f);

	m_pTorus = new PrimitiveClass();
	m_pTorus->GenerateTorus(1.0f, 0.7f, 10, 10, REGREEN);

	m_pCone = new PrimitiveClass();
	m_pCone->GenerateCone(1.0f, 1.0f, 10, REGREEN);

	b_Torus = new BoundingSphere(m_pTorus->GetVertices());
	b_Cone = new BoundingSphere(m_pCone->GetVertices());

	m_pTorus->CompileOpenGL3X();
	m_pCone->CompileOpenGL3X();
}

void AppClass::Update(void)
{
	//Update the system's time
	m_pSystem->UpdateTime();

	//Update the mesh manager's time without updating for collision detection
	m_pMeshMngr->Update(false);

	//First person camera movement
	if (m_bFPC == true)
		CameraRotation();

	if (m_bArcBall == true){
		b_ArcBall = ArcBall();
	}

	b_Torus->UpdootPosition(vector3(m_v3Torus.x, m_v3Torus.y, m_v3Torus.z));
	b_Cone->UpdootPosition(vector3(m_v3Cone.x, m_v3Cone.y, m_v3Cone.z));


	if (glm::distance(b_Torus->getCenter(), b_Cone->getCenter()) < b_Torus->getRadius() + b_Cone->getRadius()){
		//is around cone for some reason
		m_pMeshMngr->AddSphereToQueue(glm::scale(glm::translate(glm::mat4_cast(b_ArcBall), b_Torus->getCenter()), vector3(b_Torus->getRadius() * 2.0f)), RERED, WIRE);
		//supposed to be on torus
		m_pMeshMngr->AddSphereToQueue(glm::scale(glm::translate(glm::mat4_cast(b_ArcBall), b_Cone->getCenter()), vector3(b_Cone->getRadius() * 2.0f)), RERED, WIRE);
		//Adds all loaded instance to the render list
	}
	else{
		
		//is around cone for some reason
		m_pMeshMngr->AddSphereToQueue(glm::scale(glm::translate(glm::mat4_cast(b_ArcBall), b_Torus->getCenter()), vector3(b_Torus->getRadius() * 2.0f)), REWHITE, WIRE);
		//supposed to be on torus
		m_pMeshMngr->AddSphereToQueue(glm::scale(glm::translate(glm::mat4_cast(b_ArcBall), b_Cone->getCenter()), vector3(b_Cone->getRadius() * 2.0f)), REWHITE, WIRE);
		//Adds all loaded instance to the render list
	}
	m_pMeshMngr->AddInstanceToRenderList("ALL");
}

void AppClass::Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the window

	m_pGrid->Render(); //renders the XY grid with a 100% scale

	m_pMeshMngr->Render(); //renders the render list

	m_pTorus->Render(glm::translate(matrix4(1.0f), m_v3Torus), REGREEN);
	m_pCone->Render(glm::translate(matrix4(1.0f), m_v3Cone), REBLUE);
	

	m_pGLSystem->GLSwapBuffers(); //Swaps the OpenGL buffers
}

void AppClass::Release(void)
{
	super::Release(); //release the memory of the inherited fields
}
