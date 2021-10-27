#include "Sprite.h"


Sprite::Sprite(std::shared_ptr<SDL_Texture> _texture, SDL_Renderer* _renderer)
{
    this->texture = _texture;

    // get width and height of texture;
    int width, height;
    SDL_QueryTexture(texture.get(), NULL, NULL, &width, &height);
    // set clip and rect
    clip.x = 0;
    clip.y = 0;
    clip.w = width;
    clip.h = height;
    rect.x = 0;
    rect.y = 0;
    rect.w = width;
    rect.h = height;
}

void Sprite::addAnimation(std::shared_ptr<Animation> animation)
{
    animations.push_back(animation);
}

void Sprite::update(const unsigned int delta)
{
    for (auto& animation : animations)
    {
        animation->update(delta);
    }
}

void Sprite::setSize(const int width, const int height)
{
    rect.w = width;  // controls the width of the rect
    rect.h = height; // controls the height of the rect
}

void Sprite::setPosition(const int x, const int y)
{
    rect.x = x; // controls the rect's x coordinate
    rect.y = y; // controls the rect's y coordinate
}

void Sprite::setClip(const int width, const int height, const int x, const int y)
{
    clip.w = width;  // controls the width of the rect
    clip.h = height; // controls the height of the rect
    clip.x = x;      // controls the rect's x coordinate
    clip.y = y;      // controls the rect's y coordinate
}

void Sprite::attachToCamera(bool isAttached /* = true*/)
{
    this->isAttachedToCamera = isAttached;
}

int Sprite::getWidth() const
{
    return rect.w;
}

int Sprite::getHeight() const
{
    return rect.h;
}

int Sprite::getPositionX() const
{
    return rect.x;
}

int Sprite::getPositionY() const
{
    return rect.y;
}

const SDL_Rect& Sprite::getRect() const
{
    return rect;
}

void Sprite::setFlip(SDL_RendererFlip flip)
{
    flipping = flip;
}

void Sprite::render(const SDL_Rect& camera) const
{
    if (renderer != nullptr && texture != nullptr)
    {
        // change position according to camera
        SDL_Rect destrinationRect = rect;
        if (isAttachedToCamera)
        {
            destrinationRect.x -= camera.x;
            destrinationRect.y -= camera.y;
        }
        // draw on the screen
        SDL_RenderCopyEx(renderer, texture.get(), &clip, &destrinationRect, 0, nullptr, flipping);
    }
}