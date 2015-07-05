#include <SFML/Graphics.hpp>
#include <iostream>

sf::RenderWindow window;
sf::CircleShape ball(50); //created a circle
sf::CircleShape stupidBall(50);
int movement = 1; // initialised movement, will occur in positive x direction.
int stupidMovement = 1; //initialises movement for the non time stepped objects.

void update(float dt);
void render();
void handleInput();



int main(int, char const**)
{
    stupidBall.move(100, 0);
    window.create(sf::VideoMode(800, 600), "Get To The Hangar!!!");

    
    // sf::CircleShape ball(50);
    ball.setFillColor(sf::Color::Red);
    // Load a music to play
    int dt = 1;
    // Play the music
    // music.play();
    
    // Start the game loop
    
    //  double currentTime = (double)
    sf::Clock clock;
    while (window.isOpen())
    {
        
        sf::Time elapsed = clock.restart();
        handleInput();
        update(elapsed.asMilliseconds());
        render();
        
    }
    
    return EXIT_SUCCESS;
}


void update(float dt){
    
    if(ball.getPosition().y > 600){
        movement = -1;
        
    }else if(ball.getPosition().y < 1){
        movement = 1;
    }
    if(stupidBall.getPosition().y > 600){
        stupidMovement = -1;
        
    }else if(stupidBall.getPosition().y < 1){
        stupidMovement = 1;
    }
    
    ball.move(0, movement * dt);
    stupidBall.move(0,  stupidMovement );
    std::cout << dt << std::endl;
    
    
}

void render(){
    
    
    
    // Clear screen
    window.clear();
    // Draw the sprite
    //   window.draw(sprite);
    window.draw(ball);
    window.draw(stupidBall);
    // Draw the string
    //  window.draw(text);
    
    // Update the window
    window.display();
    
}


void handleInput(){
    
    
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Close window: exit
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        
        // Escape pressed: exit
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window.close();
        }
    }
}