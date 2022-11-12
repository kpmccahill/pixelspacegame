#include "galaxy.h"

using namespace godot;

void Galaxy::_init() {
    galaxy_size = 500;
    star_density = 1.0;
}

void Galaxy::_ready() {
    generate();
    // _collision_shape = get_node<CollisionShape2D>("CollisionShape2D");
    _screen_size = Vector2(1270, 720);
    _screen_center = _screen_size * 0.5;

    // _collision_shape->set_position(_screen_center);
}

void Galaxy::_process(float delta) {

}

void Galaxy::_physics_process(float delta ) {

}

// Starts the procedural generation of the galaxy. Inserting systems into the systems array.
void Galaxy::generate() { 
    // Simple offset generation
    // for (int i = 0; i < 500; i++) {
    //     temp_star = star_scene->instance();
    //     temp_star->set("position", Vector2(float(i * 2), float(3)));
    //     add_child(temp_star);
    // }
    Node *temp_star;
    Ref<RandomNumberGenerator> random = RandomNumberGenerator::_new();
    random->randomize();
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if (random->randf() > 0.6) {
                temp_star = star_scene->instance();
                temp_star->set("position", (Vector2(i * 15, j * 23)));
                add_child(temp_star);
            }
        }
    }

}

// Clears the current system and generates a new one.
void Galaxy::regenerate() {

}

// register all methods we wish to expose.
void Galaxy::_register_methods() {
    register_method("_ready", &Galaxy::_ready);
    register_method("_process", &Galaxy::_process);
    register_method("_physics_process", &Galaxy::_physics_process);
    register_property<Galaxy, int>("galaxy_size", &Galaxy::galaxy_size, 500);
    register_property<Galaxy, float>("star_density", &Galaxy::star_density, 1.0);
    register_property("star_scene", &Galaxy::star_scene, (Ref<PackedScene>)nullptr);
}