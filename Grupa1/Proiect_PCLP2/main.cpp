#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <set>
#include <optional>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>

std::string getRandomWord() {
    std::vector<std::string> wordList = {
        "HELLO", "WORLD", "HANGMAN", "COMPUTER", "SCIENCE", "PROGRAMMING", "LANGUAGE", "PRESIDENT",
        "AMERICA", "SYSTEM", "TELEPHONE", "RANDOM", "CONGRESS", "BURGER", "WATER",
        "CRYSTAL", "KEYBOARD", "LAPTOP", "DESKTOP", "MOUSE", "CHAIR", "TABLE", "WINDOW", 
        "GLASS", "BOTTLE", "CABLE", "CHARGER", "CHARGE", "PHONE", "INTERNET", "CLOUD", "SERVER", 
        "SOFTWARE", "HARDWARE", "NETWORK", "ROBOT", "AI", "MACHINE", "LEARNING", "DATA", "CLOUD", 
        "STORAGE", "DEVICE", "MONITOR", "SCREEN", "PIXEL", "KEYBOARD", "CURSOR", "APPLICATION", "GAME",
        "LEVEL", "SCORE", "PLAY", "PAUSE", "START", "FINISH", "EXIT", "SAVE", "LOAD", "FILE", "FOLDER", 
        "DIRECTORY", "SEARCH", "ICON", "BUTTON", "CLICK", "DRAG", "DROP", "ZOOM", "SCROLL", "ERROR", "BUG", "FIX", 
        "UPDATE", "INSTALL", "DOWNLOAD", "UPLOAD", "BACKUP", "RESTORE", "SYNC", "MEMORY", "CACHE", "RAM", "CPU", 
        "GPU", "GRAPHICS", "PROGRAM", "SCRIPT", "CODE", "FUNCTION", "VARIABLE", "LOOP", "CONDITION", "ARRAY", "LIST", 
        "OBJECT", "CLASS", "MODULE", "DEBUG", "COMPILE", "EXECUTE", "RUN", "TEST", "COMMAND", "CONSOLE", "OUTPUT", 
        "INPUT", "EXCEPTION", "FAIL", "PASS", "ASSERT", "IMPORT", "EXPORT", "PACKAGE", "REPOSITORY", "VERSION", 
        "BRANCH", "COMMIT", "PUSH", "PULL", "CLONE", "MERGE", "CONFLICT", "RESOLVE", "IDE", "TERMINAL", "PROMPT", 
        "SHELL", "BASH", "GIT", "SVN", "DOCKER", "CONTAINER", "CLOUD", "KUBERNETES", "MONITOR", "LOG", 
        "ERROR", "WARNING", "INFO", "DEBUGGING", "SCRIPT", "TRACE", "PROFILE"
        
    };
    
    

    std::srand(static_cast<unsigned int>(std::time(0)));
    
    int randomIndex = std::rand() % wordList.size();
    
    return wordList[randomIndex];
}
const int WRONG_GUESSES = 7;

void resetBody(sf::CircleShape & head,sf::RectangleShape & body,sf::RectangleShape & leftArm,sf::RectangleShape & rightArm,sf::RectangleShape & leftLeg,sf::RectangleShape & rightLeg)
{
    head.setPosition({340.f, 370.f});head.setRotation(sf::degrees(0.f));
    body.setOrigin({2.5f, 0.f}); body.setPosition({340.f, 400.f}); 
    leftArm.setPosition({340.f, 430.f});leftArm.setRotation(sf::degrees(45.f));
    rightArm.setPosition({340.f, 430.f});rightArm.setRotation(sf::degrees(135.f));
    leftLeg.setPosition({340.f, 500.f});leftLeg.setRotation(sf::degrees(45.f));
    rightLeg.setPosition({340.f, 500.f});rightLeg.setRotation(sf::degrees(135.f));
}
void resetGame(std::string& SECRET_WORD, std::string& foundLetters, std::set<char>& guessedLetters, int& wrongGuessesLeft, bool& gameEnded, sf::Text& resultText, sf::Text& infoText) 
{
    SECRET_WORD= getRandomWord();
    foundLetters = std::string(SECRET_WORD.size(), '_');
    guessedLetters.clear();
    wrongGuessesLeft = 7;
    gameEnded = false;
    resultText.setString("");
    infoText.setString("Type a letter:");
    
      
    if(SECRET_WORD.size()>4){
        char firstLetter = SECRET_WORD[0];
        char lastLetter = SECRET_WORD[SECRET_WORD.size()-1];
        
        foundLetters[0] = firstLetter;
        foundLetters[SECRET_WORD.size()-1] = lastLetter;

        for(int i = 1; i < SECRET_WORD.size()-1; i++) {
            if(SECRET_WORD[i] == firstLetter || SECRET_WORD[i] == lastLetter) {
                foundLetters[i] = SECRET_WORD[i];
            }
        }
    }
}

