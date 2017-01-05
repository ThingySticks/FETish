int Fet1 = D2; // Or B0 - Red LED
int Fet2 = A4; // Or B1 - Yellow LED
int Fet3 = D3; // Or B2 - Green LED
int Fet4 = A3; // Or B3 - Buzzer

// Output pins (as array)
int outputs[] = {D2, A4, D3, A3};
// int outputs[] = {B0, B1, B2, B3}; // - Use this if using the Electron extended options.

// Particle function definitions
int SwitchOutputOn (String args);
int SwitchOutputOff (String args);
int SwitchLightOn (String args);
int SwitchLightOff (String args);
int ShowSequence (String args);

bool showSequenceEnabled = false;

void setup() {
    // Debug LED.
    pinMode(D7, OUTPUT);
    
    for (int i = 0; i<4; i++) {
        // Set-up the pin as output.
        pinMode(outputs[i], OUTPUT);
        // Ensure it is switched off.
        digitalWrite(outputs[i], LOW);
    }
    
    // Declare the functions exposed to the internet.
    Particle.function("OutputOn", SwitchOutputOn);
    Particle.function("OutputOff", SwitchOutputOff);
    Particle.function("LightOn", SwitchLightOn);
    Particle.function("LightOff", SwitchLightOff);
    Particle.function("showSeq", ShowSequence);
    
    // Publish our online message.
    publishStatus("Fets and Lights. V0.3");
}

void loop() {
    
    digitalWrite(D7, HIGH);

    if (showSequenceEnabled) {
        runSequence();
    } else {
        delay(1000);
    }
    
    digitalWrite(D7, LOW);
    delay(1000);
}

void runSequence() {
    for (int i = 0; i<4; i++) {
        digitalWrite(outputs[i], HIGH);
        delay(1000);
        digitalWrite(outputs[i], LOW);
    }
}

// ==========================================
// Particle Functions
// ==========================================

// Switch the output channel on
// Use the channel number (1-4) for the argument
int SwitchOutputOn (String args) {
    int channel = args.toInt();
    switchOnChannel(channel);
    return channel;
}

// Switch the output channel off
// Use the channel number (1-4) for the argument
int SwitchOutputOff (String args) {
    int channel = args.toInt();
    switchOffChannel(channel);
    return channel;
}

// Switch the light on for a given named color
// Red, Yellow, Green, Buzzer (I know, buzzer isn't a color!)
int SwitchLightOn (String args) {
    int channel = getChannel(args);
    switchOnChannel(channel);
    return channel;
}

// Switch the light off for a given named color
// Red, Yellow, Green, Buzzer
int SwitchLightOff (String args) {
    int channel = getChannel(args);
    switchOffChannel(channel);
    return channel;
}

// Start the channel sequence.
int ShowSequence (String args) {
    showSequenceEnabled = true;
    return 1;
}

// --------------------------------------
// Helpers
// --------------------------------------
int switchOnChannel(int channel) {
    // Convert channel (1-4) to array index (0-3)
    int arrayIndex = channel - 1;
    digitalWrite(outputs[arrayIndex], HIGH);
    
    publishStatus("Channel " + String(channel) + " On.");
}

int switchOffChannel(int channel) {
    // Convert channel (1-4) to array index (0-3)
    int arrayIndex = channel - 1;
    digitalWrite(outputs[arrayIndex], LOW);
    
    publishStatus("Channel " + String(channel) + " Off.");
}


int getChannel(String color) {
    
    String lowerColor = color.toLowerCase();

    // Doesn't support String switch/case.
    if (lowerColor == "red") {
        return 1;
    } else if (lowerColor == "yellow") {
        return 2;
    } else if (lowerColor ==  "green") {
        return 3;
    } else if (lowerColor ==  "buzzer") {
        return 4;
    } else {
        // light up the red light.
        return 0;
    }
}

void publishStatus(String message) {
    Particle.publish("status", message);
}