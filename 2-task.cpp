#include <iostream>
#include <cmath>

enum Color {
    NONE = -1,
    RED,
    GREEN,
    BLUE
};

struct Coordinates {
    double x_coordinate = 0;
    double y_coordinate = 0;
};

class Figure {
    Coordinates center_coordinates;
    Color colorFigure = NONE;

    public:
        void setCenterCoordinates() {
            std::cout << "Input x: ";
            std::cin >> center_coordinates.x_coordinate;
            std::cout << "Input y: ";
            std::cin >> center_coordinates.y_coordinate;
        }
        Coordinates getCenterCoordinates() {
            return center_coordinates;
        }

        void setColorFigure() {
            std::string answer;
            std::cout << "Input color: ";
            std::cin >> answer;
            if (answer == "red") colorFigure = RED;
            else if (answer == "green") colorFigure = GREEN;
            else if (answer == "blue") colorFigure = BLUE; 
        }
        Color getColorFigure() {
            return colorFigure;
        }
};

class Rectangle: public Figure {
    Coordinates center_coordinates;
    Color colorFigure = NONE;
    double width = 0;
    double height = 0;

    public:
        void setHeight(double inHeight) {
            height = inHeight;
        }
        void setWidth(double inWidth) {
            width = inWidth;
        }
        double getHeight() {
            return height;
        }
        double getWidth() {
            return width;
        }

        double getArea() {
            return width * height;
        }
};

class Circle: public Figure {
    Coordinates center_coordinates;
    Color colorFigure = NONE;
    double radius = 0;

    public:
        void setRadius() {
            do {
                std::cout << "Input radius: ";
                std::cin >> radius;
            } while (radius <= 0);
        }

        Rectangle getDescribedRectangle() {
            Rectangle rectangle;
            rectangle.setHeight(radius * 2);
            rectangle.setWidth(radius * 2);
            return rectangle;
        }

        double getArea() {
            return std::atan(1) * 4 * radius;
        }
};

class Square: public Figure {
    Coordinates center_coordinates;
    Color colorFigure = NONE;
    double sideLength = 0;

    public:
        void setSideLength() {
            do {
                std::cout << "Input side length: ";
                std::cin >> sideLength;
            } while (sideLength <= 0);
        }

        Rectangle getDescribedRectangle() {
            Rectangle rectangle;
            rectangle.setHeight(sideLength);
            rectangle.setWidth(sideLength);
            return rectangle;
        }

        double getArea() {
            return std::pow(sideLength, 2); 
        }
};

class Triangle: public Figure {
    Coordinates center_coordinates;
    Color colorFigure = NONE;
    double sideLength = 0;

    public:
        void setSideLength() {
            do {
                std::cout << "Input side length: ";
                std::cin >> sideLength;
            } while (sideLength <= 0);
        }

        Rectangle getDescribedRectangle() {
            Rectangle rectangle;
            rectangle.setHeight((sideLength * std::sqrt(3)) / 2);
            rectangle.setWidth(sideLength);
            return rectangle;
        }

        double getArea() {
            return sideLength * sideLength * std::sqrt(3) / 4;
        }
};