int main()
{
    
    
    std::string SECRET_WORD = getRandomWord();
    
    sf::RenderWindow window(sf::VideoMode({1600, 900}), "Hangman");
    window.setFramerateLimit(60);
    
    sf::CircleShape around(80.f,8.f);
    around.setFillColor(sf::Color(200,0,0));

    around.setPosition(sf::Vector2f(800,300));
    around.setRotation(sf::degrees(23.f));
    around.setOrigin({80.f,80.f});
    around.setOutlineColor(sf::Color(255,255,255));
    around.setOutlineThickness({10.f});
   
    sf::RectangleShape base(sf::Vector2f(200.f, 20.f));
    base.setFillColor(sf::Color::White);
    base.setPosition({100.f, 600.f});


    sf::RectangleShape pole(sf::Vector2f(20.f, 300.f));
    pole.setFillColor(sf::Color::White);
    pole.setPosition({190.f, 300.f});

    sf::RectangleShape topBar(sf::Vector2f(150.f, 20.f));
    topBar.setFillColor(sf::Color::White);
    topBar.setPosition({190.f, 300.f});

    sf::RectangleShape rope(sf::Vector2f(5.f, 80.f));
    rope.setFillColor(sf::Color::White);
    rope.setPosition({340.f, 320.f});

    sf::CircleShape head(30.f);
    head.setFillColor(sf::Color::White);
    head.setOutlineColor(sf::Color::White);
    head.setOutlineThickness(5.f);
    head.setOrigin({30.f, 15.f});
    head.setPosition({340.f, 370.f});
    head.setRotation(sf::degrees(0.f));

    sf::RectangleShape body(sf::Vector2f(5.f, 100.f));
    body.setFillColor(sf::Color::White);
    body.setOrigin({2.5f, 0.f}); 
    body.setPosition({340.f, 400.f}); 

    sf::RectangleShape leftArm(sf::Vector2f(60.f, 5.f));
    leftArm.setFillColor(sf::Color::White);
    leftArm.setOrigin({0.f, 2.5f});
    leftArm.setPosition({340.f, 430.f});
    leftArm.setRotation(sf::degrees(45.f));

    sf::RectangleShape rightArm(sf::Vector2f(60.f, 5.f));
    rightArm.setFillColor(sf::Color::White);
    rightArm.setOrigin({0.f, 2.5f});
    rightArm.setPosition({340.f, 430.f});
    rightArm.setRotation(sf::degrees(135.f));

    sf::RectangleShape leftLeg(sf::Vector2f(60.f, 5.f));
    leftLeg.setFillColor(sf::Color::White);
    leftLeg.setOrigin({0.f, 2.5f});
    leftLeg.setPosition({340.f, 500.f});
    leftLeg.setRotation(sf::degrees(45.f));

    sf::RectangleShape rightLeg(sf::Vector2f(60.f, 5.f));
    rightLeg.setFillColor(sf::Color::White);
    rightLeg.setOrigin({0.f, 2.5f});
    rightLeg.setPosition({340.f, 500.f});
    rightLeg.setRotation(sf::degrees(135.f));


    sf::Font font("Fonts/arial/ARIAL.TTF");

    sf::Text stop1(font,"STOP",50);
    stop1.setPosition(sf::Vector2f(774,308));
    stop1.setOrigin({40,40});

    sf::Text wordDisplay(font, "", 50);
    wordDisplay.setFillColor(sf::Color::White);
    wordDisplay.setPosition({100.f, 200.f});

    sf::Text infoText(font, "Type a letter:", 30);
    infoText.setFillColor(sf::Color::Yellow);
    infoText.setPosition({100.f, 100.f});

    sf::Text resultText(font, "", 60);
    resultText.setFillColor(sf::Color::Red);
    resultText.setPosition({400.f, 400.f});
    
    sf::Text guessedLettersText(font, "", 30);  
    guessedLettersText.setFillColor(sf::Color::Green);  
    guessedLettersText.setPosition({100.f, 150.f});   

    
    sf::RectangleShape restartButton(sf::Vector2f(200.f, 50.f));
    restartButton.setFillColor(sf::Color::Blue);
    restartButton.setPosition({100.f, 750.f});

    sf::Text restartText(font, "Restart", 30);
    restartText.setFillColor(sf::Color::White);
    restartText.setPosition({130.f, 755.f});

    std::string foundLetters(SECRET_WORD.size(), '_');
    std::set<char> guessedLetters;
    int wrongGuessesLeft = WRONG_GUESSES;
    bool gameEnded = false;
     
    if(SECRET_WORD.size()>4){
        char firstLetter = SECRET_WORD[0];
        char lastLetter = SECRET_WORD[SECRET_WORD.size()-1];
        

        foundLetters[0] = firstLetter;
        foundLetters[SECRET_WORD.size()-1] = lastLetter;
        
        for(int i = 1; i < SECRET_WORD.size()-1; i++) {
            if(SECRET_WORD[i] == firstLetter || SECRET_WORD[i] == lastLetter) {
                foundLetters[i] = SECRET_WORD[i];
            }
        }
    }
    sf::Clock clock;
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if(event->is<sf::Event::Resized>()){
                sf::View view(sf::FloatRect({0.f,0.f},sf::Vector2f(window.getSize())));
                window.setView(view);
            }
            else if(const auto* spacePressed = event->getIf<sf::Event::KeyPressed>())
            {
                if(spacePressed->scancode==sf::Keyboard::Scancode::Space)
                {
                     resetGame(SECRET_WORD, foundLetters, guessedLetters, wrongGuessesLeft, gameEnded, resultText, infoText);
                    resetBody(head,body,leftArm,rightArm,leftLeg,rightLeg);
                }
            }
            else if (const auto* textEntered = event->getIf<sf::Event::TextEntered>()) {
                if (!gameEnded && textEntered->unicode < 128) {
                    char userChoice = static_cast<char>(textEntered->unicode);

                    if (std::isalpha(userChoice)) {
                        userChoice = static_cast<char>(std::toupper(userChoice));

                        if (!guessedLetters.insert(userChoice).second) {
                            infoText.setString("Already guessed " + std::string(1, userChoice));
                            continue;
                        }

                        std::size_t pos = SECRET_WORD.find(userChoice);
                        if (pos != std::string::npos) {
                            int found = 0;
                            do {
                                foundLetters[pos] = userChoice;
                                found++;
                                pos = SECRET_WORD.find(userChoice, pos + 1);
                            } while (pos != std::string::npos);

                            infoText.setString("Found " + std::to_string(found) + " letter" + (found > 1 ? "s" : "") + "!");
                            if (foundLetters == SECRET_WORD) {
                                resultText.setString("You WIN! GG");
                                gameEnded = true;
                            }
                        }
                        else {
                            wrongGuessesLeft--;
                            infoText.setString("Wrong guess! " + std::to_string(wrongGuessesLeft) + " tries left.");
                            if (wrongGuessesLeft == 0) {
                                resultText.setString("You LOST! The word was: " + SECRET_WORD);
                                gameEnded = true;
                            }
                        }
                    }
                }
            }
            else if (event->is<sf::Event::MouseButtonPressed>()) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (restartButton.getGlobalBounds().contains(mousePos)) {
                    resetGame(SECRET_WORD, foundLetters, guessedLetters, wrongGuessesLeft, gameEnded, resultText, infoText);
                    resetBody(head,body,leftArm,rightArm,leftLeg,rightLeg);
                }
            }
            
        }

        if (wrongGuessesLeft == 0) {
            head.setPosition({340.f, 400.f}); 
            float time = clock.getElapsedTime().asSeconds();
            float wiggleSpeed = 0.4f;  
            float amplitude = 50.f;   
            float angle = amplitude * std::sin(wiggleSpeed * time);
            float angle_left_arm=5.f * std::sin(0.4f*time); 
            float angle_right_arm=5.f * std::sin(-0.4f*time); 
            float angle_left_leg=5.f * std::sin(1.f*time); 
            float angle_right_leg=5.f * std::sin(-1.f*time); 
            head.setRotation(sf::degrees(angle)); 
            leftArm.setRotation(sf::degrees(75.f + angle_left_arm));    
            rightArm.setRotation(sf::degrees(100.f + angle_right_arm)); 
            leftLeg.setRotation(sf::degrees(75.f + angle_left_leg));    
            rightLeg.setRotation(sf::degrees(100.f + angle_right_leg)); 
        }
        
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        restartButton.setFillColor(restartButton.getGlobalBounds().contains(mousePos) ? sf::Color::Red : sf::Color(sf::Color::Blue))    ;

        std::string displayStr;
        for (char c : foundLetters) {
            displayStr += c;
            displayStr += ' ';
        }
        wordDisplay.setString(displayStr);

    
        std::string guessedLettersStr = "Guessed Letters: ";
        for (char guessedLetter : guessedLetters) {
            guessedLettersStr += guessedLetter;
            guessedLettersStr += ' ';
        }
        guessedLettersText.setString(guessedLettersStr);

        window.clear();
        if(WRONG_GUESSES - wrongGuessesLeft >=1) window.clear(sf::Color(30,0,0));
        if(WRONG_GUESSES - wrongGuessesLeft >=2) window.clear(sf::Color(45,0,0));
        if(WRONG_GUESSES - wrongGuessesLeft >=3) window.clear(sf::Color(60,0,0));
        if(WRONG_GUESSES - wrongGuessesLeft >=4) window.clear(sf::Color(75,0,0));
        if(WRONG_GUESSES - wrongGuessesLeft >=5) window.clear(sf::Color(90,0,0));
        if(WRONG_GUESSES - wrongGuessesLeft >=6) window.clear(sf::Color(105,0,0));

        window.draw(base);
        window.draw(pole);
        window.draw(topBar);
        window.draw(rope);

        if (WRONG_GUESSES - wrongGuessesLeft >= 1) window.draw(head);
        if (WRONG_GUESSES - wrongGuessesLeft >= 2) window.draw(body);
        if (WRONG_GUESSES - wrongGuessesLeft >= 3) window.draw(leftArm);
        if (WRONG_GUESSES - wrongGuessesLeft >= 4) window.draw(rightArm);
        if (WRONG_GUESSES - wrongGuessesLeft >= 5) window.draw(leftLeg);
        if (WRONG_GUESSES - wrongGuessesLeft >= 6) window.draw(rightLeg);
        
        if(WRONG_GUESSES-wrongGuessesLeft >=7) {around.rotate(sf::degrees(-5));}

        window.draw(restartButton);
        window.draw(restartText);
        window.draw(infoText);
        window.draw(wordDisplay);
        window.draw(resultText);
        window.draw(guessedLettersText);  
        window.display();
    }

    return 0;
}
