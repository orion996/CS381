#include "TutorialApplication.h"

TutorialApplication::TutorialApplication(void)
{
}

TutorialApplication::~TutorialApplication(void)
{
}

void TutorialApplication::createScene(void)
{
	//set light and shadowing
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
	mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_MODULATIVE);

	//create spotlight
	Ogre::Light* spotLight = mSceneMgr->createLight("SpotLight");
	spotLight->setType(Ogre::Light::LT_SPOTLIGHT);

	//spotlight diffuse and specular
	spotLight->setDiffuseColour(0, 0, 1.0);
	spotLight->setSpecularColour(0, 0, 1.0);

	//attach spotlight to the scene
	Ogre::SceneNode* spotLightNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	spotLightNode->attachObject(spotLight);
	spotLightNode->setDirection(-1, -1, 0);
	spotLightNode->setPosition(Ogre::Vector3(200, 200, 0));



	//create the plane
		Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
		Ogre::MeshManager::getSingleton().createPlane(
				"ground", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, //region name
				plane, //plane object
				10000, 10000, 20, 20, //dimensions?
				true, //toggle normal?
				1, 5, 5, //uv coordinate stuff
				Ogre::Vector3::UNIT_Z //normal vector
		);

		const float surfaceHeight = -120.0;

		//attach ground to the scene
		Ogre::SceneNode* floorNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		Ogre::Entity* floorEnt = mSceneMgr->createEntity("ground");
		floorNode->setPosition(Ogre::Vector3(0, surfaceHeight, 0));
		floorNode->attachObject(floorEnt);
		floorEnt->setCastShadows(false);
		floorEnt->setMaterialName("Examples/Rockwall");

	//create sphere
		Ogre::Entity* ballEnt = mSceneMgr->createEntity("sphere.mesh");
		ballEnt->setCastShadows(true);
		mSceneMgr->getRootSceneNode()->createChildSceneNode("ballNode")->attachObject(ballEnt);



	//*********TUTORIALS 2 AND 4***************************
//	//create spotlight
//	Ogre::Light* spotLight = mSceneMgr->createLight("SpotLight");
//	spotLight->setType(Ogre::Light::LT_SPOTLIGHT);
//
//	//spotlight diffuse and specular
//	spotLight->setDiffuseColour(0, 0, 1.0);
//	spotLight->setSpecularColour(0, 0, 1.0);
//
//	//attach spotlight to the scene
//	Ogre::SceneNode* spotLightNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
//	spotLightNode->attachObject(spotLight);
//	spotLightNode->setDirection(-1, -1, 0);
//	spotLightNode->setPosition(Ogre::Vector3(200, 200, 0));
//
//	//create ninja
//	Ogre::Entity* ninjaEnt = mSceneMgr->createEntity("ninja.mesh");
//	ninjaEnt->setCastShadows(true);
//
//	//attach ninja to the scene
//	mSceneMgr->getRootSceneNode()->createChildSceneNode("ninjaNode")->attachObject(ninjaEnt);
//
//	//create ground plane
//	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
//	Ogre::MeshManager::getSingleton().createPlane(
//			"ground", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, //region name
//			plane, //plane object
//			1500, 1500, 20, 20, //dimensions?
//			true, //toggle normal?
//			1, 5, 5, //uv coordinate stuff
//			Ogre::Vector3::UNIT_Z //normal vector
//	);
//
//	//attach ground to the scene
//	Ogre::SceneNode* floorNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
//	Ogre::Entity* floorEnt = mSceneMgr->createEntity("ground");
//	floorNode->attachObject(floorEnt);
//	floorEnt->setCastShadows(false);
//	floorEnt->setMaterialName("Examples/Rockwall");

	//***********************************************************************



}

bool TutorialApplication::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
	if(!processUnbufferedInput(fe))
		return false;

	return BaseApplication::frameRenderingQueued(fe);
}

