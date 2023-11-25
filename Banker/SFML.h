#pragma once
struct Process
{
	int x;
	int y;
	int id;
    sf::RectangleShape Shape;
    sf::Text text;
    void Set(int X, int Y, int ID)
    {
        x = X;
        y = Y;
        id = ID;
    }
	void SetInfor(sf::RenderWindow *window,sf::Color color)
	{
        Shape.setSize(sf::Vector2f(50.f, 50.f));
        Shape.setFillColor(sf::Color(color));
        Shape.setOrigin(25.0f, 25.0f);
        Shape.setPosition(sf::Vector2f(x, y));
        sf::Font font;
        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Failed to load font!" << std::endl;
            return;
        }
        text.setFont(font);
        text.setFillColor(sf::Color::Black);
        text.setCharacterSize(24);
        text.setString(to_string(id));
        text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
        text.setPosition(Shape.getPosition().x, Shape.getPosition().y );
        window->draw(Shape);
        window->draw(text);
	}
};
void DrawProcess(sf::RenderWindow *window, int x, int y, v<bool>Finish,v<Process>&P)
{
    for (int i = 0; i < Finish.size(); i++)
    {
        if (!Finish[i])
        {
            P[i].Set(x, y, i);
            P[i].SetInfor(window,sf::Color::Green);
            y += 70;
        }
    }
}
struct Rq
{
    int x;
    int y;
    int id;
    sf::CircleShape Shape;
    sf::Text text;
    void Set(int X, int Y, int ID)
    {
        x = X;
        y = Y;
        id = ID;
    }
    void SetInfor(sf::RenderWindow* window, sf::Color color)
    {
        Shape.setRadius(25.f);
        Shape.setFillColor(sf::Color(color));
        Shape.setPosition(sf::Vector2f(x, y));
        Shape.setOrigin(12.5f, 12.5f);
        sf::Font font;
        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Failed to load font!" << std::endl;
            return;
        }
        text.setFont(font);
        text.setFillColor(sf::Color::Black);
        text.setCharacterSize(24);
        text.setString(to_string(id));
        text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
        text.setPosition(Shape.getPosition().x+12.5f, Shape.getPosition().y+12.5f);
        window->draw(Shape);
        window->draw(text);
    }
    void SetInfor(sf::RenderWindow* window, sf::Color color,int x,int y)
    {
        Shape.setRadius(25.f);
        Shape.setFillColor(sf::Color(color));
        Shape.setPosition(sf::Vector2f(x, y));
        Shape.setOrigin(12.5f, 12.5f);
        sf::Font font;
        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Failed to load font!" << std::endl;
            return;
        }
        text.setFont(font);
        text.setFillColor(sf::Color::Black);
        text.setCharacterSize(24);
        text.setString(to_string(id));
        text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
        text.setPosition(Shape.getPosition().x + 12.5f, Shape.getPosition().y + 12.5f);
        window->draw(Shape);
        window->draw(text);
    }
};
void DrawRequest(sf::RenderWindow* window, int x, int y, v <int>id, v<Rq>& R)
{
    R.clear();
    R.resize(id.size());
    for (int i = 0; i < id.size(); i++)
    {
        R[i].Set(x, y, id[i]);
        R[i].SetInfor(window, sf::Color::Green);
        y += 70;

    }
}
void DrawPAR(sf::RenderWindow& window, v<Process>& P, v<Rq>& R, v<int>id, v<bool>Finish, sf::RectangleShape Background, int status_pos_x,int need_pos_y,int request_pos_x )
{
    int p_pos_x = status_pos_x;
    int p_pos_y = 210;
    int r_pos_y =210;
    int r_pos_x = request_pos_x;
    window.draw(Background);
    DrawRequest(&window, r_pos_x, r_pos_y, id, R); 
    DrawProcess(&window, p_pos_x, p_pos_y, Finish, P);
}
void change_x_y(int& x, int& y, v<Process>& P, int status_pos_x, int need_pos_y)//ham nay dung de doi lai vi tri cua process
{
    int p_pos_x = status_pos_x;
    int p_pos_y = need_pos_y - (70 * (P.size() / 2))-80;
}
float Cal_Y(int x, const sf::CircleShape& A, const sf::RectangleShape& B)
{
	return (-(A.getPosition().y - B.getPosition().y)*1.00 * (x - A.getPosition().x) / (B.getPosition().x - A.getPosition().x)) + A.getPosition().y;
}