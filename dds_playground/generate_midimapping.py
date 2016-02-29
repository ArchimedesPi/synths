def midi_to_freq(note):
    return (2**((note-69)/12)) * 440


print("const uint16_t notemappings[] PROGMEM = {")
print(", ".join([str(round(midi_to_freq(note))) for note in range(0,128)]))
print("};")