bool TutorialApplication::processUnbufferedInput(const Ogre::FrameEvent& fe)
{
	static bool mouseDownLastFrame = false;
	static Ogre::Real toggleTimer = 0.0;
	static Ogre::Real rotate = .13;
	static Ogre::Real move = 10;

	static Ogre::Vector3 ballVelocity = Ogre::Vector3(0,0,0);
	static Ogre::Vector3 camVec = mCamera->getPosition();
	static bool ballIsMoving = false;

	if(mKeyboard->isKeyDown(OIS::KC_UP))//+z
	{
		ballVelocity.z += move;
	}
	if(mKeyboard->isKeyDown(OIS::KC_DOWN))//-z
	{
		ballVelocity.z -= move;
	}
	if(mKeyboard->isKeyDown(OIS::KC_RIGHT))//+x
	{
		ballVelocity.x += move;
	}
	if(mKeyboard->isKeyDown(OIS::KC_LEFT))//-x
	{
		ballVelocity.x -= move;
	}

	if(mKeyboard->isKeyDown(OIS::KC_J))//+y
	{
		ballVelocity.y += move;
	}
	if(mKeyboard->isKeyDown(OIS::KC_K))//-y
	{
		ballVelocity.y -= move;
	}

	if(mKeyboard->isKeyDown(OIS::KC_SPACE))//reset velocity
	{
		ballVelocity.x = 0;
		ballVelocity.y = 0;
		ballVelocity.z = 0;
	}

	if(mKeyboard->isKeyDown(OIS::KC_Y))//reset ball position
	{
		mSceneMgr->getSceneNode("ballNode")->setPosition(Ogre::Vector3(0, 0, 0));
	}


	//camera controls
	if(mKeyboard->isKeyDown(OIS::KC_E))//camera up
	{
		camVec = mCamera->getPosition();
		camVec.y += 0.5;
		mCamera->setPosition(camVec);
	}
	if(mKeyboard->isKeyDown(OIS::KC_F))//camera down
	{
		camVec = mCamera->getPosition();
		camVec.y -= 0.5;
		mCamera->setPosition(camVec);
	}
//	if(mKeyboard->isKeyDown(OIS::KC_W))//camera down
//	{
//		camVec = mCamera->getPosition();
//		camVec.z -= 1;
//		mCamera->setPosition(camVec);
//	}
//	if(mKeyboard->isKeyDown(OIS::KC_S))//camera down
//	{
//		camVec = mCamera->getPosition();
//		camVec.z += 1;
//		mCamera->setPosition(camVec);
//	}
//	if(mKeyboard->isKeyDown(OIS::KC_A))//camera down
//	{
//		camVec = mCamera->getPosition();
//		camVec.x -= 1;
//		mCamera->setPosition(camVec);
//	}
//	if(mKeyboard->isKeyDown(OIS::KC_D))//camera down
//	{
//		camVec = mCamera->getPosition();
//		camVec.x += 1;
//		mCamera->setPosition(camVec);
//	}


	//Move ball
	mSceneMgr->getSceneNode("ballNode")->translate(
				ballVelocity * fe.timeSinceLastFrame,
				Ogre::Node::TS_LOCAL
	);


	//***********TUTORIALS 2 AND 4 *************************
//	//toggle light with LMB
//	toggleTimer -= fe.timeSinceLastFrame;
//
//	bool lmbDown = mMouse->getMouseState().buttonDown(OIS::MB_Left);
//
//	if((toggleTimer < 0) && lmbDown && !mouseDownLastFrame)
//	{
//		toggleTimer = 0.5;
//		Ogre::Light* light = mSceneMgr->getLight("SpotLight");
//		light->setVisible(!light->isVisible());
//	}
//
//	mouseDownLastFrame = lmbDown;
//
//	//toggle light with RMB
//	bool rmbDown = mMouse->getMouseState().buttonDown(OIS::MB_Right);
//
//	if((toggleTimer < 0) && rmbDown && !mouseDownLastFrame)
//	{
//		toggleTimer = 0.5;
//		Ogre::Light* light = mSceneMgr->getLight("SpotLight");
//		light->setVisible(!light->isVisible());
//	}
//
//	mouseDownLastFrame = rmbDown;
//
//	//move ninja
//	Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;
//
//	if(mKeyboard->isKeyDown(OIS::KC_I))//move back
//		dirVec.z -= move;
//	if(mKeyboard->isKeyDown(OIS::KC_K))//move forward
//			dirVec.z += move;
//	if(mKeyboard->isKeyDown(OIS::KC_U))//move up
//			dirVec.y += move;
//	if(mKeyboard->isKeyDown(OIS::KC_O))//move down
//			dirVec.y -= move;
//
//	if(mKeyboard->isKeyDown(OIS::KC_J))//move left or rotate left w/LSHIFT
//	{
//		if(mKeyboard->isKeyDown(OIS::KC_LSHIFT))
//			mSceneMgr->getSceneNode("ninjaNode")->yaw(Ogre::Degree(5 * rotate));
//		else
//			dirVec.x -= move;
//	}
//
//	if(mKeyboard->isKeyDown(OIS::KC_L))//move right or rotate right w/LSHIFT
//		{
//			if(mKeyboard->isKeyDown(OIS::KC_LSHIFT))
//				mSceneMgr->getSceneNode("ninjaNode")->yaw(Ogre::Degree(-5 * rotate));
//			else
//				dirVec.x += move;
//		}
//
//	mSceneMgr->getSceneNode("ninjaNode")->translate(
//			dirVec * fe.timeSinceLastFrame,
//			Ogre::Node::TS_LOCAL
//	);

	//********************************************************************


	return true;
}


#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
    int main(int argc, char *argv[])
#endif
    {
	// Create application object
	TutorialApplication app;

	try {
	    app.go();
	} catch(Ogre::Exception& e)  {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	    MessageBox(NULL, e.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
	    std::cerr << "An exception has occurred: " <<
		e.getFullDescription().c_str() << std::endl;
#endif
	}

	return 0;
    }

#ifdef __cplusplus
}
#endif
