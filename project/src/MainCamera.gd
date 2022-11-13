extends Camera2D

# movement vars
export var speed: int = 250

# zoom vars
var default_zoom: Vector2 = Vector2.ONE
var zoom_interval: Vector2 = Vector2(0.25, 0.25)

export var _zoom_max: float = 2
export var _zoom_min: float = 0.25
var zoom_max: Vector2 = Vector2(_zoom_max, _zoom_max)
var zoom_min: Vector2 = Vector2(_zoom_min, _zoom_min)
export var zoom_speed: float = 0.25 ## lerp weight

# Called when the node enters the scene tree for the first time.
func _ready():
    smoothing_enabled = true

func _unhandled_input(event):
    if event.is_action_released("zoom_in") and zoom > zoom_min:
        camera_zoom(-zoom_interval)
    elif event.is_action_released("zoom_out") and zoom < zoom_max:
        camera_zoom(zoom_interval)

# TODO: Unhook from framerate but dunno if I need to even.
func camera_zoom(interval: Vector2) -> void:
    var target_zoom = zoom + interval
    zoom = lerp(zoom, target_zoom, zoom_speed)

    if interval < Vector2.ZERO:
        position = lerp(position, get_global_mouse_position(), 0.15)
    
    ## Debug
    # print("Zoom: ", zoom)
    
# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):

    var input_vector = Vector2.ZERO

    input_vector.x = Input.get_action_strength("move_right") - Input.get_action_strength("move_left")
    input_vector.y = Input.get_action_strength("move_down") - Input.get_action_strength("move_up")
    input_vector = input_vector.normalized()

    position += input_vector * speed * delta
