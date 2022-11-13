#include "galaxy.h"

using namespace godot;

void Galaxy::_init() {
    galaxy_size = 50;
    star_density = 0.1;
    offset_x = 50;
    offset_y = 50;
}

void Galaxy::_ready() {
    _input = Input::get_singleton();
    _screen_size = Vector2(1270, 720);
    _screen_center = _screen_size * 0.5;
    generate();
    // _collision_shape = get_node<CollisionShape2D>("CollisionShape2D");
    // _collision_shape->set_position(_screen_center);
}

void Galaxy::_process(float delta) {
    if (_input->is_action_pressed("regen")){
        regenerate();
    }
}

void Galaxy::_physics_process(float delta ) {

}

// Starts procedural generation w/ a simple offset and threshold.
void Galaxy::generate() { 
    Node *temp_star;
    Ref<RandomNumberGenerator> random = RandomNumberGenerator::_new();
    random->randomize();
    seed = random->get_seed();
    int dimensions = galaxy_size / 2;
    // Array weights = Array(Array());
    for (int i = 0; i < int(dimensions); i++){
        for (int j = 0; j < int(dimensions); j++){
            if (random->randf() < star_density) {
                temp_star = star_scene->instance();
                temp_star->set("position", (Vector2(i * offset_x, j * offset_y)));
                add_child(temp_star);
            }
        }
    }
}
/*
    Clears all children of this node and then calls the generate function.
    This is really slow. This is O(n^2) time for clearing followed by the generate method.
    Could get around this by just creating a completely new galaxy instance
    from outsite the class.
    */
void Galaxy::regenerate() {
    printf("regen\n");
    Array children = get_children();
    for (int i = 0; i < get_child_count(); i++){
        Node *temp = children.pop_front();
        temp->queue_free();
    }
    emit_signal("regenerating");
    generate();
}

// register all methods we wish to expose.
void Galaxy::_register_methods() {
    register_method("_ready", &Galaxy::_ready);
    register_method("_process", &Galaxy::_process);
    register_method("_physics_process", &Galaxy::_physics_process);
    register_property<Galaxy, int>("galaxy_size", &Galaxy::galaxy_size, 50);
    register_property<Galaxy, float>("star_density", &Galaxy::star_density, 0.1);
    register_property<Galaxy, int>("seed", &Galaxy::seed, 0);
    register_property<Galaxy, float>("offset_x", &Galaxy::offset_x, 50);
    register_property<Galaxy, float>("offset_y", &Galaxy::offset_y, 50);
    register_property("star_scene", &Galaxy::star_scene, (Ref<PackedScene>)nullptr);

    register_signal<Galaxy>("regenerating", Dictionary());
}