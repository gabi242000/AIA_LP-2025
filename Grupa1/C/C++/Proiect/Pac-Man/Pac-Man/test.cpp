#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>
#include <vector>
#include <cmath>


        using namespace std;
        int score=0;
        //Create enemy class
            class Enemy{
                public:
                        Enemy(sf::Vector2f dimensions, sf::Color color,sf::Vector2f startPos,sf::Vector2f direction,float proximityThreshold):
                                m_dimensions_e(dimensions),m_color_e(color),m_direction_e(direction),m_position_e(startPos),m_proximityThreshold_e(proximityThreshold){
                                        m_shape_e.setSize(m_dimensions_e);
                                        m_shape_e.setFillColor(color);
                                        m_shape_e.setPosition(startPos);
                                        m_speed = 200.f;

                                }

                        //Enemy functions

                        sf::FloatRect getGlobalBounds() const{
                                return m_shape_e.getGlobalBounds();
                        }

                        bool Visible() const{
                                return isVisible;
                                }

                        void setFillColor(sf::Color color){
                                m_shape_e.setFillColor(color);
                                }

                        void setSpeed(float speed){
                                m_speed = speed;
                                }

                        bool is_chickenGhostMode() const {
                                return chickenGhostMode;
                        }


                        void HideForSeconds(float seconds){
                                isVisible = false;
                                visibilityClock.restart();
                                hiddenTime = sf::seconds(seconds);
                                }

                        void updateVisibility(){
                                if(!isVisible && visibilityClock.getElapsedTime() > hiddenTime)
                                        isVisible = true;
                                }


                        //Update function

                        void update(sf::Time deltaTime ,const sf::Vector2f& borderPosition, const sf::Vector2f& borderSize, std::vector<sf::RectangleShape>& pereti,bool& GameOver
                        ,std::vector<Enemy>& enemies){
                                updateVisibility();
                                sf::Vector2f movement = m_speed * m_direction_e * deltaTime.asSeconds();
                                sf::Vector2f nextPos = movement+ m_position_e;
                                bool changedDirection;

                                changedDirection = false;
                                if(GameOver) return;

                                //Set enemy movement
                                if (m_position_e.x + movement.x - m_dimensions_e.x < borderPosition.x + m_proximityThreshold_e-40 ||
                                m_position_e.x + movement.x + m_dimensions_e.x > borderPosition.x + borderSize.x - m_proximityThreshold_e)
                                        changedDirection = true;



                                if (m_position_e.y + movement.y - m_dimensions_e.y < borderPosition.y + m_proximityThreshold_e-40 ||
                                m_position_e.y + movement.y + m_dimensions_e.y > borderPosition.y + borderSize.y - m_proximityThreshold_e)
                                        changedDirection = true;


                                if(changedDirection||m_directionCooldown.getElapsedTime() > m_cooldownTime){
                                        vector<sf::Vector2f>directions = {
                                                {1.f,0.f},{0.f,1.f},{-1.f,0.f},{0.f,-1.f}
                                        };

                                        int index= rand() % directions.size();
                                        m_direction_e = directions[index];
                                        m_directionCooldown.restart();
                                }


                                sf::FloatRect enemyBounds = m_shape_e.getGlobalBounds();
                                //Check for enemy wall intersection to change direction
                                for (const auto& wall : pereti) {
                                                bool changedDir = false;
                                        sf::FloatRect wallBounds  = wall.getGlobalBounds();
                                        if(const std::optional intersection =enemyBounds.findIntersection(wallBounds) ){
                                                changedDir = true;

                                                if(changedDir){
                                                        vector<sf::Vector2f>directions = {
                                                        {1.f,0.f},{0.f,1.f},{-1.f,0.f},{0.f,-1.f}
                                                        };

                                                        int index= rand() % directions.size();
                                                        m_direction_e = directions[index];


                                }

                                }




                }

                                //Enemy state changes
                                if(!chickenGhostMode && ghostCooldown.getElapsedTime()>ghostCooldownTime)
                                        for(auto& enemy:enemies){
                                                enemy.setFillColor(sf::Color::Red);
                                                enemy.setSpeed(250.f);
                                                chickenGhostMode = true;

                                                ghostCooldown.restart();
                                                }

                                else if(chickenGhostMode && ghostCooldown.getElapsedTime()>chickenghostcooldownTime){
                                        for(auto& enemy:enemies)
                                                enemy.setSpeed(200.f);

                                        enemies[0].setFillColor(sf::Color::Red);
                                        enemies[1].setFillColor(sf::Color::Green);
                                        enemies[2].setFillColor(sf::Color::Cyan);
                                        enemies[3].setFillColor(sf::Color::Magenta);
                                        chickenGhostMode = false;
                                        ghostCooldown.restart();
                                }





                                //Update the position of the enemy

                                m_position_e +=m_direction_e*m_speed*deltaTime.asSeconds();
                                m_shape_e.setPosition(m_position_e);

                        }



                        //Function to render the enemy on the screen
                        void render(sf::RenderWindow& window) {
                                if(isVisible)
                                        window.draw(m_shape_e);
                }
                //Enemy class variables
                private:
                        sf::RectangleShape m_shape_e;
                        sf::Vector2f m_position_e;
                        sf::Vector2f m_direction_e;
                        sf::Clock m_directionCooldown;
                        sf::Time m_cooldownTime = sf::seconds(2.f);
                        sf::Vector2f m_dimensions_e;
                        sf::Color m_color_e;
                        float m_speed;
                        float m_proximityThreshold_e;
                        bool chickenGhostMode = false;
                        sf::Clock ghostCooldown;
                        sf::Time ghostCooldownTime =sf::seconds(10.f);
                        sf::Time chickenghostcooldownTime = sf::seconds(5.f);
                        bool isVisible = true;
                        sf::Clock visibilityClock;
                        sf::Time hiddenTime;


            };
                //Pac-Man class
            class PacMan {
            public:

                PacMan(float radius, sf::Color color, float x, float y, float proximityThreshold)

                    : m_radius(radius), m_color(color), m_position(x, y), m_proximityThreshold(proximityThreshold) {
                    m_shape.setRadius(m_radius);
                    m_shape.setFillColor(m_color);
                    m_shape.setPosition(m_position);

                   // buffer.loadFromFile("/home/remus/Desktop/Game/Pac-Man/pacman_chomp.wav");
                }

                int intrand(int min, int max){

                        return rand()%(max-min+1)+min;
                }

                float distance(const sf::Vector2f& point1, const sf::Vector2f& point2){
                                return sqrt((point2.x-point1.x)*(point2.x-point1.x)+(point2.y-point1.y)*(point2.y-point1.y));
                        }

                //Function to generate the points on the map
                vector<sf::CircleShape> pointsgen(const std::vector<sf::RectangleShape>& walls,float Width, float Height){
                                std::vector<sf::CircleShape> points;
                                const int points_num = 30;
                                const int max_attempts=300000;
                                for(int i=0;i<points_num;i++){
                                        int attempt=0;
                                        sf::CircleShape point(10.f);
                                        sf::CircleShape hitbox(10.f);
                                        point.setFillColor(sf::Color::Blue);
                                        bool valid = false;
                                        int ok=1;
                                      while(valid==false && attempt<max_attempts){
                                        float x = intrand(95,Width);
                                        float y = intrand(80,Height+20);
                                        point.setPosition(sf::Vector2f({x,y}));
                                        hitbox.setPosition(point.getPosition());

                                        valid =true;


                                        sf::FloatRect pointbounds = hitbox.getGlobalBounds();

                                        sf::Vector2f pointpos = point.getPosition();



                                        for(const auto& wall:walls){
                                                sf::FloatRect wallbounds = wall.getGlobalBounds();
                                                if(const std::optional intersection = pointbounds.findIntersection(wallbounds))

                                                        valid=false;
                                        }

                                        if(valid){
                                                for(const auto& expoint:points){
                                                        sf::Vector2f expointpos = expoint.getPosition();
                                                        if(distance(pointpos,expointpos)<50.f)
                                                                valid=false;

                                        }

                                }
                                 attempt++;
                }

                        if(valid)points.push_back(point);

        }
                        return points;

        }
                //Pac-Man function for score

                void ChangeScore(sf::Text& text, int& score){
                                score+=100;
                                text.setString("Score: "+std::to_string(score));
                        }

                void GetGhostPoints(sf::Text& text, int& score){
                                score +=300;
                                text.setString("Score: " +std::to_string(score));
                                }

                //Pac-Man update function
                void update(sf::Time deltaTime, const sf::Vector2f& borderPosition, const sf::Vector2f& borderSize, std::vector<sf::RectangleShape>& pereti,  std::vector<sf::CircleShape>& points,sf::Text& text,int& score
                        , std::vector<Enemy>& enemies,bool& GameOver,sf::RenderWindow& window,int& grab_count,bool& Won) {
                     sf::Vector2f movement(0.f, 0.f);

                    // Handle movement based on input
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
                        movement.x = -m_speed * deltaTime.asSeconds();
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
                        movement.x = m_speed * deltaTime.asSeconds();
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
                        movement.y = -m_speed * deltaTime.asSeconds();
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
                        movement.y = m_speed * deltaTime.asSeconds();
                    }

                    // Check proximity to the border, and adjust the movement speed to stop near it
                    if (m_position.x + movement.x - m_radius < borderPosition.x + m_proximityThreshold - 30) {
                        movement.x = 0;  // Stop horizontal movement if too close to the left border
                    }
                    if (m_position.x + movement.x + m_radius > borderPosition.x + borderSize.x - m_proximityThreshold) {
                        movement.x = 0;  // Stop horizontal movement if too close to the right border
                    }

                    if (m_position.y + movement.y - m_radius < borderPosition.y + m_proximityThreshold - 30) {
                        movement.y = 0;  // Stop vertical movement if too close to the top border
                    }
                    if (m_position.y + movement.y + m_radius > borderPosition.y + borderSize.y - m_proximityThreshold) {
                        movement.y = 0;  // Stop vertical movement if too close to the bottom border
                    }


                sf::FloatRect pacmanBounds = m_shape.getGlobalBounds();

                // Wall collision check
                for (const auto& wall : pereti) {
                    // Wall's bounding box
                        sf::FloatRect wallBounds  = wall.getGlobalBounds();
                        if(const std::optional intersection =pacmanBounds.findIntersection(wallBounds) ){
                                movement = sf::Vector2f ({0.f, 0.f});
                                GameOver = true;

                        }



                }
                //Check for enemy collision
                        for( auto& enemy :enemies){
                                sf::FloatRect enemyBounds = enemy.getGlobalBounds();
                                if(!enemy.is_chickenGhostMode()){
                                        if(const std::optional intersection_enemy = pacmanBounds.findIntersection(enemyBounds)){
                                                movement = sf::Vector2f({0.f,0.f});
                                                GameOver = true;
                                        }
                                }
                                else if(enemy.is_chickenGhostMode()){
                                        if(const std::optional intersection_enemy = pacmanBounds.findIntersection(enemyBounds)){
                                                if(enemy.Visible()){
                                                GetGhostPoints(text,score);
                                                enemy.HideForSeconds(5.f);
                                                }

                                        }

                                }
}

                        if(GameOver) window.clear(sf::Color::Black);



                        //Grab points
                    for(size_t  i=0;i<points.size();i++){
                        sf::FloatRect pointBounds = points[i].getGlobalBounds();
                        if(const std::optional pointIntersection = pacmanBounds.findIntersection(pointBounds)){
                                points.erase(points.begin()+i);

                                ChangeScore(text,score);
                                }
                        }

                        if(points.empty())
                                Won = true;
                        if(Won) window.clear(sf::Color::Black);



                //Update Pac-Man postion
                    m_position+=movement;
                    m_shape.setPosition(m_position);

                    }




                //Function to render Pac-Man
                void render(sf::RenderWindow& window) {
                    window.draw(m_shape);
                }



                //Pac-Man class variables
            private:
                sf::CircleShape m_shape;
                sf::Vector2f m_position;
                float m_radius;
                sf::Color m_color;
                float m_speed = 200.0f; // Speed of Pac-Man (pixels per second)
                float m_proximityThreshold;  // Proximity threshold to stop movement near the border

                //sf::SoundBuffer buffer;

                bool m_movingLeft = false;
                bool m_movingRight = false;
                bool m_movingUp = false;
                bool m_movingDown = false;



            };

                //Main function
            int main() {
                bool GameOver = false;
                bool Won = false;
                int grab_count=0;
                sf::RenderWindow window(sf::VideoMode({1400, 600}), "Pac-Man");




                // Create a Pac-Man object (yellow, radius of 20, starting at position (400, 300))
                float proximityThreshold = 30.0f;  // Set the proximity threshold to 30 pixels
                PacMan pacman(15.f, sf::Color::Yellow, 130.f, 480.f, proximityThreshold);

                float borderThickness = 5.f;
                sf::RectangleShape border(sf::Vector2f(1200.f, 500.f)); // Adjusted for border size
                border.setFillColor(sf::Color::Transparent);            // No fill color (transparent)
                border.setOutlineColor(sf::Color::White);               // White border
                border.setOutlineThickness(borderThickness);

                // Center the border inside the window
                float xpos = (window.getSize().x - border.getSize().x) / 2.f;
                float ypos = (window.getSize().y - border.getSize().y) / 2.f;
                border.setPosition({xpos, ypos});

                // Store border position and size for easy reference
                sf::Vector2f borderPosition = border.getPosition();
                sf::Vector2f borderSize = border.getSize();

                //Score

                sf::Font font("ARIAL.TTF");
                sf::Text scoreText(font);
                scoreText.setCharacterSize(20);
                scoreText.setFillColor(sf::Color::Yellow);
                scoreText.setPosition({10.f,10.f});
                scoreText.setString("Score:0");


                sf::Text title(font);
                title.setFillColor(sf::Color::Yellow);
                title.setCharacterSize(30);
                title.setString("PAC-MAN");
                title.setPosition(sf::Vector2f({650.f,5.f}));

                vector<Enemy> enemies;
                enemies.emplace_back(sf::Vector2f({30.f,30.f}),sf::Color::Red,sf::Vector2f({1230.f,260.f}),sf::Vector2f({-1.f,0.f}),proximityThreshold);
                enemies.emplace_back(sf::Vector2f({30.f,30.f}),sf::Color::Green,sf::Vector2f({1230.f,290.f}),sf::Vector2f({0.f,1.f}),proximityThreshold);
                enemies.emplace_back(sf::Vector2f({30.f,30.f}),sf::Color::Cyan,sf::Vector2f({1230.f,320.f}),sf::Vector2f({1.f,0.f}),proximityThreshold);
                enemies.emplace_back(sf::Vector2f({30.f,30.f}),sf::Color::Magenta,sf::Vector2f({1230.f,350.f}),sf::Vector2f({0.f,-1.f}),proximityThreshold);



                //Create the map
                std::vector<sf::RectangleShape> walls;

                sf::RectangleShape wall1(sf::Vector2f(200.f, 30.f));
                wall1.setPosition({150.f, 100.f});  // Set position using curly brackets
                wall1.setFillColor(sf::Color::White);
                walls.push_back(wall1);

                sf::RectangleShape wall2(sf::Vector2f(150.f, 150.f));
                wall2.setPosition({300.f, 200.f});  // Set position using curly brackets
                wall2.setFillColor(sf::Color::White);
                walls.push_back(wall2);

                sf::RectangleShape wall3(sf::Vector2f(150.f, 150.f));
                wall3.setPosition({600.f, 200.f});  // Set position using curly brackets
                wall3.setFillColor(sf::Color::White);
                walls.push_back(wall3);

                sf::RectangleShape wall4(sf::Vector2f(150.f, 150.f));
                wall4.setPosition({920.f, 200.f});  // Set position using curly brackets
                wall4.setFillColor(sf::Color::White);
                walls.push_back(wall4);

                sf::RectangleShape wall11(sf::Vector2f(250.f,30.f));
                wall11.setPosition({440.f,100.f});
                wall11.setFillColor(sf::Color::White);
                walls.push_back(wall11);

                sf::RectangleShape wall12(sf::Vector2f(250.f,30.f));
                wall12.setPosition({440.f,430.f});
                wall12.setFillColor(sf::Color::White);
                walls.push_back(wall12);

                sf::RectangleShape wall13(sf::Vector2f(150.f,30.f));
                wall13.setPosition({200.f,430.f});
                wall13.setFillColor((sf::Color::White));
                walls.push_back(wall13);

                sf::RectangleShape wall15(sf::Vector2f(180.f,30.f));
                wall15.setPosition({1010.f,110.f});
                walls.push_back(wall15);

                sf::RectangleShape wall16(sf::Vector2f(180.f,30.f));
                wall16.setPosition({1010.f,430.f});
                walls.push_back(wall16);

                // Vertical walls
                sf::RectangleShape wall5(sf::Vector2f(30.f, 200.f));
                wall5.setPosition({200.f, 120.f});  // Set position using curly brackets
                wall5.setFillColor(sf::Color::White);
                walls.push_back(wall5);

                sf::RectangleShape wall6(sf::Vector2f(20.f, 20.f));
                wall6.setPosition({200.f, 200.f});  // Set position using curly brackets
                wall6.setFillColor(sf::Color::White);
                walls.push_back(wall6);

                sf::RectangleShape wall8(sf::Vector2f(30.f, 350.f));
                wall8.setPosition({815.f, 110.f});  // Set position using curly brackets
                wall8.setFillColor(sf::Color::White);
                walls.push_back(wall8);

                sf::RectangleShape wall9(sf::Vector2f(30.f, 150.f));
                wall9.setPosition({510.f, 100.f});  // Set position using curly brackets
                wall9.setFillColor(sf::Color::White);
                walls.push_back(wall9);

                sf::RectangleShape wall10(sf::Vector2f(30.f, 110.f));
                wall10.setPosition({510.f, 320.f});  // Set position using curly brackets
                wall10.setFillColor(sf::Color::White);
                walls.push_back(wall10);

                sf::RectangleShape wall14(sf::Vector2f(30.f,330.f));
                wall14.setPosition({1160.f,110.f});
                walls.push_back(wall14);

                vector<sf::CircleShape> points = pacman.pointsgen(walls,1300.f,500.f);


                // Clock to track time for smooth movement
                sf::Clock clock;

                while (window.isOpen()) {
                    sf::Time deltaTime = clock.restart();

                    // Event handling
                    while (const std::optional event = window.pollEvent())
                {
                    if (event->is<sf::Event::Closed>())
                    {
                        window.close();
                    }
                        // Handle key events for PacMan movement

                        }

                 if(Won){
                        window.clear(sf::Color::Black);
                        sf::Text WinText(font);
                        WinText.setPosition(sf::Vector2f({480.f,150.f}));
                        WinText.setCharacterSize(80);
                        WinText.setFillColor(sf::Color::White);
                        WinText.setString("You Won");
                        sf::Text retry(font);
                        retry.setString("Press enter to retry");
                        retry.setFillColor(sf::Color::White);
                        retry.setCharacterSize(30);
                        retry.setPosition(sf::Vector2f({560.f,260.f}));
                        window.draw(WinText);
                        window.draw(retry);

                        }

                else if(!GameOver){
                    // Update Pac-Man position (passing border position and size for collision detection)
                    pacman.update(deltaTime, borderPosition, borderSize,walls,points,scoreText,score,enemies,GameOver,window,grab_count,Won);

                    // Clear the window and draw everything
                    window.clear(sf::Color::Black);
                    pacman.render(window);
                    window.draw(border);
                    window.draw(scoreText);
                    window.draw(title);

                    for(const auto& wall:walls){
                            window.draw(wall);
                        }

                    for(const auto& point :points)
                                window.draw(point);

                    for( auto& enemy :enemies){
                                enemy.update(deltaTime,borderPosition,borderSize,walls,GameOver,enemies);
                                enemy.render(window);
                                }


                    }
                    else if(GameOver) {
                    window.clear(sf::Color::Black);
                    sf::Text GameOverText(font);
                    GameOverText.setPosition(sf::Vector2f({480.f,150.f}));
                    GameOverText.setCharacterSize(80);
                    GameOverText.setFillColor(sf::Color::White);
                    GameOverText.setString("Game Over");
                    sf::Text retry(font);
                    retry.setString("Press enter to retry");
                    retry.setFillColor(sf::Color::White);
                    retry.setCharacterSize(30);
                    retry.setPosition(sf::Vector2f({560.f,260.f}));
                    window.draw(GameOverText);
                    window.draw(retry);

                    }



                    if(GameOver && sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Enter)){
                        GameOver = false;
                        score = 0;
                        scoreText.setString("Score: 0");
                        pacman = PacMan(15.f,sf::Color::Yellow,130.f,480.f,proximityThreshold);
                        points = pacman.pointsgen(walls,1300.f,500.f);

                        enemies.clear();
                         enemies.emplace_back(sf::Vector2f({30.f,30.f}),sf::Color::Red,sf::Vector2f({1230.f,260.f}),sf::Vector2f({-1.f,0.f}),proximityThreshold);
                         enemies.emplace_back(sf::Vector2f({30.f,30.f}),sf::Color::Green,sf::Vector2f({1230.f,290.f}),sf::Vector2f({0.f,1.f}),proximityThreshold);
                         enemies.emplace_back(sf::Vector2f({30.f,30.f}),sf::Color::Cyan,sf::Vector2f({1230.f,320.f}),sf::Vector2f({1.f,0.f}),proximityThreshold);
                         enemies.emplace_back(sf::Vector2f({30.f,30.f}),sf::Color::Magenta,sf::Vector2f({1230.f,350.f}),sf::Vector2f({0.f,-1.f}),proximityThreshold);
;                        }




                    window.display();


        }

                return 0;
        }



