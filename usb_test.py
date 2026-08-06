import usb.core
import usb.util
import sys
import time

VID = 0x1d50
PID = 0x6149

def main():
    print(f"Looking for device {VID:04x}:{PID:04x}...")
    dev = usb.core.find(idVendor=VID, idProduct=PID)
    if dev is None:
        print("Device not found!")
        return

    print(f"Device found! Speed: {dev.speed}")
    print(f"  bcdUSB: 0x{dev.bcdUSB:04x}")
    print(f"  bNumConfigurations: {dev.bNumConfigurations}")

    # Print full descriptor info
    cfg = dev.get_active_configuration()
    if cfg is None:
        print("No active configuration!")
    else:
        print(f"  Active config: {cfg.bConfigurationValue}")
        for intf in cfg:
            print(f"  Interface {intf.bInterfaceNumber}, Alt {intf.bAlternateSetting}, "
                  f"Class 0x{intf.bInterfaceClass:02x}, Subclass 0x{intf.bInterfaceSubClass:02x}")
            for ep in intf:
                print(f"    EP 0x{ep.bEndpointAddress:02x}: "
                      f"MaxPacketSize={ep.wMaxPacketSize}, "
                      f"Type={'BULK' if (ep.bmAttributes & 3) == 2 else 'OTHER'}, "
                      f"Interval={ep.bInterval}")

    # Detach kernel drivers if active
    for iface in [0, 1]:
        try:
            if dev.is_kernel_driver_active(iface):
                dev.detach_kernel_driver(iface)
                print(f"  Detached kernel driver from interface {iface}")
        except Exception as e:
            print(f"  Could not detach iface {iface}: {e}")

    # Set configuration after detaching drivers
    try:
        dev.set_configuration(1)
        print("  Configuration set")
    except Exception as e:
        print(f"  set_configuration: {e}")

    # Claim interfaces
    for iface in [0, 1]:
        try:
            usb.util.claim_interface(dev, iface)
            print(f"  Claimed interface {iface}")
        except Exception as e:
            print(f"  Could not claim iface {iface}: {e}")

    # CDC init
    try:
        dev.ctrl_transfer(0x21, 0x20, 0, 0, [0x00, 0xC2, 0x01, 0x00, 0x00, 0x00, 0x08])
        dev.ctrl_transfer(0x21, 0x22, 0x0003, 0, None)
        print("  CDC control transfers OK")
    except Exception as e:
        print(f"  CDC control transfer failed: {e}")

    print("\n--- Starting read test ---")
    print("Trying various transfer sizes...\n")

    # Test with small reads first (single-packet), then larger
    for xfer_size in [64, 512, 1024, 4096, 16384]:
        print(f"Transfer size: {xfer_size} bytes")
        ok = 0
        fail = 0
        total_bytes = 0
        for i in range(20):
            try:
                data = dev.read(0x82, xfer_size, timeout=500)
                ok += 1
                total_bytes += len(data)
                if i < 3:
                    print(f"  [{i}] OK: {len(data)} bytes. First 8: {[hex(x) for x in data[:8]]}")
            except usb.core.USBTimeoutError:
                fail += 1
                if i < 3:
                    print(f"  [{i}] TIMEOUT")
            except usb.core.USBError as e:
                fail += 1
                if i < 3:
                    print(f"  [{i}] ERROR: {e}")
        print(f"  Result: {ok}/20 OK, {fail}/20 failed, {total_bytes} bytes total\n")

    # Cleanup
    for iface in [0, 1]:
        try:
            usb.util.release_interface(dev, iface)
        except:
            pass

if __name__ == "__main__":
    main()
