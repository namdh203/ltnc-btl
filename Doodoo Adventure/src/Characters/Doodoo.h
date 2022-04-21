#ifndef DOODOO_H
#define DOODOO_H

#include "Character.h"

class Doodoo : public Character {
  public:
    Doodoo(Properties* props);

    virtual void Draw();
    virtual void Clean();
    virtual void Update(float dt);

  private:
    int m_Row, m_Frame, m_FrameCount;
    int m_AnimSpeed;
};

#endif // DOODOO_H
