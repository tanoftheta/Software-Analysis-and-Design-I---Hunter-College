#include <iostream> 
#include <cmath>
using namespace std; 

/*Name: Tan Mahmud 
Class: CS135 
Lab 9 - Bonus Task */ 

class Coord3D { // establishes new class;
public: 
    double x; 
    double y; 
    double z; 
};
class Particle // class particle stores position and velocity 
{
public: 
    Coord3D position; 
    Coord3D velocity; 
}; 
Particle* createParticle(double x, double y, double z, double vx, double vy, double vz) 
{
    Particle *newpart = new Particle; //dynamically allocate memory 
    newpart->position = {x, y, z};  // position of particle 
    newpart->velocity = {vx, vy, vz}; // velocity of particle
    return newpart; 
}
void setVelocity(Particle *p, double vx, double vy, double vz)
{
    p->velocity = {vx, vy, vz}; // update velocity 
}
Coord3D getPosition(Particle *p)
{
    Coord3D posi; // extract position Coord3D
    posi.x = p->position.x; 
    posi.y = p->position.y; 
    posi.z = p->position.z; 
    return posi;
}
void move(Particle *p, double dt)
{
    p->position.x = p-> position.x + (p->velocity.x*dt); //using positon formula
    p->position.y = p-> position.y + (p->velocity.y*dt);
    p->position.z = p-> position.z + (p->velocity.z*dt);
}
void deleteParticle(Particle *p)
{
    delete p; // dynamically allocated - must delete 
}


int main()
{
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3); 
    double times = 0.0; 
    double dt = 0.1; 
    while (times < 3.0 )
    {
        setVelocity(p, 10.0 * times, 0.3, 0.1); 
        move(p, dt); 
        times += dt; 
        cout << "Time: " << times << " \t"; 
        cout << "Position: " << getPosition(p).x << ", " << getPosition(p).y << ", " << getPosition(p).z ;  
        
    }
    deleteParticle(p); 
}