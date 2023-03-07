# CMake generated Testfile for 
# Source directory: /Users/filiphamrelius/Documents/TNM094/particlesystem
# Build directory: /Users/filiphamrelius/Documents/TNM094/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[unittest]=] "/Users/filiphamrelius/Documents/TNM094/build/Debug/unittest")
  set_tests_properties([=[unittest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/filiphamrelius/Documents/TNM094/particlesystem/CMakeLists.txt;120;add_test;/Users/filiphamrelius/Documents/TNM094/particlesystem/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[unittest]=] "/Users/filiphamrelius/Documents/TNM094/build/Release/unittest")
  set_tests_properties([=[unittest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/filiphamrelius/Documents/TNM094/particlesystem/CMakeLists.txt;120;add_test;/Users/filiphamrelius/Documents/TNM094/particlesystem/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[unittest]=] "/Users/filiphamrelius/Documents/TNM094/build/MinSizeRel/unittest")
  set_tests_properties([=[unittest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/filiphamrelius/Documents/TNM094/particlesystem/CMakeLists.txt;120;add_test;/Users/filiphamrelius/Documents/TNM094/particlesystem/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[unittest]=] "/Users/filiphamrelius/Documents/TNM094/build/RelWithDebInfo/unittest")
  set_tests_properties([=[unittest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/filiphamrelius/Documents/TNM094/particlesystem/CMakeLists.txt;120;add_test;/Users/filiphamrelius/Documents/TNM094/particlesystem/CMakeLists.txt;0;")
else()
  add_test([=[unittest]=] NOT_AVAILABLE)
endif()
