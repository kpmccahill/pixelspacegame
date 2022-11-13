#ifndef GALAXY_H
#define GALAXY_H

#include <Godot.hpp>
#include <Area2D.hpp>
#include <CollisionShape2D.hpp>
#include <PackedScene.hpp>
#include <RandomNumberGenerator.hpp>
#include <Input.hpp>

// Local
#include <star.h>
#include <list>

// std
#include <vector>

namespace godot {
    class Galaxy : public Area2D {
        GODOT_CLASS(Galaxy, Area2D);

        CollisionShape2D *_collision_shape;
        Vector2 _screen_size;
        Vector2 _screen_center;

        int galaxy_size; // # of stars
        float star_density; // how tightly packed they are. might need to change away from # of stars
        float offset;

        Input *_input;


    public:
        Ref<PackedScene> star_scene;

        void _init();
        void _ready();
        void _process(float delta);
        void _physics_process(float delta );

        void generate();
        void regenerate();
        static void _register_methods();
        
    };
}

#endif