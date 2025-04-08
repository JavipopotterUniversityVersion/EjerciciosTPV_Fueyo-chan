#pragma once
#include "../utils/Vector2D.h"

class AnimationUtility {
public:
	static inline Vector2D getPacmanAnimation() { return Vector2D(0,3); }
	static inline Vector2D getCherry() { return Vector2D(12, 12); }
	static inline Vector2D getPear() { return Vector2D(15, 15); }
	static inline Vector2D getVulnerableGhost() { return Vector2D(30, 31); }
	static inline Vector2D getRedGhost() { return Vector2D(32, 39); }
};