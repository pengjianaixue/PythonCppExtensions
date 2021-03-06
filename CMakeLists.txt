cmake_minimum_required (VERSION 3.8)

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM_NAME}")
project ("PythonExtension")
include_directories("C:/Users/jianpeng/AppData/Local/Programs/Python/Python39/include")
include_directories("C:/Users/jianpeng/Documents/GitHub/pybind11/include")
# link_directories must be set before the set up build target  
link_directories(AFTER "C:/Users/jianpeng/AppData/Local/Programs/Python/Python39/libs/")
add_library (PythonExtension SHARED  "PyExtensions.cpp")
# set target suffix name will gen as *.pyd file
set_target_properties(PythonExtension PROPERTIES  SUFFIX ".pyd")
target_link_libraries(PythonExtension "python39.lib")

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
	MESSAGE(STATUS "current platform: Linux ")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
	MESSAGE(STATUS "current platform: Windows")
	SET(COPY_COMMAND "cmd.exe /C COPY C:\\Users\\jianpeng\\source\\repos\\PythonCppExtensions\\out\\build\\x64-Release\\PythonExtension.pyd C:\\Users\\jianpeng\\PycharmProjects\\PythonExtension\\PythonExtension.pyd /Y" )
	execute_process(COMMAND  ${COPY_COMMAND})
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
	MESSAGE(STATUS "current platform: FreeBSD")
ELSE ()
	MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

#add_custom_command(OUTPUT PythonExtension POST_BUILD "xcopy C:\\Users\\jianpeng\\source\\repos\\PythonCppExtensions\\out\\build\\x64-Release\\PythonExtension.pyd C:\\Users\\jianpeng\\PycharmProjects\\PythonExtension\\PythonExtension.pyd /S /E /Y")