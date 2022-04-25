#include "Doodoo.h"
#include "Texture.h"
#include "Input.h"
#include "SDL.h"

Doodoo::Doodoo(Properties* props) : Character(props) {
  m_RigidBody = new RigidBody();
  m_Animation = new Animation();
//  m_Animation->SetProps(m_TextureID, 1, 8, 80, SDL_FLIP_HORIZONTAL);
  m_Animation->SetProps(m_TextureID, 1, 8, 80);
}

void Doodoo::Draw() {
  m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}

void Doodoo::Clean() {
  Texture::GetInstance()->Clean();
}

void Doodoo::Update(float dt) {
  m_Animation->SetProps("player", 1, 6, 80);
  m_RigidBody->UnSetForce();
  // move left
  if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)){
    m_RigidBody->ApplyForceX(5 * BACKWARD);
    m_Animation->SetProps("player_run", 1, 8, 80, SDL_FLIP_HORIZONTAL);
  };

  //move right
  if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D)){
    m_RigidBody->ApplyForceX(5 * FORWARD);
    m_Animation->SetProps("player_run", 1, 8, 80);
  };

  m_RigidBody->Update(0.6);

//  m_Transform->Translate(m_RigidBody->Position());
  m_Transform->TranslateX(m_RigidBody->Position().X);
  m_Animation->Update();
}
