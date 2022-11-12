#include "galaxy.h"

using namespace godot;

// void Galaxy::_init() { }

void Galaxy::_ready() {
    galaxy_size = 500;
    star_density = 1.0;
    generate();
    // _collision_shape = get_node<CollisionShape2D>("CollisionShape2D");
    _screen_size = get_viewport_rect().size;
    _screen_center = _screen_center * 0.5;

    printf("testing");
    // _collision_shape->set_position(_screen_center);
}

void Galaxy::_process(float delta) {

}

void Galaxy::_physics_process(float delta ) {

}

// Starts the procedural generation of the galaxy. Inserting systems into the systems array.
void Galaxy::generate() { 
    // Simple offset generation
    Star *temp_star;
    for (int i = 0; i < _screen_size.y; i++){
        for (int j = 0; j < _screen_size.x; j++){
            temp_star = Star::_new();
            temp_star->set_position(Vector2(i * 2, j * 3));
            add_child(temp_star);
            printf("testing2");
        }
    }

}

// Clears the current system and generates a new one.
void Galaxy::regenerate() {

}

// register all methods we wish to expose.
void Galaxy::_register_methods() {
    register_method("_process", &Galaxy::_process);
    register_method("_physics_process", &Galaxy::_physics_process);
    register_property<Galaxy, int>("galaxy_size", &Galaxy::galaxy_size, 500);
    register_property<Galaxy, float>("star_density", &Galaxy::star_density, 1.0);
}