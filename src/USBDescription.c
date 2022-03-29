#include "usb_names.h"

#define MANUFACTURER_NAME {'C','r','a','z','y','R','u','s','s','i','a', 'n'}
#define MANUFACTURER_NAME_LEN 12
#define PRODUCT_NAME    {'B', 'y', ' ', 'C','r','a','z','y','R','u','s','s','i','a', 'n', ' ', '-', ' ', 'S', 'i', 'm', 'u', 'l', 'a', 't', 'o', 'r', 's', ' ', 'C', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r'}
#define PRODUCT_NAME_LEN  39

#define SERIAL_NUM {'S', 'i', 'm', 'u', 'l', 'a', 't', 'o', 'r', 's','P','a','n','e','l'}
#define SERIAL_NUM_LEN 15


// This exact format is required by USB.

struct usb_string_descriptor_struct usb_string_manufacturer_name = {
        2 + MANUFACTURER_NAME_LEN * 2,
        3,
        MANUFACTURER_NAME
};

struct usb_string_descriptor_struct usb_string_product_name = {
        2 + PRODUCT_NAME_LEN * 2,
        3,
        PRODUCT_NAME
};


struct usb_string_descriptor_struct usb_string_serial_number = {
        2 + SERIAL_NUM_LEN * 2,
        3,
        SERIAL_NUM
};
