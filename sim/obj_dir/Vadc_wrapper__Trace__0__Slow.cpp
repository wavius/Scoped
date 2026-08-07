// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vadc_wrapper__Syms.h"


VL_ATTR_COLD void Vadc_wrapper___024root__trace_init_sub__TOP__params_pkg__0(Vadc_wrapper___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vadc_wrapper___024root__trace_init_sub__TOP__utils_pkg__0(Vadc_wrapper___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vadc_wrapper___024root__trace_init_sub__TOP__0(Vadc_wrapper___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root__trace_init_sub__TOP__0\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+26,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"adc_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"adc_clk_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+30,0,"adc_data_raw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+31,0,"adc_otr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"ulpi_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"tx_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"tx_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+35,0,"tx_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("adc_wrapper", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+50,0,"DWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"AWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+26,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"adc_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"adc_clk_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+30,0,"adc_data_raw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+31,0,"adc_otr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"ulpi_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"tx_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"tx_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+35,0,"tx_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+20,0,"adc_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+36,0,"adc_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"fifo_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"fifo_rd_ena",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+39,0,"fifo_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBit(c+40,0,"adc_rst_ms",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"adc_rst_sync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"current_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"burst_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+43,0,"byte_sent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_adc_int", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+50,0,"DWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+28,0,"clk_25m",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"a_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+30,0,"adc_data_raw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+31,0,"adc_otr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"adc_clk_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+20,0,"sample_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+36,0,"sample_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"fifo_full",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+21,0,"latency_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+22,0,"adc_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_oddr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+52,0,"D0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"D1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"SCLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"RST",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"Q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_dc_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+51,0,"AWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"DWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+26,0,"a_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"wr_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"wr_ena",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+20,0,"wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+37,0,"full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"rd_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"rd_ena",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"rd_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+4,0,"empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+39,0,"count",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBit(c+44,0,"std_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"std_rd_ena",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"std_rd_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+46,0,"std_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBit(c+7,0,"data_out_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"fall_through",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"middle_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"middle_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->pushPrefix("u_std_dc_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+51,0,"AWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"DWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+26,0,"a_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"wr_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"wr_ena",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+20,0,"wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+37,0,"full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"rd_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"rd_ena",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"rd_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+44,0,"empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+46,0,"count",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+54,0,"PTR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+47,0,"wr_a_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"wr_a_rst_ms",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"rd_a_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"rd_a_rst_ms",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+17,0,"wr_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+18,0,"wr_ptr_gray",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+14,0,"wr_ptr_ms",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+15,0,"wr_ptr_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+16,0,"wr_ptr_gray_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+23,0,"rd_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+24,0,"rd_ptr_gray",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+1,0,"rd_ptr_ms",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+2,0,"rd_ptr_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->declBus(c+3,0,"rd_ptr_gray_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
    tracep->pushPrefix("u_dpdcram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+51,0,"AWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"DWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+28,0,"wr_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"wr_ena",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"wr_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+20,0,"wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+32,0,"rd_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"rd_ena",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+13,0,"rd_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+55,0,"MDEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("params_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vadc_wrapper___024root__trace_init_sub__TOP__params_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("utils_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vadc_wrapper___024root__trace_init_sub__TOP__utils_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vadc_wrapper___024root__trace_init_sub__TOP__params_pkg__0(Vadc_wrapper___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root__trace_init_sub__TOP__params_pkg__0\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+50,0,"DWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"AWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vadc_wrapper___024root__trace_init_sub__TOP__utils_pkg__0(Vadc_wrapper___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root__trace_init_sub__TOP__utils_pkg__0\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+0,0,"gray2bin__Vstatic__i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+49,0,"gray2bin__Vstatic__b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 14,0);
}

VL_ATTR_COLD void Vadc_wrapper___024root__trace_init_top(Vadc_wrapper___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root__trace_init_top\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vadc_wrapper___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vadc_wrapper___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vadc_wrapper___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadc_wrapper___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadc_wrapper___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vadc_wrapper___024root__trace_register(Vadc_wrapper___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root__trace_register\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vadc_wrapper___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vadc_wrapper___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vadc_wrapper___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vadc_wrapper___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vadc_wrapper___024root__trace_const_0_sub_0(Vadc_wrapper___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadc_wrapper___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root__trace_const_0\n"); );
    // Body
    Vadc_wrapper___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadc_wrapper___024root*>(voidSelf);
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vadc_wrapper___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadc_wrapper___024root__trace_const_0_sub_0(Vadc_wrapper___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root__trace_const_0_sub_0\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+50,(0x0000000cU),32);
    bufp->fullIData(oldp+51,(0x0000000eU),32);
    bufp->fullBit(oldp+52,(1U));
    bufp->fullBit(oldp+53,(0U));
    bufp->fullIData(oldp+54,(0x0000000fU),32);
    bufp->fullIData(oldp+55,(0x00004000U),32);
}

VL_ATTR_COLD void Vadc_wrapper___024root__trace_full_0_sub_0(Vadc_wrapper___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadc_wrapper___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root__trace_full_0\n"); );
    // Body
    Vadc_wrapper___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadc_wrapper___024root*>(voidSelf);
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vadc_wrapper___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadc_wrapper___024root__trace_full_0_sub_0(Vadc_wrapper___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadc_wrapper___024root__trace_full_0_sub_0\n"); );
    Vadc_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+0,(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__i),32);
    bufp->fullSData(oldp+1,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_ms),15);
    bufp->fullSData(oldp+2,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_wr),15);
    bufp->fullSData(oldp+3,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr),15);
    bufp->fullBit(oldp+4,((1U & (~ (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid)))));
    bufp->fullBit(oldp+5,(vlSelfRef.adc_wrapper__DOT__current_state));
    bufp->fullSData(oldp+6,(vlSelfRef.adc_wrapper__DOT__burst_count),10);
    bufp->fullBit(oldp+7,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid));
    bufp->fullBit(oldp+8,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__fall_through));
    bufp->fullBit(oldp+9,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid));
    bufp->fullSData(oldp+10,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__middle_data),12);
    bufp->fullBit(oldp+11,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst));
    bufp->fullBit(oldp+12,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst_ms));
    bufp->fullSData(oldp+13,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__std_rd_data),12);
    bufp->fullSData(oldp+14,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_ms),15);
    bufp->fullSData(oldp+15,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_rd),15);
    bufp->fullSData(oldp+16,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd),15);
    bufp->fullSData(oldp+17,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr),15);
    bufp->fullSData(oldp+18,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray),15);
    bufp->fullSData(oldp+19,((0x00003fffU & (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr))),14);
    bufp->fullSData(oldp+20,(vlSelfRef.adc_wrapper__DOT__adc_data),12);
    bufp->fullCData(oldp+21,(vlSelfRef.adc_wrapper__DOT__u_adc_int__DOT__latency_counter),3);
    bufp->fullBit(oldp+22,((0U == (IData)(vlSelfRef.adc_wrapper__DOT__u_adc_int__DOT__latency_counter))));
    bufp->fullSData(oldp+23,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr),15);
    bufp->fullSData(oldp+24,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray),15);
    bufp->fullSData(oldp+25,((0x00003fffU & (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr))),14);
    bufp->fullBit(oldp+26,(vlSelfRef.rst));
    bufp->fullBit(oldp+27,(vlSelfRef.enable));
    bufp->fullBit(oldp+28,(vlSelfRef.adc_clk));
    bufp->fullBit(oldp+29,(vlSelfRef.adc_clk_out));
    bufp->fullSData(oldp+30,(vlSelfRef.adc_data_raw),12);
    bufp->fullBit(oldp+31,(vlSelfRef.adc_otr));
    bufp->fullBit(oldp+32,(vlSelfRef.ulpi_clk));
    bufp->fullBit(oldp+33,(vlSelfRef.tx_ready));
    bufp->fullSData(oldp+34,(vlSelfRef.tx_data),12);
    bufp->fullBit(oldp+35,(vlSelfRef.tx_valid));
    bufp->fullBit(oldp+36,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__wr_ena));
    bufp->fullBit(oldp+37,(((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray) 
                            == ((0x00006000U & ((~ 
                                                 ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr) 
                                                  >> 0x0000000dU)) 
                                                << 0x0000000dU)) 
                                | (0x00001fffU & (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr))))));
    bufp->fullBit(oldp+38,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__rd_ena));
    bufp->fullSData(oldp+39,((0x00007fffU & (((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_rd) 
                                              - (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr)) 
                                             + ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__data_out_valid) 
                                                + ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__middle_valid) 
                                                   + (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__fall_through)))))),15);
    bufp->fullBit(oldp+40,(vlSelfRef.adc_wrapper__DOT__adc_rst_ms));
    bufp->fullBit(oldp+41,(vlSelfRef.adc_wrapper__DOT__adc_rst_sync));
    bufp->fullBit(oldp+42,(vlSelfRef.adc_wrapper__DOT__next_state));
    bufp->fullBit(oldp+43,(vlSelfRef.adc_wrapper__DOT__byte_sent));
    bufp->fullBit(oldp+44,(((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray) 
                            == (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd))));
    bufp->fullBit(oldp+45,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__rd_ena));
    bufp->fullSData(oldp+46,((0x00007fffU & ((IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_rd) 
                                             - (IData)(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr)))),15);
    bufp->fullBit(oldp+47,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst));
    bufp->fullBit(oldp+48,(vlSelfRef.adc_wrapper__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_a_rst_ms));
    bufp->fullSData(oldp+49,(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b),15);
}
