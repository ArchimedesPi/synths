#ifndef __WAVETABLES_H__
#define __WAVETABLES_H__

#define PI 3.14159
#define PI2 (PI*2)
#define ACCUMULATOR_STEPS 2048

#define NONOTE 200 // MIDI notes go up to 127 so we can safely put our own overhead above that

typedef struct Wavetable {
    u16 len;
    int *wave;
    
    u32 position;
    u32 accumulator;
    u32 increment;

    u8 currentnote;
    double basefreq;
} Wavetable;

#define WT_SINE_LENGTH 256
#define WT_SINE_AMPLITUDE 127
#define WT_SINE_BASEFREQ 31.25

int wt_sine_data[WT_SINE_LENGTH];

inline void wt_init(Wavetable *table, int *data, u16 len, double basefreq) {
    table->len = len;
    table->wave = data;

    table->position = 0;
    table->accumulator = 0;
    table->increment = 0;

    table->currentnote = NONOTE;
    table->basefreq = basefreq;
}

inline void initialize_datatables() {
    for (int i=0; i < WT_SINE_LENGTH; i++) {
        wt_sine_data[i] = int(WT_SINE_AMPLITUDE * sin((PI2/WT_SINE_LENGTH) * i));
    }
}


void print_wavetable(Wavetable *table) {
    Serial.println("--- WAVETABLE DUMP ---");
    Serial << "len: 0x" << _HEX(table->len) << endl;
    for (int i=0; i < table->len; i++) {
        Serial << "0x" << _HEX(i) << ": " << table->wave[i] << endl;
    }
    Serial.println("--- DUMP DONE ---");
}

#endif
