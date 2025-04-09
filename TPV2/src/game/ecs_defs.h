// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once

// Components list - must have at least one element
//
struct Transform;
struct Image;
struct StarMotion;
struct Points;
struct WonderFruitComponent;
struct FramedImage;
struct Health;

#define _CMPS_LIST_ \
	Transform, \
	Image, \
	StarMotion, \
	Points, \
	WonderFruitComponent, \
	FramedImage, \
	Image, \
	Health

// Groups list - must have at least one element
//
#define _GRPS_LIST_ \
	GHOST, \
	FRUITS, \
	WONDER_FRUITS

// Handlers list - must have at least one element
//
#define _HDLRS_LIST_ \
    PACMAN

// Systems list - must have at least one element
//
class StarsSystem;
class RenderSystem;
class PacManSystem;
class GameCtrlSystem;
class CollisionsSystem;
class GhostSystem;
class FoodSystem;
class InmunitySystem;

#define _SYS_LIST_ \
    StarsSystem, \
	RenderSystem, \
	PacManSystem, \
	GameCtrlSystem, \
	CollisionsSystem, \
	GhostSystem, \
	FoodSystem, \
	InmunitySystem

