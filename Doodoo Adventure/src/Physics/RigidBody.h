#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "vector2d.h"

#define UNI_MASS 1.0f
#define GRAVITY 9.8f

#define FORWARD 1
#define BACKWARD -1

#define UPWARD -1
#define DOWNWARD 1

class RigidBody {
  public:
    RigidBody() {
      m_Mass = UNI_MASS;
      m_Gravity = GRAVITY;
      //init value set of mass & gravity
    }

    inline void SetMass(float mass) {m_Mass = mass;}
    inline void SetGravity(float gravity) {m_Gravity = gravity;}
    //set value mass & gravity

    inline void ApplyForce(vector2d F) {m_Force = F;}
    inline void ApplyForceX(float Fx) {m_Force.X = Fx;}
    inline void ApplyForceY(float Fy) {m_Force.Y = Fy;}
    inline void UnSetForce() {m_Force = vector2d(0, 0);}
    //Force

    inline void ApplyFriction(vector2d Fr) {m_Friction = Fr;}
    inline void UnSetFriction() {m_Friction = vector2d(0, 0);}
    //Friction

    void Update(float dt) {
      m_Accelaration.X = (m_Force.X + m_Friction.X) / m_Mass;
      m_Accelaration.Y = (m_Gravity + m_Friction.Y) / m_Mass;
      m_Velocity = m_Accelaration * dt; // v = a * t
      m_Position = m_Velocity * dt; // x = v * t
    }
    //update

    inline float GetMass() {return m_Mass;}
    inline vector2d Accelaration() {return m_Accelaration;}
    inline vector2d Velocity() {return m_Velocity;}
    inline vector2d Position() {return m_Position;}
    //Getter
  private:
    float m_Mass, m_Gravity;

    vector2d m_Force, m_Friction;
    vector2d m_Position, m_Velocity;
    vector2d m_Accelaration;
};

#endif // RIGIDBODY_H
