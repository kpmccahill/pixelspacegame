#include "star.h"

using namespace godot;

void Star::_ready() {
    name = "test";
    magnitude = float(4.83);
}

void Star::_process(float delta) {
}


void Star::_register_methods(){
    register_method("_process", &Star::_process);
    register_property<Star, String>("name", &Star::name, "test");
    register_property<Star, float>("magnitude", &Star::magnitude, float(4.83));
}