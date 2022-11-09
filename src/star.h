#ifndef STAR_H
#define STAR_H

#include <Godot.hpp>
#include <Node2D.hpp>

namespace godot {
    class Star : public godot::Node2D {
        GODOT_CLASS(Star, godot::Node2D)

    private:
        String name;
        // float mass;             // think about good way to model this
        // char spectral_type;
        float magnitude;    // absoulute magnitude Mv is the measure of luminosity of an object on an inverse log astronomical magnitude scale. Basically how bright an object is when
                            // viewed unobstructed from 10 parsecs away. range -20, 20?

    public:
        void _init();
        void _process(float delta);

        static void _register_methods();
    };
}

#endif