# =============== Edit here ==================== #
set(_TARGET_NAME "SeetaFaceDetector")
set(_TARGET_VERSION_MAJOR "6")
set(_TARGET_VERSION_MINOR "0")
set(_TARGET_VERSION_SINOR "0")
set(_TARGET_HEADER "seeta/FaceDetector.h")
# =============== Edit end ===================== #

# Find library
#<NAME>_FOUND
#<NAME>_INCLUDE_DIRS or <NAME>_INCLUDES
#<NAME>_LIBRARIES or <NAME>_LIBRARIES or <NAME>_LIBS
#<NAME>_VERSION
#<NAME>_DEFINITIONS

#variables:
#<NAME>_NAME
#<NAME>_INCLUDE_DIR
#<NAME>_LIBRARY
#<NAME>_MODULE_PATH

# --------------- Do not edit here ------------- #
set(${_TARGET_NAME}_NAME "{_TARGET_NAME}")
set(${_TARGET_NAME}_VERSION_MAJOR ${_TARGET_VERSION_MAJOR})
set(${_TARGET_NAME}_VERSION_MINOR ${_TARGET_VERSION_MINOR})
set(${_TARGET_NAME}_VERSION_SINOR ${_TARGET_VERSION_SINOR})

set(${_TARGET_NAME}_VERSION "${${_TARGET_NAME}_VERSION_MAJOR}.${${_TARGET_NAME}_VERSION_MINOR}.${${_TARGET_NAME}_VERSION_SINOR}" CACHE STRING "The ${_TARGET_NAME} library version")
set(NAME_STR ${${_TARGET_NAME}_VERSION_MAJOR}${${_TARGET_NAME}_VERSION_MINOR}${${_TARGET_NAME}_VERSION_SINOR})
set(${_TARGET_NAME}_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../")

message(STATUS "${_TARGET_NAME} default path: " ${${_TARGET_NAME}_MODULE_PATH})

if(BUILD_ANDROID)
	# if(${_TARGET_NAME}_ROOT_DIR STREQUAL "")
	# message(SEND_ERROR "Set the path to ${_TARGET_NAME} root folder in the system variable ${_TARGET_NAME}_ROOT_DIR ")
	# endif()
	set(${_TARGET_NAME}_INCLUDE_DIR "${${_TARGET_NAME}_MODULE_PATH}/include")
	file(GLOB_RECURSE INCLUDE_FILE
			${${_TARGET_NAME}_INCLUDE_DIR}/VIPLFaceRecognizer.h)
	if("${INCLUDE_FILE}" STREQUAL "")
		set(${_TARGET_NAME}_INCLUDE_DIR "${${_TARGET_NAME}_ROOT_DIR}/include")
	endif()
	message(STATUS "${_TARGET_NAME} include dir : ${${_TARGET_NAME}_INCLUDE_DIR}")
	file(GLOB LIBRARY_DEBUG
			${${_TARGET_NAME}_MODULE_PATH}/${ENV_LIBRARY_DIR}/*${_TARGET_NAME}*d.so)
	if("${LIBRARY_DEBUG}" STREQUAL "")
		file(GLOB LIBRARY_DEBUG
				${${_TARGET_NAME}_ROOT_DIR}/${ENV_LIBRARY_DIR}/*${_TARGET_NAME}*d.so)
	endif()
	file(GLOB LIBRARY_RELEASE
			${${_TARGET_NAME}_MODULE_PATH}/${ENV_LIBRARY_DIR}/*${_TARGET_NAME}*.so)
	if("${LIBRARY_RELEASE}" STREQUAL "")
		file(GLOB LIBRARY_RELEASE
				${${_TARGET_NAME}_ROOT_DIR}/${ENV_LIBRARY_DIR}/*${_TARGET_NAME}*.so)
	endif()
else()
	find_path(${_TARGET_NAME}_INCLUDE_DIR
			NAMES
			${_TARGET_HEADER}
			PATHS
			ENV SEETA_LOCAL_INSTALL
			${${_TARGET_NAME}_ROOT_DIR}
			${${_TARGET_NAME}_MODULE_PATH}
			ENV ${_TARGET_NAME}_ROOT_DIR
			usr
			usr/local
			PATH_SUFFIXES
			${ENV_HEADER_DIR}
			${_TARGET_NAME}/${ENV_HEADER_DIR})

	find_library(${_TARGET_NAME}_LIBRARY_DEBUG
			NAMES
			${_TARGET_NAME}${NAME_STR}d
			PATHS
			ENV SEETA_LOCAL_INSTALL
			${${_TARGET_NAME}_ROOT_DIR}
			${${_TARGET_NAME}_MODULE_PATH}
			ENV ${_TARGET_NAME}_ROOT_DIR
			usr
			usr/local
			PATH_SUFFIXES
			${ENV_LIBRARY_DIR}
			${ENV_LIBRARY_DIR}/${CONFIGURATION}
			${_TARGET_NAME}/${ENV_LIBRARY_DIR}
			${_TARGET_NAME}/${ENV_LIBRARY_DIR})

	find_library(${_TARGET_NAME}_LIBRARY_RELEASE
			NAMES
			${_TARGET_NAME}${NAME_STR}
			PATHS
			ENV SEETA_LOCAL_INSTALL
			${${_TARGET_NAME}_ROOT_DIR}
			${${_TARGET_NAME}_MODULE_PATH}
			ENV ${_TARGET_NAME}_ROOT_DIR
			usr
			usr/local
			PATH_SUFFIXES
			${ENV_LIBRARY_DIR}
			${ENV_LIBRARY_DIR}/${CONFIGURATION}
			${_TARGET_NAME}/${ENV_LIBRARY_DIR}
			${_TARGET_NAME}/${ENV_LIBRARY_DIR})
endif()

if ("${CONFIGURATION}" STREQUAL "Debug")
	set(${_TARGET_NAME}_LIBRARY ${${_TARGET_NAME}_LIBRARY_DEBUG})
else()
	set(${_TARGET_NAME}_LIBRARY ${${_TARGET_NAME}_LIBRARY_RELEASE})
endif()

find_package(PackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(${_TARGET_NAME}
		FOUND_VAR
		${_TARGET_NAME}_FOUND
		REQUIRED_VARS
		${_TARGET_NAME}_INCLUDE_DIR
		${_TARGET_NAME}_LIBRARY
		VERSION_VAR
		${_TARGET_NAME}_VERSION
		FAIL_MESSAGE
		"Could not find ${_TARGET_NAME}!try to set the path to ${_TARGET_NAME} root folder in the system variable ${_TARGET_NAME}_ROOT_DIR "
		)

if(${_TARGET_NAME}_FOUND)
	set(${_TARGET_NAME}_LIBRARIES ${${_TARGET_NAME}_LIBRARY})
	set(${_TARGET_NAME}_INCLUDE_DIRS ${${_TARGET_NAME}_INCLUDE_DIR})
endif()

message(STATUS "${_TARGET_NAME} Found: " ${${_TARGET_NAME}_FOUND})

foreach (inc ${${_TARGET_NAME}_INCLUDE_DIRS})
	message(STATUS "${_TARGET_NAME} include: " ${inc})
endforeach ()
foreach (lib ${${_TARGET_NAME}_LIBRARIES})
	message(STATUS "${_TARGET_NAME} library: " ${lib})
endforeach ()

set(_TARGET_NAME "")
set(_TARGET_VERSION_MAJOR "")
set(_TARGET_VERSION_MINOR "")
set(_TARGET_VERSION_SINOR "")
set(_TARGET_HEADER "")
