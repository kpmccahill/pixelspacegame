extends Node

var debug_message_template: String
var _galaxy_seed: int 
var _galaxy_size: int
var _galaxy_density: float
var _offset_x: int
var _offset_y: int
var debug_message: String 

func update_debug_info():
	_galaxy_seed = $Galaxy.seed
	_galaxy_size = $Galaxy.galaxy_size
	_galaxy_density = $Galaxy.star_density
	_offset_x = $Galaxy.offset_x
	_offset_y = $Galaxy.offset_y
	debug_message = debug_message_template % [_galaxy_size, _galaxy_density, _galaxy_seed, _offset_x, _offset_y]

func _ready():
	debug_message_template = "Size: %s\nDensity: %s\nSeed: %s\nOffsetX: %s\nOffsetY: %s"
	update_debug_info()
	$HUD.show_debug_label(debug_message)

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta):
	update_debug_info()
	$HUD.update_debug_label(debug_message)

func _on_Galaxy_regenerating():
	update_debug_info()
	$HUD.update_debug_label(debug_message)
