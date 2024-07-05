# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Routinee_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Routinee_autogen.dir\\ParseCache.txt"
  "Routinee_autogen"
  )
endif()
