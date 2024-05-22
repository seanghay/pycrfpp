cmake_minimum_required(VERSION 3.8)

project(pycrfpp)

add_subdirectory(pybind11)
pybind11_add_module(${PROJECT_NAME} 
  src/binding.cpp
  
  crfpp/libcrfpp.cpp
  crfpp/lbfgs.cpp
  crfpp/param.cpp
  crfpp/encoder.cpp
  crfpp/feature.cpp
  crfpp/feature_cache.cpp
  crfpp/feature_index.cpp 
  crfpp/node.cpp 
  crfpp/path.cpp 
  crfpp/tagger.cpp
)

target_compile_definitions(${PROJECT_NAME} PRIVATE HAVE_CONFIG_H)
target_include_directories(${PROJECT_NAME} PRIVATE crfpp)
target_compile_definitions(${PROJECT_NAME} PRIVATE VERSION_INFO=${PYCRFPP_VERSION_INFO})