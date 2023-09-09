// namespace.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
// Пространство имён для вычислений на координатной плоскости
namespace CoordinateSpace {
    // Класс для точки на плоскости
    class Point 
    {
    public:
        Point() : x(0.0), y(0.0) {} 

        Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

        double getX() const { return x; }
        double getY() const { return y; }

    private:
        double x;
        double y;
    };

    // Класс для многоугольника
    class Polygon 
    {
    public:
        Polygon() : numVertices(0), vertices(nullptr) {}
        Polygon(int numVerticesCount) : numVertices(numVerticesCount), vertices(new Point[numVerticesCount]) {}

        void setVertex(int index, double xCoord, double yCoord) 
        {
            if (index >= 0 && index < numVertices) 
            {
                vertices[index] = Point(xCoord, yCoord);
            }
        }

        const Point* getVertices() const { return vertices; }
        int getNumVertices() const { return numVertices; }

    private:
        int numVertices;
        Point* vertices;
    };
}

// Пространство имён для классов-хранилищ
namespace StorageSpace {
    // Класс для динамического массива точек
    class DynamicArray 
    {
    public:
        DynamicArray(int capacityCount) : capacity(capacityCount), size(0), points(new CoordinateSpace::Point[capacityCount]) {}

        void addPoint(double xCoord, double yCoord) 
        {
            if (size < capacity)
            {
                points[size] = CoordinateSpace::Point(xCoord, yCoord);
                size++;
            }
        }

        const CoordinateSpace::Point* getPoints() const { return points; }
        int getSize() const { return size; }

    private:
        int capacity;
        int size;
        CoordinateSpace::Point* points;
    };
}

int main()
{
    using namespace CoordinateSpace;
    using namespace StorageSpace;

    // Создаем динамический массив точек
    DynamicArray pointArray(3);
    pointArray.addPoint(1.0, 2.0);
    pointArray.addPoint(3.0, 4.0);
    pointArray.addPoint(5.0, 6.0);

    // Преобразуем массив точек в многоугольник
    Polygon polygon(pointArray.getSize());
    const Point* points = pointArray.getPoints();
    for (int i = 0; i < pointArray.getSize(); i++) 
    {
        polygon.setVertex(i, points[i].getX(), points[i].getY());
    }

    // Выводим координаты вершин многоугольника
    const Point* vertices = polygon.getVertices();
    for (int i = 0; i < polygon.getNumVertices(); i++)
    {
        cout << "X: " << vertices[i].getX() << ", Y: " << vertices[i].getY() << endl;
    }

    return 0;
}
