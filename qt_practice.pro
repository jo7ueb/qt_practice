TEMPLATE = subdirs

SUBDIRS += \
    hello_world \
    picture_shuffler \
    image2qlabel \
    dwaring_on_qimage \
    external_lib_test \
    sound_test

#win32{
    SUBDIRS += display_available_sound_devices
#}
