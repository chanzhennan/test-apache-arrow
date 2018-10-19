#ifndef particle_h
#define particle_h

#include <vector>
#include <tuple>
#include <ostream>

namespace hep {

template<typename T>
struct vector4 {
    T x, y, z, t;

    static vector4<T> get_random() {
        return {static_cast<T>(std::rand()), static_cast<T>(std::rand()), static_cast<T>(std::rand()),
                       static_cast<T>(std::rand())};
    }
};

template<typename T>
struct vector3 {
    T x,y,z;

    static vector3<T> get_random() {
        return {static_cast<T>(std::rand()), static_cast<T>(std::rand()), static_cast<T>(std::rand())};
    }
};

template<typename T>
class particle {
private:
    std::tuple<T, T, T> position;
    vector4<T>          momentum;
    int                 charge;
    std::vector<int>  some_properties;

    static particle<T> get_random() {
        return {
            {static_cast<T>(std::rand()), static_cast<T>(std::rand()), static_cast<T>(std::rand())},
            vector4<T>::get_random(),
            static_cast<int>(std::rand() % 5),
            {1,2,3,4,5,6}
        };
    }
};

}

#endif
