# digitalsound
Translate simple music syntax into sampled sound wav files.

Digital sound is based on sampling an audio signal at a high rate in a manner that the sampled signal mimics the analog signal. This program turns the octpch notation of musical notes into sampled sound.

In octpch notation, each musical note is represented as a numbered pair, where the first number indicates the octave the note belongs to and the second number indicates the note within the octave (pitch). The 12 semitones within each octave are represented, and flat note equivalencies are ignored (example: 6.1 is 6th octave, 1st semitone).

To map sound frequencies to this representation, a reference note is chosen. This reference note frequency mapping is that 4.9 (A in the 4th octave) is 440 Hz. The tuning mapping insures that each note in the next higher octave has a frequency that is twice the prior octave.

A sample file in octpch notation that maps to "Mary Had A Little Lamb" is provided, in addition to a main that samples the audio signal into a file called my_wave.wav.
