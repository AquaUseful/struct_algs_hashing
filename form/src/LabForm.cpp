#include "LabForm.hpp"


LabForm::LabForm(QWidget *parent) : QMainWindow(parent), ui{new Ui::LabForm} {
  ui->setupUi(this);
}

LabForm::~LabForm() { delete ui; }