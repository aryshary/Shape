#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Shape {
public:
    virtual void Show() = 0;
    virtual void Save(const string& file) = 0;
    virtual void Load(const string& file) = 0;
    virtual ~Shape() {}
};

class SquareShape : public Shape {
    int x;
    int y;
    int l;
public:
    SquareShape(int x_i, int y_i, int l_i) : x{ x_i }, y{ y_i }, l{ l_i } {}

    void Show() override {
        cout << "Квадрат\nверхній лівий кут: (" << x << ", " << y << "), довжина сторони: " << l << endl;
    }

    void Save(const string& file) override {
        ofstream File(file);
        File << x << " " << y << " " << l << endl;
        File.close();
    }

    void Load(const string& filename) override {
        ifstream File(filename);
        File >> x >> y >> l;
        File.close();
    }
};

class RectangleShape : public Shape {
private:
    int x;
    int y;
    int w;
    int h;
public:
    RectangleShape(int x_i, int y_i, int w_i, int h_i) : x{ x_i }, y{ y_i }, w{ w_i }, h{ h_i } {}

    void Show() override {
        cout << "Прямокутник\nверхній лівий кут: (" << x << ", " << y << "), ширина: " << w << ", висота: " << h << endl;
    }

    void Save(const string& file) override {
        ofstream File(file);
        File << x << " " << y << " " << w << " " << h << endl;
        File.close();
    }

    void Load(const string& filename) override {
        ifstream File(filename);
        File >> x >> y >> w >> h;
        File.close();
    }
};

class CircleShape : public Shape {
private:
    int x;
    int y;
    int r;
public:
    CircleShape(int x_i, int y_i, int r_i) : x{ x_i }, y{ y_i }, r{ r_i } {}

    void Show() override {
        cout << "Коло\nцентр кола: (" << x << ", " << y << "), радіус кола: " << r << endl;
    }

    void Save(const string& file) override {
        ofstream File(file);
        File << x << " " << y << " " << r << endl;
        File.close();
    }

    void Load(const string& filename) override {
        ifstream File(filename);
        File >> x >> y >> r;
        File.close();
    }
};

class EllipseShape : public Shape {
private:
    int x;
    int y;
    int w;
    int h;
public:
    EllipseShape(int x_i, int y_i, int w_i, int h_i) : x{ x_i }, y{ y_i }, w{ w_i }, h{ h_i } {}

    void Show() override {
        cout << "Еліпс\nверхній кут: (" << x << ", " << y << "), ширина: " << w << ", висота: " << h << endl;
    }

    void Save(const string& file) override {
        ofstream File(file);
        File << x << " " << y << " " << w << " " << h << endl;
        File.close();
    }

    void Load(const string& filename) override {
        ifstream File(filename);
        File >> x >> y >> w >> h;
        File.close();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Shape*> shapes;

    shapes.push_back(new SquareShape(3, 4, 6));
    shapes.push_back(new RectangleShape(1, 2, 8, 5));
    shapes.push_back(new CircleShape(1, 5, 2));
    shapes.push_back(new EllipseShape(1, 3, 7, 4));

    for (int i = 0; i < shapes.size(); ++i) {
        shapes[i]->Save("shape" + to_string(i + 1) + ".txt");
        shapes[i]->Load("shape" + to_string(i + 1) + ".txt");
        shapes[i]->Show();
    }
    for (Shape* shape : shapes) {
        delete shape;
    }
    return 0;
}