int main() {
    std::string command;

    while (command != "exit") {
        std::cout << "Input command: ";
        std::cin >> command;

        if (command == "circle") {
            Circle circle;
            circle.setRadius();
            circle.setColorFigure();
            circle.setCenterCoordinates();
            Rectangle describedRectangle = circle.getDescribedRectangle();
            std::cout << "Area: " << circle.getArea() << std::endl;
            std::cout << "Described rectangle: height is " << describedRectangle.getHeight() << ", width is " << describedRectangle.getWidth() << std::endl;
            Coordinates center_coordinates = circle.getCenterCoordinates();
            std::cout << "Coordinates: x is " << center_coordinates.x_coordinate << ", y is " << center_coordinates.y_coordinate << std::endl;
            if (circle.getColorFigure() == RED) {
                std::cout << "Color: Red" << std::endl;
            }
            else if (circle.getColorFigure() == GREEN) {
                std::cout << "Color: Green" << std::endl;
            }
            else if (circle.getColorFigure() == BLUE) {
                std::cout << "Color: Blue" << std::endl;
            }
            else {
                std::cout << "Color: None" << std::endl;
            }   
        }
        else if (command == "square") {
            Square square;
            square.setSideLength();
            square.setColorFigure();
            square.setCenterCoordinates();
            Rectangle describedRectangle = square.getDescribedRectangle();
            std::cout << "Area: " << square.getArea() << std::endl;
            std::cout << "Described rectangle: height is " << describedRectangle.getHeight() << ", width is " << describedRectangle.getWidth() << std::endl;
            Coordinates center_coordinates = square.getCenterCoordinates();
            std::cout << "Coordinates: x is " << center_coordinates.x_coordinate << ", y is " << center_coordinates.y_coordinate << std::endl;
            if (square.getColorFigure() == RED) {
                std::cout << "Color: Red" << std::endl;
            }
            else if (square.getColorFigure() == GREEN) {
                std::cout << "Color: Green" << std::endl;
            }
            else if (square.getColorFigure() == BLUE) {
                std::cout << "Color: Blue" << std::endl;
            }
            else {
                std::cout << "Color: None" << std::endl;
            } 
        }
        else if (command == "triangle") {
            Triangle triangle;
            triangle.setSideLength();
            triangle.setColorFigure();
            triangle.setCenterCoordinates();
            Rectangle describedRectangle = triangle.getDescribedRectangle();
            std::cout << "Area: " << triangle.getArea() << std::endl;
            std::cout << "Described rectangle: height is " << describedRectangle.getHeight() << ", width is " << describedRectangle.getWidth() << std::endl;
            Coordinates center_coordinates = triangle.getCenterCoordinates();
            std::cout << "Coordinates: x is " << center_coordinates.x_coordinate << ", y is " << center_coordinates.y_coordinate << std::endl;
            if (triangle.getColorFigure() == RED) {
                std::cout << "Color: Red" << std::endl;
            }
            else if (triangle.getColorFigure() == GREEN) {
                std::cout << "Color: Green" << std::endl;
            }
            else if (triangle.getColorFigure() == BLUE) {
                std::cout << "Color: Blue" << std::endl;
            }
            else {
                std::cout << "Color: None" << std::endl;
            } 
        }
        else if (command == "rectangle") {
            Rectangle rectangle;
            double tempWidth, tempHeight;
            do {
                std::cout << "Input width: ";
                std::cin >> tempWidth;
            } while (tempWidth <= 0);
            do {
                std::cout << "Input height: ";
                std::cin >> tempHeight;
            } while (tempHeight <= 0);

            rectangle.setWidth(tempWidth);
            rectangle.setHeight(tempHeight);
            rectangle.setColorFigure();
            rectangle.setCenterCoordinates();
            std::cout << "Area: " << rectangle.getArea() << std::endl;
            Coordinates center_coordinates = rectangle.getCenterCoordinates();
            std::cout << "Coordinates: x is " << center_coordinates.x_coordinate << ", y is " << center_coordinates.y_coordinate << std::endl;  
            if (rectangle.getColorFigure() == RED) {
                std::cout << "Color: Red" << std::endl;
            }
            else if (rectangle.getColorFigure() == GREEN) {
                std::cout << "Color: Green" << std::endl;
            }
            else if (rectangle.getColorFigure() == BLUE) {
                std::cout << "Color: Blue" << std::endl;
            }
            else {
                std::cout << "Color: None" << std::endl;
            }
        }
    } 
}

/*
Спроектируйте иерархию классов различных фигур: 
круг, квадрат, равносторонний треугольник, прямоугольник.
Для всех этих фигур есть общие поля-данные — это 
координаты их центра и условный цвет фигуры: красный, синий или зелёный.
Для отдельных фигур есть и уникальные параметры: 
радиус для круга, длина ребра для квадрата и равностороннего 
треугольника, ширина и высота для прямоугольника. 
Все данные — это вещественные числа с удвоенной точностью.
Для каждой из фигур требуется определить метод нахождения 
площади фигуры, а также метод нахождения прямоугольника, 
описывающего фигуру полностью (он может быть больше зоны фигуры, но не меньше).
Для лучшего понимания задачи приведена иллюстрация. 
На ней разными цветами помечены площади фигур, 
а пунктиром изображены прямоугольники, описывающие фигуры.
*/