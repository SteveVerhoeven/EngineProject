#pragma once
// ---------------------
// Disable warning
// ---------------------
// GLM
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/glm.hpp>
#pragma warning(pop)
#pragma warning(disable : 4702)
#pragma warning(disable : 4103)

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include <iostream> // std::cout
#include <memory> // smart pointers
#include <vector>
#include <thread>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// Engine includes
#include "Locator.h"

// ---------------------
// MACROs
// ---------------------
#pragma region MACROs
/* ***************** */
/* DELETING POINTERS */
/* ***************** */
#define DELETE_POINTER( x ) \
if (x != NULL)			    \
{						    \
    delete x;			    \
    x = NULL;		        \
}
#define DELETE_POINTERS( x, size ) 	\
for (size_t i{}; i < size; ++i)		\
{									\
	DELETEPOINTER(x[i]);			\
}									\
x.clear();
#pragma endregion