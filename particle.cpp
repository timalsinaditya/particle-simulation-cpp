#include "raylib.h"
#include "particle.h"
#include <math.h>
#include <sstream>

using namespace std;

float Distance(float x, float y) {
    return max((float)sqrt(pow(x, 2)+pow(y, 2)), 50.0f);
}

Particle::Particle(int x, int y) {
    this->pos = Vector2{(float)x, (float)y};
    this->vel = Vector2{0, 0};
    this->acc = Vector2{0, 0};
    
    this->m = 2;
    this->original = pos;
}

Particle::Particle() {
    this->pos = Vector2{0, 0};
    this->vel = Vector2{0, 0};
    this->acc = Vector2{0, 0};

    this->m = 1;
}

void Particle::ApplyGravityForce(Vector2 pos, int mass, float sign) {
    float xdist = this->pos.x-pos.x;
    float ydist = this->pos.y-pos.y;
    float dist = Distance(xdist, ydist)/5;
    float f = min(-((mass*m)/pow(dist, 2)), 2.0)*sign;
    Vector2 force = {f*(xdist/dist), f*(ydist/dist)};
    
    acc.x += force.x/m;
    acc.y += force.y/m;
}

void Particle::Update() {
    vel.x += acc.x;
    vel.y += acc.y;

    vel.x *= 0.98f;
    vel.y *= 0.98f;
    
    pos.x += vel.x*GetFrameTime();
    pos.y += vel.y*GetFrameTime();

    acc = Vector2{0, 0};
}

void Particle::Draw() {
    DrawPixelV(pos, {255, 255, 255, 225});
}
