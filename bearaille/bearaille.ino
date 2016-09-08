/*
   Bearaille, by jeremy b warner
   MCU code to parse board signals as braille code
   Made at the University of California, Berkeley
   Interactive Device Design, Fall 2016
 */

int enter = D0; // submit
int ul = D1; // upper-left
int ur = D2; // upper-right
int cl = D3; // center-left
int cr = D4; // center-right
int bl = D5; // lower-left
int br = D6; // lower-right

// fix for readbear
#if defined(ARDUINO)
SYSTEM_MODE(SEMI_AUTOMATIC);
#endif

void setup() {
    // setup pin switches
    pinMode(enter, INPUT_PULLUP);
    pinMode(ul, INPUT_PULLUP);
    pinMode(ur, INPUT_PULLUP);
    pinMode(cl, INPUT_PULLUP);
    pinMode(cr, INPUT_PULLUP);
    pinMode(bl, INPUT_PULLUP);
    pinMode(br, INPUT_PULLUP);

    // begin communication
    Serial.begin(9600);
}

int encode() {
    // return intermediate evaluation code from switches
    int code = 0;

    /* ul, ur, cl, cr, bl, br */
    /* MSB <------------> LSB */
    if(digitalRead(ul) == LOW) code += 32;
    if(digitalRead(ur) == LOW) code += 16;
    if(digitalRead(cl) == LOW) code += 8;
    if(digitalRead(cr) == LOW) code += 4;
    if(digitalRead(bl) == LOW) code += 2;
    if(digitalRead(br) == LOW) code += 1;

    return code;
}

char* strmap(int code) {
    // return relevant braille encoding given encoding. range is between 0 - 63,
    // custom mapping based on simplified english braille. can be found here:
    // https://en.wikipedia.org/wiki/English_Braille
    switch(code) {
        case 0: return " "; // enter space
        case 1: return "???"; // caps mod
        case 2: return "the quick brown fox jumps over the lazy dog";
        case 3: return "null";
        case 4: return "null";
        case 5: return "???"; // letter mod
        case 6: return "in";
        case 7: return "null";
        case 8: return "ea";
        case 9: return "null";
        case 10: return "bb";
        case 11: return "null";
        case 12: return "cc";
        case 13: return "dd";
        case 14: return "ff";
        case 15: return "gg";
        case 16: return "???"; // accent mod
        case 17: return "???"; // emph mod
        case 18: return "st";
        case 19: return "ing";
        case 20: return "null";
        case 21: return "null";
        case 22: return "ar";
        case 23: return "ble";
        case 24: return "i";
        case 25: return "ow";
        case 26: return "s";
        case 27: return "the";
        case 28: return "j";
        case 29: return "w";
        case 30: return "t";
        case 31: return "with";
        case 32: return "a";
        case 33: return "ch";
        case 34: return "k";
        case 35: return "u";
        case 36: return "e";
        case 37: return "wh";
        case 38: return "o";
        case 39: return "z";
        case 40: return "b";
        case 41: return "gh";
        case 42: return "l";
        case 43: return "v";
        case 44: return "h";
        case 45: return "ou";
        case 46: return "r";
        case 47: return "of";
        case 48: return "c";
        case 49: return "sh";
        case 50: return "m";
        case 51: return "x";
        case 52: return "d";
        case 53: return "th";
        case 54: return "n";
        case 55: return "y";
        case 56: return "f";
        case 57: return "ed";
        case 58: return "p";
        case 59: return "and";
        case 60: return "g";
        case 61: return "er";
        case 62: return "q";
        case 63: return "for";
        default: return "null";
    }
}

void loop() {
    // trigger on submission
    if (digitalRead(enter) == LOW) {

        // read the code, get string
        char* in = strmap(encode());

        // write string
        Serial.write(in);
        Serial.write('\n');

        // slow down
        delay(200);
    }
}

