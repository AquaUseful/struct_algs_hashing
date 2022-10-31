set(FORM_UI_FILES ui/form.ui)
set(FORM_SRC_FILES src/LabForm.cpp)
set(FORM_INCLUDE_DIRS include/)
set(FORM_MOC_FILES include/LabForm.hpp)

qt_wrap_cpp(FORM_SRC_FILES ${FORM_MOC_FILES})
qt_wrap_ui(FORM_SRC_FILES ${FORM_UI_FILES})

add_library(form ${FORM_SRC_FILES})
target_include_directories(form PUBLIC ${FORM_INCLUDE_DIRS})
target_link_libraries(form Qt5::Core Qt5::Widgets)
