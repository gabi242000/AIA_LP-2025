#pragma once
#include <SFML/Graphics.hpp>
class Animation {
public:
    Animation(sf::Texture& texture, int frameWidth, int frameHeight, int frameCount, float frameTime) : 
        sprite(texture),
        frameWidth(frameWidth),
        frameHeight(frameHeight),
        frameCount(frameCount),
        frameTime(frameTime),
        currentFrame(0),
        elapsedTime(0.0f),
        isPlaying(false),
        framesPlayed(0) 
    {
        sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
    }

    void playOnce(int framesToPlay = -1) {
        isPlaying = true;
        currentFrame = 0;
        elapsedTime = 0.0f;
        framesPlayed = 0;
        maxFrames = (framesToPlay == -1) ? frameCount : framesToPlay;
        sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
    }

    void update(float deltaTime) {
        if (!isPlaying) return;

        elapsedTime += deltaTime;

        if (elapsedTime >= frameTime) {
            elapsedTime = 0.0f;
            currentFrame++;
            framesPlayed++;

            if (framesPlayed >= maxFrames) {
                isPlaying = false;
                currentFrame = 0;
                sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
                return;
            }

            int left = (currentFrame % frameCount) * frameWidth;
            sprite.setTextureRect(sf::IntRect(left, 0, frameWidth, frameHeight));
        }
    }

    sf::Sprite& getSprite() {
        return sprite;
    }

private:
    sf::Sprite sprite;
    int frameWidth, frameHeight;
    int frameCount;
    float frameTime;
    int currentFrame;
    float elapsedTime;

    //Play once
    bool isPlaying;
    int framesPlayed;
    int maxFrames;
};

