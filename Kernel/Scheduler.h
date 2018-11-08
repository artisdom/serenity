#pragma once

#include <AK/Assertions.h>

class Process;
struct RegisterDump;

extern Process* current;

class Scheduler {
public:
    static void initialize();
    static void timer_tick(RegisterDump&);
    static bool pick_next();
    static void pick_next_and_switch_now();
    static void switch_now();
    static bool yield();
    static bool context_switch(Process&);
    static void prepare_to_modify_tss(Process&);
private:
    static void prepare_for_iret_to_new_process();
};

int sched_yield();