#include "Doodoo.h"
#include "Texture.h"
#include "SDL.h"

Doodoo::Doodoo(Properties* props) : Character(props) {
  m_Row = 1;
  m_FrameCount = 6; // numbers of Frame
  m_AnimSpeed = 100;
}

void Doodoo::Draw() {
  Texture::GetInstance()->DrawFrame(m_TextureID, m_Transform->X, m_Transform->Y, m_Width, m_Height, m_Row, m_Frame);
}

void Doodoo::Clean() {
  Texture::GetInstance()->Clean();
}

void Doodoo::Update(float dt) {
  m_Frame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount;
}
