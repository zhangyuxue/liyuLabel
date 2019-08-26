
SOURCES += kColorPicker/src/IconCreator.cpp \
    kColorPicker/src/KColorPicker.cpp \
    kColorPicker/src/PopupMenu.cpp \
    kColorPicker/src/buttons/AbstractPopupMenuButton.cpp \
    kColorPicker/src/buttons/ColorButton.cpp \
    kColorPicker/src/buttons/ColorDialogButton.cpp

HEADERS += kColorPicker/include/kColorPicker/KColorPicker.h \
    kColorPicker/include/kColorPicker/KColorPickerExport.h \
    kColorPicker/src/IconCreator.h \
    kColorPicker/src/PopupMenu.h \
    kColorPicker/src/buttons/AbstractPopupMenuButton.h \
    kColorPicker/src/buttons/ColorButton.h \
    kColorPicker/src/buttons/ColorDialogButton.h

INCLUDEPATH += \
                kColorPicker \
                kColorPicker/include \
                kColorPicker/src \
                kColorPicker/src/buttons

RESOURCES += \
    kColorPicker/icons/kColorPicker_icons.qrc \


DISTFILES += \
    kColorPicker/icons/ellipsis.64.png
