// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadc_wrapper.h for the primary calling header

#ifndef VERILATED_VADC_WRAPPER___024ROOT_H_
#define VERILATED_VADC_WRAPPER___024ROOT_H_  // guard

#include "verilated.h"
class Vadc_wrapper_utils_pkg;


class Vadc_wrapper__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vadc_wrapper___024root final {
  public:
    // CELLS
    Vadc_wrapper_utils_pkg* __PVT__utils_pkg;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(rst,0,0);
        VL_IN8(adc_clk,0,0);
        VL_IN8(ulpi_clk,0,0);
        VL_IN8(enable,0,0);
        VL_OUT8(adc_clk_out,0,0);
        VL_IN8(adc_otr,0,0);
        VL_IN8(tx_ready,0,0);
        VL_OUT8(tx_valid,0,0);
        CData/*0:0*/ adc_wrapper__DOT__adc_rst_ms;
        CData/*0:0*/ adc_wrapper__DOT__adc_rst_sync;
        CData/*0:0*/ adc_wrapper__DOT__current_state;
        CData/*0:0*/ adc_wrapper__DOT__next_state;
        CData/*0:0*/ adc_wrapper__DOT__byte_sent;
        CData/*2:0*/ adc_wrapper__DOT__u_adc_int__DOT__latency_counter;
        CData/*0:0*/ adc_wrapper__DOT__u_adc_int__DOT__adc_ready;
        CData/*0:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__rd_ena;
        CData/*0:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid;
        CData/*0:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__fall_through;
        CData/*0:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid;
        CData/*0:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst;
        CData/*0:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst_ms;
        CData/*0:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst;
        CData/*0:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst_ms;
        CData/*0:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__wr_ena;
        CData/*0:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__rd_ena;
        CData/*2:0*/ __Vdly__adc_wrapper__DOT__u_adc_int__DOT__latency_counter;
        CData/*0:0*/ __VdlySet__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __VicoPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__adc_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__ulpi_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__adc_wrapper__DOT__adc_rst_sync__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        VL_IN16(adc_data_raw,11,0);
        VL_OUT16(tx_data,11,0);
        SData/*11:0*/ adc_wrapper__DOT__adc_data;
        SData/*9:0*/ adc_wrapper__DOT__burst_count;
        SData/*11:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__std_rd_data;
        SData/*11:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__middle_data;
        SData/*14:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr;
        SData/*14:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray;
        SData/*14:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_ms;
        SData/*14:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_rd;
        SData/*14:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd;
        SData/*14:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr;
        SData/*14:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray;
        SData/*14:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_ms;
        SData/*14:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_wr;
        SData/*14:0*/ adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr;
        SData/*14:0*/ __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr;
        SData/*14:0*/ __Vdly__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr;
        SData/*11:0*/ __VdlyVal__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0;
        SData/*13:0*/ __VdlyDim0__adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<SData/*11:0*/, 16384> adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    };
    struct {
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 7> __Vm_traceActivity;
    };

    // INTERNAL VARIABLES
    Vadc_wrapper__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vadc_wrapper___024root(Vadc_wrapper__Syms* symsp, const char* namep);
    ~Vadc_wrapper___024root();
    VL_UNCOPYABLE(Vadc_wrapper___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
