#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <random>
#include <vector>
#include <cmath>

std::random_device rd;
std::mt19937 rng(rd());
std::uniform_int_distribution<int> coords(4, 196);

struct Circle {
    sf::Vector2f pos;
    float radius;
    sf::Color color;
};

void appendCircleTriangles(
    sf::VertexArray& va,
    const Circle& c,
    int segments = 32
) {
    const float TWO_PI = 6.28318530718f;

    for (int i = 0; i < segments; ++i) {
        float a0 = (i / float(segments)) * TWO_PI;
        float a1 = ((i + 1) / float(segments)) * TWO_PI;

        sf::Vector2f p0 = c.pos;
        sf::Vector2f p1 = {
            c.pos.x + std::cos(a0) * c.radius,
            c.pos.y + std::sin(a0) * c.radius
        };
        sf::Vector2f p2 = {
            c.pos.x + std::cos(a1) * c.radius,
            c.pos.y + std::sin(a1) * c.radius
        };

        va.append({p0, c.color});
        va.append({p1, c.color});
        va.append({p2, c.color});
    }
}

int main() {
    sf::RenderWindow window(
        sf::VideoMode({200, 200}),
        "VertexArray Circles (Triangles Batch)"
    );

    window.setVerticalSyncEnabled(true);

    std::vector<Circle> circles;
    circles.push_back({{4.f, 4.f}, 4.f, sf::Color::Green});

    sf::VertexArray vertices(sf::PrimitiveType::Triangles);

    const float speed = 200.f;
    sf::Clock clock;

    // ---------------- Loop ----------------
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        // -------- Events --------
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto* mouse =
                    event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouse->button == sf::Mouse::Button::Left) {
                    circles.push_back({
                        {
                            static_cast<float>(coords(rng)),
                            static_cast<float>(coords(rng))
                        },
                        4.f,
                        sf::Color::Red
                    });
                }
            }
        }

        if (!circles.empty()) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
                circles[0].pos.y -= speed * dt;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
                circles[0].pos.y += speed * dt;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
                circles[0].pos.x -= speed * dt;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
                circles[0].pos.x += speed * dt;
        }

        vertices.clear();
        for (const auto& c : circles)
            appendCircleTriangles(vertices, c);

        window.clear();
        window.draw(vertices);
        window.display();
    }
}

