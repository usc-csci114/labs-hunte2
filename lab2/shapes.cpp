#include "shapes.h"
#include <algorithm>




//Implement your shapes here




Shape::Shape(Color c) : m_color(c) {}
Shape::~Shape() {}

void Shape::draw(uint8_t*** image, uint32_t h, uint32_t w) {
    BoundingBox box = getBoundingBox();
    for (uint32_t y = box.ul.y; y <= box.br.y && y < h; ++y) {
        for (uint32_t x = box.ul.x; x <= box.br.x && x < w; ++x) {
            if (inside(x, y)) {
                image[y][x][0] = m_color.r;
                image[y][x][1] = m_color.g;
                image[y][x][2] = m_color.b;
            }
        }
    }
}



Triangle::Triangle(Point t[3], Color c) : Shape(c){
    m_tri[0] = t[0];
    m_tri[1] = t[1];
    m_tri[2] = t[2];
}

Triangle::~Triangle() {};

BoundingBox Triangle::getBoundingBox(){
    BoundingBox b;
    b.ul.x = min(m_tri[0].x, m_tri[1].x, m_tri[2].x);
    b.ul.y = min(m_tri[0].y, m_tri[1].y, m_tri[2].y);

    b.br.x = max(m_tri[0].x, m_tri[1].x, m_tri[2].x);
    b.br.y = max(m_tri[0].y, m_tri[1].y, m_tri[2].y);


    return b; 
}

bool Triangle::inside(uint32_t x, uint32_t y){
    Point p = {x,y};
    

    return PointInTriangle(p, m_tri);
}

Circle::Circle(Point center, uint32_t radius, Color c) : Shape(c), m_center(center), m_radius(radius) {}

Circle::~Circle() {};

BoundingBox Circle::getBoundingBox() {
    BoundingBox b;
    b.ul.x = m_center.x - m_radius;
    b.ul.y = m_center.y - m_radius;
    b.br.x = m_center.x + m_radius;
    b.br.y = m_center.y + m_radius;
    return b;
}

bool Circle::inside(uint32_t x, uint32_t y) {
    int dx = static_cast<int>(x) - static_cast<int>(m_center.x);
    int dy = static_cast<int>(y) - static_cast<int>(m_center.y);
    return dx*dx + dy*dy <= m_radius*m_radius;
}

Rectangle::Rectangle(Point topLeft, uint32_t width, uint32_t height, Color c) : Shape(c), m_topLeft(topLeft), m_width(width), m_height(height) {}

Rectangle::~Rectangle() {};

BoundingBox Rectangle::getBoundingBox() {
    BoundingBox b;
    b.ul = m_topLeft;
    b.br.x = m_topLeft.x + m_width;
    b.br.y = m_topLeft.y + m_height;
    return b;
}

bool Rectangle::inside(uint32_t x, uint32_t y) {
    return x >= m_topLeft.x && x < m_topLeft.x + m_width &&
           y >= m_topLeft.y && y < m_topLeft.y + m_height;
}
