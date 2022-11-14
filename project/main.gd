extends Node

#NOTE: For some reason modifying these values at runtime (in the editor) clears them completely.
export var galaxy_seed: int = 0;
export var galaxy_size: int = 1000;
export var galaxy_density: float = 0.001;
export var offset_x: int = 3;
export var offset_y: int = 3;

var _galaxy

# Vars for the debug menu
var debug_message_template: String
var _galaxy_seed: int 
var _galaxy_size: int
var _galaxy_density: float
var _offset_x: int
var _offset_y: int
var debug_message: String

func update_debug_info():
	_galaxy_seed = _galaxy.seed
	_galaxy_size = _galaxy.galaxy_size
	_galaxy_density = _galaxy.star_density
	_offset_x = _galaxy.offset_x
	_offset_y = _galaxy.offset_y
	debug_message = debug_message_template % [_galaxy_size, _galaxy_density, _galaxy_seed, _offset_x, _offset_y]

func _init():
	_galaxy = preload("res://galaxy.tscn").instance()
	_galaxy.init(galaxy_size, galaxy_density, offset_x, offset_y);
	add_child(_galaxy)
	
func _ready():
	debug_message_template = "Size: %s\nDensity: %s\nSeed: %s\nOffsetX: %s\nOffsetY: %s"
	update_debug_info()
	$HUD.show_debug_label(debug_message)

func _new_galaxy():
	_galaxy.queue_free()

	_galaxy = preload("res://galaxy.tscn").instance()
	_galaxy.init(galaxy_size, galaxy_density, offset_x, offset_y);
	add_child(_galaxy)

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta):
	if Input.is_action_pressed("regen"):
		print("regen");
		_new_galaxy();

	update_debug_info()
	$HUD.update_debug_label(debug_message)

# func _on_Galaxy_regenerating():
# 	update_debug_info()
# 	$HUD.update_debug_label(debug_message)
