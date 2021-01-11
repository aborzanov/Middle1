#include <iostream>
#include <cmath>

class Vector
{
public:
    Vector()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    operator float()
    {
        return sqrt(x * x + y * y + z * z);
    }

    float operator[](int index)
    {
        switch (index)
        {
        case 0:
            return x;
            break;
        case 1:
            return y;
            break;
        case 2:
            return z;
            break;
        default:
            std::cout << "Index error!";
            return 0;
            break;
        }
    }

    friend Vector operator+(const Vector& a, const Vector& b);
    friend Vector operator-(const Vector& a, const Vector& b);
    friend Vector operator*(const Vector& a, float k);
    friend bool operator<(const Vector& a, const Vector& b);
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
    friend std::istream& operator>>(std::istream& in, Vector& v);

private:
    float x;
    float y;
    float z;

};

Vector operator+(const Vector& a, const Vector& b)
{
    return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

bool operator<(const Vector& a, const Vector& b)
{
    return false;
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    out << v.x << ' ' << v.y << ' ' << v.z;
    return out;
}

Vector operator-(const Vector& a, const Vector& b)
{
    return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector operator*(const Vector& a, float k)
{
    return Vector(a.x * k, a.y * k, a.z * k);
}

std::istream& operator>>(std::istream& in, Vector& v)
{
    in >> v.x;
    in >> v.y;
    in >> v.z;
    return in;
}

int main()
{
    int x = 1;
    float f;
    Vector v1(0, 1, 2);
    Vector v2(3, 4, 5);
    Vector v3;

    v3 = v1 + v2;
    std::cout << v3 << "\n";
    std::cout << float(v3) << "\n";
    std::cout << v2[1] << "\n";

    std::cout << v2 * 3.0f << "\n";
    std::cout << v1 - v2 << "\n";

    std::cin >> v3;
    std::cout << v3 << "\n";

    return 0;

}