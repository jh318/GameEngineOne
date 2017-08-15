#include "Vector2.h"
#include <math.h>

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2(const Vector2& v)
{
	x = v.x;
	y = v.y;
}

Vector2 Vector2::operator + (const Vector2& v) const
{
	return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator - (const Vector2& v) const
{
	return Vector2(x - v.x, y - v.y);
}

Vector2 Vector2::operator * (const float& f) const
{
	return Vector2(x* f, y *f);
}

Vector2& Vector2::operator += (const Vector2& v)
{
	x += v.x;
	y += v.y;

	return *this;
}

Vector2& Vector2::operator -= (const Vector2& v)
{
	x -= v.x;
	y -= v.y;

	return *this;
}

float Vector2::Magnitude() const
{
	return sqrt(x * x + y * y);
}

Vector2 Vector2::operator - () const
{
	return Vector2(-x, -y);
}

void Vector2::Normalize()
{
	float mag = Magnitude();

	if (mag > 0)
	{
		x = x / mag;
		y = y / mag;
	}
}

float Vector2::dot(const Vector2& v) const
{
	return x * v.x + y * v.y;
}