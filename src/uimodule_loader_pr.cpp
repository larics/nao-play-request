

/**
 * @author Emilie Wirbel
 *
 * \section Description
 * This file was generated by Aldebaran Robotics ModuleGenerator
 */

#include <signal.h>
#include <boost/shared_ptr.hpp>
#include <alcommon/albroker.h>
#include <alcommon/almodule.h>
#include <alcommon/albrokermanager.h>
#include <alcommon/altoolsmain.h>

#include "uimodule_pr.hpp"


#ifdef INTERFACE_PR_IS_REMOTE
# define ALCALL
#else
# ifdef _WIN32
#  define ALCALL __declspec(dllexport)
# else
#  define ALCALL
# endif
#endif

extern "C"
{
  ALCALL int _createModule(boost::shared_ptr<AL::ALBroker> pBroker)
  {
    // init broker with the main broker instance
    // from the parent executable
    AL::ALBrokerManager::setInstance(pBroker->fBrokerManager.lock());
    AL::ALBrokerManager::getInstance()->addBroker(pBroker);
      AL::ALModule::createModule<PlayRequestInterface>( pBroker, "PlayRequestInterface" );

    return 0;
  }

  ALCALL int _closeModule()
  {
    return 0;
  }
}

#ifdef INTERFACE_PR_IS_REMOTE
  int main(int argc, char *argv[])
  {
    // pointer to createModule
    TMainType sig;
    sig = &_createModule;
    // call main
    ALTools::mainFunction("PlayRequestInterface", argc, argv, sig);
  }
#endif

