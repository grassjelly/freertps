#ifndef SAMV_USB_H
#define SAMV_USB_H

#include <stdint.h>

typedef struct usb_ep_desc
{
  uint8_t  len;
  uint8_t  desc_type;
  uint8_t  ep_addr;
  uint8_t  attr;
  uint16_t max_pkt_size;
  uint8_t  interval;
} __attribute__((packed)) usb_ep_desc_t;

typedef struct usb_iface_desc
{
  uint8_t len;
  uint8_t desc_type;
  uint8_t iface_num;
  uint8_t alt_setting;
  uint8_t num_ep;
  uint8_t iface_class;
  uint8_t iface_subclass;
  uint8_t iface_proto;
  uint8_t iface_str_idx;
  struct usb_ep_desc eps[];
} __attribute__((packed)) usb_iface_desc_t;

typedef struct usb_config_desc
{
  uint8_t  len;
  uint8_t  desc_type;
  uint16_t total_len;
  uint8_t  num_ifaces;
  uint8_t  config_val;
  uint8_t  config_str_idx;
  uint8_t  attributes;
  uint8_t  max_power;
  struct usb_iface_desc ifaces[];
} __attribute__((packed)) usb_config_desc_t;

#define METAL_USB_DESC_TYPE_DEVICE 1
#define METAL_USB_PROTO 0x0200
#define METAL_USB_DEV_CLASS_CUSTOM    0xff
#define METAL_USB_DEV_SUBCLASS_CUSTOM 0xff
#define METAL_USB_DEV_PROTO_CUSTOM    0xff
#define METAL_USB_MAX_EP0_PKT_SIZE 64
#define METAL_USB_VID 0x55f0
#define METAL_USB_BCD_DEV 0
#define METAL_USB_NO_MFGR_STR 0
#define METAL_USB_NO_PROD_STR 0
#define METAL_USB_NO_SERIAL_STR 0

typedef struct usb_device_desc
{
  uint8_t  len;
  uint8_t  desc_type;
  uint16_t proto_ver;
  uint8_t  dev_class;
  uint8_t  dev_subclass;
  uint8_t  max_ep0_pkt_size;
  uint16_t  vid;
  uint16_t  pid;
  uint16_t  bcdDevice; // wtf
  uint8_t   man_str_idx;
  uint8_t   prod_str_idx;
  uint8_t   ser_num_str_idx;
  uint8_t   num_config;
} __attribute__((packed)) usb_device_desc_t;

/////////////////////////

// these functions are not portable and need to be implemented by chip libs
void usb_init();
void usb_tx(const unsigned ep, const void *buf, const unsigned len);
void usb_set_addr(const uint8_t addr);

// these functions are portable
void usb_rx_setup(const uint8_t *buf, const unsigned len);

#endif
