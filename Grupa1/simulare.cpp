
#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"  // asigură-te că json.hpp e în același folder

using json = nlohmann::json;
using namespace std;

struct Car {
    int id;
    int x, y;
};

struct TrafficLight {
    int x, y;
    bool green_ns;
};

int main() {
    ifstream f("sim.json");
    if (!f) {
        cerr << "Nu s-a putut deschide sim.json" << endl;
        return 1;
    }

    json data;
    f >> data;

    vector<Car> cars;
    for (const auto& car : data["cars"]) {
        Car c;
        c.id = car["id"].get<int>();
        c.x = car["x"].get<int>();
        c.y = car["y"].get<int>();
        cars.push_back(c);
    }

    vector<TrafficLight> lights;
    for (const auto& light : data["traffic_lights"]) {
        TrafficLight tl;
        tl.x = light["x"].get<int>();
        tl.y = light["y"].get<int>();
        tl.green_ns = light["green_ns"].get<bool>();
        lights.push_back(tl);
    }

    for (auto& car : cars) {
        for (const auto& light : lights) {
            if (abs(car.y - light.y) < 20) {
                if (light.green_ns || car.x + 40 < light.x) {
                    car.x += 50;
                }
                break;
            }
        }
    }

    json out;
    for (const auto& car : cars) {
        out["cars"].push_back({{"id", car.id}, {"x", car.x}, {"y", car.y}});
    }
    for (const auto& light : lights) {
        out["traffic_lights"].push_back({
            {"x", light.x}, {"y", light.y}, {"green_ns", light.green_ns}
        });
    }

    ofstream o("sim.json");
    o << out.dump(4);

    return 0;
}
