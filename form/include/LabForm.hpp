#pragma once

#include "ui_form.h"
#include <qobjectdefs.h>

class LabForm : public QMainWindow {

  Q_OBJECT

public:
  explicit LabForm(QWidget *parent = nullptr);
  virtual ~LabForm();

private:
  void configure_slots();

  Ui::LabForm *ui;
};