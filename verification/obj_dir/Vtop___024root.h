// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class Vtop_utils_pkg;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:
    // CELLS
    Vtop_utils_pkg* __PVT__utils_pkg;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk_25m,0,0);
        VL_IN8(ulpi_clk60,0,0);
        VL_INOUT8(ulpi_data,7,0);
        VL_IN8(ulpi_dir,0,0);
        VL_IN8(ulpi_nxt,0,0);
        VL_OUT8(ulpi_stp,0,0);
        VL_OUT8(ulpi_reset,0,0);
        VL_OUT8(adc_clk_out,0,0);
        VL_IN8(adc_otr,0,0);
        VL_OUT8(led_r,0,0);
        VL_OUT8(led_g,0,0);
        VL_OUT8(led_b,0,0);
        CData/*0:0*/ top__DOT__phy_rst;
        CData/*2:0*/ top__DOT__rst_sync;
        CData/*0:0*/ top__DOT__cdc_rst;
        CData/*0:0*/ top__DOT__ready_for_leds;
        CData/*0:0*/ top__DOT__utmi_txready_wrapper;
        CData/*0:0*/ top__DOT__tx_valid;
        CData/*0:0*/ top__DOT__tx_seen;
        CData/*1:0*/ top__DOT__u_ulpi__DOT__state_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT__mode_update_q;
        CData/*1:0*/ top__DOT__u_ulpi__DOT__xcvrselect_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT__termselect_q;
        CData/*1:0*/ top__DOT__u_ulpi__DOT__opmode_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT__phy_reset_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT__mode_write_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT__otg_update_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT__dppulldown_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT__dmpulldown_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT__otg_write_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT__ulpi_dir_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT__turnaround_w;
        CData/*2:0*/ top__DOT__u_ulpi__DOT__tx_delay_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT__tx_wr_idx_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT__tx_rd_idx_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT__utmi_tx_ready_w;
        CData/*7:0*/ top__DOT__u_ulpi__DOT__utmi_tx_data_w;
        CData/*7:0*/ top__DOT__u_ulpi__DOT__ulpi_data_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT__ulpi_stp_q;
        CData/*7:0*/ top__DOT__u_ulpi__DOT__data_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT__utmi_rxvalid_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT__utmi_rxerror_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT__utmi_rxactive_q;
        CData/*1:0*/ top__DOT__u_ulpi__DOT__utmi_linestate_q;
        CData/*7:0*/ top__DOT__u_ulpi__DOT__utmi_data_q;
        CData/*0:0*/ top__DOT__u_ulpi__DOT____VdfgRegularize_hdd78e87c_0_2;
        CData/*0:0*/ top__DOT__u_adc_wrap__DOT__tx_ready;
        CData/*0:0*/ top__DOT__u_adc_wrap__DOT__adc_rst_ms;
        CData/*0:0*/ top__DOT__u_adc_wrap__DOT__adc_rst_sync;
        CData/*0:0*/ top__DOT__u_adc_wrap__DOT__current_state;
        CData/*0:0*/ top__DOT__u_adc_wrap__DOT__next_state;
        CData/*0:0*/ top__DOT__u_adc_wrap__DOT__byte_sent;
        CData/*2:0*/ top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__latency_counter;
        CData/*0:0*/ top__DOT__u_adc_wrap__DOT__u_adc_int__DOT__adc_ready;
        CData/*0:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__rd_ena;
        CData/*0:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__data_out_valid;
        CData/*0:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__fall_through;
        CData/*0:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_valid;
        CData/*0:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst;
        CData/*0:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst_ms;
        CData/*0:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__wr_ena;
        CData/*0:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__rd_ena;
        CData/*6:0*/ top__DOT__u_cdc__DOT__device_addr_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__usb_ep0_tx_rd_w;
    };
    struct {
        CData/*7:0*/ top__DOT__u_cdc__DOT__usb_ep0_tx_data_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__usb_ep0_tx_empty_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__usb_ep0_rx_wr_w;
        CData/*7:0*/ top__DOT__u_cdc__DOT__usb_ep0_rx_data_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__usb_ep0_rx_full_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__usb_ep1_tx_rd_w;
        CData/*7:0*/ top__DOT__u_cdc__DOT__usb_ep1_tx_data_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__usb_ep1_tx_empty_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__usb_ep1_rx_wr_w;
        CData/*7:0*/ top__DOT__u_cdc__DOT__usb_ep1_rx_data_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__usb_ep1_rx_full_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__usb_ep2_tx_rd_w;
        CData/*7:0*/ top__DOT__u_cdc__DOT__usb_ep2_tx_data_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__usb_ep2_tx_empty_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__usb_ep2_rx_wr_w;
        CData/*7:0*/ top__DOT__u_cdc__DOT__usb_ep2_rx_data_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__usb_ep2_rx_full_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__usb_ep3_tx_rd_w;
        CData/*7:0*/ top__DOT__u_cdc__DOT__usb_ep3_tx_data_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__usb_ep3_tx_empty_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__usb_ep3_rx_wr_w;
        CData/*7:0*/ top__DOT__u_cdc__DOT__usb_ep3_rx_data_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__usb_ep3_rx_full_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__rx_last_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ep0_rx_valid_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ep0_rx_setup_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ep0_tx_data_accept_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ep2_tx_data_last_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ep2_tx_data_accept_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ep2_tx_stall_w;
        CData/*2:0*/ top__DOT__u_cdc__DOT__setup_wr_idx_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__setup_frame_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__setup_valid_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__setup_data_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__status_ready_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__setup_set_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__setup_no_data_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ctrl_stall_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ctrl_ack_r;
        CData/*7:0*/ top__DOT__u_cdc__DOT__desc_addr_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__addressed_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__addressed_r;
        CData/*6:0*/ top__DOT__u_cdc__DOT__device_addr_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__configured_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__configured_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__set_with_data_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__set_with_data_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ctrl_sending_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ctrl_sending_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ctrl_txvalid_q;
        CData/*7:0*/ top__DOT__u_cdc__DOT__ctrl_txdata_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ctrl_txstrb_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ctrl_txlast_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ctrl_txstall_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ctrl_txvalid_r;
        CData/*7:0*/ top__DOT__u_cdc__DOT__ctrl_txdata_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ctrl_txstrb_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ctrl_txlast_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ctrl_txstall_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__ctrl_send_accept_w;
        CData/*7:0*/ top__DOT__u_cdc__DOT__desc_addr_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__inport_valid_q;
        CData/*7:0*/ top__DOT__u_cdc__DOT__inport_data_q;
        CData/*2:0*/ top__DOT__u_cdc__DOT__genblk1__DOT__state_q;
    };
    struct {
        CData/*2:0*/ top__DOT__u_cdc__DOT__genblk1__DOT__next_state_r;
        CData/*7:0*/ top__DOT__u_cdc__DOT__genblk1__DOT__chirp_count_q;
        CData/*1:0*/ top__DOT__u_cdc__DOT__genblk1__DOT__last_linestate_q;
        CData/*1:0*/ top__DOT__u_cdc__DOT__genblk1__DOT__utmi_op_mode_r;
        CData/*1:0*/ top__DOT__u_cdc__DOT__genblk1__DOT__utmi_xcvrselect_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__genblk1__DOT__utmi_termselect_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dppulldown_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__genblk1__DOT__utmi_dmpulldown_r;
        CData/*3:0*/ top__DOT__u_cdc__DOT__u_core__DOT__ep_clear_toggle_i;
        CData/*2:0*/ top__DOT__u_cdc__DOT__u_core__DOT__state_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__tx_data_valid_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__tx_data_strb_r;
        CData/*7:0*/ top__DOT__u_cdc__DOT__u_core__DOT__tx_data_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__tx_data_last_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__tx_data_accept_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_q;
        CData/*7:0*/ top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__rx_space_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__rx_space_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__tx_ready_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__out_data_bit_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__in_data_bit_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__ep_stall_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__ep_iso_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__rx_enable_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__rx_setup_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__ep0_out_data_bit_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__ep0_in_data_bit_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__ep1_out_data_bit_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__ep1_in_data_bit_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__ep2_out_data_bit_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__ep2_in_data_bit_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__ep3_out_data_bit_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__ep3_in_data_bit_q;
        CData/*6:0*/ top__DOT__u_cdc__DOT__u_core__DOT__current_addr_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT____Vcellinp__u_sie_rx__enable_i;
        CData/*2:0*/ top__DOT__u_cdc__DOT__u_core__DOT__next_state_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__tx_valid_r;
        CData/*7:0*/ top__DOT__u_cdc__DOT__u_core__DOT__tx_pid_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__addr_update_pending_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__sent_status_zlp_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__new_out_bit_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__new_in_bit_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__rst_event_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__intr_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__cfg_int_rx_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__cfg_int_tx_r;
        CData/*7:0*/ top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT____VdfgRegularize_h04591d3f_0_4;
        CData/*2:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__state_q;
        CData/*2:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__next_state_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_pid_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_zlp_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_err_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__valid_q;
        CData/*7:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__data_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_txvalid_r;
        CData/*7:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__utmi_data_r;
        CData/*3:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__state_q;
        CData/*6:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_dev_q;
        CData/*3:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_ep_q;
        CData/*7:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_pid_q;
        CData/*3:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_valid_q;
        CData/*3:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__rx_active_q;
    };
    struct {
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__shift_en_w;
        CData/*1:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_crc_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__address_match_w;
        CData/*3:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__next_state_r;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__handshake_valid_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_valid_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__token_valid_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__input_ready_w;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_err_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_complete_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_zlp_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__valid_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__last_q;
        CData/*7:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_q;
        CData/*0:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__mask_q;
        CData/*7:0*/ top__DOT__u_cdc__DOT__u_rom__DOT__desc_rom_r;
        CData/*2:0*/ __Vdly__top__DOT__rst_sync;
        CData/*0:0*/ __VdlySet__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __VicoPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk_25m__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__phy_rst__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__ulpi_clk60__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__cdc_rst__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__u_adc_wrap__DOT__adc_rst_sync__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_a_rst__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        VL_IN16(adc_data_raw,11,0);
        SData/*11:0*/ top__DOT__tx_data_12b;
        SData/*11:0*/ top__DOT__u_adc_wrap__DOT__adc_data;
        SData/*9:0*/ top__DOT__u_adc_wrap__DOT__burst_count;
        SData/*11:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__std_rd_data;
        SData/*11:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__middle_data;
        SData/*14:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr;
        SData/*14:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray;
        SData/*14:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_ms;
        SData/*14:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_rd;
        SData/*14:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__wr_ptr_gray_rd;
        SData/*14:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr;
        SData/*14:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray;
        SData/*14:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_ms;
        SData/*14:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_wr;
        SData/*14:0*/ top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr_gray_wr;
        SData/*15:0*/ top__DOT__u_cdc__DOT__wValue_w;
        SData/*15:0*/ top__DOT__u_cdc__DOT__wIndex_w;
        SData/*15:0*/ top__DOT__u_cdc__DOT__wLength;
        SData/*15:0*/ top__DOT__u_cdc__DOT__ctrl_get_len_r;
        SData/*15:0*/ top__DOT__u_cdc__DOT__ctrl_send_idx_q;
        SData/*15:0*/ top__DOT__u_cdc__DOT__ctrl_send_len_q;
        SData/*15:0*/ top__DOT__u_cdc__DOT__ctrl_send_idx_r;
        SData/*15:0*/ top__DOT__u_cdc__DOT__ctrl_send_len_r;
        SData/*10:0*/ top__DOT__u_cdc__DOT__inport_cnt_q;
        SData/*14:0*/ top__DOT__u_cdc__DOT__u_core__DOT__se0_cnt_q;
        SData/*10:0*/ top__DOT__u_cdc__DOT__u_core__DOT__frame_num_w;
        SData/*15:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__crc_sum_q;
        SData/*15:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_tx__DOT__u_crc16__DOT__crc_out_o;
        SData/*10:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__frame_num_q;
        SData/*15:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__crc_sum_q;
        SData/*15:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__u_crc16__DOT__crc_out_o;
        SData/*14:0*/ __Vdly__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__rd_ptr;
        SData/*11:0*/ __VdlyVal__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0;
    };
    struct {
        SData/*13:0*/ __VdlyDim0__top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem__v0;
        IData/*19:0*/ top__DOT__rst_cnt;
        IData/*22:0*/ top__DOT__startup_timer;
        IData/*19:0*/ top__DOT__u_cdc__DOT__genblk1__DOT__usb_rst_time_q;
        VlWide<3>/*79:0*/ top__DOT__u_cdc__DOT__u_core__DOT__dbg_state;
        VlWide<3>/*79:0*/ top__DOT__u_cdc__DOT__u_core__DOT__dbg_pid;
        IData/*31:0*/ top__DOT__u_cdc__DOT__u_core__DOT__u_sie_rx__DOT__data_buffer_q;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*7:0*/, 2> top__DOT__u_ulpi__DOT__tx_buffer_q;
        VlUnpacked<CData/*0:0*/, 2> top__DOT__u_ulpi__DOT__tx_valid_q;
        VlUnpacked<SData/*11:0*/, 16384> top__DOT__u_adc_wrap__DOT__u_dc_fifo__DOT__u_std_dc_fifo__DOT__u_dpdcram__DOT__mem;
        VlUnpacked<CData/*7:0*/, 8> top__DOT__u_cdc__DOT__setup_packet_q;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    };

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
