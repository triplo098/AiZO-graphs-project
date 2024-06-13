#ifndef SCRIPT_RUNNER_H
#define SCRIPT_RUNNER_H

class ScriptRunner {
public:

    void runScript();
    ScriptRunner(int argc, char *argv[]);
    /**
    param[0] = ALGORITHM
    param[1] = MATRIX OR LIST R`EPRESENTATION
    param[2] = NUMBER OF VERTICES
    param[3] = GRAPH DENSITY
    param[4] = NUMBER OF SAMPLES
    */
    int *par;

};

#endif