def midi_to_freq(note):
    return (2**((note-69)/12)) * 440

BASEFREQ = 30.637
ACCUMULATOR_STEPS = 2048
def freq_to_interval(freq):
    return freq/BASEFREQ * ACCUMULATOR_STEPS


print("const uint16_t notemappings[] PROGMEM = {")
print(", ".join([str(round(freq_to_interval(midi_to_freq(note)))) for note in range(0,128)]))
print("};")
