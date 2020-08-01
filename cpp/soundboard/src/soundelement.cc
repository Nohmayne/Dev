#include "soundelement.hh"

SoundElement::SoundElement(const std::string &soundfile, float buttonSize) :
    m_button(sf::Vector2f(buttonSize, buttonSize))
{
    m_button.setFillColor(sf::Color::White);

    m_font.loadFromFile("../res/fonts/roboto.ttf");
    m_text = sf::Text(soundfile, m_font, buttonSize / soundfile.size() - 5.f);
    m_text.setFillColor(sf::Color::Black);

    loadSound(soundfile);
}

SoundElement::~SoundElement()
{
    m_sound.stop();
}

void SoundElement::loadSound(const std::string &filepath)
{
    if (!m_buffer.loadFromFile(filepath))
        std::cout << "[Error] Unable to load sound file: " << filepath << std::endl;

    m_sound.setBuffer(m_buffer);
}

void SoundElement::playSound()
{
    m_sound.play();
}

void SoundElement::stopSound()
{
    m_sound.stop();
}

void SoundElement::setPosition(const float &xpos, const float& ypos)
{
    m_button.setPosition(sf::Vector2f(xpos, ypos));
    m_text.setPosition(sf::Vector2f(xpos, ypos));
}
