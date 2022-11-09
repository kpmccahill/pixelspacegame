#ifndef GALAXY_H
#define GALAXY_H

#include <Godot.hpp>
#include <Area2D.hpp>
#include <CollisionShape2D.hpp>

// Local
#include <star.h>
#include <list>

namespace godot {
    class Galaxy : public Area2D {
        GODOT_CLASS(Galaxy, Area2D);

        CollisionShape2D *_collision_shape;
        Vector2 _screen_size;

        float star_density = 1000;




    public:

        void _init();
        void _ready();
        void _process(float delta);

        void genereate();
        void regenerate();

        static void _register_methods();


    };
}

#endif