#ifndef STAR_H
#define STAR_H

#include <Godot.hpp>
#include <Node2D.hpp>


// since this inherits Node2D also have to consider it inherits positional info
namespace godot {
    class Star : public godot::Node2D {
        GODOT_CLASS(Star, godot::Node2D)

    private:
        String name;
        float magnitude;
        // absoulute magnitude Mv is the measure of luminosity of an object 
        // on an inverse log astronomical magnitude scale. 
        // Basically how bright an object is when viewed unobstructed 
        // from 10 parsecs away. range -20, 20?de;

        // float mass;      // think about good way to model this
        // char spectral_type;
    public:
        // Star _new(); // can implement this?
        void _init() {} 
        void _ready();
        void _process(float delta);

        static void _register_methods();
    };
}

#endif