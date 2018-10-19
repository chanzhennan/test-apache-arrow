#ifndef RArrowInterface_h
#define RArrowInterface_h

namespace ROOT {

class RArrowInterface {
public:
    RArrowInterface() = default;
    RArrowInterface(int x, int y, int z)
        : x{x}, y{y}, z{z}
    {}
    int x{0}, y{0}, z{0};

    ClassDef(RArrowInterface, 1);
};

}

#endif // RArrowInterface_h
