#include <QtWidgets/qapplication.h>
#include <cstdlib>
#include <qmainwindow.h>
#include <qwidget.h>

#include "LabForm.hpp"

auto main(int argc, char *argv[]) -> int {
  QApplication app(argc, argv);
  LabForm form;

  form.show();
  return app.exec();
}