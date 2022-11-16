#include <QtWidgets/qapplication.h>
#include <cstdlib>
#include <iostream>
#include <qmainwindow.h>
#include <qwidget.h>

#include "ChainHashmap.hpp"
#include "LabForm.hpp"
#include "OpenAddressHashmap.hpp"

auto main(int argc, char *argv[]) -> int {
  QApplication app(argc, argv);
  LabForm form;

  form.show();
  return app.exec();
}