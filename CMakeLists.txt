cmake_minimum_required(VERSION 2.8)
project(nao-play-request)
find_package(qibuild)

include_directories(include)
## building Logger module

option(LOGGER_PR_IS_REMOTE
  "module is compiled as a remote module (ON or OFF)"
  OFF)

set(_srcsLogger_pr
  src/logmodule_loader_pr.cpp
  include/logmodule_pr.hpp
  src/logmodule_pr.cpp
)

if(LOGGER_PR_IS_REMOTE)
  add_definitions(" -DLOGGER_PR_IS_REMOTE ")
  qi_create_bin(logger_pr ${_srcsLogger_pr})
else()
  qi_create_lib(logger_pr SHARED ${_srcsLogger_pr} SUBFOLDER Logger_pr)
endif()

qi_use_lib(logger_pr ALCOMMON)

## building Interface module

option(INTERFACE_PR_IS_REMOTE
  "module is compiled as a remote module (ON or OFF)"
  OFF)

set(_srcsInterface_pr
  src/uimodule_loader_pr.cpp
  include/uimodule_pr.hpp
  src/uimodule_pr.cpp
)

if(INTERFACE_PR_IS_REMOTE)
  add_definitions(" -DINTERFACE_PR_IS_REMOTE ")
  qi_create_bin(interface_pr ${_srcsInterface_pr})
else()
  qi_create_lib(interface_pr SHARED ${_srcsInterface_pr} SUBFOLDER Interface_pr)
endif()

qi_use_lib(interface_pr ALCOMMON)
