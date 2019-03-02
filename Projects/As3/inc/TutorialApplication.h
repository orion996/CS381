#ifndef __TutorialApplication_h_
#define __TutorialApplication_h_

#include "BaseApplication.h"

class TutorialApplication : public BaseApplication
{
public:
  TutorialApplication();
  virtual ~TutorialApplication();

  void makeGround();
  void makeSky();
  void makeEntities();
  void makeLight();

protected:
  virtual void createScene();
  virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);

private:
  bool processUnbufferedInput(const Ogre::FrameEvent& fe);

//  virtual void createCamera();
  //  virtual void createViewports();
};

#endif // #ifndef __TutorialApplication_h_
