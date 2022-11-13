extends CanvasLayer

func hide_debug_label():
	$DebugLabel.hide()

func show_debug_label(text):
	$DebugLabel.text = text
	$DebugLabel.show()

func update_debug_label(text):
	$DebugLabel.text = text
