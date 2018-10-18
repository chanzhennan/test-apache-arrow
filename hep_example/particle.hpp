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
struct particle {
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

std::ostream& operator<<(std::ostream& os, std::vector<int> const& vs) {
    for (auto const& v : vs)
        os << v;
}

std::ostream& operator<<(std::ostream& os, hep::particle<float> const& p) {
    auto const& [x, y, z] = p.position;
    auto const& [x1, y1, z1, t1] = p.momentum;
    os << "*** particle ***\n";
    os << "position: " << x << ", " << y << ", " << z << "\n";
    os << "momentum: " << x1 << ", " << y1 << ", " << z1 << ", " << t1 << "\n";
    os << "charge: " << p.charge << "\n";
    return os;
}


#endif
