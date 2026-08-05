// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vadc_wrapper__pch.h"

Vadc_wrapper__Syms::Vadc_wrapper__Syms(VerilatedContext* contextp, const char* namep, Vadc_wrapper* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(294);
    // Setup sub module instances
    TOP__utils_pkg.ctor(this, "utils_pkg");
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__utils_pkg = &TOP__utils_pkg;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__utils_pkg.__Vconfigure(true);
    // Setup scopes
}

Vadc_wrapper__Syms::~Vadc_wrapper__Syms() {
    // Tear down scopes
    // Tear down sub module instances
    TOP__utils_pkg.dtor();
}
