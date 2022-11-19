#include <iostream>
#include <cmath>

using namespace std;
double g = -10;


struct Point {
    double x;
    double y;
};

struct Velocity {
    double vx;
    double vy;
};

struct Stats {
    Point r;
    Velocity v;
    double t;
};


class Ball {
private:
    Point r = { 0, 0 };
    Velocity v;
    double t, T, V;


public:
    void push(double alpha, double v_mod) {
        v = { v_mod * cos(alpha), v_mod * sin(alpha) };
        V = v.vy;
        T = (double)-2 * V / g;
    };
    void fly(double time) {
        double t1;
        t = time;
        r.x = v.vx * t;
        if (T == 0) {
            r.y = 0;
        }
        else {
            int n = (int)t / T;
            t1 = t - n * T;
            r.y = V * t1 + g * t1 * t1 * 0.5;
            v.vy = V + g * t1;
        }
    };
    Point getPosition() {
        return r;
    };
    Velocity getVelocity() {
        return v;
    };

    Stats getStats() {
        Stats stat;
        stat.r = r;
        stat.v = v;
        stat.t = t;
        cout << "Position:  " << stat.r.x << ", " << stat.r.y << '\n';
        cout << "Velocity: " << sqrt((stat.v.vx)* (stat.v.vx) + (stat.v.vy)* (stat.v.vy)) << '\n';
        cout << "Time: " << stat.t << '\n';
        return stat;
    };

};


int main()
{
    Ball b;
    b.push(1, 100);
    b.fly(5);

    Stats stat;
    stat = b.getStats();
    return 0;
}
