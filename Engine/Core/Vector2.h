#pragma once

class Vector2
{
public:
	float x;
	float y;

	Vector2();
	Vector2(float x, float y);
	Vector2(const Vector2& v);

	Vector2 operator - () const;

	Vector2 operator + (const Vector2& v) const;
	Vector2 operator - (const Vector2& v) const;
	Vector2 operator * (const float& f) const;

	Vector2& operator += (const Vector2& v);
	Vector2& operator -= (const Vector2& v);

	float Magnitude() const;

	void Normalize();
	float dot(const Vector2& v) const;
};