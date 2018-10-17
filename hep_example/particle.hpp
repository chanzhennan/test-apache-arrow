#ifndef particle_h
#define particle_h

#include <vector>
#include <tuple>

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
struct particle {
    std::tuple<T, T, T> position;
    vector4<T>          momentum;
    int                 charge;

    static particle<T> get_random() {
        return {
            {static_cast<T>(std::rand()), static_cast<T>(std::rand()), static_cast<T>(std::rand())},
            vector4<T>::get_random(),
            static_cast<int>(std::rand())
        };
    }
};

}

#endif
