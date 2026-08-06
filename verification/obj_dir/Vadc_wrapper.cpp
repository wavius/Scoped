// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vadc_wrapper__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vadc_wrapper::Vadc_wrapper(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vadc_wrapper__Syms(contextp(), _vcname__, this)}
    , rst{vlSymsp->TOP.rst}
    , adc_clk{vlSymsp->TOP.adc_clk}
    , ulpi_clk{vlSymsp->TOP.ulpi_clk}
    , enable{vlSymsp->TOP.enable}
    , adc_clk_out{vlSymsp->TOP.adc_clk_out}
    , adc_otr{vlSymsp->TOP.adc_otr}
    , tx_ready{vlSymsp->TOP.tx_ready}
    , tx_valid{vlSymsp->TOP.tx_valid}
    , adc_data_raw{vlSymsp->TOP.adc_data_raw}
    , tx_data{vlSymsp->TOP.tx_data}
    , __PVT__utils_pkg{vlSymsp->TOP.__PVT__utils_pkg}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vadc_wrapper::Vadc_wrapper(const char* _vcname__)
    : Vadc_wrapper(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vadc_wrapper::~Vadc_wrapper() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vadc_wrapper___024root___eval_debug_assertions(Vadc_wrapper___024root* vlSelf);
#endif  // VL_DEBUG
void Vadc_wrapper___024root___eval_static(Vadc_wrapper___024root* vlSelf);
void Vadc_wrapper___024root___eval_initial(Vadc_wrapper___024root* vlSelf);
void Vadc_wrapper___024root___eval_settle(Vadc_wrapper___024root* vlSelf);
void Vadc_wrapper___024root___eval(Vadc_wrapper___024root* vlSelf);

void Vadc_wrapper::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vadc_wrapper::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vadc_wrapper___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vadc_wrapper___024root___eval_static(&(vlSymsp->TOP));
        Vadc_wrapper___024root___eval_initial(&(vlSymsp->TOP));
        Vadc_wrapper___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vadc_wrapper___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vadc_wrapper::eventsPending() { return false; }

uint64_t Vadc_wrapper::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vadc_wrapper::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vadc_wrapper___024root___eval_final(Vadc_wrapper___024root* vlSelf);

VL_ATTR_COLD void Vadc_wrapper::final() {
    Vadc_wrapper___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vadc_wrapper::hierName() const { return vlSymsp->name(); }
const char* Vadc_wrapper::modelName() const { return "Vadc_wrapper"; }
unsigned Vadc_wrapper::threads() const { return 1; }
void Vadc_wrapper::prepareClone() const { contextp()->prepareClone(); }
void Vadc_wrapper::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vadc_wrapper::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vadc_wrapper___024root__trace_decl_types(VerilatedVcd* tracep);

void Vadc_wrapper___024root__trace_init_top(Vadc_wrapper___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vadc_wrapper___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadc_wrapper___024root*>(voidSelf);
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vadc_wrapper___024root__trace_decl_types(tracep);
    Vadc_wrapper___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vadc_wrapper___024root__trace_register(Vadc_wrapper___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vadc_wrapper::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vadc_wrapper::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 56);
    Vadc_wrapper___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
