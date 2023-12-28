#include "raylib.h"

class Particle{   
public:
    Vector2 original;

    Vector2 pos;
    Vector2 vel;
    Vector2 acc;

    float m;

    Particle(int x, int y);

    Particle();

    void ApplyGravityForce(Vector2 force, int mass, float sign);

    void Update();

    void Draw();
};
