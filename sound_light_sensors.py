from adafruit_circuitplayground import cp


color_value = (255, 0, 0)

geen = (0, 255, 0)

# range is 0 - 65535.
sound_max = 3000

cp.pixels.auto_write = False
cp.pixels.brightness = 0.3

print(100 / sound_max * 5)
def sound_scale_range(value):
    """Scale a value from 0-sound_max (chosen sound range) to 0-9 (NeoPixel range).
    Allows remapping sound value to pixel position.
    Full sound range is 0 - 65535. sound_max should be chosen based on testing."""
    return round(value / sound_max * 5)

def light_scale_range(value):
    """Scale a value from 0-320 (light range) to 0-9 (NeoPixel range).
    Allows remapping light value to pixel position."""
    return round(value / 320 * 9)

while True:
    peak = sound_scale_range(cp.sound_level)

    for pixel in range(5):
        if pixel <= peak:
            cp.pixels[pixel] = color_value
        else:
            cp.pixels[pixel] = (0, 0, 0)  # Off

    light_peak = light_scale_range(cp.light)

    for i in range(5,10):
        if i <= light_peak:
            cp.pixels[i] = geen
        else:
            cp.pixels[i] = (0, 0, 0)
    cp.pixels.show()

