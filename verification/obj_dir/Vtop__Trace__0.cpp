// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0U]))) {
        bufp->chgIData(oldp+0,(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__i),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgSData(oldp+1,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_ms),15);
        bufp->chgSData(oldp+2,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_wr),15);
        bufp->chgSData(oldp+3,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr),15);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+4,(vlSelfRef.top__DOT__startup_timer),23);
        bufp->chgBit(oldp+5,(vlSelfRef.top__DOT__ready_for_leds));
        bufp->chgCData(oldp+6,(vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_data_q),8);
        bufp->chgCData(oldp+7,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r),8);
        bufp->chgCData(oldp+8,(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_data_q),8);
        bufp->chgBit(oldp+9,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_txvalid_r));
        bufp->chgBit(oldp+10,(vlSelfRef.top__DOT__utmi_txready_wrapper));
        bufp->chgBit(oldp+11,(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxvalid_q));
        bufp->chgBit(oldp+12,(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxactive_q));
        bufp->chgBit(oldp+13,(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_rxerror_q));
        bufp->chgCData(oldp+14,(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_linestate_q),2);
        bufp->chgCData(oldp+15,(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_op_mode_r),2);
        bufp->chgCData(oldp+16,(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_xcvrselect_r),2);
        bufp->chgBit(oldp+17,(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_termselect_r));
        bufp->chgBit(oldp+18,(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dppulldown_r));
        bufp->chgBit(oldp+19,(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dmpulldown_r));
        bufp->chgCData(oldp+20,((0x000000ffU & ((IData)(vlSelfRef.top__DOT__tx_data_12b) 
                                                >> 4U))),8);
        bufp->chgSData(oldp+21,(vlSelfRef.top__DOT__tx_data_12b),12);
        bufp->chgBit(oldp+22,(vlSelfRef.top__DOT__tx_valid));
        bufp->chgBit(oldp+23,(vlSelfRef.top__DOT__u_adc_wrap__DOT__tx_ready));
        bufp->chgBit(oldp+24,(vlSelfRef.top__DOT__tx_seen));
        bufp->chgBit(oldp+25,((1U & (~ (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid)))));
        bufp->chgBit(oldp+26,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__rd_ena));
        bufp->chgBit(oldp+27,(vlSelfRef.top__DOT__u_adc_wrap__DOT__current_state));
        bufp->chgSData(oldp+28,(vlSelfRef.top__DOT__u_adc_wrap__DOT__burst_count),10);
        bufp->chgBit(oldp+29,(vlSelfRef.top__DOT__u_adc_wrap__DOT__byte_sent));
        bufp->chgBit(oldp+30,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid));
        bufp->chgBit(oldp+31,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__fall_through));
        bufp->chgBit(oldp+32,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid));
        bufp->chgSData(oldp+33,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_data),12);
        bufp->chgBit(oldp+34,((((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT____VdfgRegularize_h04591d3f_0_4) 
                                & (1U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q))) 
                               & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__mask_q))));
        bufp->chgCData(oldp+35,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_q),8);
        bufp->chgBit(oldp+36,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q));
        bufp->chgCData(oldp+37,(vlSelfRef.top__DOT__u_cdc__DOT__device_addr_q),7);
        bufp->chgBit(oldp+38,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__mask_q));
        bufp->chgBit(oldp+39,(vlSelfRef.top__DOT__u_cdc__DOT__rx_last_w));
        bufp->chgBit(oldp+40,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_err_q));
        bufp->chgBit(oldp+41,(vlSelfRef.top__DOT__u_cdc__DOT__ep0_rx_valid_w));
        bufp->chgBit(oldp+42,(vlSelfRef.top__DOT__u_cdc__DOT__ep0_rx_setup_w));
        bufp->chgBit(oldp+43,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_q));
        bufp->chgBit(oldp+44,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstrb_q));
        bufp->chgCData(oldp+45,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txdata_q),8);
        bufp->chgBit(oldp+46,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txlast_q));
        bufp->chgBit(oldp+47,(vlSelfRef.top__DOT__u_cdc__DOT__ep0_tx_data_accept_w));
        bufp->chgBit(oldp+48,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstall_q));
        bufp->chgBit(oldp+49,(((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT____VdfgRegularize_h04591d3f_0_4) 
                               & (1U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q)))));
        bufp->chgBit(oldp+50,(((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_accept_w) 
                               & (1U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q)))));
        bufp->chgBit(oldp+51,(((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT____VdfgRegularize_h04591d3f_0_4) 
                               & (2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q)))));
        bufp->chgBit(oldp+52,(vlSelfRef.top__DOT__u_cdc__DOT__inport_valid_q));
        bufp->chgCData(oldp+53,(vlSelfRef.top__DOT__u_cdc__DOT__inport_data_q),8);
        bufp->chgBit(oldp+54,(vlSelfRef.top__DOT__u_cdc__DOT__ep2_tx_data_last_w));
        bufp->chgBit(oldp+55,(vlSelfRef.top__DOT__u_cdc__DOT__ep2_tx_data_accept_w));
        bufp->chgBit(oldp+56,(((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT____VdfgRegularize_h04591d3f_0_4) 
                               & (3U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q)))));
        bufp->chgBit(oldp+57,(((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_accept_w) 
                               & (3U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q)))));
        bufp->chgBit(oldp+58,((2U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))));
        bufp->chgBit(oldp+59,((5U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))));
        bufp->chgCData(oldp+60,(vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[0]),8);
        bufp->chgCData(oldp+61,(vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1]),8);
        bufp->chgCData(oldp+62,(vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[2]),8);
        bufp->chgCData(oldp+63,(vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[3]),8);
        bufp->chgCData(oldp+64,(vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[4]),8);
        bufp->chgCData(oldp+65,(vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[5]),8);
        bufp->chgCData(oldp+66,(vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[6]),8);
        bufp->chgCData(oldp+67,(vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[7]),8);
        bufp->chgCData(oldp+68,(vlSelfRef.top__DOT__u_cdc__DOT__setup_wr_idx_q),3);
        bufp->chgBit(oldp+69,(vlSelfRef.top__DOT__u_cdc__DOT__setup_frame_q));
        bufp->chgBit(oldp+70,(vlSelfRef.top__DOT__u_cdc__DOT__setup_valid_q));
        bufp->chgBit(oldp+71,(vlSelfRef.top__DOT__u_cdc__DOT__setup_data_q));
        bufp->chgBit(oldp+72,(vlSelfRef.top__DOT__u_cdc__DOT__status_ready_q));
        bufp->chgCData(oldp+73,(vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[0U]),8);
        bufp->chgCData(oldp+74,(vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[1U]),8);
        bufp->chgSData(oldp+75,(vlSelfRef.top__DOT__u_cdc__DOT__wValue_w),16);
        bufp->chgSData(oldp+76,(vlSelfRef.top__DOT__u_cdc__DOT__wIndex_w),16);
        bufp->chgSData(oldp+77,(vlSelfRef.top__DOT__u_cdc__DOT__wLength),16);
        bufp->chgBit(oldp+78,(((IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_valid_q) 
                               & (vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[0U] 
                                  >> 7U))));
        bufp->chgBit(oldp+79,(vlSelfRef.top__DOT__u_cdc__DOT__setup_set_w));
        bufp->chgBit(oldp+80,(vlSelfRef.top__DOT__u_cdc__DOT__setup_no_data_w));
        bufp->chgCData(oldp+81,(vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[3U]),8);
        bufp->chgCData(oldp+82,(vlSelfRef.top__DOT__u_cdc__DOT__setup_packet_q[2U]),8);
        bufp->chgBit(oldp+83,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_stall_r));
        bufp->chgBit(oldp+84,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_ack_r));
        bufp->chgSData(oldp+85,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_get_len_r),16);
        bufp->chgCData(oldp+86,(vlSelfRef.top__DOT__u_cdc__DOT__desc_addr_r),8);
        bufp->chgBit(oldp+87,(vlSelfRef.top__DOT__u_cdc__DOT__addressed_q));
        bufp->chgBit(oldp+88,(vlSelfRef.top__DOT__u_cdc__DOT__addressed_r));
        bufp->chgCData(oldp+89,(vlSelfRef.top__DOT__u_cdc__DOT__device_addr_r),7);
        bufp->chgBit(oldp+90,(vlSelfRef.top__DOT__u_cdc__DOT__configured_q));
        bufp->chgBit(oldp+91,(vlSelfRef.top__DOT__u_cdc__DOT__configured_r));
        bufp->chgBit(oldp+92,(vlSelfRef.top__DOT__u_cdc__DOT__set_with_data_q));
        bufp->chgBit(oldp+93,(vlSelfRef.top__DOT__u_cdc__DOT__set_with_data_r));
        bufp->chgBit(oldp+94,(((IData)(vlSelfRef.top__DOT__u_cdc__DOT__set_with_data_q) 
                               & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__setup_data_q) 
                                  & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_accept_w)))));
        bufp->chgBit(oldp+95,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_sending_q));
        bufp->chgSData(oldp+96,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_idx_q),16);
        bufp->chgSData(oldp+97,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_len_q),16);
        bufp->chgBit(oldp+98,(((IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_sending_q) 
                               & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_len_q) 
                                  != (IData)(vlSelfRef.top__DOT__u_cdc__DOT__wLength)))));
        bufp->chgBit(oldp+99,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_sending_r));
        bufp->chgSData(oldp+100,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_idx_r),16);
        bufp->chgSData(oldp+101,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_len_r),16);
        bufp->chgBit(oldp+102,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_r));
        bufp->chgCData(oldp+103,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txdata_r),8);
        bufp->chgBit(oldp+104,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstrb_r));
        bufp->chgBit(oldp+105,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txlast_r));
        bufp->chgBit(oldp+106,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstall_r));
        bufp->chgBit(oldp+107,(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_send_accept_w));
        bufp->chgCData(oldp+108,(vlSelfRef.top__DOT__u_cdc__DOT__desc_addr_q),8);
        bufp->chgCData(oldp+109,(vlSelfRef.top__DOT__u_cdc__DOT__u_rom__DOT__desc_rom_r),8);
        bufp->chgSData(oldp+110,(vlSelfRef.top__DOT__u_cdc__DOT__inport_cnt_q),11);
        bufp->chgSData(oldp+111,(((5U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q))
                                   ? 0x01ffU : 0x003fU)),11);
        bufp->chgCData(oldp+112,(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__state_q),3);
        bufp->chgCData(oldp+113,(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r),3);
        bufp->chgIData(oldp+114,(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q),20);
        bufp->chgCData(oldp+115,(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__chirp_count_q),8);
        bufp->chgCData(oldp+116,(vlSelfRef.top__DOT__u_cdc__DOT__genblk1__DOT__last_linestate_q),2);
        bufp->chgBit(oldp+117,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__intr_q));
        bufp->chgSData(oldp+118,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_num_q),11);
        bufp->chgCData(oldp+119,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__state_q),3);
        bufp->chgSData(oldp+120,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q),15);
        bufp->chgBit(oldp+121,((1U & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q) 
                                      >> 0x0000000eU))));
        bufp->chgBit(oldp+122,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_valid_q));
        bufp->chgCData(oldp+123,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_dev_q),7);
        bufp->chgCData(oldp+124,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q),4);
        bufp->chgCData(oldp+125,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q),8);
        bufp->chgBit(oldp+126,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_valid_q));
        bufp->chgBit(oldp+127,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__valid_q));
        bufp->chgBit(oldp+128,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_complete_q));
        bufp->chgBit(oldp+129,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__handshake_valid_q));
        bufp->chgBit(oldp+130,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_valid_r));
        bufp->chgBit(oldp+131,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_strb_r));
        bufp->chgCData(oldp+132,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_r),8);
        bufp->chgBit(oldp+133,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_last_r));
        bufp->chgBit(oldp+134,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_accept_w));
        bufp->chgBit(oldp+135,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_q));
        bufp->chgCData(oldp+136,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_q),8);
        bufp->chgBit(oldp+137,((0U == (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q))));
        bufp->chgBit(oldp+138,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_space_q));
        bufp->chgBit(oldp+139,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_space_r));
        bufp->chgBit(oldp+140,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_ready_r));
        bufp->chgBit(oldp+141,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r));
        bufp->chgBit(oldp+142,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__in_data_bit_r));
        bufp->chgBit(oldp+143,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_stall_r));
        bufp->chgBit(oldp+144,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep_iso_r));
        bufp->chgBit(oldp+145,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_enable_q));
        bufp->chgBit(oldp+146,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__rx_setup_q));
        bufp->chgBit(oldp+147,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep0_out_data_bit_q));
        bufp->chgBit(oldp+148,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep0_in_data_bit_q));
        bufp->chgBit(oldp+149,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep1_out_data_bit_q));
        bufp->chgBit(oldp+150,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep1_in_data_bit_q));
        bufp->chgBit(oldp+151,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep2_out_data_bit_q));
        bufp->chgBit(oldp+152,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep2_in_data_bit_q));
        bufp->chgBit(oldp+153,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep3_out_data_bit_q));
        bufp->chgBit(oldp+154,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__ep3_in_data_bit_q));
        bufp->chgCData(oldp+155,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__current_addr_q),7);
        bufp->chgCData(oldp+156,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__next_state_r),3);
        bufp->chgBit(oldp+157,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_r));
        bufp->chgCData(oldp+158,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_r),8);
        bufp->chgBit(oldp+159,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__addr_update_pending_q));
        bufp->chgBit(oldp+160,(((~ (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txstrb_q)) 
                                & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txvalid_q) 
                                   & ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__ctrl_txlast_q) 
                                      & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__ep0_tx_data_accept_w))))));
        bufp->chgBit(oldp+161,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__sent_status_zlp_q));
        bufp->chgBit(oldp+162,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__new_out_bit_r));
        bufp->chgBit(oldp+163,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__new_in_bit_r));
        bufp->chgBit(oldp+164,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__cfg_int_rx_r));
        bufp->chgBit(oldp+165,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__cfg_int_tx_r));
        bufp->chgWData(oldp+166,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_state),80);
        bufp->chgWData(oldp+169,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid),80);
        bufp->chgCData(oldp+172,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r),8);
        bufp->chgBit(oldp+173,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT____Vcellinp__u_sie_rx__enable_i));
        bufp->chgCData(oldp+174,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q),4);
        bufp->chgIData(oldp+175,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q),32);
        bufp->chgCData(oldp+176,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q),4);
        bufp->chgCData(oldp+177,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__rx_active_q),4);
        bufp->chgBit(oldp+178,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__shift_en_w));
        bufp->chgCData(oldp+179,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q),2);
        bufp->chgCData(oldp+180,((0x000000ffU & vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q)),8);
        bufp->chgBit(oldp+181,((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q))));
        bufp->chgBit(oldp+182,((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q))));
        bufp->chgBit(oldp+183,((1U & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__rx_active_q))));
        bufp->chgBit(oldp+184,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__address_match_w));
        bufp->chgCData(oldp+185,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r),4);
        bufp->chgBit(oldp+186,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__input_ready_w));
        bufp->chgSData(oldp+187,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q),16);
        bufp->chgSData(oldp+188,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT__crc_out_o),16);
        bufp->chgBit(oldp+189,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_zlp_q));
        bufp->chgBit(oldp+190,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__last_q));
        bufp->chgBit(oldp+191,((1U & (~ ((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q) 
                                         >> 0x0000000eU)))));
        bufp->chgCData(oldp+192,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q),3);
        bufp->chgCData(oldp+193,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__next_state_r),3);
        bufp->chgBit(oldp+194,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_pid_q));
        bufp->chgBit(oldp+195,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_zlp_q));
        bufp->chgBit(oldp+196,(((IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__tx_data_strb_r) 
                                & (IData)(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_pid_q))));
        bufp->chgSData(oldp+197,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q),16);
        bufp->chgSData(oldp+198,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT__crc_out_o),16);
        bufp->chgBit(oldp+199,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__valid_q));
        bufp->chgCData(oldp+200,(vlSelfRef.top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_q),8);
        bufp->chgCData(oldp+201,(vlSelfRef.top__DOT__u_ulpi__DOT__state_q),2);
        bufp->chgBit(oldp+202,(vlSelfRef.top__DOT__u_ulpi__DOT__mode_update_q));
        bufp->chgCData(oldp+203,(vlSelfRef.top__DOT__u_ulpi__DOT__xcvrselect_q),2);
        bufp->chgBit(oldp+204,(vlSelfRef.top__DOT__u_ulpi__DOT__termselect_q));
        bufp->chgCData(oldp+205,(vlSelfRef.top__DOT__u_ulpi__DOT__opmode_q),2);
        bufp->chgBit(oldp+206,(vlSelfRef.top__DOT__u_ulpi__DOT__phy_reset_q));
        bufp->chgBit(oldp+207,(vlSelfRef.top__DOT__u_ulpi__DOT__mode_write_q));
        bufp->chgBit(oldp+208,(vlSelfRef.top__DOT__u_ulpi__DOT__otg_update_q));
        bufp->chgBit(oldp+209,(vlSelfRef.top__DOT__u_ulpi__DOT__dppulldown_q));
        bufp->chgBit(oldp+210,(vlSelfRef.top__DOT__u_ulpi__DOT__dmpulldown_q));
        bufp->chgBit(oldp+211,(vlSelfRef.top__DOT__u_ulpi__DOT__otg_write_q));
        bufp->chgBit(oldp+212,(vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_dir_q));
        bufp->chgCData(oldp+213,(vlSelfRef.top__DOT__u_ulpi__DOT__tx_delay_q),3);
        bufp->chgBit(oldp+214,((0U == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__tx_delay_q))));
        bufp->chgCData(oldp+215,(vlSelfRef.top__DOT__u_ulpi__DOT__tx_buffer_q[0]),8);
        bufp->chgCData(oldp+216,(vlSelfRef.top__DOT__u_ulpi__DOT__tx_buffer_q[1]),8);
        bufp->chgBit(oldp+217,(vlSelfRef.top__DOT__u_ulpi__DOT__tx_valid_q[0]));
        bufp->chgBit(oldp+218,(vlSelfRef.top__DOT__u_ulpi__DOT__tx_valid_q[1]));
        bufp->chgBit(oldp+219,(vlSelfRef.top__DOT__u_ulpi__DOT__tx_wr_idx_q));
        bufp->chgBit(oldp+220,(vlSelfRef.top__DOT__u_ulpi__DOT__tx_rd_idx_q));
        bufp->chgBit(oldp+221,(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_tx_ready_w));
        bufp->chgCData(oldp+222,(vlSelfRef.top__DOT__u_ulpi__DOT__utmi_tx_data_w),8);
        bufp->chgBit(oldp+223,(vlSelfRef.top__DOT__u_ulpi__DOT__ulpi_stp_q));
        bufp->chgCData(oldp+224,(vlSelfRef.top__DOT__u_ulpi__DOT__data_q),8);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgSData(oldp+225,(vlSelfRef.top__DOT__u_adc_wrap__DOT__adc_data),12);
        bufp->chgCData(oldp+226,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter),3);
        bufp->chgBit(oldp+227,((0U == (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter))));
        bufp->chgSData(oldp+228,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr),15);
        bufp->chgSData(oldp+229,((0x00003fffU & (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr))),14);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgSData(oldp+230,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__std_rd_data),12);
        bufp->chgSData(oldp+231,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_ms),15);
        bufp->chgSData(oldp+232,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_rd),15);
        bufp->chgSData(oldp+233,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd),15);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgSData(oldp+234,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr),15);
        bufp->chgSData(oldp+235,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray),15);
        bufp->chgSData(oldp+236,((0x00003fffU & (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr))),14);
    }
    bufp->chgBit(oldp+237,(vlSelfRef.clk_25m));
    bufp->chgBit(oldp+238,(vlSelfRef.ulpi_clk60));
    bufp->chgCData(oldp+239,(vlSelfRef.ulpi_data),8);
    bufp->chgBit(oldp+240,(vlSelfRef.ulpi_dir));
    bufp->chgBit(oldp+241,(vlSelfRef.ulpi_nxt));
    bufp->chgBit(oldp+242,(vlSelfRef.ulpi_stp));
    bufp->chgBit(oldp+243,(vlSelfRef.ulpi_reset));
    bufp->chgBit(oldp+244,(vlSelfRef.adc_clk_out));
    bufp->chgBit(oldp+245,(vlSelfRef.adc_otr));
    bufp->chgSData(oldp+246,(vlSelfRef.adc_data_raw),12);
    bufp->chgBit(oldp+247,(vlSelfRef.led_r));
    bufp->chgBit(oldp+248,(vlSelfRef.led_g));
    bufp->chgBit(oldp+249,(vlSelfRef.led_b));
    bufp->chgIData(oldp+250,(vlSelfRef.top__DOT__rst_cnt),20);
    bufp->chgBit(oldp+251,(vlSelfRef.top__DOT__phy_rst));
    bufp->chgCData(oldp+252,(vlSelfRef.top__DOT__rst_sync),3);
    bufp->chgBit(oldp+253,((1U & ((IData)(vlSelfRef.top__DOT__rst_sync) 
                                  >> 2U))));
    bufp->chgBit(oldp+254,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__wr_ena));
    bufp->chgBit(oldp+255,(((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray) 
                            == ((0x00006000U & ((~ 
                                                 ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr) 
                                                  >> 0x0000000dU)) 
                                                << 0x0000000dU)) 
                                | (0x00001fffU & (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr))))));
    bufp->chgSData(oldp+256,((0x00007fffU & (((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_rd) 
                                              - (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr)) 
                                             + ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid) 
                                                + ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid) 
                                                   + (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__fall_through)))))),15);
    bufp->chgBit(oldp+257,(vlSelfRef.top__DOT__u_adc_wrap__DOT__adc_rst_ms));
    bufp->chgBit(oldp+258,(vlSelfRef.top__DOT__u_adc_wrap__DOT__adc_rst_sync));
    bufp->chgBit(oldp+259,(vlSelfRef.top__DOT__u_adc_wrap__DOT__next_state));
    bufp->chgBit(oldp+260,(((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray) 
                            == (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd))));
    bufp->chgBit(oldp+261,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__rd_ena));
    bufp->chgSData(oldp+262,((0x00007fffU & ((IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_rd) 
                                             - (IData)(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr)))),15);
    bufp->chgBit(oldp+263,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst));
    bufp->chgBit(oldp+264,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst_ms));
    bufp->chgSData(oldp+265,(vlSelfRef.top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray),15);
    bufp->chgBit(oldp+266,(((3U == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__state_q)) 
                            & ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__mode_write_q) 
                               & (IData)(vlSelfRef.top__DOT__u_ulpi__DOT____VdfgRegularize_hdd78e87c_0_2)))));
    bufp->chgBit(oldp+267,(((3U == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__state_q)) 
                            & ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__otg_write_q) 
                               & (IData)(vlSelfRef.top__DOT__u_ulpi__DOT____VdfgRegularize_hdd78e87c_0_2)))));
    bufp->chgBit(oldp+268,(vlSelfRef.top__DOT__u_ulpi__DOT__turnaround_w));
    bufp->chgBit(oldp+269,(((~ (IData)(vlSelfRef.ulpi_dir)) 
                            & (((~ ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__mode_update_q) 
                                    | ((IData)(vlSelfRef.top__DOT__u_ulpi__DOT__otg_update_q) 
                                       | (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__turnaround_w)))) 
                                & (0U == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__state_q))) 
                               | ((2U == (IData)(vlSelfRef.top__DOT__u_ulpi__DOT__state_q)) 
                                  & (IData)(vlSelfRef.ulpi_nxt))))));
    bufp->chgSData(oldp+270,(vlSymsp->TOP__utils_pkg.gray2bin__Vstatic__b),15);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
