#ifndef DOODOO_H
#define DOODOO_H

#include "Character.h"
#include "Animation.h"
#include "RigidBody.h"


class Doodoo : public Character {
  public:
    Doodoo(Properties* props);

    virtual void Draw();
    virtual void Clean();
    virtual void Update(float dt);

  private:
    //int m_Row, m_Frame, m_FrameCount;
    //int m_AnimSpeed;

    Animation* m_Animation;
    RigidBody* m_RigidBody;

};

#endif // DOODOO_H
