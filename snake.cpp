#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;

const int SIZE = 20;
const int WIDTH = 30;
const int HEIGHT = 20;

struct SnakePart {
    int x, y;
};

int main() {
    RenderWindow window(VideoMode(WIDTH * SIZE, HEIGHT * SIZE), "Snake Game");

    // Snake Initial
    std::vector<SnakePart> snake = {{10, 10}, {9, 10}, {8, 10}};
    int dirX = 1, dirY = 0; // Right

    // Food
    SnakePart food = {5, 5};

    // Clock
    Clock clock;
    float timer = 0, delay = 0.1;

    while (window.isOpen()) {
        float time = clock.restart().asSeconds();
        timer += time;

        // ----------- Events ------------
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed)
                window.close();
        }

        // ----------- Keyboard ------------
        if (Keyboard::isKeyPressed(Keyboard::Up)) { dirX = 0; dirY = -1; }
        if (Keyboard::isKeyPressed(Keyboard::Down)) { dirX = 0; dirY = 1; }
        if (Keyboard::isKeyPressed(Keyboard::Left)) { dirX = -1; dirY = 0; }
        if (Keyboard::isKeyPressed(Keyboard::Right)) { dirX = 1; dirY = 0; }

        // ----------- Movement ------------
        if (timer > delay) {
            timer = 0;

            // Move body
            for (int i = snake.size() - 1; i > 0; i--) {
                snake[i] = snake[i - 1];
            }

            // Move head
            snake[0].x += dirX;
            snake[0].y += dirY;

            // -------- Boundaries (Game Over) --------
            if (snake[0].x < 0 || snake[0].x >= WIDTH || snake[0].y < 0 || snake[0].y >= HEIGHT) {
                std::cout << "GAME OVER!\n";
                window.close();
            }

            // -------- Eating Food --------
            if (snake[0].x == food.x && snake[0].y == food.y) {
                snake.push_back({snake[0].x, snake[0].y});
                food.x = rand() % WIDTH;
                food.y = rand() % HEIGHT;
            }

            // -------- Self Collision --------
            for (int i = 1; i < snake.size(); i++) {
                if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
                    std::cout << "GAME OVER (Self Hit)!\n";
                    window.close();
                }
            }
        }

        // ----------- Drawing ------------
        window.clear(Color::Black);

        // Draw snake
        RectangleShape rect(Vector2f(SIZE - 1, SIZE - 1));
        rect.setFillColor(Color::Green);
        for (auto &p : snake) {
            rect.setPosition(p.x * SIZE, p.y * SIZE);
            window.draw(rect);
        }

        // Draw Food
        rect.setFillColor(Color::Red);
        rect.setPosition(food.x * SIZE, food.y * SIZE);
        window.draw(rect);

        window.display();
    }

    return 0;
}
.