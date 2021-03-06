#include "AppClass.h"
void AppClass::ProcessKeyboard(void)
{
	bool bModifier = false;
	float fSpeed = 0.01f;

#pragma region ON PRESS/RELEASE DEFINITION
	static bool	bLastF1 = false, bLastF2 = false, bLastF3 = false, bLastF4 = false, bLastF5 = false,
				bLastF6 = false, bLastF7 = false, bLastF8 = false, bLastF9 = false, bLastF10 = false,
				bLastEscape = false;
#define ON_KEY_PRESS_RELEASE(key, pressed_action, released_action){  \
			bool pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::key);			\
			if(pressed){											\
				if(!bLast##key) pressed_action;}/*Just pressed? */\
			else if(bLast##key) released_action;/*Just released?*/\
			bLast##key = pressed; } //remember the state
#pragma endregion

#pragma region Modifiers
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
		bModifier = true;
#pragma endregion

#pragma region Camera Positioning
	if(bModifier)
		fSpeed *= 10.0f;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		m_pCameraMngr->MoveForward(fSpeed);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		m_pCameraMngr->MoveForward(-fSpeed);
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		m_pCameraMngr->MoveSideways(-fSpeed);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		m_pCameraMngr->MoveSideways(fSpeed);
	m_pCameraMngr->CalculateView();
#pragma endregion

#pragma region Model Positioning
	if (bModifier)
		fSpeed *= 10.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_v3Torus.x -= 0.1f;
//		b_Torus->getCenter().x -= 0.1f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_v3Torus.y += 0.1f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_v3Torus.x += 0.1f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_v3Torus.y -= 0.1f;




	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		m_v3Cone.x -= 0.1f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		m_v3Cone.y += 0.1f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		m_v3Cone.x += 0.1f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		m_v3Cone.y -= 0.1f;


	
#pragma endregion

#pragma region Other Actions
	ON_KEY_PRESS_RELEASE(Escape, NULL, PostMessage(m_pWindow->GetHandler(), WM_QUIT, NULL, NULL))
#pragma endregion
}
void AppClass::ProcessMouse(void)
{
	m_bArcBall = false;
	m_bFPC = false;
	
	if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle))
		m_bArcBall = true;
	
	if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
		m_bFPC = true;
}
