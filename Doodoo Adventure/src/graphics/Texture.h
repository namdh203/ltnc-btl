#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include "SDL.h"
#include <map>

class Texture {
  public:
    static Texture* GetInstance() {
      return s_Instance = (s_Instance != nullptr) ? s_Instance : new Texture();
    }

    bool Load(std::string id, std::string filename);
    void Drop(std::string id);
    void Clean();

    void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);

  private:
    Texture() {}
    std::map<std::string, SDL_Texture*> m_TextureMap;
    static Texture* s_Instance;
};

#endif // TEXTURE_H
