#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <string>
#include <iostream>

class SoundElement : public sf::Drawable
{
    public:
        SoundElement(const std::string &soundfile, float buttonSize = 50.f);
        ~SoundElement();

        void loadSound(const std::string &filepath);
        void playSound();
        void stopSound();

        void setPosition(const float &xpos, const float& ypos);
    private:
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    private:
        sf::SoundBuffer m_buffer;
        sf::Sound m_sound;

        sf::RectangleShape m_button;
        sf::Font m_font;
        sf::Text m_text;

        sf::Vector2f m_pos;
};
