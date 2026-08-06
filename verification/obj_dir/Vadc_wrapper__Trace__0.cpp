// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vadc_wrapper__Syms.h"


void Vadc_wrapper___024root__trace_chg_0_sub_0(Vadc_wrapper___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadc_wrapper___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root__trace_chg_0\n"); );
    // Body
    Vadc_wrapper___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadc_wrapper___024root*>(voidSelf);
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vadc_wrapper___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vadc_wrapper___024root__trace_chg_0_sub_0(Vadc_wrapper___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root__trace_chg_0_sub_0\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0U]))) {
        bufp->chgIData(oldp+0,(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__i),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgSData(oldp+1,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_ms),15);
        bufp->chgSData(oldp+2,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_wr),15);
        bufp->chgSData(oldp+3,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr),15);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+4,((1U & (~ (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid)))));
        bufp->chgBit(oldp+5,(vlSelfRef.adc_wrapper__DOT__current_state));
        bufp->chgSData(oldp+6,(vlSelfRef.adc_wrapper__DOT__burst_count),10);
        bufp->chgBit(oldp+7,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid));
        bufp->chgBit(oldp+8,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__fall_through));
        bufp->chgBit(oldp+9,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid));
        bufp->chgSData(oldp+10,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__middle_data),12);
        bufp->chgBit(oldp+11,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst));
        bufp->chgBit(oldp+12,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst_ms));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgSData(oldp+13,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__std_rd_data),12);
        bufp->chgSData(oldp+14,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_ms),15);
        bufp->chgSData(oldp+15,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_rd),15);
        bufp->chgSData(oldp+16,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd),15);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgSData(oldp+17,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr),15);
        bufp->chgSData(oldp+18,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray),15);
        bufp->chgSData(oldp+19,((0x00003fffU & (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr))),14);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgSData(oldp+20,(vlSelfRef.adc_wrapper__DOT__adc_data),12);
        bufp->chgCData(oldp+21,(vlSelfRef.adc_wrapper__DOT__u_adc_int__DOT__latency_counter),3);
        bufp->chgBit(oldp+22,((0U == (IData)(vlSelfRef.adc_wrapper__DOT__u_adc_int__DOT__latency_counter))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[6U]))) {
        bufp->chgSData(oldp+23,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr),15);
        bufp->chgSData(oldp+24,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray),15);
        bufp->chgSData(oldp+25,((0x00003fffU & (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr))),14);
    }
    bufp->chgBit(oldp+26,(vlSelfRef.rst));
    bufp->chgBit(oldp+27,(vlSelfRef.enable));
    bufp->chgBit(oldp+28,(vlSelfRef.adc_clk));
    bufp->chgBit(oldp+29,(vlSelfRef.adc_clk_out));
    bufp->chgSData(oldp+30,(vlSelfRef.adc_data_raw),12);
    bufp->chgBit(oldp+31,(vlSelfRef.adc_otr));
    bufp->chgBit(oldp+32,(vlSelfRef.ulpi_clk));
    bufp->chgBit(oldp+33,(vlSelfRef.tx_ready));
    bufp->chgSData(oldp+34,(vlSelfRef.tx_data),12);
    bufp->chgBit(oldp+35,(vlSelfRef.tx_valid));
    bufp->chgBit(oldp+36,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__wr_ena));
    bufp->chgBit(oldp+37,(((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray) 
                           == ((0x00006000U & ((~ ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr) 
                                                   >> 0x0000000dU)) 
                                               << 0x0000000dU)) 
                               | (0x00001fffU & (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr))))));
    bufp->chgBit(oldp+38,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__rd_ena));
    bufp->chgSData(oldp+39,((0x00007fffU & (((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_rd) 
                                             - (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr)) 
                                            + ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid) 
                                               + ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid) 
                                                  + (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__fall_through)))))),15);
    bufp->chgBit(oldp+40,(vlSelfRef.adc_wrapper__DOT__adc_rst_ms));
    bufp->chgBit(oldp+41,(vlSelfRef.adc_wrapper__DOT__adc_rst_sync));
    bufp->chgBit(oldp+42,(vlSelfRef.adc_wrapper__DOT__next_state));
    bufp->chgBit(oldp+43,(vlSelfRef.adc_wrapper__DOT__byte_sent));
    bufp->chgBit(oldp+44,(((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray) 
                           == (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd))));
    bufp->chgBit(oldp+45,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__rd_ena));
    bufp->chgSData(oldp+46,((0x00007fffU & ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_rd) 
                                            - (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr)))),15);
    bufp->chgBit(oldp+47,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst));
    bufp->chgBit(oldp+48,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst_ms));
    bufp->chgSData(oldp+49,(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b),15);
}

void Vadc_wrapper___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root__trace_cleanup\n"); );
    // Body
    Vadc_wrapper___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadc_wrapper___024root*>(voidSelf);
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
}
